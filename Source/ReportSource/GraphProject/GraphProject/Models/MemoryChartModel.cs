using LiveCharts.Wpf;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media;
using GalaSoft.MvvmLight;
using LiveCharts;

namespace GraphProject.Models
{
    public class MemoryChartModel : ObservableObject
    {
        
        public Brush TopBackground { get; set; }
        public Brush BottomBackground { get; set; }

        public string Title { get; set; }

        public SeriesCollection SeriesCollection { get; set; }
        public SeriesCollection StackSeriesCollection { get; set; }

        public string[] Labels { get; set; }
        public Func<double, string> Formatter { get; set; }

        public string[] StackLabels { get; set; }
        public Func<double, string> StackFormatter { get; set; }

        public double LastLecture { get; set; }

        public string Total { get; set; }
        public string Reserved { get; set; }
        public string Free { get; set; }

        public string CodeUsage { get; set; }
        public string DataUsage { get; set; }

        public string Comment { get; set; }
        
    }
}
