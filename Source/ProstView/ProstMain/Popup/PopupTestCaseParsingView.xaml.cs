using ProstMain.Util;
using System;
using System.Collections.Generic;
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
    /// PopupTestCaseParsingView_Working.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class PopupTestCaseParsingView : Window
    {
        private bool isMarquee_teststatement = false;
        private bool isMarquee_testcase = false;
        public PopupTestCaseParsingView()
        {
            InitializeComponent();
        }
        private void CommandBinding_CanExecute(object sender, CanExecuteRoutedEventArgs e)
        {
            e.CanExecute = true;
        }

        private void CommandBinding_Executed_Close(object sender, ExecutedRoutedEventArgs e)
        {
            CommonUtil.ExitPythonProcess();
            SystemCommands.CloseWindow(this);
        }

        private void DockPanel_MouseDown(object sender, MouseButtonEventArgs e)
        {
            DragMove();
        }

        private void TEXTBLOCK_TestStatementPath_MouseMove(object sender, MouseEventArgs e)
        {
            if (!isMarquee_teststatement && TEXTBLOCK_TestStatementPath.ActualWidth > CANVAS_TestStatementPath.ActualWidth)
            {

                DoubleAnimation doubleAnimation = new DoubleAnimation();
                doubleAnimation.From = 0;
                doubleAnimation.To = -TEXTBLOCK_TestStatementPath.ActualWidth;
                doubleAnimation.RepeatBehavior = RepeatBehavior.Forever;
                doubleAnimation.Duration = new Duration(TimeSpan.FromSeconds(10));
                TEXTBLOCK_TestStatementPath.BeginAnimation(Canvas.LeftProperty, doubleAnimation);
                isMarquee_teststatement = true;
            }
        }

        private void TEXTBLOCK_TestStatementPath_MouseLeave(object sender, MouseEventArgs e)
        {
            TEXTBLOCK_TestStatementPath.BeginAnimation(Canvas.LeftProperty, null);
            DoubleAnimation doubleAnimation = new DoubleAnimation();
            doubleAnimation.BeginTime = null;
            TEXTBLOCK_TestStatementPath.BeginAnimation(Canvas.LeftProperty, doubleAnimation);
            TEXTBLOCK_TestStatementPath.Margin = new Thickness(0, 0, 0, 0);
            isMarquee_teststatement = false;
        }

        private void TEXTBLOCK_TestCasePath_MouseMove(object sender, MouseEventArgs e)
        {
            if (!isMarquee_testcase && TEXTBLOCK_TestCasePath.ActualWidth > CANVAS_TestCasePath.ActualWidth)
            {
                DoubleAnimation doubleAnimation = new DoubleAnimation();
                doubleAnimation.From = 0;
                doubleAnimation.To = -TEXTBLOCK_TestCasePath.ActualWidth;
                doubleAnimation.RepeatBehavior = RepeatBehavior.Forever;
                doubleAnimation.Duration = new Duration(TimeSpan.FromSeconds(10));
                TEXTBLOCK_TestCasePath.BeginAnimation(Canvas.LeftProperty, doubleAnimation);
                isMarquee_testcase = true;
            }
        }

        private void TEXTBLOCK_TestCasePath_MouseLeave(object sender, MouseEventArgs e)
        {
            TEXTBLOCK_TestCasePath.BeginAnimation(Canvas.LeftProperty, null);
            DoubleAnimation doubleAnimation = new DoubleAnimation();
            doubleAnimation.BeginTime = null;
            TEXTBLOCK_TestCasePath.BeginAnimation(Canvas.LeftProperty, doubleAnimation);
            TEXTBLOCK_TestCasePath.Margin = new Thickness(0, 0, 0, 0);
            isMarquee_testcase = false;
        }
    }
}
