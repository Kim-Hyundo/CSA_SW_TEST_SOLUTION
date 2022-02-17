using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using Javi.ExplorerTreeView;
using MaterialDesignThemes.Wpf;
using Microsoft.Win32;
using Microsoft.WindowsAPICodePack.Dialogs;
using ProstMain.Common;
using ProstMain.Dialog;
using ProstMain.Model;
using ProstMain.Popup;
using ProstMain.Util;
using ProstMain.View;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Runtime.ExceptionServices;
using System.Runtime.InteropServices;
using System.Security;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Forms;
using System.Windows.Media;
using System.Windows.Threading;
using System.Xml;
using WSF.Interfaces;

namespace ProstMain.ViewModel
{
    public class MainViewModel : ViewModelBase
    {
        // Window Command
        public RelayCommand<object> HideWindowCommand { get; set; }
        public RelayCommand<object> ShowWindowCommand { get; set; }

        // Show DialogView
        public RelayCommand CreateProjectCommand { get; set; }
        public RelayCommand<object> SaveProjectCommand { get; set; }
        public RelayCommand<object> DeleteProjectCommand { get; set; }
        public RelayCommand LogFilterCommand { get; set; }
        public RelayCommand SearchLastTestCommand { get; set; }
        

        // DialogView OK Command
        public RelayCommand<object> CreateProjectDialogOKCommand { get; set; }
        public RelayCommand<object> DeleteProjectDialogOKCommand { get; set; }
        
        public RelayCommand<object> SaveProjectDialogOKCommand { get; set; }
        public RelayCommand<object> LogFilterDialogOKCommand { get; set; }
        public RelayCommand<object> ImportProjectDialogOKCommand { get; set; }
        public RelayCommand<object> ExportPojectDialogOKCommand { get; set; }

        // File&Folder Browser
        public RelayCommand ImportProjectDialogBrowserCommand { get; set; }
        public RelayCommand ExportProjectDialogBrowserCommand { get; set; }
        

        // Import&Export PropertyCheck
        public RelayCommand ImportProjectCheckAllCommand { get; set; }
        public RelayCommand ExportProjectCheckAllCommand { get; set; }

        // DialogView Cancel Command
        public RelayCommand<object> DialogCancelCommand { get; set; }


        // SubWindow Command
        public RelayCommand ShowLogWindowCommand { get; set; }
        public RelayCommand CloseLogWindowCommand { get; set; }

        // Program Exit
        public RelayCommand<object> ExitProgramCommand { get; set; }



        private MainModel _MainModel;
        public MainModel MainModel
        {
            get { return _MainModel; }
            set
            {
                if (_MainModel != value)
                {
                    _MainModel = value;
                    RaisePropertyChanged("MainModel");
                }
            }
        }

        public MainViewModel()
        {
            CreateProjectCommand = new RelayCommand(ShowDialog_CreateProject);
            SaveProjectCommand = new RelayCommand<object>(ShowDialog_SaveProject);
            LogFilterCommand = new RelayCommand(ShowDialog_LogFilter);
            DeleteProjectCommand = new RelayCommand<object>(ShowDialog_DeleteProject);

            SearchLastTestCommand = new RelayCommand(ShowDialog_SearchLastTest);

            CreateProjectDialogOKCommand = new RelayCommand<object>(CreateProjectDialogOK);
            DeleteProjectDialogOKCommand = new RelayCommand<object>(DeleteProjectDialogOK);
            
            SaveProjectDialogOKCommand = new RelayCommand<object>(SaveProjectDialogOK);
            LogFilterDialogOKCommand = new RelayCommand<object>(LogFilterDialogOK);
            ImportProjectDialogOKCommand = new RelayCommand<object>(ImportProjectDialogOK);
            ImportProjectCheckAllCommand = new RelayCommand(ImportProjectCheckAll);
            ExportProjectCheckAllCommand = new RelayCommand(ExportProjectCheckAll);
            ExportPojectDialogOKCommand = new RelayCommand<object>(ExportPojectDialogOK);

            ImportProjectDialogBrowserCommand = new RelayCommand(ImportProjectDialogBrowser);
            ExportProjectDialogBrowserCommand = new RelayCommand(ExportProjectDialogBrowser);

            DialogCancelCommand = new RelayCommand<object>(DialogCancel);

            HideWindowCommand = new RelayCommand<object>(HideWindow);
            ShowWindowCommand = new RelayCommand<object>(ShowWindow);
            ShowLogWindowCommand = new RelayCommand(ShowLogWindow);
            CloseLogWindowCommand = new RelayCommand(CloseLogWindow);

            ExitProgramCommand = new RelayCommand<object>(ExitProgram);

            MainModel = new MainModel();

            ReadTrace32Info();

        }
        private void ReadTrace32Info()
        {
            try
            {
                DirectoryInfo d = new DirectoryInfo(@"..\etc");
                FileInfo[] Files = d.GetFiles("*.plc");

                if (Files.Length == 0)
                    return;
                else
                {
                    string[] licenseFile = FileManager.FileRead(Files[0].FullName);

                    for (int i = 0; i < licenseFile.Length; i++)
                    {
                        string[] temp = licenseFile[i].Split(new string[] { "=" }, StringSplitOptions.None);

                        if (temp[0].Equals("TRACE32 IP Address"))
                            ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.Trace32IPAddress = temp[1];
                        else if (temp[0].Equals("UserName"))
                            ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.LicenseData_UserName = temp[1];
                        else if (temp[0].Equals("LicenseIssuedDate"))
                            ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.LicenseData_IssuedDate = temp[1];
                        else if (temp[0].Equals("LicenseExpirationDate"))
                            ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.LicenseData_ExpirationDate = temp[1];
                        else if (temp[0].Equals("SupportArchitecture"))
                        {
                            if (!ViewModelLocator.TargetHWSettingVM.ManufacturerList.Contains(temp[1]))
                                ViewModelLocator.TargetHWSettingVM.ManufacturerList.Add(temp[1]);
                        }
                        /*                        else if (temp[0].Equals("SupportMCU"))
                                                {
                                                    ViewModelLocator.TargetHWSettingVM.CPUList.Add(temp[1]);
                                                }*/
                    }
                }

                ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.Trace32Version = FileVersionInfo.GetVersionInfo(@"..\src\lib\T32\bin\windows64\t32mtc.exe").FileVersion;
                DirectoryInfo a = new DirectoryInfo(@"..\src\lib\T32\bin\windows64");
                ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.Trace32InstallPath = a.FullName;
            }
            catch (Exception ex)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, typeof(MainViewModel).Name + " :: " + ex.Message + " Line :: " + CommonUtil.GetExceptionLineNumber(ex));
            }

        }
        #region SHOWDIALOG
        public void ShowDialog_CreateProject()
        {
            MainModel.DialogContent = new CreateProjectDialogView();
            MainModel.isDialogOpen = true;
        }
        public void ShowDialog_DeleteProject()
        {
            MainModel.DialogContent = new DeleteProjectDialogView(ViewModelLocator.ProjectExplorerVM.SelectProjectName);
            MainModel.isDialogOpen = true;
        }
        public void ShowDialog_SaveProject(object e)
        {
            if (e != null)
            {
                string project_name = ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName;
                MainModel.DialogContent = new SaveProjectDialogView(project_name);
                MainModel.isDialogOpen = true;
            }
            else
            {
                ViewModelLocator.WorkSpaceVM.ChangeWorkSpace();
            }
        }
        public void ShowDialog_ImportProjectProperty()
        {
            Util.InvFileManager.initImportCheckData();

            MainModel.DialogContent = new ImportProjectDialogView(ViewModelLocator.ProjectExplorerVM.SelectProjectName);
            MainModel.isDialogOpen = true;


        }
        public void ShowDialog_ExportProjectProperty()
        {
            Util.InvFileManager.initExportCheckData();

            //Util.InvFileManager.CheckImportInvFile(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.ProjectExplorerVM.SelectProjectName + "\\T15_Env_Config\\T15_ProjectCfg.csa");

            MainModel.DialogContent = new ExportProjectDialogView(ViewModelLocator.ProjectExplorerVM.SelectProjectName);
            MainModel.isDialogOpen = true;
        }

        private void ShowDialog_LogFilter()
        {
            MainModel.DialogContent = new LogFilterDialogView();
            MainModel.isDialogOpen = true;
        }
        private void ShowDialog_DeleteProject(object e)
        {
            ProjectExplorerListModel projectExplorerListModel = (ProjectExplorerListModel)e;
            MainModel.DialogContent = new DeleteProjectDialogView(projectExplorerListModel.ItemName);
            MainModel.isDialogOpen = true;
        }

        public void ShowDialog_AboutProst()
        {
            MainModel.DialogContent = new AboutProstDialogView();
            MainModel.isDialogOpen = true;
        }
        private void ShowDialog_SearchLastTest()
        {
            MainModel.DialogContent = new SearchLastTestDialogView();
            MainModel.isDialogOpen = true;
        }
        public void ShowDialog_CreateFolder()
        {
            MainModel.DialogContent = new CreateFolderDialogView();
            MainModel.isDialogOpen = true;
        }
        #endregion

        
        private void CreateProjectDialogOK(object e)
        {
            string param = e.ToString();
            if (param == null || param == "")
                return;

            ViewModelLocator.ProjectExplorerVM.CreateNewProject(e.ToString());
            MainModel.isDialogOpen = false;
        }
        private void DeleteProjectDialogOK(object e)
        {
            MainModel.isDialogOpen = false;

            ViewModelLocator.ProjectExplorerVM.DeleteProject(e.ToString(), MainModel.isDeleteProjectList);
            MainModel.isDeleteProjectList = false;
        }


       
       
        private void SaveProjectDialogOK(object e)
        {
            ViewModelLocator.ProjectExplorerVM.SaveProject();
            MainModel.isDialogOpen = false;

        }
        private void ImportProjectDialogOK(object e)
        {
            bool result = Util.InvFileManager.ImportInvFile();

            if (result)
            {
                MainModel.isDialogOpen = false;
                showTrackBarMessage("Import Project File");
            }

        }
        private void ExportProjectCheckAll()
        {
            if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExportCheckedAllList)
            {
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportComment)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedComment = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCompilerOption)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCompilerOption = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCompilerPath)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCompilerPath = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCompilerType)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCompilerType = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCompilerVersion)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCompilerVersion = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCpuClock)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCpuClock = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCpuName)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCpuName = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCoreIndex)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCoreIndex = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportIncludePath)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedIncludePath = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportInitFunction)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedInitFunction = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportLibrary)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedLibrary = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportFrequency)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedFrequency = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportLinkerOption)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedLinkerOption = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportLogLevel)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedLogLevel = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportRegisterList)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedRegisterList = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportResolution)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedResolution = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportRunnableList)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedRunnableList = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportRunnableStubList)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedRunnableStubList = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportTester)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedTester = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportTestStatement)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedTestStatement = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCopyPathList)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCopyPathList = true;
            }
            else
            {
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportComment)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedComment = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCompilerOption)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCompilerOption = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCompilerPath)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCompilerPath = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCompilerType)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCompilerType = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCompilerVersion)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCompilerVersion = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCpuClock)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCpuClock = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCpuName)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCpuName = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCoreIndex)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCoreIndex = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportIncludePath)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedIncludePath = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportInitFunction)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedInitFunction = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportLibrary)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedLibrary = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportFrequency)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedFrequency = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportLinkerOption)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedLinkerOption = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportLogLevel)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedLogLevel = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportRegisterList)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedRegisterList = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportResolution)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedResolution = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportRunnableList)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedRunnableList = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportRunnableStubList)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedRunnableStubList = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportTester)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedTester = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportTestStatement)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedTestStatement = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCopyPathList)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCopyPathList = false;
            }
        }
        private void ImportProjectCheckAll()
        {
            if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsImportCheckedAllList)
            {
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportComment)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedComment = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCompilerOption)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCompilerOption = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCompilerPath)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCompilerPath = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCompilerType)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCompilerType = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCompilerVersion)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCompilerVersion = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCpuClock)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCpuClock = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCpuName)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCpuName = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCoreIndex)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCoreIndex = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportIncludePath)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedIncludePath = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportInitFunction)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedInitFunction = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportLibrary)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedLibrary = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportFrequency)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedFrequency = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportLinkerOption)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedLinkerOption = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportLogLevel)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedLogLevel = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportRegisterList)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedRegisterList = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportResolution)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedResolution = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportRunnableList)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedRunnableList = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportRunnableStubList)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedRunnableStubList = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportTester)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedTester = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportTestStatement)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedTestStatement = true;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCopyPathList)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCopyPathList = true;
            }
            else
            {
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportComment)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedComment = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCompilerOption)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCompilerOption = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCompilerPath)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCompilerPath = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCompilerType)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCompilerType = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCompilerVersion)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCompilerVersion = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCpuClock)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCpuClock = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCpuName)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCpuName = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCoreIndex)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCoreIndex = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportIncludePath)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedIncludePath = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportInitFunction)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedInitFunction = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportLibrary)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedLibrary = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportFrequency)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedFrequency = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportLinkerOption)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedLinkerOption = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportLogLevel)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedLogLevel = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportRegisterList)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedRegisterList = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportResolution)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedResolution = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportRunnableList)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedRunnableList = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportRunnableStubList)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedRunnableStubList = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportTester)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedTester = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportTestStatement)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedTestStatement = false;
                if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsExistImportCopyPathList)
                    ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.IsCheckedCopyPathList = false;
            }
        }
        private void ExportPojectDialogOK(object e)
        {
            bool result = Util.InvFileManager.ExportInvFile();

            if (result)
            {
                MainModel.isDialogOpen = false;
                showTrackBarMessage("Export Project File");
            }
        }
        private void LogFilterDialogOK(object e)
        {
            ViewModelLocator.CommandVM.LogFilter();
            MainModel.isDialogOpen = false;
        }
        private void ImportProjectDialogBrowser()
        {
            Microsoft.Win32.OpenFileDialog dialog = new Microsoft.Win32.OpenFileDialog();
            dialog.InitialDirectory = ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath;
            dialog.Filter = "csa Files (*.csa)|*.csa";

            if (dialog.ShowDialog() == true)
            {
                Util.InvFileManager.initImportCheckData();
                // .inv파일의 Property를 가져올 수 있는지 확인
                ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.ImportProjectPath = dialog.FileName;

                Util.InvFileManager.CheckImportInvFile(ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.ImportProjectPath);
            }
        }
        private void ExportProjectDialogBrowser()
        {
            CommonOpenFileDialog dialog = new CommonOpenFileDialog();
            dialog.InitialDirectory = @"C:";
            dialog.IsFolderPicker = true;
            if (dialog.ShowDialog() == CommonFileDialogResult.Ok)
            {
                ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.ExporttProjectPath = dialog.FileName;
            }
        }
        
        protected XmlNode createnode(XmlDocument xmlDoc, string name, string innerXml)
        {
            XmlNode node = xmlDoc.CreateElement(string.Empty, name, string.Empty);
            node.InnerXml = innerXml;

            return node;
        }

        [HandleProcessCorruptedStateExceptions]
        [SecurityCritical]
        private void DialogCancel(object obj)
        {
            MainModel.isDialogOpen = false;
            if (obj != null && obj.ToString().Equals("Save"))
            {
                switch (ViewModelLocator.MainVM.MainModel.BeforeSaveMode)
                {
                    case Common.Common.EXIT: // 종료
                        if (ViewModelLocator.MainVM.MainModel.IsTrace32Connection)
                        {
                            try
                            {
                                Trace32Handler.TRACE32_DLL.T32_SetChannel(Trace32Handler.ChannelT32Main);
                                Trace32Handler.TRACE32_DLL.T32_Cmd("QUIT");
                                Trace32Handler.TRACE32_DLL.T32_Exit();
                                Thread.Sleep(10);
                            }
                            catch (System.AccessViolationException exception) { Console.WriteLine(exception.Message); }
                            try
                            {
                                Trace32Handler.TRACE32_DLL.T32_SetChannel(Trace32Handler.ChannelT32SimulAnalysis);
                                Trace32Handler.TRACE32_DLL.T32_Cmd("QUIT");
                                Trace32Handler.TRACE32_DLL.T32_Exit();
                                Thread.Sleep(10);
                            }
                            catch (System.AccessViolationException exception) { Console.WriteLine(exception.Message); }
                            try
                            {
                                Trace32Handler.TRACE32_DLL.T32_SetChannel(Trace32Handler.ChannelT32SimulMerge);
                                Trace32Handler.TRACE32_DLL.T32_Cmd("QUIT");
                                Trace32Handler.TRACE32_DLL.T32_Exit();
                            }
                            catch (System.AccessViolationException exception) { Console.WriteLine(exception.Message); }
                        }

                        System.Diagnostics.Process.GetCurrentProcess().Kill();

                        break;
                    case Common.Common.WORKSPACE_CHANGE:
                        ViewModelLocator.WorkSpaceVM.ChangeWorkSpace();
                        break;
                    case Common.Common.SAVE_MODE:
                        break;
                }
            }
            else if (obj != null && obj.ToString().Equals("CreateProject"))
            {

            }
        }
        private void HideWindow(object e)
        {
            if (e != null)
            {
                if (Common.Common.m_PopupTestStatusView != null)
                {
                    Common.Common.m_PopupTestStatusView.Hide();
                }

                m_MainWindow = (System.Windows.Window)e;
                m_MainWindow.Hide();

                MainModel.isTrackBarVisible = Visibility.Visible;
                MainModel.isPopupOpen = true;
            }
        }

        private System.Windows.Window m_MainWindow;
        private void ShowWindow(object e)
        {
            if (m_MainWindow != null)
            {
                if (MainModel.IsTrackbarRunClick)
                {
                    Common.Common.m_PopupTestStatusView = new PopupTestStatusView();
                    MainModel.IsTrackbarRunClick = false;
                }
                
                if (Common.Common.m_PopupTestStatusView != null)
                {
                    Common.Common.m_PopupTestStatusView.Owner = App.Current.MainWindow;
                    Common.Common.m_PopupTestStatusView.Show();
                    ViewModelLocator.ToolbarVM.ToolbarModel.IsToolbarEnable = false;
                    ViewModelLocator.MenuBarVM.IsMenubarEnable = false;
                }

                m_MainWindow.Show();
                MainModel.isTrackBarVisible = Visibility.Collapsed;
                MainModel.isPopupOpen = false;

                if (m_PopupLogWIndow != null && m_PopupLogWIndow.ShowActivated)
                    m_PopupLogWIndow.Close();
            }
        }
        

        PopupLogView m_PopupLogWIndow;
        private void ShowLogWindow()
        {
            if (m_PopupLogWIndow == null)
            {
                m_PopupLogWIndow = new PopupLogView();
                m_PopupLogWIndow.Width = 600;
                m_PopupLogWIndow.Height = 500;
            }
            m_PopupLogWIndow.ShowDialog();

        }
        private void CloseLogWindow()
        {
            if (m_PopupLogWIndow != null)
            {
                m_PopupLogWIndow.Close();
                m_PopupLogWIndow = null;
            }
        }

        public void showTrackBarMessage(string message)
        {
            Task.Factory.StartNew(() => MainModel.TrackBarMessageQueue.Enqueue(message, null, null, null, false, true, TimeSpan.FromSeconds(1)));
        }


        public void ExitProgram(object e)
        {
            if (e != null)
            {
                if (e.ToString().Equals("workspace"))
                {
                    System.Diagnostics.Process.GetCurrentProcess().Kill();
                }
                else
                {
                    if(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName == null || ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName == "")
                    {
                        System.Diagnostics.Process.GetCurrentProcess().Kill();
                    }

                    ViewModelLocator.MainVM.MainModel.BeforeSaveMode = Common.Common.EXIT;
                    ViewModelLocator.MainVM.ShowDialog_SaveProject(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName);
                }
            }
        }
        public BackgroundWorker ParsingExcelDataWorker;
        private object ParsingExcelDataObject = new object();
        public void ParsingLastTestData(int mode, string buildPath, string testcasePath, string senarioPath)
        {
            lock (ParsingExcelDataObject)
            {
                if (mode == Common.Common.SELECT_INIT) // Init
                {

                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TestSenarioList.Clear();
                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TestFolderList.Clear();
                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.BuildFolderList.Clear();
                }
                else if (mode == Common.Common.SELECT_BUILD)
                {
                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TestSenarioList.Clear();
                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TestFolderList.Clear();
                }
                else if (mode == Common.Common.SELECT_TESTCASE) // select Folderlist
                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TestSenarioList.Clear();


                ParsingExcelDataWorker = new BackgroundWorker();

                ParsingExcelDataWorker.DoWork += (obj, e) => ParsingExcelDataWorker_DoWork(mode, buildPath, testcasePath, senarioPath, e);
                ParsingExcelDataWorker.WorkerReportsProgress = true;
                ParsingExcelDataWorker.RunWorkerCompleted += ParsingExcelDataWorker_DoWorkComplete;
                ParsingExcelDataWorker.WorkerSupportsCancellation = true;
                ParsingExcelDataWorker.RunWorkerAsync();
                ViewModelLocator.ProjectSettingVM.ProjectSettingModel.IsRunningExcel = Common.Common.TRUE;
            }
        }

        bool InitFlag;
        private void ParsingExcelDataWorker_DoWork(int mode, string buildPath, string folderPath, string senarioPath, DoWorkEventArgs e)
        {
            ViewModelLocator.ProjectSettingVM.ProjectSettingModel.LastTest_Comment = "";
            ViewModelLocator.ProjectSettingVM.ProjectSettingModel.LastTest_SWComponent = "";
            ViewModelLocator.ProjectSettingVM.ProjectSettingModel.LastTest_TestCoverage_Pass = "";
            ViewModelLocator.ProjectSettingVM.ProjectSettingModel.LastTest_TestCoverage_Fail = "";
            ViewModelLocator.ProjectSettingVM.ProjectSettingModel.LastTest_Time = "";
            ViewModelLocator.ProjectSettingVM.ProjectSettingModel.LastTest_MemUseage = "";
            ViewModelLocator.ProjectSettingVM.ProjectSettingModel.LastTest_StatementCoverage = "";
            ViewModelLocator.ProjectSettingVM.ProjectSettingModel.LastTest_CallCoverage = "";
            ViewModelLocator.ProjectSettingVM.ProjectSettingModel.LastTest_FunctionCoverage = "";

            var engine = IronPython.Hosting.Python.CreateEngine();
            var scope = engine.CreateScope();

            ICollection<string> searchPaths = engine.GetSearchPaths();

            searchPaths.Add(@"..\src\lib\IronPython 2.7\Lib");
            searchPaths.Add(@"..\src\lib\common\Pickle");
            searchPaths.Add(@"..\src\compiler\python");
            searchPaths.Add(@"..\src\parser\python");
            searchPaths.Add(@"..\src\Parser\python\Lib");
            engine.SetSearchPaths(searchPaths);

            var source = engine.CreateScriptSourceFromFile(@"..\src\lib\common\Pickle\test_pickle.py");
            source.Execute(scope);


            if (mode == Common.Common.SELECT_INIT) // Init
            {
                try
                {
                    InitFlag = true;
                    foreach (string s in Directory.GetDirectories(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Gen"))
                    {
                        if (Path.GetFileNameWithoutExtension(s) != "Build" && Directory.GetFiles(s, "*.csv", SearchOption.AllDirectories).Length > 0)
                        {
                            System.Windows.Application.Current.Dispatcher.Invoke(new Action(() =>
                            {
                                ViewModelLocator.ProjectSettingVM.ProjectSettingModel.BuildFolderList.Add(s);
                            }));
                        }
                    }

                    if (ViewModelLocator.ProjectSettingVM.ProjectSettingModel.BuildFolderList.Count > 0)
                        ViewModelLocator.ProjectSettingVM.ProjectSettingModel.SelectedBuildFolder = ViewModelLocator.ProjectSettingVM.ProjectSettingModel.BuildFolderList[ViewModelLocator.ProjectSettingVM.ProjectSettingModel.BuildFolderList.Count - 1];
                    else
                        return;

                    foreach (string s in Directory.GetDirectories(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.SelectedBuildFolder))
                    {
                        if (Directory.GetFiles(s, "*.csv", SearchOption.AllDirectories).Length > 0)
                        {
                            System.Windows.Application.Current.Dispatcher.Invoke(new Action(() =>
                            {
                                ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TestFolderList.Add(s);
                            }));
                        }
                    }

                    if (ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TestFolderList.Count > 0)
                        ViewModelLocator.ProjectSettingVM.ProjectSettingModel.SelectedTestFolder = ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TestFolderList[ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TestFolderList.Count - 1];
                    else
                        return;

                    var Origin_TC_Load_init = scope.GetVariable<Func<string, object>>("Origin_TC_Load");

                    IronPython.Runtime.PythonDictionary Summary_Data_Tmp_init = (IronPython.Runtime.PythonDictionary)Origin_TC_Load_init(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.SelectedTestFolder + "\\" + @"Debug\dic\project_info\R_test_dictionary.txt");
                    IronPython.Runtime.PythonDictionary ReportSummary_Data_Tmp_init = (IronPython.Runtime.PythonDictionary)Origin_TC_Load_init(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.SelectedTestFolder + "\\" + @"Debug\dic\report_summary\report_summary.txt");
                    IronPython.Runtime.PythonDictionary Statement_Cov_Data_Tmp_init = null;
                    IronPython.Runtime.PythonDictionary Function_Cov_Data_Tmp_init = null;
                    IronPython.Runtime.PythonDictionary Call_Cov_Data_Tmp_init = null;
                    if (File.Exists(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.SelectedTestFolder + "\\" + @"\Debug\dic\coverage\cov\cov_merge.txt"))
                        Statement_Cov_Data_Tmp_init = (IronPython.Runtime.PythonDictionary)Origin_TC_Load_init(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.SelectedTestFolder + "\\" + @"\Debug\dic\coverage\cov\cov_merge.txt");

                    if (File.Exists(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.SelectedTestFolder + "\\" + @"Debug\dic\funccov\dic_func_cov_result.txt"))
                        Function_Cov_Data_Tmp_init = (IronPython.Runtime.PythonDictionary)Origin_TC_Load_init(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.SelectedTestFolder + "\\" + @"Debug\dic\funccov\dic_func_cov_result.txt");

                    if (File.Exists(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.SelectedTestFolder + "\\" + @"Debug\dic\callccov\dic_call_cov_result.txt"))
                        Call_Cov_Data_Tmp_init = (IronPython.Runtime.PythonDictionary)Origin_TC_Load_init(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.SelectedTestFolder + "\\" + @"Debug\dic\callccov\dic_call_cov_result.txt");

                    foreach (string key in ReportSummary_Data_Tmp_init.keys())
                    {
                        System.Windows.Application.Current.Dispatcher.Invoke(new Action(() =>
                        {
                            ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TestSenarioList.Add(key);
                        }));
                    }
                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.SelectedSenario = ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TestSenarioList[ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TestSenarioList.Count - 1];

                    foreach (string key in Summary_Data_Tmp_init.keys())
                    {
                        if (key.Equals("Test Comment"))
                            ViewModelLocator.ProjectSettingVM.ProjectSettingModel.LastTest_Comment = Summary_Data_Tmp_init[key].ToString();
                        else if (key.Equals("Date/Time"))
                            ViewModelLocator.ProjectSettingVM.ProjectSettingModel.LastTest_Time = Summary_Data_Tmp_init[key].ToString().Substring(0, 4) + "/" + Summary_Data_Tmp_init[key].ToString().Substring(4, 2) + "/" + Summary_Data_Tmp_init[key].ToString().Substring(6, 2) + " " + Summary_Data_Tmp_init[key].ToString().Substring(8, 2) + ":" + Summary_Data_Tmp_init[key].ToString().Substring(10, 2);
                        else if (key.Equals("Test Project"))
                            ViewModelLocator.ProjectSettingVM.ProjectSettingModel.LastTest_SWComponent = Summary_Data_Tmp_init[key].ToString();
                    }


                    IronPython.Runtime.PythonDictionary ReportSummary_Senario_Data = ((IronPython.Runtime.PythonDictionary)ReportSummary_Data_Tmp_init[ViewModelLocator.ProjectSettingVM.ProjectSettingModel.SelectedSenario]);

                    IronPython.Runtime.List Total_Memory = (IronPython.Runtime.List)ReportSummary_Senario_Data["Memory Usage"];
                    string passRate = ReportSummary_Senario_Data["Pass Rate"].ToString().Replace("%", "");
                    string failRate = ReportSummary_Senario_Data["Fail Rate"].ToString().Replace("%", "");

                    string passCount = ReportSummary_Senario_Data["Pass Count"].ToString();
                    string failCount = ReportSummary_Senario_Data["Fail Count"].ToString();

                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.LastTest_TestCoverage_Pass = passCount + " (" + Math.Round(Convert.ToDouble(passRate), 2) + "%) ";
                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.LastTest_TestCoverage_Fail = " " + failCount + " (" + Math.Round(Convert.ToDouble(failRate), 2) + "%)";

                    foreach (IronPython.Runtime.PythonDictionary tmp in Total_Memory)
                    {
                        if (tmp["Memory"].ToString() == "Total")
                            ViewModelLocator.ProjectSettingVM.ProjectSettingModel.LastTest_MemUseage = Math.Round((Convert.ToDouble(tmp["Usage"].ToString()) * 100), 2) + "%";
                    }

                    if (Statement_Cov_Data_Tmp_init == null)
                        ViewModelLocator.ProjectSettingVM.ProjectSettingModel.LastTest_StatementCoverage = "Not Supported";
                    else
                        ViewModelLocator.ProjectSettingVM.ProjectSettingModel.LastTest_StatementCoverage = CommonUtil.merge_StateCoverage((IronPython.Runtime.List)Statement_Cov_Data_Tmp_init[ViewModelLocator.ProjectSettingVM.ProjectSettingModel.SelectedSenario]).ToString() + "%";

                    if (Function_Cov_Data_Tmp_init == null)
                        ViewModelLocator.ProjectSettingVM.ProjectSettingModel.LastTest_FunctionCoverage = "Not Supported";
                    else
                        ViewModelLocator.ProjectSettingVM.ProjectSettingModel.LastTest_FunctionCoverage = CommonUtil.merge_FunctionCoverage((IronPython.Runtime.PythonDictionary)Function_Cov_Data_Tmp_init[ViewModelLocator.ProjectSettingVM.ProjectSettingModel.SelectedSenario]).ToString() + "%";

                    if (Call_Cov_Data_Tmp_init == null)
                        ViewModelLocator.ProjectSettingVM.ProjectSettingModel.LastTest_CallCoverage = "Not Supported";
                    else
                        ViewModelLocator.ProjectSettingVM.ProjectSettingModel.LastTest_CallCoverage = CommonUtil.merge_CallCoverage((IronPython.Runtime.PythonDictionary)Call_Cov_Data_Tmp_init[ViewModelLocator.ProjectSettingVM.ProjectSettingModel.SelectedSenario]).ToString() + "%";

                    InitFlag = false;
                }
                catch (Exception)
                {
                    showTrackBarMessage("Test data did not load properly");
                    return;
                }
            }
            if (InitFlag)
                return;

            if (mode == Common.Common.SELECT_BUILD)
            {
                foreach (string s in Directory.GetDirectories(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.SelectedBuildFolder))
                {
                    if (Directory.GetFiles(s, "*.csv", SearchOption.AllDirectories).Length > 0)
                    {
                        System.Windows.Application.Current.Dispatcher.Invoke(new Action(() =>
                        {
                            if (!ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TestFolderList.Contains(s))
                                ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TestFolderList.Add(s);
                        }));
                    }
                }

                if (ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TestFolderList.Count > 0)
                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.SelectedTestFolder = ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TestFolderList[ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TestFolderList.Count - 1];
                else
                    return;
            }
            if (ViewModelLocator.ProjectSettingVM.ProjectSettingModel.SelectedTestFolder == null)
                return;

            var Origin_TC_Load = scope.GetVariable<Func<string, object>>("Origin_TC_Load");

            IronPython.Runtime.PythonDictionary Summary_Data_Tmp = (IronPython.Runtime.PythonDictionary)Origin_TC_Load(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.SelectedTestFolder + "\\" + @"Debug\dic\project_info\R_test_dictionary.txt");
            IronPython.Runtime.PythonDictionary ReportSummary_Data_Tmp = (IronPython.Runtime.PythonDictionary)Origin_TC_Load(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.SelectedTestFolder + "\\" + @"Debug\dic\report_summary\report_summary.txt");

            IronPython.Runtime.PythonDictionary Statement_Cov_Data_Tmp = null;
            IronPython.Runtime.PythonDictionary Function_Cov_Data_Tmp = null;
            IronPython.Runtime.PythonDictionary Call_Cov_Data_Tmp = null;
            if (File.Exists(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.SelectedTestFolder + "\\" + @"\Debug\dic\coverage\cov\cov_merge.txt"))
                Statement_Cov_Data_Tmp = (IronPython.Runtime.PythonDictionary)Origin_TC_Load(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.SelectedTestFolder + "\\" + @"\Debug\dic\coverage\cov\cov_merge.txt");

            if (File.Exists(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.SelectedTestFolder + "\\" + @"Debug\dic\funccov\dic_func_cov_result.txt"))
                Function_Cov_Data_Tmp = (IronPython.Runtime.PythonDictionary)Origin_TC_Load(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.SelectedTestFolder + "\\" + @"Debug\dic\funccov\dic_func_cov_result.txt");

            if (File.Exists(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.SelectedTestFolder + "\\" + @"Debug\dic\callccov\dic_call_cov_result.txt"))
                Call_Cov_Data_Tmp = (IronPython.Runtime.PythonDictionary)Origin_TC_Load(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.SelectedTestFolder + "\\" + @"Debug\dic\callccov\dic_call_cov_result.txt");


            if (mode == Common.Common.SELECT_TESTCASE) // select Folderlist
            {
                foreach (string key in ReportSummary_Data_Tmp.keys())
                {
                    System.Windows.Application.Current.Dispatcher.Invoke(new Action(() =>
                    {
                        if (!ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TestSenarioList.Contains(key))
                            ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TestSenarioList.Add(key);
                    }));
                }
                ViewModelLocator.ProjectSettingVM.ProjectSettingModel.SelectedSenario = ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TestSenarioList[ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TestSenarioList.Count - 1];
            }

            if (mode == Common.Common.SELECT_SCNARIO)
            {
                foreach (string key in Summary_Data_Tmp.keys())
                {
                    if (key.Equals("Test Comment"))
                        ViewModelLocator.ProjectSettingVM.ProjectSettingModel.LastTest_Comment = Summary_Data_Tmp[key].ToString();
                    else if (key.Equals("Date/Time"))
                        ViewModelLocator.ProjectSettingVM.ProjectSettingModel.LastTest_Time = Summary_Data_Tmp[key].ToString().Substring(0, 4) + "/" + Summary_Data_Tmp[key].ToString().Substring(4, 2) + "/" + Summary_Data_Tmp[key].ToString().Substring(6, 2) + " " + Summary_Data_Tmp[key].ToString().Substring(8, 2) + ":" + Summary_Data_Tmp[key].ToString().Substring(10, 2);
                    else if (key.Equals("Test Project"))
                        ViewModelLocator.ProjectSettingVM.ProjectSettingModel.LastTest_SWComponent = Summary_Data_Tmp[key].ToString();
                }


                IronPython.Runtime.PythonDictionary ReportSummary_Senario_Data = ((IronPython.Runtime.PythonDictionary)ReportSummary_Data_Tmp[ViewModelLocator.ProjectSettingVM.ProjectSettingModel.SelectedSenario]);

                IronPython.Runtime.List Total_Memory = (IronPython.Runtime.List)ReportSummary_Senario_Data["Memory Usage"];
                string passRate = ReportSummary_Senario_Data["Pass Rate"].ToString().Replace("%", "");
                string failRate = ReportSummary_Senario_Data["Fail Rate"].ToString().Replace("%", "");

                string passCount = ReportSummary_Senario_Data["Pass Count"].ToString();
                string failCount = ReportSummary_Senario_Data["Fail Count"].ToString();

                ViewModelLocator.ProjectSettingVM.ProjectSettingModel.LastTest_TestCoverage_Pass = passCount + " (" + Math.Round(Convert.ToDouble(passRate), 2) + "%) ";
                ViewModelLocator.ProjectSettingVM.ProjectSettingModel.LastTest_TestCoverage_Fail = " " + failCount + " (" + Math.Round(Convert.ToDouble(failRate), 2) + "%)";

                foreach (IronPython.Runtime.PythonDictionary tmp in Total_Memory)
                {
                    if (tmp["Memory"].ToString() == "Total")
                        ViewModelLocator.ProjectSettingVM.ProjectSettingModel.LastTest_MemUseage = (Convert.ToDouble(tmp["Usage"].ToString()) * 100).ToString() + "%";
                }

                if (Statement_Cov_Data_Tmp == null)
                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.LastTest_StatementCoverage = "Not Supported";
                else
                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.LastTest_StatementCoverage = CommonUtil.merge_StateCoverage((IronPython.Runtime.List)Statement_Cov_Data_Tmp[ViewModelLocator.ProjectSettingVM.ProjectSettingModel.SelectedSenario]).ToString() + "%";

                if (Function_Cov_Data_Tmp == null)
                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.LastTest_FunctionCoverage = "Not Supported";
                else
                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.LastTest_FunctionCoverage = CommonUtil.merge_FunctionCoverage((IronPython.Runtime.PythonDictionary)Function_Cov_Data_Tmp[ViewModelLocator.ProjectSettingVM.ProjectSettingModel.SelectedSenario]).ToString() + "%";

                if (Call_Cov_Data_Tmp == null)
                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.LastTest_CallCoverage = "Not Supported";
                else
                    ViewModelLocator.ProjectSettingVM.ProjectSettingModel.LastTest_CallCoverage = CommonUtil.merge_CallCoverage((IronPython.Runtime.PythonDictionary)Call_Cov_Data_Tmp[ViewModelLocator.ProjectSettingVM.ProjectSettingModel.SelectedSenario]).ToString() + "%";
            }
        }


        private void ParsingExcelDataWorker_DoWorkComplete(object sender, RunWorkerCompletedEventArgs e)
        {
            ViewModelLocator.ProjectSettingVM.ProjectSettingModel.IsRunningExcel = Common.Common.FALSE;
            if (ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TestSenarioList.Count == 0)
            {
                ViewModelLocator.ProjectSettingVM.ProjectSettingModel.IsHistoryVisible = Common.Common.TRUE;
                ViewModelLocator.ProjectSettingVM.ProjectSettingModel.IsHistoryVisibleTemp = Common.Common.FALSE;
            }
        }
    }
}