using GalaSoft.MvvmLight;
using ProstMain.ViewModel;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProstMain.Model
{
    public class PopupBuildStatusModel : ObservableObject
    {
        /// <summary>
        /// Build Popup Open Flag
        /// </summary>
        private bool _IsBuildStatusPopupOpen;
        public bool IsBuildStatusPopupOpen
        {
            get { return _IsBuildStatusPopupOpen; }
            set
            {
                if (_IsBuildStatusPopupOpen != value)
                {
                    _IsBuildStatusPopupOpen = value;
                    RaisePropertyChanged("IsBuildStatusPopupOpen");
                }
            }
        }
        /// <summary>
        /// HW Image Resource Path
        /// </summary>
        private string _IsBuildTestHWImagePath;
        public string IsBuildTestHWImagePath
        {
            get { return _IsBuildTestHWImagePath; }
            set
            {
                if (_IsBuildTestHWImagePath != value)
                {
                    _IsBuildTestHWImagePath = value;
                    RaisePropertyChanged("IsBuildTestHWImagePath");
                }
            }
        }
        /// <summary>
        /// SW Image Resource Path
        /// </summary>
        private string _IsBuildTestSWImagePath;
        public string IsBuildTestSWImagePath
        {
            get { return _IsBuildTestSWImagePath; }
            set
            {
                if (_IsBuildTestSWImagePath != value)
                {
                    _IsBuildTestSWImagePath = value;
                    RaisePropertyChanged("IsBuildTestSWImagePath");
                }
            }
        }
        /// <summary>
        /// Compiler Image Resource Path
        /// </summary>
        private string _IsBuildTestCompileImagePath;
        public string IsBuildTestCompileImagePath
        {
            get { return _IsBuildTestCompileImagePath; }
            set
            {
                if (_IsBuildTestCompileImagePath != value)
                {
                    _IsBuildTestCompileImagePath = value;
                    RaisePropertyChanged("IsBuildTestCompileImagePath");
                }
            }
        }
        /// <summary>
        /// ELF Image Resource Path
        /// </summary>
        private string _IsBuildTestELFImagePath;
        public string IsBuildTestELFImagePath
        {
            get { return _IsBuildTestELFImagePath; }
            set
            {
                if (_IsBuildTestELFImagePath != value)
                {
                    _IsBuildTestELFImagePath = value;
                    RaisePropertyChanged("IsBuildTestELFImagePath");
                }
            }
        }
        /// <summary>
        /// HW Setting Check Value
        /// </summary>
        private int _IsHWSettingValue;
        public int IsHWSettingValue
        {
            get { return _IsHWSettingValue; }
            set
            {
                if (_IsHWSettingValue != value)
                {
                    _IsHWSettingValue = value;
                    if (_IsHWSettingValue == Common.Common.DEFAULT)
                        IsBuildTestHWImagePath = "/ProstMain;component/Resources/TargetHW_Icon_Normal.png";
                    else if (_IsHWSettingValue == Common.Common.PASS)
                        IsBuildTestHWImagePath = "/ProstMain;component/Resources/TargetHW_Icon_Pass.png";
                    else if (_IsHWSettingValue == Common.Common.FAIL)
                        IsBuildTestHWImagePath = "/ProstMain;component/Resources/TargetHW_Icon_Fail.png";
                    RaisePropertyChanged("IsHWSettingValue");
                }
            }
        }
        /// <summary>
        /// SW Setting Check Value
        /// </summary>
        private int _IsSWSettingValue;
        public int IsSWSettingValue
        {
            get { return _IsSWSettingValue; }
            set
            {
                if (_IsSWSettingValue != value)
                {
                    _IsSWSettingValue = value;

                    if (_IsSWSettingValue == Common.Common.DEFAULT)
                        IsBuildTestSWImagePath = "/ProstMain;component/Resources/TargetSW_Icon_Normal.png";
                    else if (_IsSWSettingValue == Common.Common.PASS)
                        IsBuildTestSWImagePath = "/ProstMain;component/Resources/TargetSW_Icon_Pass.png";
                    else if (_IsSWSettingValue == Common.Common.FAIL)
                        IsBuildTestSWImagePath = "/ProstMain;component/Resources/TargetSW_Icon_Fail.png";

                    RaisePropertyChanged("IsSWSettingValue");
                }
            }
        }
        /// <summary>
        /// Compiler Setting Check Value
        /// </summary>
        private int _IsCompilerSettingValue;
        public int IsCompilerSettingValue
        {
            get { return _IsCompilerSettingValue; }
            set
            {
                if (_IsCompilerSettingValue != value)
                {
                    _IsCompilerSettingValue = value;

                    if (_IsCompilerSettingValue == Common.Common.DEFAULT)
                        IsBuildTestCompileImagePath = "/ProstMain;component/Resources/Compiler_Icon_Normal.png";
                    else if (_IsCompilerSettingValue == Common.Common.PASS)
                        IsBuildTestCompileImagePath = "/ProstMain;component/Resources/Compiler_Icon_Pass.png";
                    else if (_IsCompilerSettingValue == Common.Common.FAIL)
                        IsBuildTestCompileImagePath = "/ProstMain;component/Resources/Compiler_Icon_Fail.png";

                    RaisePropertyChanged("IsCompilerSettingValue");
                }
            }
        }
        /// <summary>
        /// ELF Setting Check Value
        /// </summary>
        private int _IsElfSettingValue;
        public int IsElfSettingValue
        {
            get { return _IsElfSettingValue; }
            set
            {
                if (_IsElfSettingValue != value)
                {
                    _IsElfSettingValue = value;

                    if (_IsElfSettingValue == Common.Common.DEFAULT)
                    {
                        ViewModelLocator.ToolbarVM.ToolbarModel.IsTestStartEnable = false;
                        IsBuildTestELFImagePath = "/ProstMain;component/Resources/ELF_Icon_Normal.png";
                    }
                    else if (_IsElfSettingValue == Common.Common.PASS)
                    {
                        IsBuildTestELFImagePath = "/ProstMain;component/Resources/ELF_Icon_Pass.png";
                    }
                    else if (_IsElfSettingValue == Common.Common.FAIL)
                    {
                        ViewModelLocator.ToolbarVM.ToolbarModel.IsTestStartEnable = false;
                        IsBuildTestELFImagePath = "/ProstMain;component/Resources/ELF_Icon_Fail.png";
                    }
                    RaisePropertyChanged("IsElfSettingValue");
                }
            }
        }
        /// <summary>
        /// Build Start Flag
        /// </summary>
        private bool _IsBuildStart;
        public bool IsBuildStart
        {
            get { return _IsBuildStart; }
            set
            {
                if (_IsBuildStart != value)
                {
                    _IsBuildStart = value;
                    RaisePropertyChanged("IsBuildStart");
                }
            }
        }
        /// <summary>
        /// Build Progress Value
        /// </summary>
        private double _ElfBuildProgress;
        public double ElfBuildProgress
        {
            get { return _ElfBuildProgress; }
            set
            {
                if (_ElfBuildProgress != value)
                {
                    _ElfBuildProgress = value;
                    RaisePropertyChanged("ElfBuildProgress");
                }
            }
        }
        /// <summary>
        /// Direct ELF Path Value
        /// </summary>
        private string _DirectELFFilePath;
        public string DirectELFFilePath
        {
            get { return _DirectELFFilePath; }
            set
            {
                if (_DirectELFFilePath != value)
                {
                    _DirectELFFilePath = value;
                    RaisePropertyChanged("DirectELFFilePath");
                }
            }
        }
        /// <summary>
        /// Direct MapFile Path Value
        /// </summary>
        private string _DirectMapFilePath;
        public string DirectMapFilePath
        {
            get { return _DirectMapFilePath; }
            set
            {
                if (_DirectMapFilePath != value)
                {
                    _DirectMapFilePath = value;
                    RaisePropertyChanged("DirectMapFilePath");
                }
            }
        }
        public PopupBuildStatusModel()
        {

        }
        public void Init()
        {
            IsHWSettingValue = Common.Common.DEFAULT;
            IsSWSettingValue = Common.Common.DEFAULT;
            IsCompilerSettingValue = Common.Common.DEFAULT;
            IsElfSettingValue = Common.Common.DEFAULT;

            IsBuildTestCompileImagePath = "/ProstMain;component/Resources/Compiler_Icon_Normal.png";
            IsBuildTestSWImagePath = "/ProstMain;component/Resources/TargetSW_Icon_Normal.png";
            IsBuildTestHWImagePath = "/ProstMain;component/Resources/TargetHW_Icon_Normal.png";
            IsBuildTestELFImagePath = "/ProstMain;component/Resources/ELF_Icon_Normal.png";
        }
    }
}
