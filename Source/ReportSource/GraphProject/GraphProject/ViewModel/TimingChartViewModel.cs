using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.CommandWpf;
using GalaSoft.MvvmLight.Ioc;
using GraphProject.Models;
using LiveCharts;
using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Data;

namespace GraphProject.ViewModel
{
    public class TimingChartViewModel : ViewModelBase
    {
        public TimingChartModel timingChartModel { get; set; } = new TimingChartModel();
        private ZoomingOptions ZoomingMode { get; set; }

        public RelayCommand ScaleSetCommand { get; set; }

        public TimingChartViewModel(TimingChartModel tsm)
        {
            this.timingChartModel = tsm;
            ZoomingMode = ZoomingOptions.X;

            ScaleSetCommand = new RelayCommand(ScaleSetFunction);
        }

        [PreferredConstructor]
        public TimingChartViewModel()
        {

        }

        private void ScaleSetFunction()
        {

            double max = Convert.ToDouble(timingChartModel.MaxValue.Substring(0, timingChartModel.MaxValue.Length - 2));
            double min = Convert.ToDouble(timingChartModel.MinValue.Substring(0, timingChartModel.MinValue.Length - 2));
            double scale = Convert.ToDouble(timingChartModel.Scale.Substring(0, timingChartModel.Scale.Length - 2));

            List<double> area = AreaFilteringFunction(min, max, scale);

            if (area == null)
            {
                MessageBox.Show("잘못된 Scale 값 입니다.");
                return;
            }

            ChartValues<double> count = CountFunction(timingChartModel.TotalDatas, area);
            string[] labels = CreateLabelFunction(area);
            timingChartModel.Labels = labels;
            timingChartModel.SeriesCollection[0].Values = count;
        }
        
        public static string ToMicroSecond(string time)
        {
            if (time.Contains("us") || time.Trim() == "-")
                return time;

            string result = "";

            if (time.Contains("ns"))
            {
                double time_tmp = Convert.ToDouble(time.Substring(0, time.Length - 2));
                result = (time_tmp * 0.001).ToString() + "us";
            }
            else if (time.Contains("ms"))
            {
                double time_tmp = Convert.ToDouble(time.Substring(0, time.Length - 2));
                result = (time_tmp * 1000).ToString() + "us";
            }
            else if (time.Contains("s"))
            {
                double time_tmp = Convert.ToDouble(time.Substring(0, time.Length - 2));
                result = (time_tmp * 1000000).ToString() + "us";
            }

            return result;
        }

        public static int priority(string op)
        {
            if (op.Contains("ns"))
                return 1;
            else if (op.Contains("us"))
                return 2;
            else if (op.Contains("ms"))
                return 3;
            else if (op.Contains("s"))
                return 4;

            return -1;
        }
        
        public static string prioritytoUnit(int unit, string data)
        {
            if (unit == 1)
                return data + "ns";
            else if (unit == 2)
                return data + "us";
            else if (unit == 3)
                return data + "ms";
            else if (unit == 4)
                return data + "s";

            return null;
        }

        public static string timecalc(int mode, string op1, string op2, string unit)
        {
            if (!op1.Contains(unit) || !op2.Contains(unit))
                return null;

            double op1_tmp = 0.0;
            double op2_tmp = 0.0;
            double result = 0.0;

            op1_tmp = Convert.ToDouble(op1.Substring(0, op1.Length - 2));
            op2_tmp = Convert.ToDouble(op2.Substring(0, op2.Length - 2));

            result = calc(mode, op1_tmp, op2_tmp);
            result = Math.Abs(result);
            result = Math.Truncate(result * 1000) / 1000;

            return result.ToString() + unit;
        }

        private static double calc(int mode, double a, double b)
        {
            double result = 0;

            if (mode == 1)
            {
                result = a + b;
            }
            else if (mode == 2)
            {
                result = a - b;
            }
            else if (mode == 3)
            {
                result = a * b;
            }
            else if (mode == 4)
            {
                result = a / b;
            }

            return result;
        }

        public static List<double> AreaFilteringFunction(double min, double max, double scale)
        {
            List<double> area = new List<double>();

            double diff = max - min;
            
            if (min == max)
            {
                area.Add(min);
                area.Add(max);
                return area;
            }
            if (diff <= 0 || scale == 0)
                return null;

            diff = Math.Round(diff, 4);
            double nmg = diff % scale;

            area.Add(min);

            for (double i = scale; min + i <= max; i+= scale)
            {
                area.Add(min + i);
            }

            if (nmg != 0)
            {
                if (area.Last() != nmg && nmg >= 0.001)
                    area.Add(area.Last() + nmg);
            }

            return area;   
        }

        public static ChartValues<double> CountFunction(List<double> data, List<double> area)
        {
            if (data.Count == 0 || area.Count <= 1)
                return null;

            ChartValues<double> newData = new ChartValues<double>();
            double[] datatmp = new double[area.Count - 1];

            foreach(double tmp in data)
            {
                for (int i = 0; i < area.Count - 1; i++)
                {
                    if (area[i] <= tmp && tmp <= area[i + 1])
                    {
                        datatmp[i]++;
                        break;
                    }
                }
            }
            
            foreach(double tmp in datatmp)
            {
                newData.Add(tmp);
            }

            return newData;
        }

        public static string[] CreateLabelFunction(List<double> area)
        {

            if (area.Count <= 1)
                return null;

            string[] newLabel = new string[area.Count - 1];

            for(int i = 0; i < area.Count - 1; i++)
            {
                string tmp = area[i].ToString() + "-" + area[i + 1];
                newLabel[i] = tmp;
            }

            return newLabel;
        }

        private void ToogleZoomingMode(object sender, RoutedEventArgs e)
        {
            switch (ZoomingMode)
            {
                case ZoomingOptions.None:
                    ZoomingMode = ZoomingOptions.X;
                    break;
                case ZoomingOptions.X:
                    ZoomingMode = ZoomingOptions.Y;
                    break;
                case ZoomingOptions.Y:
                    ZoomingMode = ZoomingOptions.Xy;
                    break;
                case ZoomingOptions.Xy:
                    ZoomingMode = ZoomingOptions.None;
                    break;
                default:
                    throw new ArgumentOutOfRangeException();
            }
        }

        private void ResetZoomOnClick(object sender, RoutedEventArgs e)
        {
            //Use the axis MinValue/MaxValue properties to specify the values to display.
            //use double.Nan to clear it.

            //X.MinValue = double.NaN;
            //X.MaxValue = double.NaN;
            //Y.MinValue = double.NaN;
            //Y.MaxValue = double.NaN;
        }

        public class ZoomingModeCoverter : IValueConverter
        {
            public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
            {
                switch ((ZoomingOptions)value)
                {
                    case ZoomingOptions.None:
                        return "None";
                    case ZoomingOptions.X:
                        return "X";
                    case ZoomingOptions.Y:
                        return "Y";
                    case ZoomingOptions.Xy:
                        return "XY";
                    default:
                        throw new ArgumentOutOfRangeException();
                }
            }

            public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
            {
                throw new NotImplementedException();
            }
        }

    }
}
