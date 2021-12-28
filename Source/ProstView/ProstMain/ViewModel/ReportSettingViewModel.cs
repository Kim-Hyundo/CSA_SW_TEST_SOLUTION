using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using Microsoft.WindowsAPICodePack.Dialogs;
using ProstMain.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace ProstMain.ViewModel
{
    public class ReportSettingViewModel : ViewModelBase
    {
        public RelayCommand TestReportBrowserCommand { get; set; }
        public RelayCommand IOTestReportBrowserCommand { get; set; }
        public RelayCommand CoverageReportBrowserCommand { get; set; }
        public RelayCommand PerformanceReportBrowserCommand { get; set; }


        private ReportSettingModel _ReportSettingModel;
        public ReportSettingModel ReportSettingModel
        {
            get { return _ReportSettingModel; }
            set
            {
                if(_ReportSettingModel != value)
                {
                    _ReportSettingModel = value;
                    RaisePropertyChanged("ReportSettingModel");
                }
            }
        }

        public ReportSettingViewModel()
        {
            TestReportBrowserCommand = new RelayCommand(TestReportBrowser);
            IOTestReportBrowserCommand = new RelayCommand(IOTestReportBrowser);
            CoverageReportBrowserCommand = new RelayCommand(CoverageReportBrowser);
            PerformanceReportBrowserCommand = new RelayCommand(PerformanceReportBrowser);

            ReportSettingModel = new ReportSettingModel();
        }
        private void TestReportBrowser()
        {
            CommonOpenFileDialog dialog = new CommonOpenFileDialog();   //CommonOpenFileDialog 클래스 생성

            dialog.InitialDirectory = @"C:\";   //창이 뜨면 처음 보여줄 폴더 설정
            dialog.IsFolderPicker = true;

            if (dialog.ShowDialog() == CommonFileDialogResult.Ok)
            {
                ReportSettingModel.TestSummaryReport_Path = dialog.FileName;
            }
        }
        private void IOTestReportBrowser()
        {
            CommonOpenFileDialog dialog = new CommonOpenFileDialog();   //CommonOpenFileDialog 클래스 생성

            dialog.InitialDirectory = @"C:\";   //창이 뜨면 처음 보여줄 폴더 설정
            dialog.IsFolderPicker = true;

            if (dialog.ShowDialog() == CommonFileDialogResult.Ok)
            {
                ReportSettingModel.IOTestReport_Path = dialog.FileName;
            }
        }
        private void CoverageReportBrowser()
        {
            CommonOpenFileDialog dialog = new CommonOpenFileDialog();   //CommonOpenFileDialog 클래스 생성

            dialog.InitialDirectory = @"C:\";   //창이 뜨면 처음 보여줄 폴더 설정
            dialog.IsFolderPicker = true;

            if (dialog.ShowDialog() == CommonFileDialogResult.Ok)
            {
                ReportSettingModel.CodeCoverageReport_Path = dialog.FileName;
            }
        }
        private void PerformanceReportBrowser()
        {
            CommonOpenFileDialog dialog = new CommonOpenFileDialog();   //CommonOpenFileDialog 클래스 생성

            dialog.InitialDirectory = @"C:\";   //창이 뜨면 처음 보여줄 폴더 설정
            dialog.IsFolderPicker = true;

            if (dialog.ShowDialog() == CommonFileDialogResult.Ok)
            {
                ReportSettingModel.PerformanceMeasurementReport_Path = dialog.FileName;
            }
        }
    }
}
