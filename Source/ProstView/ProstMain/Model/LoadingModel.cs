using GalaSoft.MvvmLight;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProstMain.Model
{
    public class LoadingModel : ObservableObject
    {
        /// <summary>
        /// Loading View Text
        /// </summary>
        private string _LoadingText;
        public string LoadingText
        {
            get { return _LoadingText; }
            set
            {
                if (_LoadingText != value)
                {
                    _LoadingText = value;
                    RaisePropertyChanged("LoadingText");
                }
            }
        }
        /// <summary>
        /// Loading Progress
        /// </summary>
        private int _LoadingProgress;
        public int LoadingProgress
        {
            get { return _LoadingProgress; }
            set
            {
                if (_LoadingProgress != value)
                {
                    _LoadingProgress = value;
                    RaisePropertyChanged("LoadingProgress");
                }
            }
        }

        public LoadingModel()
        {
            LoadingText = "Initialize...";
        }
    }
}

