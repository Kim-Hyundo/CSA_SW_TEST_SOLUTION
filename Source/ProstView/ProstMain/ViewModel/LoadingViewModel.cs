using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using ProstMain.Common;
using ProstMain.Model;
using ProstMain.Util;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Xml;

namespace ProstMain.ViewModel
{
    public class LoadingViewModel : ViewModelBase
    {
        private LoadingModel _LoadingModel;
        public LoadingModel LoadingModel
        {
            get { return _LoadingModel; }
            set
            {
                if (_LoadingModel != value)
                {
                    _LoadingModel = value;
                    RaisePropertyChanged("LoadingModel");
                }
            }
        }

        public LoadingViewModel()
        {
            LoadingModel = new LoadingModel();
        }
       

    }
}
