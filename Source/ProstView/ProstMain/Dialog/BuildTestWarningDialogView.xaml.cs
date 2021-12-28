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

namespace ProstMain.Dialog
{
    /// <summary>
    /// BuildTestWarningDialogView.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class BuildTestWarningDialogView : UserControl
    {
        private bool isMarquee_ELFPath = false;
        private bool isMarquee_MapPath = false;
        public BuildTestWarningDialogView()
        {
            InitializeComponent();
        }

        private void TEXTBLOCK_ELFPath_MouseMove(object sender, MouseEventArgs e)
        {
            if (!isMarquee_ELFPath && TEXTBLOCK_ELFPath.ActualWidth > CANVAS_ELFPath.ActualWidth)
            {
                DoubleAnimation doubleAnimation = new DoubleAnimation();
                doubleAnimation.From = 0;
                doubleAnimation.To = -TEXTBLOCK_ELFPath.ActualWidth;
                doubleAnimation.RepeatBehavior = RepeatBehavior.Forever;
                doubleAnimation.Duration = new Duration(TimeSpan.FromSeconds(10));
                TEXTBLOCK_ELFPath.BeginAnimation(Canvas.LeftProperty, doubleAnimation);
                isMarquee_ELFPath = true;
            }
        }

        private void TEXTBLOCK_ELFPath_MouseLeave(object sender, MouseEventArgs e)
        {
            TEXTBLOCK_ELFPath.BeginAnimation(Canvas.LeftProperty, null);
            DoubleAnimation doubleAnimation = new DoubleAnimation();
            doubleAnimation.BeginTime = null;
            TEXTBLOCK_ELFPath.BeginAnimation(Canvas.LeftProperty, doubleAnimation);
            TEXTBLOCK_ELFPath.Margin = new Thickness(0, 0, 0, 0);
            isMarquee_ELFPath = false;
        }

        private void TEXTBLOCK_MapPath_MouseMove(object sender, MouseEventArgs e)
        {
            if (!isMarquee_MapPath && TEXTBLOCK_MapPath.ActualWidth > CANVAS_MapPath.ActualWidth)
            {
                DoubleAnimation doubleAnimation = new DoubleAnimation();
                doubleAnimation.From = 0;
                doubleAnimation.To = -TEXTBLOCK_MapPath.ActualWidth;
                doubleAnimation.RepeatBehavior = RepeatBehavior.Forever;
                doubleAnimation.Duration = new Duration(TimeSpan.FromSeconds(10));
                TEXTBLOCK_MapPath.BeginAnimation(Canvas.LeftProperty, doubleAnimation);
                isMarquee_MapPath = true;
            }
        }

        private void TEXTBLOCK_MapPath_MouseLeave(object sender, MouseEventArgs e)
        {
            TEXTBLOCK_MapPath.BeginAnimation(Canvas.LeftProperty, null);
            DoubleAnimation doubleAnimation = new DoubleAnimation();
            doubleAnimation.BeginTime = null;
            TEXTBLOCK_MapPath.BeginAnimation(Canvas.LeftProperty, doubleAnimation);
            TEXTBLOCK_MapPath.Margin = new Thickness(0, 0, 0, 0);
            isMarquee_MapPath = false;
        }
    }
}
