using ProstMain.ViewModel;
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
using System.Windows.Shapes;

namespace ProstMain.Popup
{
    /// <summary>
    /// PopupTestStatusView.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class PopupTestStatusView : Window
    {
        public PopupTestStatusView()
        {
            InitializeComponent();
        }

        private void DockPanel_MouseDown(object sender, MouseButtonEventArgs e)
        {
            //DragMove();
        }

        private void Window_Closed(object sender, EventArgs e)
        {
            Common.Common.m_PopupTestStatusView = null;
            ViewModelLocator.ToolbarVM.ToolbarModel.IsToolbarEnable = true;
            ViewModelLocator.MenuBarVM.IsMenubarEnable = true;
        }
    }
}
