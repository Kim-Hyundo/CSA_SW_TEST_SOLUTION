using ProstMain.Model;
using ProstMain.ViewModel;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Runtime.ExceptionServices;
using System.Runtime.InteropServices;
using System.Security;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Threading;

namespace ProstMain.Util
{
    
    class FunctionWorkHandler
    {
        
        int ThreadFlag;
        public Thread CoverageSimulatorControlThread = null;
        IronPython.Runtime.PythonDictionary Testcase_Count;
        IronPython.Runtime.PythonDictionary MakeADFileCheckDic;
        double TestProgress;

        public BackgroundWorker BuildTestWorker;
        public BackgroundWorker TestRunWorker;

        public List<string> Dictionary_Keys_ComparisonArray;
        public List<string> Total_AdFileList = new List<string>();
        private ManualResetEvent TestWorklocker = new ManualResetEvent(true);
        private ManualResetEvent MergeAnalysisWorklocker = new ManualResetEvent(true);
        private ManualResetEvent CoverageAnalysisWorklocker = new ManualResetEvent(true);

        private static class LazyHolder
        {
            public static readonly FunctionWorkHandler INSTANCE = new FunctionWorkHandler();
        }

        public static FunctionWorkHandler getInstance()
        {
            return LazyHolder.INSTANCE;
        }

        public FunctionWorkHandler()
        {
            Dictionary_Keys_ComparisonArray = new List<string>();
        }
        DispatcherTimer timer;
        Thread thread;
        /// <summary>
        /// 테스트 시작 전 TRACE32 연결 체크 후 PopupTestStatusView 출력
        /// [Argument : void  //  Returnvalue : void]
        /// </summary>
        public void T32CheckBeforeTest()
        {
            ViewModelLocator.PopupTestStatusVM.PopupTestStatusModel.TestStatusProgress = 0;
            ViewModelLocator.PopupTestStatusVM.PopupTestStatusModel.TestAnalysysProgress = 0;
            ViewModelLocator.PopupTestStatusVM.PopupTestStatusModel.TestMergeDataProgress = 0;
            ViewModelLocator.PopupTestStatusVM.PopupTestStatusModel.TestStatusText = "";
            ViewModelLocator.PopupTestStatusVM.PopupTestStatusModel.TestcaseProgressText = "";

            if (ViewModelLocator.PopupBuildStatusVM.PopupBuildStatusModel.IsElfSettingValue != Common.Common.PASS)
            {
                ViewModelLocator.MainVM.showTrackBarMessage("Please Check the Build");
                return;
            }

            if (ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.CpuName == "")
            {
                ViewModelLocator.MainVM.showTrackBarMessage("Please Check the CPU Name");
                return;
            }
            if (thread != null)
                thread.Abort();


            thread = new Thread(new ThreadStart(
            delegate ()
            {
                Trace32Handler.getInstance().TRACE32_CheckConnect();
            }));
            thread.IsBackground = true;
            thread.Start();

            int checkcount = 0;
            if (timer != null)
                timer.Stop();

            timer = new DispatcherTimer();
            timer.Interval = TimeSpan.FromSeconds(1);
            timer.Tick += (s, e) =>
            {
                checkcount++;

                if (checkcount > 60)
                {
                    ViewModelLocator.MainVM.showTrackBarMessage("Please Check The TRACE32 Connection..");
                    if (Common.Common.m_PopupTestStatusView != null)
                        Common.Common.m_PopupTestStatusView.Close();
                    timer.Stop();
                }
                else
                {
                    ProstLog.getInstance().Log("TRACE32 is checking the connection status... " + checkcount + "sec");
                    if (ViewModelLocator.MainVM.MainModel.IsTrace32Connection)
                    {
                        timer.Stop();
                        ViewModelLocator.PopupTestStatusVM.PopupTestStatusModel.IsTestStart = false;
                        ViewModelLocator.PopupTestStatusVM.ShowPopupTestStatus();
                    }
                }
            };
            timer.Start();
        }

        private object TestRunlockObject = new object();
        /// <summary>
        /// Background Worker를 사용하여 Test 동작을 수행하는 함수
        /// </summary>
        public void Process_TestRun()
        {
            lock (TestRunlockObject)
            {
                TestRunWorker = new BackgroundWorker();
                TestRunWorker.DoWork += TestRunWorker_DoWork;
                TestRunWorker.WorkerSupportsCancellation = true;
                TestRunWorker.RunWorkerCompleted += TestRunWorker_DoWorkComplete;
                TestRunWorker.WorkerReportsProgress = true;
                TestRunWorker.ProgressChanged += new ProgressChangedEventHandler(TestRunWorker_ProgressChanged);

                TestRunWorker.RunWorkerAsync();
                ViewModelLocator.ToolbarVM.ToolbarModel.IsToolbarEnable = false;
            }
        }
        /// <summary>
        /// TRACE32 Simulator에 FlashDownload 동작을 수행하는 함수
        /// </summary>
        public void TRACE32Start_SimulatonFlashDown(IntPtr CH, int mode)
        {
            Trace32Handler.TRACE32_DLL.T32_SetChannel(CH);
            Trace32Handler.getInstance().FlashDownload(mode);
        }

        /// <summary>
        /// TestRunWorker 동작 함수
        /// </summary>
        [HandleProcessCorruptedStateExceptions]
        [SecurityCritical]
        private void TestRunWorker_DoWork(object sender, DoWorkEventArgs e)
        {
            try
            {
                ThreadFlag = 0;
                ViewModelLocator.PopupTestStatusVM.PopupTestStatusModel.TestStatusText = "";
                ViewModelLocator.PopupTestStatusVM.PopupTestStatusModel.TestcaseProgressText = "";

                ViewModelLocator.PopupTestCaseParsingVM.PopupTestCaseParsingModel.IsTestcaseParserComplete = Common.Common.DEFAULT;

                


                DirectoryInfo di = new DirectoryInfo(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath);
                string[] CheckPath = {ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug",
                                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Report"};

                try
                {
                    for (int i = 0; i < CheckPath.Length; i++)
                    {
                        di = new DirectoryInfo(CheckPath[i]);
                        if (di.Exists)
                        {
                            CommonUtil.ClearAttributes(CheckPath[i]);

                            if (i == 1)
                            {
                                ProstLog.getInstance().Log("");
                                ProstLog.getInstance().Log("/*************************************************************");
                                ProstLog.getInstance().Log("******************** Test Report Reset ***********************");
                                ProstLog.getInstance().Log("/************************************************************/");
                                ProstLog.getInstance().Log("");
                            }
                        }
                    }

                    string[] MakeFolderPath = {ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\dic",
                                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\ad",
                                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\ad\\Total",
                                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\cba",
                                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\dic\\project_info",
                                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\dic\\coverage",
                                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\dic\\timing",
                                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\dic\\trace",
                                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\txt",
                                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\txt\\coverage",
                                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\txt\\mcdc_cov",
                                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\txt\\mcdc_cov\\Total",
                                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\txt\\mcdc_cov\\Total\\cba",
                                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\txt\\mcdc_cov\\Total\\cov",
                                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\txt\\coverage\\Total",
                                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\txt\\coverage\\Total\\cba",
                                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\txt\\coverage\\Total\\cov",
                                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\txt\\timing",
                                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\txt\\trace",
                                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\txt\\funccall_cov\\all",
                                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\txt\\funccall_cov\\call"};

                    for (int i = 0; i < CheckPath.Length; i++)
                    {
                        di = new DirectoryInfo(CheckPath[i]);
                        if(!di.Exists)
                            di.Create();
                    }

                    for (int i = 0; i < MakeFolderPath.Length; i++)
                    {
                        di = new DirectoryInfo(MakeFolderPath[i]);
                        if (!di.Exists)
                            di.Create();
                    }

                }
                catch (Exception)
                {
                    ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, "파일 및 폴더가 열려있거나, 접근할 수 없습니다.");
                    throw;
                }


                if (File.Exists(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\parse_result.txt"))
                    File.Delete(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\parse_result.txt");

                int check = 1;
                UInt32 timer_addr = 0x90000010;
                UInt32 addr_idx = 0x0;
                double time_value = 0;
                IronPython.Runtime.List G_Precondition_dic;

                ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.TestCodeList.Clear();

                // get source code list
                CommonUtil.GetSourceList();

                if (!PythonHandler.getInstance().makeProjectData())
                {
                    ViewModelLocator.MainVM.showTrackBarMessage("Please Check the Dictionary File");
                    ViewModelLocator.PopupTestStatusVM.PopupTestStatusModel.IsTestSettingValue = Common.Common.FAIL;
                    return;
                }

                TestRunWorker.ReportProgress(12, new ProgressState { Value = 9, Content = "Parsing Test Case..." });
                ViewModelLocator.PopupTestStatusVM.PopupTestStatusModel.IsTestStart = true;

                PythonHandler.getInstance().PaserCall();

                TestRunWorker.ReportProgress(12, new ProgressState { Value = 12, Content = "Complete Parsing Test Case..." });

                Trace32Handler.TRACE32_DLL.T32_SetChannel(Trace32Handler.ChannelT32Main);

                Thread.Sleep(2000);

                /*if (!Trace32Handler.getInstance().FlashDownload(Common.Common.TRACE32_POWERVIEW))
                {
                    e.Cancel = true;
                    return;
                }*/
                try
                {
                    int check_ = 1;
                    int tempindex = 0;
                    string FlashPath = "";
                    string str = "";
                    StringBuilder resultTemp = new StringBuilder("", 0);
                    UInt16 type = 0;

                    Trace32Handler.TRACE32_DLL.T32_Cmd("SYSTEM.RESET");

                    resultTemp = null;

                    FlashPath = Common.Common.INSTALL_PATH + @"\src\lib\T32\flash\" + ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.CpuName + ".cmm";

                    string[] elffiles = Directory.GetFiles(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TimeCreateFolderPath + "\\" + "Build", "*.elf");

                    for (int i = 0; i < ViewModelLocator.TargetHWSettingVM.CoreList.Count; i++)
                    {
                        if (ViewModelLocator.TargetHWSettingVM.CoreList[i] == true)
                        {
                            tempindex = i;
                            break;
                        }
                    }

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

                        /*지현 수정*/
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

                        Trace32Handler.TRACE32_DLL.T32_Cmd("CD.DO \"" + FlashPath + "\" " + "\"" + elffiles[0] + "\" " + "\"" + tempindex + "\"" + "\"" + PreElfConvertPath + "\"" + "\"" + PostElfConvertPath + "\"");
                        //Trace32Handler.TRACE32_DLL.T32_Cmd("cd.do \"" + "\"C:\\Users\\GiCheol.Shin\\Desktop\\Prost_v2.0\\Prost v2.0\\src\\lib\\T32\\flash\\CYT2B75CA(rev_d).cmm\" " + "\"C:\\Users\\GiCheol.Shin\\Desktop\\test\\test\\Gen\\20211201_\\Build\\test.elf\" " + "\"1\" " +"\"C:\\Users\\GiCheol.Shin\\Desktop\\test\\test\\Target_SW\\Debug\\cm0plus.elf\" " + "\"\"");
                        //Trace32Handler.TRACE32_DLL.T32_Cmd("CD.DO \"" + FlashPath + "\" " + "\"" + elffiles[0] + "\" " + "\"" + tempindex + "\" " + "\"" + ViewModelLocator.ETCSettingVM.PreLoadElfPath + "\" " + "\"" + ViewModelLocator.ETCSettingVM.PostLoadElfPath + "\"");
                        /*지현 수정 여기까지*/
                        Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref check);
                        while (check != 0)
                        {
                            Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref check);
                        }

                        string ConvertPath = "";
                        if (ViewModelLocator.ETCSettingVM.EnumScriptPath.Contains("$(workspace_loc)"))
                            ConvertPath = ViewModelLocator.ETCSettingVM.EnumScriptPath.Replace("$(workspace_loc)", ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath);
                        else
                            ConvertPath = ViewModelLocator.ETCSettingVM.EnumScriptPath;
                        if (File.Exists(ConvertPath))
                        {
                            Trace32Handler.TRACE32_DLL.T32_Cmd("CD.DO \"" + ConvertPath + "\"");
                            Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref check);
                            while (check != 0)
                            {
                                Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref check);
                            }
                        }
                        if (File.Exists(Common.Common.INSTALL_PATH + @"\src\parser\Cmm\Templete\enum_macro.cmm"))
                        {
                            Trace32Handler.TRACE32_DLL.T32_Cmd("CD.DO \"" + Common.Common.INSTALL_PATH + @"\src\parser\Cmm\Templete\enum_macro.cmm" + "\"");
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
                                Trace32Handler.TRACE32_DLL.T32_Cmd("y.new.macro " + FunctionFlagName + " " + index);
                                index++;
                            }
                        }

                        /* 12/01 지현 수정 -> Stack 사용량 측정 관련 address 정보 저장 */
                        Trace32Handler.getInstance().StackAddressSave();
                    }
                    else
                        Console.WriteLine("Elf file is not exist.");
                }
                catch (Exception ex)
                {
                    ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, ex.Message);
                }

                while (ViewModelLocator.PopupTestCaseParsingVM.PopupTestCaseParsingModel.IsTestcaseParserComplete == Common.Common.DEFAULT)
                {
                    ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, "TestcaseParserComplete [" + ViewModelLocator.PopupTestCaseParsingVM.PopupTestCaseParsingModel.IsTestcaseParserComplete + "]");
                    e.Cancel = true;
                    return;
                }

                if (ViewModelLocator.MenuBarVM.IsADFileGenerator)
                {
                    Thread SimulatorCoverageThread = new Thread(() => TRACE32Start_SimulatonFlashDown(Trace32Handler.ChannelT32SimulAnalysis, Common.Common.TRACE32_SIMULATOR));
                    SimulatorCoverageThread.Start();
                    SimulatorCoverageThread.Join();

                    Thread SimulatorTimingThread = new Thread(() => TRACE32Start_SimulatonFlashDown(Trace32Handler.ChannelT32SimulMerge, Common.Common.TRACE32_SIMULATOR));
                    SimulatorTimingThread.Start();
                    SimulatorTimingThread.Join();
                }

                TestRunWorker.ReportProgress(31, new ProgressState { Value = 31, Content = "Flash Download..." });
                TestProgress = 31;

                string parse_result = ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\" + "parse_result.txt";

                var engine = IronPython.Hosting.Python.CreateEngine();
                var scope = engine.CreateScope();

                ICollection<string> searchPaths = engine.GetSearchPaths();

                searchPaths.Add(@"..\src\lib\IronPython 2.7\Lib");
                searchPaths.Add(@"..\src\lib\common\Pickle");
                searchPaths.Add(@"..\src\compiler\python");
                searchPaths.Add(@"..\src\parser\python");
                searchPaths.Add(@"..\src\Parser\python\Lib");
                engine.SetSearchPaths(searchPaths);

                var source = engine.CreateScriptSourceFromFile(@"..\src\lib\common\Pickle\test_pickle.py");
                source.Execute(scope);

                var Origin_TC_Load = scope.GetVariable<Func<string, object>>("Origin_TC_Load");
                IronPython.Runtime.PythonDictionary parse_result_dic = (IronPython.Runtime.PythonDictionary)Origin_TC_Load(parse_result);
                ViewModelLocator.ReportSettingVM.ReportSettingModel.TestInfoDictionary = (IronPython.Runtime.PythonDictionary)parse_result_dic["Test_Info"];

                var Precondition_TC_Load = scope.GetVariable<Func<string, object>>("Precondition_TC_Load");
                IronPython.Runtime.List Test_PreCondition_Dictionary = null;

                if (ViewModelLocator.PopupTestCaseParsingVM.PopupTestCaseParsingModel.ParserSelectedItem.Equals("WiaUnitTestspecParser"))
                {
                    G_Precondition_dic = (IronPython.Runtime.List)Precondition_TC_Load(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\TestCase" + "\\precond_data.txt");
                    Test_PreCondition_Dictionary = (IronPython.Runtime.List)G_Precondition_dic[0];
                }

                IronPython.Runtime.PythonDictionary test_squence_dic = (IronPython.Runtime.PythonDictionary)parse_result_dic["Test_Sequence"];
                if (Dictionary_Keys_ComparisonArray != null)
                    Dictionary_Keys_ComparisonArray.Clear();

                ///////////////////////////////////////////////////
                ///
                /*if (!PrevCheckTestVarification()) //지현 수정
                {
                    e.Cancel = true;
                    return;
                }
                */
                TestWorkerCheckCancel(e);
                
                /// 
                ///////////////////////////////////////////////////

                // AD File 생성여부 Flag
                MakeADFileCheckDic = new IronPython.Runtime.PythonDictionary();

                for (int i = 0; i < ViewModelLocator.ReportSettingVM.ReportSettingModel.TestInfoDictionary.keys().Count; i++)
                {
                    Dictionary_Keys_ComparisonArray.Add(Convert.ToString(ViewModelLocator.ReportSettingVM.ReportSettingModel.TestInfoDictionary.keys()[i]));
                }

                Dictionary_Keys_ComparisonArray.Sort();

                IronPython.Runtime.PythonDictionary runnable_flag_dic = null;
                if (ViewModelLocator.MainVM.MainModel.PROGRAM_MODE == Common.Common.CUSTOMER_WIA)
                {
                    runnable_flag_dic = new IronPython.Runtime.PythonDictionary();
                    foreach (string scenario_name in Dictionary_Keys_ComparisonArray)
                        runnable_flag_dic.Add(scenario_name, "0");
                }
                else
                    runnable_flag_dic = (IronPython.Runtime.PythonDictionary)parse_result_dic["Test Func Name"];



                Testcase_Count = new IronPython.Runtime.PythonDictionary();

                int Scenario_Cycle = 0;
                int TestCaseAllCount = 0;
                int TestCaseCurrentCount = 0;
                int PreconditionFlag = 0;


                for (int i = 0; i < ViewModelLocator.ReportSettingVM.ReportSettingModel.TestInfoDictionary.keys().Count; i++)
                {
                    IronPython.Runtime.PythonDictionary AllTestCaseCountTemp = (IronPython.Runtime.PythonDictionary)test_squence_dic.get(ViewModelLocator.ReportSettingVM.ReportSettingModel.TestInfoDictionary.keys()[i]);
                    IronPython.Runtime.PythonDictionary Scenario_Dic = new IronPython.Runtime.PythonDictionary();

                    for (int j = 0; j < AllTestCaseCountTemp.Count; j++)
                    {
                        Scenario_Dic.Add(j, false);
                    }

                    Testcase_Count.Add(ViewModelLocator.ReportSettingVM.ReportSettingModel.TestInfoDictionary.keys()[i], AllTestCaseCountTemp.Count);
                    TestCaseAllCount += AllTestCaseCountTemp.Count;
                    MakeADFileCheckDic.Add(ViewModelLocator.ReportSettingVM.ReportSettingModel.TestInfoDictionary.keys()[i], Scenario_Dic);

                }

                Total_AdFileList.Clear();

                foreach (string scenario_name in Dictionary_Keys_ComparisonArray)
                {
                    int TestZeroCount = 0;
                    if (TestRunWorker.CancellationPending)
                    {
                        e.Cancel = true;
                        return;
                    }

                    DirectoryInfo ScenarioFolderDI = new DirectoryInfo(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\ad\\" + scenario_name);
                    ScenarioFolderDI.Create();
                    ScenarioFolderDI = new DirectoryInfo(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\txt\\mcdc_cov\\" + scenario_name + "\\cov");
                    ScenarioFolderDI.Create();
                    ScenarioFolderDI = new DirectoryInfo(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\txt\\mcdc_cov\\" + scenario_name + "\\cba");
                    ScenarioFolderDI.Create();
                    ScenarioFolderDI = new DirectoryInfo(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\txt\\coverage\\" + scenario_name + "\\cov");
                    ScenarioFolderDI.Create();
                    ScenarioFolderDI = new DirectoryInfo(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\txt\\coverage\\" + scenario_name + "\\cba");
                    ScenarioFolderDI.Create();
                    ScenarioFolderDI = new DirectoryInfo(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\txt\\timing\\" + scenario_name);
                    ScenarioFolderDI.Create();
                    ScenarioFolderDI = new DirectoryInfo(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\txt\\trace\\" + scenario_name);
                    ScenarioFolderDI.Create();
                    ScenarioFolderDI = new DirectoryInfo(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Report\\" + scenario_name);
                    ScenarioFolderDI.Create();
                    ScenarioFolderDI = new DirectoryInfo(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\cba\\" + scenario_name);
                    ScenarioFolderDI.Create();

                    Trace32Handler.TRACE32_DLL.T32_SetChannel(Trace32Handler.ChannelT32Main); //T32 채널 연결
                    Trace32Handler.TRACE32_DLL.T32_Cmd("SYSTEM.UP");
                    ProstLog.getInstance().Log(Common.Common.MODULE_TRACE32, Common.Common.LOGTYPE_PGR, "SYSTEM.UP");
                    Trace32Handler.TRACE32_DLL.T32_Cmd("Break.Delete");
                    ProstLog.getInstance().Log(Common.Common.MODULE_TRACE32, Common.Common.LOGTYPE_PGR, "Break.Delete");

                    Trace32Handler.getInstance().FlashDownload(Common.Common.TRACE32_POWERVIEW);

                    // Input Runnable Flag 

                    string scenario_runnable = runnable_flag_dic.get(scenario_name).ToString();
                    RunnableModel tempModel = ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableList.Where(p => p.RunnableNameGrid.Substring(0, p.RunnableNameGrid.IndexOf("(")).Equals(scenario_runnable)).FirstOrDefault();

                    int enumIndex = ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableList.IndexOf(tempModel);

                    int bitConvert = 1 << enumIndex;
                    Trace32Handler.getInstance().T32_Command("Var.set run_func_flag=" + bitConvert, false);
                    ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PFF, "enumIndex [" + enumIndex + "]");


                    //

                    IronPython.Runtime.List test_info_list = (IronPython.Runtime.List)ViewModelLocator.ReportSettingVM.ReportSettingModel.TestInfoDictionary.get(scenario_name);
                    IronPython.Runtime.PythonDictionary test_squence_tmp = (IronPython.Runtime.PythonDictionary)test_squence_dic.get(scenario_name);
                    IronPython.Runtime.List squence_idx = test_squence_tmp.keys();

                    List<string> squence_idx_sort = new List<string>();

                    for (int i = 0; i < squence_idx.Count; i++)
                    {
                        squence_idx_sort.Add(squence_idx[i].ToString());
                    }
                    var comaprer = new CoordinatesBasedComparer();
                    squence_idx_sort.Sort(comaprer);

                    for (int i = 0; i < test_squence_tmp.Count + TestZeroCount; i++)
                    {
                        IronPython.Runtime.PythonDictionary test_info_temp = (IronPython.Runtime.PythonDictionary)test_info_list[i];
                        IronPython.Runtime.PythonDictionary ex_output = (IronPython.Runtime.PythonDictionary)test_info_temp.get("Expect Output Data");
                        IronPython.Runtime.List ex_outputkeyList = ex_output.keys();

                        TestWorklocker.WaitOne();

                        if (TestRunWorker.CancellationPending)
                        {
                            e.Cancel = true;
                            return;
                        }
                        Trace32Handler.TRACE32_DLL.T32_SetChannel(Trace32Handler.ChannelT32Main); //T32 채널 연결

                        IronPython.Runtime.List Sequence = (IronPython.Runtime.List)test_squence_tmp[squence_idx_sort[i - TestZeroCount].ToString()];
                        IronPython.Runtime.PythonDictionary _CreateTestResultTable = (IronPython.Runtime.PythonDictionary)test_info_list[i];

                        string TestID = _CreateTestResultTable["Test ID"].ToString(); // 예상값 비교를 위해 뽑음

                        IronPython.Runtime.PythonDictionary CreateTestResultData = new IronPython.Runtime.PythonDictionary();
                        IronPython.Runtime.PythonDictionary Runtime = new IronPython.Runtime.PythonDictionary();

                        IronPython.Runtime.PythonDictionary PreconditionDic = null;
                        IronPython.Runtime.PythonDictionary PreconditionValue = null;

                        if (ViewModelLocator.PopupTestCaseParsingVM.PopupTestCaseParsingModel.ParserSelectedItem.Equals("WiaUnitTestspecParser"))
                        {
                            if ((bool)_CreateTestResultTable.get("AutoGen") == true)
                            {
                                PreconditionDic = (IronPython.Runtime.PythonDictionary)Test_PreCondition_Dictionary[PreconditionFlag];
                                PreconditionFlag++;
                                if (PreconditionDic.get(Dictionary_Keys_ComparisonArray[Scenario_Cycle]).GetType().Name == "PythonDictionary")
                                {
                                    PreconditionValue = (IronPython.Runtime.PythonDictionary)PreconditionDic.get(Dictionary_Keys_ComparisonArray[Scenario_Cycle]);
                                    Trace32Handler.TRACE32_DLL.T32_SetChannel(Trace32Handler.ChannelT32Main);
                                    string PreconditionValueName = "";
                                    string PreconditionValueData = "";

                                    IronPython.Runtime.List PreconditionData = PreconditionValue.keys();
                                    for (int PreCnt = 0; PreCnt < PreconditionData.Count; PreCnt++)
                                    {
                                        PreconditionValueName = (string)PreconditionData[PreCnt];
                                        PreconditionValueData = (string)PreconditionValue.get(PreconditionData[PreCnt]);
                                        string T32CMD = "Var.set " + PreconditionValueName + "=" + PreconditionValueData;
                                        Trace32Handler.TRACE32_DLL.T32_Cmd(T32CMD);
                                    }

                                    if ((string)_CreateTestResultTable.get("Test ID") == "0" || (string)_CreateTestResultTable.get("Test ID") == "0.0" || (string)_CreateTestResultTable.get("Test ID") == "0.00")
                                    {
                                        for (int x = 0; x < ex_outputkeyList.Count; x++)
                                        {
                                            CreateTestResultData[ex_outputkeyList[x].ToString()] = "0";
                                            for (int k = 0; k < ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableList.Count; k++)
                                            {
                                                Runtime[ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableList[k].RunnableNameGrid] = "N/A";
                                            }
                                        }
                                        _CreateTestResultTable["Execution time"] = Runtime;
                                        _CreateTestResultTable["Actual Output Data"] = CreateTestResultData;
                                        //TestZeroCount += 1;
                                        //continue;
                                    }
                                }
                                else
                                {
                                    if ((string)_CreateTestResultTable.get("Test ID") == "0" || (string)_CreateTestResultTable.get("Test ID") == "0.0" || (string)_CreateTestResultTable.get("Test ID") == "0.00")
                                    {
                                        for (int x = 0; x < ex_outputkeyList.Count; x++)
                                        {
                                            CreateTestResultData[ex_outputkeyList[x].ToString()] = "0";
                                            for (int k = 0; k < ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableList.Count; k++)
                                            {
                                                Runtime[ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableList[k].RunnableNameGrid] = "N/A";
                                            }
                                        }
                                        _CreateTestResultTable["Execution time"] = Runtime;
                                        _CreateTestResultTable["Actual Output Data"] = CreateTestResultData;
                                        //TestZeroCount += 1;
                                        //continue;
                                    }
                                }
                            }
                            else if ((bool)_CreateTestResultTable.get("AutoGen") == false)
                            {
                                if ((string)_CreateTestResultTable.get("Test ID") == "0" || (string)_CreateTestResultTable.get("Test ID") == "0.0" || (string)_CreateTestResultTable.get("Test ID") == "0.00")
                                {
                                    for (int x = 0; x < ex_outputkeyList.Count; x++)
                                    {
                                        CreateTestResultData[ex_outputkeyList[x].ToString()] = "0";
                                        for (int k = 0; k < ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableList.Count; k++)
                                        {
                                            Runtime[ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableList[k].RunnableNameGrid] = "N/A";
                                        }
                                    }
                                    _CreateTestResultTable["Execution time"] = Runtime;
                                    _CreateTestResultTable["Actual Output Data"] = CreateTestResultData;
                                    //TestZeroCount += 1;
                                    //continue;
                                }
                            }
                        }
                        List<string> MacroOutputList = new List<string>(); // MACRO Output Script 수행 후 확인
                        bool isUserMacroOutput = false;
                        bool isDummySkip = false;

                        int LastGoScriptIndex = 0;

                        if (ex_outputkeyList[0].ToString().ToLower().Contains("user macro output"))
                            isUserMacroOutput = true;

                        if (isUserMacroOutput) // user macro expected output
                        {
                            for (int a = 0; a < Sequence.Count; a++)
                            {
                                if (Sequence[a].ToString().Contains("DUMMY"))
                                    isDummySkip = true;

                                if (Sequence[a].ToString().Contains("go.cmm"))
                                    LastGoScriptIndex = a;
                            }
                        }

                        for (int j = 0; j < Sequence.Count + 1; j++)
                        {
                            Trace32Handler.TRACE32_DLL.T32_SetChannel(Trace32Handler.ChannelT32Main);

                            if (j < Sequence.Count)
                            {
                                check = 1;
                                if (!isDummySkip)
                                {
                                    bitConvert = 1 << enumIndex;
                                    Trace32Handler.getInstance().T32_Command("Var.set run_func_flag=" + bitConvert, false);
                                    Trace32Handler.TRACE32_DLL.T32_Cmd(Sequence[j].ToString().Trim());
                                    Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref check);
                                    while (check != 0)
                                    {
                                        Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref check);
                                    }
                                }
                                else
                                {
                                    if (LastGoScriptIndex == j)
                                    {
                                        Trace32Handler.TRACE32_DLL.T32_Cmd(Sequence[j].ToString().Trim());
                                        Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref check);
                                        while (check != 0)
                                        {
                                            Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref check);
                                        }
                                    }

                                    if (!Sequence[j].ToString().Trim().Contains("go.cmm"))
                                    {
                                        Trace32Handler.TRACE32_DLL.T32_Cmd(Sequence[j].ToString().Trim());
                                        Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref check);
                                        while (check != 0)
                                        {
                                            Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref check);
                                        }
                                    }
                                }


                                if (Sequence[j].ToString().Trim().Equals("system.RESetTarget"))
                                {
                                    if (ViewModelLocator.MainVM.MainModel.IsTestSimulationEnable)
                                    {
                                        Trace32Handler.getInstance().FlashDownload(Common.Common.TRACE32_POWERVIEW);
                                        bitConvert = 1 << enumIndex;
                                        Trace32Handler.getInstance().T32_Command("Var.set run_func_flag=" + bitConvert, false);
                                    }
                                }
                                if (Sequence[j].ToString().Contains("stm_save.cmm"))
                                {
                                    bitConvert = 1 << enumIndex;
                                    Trace32Handler.getInstance().T32_Command("Var.set run_func_flag=" + bitConvert, false);
                                }
                                if (isUserMacroOutput && LastGoScriptIndex < j)
                                {
                                    UInt16 msg = 0;
                                    StringBuilder resultTemp = new StringBuilder("0", 256);

                                    Trace32Handler.TRACE32_DLL.T32_GetMessage(resultTemp, ref msg);

                                    if (resultTemp.ToString().Contains("ERROR") || resultTemp.ToString().Contains("dummy"))
                                    {
                                        MacroOutputList.Add("ERROR");
                                    }
                                    else if (resultTemp.ToString().StartsWith("0x"))
                                    {
                                        if (CommonUtil.IsHex(resultTemp.ToString().Replace("0x", "")))
                                            MacroOutputList.Add(Convert.ToInt64(resultTemp.ToString().Replace("0x", "").Trim(), 16).ToString());
                                        else
                                            MacroOutputList.Add("ERROR");
                                    }
                                    else
                                    {
                                        MacroOutputList.Add(Convert.ToInt64(resultTemp.ToString().Trim()).ToString());
                                    }
                                }
                            }
                            else if (j >= Sequence.Count)
                            {
                                UInt16[] pBuffer = new UInt16[4];
                                check = 1;

                                if (ViewModelLocator.MenuBarVM.IsADFileGenerator)
                                {
                                    string DataInput = "CD.DO \"" + Common.Common.INSTALL_PATH + "\\src\\parser\\Cmm\\Templete\\trace_save.cmm\" " + "_" + TestID + ".ad \"" + ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\ad\\" + scenario_name + "\"";

                                    Trace32Handler.TRACE32_DLL.T32_Cmd(DataInput);
                                    Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref check);
                                    while (check != 0)
                                    {
                                        Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref check);
                                    }

                                    UInt16 msg = 0;
                                    StringBuilder resultTemp = new StringBuilder("0", 256);

                                    Trace32Handler.TRACE32_DLL.T32_GetMessage(resultTemp, ref msg);
                                    string str = resultTemp.ToString();

                                    ProstLog.getInstance().Log(Common.Common.MODULE_TRACE32, Common.Common.LOGTYPE_PGR, "Trace Save T32_GetMessage [" + str + "]");
                                    Trace32Handler.TRACE32_DLL.T32_Cmd("print \"TRACE SAVE\"");

                                    ((IronPython.Runtime.PythonDictionary)MakeADFileCheckDic[scenario_name])[i] = true;
                                }

                                for (int x = 0; x < ex_outputkeyList.Count; x++)
                                {
                                    if (ex_outputkeyList[x].ToString().ToLower().Contains("user macro output"))
                                    {
                                        string ActualDataResultStr = "";
                                        string[] ExpectedoutputSplit = ex_output.ElementAt(x).Value.ToString().Split(new string[] { "\n" }, StringSplitOptions.None);
                                        for (int a = 0; a < ExpectedoutputSplit.Length; a++)
                                        {
                                            string[] OutputSplit = ExpectedoutputSplit[a].Split(new string[] { "==" }, StringSplitOptions.None);

                                            if (OutputSplit.Length >= 2)
                                            {
                                                if (OutputSplit[1].Contains("MS("))
                                                {
                                                    if (ExpectedoutputSplit.Length > 1)
                                                        ActualDataResultStr += OutputSplit[0] + "==" + " MS(" + MacroOutputList[a] + ")" + "\n";
                                                    else
                                                        ActualDataResultStr += OutputSplit[0] + "==" + " MS(" + MacroOutputList[a] + ")";
                                                }
                                                else
                                                {
                                                    if (ExpectedoutputSplit.Length > 1)
                                                        ActualDataResultStr += OutputSplit[0] + "==" + MacroOutputList[a] + "\n";
                                                    else
                                                        ActualDataResultStr += OutputSplit[0] + "==" + MacroOutputList[a];
                                                }
                                            }
                                            else
                                            {
                                                if (ExpectedoutputSplit.Length > 1)
                                                    ActualDataResultStr += OutputSplit[0] + "\n";
                                                else
                                                    ActualDataResultStr += OutputSplit[0];
                                            }
                                        }
                                        // for ExpectedoutputSplit count
                                        // string[] ExpectedoutputSplit "=="
                                        // for 앞에만 가지고오고 뒤에는 실제값 넣고 string 변수에 저장해 저장한거를 아래 CreateSe d
                                        if (ActualDataResultStr.Contains("DUMMY"))
                                            CreateTestResultData[ex_outputkeyList[x].ToString()] = "DUMMY";
                                        else
                                            CreateTestResultData[ex_outputkeyList[x].ToString()] = ActualDataResultStr;
                                    }
                                    else
                                    {
                                        StringBuilder resultTemp = new StringBuilder("0", 256);
                                        UInt16 msg = 0;

                                        Trace32Handler.TRACE32_DLL.T32_Cmd("print %d Var.fvalue(" + ex_outputkeyList[x].ToString() + ")");
                                        Trace32Handler.TRACE32_DLL.T32_GetMessage(resultTemp, ref msg);

                                        string str = resultTemp.ToString();
                                        ProstLog.getInstance().Log(Common.Common.MODULE_TRACE32, Common.Common.LOGTYPE_PFF, "Print Var.fValue T32_GetMessage [" + str + "]");
                                        CreateTestResultData[ex_outputkeyList[x].ToString()] = str;
                                    }
                                }

                                for (int k = 0; k < ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableList.Count; k++)
                                {
                                    Runtime[ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableList[k].RunnableNameGrid] = "N/A";
                                }

                                while (true)
                                {
                                    Trace32Handler.TRACE32_DLL.T32_ReadMemory((timer_addr + addr_idx), 16, ref pBuffer[0], 4);
                                    UInt32 time_flag = ((UInt32)pBuffer[3] << 24) + ((UInt32)pBuffer[2] << 16) + ((UInt32)pBuffer[1] << 8) + (UInt32)pBuffer[0];
                                    Trace32Handler.TRACE32_DLL.T32_ReadMemory(timer_addr + addr_idx + 0xC, 16, ref pBuffer[0], 4);
                                    UInt32 timeData = ((UInt32)pBuffer[3] << 24) + ((UInt32)pBuffer[2] << 16) + ((UInt32)pBuffer[1] << 8) + (UInt32)pBuffer[0];

                                    ProstLog.getInstance().Log(Common.Common.MODULE_TRACE32, Common.Common.LOGTYPE_PGR, "timeData [" + timeData + "]");
                                    if (ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.TimerTick <= 0)
                                        time_value = timeData * 10.0;
                                    else
                                        time_value = timeData * ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.TimerTick;

                                    if (time_value == 0x0)
                                        break;

                                    string TimeDistribution = "";

                                    TimeDistribution = (time_value / 1000).ToString();
                                    Runtime[ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableList[(int)time_flag].RunnableNameGrid] = TimeDistribution;
                                    addr_idx += 0x10;

                                }

                                _CreateTestResultTable["Execution time"] = Runtime;

                                if (Runtime != null)
                                {
                                }
                                else
                                    Console.WriteLine("NULL Point");

                                //키 - "Test Info" 값 : 리스트
                                //키 - "Test ID, Input(딕셔너리 키 - 변수명 - 값 - 변수값), exoutput(딕셔너리 키 - 변수명 - 값 - 변수값), toleranc" 
                                _CreateTestResultTable["Actual Output Data"] = CreateTestResultData;
                                test_info_list[i] = _CreateTestResultTable;

                                if (ViewModelLocator.MenuBarVM.IsADFileGenerator)
                                {
                                    // AD FLAG
                                    if (ThreadFlag == 0)
                                    {
                                        CoverageSimulatorControlThread = new Thread(() => CoverageReportPostProcessing(ViewModelLocator.ReportSettingVM.ReportSettingModel.TestInfoDictionary.Count, TestCaseAllCount));
                                        CoverageSimulatorControlThread.Start();
                                    }
                                    else
                                    {
                                        if (ThreadFlag == 1)
                                        {
                                            Thread.Sleep(1);
                                        }
                                        else if (ThreadFlag == 2)
                                        {
                                            ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, "AD file generation error.");
                                            ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, "End the test.");
                                            ViewModelLocator.MainVM.showTrackBarMessage("The AD file is not generated, terminates the process.");


                                            if (CoverageSimulatorControlThread != null && CoverageSimulatorControlThread.IsAlive)
                                            {
                                                CoverageSimulatorControlThread.Interrupt();
                                                CoverageSimulatorControlThread.Abort();
                                            }
                                            return;
                                        }
                                        else
                                        {
                                        }
                                    }
                                }
                            }
                            else
                            {
                                Console.WriteLine("TRACE32 Error");
                            }

                        }

                        TestCaseCurrentCount++;
                        TestProgress += (double)(65.0 / TestCaseAllCount);
                        ViewModelLocator.PopupTestStatusVM.PopupTestStatusModel.TestcaseProgressText = "( " + TestCaseCurrentCount + " / " + TestCaseAllCount + " )";
                        TestRunWorker.ReportProgress(31, new ProgressState { Value = TestProgress, Content = "Running Test..." });

                        Thread.Sleep(1000);
                    }

                    //지현 확인
                    if (Dictionary_Keys_ComparisonArray.Count == Scenario_Cycle + 1)
                    {
                        TestRunWorker.ReportProgress(0, new ProgressState { Value = 100, Content = "Measuring Stack Usage..." });
                    }
                    else
                    {
                        TestRunWorker.ReportProgress(0, new ProgressState { Value = TestProgress, Content = "Measuring Stack Usage..." });
                    }

                    ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PFF, "StackUsage Start");
                    ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PFF, "StackUsage Start");
                    ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PFF, "Stack Start Address : " + "0x" + ViewModelLocator.ReportSettingVM.ReportSettingModel.StartAddressValue);
                    ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PFF, "Stack Stop Address : " + "0x" + ViewModelLocator.ReportSettingVM.ReportSettingModel.EndAddressValue);

                    Trace32Handler.getInstance().StackUsage();

                    string StackPointer_Hex = ViewModelLocator.ReportSettingVM.ReportSettingModel.StackPointer.ToString("X");
                    ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PFF, "Stack Point Address : " + "0x" + StackPointer_Hex);

                    ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PGR, "StackUsage Finish");

                    ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PGR, "StackUsage Save Start");

                    ViewModelLocator.ReportSettingVM.ReportSettingModel.StackInfoValueDictionary["Stack Start Address"] = "0x" + ViewModelLocator.ReportSettingVM.ReportSettingModel.StartAddressValue;
                    ViewModelLocator.ReportSettingVM.ReportSettingModel.StackInfoValueDictionary["Stack End Address"] = "0x" + ViewModelLocator.ReportSettingVM.ReportSettingModel.EndAddressValue;
                    ViewModelLocator.ReportSettingVM.ReportSettingModel.StackInfoValueDictionary["Stack Pointer"] = "0x" + StackPointer_Hex;
                    ViewModelLocator.ReportSettingVM.ReportSettingModel.StackInfoDictionary.Add(scenario_name, ViewModelLocator.ReportSettingVM.ReportSettingModel.StackInfoValueDictionary);
                    ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PGR, "StackUsage Save Finish");

                    ViewModelLocator.ReportSettingVM.ReportSettingModel.TestInfoDictionary[scenario_name] = test_info_list;
                    Thread.Sleep(10);

                    timer_addr = 0x90000010;
                    addr_idx = 0x0;
                    ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PFF, "Data.DUMP VM: Initialization");

                    Trace32Handler.TRACE32_DLL.T32_Cmd("PMACRO.RESET");
                    Trace32Handler.TRACE32_DLL.T32_Cmd("END");

                    ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PFF, "TRACE32 PMACRO.RESET");
                    ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PFF, "TRACE32 END");

                    Scenario_Cycle++;
                }
                TestRunWorker.ReportProgress(100, new ProgressState { Value = 100, Content = "Please wait a moment..." });

                if (ViewModelLocator.MenuBarVM.IsADFileGenerator)
                {
                    if (CoverageSimulatorControlThread != null)
                        CoverageSimulatorControlThread.Join();
                    for (int i = 0; i < ScenarioThreadList.Count; i++)
                    {
                        if (ScenarioThreadList[i] != null)
                            ScenarioThreadList[i].Join();
                    }
                }

                if (ViewModelLocator.MenuBarVM.IsADFileGenerator)
                {
                    if (CoverageSimulatorControlThread != null)
                        CoverageSimulatorControlThread.Join();
                    for (int i = 0; i < ScenarioThreadList.Count; i++)
                    {
                        if (ScenarioThreadList[i] != null)
                            ScenarioThreadList[i].Join();
                    }
                }

                if (ViewModelLocator.MenuBarVM.IsADFileGenerator)
                {
                    TestRunWorker.ReportProgress(100, new ProgressState { Value = 100, Content = "Total Coverage Measurment..." });
                    // Get Total Coverage
                    string ad_temp = ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\ad\\Total\\Total.txt";
                    FileManager.FileSave_List(ad_temp, Total_AdFileList);
                    string ADFileMergeCMM = Common.Common.INSTALL_PATH + "\\src\\parser\\Cmm\\Templete\\ad_Merge.cmm\"";
                    int T32ScriptRun = 1;
                    Trace32Handler.TRACE32_DLL.T32_SetChannel(Trace32Handler.ChannelT32SimulMerge);

                    Trace32Handler.TRACE32_DLL.T32_Cmd("sYmbol.SourcePATH.SetBaseDir " + @"C:\Users\CSA_DEV\Documents\Working\Prost_v2.0\Workspace\MANDO_FailSafe_Integration\Target_SW");
                    Trace32Handler.TRACE32_DLL.T32_Cmd("symbol.eca.loadall /SkipErrors");

                    Trace32Handler.TRACE32_DLL.T32_Cmd("CD.DO \"" + ADFileMergeCMM + " " + "\"" + "0" + ".||" + ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug" + "||" + "Total" + "\"");
                    Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref T32ScriptRun);
                    while (T32ScriptRun != 0)
                    {
                        Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref T32ScriptRun);
                    }



                    // Create Total Coverage Report
                    Trace32Handler.TRACE32_DLL.T32_SetChannel(Trace32Handler.ChannelT32SimulMerge);
                    Trace32Handler.TRACE32_DLL.T32_Cmd("CD.DO \"..\\..\\..\\lib\\T32\\multi_file_report\\create_report.cmm\"" + " " + "\"" + ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Report\\Total" + "\"" + " " + "\"SYMBOL\"");
                    Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref check);
                    while (check != 0)
                    {
                        Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref check);
                    }
                }

                if (TestRunWorker.CancellationPending)
                {
                    e.Cancel = true;
                    return;
                }

                if (!PythonHandler.getInstance().makeProjectData())
                {
                    ViewModelLocator.MainVM.showTrackBarMessage("Please Check the Dictionary File");
                    return;
                }
                TestRunWorker.ReportProgress(100, new ProgressState { Value = 100, Content = "Creating Report Data..." });
                PythonHandler.getInstance().makeReportData();
                DirectoryInfo reportDI;
                if (ViewModelLocator.MenuBarVM.IsADFileGenerator)
                {
                    string RemoveBakPath = ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\" + "Report";
                    string[] Directories = Directory.GetDirectories(RemoveBakPath);
                    for (int i = 0; i < Directories.Length; i++)
                    {
                        bool Check = false;
                        Check = Directories[i].Contains(".bak");

                        if (Check)
                        {
                            reportDI = new DirectoryInfo(Directories[i]);
                            if (reportDI.Exists)
                            {
                                Directory.Delete(Directories[i], true);
                            }
                        }
                    }

                    Thread.Sleep(1000);


                    Trace32Handler.getInstance().Trace_Info_Paser();
                }

                if (!PythonHandler.getInstance().makeProjectData())
                {
                    ViewModelLocator.MainVM.showTrackBarMessage("Please Check the Dictionary File");
                    return;
                }

                PythonHandler.getInstance().ReportCall();


                if (!Common.Common.DEBUG_MODE)
                {
                    Trace32Handler.TRACE32_DLL.T32_SetChannel(Trace32Handler.ChannelT32Main);
                    Trace32Handler.TRACE32_DLL.T32_Cmd("QUIT");
                    Trace32Handler.TRACE32_DLL.T32_Exit();
                    Thread.Sleep(10);

                    if (ViewModelLocator.MenuBarVM.IsADFileGenerator)
                    {
                        Trace32Handler.TRACE32_DLL.T32_SetChannel(Trace32Handler.ChannelT32SimulAnalysis);
                        Trace32Handler.TRACE32_DLL.T32_Cmd("QUIT");
                        Trace32Handler.TRACE32_DLL.T32_Exit();
                        Thread.Sleep(10);

                        Trace32Handler.TRACE32_DLL.T32_SetChannel(Trace32Handler.ChannelT32SimulMerge);
                        Trace32Handler.TRACE32_DLL.T32_Cmd("QUIT");
                        Trace32Handler.TRACE32_DLL.T32_Exit();
                    }

                    ViewModelLocator.MainVM.MainModel.IsTrace32Connection = false;
                }
            }
            catch (Exception ex)
            {

                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, typeof(FunctionWorkHandler).Name + " :: " + ex.Message + " Line :: " + CommonUtil.GetExceptionLineNumber(ex));
            }
        }


        List<Thread> ScenarioThreadList;
        /// <summary>
        /// Coverage Simulator에서 AD파일을 기반으로 Timing과 Coverage Data를 추출하는 동작 수행
        /// </summary>
        public void CoverageReportPostProcessing(int TestScenarioCount, int TestCaseAllCount)
        {
            try
            {
                ThreadFlag = 1;
                int CreateCheckCount = 0;
                int TestAnalysysCount = 0;
                ScenarioThreadList = new List<Thread>();

                List<string> ad_file_list = new List<string>();


                for (int TestScenarioIndex = 0; TestScenarioIndex < TestScenarioCount; TestScenarioIndex++)
                {
                    ad_file_list.Clear();
                    for (int TestSequenceIndex = 0; TestSequenceIndex < (int)Testcase_Count.get(Dictionary_Keys_ComparisonArray[TestScenarioIndex]); TestSequenceIndex++)
                    {
                    CreateADFileWait:
                        CoverageAnalysisWorklocker.WaitOne();
                        IronPython.Runtime.List test_list = (IronPython.Runtime.List)ViewModelLocator.ReportSettingVM.ReportSettingModel.TestInfoDictionary[Dictionary_Keys_ComparisonArray[TestScenarioIndex]];
                        IronPython.Runtime.PythonDictionary temp = (IronPython.Runtime.PythonDictionary)test_list[TestSequenceIndex];

                        string Id = temp["Test ID"].ToString();

                        ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PGR, "AD File Load Thread Test ID :: " + Id);

                        string DefaultPath = ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\ad\\" + Dictionary_Keys_ComparisonArray[TestScenarioIndex] + "\\" + "Trace_" + Id + ".ad";

                        if (!ad_file_list.Contains(DefaultPath))
                        {
                            ad_file_list.Add(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\ad\\" + Dictionary_Keys_ComparisonArray[TestScenarioIndex] + "\\" + "Trace_" + Id + ".ad");
                            Total_AdFileList.Add(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\ad\\" + Dictionary_Keys_ComparisonArray[TestScenarioIndex] + "\\" + "Trace_" + Id + ".ad");
                        }

                        ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PGR, "DefaultPath [" + DefaultPath + "]");


                        FileInfo fileInfo = new FileInfo(DefaultPath);
                        bool makeADfile = (bool)((IronPython.Runtime.PythonDictionary)MakeADFileCheckDic[Dictionary_Keys_ComparisonArray[TestScenarioIndex]])[TestSequenceIndex];
                        ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PGR, "makeADfile [" + makeADfile + "]" + "//" + "TestScenarioIndex [" + TestScenarioIndex + "]" + "//" + "TestSequenceIndex [" + TestSequenceIndex + "]");
                        if (fileInfo.Exists && makeADfile)
                        {
                        CreateCovFileWait:

                            MakeAD2TextFile(TestScenarioIndex, TestSequenceIndex);

                            IronPython.Runtime.List test_list_1 = (IronPython.Runtime.List)ViewModelLocator.ReportSettingVM.ReportSettingModel.TestInfoDictionary[Dictionary_Keys_ComparisonArray[TestScenarioIndex]];
                            IronPython.Runtime.PythonDictionary temp_1 = (IronPython.Runtime.PythonDictionary)test_list_1[TestSequenceIndex];

                            string Id_1 = temp_1["Test ID"].ToString();
                            string ResultPath = ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\txt\\coverage\\" + Dictionary_Keys_ComparisonArray[TestScenarioIndex] + "\\cov\\" + "cov" + Id_1 + ".txt";

                            FileInfo ResultFileInfo = new FileInfo(ResultPath);

                            if (!ResultFileInfo.Exists)
                            {
                                goto CreateCovFileWait;
                            }
                            CreateCheckCount = 0;
                            ThreadFlag = 1;
                        }
                        else
                        {
                            if (CreateCheckCount < ViewModelLocator.MenuBarVM.ADFileCheckTime)
                            {
                                Thread.Sleep(1000);
                                CreateCheckCount++;
                                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PGR, "CreateCheckCount [" + CreateCheckCount + "]");
                                goto CreateADFileWait;
                            }
                            else
                            {
                                if (TestRunWorker != null)
                                    TestRunWorker.CancelAsync();

                                Dispatcher dispatcher = System.Windows.Application.Current.Dispatcher;
                                DispatcherOperation dispatcherOperation = dispatcher.BeginInvoke(System.Windows.Threading.DispatcherPriority.Send, (ThreadStart)
                                delegate ()
                                {
                                    if (Common.Common.m_PopupTestStatusView != null)
                                        Common.Common.m_PopupTestStatusView.Close();
                                });

                                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, "AD file not found.");
                                ThreadFlag = 2;
                                return;
                            }
                        }

                        TestAnalysysCount++;
                        ViewModelLocator.PopupTestStatusVM.PopupTestStatusModel.TestAnalysysProgress = ((double)((100.0 / TestCaseAllCount)) * TestAnalysysCount);
                    }

                    string ad_temp = ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\ad\\" + Dictionary_Keys_ComparisonArray[TestScenarioIndex] + "\\" + Dictionary_Keys_ComparisonArray[TestScenarioIndex] + ".txt";
                    FileManager.FileSave_List(ad_temp, ad_file_list);


                    ScenarioThreadList.Add(new Thread(() => MergeDataThread(ScenarioThreadList.Count - 1, TestScenarioCount)));
                    ScenarioThreadList[ScenarioThreadList.Count - 1].Start();
                }

                ViewModelLocator.PopupTestStatusVM.PopupTestStatusModel.TestAnalysysProgress = 100;

                ThreadFlag = 3;
            }
            catch (Exception ex)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, typeof(FunctionWorkHandler).Name + " :: " + ex.Message + " Line :: " + CommonUtil.GetExceptionLineNumber(ex));
            }
        }
        private object lockObject = new object();
        /// <summary>
        /// Coverage Simulator에서 시나리오가 끝날 때 마다 Data Merage작업과 CallCoverage 작업을 수행하는 함수
        /// 시나리오마다 Thread가 새로 생성
        /// </summary>
        public void MergeDataThread(int scenarioIndex, int total_scenariocount)
        {
            try
            {
                while (true)
                {
                    lock (lockObject)
                    {
                        MergeAnalysisWorklocker.WaitOne();
                        ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PGR, "MergeDataThread Start :: " + scenarioIndex);
                        int T32ScriptRun = 1;
                        string ADFileMergeCMM = Common.Common.INSTALL_PATH + "\\src\\parser\\Cmm\\Templete\\ad_Merge.cmm\"";
                        Trace32Handler.TRACE32_DLL.T32_SetChannel(Trace32Handler.ChannelT32SimulMerge);
                        Trace32Handler.TRACE32_DLL.T32_Cmd("sYmbol.SourcePATH.SetBaseDir " + @"C:\Users\CSA_DEV\Documents\Working\Prost_v2.0\Workspace\MANDO_FailSafe_Integration\Target_SW");
                        Trace32Handler.TRACE32_DLL.T32_Cmd("symbol.eca.loadall /SkipErrors");

                        Trace32Handler.TRACE32_DLL.T32_Cmd("CD.DO \"" + ADFileMergeCMM + " " + "\"" + Testcase_Count.get(Dictionary_Keys_ComparisonArray[scenarioIndex]).ToString() + ".||" + ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug" + "||" + Dictionary_Keys_ComparisonArray[scenarioIndex] + "\"");
                        Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref T32ScriptRun);
                        while (T32ScriptRun != 0)
                        {
                            Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref T32ScriptRun);
                        }

                        MultiFileReport(scenarioIndex);
                        MakeAD2FunctionList(scenarioIndex);

                        PythonHandler.getInstance().makeProjectData();

                        if (ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.CpuName.Equals("tc39x"))
                            PythonHandler.getInstance().TraceVarParserCall();

                        ViewModelLocator.PopupTestStatusVM.PopupTestStatusModel.TestMergeDataProgress = ((double)((100.0 / total_scenariocount)) * ScenarioThreadList.Count);
                        return;
                    }
                }
            }
            catch (Exception ex)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, typeof(FunctionWorkHandler).Name + " :: " + ex.Message + " Line :: " + CommonUtil.GetExceptionLineNumber(ex));
            }
        }
        /// <summary>
        /// ad_load.cmm을 사용하여 ad파일을 기반으로 Coverage, timing, trace list등을 txt파일로 추출하는 동작 수행
        /// </summary>
        public void MakeAD2TextFile(int TestScenarioIndex, int TestSequenceIndex)
        {
            try
            {
                string ADLoadCMM = "";
                int TRACERunFlag = 1;

                //IronPython.Runtime.List scenario_list = (IronPython.Runtime.List)ViewModelLocator.ReportSettingVM.ReportSettingModel.TestInfoDictionary.keys();
                IronPython.Runtime.List test_list = (IronPython.Runtime.List)ViewModelLocator.ReportSettingVM.ReportSettingModel.TestInfoDictionary[Dictionary_Keys_ComparisonArray[TestScenarioIndex]];
                IronPython.Runtime.PythonDictionary temp = (IronPython.Runtime.PythonDictionary)test_list[TestSequenceIndex];
                string Id = temp["Test ID"].ToString();


                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PGR, "MakeAD2TextFile Thread Test ID :: " + Id);

                Trace32Handler.TRACE32_DLL.T32_SetChannel(Trace32Handler.ChannelT32SimulAnalysis);

                Trace32Handler.TRACE32_DLL.T32_Cmd("COVerage.Init");
                ADLoadCMM = Common.Common.INSTALL_PATH + "\\src\\parser\\Cmm\\Templete\\ad_load.cmm\"";

                int coreindex = 0;
                for (int i = 0; i < ViewModelLocator.TargetHWSettingVM.CoreList.Count; i++)
                {
                    if (ViewModelLocator.TargetHWSettingVM.CoreList[i] == true)
                    {
                        coreindex = i;
                        break;
                    }
                }

                Trace32Handler.TRACE32_DLL.T32_Cmd("CD.DO \"" + ADLoadCMM + " " + "\"" + Testcase_Count.get(Dictionary_Keys_ComparisonArray[TestScenarioIndex]).ToString() + ".||" + ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug" + "||" + Dictionary_Keys_ComparisonArray[TestScenarioIndex] + "||" + Id + "||" + Path.GetFileNameWithoutExtension(ViewModelLocator.PopupTestCaseParsingVM.PopupTestCaseParsingModel.TestStatement) + "\" " + "\"" + coreindex + "\"");
                Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref TRACERunFlag);
                while (TRACERunFlag != 0)
                {
                    Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref TRACERunFlag);
                }
                Trace32Handler.TRACE32_DLL.T32_Cmd("COVerage.Add");
            }
            catch (Exception ex)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, typeof(FunctionWorkHandler).Name + " :: " + ex.Message + " Line :: " + CommonUtil.GetExceptionLineNumber(ex));
            }
        }
        /// <summary>
        /// ad 파일을 로드하여 Callcoverage를 추출하는 작업을 수행하는 함수
        /// </summary>
        public void MakeAD2FunctionList(int TestScenarioIndex)
        {
            try
            {
                Trace32Handler.TRACE32_DLL.T32_SetChannel(Trace32Handler.ChannelT32SimulMerge);

                Trace32Handler.TRACE32_DLL.T32_Cmd("PRINT \"MakeAD2FunctionList Start\"");

                FunctionListFileCreation();
                string DefaultPath = ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\txt\\funccall_cov\\call\\" + Dictionary_Keys_ComparisonArray[TestScenarioIndex];
                DirectoryInfo di = new DirectoryInfo(DefaultPath);
                di.Create();

                string TraceFileName = "CallCoverageData";
                FunctionCallCoverageFileCreation(DefaultPath, TraceFileName);
            }
            catch (Exception ex)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, typeof(FunctionWorkHandler).Name + " :: " + ex.Message + " Line :: " + CommonUtil.GetExceptionLineNumber(ex));
            }
        }
        /// <summary>
        /// Coverage xml Report 생성스크립트 (create_report.cmm)를 호출하는 함수
        /// </summary>
        public void MultiFileReport(int i)
        {
            int check = 1;
            Trace32Handler.TRACE32_DLL.T32_SetChannel(Trace32Handler.ChannelT32SimulMerge);
            Trace32Handler.TRACE32_DLL.T32_Cmd("CD.DO \"..\\..\\..\\lib\\T32\\multi_file_report\\create_report.cmm\"" + " " + "\"" + ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Report\\" + Dictionary_Keys_ComparisonArray[i] + "\"" + " " + "\"SYMBOL\"");
            Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref check);
            while (check != 0)
            {
                Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref check);
            }
            Trace32Handler.TRACE32_DLL.T32_Cmd("PRINT \"MultiFileReport END\"");
        }
        /// <summary>
        /// 소스코드안에 함수 목록을 추출해 주는 함수
        /// </summary>
        public void FunctionCallCoverageFileCreation(string DefaultPath, string TraceFileName)
        {
            string[] FunctionList = null;

            DirectoryInfo di = new DirectoryInfo(DefaultPath + "\\" + TraceFileName);
            di.Create();

            for (int i = 0; i < ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.TestCodeList.Count; i++)
            {
                string SourceFilePath = ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\txt\\funccall_cov\\all\\" + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.TestCodeList[i] + ".txt";
                FunctionList = FunctionListParser(SourceFilePath);

                for (int j = 1; j < FunctionList.Length - 1; j++)
                {
                    if (FunctionList[j] == null || FunctionList[j] == "")
                    {
                    }
                    else
                    {
                        string CMD;
                        CMD = "PRinTer.FILE \"" + DefaultPath + "\\" + TraceFileName + "\\" + FunctionList[j] + ".txt\"" + " ASCIIE";
                        Trace32Handler.TRACE32_DLL.T32_Cmd(CMD);

                        CMD = "WinTABS 100. 20. 20. 20.";
                        Trace32Handler.TRACE32_DLL.T32_Cmd(CMD);

                        CMD = "WinPrint.list sYmbol.RANGE(" + FunctionList[j] + ") /COV";
                        Trace32Handler.TRACE32_DLL.T32_Cmd(CMD);
                    }
                }
            }

        }
        /// <summary>
        /// 함수 리스트를 Parsing하여 반환해주는 함수
        /// </summary>
        public string[] FunctionListParser(string Path)
        {
            string FunctionListFile = System.IO.File.ReadAllText(Path);
            string[] FunctionList = null;
            string[] FunctionTemp = null;
            string[] FunctionListRow = FunctionListFile.Split(new string[] { "\n" }, StringSplitOptions.None);

            FunctionList = new string[FunctionListRow.Length - 1];
            for (int i = 1; i < FunctionListRow.Length; i++)
            {
                FunctionTemp = FunctionListRow[i].Split(new string[] { "|" }, StringSplitOptions.None);
                if (FunctionTemp[0] == "" || FunctionTemp[0] == null)
                {

                }
                else
                    FunctionList[i - 1] = FunctionTemp[0].Trim();
            }

            return FunctionList;
        }
        /// <summary>
        ///
        /// </summary>
        public void FunctionListFileCreation()
        {
            for (int i = 0; i < ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.TestCodeList.Count; i++)
            {
                int check = 1;
                string SavePath = ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\txt\\funccall_cov\\all\\" + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.TestCodeList[i] + ".txt";
                Trace32Handler.TRACE32_DLL.T32_Cmd("CD.DO \"" + Common.Common.INSTALL_PATH + "\\src\\parser\\Cmm\\Templete\\Funcall.cmm\"" + " " + "\"" + SavePath + "\"" + " " + "\"" + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.TestCodeList[i] + "\"");
                Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref check);
                while (check != 0)
                {
                    Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref check);
                }
            }
        }
        /// <summary>
        /// PopupTestStatusView에서 Progress의 값을 Update 해주는 함수
        /// </summary>
        private void TestRunWorker_ProgressChanged(object sender, ProgressChangedEventArgs e)
        {
            ProgressState state = e.UserState as ProgressState;
            if (state == null)
                return;

            ViewModelLocator.PopupTestStatusVM.PopupTestStatusModel.TestStatusProgress = state.Value;
            ViewModelLocator.PopupTestStatusVM.PopupTestStatusModel.TestStatusText = state.Content;
        }
        private void TestRunWorker_DoWorkComplete(object sender, RunWorkerCompletedEventArgs e)
        {
            try
            {
                if (e.Cancelled)
                {
                    CommonUtil.ExitExcelProcess();
                    CommonUtil.ExitPythonProcess();
                    ViewModelLocator.PopupTestStatusVM.PopupTestStatusModel.TestStateMode = Common.Common.STOP;

                    Dispatcher dispatcher = System.Windows.Application.Current.Dispatcher;
                    DispatcherOperation dispatcherOperation = dispatcher.BeginInvoke(System.Windows.Threading.DispatcherPriority.Send, (ThreadStart)
                    delegate ()
                    {
                        if (Common.Common.m_PopupTestStatusView != null)
                            Common.Common.m_PopupTestStatusView.Close();
                    });


                    if (CoverageSimulatorControlThread != null && CoverageSimulatorControlThread.IsAlive)
                    {
                        CoverageSimulatorControlThread.Interrupt();
                        CoverageSimulatorControlThread.Abort();
                    }

                    if (Directory.Exists(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\ad"))
                        CommonUtil.ClearAttributes(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\ad");
                    if (Directory.Exists(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\dic\\project_info"))
                        CommonUtil.ClearAttributes(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\dic\\project_info");
                    if (Directory.Exists(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\txt"))
                        CommonUtil.ClearAttributes(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\txt");
                    if (Directory.Exists(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\cba"))
                        CommonUtil.ClearAttributes(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\Debug\\cba");
                    ViewModelLocator.MainVM.showTrackBarMessage("Test Stopped");

                    ViewModelLocator.MainVM.MainModel.IsTrace32Connection = false;
                }
            }
            catch (Exception ex)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, typeof(FunctionWorkHandler).Name + " :: " + ex.Message + " Line :: " + CommonUtil.GetExceptionLineNumber(ex));
            }
            finally
            {
                if (ScenarioThreadList != null)
                {
                    for (int i = 0; i < ScenarioThreadList.Count; i++)
                    {
                        ScenarioThreadList[i] = null;
                    }
                }
                CoverageSimulatorControlThread = null;
                TestRunWorker.DoWork -= TestRunWorker_DoWork;
                TestRunWorker.RunWorkerCompleted -= TestRunWorker_DoWorkComplete;
                TestRunWorker.ProgressChanged -= TestRunWorker_ProgressChanged;
                TestRunWorker = null;

                if (!Common.Common.DEBUG_MODE)
                {
                    Trace32Handler.TRACE32_DLL.T32_SetChannel(Trace32Handler.ChannelT32Main);
                    Trace32Handler.TRACE32_DLL.T32_Cmd("QUIT");
                    Trace32Handler.TRACE32_DLL.T32_Exit();
                    Thread.Sleep(10);

                    if (ViewModelLocator.MenuBarVM.IsADFileGenerator)
                    {
                        Trace32Handler.TRACE32_DLL.T32_SetChannel(Trace32Handler.ChannelT32SimulAnalysis);
                        Trace32Handler.TRACE32_DLL.T32_Cmd("QUIT");
                        Trace32Handler.TRACE32_DLL.T32_Exit();
                        Thread.Sleep(10);

                        Trace32Handler.TRACE32_DLL.T32_SetChannel(Trace32Handler.ChannelT32SimulMerge);
                        Trace32Handler.TRACE32_DLL.T32_Cmd("QUIT");
                        Trace32Handler.TRACE32_DLL.T32_Exit();
                    }

                    ViewModelLocator.MainVM.MainModel.IsTrace32Connection = false;
                }
            }
        }
        public void PauseTest()
        {
            TestWorklocker.Reset();
            CoverageAnalysisWorklocker.Reset();
            MergeAnalysisWorklocker.Reset();
        }
        public void RestartTest()
        {
            TestWorklocker.Set();
            CoverageAnalysisWorklocker.Set();
            MergeAnalysisWorklocker.Set();
        }
        public void StepTest()
        {
            if (ViewModelLocator.PopupTestStatusVM.PopupTestStatusModel.TestStateMode == Common.Common.PAUSE || ViewModelLocator.PopupTestStatusVM.PopupTestStatusModel.TestStateMode == Common.Common.STEP_RUNNING)
            {
                TestWorklocker.Set();
                CoverageAnalysisWorklocker.Set();
                MergeAnalysisWorklocker.Set();
                Thread.Sleep(1);
                TestWorklocker.Reset();
                CoverageAnalysisWorklocker.Reset();
                MergeAnalysisWorklocker.Reset();
            }
        }
        public void StopTest()
        {
            if (TestRunWorker != null)
            {
                TestRunWorker.CancelAsync();
                TestWorklocker.Set();
            }
            CoverageAnalysisWorklocker.Set();
            MergeAnalysisWorklocker.Set();
        }

        private object BuildTestlockObject = new object();
        public void ElfBuild()
        {
            lock (BuildTestlockObject)
            {
                BuildTestWorker = new BackgroundWorker();

                BuildTestWorker.DoWork += BuildTestWorker_DoWork;
                BuildTestWorker.RunWorkerCompleted += BuildTestWorker_DoWorkComplete;
                BuildTestWorker.WorkerSupportsCancellation = true;
                BuildTestWorker.WorkerReportsProgress = true;
                BuildTestWorker.ProgressChanged += new ProgressChangedEventHandler(BuildTestWorker_ProgressChanged);
                BuildTestWorker.RunWorkerAsync();
            }
        }
        private void BuildTestWorker_DoWork(object sender, DoWorkEventArgs e)
        {
            BuildTestWorker.ReportProgress(20);
            if (!PythonHandler.getInstance().makeProjectData())
            {
                ViewModelLocator.MainVM.showTrackBarMessage("Please Check the Dictionary File");
                return;
            }
            try
            {
                ViewModelLocator.PopupBuildStatusVM.PopupBuildStatusModel.IsBuildStart = true;
                #region FolderCreate


                DirectoryInfo di = new DirectoryInfo(path: ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TimeCreateFolderPath);

                if (!di.Exists)
                {
                    di.Create();
                    di = new DirectoryInfo(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TimeCreateFolderPath + "\\" + "Build");
                    di.Create();

                    di = new DirectoryInfo(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TimeCreateFolderPath + "\\" + "Log");
                    di.Create();
                }
                else
                {
                    ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PFF, "Proceed with the test using an existing path", true);
                }
                #endregion

                BuildTestWorker.ReportProgress(40);
                PythonHandler.getInstance().CompilerThread();
            }
            catch (Exception ex)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, typeof(FunctionWorkHandler).Name + " :: " + ex.Message + " Line :: " + CommonUtil.GetExceptionLineNumber(ex));
            }

        }
        private void BuildTestWorker_ProgressChanged(object sender, ProgressChangedEventArgs e)
        {
            ViewModelLocator.PopupBuildStatusVM.PopupBuildStatusModel.ElfBuildProgress = e.ProgressPercentage;
        }
        private void BuildTestWorker_DoWorkComplete(object sender, RunWorkerCompletedEventArgs e)
        {

            if (e.Error != null)
            {

            }
            else if (e.Cancelled)
                ViewModelLocator.MainVM.showTrackBarMessage("Build Stopped");
            try
            {
                BuildTestWorker.DoWork -= BuildTestWorker_DoWork;
                BuildTestWorker.RunWorkerCompleted -= BuildTestWorker_DoWorkComplete;
                BuildTestWorker.ProgressChanged -= BuildTestWorker_ProgressChanged;

                BuildTestWorker = null;
            }
            catch (Exception ex)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, typeof(FunctionWorkHandler).Name + " :: " + ex.Message + " Line :: " + CommonUtil.GetExceptionLineNumber(ex));
            }

        }

        private bool PrevCheckTestVarification()
        {
            bool CheckValue = true;

            int check = 1;
            UInt16 msg = 0;
            StringBuilder resultTemp = new StringBuilder("0", 256);
            string select_corename = "main_core0";

            Trace32Handler.getInstance().T32_Command("System.up", false);

            if (ViewModelLocator.MainVM.MainModel.IsTestSimulationEnable)
                Trace32Handler.getInstance().FlashDownload(Common.Common.TRACE32_POWERVIEW);

            Trace32Handler.getInstance().T32_Command("go " + select_corename, false);


            for (int i = 0; i < ViewModelLocator.TargetHWSettingVM.CoreList.Count; i++)
            {
                if (ViewModelLocator.TargetHWSettingVM.CoreList[i])
                {
                    select_corename = "main_core" + i;
                    break;
                }
            }

            Trace32Handler.TRACE32_DLL.T32_SetChannel(Trace32Handler.ChannelT32Main);

            if (!ViewModelLocator.TargetHWSettingVM.CoreList[0]) // Core 0 
                Trace32Handler.getInstance().T32_Command("go " + select_corename, false);

            Thread.Sleep(1000);

            Trace32Handler.getInstance().T32_Command("print run()", false);
            Trace32Handler.TRACE32_DLL.T32_GetMessage(resultTemp, ref msg);
            ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PFF, "Check Target Initialize... [Main]");
            ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PFF, "T32_GetMessage [" + resultTemp + "]");

            if (!resultTemp.ToString().Contains("FALSE"))
            {
                Thread.Sleep(1000);
                Trace32Handler.getInstance().T32_Command("print run()", false);
                Trace32Handler.TRACE32_DLL.T32_GetMessage(resultTemp, ref msg);
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PFF, "T32_GetMessage [" + resultTemp + "]");
                if (resultTemp.ToString().Contains("FALSE"))
                {
                    ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PFF, "Initialize Success... [Main]");
                }
                else
                {
                    ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, "Initialize Fail... [Main]");
                    return false;
                }
            }
            else
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PFF, "Initialize Success... [Main]");
            }


            Thread.Sleep(1000);
            // Main Core PC Check
            Trace32Handler.getInstance().T32_Command("print address.offset(D:" + select_corename + ")==r(pc)", false);
            Trace32Handler.TRACE32_DLL.T32_GetMessage(resultTemp, ref msg);
            if (resultTemp.ToString().Contains("FALSE"))
            {
                //ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, "PC Check Fail... [" + select_corename + "]");
            }
            else
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PFF, "PC Check Success... [" + select_corename + "]");
            }

            for (int i = 0; i < ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableList.Count; i++)
            {
                int bitConvert = 1 << i;
                Trace32Handler.getInstance().T32_Command("Var.set run_func_flag=" + bitConvert, false);


                string m_runnable = ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableList[i].RunnableNameGrid.Substring(0, ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableList[i].RunnableNameGrid.Length - 2);
                Trace32Handler.getInstance().T32_Command("go " + m_runnable, false);
                Thread.Sleep(1000);

                Trace32Handler.getInstance().T32_Command("print run()", false);
                Trace32Handler.TRACE32_DLL.T32_GetMessage(resultTemp, ref msg);

                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PFF, "Check Target Initialize... [" + m_runnable + "]");
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PFF, "T32_GetMessage [" + resultTemp + "]");
                if (!resultTemp.ToString().Contains("FALSE"))
                {
                    Thread.Sleep(1000);

                    Trace32Handler.getInstance().T32_Command("print run()", false);
                    Trace32Handler.TRACE32_DLL.T32_GetMessage(resultTemp, ref msg);
                    ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PFF, "T32_GetMessage [" + resultTemp + "]");
                    if (resultTemp.ToString().Contains("FALSE"))
                    {
                        ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PFF, "Initialize Success... [" + m_runnable + "]");
                    }
                    else
                    {
                        ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, "Initialize Fail... [" + m_runnable + "]");
                        CheckValue = false;
                    }
                }
                else
                {
                    ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PFF, "Initialize Success... [" + m_runnable + "]");
                }

                Thread.Sleep(1000);
                // Runnable PC Check
                Trace32Handler.getInstance().T32_Command("print address.offset(D:" + m_runnable + ")==r(pc)", false);
                Trace32Handler.TRACE32_DLL.T32_GetMessage(resultTemp, ref msg);
                if (resultTemp.ToString().Contains("FALSE"))
                {
                    ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, "PC Check Fail... [" + m_runnable + "]");
                    CheckValue = false;
                }
                else
                {
                    ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PFF, "PC Check Success... [" + m_runnable + "]");
                }
            }

            if (CheckValue == false)
                return false;


            Trace32Handler.getInstance().T32_Command("go Check_Point", false);
            Thread.Sleep(1000);

            Trace32Handler.getInstance().T32_Command("print run()", false);
            Trace32Handler.TRACE32_DLL.T32_GetMessage(resultTemp, ref msg);
            ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PFF, "Check Target Initialize... [Check_Point()]");
            ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PFF, "T32_GetMessage [" + resultTemp + "]");
            if (!resultTemp.ToString().Contains("FALSE"))
            {
                Thread.Sleep(1000);
                Trace32Handler.getInstance().T32_Command("print run()", false);
                Trace32Handler.TRACE32_DLL.T32_GetMessage(resultTemp, ref msg);
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PFF, "T32_GetMessage [" + resultTemp + "]");
                if (resultTemp.ToString().Contains("FALSE"))
                {
                    ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PFF, "Initialize Success... [Check_Point()]");
                }
                else
                {
                    ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, "Initialize Fail... [Check_Point()]");
                    return false;
                }
            }
            else
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PFF, "Initialize Success... [Check_Point()]");
            }

            Thread.Sleep(1000);
            // CheckPoint PC Check
            Trace32Handler.getInstance().T32_Command("print address.offset(D:Check_Point)==r(pc)", false);
            Trace32Handler.TRACE32_DLL.T32_GetMessage(resultTemp, ref msg);
            if (resultTemp.ToString().Contains("FALSE"))
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, "PC Check Fail... [Check_Point]");
                return false;
            }
            else
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PFF, "PC Check Success... [Check_Point]");
            }

            List<string> InputSymbolList = new List<string>();
            List<string> OutputSymbolList = new List<string>();

            for (int i = 0; i < ViewModelLocator.ReportSettingVM.ReportSettingModel.TestInfoDictionary.Count; i++)
            {
                IronPython.Runtime.List test_info_list = (IronPython.Runtime.List)ViewModelLocator.ReportSettingVM.ReportSettingModel.TestInfoDictionary.get(ViewModelLocator.ReportSettingVM.ReportSettingModel.TestInfoDictionary.keys()[i]);
                IronPython.Runtime.PythonDictionary test_info_temp = (IronPython.Runtime.PythonDictionary)test_info_list[0];
                IronPython.Runtime.PythonDictionary outputdata = (IronPython.Runtime.PythonDictionary)test_info_temp.get("Expect Output Data");
                IronPython.Runtime.PythonDictionary inputdata = (IronPython.Runtime.PythonDictionary)test_info_temp.get("Input Data");

                foreach (string outkey in outputdata.keys())
                {
                    if (!OutputSymbolList.Contains(outkey))
                        OutputSymbolList.Add(outkey);
                }
                foreach (string intkey in inputdata.keys())
                {
                    if (!InputSymbolList.Contains(intkey))
                        InputSymbolList.Add(intkey);
                }
            }

            foreach (string inkey in InputSymbolList)
            {
                if (inkey.ToLower().Contains("user macro"))
                    continue;

                Trace32Handler.TRACE32_DLL.T32_Cmd("print var.exist(" + inkey + ")");
                Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref check);
                while (check != 0)
                {
                    Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref check);
                }

                Trace32Handler.TRACE32_DLL.T32_GetMessage(resultTemp, ref msg);
                if (resultTemp.ToString().Contains("TRUE"))
                    ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PFF, inkey + " Exist Symbol");
                else
                {
                    CheckValue = false;
                    ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, inkey + " Not Exist Symbol");
                }
            }
            foreach (string outkey in OutputSymbolList)
            {
                if (outkey.ToLower().Contains("user macro"))
                    continue;

                Trace32Handler.TRACE32_DLL.T32_Cmd("print var.exist(" + outkey + ")");
                Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref check);
                while (check != 0)
                {
                    Trace32Handler.TRACE32_DLL.T32_GetPracticeState(ref check);
                }

                Trace32Handler.TRACE32_DLL.T32_GetMessage(resultTemp, ref msg);
                if (resultTemp.ToString().Contains("TRUE"))
                    ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_PFF, outkey + " Exist Symbol");
                else
                {
                    CheckValue = false;
                    ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, outkey + " Not Exist Symbol");
                }
            }



            return CheckValue;
        }

        public void TestWorkerCheckCancel(DoWorkEventArgs e)
        {
            if (TestRunWorker.CancellationPending)
            {
                e.Cancel = true;
                return;
            }
        }

        public class CoordinatesBasedComparer : IComparer<string>
        {
            public int Compare(string a, string b)
            {

                if (Double.Parse(a) == Double.Parse(b))
                    return 0;
                if (Double.Parse(a) < Double.Parse(b))
                    return -1;

                return 1;
            }
        }
    }
}
