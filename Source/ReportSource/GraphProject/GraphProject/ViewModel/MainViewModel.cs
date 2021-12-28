using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using GraphProject.Dialog;
using GraphProject.Etc;
using GraphProject.Models;
using GraphProject.Views;
using LiveCharts;
using LiveCharts.Wpf;
using Microsoft.WindowsAPICodePack.Dialogs;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Threading;
using System.Windows;
using System.Windows.Media;
using System.Windows.Threading;
using System.Xml;
using static GraphProject.Models.CoverageModel;

namespace GraphProject.ViewModel
{
    /// <summary>
    /// This class contains properties that the main View can data bind to.
    /// <para>
    /// Use the <strong>mvvminpc</strong> snippet to add bindable properties to this ViewModel.
    /// </para>
    /// <para>
    /// You can also use Blend to data bind with the tool's support.
    /// </para>
    /// <para>
    /// See http://www.galasoft.ch/mvvm
    /// </para>
    /// </summary>
    public class MainViewModel : ViewModelBase
    {

        private IronPython.Runtime.PythonDictionary Summary_Data_Tmp;
        private IronPython.Runtime.PythonDictionary Test_Result_Data_Tmp;
        private IronPython.Runtime.PythonDictionary Coverage_Data_Tmp;
        private IronPython.Runtime.PythonDictionary Total_Timing_Data_Tmp;
        private IronPython.Runtime.PythonDictionary Merge_Timing_Data_Tmp;
        private IronPython.Runtime.PythonDictionary Report_Option_Data_Tmp;
        private IronPython.Runtime.PythonDictionary Func_Cov_Data_Tmp;
        private IronPython.Runtime.PythonDictionary Call_Cov_Data_Tmp;
        private IronPython.Runtime.PythonDictionary MCDC_Cov_Data_Tmp;

        public static IronPython.Runtime.PythonDictionary Summary_Data;
        public static IronPython.Runtime.List Test_Result_Data;
        public static IronPython.Runtime.List Coverage_Data;
        
        public static IronPython.Runtime.PythonDictionary Total_Timing_Data;
        public static IronPython.Runtime.PythonDictionary Merge_Timing_Data;
        public static IronPython.Runtime.PythonDictionary Summary_Test_Data;
        public static IronPython.Runtime.PythonDictionary Func_Cov_Data;
        public static IronPython.Runtime.PythonDictionary Call_Cov_Data;
        public static IronPython.Runtime.List MCDC_Cov_Data;
        public static IronPython.Runtime.PythonDictionary Report_Option_Data;

        public static IronPython.Runtime.List TotalCoverage_Data;
        public static IronPython.Runtime.PythonDictionary TotalFunc_Cov_Data;
        public static IronPython.Runtime.PythonDictionary TotalCall_Cov_Data;
        public static IronPython.Runtime.List TotalMCDCCoverage_Data;

        public static bool is_ok = false;
        public static bool memory_flags = false;
        public static bool timing_flags = false;
        public static bool cov_flags = false;

        public static string Install_path;
        public static string curr_Workspace;
        public static string curr_Project;
        public static string curr_Folder;
        public static string curr_scenario;
        public static string curr_testcase;


        private string report_summary = @"Debug\dic\report_summary\report_summary.txt";
        private string test_result = @"Debug\dic\test_result\test_result.txt";
        private string coverage_result = @"Debug\dic\coverage\cov\cov_merge.txt";
        private string total_timing_result = @"\Debug\dic\timing\dic_trace_time_data.txt";
        private string timing_result = @"\Debug\dic\timing\dic_trace_timing_merged_file.txt";
        private string summary = @"Debug\dic\project_info\R_test_dictionary.txt";
        private string call_coverage = @"Debug\dic\callccov\dic_call_cov_result.txt";
        private string func_coverage = @"Debug\dic\funccov\dic_func_cov_result.txt";
        private string mcdc_coverage = @"Debug\dic\mcdc_cov\cov\cov_merge.txt";

        Dictionary<string, ObservableCollection<string>> proj_build;
        Dictionary<string, ObservableCollection<string>> build_testcase;

        private bool _IsWorkerProgressDialogOpen;

        public bool IsWorkerProgressDialogOpen
        {
            get { return this._IsWorkerProgressDialogOpen; }

            set
            {
                this._IsWorkerProgressDialogOpen = value;
                this.RaisePropertyChanged("IsWorkerProgressDialogOpen");
            }
        }
        private bool _IsControlEnable = true;

        public bool IsControlEnable
        {
            get { return this._IsControlEnable; }

            set
            {
                this._IsControlEnable = value;
                this.RaisePropertyChanged("IsControlEnable");
            }
        }
        private string _currentScenario;

        public string CurrentScenario
        {
            get { return this._currentScenario; }

            set
            {
                this._currentScenario = value;
                curr_scenario = value;
                this.RaisePropertyChanged("CurrentScenario");

                IsWorkerProgressDialogOpen = true;
                IsControlEnable = false;

                Data_Update();
            }
        }
        private string _currentTestCaseFolder;

        public string CurrentTestCaseFolder
        {
            get { return this._currentTestCaseFolder; }

            set
            {
                this._currentTestCaseFolder = value;
                curr_testcase = value;
                this.RaisePropertyChanged("CurrentTestCaseFolder");
            }
        }

        private string _currentFolder;

        public string CurrentFolder
        {
            get { return this._currentFolder; }

            set
            {
                this._currentFolder = value;
                curr_Folder = value;
                this.RaisePropertyChanged("CurrentFolder");
            }
        }

        private string _currentProject;

        public string CurrentProject
        {
            get { return this._currentProject; }

            set
            {
                this._currentProject = value;
                curr_Project = value;
                this.RaisePropertyChanged("CurrentProject");
            }
        }

        private ObservableCollection<string> _projectList;

        public ObservableCollection<string> ProjectList
        {
            get { return this._projectList; }

            set
            {
                this._projectList = value;
                this.RaisePropertyChanged("ProjectList");
            }
        }

        private ObservableCollection<string> _testReportList;

        public ObservableCollection<string> TestReportList
        {
            get { return this._testReportList; }

            set
            {
                this._testReportList = value;
                this.RaisePropertyChanged("TestReportList");
            }
        }

        private ObservableCollection<string> _scenarioList;

        public ObservableCollection<string> ScenarioList
        {
            get { return this._scenarioList; }

            set
            {
                this._scenarioList = value;
                this.RaisePropertyChanged("ScenarioList");
            }
        }
        private ObservableCollection<string> _TestCaseFolderList;

        public ObservableCollection<string> TestCaseFolderList
        {
            get { return this._TestCaseFolderList; }

            set
            {
                this._TestCaseFolderList = value;
                this.RaisePropertyChanged("TestCaseFolderList");
            }
        }
        private object _summaryContainerView;

        public object SummaryContainerView
        {
            get { return this._summaryContainerView; }

            set
            {
                this._summaryContainerView = value;
                this.RaisePropertyChanged("SummaryContainerView");
            }
        }

        private object _containerView;

        public object ContainerView
        {
            get { return this._containerView; }

            set
            {
                this._containerView = value;
                this.RaisePropertyChanged("ContainerView");
            }
        }

        private object _containerView2;

        public object ContainerView2
        {
            get { return this._containerView2; }

            set
            {
                this._containerView2 = value;
                this.RaisePropertyChanged("ContainerView2");
            }
        }

        private object _containerView3;

        public object ContainerView3
        {
            get { return this._containerView3; }

            set
            {
                this._containerView3 = value;
                this.RaisePropertyChanged("ContainerView3");
            }
        }

        private object _coverageContainerView;

        public object CoverageContainerView
        {
            get { return this._coverageContainerView; }

            set
            {
                this._coverageContainerView = value;
                this.RaisePropertyChanged("CoverageContainerView");
            }
        }
        private object _totalcoverageContainerView;

        public object TotalCoverageContainerView
        {
            get { return this._totalcoverageContainerView; }

            set
            {
                this._totalcoverageContainerView = value;
                this.RaisePropertyChanged("TotalCoverageContainerView");
            }
        }
        private object _totalmcdccoverageContainerView;

        public object TotalMCDCCoverageContainerView
        {
            get { return this._totalmcdccoverageContainerView; }

            set
            {
                this._totalmcdccoverageContainerView = value;
                this.RaisePropertyChanged("TotalMCDCCoverageContainerView");
            }
        }

        private string _workspaceText;

        public string WorkspaceText
        {
            get { return _workspaceText; }
            set
            {
                this._workspaceText = value;
                curr_Workspace = value;
                this.RaisePropertyChanged("WorkspaceText");
            }
        }
        private string _projectnameText;

        public string ProjectNameText
        {
            get { return _projectnameText; }
            set
            {
                this._projectnameText = value;
                curr_Project = value;
                this.RaisePropertyChanged("ProjectNameText");
            }
        }
        private string _testcasefolderText;

        public string TestCaseFolderText
        {
            get { return _testcasefolderText; }
            set
            {
                this._testcasefolderText = value;
                curr_testcase = value;
                this.RaisePropertyChanged("TestCaseFolderText");
            }
        }
        private int _SavePdfProgress;

        public int SavePdfProgress
        {
            get { return this._SavePdfProgress; }

            set
            {
                this._SavePdfProgress = value;
                this.RaisePropertyChanged("SavePdfProgress");
            }
        }
        private bool _isDialogOpen;

        public bool isDialogOpen
        {
            get { return this._isDialogOpen; }

            set
            {
                this._isDialogOpen = value;
                this.RaisePropertyChanged("isDialogOpen");
            }
        }
        private object _DialogViewContent;

        public object DialogViewContent
        {
            get { return this._DialogViewContent; }

            set
            {
                this._DialogViewContent = value;
                this.RaisePropertyChanged("DialogViewContent");
            }
        }



        public RelayCommand WorkspaceSearchCommand { get; set; }
        public RelayCommand WorkspaceLoadCommand { get; set; }

        public RelayCommand SelectionChangedCommand { get; set; }
        public RelayCommand FolderSelectionChangedCommand { get; set; }
        public RelayCommand ProjectSelectionChangedCommand { get; set; }
        public RelayCommand BuildFolderSelectionChangedCommand { get; set; }

        public MainViewModel()
        {
            SelectionChangedCommand = new RelayCommand(ScenarioSelectionChanged);
            WorkspaceSearchCommand = new RelayCommand(WorkspaceSearchFunction);
            WorkspaceLoadCommand = new RelayCommand(WorkspaceLoadFunction);
            ProjectSelectionChangedCommand = new RelayCommand(ProjectSelectionChangedFunction);
            FolderSelectionChangedCommand = new RelayCommand(FolderSelectionChangedFunction);
            BuildFolderSelectionChangedCommand = new RelayCommand(BuildFolderSelectionChanged);

            ScenarioList = new ObservableCollection<string>();
            TestCaseFolderList = new ObservableCollection<string>();
            TestReportList = new ObservableCollection<string>();
            ProjectList = new ObservableCollection<string>();
            proj_build = new Dictionary<string, ObservableCollection<string>>();
            build_testcase = new Dictionary<string, ObservableCollection<string>>();

            /*            WorkspaceText = @"C:\Users\CSA_DEV\Documents\Working\Prost_v2.0\Workspace";
                        CurrentProject = "MANDO_USM";
                        CurrentFolder = "20201104_USM_PROJECT";
                        CurrentTestCaseFolder = "USM-TestSpec_Full";
                        Install_path = @"C:\Users\CSA_DEV\Documents\Working\Prost_v2.0\Prost v2.0";*/
            Install_path = @"C:\Users\CSA_DEV\Documents\Working\Prost_v2.0\Prost v2.0";

            string[] strArg = Environment.GetCommandLineArgs();
            if (strArg.Length > 1)
            {

                if (Directory.Exists(strArg[1]))
                {
                    WorkspaceText = strArg[1];
                    CurrentProject = strArg[2];
                    CurrentFolder = strArg[3];
                    CurrentTestCaseFolder = strArg[4];
                    Install_path = strArg[5];

                    CommonUtil.LogMessageList.Add("strArg[1] :: " + strArg[1]);
                    CommonUtil.LogMessageList.Add("strArg[2] :: " + strArg[2]);
                    CommonUtil.LogMessageList.Add("strArg[3] :: " + strArg[3]);
                    CommonUtil.LogMessageList.Add("strArg[4] :: " + strArg[4]);

                    //MessageBox.Show("Workspace 정보를 얻기 위해 Load 버튼을 클릭해주십시오.\n" +
                    //  "paramter : " + WorkspaceText + "\n" +
                    // "paramter : " + Install_path + "\n");
                }
            }

            try
            {
                data_initialize();

                if (WorkspaceText != null && WorkspaceText != "")
                {
                    init_project_check();
                   
                }
            }
            catch (Exception ex)
            {
                CommonUtil.LogMessageList.Add("리포트 데이터 로드를 실패하였습니다. 리포트 파일 경로 또는 존재여부를 확인해주십시오. \n" + ex.Message);
                return;
            }
        }
        private void ScenarioSelectionChanged()
        {


        }
        private void Data_Update()
        {

            if (ScenarioList.Count == 0)
            {
                data_initialize();
                //MessageBox.Show("시나리오 정보 로드를 실패하였습니다. 리포트 파일이 정상적으로 작성되었는지 확인해주십시오.");
                IsWorkerProgressDialogOpen = false;
                return;
            }

            if (CurrentScenario == null || CurrentScenario == "")
            {
                MessageBox.Show("시나리오 정보 로드를 실패하였습니다. 리포트 파일이 정상적으로 작성되었는지 확인해주십시오.");
                IsWorkerProgressDialogOpen = false;
                data_initialize();
                return;
            }

            try
            {
                Summary_Data = (IronPython.Runtime.PythonDictionary)Summary_Data_Tmp[CurrentScenario];
                Test_Result_Data = (IronPython.Runtime.List)Test_Result_Data_Tmp[CurrentScenario];
                if (timing_flags)
                {
                    Total_Timing_Data = (IronPython.Runtime.PythonDictionary)Total_Timing_Data_Tmp[CurrentScenario];
                    Merge_Timing_Data = (IronPython.Runtime.PythonDictionary)Merge_Timing_Data_Tmp[CurrentScenario];

                    this.ContainerView3 = new TimingChartContainerViewModel();
                }

                if (cov_flags)
                {
                    Coverage_Data = (IronPython.Runtime.List)Coverage_Data_Tmp[CurrentScenario];
                    Func_Cov_Data = (IronPython.Runtime.PythonDictionary)Func_Cov_Data_Tmp[CurrentScenario];
                    if (!Call_Cov_Data_Tmp.ContainsKey(CurrentScenario) || ((IronPython.Runtime.PythonDictionary)Call_Cov_Data_Tmp[CurrentScenario]).Count == 0)
                    {

                    }
                    else
                        Call_Cov_Data = (IronPython.Runtime.PythonDictionary)Call_Cov_Data_Tmp[CurrentScenario];

                    TotalCoverage_Data = (IronPython.Runtime.List)Coverage_Data_Tmp["Total"];
                    MCDC_Cov_Data = (IronPython.Runtime.List)MCDC_Cov_Data_Tmp[CurrentScenario];

                    TotalMCDCCoverage_Data = (IronPython.Runtime.List)MCDC_Cov_Data_Tmp["Total"];

                }

            }
            catch (Exception ex)
            {
                CommonUtil.LogMessageList.Add("리포트 데이터의 일부를 로드하지 못하였습니다. " + CommonUtil.GetExceptionLineNumber(ex));
                return;
            }
            finally {
                this.SummaryContainerView = new TestSummaryContainerViewModel();
                this.ContainerView = new MemoryUsageContainerViewModel();
                this.ContainerView2 = new TestFailListContainerViewModel();
                if(cov_flags)
                {
                    this.CoverageContainerView = new TestCoverageContainerViewModel();
                    this.TotalCoverageContainerView = new TotalTestCoverageContainerViewModel();
                    this.TotalMCDCCoverageContainerView = new TotalMCDCCoverageContainerViewModel();
                }
                    


                IsWorkerProgressDialogOpen = false;
                IsControlEnable = true;
            }

        }

        private void data_initialize()
        {
            this.SummaryContainerView = new NoDataView();
            this.ContainerView = new NoDataView();
            this.ContainerView2 = new NoDataView();
            this.CoverageContainerView = new NoDataView();
            this.ContainerView3 = new NoDataView();
            this.TotalCoverageContainerView = new NoDataView();
            this.TotalMCDCCoverageContainerView = new NoDataView();

            Summary_Data = null;
            Test_Result_Data = null;
            Coverage_Data = null;
            Total_Timing_Data = null;
            Merge_Timing_Data = null;

            Func_Cov_Data = null;
            Call_Cov_Data = null;

            Summary_Data_Tmp = null;
            Test_Result_Data_Tmp = null;
            Coverage_Data_Tmp = null;
            Total_Timing_Data_Tmp = null;
            Merge_Timing_Data_Tmp = null;

            Func_Cov_Data_Tmp = null;
            Call_Cov_Data_Tmp = null;
            MCDC_Cov_Data_Tmp = null;
        }

        private void WorkspaceLoadFunction()
        {
            try
            {
                if (WorkspaceText == null || !Directory.Exists(WorkspaceText))
                {
                    MessageBox.Show("Workspapce 경로를 입력해주십시오.");
                    return;
                }

                if (ProjectList != null && ProjectList.Count != 0)
                    ProjectList.Clear();
                if (TestReportList != null && TestReportList.Count != 0)
                    TestReportList.Clear();
                if (ScenarioList != null && ScenarioList.Count != 0)
                    ScenarioList.Clear();
                if (TestCaseFolderList != null && TestCaseFolderList.Count != 0)
                    TestCaseFolderList.Clear();

                //IsWorkerProgressDialogOpen = true;
                //IsControlEnable = false;
                project_check();
            }
            catch(Exception ex)
            {
                CommonUtil.LogMessageList.Add(ex.Message);
            }
        }

        private void ProjectSelectionChangedFunction()
        {
            if (ProjectList.Count == 0)
                return;

            TestReportList = proj_build[CurrentProject];
        }
        private void BuildFolderSelectionChanged()
        {
            try
            {
                if (TestReportList.Count == 0)
                    return;

                TestCaseFolderList.Clear();
                ScenarioList.Clear();
                System.IO.DirectoryInfo di = new System.IO.DirectoryInfo(WorkspaceText + "\\" + CurrentProject + "\\Gen\\" + CurrentFolder);
                foreach (System.IO.DirectoryInfo d in di.GetDirectories())
                {
                    if (!d.Name.Equals("Build") && !d.Name.Equals("Log"))
                    {
                        TestCaseFolderList.Add(d.Name);
                    }
                }

                if (TestCaseFolderList.Count > 0)
                {
                    //CurrentTestCaseFolder = TestCaseFolderList[0];
                }

                /*if (TestCaseFolderList.Count > 0)
                {
                    CurrentTestCaseFolder = TestCaseFolderList[0];
                }*/
            }
            catch(Exception ex)
            {
                CommonUtil.LogMessageList.Add(ex.Message + CommonUtil.GetExceptionLineNumber(ex));
            }
        }

        private void FolderSelectionChangedFunction()
        {
            if (CurrentFolder == null)
                return;

            if (CurrentTestCaseFolder == null)
            {
                /*MessageBox.Show("테스트 케이스 정보 로드를 실패하였습니다. 리포트 파일이 정상적으로 작성되었는지 확인해주십시오.");
                data_initialize();*/
                return;
            }

            try
            {
                string file_path = WorkspaceText + "\\" + CurrentProject + "\\Gen\\" + CurrentFolder + "\\" + CurrentTestCaseFolder;

                is_ok = true;
                memory_flags = true;
                timing_flags = true;
                cov_flags = true;

                if (!File.Exists(file_path + "\\" + report_summary))
                    memory_flags = false;
                if (!File.Exists(file_path + "\\" + test_result))
                    is_ok = false;
                if (!File.Exists(file_path + "\\" + coverage_result))
                    cov_flags = false;
                if (!File.Exists(file_path + "\\" + total_timing_result))
                    timing_flags = false;
                if (!File.Exists(file_path + "\\" + timing_result))
                    timing_flags = false;
                if (!File.Exists(file_path + "\\" + summary))
                    is_ok = false;
                if (!File.Exists(file_path + "\\" + call_coverage))
                    cov_flags = false;
                if (!File.Exists(file_path + "\\" + func_coverage))
                    cov_flags = false;
                /*if (!File.Exists(file_path + "\\" + mcdc_coverage))
                    cov_flags = false;*/


                if (memory_flags && is_ok)
                    dic_load(file_path);
                else
                {
                    data_initialize();
                    //MessageBox.Show("시나리오 정보 로드를 실패하였습니다. 리포트 파일이 정상적으로 작성되었는지 확인해주십시오.");
                }

                //Data_Update();
            }
            catch(Exception ex)
            {
                CommonUtil.LogMessageList.Add(ex.Message + CommonUtil.GetExceptionLineNumber(ex));
            }

        }

        private void WorkspaceSearchFunction()
        {
            CommonOpenFileDialog folderDialog = new CommonOpenFileDialog()
            {
                InitialDirectory = "",
                IsFolderPicker = true
            };

            if (folderDialog.ShowDialog() == CommonFileDialogResult.Ok)
            {
                WorkspaceText = folderDialog.FileName;
            }
        }

        private void dic_load(string file_path)
        {
            data_initialize();

            

                var engine = IronPython.Hosting.Python.CreateEngine();
                var scope = engine.CreateScope();

                ICollection<string> searchPaths = engine.GetSearchPaths();

                //searchPaths.Add(@"C:\Users\SangJun.Choi\MDS\PROST\Source\Prost_v1.0 Git\Prost v1.0\src\lib\IronPython 2.7\Lib");
                //searchPaths.Add(@"C:\Users\SangJun.Choi\MDS\PROST\Source\Prost_v1.0 Git\Prost v1.0\src\lib\common\Pickle");

                searchPaths.Add(@"..\src\lib\IronPython 2.7\Lib");
                searchPaths.Add(@"..\src\lib\common\Pickle");
                engine.SetSearchPaths(searchPaths);

                //var source = engine.CreateScriptSourceFromFile(@"C:\Users\SangJun.Choi\MDS\PROST\Source\Prost_v1.0 Git\Prost v1.0\src\lib\common\Pickle\test_pickle.py");
                var source = engine.CreateScriptSourceFromFile(@"..\src\lib\common\Pickle\test_pickle.py");
                source.Execute(scope);

            try
            {


                if (is_ok)
                {
                    var Origin_TC_Load = scope.GetVariable<Func<string, object>>("Origin_TC_Load");
                    Summary_Data_Tmp = (IronPython.Runtime.PythonDictionary)Origin_TC_Load(file_path + "\\" + report_summary);

                    
                    /*                    Origin_TC_Load = scope.GetVariable<Func<string, object>>("Origin_TC_Load");
                                        Report_Option_Data_Tmp = (IronPython.Runtime.PythonDictionary)Origin_TC_Load(WorkspaceText + "\\" + CurrentProject + "\\Temp\\C_PROJECT_INFO_DATA_dictionary.txt");
                                        Report_Option_Data = (IronPython.Runtime.PythonDictionary)Report_Option_Data_Tmp["Report"];
                    */


                    Origin_TC_Load = scope.GetVariable<Func<string, object>>("Origin_TC_Load");
                    Summary_Test_Data = (IronPython.Runtime.PythonDictionary)Origin_TC_Load(file_path + "\\" + summary);

                    Origin_TC_Load = scope.GetVariable<Func<string, object>>("Origin_TC_Load");
                    Test_Result_Data_Tmp = (IronPython.Runtime.PythonDictionary)Origin_TC_Load(file_path + "\\" + test_result);

                    if (timing_flags)
                    {
                        Origin_TC_Load = scope.GetVariable<Func<string, object>>("Origin_TC_Load");
                        Total_Timing_Data_Tmp = (IronPython.Runtime.PythonDictionary)Origin_TC_Load(file_path + "\\" + total_timing_result);

                        Origin_TC_Load = scope.GetVariable<Func<string, object>>("Origin_TC_Load");
                        Merge_Timing_Data_Tmp = (IronPython.Runtime.PythonDictionary)Origin_TC_Load(file_path + "\\" + timing_result);
                    }

                    if (cov_flags)
                    {
                        Origin_TC_Load = scope.GetVariable<Func<string, object>>("Origin_TC_Load");
                        Coverage_Data_Tmp = (IronPython.Runtime.PythonDictionary)Origin_TC_Load(file_path + "\\" + coverage_result);

                        Origin_TC_Load = scope.GetVariable<Func<string, object>>("Origin_TC_Load");
                        Func_Cov_Data_Tmp = (IronPython.Runtime.PythonDictionary)Origin_TC_Load(file_path + "\\" + func_coverage);

                        Origin_TC_Load = scope.GetVariable<Func<string, object>>("Origin_TC_Load");
                        Call_Cov_Data_Tmp = (IronPython.Runtime.PythonDictionary)Origin_TC_Load(file_path + "\\" + call_coverage);

                        Origin_TC_Load = scope.GetVariable<Func<string, object>>("Origin_TC_Load");
                        if (File.Exists(file_path + "\\" + mcdc_coverage))
                            MCDC_Cov_Data_Tmp = (IronPython.Runtime.PythonDictionary)Origin_TC_Load(file_path + "\\" + mcdc_coverage);
                    }

                    ScenarioList.Clear();

                    var list = Summary_Data_Tmp.Keys.ToList();
                    list.Sort();

                    foreach (var key in list)
                        ScenarioList.Add(key.ToString());



                    if (ScenarioList.Count != 0)
                    {
                        CurrentScenario = ScenarioList[0];
                    }

                }
            }
            catch (Exception ex)
            {
                CommonUtil.LogMessageList.Add(ex.Message + CommonUtil.GetExceptionLineNumber(ex));
                throw;
            }
        }
        
        private void init_project_check()
        {
            if (WorkspaceText == "") return;

            System.IO.DirectoryInfo di = new System.IO.DirectoryInfo(WorkspaceText);
            foreach (System.IO.DirectoryInfo d in di.GetDirectories())
            {
                proj_build[d.Name] = new ObservableCollection<string>();

                if (!Directory.Exists(d.FullName + @"\Gen"))
                    continue;

                System.IO.DirectoryInfo di_di = new System.IO.DirectoryInfo(d.FullName + @"\Gen");
                foreach (System.IO.DirectoryInfo d_d in di_di.GetDirectories())
                {
                    proj_build[d.Name].Add(d_d.Name);
                }

                ProjectList.Add(d.Name);
            }

            TestReportList.Clear();
            System.IO.DirectoryInfo BuildFolderDI = new System.IO.DirectoryInfo(WorkspaceText + "\\" + CurrentProject + "\\Gen");
            foreach (System.IO.DirectoryInfo d in BuildFolderDI.GetDirectories())
            {
                TestReportList.Add(d.Name);
            }

            TestCaseFolderList.Clear();
            System.IO.DirectoryInfo TestCaseFolderDI = new System.IO.DirectoryInfo(WorkspaceText + "\\" + CurrentProject + "\\Gen\\" + CurrentFolder);
            foreach (System.IO.DirectoryInfo d in TestCaseFolderDI.GetDirectories())
            {
                if (!d.Name.Equals("Build") && !d.Name.Equals("Log"))
                {
                    TestCaseFolderList.Add(d.Name);
                }
            }



            FolderSelectionChangedFunction();
            //Data_Update();

            //IsWorkerProgressDialogOpen = true;
            //IsControlEnable = false;

            /*            if (ScenarioList.Count != 0)
                        {
                            CurrentScenario = ScenarioList[ScenarioList.Count - 1];

                            IsWorkerProgressDialogOpen = true;
                            IsControlEnable = false;
                            Data_Update();
                        }*/
        }
        private void project_check()
        {

            if (WorkspaceText == "") return;

            System.IO.DirectoryInfo di = new System.IO.DirectoryInfo(WorkspaceText);
            foreach (System.IO.DirectoryInfo d in di.GetDirectories())
            {
                proj_build[d.Name] = new ObservableCollection<string>();

                if (!Directory.Exists(d.FullName + @"\Gen"))
                    continue;

                System.IO.DirectoryInfo di_di = new System.IO.DirectoryInfo(d.FullName + @"\Gen");
                foreach (System.IO.DirectoryInfo d_d in di_di.GetDirectories())
                {
                    proj_build[d.Name].Add(d_d.Name);
                }

                ProjectList.Add(d.Name);
            }


            foreach (string project_name in ProjectList)
            {
                CurrentProject = project_name;
                ProjectSelectionChangedFunction();

                foreach (string report_folder in TestReportList)
                {
                    CurrentFolder = report_folder;
                    //FolderSelectionChangedFunction();

                    foreach (string testcase_folder in TestCaseFolderList)
                    {
                        CurrentTestCaseFolder = testcase_folder;
                        //FolderSelectionChangedFunction();

                        if (ScenarioList.Count != 0)
                        {
                            CurrentScenario = ScenarioList[0];
                            //Data_Update();
                            is_ok = true;
                        }

                        if (is_ok)
                            break;
                    }
                }

                if (is_ok)
                    break;
            }
        }
    }
}