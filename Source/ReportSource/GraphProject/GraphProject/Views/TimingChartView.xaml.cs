using LiveCharts;
using LiveCharts.Wpf;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace GraphProject.Views
{
    /// <summary>
    /// TimingChartView.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class TimingChartView : UserControl
    {
        public SeriesCollection SeriesCollection { get; set; }
        public string[] Labels { get; set; }
        public Func<double, string> Formatter { get; set; }

        public TimingChartView()
        {
            InitializeComponent();
        }


        private void TextBox_LostFocus(object sender, RoutedEventArgs e)
        {
            TextBox tb = (TextBox)sender;

            if (tb == null) return;

            string Scale = tb.Text;
            double scale = 0.0;
            if (Scale.Contains("ns"))
            {
                scale = Convert.ToDouble(Scale.Substring(0, Scale.Length - 2));
                scale = scale * 0.001;
                scale = Math.Truncate(scale * 10000) / 10000;
            }
            else if (Scale.Contains("us"))
            {
                return;
            }
            else if (Scale.Contains("ms"))
            {
                scale = Convert.ToDouble(Scale.Substring(0, Scale.Length - 2));
                scale = scale * 1000;
                scale = Math.Truncate(scale * 10000) / 10000;
            }
            else if (Scale.Contains("s"))
            {
                scale = Convert.ToDouble(Scale.Substring(0, Scale.Length - 1));
                scale = scale * 1000000;
                scale = Math.Truncate(scale * 10000) / 10000;
            }
            else
            {
                tb.Text = Scale + "us";
                return;
            }

            tb.Text = scale.ToString() + "us";

        }
    }
}
