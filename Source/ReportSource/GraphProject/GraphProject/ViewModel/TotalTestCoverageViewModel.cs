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
    public class TotalTestCoverageViewModel : ViewModelBase
    {
        private string _selectMode;

        public string SelectMode
        {
            get { return _selectMode; }
            set
            {
                if (_selectMode != value)
                {
                    _selectMode = value;
                    RaisePropertyChanged("SelectMode");
                }
            }
        }


        private string _statement_visiblity;

        public string Statement_visiblity
        {
            get { return _statement_visiblity; }
            set
            {
                if (_statement_visiblity != value)
                {
                    _statement_visiblity = value;
                    RaisePropertyChanged("Statement_visiblity");
                }
            }
        }

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
        public TestCoverageModel testCoverageModel { get; set; } = new TestCoverageModel();

        public TotalTestCoverageViewModel(TestCoverageModel tcm)
        {
            this.testCoverageModel = tcm;

            Title = "Total Coverage";
            SelectMode = "Statement";
            Statement_visiblity = "Visible";

            PercentBar = tcm.PercentBar;
            PercentBarText = tcm.PercentBarText;
        }
        [PreferredConstructor]
        public TotalTestCoverageViewModel()
        {

        }
    }
}
