using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using GalaSoft.MvvmLight.Messaging;
using ProstMain.Common;
using ProstMain.Dialog;
using ProstMain.Model;
using ProstMain.Util;
using ProstMain.View;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Threading;
using System.Xml;



namespace ProstMain.ViewModel
{
    public class ProjectExplorerViewModel : ViewModelBase
    {
        public RelayCommand<object> TreeViewItemSelectCommand { get; set; }


        #region Variable
        private ProjectExplorerModel _ProjectExplorerModel;
        public ProjectExplorerModel ProjectExplorerModel
        {
            get { return _ProjectExplorerModel; }
            set
            {
                if (_ProjectExplorerModel != value)
                {
                    _ProjectExplorerModel = value;
                    RaisePropertyChanged("ProjectExplorerModel");
                }
            }
        }

        private Boolean _IsSelected;
        public Boolean IsSelected
        {
            get { return _IsSelected; }
            set
            {
                if (_IsSelected != value)
                {
                    _IsSelected = value;
                    RaisePropertyChanged("IsSelected");
                }
            }
        }
        private string _SelectProjectName;
        public string SelectProjectName
        {
            get { return _SelectProjectName; }
            set
            {
                if (_SelectProjectName != value)
                {
                    _SelectProjectName = value;
                    RaisePropertyChanged("SelectProjectName");
                }
            }
        }


        #endregion

        public ProjectExplorerViewModel()
        {
            TreeViewItemSelectCommand = new RelayCommand<object>(TreeViewItemSelect);

            IsSelected = true;
            ProjectExplorerModel = new ProjectExplorerModel();
            //LoadWorkSpace(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath);

        }

        


        public void TreeViewItemSelect(object e)
        {
            if (e != null)
            {
                try
                {
                    ProjectExplorerListModel obj = (ProjectExplorerListModel)e;
                    if (obj.SubItem.Count > 0) // Project Name Click시
                    {
                        if (ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName != null)
                        {
                            ViewModelLocator.MainVM.MainModel.BeforeSaveMode = Common.Common.SAVE_MODE;
                            SaveProject();
                        }
                        ProjectLoad(obj.ItemName);
                        ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceCodePath = ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Target_SW";
                    }
                }
                catch (Exception exception)
                {
                    Console.WriteLine(exception.Message);
                    ProjectExplorerSubListModel obj = (ProjectExplorerSubListModel)e;
                    if (!ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName.Equals(obj.ParentName))
                    {
                        if (ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName != null)
                        {
                            ViewModelLocator.MainVM.MainModel.BeforeSaveMode = Common.Common.SAVE_MODE;
                            SaveProject();
                        }
                        ProjectLoad(obj.ParentName);
                    }


                    DispatcherTimer dispatcherTimer = new DispatcherTimer();
                    if (obj.ItemName.Contains("1."))
                    {
                        ViewModelLocator.MainVM.MainModel.TabControlIndex = 1;
                        ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.IsOpenTargetSetting = true;
                        ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.IsVisibleCPUNameGuild = "True";
                        dispatcherTimer.Tick += (sender, a) => { UpdateGuidTimerTick(sender, a, 1); };
                        dispatcherTimer.Interval = new TimeSpan(0, 0, 2);
                        dispatcherTimer.Start();
                    }
                    else if (obj.ItemName.Contains("2."))
                    {
                        ViewModelLocator.MainVM.MainModel.TabControlIndex = 2;
                        ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.IsVisibleTestCodePathGuild = "True";
                        dispatcherTimer.Tick += (sender, a) => { UpdateGuidTimerTick(sender, a, 2); };
                        dispatcherTimer.Interval = new TimeSpan(0, 0, 2);
                        dispatcherTimer.Start();
                    }
                    else if (obj.ItemName.Contains("3."))
                    {
                        ViewModelLocator.MainVM.MainModel.TabControlIndex = 3;
                        ViewModelLocator.CompilerSettingVM.CompilerSettingModel.IsVisibleCompileGuild = "True";
                        dispatcherTimer.Tick += (sender, a) => { UpdateGuidTimerTick(sender, a, 3); };
                        dispatcherTimer.Interval = new TimeSpan(0, 0, 2);
                        dispatcherTimer.Start();
                    }
                    else if (obj.ItemName.Contains("4."))
                    {
                        ViewModelLocator.ToolbarVM.ToolbarModel.IsVisibleBuildGuild = "True";
                        dispatcherTimer.Tick += (sender, a) => { UpdateGuidTimerTick(sender, a, 4); };
                        dispatcherTimer.Interval = new TimeSpan(0, 0, 2);
                        dispatcherTimer.Start();
                    }
                    else if (obj.ItemName.Contains("5."))
                    {
                        /*ViewModelLocator.MainVM.MainModel.TabControlIndex = 4;
                        ViewModelLocator.TestSettingVM.TestSettingModel.IsVisibleTestCaseGuild = "True";
                        dispatcherTimer.Tick += (sender, a) => { UpdateGuidTimerTick(sender, a, 5); };
                        dispatcherTimer.Interval = new TimeSpan(0, 0, 2);
                        dispatcherTimer.Start();*/
                        ViewModelLocator.ToolbarVM.ToolbarModel.IsVisibleTestCaseGuild = "True";
                        dispatcherTimer.Tick += (sender, a) => { UpdateGuidTimerTick(sender, a, 5); };
                        dispatcherTimer.Interval = new TimeSpan(0, 0, 2);
                        dispatcherTimer.Start();
                    }
                    /*                    else if (obj.ItemName.Contains("6."))
                                        {
                                            ViewModelLocator.MainVM.MainModel.TabControlIndex = 5;
                                        }*/
                    else if (obj.ItemName.Contains("6."))
                    {
                        ViewModelLocator.ToolbarVM.ToolbarModel.IsVisibleTestStartGuild = "True";
                        dispatcherTimer.Tick += (sender, a) => { UpdateGuidTimerTick(sender, a, 6); };
                        dispatcherTimer.Interval = new TimeSpan(0, 0, 2);
                        dispatcherTimer.Start();
                    }
                }
            }
        }
        
        private void UpdateGuidTimerTick(object sender, EventArgs e, int Step)
        {
            switch (Step)
            {
                case 1:
                    ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.IsVisibleCPUNameGuild = "Stop";
                    break;
                case 2:
                    ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.IsVisibleTestCodePathGuild = "Stop";
                    break;
                case 3:
                    ViewModelLocator.CompilerSettingVM.CompilerSettingModel.IsVisibleCompileGuild = "Stop";
                    break;
                case 4:
                    ViewModelLocator.ToolbarVM.ToolbarModel.IsVisibleBuildGuild = "Stop";
                    break;
                case 5:
                    ViewModelLocator.ToolbarVM.ToolbarModel.IsVisibleTestCaseGuild = "Stop";
                    break;
                case 6:
                    ViewModelLocator.ToolbarVM.ToolbarModel.IsVisibleTestStartGuild = "Stop";
                    break;
            }
            (sender as DispatcherTimer).Stop();
        }

        
        public void LoadWorkSpace(string workspace)
        {
            try
            {
                ProjectExplorerModel.ProjectExplorerModelList.Clear();
                ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName = null;
                if (workspace != null && workspace != "")
                {
                    string path = workspace + "\\workspace_projectlist.xml";

                    FileInfo fileInfo = new FileInfo(path);

                    if (fileInfo.Exists) //workspace에 workspace_projectlist.xml 파일이 있으면, 파싱해서 List에 추가.
                    {
                        string proj_list_path = System.IO.File.ReadAllText(path);

                        XmlDocument xml = new XmlDocument();
                        xml.LoadXml(proj_list_path);
                        XmlElement root = xml.DocumentElement;

                        XmlNodeList xnlist = root.ChildNodes;
                        List<XmlNode> removelist = new List<XmlNode>();
                        List<XmlNode> replacelist = new List<XmlNode>();

                        foreach (XmlNode item in xnlist)
                        {
                            string node_name = item.SelectSingleNode("Name").InnerText;
                            string node_path = item.SelectSingleNode("Path").InnerText;

                            string convert_nodepath = node_path.Replace("$(workspace_loc)", ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath);

                            if (!Directory.Exists(convert_nodepath))
                            {
                                removelist.Add(item);
                                continue;
                            }
                            if (!item.SelectSingleNode("Path").InnerText.Contains("$(workspace_loc)")) {
                                item.SelectSingleNode("Path").InnerText = "$(workspace_loc)" + @"\" + item.SelectSingleNode("Path").InnerText.Split('\\').Last();
                                replacelist.Add(item);
                            }


                            ObservableCollection<ProjectExplorerSubListModel> subItems = new ObservableCollection<ProjectExplorerSubListModel>();


                            subItems.Add(new ProjectExplorerSubListModel { ItemName = "1. 타겟 CPU 설정", ListType = Common.Common.PROPERTY, FolderImage = "FileDocumentBoxOutline",ParentName = node_name});
                            subItems.Add(new ProjectExplorerSubListModel { ItemName = "2. 소스코드 경로 설정", ListType = Common.Common.PROPERTY, FolderImage = "FileDocumentBoxOutline", ParentName = node_name });
                            subItems.Add(new ProjectExplorerSubListModel { ItemName = "3. 컴파일러 설정", ListType = Common.Common.PROPERTY, FolderImage = "FileDocumentBoxOutline", ParentName = node_name });
                            subItems.Add(new ProjectExplorerSubListModel { ItemName = "4. ELF 파일 빌드 작업", ListType = Common.Common.PROPERTY, FolderImage = "FileDocumentBoxOutline", ParentName = node_name });
                            subItems.Add(new ProjectExplorerSubListModel { ItemName = "5. 테스트 케이스 파싱 작업", ListType = Common.Common.PROPERTY, FolderImage = "FileDocumentBoxOutline", ParentName = node_name });
                            //subItems.Add(new ProjectExplorerSubListModel { ItemName = "6. 테스트 리포트 옵션 설정", ListType = Common.Common.PROPERTY, FolderImage = "FileDocumentBoxOutline" });
                            subItems.Add(new ProjectExplorerSubListModel { ItemName = "6. 테스트 시작", ListType = Common.Common.PROPERTY, FolderImage = "FileDocumentBoxOutline", ParentName = node_name });

                            ProjectExplorerModel.ProjectExplorerModelList.Add(new ProjectExplorerListModel() { ItemName = node_name, SubItem = subItems, ListType = Common.Common.PROJECT, FolderImage = "FolderOutline" });
                        }

                        if(removelist.Count > 0)
                        {
                            foreach(XmlNode node in removelist)
                            {
                                root.RemoveChild(node);
                                xml.Save(path);
                            }
                        }
                        if(replacelist.Count > 0)
                        {
                            foreach (XmlNode node in replacelist)
                            {
                                root.RemoveChild(node);
                                root.AppendChild(node);
                                xml.Save(path);
                            }
                        }

                        if (ProjectExplorerModel.ProjectExplorerModelList.Count == 0) // xml에 정상적인 경로가 1도 없을 때
                        {
                            //xml.RemoveAll();
                            ViewModelLocator.MainVM.ShowDialog_CreateProject();
                        }
                        ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.WorkspaceRootPath = workspace;
                    }
                    else //없으면 workspace_projectlist.xml 파일 생성
                    {
                        XmlDocument NewXmlDoc = new XmlDocument();
                        NewXmlDoc.AppendChild(NewXmlDoc.CreateXmlDeclaration("1.0", "utf-8", "yes"));

                        XmlNode root = NewXmlDoc.CreateElement("", "Projects", "");
                        NewXmlDoc.AppendChild(root);

                        NewXmlDoc.Save(path);
                    }
                }
                if (ProjectExplorerModel.ProjectExplorerModelList.Count == 0)
                {
                    InitProgram();
                }

            }
            catch (Exception ex)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, typeof(ProjectExplorerViewModel).Name + " :: " + ex.Message + " Line :: " + CommonUtil.GetExceptionLineNumber(ex));
            }
        }
        public void ProjectLoad(string projectName)
        {
            ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TestDate = DateTime.Now.ToString("yyyyMMdd");
            ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName = projectName;
            ViewModelLocator.ProjectExplorerVM.SelectProjectName = projectName;

            ViewModelLocator.MainVM.ParsingLastTestData(Common.Common.SELECT_INIT, "", "", "");
            ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.CopyDictionary.Clear();
            ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.IncludePathList.Clear();
            ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.InitFunctionList.Clear();
            ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.LibraryPathList.Clear();
            ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.MemoryLocationTextABS18.Text = "";
            ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.MemoryLocationTextLinear.Text = "";

            for (int i = 0; i < ViewModelLocator.TargetHWSettingVM.CoreList.Count; i++)
                ViewModelLocator.TargetHWSettingVM.CoreList[i] = false;


            InitProgram();
            try
            {
                string[] Project_Cfg = FileManager.FileRead(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + projectName + "\\" + "T15_Env_Config\\T15_ProjectCfg.csa");

                if (Project_Cfg == null)
                    return;

                for (int i = 0; i < Project_Cfg.Length; i++)
                {
                    string[] temp = Project_Cfg[i].Split(new string[] { "=$=" }, StringSplitOptions.None);

                    if (temp[0].Equals("CopyPath"))
                    {
                        string[] CopyPathSplit = temp[1].Split(new string[] { "$$" }, StringSplitOptions.None);
                        ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.CopyDictionary.Add(CopyPathSplit[0], CopyPathSplit[1]);
                    }
                }

                for (int i = 0; i < Project_Cfg.Length; i++)
                {
                    string[] temp = Project_Cfg[i].Split(new string[] { "=$=" }, StringSplitOptions.None);

                    if (temp == null) continue;

                    if (temp[0].Equals("Comment"))
                        ViewModelLocator.ProjectSettingVM.ProjectSettingModel.Comment = temp[1];
                    else if (temp[0].Equals("Tester"))
                        ViewModelLocator.ProjectSettingVM.ProjectSettingModel.Tester = temp[1];
                    else if (temp[0].Equals("CpuName"))
                        ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.CpuName = temp[1];
                    else if (temp[0].Equals("CpuClock"))
                    {
                        if (temp[1] != "")
                            ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.CpuClock = double.Parse(temp[1]);
                    }
                    else if (temp[0].Equals("Core"))
                    {
                        ViewModelLocator.TargetHWSettingVM.CoreList[Int32.Parse(temp[1])] = true;
                    }
                    else if (temp[0].Equals("TestStatement"))
                        ViewModelLocator.PopupTestCaseParsingVM.PopupTestCaseParsingModel.TestStatement = CommonUtil.GetAbsoluteToRelativePath(temp[1]);
                    else if (temp[0].Equals("Testcase"))
                        ViewModelLocator.PopupTestCaseParsingVM.PopupTestCaseParsingModel.TestcasePath = temp[1];
                    else if (temp[0].Equals("Resolution"))
                        ViewModelLocator.MenuBarVM.Resolution = double.Parse(temp[1]);
                    else if (temp[0].Equals("ParserSelectedItem"))
                        ViewModelLocator.PopupTestCaseParsingVM.PopupTestCaseParsingModel.ParserSelectedItem = temp[1];
                    else if (temp[0].Equals("Frequency"))
                    {
                        if (temp[1] != "")
                            ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.Frequency = double.Parse(temp[1]);
                    }
                    else if (temp[0].Equals("WorkspaceRootPath"))
                    {
                        if (Directory.Exists(temp[1]))
                            ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.WorkspaceRootPath = temp[1];
                        else
                            ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.WorkspaceRootPath = ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath;
                    }
                    else if (temp[0].Equals("SourceCodeRootPath"))
                    {
                        if (Directory.Exists(temp[1]))
                            ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceCodeRootPath = temp[1];
                        else
                            ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceCodeRootPath = @"C:\";
                    }
                    else if (temp[0].Equals("EnumScriptPath"))
                        ViewModelLocator.ETCSettingVM.EnumScriptPath = temp[1];
                    else if (temp[0].Equals("TestSummaryReportPath"))
                        ViewModelLocator.ReportSettingVM.ReportSettingModel.TestSummaryReport_Path = temp[1];
                    else if (temp[0].Equals("IOTestReportPath"))
                        ViewModelLocator.ReportSettingVM.ReportSettingModel.IOTestReport_Path = temp[1];
                    else if (temp[0].Equals("CodeCoverageReportPath"))
                        ViewModelLocator.ReportSettingVM.ReportSettingModel.CodeCoverageReport_Path = temp[1];
                    else if (temp[0].Equals("PerformanceReportPath"))
                        ViewModelLocator.ReportSettingVM.ReportSettingModel.PerformanceMeasurementReport_Path = temp[1];
                    else if (temp[0].Equals("IOTestReport_InputData"))
                        ViewModelLocator.ReportSettingVM.ReportSettingModel.IOTestReport_InputData = bool.Parse(temp[1]);
                    else if (temp[0].Equals("IOTestReport_OutputData"))
                        ViewModelLocator.ReportSettingVM.ReportSettingModel.IOTestReport_OutputData = bool.Parse(temp[1]);
                    else if (temp[0].Equals("IOTestReport_ExpectedData"))
                        ViewModelLocator.ReportSettingVM.ReportSettingModel.IOTestReport_ExpectedData = bool.Parse(temp[1]);
                    else if (temp[0].Equals("IOTestReport_TestPassFail"))
                        ViewModelLocator.ReportSettingVM.ReportSettingModel.IOTestReport_TestPassFail = bool.Parse(temp[1]);
                    else if (temp[0].Equals("IOTestReport_RuntimeMeasure"))
                        ViewModelLocator.ReportSettingVM.ReportSettingModel.IOTestReport_RuntimeMeasure = bool.Parse(temp[1]);
                    else if (temp[0].Equals("CodeCoverageReport_FunctionCall"))
                        ViewModelLocator.ReportSettingVM.ReportSettingModel.CodeCoverageReport_FunctionCall = bool.Parse(temp[1]);
                    else if (temp[0].Equals("CodeCoverageReport_Statement"))
                        ViewModelLocator.ReportSettingVM.ReportSettingModel.CodeCoverageReport_Statement = bool.Parse(temp[1]);
                    else if (temp[0].Equals("CodeCoverageReport_MC_DC"))
                        ViewModelLocator.ReportSettingVM.ReportSettingModel.CodeCoverageReport_MC_DC = bool.Parse(temp[1]);
                    else if (temp[0].Equals("PerformanceMeasurementReport_ExecuteChart"))
                        ViewModelLocator.ReportSettingVM.ReportSettingModel.PerformanceMeasurementReport_ExecuteChart = bool.Parse(temp[1]);
                    else if (temp[0].Equals("PerformanceMeasurementReport_DataReadWrite"))
                        ViewModelLocator.ReportSettingVM.ReportSettingModel.PerformanceMeasurementReport_DataReadWrite = bool.Parse(temp[1]);
                    else if (temp[0].Equals("PerformanceMeasurementReport_BenchMark"))
                        ViewModelLocator.ReportSettingVM.ReportSettingModel.PerformanceMeasurementReport_BenchMark = bool.Parse(temp[1]);
                    else if (temp[0].Equals("CompilerPath"))
                        ViewModelLocator.CompilerSettingVM.CompilerSettingModel.CompilerPath = temp[1];
                    else if (temp[0].Equals("CompilerOption"))
                        ViewModelLocator.CompilerSettingVM.CompilerSettingModel.CompilerOption = temp[1];
                    else if (temp[0].Equals("LinkerOption"))
                        ViewModelLocator.CompilerSettingVM.CompilerSettingModel.LinkerOption = temp[1];
                    else if (temp[0].Equals("CompilerType"))
                        ViewModelLocator.CompilerSettingVM.CompilerSettingModel.CompilerType = temp[1];
                    else if (temp[0].Equals("CompilerVersion"))
                        ViewModelLocator.CompilerSettingVM.CompilerSettingModel.CompilerVersion = temp[1];
                    else if (temp[0].Equals("DirectELFPath"))
                        ViewModelLocator.PopupBuildStatusVM.PopupBuildStatusModel.DirectELFFilePath= temp[1];
                    else if (temp[0].Equals("DirectMapxmlPath"))
                        ViewModelLocator.PopupBuildStatusVM.PopupBuildStatusModel.DirectMapFilePath = temp[1];
                    else if (temp[0].Equals("LogLevel"))
                    {
                        ViewModelLocator.MenuBarVM.LogLevelIndex = Convert.ToInt32(temp[1]);
                        ViewModelLocator.MenuBarVM.LogLevel_1_Checked = false;
                        ViewModelLocator.MenuBarVM.LogLevel_2_Checked = false;
                        ViewModelLocator.MenuBarVM.LogLevel_3_Checked = false;

                        switch (ViewModelLocator.MenuBarVM.LogLevelIndex)
                        {
                            case Common.Common.LOG_STANDARD:
                                ViewModelLocator.MenuBarVM.LogLevel_1_Checked = true;
                                break;
                            case Common.Common.LOG_INFORMATION:
                                ViewModelLocator.MenuBarVM.LogLevel_2_Checked = true;
                                break;
                            case Common.Common.LOG_DEBUG:
                                ViewModelLocator.MenuBarVM.LogLevel_3_Checked = true;
                                break;

                        }
                    }
                    else if (temp[0].Equals("RunnableList"))
                    {
                        string[] dataSplit = temp[1].Split(new string[] { "$$" }, StringSplitOptions.None);
                        RunnableModel runnableModel = new RunnableModel();
                        runnableModel.RunnableNameGrid = dataSplit[0];
                        runnableModel.RunnableCycleGrid = dataSplit[1];
                        runnableModel.RunnableCoreGrid = dataSplit[2];
                        runnableModel.RunnableHeader = dataSplit[3];

                        ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableList.Add(runnableModel);
                    }
                    else if (temp[0].Equals("StubList"))
                    {
                        string[] dataSplit = temp[1].Split(new string[] { "$$" }, StringSplitOptions.None);
                        RunnableStubModel runnableModel = new RunnableStubModel();
                        runnableModel.RunnableSTUBFunctionGrid = dataSplit[0];
                        runnableModel.RunnableSTUBDelayGrid = dataSplit[1];
                        runnableModel.RunnableSTUBReturnGrid = dataSplit[2];

                        ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableStubList.Add(runnableModel);
                    }
                    else if (temp[0].Equals("RegisterList"))
                    {
                        string[] dataSplit = temp[1].Split(new string[] { "$$" }, StringSplitOptions.None);
                        RegisterModel registerModel = new RegisterModel();
                        registerModel.RegisterName = dataSplit[0];
                        registerModel.RegisterValue = dataSplit[1];

                        ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RegisterList.Add(registerModel);
                    }

                    else if (temp[0].Equals("IncludePathList"))
                    {
                        string[] IncludePathSplit = temp[1].Split(new string[] { "$$" }, StringSplitOptions.None);

                        string absolute = IncludePathSplit[0];
                        string relative = IncludePathSplit[1];
                        IncludePathModel includePathmodel = new IncludePathModel();

                        if (relative != "" && !Directory.Exists(absolute)) // 상대경로가있고 절대경로가 존재하지 않는 경로일 때, 상대경로가 있다는 것은 Target_SW안에 있다는 것
                        {
                            includePathmodel.AbsolutePath = ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Target_SW" + absolute.Split(new string[] { "Target_SW" }, StringSplitOptions.None)[1];
                            includePathmodel.RelativePath = relative;
                        }
                        else
                        {
                            includePathmodel.AbsolutePath = absolute;
                            includePathmodel.RelativePath = relative;
                        }
                        ViewModelLocator.TargetSWSettingVM.AddIncludeModel(includePathmodel);
                    }
                    else if (temp[0].Equals("InitFunctionList"))
                    {
                        ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.InitFunctionList.Add(temp[1]);
                    }
                    else if (temp[0].Equals("LibraryList"))
                    {
                        ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.LibraryPathList.Add(CommonUtil.GetAbsoluteToRelativePath(temp[1]));
                    }
                    else if (temp[0].Equals("TestcodePath"))
                    {
                        ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceCodePath = ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Target_SW";
                    }
                }
                // Update Value & View
                TargetHWSettingView.Instance.UpdateView();

                ViewModelLocator.TargetSWSettingVM.RefreshFileFolder();

                if (File.Exists(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\" + "T15_Env_Config\\ABS18.csa"))
                    ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.MemoryLocationTextABS18.Text = File.ReadAllText(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\" + "T15_Env_Config\\ABS18.csa");
                if (File.Exists(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\" + "T15_Env_Config\\Linear.csa"))
                    ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.MemoryLocationTextLinear.Text = File.ReadAllText(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\" + "T15_Env_Config\\Linear.csa");

                ViewModelLocator.HistoryVM.ParsingHistoryData();
            }
            catch (Exception exception)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, typeof(ProjectExplorerViewModel).Name + " :: " + exception.Message + " Line :: " + CommonUtil.GetExceptionLineNumber(exception));
            }
        }
        public void InitProgram()
        {
            ViewModelLocator.ProjectSettingVM.ProjectSettingModel.Tester = "";
            ViewModelLocator.ProjectSettingVM.ProjectSettingModel.Comment = "";
            ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.CpuClock = 100;
            ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.CpuName = null;
            ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.Frequency = 0.0;

            ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableList.Clear();
            ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableStubList.Clear();
            ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RegisterList.Clear();

            ViewModelLocator.CompilerSettingVM.CompilerSettingModel.CompilerPath = "";
            ViewModelLocator.CompilerSettingVM.CompilerSettingModel.CompilerOption = "";
            ViewModelLocator.CompilerSettingVM.CompilerSettingModel.LinkerOption = "";
            ViewModelLocator.CompilerSettingVM.CompilerSettingModel.CompilerVersion = null;
            ViewModelLocator.CompilerSettingVM.CompilerSettingModel.CompilerType = null;

            ViewModelLocator.PopupTestCaseParsingVM.PopupTestCaseParsingModel.TestStatement = "";
            ViewModelLocator.PopupTestCaseParsingVM.PopupTestCaseParsingModel.TestcasePath = "";

            ViewModelLocator.HistoryVM.MemoryUseage.Clear();


            /*            ViewModelLocator.ProjectSettingVM.ProjectSettingModel = null;
                        //ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel = null;
                        ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel = null;
                        ViewModelLocator.TestSettingVM.TestSettingModel = null;
                        ViewModelLocator.CompilerSettingVM.CompilerModel = null;
                        ViewModelLocator.ProjectSettingVM.ProjectSettingModel = new ProjectSettingModel();
                        //ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel = new TargetHWSettingModel();
                        ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel = new TargetSWSettingModel();
                        ViewModelLocator.TestSettingVM.TestSettingModel = new TestSettingModel();
                        ViewModelLocator.CompilerSettingVM.CompilerModel = new CompilerSettingModel();*/
        }
        public void CreateNewProject(string s)
        {
            string ret_msg = s;

            add_newProjectFolder(ret_msg);
            LoadWorkSpace(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath);
            ViewModelLocator.MainVM.showTrackBarMessage("Create New Project");

        }
        public void OpenProject(string _project_name)
        {
            string savePath = ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\workspace_projectlist.xml";
            XmlDocument XmlDoc = new XmlDocument();
            XmlDoc.Load(savePath);

            XmlNode firstnode = XmlDoc.DocumentElement;
            XmlElement root = XmlDoc.CreateElement("Project");

            root.AppendChild(createnode(XmlDoc, "Name", _project_name));
            root.AppendChild(createnode(XmlDoc, "Path", "$(workspace_loc)" + @"\" + _project_name));

            firstnode.AppendChild(root);
            XmlDoc.Save(savePath);
            LoadWorkSpace(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath);
        }
        public void SaveProject()
        {
            List<string> Project_Cfg = new List<string>();

            Project_Cfg.Add("Comment=$=" + ViewModelLocator.ProjectSettingVM.ProjectSettingModel.Comment);
            Project_Cfg.Add("Tester=$=" + ViewModelLocator.ProjectSettingVM.ProjectSettingModel.Tester);
            Project_Cfg.Add("TestStatement=$=" + ViewModelLocator.PopupTestCaseParsingVM.PopupTestCaseParsingModel.TestStatement);
            Project_Cfg.Add("Testcase=$=" + ViewModelLocator.PopupTestCaseParsingVM.PopupTestCaseParsingModel.TestcasePath);
            Project_Cfg.Add("Frequency=$=" + ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.Frequency);
            Project_Cfg.Add("LogLevel=$=" + ViewModelLocator.MenuBarVM.LogLevelIndex);
            Project_Cfg.Add("Resolution=$=" + ViewModelLocator.MenuBarVM.Resolution);
            Project_Cfg.Add("CompilerType=$=" + ViewModelLocator.CompilerSettingVM.CompilerSettingModel.CompilerType);
            Project_Cfg.Add("CompilerVersion=$=" + ViewModelLocator.CompilerSettingVM.CompilerSettingModel.CompilerVersion);

            Project_Cfg.Add("CpuName=$=" + ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.CpuName);

            Project_Cfg.Add("DirectELFPath=$=" + ViewModelLocator.PopupBuildStatusVM.PopupBuildStatusModel.DirectELFFilePath);
            Project_Cfg.Add("DirectMapxmlPath=$=" + ViewModelLocator.PopupBuildStatusVM.PopupBuildStatusModel.DirectMapFilePath);

            for (int i=0;i< ViewModelLocator.TargetHWSettingVM.CoreList.Count;i++)
            {
                if(ViewModelLocator.TargetHWSettingVM.CoreList[i])
                    Project_Cfg.Add("Core=$=" + i);
            }
            Project_Cfg.Add("CpuClock=$=" + ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.CpuClock);
            Project_Cfg.Add("TestcodePath=$=" + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceCodePath);
            Project_Cfg.Add("WorkspaceRootPath=$=" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath);
            Project_Cfg.Add("SourceCodeRootPath=$=" + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceCodeRootPath);
            Project_Cfg.Add("EnumScriptPath=$=" + ViewModelLocator.ETCSettingVM.EnumScriptPath);

            Project_Cfg.Add("CompilerPath=$=" + ViewModelLocator.CompilerSettingVM.CompilerSettingModel.CompilerPath);
            Project_Cfg.Add("CompilerOption=$=" + ViewModelLocator.CompilerSettingVM.CompilerSettingModel.CompilerOption);
            Project_Cfg.Add("LinkerOption=$=" + ViewModelLocator.CompilerSettingVM.CompilerSettingModel.LinkerOption);
            Project_Cfg.Add("ParserSelectedItem=$=" + ViewModelLocator.PopupTestCaseParsingVM.PopupTestCaseParsingModel.ParserSelectedItem);


            Project_Cfg.Add("TestSummaryReportPath=$=" + ViewModelLocator.ReportSettingVM.ReportSettingModel.TestSummaryReport_Path);
            Project_Cfg.Add("IOTestReportPath=$=" + ViewModelLocator.ReportSettingVM.ReportSettingModel.IOTestReport_Path);
            Project_Cfg.Add("IOTestReport_InputData=$=" + ViewModelLocator.ReportSettingVM.ReportSettingModel.IOTestReport_InputData);
            Project_Cfg.Add("IOTestReport_OutputData=$=" + ViewModelLocator.ReportSettingVM.ReportSettingModel.IOTestReport_OutputData);
            Project_Cfg.Add("IOTestReport_ExpectedData=$=" + ViewModelLocator.ReportSettingVM.ReportSettingModel.IOTestReport_ExpectedData);
            Project_Cfg.Add("IOTestReport_TestPassFail=$=" + ViewModelLocator.ReportSettingVM.ReportSettingModel.IOTestReport_TestPassFail);
            Project_Cfg.Add("IOTestReport_RuntimeMeasure=$=" + ViewModelLocator.ReportSettingVM.ReportSettingModel.IOTestReport_RuntimeMeasure);

            Project_Cfg.Add("CodeCoverageReportPath=$=" + ViewModelLocator.ReportSettingVM.ReportSettingModel.CodeCoverageReport_Path);
            Project_Cfg.Add("CodeCoverageReport_FunctionCall=$=" + ViewModelLocator.ReportSettingVM.ReportSettingModel.CodeCoverageReport_FunctionCall);
            Project_Cfg.Add("CodeCoverageReport_MC_DC=$=" + ViewModelLocator.ReportSettingVM.ReportSettingModel.CodeCoverageReport_MC_DC);
            Project_Cfg.Add("CodeCoverageReport_Statement=$=" + ViewModelLocator.ReportSettingVM.ReportSettingModel.CodeCoverageReport_Statement);

            Project_Cfg.Add("PerformanceReportPath=$=" + ViewModelLocator.ReportSettingVM.ReportSettingModel.PerformanceMeasurementReport_Path);
            Project_Cfg.Add("PerformanceMeasurementReport_BenchMark=$=" + ViewModelLocator.ReportSettingVM.ReportSettingModel.PerformanceMeasurementReport_BenchMark);
            Project_Cfg.Add("PerformanceMeasurementReport_DataReadWrite=$=" + ViewModelLocator.ReportSettingVM.ReportSettingModel.PerformanceMeasurementReport_DataReadWrite);
            Project_Cfg.Add("PerformanceMeasurementReport_ExecuteChart=$=" + ViewModelLocator.ReportSettingVM.ReportSettingModel.PerformanceMeasurementReport_ExecuteChart);


            for (int i = 0; i < ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableList.Count(); i++)
            {
                Project_Cfg.Add("RunnableList=$=" + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableList[i].RunnableNameGrid + "$$" + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableList[i].RunnableCycleGrid + "$$" + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableList[i].RunnableCoreGrid + "$$" + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableList[i].RunnableHeader);
            }
            for (int i = 0; i < ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableStubList.Count; i++)
            {
                Project_Cfg.Add("StubList=$=" + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableStubList[i].RunnableSTUBFunctionGrid + "$$" + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableStubList[i].RunnableSTUBDelayGrid + "$$" + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RunnableStubList[i].RunnableSTUBReturnGrid);
            }
            for (int i = 0; i < ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RegisterList.Count(); i++)
            {
                Project_Cfg.Add("RegisterList=$=" + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RegisterList[i].RegisterName + "$$" + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.RegisterList[i].RegisterValue);
            }

            foreach (string key in ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.CopyDictionary.Keys)
            {
                Project_Cfg.Add("CopyPath=$=" + key + "$$" + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.CopyDictionary[key]);
            }
            foreach (IncludePathModel model in ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.IncludePathList)
            {
                Project_Cfg.Add("IncludePathList=$=" + model.AbsolutePath + "$$" + model.RelativePath);
            }
            for (int i = 0; i < ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.InitFunctionList.Count(); i++)
            {
                Project_Cfg.Add("InitFunctionList=$=" + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.InitFunctionList[i]);
            }
            for (int i = 0; i < ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.LibraryPathList.Count(); i++)
            {
                Project_Cfg.Add("LibraryList=$=" + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.LibraryPathList[i]);
            }

            /*            Project_Cfg.Add("MemoryLocationText=$=" + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SelectTextLoadMemory + "$$" + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SelectTextRunMemory);
                        Project_Cfg.Add("MemoryLocationBss=$=" + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SelectBssRunMemory);
                        Project_Cfg.Add("MemoryLocationData=$=" + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SelectDataLoadMemory + "$$" + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SelectDataRunMemory);
                        Project_Cfg.Add("MemoryLocationZbss=$=" + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SelectZbssRunMemory);
                        Project_Cfg.Add("MemoryLocationZdata=$=" + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SelectZdataLoadMemory + "$$" + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SelectZdataRunMemory);*/

                FileManager.FileSave(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\" + "T15_Env_Config\\ABS18.csa", ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.MemoryLocationTextABS18.Text);
                FileManager.FileSave(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\" + "T15_Env_Config\\Linear.csa", ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.MemoryLocationTextLinear.Text);

            FileManager.FileSave_List(filePath: ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\" + "T15_Env_Config\\T15_ProjectCfg.csa", lines: Project_Cfg);

            ViewModelLocator.MainVM.showTrackBarMessage("Save the Project");

            switch (ViewModelLocator.MainVM.MainModel.BeforeSaveMode)
            {
                case Common.Common.EXIT: // 종료
                    System.Diagnostics.Process.GetCurrentProcess().Kill();
                    break;
                case Common.Common.WORKSPACE_CHANGE:
                    ViewModelLocator.WorkSpaceVM.ChangeWorkSpace();
                    break;
                case Common.Common.SAVE_MODE:
                    break;
            }
        }
        public void add_newProjectFolder(string Proj_name_)
        {
            DirectoryInfo di = new DirectoryInfo(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + Proj_name_);
            if (di.Exists == false)
            {
                di.Create();

                di = new DirectoryInfo(path: ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + Proj_name_ + "\\" + "Gen");
                di.Create();
                di = new DirectoryInfo(path: ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + Proj_name_ + "\\" + "T15_Env_Config");
                di.Create();
                di = new DirectoryInfo(path: ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + Proj_name_ + "\\" + "Target_SW");
                di.Create();
                di = new DirectoryInfo(path: ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + Proj_name_ + "\\" + "Target_SW" + "\\" + "Debug");
                di.Create();
                di = new DirectoryInfo(path: ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + Proj_name_ + "\\" + "Temp");
                di.Create();
                di = new DirectoryInfo(path: ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + Proj_name_ + "\\" + "Temp" + "\\TestCase");
                di.Create();
                di = new DirectoryInfo(path: ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + Proj_name_ + "\\" + "TestCase");
                di.Create();

            }
            else
            {
                MessageBox.Show("Project name already exists");
                return;
            }


            //Add project information created in workspace_projectlist.xml


            string savePath = ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\workspace_projectlist.xml";
            XmlDocument XmlDoc = new XmlDocument();
            XmlDoc.Load(savePath);

            XmlNode firstnode = XmlDoc.DocumentElement;
            XmlElement root = XmlDoc.CreateElement("Project");
            root.AppendChild(createnode(XmlDoc, "Name", Proj_name_));
            root.AppendChild(createnode(XmlDoc, "Path", "$(workspace_loc)" + @"\" + Proj_name_));

            firstnode.AppendChild(root);
            XmlDoc.Save(savePath);
        }
        protected XmlNode createnode(XmlDocument xmlDoc, string name, string innerXml)
        {
            XmlNode node = xmlDoc.CreateElement(string.Empty, name, string.Empty);
            node.InnerXml = innerXml;

            return node;
        }
        public void DeleteProject(string s, bool deleteList)
        {
            string Project_Name = s;

            if (deleteList)
            {
                ViewModelLocator.MainVM.MainModel.DialogContent = new ProgressBarDialogView();
                ViewModelLocator.MainVM.MainModel.isDialogOpen = true;
                BackgroundWorker DeleteProjectWorker = new BackgroundWorker();

                DeleteProjectWorker.DoWork += (obj, e) => DeleteProjectWorker_DoWork(Project_Name);
                DeleteProjectWorker.RunWorkerCompleted += DeleteProjectWorker_RunWorkerCompleted;
                DeleteProjectWorker.RunWorkerAsync();

            }

            for (int i = 0; i < ProjectExplorerModel.ProjectExplorerModelList.Count; i++)
            {
                if (ProjectExplorerModel.ProjectExplorerModelList[i].ItemName.Equals(Project_Name))
                    ProjectExplorerModel.ProjectExplorerModelList.RemoveAt(i);
            }

            string savePath = ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\workspace_projectlist.xml";


            XmlDocument XmlDoc = new XmlDocument();
            XmlDoc.Load(savePath);
            XmlNode nodeToDelete = XmlDoc.SelectSingleNode("/Projects/Project[Name='" + Project_Name + "']");

            if (nodeToDelete != null)
                nodeToDelete.ParentNode.RemoveChild(nodeToDelete);
            XmlDoc.Save(savePath);
        }

        private void DeleteProjectWorker_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
        {
            ViewModelLocator.MainVM.MainModel.isDialogOpen = false;
            LoadWorkSpace(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath);
        }

        private void DeleteProjectWorker_DoWork(string p)
        {
            DirectoryInfo di = new DirectoryInfo(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + p);
            CommonUtil.ClearAttributes(di.FullName);
            di.Delete(true);
        }
    }
}
