using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using Microsoft.WindowsAPICodePack.Dialogs;
using ProstMain.Model;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace ProstMain.ViewModel
{
    public class CompilerSettingViewModel : ViewModelBase
    {
        private CompilerSettingModel _CompilerSettingModel;
        public CompilerSettingModel CompilerSettingModel
        {
            get { return _CompilerSettingModel; }
            set
            {
                if(_CompilerSettingModel != value)
                {
                    _CompilerSettingModel = value;
                    RaisePropertyChanged("CompilerSettingModel");
                }    
            }
        }
        private ObservableCollection<string> _CompilerVersionList;
        public ObservableCollection<string> CompilerVersionList
        {
            get { return _CompilerVersionList; }
            set
            {
                if (_CompilerVersionList != value)
                {
                    _CompilerVersionList = value;
                    RaisePropertyChanged("CompilerVersionList");
                }
            }
        }
        private ObservableCollection<string> _ComplilerTypeList;
        public ObservableCollection<string> ComplilerTypeList
        {
            get { return _ComplilerTypeList; }
            set
            {
                if (_ComplilerTypeList != value)
                {
                    _ComplilerTypeList = value;
                    RaisePropertyChanged("ComplilerTypeList");
                }
            }
        }

        public RelayCommand CompilerPathBrowserCommand { get; set; }
        public CompilerSettingViewModel()
        {
            CompilerSettingModel = new CompilerSettingModel();
            CompilerVersionList = new ObservableCollection<string>();
            CompilerVersionList.Add("6.2");
            CompilerVersionList.Add("4.2");
            CompilerVersionList.Add("4.3");

            ComplilerTypeList = new ObservableCollection<string>();
            ComplilerTypeList.Add("TASKING");
            ComplilerTypeList.Add("GHS"); // 11/22

            CompilerPathBrowserCommand = new RelayCommand(CompilerPathBrowser);
        }
        private void CompilerPathBrowser()
        {
            CommonOpenFileDialog dialog = new CommonOpenFileDialog();   //CommonOpenFileDialog 클래스 생성

            dialog.InitialDirectory = @"C:\";   //창이 뜨면 처음 보여줄 폴더 설정
            dialog.IsFolderPicker = true;
            CommonFileDialogResult commonFileDialogResult = dialog.ShowDialog();

            if (commonFileDialogResult == CommonFileDialogResult.Ok)
            {
                CompilerSettingModel.CompilerPath = dialog.FileName; 
            }
        }

        public void RefreshCompiler()
        {
            CompilerVersionList.Clear();
            if (CompilerSettingModel.CompilerType == null || CompilerSettingModel.CompilerType == "")
            { }
            else
            {
                if (CompilerSettingModel.CompilerType.Equals("TASKING"))
                {
                    CompilerVersionList.Add("6.2");
                    CompilerVersionList.Add("4.2");
                    CompilerVersionList.Add("4.3");
                }
                /* 11/22 */
                else if (CompilerSettingModel.CompilerType.Equals("GHS"))
                {
                    CompilerVersionList.Add("2021.1.4");
                }
            }
        }

                public bool checkTargetCompilerData()
        {
            bool resultValue = true;
            if (CompilerSettingModel.CompilerVersion == null || CompilerSettingModel.CompilerVersion.Equals(""))
                resultValue = false;
            if (CompilerSettingModel.CompilerOption.Equals(""))
                resultValue = false;
            if (CompilerSettingModel.CompilerPath.Equals(""))
                resultValue = false;
            if (CompilerSettingModel.LinkerOption.Equals(""))
                resultValue = false;

            return resultValue;
        }
    }
}
