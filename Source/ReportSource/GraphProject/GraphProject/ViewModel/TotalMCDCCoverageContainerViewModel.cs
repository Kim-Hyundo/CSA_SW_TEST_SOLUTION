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
using System.IO;
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
    public class TotalMCDCCoverageContainerViewModel : ViewModelBase
    {
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
        public TotalMCDCCoverageContainerViewModel()
        {
            try
            {
                this.StateCoverageView = new TotalMCDCCoverageViewModel(MCDCcontentViewAdd(MainViewModel.TotalMCDCCoverage_Data));
            }
            catch (Exception ex)
            {
                CommonUtil.LogMessageList.Add(ex.Message + CommonUtil.GetExceptionLineNumber(ex));
                throw;
                //return;
            }
        }
    }
}
