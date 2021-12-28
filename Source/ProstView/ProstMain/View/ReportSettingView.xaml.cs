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
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace ProstMain.View
{
    /// <summary>
    /// ReportSettingView.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class ReportSettingView : UserControl
    {
        bool isMarquee_testreportpath = false;
        bool isMarquee_IOTestReportPath = false;
        bool isMarquee_codeCoveragePath = false;
        bool isMarquee_performancePath = false;
        public ReportSettingView()
        {
            InitializeComponent();
        }

        private void TEXTBLOCK_TestReportPath_MouseMove(object sender, MouseEventArgs e)
        {
            if (!isMarquee_testreportpath && TEXTBLOCK_TestReportPath.ActualWidth > CANVAS_TestReportPath.ActualWidth)
            {
                DoubleAnimation doubleAnimation = new DoubleAnimation();
                doubleAnimation.From = 0;
                doubleAnimation.To = -TEXTBLOCK_TestReportPath.ActualWidth;
                doubleAnimation.RepeatBehavior = RepeatBehavior.Forever;
                doubleAnimation.Duration = new Duration(TimeSpan.FromSeconds(10));
                TEXTBLOCK_TestReportPath.BeginAnimation(Canvas.LeftProperty, doubleAnimation);
                isMarquee_testreportpath = true;
            }
        }

        private void TEXTBLOCK_TestReportPath_MouseLeave(object sender, MouseEventArgs e)
        {
            TEXTBLOCK_TestReportPath.BeginAnimation(Canvas.LeftProperty, null);
            DoubleAnimation doubleAnimation = new DoubleAnimation();
            doubleAnimation.BeginTime = null;
            TEXTBLOCK_TestReportPath.BeginAnimation(Canvas.LeftProperty, doubleAnimation);
            TEXTBLOCK_TestReportPath.Margin = new Thickness(0, 0, 0, 0);
            isMarquee_testreportpath = false;
        }

        private void TEXTBLOCK_IOTestReportPath_MouseMove(object sender, MouseEventArgs e)
        {
            if (!isMarquee_IOTestReportPath && TEXTBLOCK_IOTestReportPath.ActualWidth > CANVAS_IOTestPath.ActualWidth)
            {
                DoubleAnimation doubleAnimation = new DoubleAnimation();
                doubleAnimation.From = 0;
                doubleAnimation.To = -TEXTBLOCK_IOTestReportPath.ActualWidth;
                doubleAnimation.RepeatBehavior = RepeatBehavior.Forever;
                doubleAnimation.Duration = new Duration(TimeSpan.FromSeconds(10));
                TEXTBLOCK_IOTestReportPath.BeginAnimation(Canvas.LeftProperty, doubleAnimation);
                isMarquee_IOTestReportPath = true;
            }
        }

        private void TEXTBLOCK_IOTestReportPath_MouseLeave(object sender, MouseEventArgs e)
        {
            TEXTBLOCK_IOTestReportPath.BeginAnimation(Canvas.LeftProperty, null);
            DoubleAnimation doubleAnimation = new DoubleAnimation();
            doubleAnimation.BeginTime = null;
            TEXTBLOCK_IOTestReportPath.BeginAnimation(Canvas.LeftProperty, doubleAnimation);
            TEXTBLOCK_IOTestReportPath.Margin = new Thickness(0, 0, 0, 0);
            isMarquee_IOTestReportPath = false;
        }

        private void TEXTBLOCK_CodeCoverage_MouseMove(object sender, MouseEventArgs e)
        {
            if (!isMarquee_codeCoveragePath && TEXTBLOCK_CodeCoverage.ActualWidth > CANVAS_CodeCoverage.ActualWidth)
            {
                DoubleAnimation doubleAnimation = new DoubleAnimation();
                doubleAnimation.From = 0;
                doubleAnimation.To = -TEXTBLOCK_CodeCoverage.ActualWidth;
                doubleAnimation.RepeatBehavior = RepeatBehavior.Forever;
                doubleAnimation.Duration = new Duration(TimeSpan.FromSeconds(10));
                TEXTBLOCK_CodeCoverage.BeginAnimation(Canvas.LeftProperty, doubleAnimation);
                isMarquee_codeCoveragePath = true;
            }
        }

        private void TEXTBLOCK_CodeCoverage_MouseLeave(object sender, MouseEventArgs e)
        {
            TEXTBLOCK_CodeCoverage.BeginAnimation(Canvas.LeftProperty, null);
            DoubleAnimation doubleAnimation = new DoubleAnimation();
            doubleAnimation.BeginTime = null;
            TEXTBLOCK_CodeCoverage.BeginAnimation(Canvas.LeftProperty, doubleAnimation);
            TEXTBLOCK_CodeCoverage.Margin = new Thickness(0, 0, 0, 0);
            isMarquee_codeCoveragePath = false;
        }

        private void TEXTBLOCK_Performance_MouseMove(object sender, MouseEventArgs e)
        {
            if (!isMarquee_performancePath && TEXTBLOCK_Performance.ActualWidth > CANVAS_Performance.ActualWidth)
            {
                DoubleAnimation doubleAnimation = new DoubleAnimation();
                doubleAnimation.From = 0;
                doubleAnimation.To = -TEXTBLOCK_Performance.ActualWidth;
                doubleAnimation.RepeatBehavior = RepeatBehavior.Forever;
                doubleAnimation.Duration = new Duration(TimeSpan.FromSeconds(10));
                TEXTBLOCK_Performance.BeginAnimation(Canvas.LeftProperty, doubleAnimation);
                isMarquee_performancePath = true;
            }
        }

        private void TEXTBLOCK_Performance_MouseLeave(object sender, MouseEventArgs e)
        {
            TEXTBLOCK_Performance.BeginAnimation(Canvas.LeftProperty, null);
            DoubleAnimation doubleAnimation = new DoubleAnimation();
            doubleAnimation.BeginTime = null;
            TEXTBLOCK_Performance.BeginAnimation(Canvas.LeftProperty, doubleAnimation);
            TEXTBLOCK_Performance.Margin = new Thickness(0, 0, 0, 0);
            isMarquee_performancePath = false;
        }
    }
}
