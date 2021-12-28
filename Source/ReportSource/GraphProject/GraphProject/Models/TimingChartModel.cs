using GalaSoft.MvvmLight;
using LiveCharts;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GraphProject.Models
{
    public class TimingChartModel : ObservableObject
    {
        public string FuncName { get; set; }
        public string Scale { get; set; }
        public string MinValue { get; set; }
        public string MaxValue { get; set; }
        public string AvrValue { get; set; }
        public string FuncCount { get; set; }

        public List<double> TotalDatas { get; set; }

        public SeriesCollection SeriesCollection { get; set; }
        public string[] Labels { get; set; }
        public Func<double, string> Formatter { get; set; }
    }
}
