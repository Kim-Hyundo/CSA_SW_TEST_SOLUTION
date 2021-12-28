using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Ioc;
using GraphProject.Models;
using LiveCharts;
using LiveCharts.Wpf;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media;

namespace GraphProject.ViewModel
{
    public class ChartViewModel : ViewModelBase
    {
        public MemoryChartModel memorychartmodel { get; set; } = new MemoryChartModel();
        private string _Unit;
        public string Unit
        {
            get { return this._Unit; }

            set
            {
                this._Unit = value;
                this.RaisePropertyChanged("Unit");
            }
        }

        public ChartViewModel(MemoryChartModel memoryChartModel, string unit)
        {
            this.memorychartmodel = memoryChartModel;
            Unit = unit;
        }

        [PreferredConstructor]
        public ChartViewModel()
        {
 
        }
    }
}
