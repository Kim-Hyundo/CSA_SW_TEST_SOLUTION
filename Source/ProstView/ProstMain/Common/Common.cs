using ProstMain.Popup;
using ProstMain.View;
using ProstMain.ViewModel;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web.SessionState;
using System.Windows;

namespace ProstMain.Common
{
    class Common
    {
        public const bool DEBUG_MODE = false;

        // Using App
        public const int FILE_CHECK = 0;
        public const int VERSION_CHECK = 1;
        public const int LICENSE_CHECK = 2;
        public const int CHECK_COMPLETE = 3;

        public const int CUSTOMER_ALL = 0;
        public const int CUSTOMER_MANDO = 1;
        public const int CUSTOMER_WIA = 2;

        // Using View, TrackBar
        public const string TRUE = "Visible";
        public const string FALSE = "Collapsed";

        // Using ProjectExploreView
        public const string PROJECT = "Visible";
        public const string PROPERTY = "Collapsed";

        public const int EXIT = 0;
        public const int WORKSPACE_CHANGE = 1;
        public const int PROJECT_CHANGE = 2;
        public const int SAVE_MODE = 3;

        // Using CommandView
        public const int MODULE_MAIN_GUI = 0;
        public const int MODULE_PARSER = 1;
        public const int MODULE_REPORTER = 2;
        public const int MODULE_COMPILER = 3;
        public const int MODULE_TRACE32 = 4;

        public const int LOGTYPE_INF = 0;
        public const int LOGTYPE_PGR = 1;
        public const int LOGTYPE_PFF = 2;
        public const int LOGTYPE_ERR = 3;
        public const int LOGTYPE_CPL = 4;
        public const int LOGTYPE_WARN = 5;

        // Using HistoryViewModel
        public const int INIT = 0;
        public const int SELECT = 1;

        // Using ProjectSettingView
        public const string WARNING = "PrimaryDark";
        public const string MODIFY = "Accent";
        public const string COMPLETE = "PrimaryLight";

        public const int DEFAULT = 0;
        public const int PASS = 1;
        public const int FAIL = -1;

        public const int SELECT_INIT = 0;
        public const int SELECT_BUILD = 1;
        public const int SELECT_TESTCASE = 2;
        public const int SELECT_SCNARIO = 3;

        // Using CommandView
        public const string GREEN = "Green";
        public const string RED = "Red";
        public const string BLUE = "Blue";
        public const string PURPLE = "Purple";
        public const string BLACK = "Black";

        public const string FILTER_MAINGUI = "[MAIN_GUI]";
        public const string FILTER_PARSER = "(PARSER)";
        public const string FILTER_REPORT = "(REPORTER)";
        public const string FILTER_COMPILER = "(COMPILER)";
        public const string FILTER_TRACE32 = "[TRACE32]";

        // Using PythonHandler
        public const int ELF = 0;
        public const int LSL = 1;
        public const int MAPXML = 2;

        public const int PARSING_TESTSPECIFICATION = 0;
        public const int PARSING_TESTCASE = 0;

        // Using Menubar
        public const int THEMA_DARK = 0;
        public const int THEMA_LIGHT = 1;
        public const int LOG_STANDARD = 1;
        public const int LOG_INFORMATION = 2;
        public const int LOG_DEBUG = 3;

        // Using FunctionWorker
        public const int RUNNING = 0;
        public const int PAUSE = 1;
        public const int STEP_RUNNING = 2;
        public const int STOP = 3;

        // Using TargetSW
        public const int NOT_EXIST = -1;
        public const int FILE = 0;
        public const int FOLDER = 1;

        // Using ToolBarView
        public const int STANDARD = 0;
        public const int ALREADY_ELF = 1;

        // Using TRACE32
        public const int TRACE32_POWERVIEW = 0;
        public const int TRACE32_SIMULATOR = 1;

        // Using ToolbarView
        public const int TESTMODE_MANUAL = 0;
        public const int TESTMODE_AUTO = 1;

        // Install Path = Ex) C:\Users\CSA_DEV\Documents\Working\Prost_v2.0\Prost v2.0
        public static string INSTALL_PATH = Directory.GetParent(Environment.CurrentDirectory).FullName;
        public const string PYTHON_APP = @"..\src\lib\Python37\python.exe";
        public const string COMPILER_APP = @"..\src\Compiler\src\compiler.py";
        public const string PARSER_APP = @"..\src\parser\src\Main.py";
        public const string PARSER_MODE_TRACEINFO = "TraceInfoParser";
        public const string PARSER_MODE_TESTCASE = "TestcaseParser";
        public const string PARSER_MODE_TESTSPEC = "TestspecParser";
        public const string PARSER_MODE_TRACEVARPARSER = "TraceVarParser";

        public const string PARSER_MODE_MANDOTESTCASE = "MandoUnitTestcaseParser";

        public const string PARSER_MODE_WIATESTCASE = "WiaUnitTestcaseParser";

        public const string CALLPATH_APP = @"..\src\Parser\src\call_path.py";
        public const string REPORTER_APP = @"..\src\Report\src\main.py";

        public const string PROJECT_INFO_DATA = "\\C_PROJECT_INFO_DATA_dictionary.txt";

        public static Window loadingView = new LoadingView();
        public static Window workspaceView = new WorkSpaceView();
        public static Window mainwindowView = new MainWindow();
        public static PopupTestStatusView m_PopupTestStatusView;
        public static PopupBuildStatusView m_PopupBuildStatusView;
        public static PopupTestCaseParsingView m_PopupTestCaseParsingView;
        public static PopupIncludePathRegistView m_PopupIncludePathRegistView;



    }
}

