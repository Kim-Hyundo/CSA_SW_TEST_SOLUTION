using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using GalaSoft.MvvmLight.Ioc;
using GraphProject.Etc;
using GraphProject.Models;
using LiveCharts;
using LiveCharts.Wpf;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Media;
using System.Xml;
using static GraphProject.Models.CoverageModel;

namespace GraphProject.ViewModel
{
    public class TotalTestCoverageContainerViewModel : ViewModelBase
    {
        public RelayCommand CovSelectionChangedCommand { get; set; }
        FuncCoveragePassFailComparer funcoveragepassfailcompare = new FuncCoveragePassFailComparer();
        CallCoveragePassFailComparer callcoveragepassfailcompare = new CallCoveragePassFailComparer();
        private object _stateCoverageView;

        public object StateCoverageView
        {
            get { return this._stateCoverageView; }

            set
            {
                this._stateCoverageView = value;
                this.RaisePropertyChanged("StateCoverageView");
            }
        }

        private object _functionCallCoverageView;

        public object FunctionCallCoverageView
        {
            get { return this._functionCallCoverageView; }

            set
            {
                this._functionCallCoverageView = value;
                this.RaisePropertyChanged("FunctionCallCoverageView");
            }
        }

        private string _scenarioName;

        public string ScenarioName
        {
            get { return this._scenarioName; }

            set
            {
                this._scenarioName = value;
                this.RaisePropertyChanged("ScenarioName");
            }
        }
        private CoverageModel _SelectCoverageModel;

        public CoverageModel SelectCoverageModel
        {
            get { return this._SelectCoverageModel; }

            set
            {
                this._SelectCoverageModel = value;
                this.RaisePropertyChanged("SelectCoverageModel");
            }
        }
        private ObservableCollection<CoverageModel> _TotalCoverageData;

        public ObservableCollection<CoverageModel> TotalCoverageData
        {
            get { return this._TotalCoverageData; }

            set
            {
                this._TotalCoverageData = value;
                this.RaisePropertyChanged("TotalCoverageData");
            }
        }

        public FuncCoverageModelList func_contentViewAdd(IronPython.Runtime.PythonDictionary Func_List)
        {
            FuncCoverageModelList ftcml = new FuncCoverageModelList();

            List<FuncCoverageModel> func_list = new List<FuncCoverageModel>();

            IronPython.Runtime.List func_list_tmp = (IronPython.Runtime.List)Func_List["FunctionList"];

            double total_cov = 0.0;
            double executed_cov = 0.0;
            double percentage = 0.0;

            foreach (IronPython.Runtime.PythonDictionary tmp in func_list_tmp)
            {
                func_list.Add(new FuncCoverageModel()
                {
                    Func_Source_File = tmp["File"].ToString(),
                    Func_Func_Name = tmp["Function"].ToString(),
                    Func_Address = tmp["AddressRange"].ToString(),
                    Func_IsExecuted = tmp["Coverage"].ToString()
                });
                total_cov += 1.0;
                if (tmp["Coverage"].ToString() == "True")
                    executed_cov += 1.0;
            }


            func_list.Sort(funcoveragepassfailcompare);
            percentage = Math.Truncate(executed_cov / total_cov * 100) / 100;
            ftcml.PercentBar = 200 * percentage;
            ftcml.PercentBarText = (percentage * 100).ToString() + "%";

            ftcml.ftcm = func_list;

            return ftcml;
        }

        public CallCoverageModelList call_contentViewAdd(IronPython.Runtime.PythonDictionary Call_List)
        {
            CallCoverageModelList ctcml = new CallCoverageModelList();

            List<CallCoverageModel> call_list = new List<CallCoverageModel>();

            double total_cov = 0.0;
            double executed_cov = 0.0;
            double percentage = 0.0;

            IronPython.Runtime.List data_tmp = (IronPython.Runtime.List)Call_List["FunctionList"];

            ScenarioName = MainViewModel.curr_scenario;

            foreach (IronPython.Runtime.PythonDictionary tmp in data_tmp)
            {
                IronPython.Runtime.List tc_tmp = (IronPython.Runtime.List)tmp["TestCase"];

                string tc_list = "";

                foreach (string tc in tc_tmp)
                {
                    tc_list += tc + ", ";
                }

                call_list.Add(new CallCoverageModel()
                {
                    Call_Source_File = tmp["File"].ToString(),
                    Call_Func_Name = tmp["Function"].ToString(),
                    Call_Inner_Func_Name = tmp["CalledFunction"].ToString(),
                    Call_Address = tmp["Address"].ToString(),
                    Call_IsExecuted = tmp["Coverage"].ToString(),
                    TC_list = tc_list,
                });

                total_cov += 1.0;
                if (tmp["Coverage"].ToString() == "True")
                    executed_cov += 1.0;
            }

            call_list.Sort(callcoveragepassfailcompare);
            percentage = Math.Truncate(executed_cov / total_cov * 100) / 100;
            ctcml.PercentBar = 200 * percentage;
            ctcml.PercentBarText = (percentage * 100).ToString() + "%";

            ctcml.ctcm = call_list;

            return ctcml;
        }
        private void CovSelectionChangedFunction()
        {
            if (SelectCoverageModel.ModuleName == "Total" && SelectCoverageModel.ModuleCoveragePercent == "9999")
                this.StateCoverageView = new TotalTestCoverageViewModel(contentViewAdd(MainViewModel.TotalCoverage_Data));
            else 
                this.StateCoverageView = new TotalTestCoverageViewModel(contentViewAdd());
            
        }
        public TestCoverageModel contentViewAdd()
        {
            if(TotalCoverageData == null)
                TotalCoverageData = new ObservableCollection<CoverageModel>();
            CoverageXMLParsing();

            if (SelectCoverageModel == null)
                return null;

            int total_cnt = SelectCoverageModel.CoverageList_Function.Count;
            double total_cov = 0.0;
            double percentage = 0.0;

            string[] funcnames = new string[total_cnt];
            ChartValues<double> executed_list = new ChartValues<double>();

            int idx = 0;

            foreach (CoverageFunctionModel model in SelectCoverageModel.CoverageList_Function)
            {
                string funcname_tmp = model.FunctionName;
                string executed_tmp = model.FunctionStatementCoveragePercent;

                if (funcname_tmp == "")
                    continue;

                if (executed_tmp == "" || executed_tmp == "-")
                    continue;

                funcnames[idx++] = funcname_tmp.Trim();

                if (executed_tmp.Contains("%"))
                    executed_tmp = executed_tmp.Substring(0, executed_tmp.Length - 1);

                double executed_double = Convert.ToDouble(executed_tmp);
                total_cov += executed_double;
                executed_list.Add(executed_double);
            }

            percentage = Math.Truncate(total_cov / total_cnt * 100) / 100;

            LinearGradientBrush myLinearGradientBrush = new LinearGradientBrush();
            myLinearGradientBrush.StartPoint = new Point(0, 0);
            myLinearGradientBrush.EndPoint = new Point(1, 1);
            myLinearGradientBrush.GradientStops.Add(
                new GradientStop(Color.FromArgb(0x8F, 0x71, 0xCE, 0xAA), 1.0));
            myLinearGradientBrush.GradientStops.Add(
                new GradientStop(Color.FromArgb(0x8F, 0xD1, 0xEF, 0xCF), 0.0));

            TestCoverageModel tcm = new TestCoverageModel()
            {
                PercentBar = 200 * (percentage / 100),
                PercentBarText = percentage.ToString() + "%",
                CoverageSeriesCollection = new SeriesCollection()
                {
                    new RowSeries
                    {
                        Title = "Coverage",
                        Values = executed_list,
                        DataLabels = true,
                        Foreground = new SolidColorBrush(Colors.White),
                        Fill = myLinearGradientBrush,
                    },
                },
                Statement_height = executed_list.Count * 18,
                Labels = funcnames,
                Formatter = value => value + "%"
            };

            return tcm;
        }
        public TestCoverageModel contentViewAdd(IronPython.Runtime.List Cov_List)
        {
            int total_cnt = Cov_List.Count;
            double total_cov = 0.0;
            double percentage = 0.0;

            string[] funcnames = new string[total_cnt];
            ChartValues<double> executed_list = new ChartValues<double>();

            int idx = 0;

            foreach (IronPython.Runtime.PythonDictionary tmp in Cov_List)
            {
                string funcname_tmp = tmp["tree"].ToString();
                string executed_tmp = tmp["statement"].ToString();

                if (funcname_tmp == "")
                    continue;

                if (executed_tmp == "" || executed_tmp == "-")
                    continue;

                funcnames[idx++] = funcname_tmp.Trim();

                if (executed_tmp.Contains("%"))
                    executed_tmp = executed_tmp.Substring(0, executed_tmp.Length - 1);

                double executed_double = Convert.ToDouble(executed_tmp);
                total_cov += executed_double;
                executed_list.Add(executed_double);
            }

            percentage = Math.Truncate(total_cov / total_cnt * 100) / 100;

            LinearGradientBrush myLinearGradientBrush = new LinearGradientBrush();
            myLinearGradientBrush.StartPoint = new Point(0, 0);
            myLinearGradientBrush.EndPoint = new Point(1, 1);
            myLinearGradientBrush.GradientStops.Add(
                new GradientStop(Color.FromArgb(0x8F, 0x71, 0xCE, 0xAA), 1.0));
            myLinearGradientBrush.GradientStops.Add(
                new GradientStop(Color.FromArgb(0x8F, 0xD1, 0xEF, 0xCF), 0.0));

            TestCoverageModel tcm = new TestCoverageModel()
            {
                PercentBar = 200 * (percentage / 100),
                PercentBarText = percentage.ToString() + "%",
                CoverageSeriesCollection = new SeriesCollection()
                {
                    new RowSeries
                    {
                        Title = "Coverage",
                        Values = executed_list,
                        DataLabels = true,
                        Foreground = new SolidColorBrush(Colors.White),
                        Fill = myLinearGradientBrush,
                    },
                },
                Statement_height = executed_list.Count * 18,
                Labels = funcnames,
                Formatter = value => value + "%"
            };

            return tcm;
        }

        [PreferredConstructor]
        public TotalTestCoverageContainerViewModel()
        {
            CovSelectionChangedCommand = new RelayCommand(CovSelectionChangedFunction);
            try
            {
                this.StateCoverageView = new TotalTestCoverageViewModel(contentViewAdd());
                //this.StateCoverageView = new TotalTestCoverageViewModel(contentViewAdd(Cov_List));
                /*if (Call_List == null)
                    this.StateCoverageView = new TestCoverageViewModel(contentViewAdd(Cov_List), func_contentViewAdd(Func_List));
                else
                    this.StateCoverageView = new TestCoverageViewModel(contentViewAdd(Cov_List), func_contentViewAdd(Func_List), call_contentViewAdd(Call_List));*/
            }
            catch (Exception ex)
            {
                CommonUtil.LogMessageList.Add(ex.Message + CommonUtil.GetExceptionLineNumber(ex));
                return;
            }
        }
        public class FuncCoveragePassFailComparer : IComparer<FuncCoverageModel>
        {
            public int Compare(FuncCoverageModel x, FuncCoverageModel y)
            {
                if (x.Func_IsExecuted == "True" && y.Func_IsExecuted == "False")
                    return -1;
                if (y.Func_IsExecuted == "True" && x.Func_IsExecuted == "False")
                    return 1;
                else
                    return 0;
            }
        }
        public class CallCoveragePassFailComparer : IComparer<CallCoverageModel>
        {
            public int Compare(CallCoverageModel x, CallCoverageModel y)
            {
                if (x.Call_IsExecuted == "True" && y.Call_IsExecuted == "False")
                    return -1;
                if (y.Call_IsExecuted == "True" && x.Call_IsExecuted == "False")
                    return 1;
                else
                    return 0;
            }
        }
        public void CoverageXMLParsing()
        {
            string url = MainViewModel.curr_Workspace + "\\" + MainViewModel.curr_Project + "\\Gen\\" + MainViewModel.curr_Folder + "\\" + MainViewModel.curr_testcase + "\\Report\\Total\\" + "Coverage_Report.xml";
            try
            {
                XmlDocument xmldoc = new XmlDocument();
                xmldoc.Load(url);
                XmlNodeList CoverageNodeList = xmldoc.SelectNodes("/TRACE32/coverage/COVerage.EXPORT.ListModule/module");
                List<string> SourceCodeList = new List<string>();
                foreach (XmlNode node in CoverageNodeList)
                {
                    string[] temp = node["tree"].InnerText.Split(new string[] { "\\" }, StringSplitOptions.None);

                    string SourceCodeName = temp[temp.Length - 1];
                    SourceCodeList.Add(SourceCodeName);
                }
                foreach (string path in SourceCodeList)
                {
                    CoverageModel inputModel = new CoverageModel();
                    ObservableCollection<CoverageFunctionModel> functionModelList = new ObservableCollection<CoverageFunctionModel>();

                    string url_function = MainViewModel.curr_Workspace + "\\" + MainViewModel.curr_Project + "\\Gen\\" + MainViewModel.curr_Folder + "\\" + MainViewModel.curr_testcase + "\\Report\\" + MainViewModel.curr_scenario + "\\" + MainViewModel.curr_Project + "\\" + path + "\\" + "Coverage_Report.xml";

                    XmlDocument xmldoc_function = new XmlDocument();
                    xmldoc_function.Load(url_function);

                    XmlNode Modulenode = xmldoc_function.SelectSingleNode("/TRACE32/coverage/COVerage.EXPORT.ListFunc/module");

                    if (Modulenode == null)
                        continue;

                    inputModel.ModuleName = path;
                    inputModel.ModuleCoveragePercent = Modulenode["exec"].InnerText;

                    XmlNodeList CoverageFunctionNodeList = xmldoc_function.SelectNodes("/TRACE32/coverage/COVerage.EXPORT.ListFunc/module/function");

                    foreach (XmlNode node1 in CoverageFunctionNodeList)
                    {
                        CoverageFunctionModel cfm = new CoverageFunctionModel();
                        IronPython.Runtime.PythonDictionary dic = new IronPython.Runtime.PythonDictionary();
                        string[] temp = node1["tree"].InnerText.Split(new string[] { "\\" }, StringSplitOptions.None);
                        string functioName = temp[temp.Length - 1];
                        string percent = node1["exec"].InnerText;

                        cfm.FunctionName = functioName;
                        cfm.FunctionStatementCoveragePercent = percent;

                        functionModelList.Add(cfm);
                    }

                    inputModel.CoverageList_Function = functionModelList;

                    TotalCoverageData.Add(inputModel);
                }
                TotalCoverageData.Add(new CoverageModel() { ModuleName = "Total", ModuleCoveragePercent = "9999" });

                if(TotalCoverageData.Count > 0 && SelectCoverageModel == null)
                    SelectCoverageModel = TotalCoverageData[0];

                xmldoc = null;
                GC.Collect();
                GC.WaitForPendingFinalizers();
            }

            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }
        }
    }
}
