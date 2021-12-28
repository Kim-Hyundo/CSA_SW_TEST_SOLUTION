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
    /// TimingChartContainerView.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class TimingChartContainerView : UserControl
    {
        public TimingChartContainerView()
        {
            InitializeComponent();

            TimingChartContainerViewModel.test_tmp.Add(TimingTitle);

        }

        private void SearchTextbox_TextChanged(object sender, TextChangedEventArgs e)
        {

        }

        private void SearchTextBox_KeyUp(object sender, KeyEventArgs e)
        {
            if(e.Key == Key.Enter)
            {
                CommonServiceLocator.ServiceLocator.Current.GetInstance<TimingChartContainerViewModel>().Search(SearchTextBox.Text);
            }
        }
    }
}
