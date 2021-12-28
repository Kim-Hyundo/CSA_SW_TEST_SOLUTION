using GalaSoft.MvvmLight;
using ProstMain.ViewModel;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Documents;

namespace ProstMain.Model
{
    public class ReportSettingModel : ObservableObject
    {
        private string _TestSummaryReport_Path;
        public string TestSummaryReport_Path
        {
            get { return _TestSummaryReport_Path; }
            set
            {
                if (_TestSummaryReport_Path != value)
                {
                    _TestSummaryReport_Path = value;
                    RaisePropertyChanged("TestSummaryReport_Path");
                }
            }
        }

        private string _IOTestReport_Path;
        public string IOTestReport_Path
        {
            get { return _IOTestReport_Path; }
            set
            {
                if (_IOTestReport_Path != value)
                {
                    _IOTestReport_Path = value;
                    RaisePropertyChanged("IOTestReport_Path");
                }
            }
        }

        private bool _IOTestReport_InputData;
        public bool IOTestReport_InputData
        {
            get { return _IOTestReport_InputData; }
            set
            {
                if (_IOTestReport_InputData != value)
                {
                    _IOTestReport_InputData = value;
                    RaisePropertyChanged("IOTestReport_InputData");
                }
            }
        }
        private bool _IOTestReport_OutputData;
        public bool IOTestReport_OutputData
        {
            get { return _IOTestReport_OutputData; }
            set
            {
                if (_IOTestReport_OutputData != value)
                {
                    _IOTestReport_OutputData = value;
                    RaisePropertyChanged("IOTestReport_OutputData");
                }
            }
        }
        private bool _IOTestReport_ExpectedData;
        public bool IOTestReport_ExpectedData
        {
            get { return _IOTestReport_ExpectedData; }
            set
            {
                if (_IOTestReport_ExpectedData != value)
                {
                    _IOTestReport_ExpectedData = value;
                    RaisePropertyChanged("IOTestReport_ExpectedData");
                }
            }
        }
        private bool _IOTestReport_TestPassFail;
        public bool IOTestReport_TestPassFail
        {
            get { return _IOTestReport_TestPassFail; }
            set
            {
                if (_IOTestReport_TestPassFail != value)
                {
                    _IOTestReport_TestPassFail = value;
                    RaisePropertyChanged("IOTestReport_TestPassFail");
                }
            }
        }
        private bool _IOTestReport_RuntimeMeasure;
        public bool IOTestReport_RuntimeMeasure
        {
            get { return _IOTestReport_RuntimeMeasure; }
            set
            {
                if (_IOTestReport_RuntimeMeasure != value)
                {
                    _IOTestReport_RuntimeMeasure = value;
                    RaisePropertyChanged("IOTestReport_RuntimeMeasure");
                }
            }
        }
        private string _CodeCoverageReport_Path;
        public string CodeCoverageReport_Path
        {
            get { return _CodeCoverageReport_Path; }
            set
            {
                if (_CodeCoverageReport_Path != value)
                {
                    _CodeCoverageReport_Path = value;
                    RaisePropertyChanged("CodeCoverageReport_Path");
                }
            }
        }
        private bool _CodeCoverageReport_Statement;
        public bool CodeCoverageReport_Statement
        {
            get { return _CodeCoverageReport_Statement; }
            set
            {
                if (_CodeCoverageReport_Statement != value)
                {
                    _CodeCoverageReport_Statement = value;
                    RaisePropertyChanged("CodeCoverageReport_Statement");
                }
            }
        }
        private bool _CodeCoverageReport_FunctionCall;
        public bool CodeCoverageReport_FunctionCall
        {
            get { return _CodeCoverageReport_FunctionCall; }
            set
            {
                if (_CodeCoverageReport_FunctionCall != value)
                {
                    _CodeCoverageReport_FunctionCall = value;
                    RaisePropertyChanged("CodeCoverageReport_FunctionCall");
                }
            }
        }
        private bool _CodeCoverageReport_MC_DC;
        public bool CodeCoverageReport_MC_DC
        {
            get { return _CodeCoverageReport_MC_DC; }
            set
            {
                if (_CodeCoverageReport_MC_DC != value)
                {
                    _CodeCoverageReport_MC_DC = value;
                    RaisePropertyChanged("CodeCoverageReport_MC_DC");
                }
            }
        }
        private string _PerformanceMeasurementReport_Path;
        public string PerformanceMeasurementReport_Path
        {
            get { return _PerformanceMeasurementReport_Path; }
            set
            {
                if (_PerformanceMeasurementReport_Path != value)
                {
                    _PerformanceMeasurementReport_Path = value;
                    RaisePropertyChanged("PerformanceMeasurementReport_Path");
                }
            }
        }
        private bool _PerformanceMeasurementReport_ExecuteChart;
        public bool PerformanceMeasurementReport_ExecuteChart
        {
            get { return _PerformanceMeasurementReport_ExecuteChart; }
            set
            {
                if (_PerformanceMeasurementReport_ExecuteChart != value)
                {
                    _PerformanceMeasurementReport_ExecuteChart = value;
                    RaisePropertyChanged("PerformanceMeasurementReport_ExecuteChart");
                }
            }
        }
        private bool _PerformanceMeasurementReport_DataReadWrite;
        public bool PerformanceMeasurementReport_DataReadWrite
        {
            get { return _PerformanceMeasurementReport_DataReadWrite; }
            set
            {
                if (_PerformanceMeasurementReport_DataReadWrite != value)
                {
                    _PerformanceMeasurementReport_DataReadWrite = value;
                    RaisePropertyChanged("PerformanceMeasurementReport_DataReadWrite");
                }
            }
        }
        private bool _PerformanceMeasurementReport_BenchMark;
        public bool PerformanceMeasurementReport_BenchMark
        {
            get { return _PerformanceMeasurementReport_BenchMark; }
            set
            {
                if (_PerformanceMeasurementReport_BenchMark != value)
                {
                    _PerformanceMeasurementReport_BenchMark = value;
                    RaisePropertyChanged("PerformanceMeasurementReport_BenchMark");
                }
            }
        }

        private bool _DebugAnalysis;
        public bool DebugAnalysis
        {
            get { return _DebugAnalysis; }
            set
            {
                if (_DebugAnalysis != value)
                {
                    _DebugAnalysis = value;
                    RaisePropertyChanged("DebugAnalysis");
                }
            }
        }
        private bool _DataMornitoring;
        public bool DataMornitoring
        {
            get { return _DataMornitoring; }
            set
            {
                if (_DataMornitoring != value)
                {
                    _DataMornitoring = value;
                    RaisePropertyChanged("DataMornitoring");
                }
            }
        }
        private bool _FunctionCallPathReport;
        public bool FunctionCallPathReport
        {
            get { return _FunctionCallPathReport; }
            set
            {
                if (_FunctionCallPathReport != value)
                {
                    _FunctionCallPathReport = value;
                    RaisePropertyChanged("FunctionCallPathReport");
                }
            }
        }

        private IronPython.Runtime.PythonDictionary _StackInfoValueDictionary;
        public IronPython.Runtime.PythonDictionary StackInfoValueDictionary
        {
            get { return _StackInfoValueDictionary; }
            set
            {
                if (_StackInfoValueDictionary != value)
                {
                    _StackInfoValueDictionary = value;
                    RaisePropertyChanged("StackInfoValueDictionary");
                }
            }
        }
        private IronPython.Runtime.PythonDictionary _StackInfoDictionary;
        public IronPython.Runtime.PythonDictionary StackInfoDictionary
        {
            get { return _StackInfoDictionary; }
            set
            {
                if (_StackInfoDictionary != value)
                {
                    _StackInfoDictionary = value;
                    RaisePropertyChanged("StackInfoDictionary");
                }
            }
        }
        private IronPython.Runtime.PythonDictionary _TestInfoDictionary;
        public IronPython.Runtime.PythonDictionary TestInfoDictionary
        {
            get { return _TestInfoDictionary; }
            set
            {
                if (_TestInfoDictionary != value)
                {
                    _TestInfoDictionary = value;
                    RaisePropertyChanged("TestInfoDictionary");
                }
            }
        }
        private string _StartAddressValue;
        public string StartAddressValue
        {
            get { return _StartAddressValue; }
            set
            {
                if (_StartAddressValue != value)
                {
                    _StartAddressValue = value;
                    RaisePropertyChanged("StartAddressValue");
                }
            }
        }
        private string _EndAddressValue;
        public string EndAddressValue
        {
            get { return _EndAddressValue; }
            set
            {
                if (_EndAddressValue != value)
                {
                    _EndAddressValue = value;
                    RaisePropertyChanged("EndAddressValue");
                }
            }
        }
        private int _StackPointer;
        public int StackPointer
        {
            get { return _StackPointer; }
            set
            {
                if (_StackPointer != value)
                {
                    _StackPointer = value;
                    RaisePropertyChanged("StackPointer");
                }
            }
        }

        public ReportSettingModel()
        {
            StackInfoDictionary = new IronPython.Runtime.PythonDictionary();
            StackInfoValueDictionary = new IronPython.Runtime.PythonDictionary();
            TestInfoDictionary = new IronPython.Runtime.PythonDictionary();
            StartAddressValue = "";
            EndAddressValue = "";
            StackPointer = 0;
        }
    }
}

