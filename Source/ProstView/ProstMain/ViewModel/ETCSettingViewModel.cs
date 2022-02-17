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
        public RelayCommand MakeEnumScriptCommand { get; set; }

        public ETCSettingViewModel()
        {
            EnumScriptPathBrowserCommand = new RelayCommand(EnumScriptPathBrowserFunction);
            MakeEnumScriptCommand = new RelayCommand(MakeEnumScriptFunction);
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
