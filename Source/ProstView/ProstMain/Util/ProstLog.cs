using ProstMain.Common;
using ProstMain.ViewModel;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Threading;
using static ProstMain.Model.CommandModel;

namespace ProstMain.Util
{
    class ProstLog
    {
        public object Dispatcher { get; private set; }

        private static class LazyHolder
        {
            public static readonly ProstLog INSTANCE = new ProstLog();
        }

        public static ProstLog getInstance()
        {
            return LazyHolder.INSTANCE;
        }
        public void Log(int module, int logtype, string msg, bool isThread = true)
        {
            if (isThread)
            {
                Dispatcher dispatcher = System.Windows.Application.Current.Dispatcher;
                DispatcherOperation dispatcherOperation = dispatcher.BeginInvoke(System.Windows.Threading.DispatcherPriority.Send, (ThreadStart)
                delegate ()
                {
                    if (msg != null && !msg.Equals(""))
                    {
                        string Logtime = "[" + DateTime.Now.ToString(format: "HH:mm:ss.fff") + "]";
                        if (module == Common.Common.MODULE_MAIN_GUI)
                        {
                            switch(logtype)
                            {
                                case Common.Common.LOGTYPE_INF:
                                    if(ViewModelLocator.MenuBarVM.LogLevelIndex >= 1)
                                    ViewModelLocator.CommandVM.AddLog(Logtime + " [MAIN_GUI]" + " [INF] " + msg.TrimStart());
                                    break;
                                case Common.Common.LOGTYPE_PFF:
                                    if(ViewModelLocator.MenuBarVM.LogLevelIndex >= 1)
                                    ViewModelLocator.CommandVM.AddLog(Logtime + " [MAIN_GUI]" + " [PFF] " + msg.TrimStart());
                                    break;
                                case Common.Common.LOGTYPE_PGR:
                                    if (ViewModelLocator.MenuBarVM.LogLevelIndex  >= 2)
                                        ViewModelLocator.CommandVM.AddLog(Logtime + " [MAIN_GUI]" + " [PRG] " + msg.TrimStart());
                                    break;
                                case Common.Common.LOGTYPE_ERR:
                                    if (ViewModelLocator.MenuBarVM.LogLevelIndex  >= 1)
                                        ViewModelLocator.CommandVM.AddLog(Logtime + " [MAIN_GUI]" + " [ERR] " + msg.TrimStart());
                                    break;
                                case Common.Common.LOGTYPE_WARN:
                                    if (ViewModelLocator.MenuBarVM.LogLevelIndex >= 1)
                                        ViewModelLocator.CommandVM.AddLog(Logtime + " [MAIN_GUI]" + " [WARN] " + msg.TrimStart());
                                    break;
                                case Common.Common.LOGTYPE_CPL:
                                    if (ViewModelLocator.MenuBarVM.LogLevelIndex  >= 3)
                                        ViewModelLocator.CommandVM.AddLog(Logtime + " [MAIN_GUI]" + " [CPL] " + msg.TrimStart());
                                    break;
                            }
                        }
                        else if(module == Common.Common.MODULE_TRACE32)
                        {
                            switch (logtype)
                            {
                                case Common.Common.LOGTYPE_INF:
                                    if (ViewModelLocator.MenuBarVM.LogLevelIndex  >= 1)
                                        ViewModelLocator.CommandVM.AddLog(Logtime + " [TRACE32]" + " [INF] " + msg.TrimStart());
                                    break;
                                case Common.Common.LOGTYPE_PFF:
                                    if (ViewModelLocator.MenuBarVM.LogLevelIndex  >= 1)
                                        ViewModelLocator.CommandVM.AddLog(Logtime + " [TRACE32]" + " [PFF] " + msg.TrimStart());
                                    break;
                                case Common.Common.LOGTYPE_PGR:
                                    if (ViewModelLocator.MenuBarVM.LogLevelIndex  >= 2)
                                        ViewModelLocator.CommandVM.AddLog(Logtime + " [TRACE32]" + " [PRG] " + msg.TrimStart());
                                    break;
                                case Common.Common.LOGTYPE_ERR:
                                    if (ViewModelLocator.MenuBarVM.LogLevelIndex  >= 1)
                                        ViewModelLocator.CommandVM.AddLog(Logtime + " [TRACE32]" + " [ERR] " + msg.TrimStart());
                                    break;
                                case Common.Common.LOGTYPE_CPL:
                                    if (ViewModelLocator.MenuBarVM.LogLevelIndex  >= 3)
                                        ViewModelLocator.CommandVM.AddLog(Logtime + " [TRACE32]" + " [CPL] " + msg.TrimStart());
                                    break;
                            }
                        }
                    }
                });
            }
            else
            {
                if (msg != null && !msg.Equals(""))
                {
                    string Logtime = "[" + DateTime.Now.ToString(format: "HH:mm:ss.fff") + "]";
                    if (module == Common.Common.MODULE_MAIN_GUI)
                        ViewModelLocator.CommandVM.AddLog(Logtime + " [MAIN_GUI]" + " [INF] " + msg.TrimStart());
                    else if (module == Common.Common.MODULE_PARSER)
                        ViewModelLocator.CommandVM.AddLog("(PARSER)" + " " + msg.TrimStart());
                    else if (module == Common.Common.MODULE_COMPILER)
                        ViewModelLocator.CommandVM.AddLog("(COMPILER)" + " " + msg.TrimStart());
                    else if (module == Common.Common.MODULE_REPORTER)
                        ViewModelLocator.CommandVM.AddLog("(REPORTER)" + " " + msg.TrimStart());
                    else if (module == Common.Common.MODULE_TRACE32)
                        ViewModelLocator.CommandVM.AddLog(Logtime + " (TRACE32)" + " " + msg.TrimStart());
                }
            }
        }
        public void Log(int module, string msg, bool isThread=true)
        {
            if (isThread)
            {
                Dispatcher dispatcher = System.Windows.Application.Current.Dispatcher;
                DispatcherOperation dispatcherOperation = dispatcher.BeginInvoke(System.Windows.Threading.DispatcherPriority.Send, (ThreadStart)
                delegate ()
                {
                    if (msg != null && !msg.Equals(""))
                    {
                        string Logtime = "[" + DateTime.Now.ToString(format: "HH:mm:ss.fff") + "]";
                        if (module == Common.Common.MODULE_MAIN_GUI)
                            ViewModelLocator.CommandVM.AddLog(Logtime + " [MAIN_GUI]" + " [INF] " + msg.TrimStart());
                        else if (module == Common.Common.MODULE_PARSER)
                            ViewModelLocator.CommandVM.AddLog("(PARSER)" + " " + msg.TrimStart());
                        else if (module == Common.Common.MODULE_COMPILER)
                            ViewModelLocator.CommandVM.AddLog("(COMPILER)" + " " + msg.TrimStart());
                        else if (module == Common.Common.MODULE_REPORTER)
                            ViewModelLocator.CommandVM.AddLog("(REPORTER)" + " " + msg.TrimStart());
                        else if (module == Common.Common.MODULE_TRACE32)
                            ViewModelLocator.CommandVM.AddLog(Logtime + " [TRACE32]" + " [INF] " + msg.TrimStart());
                    }
                });
            }
            else
            {
                if (msg != null && !msg.Equals(""))
                {
                    string Logtime = "[" + DateTime.Now.ToString(format: "HH:mm:ss.fff") + "]";
                    if (module == Common.Common.MODULE_MAIN_GUI)
                        ViewModelLocator.CommandVM.AddLog(Logtime + " [MAIN_GUI]" + " [INF] " + msg.TrimStart());
                    else if (module == Common.Common.MODULE_PARSER)
                        ViewModelLocator.CommandVM.AddLog("(PARSER)" + " " + msg.TrimStart());
                    else if (module == Common.Common.MODULE_COMPILER)
                        ViewModelLocator.CommandVM.AddLog("(COMPILER)" + " " + msg.TrimStart());
                    else if (module == Common.Common.MODULE_REPORTER)
                        ViewModelLocator.CommandVM.AddLog("(REPORTER)" + " " + msg.TrimStart());
                    else if (module == Common.Common.MODULE_TRACE32)
                        ViewModelLocator.CommandVM.AddLog(Logtime + " (TRACE32)" + " " + msg.TrimStart());
                }
            }
        }
        public void Log(string msg, bool isThread=true)
        {
            if (isThread)
            {
                Dispatcher dispatcher = System.Windows.Application.Current.Dispatcher;
                DispatcherOperation dispatcherOperation = dispatcher.BeginInvoke(System.Windows.Threading.DispatcherPriority.Send, (ThreadStart)
                delegate ()
                {
                    string Logtime = "[" + DateTime.Now.ToString(format: "HH:mm:ss.fff") + "]";
                    ViewModelLocator.CommandVM.AddLog(Logtime + msg.TrimStart());
                });
            }
            else
            {
                string Logtime = "[" + DateTime.Now.ToString(format: "HH:mm:ss.fff") + "]";
                ViewModelLocator.CommandVM.AddLog(Logtime + msg.TrimStart());
            }
        }
    }

}
