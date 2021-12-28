using ProstMain.Model;
using ProstMain.ViewModel;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace ProstMain.Util
{
    class InvFileManager
    {
        public static bool ExportInvFile()
        {
            if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.ExporttProjectPath == "")
            {
                MessageBox.Show("저장 경로가 선택되지 않았습니다.");
                return false;
            }

            string[] Project_Cfg = FileManager.FileRead(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.ProjectExplorerVM.SelectProjectName + "\\T15_Env_Config\\T15_ProjectCfg.csa");

            List<string> Export_Project_Cfg = new List<string>();

            if (Project_Cfg == null)
                return false;

            for (int i = 0; i < Project_Cfg.Length; i++)
            {
                string[] temp = Project_Cfg[i].Split(new string[] { "=$=" }, StringSplitOptions.None);

                if (temp == null) continue;

                // 해당 내용이 있고 Import Check가 되어있으면 내용 업데이트
                if (temp[0].Equals("Comment") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedComment)
                    Export_Project_Cfg.Add("Comment=$=" + temp[1]);
                else if (temp[0].Equals("Tester") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedTester)
                    Export_Project_Cfg.Add("Tester=$=" + temp[1]);
                else if (temp[0].Equals("TestStatement") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedTestStatement)
                    Export_Project_Cfg.Add("TestStatement=$=" + temp[1]);
                else if (temp[0].Equals("Frequency") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedFrequency)
                    Export_Project_Cfg.Add("Frequency=$=" + temp[1]);
                else if (temp[0].Equals("LogLevel") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedLogLevel)
                    Export_Project_Cfg.Add("LogLevel=$=" + temp[1]);
                else if (temp[0].Equals("Resolution") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedResolution)
                    Export_Project_Cfg.Add("Resolution=$=" + temp[1]);
                else if (temp[0].Equals("CompilerType") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCompilerType)
                    Export_Project_Cfg.Add("CompilerType=$=" + temp[1]);
                else if (temp[0].Equals("CompilerVersion") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCompilerVersion)
                    Export_Project_Cfg.Add("CompilerVersion=$=" + temp[1]);
                else if (temp[0].Equals("CpuName") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCpuName)
                    Export_Project_Cfg.Add("CpuName=$=" + temp[1]);
                else if (temp[0].Equals("CpuClock") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCpuClock)
                    Export_Project_Cfg.Add("CpuClock=$=" + temp[1]);
                else if (temp[0].Equals("Core") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCoreIndex)
                    Export_Project_Cfg.Add("Core=$=" + Int32.Parse(temp[1]));
                else if (temp[0].Equals("CompilerPath") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCompilerPath)
                    Export_Project_Cfg.Add("CompilerPath=$=" + temp[1]);
                else if (temp[0].Equals("CompilerOption") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCompilerOption)
                    Export_Project_Cfg.Add("CompilerOption=$=" + temp[1]);
                else if (temp[0].Equals("LinkerOption") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedLinkerOption)
                    Export_Project_Cfg.Add("LinkerOption=$=" + temp[1]);
                else if (temp[0].Equals("RunnableList") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedRunnableList)
                {
                    string[] runnable = temp[1].Split(new string[] { "$$" }, StringSplitOptions.None);
                    Export_Project_Cfg.Add("RunnableList=$=" + runnable[0] + "$$" + runnable[1] + "$$" + runnable[2] + "$$" + runnable[3]);

                }
                else if (temp[0].Equals("StubList") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedRunnableStubList)
                {
                    string[] runnableStub = temp[1].Split(new string[] { "$$" }, StringSplitOptions.None);
                    Export_Project_Cfg.Add("StubList=$=" + runnableStub[0] + "$$" + runnableStub[1] + "$$" + runnableStub[2]);
                }
                else if (temp[0].Equals("CopyPath") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCopyPathList)
                {
                    string[] copypath = temp[1].Split(new string[] { "$$" }, StringSplitOptions.None);
                    Export_Project_Cfg.Add("CopyPath=$=" + copypath[0] + "$$" + copypath[1]);
                }
                else if (temp[0].Equals("SourceCodeRootPath") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCopyPathList)
                {
                    Export_Project_Cfg.Add("SourceCodeRootPath=$=" + temp[1]);
                }
                else if (temp[0].Equals("RegisterList") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedRegisterList)
                {
                    string[] registerlist = temp[1].Split(new string[] { "$$" }, StringSplitOptions.None);
                    Export_Project_Cfg.Add("RegisterList=$=" + registerlist[0] + "$$" + registerlist[1]);
                }
                else if (temp[0].Equals("LibraryList") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedLibrary)
                {
                    Export_Project_Cfg.Add("LibraryList=$=" + temp[1]);
                }
                else if (temp[0].Equals("InitFunctionList") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedInitFunction)
                {
                    Export_Project_Cfg.Add("InitFunctionList=$=" + temp[1]);
                }
                else if (temp[0].Equals("IncludePathList") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedIncludePath)
                {
                    string[] includepathlist = temp[1].Split(new string[] { "$$" }, StringSplitOptions.None);
                    Export_Project_Cfg.Add("IncludePathList=$=" + includepathlist[0] + "$$" + includepathlist[1] + "$$" + includepathlist[2]);
                }
            }

            FileManager.FileSave_List(filePath: ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.ExporttProjectPath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "_ProjectCfg.csa", lines: Export_Project_Cfg);

            return true;
        }
        public static bool ImportInvFile()
        {
            try
            {
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.ImportProjectPath == "")
                {
                    MessageBox.Show("inv 파일이 선택되지 않았습니다.");
                    return false;
                }
                string[] Project_Cfg = FileManager.FileRead(ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.ImportProjectPath);

                if (Project_Cfg == null)
                    return false;


                bool isClearRunnableList = false;
                bool isClearRunnableStubList = false;
                bool isClearIncludePathList = false;
                bool isClearLibraryList = false;
                bool isClearInitFunction = false;
                bool isClearResigterList = false;
                bool isClearCopypath = false;

                for (int i = 0; i < Project_Cfg.Length; i++)
                {
                    string[] temp = Project_Cfg[i].Split(new string[] { "=$=" }, StringSplitOptions.None);

                    if (temp == null) continue;

                    // 해당 내용이 있고 Import Check가 되어있으면 내용 업데이트
                    if (temp[0].Equals("Comment") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedComment)
                        ViewModelLocator.ProjectSettingVM.ProjectSettingModel.Comment = temp[1];
                    else if (temp[0].Equals("Tester") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedTester)
                        ViewModelLocator.ProjectSettingVM.ProjectSettingModel.Tester = temp[1];
                    else if (temp[0].Equals("TestStatement") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedTestStatement)
                        ViewModelLocator.PopupTestCaseParsingVM.PopupTestCaseParsingModel.TestStatement = temp[1];
                    else if (temp[0].Equals("CpuName") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCpuName)
                        ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.CpuName = temp[1];
                    else if (temp[0].Equals("CpuClock") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCpuClock)
                        ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.CpuClock = Int32.Parse(temp[1]);
                    else if (temp[0].Equals("Core") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCoreIndex)
                    {
                        if(ViewModelLocator.TargetHWSettingVM.CoreList.Count > Int32.Parse(temp[1]))
                            ViewModelLocator.TargetHWSettingVM.CoreList[Int32.Parse(temp[1])] = true;
                    }
                    else if (temp[0].Equals("Frequency") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedFrequency)
                        ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.Frequency = Double.Parse(temp[1]);
                    else if (temp[0].Equals("Resolution") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedResolution)
                        ViewModelLocator.MenuBarVM.Resolution = Double.Parse(temp[1]);
                    else if (temp[0].Equals("CompilerPath") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCompilerPath)
                        ViewModelLocator.CompilerSettingVM.CompilerSettingModel.CompilerPath = temp[1];
                    else if (temp[0].Equals("CompilerType") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCompilerType)
                        ViewModelLocator.CompilerSettingVM.CompilerSettingModel.CompilerType = temp[1];
                    else if (temp[0].Equals("CompilerVersion") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCompilerVersion)
                        ViewModelLocator.CompilerSettingVM.CompilerSettingModel.CompilerVersion = temp[1];
                    else if (temp[0].Equals("CompilerOption") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCompilerOption)
                        ViewModelLocator.CompilerSettingVM.CompilerSettingModel.CompilerOption = temp[1];
                    else if (temp[0].Equals("LinkerOption") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedLinkerOption)
                        ViewModelLocator.CompilerSettingVM.CompilerSettingModel.LinkerOption = temp[1];
                    else if (temp[0].Equals("SourceCodeRootPath") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCopyPathList)
                        ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceCodeRootPath = temp[1];
                    else if (temp[0].Equals("RunnableList") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedRunnableList)
                    {
                        if (!isClearRunnableList)
                        {
                            // RunnableList의 Import가 Check되어 있으면 Clear
                            ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableList.Clear();
                            isClearRunnableList = true;
                        }

                        string[] dataSplit = temp[1].Split(new string[] { "$$" }, StringSplitOptions.None);
                        RunnableModel runnableModel = new RunnableModel();
                        runnableModel.RunnableNameGrid = dataSplit[0];
                        runnableModel.RunnableCycleGrid = dataSplit[1];
                        runnableModel.RunnableCoreGrid = dataSplit[2];
                        runnableModel.RunnableHeader = dataSplit[3];

                        ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableList.Add(runnableModel);
                    }
                    else if (temp[0].Equals("StubList") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedRunnableStubList)
                    {
                        if (!isClearRunnableStubList)
                        {
                            ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableStubList.Clear();
                            isClearRunnableStubList = true;
                        }

                        string[] dataSplit = temp[1].Split(new string[] { "$$" }, StringSplitOptions.None);
                        RunnableStubModel runnableModel = new RunnableStubModel();
                        runnableModel.RunnableSTUBFunctionGrid = dataSplit[0];
                        runnableModel.RunnableSTUBDelayGrid = dataSplit[1];
                        runnableModel.RunnableSTUBReturnGrid = dataSplit[2];

                        ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableStubList.Add(runnableModel);
                    }
                    else if (temp[0].Equals("RegisterList") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedRegisterList)
                    {
                        if (!isClearResigterList)
                        {
                            ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RegisterList.Clear();
                            isClearResigterList = true;
                        }

                        string[] registersplit = temp[1].Split(new string[] { "$$" }, StringSplitOptions.None);
                        RegisterModel registerModel = new RegisterModel();
                        registerModel.RegisterName = registersplit[0];
                        registerModel.RegisterValue = registersplit[1];

                        ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RegisterList.Add(registerModel);
                    }

                    else if (temp[0].Equals("LibraryList") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedLibrary)
                    {
                        if (!isClearLibraryList)
                        {
                            ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.LibraryPathList.Clear();
                            isClearLibraryList = true;
                        }

                        ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.LibraryPathList.Add(CommonUtil.GetAbsoluteToRelativePath(temp[1]));
                    }

                    else if (temp[0].Equals("CopyPath") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCopyPathList)
                    {
                        if (!isClearCopypath)
                        {
                            ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.CopyDictionary.Clear();
                            isClearCopypath = true;
                        }

                        string[] copypathsplit = temp[1].Split(new string[] { "$$" }, StringSplitOptions.None);

                        ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.CopyDictionary.Add("$(workspace_loc)" + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Target_SW" + copypathsplit[0].Split(new string[] { "\\Target_SW" }, StringSplitOptions.None)[1], copypathsplit[1]);
                    }
                    else if (temp[0].Equals("InitFunctionList") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedInitFunction)
                    {
                        if (!isClearInitFunction)
                        {
                            ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.InitFunctionList.Clear();
                            isClearInitFunction = true;
                        }

                        ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.InitFunctionList.Add(temp[1]);
                    }
                    else if (temp[0].Equals("IncludePathList") && ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedIncludePath)
                    {
                        if (!isClearIncludePathList)
                        {
                            ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.IncludePathList.Clear();
                            isClearIncludePathList = true;
                        }

                        string[] includesplit = temp[1].Split(new string[] { "$$" }, StringSplitOptions.None);
                        IncludePathModel includepathModel = new IncludePathModel();
                        includepathModel.AbsolutePath = includesplit[0];
                        includepathModel.RelativePath = includesplit[1];
                        ViewModelLocator.TargetSWSettingVM.AddIncludeModel(includepathModel);
                    }
                }


            }
            catch (Exception exception)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, typeof(InvFileManager).Name + " :: " + exception.Message + " Line :: " + CommonUtil.GetExceptionLineNumber(exception));
            }

            return true;
        }
        public static void initImportCheckData()
        {
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedComment = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCompilerOption = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCompilerPath = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCompilerType = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCompilerVersion = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCpuClock = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCoreIndex = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCpuName = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedFrequency = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedLinkerOption = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedLogLevel = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedRegisterList = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedResolution = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedRunnableList = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedRunnableStubList = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedIncludePath = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedInitFunction = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedLibrary = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedTestCasePath = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedTester = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedTestStatement = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCopyPathList = false;

            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportComment = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCompilerOption = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCompilerPath = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCompilerType = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCompilerVersion = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCpuClock = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCpuName = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCoreIndex = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportFrequency = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportLinkerOption = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportLogLevel = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportRegisterList = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportResolution = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportRunnableList = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportRunnableStubList = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportIncludePath = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportLibrary = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportInitFunction = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportTestCasePath = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportTester = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportTestStatement = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCopyPathList = false;

            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.ExporttProjectPath = "";
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.ImportProjectPath = "";
        }
        public static void initExportCheckData()
        {
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedComment = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCompilerOption = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCompilerPath = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCompilerType = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCompilerVersion = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCpuClock = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCpuName = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedFrequency = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedLinkerOption = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedLogLevel = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedRegisterList = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedResolution = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedRunnableList = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedRunnableStubList = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedIncludePath = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedInitFunction = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedLibrary = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedTestCasePath = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedTester = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedTestStatement = false;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCopyPathList = false;

            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportComment = true;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCompilerOption = true;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCompilerPath = true;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCompilerType = true;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCompilerVersion = true;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCpuClock = true;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCpuName = true;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportFrequency = true;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportLinkerOption = true;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportLogLevel = true;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportRegisterList = true;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportResolution = true;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportRunnableList = true;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportRunnableStubList = true;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportIncludePath = true;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportLibrary = true;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportInitFunction = true;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportTestCasePath = true;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportTester = true;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportTestStatement = true;
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCopyPathList = true;

            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.ExporttProjectPath = "";
        }
        public static bool CheckImportInvFile(string path)
        {
            try
            {
                string[] Project_Cfg = FileManager.FileRead(path);

                if (Project_Cfg == null)
                    return false;

                for (int i = 0; i < Project_Cfg.Length; i++)
                {
                    string[] temp = Project_Cfg[i].Split(new string[] { "=$=" }, StringSplitOptions.None);

                    if (temp == null) continue;

                    if (temp[0].Equals("Comment"))
                        ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportComment = true;
                    else if (temp[0].Equals("Tester"))
                        ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportTester = true;
                    else if (temp[0].Equals("TestStatement"))
                        ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportTestStatement = true;
                    else if (temp[0].Equals("InitFunctionList"))
                        ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportInitFunction = true;
                    else if (temp[0].Equals("LibraryList"))
                        ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportLibrary = true;
                    else if (temp[0].Equals("IncludePathList"))
                        ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportIncludePath = true;
                    else if (temp[0].Equals("Frequency"))
                        ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportFrequency = true;
                    else if (temp[0].Equals("LogLevel"))
                        ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportLogLevel = true;
                    else if (temp[0].Equals("Resolution"))
                        ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportResolution = true;
                    else if (temp[0].Equals("CompilerType"))
                        ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCompilerType = true;
                    else if (temp[0].Equals("CompilerVersion"))
                        ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCompilerVersion = true;
                    else if (temp[0].Equals("CpuName"))
                        ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCpuName = true;
                    else if (temp[0].Equals("Core"))
                        ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCoreIndex = true;
                    else if (temp[0].Equals("CpuClock"))
                        ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCpuClock = true;
                    else if (temp[0].Equals("TestcasePath"))
                        ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportTestCasePath = true;
                    else if (temp[0].Equals("CompilerPath"))
                        ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCompilerPath = true;
                    else if (temp[0].Equals("CompilerOption"))
                        ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCompilerOption = true;
                    else if (temp[0].Equals("LinkerOption"))
                        ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportLinkerOption = true;
                    else if (temp[0].Equals("RunnableList"))
                        ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportRunnableList = true;
                    else if (temp[0].Equals("StubList"))
                        ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportRunnableStubList = true;
                    else if (temp[0].Equals("RegisterList"))
                        ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportRegisterList = true;
                    else if (temp[0].Equals("CopyPath"))
                        ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCopyPathList = true;
                }
            }
            catch (Exception exception)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, typeof(InvFileManager).Name + " :: " + exception.Message + " Line :: " + CommonUtil.GetExceptionLineNumber(exception));
            }

            return true;
        }

    }
}
