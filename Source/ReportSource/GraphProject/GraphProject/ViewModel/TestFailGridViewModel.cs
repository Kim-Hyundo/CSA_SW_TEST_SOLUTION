using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using GalaSoft.MvvmLight.Ioc;
using GraphProject.Etc;
using GraphProject.Models;
using GraphProject.TRACE32;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;

namespace GraphProject.ViewModel
{
    public class TestFailGridViewModel : ViewModelBase
    {
        public static int T32_PORT_NUM = 30000;

        private ICollectionView collectionView;

        private ComboBoxItem _filterContent;

        public ComboBoxItem FilterContent
        {
            get{ return _filterContent; }
            set
            {
                if (_filterContent != value)
                {
                    _filterContent = value;
                    collectionView.Refresh();
                    RaisePropertyChanged("FilterContent");
                }
            }
        }
        private ObservableCollection<TestFailListModel> _displaytestFailListModel;

        public ObservableCollection<TestFailListModel> displaytestFailListModel
        {
            get { return this._displaytestFailListModel; }

            set
            {
                this._displaytestFailListModel = value;
                this.RaisePropertyChanged("displaytestFailListModel");
            }
        }

        private ObservableCollection<TestFailListModel> _displaytestFailTitleListModel;

        public ObservableCollection<TestFailListModel> displaytestFailTitleListModel
        {
            get { return this._displaytestFailTitleListModel; }

            set
            {
                this._displaytestFailTitleListModel = value;
                this.RaisePropertyChanged("displaytestFailTitleListModel");
            }
        }
        private ObservableCollection<int> _ListPageCount;

        public ObservableCollection<int> ListPageCount
        {
            get { return this._ListPageCount; }

            set
            {
                this._ListPageCount = value;
                this.RaisePropertyChanged("ListPageCount");
            }
        }
        private int _currentElementPage = 0;

        public int currentElementPage
        {
            get { return this._currentElementPage; }

            set
            {
                this._currentElementPage = value;
                this.RaisePropertyChanged("currentElementPage");
            }
        }

        private bool _isListShowAll;

        public bool isListShowAll
        {
            get { return this._isListShowAll; }

            set
            {
                this._isListShowAll = value;
                this.RaisePropertyChanged("isListShowAll");
            }
        }

        public List<TestFailListModel> testFailListModel { get; set; } =  new List<TestFailListModel>();

        public RelayCommand<object> DebugButtonCommand { get; set; }
        public RelayCommand ListIndexChangedCommand { get; set; }
        public RelayCommand<object> ListShowChangedCommand { get; set; }

        [PreferredConstructor]
        public TestFailGridViewModel() { }

        public TestFailGridViewModel(TestFailListModel tdlm)
        {
            this.testFailListModel = new List<TestFailListModel>() { tdlm };

            collectionView = CollectionViewSource.GetDefaultView(testFailListModel);
            collectionView.Filter = UserFilter;

            DebugButtonCommand = new RelayCommand<object>(DebugButtonFunction);
        }
        int LastElement = 0;
        int TotalElementPage = 0;
        private void ListIndexChanged()
        {
            if (currentElementPage == -1)
                return;

            displaytestFailListModel.Clear();
            if((currentElementPage + 1) * 10 > testFailListModel.Count)
            {
                for (int i = currentElementPage * 10; i < (currentElementPage * 10) + LastElement; i++)
                {
                    displaytestFailListModel.Add(testFailListModel[i]);
                }
            }
            else
            {
                for (int i = currentElementPage * 10; i < (currentElementPage * 10) + 10; i++)
                {
                    displaytestFailListModel.Add(testFailListModel[i]);
                }
            }
        }
        private void ListShowChanged(object e)
        {
            if (!(bool)e) // SHOW ALL
            {
                displaytestFailListModel.Clear();
                ListPageCount.Clear();
                foreach (TestFailListModel model in testFailListModel)
                {
                    displaytestFailListModel.Add(model);
                }
            }
            else // SHOW PAGE
            {
                displaytestFailListModel.Clear();
                ListPageCount.Clear();

                if (testFailListModel.Count < 10)
                {
                    for (int i = 0; i < testFailListModel.Count; i++)
                        displaytestFailListModel.Add(testFailListModel[i]);

                    TotalElementPage = 1;
                    LastElement = testFailListModel.Count;
                }
                else
                {
                    for (int i = 0; i < 10; i++)
                        displaytestFailListModel.Add(testFailListModel[i]);
                    TotalElementPage = (int)Math.Ceiling(Decimal.Divide(testFailListModel.Count, 10));
                    LastElement = testFailListModel.Count % 10; // 마지막 표시 갯수
                }



                for (int i = 1; i <= TotalElementPage; i++)
                    ListPageCount.Add(i);

                currentElementPage = 0;
            }
        }
        public TestFailGridViewModel(List<TestFailListModel> tdlm)
        {
            this.testFailListModel = tdlm;
            displaytestFailListModel = new ObservableCollection<TestFailListModel>();
            displaytestFailTitleListModel = new ObservableCollection<TestFailListModel>();
            ListPageCount = new ObservableCollection<int>();

            if (testFailListModel.Count < 10)
            {
                for (int i = 0; i < testFailListModel.Count; i++)
                    displaytestFailListModel.Add(testFailListModel[i]);

                TotalElementPage = 1;
                LastElement = testFailListModel.Count;
            }
            else
            {
                for (int i = 0; i < 10; i++)
                    displaytestFailListModel.Add(testFailListModel[i]);
                TotalElementPage = (int)Math.Ceiling(Decimal.Divide(testFailListModel.Count, 10));
                LastElement = testFailListModel.Count % 10; // 마지막 표시 갯수
            }



            for (int i = 1; i <= TotalElementPage; i++)
                ListPageCount.Add(i);


            collectionView = CollectionViewSource.GetDefaultView(displaytestFailListModel);
            collectionView.Filter = UserFilter;

            MeasureDataColumWidth();

            DebugButtonCommand = new RelayCommand<object>(DebugButtonFunction);
            ListIndexChangedCommand = new RelayCommand(ListIndexChanged);
            ListShowChangedCommand = new RelayCommand<object>(ListShowChanged);
        }
        int widthoffset = 55;
        private void MeasureDataColumWidth()
        {
            displaytestFailTitleListModel.Clear();
            displaytestFailTitleListModel.Add(new TestFailListModel()
            {
                ScenarioName = "ScenarioName",
                ActualOutputData = "Output Data (Ac)",
                TestCaseNum = "Test ID",
                InputData = "Input Data",
                ExpectedOutputData = "Output Data (Ex)",
                ExecutionTime = "Execution Time(us)",
                PassFail = "PassFail",
                Tolerance = "Tolerance"
            });
            CommonUtil.ExOutputWidth = 0;
            CommonUtil.TestIDWidth = 0;
            CommonUtil.InputDataWidth = 0;
            CommonUtil.AcOutputWidth = 0;
            CommonUtil.SenarioWidth = 0;
            CommonUtil.ExecutionTimeWidth = 0;

            foreach (TestFailListModel model in testFailListModel)
            {
                TextBlock textBlock = new TextBlock();

                textBlock.Text = model.ExpectedOutputData;
                textBlock.FontSize = 9;

                double output_width = CommonUtil.MeasureTextSize(textBlock.Text, textBlock.FontFamily, textBlock.FontStyle, textBlock.FontWeight, textBlock.FontStretch, textBlock.FontSize).Width;
                if (CommonUtil.ExOutputWidth < output_width + widthoffset + widthoffset)
                    CommonUtil.ExOutputWidth = output_width + widthoffset + widthoffset;

                textBlock.Text = model.TestCaseNum;
                double testcasenum_width = CommonUtil.MeasureTextSize(textBlock.Text, textBlock.FontFamily, textBlock.FontStyle, textBlock.FontWeight, textBlock.FontStretch, textBlock.FontSize).Width;
                if (CommonUtil.TestIDWidth < testcasenum_width + widthoffset)
                    CommonUtil.TestIDWidth = testcasenum_width + widthoffset;

                

                textBlock.Text = model.InputData;
                double inputdata_width = CommonUtil.MeasureTextSize(textBlock.Text, textBlock.FontFamily, textBlock.FontStyle, textBlock.FontWeight, textBlock.FontStretch, textBlock.FontSize).Width;
                if (CommonUtil.InputDataWidth < inputdata_width + widthoffset + widthoffset)
                    CommonUtil.InputDataWidth = inputdata_width + widthoffset + widthoffset;


                textBlock.Text = model.ActualOutputData;
                double acoutput_width = CommonUtil.MeasureTextSize(textBlock.Text, textBlock.FontFamily, textBlock.FontStyle, textBlock.FontWeight, textBlock.FontStretch, textBlock.FontSize).Width;
                if (CommonUtil.AcOutputWidth < acoutput_width + widthoffset + widthoffset)
                    CommonUtil.AcOutputWidth = acoutput_width + widthoffset + widthoffset;

                textBlock.Text = model.ScenarioName;
                double scenario_width = CommonUtil.MeasureTextSize(textBlock.Text, textBlock.FontFamily, textBlock.FontStyle, textBlock.FontWeight, textBlock.FontStretch, textBlock.FontSize).Width;
                if (CommonUtil.SenarioWidth < scenario_width + widthoffset)
                    CommonUtil.SenarioWidth = scenario_width + widthoffset;

                textBlock.Text = model.ExecutionTime;
                double executiontime_width = CommonUtil.MeasureTextSize(textBlock.Text, textBlock.FontFamily, textBlock.FontStyle, textBlock.FontWeight, textBlock.FontStretch, textBlock.FontSize).Width;
                if (CommonUtil.ExecutionTimeWidth < executiontime_width + widthoffset + 10)
                    CommonUtil.ExecutionTimeWidth = executiontime_width + widthoffset + 10;
            }

            CommonUtil.TotalTestResultWidth = CommonUtil.ExOutputWidth + CommonUtil.TestIDWidth + CommonUtil.InputDataWidth + CommonUtil.AcOutputWidth + CommonUtil.SenarioWidth + CommonUtil.ExecutionTimeWidth + 140;

            if (CommonUtil.TotalTestResultWidth < 1450)
                CommonUtil.TotalTestResultWidth = 1450;

            collectionView.Refresh();
        }
        public void DebugButtonFunction(object parameter)
        {
            try
            {
                var values = (object[])parameter;
                string ScenarioName = values[0].ToString();
                string TestIDName = values[1].ToString();
                string InputVars = values[2].ToString();
                string OutputVars = values[3].ToString();


                //string ad_file_name = ScenarioName + "." +TestIDName + ".ad";
                string ad_file_name = "Trace_" + TestIDName + ".ad";
                string gen_path = MainViewModel.curr_Workspace + "\\" + MainViewModel.curr_Project + "\\Gen\\" + MainViewModel.curr_Folder;
                string elf_file_path = gen_path + "\\Build\\";

                DirectoryInfo d = new DirectoryInfo(elf_file_path);       //Assuming Test is your Folder
                FileInfo[] Files = d.GetFiles("*.elf");                  //Getting Text files
                string elf_file = "";

                foreach (FileInfo file in Files)
                {
                    elf_file = file.FullName;
                    break;
                }


                Trace32Remote.T32_PATH = @"..\src\lib\T32";
                string convert_cpu_name = "";

                if (MainViewModel.Summary_Test_Data.get("MCU/CPU").ToString().Contains("tc27"))
                {
                    convert_cpu_name = "TC277TF";
                }
                else if(MainViewModel.Summary_Test_Data.get("MCU/CPU").ToString().Contains("tc39"))
                {
                    convert_cpu_name = "TC397XE";
                }
                
                Thread t = new Thread(() => DebugStart(convert_cpu_name, elf_file, gen_path + "\\" + MainViewModel.curr_testcase + "\\Debug\\ad\\" + ScenarioName + "\\" + ad_file_name, InputVars, OutputVars, TestIDName));
                t.Start();
            }
            catch(Exception ex)
            {
                CommonUtil.LogMessageList.Add(typeof(TestFailGridViewModel).Name + " :: " + ex.Message + " Line :: " + CommonUtil.GetExceptionLineNumber(ex));
            }
        }

        private void DebugStart(string cpu, string elf, string ad, string InputVars, string OutputVars, string TestIDName)
        {
            Trace32Remote t32 = new Trace32Remote(T32_PORT_NUM);
            t32.RemoteConnection();
            t32.DebugEnvSetting(cpu, elf, ad, InputVars, OutputVars, TestIDName);
            T32_PORT_NUM++;
        }

        private bool UserFilter(object item)
        {
            if (FilterContent == null)
                return true;

            if (String.IsNullOrEmpty(FilterContent.Content.ToString()))
                return false;
            else
            {
                if (FilterContent.Content.ToString() == "All")
                    return true;
                
                return ((item as TestFailListModel).PassFail.IndexOf(FilterContent.Content.ToString(), StringComparison.OrdinalIgnoreCase) >= 0);
            }
        }

    }
}
