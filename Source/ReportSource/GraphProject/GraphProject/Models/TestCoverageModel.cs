using GalaSoft.MvvmLight;
using LiveCharts;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GraphProject.Models
{
    public class TestCoverageModel : ObservableObject
    {
        public double PercentBar { get; set; }
        public string PercentBarText { get; set; }

        public double Statement_height { get; set; }

        public SeriesCollection CoverageSeriesCollection { get; set; }

        public string[] Labels { get; set; }
        public Func<double, string> Formatter { get; set; }
    }

    public class FuncCoverageModelList : ObservableObject
    {
        public double PercentBar { get; set; }
        public string PercentBarText { get; set; }

        public List<FuncCoverageModel> ftcm { get; set; }
    }

    public class FuncCoverageModel : ObservableObject
    {
        public string Func_Source_File { get; set; }
        public string Func_Func_Name { get; set; }
        public string Func_Address { get; set; }
        public string Func_IsExecuted { get; set; }
    }

    public class CallCoverageModelList : ObservableObject
    {
        public double PercentBar { get; set; }
        public string PercentBarText { get; set; }

        public List<CallCoverageModel> ctcm { get; set; }
    }

    public class CallCoverageModel : ObservableObject
    {
        public string Call_Source_File { get; set; }
        public string Call_Func_Name { get; set; }
        public string Call_Inner_Func_Name { get; set; }
        public string Call_Address { get; set; }
        public string Call_IsExecuted { get; set; }
        public string TC_list { get; set; }
    }
    public class MCDCTestCoverageModel : ObservableObject
    {
        public double PercentBar { get; set; }
        public string PercentBarText { get; set; }

        public double Statement_height { get; set; }

        public SeriesCollection CoverageSeriesCollection { get; set; }

        public string[] Labels { get; set; }
        public Func<double, string> Formatter { get; set; }
    }
}
