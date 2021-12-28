using GalaSoft.MvvmLight;
using ProstMain.ViewModel;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProstMain.Model
{
    public class TestHistoryClass : ObservableObject
    {
        public string BuildFolderName { set; get; }
        public string BuildFolderPath { set; get; }

        private ObservableCollection<TestSenarioModel> _TestSenarioList;
        public ObservableCollection<TestSenarioModel> TestSenarioList
        {
            get { return _TestSenarioList; }
            set
            {
                if (_TestSenarioList != value)
                {
                    _TestSenarioList = value;
                    RaisePropertyChanged("TestSenarioList");
                }
            }
        }

        public TestHistoryClass()
        {
            TestSenarioList = new ObservableCollection<TestSenarioModel>();
        }
    }
}
