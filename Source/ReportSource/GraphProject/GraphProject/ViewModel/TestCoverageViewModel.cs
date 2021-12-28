using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using GalaSoft.MvvmLight.Ioc;
using GraphProject.Etc;
using GraphProject.Models;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Windows.Data;

namespace GraphProject.ViewModel
{
    public class TestCoverageViewModel : ViewModelBase
    {
        private string _selectMode;

        public string SelectMode
        {
            get { return _selectMode; }
            set
            {
                if (_selectMode != value)
                {
                    _selectMode = value;
                    RaisePropertyChanged("SelectMode");
                }
            }
        }

        private string _mcdc_visiblity;

        public string MCDC_visiblity
        {
            get { return _mcdc_visiblity; }
            set
            {
                if (_mcdc_visiblity != value)
                {
                    _mcdc_visiblity = value;
                    RaisePropertyChanged("MCDC_visiblity");
                }
            }
        }
        private string _statement_visiblity;

        public string Statement_visiblity
        {
            get { return _statement_visiblity; }
            set
            {
                if (_statement_visiblity != value)
                {
                    _statement_visiblity = value;
                    RaisePropertyChanged("Statement_visiblity");
                }
            }
        }

        private string _function_visiblity;

        public string Function_visiblity
        {
            get { return _function_visiblity; }
            set
            {
                if (_function_visiblity != value)
                {
                    _function_visiblity = value;
                    RaisePropertyChanged("Function_visiblity");
                }
            }
        }

        private string _call_visiblity;

        public string Call_visiblity
        {
            get { return _call_visiblity; }
            set
            {
                if (_call_visiblity != value)
                {
                    _call_visiblity = value;
                    RaisePropertyChanged("Call_visiblity");
                }
            }
        }

        private ICollectionView collectionView;

        private ComboBoxItem _filterContent;

        public ComboBoxItem FilterContent
        {
            get { return _filterContent; }
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

        private ICollectionView collectionView2;

        private ComboBoxItem _filterContent2;

        public ComboBoxItem FilterContent2
        {
            get { return _filterContent2; }
            set
            {
                if (_filterContent2 != value)
                {
                    _filterContent2 = value;
                    if(collectionView2 != null)
                    collectionView2.Refresh();
                    RaisePropertyChanged("FilterContent2");
                }
            }
        }

        private string _title;

        public string Title
        {
            get { return _title; }
            set
            {
                if (_title != value)
                {
                    _title = value;
                    RaisePropertyChanged("Title");
                }
            }
        }

        private double _percentBar;

        public double PercentBar
        {
            get { return _percentBar; }
            set
            {
                if (_percentBar != value)
                {
                    _percentBar = value;
                    RaisePropertyChanged("PercentBar");
                }
            }
        }

        private string _percentBarText;

        public string PercentBarText
        {
            get { return _percentBarText; }
            set
            {
                if (_percentBarText != value)
                {
                    _percentBarText = value;
                    RaisePropertyChanged("PercentBarText");
                }
            }
        }
        private string _MCDC_Cov_Enable;

        public string MCDC_Cov_Enable
        {
            get { return _MCDC_Cov_Enable; }
            set
            {
                if (_MCDC_Cov_Enable != value)
                {
                    _MCDC_Cov_Enable = value;
                    RaisePropertyChanged("MCDC_Cov_Enable");
                }
            }
        }

        public TestCoverageModel testCoverageModel { get; set; } = new TestCoverageModel();
        public FuncCoverageModelList funcCoverageModel { get; set; } = new FuncCoverageModelList();
        public CallCoverageModelList callCoverageModel { get; set; } = new CallCoverageModelList();
        public MCDCTestCoverageModel mcdcCoverageModel { get; set; } = new MCDCTestCoverageModel();


        public RelayCommand CovSelectionChangedCommand { get; set; }

        public TestCoverageViewModel(TestCoverageModel tcm, FuncCoverageModelList ftcm, CallCoverageModelList ctcm, MCDCTestCoverageModel mcdccm)
        {
            if (File.Exists(MainViewModel.curr_Workspace + "\\" + MainViewModel.curr_Project + "\\Gen\\" + MainViewModel.curr_Folder + "\\" + MainViewModel.curr_testcase + "\\" + @"Debug\dic\mcdc_cov\cov\cov_merge.txt"))
                MCDC_Cov_Enable = "Visible";
            else
                MCDC_Cov_Enable = "Collapsed";

            this.testCoverageModel = tcm;

            this.funcCoverageModel = ftcm;
            this.callCoverageModel = ctcm;
            this.mcdcCoverageModel = mcdccm;

            Title = "Total Coverage";
            SelectMode = "Statement";
            Statement_visiblity = "Visible";
            Function_visiblity = "Collapsed";
            Call_visiblity = "Collapsed";
            MCDC_visiblity = "Collapsed";

            PercentBar = tcm.PercentBar;
            PercentBarText = tcm.PercentBarText;

            CovSelectionChangedCommand = new RelayCommand(CovSelectionChangedFunction);

            collectionView = CollectionViewSource.GetDefaultView(funcCoverageModel.ftcm);
            collectionView.Filter = UserFilter;

            collectionView2 = CollectionViewSource.GetDefaultView(callCoverageModel.ctcm);
            collectionView2.Filter = UserFilter2;

            MeasureCallCoverageDataColumWidth();
            MeasureFunctionCoverageDataColumWidth();
        }
        public TestCoverageViewModel(TestCoverageModel tcm, FuncCoverageModelList ftcm)
        {
            this.testCoverageModel = tcm;

            this.funcCoverageModel = ftcm;

            Title = "Total Coverage";
            SelectMode = "Statement";
            Statement_visiblity = "Visible";
            Function_visiblity = "Collapsed";
            Call_visiblity = "Collapsed";
            MCDC_visiblity = "Collapsed";

            PercentBar = tcm.PercentBar;
            PercentBarText = tcm.PercentBarText;

            CovSelectionChangedCommand = new RelayCommand(CovSelectionChangedFunction);

            collectionView = CollectionViewSource.GetDefaultView(funcCoverageModel.ftcm);
            collectionView.Filter = UserFilter;

            MeasureFunctionCoverageDataColumWidth();
        }
        [PreferredConstructor]
        public TestCoverageViewModel()
        {

        }

        private void CovSelectionChangedFunction()
        {
            if (SelectMode == null || SelectMode == "")
                return;

            if (SelectMode == "MC/DC")
            {
                Statement_visiblity = "Collapsed";
                Function_visiblity = "Collapsed";
                Call_visiblity = "Collapsed";
                MCDC_visiblity = "Visible";

                PercentBar = this.mcdcCoverageModel.PercentBar;
                PercentBarText = this.mcdcCoverageModel.PercentBarText;
            }
            else if (SelectMode == "Statement")
            {
                Statement_visiblity = "Visible";
                Function_visiblity = "Collapsed";
                Call_visiblity = "Collapsed";
                MCDC_visiblity = "Collapsed";

                PercentBar = this.testCoverageModel.PercentBar;
                PercentBarText = this.testCoverageModel.PercentBarText;
            }
            else if (SelectMode == "Function")
            {
                MeasureFunctionCoverageDataColumWidth();
                Statement_visiblity = "Collapsed";
                Function_visiblity = "Visible";
                Call_visiblity = "Collapsed";
                MCDC_visiblity = "Collapsed";

                PercentBar = this.funcCoverageModel.PercentBar;
                PercentBarText = this.funcCoverageModel.PercentBarText;
            }
            else if (SelectMode == "Call")
            {
                if (callCoverageModel.ctcm == null)
                    return;

                MeasureCallCoverageDataColumWidth();
                Statement_visiblity = "Collapsed";
                Function_visiblity = "Collapsed";
                Call_visiblity = "Visible";
                MCDC_visiblity = "Collapsed";

                PercentBar = this.callCoverageModel.PercentBar;
                PercentBarText = this.callCoverageModel.PercentBarText;
            }
        }
        int func_widthoffset = 100;
        private void MeasureFunctionCoverageDataColumWidth()
        {
            CommonUtil.FunctionCoverageSourceFileWidth = 0;
            CommonUtil.FunctionCoverageNameWidth = 0;

            foreach (FuncCoverageModel model in funcCoverageModel.ftcm)
            {
                double convert_width = 0;
                TextBlock textBlock = new TextBlock();

                textBlock.Text = model.Func_Source_File;
                convert_width = CommonUtil.MeasureTextSize(textBlock.Text, textBlock.FontFamily, textBlock.FontStyle, textBlock.FontWeight, textBlock.FontStretch, textBlock.FontSize).Width;
                if (CommonUtil.FunctionCoverageSourceFileWidth < convert_width + func_widthoffset)
                    CommonUtil.FunctionCoverageSourceFileWidth = convert_width + func_widthoffset;

                textBlock.Text = model.Func_Func_Name;
                convert_width = CommonUtil.MeasureTextSize(textBlock.Text, textBlock.FontFamily, textBlock.FontStyle, textBlock.FontWeight, textBlock.FontStretch, textBlock.FontSize).Width;
                if (CommonUtil.FunctionCoverageNameWidth < convert_width + func_widthoffset)
                    CommonUtil.FunctionCoverageNameWidth = convert_width + func_widthoffset;
            }

            CommonUtil.FunctionCoverageTotalWidth = CommonUtil.FunctionCoverageSourceFileWidth + CommonUtil.FunctionCoverageNameWidth + 520;
            collectionView.Refresh();
        }
        int widthoffset = 40;
        private void MeasureCallCoverageDataColumWidth()
        {
            foreach (CallCoverageModel model in callCoverageModel.ctcm)
            {
                double convert_width = 0;
                TextBlock textBlock = new TextBlock();

                textBlock.Text = model.Call_Source_File;
                convert_width = CommonUtil.MeasureTextSize(textBlock.Text, textBlock.FontFamily, textBlock.FontStyle, textBlock.FontWeight, textBlock.FontStretch, textBlock.FontSize).Width;
                if (CommonUtil.CallCoverageSourceFileWidth < convert_width + widthoffset)
                    CommonUtil.CallCoverageSourceFileWidth = convert_width + widthoffset;

                textBlock.Text = model.Call_Func_Name;
                convert_width = CommonUtil.MeasureTextSize(textBlock.Text, textBlock.FontFamily, textBlock.FontStyle, textBlock.FontWeight, textBlock.FontStretch, textBlock.FontSize).Width;
                if (CommonUtil.CallCoverageCallerWidth < convert_width + widthoffset)
                    CommonUtil.CallCoverageCallerWidth = convert_width + widthoffset;

                textBlock.Text = model.Call_Inner_Func_Name;
                convert_width = CommonUtil.MeasureTextSize(textBlock.Text, textBlock.FontFamily, textBlock.FontStyle, textBlock.FontWeight, textBlock.FontStretch, textBlock.FontSize).Width;
                if (CommonUtil.CallCoverageCalledWidth < convert_width + widthoffset)
                    CommonUtil.CallCoverageCalledWidth = convert_width + widthoffset;

                textBlock.Text = model.TC_list;
                convert_width = CommonUtil.MeasureTextSize(textBlock.Text, textBlock.FontFamily, textBlock.FontStyle, textBlock.FontWeight, textBlock.FontStretch, textBlock.FontSize).Width;
                if (CommonUtil.CallCoverageTestCaseWidth < convert_width)
                    CommonUtil.CallCoverageTestCaseWidth = convert_width;
            }

            CommonUtil.CallCoverageTotalWidth = CommonUtil.CallCoverageSourceFileWidth + CommonUtil.CallCoverageCallerWidth + CommonUtil.CallCoverageCalledWidth + CommonUtil.CallCoverageTestCaseWidth + 210;
            collectionView.Refresh();
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

                return ((item as FuncCoverageModel).Func_IsExecuted.IndexOf(FilterContent.Content.ToString(), StringComparison.OrdinalIgnoreCase) >= 0);
            }
        }

        private bool UserFilter2(object item)
        {
            if (FilterContent2 == null)
                return true;

            if (String.IsNullOrEmpty(FilterContent2.Content.ToString()))
                return false;
            else
            {
                if (FilterContent2.Content.ToString() == "All")
                    return true;

                return ((item as CallCoverageModel).Call_IsExecuted.IndexOf(FilterContent2.Content.ToString(), StringComparison.OrdinalIgnoreCase) >= 0);
            }
        }
    }
}
