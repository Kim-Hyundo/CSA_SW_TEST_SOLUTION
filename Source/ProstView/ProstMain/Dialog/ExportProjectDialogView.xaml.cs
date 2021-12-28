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
    /// ExportProjectDialogView.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class ExportProjectDialogView : UserControl
    {
        public ExportProjectDialogView(string header)
        {
            InitializeComponent();
            TextBlockProjectName.Text = header;
        }

        bool isMarquee = false;
        private void TEXTBLOCK_Path_MouseMove(object sender, MouseEventArgs e)
        {
            if (!isMarquee && TEXTBLOCK_Path.ActualWidth > canMain.ActualWidth)
            {

                DoubleAnimation doubleAnimation = new DoubleAnimation();
                doubleAnimation.From = 0;
                doubleAnimation.To = -TEXTBLOCK_Path.ActualWidth;
                doubleAnimation.RepeatBehavior = RepeatBehavior.Forever;
                doubleAnimation.Duration = new Duration(TimeSpan.FromSeconds(10));
                TEXTBLOCK_Path.BeginAnimation(Canvas.LeftProperty, doubleAnimation);
                isMarquee = true;
            }
        }

        private void TEXTBLOCK_Path_MouseLeave(object sender, MouseEventArgs e)
        {
            TEXTBLOCK_Path.BeginAnimation(Canvas.LeftProperty, null);
            DoubleAnimation doubleAnimation = new DoubleAnimation();
            doubleAnimation.BeginTime = null;
            TEXTBLOCK_Path.BeginAnimation(Canvas.LeftProperty, doubleAnimation);
            TEXTBLOCK_Path.Margin = new Thickness(0, 0, 0, 0);
            isMarquee = false;
        }
    }
}
