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
    public class CommandModel : ObservableObject
    {
        /// <summary>
        /// Log Message ObservableCollection
        /// </summary>
        private ObservableCollection<string> _LogData;
        public ObservableCollection<string> LogData
        {
            get { return _LogData; }
            set
            {
                if (_LogData != value)
                {
                    _LogData = value;
                    RaisePropertyChanged("LogData");
                }
            }
        }
        /// <summary>
        /// Log Message Filter Checkbox Binding Value
        /// </summary>
        private bool _SearchModuleMainGUI;
        public bool SearchModuleMainGUI
        {
            get { return _SearchModuleMainGUI; }
            set
            {
                if (_SearchModuleMainGUI != value)
                {
                    _SearchModuleMainGUI = value;
                    RaisePropertyChanged("SearchModuleMainGUI");
                }
            }
        }
        /// <summary>
        /// Log Message Filter Checkbox Binding Value
        /// </summary>
        private bool _SearchModuleReport;
        public bool SearchModuleReport
        {
            get { return _SearchModuleReport; }
            set
            {
                if (_SearchModuleReport != value)
                {
                    _SearchModuleReport = value;
                    RaisePropertyChanged("SearchModuleReport");
                }
            }
        }
        /// <summary>
        /// Log Message Filter Checkbox Binding Value
        /// </summary>
        private bool _SearchModuleCompiler;
        public bool SearchModuleCompiler
        {
            get { return _SearchModuleCompiler; }
            set
            {
                if (_SearchModuleCompiler != value)
                {
                    _SearchModuleCompiler = value;
                    RaisePropertyChanged("SearchModuleCompiler");
                }
            }
        }
        /// <summary>
        /// Log Message Filter Checkbox Binding Value
        /// </summary>
        private bool _SearchModuleParser;
        public bool SearchModuleParser
        {
            get { return _SearchModuleParser; }
            set
            {
                if (_SearchModuleParser != value)
                {
                    _SearchModuleParser = value;
                    RaisePropertyChanged("SearchModuleParser");
                }
            }
        }
        /// <summary>
        /// Log Message Filter Checkbox Binding Value
        /// </summary>
        private bool _SearchModuleTrace32;
        public bool SearchModuleTrace32
        {
            get { return _SearchModuleTrace32; }
            set
            {
                if (_SearchModuleTrace32 != value)
                {
                    _SearchModuleTrace32 = value;
                    RaisePropertyChanged("SearchModuleTrace32");
                }
            }
        }

        /// <summary>
        /// Log Message Filter LogType Combobox Binding Value
        /// </summary>
        private ObservableCollection<string> _SearchLogLevel { get; set; }
        public ObservableCollection<string> SearchLogLevel
        {
            get { return _SearchLogLevel; }
            set
            {
                if (_SearchLogLevel != value)
                {
                    _SearchLogLevel = value;
                    RaisePropertyChanged("SearchLogLevel");
                }
            }
        }
        /// <summary>
        /// Log Message Filter LogType Combobox Selected Item
        /// </summary>
        private int _SearchLogLevelIndex;
        public int SearchLogLevelIndex
        {
            get { return _SearchLogLevelIndex; }
            set
            {
                if (_SearchLogLevelIndex != value)
                {
                    _SearchLogLevelIndex = value;
                    RaisePropertyChanged("SearchLogLevelIndex");
                }
            }
        }
        
        public CommandModel()
        {
            LogData = new ObservableCollection<string>();

            SearchLogLevel = new ObservableCollection<string>();
            SearchLogLevel.Add("ALL");
            SearchLogLevel.Add("INFO");
            SearchLogLevel.Add("ERROR");
            SearchLogLevel.Add("WARNING");

            SearchModuleCompiler = true;
            SearchModuleMainGUI = true;
            SearchModuleParser = true;
            SearchModuleReport = true;
            SearchModuleTrace32 = true;
        }
    }
}
