using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using LiveCharts;
using LiveCharts.Wpf;
using ProstMain.Model;
using ProstMain.Popup;
using ProstMain.Util;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Threading;
using static ProstMain.Util.CommonUtil;
using Excel = Microsoft.Office.Interop.Excel;

namespace ProstMain.ViewModel
{
    public class BuildFolderClass
    {
        public string BuildFolderName;
        public  List<TestCaseFolderClass> TestCaseFolderList;
        public BuildFolderClass()
        {
            TestCaseFolderList = new List<TestCaseFolderClass>();
        }
    }
    public class TestCaseFolderClass
    {
        public  string TestCaseFolderName;
        public  List<string> ScenarioFolderList;
        public TestCaseFolderClass()
        {
            ScenarioFolderList = new List<string>();
        }
    }
    public class HistoryViewModel : ViewModelBase
    {
        public RelayCommand<object> HistoryDataClickCommand { get; set; }
        public RelayCommand<object> HistorySelectedChangeCommand { get; set; }
        public RelayCommand CloseWindowCommand { get; set; }
        public RelayCommand PrevHistoryCommand { get; set; }
        public RelayCommand NextHistoryCommand { get; set; }

        private ChartValues<double> _CoverageSeries { get; set; }
        public ChartValues<double> CoverageSeries
        {
            get { return _CoverageSeries; }
            set
            {
                if (_CoverageSeries != value)
                {
                    _CoverageSeries = value;
                    RaisePropertyChanged("CoverageSeries");
                }
            }
        }
        private ChartValues<double> _MemoryUseage { get; set; }
        public ChartValues<double> MemoryUseage
        {
            get { return _MemoryUseage; }
            set
            {
                if (_MemoryUseage != value)
                {
                    _MemoryUseage = value;
                    RaisePropertyChanged("MemoryUseage");
                }
            }
        }
        private ChartValues<int> _Runtime { get; set; }
        public ChartValues<int> Runtime
        {
            get { return _Runtime; }
            set
            {
                if (_Runtime != value)
                {
                    _Runtime = value;
                    RaisePropertyChanged("Runtime");
                }
            }
        }

        private string _isShowCoverage { get; set; }
        public string isShowCoverage
        {
            get { return _isShowCoverage; }
            set
            {
                if (_isShowCoverage != value)
                {
                    _isShowCoverage = value;
                    RaisePropertyChanged("isShowCoverage");
                }
            }
        }
        private string _isShowMemoryUseage { get; set; }
        public string isShowMemoryUseage
        {
            get { return _isShowMemoryUseage; }
            set
            {
                if (_isShowMemoryUseage != value)
                {
                    _isShowMemoryUseage = value;
                    RaisePropertyChanged("isShowMemoryUseage");
                }
            }
        }
        private string _isShowRunTime { get; set; }
        public string isShowRunTime
        {
            get { return _isShowRunTime; }
            set
            {
                if (_isShowRunTime != value)
                {
                    _isShowRunTime = value;
                    RaisePropertyChanged("isShowRunTime");
                }
            }
        }
        private int _HistoryIndex { get; set; }
        public int HistoryIndex
        {
            get { return _HistoryIndex; }
            set
            {
                if (_HistoryIndex != value)
                {
                    _HistoryIndex = value;
                    RaisePropertyChanged("HistoryIndex");
                }
            }
        }
        private string _CurrentHistoryFolderName { get; set; }
        public string CurrentHistoryFolderName
        {
            get { return _CurrentHistoryFolderName; }
            set
            {
                if (_CurrentHistoryFolderName != value)
                {
                    _CurrentHistoryFolderName = value;
                    RaisePropertyChanged("CurrentHistoryFolderName");
                }
            }
        }
        private ObservableCollection<string> _Labels { get; set; }
        public ObservableCollection<string> Labels
        {
            get { return _Labels; }
            set
            {
                if (_Labels != value)
                {
                    _Labels = value;
                    RaisePropertyChanged("Labels");
                }
            }
        }

        public Func<int, string> FormatterY { get; set; }
        public List<BuildFolderClass> BuildFolderList { get; set; }
        public List<TestCaseFolderClass> TestFolderList { get; set; }
        public List<string> TestSenarioList { get; set; }
        

        public HistoryViewModel()
        {
            CoverageSeries = new ChartValues<double>();
            MemoryUseage = new ChartValues<double>();
            Runtime = new ChartValues<int>();
            BuildFolderList = new List<BuildFolderClass>();
            TestFolderList = new List<TestCaseFolderClass>();
            TestSenarioList = new List<string>();


            Labels = new ObservableCollection<string>();

            

            FormatterY = value => value.ToString("N");
            


            HistoryDataClickCommand = new RelayCommand<object>(HistoryDataClick);
            HistorySelectedChangeCommand = new RelayCommand<object>(HistorySelectedChange);
            PrevHistoryCommand = new RelayCommand(PrevHistory);
            NextHistoryCommand = new RelayCommand(NextHistory);
            CloseWindowCommand = new RelayCommand(CloseWindow);


            isShowCoverage = Common.Common.FALSE;
            isShowMemoryUseage = Common.Common.TRUE;
            isShowRunTime = Common.Common.FALSE;

            HistoryIndex = 0;
        }

        private void HistoryDataClick(object e)
        {
            ChartPoint chartPoint = (ChartPoint)e;
            //ShowWindow(Labels[(int)chartPoint.X].ToString());
        }

        private void HistorySelectedChange(object e)
        {
            if ((int)e == 0)
            {
                isShowCoverage = Common.Common.FALSE;
                isShowMemoryUseage = Common.Common.TRUE;
                isShowRunTime = Common.Common.FALSE;

            }
            else if ((int)e == 1)
            {
                isShowCoverage = Common.Common.TRUE;
                isShowMemoryUseage = Common.Common.FALSE;
                isShowRunTime = Common.Common.FALSE;
            }
            else if((int)e == 2)
            {
                isShowCoverage = Common.Common.TRUE;
                isShowMemoryUseage = Common.Common.FALSE;
                isShowRunTime = Common.Common.FALSE;
            }
        }
        PopupHistoryView m_PopupHistoryView;
        private void ShowWindow(string title)
        {
            m_PopupHistoryView = new PopupHistoryView(title);
            m_PopupHistoryView.Width = 430;
            m_PopupHistoryView.Height = 450;
            m_PopupHistoryView.Owner = App.Current.MainWindow;
            m_PopupHistoryView.ShowDialog();

        }
        private void CloseWindow()
        {
            m_PopupHistoryView.Close();
        }

        public BackgroundWorker ParsingHistoryDataWorker;
        private object ParsingHisotryDataObject = new object();
        public void ParsingHistoryData()
        {
            if (ParsingHistoryDataWorker !=null && ParsingHistoryDataWorker.IsBusy)
            {
                ParsingHistoryDataWorker.CancelAsync();
                ParsingHistoryDataWorker = null;
            }
            lock (ParsingHisotryDataObject)
            {
                ParsingHistoryDataWorker = new BackgroundWorker();

                ParsingHistoryDataWorker.DoWork += ParsingHistoryDataWorker_DoWork;
                ParsingHistoryDataWorker.WorkerReportsProgress = true;
                ParsingHistoryDataWorker.WorkerSupportsCancellation = true;
                ParsingHistoryDataWorker.RunWorkerCompleted += ParsingHistoryDataWorker_DoWorkComplete;
                ParsingHistoryDataWorker.RunWorkerAsync();
            }
        }

        private void ParsingHistoryDataWorker_DoWork(object sender, DoWorkEventArgs e)
        {
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

            try
            {
                Thread thread = new Thread(new ThreadStart(delegate ()
                {

                    foreach (string buildPath in Directory.GetDirectories(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Gen"))
                    {
                        if (Directory.GetFiles(buildPath, "*.csv", SearchOption.AllDirectories).Length > 0)
                        {
                            int DisplayCount = 0;
                            TestFolderList.Clear();
                            foreach (string testcasePath in Directory.GetDirectories(buildPath))
                            {
                                if (Path.GetFileNameWithoutExtension(testcasePath) == "Build" || Path.GetFileNameWithoutExtension(testcasePath) == "Log")
                                    continue;

                                DisplayCount++;
                                if (DisplayCount > 5)
                                    return;

                                var Origin_TC_Load_init = scope.GetVariable<Func<string, object>>("Origin_TC_Load");

                                IronPython.Runtime.PythonDictionary ReportSummary_Data_Tmp_init = (IronPython.Runtime.PythonDictionary)Origin_TC_Load_init(testcasePath + "\\" + @"Debug\dic\report_summary\report_summary.txt");
                                //IronPython.Runtime.PythonDictionary Statement_Cov_Data_Tmp_init = (IronPython.Runtime.PythonDictionary)Origin_TC_Load_init(testcasePath + "\\" + @"\Debug\dic\coverage\cov\cov_merge.txt");

                                TestSenarioList.Clear();
                                foreach (string key in ReportSummary_Data_Tmp_init.keys())
                                {
                                    Application.Current.Dispatcher.Invoke(new Action(() =>
                                    {
                                        TestSenarioList.Add(key);
                                    }));
                                }

                                if (TestSenarioList.Count <= 0)
                                    continue;

                                TestFolderList.Add(new TestCaseFolderClass { TestCaseFolderName = testcasePath, ScenarioFolderList = TestSenarioList.ToList() });

                            }
                            if (TestFolderList.Count <= 0)
                                continue;

                            BuildFolderList.Add(new BuildFolderClass { BuildFolderName = buildPath, TestCaseFolderList = TestFolderList.ToList() });
                        }
                    }

                    /*if (BuildFolderList.Count > 0)
                        LoadHistoryData(Common.Common.INIT);*/
                }));
                thread.Start();

            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
        private void LoadHistoryData(int mode)
        {
            try
            {
                MemoryUseage.Clear();
                CoverageSeries.Clear();
                Labels.Clear();

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

                var Origin_TC_Load_init = scope.GetVariable<Func<string, object>>("Origin_TC_Load");

                switch (mode)
                {
                    case Common.Common.INIT:
                        CurrentHistoryFolderName = Path.GetFileNameWithoutExtension(BuildFolderList[0].BuildFolderName);

                        foreach (TestCaseFolderClass casefoldermodel in BuildFolderList[0].TestCaseFolderList)
                        {
                            IronPython.Runtime.PythonDictionary ReportSummary_Data_Tmp_init = (IronPython.Runtime.PythonDictionary)Origin_TC_Load_init(casefoldermodel.TestCaseFolderName + "\\" + @"Debug\dic\report_summary\report_summary.txt");
                            IronPython.Runtime.PythonDictionary Statement_Cov_Data_Tmp_init = (IronPython.Runtime.PythonDictionary)Origin_TC_Load_init(casefoldermodel.TestCaseFolderName + "\\" + @"\Debug\dic\coverage\cov\cov_merge.txt");
                            IronPython.Runtime.PythonDictionary ReportSummary_Senario_Data = ((IronPython.Runtime.PythonDictionary)ReportSummary_Data_Tmp_init[casefoldermodel.ScenarioFolderList[0]]);

                            IronPython.Runtime.List Total_Memory = (IronPython.Runtime.List)ReportSummary_Senario_Data["Memory Usage"];
                            string passRate = ReportSummary_Senario_Data["Pass Rate"].ToString();
                            string failRate = ReportSummary_Senario_Data["Fail Rate"].ToString();

                            //ViewModelLocator.ProjectSettingVM.ProjectSettingModel.LastTest_TestCoverage = "" + passRate.Split('.')[0] + "% / " + failRate.Split('.')[0] + "%";

                            foreach (IronPython.Runtime.PythonDictionary tmp in Total_Memory)
                            {
                                if (tmp["Memory"].ToString() == "Total")
                                {
                                    Application.Current.Dispatcher.Invoke(new Action(() =>
                                    {
                                        MemoryUseage.Add(Convert.ToDouble(tmp["Usage"].ToString()) * 100);
                                    }));
                                }
                            }
                            Application.Current.Dispatcher.Invoke(new Action(() =>
                            {
                                CoverageSeries.Add(CommonUtil.merge_StateCoverage((IronPython.Runtime.List)Statement_Cov_Data_Tmp_init[casefoldermodel.ScenarioFolderList[0]]));
                                Labels.Add(Path.GetFileNameWithoutExtension(casefoldermodel.TestCaseFolderName));
                            }));
                        }
                        if (Labels.Count < 5)
                        {
                            int temp_count = Labels.Count;
                            for (int i = 0; i < 5 - temp_count; i++)
                            {
                                Application.Current.Dispatcher.Invoke(new Action(() =>
                                {
                                    CoverageSeries.Add(0);
                                    MemoryUseage.Add(0);
                                    Labels.Add("");
                                }));
                            }
                        }
                        break;
                    case Common.Common.SELECT:
                        CurrentHistoryFolderName = Path.GetFileNameWithoutExtension(BuildFolderList[HistoryIndex].BuildFolderName);

                        foreach (TestCaseFolderClass casefoldermodel in BuildFolderList[HistoryIndex].TestCaseFolderList)
                        {
                            IronPython.Runtime.PythonDictionary ReportSummary_Data_Tmp_init = (IronPython.Runtime.PythonDictionary)Origin_TC_Load_init(casefoldermodel.TestCaseFolderName + "\\" + @"Debug\dic\report_summary\report_summary.txt");
                            IronPython.Runtime.PythonDictionary Statement_Cov_Data_Tmp_init = (IronPython.Runtime.PythonDictionary)Origin_TC_Load_init(casefoldermodel.TestCaseFolderName + "\\" + @"\Debug\dic\coverage\cov\cov_merge.txt");
                            IronPython.Runtime.PythonDictionary ReportSummary_Senario_Data = ((IronPython.Runtime.PythonDictionary)ReportSummary_Data_Tmp_init[casefoldermodel.ScenarioFolderList[0]]);

                            IronPython.Runtime.List Total_Memory = (IronPython.Runtime.List)ReportSummary_Senario_Data["Memory Usage"];
                            string passRate = ReportSummary_Senario_Data["Pass Rate"].ToString();
                            string failRate = ReportSummary_Senario_Data["Fail Rate"].ToString();

                            //ViewModelLocator.ProjectSettingVM.ProjectSettingModel.LastTest_TestCoverage = "" + passRate.Split('.')[0] + "% / " + failRate.Split('.')[0] + "%";

                            foreach (IronPython.Runtime.PythonDictionary tmp in Total_Memory)
                            {
                                if (tmp["Memory"].ToString() == "Total")
                                {
                                    Application.Current.Dispatcher.Invoke(new Action(() =>
                                    {
                                        MemoryUseage.Add(Convert.ToDouble(tmp["Usage"].ToString()) * 100);
                                    }));
                                }
                            }
                            Application.Current.Dispatcher.Invoke(new Action(() =>
                            {
                                CoverageSeries.Add(CommonUtil.merge_StateCoverage((IronPython.Runtime.List)Statement_Cov_Data_Tmp_init[casefoldermodel.ScenarioFolderList[0]]));
                                Labels.Add(Path.GetFileNameWithoutExtension(casefoldermodel.TestCaseFolderName));
                            }));
                        }
                        if (Labels.Count < 5)
                        {
                            int temp_count = Labels.Count;
                            for (int i = 0; i < 5 - temp_count; i++)
                            {
                                Application.Current.Dispatcher.Invoke(new Action(() =>
                                {
                                    CoverageSeries.Add(0);
                                    MemoryUseage.Add(0);
                                    Labels.Add("");
                                }));
                            }
                        }
                        break;
                }
            }
            catch(Exception ex)
            {

            }
        }

        private void ParsingHistoryDataWorker_DoWorkComplete(object sender, RunWorkerCompletedEventArgs e)
        {

        }

        private void PrevHistory()
        {
            if (HistoryIndex == 0 && BuildFolderList.Count > 0)
                HistoryIndex = BuildFolderList.Count - 1;
            else
                HistoryIndex--;

            LoadHistoryData(Common.Common.SELECT);
        }
        private void NextHistory()
        {
            if (HistoryIndex == BuildFolderList.Count - 1)
                HistoryIndex = 0;
            else
                HistoryIndex++;

            LoadHistoryData(Common.Common.SELECT);
        }
    }
}
