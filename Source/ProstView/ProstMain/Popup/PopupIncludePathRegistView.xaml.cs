using ProstMain.ViewModel;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace ProstMain.Popup
{
    /// <summary>
    /// PopupIncludePathRegistView.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class PopupIncludePathRegistView : Window
    {
        bool isMarquee_directorypath = false;
        public PopupIncludePathRegistView(string msg)
        {
            InitializeComponent();
            tb_title.Text = msg + " Include Path";
        }

        private void CANVAS_DirectoryPath_MouseMove(object sender, MouseEventArgs e)
        {
            if (!isMarquee_directorypath && TEXTBLOCK_DisplayDirectoryPath.ActualWidth > CANVAS_DirectoryPath.ActualWidth)
            {
                DoubleAnimation doubleAnimation = new DoubleAnimation();
                doubleAnimation.From = 0;
                doubleAnimation.To = -TEXTBLOCK_DisplayDirectoryPath.ActualWidth;
                doubleAnimation.RepeatBehavior = RepeatBehavior.Forever;
                doubleAnimation.Duration = new Duration(TimeSpan.FromSeconds(10));
                TEXTBLOCK_DisplayDirectoryPath.BeginAnimation(Canvas.LeftProperty, doubleAnimation);
                isMarquee_directorypath = true;
            }
        }

        private void CANVAS_DirectoryPath_MouseLeave(object sender, MouseEventArgs e)
        {
            TEXTBLOCK_DisplayDirectoryPath.BeginAnimation(Canvas.LeftProperty, null);
            DoubleAnimation doubleAnimation = new DoubleAnimation();
            doubleAnimation.BeginTime = null;
            TEXTBLOCK_DisplayDirectoryPath.BeginAnimation(Canvas.LeftProperty, doubleAnimation);
            TEXTBLOCK_DisplayDirectoryPath.Margin = new Thickness(0, 0, 0, 0);
            isMarquee_directorypath = false;
        }

        private void DockPanel_MouseDown(object sender, MouseButtonEventArgs e)
        {
            DragMove();
        }

        private void CommandBinding_CanExecute(object sender, CanExecuteRoutedEventArgs e)
        {
            e.CanExecute = true;
        }

        private void CommandBinding_Executed_Close(object sender, ExecutedRoutedEventArgs e)
        {
            SystemCommands.CloseWindow(this);
        }
    }
}
