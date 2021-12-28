using GalaSoft.MvvmLight;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProstMain.Model
{
    public class PopupTestStatusModel : ObservableObject
    {
        private bool _IsTestStatusPopupOpen;
        public bool IsTestStatusPopupOpen
        {
            get { return _IsTestStatusPopupOpen; }
            set
            {
                if (_IsTestStatusPopupOpen != value)
                {
                    _IsTestStatusPopupOpen = value;
                    RaisePropertyChanged("IsTestStatusPopupOpen");
                }
            }
        }
        private string _TestcaseProgressText;
        public string TestcaseProgressText
        {
            get { return _TestcaseProgressText; }
            set
            {
                if (_TestcaseProgressText != value)
                {
                    _TestcaseProgressText = value;
                    RaisePropertyChanged("TestcaseProgressText");
                }
            }
        }
        private bool _IsTestStart;
        public bool IsTestStart
        {
            get { return _IsTestStart; }
            set
            {
                if (_IsTestStart != value)
                {
                    _IsTestStart = value;
                    RaisePropertyChanged("IsTestStart");
                }
            }
        }
        private double _TestStatusProgress;
        public double TestStatusProgress
        {
            get { return _TestStatusProgress; }
            set
            {
                if (_TestStatusProgress != value)
                {
                    _TestStatusProgress = value;
                    RaisePropertyChanged("TestStatusProgress");
                }
            }
        }
        private string _TestStatusText;
        public string TestStatusText
        {
            get { return _TestStatusText; }
            set
            {
                if (_TestStatusText != value)
                {
                    _TestStatusText = value;
                    RaisePropertyChanged("TestStatusText");
                }
            }
        }
        private double _TestAnalysysProgress;
        public double TestAnalysysProgress
        {
            get { return _TestAnalysysProgress; }
            set
            {
                if (_TestAnalysysProgress != value)
                {
                    _TestAnalysysProgress = value;
                    RaisePropertyChanged("TestAnalysysProgress");
                }
            }
        }
        private double _TestMergeDataProgress;
        public double TestMergeDataProgress
        {
            get { return _TestMergeDataProgress; }
            set
            {
                if (_TestMergeDataProgress != value)
                {
                    _TestMergeDataProgress = value;
                    RaisePropertyChanged("TestMergeDataProgress");
                }
            }
        }
        private int _TestStateMode;
        public int TestStateMode
        {
            get { return _TestStateMode; }
            set
            {
                if (_TestStateMode != value)
                {
                    _TestStateMode = value;
                    RaisePropertyChanged("TestStateMode");
                }
            }
        }
        /// <summary>
        /// ELF Setting Check Value
        /// </summary>
        private int _IsTestSettingValue;
        public int IsTestSettingValue
        {
            get { return _IsTestSettingValue; }
            set
            {
                if (_IsTestSettingValue != value)
                {
                    _IsTestSettingValue = value;
                    RaisePropertyChanged("IsTestSettingValue");
                }
            }
        }
    }
}
