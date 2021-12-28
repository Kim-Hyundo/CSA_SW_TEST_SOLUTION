using GraphProject.ViewModel;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;

namespace GraphProject.TRACE32
{
    public class Trace32Remote
    {
        public static string T32_CMM_PATH = "\"" + System.IO.Directory.GetCurrentDirectory() + "\\..\\report\\window_setting.cmm\" ";
        public static string T32_CMM_PATH_USERMACRO = "\"" + System.IO.Directory.GetCurrentDirectory() + "\\..\\report\\window_setting_usermacro.cmm\" ";
        public static string T32_PATH = "";

        public int T32_RCL_PORT_NUM = 0;
        public bool PowerViewWorking = false;
        public bool Trace32Connected = false;
        public static string POWERVIEW_NAME = "t32mtc";

        public Header header = new Header();

        #region T32 Variables

        public T32API T32;
        public T32API.Channel channel = new T32API.Channel();
        private Process PowerView = null;

        #endregion

        #region Contructor

        public Trace32Remote(int port)
        {
            T32 = new T32API();
            header = new Header();
            T32_RCL_PORT_NUM = port;
        }

        #endregion

        #region PowerView Connect

        public bool T32_PowerviewConnect(string parameter)
        {
            T32_PATH =@"..\src\lib\T32";
            string filePath = T32_PATH + @"\bin\windows64\t32mtc.exe";

            ProcessStartInfo psi = new ProcessStartInfo();
            psi.FileName = Path.GetFileName(filePath);
            psi.WorkingDirectory = Path.GetDirectoryName(filePath);
            psi.Arguments = parameter;

            try
            {
                Process[] process = Process.GetProcessesByName(POWERVIEW_NAME);
                
                PowerView = Process.Start(psi);

                PowerViewWorking = true;
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "PowerView Connection Error");
                Debug.Write(ex.Message, "PowerView Connection Error");
                return false;
            }

            return true;
        }

        #endregion

        #region T32 Connection Setting

        public bool T32_InitSetting()
        {
            if (PowerViewWorking == false)
            {
                Debug.Write("PowerView is not Activated");
                return false;
            }

            try
            {
                T32.GetChannelSize();
                T32.GetChannelDefaults(channel);
                T32.SetChannel(channel);

                T32.Config("NODE=", "localhost");
                T32.Config("PACKLEN=", "1024");
                T32.Config("PORT=", T32_RCL_PORT_NUM.ToString());

                int rc;
                int timeout = 10;
                int currtime = 0;

                while ((rc = T32.Init()) != 0)
                {
                    if (currtime >= timeout)
                        return false;

                    currtime++;
                    Thread.Sleep(1000);
                }

                rc = T32.Attach((int)T32API.Device.ICE);
                rc = T32.Ping();
            }
            catch (Exception ex)
            {
                Debug.Write(ex.Message);
                Trace32Connected = false;
                return false;
            }

            Trace32Connected = true;

            return true;
        }

        #endregion

        #region Terminate
        public bool T32_Terminate()
        {
            try
            {
                if (T32 != null)
                {
                    if (Trace32Connected == true)
                    {
                        T32.SetChannel(channel);
                        T32.Cmd("Quit");
                        T32.Exit();
                        Trace32Connected = false;
                        PowerViewWorking = false;
                    }
                    else
                    {
                        PowerViewWorking = false;
                    }

                }
            }
            catch (Exception ex)
            {
                Debug.Write(ex.Message);
                return false;
            }

            return true;
        }

        #endregion


        #region

        public bool PowerViewExecute()
        {

            header.PORT = T32_RCL_PORT_NUM.ToString();

            header.TMPDIR = MainViewModel.Install_path + @"\Temp";
            header.SYSDIR = T32_PATH;
            //header.HELPDIR = T32_PATH+"\\pdf";
            //header.INTERFACE = "USB";
            //header.INTERFACE2 = "SIM";
            //header.CONNECTIONMODE = "CONNECTIONMODE=AUTOCONNECT";
            //header.SCREEN = "";
            //header.STARTUP = T32_PATH + "\\autostart.cmm";
            //header.NODE = "";

            string parameter = header.createParameter();

            if (!T32_PowerviewConnect(parameter))
            {
                return false;
            }

            Thread.Sleep(5000);
            //if (TRACE32Controller.GetInstance().T32_PowerViewCount("t32mtc") != TRACE32Controller.PDMU_COUNT)
            //return false;

            return true;
        }

        public bool RemoteConnection()
        {
            if (!PowerViewWorking)
            {
                if (!PowerViewExecute())
                {
                    return false;
                }
            }

            if (!Trace32Connected)
            {
                if (!T32_InitSetting())
                {
                    T32_Terminate();
                    return false;
                }
            }

            return true;
        }

        public void DebugEnvSetting(string cpu, string elf_path, string trace_path, string input_var, string output_var, string TestIDName)
        {
            bool isUserMacroFlag = false;
            IronPython.Runtime.List Test_Result_List = (IronPython.Runtime.List)MainViewModel.Test_Result_Data;
            IronPython.Runtime.PythonDictionary inputDic = new IronPython.Runtime.PythonDictionary();
            IronPython.Runtime.List input_keys = new IronPython.Runtime.List();
            

            foreach (IronPython.Runtime.PythonDictionary tmp in Test_Result_List)
            {
                if(tmp["Test ID"].ToString().Equals(TestIDName))
                {
                    inputDic = (IronPython.Runtime.PythonDictionary)tmp["Input Data"];
                    input_keys = (IronPython.Runtime.List)inputDic.keys();
                    foreach (string str in input_keys)
                    {
                        if(str.ToLower().Contains("user macro input"))
                            isUserMacroFlag = true;
                    }
                }
                
            }

            if (isUserMacroFlag)
            {
                string parse_result = MainViewModel.curr_Workspace + "\\" + MainViewModel.curr_Project + "\\Gen\\" + MainViewModel.curr_Folder + "\\" + MainViewModel.curr_testcase + "\\" + "parse_result.txt";
                string UserScriptPath = MainViewModel.curr_Workspace + "\\" + MainViewModel.curr_Project + "\\" + MainViewModel.curr_Folder + "\\" + MainViewModel.curr_testcase + "\\Cmm\\UserMacroScript";

                string strInput = "";

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
                IronPython.Runtime.PythonDictionary test_squence_dic = (IronPython.Runtime.PythonDictionary)parse_result_dic["Test_Sequence"];
                IronPython.Runtime.PythonDictionary test_squence_tmp = (IronPython.Runtime.PythonDictionary)test_squence_dic.get(MainViewModel.curr_scenario);

                IronPython.Runtime.List Sequence = (IronPython.Runtime.List)test_squence_tmp[TestIDName];

                //T32.Cmd("CD.DO " + T32_CMM_PATH_USERMACRO + cpu + " \"" + elf_path + "\" \"" + trace_path + "\" ");
                List<string> InputScriptList = new List<string>();
                foreach (string script in Sequence)
                {
                    if (script.Contains("go.cmm"))
                        break;
                    InputScriptList.Add(script.Replace("CD.DO ", ""));
                }
                for (int i = 0; i < InputScriptList.Count; i++)
                {
                    strInput += InputScriptList[i].Replace("\"", "").Replace("\n", "") + "||";
                }

                string str_enumscript = "";
                string str_enummacro = "";

                str_enumscript = MainViewModel.Summary_Data["EnumScriptPath"].ToString().Replace("$(workspace_loc)", MainViewModel.curr_Workspace);
                if (!File.Exists(str_enumscript))
                {
                    if (File.Exists(MainViewModel.curr_Workspace + "\\" + MainViewModel.curr_Project + "\\Temp\\EnumScript.cmm"))
                        str_enumscript = MainViewModel.curr_Workspace + "\\" + MainViewModel.curr_Project + "\\Temp\\EnumScript.cmm";
                }
                if (File.Exists(MainViewModel.Install_path + @"\src\parser\Cmm\Templete\enum_macro.cmm"))
                    str_enummacro = MainViewModel.Install_path + @"\src\parser\Cmm\Templete\enum_macro.cmm";

                T32.Cmd("CD.DO " + T32_CMM_PATH + cpu + " \"" + elf_path + "\" \"" + trace_path + "\" " + "\"" + strInput + "\"" + " Outputdummy " + " \"" + str_enumscript + " \"" + "\"" + str_enummacro + "\"");

                Trace32Connected = false;
                T32.Exit();
            }
            else
            {
                string[] input_var_split = input_var.Split(new string[] { "\n" }, StringSplitOptions.None);
                string[] output_var_split = output_var.Split(new string[] { "\n" }, StringSplitOptions.None);

                string total_input_var = "";
                string total_output_var = "";

                foreach (string tmp in input_var_split)
                {
                    total_input_var += tmp.Trim() + "||";
                }

                foreach (string tmp in output_var_split)
                {
                    string[] out_tmp = tmp.Split(new string[] { "=" }, StringSplitOptions.None);

                    if (out_tmp == null)
                        continue;

                    string var_name = tmp.Trim();

                    total_output_var += var_name + "||";
                }



                T32.Cmd("CD.DO " + T32_CMM_PATH + cpu + " \"" + elf_path + "\" \"" + trace_path + "\" " + "\"" + total_input_var + "\"");
                T32.Exit();
                Trace32Connected = false;
            }
        }

        #endregion
    }
}
