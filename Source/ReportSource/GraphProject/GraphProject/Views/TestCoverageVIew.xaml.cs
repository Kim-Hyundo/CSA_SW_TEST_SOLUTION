using CommonServiceLocator;
using GraphProject.ViewModel;
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
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace GraphProject.Views
{
    /// <summary>
    /// TestCoverageVIew.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class TestCoverageVIew : UserControl
    {
        public TestCoverageVIew()
        {
            InitializeComponent();
        }

        Point scrollMousePoint = new Point();
        double hOff = 1;
        double vOff = 1;
        private void CallCoverageScrollViewer_PreviewMouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            scrollMousePoint = e.GetPosition(CallCoverageScrollViewer);
            hOff = CallCoverageScrollViewer.HorizontalOffset;
            vOff = CallCoverageScrollViewer.VerticalOffset;
            CallCoverageScrollViewer.CaptureMouse();
        }

        private void CallCoverageScrollViewer_PreviewMouseMove(object sender, MouseEventArgs e)
        {
            if (CallCoverageScrollViewer.IsMouseCaptured)
            {
                CallCoverageScrollViewer.ScrollToHorizontalOffset(hOff + (scrollMousePoint.X - e.GetPosition(CallCoverageScrollViewer).X));
                CallCoverageScrollViewer.ScrollToVerticalOffset(vOff + (scrollMousePoint.Y - e.GetPosition(CallCoverageScrollViewer).Y));
            }
        }

        private void CallCoverageScrollViewer_PreviewMouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            CallCoverageScrollViewer.ReleaseMouseCapture();
        }

        Point scrollMousePoint_1 = new Point();
        double hOff_1 = 1;
        double vOff_1 = 1;
        private void FunctionCoverageScrollViewer_PreviewMouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            scrollMousePoint_1 = e.GetPosition(FunctionCoverageScrollViewer);
            hOff_1 = FunctionCoverageScrollViewer.HorizontalOffset;
            vOff_1 = FunctionCoverageScrollViewer.VerticalOffset;
            FunctionCoverageScrollViewer.CaptureMouse();
        }

        private void FunctionCoverageScrollViewer_PreviewMouseMove(object sender, MouseEventArgs e)
        {
            if (FunctionCoverageScrollViewer.IsMouseCaptured)
            {
                FunctionCoverageScrollViewer.ScrollToHorizontalOffset(hOff_1 + (scrollMousePoint_1.X - e.GetPosition(FunctionCoverageScrollViewer).X));
                FunctionCoverageScrollViewer.ScrollToVerticalOffset(vOff_1 + (scrollMousePoint_1.Y - e.GetPosition(FunctionCoverageScrollViewer).Y));
            }
        }

        private void FunctionCoverageScrollViewer_PreviewMouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            FunctionCoverageScrollViewer.ReleaseMouseCapture();
        }

        private void CallCoverage_MouseWheel(object sender, MouseWheelEventArgs e)
        {
            if (e.Delta > 0)
                CallCoverageScrollViewer.ScrollToTop();
            else
                CallCoverageScrollViewer.ScrollToBottom();

        }
        private void FunctionCoverage_MouseWheel(object sender, MouseWheelEventArgs e)
        {
            if (e.Delta > 0)
                FunctionCoverageScrollViewer.ScrollToTop();
            else
                FunctionCoverageScrollViewer.ScrollToBottom();

        }
    }
}
