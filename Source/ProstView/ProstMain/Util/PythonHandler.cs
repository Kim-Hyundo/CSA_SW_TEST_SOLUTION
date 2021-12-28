using ProstMain.Model;
using ProstMain.ViewModel;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Input;
using System.Windows.Threading;


namespace ProstMain.Util
{
    class PythonHandler
    {
        int SelectParserMode;

        private static class LazyHolder
        {
            public static readonly PythonHandler INSTANCE = new PythonHandler();
        }

        public static PythonHandler getInstance()
        {
            return LazyHolder.INSTANCE;
        }

        public PythonHandler()
        {

        }
        public bool makeReportData()
        {
            Dictionary<String, Object> REPO_TEST_INFO_PAR = new Dictionary<String, Object>
            {
                { "Test Project", ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName },
                { "Test Comment", ViewModelLocator.ProjectSettingVM.ProjectSettingModel.Comment },
                { "PROST Version", "2.0" },
                { "Date/Time", DateTime.Now.ToString(format: "yyyMMddHHmm") },
                { "Tester name", ViewModelLocator.ProjectSettingVM.ProjectSettingModel.Tester },
                { "MCU/CPU", ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.CpuName },
                { "CPU Clock setting", ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.Frequency.ToString() },
                { "Compiler Type", ViewModelLocator.CompilerSettingVM.CompilerSettingModel.CompilerType },
                { "Compiler Version", ViewModelLocator.CompilerSettingVM.CompilerSettingModel.CompilerVersion },
                { "Test SW Path", ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceCodePath },
                { "Test Statement", CommonUtil.GetRelativeToAbsolutePath(ViewModelLocator.PopupTestCaseParsingVM.PopupTestCaseParsingModel.TestStatement)},
                { "Testcase Path", ViewModelLocator.PopupTestCaseParsingVM.PopupTestCaseParsingModel.TestcasePath }
            };

            if (ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.TestCodeList != null && ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.TestCodeList.Count != 0)
            {
                IronPython.Runtime.List SendTestCodeList = new IronPython.Runtime.List();
                foreach (string str in ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.TestCodeList)
                {
                    SendTestCodeList.Add(str + ".c");
                }
                REPO_TEST_INFO_PAR.Add("Test_Code_List", SendTestCodeList);
            }


            REPO_TEST_INFO_PAR.Add("AutoGenEnable", "TRUE");

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


            var dictionary_dump = scope.GetVariable<Func<object, string, string>>("Report_dictionary_dump");
            dictionary_dump(REPO_TEST_INFO_PAR, ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Temp\\R_test_dictionary.txt");

            return true;
        }
        public void makeProjectDataOnlyTestCase(string pathSet)
        {
            IronPython.Runtime.PythonDictionary GUI_PARAMETER_DIC = new IronPython.Runtime.PythonDictionary();

            // Common Path DIctionary
            IronPython.Runtime.PythonDictionary Common_Path_DIC = new IronPython.Runtime.PythonDictionary
            {
                { "Workspace_Path", ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath },
                { "WorkingProject_Path", pathSet },
                { "T15_Install_Path", Common.Common.INSTALL_PATH },
                { "Project_Root_Path", ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName },
                { "Project_Gen_Path", ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\" + "Gen" },
                { "EnumScriptPath", ViewModelLocator.ETCSettingVM.EnumScriptPath }
            };

            GUI_PARAMETER_DIC.Add("Common_Path", Common_Path_DIC);

            // Log DIctionary
            IronPython.Runtime.PythonDictionary Log_DIC = new IronPython.Runtime.PythonDictionary
            {
                { "Log_Level", ViewModelLocator.MenuBarVM.LogLevelIndex.ToString() }
            };
            GUI_PARAMETER_DIC.Add("Log", Log_DIC);

            IronPython.Runtime.PythonDictionary Parser_DIC = new IronPython.Runtime.PythonDictionary
            {
                { "Test_Case_Path", "" },
                { "Test_Spec_Path", CommonUtil.GetRelativeToAbsolutePath(ViewModelLocator.PopupTestCaseParsingVM.PopupTestCaseParsingModel.TestStatement)},
                { "Min_Diff", ViewModelLocator.MenuBarVM.Resolution.ToString() },
                { "Execution_Time", "TRUE" }
            };


            GUI_PARAMETER_DIC.Add("Parser", Parser_DIC);



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



            var GUI_Parameter = scope.GetVariable<Func<IronPython.Runtime.PythonDictionary, string, string>>("GUI_Parameter");

            GUI_Parameter(GUI_PARAMETER_DIC, ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Temp" + Common.Common.PROJECT_INFO_DATA);

        }
        // 김젼★ 이거봐 중요하다 집중해!!!!김젼★ 이거봐 중요하다 집중해!!!!김젼★ 이거봐 중요하다 집중해!!!!김젼★ 이거봐 중요하다 집중해!!!!김젼★ 이거봐 중요하다 집중해!!!!
        public bool makeProjectData()
        {
            IronPython.Runtime.PythonDictionary GUI_PARAMETER_DIC = new IronPython.Runtime.PythonDictionary();

            string convertEnumScriptPath = ViewModelLocator.ETCSettingVM.EnumScriptPath.Replace("$(workspace_loc)", ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath);


            // Common Path DIctionary
            IronPython.Runtime.PythonDictionary Common_Path_DIC = new IronPython.Runtime.PythonDictionary
            {
                { "Workspace_Path", ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath },
                { "WorkingProject_Path", ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath }, // Ex) C:\Users\CSA_DEV\Documents\Working\Prost_v2.0\Workspace\ExampleProject\Gen\202009240959_TUC\202009031155_Parsed_TestSequence_2020-02-12_1
                { "BuildProject_Path", ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TimeCreateFolderPath }, // Ex) C:\Users\CSA_DEV\Documents\Working\Prost_v2.0\Workspace\ExampleProject\Gen\202009240959_TUC\
                { "T15_Install_Path", Common.Common.INSTALL_PATH },
                { "Project_Root_Path", ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName },
                { "Project_Gen_Path", ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\" + "Gen" },
                { "Simulator", ViewModelLocator.MainVM.MainModel.IsTestSimulationEnable.ToString().ToUpper()},
                { "EnumScriptPath",  convertEnumScriptPath}
            };
            //Common_Path_DIC.Add("WorkingProject_Path", ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TimeCreateFolderPath);



            GUI_PARAMETER_DIC.Add("Common_Path", Common_Path_DIC);

            // Test Env DIctionary
            IronPython.Runtime.PythonDictionary Test_Env_DIC = new IronPython.Runtime.PythonDictionary
            {

                { "SW_Version", ViewModelLocator.MainVM.MainModel.VERSION },
                { "Tester", ViewModelLocator.ProjectSettingVM.ProjectSettingModel.Tester },
                { "Test_Project", ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName },
                { "Test_SW_Version", "" },
                { "Test_CPU", ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.CpuName },
                { "CPU_Clock", ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.CpuClock.ToString() },
                { "Test_CompilerType", ViewModelLocator.CompilerSettingVM.CompilerSettingModel.CompilerType },
                { "CompilerVersion", ViewModelLocator.CompilerSettingVM.CompilerSettingModel.CompilerVersion },
                { "Test_Code_Path", ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceCodePath},
                { "Comment", ViewModelLocator.ProjectSettingVM.ProjectSettingModel.Comment },
                { "Dcache", Convert.ToInt32(ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.DCache) },
                { "Pcache", Convert.ToInt32(ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.PCache) },
                { "HeaderFile_Path", "" },
                { "Test_Component", ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName }
            };



            if (ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.TestCodeList != null && ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.TestCodeList.Count != 0)
            {
                IronPython.Runtime.List SendTestCodeList = new IronPython.Runtime.List();
                foreach (string str in ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.TestCodeList)
                {
                    SendTestCodeList.Add(str.Replace(".src", "") + ".c");
                }
                Test_Env_DIC.Add("Test_Code_List", SendTestCodeList);
            }

            GUI_PARAMETER_DIC.Add("Test_Env", Test_Env_DIC);

            // Log DIctionary
            IronPython.Runtime.PythonDictionary Log_DIC = new IronPython.Runtime.PythonDictionary
            {
                { "Log_Level", ViewModelLocator.MenuBarVM.LogLevelIndex.ToString() }
            };
            GUI_PARAMETER_DIC.Add("Log", Log_DIC);


            // Parser DIctionary
            IronPython.Runtime.PythonDictionary Parser_DIC = new IronPython.Runtime.PythonDictionary
            {
                { "Test_Case_Path", ViewModelLocator.PopupTestCaseParsingVM.PopupTestCaseParsingModel.TestcasePath },
                { "Test_Spec_Path", CommonUtil.GetRelativeToAbsolutePath(ViewModelLocator.PopupTestCaseParsingVM.PopupTestCaseParsingModel.TestStatement)},
                { "Min_Diff", ViewModelLocator.MenuBarVM.Resolution.ToString() },
                { "Execution_Time", "TRUE" },
                { "MappingTable_Path", "" }
            };



            GUI_PARAMETER_DIC.Add("Parser", Parser_DIC);

            // 김젼별 Report_DIC은 일단 무시해!!!!
            // Report DIctionary
            IronPython.Runtime.PythonDictionary Report_DIC = new IronPython.Runtime.PythonDictionary
            {
                { "Test_Result_Path", ViewModelLocator.ReportSettingVM.ReportSettingModel.TestSummaryReport_Path },
                { "IOTest_Result_Path", ViewModelLocator.ReportSettingVM.ReportSettingModel.IOTestReport_Path },
                { "IOTest_InputData", ViewModelLocator.ReportSettingVM.ReportSettingModel.IOTestReport_InputData.ToString().ToUpper() },
                { "IOTest_OutputData", ViewModelLocator.ReportSettingVM.ReportSettingModel.IOTestReport_OutputData.ToString().ToUpper() },
                { "IOTest_ExpectedData", ViewModelLocator.ReportSettingVM.ReportSettingModel.IOTestReport_ExpectedData.ToString().ToUpper() },
                { "IOTest_TestPassFail", ViewModelLocator.ReportSettingVM.ReportSettingModel.IOTestReport_TestPassFail.ToString().ToUpper() },
                { "IOTest_SWRuntime", ViewModelLocator.ReportSettingVM.ReportSettingModel.IOTestReport_RuntimeMeasure.ToString().ToUpper() },
                { "CodeCoverage_Result_Path", ViewModelLocator.ReportSettingVM.ReportSettingModel.CodeCoverageReport_Path },
                { "CodeCoverage_Statement_Result", ViewModelLocator.ReportSettingVM.ReportSettingModel.CodeCoverageReport_Statement.ToString().ToUpper() },
                { "CodeCoverage_FunctionCall_Result", ViewModelLocator.ReportSettingVM.ReportSettingModel.CodeCoverageReport_FunctionCall.ToString().ToUpper() },
                { "CodeCoverage_MC_DC_Result", ViewModelLocator.ReportSettingVM.ReportSettingModel.CodeCoverageReport_MC_DC.ToString().ToUpper() },
                { "Performance_Result_Path", ViewModelLocator.ReportSettingVM.ReportSettingModel.PerformanceMeasurementReport_Path },
                { "Performance_Function_ExcecuteTime", ViewModelLocator.ReportSettingVM.ReportSettingModel.PerformanceMeasurementReport_ExecuteChart.ToString().ToUpper() },
                { "Performance_Data_ReadWrite_Count", ViewModelLocator.ReportSettingVM.ReportSettingModel.PerformanceMeasurementReport_DataReadWrite.ToString().ToUpper() },
                { "Performance_Data_Benchmark_Count", ViewModelLocator.ReportSettingVM.ReportSettingModel.PerformanceMeasurementReport_BenchMark.ToString().ToUpper() },
                { "Simulator_Debug_Analysis", ViewModelLocator.ReportSettingVM.ReportSettingModel.DebugAnalysis.ToString().ToUpper() },
                { "Data_Mornitoring", ViewModelLocator.ReportSettingVM.ReportSettingModel.DataMornitoring.ToString().ToUpper() },
                { "Function_Call_Path_Analysis", ViewModelLocator.ReportSettingVM.ReportSettingModel.FunctionCallPathReport.ToString().ToUpper() },
                { "AutoGen_En", "TRUE" }
            };

            if (ViewModelLocator.ReportSettingVM.ReportSettingModel.TestInfoDictionary.Count > 0)
                Report_DIC.Add("Test_Info", ViewModelLocator.ReportSettingVM.ReportSettingModel.TestInfoDictionary);

            if (ViewModelLocator.ReportSettingVM.ReportSettingModel.StackInfoDictionary.Count > 0)
                Report_DIC.Add("Stack_Info", ViewModelLocator.ReportSettingVM.ReportSettingModel.StackInfoDictionary);

            Report_DIC.Add("AD_File_Opt", ViewModelLocator.MenuBarVM.IsADFileGenerator.ToString().ToUpper());
            
            GUI_PARAMETER_DIC.Add("Report", Report_DIC);

            // Report DIctionary
            IronPython.Runtime.PythonDictionary Compiler_DIC = new IronPython.Runtime.PythonDictionary();
            IronPython.Runtime.PythonDictionary Core_DIC = new IronPython.Runtime.PythonDictionary();

            Compiler_DIC.Add("Compiler_Path", ViewModelLocator.CompilerSettingVM.CompilerSettingModel.CompilerPath);
            Compiler_DIC.Add("Init_Func", "");
            Compiler_DIC.Add("Compiler_Option", ViewModelLocator.CompilerSettingVM.CompilerSettingModel.CompilerOption);
            Compiler_DIC.Add("Linker_Option", ViewModelLocator.CompilerSettingVM.CompilerSettingModel.LinkerOption);
            Compiler_DIC.Add("Delay_Coeff", "25");
            for (int i = 0; i < ViewModelLocator.TargetHWSettingVM.CoreList.Count; i++)
            {
                Core_DIC.Add(ViewModelLocator.TargetHWSettingVM.CoreNameList[i], ViewModelLocator.TargetHWSettingVM.CoreList[i].ToString().ToUpper());
                //Core_DIC.Add("core" + i, ViewModelLocator.TargetHWSettingVM.CoreList[i].ToString().ToUpper());
            }
            Compiler_DIC.Add("Core", Core_DIC);

            IronPython.Runtime.PythonDictionary Runnable_Dic = new IronPython.Runtime.PythonDictionary();
            IronPython.Runtime.PythonDictionary Register_Dic = new IronPython.Runtime.PythonDictionary();
            IronPython.Runtime.PythonDictionary Stub_Dic = new IronPython.Runtime.PythonDictionary();
            IronPython.Runtime.PythonDictionary InitFunc_Dic = new IronPython.Runtime.PythonDictionary();
            IronPython.Runtime.PythonDictionary LibFunc_Dic = new IronPython.Runtime.PythonDictionary();
            IronPython.Runtime.PythonDictionary IncludePath_Dic = new IronPython.Runtime.PythonDictionary();
            IronPython.Runtime.PythonDictionary MemoryLocation_Dic = new IronPython.Runtime.PythonDictionary();

            for (int i = 0; i < ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableStubList.Count(); i++)
            {
                Stub_Dic.Add(i + 1, ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableStubList[i].RunnableSTUBFunctionGrid + "$$" + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableStubList[i].RunnableSTUBDelayGrid + "$$" + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableStubList[i].RunnableSTUBReturnGrid);
            }

            for (int i = 0; i < ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableList.Count(); i++)
            {
                Runnable_Dic.Add(i + 1, ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableList[i].RunnableNameGrid + "$$" + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableList[i].RunnableCycleGrid + "$$" + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableList[i].RunnableCoreGrid + "$$" + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableList[i].RunnableHeader);
            }

            for (int i = 0; i < ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RegisterList.Count(); i++)
            {
                Register_Dic.Add(ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RegisterList[i].RegisterName, ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RegisterList[i].RegisterValue);
            }
            for (int i = 0; i < ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.InitFunctionList.Count(); i++)
            {
                InitFunc_Dic.Add(i + 1, ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.InitFunctionList[i]);
            }
            for (int i = 0; i < ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.IncludePathList.Count(); i++)
            {
                if(ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.IncludePathList[i].RelativePath != "")
                    IncludePath_Dic.Add(i + 1, ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.IncludePathList[i].RelativePath);
                else
                    IncludePath_Dic.Add(i + 1, ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.IncludePathList[i].AbsolutePath);
            }
            for (int i = 0; i < ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.LibraryPathList.Count(); i++)
            {
                LibFunc_Dic.Add(i + 1, CommonUtil.GetRelativeToAbsolutePath(ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.LibraryPathList[i]));
            }
            System.Windows.Application.Current.Dispatcher.Invoke(new Action(() =>
            {
                MemoryLocation_Dic.Add("abs18", ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.MemoryLocationTextABS18.Text.ToString());
                MemoryLocation_Dic.Add("linear", ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.MemoryLocationTextLinear.Text.ToString());
            }));
            /*            MemoryLocation_Dic.Add("text", ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SelectTextLoadMemory + "$$" + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SelectTextRunMemory);
                        MemoryLocation_Dic.Add("bss", ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SelectBssRunMemory);
                        MemoryLocation_Dic.Add("data", ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SelectDataLoadMemory + "$$" + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SelectDataRunMemory);
                        MemoryLocation_Dic.Add("zbss,", ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SelectZbssRunMemory);
                        MemoryLocation_Dic.Add("zdata", ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SelectZdataLoadMemory + "$$" + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SelectZdataRunMemory);
            */


            Compiler_DIC.Add("Stub_List", Stub_Dic);
            Compiler_DIC.Add("Runnable_List", Runnable_Dic);
            Compiler_DIC.Add("Register_List", Register_Dic);
            Compiler_DIC.Add("InitFunction_List", InitFunc_Dic);
            Compiler_DIC.Add("IncludePath_List", IncludePath_Dic);
            Compiler_DIC.Add("Library_List", LibFunc_Dic);
            Compiler_DIC.Add("Memory_Section", MemoryLocation_Dic);
            if (ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SelectMainLinkerScript == "None" || ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SelectMainLinkerScript == "" || ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SelectMainLinkerScript == null)
                Compiler_DIC.Add("IsExistMainls", "FALSE");
            else
                Compiler_DIC.Add("IsExistMainls", "TRUE");

            GUI_PARAMETER_DIC.Add("Compiler", Compiler_DIC);


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



            var GUI_Parameter = scope.GetVariable<Func<IronPython.Runtime.PythonDictionary, string, string>>("GUI_Parameter");

            //딕셔너리 파일 생성해서 temp폴더에 저장
            GUI_Parameter(GUI_PARAMETER_DIC, ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Temp" + Common.Common.PROJECT_INFO_DATA);

            return true;
        }
       
        public void CompilerThread()
        {
            try
            {
                ProcessStartInfo myProcessStartInfo = new ProcessStartInfo(Common.Common.PYTHON_APP);

                // make sure we can read the output from stdout 
                myProcessStartInfo.UseShellExecute = false;
                myProcessStartInfo.RedirectStandardOutput = true;

                //쌍따옴표 추가
                myProcessStartInfo.Arguments = Common.Common.COMPILER_APP + " \"" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Temp" + Common.Common.PROJECT_INFO_DATA;

                Process myProcess = new Process();
                // assign start information to the process 
                myProcess.StartInfo = myProcessStartInfo;
                myProcess.StartInfo.CreateNoWindow = true;
                myProcess.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;

                myProcess.StartInfo.UseShellExecute = false;
                myProcess.StartInfo.RedirectStandardOutput = true;
                myProcess.StartInfo.RedirectStandardError = true;
                //* Set your output and error (asynchronous) handlers
                myProcess.OutputDataReceived += new DataReceivedEventHandler(CompilerOutputHandler);
                myProcess.ErrorDataReceived += new DataReceivedEventHandler(CompilerOutputHandler);

                myProcess.Start();
                myProcess.BeginOutputReadLine();
                myProcess.BeginErrorReadLine();
                myProcess.WaitForExit();


                // close the process 
                //myProcess.Close();
            }
            catch (Exception ex)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, typeof(PythonHandler).Name + " :: " + ex.Message + " Line :: " + CommonUtil.GetExceptionLineNumber(ex));
            }
        }
        private void CompilerOutputHandler(object sendingProcess, DataReceivedEventArgs outLine)
        {
            if (outLine.Data == null)
                return;

            if (outLine.Data.Contains("[ERR"))
                ViewModelLocator.PopupBuildStatusVM.PopupBuildStatusModel.IsElfSettingValue = Common.Common.FAIL;
            else if (outLine.Data == "Build Success")
            {
                FunctionWorkHandler.getInstance().BuildTestWorker.ReportProgress(60);
                checkBuildFile();
            }
            else if (outLine.Data == "Build Failed")
            {
                FunctionWorkHandler.getInstance().BuildTestWorker.ReportProgress(100);
                ViewModelLocator.PopupBuildStatusVM.PopupBuildStatusModel.IsElfSettingValue = Common.Common.FAIL;
            }

            ProstLog.getInstance().Log(Common.Common.MODULE_COMPILER, outLine.Data);
        }
        int ExceptionFlag;
        private void ParserOutputHandler(object sendingProcess, DataReceivedEventArgs outLine)
        {
            if (outLine.Data == null)
                return;

            if (outLine.Data.Contains("[PROGRESS]"))
            {
                return;
            }
            else if (outLine.Data.Contains("TESTCASEPATH::"))
            {
                ViewModelLocator.PopupTestCaseParsingVM.PopupTestCaseParsingModel.TestcasePath = outLine.Data.Split(new string[] { "::" }, StringSplitOptions.None)[1];
            }
            else if (outLine.Data.Contains("TestspecParser Done"))
            {
                System.Windows.Application.Current.Dispatcher.Invoke(new Action(() =>
                {
                    if (ExceptionFlag == 0)
                    {
                        ViewModelLocator.PopupTestCaseParsingVM.TestSpecConverFinish(Common.Common.PASS);
                        ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TestStepIconColumn = 4;

                        Thread.Sleep(500);

                        ////////// AUTO TEST ///////////////
                        if (ViewModelLocator.ToolbarVM.ToolbarModel.TestStartMode == Common.Common.TESTMODE_AUTO)
                        {
                            ViewModelLocator.PopupTestCaseParsingVM.CloseTestCasePopupView();
                            ViewModelLocator.ToolbarVM.RunTest();
                        }
                    }
                    else
                    {
                        ViewModelLocator.PopupTestCaseParsingVM.TestSpecConverFinish(Common.Common.FAIL);
                        ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TestStepIconColumn = 2;
                    }
                }));
                ExceptionFlag = 0;
            }
            else if (outLine.Data.Equals("TestcaseParser Done"))
            {
                ViewModelLocator.PopupTestCaseParsingVM.PopupTestCaseParsingModel.IsTestcaseParserComplete = Common.Common.PASS;
                ViewModelLocator.PopupTestStatusVM.PopupTestStatusModel.TestStatusText = "Test Running...";
            }
            else if (outLine.Data == "Exception" || outLine.Data.Contains("[ERR]"))
            {
                if (SelectParserMode == Common.Common.PARSING_TESTSPECIFICATION)
                {
                    ExceptionFlag++;
                    CommonUtil.ExitExcelProcess();
                }
                else if (SelectParserMode == Common.Common.PARSING_TESTCASE)
                    ViewModelLocator.PopupTestCaseParsingVM.PopupTestCaseParsingModel.IsTestcaseParserComplete = Common.Common.FAIL;
            }
            else if (outLine.Data.Contains("TestCase Parsing Complete..."))
            {
                Dispatcher dispatcher = Application.Current.Dispatcher;
                DispatcherOperation dispatcherOperation = dispatcher.BeginInvoke(System.Windows.Threading.DispatcherPriority.Send, (ThreadStart)
                delegate ()
                {
                    ViewModelLocator.PopupTestCaseParsingVM.TestSpecConverFinish(Common.Common.PASS);
                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TestStepIconColumn = 4;
                });
            }
                ProstLog.getInstance().Log(Common.Common.MODULE_PARSER, outLine.Data);
        }

        private void checkBuildFile()
        {
            try
            {
                string SourceFilePath = ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\" + "Target_SW";
                string TargetFilePath = ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TimeCreateFolderPath + "\\" + "Build";

                
                string elfFileName = SourceFilePath + "\\Debug\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + ".elf";

                
                //string mapFileName = SourceFilePath + "\\Debug\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + ".mapxml";
                string mapFileName = "";


                if (ViewModelLocator.CompilerSettingVM.CompilerSettingModel.CompilerType.Equals("TASKING"))
                {
                    mapFileName = SourceFilePath + "\\Debug\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + ".mapxml";
                }
                else if (ViewModelLocator.CompilerSettingVM.CompilerSettingModel.CompilerType.Equals("GHS"))
                {
                    mapFileName = SourceFilePath + "\\Debug\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + ".map";
                }
                string elf_src_temp = elfFileName;
                string elf_target_temp = TargetFilePath + "\\" + Path.GetFileName(elfFileName);
                File.Copy(elf_src_temp, elf_target_temp, true);

                string map_src_temp = mapFileName;
                string map_target_temp = TargetFilePath + "\\" + Path.GetFileName(mapFileName);
                File.Copy(map_src_temp, map_target_temp, true);


                ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.TestCodeList.Clear();
                ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.TestCodeList = CommonUtil.GetELFtoSourceSymbol(elfFileName);

                ViewModelLocator.PopupBuildStatusVM.PopupBuildStatusModel.IsElfSettingValue = Common.Common.PASS;
            }
            catch(Exception ex)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, typeof(PythonHandler).Name + " :: " + ex.Message + " Line :: " + CommonUtil.GetExceptionLineNumber(ex));
                ViewModelLocator.PopupBuildStatusVM.PopupBuildStatusModel.IsElfSettingValue = Common.Common.FAIL;
                return;
            }

            System.Windows.Application.Current.Dispatcher.Invoke(new Action(() =>
            {
                ////////// AUTO TEST ///////////////
                if (ViewModelLocator.ToolbarVM.ToolbarModel.TestStartMode == Common.Common.TESTMODE_AUTO)
                {
                    ViewModelLocator.PopupBuildStatusVM.CloseBuildStatusView();
                    Thread.Sleep(500);
                    ViewModelLocator.ToolbarVM.TestSpecConvertWork();
                }
            }));
            
            FunctionWorkHandler.getInstance().BuildTestWorker.ReportProgress(100);
        }

        
        public void PaserCall()
        {
            try
            {
                ProcessStartInfo myProcessStartInfo = new ProcessStartInfo(Common.Common.PYTHON_APP);

                // make sure we can read the output from stdout 
                myProcessStartInfo.UseShellExecute = false;
                myProcessStartInfo.RedirectStandardOutput = true;

                if (ViewModelLocator.MainVM.MainModel.PROGRAM_MODE == Common.Common.CUSTOMER_MANDO)
                    myProcessStartInfo.Arguments = Common.Common.PARSER_APP + " \"" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Temp" + Common.Common.PROJECT_INFO_DATA + "\" " + Common.Common.PARSER_MODE_MANDOTESTCASE;
                else if (ViewModelLocator.MainVM.MainModel.PROGRAM_MODE == Common.Common.CUSTOMER_WIA)
                    myProcessStartInfo.Arguments = Common.Common.PARSER_APP + " \"" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Temp" + Common.Common.PROJECT_INFO_DATA + "\" " + Common.Common.PARSER_MODE_WIATESTCASE;
                else
                {
                    if (ViewModelLocator.PopupTestCaseParsingVM.PopupTestCaseParsingModel.ParserSelectedItem.Contains("Mando"))
                        myProcessStartInfo.Arguments = Common.Common.PARSER_APP + " \"" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Temp" + Common.Common.PROJECT_INFO_DATA + "\" " + Common.Common.PARSER_MODE_MANDOTESTCASE;
                    else if (ViewModelLocator.PopupTestCaseParsingVM.PopupTestCaseParsingModel.ParserSelectedItem.Contains("Wia"))
                        myProcessStartInfo.Arguments = Common.Common.PARSER_APP + " \"" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Temp" + Common.Common.PROJECT_INFO_DATA + "\" " + Common.Common.PARSER_MODE_WIATESTCASE;
                }

                Process myProcess = new Process();
                // assign start information to the process 
                myProcess.StartInfo = myProcessStartInfo;
                myProcess.StartInfo.CreateNoWindow = true;
                myProcess.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;

                myProcess.StartInfo.UseShellExecute = false;
                myProcess.StartInfo.RedirectStandardOutput = true;
                myProcess.StartInfo.RedirectStandardError = true;
                //* Set your output and error (asynchronous) handlers
                myProcess.OutputDataReceived += new DataReceivedEventHandler(ParserOutputHandler);
                myProcess.ErrorDataReceived += new DataReceivedEventHandler(ParserOutputHandler);

                myProcess.Start();
                myProcess.BeginOutputReadLine();
                myProcess.BeginErrorReadLine();
                myProcess.WaitForExit();


                // close the process 
                //myProcess.Close();
            }
            catch (Exception ex)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, typeof(PythonHandler).Name + " :: " + ex.Message + " Line :: " + CommonUtil.GetExceptionLineNumber(ex));
            }
        }
        public void TraceVarParserCall()
        {
            try
            {
                ProcessStartInfo myProcessStartInfo = new ProcessStartInfo(Common.Common.PYTHON_APP);

                // make sure we can read the output from stdout 
                myProcessStartInfo.UseShellExecute = false;
                myProcessStartInfo.RedirectStandardOutput = true;
                myProcessStartInfo.Arguments = Common.Common.PARSER_APP + " \"" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Temp" + Common.Common.PROJECT_INFO_DATA + "\" " + Common.Common.PARSER_MODE_TRACEVARPARSER;

                Process myProcess = new Process();
                // assign start information to the process 
                myProcess.StartInfo = myProcessStartInfo;
                myProcess.StartInfo.CreateNoWindow = true;
                myProcess.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;

                myProcess.StartInfo.UseShellExecute = false;
                myProcess.StartInfo.RedirectStandardOutput = true;
                myProcess.StartInfo.RedirectStandardError = true;
                //* Set your output and error (asynchronous) handlers
                myProcess.OutputDataReceived += new DataReceivedEventHandler(ParserOutputHandler);
                myProcess.ErrorDataReceived += new DataReceivedEventHandler(ParserOutputHandler);

                myProcess.Start();
                myProcess.BeginOutputReadLine();
                myProcess.BeginErrorReadLine();
                myProcess.WaitForExit();


                // close the process 
                //myProcess.Close();
            }
            catch (Exception ex)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, typeof(PythonHandler).Name + " :: " + ex.Message + " Line :: " + CommonUtil.GetExceptionLineNumber(ex));
            }
        }
        public void TestStatement()
        {
            try
            {
                ProcessStartInfo myProcessStartInfo = new ProcessStartInfo(Common.Common.PYTHON_APP);

                // make sure we can read the output from stdout 
                myProcessStartInfo.UseShellExecute = false;
                myProcessStartInfo.RedirectStandardOutput = true;

                myProcessStartInfo.Arguments = Common.Common.PARSER_APP + " \"" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Temp" + Common.Common.PROJECT_INFO_DATA + "\" " + ViewModelLocator.PopupTestCaseParsingVM.PopupTestCaseParsingModel.ParserSelectedItem;

                Process myProcess = new Process();
                // assign start information to the process 
                myProcess.StartInfo = myProcessStartInfo;
                myProcess.StartInfo.CreateNoWindow = true;
                myProcess.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;

                myProcess.StartInfo.UseShellExecute = false;
                myProcess.StartInfo.RedirectStandardOutput = true;
                myProcess.StartInfo.RedirectStandardError = true;
                //* Set your output and error (asynchronous) handlers
                myProcess.OutputDataReceived += new DataReceivedEventHandler(ParserOutputHandler);
                myProcess.ErrorDataReceived += new DataReceivedEventHandler(ParserOutputHandler);

                SelectParserMode = Common.Common.PARSING_TESTSPECIFICATION;
                myProcess.Start();
                myProcess.BeginOutputReadLine();
                myProcess.BeginErrorReadLine();
                myProcess.WaitForExit();


                // close the process 
                //                myProcess.Close();

            }
            catch (Exception ex)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, typeof(PythonHandler).Name + " :: " + ex.Message + " Line :: " + CommonUtil.GetExceptionLineNumber(ex));
            }

            
        }

        public void TraceInfoParserCall()
        {
            try
            {
                ProcessStartInfo myProcessStartInfo = new ProcessStartInfo(Common.Common.PYTHON_APP);

                // make sure we can read the output from stdout 
                myProcessStartInfo.UseShellExecute = false;
                myProcessStartInfo.RedirectStandardOutput = true;


                myProcessStartInfo.Arguments = Common.Common.PARSER_APP + " \"" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Temp" + Common.Common.PROJECT_INFO_DATA + "\" " + Common.Common.PARSER_MODE_TRACEINFO;

                Process myProcess = new Process();
                // assign start information to the process 
                myProcess.StartInfo = myProcessStartInfo;
                myProcess.StartInfo.CreateNoWindow = true;
                myProcess.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;

                myProcess.StartInfo.UseShellExecute = false;
                myProcess.StartInfo.RedirectStandardOutput = true;
                myProcess.StartInfo.RedirectStandardError = true;
                //* Set your output and error (asynchronous) handlers
                myProcess.OutputDataReceived += new DataReceivedEventHandler(ParserOutputHandler);
                myProcess.ErrorDataReceived += new DataReceivedEventHandler(ParserOutputHandler);

                SelectParserMode = Common.Common.PARSING_TESTCASE;
                myProcess.Start();
                myProcess.BeginOutputReadLine();
                myProcess.BeginErrorReadLine();
                myProcess.WaitForExit();

                // close the process 
                //                    myProcess.Close();

            }
            catch (Exception ex)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, typeof(PythonHandler).Name + " :: " + ex.Message + " Line :: " + CommonUtil.GetExceptionLineNumber(ex));
            }
        }
        public void ReportCall()
        {
            try
            {
                // Create new process start info 
                ProcessStartInfo myProcessStartInfo = new ProcessStartInfo(Common.Common.PYTHON_APP);

                // make sure we can read the output from stdout 
                myProcessStartInfo.UseShellExecute = false;
                myProcessStartInfo.RedirectStandardOutput = true;

                // start python app with 3 arguments  
                // 1st arguments is pointer to itself,  
                // 2nd and 3rd are actual arguments we want to send 
                myProcessStartInfo.Arguments = Common.Common.REPORTER_APP + " \"" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Temp" + Common.Common.PROJECT_INFO_DATA;


                Process myProcess = new Process();
                // assign start information to the process 
                myProcess.StartInfo = myProcessStartInfo;
                myProcess.StartInfo.CreateNoWindow = true;
                myProcess.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;

                myProcess.StartInfo.UseShellExecute = false;
                myProcess.StartInfo.RedirectStandardOutput = true;
                myProcess.StartInfo.RedirectStandardError = true;
                //* Set your output and error (asynchronous) handlers
                myProcess.OutputDataReceived += new DataReceivedEventHandler(ReportOutputHandler);
                myProcess.ErrorDataReceived += new DataReceivedEventHandler(ReportOutputHandler);

                myProcess.Start();
                myProcess.BeginOutputReadLine();
                myProcess.BeginErrorReadLine();
                //myProcess.WaitForExit();

                // close the process 
                //myProcess.Close();
            }
            catch (Exception ex)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, typeof(PythonHandler).Name + " :: " + ex.Message + " Line :: " + CommonUtil.GetExceptionLineNumber(ex));
            }
        }
        private void ReportOutputHandler(object sendingProcess, DataReceivedEventArgs outLine)
        {
            if (outLine.Data == null)
                return;

            if (outLine.Data.Contains("Report Module Pass"))
            {
                ViewModelLocator.PopupTestStatusVM.PopupTestStatusModel.IsTestSettingValue = Common.Common.PASS;

                ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TestStepIconColumn = 8;
                ViewModelLocator.MainVM.MainModel.PopupDialogText = "TEST Complete!!";

                ViewModelLocator.PopupTestStatusVM.PopupTestStatusModel.IsTestStatusPopupOpen = true;

                if (ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TestStepIconColumn < 6)
                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TestStepIconColumn = 6;

                string parameter = "\"" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\" \"" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\" \"" + Path.GetFileNameWithoutExtension(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TimeCreateFolderPath) + "\" \"" + Path.GetFileNameWithoutExtension(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath) + "\" \"" + Common.Common.INSTALL_PATH + "\"";
                try
                {
                    Process.Start(@"..\report\GraphProject.exe", parameter);
                    ViewModelLocator.HistoryVM.ParsingHistoryData();
                }
                catch (Exception ex)
                {
                    ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, ex.Message);
                    ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, "Not Found Report Program");
                }

            }
            else if (outLine.Data == "Report Module Fail" || outLine.Data.Contains("ERR"))
            {
                ViewModelLocator.PopupTestStatusVM.PopupTestStatusModel.IsTestSettingValue = Common.Common.PASS;

                ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TestStepIconColumn = 8;
                ViewModelLocator.MainVM.MainModel.PopupDialogText = "TEST Fail!!";

                ViewModelLocator.PopupTestStatusVM.PopupTestStatusModel.IsTestStatusPopupOpen = true;
            }
            ProstLog.getInstance().Log(Common.Common.MODULE_REPORTER, outLine.Data);
        }
    }
}
