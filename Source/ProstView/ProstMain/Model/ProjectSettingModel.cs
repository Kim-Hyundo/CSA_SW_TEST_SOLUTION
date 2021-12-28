using GalaSoft.MvvmLight;
using Microsoft.Scripting.Utils;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Media.Animation;
using System.Windows.Threading;

namespace ProstMain.Model
{
    public class ProjectSettingModel : ObservableObject
    {
        /// <summary>
        ///  Tester Value
        /// </summary>
        private string _Tester;
        public string Tester
        {
            get { return _Tester; }
            set
            {
                if (_Tester != value)
                {
                    _Tester = value;
                    RaisePropertyChanged("Tester");
                }
            }
        }
        /// <summary>
        ///  Comment Value
        /// </summary>
        private string _Comment;
        public string Comment
        {
            get { return _Comment; }
            set
            {
                if (_Comment != value)
                {
                    _Comment = value;
                    RaisePropertyChanged("Comment");
                }
            }
        }
        /// <summary>
        ///  Test Date Value
        /// </summary>
        private string _TestDate;
        public string TestDate
        {
            get { return _TestDate; }
            set
            {
                if (_TestDate != value)
                {
                    _TestDate = value;
                    RaisePropertyChanged("TestDate");
                }
            }
        }
        /// <summary>
        /// Build 후 생성되는 폴더 Ex)C:\Users\CSA_DEV\Documents\Working\Prost_v2.0\Workspace\MANDOProject1007\Gen\20201116_asdsad
        /// </summary>
        private string _TimeCreateFolderPath;
        public string TimeCreateFolderPath
        {
            get { return _TimeCreateFolderPath; }
            set
            {
                if (_TimeCreateFolderPath != value)
                {
                    _TimeCreateFolderPath = value;
                    RaisePropertyChanged("TimeCreateFolderPath");
                }
            }
        }
        /// <summary>
        /// 테스트사양서 파싱 작업 시 생성되는 폴더 Ex)C:\Users\CSA_DEV\Documents\Working\Prost_v2.0\Workspace\MANDOProject1007\Gen\20201116_asdsad\IDC_Unit_Test_Template_시그널심볼단위_rev2_small_version
        /// </summary>
        private string _FolderByTestCasePath;
        public string FolderByTestCasePath
        {
            get { return _FolderByTestCasePath; }
            set
            {
                if (_FolderByTestCasePath != value)
                {
                    _FolderByTestCasePath = value;
                    RaisePropertyChanged("FolderByTestCasePath");
                }
            }
        }
        /// <summary>
        /// Histroy Last Information
        /// </summary>
        private string _LastTest_Time;
        public string LastTest_Time
        {
            get { return _LastTest_Time; }
            set
            {
                if (_LastTest_Time != value)
                {
                    _LastTest_Time = value;
                    RaisePropertyChanged("LastTest_Time");
                }
            }
        }
        /// <summary>
        /// Histroy Last Information
        /// </summary>
        private string _LastTest_Comment;
        public string LastTest_Comment
        {
            get { return _LastTest_Comment; }
            set
            {
                if (_LastTest_Comment != value)
                {
                    _LastTest_Comment = value;
                    RaisePropertyChanged("LastTest_Comment");
                }
            }
        }
        /// <summary>
        /// Histroy Last Information
        /// </summary>
        private string _LastTest_SWComponent;
        public string LastTest_SWComponent
        {
            get { return _LastTest_SWComponent; }
            set
            {
                if (_LastTest_SWComponent != value)
                {
                    _LastTest_SWComponent = value;
                    RaisePropertyChanged("LastTest_SWComponent");
                }
            }
        }
        /// <summary>
        /// Histroy Last Information
        /// </summary>
        private string _LastTest_TestCoverage_Pass;
        public string LastTest_TestCoverage_Pass
        {
            get { return _LastTest_TestCoverage_Pass; }
            set
            {
                if (_LastTest_TestCoverage_Pass != value)
                {
                    _LastTest_TestCoverage_Pass = value;
                    RaisePropertyChanged("LastTest_TestCoverage_Pass");
                }
            }
        }
        /// <summary>
        /// Histroy Last Information
        /// </summary>
        private string _LastTest_TestCoverage_Fail;
        public string LastTest_TestCoverage_Fail
        {
            get { return _LastTest_TestCoverage_Fail; }
            set
            {
                if (_LastTest_TestCoverage_Fail != value)
                {
                    _LastTest_TestCoverage_Fail = value;
                    RaisePropertyChanged("LastTest_TestCoverage_Fail");
                }
            }
        }

        /// <summary>
        /// Histroy Last Information
        /// </summary>
        private string _LastTest_MemUseage;
        public string LastTest_MemUseage
        {
            get { return _LastTest_MemUseage; }
            set
            {
                if (_LastTest_MemUseage != value)
                {
                    _LastTest_MemUseage = value;
                    RaisePropertyChanged("LastTest_MemUseage");
                }
            }
        }
        /// <summary>
        /// Histroy Last Information
        /// </summary>
        private string _LastTest_StatementCoverage;
        public string LastTest_StatementCoverage
        {
            get { return _LastTest_StatementCoverage; }
            set
            {
                if (_LastTest_StatementCoverage != value)
                {
                    _LastTest_StatementCoverage = value;
                    RaisePropertyChanged("LastTest_StatementCoverage");
                }
            }
        }
        /// <summary>
        /// Histroy Last Information
        /// </summary>
        private string _LastTest_FunctionCoverage;
        public string LastTest_FunctionCoverage
        {
            get { return _LastTest_FunctionCoverage; }
            set
            {
                if (_LastTest_FunctionCoverage != value)
                {
                    _LastTest_FunctionCoverage = value;
                    RaisePropertyChanged("LastTest_FunctionCoverage");
                }
            }
        }
        /// <summary>
        /// Histroy Last Information
        /// </summary>
        private string _LastTest_CallCoverage;
        public string LastTest_CallCoverage
        {
            get { return _LastTest_CallCoverage; }
            set
            {
                if (_LastTest_CallCoverage != value)
                {
                    _LastTest_CallCoverage = value;
                    RaisePropertyChanged("LastTest_CallCoverage");
                }
            }
        }
        /// <summary>
        /// Current Test Step Value
        /// </summary>
        private int _TestStep;
        public int TestStep
        {
            get { return _TestStep; }
            set
            {
                if (_TestStep != value)
                {
                    _TestStep = value;
                    RaisePropertyChanged("TestStep");
                }
            }
        }
        /// <summary>
        /// History Arrow GUI Grid Column Value
        /// </summary>
        private int _TestStepIconColumn;
        public int TestStepIconColumn
        {
            get { return _TestStepIconColumn; }
            set
            {
                if (_TestStepIconColumn != value)
                {
                    _TestStepIconColumn = value;
                    RaisePropertyChanged("TestStepIconColumn");
                }
            }
        }

        private string _SelectedSenario;
        public string SelectedSenario
        {
            get { return _SelectedSenario; }
            set
            {
                if (_SelectedSenario != value)
                {
                    _SelectedSenario = value;
                    RaisePropertyChanged("SelectedSenario");
                }
            }
        }
        private string _SelectedTestFolder;
        public string SelectedTestFolder
        {
            get { return _SelectedTestFolder; }
            set
            {
                if (_SelectedTestFolder != value)
                {
                    _SelectedTestFolder = value;
                    RaisePropertyChanged("SelectedTestFolder");
                }
            }
        }
        private string _SelectedBuildFolder;
        public string SelectedBuildFolder
        {
            get { return _SelectedBuildFolder; }
            set
            {
                if (_SelectedBuildFolder != value)
                {
                    _SelectedBuildFolder = value;
                    RaisePropertyChanged("SelectedBuildFolder");
                }
            }
        }
        private int _SelectedSenarioIndex;
        public int SelectedSenarioIndex
        {
            get { return _SelectedSenarioIndex; }
            set
            {
                if (_SelectedSenarioIndex != value)
                {
                    _SelectedSenarioIndex = value;
                    RaisePropertyChanged("SelectedSenarioIndex");
                }
            }
        }
        private int _SelectedTestFolderIndex;
        public int SelectedTestFolderIndex
        {
            get { return _SelectedTestFolderIndex; }
            set
            {
                if (_SelectedTestFolderIndex != value)
                {
                    _SelectedTestFolderIndex = value;
                    RaisePropertyChanged("SelectedTestFolderIndex");
                }
            }
        }
        private int _SelectedBuildFolderIndex;
        public int SelectedBuildFolderIndex
        {
            get { return _SelectedBuildFolderIndex; }
            set
            {
                if (_SelectedBuildFolderIndex != value)
                {
                    _SelectedBuildFolderIndex = value;
                    RaisePropertyChanged("SelectedBuildFolderIndex");
                }
            }
        }
        private string _IsRunningExcel;
        public string IsRunningExcel
        {
            get { return _IsRunningExcel; }
            set
            {
                if (_IsRunningExcel != value)
                {
                    _IsRunningExcel = value;
                    RaisePropertyChanged("IsRunningExcel");
                }
            }
        }

        private string _IsHistoryVisible;
        public string IsHistoryVisible
        {
            get { return _IsHistoryVisible; }
            set
            {
                if (_IsHistoryVisible != value)
                {
                    _IsHistoryVisible = value;
                    RaisePropertyChanged("IsHistoryVisible");
                }
            }
        }

        private string _IsHistoryVisibleTemp;
        public string IsHistoryVisibleTemp
        {
            get { return _IsHistoryVisibleTemp; }
            set
            {
                if (_IsHistoryVisibleTemp != value)
                {
                    _IsHistoryVisibleTemp = value;
                    RaisePropertyChanged("IsHistoryVisibleTemp");
                }
            }
        }
        private ObservableCollection<string> _TestSenarioList;
        public ObservableCollection<string> TestSenarioList
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
        private ObservableCollection<string> _TestFolderList;
        public ObservableCollection<string> TestFolderList
        {
            get { return _TestFolderList; }
            set
            {
                if (_TestFolderList != value)
                {
                    _TestFolderList = value;
                    RaisePropertyChanged("TestFolderList");
                }
            }
        }
        private ObservableCollection<string> _BuildFolderList;
        public ObservableCollection<string> BuildFolderList
        {
            get { return _BuildFolderList; }
            set
            {
                if (_BuildFolderList != value)
                {
                    _BuildFolderList = value;
                    RaisePropertyChanged("BuildFolderList");
                }
            }
        }
        public ProjectSettingModel()
        {
            IsRunningExcel = Common.Common.FALSE;
            TestSenarioList = new ObservableCollection<string>();
            TestFolderList = new ObservableCollection<string>();
            BuildFolderList = new ObservableCollection<string>();
        }


    }
}
