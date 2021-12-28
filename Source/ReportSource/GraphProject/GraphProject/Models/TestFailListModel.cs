using CommonServiceLocator;
using GalaSoft.MvvmLight;
using GraphProject.ViewModel;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GraphProject.Models
{
    public class TestFailListModel : ObservableObject
    {
        public string ScenarioName { get; set; }
        public string TestCaseNum { get; set; }

        public string InputData { get; set; }
        public string ExpectedOutputData { get; set; }
        public string ActualOutputData { get; set; }
        public string Tolerance { get; set; }
        public string ExecutionTime { get; set; }

        public string PassFail { get; set; }

    }
}
