using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using LiveCharts;
using LiveCharts.Wpf;
using Microsoft.WindowsAPICodePack.Dialogs;
using ProstMain.Model;
using ProstMain.Popup;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Threading;

namespace ProstMain.ViewModel
{
    public class ProjectSettingViewModel : ViewModelBase
    {
        public RelayCommand SelectedSenarioCommand { get; set; }
        public RelayCommand SelectedTestFolderCommand { get; set; }
        public RelayCommand SelectedBuldFolderCommand { get; set; }

        private ProjectSettingModel _ProjectSettingModel;
        public ProjectSettingModel ProjectSettingModel
        {
            get { return _ProjectSettingModel; }
            set
            {
                if (_ProjectSettingModel != value)
                {
                    _ProjectSettingModel = value;
                    RaisePropertyChanged("ProjectSettingModel");
                }
            }
        }


        public ProjectSettingViewModel()
        {
            ProjectSettingModel = new ProjectSettingModel();

            SelectedSenarioCommand = new RelayCommand(SelectedSenario);
            SelectedTestFolderCommand = new RelayCommand(SelectedTestFolder);
            SelectedBuldFolderCommand = new RelayCommand(SelectedBuldFolder);
            ProjectSettingModel.TestDate = DateTime.Now.ToString("yyyyMMdd");
        }

        private void SelectedSenario()
        {
            if (ProjectSettingModel.TestSenarioList.Count > 0)
            {
                if (ProjectSettingModel.SelectedSenario != null)
                    ViewModelLocator.MainVM.ParsingLastTestData(Common.Common.SELECT_SCNARIO, ProjectSettingModel.SelectedBuildFolder, ProjectSettingModel.SelectedTestFolder, ProjectSettingModel.SelectedSenario);
            }

        }
        private void SelectedTestFolder()
        {
            if (ProjectSettingModel.SelectedTestFolder != null)
                ViewModelLocator.MainVM.ParsingLastTestData(Common.Common.SELECT_TESTCASE, ProjectSettingModel.SelectedBuildFolder,ProjectSettingModel.SelectedTestFolder, "");
        }
        private void SelectedBuldFolder()
        {
            if (ProjectSettingModel.SelectedBuildFolder != null)
                ViewModelLocator.MainVM.ParsingLastTestData(Common.Common.SELECT_BUILD, ProjectSettingModel.SelectedBuildFolder, "", "");
        }


    }
}
