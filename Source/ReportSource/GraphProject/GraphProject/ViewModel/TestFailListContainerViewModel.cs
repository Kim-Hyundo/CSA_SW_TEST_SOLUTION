using GalaSoft.MvvmLight;
using GraphProject.Etc;
using GraphProject.Models;
using LiveCharts;
using LiveCharts.Wpf;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;

namespace GraphProject.ViewModel
{
    public class TestFailListContainerViewModel : ViewModelBase
    {

        private object _pieContentView;

        public object PieContentView
        {
            get { return this._pieContentView; }

            set
            {
                this._pieContentView = value;
                this.RaisePropertyChanged("PieContentView");
            }
        }

        private object _gridviewContentView;

        public object GridviewContentView
        {
            get { return this._gridviewContentView; }

            set
            {
                this._gridviewContentView = value;
                this.RaisePropertyChanged("GridviewContentView");
            }
        }

        private PassFailPieChartModel contentviewAdd(IronPython.Runtime.List Test_Result_List)
        {
            int fail_count = (int)MainViewModel.Summary_Data["Fail Count"];
            int pass_count = (int)MainViewModel.Summary_Data["Pass Count"];
            int total_count = (int)MainViewModel.Summary_Data["Test Sample Count"];

            PassFailPieChartModel temp = new PassFailPieChartModel();

            temp.PieSeriesCollection = new SeriesCollection{
                new PieSeries
                {
                    Values = new ChartValues<double> { pass_count },
                    Title = "Pass",
                    DataLabels = true,
                    LabelPoint = chartPoint => string.Format("{0} ({1:P})", chartPoint.Y, chartPoint.Participation),
                    Stroke = new SolidColorBrush(Color.FromArgb(0xFF,0x22,0x22,0x22)),//#53A5AB
                    Fill = new SolidColorBrush(Color.FromArgb(0xCC, 0x57, 0x95, 0x5A))//#CCAB33
                },
                new PieSeries
                {
                    Values = new ChartValues<double> { fail_count },
                    Title = "Fail",
                    DataLabels = true,
                    LabelPoint = chartPoint => string.Format("{0} ({1:P})", chartPoint.Y, chartPoint.Participation),
                    Stroke = new SolidColorBrush(Colors.Red),//#53A5AB
                    Fill = new SolidColorBrush(Colors.Red)
                },

                new PieSeries
                {
                    Values = new ChartValues<double> { 0 },
                    Title = "Unknown",
                    DataLabels = true,
                    LabelPoint = chartPoint => string.Format("{0} ({1:P})", chartPoint.Y, chartPoint.Participation),
                    Stroke = new SolidColorBrush(Color.FromArgb(0xFF,0x22,0x22,0x22)),//#53A5AB
                    Fill = new SolidColorBrush(Color.FromArgb(0xCC, 0x90, 0x91, 0x42))
                },

            };

            temp.PassCount = pass_count.ToString() + " EA";
            temp.FailCount = fail_count.ToString() + " EA";
            temp.TotalCount = total_count.ToString() + " EA";
            temp.NullCount = "0 EA";

            temp.ScenarioName = MainViewModel.curr_scenario;

            temp.Date = DateTime.Now.ToString("yyyy/MM/dd  HH:mm:ss");

            temp.FailList = new System.Collections.ObjectModel.ObservableCollection<string>();
            temp.LinearSeriesCollection = new ChartValues<double>();

            string ScenarioName = MainViewModel.curr_scenario;

            foreach (IronPython.Runtime.PythonDictionary tmp in Test_Result_List)
            {
                string TestID = tmp["Test ID"].ToString();

                string Passfail = tmp["PassFail"].ToString();

                if (Passfail == "Fail")
                {
                    temp.LinearSeriesCollection.Add(0);
                    temp.FailList.Add(ScenarioName + " , " + TestID);
                }
                else if (Passfail == "Pass")
                {
                    temp.LinearSeriesCollection.Add(0.9);
                }

            }

            return temp;
        }

        private List<TestFailListModel> gridcontentviewAdd(IronPython.Runtime.List Test_Result_List)
        {
            string ScenarioName = MainViewModel.curr_scenario;

            List<TestFailListModel> TestResultList = new List<TestFailListModel>();

            foreach (IronPython.Runtime.PythonDictionary tmp in Test_Result_List)
            {

                string TestID = tmp["Test ID"].ToString();
                string Passfail = tmp["PassFail"].ToString();
                string input_data = "";
                string ex_output_data = "";
                string ac_output_data = "";
                string tolerance = "";
                string execution_time = "";

                IronPython.Runtime.PythonDictionary inp = (IronPython.Runtime.PythonDictionary)tmp["Input Data"];
                IronPython.Runtime.List input_keys = (IronPython.Runtime.List)inp.keys();

                IronPython.Runtime.PythonDictionary ex_out = (IronPython.Runtime.PythonDictionary)tmp["Expect Output Data"];
                IronPython.Runtime.List ex_out_keys = (IronPython.Runtime.List)ex_out.keys();

                IronPython.Runtime.PythonDictionary ac_out = (IronPython.Runtime.PythonDictionary)tmp["Actual Output Data"];
                IronPython.Runtime.List ac_out_keys = (IronPython.Runtime.List)ac_out.keys();

                IronPython.Runtime.PythonDictionary toler = null;
                IronPython.Runtime.List tolerance_keys = null;

                if (tmp.ContainsKey("Tolerance"))
                {
                    toler = (IronPython.Runtime.PythonDictionary)tmp["Tolerance"];
                    tolerance_keys = (IronPython.Runtime.List)toler.keys();
                }

                IronPython.Runtime.PythonDictionary exec_time = (IronPython.Runtime.PythonDictionary)tmp["Execution time"];
                IronPython.Runtime.List exec_time_keys = (IronPython.Runtime.List)exec_time.keys();

                foreach (string key in input_keys)
                {
                    if (key.ToLower().Contains("user macro"))
                        input_data += inp[key].ToString() + "\n";
                    else
                        input_data += key + " = " + inp[key].ToString() + "\n";
                }

                if (input_data != "")
                    input_data = input_data.Substring(0, input_data.Length - 1);

                foreach (string key in ex_out_keys)
                {
                    if (key.ToLower().Contains("user macro"))
                        ex_output_data += ex_out[key].ToString() + "\n";
                    else
                        ex_output_data += key + " = " + ex_out[key].ToString() + "\n";
                }

                if (ex_output_data != "")
                    ex_output_data = ex_output_data.Substring(0, ex_output_data.Length - 1);

                foreach (string key in ac_out_keys)
                {
                    if (key.ToLower().Contains("user macro"))
                        ac_output_data += ac_out[key].ToString() + "\n";
                    else
                        ac_output_data += key + " = " + ac_out[key].ToString() + "\n";
                }

                if (ac_output_data != "")
                    ac_output_data = ac_output_data.Substring(0, ac_output_data.Length - 1);

                if (tolerance_keys != null)
                {
                    foreach (string key in tolerance_keys)
                    {
                        //tolerance += key + " = " + toler[key].ToString() + "\n";
                        tolerance += toler[key].ToString() + "\n";
                    }

                    if (tolerance != "")
                        tolerance = tolerance.Substring(0, tolerance.Length - 1);
                }

                foreach (string key in exec_time_keys)
                {
                    execution_time += key + " = " + exec_time[key].ToString() + "\n";
                }

                if (execution_time != "")
                    execution_time = execution_time.Substring(0, execution_time.Length - 1);


                if (input_data.Contains("DUMMY"))
                    continue;

                TestResultList.Add(new TestFailListModel()
                {
                    ScenarioName = ScenarioName,
                    TestCaseNum = TestID,
                    InputData = input_data,
                    ExpectedOutputData = ex_output_data,
                    ActualOutputData = ac_output_data,
                    Tolerance = tolerance,
                    ExecutionTime = execution_time,
                    PassFail = Passfail
                });



            }

            return TestResultList;
        }

        public TestFailListContainerViewModel()
        {
            try
            {
                IronPython.Runtime.List Test_Result_List = (IronPython.Runtime.List)MainViewModel.Test_Result_Data;

                this.PieContentView = new TestFailListViewModel(contentviewAdd(Test_Result_List));

                this.GridviewContentView = new TestFailGridViewModel(gridcontentviewAdd(Test_Result_List));
            }
            catch (Exception ex)
            {
                CommonUtil.LogMessageList.Add(ex.Message);
            }
        }
    }
}
