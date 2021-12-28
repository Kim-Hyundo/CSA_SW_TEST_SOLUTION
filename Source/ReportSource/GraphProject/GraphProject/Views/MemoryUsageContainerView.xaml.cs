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
    /// MemoryUsageContainerView.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class MemoryUsageContainerView : UserControl
    {
        public static MemoryUsageContainerView Instance { get; private set; }

        public MemoryUsageContainerView()
        {
            InitializeComponent();
            Instance = this;
            MemoryUsageContainerViewModel.test_tmp.Add(TotalContentView);
        }
        public void UpdateBottomContentView(Grid g)
        {
            BottomContentView.Content = g;
        }

    }
}
