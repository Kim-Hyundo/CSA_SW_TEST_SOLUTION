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
    public class TargetHWSettingModel : ObservableObject
    {
        /// <summary>
        /// UserName 정보
        /// </summary>
        private string _LicenseData_UserName;
        public string LicenseData_UserName
        {
            get { return _LicenseData_UserName; }
            set
            {
                if (_LicenseData_UserName != value)
                {
                    _LicenseData_UserName = value;
                    RaisePropertyChanged("LicenseData_UserName");
                }
            }
        }
        /// <summary>
        /// LicenseIssuedDate 정보
        /// </summary>
        private string _LicenseData_IssuedDate;
        public string LicenseData_IssuedDate
        {
            get { return _LicenseData_IssuedDate; }
            set
            {
                if (_LicenseData_IssuedDate != value)
                {
                    _LicenseData_IssuedDate = value;
                    RaisePropertyChanged("LicenseData_IssuedDate");
                }
            }
        }
        /// <summary>
        /// LicenseExpirationDate 정보
        /// </summary>
        private string _LicenseData_ExpirationDate;
        public string LicenseData_ExpirationDate
        {
            get { return _LicenseData_ExpirationDate; }
            set
            {
                if (_LicenseData_ExpirationDate != value)
                {
                    _LicenseData_ExpirationDate = value;
                    RaisePropertyChanged("LicenseData_ExpirationDate");
                }
            }
        }
        /// <summary>
        /// TRACE32 IP 정보
        /// </summary>
        private string _Trace32IPAddress;
        public string Trace32IPAddress
        {
            get { return _Trace32IPAddress; }
            set
            {
                if (_Trace32IPAddress != value)
                {
                    _Trace32IPAddress = value;
                    RaisePropertyChanged("Trace32IPAddress");
                }
            }
        }
        /// <summary>
        /// TRACE32의 버전
        /// </summary>
        private string _Trace32Version;
        public string Trace32Version
        {
            get { return _Trace32Version; }
            set
            {
                if (_Trace32Version != value)
                {
                    _Trace32Version = value;
                    RaisePropertyChanged("Trace32Version");
                }
            }
        }
        /// <summary>
        /// TRACE32 Install Path
        /// </summary>
        private string _Trace32InstallPath;
        public string Trace32InstallPath
        {
            get { return _Trace32InstallPath; }
            set
            {
                if (_Trace32InstallPath != value)
                {
                    _Trace32InstallPath = value;
                    RaisePropertyChanged("Trace32InstallPath");
                }
            }
        }
        /// <summary>
        /// TRACE32 License
        /// </summary>
        private string _Trace32License;
        public string Trace32License
        {
            get { return _Trace32License; }
            set
            {
                if (_Trace32License != value)
                {
                    _Trace32License = value;
                    RaisePropertyChanged("Trace32License");
                }
            }
        }
        /// <summary>
        /// CPU Name
        /// </summary>
        private string _CpuName;
        public string CpuName
        {
            get { return _CpuName; }
            set
            {
                if (_CpuName != value)
                {
                    _CpuName = value;
                    RaisePropertyChanged("CpuName");
                    ViewModelLocator.TargetHWSettingVM.RefreshCore();
                }
            }
        }

        /// <summary>
        /// CPU Manufacture Name
        /// </summary>
        private string _ManufacturerName;
        public string ManufacturerName
        {
            get { return _ManufacturerName; }
            set
            {
                if (_ManufacturerName != value)
                {
                    _ManufacturerName = value;
                    RaisePropertyChanged("ManufacturerName");
                    ViewModelLocator.TargetHWSettingVM.RefreshCPU();
                }
            }
        }
        /// <summary>
        /// CPU Clock
        /// </summary>
        private double _CpuClock;
        public double CpuClock
        {
            get { return _CpuClock; }
            set
            {
                if (_CpuClock != value)
                {
                    _CpuClock = value;
                    RaisePropertyChanged("CpuClock");
                }
            }
        }
        /// <summary>
        /// CPU Frequency
        /// </summary>
        private double _Frequency;
        public double Frequency
        {
            get { return _Frequency; }
            set
            {
                if (_Frequency != value)
                {
                    _Frequency = value;
                    RaisePropertyChanged("Frequency");
                }
            }
        }
        /// <summary>
        /// Cache Value
        /// </summary>
        private bool _PCache;
        public bool PCache
        {
            get { return _PCache; }
            set
            {
                if (_PCache != value)
                {
                    _PCache = value;
                    RaisePropertyChanged("PCache");
                }
            }
        }
        /// <summary>
        /// Cache Value
        /// </summary>
        private bool _DCache;
        public bool DCache
        {
            get { return _DCache; }
            set
            {
                if (_DCache != value)
                {
                    _DCache = value;
                    RaisePropertyChanged("DCache");
                }
            }
        }
        /// <summary>
        /// Target HW Drawer Open Flag
        /// </summary>
        private bool _IsOpenTargetSetting;
        public bool IsOpenTargetSetting
        {
            get { return _IsOpenTargetSetting; }
            set
            {
                if (_IsOpenTargetSetting != value)
                {
                    _IsOpenTargetSetting = value;
                    RaisePropertyChanged("IsOpenTargetSetting");
                }
            }
        }
        /// <summary>
        /// Guide Line Visible Flag
        /// </summary>
        private string _IsVisibleCPUNameGuild;
        public string IsVisibleCPUNameGuild
        {
            get { return _IsVisibleCPUNameGuild; }
            set
            {
                if (_IsVisibleCPUNameGuild != value)
                {
                    _IsVisibleCPUNameGuild = value;
                    RaisePropertyChanged("IsVisibleCPUNameGuild");
                }
            }
        }
        /// <summary>
        /// Time Calc Timer Tick
        /// </summary>
        private double _TimerTick;
        public double TimerTick
        {
            get { return _TimerTick; }
            set
            {
                if (_TimerTick != value)
                {
                    _TimerTick = value;
                    RaisePropertyChanged("TimerTick");
                }
            }
        }
        /// <summary>
        /// TRACE32 Execution Mode Value
        /// </summary>
        private bool _IsTRACE32ForgroundExecute = true;
        public bool IsTRACE32ForgroundExecute
        {
            get { return _IsTRACE32ForgroundExecute; }
            set
            {
                if (_IsTRACE32ForgroundExecute != value)
                {
                    _IsTRACE32ForgroundExecute = value;
                    RaisePropertyChanged("IsTRACE32ForgroundExecute");
                }
            }
        }
        public TargetHWSettingModel()
        {
            TimerTick = 10.0;
        }
    }
}
