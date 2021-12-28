using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using GalaSoft.MvvmLight.Messaging;
using ProstMain.Util;
using ProstMain.View;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media;
using System.Windows.Threading;
using static System.Net.Mime.MediaTypeNames;

namespace ProstMain.ViewModel
{
    public class MenuBarViewModel : ViewModelBase
    {
        public RelayCommand CreateProjectCommand { get; set; }
        public RelayCommand SaveProjectCommand { get; set; }
        public RelayCommand ImportProjectCommand { get; set; }
        public RelayCommand ExportProjectCommand { get; set; }
        public RelayCommand DeleteProjectCommand { get; set; }
        public RelayCommand ChangeWorkSpaceCommand { get; set; }
        public RelayCommand ExitProjectCommand { get; set; }
        public RelayCommand Trace32SettingCommand { get; set; }
        public RelayCommand AboutProstCommand { get; set; }
        public RelayCommand<object> LogLevelClickCommand { get; set; }

        private bool _IsMenubarEnable;
        public bool IsMenubarEnable
        {
            get { return _IsMenubarEnable; }
            set
            {
                if (_IsMenubarEnable != value)
                {
                    _IsMenubarEnable = value;
                    RaisePropertyChanged("IsMenubarEnable");
                }
            }
        }
        private int _ProstThema;
        public int ProstThema
        {
            get { return _ProstThema; }
            set
            {
                if (_ProstThema != value)
                {
                    _ProstThema = value;
                    RaisePropertyChanged("ProstThema");
                }
            }
        }

        private bool _IsADFileGenerator;
        public bool IsADFileGenerator
        {
            get { return _IsADFileGenerator; }
            set
            {
                if (_IsADFileGenerator != value)
                {
                    _IsADFileGenerator = value;
                    RaisePropertyChanged("IsADFileGenerator");
                }
            }
        }
        private int _LogLevelIndex;
        public int LogLevelIndex
        {
            get { return _LogLevelIndex; }
            set
            {
                if (_LogLevelIndex != value)
                {
                    _LogLevelIndex = value;
                    RaisePropertyChanged("LogLevelIndex");
                }
            }
        }
        private bool _LogLevel_1_Checked;
        public bool LogLevel_1_Checked
        {
            get { return _LogLevel_1_Checked; }
            set
            {
                if (_LogLevel_1_Checked != value)
                {
                    _LogLevel_1_Checked = value;
                    RaisePropertyChanged("LogLevel_1_Checked");
                }
            }
        }
        private bool _LogLevel_2_Checked;
        public bool LogLevel_2_Checked
        {
            get { return _LogLevel_2_Checked; }
            set
            {
                if (_LogLevel_2_Checked != value)
                {
                    _LogLevel_2_Checked = value;
                    RaisePropertyChanged("LogLevel_2_Checked");
                }
            }
        }
        private bool _LogLevel_3_Checked;
        public bool LogLevel_3_Checked
        {
            get { return _LogLevel_3_Checked; }
            set
            {
                if (_LogLevel_3_Checked != value)
                {
                    _LogLevel_3_Checked = value;
                    RaisePropertyChanged("LogLevel_3_Checked");
                }
            }
        }
        private double _Resolution;
        public double Resolution
        {
            get { return _Resolution; }
            set
            {
                if (_Resolution != value)
                {
                    _Resolution = value;
                    RaisePropertyChanged("Resolution");
                }
            }
        }
        private int _ADFileCheckTime;
        public int ADFileCheckTime
        {
            get { return _ADFileCheckTime; }
            set
            {
                if (_ADFileCheckTime != value)
                {
                    _ADFileCheckTime = value;
                    RaisePropertyChanged("ADFileCheckTime");
                }
            }
        }
        public MenuBarViewModel()
        {
            CreateProjectCommand = new RelayCommand(CreateProject);
            SaveProjectCommand = new RelayCommand(SaveProject);
            ExitProjectCommand = new RelayCommand(ExitProject);
            ChangeWorkSpaceCommand = new RelayCommand(PrevSaveProject);
            ImportProjectCommand = new RelayCommand(ImportProject);
            ExportProjectCommand = new RelayCommand(ExportProject);
            DeleteProjectCommand = new RelayCommand(DeleteProject);
            Trace32SettingCommand = new RelayCommand(Trace32Setting);
            AboutProstCommand = new RelayCommand(AboutProst);
            LogLevelClickCommand = new RelayCommand<object>(LogLevelClick);

            IsADFileGenerator = true;
            IsMenubarEnable = true;
            ProstThema = Common.Common.THEMA_DARK;

            LogLevelIndex = 0;
            ADFileCheckTime = 30;
        }
        private void CreateProject()
        {
            ViewModelLocator.MainVM.ShowDialog_CreateProject();
        }
        private void SaveProject()
        {
            if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.ProjectExplorerModelList.Count == 0)
            {
                ViewModelLocator.MainVM.showTrackBarMessage("Projst List is Empty");
                return;
            }

            ViewModelLocator.MainVM.MainModel.BeforeSaveMode = Common.Common.SAVE_MODE;
            ViewModelLocator.MainVM.ShowDialog_SaveProject(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName);
        }
        private void PrevSaveProject()
        {
            ViewModelLocator.MainVM.MainModel.BeforeSaveMode = Common.Common.WORKSPACE_CHANGE;
            ViewModelLocator.MainVM.ShowDialog_SaveProject(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName);
        }
        private void ImportProject()
        {
            if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.ProjectExplorerModelList.Count == 0)
            {
                ViewModelLocator.MainVM.showTrackBarMessage("Projst List is Empty");
                return;
            }
            ViewModelLocator.MainVM.ShowDialog_ImportProjectProperty();
        }
        private void ExportProject()
        {
            if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.ProjectExplorerModelList.Count == 0)
            {
                ViewModelLocator.MainVM.showTrackBarMessage("Projst List is Empty");
                return;
            }
            ViewModelLocator.MainVM.ShowDialog_ExportProjectProperty();
        }
        private void ExitProject()
        {
            ViewModelLocator.MainVM.ExitProgram("mainwindow");
        }
        private void DeleteProject()
        {
            if (ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.ProjectExplorerModelList.Count == 0)
            {
                ViewModelLocator.MainVM.showTrackBarMessage("Projst List is Empty");
                return;
            }
            ViewModelLocator.MainVM.ShowDialog_DeleteProject();
        }
        private void Trace32Setting()
        {

        }
        private void AboutProst()
        {
            ViewModelLocator.MainVM.ShowDialog_AboutProst();
        }
        private void LogLevelClick(object e)
        {
            string itemName = e.ToString();
            LogLevel_1_Checked = false;
            LogLevel_2_Checked = false;
            LogLevel_3_Checked = false;

            if (itemName.Equals("LogLevel_1"))
            {
                LogLevel_1_Checked = true;
                LogLevelIndex = Common.Common.LOG_STANDARD;
                
            }
            else if (itemName.Equals("LogLevel_2"))
            {
                LogLevel_2_Checked = true;
                LogLevelIndex = Common.Common.LOG_INFORMATION;
            }
            else if (itemName.Equals("LogLevel_3"))
            {
                LogLevel_3_Checked = true;
                LogLevelIndex = Common.Common.LOG_DEBUG;
            }
        }
    }
}
