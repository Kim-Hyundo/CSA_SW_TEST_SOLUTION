using Hardcodet.Wpf.TaskbarNotification;
using ProstMain.ViewModel;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Threading;

namespace ProstMain.View
{
    /// <summary>
    /// MainWindow.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class MainWindow : Window
    {
        bool isImageSwitch = false;
        public MainWindow()
        {
            InitializeComponent();

            DispatcherTimer trace32ConnectTimer = new DispatcherTimer();
            trace32ConnectTimer.Interval = TimeSpan.FromSeconds(0.4);
            trace32ConnectTimer.Tick += new EventHandler(timer_Tick);
            trace32ConnectTimer.Start();

            StateChanged += MainWindowStateChangeRaised;
        }

        private void timer_Tick(object sender, EventArgs e)
        {
            if(isImageSwitch)
            {
                if (ViewModelLocator.MainVM.MainModel.IsTrace32Connection)
                {
                    IMAGE_trace32Connect.Background = Brushes.Green;
                    TEXTBLOCK_Trace32Connection.Text = "TRACE32 Connection";
                }
                else
                {
                    IMAGE_trace32Connect.Background = Brushes.Red;
                    TEXTBLOCK_Trace32Connection.Text = "TRACE32 Disconnection";
                }
                    
            }
            else
            {
                IMAGE_trace32Connect.Background = Brushes.Gray;
            }
            isImageSwitch = !isImageSwitch;
        }
        private void CommandBinding_CanExecute(object sender, CanExecuteRoutedEventArgs e)
        {
            e.CanExecute = true;
        }

        // Minimize
        private void CommandBinding_Executed_Minimize(object sender, ExecutedRoutedEventArgs e)
        {
            SystemCommands.MinimizeWindow(this);
        }
        private void CommandBinding_Executed_Maximize(object sender, ExecutedRoutedEventArgs e)
        {
            SystemCommands.MaximizeWindow(this);
        }

        // Restore
        private void CommandBinding_Executed_Restore(object sender, ExecutedRoutedEventArgs e)
        {
            SystemCommands.RestoreWindow(this);
        }


        private void TitleBar_MouseDown(object sender, MouseButtonEventArgs e)
        {
            DragMove();
        }

        private void popup_Opened(object sender, EventArgs e)
        {
            TrackBarPopupGroupbox.Background = (SolidColorBrush)App.Current.Resources["StandardBackground"];
            TrackBarText.Foreground = (SolidColorBrush)App.Current.Resources["StandardTextForeground"];
            //TrackBarPopupGroupboxHeader.Background = (SolidColorBrush)App.Current.Resources["GroupBoxHeaderGradient"];
            BUTTON_TrackBarShowWindow.Background = (SolidColorBrush)App.Current.Resources["TrackBarButtonBackground"];
            BUTTON_TrackBarShowLogWindow.Background = (SolidColorBrush)App.Current.Resources["TrackBarButtonBackground"];
            //BUTTON_TrackBarRun.Background = (SolidColorBrush)App.Current.Resources["TrackBarButtonBackground"];

            BUTTON_TrackBarShowWindow.BorderBrush = Brushes.Transparent;
            BUTTON_TrackBarShowLogWindow.BorderBrush = Brushes.Transparent;
            //BUTTON_TrackBarRun.BorderBrush = Brushes.Transparent;

            windowicon.Foreground = (SolidColorBrush)App.Current.Resources["StandardTextForeground"];
            Logicon.Foreground = (SolidColorBrush)App.Current.Resources["StandardTextForeground"];
            //playicon.Foreground = (SolidColorBrush)App.Current.Resources["StandardTextForeground"];



            popup.VerticalOffset = SystemParameters.WorkArea.Height - 150;
            popup.HorizontalOffset = SystemParameters.WorkArea.Width - 260;
        }

        private void Grid_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            ViewModelLocator.MainVM.MainModel.isPopupOpen = false;
        }

        private void mainwindow_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.S && Keyboard.IsKeyDown(Key.LeftCtrl))
            {
                ViewModelLocator.MainVM.MainModel.BeforeSaveMode = Common.Common.SAVE_MODE;
                ViewModelLocator.MainVM.ShowDialog_SaveProject(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName);
            }
            else if (e.Key == Key.S && !Keyboard.IsKeyDown(Key.LeftCtrl))
            {
                return;
            }
        }
        private void MainWindowStateChangeRaised(object sender, EventArgs e)
        {
            if (WindowState == WindowState.Maximized)
            {
                RestoreButton.Visibility = Visibility.Visible;
                MaximizeButton.Visibility = Visibility.Collapsed;
            }
            else
            {
                RestoreButton.Visibility = Visibility.Collapsed;
                MaximizeButton.Visibility = Visibility.Visible;
            }
        }
    }

}
