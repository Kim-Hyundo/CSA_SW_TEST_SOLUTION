using ProstMain.Model;
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

namespace ProstMain.View
{
    /// <summary>
    
    /// </summary>
    public partial class ProjectExplorerView : UserControl
    {
        public ProjectExplorerView()
        {
            InitializeComponent();
            ViewModelLocator.ProjectExplorerVM.ProjectExplorerModel.ProjectExplorerModelList.CollectionChanged += new System.Collections.Specialized.NotifyCollectionChangedEventHandler(items_CollectionChanged);
        }

        void items_CollectionChanged(object sender, System.Collections.Specialized.NotifyCollectionChangedEventArgs e)
        {
            TreeViewItem treeViewItem = (TreeViewItem)(foldersItem.ItemContainerGenerator.ContainerFromIndex(0));
            if (treeViewItem != null)
                treeViewItem.IsSelected = true;
        }

        private void foldersItem_MouseRightButtonUp(object sender, MouseButtonEventArgs e)
        {
/*            if (sender != null)
            {
                TextBlock textBlock = (TextBlock)sender;
                textBlock.Text
            }
            TreeViewItem treeViewItem = VisualUpwardSearch<TreeViewItem>(e.OriginalSource as DependencyObject) as TreeViewItem;
            */
            /*if (treeViewItem != null)
                treeViewItem.IsSelected = true;*/
        }
        static DependencyObject VisualUpwardSearch<T>(DependencyObject source)
        {
            while (source != null && source.GetType() != typeof(T))
                source = VisualTreeHelper.GetParent(source);

            return source;
        }

        private void UserControl_Loaded(object sender, RoutedEventArgs e)
        {
            TreeViewItem treeViewItem = (TreeViewItem)(foldersItem.ItemContainerGenerator.ContainerFromIndex(0));
            if (treeViewItem != null)
                treeViewItem.IsSelected = true;
        }

    }
}
