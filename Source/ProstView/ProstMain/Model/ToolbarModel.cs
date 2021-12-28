using GalaSoft.MvvmLight;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProstMain.Model
{
    public class ToolbarModel : ObservableObject
    {
        /// <summary>
        /// 테스트 중 Toolbar 사용을 막는 Flag
        /// </summary>
        private bool _IsToolbarEnable;
        public bool IsToolbarEnable
        {
            get { return _IsToolbarEnable; }
            set
            {
                if (_IsToolbarEnable != value)
                {
                    _IsToolbarEnable = value;
                    RaisePropertyChanged("IsToolbarEnable");
                }
            }
        }
        /// <summary>
        /// Guide Line Show Flag
        /// </summary>
        private string _IsVisibleBuildGuild;
        public string IsVisibleBuildGuild
        {
            get { return _IsVisibleBuildGuild; }
            set
            {
                if (_IsVisibleBuildGuild != value)
                {
                    _IsVisibleBuildGuild = value;
                    RaisePropertyChanged("IsVisibleBuildGuild");
                }
            }
        }
        /// <summary>
        /// Guide Line Show Flag
        /// </summary>
        private string _IsVisibleTestCaseGuild;
        public string IsVisibleTestCaseGuild
        {
            get { return _IsVisibleTestCaseGuild; }
            set
            {
                if (_IsVisibleTestCaseGuild != value)
                {
                    _IsVisibleTestCaseGuild = value;
                    RaisePropertyChanged("IsVisibleTestCaseGuild");
                }
            }
        }
        /// <summary>
        /// Guide Line Show Flag
        /// </summary>
        private string _IsVisibleTestStartGuild;
        public string IsVisibleTestStartGuild
        {
            get { return _IsVisibleTestStartGuild; }
            set
            {
                if (_IsVisibleTestStartGuild != value)
                {
                    _IsVisibleTestStartGuild = value;
                    RaisePropertyChanged("IsVisibleTestStartGuild");
                }
            }
        }
        /// <summary>
        /// New Project Image Resource Path
        /// </summary>
        private string _NewIconImagePath;
        public string NewIconImagePath
        {
            get { return _NewIconImagePath; }
            set
            {
                if (_NewIconImagePath != value)
                {
                    _NewIconImagePath = value;
                    RaisePropertyChanged("NewIconImagePath");
                }
            }
        }
        /// <summary>
        /// Save Project Image Resource Path
        /// </summary>
        private string _SaveIconImagePath;
        public string SaveIconImagePath
        {
            get { return _SaveIconImagePath; }
            set
            {
                if (_SaveIconImagePath != value)
                {
                    _SaveIconImagePath = value;
                    RaisePropertyChanged("SaveIconImagePath");
                }
            }
        }
        /// <summary>
        /// Build Image Resource Path
        /// </summary>
        private string _BuildIconImagePath;
        public string BuildIconImagePath
        {
            get { return _BuildIconImagePath; }
            set
            {
                if (_BuildIconImagePath != value)
                {
                    _BuildIconImagePath = value;
                    RaisePropertyChanged("BuildIconImagePath");
                }
            }
        }
        /// <summary>
        /// Test Parser Image Resource Path
        /// </summary>
        private string _TestCaseIconImagePath;
        public string TestCaseIconImagePath
        {
            get { return _TestCaseIconImagePath; }
            set
            {
                if (_TestCaseIconImagePath != value)
                {
                    _TestCaseIconImagePath = value;
                    RaisePropertyChanged("TestCaseIconImagePath");
                }
            }
        }
        /// <summary>
        /// Test Image Resource Path
        /// </summary>
        private string _TestIconImagePath;
        public string TestIconImagePath
        {
            get { return _TestIconImagePath; }
            set
            {
                if (_TestIconImagePath != value)
                {
                    _TestIconImagePath = value;
                    RaisePropertyChanged("TestIconImagePath");
                }
            }
        }
        private string _AutoTestIconImagePath;
        public string AutoTestIconImagePath
        {
            get { return _AutoTestIconImagePath; }
            set
            {
                if (_AutoTestIconImagePath != value)
                {
                    _AutoTestIconImagePath = value;
                    RaisePropertyChanged("AutoTestIconImagePath");
                }
            }
        }
        /// <summary>
        /// Report Image Resource Path
        /// </summary>
        private string _ReportIconImagePath;
        public string ReportIconImagePath
        {
            get { return _ReportIconImagePath; }
            set
            {
                if (_ReportIconImagePath != value)
                {
                    _ReportIconImagePath = value;
                    RaisePropertyChanged("ReportIconImagePath");
                }
            }
        }
        /// <summary>
        /// Build Mode :: ALREADY_ELF / STANDARD
        /// </summary>
        private int _BuildMode;
        public int BuildMode
        {
            get { return _BuildMode; }
            set
            {
                if (_BuildMode != value)
                {
                    _BuildMode = value;
                    RaisePropertyChanged("BuildMode");
                }
            }
        }
        /// <summary>
        /// 테스트 자동 시작에 대한 모드를 저장
        /// </summary>
        private int _TestStartMode;
        public int TestStartMode
        {
            get { return _TestStartMode; }
            set
            {
                if (_TestStartMode != value)
                {
                    _TestStartMode = value;
                    RaisePropertyChanged("TestStartMode");
                }
            }
        }
        private bool _IsTestStartEnable;
        public bool IsTestStartEnable
        {
            get { return _IsTestStartEnable; }
            set
            {
                if (_IsTestStartEnable != value)
                {
                    _IsTestStartEnable = value;
                    RaisePropertyChanged("IsTestStartEnable");
                }
            }
        }
        public ToolbarModel()
        {
            IsToolbarEnable = true;
            NewIconImagePath = "/ProstMain;component/Resources/New_Icon.png";
            SaveIconImagePath = "/ProstMain;component/Resources/Save_Icon.png";
            BuildIconImagePath = "/ProstMain;component/Resources/Build_Icon.png";
            TestCaseIconImagePath = "/ProstMain;component/Resources/TestCase_Icon_Toolbar.png";
            TestIconImagePath = "/ProstMain;component/Resources/Test_Icon.png";
            ReportIconImagePath = "/ProstMain;component/Resources/Report_Icon.png";
            AutoTestIconImagePath = "/ProstMain;component/Resources/AutoTest_Icon.png";
        }
    }
}
