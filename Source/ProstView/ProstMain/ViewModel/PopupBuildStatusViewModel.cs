using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using Microsoft.WindowsAPICodePack.Dialogs;
using ProstMain.Dialog;
using ProstMain.Model;
using ProstMain.Popup;
using ProstMain.Util;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ProstMain.ViewModel
{
    public class PopupBuildStatusViewModel : ViewModelBase
    {
        public RelayCommand StopBuildStatusCommand { get; set; }
        public RelayCommand CloseBuildStatusViewCommand { get; set; }
        public RelayCommand BuildTestWarningDialogOKCommand { get; set; }
        public RelayCommand DirectELFPathDialogBrowserCommand { get; set; }
        public RelayCommand ClearELFPathCommand { get; set; }
        public RelayCommand ClearMapxmlPathCommand { get; set; }
        public RelayCommand DirectMapPathDialogBrowserCommand { get; set; }
        public RelayCommand DeleteBuildFolderDialogOKCommand { get; set; }

        private PopupBuildStatusModel _PopupBuildStatusModel;
        public PopupBuildStatusModel PopupBuildStatusModel
        {
            get { return _PopupBuildStatusModel; }
            set
            {
                if (_PopupBuildStatusModel != value)
                {
                    _PopupBuildStatusModel = value;
                    RaisePropertyChanged("PopupBuildStatusModel");
                }
            }
        }
        public PopupBuildStatusViewModel()
        {
            PopupBuildStatusModel = new PopupBuildStatusModel();

            StopBuildStatusCommand = new RelayCommand(StopBuildStatus);
            CloseBuildStatusViewCommand = new RelayCommand(CloseBuildStatusView);
            BuildTestWarningDialogOKCommand = new RelayCommand(BuildTestWarningDialogOK);
            DirectELFPathDialogBrowserCommand = new RelayCommand(DirectELFPathDialogBrowser);
            DirectMapPathDialogBrowserCommand = new RelayCommand(DirectMapPathDialogBrowser);

            ClearELFPathCommand = new RelayCommand(ClearELFPathFunction);
            ClearMapxmlPathCommand = new RelayCommand(ClearMapxmlPathFunction);

            DeleteBuildFolderDialogOKCommand = new RelayCommand(DeleteBuildFolderDialogOK);
        }

        private int BuildcheckStep;
        private void CheckBuildTestStatus()
        {
            ViewModelLocator.MainVM.MainModel.PopupDialogText = "";
            BuildcheckStep = 0;
            PopupBuildStatusModel.Init();

            Task.Factory.StartNew(() =>
            {
                while (true)
                {
                    switch (BuildcheckStep)
                    {
                        case 0:
                            Thread.Sleep(300);
                            if (ViewModelLocator.TargetHWSettingVM.checkTargetHWData())
                                PopupBuildStatusModel.IsHWSettingValue = Common.Common.PASS;
                            else
                                PopupBuildStatusModel.IsHWSettingValue = Common.Common.FAIL;

                            BuildcheckStep++;
                            Thread.Sleep(500);
                            break;
                        case 1:
                            if (ViewModelLocator.TargetSWSettingVM.checkTargetSWData())
                                PopupBuildStatusModel.IsSWSettingValue = Common.Common.PASS;
                            else
                                PopupBuildStatusModel.IsSWSettingValue = Common.Common.FAIL;

                            BuildcheckStep++;
                            Thread.Sleep(500);
                            break;
                        case 2:
                            if (ViewModelLocator.CompilerSettingVM.checkTargetCompilerData())
                                PopupBuildStatusModel.IsCompilerSettingValue = Common.Common.PASS;
                            else
                                PopupBuildStatusModel.IsCompilerSettingValue = Common.Common.FAIL;

                            if (PopupBuildStatusModel.IsHWSettingValue == Common.Common.FAIL || PopupBuildStatusModel.IsSWSettingValue == Common.Common.FAIL || PopupBuildStatusModel.IsCompilerSettingValue == Common.Common.FAIL)
                            {
                                PopupBuildStatusModel.IsElfSettingValue = Common.Common.FAIL;
                                ViewModelLocator.MainVM.MainModel.PopupDialogText = "Check Setting Data";
                                BuildcheckStep = 4;
                            }
                            else
                            {
                                BuildcheckStep++;
                                FunctionWorkHandler.getInstance().ElfBuild();
                            }
                            Thread.Sleep(500);
                            break;
                        case 3:
                            if (PopupBuildStatusModel.IsElfSettingValue == Common.Common.PASS)
                            {
                                BuildcheckStep++;
                                ViewModelLocator.MainVM.MainModel.PopupDialogText = "Elf Build Success";
                                ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TestStepIconColumn = 2;
                            }
                            else if (PopupBuildStatusModel.IsElfSettingValue == Common.Common.FAIL)
                            {
                                BuildcheckStep++;
                                ViewModelLocator.MainVM.MainModel.PopupDialogText = "Elf Build Failed";
                                ViewModelLocator.MainVM.showTrackBarMessage("Elf Build Fail");
                            }
                            Thread.Sleep(500);
                            break;
                        case 4:
                            PopupBuildStatusModel.IsBuildStatusPopupOpen = true;
                            return;
                    }
                }
            });
        }
        public void GenerateLinkerScript()
        {
            if(ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SelectMainLinkerScript != null && ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SelectMainLinkerScript != "" && ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SelectMainLinkerScript != "None")
            {
                string target_sw_path = ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Target_SW\\";
                if (File.Exists(target_sw_path + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SelectMainLinkerScript))
                {
                    if(File.Exists(target_sw_path + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + ".lsl"))
                        File.Delete(target_sw_path + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + ".lsl");

                    File.Copy(target_sw_path + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SelectMainLinkerScript, target_sw_path + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + ".lsl");
                }
            }
        }
        public void GenerateT32Cast()
        {
            Thread thread = new Thread(new ThreadStart(delegate ()
            {
                string[] tmp = Directory.GetFiles(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Target_SW", "*.c", SearchOption.AllDirectories);
                foreach (string f in tmp)
                {
                    string includePathList = "";
                    foreach (IncludePathModel ipm in ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.IncludePathList)
                    {
                        string ConvertPath = ipm.RelativePath.Replace("$(workspace_loc)", ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath);
                        includePathList += "-I " + "\"" + ConvertPath + "\"" + " ";
                    }
                    Process cmd = new Process();
                    cmd.StartInfo.WorkingDirectory = Common.Common.INSTALL_PATH + "\\src\\lib\\T32\\bin\\windows64\\";
                    cmd.StartInfo.FileName = "cmd.exe";
                    cmd.StartInfo.RedirectStandardInput = true;
                    cmd.StartInfo.RedirectStandardOutput = true;
                    cmd.StartInfo.CreateNoWindow = true;
                    cmd.StartInfo.UseShellExecute = false;
                    cmd.Start();

                    cmd.StandardInput.WriteLine("t32cast.exe -I \"" + ViewModelLocator.CompilerSettingVM.CompilerSettingModel.CompilerPath + "\\ctc\\include\" " + includePathList + f + " -o " + f.Replace(".c", ".eca"));
                    cmd.StandardInput.Flush();
                    cmd.StandardInput.Close();
                    cmd.WaitForExit();
                }
            }));
            thread.Start();
        }
        public void ShowPopupBuildStatus()
        {
            GenerateT32Cast();
            GenerateLinkerScript();

            PopupBuildStatusModel.IsBuildStatusPopupOpen = false;

            CheckBuildTestStatus();
            Common.Common.m_PopupBuildStatusView = new PopupBuildStatusView();

            Common.Common.m_PopupBuildStatusView.Width = 450;
            Common.Common.m_PopupBuildStatusView.Height = 450;
            Common.Common.m_PopupBuildStatusView.Owner = App.Current.MainWindow;
            Common.Common.m_PopupBuildStatusView.ShowDialog();
        }
        public void StopBuildStatus()
        {
            CommonUtil.ExitPythonProcess();
            if(FunctionWorkHandler.getInstance().BuildTestWorker != null)
            FunctionWorkHandler.getInstance().BuildTestWorker.CancelAsync();

            if (Common.Common.m_PopupBuildStatusView != null && Common.Common.m_PopupBuildStatusView.IsActive)
                Common.Common.m_PopupBuildStatusView.Close();


        }
        public void ShowDialog_BuildTestWarning()
        {
            ViewModelLocator.MainVM.MainModel.DialogContent = new BuildTestWarningDialogView();
            ViewModelLocator.MainVM.MainModel.isDialogOpen = true;
        }

        public void CloseBuildStatusView()
        {
            PopupBuildStatusModel.IsBuildStatusPopupOpen = false;
            Common.Common.m_PopupBuildStatusView.Close();
        }
        public void BuildTestWarningDialogOK()
        {
            if (PopupBuildStatusModel.DirectELFFilePath == "" || PopupBuildStatusModel.DirectMapFilePath == "")
                return;

            string ConvertDirectElfPath = PopupBuildStatusModel.DirectELFFilePath.Replace("$(workspace_loc)", ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath);
            string ConvertDirectMapxmlPath = PopupBuildStatusModel.DirectMapFilePath.Replace("$(workspace_loc)", ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath);

            ViewModelLocator.PopupTestCaseParsingVM.PopupTestCaseParsingModel.IsTestSpecParserComplete = Common.Common.DEFAULT;
            if (!PythonHandler.getInstance().makeProjectData())
            {
                ViewModelLocator.MainVM.showTrackBarMessage("Please Check the Dictionary File");
                return;
            }
            try
            {
                DirectoryInfo di = new DirectoryInfo(path: ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TimeCreateFolderPath);
                if (!di.Exists)
                    di.Create();

                di = new DirectoryInfo(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TimeCreateFolderPath + "\\" + "Build");
                if (!di.Exists)
                    di.Create();

                di = new DirectoryInfo(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TimeCreateFolderPath + "\\" + "Log");
                if (!di.Exists)
                    di.Create();

                FileManager.FileCopy(ConvertDirectElfPath, ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TimeCreateFolderPath + "\\" + "Build\\" + Path.GetFileName(PopupBuildStatusModel.DirectELFFilePath));
                FileManager.FileCopy(ConvertDirectMapxmlPath, ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TimeCreateFolderPath + "\\" + "Build\\" + Path.GetFileName(PopupBuildStatusModel.DirectMapFilePath));

                PopupBuildStatusModel.IsElfSettingValue = Common.Common.PASS;
                ViewModelLocator.MainVM.showTrackBarMessage("Make Build Folder");

                if (ViewModelLocator.ToolbarVM.ToolbarModel.TestStartMode == Common.Common.TESTMODE_AUTO)
                {
                    ////////// AUTO TEST ///////////////
                    if (ViewModelLocator.ToolbarVM.ToolbarModel.TestStartMode == Common.Common.TESTMODE_AUTO)
                    {
                        Thread.Sleep(100);
                        ViewModelLocator.ToolbarVM.TestSpecConvertWork();
                    }
                }
            }
            catch (Exception ex)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, typeof(MainViewModel).Name + " :: " + ex.Message + " Line :: " + CommonUtil.GetExceptionLineNumber(ex));
            }
            ViewModelLocator.MainVM.MainModel.isDialogOpen = false;
        }
        private void DirectELFPathDialogBrowser()
        {
            CommonOpenFileDialog dialog = new CommonOpenFileDialog();
            dialog.InitialDirectory = ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath;
            dialog.IsFolderPicker = false;
            dialog.RestoreDirectory = true;
            if (dialog.ShowDialog() == CommonFileDialogResult.Ok)
            {
                string ConvertPath = dialog.FileName.Replace(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath, "$(workspace_loc)");
                PopupBuildStatusModel.DirectELFFilePath = ConvertPath;
            }
        }
        private void DirectMapPathDialogBrowser()
        {
            CommonOpenFileDialog dialog = new CommonOpenFileDialog();
            dialog.InitialDirectory = ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath;
            dialog.IsFolderPicker = false;
            dialog.RestoreDirectory = true;
            if (dialog.ShowDialog() == CommonFileDialogResult.Ok)
            {
                string ConvertPath = dialog.FileName.Replace(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath, "$(workspace_loc)");
                PopupBuildStatusModel.DirectMapFilePath = ConvertPath;
            }
        }
        private void ClearELFPathFunction()
        {
            PopupBuildStatusModel.DirectELFFilePath = "";
        }
        private void ClearMapxmlPathFunction()
        {
            PopupBuildStatusModel.DirectMapFilePath  = "";
        }
        public void DeleteBuildFolderDialogOK()
        {
            PopupBuildStatusModel.IsElfSettingValue = Common.Common.DEFAULT;
            ViewModelLocator.CommandVM.CommandModel.LogData.Clear();
            ViewModelLocator.MainVM.MainModel.DialogContent = new ProgressBarDialogView();
            ViewModelLocator.MainVM.MainModel.isDialogOpen = true;
            BackgroundWorker DeleteBuildFolderWorker = new BackgroundWorker();

            DeleteBuildFolderWorker.DoWork += (obj, e) => DeleteBuildFolderWorker_DoWork("");
            DeleteBuildFolderWorker.RunWorkerCompleted += DeleteBuildFolderWorker_RunWorkerCompleted;
            DeleteBuildFolderWorker.RunWorkerAsync();
        }
        private void DeleteBuildFolderWorker_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
        {
            ViewModelLocator.MainVM.MainModel.isDialogOpen = false;

            if (e.Error != null)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, e.Error.Message);
                return;
            }
            if (PopupBuildStatusModel.DirectELFFilePath != "" && PopupBuildStatusModel.DirectMapFilePath != "")
                ViewModelLocator.ToolbarVM.ToolbarModel.BuildMode = Common.Common.ALREADY_ELF;

            if (ViewModelLocator.ToolbarVM.ToolbarModel.BuildMode == Common.Common.STANDARD)
            {
                PopupBuildStatusModel.IsBuildStart = false;
                PopupBuildStatusModel.ElfBuildProgress = 0;
                ShowPopupBuildStatus();
            }
            else
            {
                try
                {
                    if (PopupBuildStatusModel.DirectELFFilePath != null && PopupBuildStatusModel.DirectELFFilePath == "")
                        BuildTestWarningDialogOK();
                    else
                        ShowDialog_BuildTestWarning();
                }
                catch (Exception ex)
                {
                    ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, typeof(MainViewModel).Name + " :: " + ex.Message + " Line :: " + CommonUtil.GetExceptionLineNumber(ex));
                }
            }
        }

        private void DeleteBuildFolderWorker_DoWork(string p)
        {
            try
            {
                DirectoryInfo di = new DirectoryInfo(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TimeCreateFolderPath);
                CommonUtil.ClearAttributes(di.FullName);
                di.Delete(true);
            }
            catch (Exception ex)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, "파일 및 폴더가 열려있거나, 접근할 수 없습니다.");
                throw;
            }
        }
        public void ShowDialog_DeleteBuildFolder()
        {
            ViewModelLocator.MainVM.MainModel.DialogContent = new DeleteBuildFolderDialogView();
            ViewModelLocator.MainVM.MainModel.isDialogOpen = true;
        }
    }
}
