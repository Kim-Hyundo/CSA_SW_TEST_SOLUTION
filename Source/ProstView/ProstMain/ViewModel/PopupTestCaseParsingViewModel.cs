using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using Microsoft.WindowsAPICodePack.Dialogs;
using ProstMain.Dialog;
using ProstMain.Model;
using ProstMain.Util;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Threading;

namespace ProstMain.ViewModel
{
    public class PopupTestCaseParsingViewModel : ViewModelBase
    {
        public RelayCommand TestCaseProductCommand { get; set; }
        public RelayCommand TestCasePathBrowserCommand { get; set; }
        public RelayCommand TestStatementBrowserCommand { get; set; }
        public RelayCommand TestSpecConvertDialogOKCommand { get; set; }

        public RelayCommand TestSpecConvertWarningDialogOKCommand { get; set; }
        public RelayCommand ParserSelectCommand { get; set; }
        public RelayCommand ParserSelectDialogOKCommand { get; set; }

        public RelayCommand DeleteTCFolderDialogOKCommand { get; set; }

        private PopupTestCaseParsingModel _PopupTestCaseParsingModel;
        public PopupTestCaseParsingModel PopupTestCaseParsingModel
        {
            get { return _PopupTestCaseParsingModel; }
            set
            {
                if (_PopupTestCaseParsingModel != value)
                {
                    _PopupTestCaseParsingModel = value;
                    RaisePropertyChanged("PopupTestCaseParsingModel");
                }
            }
        }

        public BackgroundWorker TestStatementWorker;
        private object TestStatementObject = new object();

        public PopupTestCaseParsingViewModel()
        {
            PopupTestCaseParsingModel = new PopupTestCaseParsingModel();

            TestCaseProductCommand = new RelayCommand(TestCaseProduct);
            TestCasePathBrowserCommand = new RelayCommand(TestCasePathBrowser);
            TestStatementBrowserCommand = new RelayCommand(TestStatementBrowser);
            TestSpecConvertDialogOKCommand = new RelayCommand(TestSpecConvertDialogOK);
            TestSpecConvertWarningDialogOKCommand = new RelayCommand(TestSpecConvertWarningDialogOK);

            ParserSelectCommand = new RelayCommand(ShowDialog_ParserSelect);
            ParserSelectDialogOKCommand = new RelayCommand(ParserSelectDialogOK);
            DeleteTCFolderDialogOKCommand = new RelayCommand(DeleteTCFolderDialogOK);
        }

        public void TestCaseProduct()
        {
            //ViewModelLocator.MainVM.ShowDialog_ParserSelect();
            if (PopupTestCaseParsingModel.TestStatement == null || PopupTestCaseParsingModel.TestStatement == "")
            {
                ViewModelLocator.MainVM.showTrackBarMessage("Test Statement Path Empty");
                return;
            }

            if (ViewModelLocator.PopupBuildStatusVM.PopupBuildStatusModel.IsElfSettingValue != Common.Common.PASS)
            {
                //ViewModelLocator.MainVM.showTrackBarMessage("Not Exist Build Folder");
                ShowDialog_TestSpecConvertWarning();
                return;
            }
            
            ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath = ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TimeCreateFolderPath + "\\" + Path.GetFileNameWithoutExtension(CommonUtil.GetRelativeToAbsolutePath(ViewModelLocator.PopupTestCaseParsingVM.PopupTestCaseParsingModel.TestStatement));
            if (Directory.Exists(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath))
            {
                if(ViewModelLocator.ToolbarVM.ToolbarModel.TestStartMode == Common.Common.TESTMODE_MANUAL)
                    ShowDialog_DeleteTCFolder();
                else
                    DeleteTCFolderDialogOK();
            }
            else
            {
                CommonUtil.ExitExcelProcess();
                ConvertTestCase();
            }

        }
        private void TestStatementBrowser()
        {
            CommonOpenFileDialog Browser = new CommonOpenFileDialog();
            if (Directory.Exists(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\TestCase"))
                Browser.InitialDirectory = ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\TestCase";
            Browser.IsFolderPicker = false;
            Browser.Filters.Add(new CommonFileDialogFilter("Excel File", ".xlsx"));

            if (Browser.ShowDialog() == CommonFileDialogResult.Ok)
                PopupTestCaseParsingModel.TestStatement = CommonUtil.GetAbsoluteToRelativePath(Browser.FileName);
        }
        private void TestCasePathBrowser()
        {
            CommonOpenFileDialog dialog = new CommonOpenFileDialog();   //CommonOpenFileDialog 클래스 생성

            dialog.InitialDirectory = @"C:\";   //창이 뜨면 처음 보여줄 폴더 설정
            dialog.IsFolderPicker = false;
            CommonFileDialogResult commonFileDialogResult = dialog.ShowDialog();

            if (commonFileDialogResult == CommonFileDialogResult.Ok)
            {
                PopupTestCaseParsingModel.TestcasePath = dialog.FileName;
            }
        }

        public void ConvertTestCase()
        {
            lock (TestStatementObject)
            {
                TestStatementWorker = new BackgroundWorker();

                TestStatementWorker.DoWork += FullTestStatementWorker_DoWork;
                TestStatementWorker.WorkerReportsProgress = true;
                TestStatementWorker.ProgressChanged += new ProgressChangedEventHandler(TestStatementWorker_ProgressChanged);
                TestStatementWorker.RunWorkerCompleted += TestStatementWorker_DoWorkComplete;
                TestStatementWorker.RunWorkerAsync();
            }
        }
        public void WithoutBuildTestStatement()
        {
            CommonUtil.ExitExcelProcess();

            DirectoryInfo TestCaseFolder = new DirectoryInfo(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Temp\\TestCase");
            if (!TestCaseFolder.Exists)
                TestCaseFolder.Create();

            PythonHandler.getInstance().makeProjectDataOnlyTestCase(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Temp");
            lock (TestStatementObject)
            {
                TestStatementWorker = new BackgroundWorker();

                TestStatementWorker.DoWork += TestStatementWorker_DoWork;
                TestStatementWorker.WorkerReportsProgress = true;
                TestStatementWorker.ProgressChanged += new ProgressChangedEventHandler(TestStatementWorker_ProgressChanged);
                TestStatementWorker.RunWorkerCompleted += TestStatementWorker_DoWorkComplete;
                TestStatementWorker.RunWorkerAsync();
            }
        }
        private void FullTestStatementWorker_DoWork(object sender, DoWorkEventArgs e)
        {
            Dispatcher dispatcher = System.Windows.Application.Current.Dispatcher;
            DispatcherOperation dispatcherOperation = dispatcher.BeginInvoke(System.Windows.Threading.DispatcherPriority.Send, (ThreadStart)
            delegate ()
            {
                PopupTestCaseParsingModel.IsTestCaseProduction = "Running";
            });

            DirectoryInfo di = new DirectoryInfo(path: ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\" + "Cmm");
            di.Create();
            di = new DirectoryInfo(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\" + "Cmm" + "\\" + "Sequence");
            di.Create();
            di = new DirectoryInfo(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\" + "Debug");
            di.Create();
            di = new DirectoryInfo(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\" + "Debug" + "\\" + "dic");
            di.Create();
            di = new DirectoryInfo(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\" + "Debug" + "\\" + "dic" + "\\" + "project_info");
            di.Create();
            di = new DirectoryInfo(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\" + "Debug" + "\\" + "txt");
            di.Create();
            di = new DirectoryInfo(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath + "\\" + "TestCase");
            di.Create();

            PythonHandler.getInstance().makeProjectData();

            PopupTestCaseParsingModel.IsTestcaseParserComplete = Common.Common.DEFAULT;

            PythonHandler.getInstance().TestStatement();
        }
        private void TestStatementWorker_DoWork(object sender, DoWorkEventArgs e)
        {
            PopupTestCaseParsingModel.IsTestcaseParserComplete = Common.Common.DEFAULT;
            PopupTestCaseParsingModel.IsTestCaseProduction = "Running";

            PythonHandler.getInstance().TestStatement();

        }
        private void TestStatementWorker_ProgressChanged(object sender, ProgressChangedEventArgs e)
        {
            Console.WriteLine("" + e.ProgressPercentage);
        }
        private void TestStatementWorker_DoWorkComplete(object sender, RunWorkerCompletedEventArgs e)
        {
            PopupTestCaseParsingModel.IsTestCaseProduction = "Stop";
        }
        public bool checkTestSettingData()
        {
            bool returnValue = true;
            if (PopupTestCaseParsingModel.TestStatement == null || PopupTestCaseParsingModel.TestStatement.Equals(""))
                returnValue = false;
            if (PopupTestCaseParsingModel.TestcasePath == null || PopupTestCaseParsingModel.TestcasePath.Equals(""))
                returnValue = false;

            return returnValue;
        }
        public void CloseTestCasePopupView()
        {
            PopupTestCaseParsingModel.IsTestSpecConvertPopupOpen = false;
            Common.Common.m_PopupTestCaseParsingView.Close();
        }
        private void TestSpecConvertDialogOK()
        {
            PopupTestCaseParsingModel.IsTestSpecConvertPopupOpen = false;
            Common.Common.m_PopupTestCaseParsingView.Close();
        }
        public void ShowDialog_TestSpecConvertWarning()
        {
            ViewModelLocator.MainVM.MainModel.DialogContent = new TestSpecConvertWarningDialogView();
            ViewModelLocator.MainVM.MainModel.isDialogOpen = true;
        }


        private void TestSpecConvertWarningDialogOK()
        {
            WithoutBuildTestStatement();
            ViewModelLocator.MainVM.MainModel.isDialogOpen = false;
        }
        public void TestSpecConverFinish(int result)
        {
            if (result == Common.Common.PASS)
            {
                ViewModelLocator.MainVM.MainModel.PopupDialogText = "TestCase Creation Complete";
                PopupTestCaseParsingModel.IsTestSpecParserComplete = Common.Common.PASS;
                if(ViewModelLocator.PopupBuildStatusVM.PopupBuildStatusModel.IsElfSettingValue == Common.Common.PASS)
                    ViewModelLocator.ToolbarVM.ToolbarModel.IsTestStartEnable = true;
            }
            else
            {
                ViewModelLocator.MainVM.MainModel.PopupDialogText = "TestCase Creation Failure";
                PopupTestCaseParsingModel.IsTestSpecParserComplete = Common.Common.FAIL;
            }

            PopupTestCaseParsingModel.IsTestSpecConvertPopupOpen = true;
        }
        public void ShowDialog_ParserSelect()
        {
            ViewModelLocator.MainVM.MainModel.DialogContent = new ParserSelectDIalogView();
            ViewModelLocator.MainVM.MainModel.isDialogOpen = true;
        }
        private void ParserSelectDialogOK()
        {
            ViewModelLocator.MainVM.MainModel.isDialogOpen = false;
            if (PopupTestCaseParsingModel.ParserSelectedItem == null || PopupTestCaseParsingModel.ParserSelectedItem == "")
                return;

            TestCaseProduct();
        }
        public void DeleteTCFolderDialogOK()
        {
            ViewModelLocator.MainVM.MainModel.DialogContent = new ProgressBarDialogView();
            ViewModelLocator.MainVM.MainModel.isDialogOpen = true;
            BackgroundWorker DeleteTCFolderWorker = new BackgroundWorker();

            DeleteTCFolderWorker.DoWork += (obj, e) => DeleteTCFolderWorker_DoWork("");
            DeleteTCFolderWorker.RunWorkerCompleted += DeleteTCFolderWorker_RunWorkerCompleted;
            DeleteTCFolderWorker.RunWorkerAsync();
        }
        private void DeleteTCFolderWorker_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
        {
            ViewModelLocator.MainVM.MainModel.isDialogOpen = false;

            if (e.Error != null)
            {
                //ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, e.Error.Message);
                return;
            }

            ViewModelLocator.PopupTestCaseParsingVM.ConvertTestCase();
        }

        private void DeleteTCFolderWorker_DoWork(string p)
        {
            try
            {
                DirectoryInfo di = new DirectoryInfo(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.FolderByTestCasePath);
                CommonUtil.ClearAttributes(di.FullName);
                di.Delete(true);
            }
            catch (Exception ex)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, "파일 및 폴더가 열려있거나, 접근할 수 없습니다.");
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, typeof(MainViewModel).Name + " :: " + ex.Message + " Line :: " + CommonUtil.GetExceptionLineNumber(ex));
                throw;
            }
        }
        public void ShowDialog_DeleteTCFolder()
        {
            ViewModelLocator.MainVM.MainModel.DialogContent = new DeleteTCFolderDialogView();
            ViewModelLocator.MainVM.MainModel.isDialogOpen = true;
        }
    }
}
