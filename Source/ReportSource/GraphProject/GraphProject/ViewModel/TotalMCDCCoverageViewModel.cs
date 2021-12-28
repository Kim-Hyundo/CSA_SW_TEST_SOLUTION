using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using GalaSoft.MvvmLight.Ioc;
using GraphProject.Etc;
using GraphProject.Models;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Windows.Data;

namespace GraphProject.ViewModel
{
    public class TotalMCDCCoverageViewModel : ViewModelBase
    {

        private string _title;

        public string Title
        {
            get { return _title; }
            set
            {
                if (_title != value)
                {
                    _title = value;
                    RaisePropertyChanged("Title");
                }
            }
        }

        private double _percentBar;

        public double PercentBar
        {
            get { return _percentBar; }
            set
            {
                if (_percentBar != value)
                {
                    _percentBar = value;
                    RaisePropertyChanged("PercentBar");
                }
            }
        }

        private string _percentBarText;

        public string PercentBarText
        {
            get { return _percentBarText; }
            set
            {
                if (_percentBarText != value)
                {
                    _percentBarText = value;
                    RaisePropertyChanged("PercentBarText");
                }
            }
        }
        public MCDCTestCoverageModel mcdctestCoverageModel { get; set; } = new MCDCTestCoverageModel();

        public TotalMCDCCoverageViewModel(MCDCTestCoverageModel mcdctcm)
        {
            this.mcdctestCoverageModel = mcdctcm;

            Title = "Total Coverage";

            PercentBar = mcdctcm.PercentBar;
            PercentBarText = mcdctcm.PercentBarText;
        }
        
        [PreferredConstructor]
        public TotalMCDCCoverageViewModel()
        {

        }
    }
}
