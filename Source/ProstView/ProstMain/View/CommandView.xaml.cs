using ProstMain.Model;
using ProstMain.ViewModel;
using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Threading;
using static ProstMain.Model.CommandModel;

namespace ProstMain.View
{
    /// <summary>
    /// CommandView.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class CommandView : UserControl
    {
        public CommandView()
        {
            InitializeComponent();
            logview.ItemContainerGenerator.StatusChanged += ItemContainerGenerator_StatusChanged;
            //((INotifyCollectionChanged)logview.Items).CollectionChanged += (s, e2) => ScrollToBottom(logview, e2.Action);
            


        }
        void ItemContainerGenerator_StatusChanged(object sender, EventArgs e)
        {
            if (logview.ItemContainerGenerator.Status == GeneratorStatus.ContainersGenerated)
            {
                var info = logview.Items[logview.Items.Count - 1];
                if (info == null)
                    return;

                Dispatcher.BeginInvoke(DispatcherPriority.ApplicationIdle, new Action(() =>
                {
                    logview.ScrollIntoView(info);
                }));
            }
        }
        private void ScrollToBottom(ListView log, NotifyCollectionChangedAction action)
        {
            if (log == null || !log.IsInitialized || action != NotifyCollectionChangedAction.Add || log.Items.Count == 0) return;

            var items = log.Items;
            var last = items[items.Count - 1];

            Dispatcher.BeginInvoke(DispatcherPriority.ApplicationIdle, new Action(() =>
            {
                log.ScrollIntoView(last);
                log.UpdateLayout();
            }));
        }
        private void ListView_KeyDown(object sender, KeyEventArgs e)
        {
            if (sender != logview) return;

            if (e.Key == Key.C && Keyboard.IsKeyDown(Key.LeftCtrl))
                CopySelectedValuesToClipboard();
        }

        private void CopySelectedValuesToClipboard()
        {
            var builder = new StringBuilder();
            foreach (string item in logview.SelectedItems)
                builder.AppendLine(item);

            Clipboard.SetText(builder.ToString());
        }

        private bool excuteFilter(object item)
        {
            bool result = false;
            string logItem = item as string;

            if (LogSearchText.SearchTerm == null)
                LogSearchText.SearchTerm = "";

            if (logItem.Contains(LogSearchText.SearchTerm))
                result = true;

            return result;
            
        }

        private void PersistentSearch_Search(object sender, MaterialDesignExtensions.Controls.SearchEventArgs args)
        {
            ICollectionView phrasesView;
            phrasesView = CollectionViewSource.GetDefaultView(ViewModelLocator.CommandVM.CommandModel.LogData);
            phrasesView.Filter = null;

            phrasesView.Filter = excuteFilter;
            
            phrasesView.Refresh();
        }

        private void LogSearchText_GotFocus(object sender, RoutedEventArgs e)
        {
            Dispatcher dispatcher = System.Windows.Application.Current.Dispatcher;
            DispatcherOperation dispatcherOperation = dispatcher.BeginInvoke(System.Windows.Threading.DispatcherPriority.Send, (ThreadStart)
            delegate ()
            {
                ICollectionView phrasesView;
                phrasesView = CollectionViewSource.GetDefaultView(ViewModelLocator.CommandVM.CommandModel.LogData);
                phrasesView.Filter = null;

                phrasesView.Filter = excuteFilter;

                phrasesView.Refresh();
            });
        }
    }
}
