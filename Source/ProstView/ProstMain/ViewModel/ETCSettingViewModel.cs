using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using Microsoft.WindowsAPICodePack.Dialogs;
using ProstMain.Dialog;
using ProstMain.Util;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ProstMain.ViewModel
{
    public class ETCSettingViewModel : ViewModelBase
    {
        private string _EnumScriptPath;
        public string EnumScriptPath
        {
            get { return _EnumScriptPath; }
            set
            {
                if (_EnumScriptPath != value)
                {
                    _EnumScriptPath = value;
                    RaisePropertyChanged("EnumScriptPath");
                }
            }
        }

        private string _PreLoadElfPath;
        public string PreLoadElfPath
        {
            get { return _PreLoadElfPath; }
            set
            {
                if (_PreLoadElfPath != value)
                {
                    _PreLoadElfPath = value;
                    RaisePropertyChanged("PreLoadElfPath");
                }
            }
        }

        private string _PostLoadElfPath;
        public string PostLoadElfPath
        {
            get { return _PostLoadElfPath; }
            set
            {
                if (_PostLoadElfPath != value)
                {
                    _PostLoadElfPath = value;
                    RaisePropertyChanged("PostLoadElfPath");
                }
            }
        }

        private string _EnumScriptDialogViewContent;
        public string EnumScriptDialogViewContent
        {
            get { return _EnumScriptDialogViewContent; }
            set
            {
                if (_EnumScriptDialogViewContent != value)
                {
                    _EnumScriptDialogViewContent = value;
                    RaisePropertyChanged("EnumScriptDialogViewContent");
                }
            }
        }
        public RelayCommand EnumScriptPathBrowserCommand { get; set; }
        public RelayCommand PreLoadElfPathBrowserCommand { get; set; }
        public RelayCommand PostLoadElfPathBrowserCommand { get; set; }
        public RelayCommand MakeEnumScriptCommand { get; set; }

        public ETCSettingViewModel()
        {
            EnumScriptPathBrowserCommand = new RelayCommand(EnumScriptPathBrowserFunction);
            PreLoadElfPathBrowserCommand = new RelayCommand(PreLoadElfPathBrowserFunction);
            PostLoadElfPathBrowserCommand = new RelayCommand(PostLoadElfPathBrowserFunction);

            MakeEnumScriptCommand = new RelayCommand(MakeEnumScriptFunction);
        }
        private void PreLoadElfPathBrowserFunction()
        {
            Microsoft.Win32.OpenFileDialog dialog = new Microsoft.Win32.OpenFileDialog();
            dialog.Filter = "Elf Files (*.elf)|*.elf";

            if (dialog.ShowDialog() == true)
            {
                if (dialog.FileName.Contains(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath))
                    PreLoadElfPath = @"$(workspace_loc)\" + dialog.FileName.Replace(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + @"\", "");
                else
                    PreLoadElfPath = dialog.FileName;
            }
        }

        private void PostLoadElfPathBrowserFunction()
        {
            Microsoft.Win32.OpenFileDialog dialog = new Microsoft.Win32.OpenFileDialog();
            dialog.Filter = "Elf Files (*.elf)|*.elf";

            if (dialog.ShowDialog() == true)
            {
                if (dialog.FileName.Contains(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath))
                    PostLoadElfPath = @"$(workspace_loc)\" + dialog.FileName.Replace(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + @"\", "");
                else
                    PostLoadElfPath = dialog.FileName;
            }
        }

        private void EnumScriptPathBrowserFunction()
        {
            Microsoft.Win32.OpenFileDialog dialog = new Microsoft.Win32.OpenFileDialog();
            dialog.Filter = "Cmm Script Files (*.cmm)|*.cmm";

            if (dialog.ShowDialog() == true)
            {
                if (dialog.FileName.Contains(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath))
                    EnumScriptPath = @"$(workspace_loc)\" + dialog.FileName.Replace(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + @"\", "");
                else
                    EnumScriptPath = dialog.FileName;
            }
        }
        private void MakeEnumScriptFunction()
        {
            Thread thread = new Thread(new ThreadStart(
            delegate ()
            {
                System.Windows.Application.Current.Dispatcher.Invoke(new Action(() =>
                {
                    ShowEnumScriptLoadingView();
                }));
                EnumParsingHandler.getInstance().doParsing();
            }));
            thread.Start();
        }
        public void ShowEnumScriptLoadingView()
        {
            ViewModelLocator.MainVM.MainModel.DialogContent = new EnumScriptLoadingDialogView();
            ViewModelLocator.MainVM.MainModel.isDialogOpen = true;
        }
    }
}
