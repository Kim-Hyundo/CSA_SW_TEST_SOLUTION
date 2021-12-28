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
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace ProstMain.Dialog
{
    /// <summary>
    /// AboutProstDialogView.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class AboutProstDialogView : UserControl
    {
        public AboutProstDialogView()
        {
            InitializeComponent();
        }

        int ClickCount = 0;
        private void Logo_MouseUp(object sender, MouseButtonEventArgs e)
        {
            if (ClickCount <= 3)
                ClickCount++;
            else
                ClickCount = 0;
        }
        private void Version_MouseUp(object sender, MouseButtonEventArgs e)
        {
            if(ClickCount == 3)
            {
                ClickCount = 0;
                ViewModelLocator.MainVM.MainModel.IsHidenMenuEnable = !ViewModelLocator.MainVM.MainModel.IsHidenMenuEnable;
            }

            if (ClickCount >= 3)
                ClickCount++;
            else
                ClickCount = 0;
        }
    }
}
