using GalaSoft.MvvmLight;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Documents;

namespace ProstMain.Model
{
    public class ProjectExplorerModel : ObservableObject
    {
        /// <summary>
        /// Project Model List
        /// </summary>
        ObservableCollection<ProjectExplorerListModel> _ProjectExplorerModelList = new ObservableCollection<ProjectExplorerListModel>();
        public ObservableCollection<ProjectExplorerListModel> ProjectExplorerModelList
        {
            get { return _ProjectExplorerModelList; }
            set { _ProjectExplorerModelList = value; RaisePropertyChanged("ProjectExplorerModelList"); }

        }

        ProjectExplorerListModel _SelectedProjectExplorerModel;
        public ProjectExplorerListModel SelectedProjectExplorerModel
        {
            get { return _SelectedProjectExplorerModel; }
            set { _SelectedProjectExplorerModel = value; RaisePropertyChanged("SelectedProjectExplorerModel"); }

        }
        /// <summary>
        /// .csa파일 Import시 속성값 정보 존재 여부
        /// </summary>
        private bool _IsExistImportComment;
        public bool IsExistImportComment
        {
            get { return _IsExistImportComment; }
            set
            {
                if (_IsExistImportComment != value)
                {
                    _IsExistImportComment = value;
                    RaisePropertyChanged("IsExistImportComment");
                }
            }
        }

        /// <summary>
        /// .csa파일 Import시 속성값 정보 존재 여부
        /// </summary>
        private bool _IsExistImportTester;
        public bool IsExistImportTester
        {
            get { return _IsExistImportTester; }
            set
            {
                if (_IsExistImportTester != value)
                {
                    _IsExistImportTester = value;
                    RaisePropertyChanged("IsExistImportTester");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import시 속성값 정보 존재 여부
        /// </summary>
        private bool _IsExistImportTestStatement;
        public bool IsExistImportTestStatement
        {
            get { return _IsExistImportTestStatement; }
            set
            {
                if (_IsExistImportTestStatement != value)
                {
                    _IsExistImportTestStatement = value;
                    RaisePropertyChanged("IsExistImportTestStatement");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import시 속성값 정보 존재 여부
        /// </summary>
        private bool _IsExistImportFrequency;
        public bool IsExistImportFrequency
        {
            get { return _IsExistImportFrequency; }
            set
            {
                if (_IsExistImportFrequency != value)
                {
                    _IsExistImportFrequency = value;
                    RaisePropertyChanged("IsExistImportFrequency");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import시 속성값 정보 존재 여부
        /// </summary>
        private bool _IsExistImportLogLevel;
        public bool IsExistImportLogLevel
        {
            get { return _IsExistImportLogLevel; }
            set
            {
                if (_IsExistImportLogLevel != value)
                {
                    _IsExistImportLogLevel = value;
                    RaisePropertyChanged("IsExistImportLogLevel");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import시 속성값 정보 존재 여부
        /// </summary>
        private bool _IsExistImportResolution;
        public bool IsExistImportResolution
        {
            get { return _IsExistImportResolution; }
            set
            {
                if (_IsExistImportResolution != value)
                {
                    _IsExistImportResolution = value;
                    RaisePropertyChanged("IsExistImportResolution");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import시 속성값 정보 존재 여부
        /// </summary>
        private bool _IsExistImportCompilerType;
        public bool IsExistImportCompilerType
        {
            get { return _IsExistImportCompilerType; }
            set
            {
                if (_IsExistImportCompilerType != value)
                {
                    _IsExistImportCompilerType = value;
                    RaisePropertyChanged("IsExistImportCompilerType");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import시 속성값 정보 존재 여부
        /// </summary>
        private bool _IsExistImportCompilerVersion;
        public bool IsExistImportCompilerVersion
        {
            get { return _IsExistImportCompilerVersion; }
            set
            {
                if (_IsExistImportCompilerVersion != value)
                {
                    _IsExistImportCompilerVersion = value;
                    RaisePropertyChanged("IsExistImportCompilerVersion");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import시 속성값 정보 존재 여부
        /// </summary>
        private bool _IsExistImportCpuName;
        public bool IsExistImportCpuName
        {
            get { return _IsExistImportCpuName; }
            set
            {
                if (_IsExistImportCpuName != value)
                {
                    _IsExistImportCpuName = value;
                    RaisePropertyChanged("IsExistImportCpuName");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import시 속성값 정보 존재 여부
        /// </summary>
        private bool _IsExistImportCoreIndex;
        public bool IsExistImportCoreIndex
        {
            get { return _IsExistImportCoreIndex; }
            set
            {
                if (_IsExistImportCoreIndex != value)
                {
                    _IsExistImportCoreIndex = value;
                    RaisePropertyChanged("IsExistImportCoreIndex");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import시 속성값 정보 존재 여부
        /// </summary>
        private bool _IsExistImportCpuClock;
        public bool IsExistImportCpuClock
        {
            get { return _IsExistImportCpuClock; }
            set
            {
                if (_IsExistImportCpuClock != value)
                {
                    _IsExistImportCpuClock = value;
                    RaisePropertyChanged("IsExistImportCpuClock");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import시 속성값 정보 존재 여부
        /// </summary>
        private bool _IsExistImportTestCasePath;
        public bool IsExistImportTestCasePath
        {
            get { return _IsExistImportTestCasePath; }
            set
            {
                if (_IsExistImportTestCasePath != value)
                {
                    _IsExistImportTestCasePath = value;
                    RaisePropertyChanged("IsExistImportTestCasePath");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import시 속성값 정보 존재 여부
        /// </summary>
        private bool _IsExistImportCompilerPath;
        public bool IsExistImportCompilerPath
        {
            get { return _IsExistImportCompilerPath; }
            set
            {
                if (_IsExistImportCompilerPath != value)
                {
                    _IsExistImportCompilerPath = value;
                    RaisePropertyChanged("IsExistImportCompilerPath");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import시 속성값 정보 존재 여부
        /// </summary>
        private bool _IsExistImportCompilerOption;
        public bool IsExistImportCompilerOption
        {
            get { return _IsExistImportCompilerOption; }
            set
            {
                if (_IsExistImportCompilerOption != value)
                {
                    _IsExistImportCompilerOption = value;
                    RaisePropertyChanged("IsExistImportCompilerOption");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import시 속성값 정보 존재 여부
        /// </summary>
        private bool _IsExistImportLinkerOption;
        public bool IsExistImportLinkerOption
        {
            get { return _IsExistImportLinkerOption; }
            set
            {
                if (_IsExistImportLinkerOption != value)
                {
                    _IsExistImportLinkerOption = value;
                    RaisePropertyChanged("IsExistImportLinkerOption");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import시 속성값 정보 존재 여부
        /// </summary>
        private bool _IsExistImportRunnableList;
        public bool IsExistImportRunnableList
        {
            get { return _IsExistImportRunnableList; }
            set
            {
                if (_IsExistImportRunnableList != value)
                {
                    _IsExistImportRunnableList = value;
                    RaisePropertyChanged("IsExistImportRunnableList");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import시 속성값 정보 존재 여부
        /// </summary>
        private bool _IsExistImportRunnableStubList;
        public bool IsExistImportRunnableStubList
        {
            get { return _IsExistImportRunnableStubList; }
            set
            {
                if (_IsExistImportRunnableStubList != value)
                {
                    _IsExistImportRunnableStubList = value;
                    RaisePropertyChanged("IsExistImportRunnableStubList");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import시 속성값 정보 존재 여부
        /// </summary>
        private bool _IsExistImportRegisterList;
        public bool IsExistImportRegisterList
        {
            get { return _IsExistImportRegisterList; }
            set
            {
                if (_IsExistImportRegisterList != value)
                {
                    _IsExistImportRegisterList = value;
                    RaisePropertyChanged("IsExistImportRegisterList");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import시 속성값 정보 존재 여부
        /// </summary>
        private bool _IsExistImportLibrary;
        public bool IsExistImportLibrary
        {
            get { return _IsExistImportLibrary; }
            set
            {
                if (_IsExistImportLibrary != value)
                {
                    _IsExistImportLibrary = value;
                    RaisePropertyChanged("IsExistImportLibrary");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import시 속성값 정보 존재 여부
        /// </summary>
        private bool _IsExistImportInitFunction;
        public bool IsExistImportInitFunction
        {
            get { return _IsExistImportInitFunction; }
            set
            {
                if (_IsExistImportInitFunction != value)
                {
                    _IsExistImportInitFunction = value;
                    RaisePropertyChanged("IsExistImportInitFunction");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import시 속성값 정보 존재 여부
        /// </summary>
        private bool _IsExistImportIncludePath;
        public bool IsExistImportIncludePath
        {
            get { return _IsExistImportIncludePath; }
            set
            {
                if (_IsExistImportIncludePath != value)
                {
                    _IsExistImportIncludePath = value;
                    RaisePropertyChanged("IsExistImportIncludePath");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import시 속성값 정보 존재 여부
        /// </summary>
        private bool _IsExistImportCopyPathList;
        public bool IsExistImportCopyPathList
        {
            get { return _IsExistImportCopyPathList; }
            set
            {
                if (_IsExistImportCopyPathList != value)
                {
                    _IsExistImportCopyPathList = value;
                    RaisePropertyChanged("IsExistImportCopyPathList");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import/Export시 속성값 Import/Export 여부
        /// </summary>
        private bool _IsCheckedComment;
        public bool IsCheckedComment
        {
            get { return _IsCheckedComment; }
            set
            {
                if (_IsCheckedComment != value)
                {
                    _IsCheckedComment = value;
                    RaisePropertyChanged("IsCheckedComment");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import/Export시 속성값 Import/Export 여부
        /// </summary>
        private bool _IsCheckedInitFunction;
        public bool IsCheckedInitFunction
        {
            get { return _IsCheckedInitFunction; }
            set
            {
                if (_IsCheckedInitFunction != value)
                {
                    _IsCheckedInitFunction = value;
                    RaisePropertyChanged("IsCheckedInitFunction");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import/Export시 속성값 Import/Export 여부
        /// </summary>
        private bool _IsCheckedLibrary;
        public bool IsCheckedLibrary
        {
            get { return _IsCheckedLibrary; }
            set
            {
                if (_IsCheckedLibrary != value)
                {
                    _IsCheckedLibrary = value;
                    RaisePropertyChanged("IsCheckedLibrary");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import/Export시 속성값 Import/Export 여부
        /// </summary>
        private bool _IsCheckedIncludePath;
        public bool IsCheckedIncludePath
        {
            get { return _IsCheckedIncludePath; }
            set
            {
                if (_IsCheckedIncludePath != value)
                {
                    _IsCheckedIncludePath = value;
                    RaisePropertyChanged("IsCheckedIncludePath");
                }
            }
        }
       
        /// <summary>
        /// .csa파일 Import/Export시 속성값 Import/Export 여부
        /// </summary>
        private bool _IsCheckedTester;
        public bool IsCheckedTester
        {
            get { return _IsCheckedTester; }
            set
            {
                if (_IsCheckedTester != value)
                {
                    _IsCheckedTester = value;
                    RaisePropertyChanged("IsCheckedTester");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import/Export시 속성값 Import/Export 여부
        /// </summary>
        private bool _IsCheckedTestStatement;
        public bool IsCheckedTestStatement
        {
            get { return _IsCheckedTestStatement; }
            set
            {
                if (_IsCheckedTestStatement != value)
                {
                    _IsCheckedTestStatement = value;
                    RaisePropertyChanged("IsCheckedTestStatement");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import/Export시 속성값 Import/Export 여부
        /// </summary>
        private bool _IsCheckedFrequency;
        public bool IsCheckedFrequency
        {
            get { return _IsCheckedFrequency; }
            set
            {
                if (_IsCheckedFrequency != value)
                {
                    _IsCheckedFrequency = value;
                    RaisePropertyChanged("IsCheckedFrequency");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import/Export시 속성값 Import/Export 여부
        /// </summary>
        private bool _IsCheckedLogLevel;
        public bool IsCheckedLogLevel
        {
            get { return _IsCheckedLogLevel; }
            set
            {
                if (_IsCheckedLogLevel != value)
                {
                    _IsCheckedLogLevel = value;
                    RaisePropertyChanged("IsCheckedLogLevel");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import/Export시 속성값 Import/Export 여부
        /// </summary>
        private bool _IsCheckedResolution;
        public bool IsCheckedResolution
        {
            get { return _IsCheckedResolution; }
            set
            {
                if (_IsCheckedResolution != value)
                {
                    _IsCheckedResolution = value;
                    RaisePropertyChanged("IsCheckedResolution");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import/Export시 속성값 Import/Export 여부
        /// </summary>
        private bool _IsCheckedCompilerType;
        public bool IsCheckedCompilerType
        {
            get { return _IsCheckedCompilerType; }
            set
            {
                if (_IsCheckedCompilerType != value)
                {
                    _IsCheckedCompilerType = value;
                    RaisePropertyChanged("IsCheckedCompilerType");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import/Export시 속성값 Import/Export 여부
        /// </summary>
        private bool _IsCheckedCompilerVersion;
        public bool IsCheckedCompilerVersion
        {
            get { return _IsCheckedCompilerVersion; }
            set
            {
                if (_IsCheckedCompilerVersion != value)
                {
                    _IsCheckedCompilerVersion = value;
                    RaisePropertyChanged("IsCheckedCompilerVersion");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import/Export시 속성값 Import/Export 여부
        /// </summary>
        private bool _IsCheckedCpuName;
        public bool IsCheckedCpuName
        {
            get { return _IsCheckedCpuName; }
            set
            {
                if (_IsCheckedCpuName != value)
                {
                    _IsCheckedCpuName = value;
                    RaisePropertyChanged("IsCheckedCpuName");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import/Export시 속성값 Import/Export 여부
        /// </summary>
        private bool _IsCheckedCoreIndex;
        public bool IsCheckedCoreIndex
        {
            get { return _IsCheckedCoreIndex; }
            set
            {
                if (_IsCheckedCoreIndex != value)
                {
                    _IsCheckedCoreIndex = value;
                    RaisePropertyChanged("IsCheckedCoreIndex");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import/Export시 속성값 Import/Export 여부
        /// </summary>
        private bool _IsCheckedCpuClock;
        public bool IsCheckedCpuClock
        {
            get { return _IsCheckedCpuClock; }
            set
            {
                if (_IsCheckedCpuClock != value)
                {
                    _IsCheckedCpuClock = value;
                    RaisePropertyChanged("IsCheckedCpuClock");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import/Export시 속성값 Import/Export 여부
        /// </summary>
        private bool _IsCheckedTestCasePath;
        public bool IsCheckedTestCasePath
        {
            get { return _IsCheckedTestCasePath; }
            set
            {
                if (_IsCheckedTestCasePath != value)
                {
                    _IsCheckedTestCasePath = value;
                    RaisePropertyChanged("IsCheckedTestCasePath");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import/Export시 속성값 Import/Export 여부
        /// </summary>
        private bool _IsCheckedCompilerPath;
        public bool IsCheckedCompilerPath
        {
            get { return _IsCheckedCompilerPath; }
            set
            {
                if (_IsCheckedCompilerPath != value)
                {
                    _IsCheckedCompilerPath = value;
                    RaisePropertyChanged("IsCheckedCompilerPath");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import/Export시 속성값 Import/Export 여부
        /// </summary>
        private bool _IsCheckedCompilerOption;
        public bool IsCheckedCompilerOption
        {
            get { return _IsCheckedCompilerOption; }
            set
            {
                if (_IsCheckedCompilerOption != value)
                {
                    _IsCheckedCompilerOption = value;
                    RaisePropertyChanged("IsCheckedCompilerOption");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import/Export시 속성값 Import/Export 여부
        /// </summary>
        private bool _IsCheckedLinkerOption;
        public bool IsCheckedLinkerOption
        {
            get { return _IsCheckedLinkerOption; }
            set
            {
                if (_IsCheckedLinkerOption != value)
                {
                    _IsCheckedLinkerOption = value;
                    RaisePropertyChanged("IsCheckedLinkerOption");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import/Export시 속성값 Import/Export 여부
        /// </summary>
        private bool _IsCheckedRunnableList;
        public bool IsCheckedRunnableList
        {
            get { return _IsCheckedRunnableList; }
            set
            {
                if (_IsCheckedRunnableList != value)
                {
                    _IsCheckedRunnableList = value;
                    RaisePropertyChanged("IsCheckedRunnableList");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import/Export시 속성값 Import/Export 여부
        /// </summary>
        private bool _IsCheckedRunnableStubList;
        public bool IsCheckedRunnableStubList
        {
            get { return _IsCheckedRunnableStubList; }
            set
            {
                if (_IsCheckedRunnableStubList != value)
                {
                    _IsCheckedRunnableStubList = value;
                    RaisePropertyChanged("IsCheckedRunnableStubList");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import/Export시 속성값 Import/Export 여부
        /// </summary>
        private bool _IsCheckedRegisterList;
        public bool IsCheckedRegisterList
        {
            get { return _IsCheckedRegisterList; }
            set
            {
                if (_IsCheckedRegisterList != value)
                {
                    _IsCheckedRegisterList = value;
                    RaisePropertyChanged("IsCheckedRegisterList");
                }
            }
        }
        /// <summary>
        /// .csa파일 Import/Export시 속성값 Import/Export 여부
        /// </summary>
        private bool _IsCheckedCopyPathList;
        public bool IsCheckedCopyPathList
        {
            get { return _IsCheckedCopyPathList; }
            set
            {
                if (_IsCheckedCopyPathList != value)
                {
                    _IsCheckedCopyPathList = value;
                    RaisePropertyChanged("IsCheckedCopyPathList");
                }
            }
        }
        /// <summary>
        /// Import Check All Checkbox Binding Value
        /// </summary>
        private bool _IsImportCheckedAllList;
        public bool IsImportCheckedAllList
        {
            get { return _IsImportCheckedAllList; }
            set
            {
                if (_IsImportCheckedAllList != value)
                {
                    _IsImportCheckedAllList = value;
                    RaisePropertyChanged("IsImportCheckedAllList");
                }
            }
        }
        /// <summary>
        /// Export Check All Checkbox Binding Value
        /// </summary>
        private bool _IsExportCheckedAllList;
        public bool IsExportCheckedAllList
        {
            get { return _IsExportCheckedAllList; }
            set
            {
                if (_IsExportCheckedAllList != value)
                {
                    _IsExportCheckedAllList = value;
                    RaisePropertyChanged("IsExportCheckedAllList");
                }
            }
        }
        /// <summary>
        /// Import .csa File Path
        /// </summary>
        private string _ImportProjectPath;
        public string ImportProjectPath
        {
            get { return _ImportProjectPath; }
            set
            {
                if (_ImportProjectPath != value)
                {
                    _ImportProjectPath = value;
                    RaisePropertyChanged("ImportProjectPath");
                }
            }
        }
        /// <summary>
        ///  .csa을 Export할 경로
        /// </summary>
        private string _ExporttProjectPath;
        public string ExporttProjectPath
        {
            get { return _ExporttProjectPath; }
            set
            {
                if (_ExporttProjectPath != value)
                {
                    _ExporttProjectPath = value;
                    RaisePropertyChanged("ExporttProjectPath");
                }
            }
        }

        public ProjectExplorerModel()
        {
            ProjectExplorerModelList = new ObservableCollection<ProjectExplorerListModel>();
        }
    }
}
