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
using System.Windows.Threading;

namespace GraphProject.Views
{
    /// <summary>
    /// TestFailGridView.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class TestFailGridView : UserControl
    {
        public TestFailGridView()
        {
            InitializeComponent();
            
        }

        private void StackPanel_MouseWheel(object sender, MouseWheelEventArgs e)
        {
            if (e.Delta > 0)
                ContentScrollViewer.ScrollToTop();
            else
                ContentScrollViewer.ScrollToBottom();

        }

        Point scrollMousePoint = new Point();
        double hOff = 1;
        double vOff = 1;
        private void scrollViewer_PreviewMouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            scrollMousePoint = e.GetPosition(ContentScrollViewer);
            hOff = ContentScrollViewer.HorizontalOffset;
            vOff = ContentScrollViewer.VerticalOffset;
            ContentScrollViewer.CaptureMouse();
        }

        private void scrollViewer_PreviewMouseMove(object sender, MouseEventArgs e)
        {
            if (ContentScrollViewer.IsMouseCaptured)
            {
                ContentScrollViewer.ScrollToHorizontalOffset(hOff + (scrollMousePoint.X - e.GetPosition(ContentScrollViewer).X));
                ContentScrollViewer.ScrollToVerticalOffset(vOff + (scrollMousePoint.Y - e.GetPosition(ContentScrollViewer).Y));
            }
        }

        private void scrollViewer_PreviewMouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            ContentScrollViewer.ReleaseMouseCapture();
        }

        private void DebugItem_Click(object sender, RoutedEventArgs e)
        {
            MenuItem item = (MenuItem)sender;
            CommonServiceLocator.ServiceLocator.Current.GetInstance<TestFailGridViewModel>().DebugButtonFunction(item.Tag);
        }
    }
}
