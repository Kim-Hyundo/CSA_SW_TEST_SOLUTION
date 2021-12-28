using GalaSoft.MvvmLight;
using LiveCharts;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GraphProject.Models
{
    public class PassFailPieChartModel : ObservableObject
    {
        public string Title { get; set; }
        public string Date { get; set; }

        public string ScenarioName { get; set; }

        public string TotalCount { get; set; }
        public string PassCount { get; set; }
        public string FailCount { get; set; }
        public string NullCount { get; set; }

        public SeriesCollection PieSeriesCollection { get; set; }
        public ChartValues<double> LinearSeriesCollection { get; set; }
        
        public ObservableCollection<string> FailList { get; set; }
    }
}
