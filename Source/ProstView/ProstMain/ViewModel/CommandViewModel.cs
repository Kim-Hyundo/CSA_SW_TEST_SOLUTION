using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using Microsoft.WindowsAPICodePack.Dialogs;
using ProstMain.Model;
using ProstMain.Util;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
using System.ComponentModel;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Data;
using System.Windows.Threading;
using static ProstMain.Model.CommandModel;

namespace ProstMain.ViewModel
{
    public class CommandViewModel : ViewModelBase
    { 
        public RelayCommand BtnSaveLogDataCommand { get; set; }
        public RelayCommand BtnDeleteLogAllCommand { get; set; }


        private CommandModel _CommandModel;
        public CommandModel CommandModel
        {
            get { return _CommandModel; }
            set
            {
                if(_CommandModel != value)
                {
                    _CommandModel = value;
                    RaisePropertyChanged("CommandModel");
                }
            }
        }

        public CommandViewModel()
        {
            CommandModel = new CommandModel();

            BtnSaveLogDataCommand = new RelayCommand(BtnSaveLogData);
            BtnDeleteLogAllCommand = new RelayCommand(BtnDeleteLogAll);
        }
        private ICollectionView _CarListView { get; set; }

        public void LogFilter()
        {
            ICollectionView phrasesView;
            phrasesView = CollectionViewSource.GetDefaultView(CommandModel.LogData);
            phrasesView.Filter = null;

            if (CommandModel.SearchModuleCompiler || CommandModel.SearchModuleMainGUI || CommandModel.SearchModuleParser || CommandModel.SearchModuleReport || CommandModel.SearchModuleTrace32)
                phrasesView.Filter = excuteFilter;

            phrasesView.Refresh();
                //String.IsNullOrEmpty(filterString) ? true : ((string)o).Contains(filterString);
        }
        private bool excuteFilter(object item)
        {
            bool result = false;
            string logItem = item as string;
            if (CommandModel.SearchModuleCompiler)
            {
                if (logItem.Contains(Common.Common.FILTER_COMPILER))
                    result = true;
            }
            if (CommandModel.SearchModuleMainGUI)
            {
                if (logItem.Contains(Common.Common.FILTER_MAINGUI))
                    result = true;
            }
            if (CommandModel.SearchModuleParser)
            {
                if (logItem.Contains(Common.Common.FILTER_PARSER))
                    result = true;
            }
            if (CommandModel.SearchModuleReport)
            {
                if (logItem.Contains(Common.Common.FILTER_REPORT))
                    result = true;
            }
            if (CommandModel.SearchModuleTrace32)
            {
                if (logItem.Contains(Common.Common.FILTER_TRACE32))
                    result = true;
            }


            return result;
        }
        public void BtnSaveLogData()
        {
            CommonSaveFileDialog dialog = new CommonSaveFileDialog();
            dialog.InitialDirectory = ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath;

            dialog.Title = "로그 파일 저장";
            dialog.Filters.Add(new CommonFileDialogFilter("txt File", "*.txt"));
            dialog.Filters.Add(new CommonFileDialogFilter("log File", "*.log"));

            if (dialog.ShowDialog() == CommonFileDialogResult.Ok)
            {
                string extension = ".txt";
                if (dialog.SelectedFileTypeIndex == 1)
                    extension = ".txt";
                else
                    extension = ".log";

                List<string> outputList = new List<string>();
                if (CommandModel.LogData.Count == 0)
                {
                    ViewModelLocator.MainVM.showTrackBarMessage("Log Message is Empty");
                    return;
                }

                try
                {
                    foreach (string data in CommandModel.LogData)
                        outputList.Add(data);

                    using (TextWriter tw = new StreamWriter(dialog.FileName + extension))
                    {
                        foreach (String s in outputList)
                            tw.WriteLine(s);

                        tw.Close();
                    }
                    ViewModelLocator.MainVM.showTrackBarMessage("Log Message is Saved (" + Path.GetFileName(dialog.FileName) + extension + ")");
                }
                catch (Exception ex)
                {
                    ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, typeof(CommandViewModel).Name + " :: " + ex.Message + " Line :: " + CommonUtil.GetExceptionLineNumber(ex));
                }
            }
            
        }
        private void BtnDeleteLogAll()
        {
            CommandModel.LogData.Clear();
        }
        public void AddLog(string str)
        {
/*            if (CommandModel.LogData.Count > 800)
            {
                SaveLogData();
            }
            else*/
                CommandModel.LogData.Add(str);
        }

    }
}
