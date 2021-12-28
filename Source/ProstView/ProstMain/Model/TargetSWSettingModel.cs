using GalaSoft.MvvmLight;
using ICSharpCode.AvalonEdit.Document;
using Javi.ExplorerTreeView;
using ProstMain.Util;
using ProstMain.ViewModel;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;

namespace ProstMain.Model
{
    public class TargetSWSettingModel : ObservableObject
    {
        /// <summary>
        /// Target_SW Source Code Tab Right FileTreePath
        /// </summary>
        private string _WorkspaceRootPath;
        public string WorkspaceRootPath
        {
            get { return _WorkspaceRootPath; }
            set
            {
                if (_WorkspaceRootPath != value)
                {
                    _WorkspaceRootPath = value;
                    RaisePropertyChanged("WorkspaceRootPath");
                }
            }
        }
        /// <summary>
        /// SourceCodeRootPath
        /// </summary>
        private string _SourceCodeRootPath;
        public string SourceCodeRootPath
        {
            get { return _SourceCodeRootPath; }
            set
            {
                if (_SourceCodeRootPath != value)
                {
                    _SourceCodeRootPath = value;
                    RaisePropertyChanged("SourceCodeRootPath");
                }
            }
        }
        /// <summary>
        /// Runnable List
        /// </summary>
        private ObservableCollection<RunnableModel> _RunnableList;
        public ObservableCollection<RunnableModel> RunnableList
        {
            get { return _RunnableList; }
            set
            {
                if (_RunnableList != value)
                {
                    _RunnableList = value;
                    RaisePropertyChanged("RunnableList");
                }
            }
        }
        /// <summary>
        /// Input Runnable Call Value
        /// </summary>
        private string _InputRunnableCall;
        public string InputRunnableCall
        {
            get { return _InputRunnableCall; }
            set
            {
                if (_InputRunnableCall != value)
                {
                    _InputRunnableCall = value;
                    RaisePropertyChanged("InputRunnableCall");
                }
            }
        }
        /// <summary>
        /// Input Runnable Cycle Value
        /// </summary>
        private string _InputCallCycle;
        public string InputCallCycle
        {
            get { return _InputCallCycle; }
            set
            {
                if (_InputCallCycle != value)
                {
                    _InputCallCycle = value;
                    RaisePropertyChanged("InputCallCycle");
                }
            }
        }
        /// <summary>
        /// Input Runnable Core Selected Item
        /// </summary>
        private string _InputCore;
        public string InputCore
        {
            get { return _InputCore; }
            set
            {
                if (_InputCore != value)
                {
                    _InputCore = value;
                    RaisePropertyChanged("InputCore");
                }
            }
        }
        /// <summary>
        /// Input Runnable Header File
        /// </summary>
        private string _InputHeader;
        public string InputHeader
        {
            get { return _InputHeader; }
            set
            {
                if (_InputHeader != value)
                {
                    _InputHeader = value;
                    RaisePropertyChanged("InputHeader");
                }
            }
        }
        /// <summary>
        /// Input Stub Function Name Value
        /// </summary>
        private string _InputStubFunctionName;
        public string InputStubFunctionName
        {
            get { return _InputStubFunctionName; }
            set
            {
                if (_InputStubFunctionName != value)
                {
                    _InputStubFunctionName = value;
                    RaisePropertyChanged("InputStubFunctionName");
                }
            }
        }
        /// <summary>
        /// Input Stub Delay Value
        /// </summary>
        private string _InputStubDelay;
        public string InputStubDelay
        {
            get { return _InputStubDelay; }
            set
            {
                if (_InputStubDelay != value)
                {
                    _InputStubDelay = value;
                    RaisePropertyChanged("InputStubDelay");
                }
            }
        }
        /// <summary>
        /// Input Stub Return Value
        /// </summary>
        private string _InputStubReturnValue;
        public string InputStubReturnValue
        {
            get { return _InputStubReturnValue; }
            set
            {
                if (_InputStubReturnValue != value)
                {
                    _InputStubReturnValue = value;
                    RaisePropertyChanged("InputStubReturnValue");
                }
            }
        }
        /// <summary>
        /// Input Register Name Value
        /// </summary>
        private string _InputRegisterName;
        public string InputRegisterName
        {
            get { return _InputRegisterName; }
            set
            {
                if (_InputRegisterName != value)
                {
                    _InputRegisterName = value;
                    RaisePropertyChanged("InputRegisterName");
                }
            }
        }
        /// <summary>
        /// Input Register Value
        /// </summary>
        private string _InputRegisterValue;
        public string InputRegisterValue
        {
            get { return _InputRegisterValue; }
            set
            {
                if (_InputRegisterValue != value)
                {
                    _InputRegisterValue = value;
                    RaisePropertyChanged("InputRegisterValue");
                }
            }
        }
        /// <summary>
        /// Input Initialize Function Name Value
        /// </summary>
        private string _InputInitFunctionName;
        public string InputInitFunctionName
        {
            get { return _InputInitFunctionName; }
            set
            {
                if (_InputInitFunctionName != value)
                {
                    _InputInitFunctionName = value;
                    RaisePropertyChanged("InputInitFunctionName");
                }
            }
        }
        /// <summary>
        /// Runnable Empty Check Warning Line Show Flag
        /// </summary>
        private Visibility _RunnableEmptyData;
        public Visibility RunnableEmptyData
        {
            get { return _RunnableEmptyData; }
            set
            {
                if(_RunnableEmptyData !=value)
                {
                    _RunnableEmptyData = value;
                    RaisePropertyChanged("RunnableEmptyData");
                }
            }
        }
        /// <summary>
        /// Stub List
        /// </summary>
        private ObservableCollection<RunnableStubModel> _RunnableStubList;
        public ObservableCollection<RunnableStubModel> RunnableStubList
        {
            get { return _RunnableStubList; }
            set
            {
                if (_RunnableStubList != value)
                {
                    _RunnableStubList = value;
                    RaisePropertyChanged("RunnableStubList");
                }
            }
        }
        /// <summary>
        /// Register List
        /// </summary>
        private ObservableCollection<RegisterModel> _RegisterList;
        public ObservableCollection<RegisterModel> RegisterList
        {
            get { return _RegisterList; }
            set
            {
                if (_RegisterList != value)
                {
                    _RegisterList = value;
                    RaisePropertyChanged("RegisterList");
                }
            }
        }
        /// <summary>
        /// Initialize Function List
        /// </summary>
        private ObservableCollection<string> _InitFunctionList;
        public ObservableCollection<string> InitFunctionList
        {
            get { return _InitFunctionList; }
            set
            {
                if (_InitFunctionList != value)
                {
                    _InitFunctionList = value;
                    RaisePropertyChanged("InitFunctionList");
                }
            }
        }
        /// <summary>
        /// Test Code List from ELF File
        /// </summary>
        private IronPython.Runtime.List _TestCodeList;
        public IronPython.Runtime.List TestCodeList
        {
            get { return _TestCodeList; }
            set
            {
                if(_TestCodeList != value)
                {
                    _TestCodeList = value;
                    RaisePropertyChanged("TestCodeList");
                }
            }
        }
        /// <summary>
        /// Guide Line Show Flag
        /// </summary>
        private string _IsVisibleTestCodePathGuild;
        public string IsVisibleTestCodePathGuild
        {
            get { return _IsVisibleTestCodePathGuild; }
            set
            {
                if (_IsVisibleTestCodePathGuild != value)
                {
                    _IsVisibleTestCodePathGuild = value;
                    RaisePropertyChanged("IsVisibleTestCodePathGuild");
                }
            }
        }
        /// <summary>
        /// Runnable Selected Item
        /// </summary>
        private RunnableModel _SelectRunnable;
        public RunnableModel SelectRunnable
        {
            get { return _SelectRunnable; }
            set
            {
                if (_SelectRunnable != value)
                {
                    _SelectRunnable = value;
                    RaisePropertyChanged("SelectRunnable");
                }
            }
        }
        /// <summary>
        /// Stub Selected Item
        /// </summary>
        private RunnableStubModel _SelectStub;
        public RunnableStubModel SelectStub
        {
            get { return _SelectStub; }
            set
            {
                if (_SelectStub != value)
                {
                    _SelectStub = value;
                    RaisePropertyChanged("SelectStub");
                }
            }
        }
        /// <summary>
        /// Register Selected Item
        /// </summary>
        private RegisterModel _SelectRegister;
        public RegisterModel SelectRegister
        {
            get { return _SelectRegister; }
            set
            {
                if (_SelectRegister != value)
                {
                    _SelectRegister = value;
                    RaisePropertyChanged("SelectRegister");
                }
            }
        }
        /// <summary>
        /// Initialize Function Selected Item
        /// </summary>
        private string _SelectInitFunction;
        public string SelectInitFunction
        {
            get { return _SelectInitFunction; }
            set
            {
                if (_SelectInitFunction != value)
                {
                    _SelectInitFunction = value;
                    RaisePropertyChanged("SelectInitFunction");
                }
            }
        }
        /// <summary>
        /// Source Code Path :: WorkspacePath + ProjectPath + Target_SW
        /// </summary>
        private string _SourceCodePath;
        public string SourceCodePath
        {
            get { return _SourceCodePath; }
            set
            {
                _SourceCodePath = value;
                RaisePropertyChanged("SourceCodePath");
            }
        }
        /// <summary>
        /// ExplorerTreeView Source Item :: Local Path Tree View
        /// </summary>
        private ExplorerTreeViewItem _SourceTreeViewItem;
        public ExplorerTreeViewItem SourceTreeViewItem
        {
            get { return _SourceTreeViewItem; }
            set
            {
                if (_SourceTreeViewItem != value)
                {
                    _SourceTreeViewItem = value;
                    RaisePropertyChanged("SourceTreeViewItem");
                }
            }
        }
        /// <summary>
        /// ExplorerTreeView Target Item :: Source Code Tree View
        /// </summary>
        private ExplorerTreeViewItem _TargetTreeViewItem;
        public ExplorerTreeViewItem TargetTreeViewItem
        {
            get { return _TargetTreeViewItem; }
            set
            {
                if (_TargetTreeViewItem != value)
                {
                    _TargetTreeViewItem = value;
                    RaisePropertyChanged("TargetTreeViewItem");
                }
            }
        }
        /// <summary>
        /// ExplorerTreeView Source Code TreeView Selected Item
        /// </summary>
        private ExplorerTreeViewItem _SelectTreeViewItem;
        public ExplorerTreeViewItem SelectTreeViewItem
        {
            get { return _SelectTreeViewItem; }
            set
            {
                if (_SelectTreeViewItem != value)
                {
                    _SelectTreeViewItem = value;
                    RaisePropertyChanged("SelectTreeViewItem");
                }
            }
        }
        /// <summary>
        /// Copy Path Save Dictionary
        /// </summary>
        private Dictionary<string,string> _CopyDictionary;
        public Dictionary<string, string> CopyDictionary
        {
            get { return _CopyDictionary; }
            set
            {
                if (_CopyDictionary != value)
                {
                    _CopyDictionary = value;
                    RaisePropertyChanged("CopyDictionary");
                }
            }
        }
        /// <summary>
        /// Include Path List
        /// </summary>
        private ObservableCollection<IncludePathModel> _IncludePathList;
        public ObservableCollection<IncludePathModel> IncludePathList
        {
            get { return _IncludePathList; }
            set
            {
                if (_IncludePathList != value)
                {
                    _IncludePathList = value;
                    RaisePropertyChanged("IncludePathList");
                }
            }
        }
        /// <summary>
        /// Library Path List
        /// </summary>
        private ObservableCollection<string> _LibraryPathList;
        public ObservableCollection<string> LibraryPathList
        {
            get { return _LibraryPathList; }
            set
            {
                if (_LibraryPathList != value)
                {
                    _LibraryPathList = value;
                    RaisePropertyChanged("LibraryPathList");
                }
            }
        }
        /// <summary>
        /// PopupIncludePath Directory Value
        /// </summary>
        private string _PopupIncludePathRegistInputDirectory;
        public string PopupIncludePathRegistInputDirectory
        {
            get { return _PopupIncludePathRegistInputDirectory; }
            set
            {
                if (_PopupIncludePathRegistInputDirectory != value)
                {
                    _PopupIncludePathRegistInputDirectory = value;
                    RaisePropertyChanged("PopupIncludePathRegistInputDirectory");
                }
            }
        }
        /// <summary>
        /// PopupIncludePath Directory Display Value :: Relative, Absolute
        /// </summary>
        private string _PopupIncludePathRegistDisplayInputDirectory;
        public string PopupIncludePathRegistDisplayInputDirectory
        {
            get { return _PopupIncludePathRegistDisplayInputDirectory; }
            set
            {
                if (_PopupIncludePathRegistDisplayInputDirectory != value)
                {
                    _PopupIncludePathRegistDisplayInputDirectory = value;
                    RaisePropertyChanged("PopupIncludePathRegistDisplayInputDirectory");
                }
            }
        }
        /// <summary>
        /// Library Path Selected Index
        /// </summary>
        private int _LibraryPathSelectedIndex;
        public int LibraryPathSelectedIndex
        {
            get { return _LibraryPathSelectedIndex; }
            set
            {
                if (_LibraryPathSelectedIndex != value)
                {
                    _LibraryPathSelectedIndex = value;
                    RaisePropertyChanged("LibraryPathSelectedIndex");
                }
            }
        }

        /// <summary>
        /// Include Path Selected Index
        /// </summary>
        private int _IncludePathSelectedIndex;
        public int IncludePathSelectedIndex
        {
            get { return _IncludePathSelectedIndex; }
            set
            {
                if (_IncludePathSelectedIndex != value)
                {
                    _IncludePathSelectedIndex = value;
                    RaisePropertyChanged("IncludePathSelectedIndex");
                }
            }
        }
        /// <summary>
        /// Memory Location ABS18 Text
        /// </summary>
        private TextDocument _MemoryLocationTextABS18;
        public TextDocument MemoryLocationTextABS18
        {
            get { return _MemoryLocationTextABS18; }
            set
            {
                if (_MemoryLocationTextABS18 != value)
                {
                    _MemoryLocationTextABS18 = value;
                    RaisePropertyChanged("MemoryLocationTextABS18");
                }
            }
        }
        /// <summary>
        /// Memory Location Linear Text
        /// </summary>
        private TextDocument _MemoryLocationTextLinear;
        public TextDocument MemoryLocationTextLinear
        {
            get { return _MemoryLocationTextLinear; }
            set
            {
                if (_MemoryLocationTextLinear != value)
                {
                    _MemoryLocationTextLinear = value;
                    RaisePropertyChanged("MemoryLocationTextLinear");
                }
            }
        }
        private string _ImportRegisterFilePath;
        public string ImportRegisterFilePath
        {
            get { return _ImportRegisterFilePath; }
            set
            {
                if (_ImportRegisterFilePath != value)
                {
                    _ImportRegisterFilePath = value;
                    RaisePropertyChanged("ImportRegisterFilePath");
                }
            }
        }
        private ObservableCollection<string> _LinkerScriptList;
        public ObservableCollection<string> LinkerScriptList
        {
            get { return _LinkerScriptList; }
            set
            {
                if (_LinkerScriptList != value)
                {
                    _LinkerScriptList = value;
                    RaisePropertyChanged("LinkerScriptList");
                }
            }
        }
        private string _SelectMainLinkerScript;
        public string SelectMainLinkerScript
        {
            get { return _SelectMainLinkerScript; }
            set
            {
                if (_SelectMainLinkerScript != value)
                {
                    _SelectMainLinkerScript = value;
                    RaisePropertyChanged("SelectMainLinkerScript");
                }
            }
        }
        public TargetSWSettingModel()
        {
            RunnableList = new ObservableCollection<RunnableModel>();
            RunnableStubList = new ObservableCollection<RunnableStubModel>();
            RegisterList = new ObservableCollection<RegisterModel>();
            IncludePathList = new ObservableCollection<IncludePathModel>();

            LibraryPathList = new ObservableCollection<string>();
            InitFunctionList = new ObservableCollection<string>();
            LinkerScriptList = new ObservableCollection<string>();

            RunnableList.CollectionChanged += this.RunnableListCollectionChanged;
            TestCodeList = new IronPython.Runtime.List();

            CopyDictionary = new Dictionary<string, string>();

            MemoryLocationTextLinear = new TextDocument();
            MemoryLocationTextABS18 = new TextDocument();

            SourceCodePath = @"C:\";
            WorkspaceRootPath = @"C:\";
            SourceCodeRootPath = @"C:\";

        }
        void RunnableListCollectionChanged(object sender, NotifyCollectionChangedEventArgs e)
        {
            if (RunnableList.Count > 0)
                RunnableEmptyData = Visibility.Collapsed;
            else
                RunnableEmptyData = Visibility.Visible;
        }

    }
}
