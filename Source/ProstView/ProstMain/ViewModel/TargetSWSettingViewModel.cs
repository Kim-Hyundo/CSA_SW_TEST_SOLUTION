using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using Javi.ExplorerTreeView;
using MaterialDesignExtensions.Model;
using MaterialDesignThemes.Wpf;
using Microsoft.WindowsAPICodePack.Dialogs;
using ProstMain.Dialog;
using ProstMain.Model;
using ProstMain.Popup;
using ProstMain.Util;
using ProstMain.View;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
using System.ComponentModel;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using WSF;
using WSF.Interfaces;
using static ProstMain.Util.FileManager;

namespace ProstMain.ViewModel
{
    public class TargetSWSettingViewModel : ViewModelBase
    {

        private TargetSWSettingModel _TargetSWSettingModel;
        public TargetSWSettingModel TargetSWSettingModel
        {
            get { return _TargetSWSettingModel; }
            set
            {
                if (_TargetSWSettingModel != value)
                {
                    _TargetSWSettingModel = value;
                    RaisePropertyChanged("TargetSWSettingModel");
                }
            }
        }
        public RelayCommand AddRunnableOKCommand { get; set; }
        public RelayCommand AddStubOKCommand { get; set; }
        public RelayCommand AddRegisterOKCommand { get; set; }
        public RelayCommand AddInitFunctionOKCommand { get; set; }
        public RelayCommand AddRunnableCancelCommand { get; set; }
        public RelayCommand AddStubCancelCommand { get; set; }

        public RelayCommand DeleteRegisterCommand { get; set; }
        public RelayCommand DeleteRunnableCommand { get; set; }
        public RelayCommand DeleteStubCommand { get; set; }
        public RelayCommand DeleteInitFunctionCommand { get; set; }
        public RelayCommand DeleteRunnableDataDialogOKCommand { get; set; }
        public RelayCommand DeleteStubDataDialogOKCommand { get; set; }
        public RelayCommand DeleteRegisterDataDialogOKCommand { get; set; }
        public RelayCommand DeleteCopyPathDialogOKCommand { get; set; }

        public RelayCommand TreeViewItemCopyDialogOKCommand { get; set; }
        public RelayCommand<object> CreateFolderOKCommand { get; set; }
        public RelayCommand DeleteFolderFileOKCommand { get; set; }
        public RelayCommand ImportRegisterOKCommand { get; set; }
        public RelayCommand ImportRegisterNOCommand { get; set; }

        public RelayCommand TestStatementBrowserCommand { get; set; }
        public RelayCommand TestCasePathBrowserCommand { get; set; }
        public RelayCommand WorkspaceRootPathBrowserCommand { get; set; }
        public RelayCommand SoruceCodeRootPathBrowserCommand { get; set; }
        public RelayCommand TCProductionCommand { get; set; }

        public RelayCommand DeleteFileFolderCommand { get; set; }
        public RelayCommand CreateFolderCommand { get; set; }
        public RelayCommand RefreshFileFolderCommand { get; set; }

        public RelayCommand IncludePathAddCommand { get; set; }
        public RelayCommand LibraryRegistAddCommand { get; set; }
        public RelayCommand<object> LibraryRegistRemoveCommand { get; set; }

        public RelayCommand<object> PopupIncludePathRegistOKCommand { get; set; }
        public RelayCommand PopupIncludePathRegistCANCELCommand { get; set; }
        public RelayCommand PopupIncludePathRegistFileSystemCommand { get; set; }
        public RelayCommand PopupIncludePathRegistWorkSpaceCommand { get; set; }

        public RelayCommand<object> IncludePathContextRemovePathCommand { get; set; }
        public RelayCommand<object> IncludePathContextEditPathCommand { get; set; }
        public RelayCommand ImportRegisterSettingCommand { get; set; }

        List<string> NotExistCopyPathList;
        public TargetSWSettingViewModel()
        {
            TargetSWSettingModel = new TargetSWSettingModel();

            

            AddRunnableOKCommand = new RelayCommand(AddRunnableOK);
            AddStubOKCommand = new RelayCommand(AddStubOK);
            AddRegisterOKCommand = new RelayCommand(AddRegisterOK);
            AddInitFunctionOKCommand = new RelayCommand(AddInitFunctionOK);

            DeleteRegisterCommand = new RelayCommand(ShowDialog_DeleteRegisterData);
            DeleteRunnableCommand = new RelayCommand(ShowDialog_DeleteRunnableData);
            DeleteStubCommand = new RelayCommand(ShowDialog_DeleteStubData);
            DeleteInitFunctionCommand = new RelayCommand(DeleteInitFunction);

            DeleteRunnableDataDialogOKCommand = new RelayCommand(DeleteRunnableDataDialogOK);
            DeleteStubDataDialogOKCommand = new RelayCommand(DeleteStubDataDialogOK);
            DeleteRegisterDataDialogOKCommand = new RelayCommand(DeleteRegisterDataDialogOK);
            DeleteCopyPathDialogOKCommand = new RelayCommand(DeleteCopyPathDialogOK);

            TreeViewItemCopyDialogOKCommand = new RelayCommand(TreeViewItemCopyDialogOK);
            CreateFolderOKCommand = new RelayCommand<object>(CreateFolderOK);
            DeleteFolderFileOKCommand = new RelayCommand(DeleteFolderFileOK);
            ImportRegisterOKCommand = new RelayCommand(ImportRegisterOK);
            ImportRegisterNOCommand = new RelayCommand(ImportRegisterNO);

            WorkspaceRootPathBrowserCommand = new RelayCommand(WorkspaceRootPathBrowser);
            SoruceCodeRootPathBrowserCommand = new RelayCommand(SoruceCodeRootPathBrowser);

            CreateFolderCommand = new RelayCommand(CreateFolder);
            DeleteFileFolderCommand = new RelayCommand(DeleteFileFolder);
            RefreshFileFolderCommand = new RelayCommand(RefreshFileFolder);

            IncludePathAddCommand = new RelayCommand(IncludePathAdd);
            LibraryRegistAddCommand = new RelayCommand(LibraryRegistAdd);
            LibraryRegistRemoveCommand = new RelayCommand<object>(LibraryRegistRemove);

            PopupIncludePathRegistOKCommand = new RelayCommand<object>(PopupIncludePathRegistOK);
            PopupIncludePathRegistCANCELCommand = new RelayCommand(PopupIncludePathRegistCANCEL);
            PopupIncludePathRegistFileSystemCommand = new RelayCommand(PopupIncludePathRegistFileSystem);
            PopupIncludePathRegistWorkSpaceCommand = new RelayCommand(PopupIncludePathRegistWorkSpace);

            IncludePathContextRemovePathCommand = new RelayCommand<object>(IncludePathContextRemovePath);
            IncludePathContextEditPathCommand = new RelayCommand<object>(IncludePathContextEditPath);

            ImportRegisterSettingCommand = new RelayCommand(ImportRegisterSetting);

            NotExistCopyPathList = new List<string>();
        }


        private void WorkspaceRootPathBrowser()
        {
            CommonOpenFileDialog dialog = new CommonOpenFileDialog();   //CommonOpenFileDialog 클래스 생성

            dialog.InitialDirectory = TargetSWSettingModel.WorkspaceRootPath;   //창이 뜨면 처음 보여줄 폴더 설정
            dialog.IsFolderPicker = true;
            CommonFileDialogResult commonFileDialogResult = dialog.ShowDialog();

            if (commonFileDialogResult == CommonFileDialogResult.Ok)
            {
                TargetSWSettingModel.WorkspaceRootPath = dialog.FileName;
            }
        }
        private void SoruceCodeRootPathBrowser()
        {
            CommonOpenFileDialog dialog = new CommonOpenFileDialog();   //CommonOpenFileDialog 클래스 생성

            dialog.InitialDirectory = TargetSWSettingModel.SourceCodeRootPath;   //창이 뜨면 처음 보여줄 폴더 설정
            dialog.IsFolderPicker = true;
            CommonFileDialogResult commonFileDialogResult = dialog.ShowDialog();

            if (commonFileDialogResult == CommonFileDialogResult.Ok)
            {
                TargetSWSettingModel.SourceCodeRootPath = dialog.FileName;
            }
        }
        private void CreateFolder()
        {
            try
            {
                if (TargetSWSettingModel.SelectTreeViewItem == null)
                    return;

                IDirectoryBrowser browser = TargetSWSettingModel.SelectTreeViewItem.Tag as IDirectoryBrowser;
                if (browser == null)
                    return;

                ViewModelLocator.MainVM.ShowDialog_CreateFolder();
            }
            catch
            {

            }
        }
        private void DeleteFileFolder()
        {
            try
            {
                if (TargetSWSettingModel.SelectTreeViewItem == null)
                    return;

                ShowDialog_DeleteFolderFile();
            }
            catch
            {

            }
        }
        public void RefreshFileFolder()
        {
            try
            {
                NotExistCopyPathList.Clear();
                TargetSWSettingModel.IncludePathList.Clear();
                TargetSWSettingModel.LinkerScriptList.Clear();
                
                CommonUtil.ClearAttributes(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Target_SW");

                List<string> keys = new List<string>(TargetSWSettingModel.CopyDictionary.Keys);

                foreach (string targetKey in keys)
                {
                    if (!targetKey.Contains("$(workspace_loc)"))
                    {
                        string value = TargetSWSettingModel.CopyDictionary[targetKey];
                        TargetSWSettingModel.CopyDictionary.Remove(targetKey);
                        TargetSWSettingModel.CopyDictionary.Add("$(workspace_loc)" + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Target_SW\\" + targetKey.Split(new string[] { "\\Target_SW\\" }, StringSplitOptions.None).Last(), value);
                    }
                }

                keys = new List<string>(TargetSWSettingModel.CopyDictionary.Keys);
                // CopyPath를 길이순으로 정렬하여 유저가 생성한 폴더먼저 업데이트할 수 있도록 한다.
                keys.Sort((a, b) => {
                    if (a.Length < b.Length)
                        return -1;
                    else if (a.Length > b.Length)
                        return 1;
                    else
                        return String.Compare(a, b);
                });


                bool CopyPathFlag = false;
                foreach (string targetKey in keys)
                {
                    string ConvertTargetKey = "";
                    if (targetKey.Contains("$(workspace_loc)"))
                        ConvertTargetKey = targetKey.Replace("$(workspace_loc)", ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath);
                    else
                        ConvertTargetKey = targetKey;

                    if (TargetSWSettingModel.CopyDictionary[targetKey].Contains("UserCreateFolder"))
                    {
                        string ConvertPath;
                        if (targetKey.Contains("$(workspace_loc)"))
                            ConvertPath = targetKey.Replace("$(workspace_loc)", ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath);
                        else if (targetKey.Contains("$(sourcecode_root)"))
                            ConvertPath = targetKey.Replace("$(sourcecode_root)", ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceCodeRootPath);
                        else
                            ConvertPath = targetKey;


                        Directory.CreateDirectory(ConvertPath);

                        if (ConvertPath.Contains(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath))
                        {
                            IncludePathModel model = new IncludePathModel();
                            model.AbsolutePath = ConvertPath;
                            model.RelativePath = "$(workspace_loc)" + ConvertPath.Replace(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath, "");
                            ViewModelLocator.TargetSWSettingVM.AddIncludeModel(model);
                        }

                        continue;
                    }

                    if(TargetSWSettingModel.CopyDictionary[targetKey].Contains("tc3xx.lsl"))
                    {

                    }

                    string checkpath = "";
                    if (TargetSWSettingModel.CopyDictionary[targetKey].Contains("$(workspace_loc)"))
                        checkpath = TargetSWSettingModel.CopyDictionary[targetKey].Replace("$(workspace_loc)", ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath);
                    else if (TargetSWSettingModel.CopyDictionary[targetKey].Contains("$(sourcecode_root)"))
                        checkpath = TargetSWSettingModel.CopyDictionary[targetKey].Replace("$(sourcecode_root)", ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceCodeRootPath);
                    else
                        checkpath = TargetSWSettingModel.CopyDictionary[targetKey];

                    switch (CommonUtil.IsDirectory(checkpath)) // Copy to Path 경로 확인
                    {
                        case Common.Common.NOT_EXIST: // Copy to Path가 존재하지 않을 때
                            ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_WARN, "Not Exist Copy Path [" + checkpath + "]");
                            CopyPathFlag = true;
                            NotExistCopyPathList.Add(targetKey);
                            break;
                        case Common.Common.FILE: // Copy To Path가 파일일 때,
                            FileCompare compare = new FileCompare();
                            FileInfo target_info = new FileInfo(ConvertTargetKey);
                            FileInfo copyto_info = new FileInfo(checkpath);

                            if (!Directory.GetParent(ConvertTargetKey).Exists)
                                continue;

                            File.Copy(copyto_info.FullName, target_info.FullName, true);
                            break;
                        case Common.Common.FOLDER:
                            if (!Directory.Exists(ConvertTargetKey)) // TargetSW에서 폴더가 존재하지 않을 때
                            {
                                DirectoryCopy(checkpath, ConvertTargetKey, false);
                            }
                            else
                            {
                                DirectoryInfo dir1 = new DirectoryInfo(ConvertTargetKey);
                                DirectoryInfo dir2 = new DirectoryInfo(checkpath);

                                // Take a snapshot of the file system.  
                                IEnumerable<FileInfo> list1 = dir1.GetFiles("*.*", SearchOption.AllDirectories);
                                IEnumerable<FileInfo> list2 = dir2.GetFiles("*.*", SearchOption.AllDirectories);

                                //A custom file comparer defined below  

                                //CommonUtil.ClearAttributes(targetKey);
                                DirectoryCopy(checkpath, ConvertTargetKey, false);
                            }
                            break;
                    }
                }
                ExplorerTreeViewItem item = new ExplorerTreeViewItem();
                item.SourcePath = ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Target_SW";

                string[] tempFiles = Directory.GetFiles(item.SourcePath, "*.lsl", SearchOption.TopDirectoryOnly);

                TargetSWSettingModel.LinkerScriptList.Add("None");
                foreach (string f in tempFiles)
                    TargetSWSettingModel.LinkerScriptList.Add(Path.GetFileName(f));

                TargetSWSettingModel.SourceCodePath = ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName;
                TargetSWSettingModel.SourceCodePath = ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Target_SW";
                ViewModelLocator.MainVM.showTrackBarMessage("Source code synchronization complete");

                if (CopyPathFlag)
                    ShowDialog_DeleteCopyPath();
            }
            catch (Exception ex)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, typeof(TargetSWSettingViewModel).Name + " :: " + ex.Message.Replace("\n","") + " Line :: " + CommonUtil.GetExceptionLineNumber(ex));
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, "Source Code Update Fail");
            }

        }
        private void IncludePathAdd()
        {
            TargetSWSettingModel.PopupIncludePathRegistInputDirectory = "";
            TargetSWSettingModel.PopupIncludePathRegistDisplayInputDirectory = "";

            Common.Common.m_PopupIncludePathRegistView = new PopupIncludePathRegistView("Add");

            Common.Common.m_PopupIncludePathRegistView.Width = 500;
            Common.Common.m_PopupIncludePathRegistView.Height = 230;
            Common.Common.m_PopupIncludePathRegistView.Owner = App.Current.MainWindow;
            Common.Common.m_PopupIncludePathRegistView.Show();
        }

        private void LibraryRegistAdd()
        {
            CommonOpenFileDialog dialog = new CommonOpenFileDialog();

            dialog.InitialDirectory = ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath;
            dialog.IsFolderPicker = false;
            dialog.Filters.Add(new CommonFileDialogFilter("라이브러리파일", ".a"));
            CommonFileDialogResult commonFileDialogResult = dialog.ShowDialog();

            if (commonFileDialogResult == CommonFileDialogResult.Ok)
            {

                TargetSWSettingModel.LibraryPathList.Add(CommonUtil.GetAbsoluteToRelativePath(dialog.FileName));
            }
        }
        private void LibraryRegistRemove(object e)
        {
            if (TargetSWSettingModel.LibraryPathSelectedIndex != -1)
                TargetSWSettingModel.LibraryPathList.Remove(e.ToString());
        }
        private void PopupIncludePathRegistOK(object e)
        {
            if (e.ToString() == "Add Include Path")
            {
                if(!Directory.Exists(TargetSWSettingModel.PopupIncludePathRegistDisplayInputDirectory)) // Relative Path
                { 
                    string Relative = @"$(workspace_loc)\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Target_SW\\" + TargetSWSettingModel.PopupIncludePathRegistInputDirectory.Replace(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Target_SW", "");

                    IncludePathModel inputModel = new IncludePathModel();
                    inputModel.RelativePath = Relative;
                    inputModel.AbsolutePath = TargetSWSettingModel.PopupIncludePathRegistInputDirectory;
                    ViewModelLocator.TargetSWSettingVM.AddIncludeModel(inputModel);

                }
                else // Absolute Path
                {
                    IncludePathModel inputModel = new IncludePathModel();
                    inputModel.AbsolutePath = TargetSWSettingModel.PopupIncludePathRegistInputDirectory;
                    inputModel.RelativePath = "";
                    ViewModelLocator.TargetSWSettingVM.AddIncludeModel(inputModel);
                }

                if (Common.Common.m_PopupIncludePathRegistView != null)
                {
                    Common.Common.m_PopupIncludePathRegistView.Close();
                    Common.Common.m_PopupIncludePathRegistView = null;
                }
            }
            else
            {
                IncludePathModel model = new IncludePathModel();
                
                DirectoryInfo dir_info = new DirectoryInfo(TargetSWSettingModel.PopupIncludePathRegistInputDirectory);

                string Relative = @"$(workspace_loc)\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "/" + dir_info.Name + "}";

                if (!Directory.Exists(TargetSWSettingModel.PopupIncludePathRegistDisplayInputDirectory))
                {
                    model.RelativePath = Relative;
                    //FileManager.DirectoryCopy(TargetSWSettingModel.PopupIncludePathRegistInputDirectory, ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Target_SW\\" + dir_info.Name, true);
                    model.AbsolutePath = ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Target_SW\\" + dir_info.Name;
                }
                else
                {
                    model.AbsolutePath = TargetSWSettingModel.PopupIncludePathRegistInputDirectory;
                    model.RelativePath = "";
                }
                TargetSWSettingModel.IncludePathList[TargetSWSettingModel.IncludePathSelectedIndex] = model;

                if (Common.Common.m_PopupIncludePathRegistView != null)
                {
                    Common.Common.m_PopupIncludePathRegistView.Close();
                    Common.Common.m_PopupIncludePathRegistView = null;
                }
            }

        }
        private void PopupIncludePathRegistCANCEL()
        {

        }
        private void PopupIncludePathRegistFileSystem()
        {
            CommonOpenFileDialog dialog = new CommonOpenFileDialog();
            
            dialog.IsFolderPicker = true;
            dialog.RestoreDirectory = true;
            CommonFileDialogResult commonFileDialogResult = dialog.ShowDialog();

            if (commonFileDialogResult == CommonFileDialogResult.Ok)
            {
                TargetSWSettingModel.PopupIncludePathRegistDisplayInputDirectory = dialog.FileName;
                TargetSWSettingModel.PopupIncludePathRegistInputDirectory = dialog.FileName;
            }
        }
        private void PopupIncludePathRegistWorkSpace()
        {
            CommonOpenFileDialog dialog = new CommonOpenFileDialog();

            dialog.InitialDirectory = ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Target_SW";
            dialog.IsFolderPicker = true;
            CommonFileDialogResult commonFileDialogResult = dialog.ShowDialog();

            if (commonFileDialogResult == CommonFileDialogResult.Ok)
            {
                if(!dialog.FileName.Contains(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath))
                {
                    ViewModelLocator.MainVM.showTrackBarMessage("Not Workspace Path..");
                    return;
                }
                string Relative = @"$(workspace_loc)\" + dialog.FileName.Replace(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath, "") + "}";
                TargetSWSettingModel.PopupIncludePathRegistDisplayInputDirectory = Relative;
                TargetSWSettingModel.PopupIncludePathRegistInputDirectory = dialog.FileName;
            }
        }
        private void AddRunnableOK()
        {
            if (TargetSWSettingModel.InputCore == null)
            {
                ViewModelLocator.MainVM.showTrackBarMessage("Please Check the Core Value");
                return;
            }

            TargetSWSettingModel.RunnableList.Add(new RunnableModel()
            {
                RunnableNameGrid = TargetSWSettingModel.InputRunnableCall,
                RunnableCycleGrid = TargetSWSettingModel.InputCallCycle,
                RunnableCoreGrid = TargetSWSettingModel.InputCore,
                RunnableHeader = TargetSWSettingModel.InputHeader
            });
            ViewModelLocator.MainVM.showTrackBarMessage("Add Runnable Data");
            TargetSWSettingModel.InputRunnableCall = "";
            TargetSWSettingModel.InputCallCycle = "";
            TargetSWSettingModel.InputCore = "";
            TargetSWSettingModel.InputHeader = "";
        }
        private void AddStubOK()
        {
            TargetSWSettingModel.RunnableStubList.Add(new RunnableStubModel()
            {
                RunnableSTUBFunctionGrid = TargetSWSettingModel.InputStubFunctionName,
                RunnableSTUBDelayGrid = TargetSWSettingModel.InputStubDelay,
                RunnableSTUBReturnGrid = TargetSWSettingModel.InputStubReturnValue,
            });
            ViewModelLocator.MainVM.showTrackBarMessage("Add Stub Data");
            TargetSWSettingModel.InputStubFunctionName = "";
            TargetSWSettingModel.InputStubDelay = "";
            TargetSWSettingModel.InputStubReturnValue = "";
        }
        private void AddRegisterOK()
        {
            TargetSWSettingModel.RegisterList.Add(new RegisterModel()
            {
                RegisterName = TargetSWSettingModel.InputRegisterName,
                RegisterValue = TargetSWSettingModel.InputRegisterValue,
            });
            ViewModelLocator.MainVM.showTrackBarMessage("Add Register Data");
            TargetSWSettingModel.InputRegisterName = "";
            TargetSWSettingModel.InputRegisterValue = "";
        }
        private void AddInitFunctionOK()
        {
            TargetSWSettingModel.InitFunctionList.Add(TargetSWSettingModel.InputInitFunctionName);
            ViewModelLocator.MainVM.showTrackBarMessage("Add Initfunction Data");
        }
        public bool checkTargetSWData()
        {
            bool resultValue = true;
            if (TargetSWSettingModel.SourceCodePath == null || TargetSWSettingModel.SourceCodePath.Equals("") || !Directory.Exists(TargetSWSettingModel.SourceCodePath))
                resultValue = false;
            if(TargetSWSettingModel.RunnableList == null || TargetSWSettingModel.RunnableList.Count == 0)
                resultValue = false;

            return resultValue;
        }
        public void CopyItem(ExplorerTreeViewItem _sourceItem, ExplorerTreeViewItem _targetItem)
        {
            try
            {
                try // folder
                {
                    IDirectoryBrowser SourcedirectoryBrowser = _sourceItem.Tag as IDirectoryBrowser;
                    if (SourcedirectoryBrowser != null)
                    {
                        IDirectoryBrowser TargetDirectoryBrowser = _targetItem.Tag as IDirectoryBrowser;
                        Directory.CreateDirectory(TargetDirectoryBrowser.FullName + "\\" + SourcedirectoryBrowser.Label);

                        FileManager.CopyFolderSourceCode(SourcedirectoryBrowser.FullName, TargetDirectoryBrowser.FullName + "\\" + SourcedirectoryBrowser.Label);
                    }
                    else
                    {
                        IDirectoryBrowser TargetDirectoryBrowser = _targetItem.Tag as IDirectoryBrowser;
                        FileManager.FileCopy(_sourceItem.Tag.ToString(), TargetDirectoryBrowser.FullName + "\\" + _sourceItem.Header);

                        string ConvertWorkspacePath = (TargetDirectoryBrowser.FullName + "\\" + _sourceItem.Header).Replace(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath, "$(workspace_loc)");
                        string ConvertSourceCodeRootPath = _sourceItem.Tag.ToString().Replace(ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceCodeRootPath, "$(sourcecode_root)" + @"\");
                        string ConvertWorkspaceSourcePath = _sourceItem.Tag.ToString().Replace(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath, "$(workspace_loc)");

                        if (!TargetSWSettingModel.CopyDictionary.ContainsKey(ConvertWorkspacePath))
                        {
                            if(ConvertSourceCodeRootPath.Contains("$(sourcecode_root)"))
                                TargetSWSettingModel.CopyDictionary.Add(ConvertWorkspacePath, ConvertSourceCodeRootPath);
                            else
                                TargetSWSettingModel.CopyDictionary.Add(ConvertWorkspacePath, ConvertWorkspaceSourcePath);
                        }

                        string sourcePath = TargetDirectoryBrowser.FullName;

                        if (sourcePath.Contains(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath))
                        {
                            IncludePathModel model = new IncludePathModel();
                            model.AbsolutePath = sourcePath;
                            model.RelativePath = "$(workspace_loc)" + sourcePath.Replace(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath, "");
                            ViewModelLocator.TargetSWSettingVM.AddIncludeModel(model);
                        }

                    }
                }
                catch // file
                {
                    IDirectoryBrowser TargetDirectoryBrowser = _targetItem.Tag as IDirectoryBrowser;
                    FileManager.FileCopy(_sourceItem.Tag.ToString(), TargetDirectoryBrowser.FullName + "\\" + _sourceItem.Header);

                    string ConvertWorkspacePath = (TargetDirectoryBrowser.FullName + "\\" + _sourceItem.Header).Replace(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath, "$(workspace_loc)");
                    string ConvertSourceCodeRootPath = _sourceItem.Tag.ToString().Replace(ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceCodeRootPath, "$(sourcecode_root)" + @"\");
                    if (!TargetSWSettingModel.CopyDictionary.ContainsKey(ConvertWorkspacePath))
                        TargetSWSettingModel.CopyDictionary.Add(ConvertWorkspacePath, ConvertSourceCodeRootPath);

                    /*                    string sourcePath = TargetDirectoryBrowser.FullName;

                                        IncludePathModel model = new IncludePathModel();
                                        model.AbsolutePath = sourcePath;
                                        model.RelativePath = "$(workspace_loc)" + sourcePath.Replace(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath, "");
                                        ViewModelLocator.TargetSWSettingVM.AddIncludeModel(model);*/
                }

                addChild(_sourceItem, _targetItem);
                ExplorerTreeViewItem ParentItem = FindVisualParent<ExplorerTreeViewItem>(_sourceItem);
                ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.TargetTreeViewItem = null;
                ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceTreeViewItem = null;
            }
            catch
            {

            }
        }
        public void addChild(ExplorerTreeViewItem _sourceItem, ExplorerTreeViewItem _targetItem)
        {
            // add item in target TreeViewItem 
            try
            {
                ExplorerTreeViewItem item1 = new ExplorerTreeViewItem();
                item1.Header = _sourceItem.Header;
                /*item1.Tag = _targetItem.Tag;*/


                IDirectoryBrowser directoryBrowser = item1.Tag as IDirectoryBrowser;

                IDirectoryBrowser targetBrowser = _targetItem.Tag as IDirectoryBrowser;
                IDirectoryBrowser sourceBrowser = _sourceItem.Tag as IDirectoryBrowser;

                if (sourceBrowser != null)
                {
                    if (sourceBrowser.FullName.Contains(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath))
                    {
                        item1.CopyPath = sourceBrowser.FullName.Replace(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath, "$(workspace_loc)");
                    }
                    else if (sourceBrowser.FullName.Contains(ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceCodeRootPath))
                    {
                        item1.CopyPath = sourceBrowser.FullName.Replace(ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceCodeRootPath, "$(sourcecode_root)" + @"\");
                    }
                    else
                        item1.CopyPath = sourceBrowser.FullName;
                    item1.Tag = Browser.Create(targetBrowser.FullName + "\\" + sourceBrowser.Name);
                    item1.Items.Add("*");

                    /*if (!TargetSWSettingModel.CopyDictionary.ContainsKey(targetBrowser.FullName + "\\" + sourceBrowser.Label))
                        TargetSWSettingModel.CopyDictionary.Add(targetBrowser.FullName + "\\" + sourceBrowser.Label, item1.CopyPath);*/
                }
                else
                {
                    _sourceItem.SourcePath = (targetBrowser.PathRAW + "\\" + _sourceItem.Header).Replace(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath, "$(workspace_loc)");
                    if (_sourceItem.Tag.ToString().Contains(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath))
                    {
                        item1.CopyPath = _sourceItem.Tag.ToString().Replace(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath, "$(workspace_loc)");
                    }
                    else if (_sourceItem.Tag.ToString().Contains(ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceCodeRootPath))
                    {
                        item1.CopyPath = _sourceItem.Tag.ToString().Replace(ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceCodeRootPath, "$(sourcecode_root)" + @"\");
                    }
                    else
                    {
                        item1.CopyPath = _sourceItem.Tag.ToString();
                    }
                    
                    item1.Tag = targetBrowser.FullName + "\\" + _sourceItem.Header;

                    if (targetBrowser.FullName + "\\" + _sourceItem.Header != item1.CopyPath)
                    {
                        /*if (!TargetSWSettingModel.CopyDictionary.ContainsKey(targetBrowser.FullName + "\\" + _sourceItem.Header))
                            TargetSWSettingModel.CopyDictionary.Add(targetBrowser.FullName + "\\" + _sourceItem.Header, item1.CopyPath);*/
                    }
                }

                
                _targetItem.Items.Add(item1);
                _targetItem.Items.IsLiveSorting = true;

                foreach (ExplorerTreeViewItem item in _sourceItem.Items)
                {
                    addChild(item, item1);
                }
            }
            catch
            {

            }
        }
        static TObject FindVisualParent<TObject>(UIElement child) where TObject : UIElement
        {
            if (child == null)
            {
                return null;
            }

            UIElement parent = VisualTreeHelper.GetParent(child) as UIElement;

            while (parent != null)
            {
                TObject found = parent as TObject;
                if (found != null)
                {
                    return found;
                }
                else
                {
                    parent = VisualTreeHelper.GetParent(parent) as UIElement;
                }
            }

            return null;
        }

        private void IncludePathContextRemovePath(object e)
        {
            List<IncludePathModel> SelectedItemsList = (e as IList).Cast<IncludePathModel>().ToList();

            foreach (IncludePathModel model in SelectedItemsList)
            {
                TargetSWSettingModel.IncludePathList.Remove(model);
            }
        }
        private void IncludePathContextEditPath(object e)
        {
            IncludePathModel model = (IncludePathModel)e;
            if (TargetSWSettingModel.IncludePathSelectedIndex != -1)
            {
                TargetSWSettingModel.PopupIncludePathRegistInputDirectory = model.AbsolutePath;

                if (model.RelativePath == "")
                    TargetSWSettingModel.PopupIncludePathRegistDisplayInputDirectory = model.AbsolutePath;
                else
                    TargetSWSettingModel.PopupIncludePathRegistDisplayInputDirectory = model.RelativePath;

                Common.Common.m_PopupIncludePathRegistView = new PopupIncludePathRegistView("Edit");

                Common.Common.m_PopupIncludePathRegistView.Width = 500;
                Common.Common.m_PopupIncludePathRegistView.Height = 230;
                Common.Common.m_PopupIncludePathRegistView.Owner = App.Current.MainWindow;
                Common.Common.m_PopupIncludePathRegistView.Show();
            }
        }
        private void ImportRegisterSetting()
        {
            CommonOpenFileDialog dialog = new CommonOpenFileDialog();

            dialog.IsFolderPicker = false;
            CommonFileDialogResult commonFileDialogResult = dialog.ShowDialog();

            if (commonFileDialogResult == CommonFileDialogResult.Ok)
            {
                TargetSWSettingModel.ImportRegisterFilePath = dialog.FileName;

                if (TargetSWSettingModel.RegisterList.Count > 0)
                    ShowDialog_ImportRegister();
                else
                    ImportRegisterOK();
            }
        }

        public bool AddIncludeModel(IncludePathModel model)
        {
            if (null != model)
            {
                if (TargetSWSettingModel.IncludePathList.Count(c => c.RelativePath == model.RelativePath) == 0 && TargetSWSettingModel.IncludePathList.Count(c => c.AbsolutePath == model.AbsolutePath) == 0)
                {
                    TargetSWSettingModel.IncludePathList.Add(model);
                    return true;
                }
            }
            return false;
        }
        private void ShowDialog_ImportRegister()
        {
            ViewModelLocator.MainVM.MainModel.DialogContent = new ImportRegisterDialogView();
            ViewModelLocator.MainVM.MainModel.isDialogOpen = true;
        }
        private void ShowDialog_DeleteRunnableData()
        {
            ViewModelLocator.MainVM.MainModel.DialogContent = new DeleteRunnableDataDialogView();
            ViewModelLocator.MainVM.MainModel.isDialogOpen = true;
        }
        private void ShowDialog_DeleteStubData()
        {
            ViewModelLocator.MainVM.MainModel.DialogContent = new DeleteStubDataDialogView();
            ViewModelLocator.MainVM.MainModel.isDialogOpen = true;
        }
        private void ShowDialog_DeleteRegisterData()
        {
            ViewModelLocator.MainVM.MainModel.DialogContent = new DeleteRegisterDataDialogView();
            ViewModelLocator.MainVM.MainModel.isDialogOpen = true;
        }
        public void ShowDialog_DeleteFolderFile()
        {
            ViewModelLocator.MainVM.MainModel.DialogContent = new DeleteFolderFileDialogView(TargetSWSettingModel.SelectTreeViewItem.Header.ToString());
            ViewModelLocator.MainVM.MainModel.isDialogOpen = true;
        }
        public void ShowDialog_AddTreeViewItem(string msg)
        {
            ViewModelLocator.MainVM.MainModel.DialogContent = new TreeViewItemCopyDialogView(msg);
            ViewModelLocator.MainVM.MainModel.isDialogOpen = true;
        }
        public void ShowDialog_DeleteCopyPath()
        {
            ViewModelLocator.MainVM.MainModel.DialogContent = new DeleteCopyPathDialogView();
            ViewModelLocator.MainVM.MainModel.isDialogOpen = true;
        }
        private void DeleteRunnableDataDialogOK()
        {
            string name = TargetSWSettingModel.SelectRunnable.RunnableNameGrid;
            if (TargetSWSettingModel.RunnableList.Remove(TargetSWSettingModel.SelectRunnable))
                ViewModelLocator.MainVM.showTrackBarMessage("Delete is " + name + " Data");
            ViewModelLocator.MainVM.MainModel.isDialogOpen = false;
        }
        private void DeleteStubDataDialogOK()
        {
            string name = TargetSWSettingModel.SelectStub.RunnableSTUBFunctionGrid;
            if (TargetSWSettingModel.RunnableStubList.Remove(TargetSWSettingModel.SelectStub))
                ViewModelLocator.MainVM.showTrackBarMessage("Delete is " + name + " Data");
            ViewModelLocator.MainVM.MainModel.isDialogOpen = false;
        }

        private void DeleteRegisterDataDialogOK()
        {
            string name = TargetSWSettingModel.SelectRegister.RegisterName;
            if (TargetSWSettingModel.RegisterList.Remove(TargetSWSettingModel.SelectRegister))
                ViewModelLocator.MainVM.showTrackBarMessage("Delete is " + name + " Data");
            ViewModelLocator.MainVM.MainModel.isDialogOpen = false;
        }
        private void DeleteCopyPathDialogOK()
        {
            ViewModelLocator.MainVM.MainModel.isDialogOpen = false;
            foreach (string str in NotExistCopyPathList)
                TargetSWSettingModel.CopyDictionary.Remove(str); // CopyDic에서 제거

            NotExistCopyPathList.Clear();
            ViewModelLocator.MainVM.MainModel.BeforeSaveMode = Common.Common.SAVE_MODE;
            ViewModelLocator.ProjectExplorerVM.SaveProject();
        }
        private void DeleteInitFunction()
        {
            string name = TargetSWSettingModel.SelectInitFunction;
            if (TargetSWSettingModel.InitFunctionList.Remove(TargetSWSettingModel.SelectInitFunction))
                ViewModelLocator.MainVM.showTrackBarMessage("Delete is " + name + " Data");
            ViewModelLocator.MainVM.MainModel.isDialogOpen = false;
        }
        private void TreeViewItemCopyDialogOK()
        {
            CopyItem(TargetSWSettingModel.SourceTreeViewItem, TargetSWSettingModel.TargetTreeViewItem);
            ViewModelLocator.MainVM.MainModel.BeforeSaveMode = Common.Common.SAVE_MODE;
            ViewModelLocator.ProjectExplorerVM.SaveProject();
            ViewModelLocator.MainVM.MainModel.isDialogOpen = false;
        }
        private void ImportRegisterOK()
        {
            TargetSWSettingModel.RegisterList.Clear();
            ViewModelLocator.MainVM.MainModel.isDialogOpen = false;
            string[] ReadFileData = FileManager.FileRead(TargetSWSettingModel.ImportRegisterFilePath);

            foreach(string str in ReadFileData)
            {
                if(!str.TrimStart().StartsWith("//"))
                {
                    string[] tempStr = str.Split(' ');
                    if(tempStr.Length > 1)
                        TargetSWSettingModel.RegisterList.Add(new RegisterModel() { RegisterName = tempStr[0].Trim(), RegisterValue = tempStr[tempStr.Length-1].Trim() });
                }
            }
        }
        private void ImportRegisterNO()
        {
            ViewModelLocator.MainVM.MainModel.isDialogOpen = false;
            string[] ReadFileData = FileManager.FileRead(TargetSWSettingModel.ImportRegisterFilePath);

            foreach (string str in ReadFileData)
            {
                if (str.TrimStart().StartsWith("//"))
                    continue;
                else
                {
                    string[] tempStr = str.Split(' ');
                    if (tempStr.Length > 1)
                    {
                        TargetSWSettingModel.RegisterList.Add(new RegisterModel() { RegisterName = tempStr[0].Trim(), RegisterValue = tempStr[1].Trim() });
                    }
                }
            }
        }
        private void DeleteFolderFileOK()
        {
            if (TargetSWSettingModel.SelectTreeViewItem == null)
                return;

            ExplorerTreeViewItem SelectedItemParent = (ExplorerTreeViewItem)TargetSWSettingModel.SelectTreeViewItem.Parent;

            IDirectoryBrowser directoryBrowser = TargetSWSettingModel.SelectTreeViewItem.Tag as IDirectoryBrowser;
            if (directoryBrowser == null)
            {
                File.Delete(TargetSWSettingModel.SelectTreeViewItem.Tag.ToString());

                if (TargetSWSettingModel.CopyDictionary.ContainsKey(TargetSWSettingModel.SelectTreeViewItem.Tag.ToString()))
                {
                    TargetSWSettingModel.CopyDictionary.Remove(TargetSWSettingModel.SelectTreeViewItem.Tag.ToString());
                    
                }
                string convertPath = TargetSWSettingModel.SelectTreeViewItem.Tag.ToString().Replace(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath, "$(workspace_loc)");
                if (TargetSWSettingModel.CopyDictionary.ContainsKey(convertPath))
                {
                    TargetSWSettingModel.CopyDictionary.Remove(convertPath);
                }
            }
            else
            {
                CommonUtil.ClearAttributes(directoryBrowser.FullName);
                Directory.Delete(directoryBrowser.FullName, true);

                List<string> remove_keys = new List<string>();
                foreach (string key in TargetSWSettingModel.CopyDictionary.Keys)
                {
                    string conterPath = key.Replace("$(workspace_loc)", ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath);
                    if (conterPath.Contains(directoryBrowser.FullName))
                        remove_keys.Add(key);
                }
                foreach (string key in remove_keys)
                {
                    TargetSWSettingModel.CopyDictionary.Remove(key);
                }
            }

            TargetSWSettingView.getInstance().RefreshTreeView(SelectedItemParent);

            ViewModelLocator.MainVM.MainModel.BeforeSaveMode = Common.Common.SAVE_MODE;
            ViewModelLocator.ProjectExplorerVM.SaveProject();

            ViewModelLocator.MainVM.MainModel.isDialogOpen = false;
        }
        private void CreateFolderOK(object e)
        {
            IDirectoryBrowser directoryBrowser = TargetSWSettingModel.SelectTreeViewItem.Tag as IDirectoryBrowser;
            Directory.CreateDirectory(directoryBrowser.FullName + "\\" + e.ToString());

            string ConvertPath = (directoryBrowser.FullName + "\\" + e.ToString()).Replace(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\", "$(workspace_loc)" + @"\");

            TargetSWSettingModel.CopyDictionary.Add(directoryBrowser.FullName + "\\" + e.ToString(), "UserCreateFolder");

            TargetSWSettingView.getInstance().RefreshTreeView(TargetSWSettingModel.SelectTreeViewItem);

            ViewModelLocator.MainVM.MainModel.isDialogOpen = false;
        }

    }
}
