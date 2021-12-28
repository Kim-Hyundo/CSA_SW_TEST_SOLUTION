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
    public class TestFailListViewModel : ViewModelBase
    {
        public PassFailPieChartModel passfailpiechartmodel { get; set; } = new PassFailPieChartModel();

        [PreferredConstructor]
        public TestFailListViewModel()
        {

        }

        public TestFailListViewModel(PassFailPieChartModel pfpc)
        {
            this.passfailpiechartmodel = pfpc;
        }
    }
}
