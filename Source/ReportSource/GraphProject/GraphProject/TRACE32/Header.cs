using GraphProject.ViewModel;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace GraphProject.TRACE32
{
    public class Header
    {
        public static string T32_CONFIG_PATH = " -c \"" + System.IO.Directory.GetCurrentDirectory() + "\\..\\report\\T32_Config.t32\"";

        #region Remote API
        private string _ic;
        public string IC
        {
            get { return _ic; }
            set { if (_ic != value) { _ic = value; } }
        }

        private string _rcl;
        public string RCL
        {
            get { return _rcl; }
            set { if (_rcl != value) { _rcl = value; } }
        }

        private string _packLen;
        public string PACKLEN
        {
            get { return _packLen; }
            set { if (_packLen != value) { _packLen = value; } }
        }

        private string _portNum;
        public string PORT
        {
            get { return _portNum; }
            set { if (_portNum != value) { _portNum = value; } }
        }
        #endregion

        #region Environment Variables

        private string _os;
        public string OS
        {
            get { return _os; }
            set { if (_os != value) { _os = value; } }
        }

        private string _id;
        public string ID
        {
            get { return _id; }
            set { if (_id != value) { _id = value; } }
        }

        private string _tmpDir;
        public string TMPDIR
        {
            get { return _tmpDir; }
            set { if (_tmpDir != value) { _tmpDir = value; } }
        }

        private string _sysDir;
        public string SYSDIR
        {
            get { return _sysDir; }
            set { if (_sysDir != value) { _sysDir = value; } }
        }

        private string _helpDIr;
        public string HELPDIR
        {
            get { return _helpDIr; }
            set { if (_helpDIr != value) { _helpDIr = value; } }
        }

        #endregion

        #region USB Information

        private string _interface;
        public string INTERFACE
        {
            get { return _interface; }
            set { if (_interface != value) { _interface = value; } }
        }

        private string _interface2;
        public string INTERFACE2
        {
            get { return _interface2; }
            set { if (_interface2 != value) { _interface2 = value; } }
        }

        private string _nodeNum;
        public string NODE
        {
            get { return _nodeNum; }
            set { if (_nodeNum != value) { _nodeNum = value; } }
        }
        #endregion

        #region Printer Settings

        private string _printer;
        public string PRINTER
        {
            get { return _printer; }
            set { if (_printer != value) { _printer = value; } }
        }

        #endregion

        #region Screen Option 

        private string _header;
        public string HEADER
        {
            get { return _header; }
            set { if (_header != value) { _header = value; } }
        }

        private string _connectionmode;
        public string CONNECTIONMODE
        {
            get { return _connectionmode; }
            set { if (_connectionmode != value) { _connectionmode = value; } }
        }

        private string _screen;
        public string SCREEN
        {
            get { return _screen; }
            set { if (_screen != value) { _screen = value; } }
        }

        #endregion

        #region Startup Cmm

        private string _startup;
        public string STARTUP
        {
            get { return _startup; }
            set { if (_startup != value) { _startup = value; } }
        }

        #endregion

        public Header() { }

        public string createParameter()
        {
            string parameter = T32_CONFIG_PATH;

            try
            {
                if (IC != null) parameter += " \"" + IC + "\"";
                if (RCL != null) parameter += " \"" + RCL + "\"";
                if (PACKLEN != null) parameter += " \"" + PACKLEN + "\"";
                if (PORT != null) parameter += " \"" + PORT + "\"";
                if (OS != null) parameter += " \"" + OS + "\"";
                if (ID != null) parameter += " \"" + ID + "\"";
                if (TMPDIR != null) parameter += " \"" + TMPDIR + "\"";
                if (SYSDIR != null)
                {
                    parameter += " \"" + MainViewModel.Install_path + @"\src\lib\T32"+ "\"";
                }
                if (HELPDIR != null) parameter += " \"" + HELPDIR + "\"";
                if (INTERFACE != null) parameter += " \"" + INTERFACE + "\"";
                if (INTERFACE2 != null) parameter += " \"" + INTERFACE2 + "\"";
                if (NODE != null) parameter += " \"" + NODE + "\"";
                if (PRINTER != null) parameter += " \"" + PRINTER + "\"";
                if (HEADER != null) parameter += " \"" + HEADER + "\"";
                if (CONNECTIONMODE != null) parameter += " \"" + CONNECTIONMODE + "\"";
                if (SCREEN != null) parameter += " \"" + SCREEN + "\"";
                if (STARTUP != null) parameter += " -s \"" + STARTUP + "\"";
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Create Parameter Error");
                return null;
            }

            return parameter;
        }
    }
}
