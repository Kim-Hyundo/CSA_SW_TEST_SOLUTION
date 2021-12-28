using IronPython.Hosting;
using ProstMain.Model;
using ProstMain.ViewModel;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Runtime.ExceptionServices;
using System.Runtime.InteropServices;
using System.Security;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Threading;

namespace ProstMain.Util
{
    public class Trace32Handler
    {

        public static IntPtr ChannelT32Main;
        public static IntPtr ChannelT32SimulMerge;
        public static IntPtr ChannelT32SimulAnalysis;

        public static class TRACE32_DLL
        {
            [DllImport(@"..\src\lib\T32\lib\t32api.dll", CallingConvention = CallingConvention.Cdecl)]
            public static extern int T32_Config([MarshalAs(UnmanagedType.LPStr)] String String1, [MarshalAs(UnmanagedType.LPStr)] String String2);
            [DllImport(@"..\src\lib\T32\lib\t32api.dll", CallingConvention = CallingConvention.Cdecl)]
            public static extern int T32_Init();
            [DllImport(@"..\src\lib\T32\lib\t32api.dll", CallingConvention = CallingConvention.Cdecl)]
            public static extern int T32_Attach(int DeviceSpecifier);
            [DllImport(@"..\src\lib\T32\lib\t32api.dll", CallingConvention = CallingConvention.Cdecl)]
            public static extern int T32_Cmd([MarshalAs(UnmanagedType.LPStr)] string Command);
            [DllImport(@"..\src\lib\T32\lib\t32api.dll", CallingConvention = CallingConvention.Cdecl)]
            public static extern void T32_Exit();
            [DllImport(@"..\src\lib\T32\lib\t32api.dll", CallingConvention = CallingConvention.Cdecl)]
            public static extern void T32_SetChannel(IntPtr Params);
            [DllImport(@"..\src\lib\T32\lib\t32api.dll", CallingConvention = CallingConvention.Cdecl)]
            public static extern int T32_ReadMemory(UInt32 Address, int Access, ref UInt16 pBuffer, UInt32 Size);
            [DllImport(@"..\src\lib\T32\lib\t32api.dll", CallingConvention = CallingConvention.Cdecl)]
            public static extern int T32_GetMessage(StringBuilder AreaMessage, ref UInt16 MessageType);
            [DllImport(@"..\src\lib\T32\lib\t32api.dll", CallingConvention = CallingConvention.Cdecl)]
            public static extern int T32_GetMessageString(StringBuilder AreaMessage, UInt16 ArraySize, ref UInt16 pMessageType, ref UInt16 pMessageLen);
            [DllImport(@"..\src\lib\T32\lib\t32api.dll", CallingConvention = CallingConvention.Cdecl)]
            public static extern int T32_GetTriggerMessage(StringBuilder AreaMessage);
            [DllImport(@"..\src\lib\T32\lib\t32api.dll", CallingConvention = CallingConvention.Cdecl)]
            public static extern int T32_GetChannelSize();
            [DllImport(@"..\src\lib\T32\lib\t32api.dll", CallingConvention = CallingConvention.Cdecl)]
            public static extern void T32_GetChannelDefaults(IntPtr Params);
            [DllImport(@"..\src\lib\T32\lib\t32api.dll", CallingConvention = CallingConvention.Cdecl)]
            public static extern void T32_GetSymbol([MarshalAs(UnmanagedType.LPStr)] string symbol, ref UInt32 address, ref UInt32 size, ref UInt32 reserved);
            [DllImport(@"..\src\lib\T32\lib\t32api.dll", CallingConvention = CallingConvention.Cdecl)]
            public static extern int T32_GetPracticeState(ref int pstate);
            [DllImport(@"..\src\lib\T32\lib\t32api.dll", CallingConvention = CallingConvention.Cdecl)]
            public static extern int T32_Nop();
            [DllImport(@"..\src\lib\T32\lib\t32api.dll", CallingConvention = CallingConvention.Cdecl)]
            public static extern int T32_Ping();
        }
        private static class LazyHolder
        {
            public static readonly Trace32Handler INSTANCE = new Trace32Handler();
        }

        public static Trace32Handler getInstance()
        {
            return LazyHolder.INSTANCE;
        }
        public Trace32Handler()
        {

        }


        public void Init(string PORT, string CH)
        {
            int nRetryCounter = 2;
            int err = 0;
            int errorCount = 0;


            if (PORT == "20000")
            {
                ChannelT32Main = Marshal.AllocHGlobal(TRACE32_DLL.T32_GetChannelSize());
                TRACE32_DLL.T32_GetChannelDefaults(ChannelT32Main);
                TRACE32_DLL.T32_SetChannel(ChannelT32Main);
            }
            else if (PORT == "20001")
            {
                ChannelT32SimulAnalysis = Marshal.AllocHGlobal(TRACE32_DLL.T32_GetChannelSize());
                TRACE32_DLL.T32_GetChannelDefaults(ChannelT32SimulAnalysis);
                TRACE32_DLL.T32_SetChannel(ChannelT32SimulAnalysis);
            }
            else if (PORT == "20002")
            {
                ChannelT32SimulMerge = Marshal.AllocHGlobal(TRACE32_DLL.T32_GetChannelSize());
                TRACE32_DLL.T32_GetChannelDefaults(ChannelT32SimulMerge);
                TRACE32_DLL.T32_SetChannel(ChannelT32SimulMerge);
            }

            TRACE32_DLL.T32_Config("PORT=", PORT);  // PowerView Port Connect
        retry:
            if ((err = TRACE32_DLL.T32_Init()) != 0)    // 초기화 예외 처리
            {
                TRACE32_DLL.T32_Exit();
                nRetryCounter = nRetryCounter--;
                if (nRetryCounter > 0)
                {
                    if (errorCount >= 13)
                    {
                        Thread.Sleep(150);
                        return;
                    }
                    goto retry;
                }
                /* we may need a second try if the software crashed before */

                Console.WriteLine("ERROR: could not initialize connection to T32-API server\n");
                //return false;
            }

            TRACE32_DLL.T32_Config("TIMEOUT=", "5");

            if (TRACE32_DLL.T32_Attach(1) != 0) // PowerView
            {
                TRACE32_DLL.T32_Exit();
                nRetryCounter = nRetryCounter--;
                if (nRetryCounter > 0)
                    goto retry; /* we may need a second try if the software crashed before */

                Console.WriteLine("ERROR: could not attach to T32-API server\n");
                //return false;
            }

            TRACE32_DLL.T32_Config("TIMEOUT=", "10");

            string temp = "PRINT " + "\"" + CH + "_successful connection\"";
            TRACE32_DLL.T32_Cmd(temp);
            Thread.Sleep(100);
        }

        public void TRACE32Start()
        {
            Process proc;
            if (ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.IsTRACE32ForgroundExecute)
            {
                if (ViewModelLocator.MainVM.MainModel.IsTestSimulationEnable)
                    proc = Process.Start(@"..\src\lib\T32\PowerView_Simulator.bat", @"..\src\lib\T32 " + ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.Trace32IPAddress);
                else
                {
                    if (ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.CpuName.ToUpper().Contains("TC")) //지현 수정
                        proc = Process.Start(@"..\src\lib\T32\PowerView.bat", "TRICORE " + @"..\src\lib\T32 " + ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.Trace32IPAddress);
                    else if (ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.CpuName.ToUpper().Contains("CYT")) //지현 수정
                        proc = Process.Start(@"..\src\lib\T32\PowerView.bat", "ARM " + @"..\src\lib\T32 " + ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.Trace32IPAddress);
                }
            }
            else
            {
                if (ViewModelLocator.MainVM.MainModel.IsTestSimulationEnable)
                    proc = Process.Start(@"..\src\lib\T32\PowerView_Simulator.bat", @"..\src\lib\T32 " + ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.Trace32IPAddress + " INVISIBLE");
                else
                    proc = Process.Start(@"..\src\lib\T32\PowerView.bat", @"..\src\lib\T32 " + ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.Trace32IPAddress + " INVISIBLE");
            }


        }

        public void TRACE32Start_Simulation(int Mode)
        {
            Process proc;

            if (Mode == 0)
            {
                if (ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.IsTRACE32ForgroundExecute)
                    proc = Process.Start(@"..\src\lib\T32\PowerView_Coverage.bat", @"..\src\lib\T32 " + ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.Trace32IPAddress);
                else
                    proc = Process.Start(@"..\src\lib\T32\PowerView_Coverage.bat", @"..\src\lib\T32 " + ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.Trace32IPAddress + " INVISIBLE");
            }
            else if (Mode == 1)
            {
                if (ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.IsTRACE32ForgroundExecute)
                    proc = Process.Start(@"..\src\lib\T32\PowerView_Timing.bat", @"..\src\lib\T32 " + ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.Trace32IPAddress);
                else
                    proc = Process.Start(@"..\src\lib\T32\PowerView_Timing.bat", @"..\src\lib\T32 " + ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.Trace32IPAddress + " INVISIBLE");
            }


        }
        public void TRACE32_CheckConnect()
        {
            if (!ViewModelLocator.MainVM.MainModel.IsTrace32Connection)
            {
                TRACE32Start();
                Thread.Sleep(3000);
                Init("20000", "CH1");
                if (ViewModelLocator.MenuBarVM.IsADFileGenerator)
                    SetMultiTrace32();

                if (TRACE32_DLL.T32_Nop() == 0)
                {
                    ViewModelLocator.MainVM.MainModel.IsTrace32Connection = true;
                    ViewModelLocator.MainVM.showTrackBarMessage("TRACE32 Connection");
                    ProstLog.getInstance().Log(Common.Common.MODULE_TRACE32, Common.Common.LOGTYPE_PGR, "TRACE32 Connection");
                }
                else
                {
                    ViewModelLocator.MainVM.MainModel.IsTrace32Connection = false;
                    ViewModelLocator.MainVM.showTrackBarMessage("TRACE32 Not Connection");
                }
                Dispatcher dispatcher = Application.Current.Dispatcher;
                DispatcherOperation dispatcherOperation = dispatcher.BeginInvoke(System.Windows.Threading.DispatcherPriority.Send, (ThreadStart)
                delegate ()
                {
                    Common.Common.mainwindowView.Activate();
                });
                return;
            }
            else
            {
                // TRACE32가 종료되었을 때 판별
                for (int i = 0; i < 6; i++)
                {
                    //Init("20000", "CH1");
                    TRACE32_DLL.T32_SetChannel(ChannelT32Main);
                    if (TRACE32_DLL.T32_Nop() == 0)
                    {
                        ViewModelLocator.MainVM.MainModel.IsTrace32Connection = true;
                        ViewModelLocator.MainVM.showTrackBarMessage("TRACE32 Connection");
                        return;
                    }
                    else
                    {
                        if (i >= 5)
                        {
                            ViewModelLocator.MainVM.MainModel.IsTrace32Connection = false;
                            ViewModelLocator.MainVM.showTrackBarMessage("TRACE32 Not Connection");
                            TRACE32_CheckConnect();
                            return;
                        }
                    }
                }
            }
        }
        private void SetMultiTrace32()
        {
            TRACE32Start_Simulation(0);
            Init("20001", "SIMULATION_Coverage");

            TRACE32Start_Simulation(1);
            Init("20002", "SIMULATION_Timing");
        }
        public bool FlashDownload(int mode)
        {
            try
            {
                int check = 1;
                int tempindex = 0;
                string FlashPath = "";
                string str = "";
                StringBuilder resultTemp = new StringBuilder("", 0);
                UInt16 type = 0;

                TRACE32_DLL.T32_Cmd("SYSTEM.RESET");

                if (mode == Common.Common.TRACE32_POWERVIEW)
                {
                    

/*                    TRACE32_DLL.T32_Cmd("system.detect.cpu");
                    Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref check);
                    while (check != 0)
                    {
                        Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref check);
                    }

                    TRACE32_DLL.T32_Cmd("print CPUIS(" + ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.CpuName.Replace("x", "") + "*)");
                    TRACE32_DLL.T32_GetMessage(resultTemp, ref type);
                    str = resultTemp.ToString();
                    if (!str.Contains("TRUE"))
                    {
                        ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, "Check the Target Board!!");
                        return false;
                    }*/
                }
                resultTemp = null;

                FlashPath = Common.Common.INSTALL_PATH + @"\src\lib\T32\flash\" + ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.CpuName + ".cmm";

                string[] elffiles = Directory.GetFiles(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TimeCreateFolderPath + "\\" + "Build", "*.elf");

                if (File.Exists(elffiles[0]))
                {
                    for (int i = 0; i < ViewModelLocator.TargetHWSettingVM.CoreList.Count; i++)
                    {
                        if (ViewModelLocator.TargetHWSettingVM.CoreList[i] == true)
                        {
                            tempindex = i;
                            break;
                        }
                    }

                    string PreElfConvertPath = "";
                    string PostElfConvertPath = "";

                    /*임시 방편*/
                    if (ViewModelLocator.ETCSettingVM.PreLoadElfPath == null)
                        ViewModelLocator.ETCSettingVM.PreLoadElfPath = "";
                    if (ViewModelLocator.ETCSettingVM.PostLoadElfPath == null)
                        ViewModelLocator.ETCSettingVM.PostLoadElfPath = "";

                    if (ViewModelLocator.ETCSettingVM.PreLoadElfPath.Contains("$(workspace_loc)"))
                        PreElfConvertPath = ViewModelLocator.ETCSettingVM.PreLoadElfPath.Replace("$(workspace_loc)", ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath);
                    else
                        PreElfConvertPath = ViewModelLocator.ETCSettingVM.PreLoadElfPath;

                    if (ViewModelLocator.ETCSettingVM.PostLoadElfPath.Contains("$(workspace_loc)"))
                        PostElfConvertPath = ViewModelLocator.ETCSettingVM.PostLoadElfPath.Replace("$(workspace_loc)", ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath);
                    else
                        PostElfConvertPath = ViewModelLocator.ETCSettingVM.PostLoadElfPath;

                    TRACE32_DLL.T32_Cmd("CD.DO \"" + FlashPath + "\" " + "\"" + elffiles[0] + "\" " + "\"" + tempindex + "\"" + "\"" + PreElfConvertPath + "\"" + "\"" + PostElfConvertPath + "\"");
                    Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref check);
                    while (check != 0)
                    {
                        Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref check);
                    }

                    /*if (mode == Common.Common.TRACE32_SIMULATOR)
                        TRACE32_DLL.T32_Cmd("sYmbol.SourcePATH.SetBaseDir " + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Target_SW");*/

                    string ConvertPath = "";
                    if (ViewModelLocator.ETCSettingVM.EnumScriptPath.Contains("$(workspace_loc)"))
                        ConvertPath = ViewModelLocator.ETCSettingVM.EnumScriptPath.Replace("$(workspace_loc)", ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath);
                    else
                        ConvertPath = ViewModelLocator.ETCSettingVM.EnumScriptPath;
                    //if (File.Exists(Common.Common.INSTALL_PATH + @"\src\parser\Cmm\Templete\enum_script.cmm"))
                    if (File.Exists(ConvertPath))
                    {
                        TRACE32_DLL.T32_Cmd("CD.DO \"" + ConvertPath + "\"");
                        Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref check);
                        while (check != 0)
                        {
                            Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref check);
                        }
                    }
                    if (File.Exists(Common.Common.INSTALL_PATH + @"\src\parser\Cmm\Templete\enum_macro.cmm"))
                    {
                        TRACE32_DLL.T32_Cmd("CD.DO \"" + Common.Common.INSTALL_PATH + @"\src\parser\Cmm\Templete\enum_macro.cmm" + "\"");
                        Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref check);
                        while (check != 0)
                        {
                            Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref check);
                        }
                    }

                    int index = 0;
                    foreach (RunnableModel model in ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableList)
                    {
                        string[] temp = model.RunnableNameGrid.Split('(');
                        if (temp.Length > 1)
                        {
                            string FunctionFlagName = temp[0] + "_flag";
                            TRACE32_DLL.T32_Cmd("y.new.macro " + FunctionFlagName + " " + index);
                            index++;
                        }
                    }

                    resultTemp = new StringBuilder("",0);
                    TRACE32_DLL.T32_GetMessage(resultTemp, ref type);
                    str = resultTemp.ToString();

                   StackAddressSave();

                    
                    switch (mode)
                    {
                        case Common.Common.TRACE32_POWERVIEW:
                            return true;
                            if (str.Contains("POWERVIEW FLASHDOWNLOAD COMPLETE"))
                            {
                                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PFF, str);
                                return true;
                            }
                            else
                            {
                                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, "PowerView Flash Download Error");
                                return false;
                            }
                            break;
                        case Common.Common.TRACE32_SIMULATOR:
                            if (str.Contains("SIMULATOR FLASHDOWNLOAD COMPLETE"))
                            {
                                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PFF, str);
                                return true;
                            }
                            else
                                return false;
                            break;
                    }
                }
                else
                    Console.WriteLine("Elf file is not exist.");
                return false;
            }
            catch(Exception ex)
            {
                return false;
            }
        }
        public void Trace_Info_Paser()
        {
            PythonHandler.getInstance().TraceInfoParserCall();
            TRACE32_DLL.T32_Cmd("END");
        }
        
        public void StackAddressSave()
        {
            int corenum = 0;
            for (int i = 0; i < ViewModelLocator.TargetHWSettingVM.CoreList.Count; i++)
            {
                if (ViewModelLocator.TargetHWSettingVM.CoreList[i])
                    corenum = i;
            }
            /* 12/01 스택사용량 측정 관련 start / end 주소 */
            string StartAddressNmae = "";
            string EndAddressNmae = "";
            if (ViewModelLocator.CompilerSettingVM.CompilerSettingModel.CompilerType.Equals("TASKING"))
            {
                StartAddressNmae = "_lc_gb_MY_FILLED_STACK" + corenum;
                EndAddressNmae = "_lc_ge_MY_FILLED_STACK" + corenum;
            }
            else if (ViewModelLocator.CompilerSettingVM.CompilerSettingModel.CompilerType.Equals("GHS"))
            {
                StartAddressNmae = "__ghs_stackstart";
                EndAddressNmae = "__ghs_stackend";
            }

            /* 지현 수정 여기까지 */

            
            StringBuilder resultTemp = new StringBuilder(0, 256);
            UInt16 msg = 0;

            TRACE32_DLL.T32_Cmd("PRINT sYmbol.RANGE(" + StartAddressNmae + ")");
            TRACE32_DLL.T32_GetMessage(resultTemp, ref msg);
            string str = resultTemp.ToString();

            if (str.LastIndexOfAny(":".ToCharArray()) > 0)
            {
                string[] sp = str.Split(':');
                ViewModelLocator.ReportSettingVM.ReportSettingModel.StartAddressValue = sp[1].Substring(1).Trim();

                sp.Initialize();
                sp = ViewModelLocator.ReportSettingVM.ReportSettingModel.StartAddressValue.Split('-');
                ViewModelLocator.ReportSettingVM.ReportSettingModel.StartAddressValue = sp[0].Substring(1).Trim();
            }
            else
            {
                ViewModelLocator.ReportSettingVM.ReportSettingModel.StartAddressValue = "N/A";
            }

            TRACE32_DLL.T32_Cmd("PRINT sYmbol.RANGE(" + EndAddressNmae + ")");
            TRACE32_DLL.T32_GetMessage(resultTemp, ref msg);
            str = resultTemp.ToString();

            if (str.LastIndexOfAny(":".ToCharArray()) > 0)
            {
                string[] sp = str.Split(':');
                ViewModelLocator.ReportSettingVM.ReportSettingModel.EndAddressValue = sp[1].Substring(1).Trim();

                sp.Initialize();
                sp = ViewModelLocator.ReportSettingVM.ReportSettingModel.EndAddressValue.Split('-');
                ViewModelLocator.ReportSettingVM.ReportSettingModel.EndAddressValue = sp[0].Substring(1).Trim();
            }
            else
            {
                ViewModelLocator.ReportSettingVM.ReportSettingModel.EndAddressValue = "N/A";
            }

        }

        
        public void StackUsage()
        {
            UInt16[] pBuffer = new UInt16[2];

            if (ViewModelLocator.ReportSettingVM.ReportSettingModel.StartAddressValue == "" || ViewModelLocator.ReportSettingVM.ReportSettingModel.StartAddressValue == null
                || ViewModelLocator.ReportSettingVM.ReportSettingModel.StartAddressValue == "N/A" || ViewModelLocator.ReportSettingVM.ReportSettingModel.EndAddressValue == ""
                || ViewModelLocator.ReportSettingVM.ReportSettingModel.EndAddressValue == null || ViewModelLocator.ReportSettingVM.ReportSettingModel.EndAddressValue == "N/A")
                return;

            int StartNum = int.Parse(ViewModelLocator.ReportSettingVM.ReportSettingModel.StartAddressValue, System.Globalization.NumberStyles.HexNumber);
            int EndNum = int.Parse(ViewModelLocator.ReportSettingVM.ReportSettingModel.EndAddressValue, System.Globalization.NumberStyles.HexNumber);

            Int32 addr = 0;

            for (int i = 0; i <= EndNum - StartNum; i++)
            {
                addr = Convert.ToInt32(StartNum) + (i) * 4;
                //LogFormat.Log_Thread("Address : " + addr.ToString() + "Checking");
                TRACE32_DLL.T32_ReadMemory((uint)addr, 0, ref pBuffer[0], 4);

                if (pBuffer[0] == 42405 && pBuffer[1] == 42405)
                {

                }
                else
                {
                    ViewModelLocator.ReportSettingVM.ReportSettingModel.StackPointer = StartNum + i * 4;
                    break;
                }
            }
        }
        public void T32_Command(string str, bool isPrintLog)
        {
            if (str.Contains("run_func_flag") && ViewModelLocator.MainVM.MainModel.PROGRAM_MODE == Common.Common.CUSTOMER_WIA)
                return;

            Trace32Handler.TRACE32_DLL.T32_Cmd(str);
            if(isPrintLog)
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PFF, "T32_Cmd [" + str + "]");
        }
    }
}
