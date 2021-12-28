using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Ioc;
using GraphProject.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GraphProject.ViewModel
{
    class TestSummaryViewModel :ViewModelBase
    {
        public List<TestSummaryModel> testSummaryModel { get; set; } = new List<TestSummaryModel>();

        //public List<string> listtemp { get; set; } = new List<string>();

        public TestSummaryViewModel(List<TestSummaryModel> tsm)
        {
            this.testSummaryModel = tsm;
            //this.listtemp = tmp;
        }
        [PreferredConstructor]
        public TestSummaryViewModel()
        {
            
        }
    }
}
