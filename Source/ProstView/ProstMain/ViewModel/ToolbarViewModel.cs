using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using IronPython.Hosting;
using ProstMain.Model;
using ProstMain.Popup;
using ProstMain.Util;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Runtime.ExceptionServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Threading;
using static ProstMain.Util.CommonUtil;

namespace ProstMain.ViewModel
{
    public class ToolbarViewModel : ViewModelBase
    {

        public RelayCommand BuildTestCommand { get; set; }
        public RelayCommand AlreadyBuildTestCommand { get; set; }
        public RelayCommand RunTestCommand { get; set; }
        public RelayCommand RunAutoTestCommand { get; set; }
        public RelayCommand TestSpecConvertCommand { get; set; }
        public RelayCommand RunTestTrackbarCommand { get; set; }
        public RelayCommand ShowReportCommand { get; set; }
        public RelayCommand Trace32Command { get; set; }


        private ToolbarModel _ToolbarModel;
        public ToolbarModel ToolbarModel
        {
            get { return _ToolbarModel; }
            set
            {
                if (_ToolbarModel != value)
                {
                    _ToolbarModel = value;
                    RaisePropertyChanged("ToolbarModel");
                }
            }
        }

        public ToolbarViewModel()
        {
            BuildTestCommand = new RelayCommand(BuildTest);
            AlreadyBuildTestCommand = new RelayCommand(AlreadyBuildTest);
            RunTestCommand = new RelayCommand(RunTest);
            RunAutoTestCommand = new RelayCommand(RunAutoTest);
            TestSpecConvertCommand = new RelayCommand(TestSpecConvert);
            RunTestTrackbarCommand = new RelayCommand(RunTestTrackbar);
            Trace32Command = new RelayCommand(Trace32);
            ShowReportCommand = new RelayCommand(ShowReport);

            ToolbarModel = new ToolbarModel();
        }
        public void TestSpecConvert()
        {
            ToolbarModel.TestStartMode = Common.Common.TESTMODE_MANUAL;
            TestSpecConvertWork();
        }
        public void TestSpecConvertWork()
        {
            if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.ProjectExplorerModelList.Count == 0)
            {
                ViewModelLocator.MainVM.showTrackBarMessage("Project List is Empty");
                return;
            }

            ViewModelLocator.PopupTestCaseParsingVM.PopupTestCaseParsingModel.IsTestSpecConvertPopupOpen = false;

            Common.Common.m_PopupTestCaseParsingView = new PopupTestCaseParsingView();

            Common.Common.m_PopupTestCaseParsingView.Width = 650;
            Common.Common.m_PopupTestCaseParsingView.Height = 230;
            Common.Common.m_PopupTestCaseParsingView.Owner = App.Current.MainWindow;
            Dispatcher dispatcher = System.Windows.Application.Current.Dispatcher;
            DispatcherOperation dispatcherOperation = dispatcher.BeginInvoke(System.Windows.Threading.DispatcherPriority.Send, (ThreadStart)
            delegate ()
            {
                Common.Common.m_PopupTestCaseParsingView.ShowDialog();
            });

            if (ToolbarModel.TestStartMode == Common.Common.TESTMODE_AUTO)
                ViewModelLocator.PopupTestCaseParsingVM.TestCaseProduct();

        }
        public void RunTest()
        {
            if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.ProjectExplorerModelList.Count == 0)
            {
                ViewModelLocator.MainVM.showTrackBarMessage("Project List is Empty");
                return;
            }

            string[] elffiles = Directory.GetFiles(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TimeCreateFolderPath + "\\" + "Build", "*.elf");
            string[] mapfiles = Directory.GetFiles(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TimeCreateFolderPath + "\\" + "Build", "*.mapxml");

            if (elffiles.Length == 0 || mapfiles.Length == 0)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, "Build File Not Exist");
                return;
            }

            if(ViewModelLocator.PopupTestCaseParsingVM.PopupTestCaseParsingModel.IsTestSpecParserComplete != Common.Common.PASS)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, "Test Specification Not Parsed..");
                return;
            }

            FunctionWorkHandler.getInstance().T32CheckBeforeTest();
        }
        private void RunAutoTest()
        {
            ToolbarModel.TestStartMode = Common.Common.TESTMODE_AUTO;

            if (ViewModelLocator.PopupBuildStatusVM.PopupBuildStatusModel.DirectELFFilePath != "" || ViewModelLocator.PopupBuildStatusVM.PopupBuildStatusModel.DirectMapFilePath != "")
            {
                ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TimeCreateFolderPath = ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\" + "Gen" + "\\" + ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TestDate + "_" + ViewModelLocator.ProjectSettingVM.ProjectSettingModel.Comment;
                if (Directory.Exists(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TimeCreateFolderPath))
                    ViewModelLocator.PopupBuildStatusVM.DeleteBuildFolderDialogOK();
                else
                    ViewModelLocator.PopupBuildStatusVM.BuildTestWarningDialogOK();
            }
            else 
                Build();
        }
        private void RunTestTrackbar()
        {
            ViewModelLocator.MainVM.MainModel.IsTrackbarRunClick = true;
            FunctionWorkHandler.getInstance().Process_TestRun();
            ViewModelLocator.PopupTestStatusVM.PopupTestStatusModel.IsTestStart = false;
        }
        Thread thread;
        private void Trace32()
        {
            if (thread != null)
                thread.Abort();

            thread = new Thread(new ThreadStart(
            delegate ()
            {
                Trace32Handler.getInstance().TRACE32_CheckConnect();
            }));
            thread.IsBackground = true;
            thread.Start();
        }


        private void Build()
        {
            ToolbarModel.BuildMode = Common.Common.STANDARD;

            if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.ProjectExplorerModelList.Count == 0)
            {
                ViewModelLocator.MainVM.showTrackBarMessage("Project List is Empty");
                return;
            }

            ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TimeCreateFolderPath = ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\" + "Gen" + "\\" + ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TestDate + "_" + ViewModelLocator.ProjectSettingVM.ProjectSettingModel.Comment;

            if (Directory.Exists(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TimeCreateFolderPath))
            {
                if (ToolbarModel.TestStartMode == Common.Common.TESTMODE_MANUAL)
                    ViewModelLocator.PopupBuildStatusVM.ShowDialog_DeleteBuildFolder();
                else
                    ViewModelLocator.PopupBuildStatusVM.DeleteBuildFolderDialogOK();

            }
            else
            {
                ViewModelLocator.PopupBuildStatusVM.PopupBuildStatusModel.IsBuildStart = false;
                ViewModelLocator.PopupBuildStatusVM.PopupBuildStatusModel.ElfBuildProgress = 0;
                ViewModelLocator.PopupBuildStatusVM.ShowPopupBuildStatus();

            }
        }
        private void BuildTest()
        {
            ToolbarModel.TestStartMode = Common.Common.TESTMODE_MANUAL;
            Build();
        }
        private void AlreadyBuildTest()
        {

            ToolbarModel.BuildMode = Common.Common.ALREADY_ELF;
            if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.ProjectExplorerModelList.Count == 0)
            {
                ViewModelLocator.MainVM.showTrackBarMessage("Project List is Empty");
                return;
            }

            ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TimeCreateFolderPath = ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\" + "Gen" + "\\" + ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TestDate + "_" + ViewModelLocator.ProjectSettingVM.ProjectSettingModel.Comment;
            if (Directory.Exists(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TimeCreateFolderPath))
            {
                ViewModelLocator.PopupBuildStatusVM.ShowDialog_DeleteBuildFolder();
            }
            else
            {
                ViewModelLocator.PopupBuildStatusVM.ShowDialog_BuildTestWarning();
            }
        }

        private void ShowReport()
        {
            /*string parameter = "\"" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\" \"" + Common.Common.INSTALL_PATH + "\"";
            Process.Start(@"..\report\GraphProject.exe", parameter);*/

            string parameter = "\"" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\" \"" + "" + "\" \"" + "" + "\" \"" + "" + "\" \"" + Common.Common.INSTALL_PATH + "\"";
            try
            {
                Process.Start(@"..\report\GraphProject.exe", parameter);
            }
            catch (Exception ex)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, "Not Found Report Program");
            }
        }
    }
}
