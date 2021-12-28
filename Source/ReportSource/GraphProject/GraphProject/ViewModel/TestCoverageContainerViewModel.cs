using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Ioc;
using GraphProject.Etc;
using GraphProject.Models;
using LiveCharts;
using LiveCharts.Wpf;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Media;

namespace GraphProject.ViewModel
{
    public class TestCoverageContainerViewModel : ViewModelBase
    {
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
        public MCDCTestCoverageModel MCDCcontentViewAdd(IronPython.Runtime.List Cov_List)
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
                string executed_tmp = tmp["mcdc"].ToString();

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

            MCDCTestCoverageModel tcm = new MCDCTestCoverageModel()
            {
                PercentBar = 200 * (percentage / 100),
                PercentBarText = percentage.ToString() + "%",
                CoverageSeriesCollection = new SeriesCollection()
                {
                    new RowSeries
                    {
                        Title = "MCDC Coverage",
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
        public TestCoverageContainerViewModel()
        {
            try
            {
                IronPython.Runtime.List Cov_List = MainViewModel.Coverage_Data;
                IronPython.Runtime.PythonDictionary Func_List = MainViewModel.Func_Cov_Data;
                IronPython.Runtime.PythonDictionary Call_List = MainViewModel.Call_Cov_Data;
                IronPython.Runtime.List MCDC_List = MainViewModel.MCDC_Cov_Data;

                if (Call_List == null)
                    this.StateCoverageView = new TestCoverageViewModel(contentViewAdd(Cov_List), func_contentViewAdd(Func_List));
                else
                {
                    if(MainViewModel.MCDC_Cov_Data == null)
                    this.StateCoverageView = new TestCoverageViewModel(contentViewAdd(Cov_List), func_contentViewAdd(Func_List), call_contentViewAdd(Call_List), null);
                    else
                        this.StateCoverageView = new TestCoverageViewModel(contentViewAdd(Cov_List), func_contentViewAdd(Func_List), call_contentViewAdd(Call_List), MCDCcontentViewAdd(MCDC_List));
                }
            }
            catch (Exception ex)
            {
                CommonUtil.LogMessageList.Add(ex.Message + CommonUtil.GetExceptionLineNumber(ex));
                throw;
                // return;
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
    }
}
