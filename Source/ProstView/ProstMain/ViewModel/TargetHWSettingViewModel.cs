using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using ProstMain.Model;
using ProstMain.Util;
using ProstMain.View;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;

namespace ProstMain.ViewModel
{
    public class TargetHWSettingViewModel : ViewModelBase
    {

        private TargetHWSettingModel _TargetHWSettingModel;
        public TargetHWSettingModel TargetHWSettingModel
        {
            get { return _TargetHWSettingModel; }
            set
            {
                if(_TargetHWSettingModel != value)
                {
                    _TargetHWSettingModel = value;
                    RaisePropertyChanged("TargetHWSettingModel");
                }
            }
        }
        private ObservableCollection<string> _CPUList;
        public ObservableCollection<string> CPUList
        {
            get { return _CPUList; }
            set
            {
                if (_CPUList != value)
                {
                    _CPUList = value;
                    RaisePropertyChanged("CPUList");
                }
            }
        }

        private ObservableCollection<bool> _CoreList;
        public ObservableCollection<bool> CoreList
        {
            get { return _CoreList; }
            set
            {
                if (_CoreList != value)
                {
                    _CoreList = value;
                    RaisePropertyChanged("CoreList");
                }
            }
        }

        private ObservableCollection<string> _CoreNameList;
        public ObservableCollection<string> CoreNameList
        {
            get { return _CoreNameList; }
            set
            {
                if (_CoreNameList != value)
                {
                    _CoreNameList = value;
                    RaisePropertyChanged("CoreNameList");
                }
            }
        }

        private ObservableCollection<string> _ManufacturerList;
        public ObservableCollection<string> ManufacturerList
        {
            get { return _ManufacturerList; }
            set
            {
                if (_ManufacturerList != value)
                {
                    _ManufacturerList = value;
                    RaisePropertyChanged("ManufacturerList");
                }
            }
        }
        public TargetHWSettingViewModel()
        {
            TargetHWSettingModel = new TargetHWSettingModel();


            CoreList = new ObservableCollection<bool>();
            CoreList.Add(false);
            CoreList.Add(false);
            CoreList.Add(false);
            
            CPUList = new ObservableCollection<string>();
            CPUList.Add("tc23x");
            CPUList.Add("tc27x");
            CPUList.Add("tc29x");
            CPUList.Add("tc39x");

            CoreNameList = new ObservableCollection<string>();
            CoreNameList.Add("core0");
            CoreNameList.Add("core1");
            CoreNameList.Add("core2");

           

            ManufacturerList = new ObservableCollection<string>();
        }
        public void RefreshCPU()
        {
            CPUList.Clear();
            CoreList.Clear();
            CoreNameList.Clear();
            if (TargetHWSettingModel.ManufacturerName == null || TargetHWSettingModel.ManufacturerName == "")
            {
            }
            else
            {
                if (TargetHWSettingModel.ManufacturerName.Equals("AURIX"))
                {
                    CPUList.Add("tc23x");
                    CPUList.Add("tc27x");
                    CPUList.Add("tc29x");
                    CPUList.Add("tc39x");

                    CoreList.Add(false);
                    CoreList.Add(false);
                    CoreList.Add(false);
                    CoreNameList.Add("core0");
                    CoreNameList.Add("core1");
                    CoreNameList.Add("core2");

                }
                else if (TargetHWSettingModel.ManufacturerName.Equals("TraveoII"))
                {
                    CPUList.Add("CYT2B75CA(rev_d)");

                    CoreList.Add(false);
                    CoreList.Add(false);
                    CoreNameList.Add("cm0plus");
                    CoreNameList.Add("cm4");
                }
            }


            }
            public bool checkTargetHWData()
        {
            bool resultValue = true;
            if (TargetHWSettingModel.CpuName == null || TargetHWSettingModel.CpuName == "")
                resultValue = false;

            if (TargetHWSettingModel.CpuName == null || TargetHWSettingModel.CpuName.Equals(""))
                resultValue = false;

            if (!ViewModelLocator.TargetHWSettingVM.CoreList.Contains(true))
                resultValue = false;

            return resultValue;
        }
        public void RefreshCore()
        {
            CoreList.Clear();
            CoreNameList.Clear();

            if (TargetHWSettingModel.CpuName == null || TargetHWSettingModel.CpuName == "")
            {
            }
            else
            {
                if (TargetHWSettingModel.CpuName.Equals("tc29x") || TargetHWSettingModel.CpuName.Equals("tc27x"))
                {
                    CoreList.Add(false);
                    CoreList.Add(false);
                    CoreList.Add(false);
                    CoreNameList.Add("core0");
                    CoreNameList.Add("core1");
                    CoreNameList.Add("core2");
                }
                else if (TargetHWSettingModel.CpuName.Equals("tc23x"))
                {
                    CoreList.Add(false);
                    CoreList.Add(false);
                    CoreNameList.Add("core0");
                    CoreNameList.Add("core1");
                }
                else if (TargetHWSettingModel.CpuName.Equals("tc39x"))
                {
                    CoreList.Add(false);
                    CoreList.Add(false);
                    CoreList.Add(false);
                    CoreList.Add(false);
                    CoreList.Add(false);
                    CoreList.Add(false);
                    CoreNameList.Add("core0");
                    CoreNameList.Add("core1");
                    CoreNameList.Add("core2");
                    CoreNameList.Add("core3");
                    CoreNameList.Add("core4");
                    CoreNameList.Add("core5");
                }
                else if (TargetHWSettingModel.CpuName.Equals("CYT2B75CA(rev_d)"))
                {
                    CoreList.Add(false);
                    CoreList.Add(false);
                    CoreNameList.Add("cm0plus");
                    CoreNameList.Add("cm4");
                }/* 11/22 */
               
               
            }
            TargetHWSettingView.Instance.UpdateView();
        }

    }
}
