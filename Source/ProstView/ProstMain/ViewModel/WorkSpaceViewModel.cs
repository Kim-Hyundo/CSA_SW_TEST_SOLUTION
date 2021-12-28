using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using GalaSoft.MvvmLight.Messaging;
using IWshRuntimeLibrary;
using Microsoft.WindowsAPICodePack.Dialogs;
using ProstMain.Common;
using ProstMain.Model;
using ProstMain.Util;
using ProstMain.View;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Input;
using System.Xml;
using System.Xml.Serialization;

namespace ProstMain.ViewModel
{
    public class WorkSpaceViewModel : ViewModelBase, IRequireViewIdentification
    {
        #region Variable
        private WorkSpaceModel _WorkSpaceModel;
        public WorkSpaceModel WorkSpaceModel
        {
            get { return _WorkSpaceModel; }
            set
            {
                if(_WorkSpaceModel != value)
                {
                    _WorkSpaceModel = value;
                    RaisePropertyChanged("WorkSpaceModel");
                }
            }
        }
        #endregion
        public RelayCommand OkClickCommand { get; set; }
        public RelayCommand CancelClickCommand { get; set; }
        public RelayCommand BrowserClickCommand { get; set; }
        public RelayCommand<object> WorkSpaceSelectedCommand { get; set; }

        private ObservableCollection<WorkspaceInfoModel> _WorkspaceInfoModelList;
        public ObservableCollection<WorkspaceInfoModel> WorkspaceInfoModelList
        {
            get { return _WorkspaceInfoModelList; }
            set
            {
                if (_WorkspaceInfoModelList != value)
                {
                    _WorkspaceInfoModelList = value;
                    RaisePropertyChanged("WorkspaceInfoModelList");
                }
            }
        }


        private Guid _viewId;
        public Guid ViewID
        {
            get { return _viewId; }
            set
            {
                if(_viewId != value)
                {
                    _viewId = value;
                    RaisePropertyChanged("ViewID");
                }
            }
        }

        public WorkSpaceViewModel()
        {
            OkClickCommand = new RelayCommand(OkClick);
            CancelClickCommand = new RelayCommand(CancelClick);
            BrowserClickCommand = new RelayCommand(BrowserClick);
            WorkSpaceSelectedCommand = new RelayCommand<object>(WorkSpaceSelected);

            WorkspaceInfoModelList = new ObservableCollection<WorkspaceInfoModel>();
            WorkSpaceModel = new WorkSpaceModel();

            ReadStartXml();
        }

        #region Execute
        private void WorkSpaceSelected(object obj)
        {
            if (obj != null)
            {
                WorkspaceInfoModel model = obj as WorkspaceInfoModel;
                WorkSpaceModel.WorkSpacePath = model.WorkspacePath;
            }
        }
        private void ReadStartXml()
        {
            try
            {
                string path = @"workspace_list.xml";
                FileInfo fileInfo = new FileInfo(path);

                if (fileInfo.Exists)
                {
                    XmlSerializer xs = new XmlSerializer(typeof(ObservableCollection<WorkspaceInfoModel>));
                    using (Stream fstream = System.IO.File.OpenRead(path))
                    {
                        WorkspaceInfoModelList = xs.Deserialize(fstream) as ObservableCollection<WorkspaceInfoModel>;
                    }
                    foreach(WorkspaceInfoModel model in WorkspaceInfoModelList)
                    {
                        if (model.DefaultPathCheck)
                            WorkSpaceModel.IsWorkSpaceDefaultPath = true;
                        if(model.DefaultPath != "")
                        {
                            WorkSpaceModel.WorkSpacePath = model.DefaultPath;
                            WorkSpaceModel.SelectWorkspaceItem = model;
                        }
                    }
                }
                else
                {
                    using (var sw = new StreamWriter(path))
                    {
                        XmlSerializer serializer = new XmlSerializer(typeof(ObservableCollection<WorkspaceInfoModel>));
                        serializer.Serialize(sw, WorkspaceInfoModelList);
                        sw.Close();
                    }
                }
            }
            catch(Exception ex)
            {
                string path = @"workspace_list.xml";
                if(System.IO.File.Exists(path))
                    System.IO.File.Delete(path);
                using (var sw = new StreamWriter(path))
                {
                    XmlSerializer serializer = new XmlSerializer(typeof(ObservableCollection<WorkspaceInfoModel>));
                    serializer.Serialize(sw, WorkspaceInfoModelList);
                    sw.Close();
                }

                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, typeof(WorkSpaceViewModel).Name + " :: " + ex.Message + " Line :: " + CommonUtil.GetExceptionLineNumber(ex));
            }
        }
        public void OkClick()
        {
            try
            {
                if (!Directory.Exists(WorkSpaceModel.WorkSpacePath))
                {
                    MessageBoxResult result = MessageBox.Show("Workspace 경로가 잘못되었습니다. 확인바랍니다.", "PROST Unit", MessageBoxButton.OK);
                    switch (result)
                    {
                        case MessageBoxResult.OK:
                            if (WorkSpaceModel.IsStartUp)
                                System.Diagnostics.Process.GetCurrentProcess().Kill();
                            else
                                WindowManager.CloseWindow(ViewID);
                            break;
                    }
                }
                else
                {
                    for(int i=0;i<WorkspaceInfoModelList.Count;i++)
                    {
                        if(WorkspaceInfoModelList[i].WorkspacePath == WorkSpaceModel.SelectWorkspaceItem.WorkspacePath)
                        {
                            WorkspaceInfoModelList[i].DefaultPath = WorkSpaceModel.SelectWorkspaceItem.WorkspacePath;
                            WorkspaceInfoModelList[i].DefaultPathCheck = WorkSpaceModel.IsWorkSpaceDefaultPath;
                        }
                        else
                        {
                            WorkspaceInfoModelList[i].DefaultPath = "";
                            WorkspaceInfoModelList[i].DefaultPathCheck = false;
                        }
                    }

                    string path = @"workspace_list.xml";
                    using (var sw = new StreamWriter(path))
                    {
                        XmlSerializer serializer = new XmlSerializer(typeof(ObservableCollection<WorkspaceInfoModel>));
                        serializer.Serialize(sw, WorkspaceInfoModelList);
                        sw.Close();
                    }

                    if (WorkSpaceModel.IsStartUp)
                    {
                        App.Current.MainWindow = Common.Common.mainwindowView;
                        //App.Current.MainWindow.Show();
                        Common.Common.mainwindowView.Show();
                    }

                    ViewModelLocator.ProjectExplorerVM.LoadWorkSpace(WorkSpaceModel.WorkSpacePath);
                    WindowManager.CloseWindow(ViewID);
                }
            }
            catch(Exception ex)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, typeof(WorkSpaceViewModel).Name + " :: " + ex.Message + " Line :: " + CommonUtil.GetExceptionLineNumber(ex));
            }
        }
        private void CancelClick()
        {
            if(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.IsStartUp)
            {
                ViewModelLocator.MainVM.ExitProgram("workspace");
            }
            WindowManager.CloseWindow(ViewID);
        }

        private void BrowserClick()
        {
            CommonOpenFileDialog dialog = new CommonOpenFileDialog();   //CommonOpenFileDialog 클래스 생성

            dialog.InitialDirectory = @"C:\";   //창이 뜨면 처음 보여줄 폴더 설정
            dialog.IsFolderPicker = true;

            if (dialog.ShowDialog() == CommonFileDialogResult.Ok)
            {
                WorkspaceInfoModel model = new WorkspaceInfoModel();
                model.WorkspacePath = dialog.FileName;
                model.WorkspaceName = Path.GetFileNameWithoutExtension(dialog.FileName);
                if (WorkspaceInfoModelList.Any(p => p.WorkspacePath == dialog.FileName) == false)
                    WorkspaceInfoModelList.Add(new WorkspaceInfoModel() {WorkspacePath=dialog.FileName,WorkspaceName=Path.GetFileNameWithoutExtension(dialog.FileName) });

                WorkSpaceModel.WorkSpacePath = model.WorkspacePath;
                WorkSpaceModel.SelectWorkspaceItem = model;
            }
                
        }
        public void ChangeWorkSpace()
        {
            if (!Common.Common.workspaceView.IsActive)
                Common.Common.workspaceView = new WorkSpaceView();

            ReadStartXml();
            Common.Common.workspaceView.Show();

            WorkSpaceModel.IsStartUp = false;
        }
        #endregion
    }
}
