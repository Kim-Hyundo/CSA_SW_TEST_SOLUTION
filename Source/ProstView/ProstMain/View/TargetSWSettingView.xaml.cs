using ProstMain.ViewModel;
using System;
using System.Collections.Generic;
using System.IO;
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
using WSF.Interfaces;
using Javi.ExplorerTreeView;

namespace ProstMain.View
{
    /// <summary>
    /// TargetSWSettingView.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class TargetSWSettingView : UserControl
    {

        private bool isMarquee_sourcecodpath = false;
        private bool isMarquee_localpath = false;
        private bool isMarquee_Rootpath = false;
        Point _lastMouseDown;

        private static class LazyHolder
        {
            public static readonly TargetSWSettingView INSTANCE = new TargetSWSettingView();
        }

        public static TargetSWSettingView getInstance()
        {
            return LazyHolder.INSTANCE;
        }

        public TargetSWSettingView()
        {
            InitializeComponent();

        }

        private void Stub_Add_Click(object sender, RoutedEventArgs e)
        {
            popupbox_stub.IsPopupOpen = false;
        }

        private void Register_Add_Click(object sender, RoutedEventArgs e)
        {
            popupbox_register.IsPopupOpen = false;
        }

        private void Runnable_Add_Click(object sender, RoutedEventArgs e)
        {
            popupbox_runnable.IsPopupOpen = false;
        }
        private void InitFunc_Add_Click(object sender, RoutedEventArgs e)
        {
            popupbox_initfunc.IsPopupOpen = false;
        }
        private void TreeView_MouseDown(object sender, MouseButtonEventArgs e)
        {
            if (e.ChangedButton == MouseButton.Left)
            {
                _lastMouseDown = e.GetPosition(local_treeview);
            }

        }
        private void treeView_MouseMove(object sender, MouseEventArgs e)
        {
            try
            {
                object element = VisualTreeHelper.GetParent(VisualTreeHelper.GetParent((ExplorerTreeViewItem)sender));
                bool a = target_treeview.IsFocused;
                bool b = local_treeview.IsFocused;
                if (e.LeftButton == MouseButtonState.Pressed)
                {
                    Point currentPosition = e.GetPosition(local_treeview);


                    if ((Math.Abs(currentPosition.X - _lastMouseDown.X) > 10.0) ||
                        (Math.Abs(currentPosition.Y - _lastMouseDown.Y) > 10.0))
                    {
                        ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceTreeViewItem = (ExplorerTreeViewItem)local_treeview.SelectedItem;
                        if (ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceTreeViewItem != null)
                        {
                            DragDropEffects finalDropEffect = DragDrop.DoDragDrop(local_treeview, local_treeview.SelectedValue,
                                DragDropEffects.Move);


                            if ((finalDropEffect == DragDropEffects.Move) && (ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.TargetTreeViewItem != null))
                            {
                                // A Move drop was accepted
                                if (!ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceTreeViewItem.Header.ToString().Equals(ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.TargetTreeViewItem.Header.ToString()))
                                {
                                    try
                                    {
                                        IDirectoryBrowser directoryBrowser = ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.TargetTreeViewItem.Tag as IDirectoryBrowser;
                                        if (directoryBrowser != null && directoryBrowser.FullName.Contains(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Target_SW"))
                                            ViewModelLocator.TargetSWSettingVM.ShowDialog_AddTreeViewItem("Would you like to Copy " + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceTreeViewItem.Header.ToString() + " into " + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.TargetTreeViewItem.Header.ToString());
                                    }
                                    catch
                                    {

                                    }
                                }

                            }
                        }
                    }
                }
            }
            catch (Exception)
            {
            }
        }
        private void treeView_DragOver(object sender, DragEventArgs e)
        {
            try
            {
                Point currentPosition = e.GetPosition(local_treeview);


                if ((Math.Abs(currentPosition.X - _lastMouseDown.X) > 10.0) ||
                    (Math.Abs(currentPosition.Y - _lastMouseDown.Y) > 10.0))
                {
                    // Verify that this is a valid drop and then store the drop target
                    ExplorerTreeViewItem item = GetNearestContainer(e.OriginalSource as UIElement);

                    if (CheckDropTarget(ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceTreeViewItem, item))
                    {
                        e.Effects = DragDropEffects.Move;
                    }
                    else
                    {
                        e.Effects = DragDropEffects.None;
                    }
                }
                e.Handled = true;
            }
            catch (Exception)
            {
            }
        }
        private void treeView_Drop(object sender, DragEventArgs e)
        {
            try
            {

                e.Effects = DragDropEffects.None;
                e.Handled = true;

                // Verify that this is a valid drop and then store the drop target
                ExplorerTreeViewItem TargetItem = GetNearestContainer(e.OriginalSource as UIElement);

                if (TargetItem != null && ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceTreeViewItem != null)
                {
                    ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.TargetTreeViewItem = TargetItem;
                    e.Effects = DragDropEffects.Move;

                }
            }
            catch (Exception)
            {
            }



        }
        private bool CheckDropTarget(ExplorerTreeViewItem _sourceItem, ExplorerTreeViewItem _targetItem)
        {
            //Check whether the target item is meeting your condition
            bool _isEqual = false;
            if (!_sourceItem.Header.ToString().Equals(_targetItem.Header.ToString()))
            {
                _isEqual = true;
            }
            return _isEqual;

        }


        public ExplorerTreeViewItem GetNearestContainer(UIElement element)
        {
            // Walk up the element tree to the nearest tree view item.
            ExplorerTreeViewItem container = element as ExplorerTreeViewItem;
            while ((container == null) && (element != null))
            {
                element = VisualTreeHelper.GetParent(element) as UIElement;
                container = element as ExplorerTreeViewItem;
            }
            return container;
        }

        private void CANVAS_SourceCodePath_MouseMove(object sender, MouseEventArgs e)
        {
            if (!isMarquee_sourcecodpath && TEXTBLOCK_SourceCodePath.ActualWidth > CANVAS_SourceCodePath.ActualWidth)
            {
                DoubleAnimation doubleAnimation = new DoubleAnimation();
                doubleAnimation.From = 0;
                doubleAnimation.To = -TEXTBLOCK_SourceCodePath.ActualWidth;
                doubleAnimation.RepeatBehavior = RepeatBehavior.Forever;
                doubleAnimation.Duration = new Duration(TimeSpan.FromSeconds(10));
                TEXTBLOCK_SourceCodePath.BeginAnimation(Canvas.LeftProperty, doubleAnimation);
                isMarquee_sourcecodpath = true;
            }
        }

        private void CANVAS_SourceCodePath_MouseLeave(object sender, MouseEventArgs e)
        {
            TEXTBLOCK_SourceCodePath.BeginAnimation(Canvas.LeftProperty, null);
            DoubleAnimation doubleAnimation = new DoubleAnimation();
            doubleAnimation.BeginTime = null;
            TEXTBLOCK_SourceCodePath.BeginAnimation(Canvas.LeftProperty, doubleAnimation);
            TEXTBLOCK_SourceCodePath.Margin = new Thickness(0, 0, 0, 0);
            isMarquee_sourcecodpath = false;
        }

        private void project_treeview_MouseMove(object sender, MouseEventArgs e)
        {

        }

        private void CANVAS_LocalPath_MouseMove(object sender, MouseEventArgs e)
        {
            if (!isMarquee_localpath && TEXTBLOCK_LocalPath.ActualWidth > CANVAS_LocalPath.ActualWidth)
            {
                DoubleAnimation doubleAnimation = new DoubleAnimation();
                doubleAnimation.From = 0;
                doubleAnimation.To = -TEXTBLOCK_LocalPath.ActualWidth;
                doubleAnimation.RepeatBehavior = RepeatBehavior.Forever;
                doubleAnimation.Duration = new Duration(TimeSpan.FromSeconds(10));
                TEXTBLOCK_LocalPath.BeginAnimation(Canvas.LeftProperty, doubleAnimation);
                isMarquee_localpath = true;
            }
        }

        private void CANVAS_LocalPath_MouseLeave(object sender, MouseEventArgs e)
        {
            TEXTBLOCK_LocalPath.BeginAnimation(Canvas.LeftProperty, null);
            DoubleAnimation doubleAnimation = new DoubleAnimation();
            doubleAnimation.BeginTime = null;
            TEXTBLOCK_LocalPath.BeginAnimation(Canvas.LeftProperty, doubleAnimation);
            TEXTBLOCK_LocalPath.Margin = new Thickness(0, 0, 0, 0);
            isMarquee_localpath = false;
        }

        public void RefreshTreeView(ExplorerTreeViewItem s)
        {
            s.IsExpanded = false;
            s.IsExpanded = true;
        }

        private void CANVAS_TargetSourcepath_MouseMove(object sender, MouseEventArgs e)
        {
            if (!isMarquee_Rootpath && TEXTBLOCK_TargetSourcepath.ActualWidth > CANVAS_TargetSourcepath.ActualWidth)
            {
                DoubleAnimation doubleAnimation = new DoubleAnimation();
                doubleAnimation.From = 0;
                doubleAnimation.To = -TEXTBLOCK_TargetSourcepath.ActualWidth;
                doubleAnimation.RepeatBehavior = RepeatBehavior.Forever;
                doubleAnimation.Duration = new Duration(TimeSpan.FromSeconds(10));
                TEXTBLOCK_TargetSourcepath.BeginAnimation(Canvas.LeftProperty, doubleAnimation);
                isMarquee_Rootpath = true;
            }
        }

        private void CANVAS_TargetSourcepath_MouseLeave(object sender, MouseEventArgs e)
        {
            TEXTBLOCK_TargetSourcepath.BeginAnimation(Canvas.LeftProperty, null);
            DoubleAnimation doubleAnimation = new DoubleAnimation();
            doubleAnimation.BeginTime = null;
            TEXTBLOCK_TargetSourcepath.BeginAnimation(Canvas.LeftProperty, doubleAnimation);
            TEXTBLOCK_TargetSourcepath.Margin = new Thickness(0, 0, 0, 0);
            isMarquee_Rootpath = false;
        }

        private void treeView_DragOver_RootPath(object sender, DragEventArgs e)
        {
            try
            {
                Point currentPosition = e.GetPosition(target_treeview);


                if ((Math.Abs(currentPosition.X - _lastMouseDown.X) > 10.0) ||
                    (Math.Abs(currentPosition.Y - _lastMouseDown.Y) > 10.0))
                {
                    // Verify that this is a valid drop and then store the drop target
                    ExplorerTreeViewItem item = GetNearestContainer(e.OriginalSource as UIElement);

                    if (CheckDropTarget(ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceTreeViewItem, item))
                    {
                        e.Effects = DragDropEffects.Move;
                    }
                    else
                    {
                        e.Effects = DragDropEffects.None;
                    }
                }
                e.Handled = true;
            }
            catch (Exception)
            {
            }
        }

        private void treeView_Drop_RootPath(object sender, DragEventArgs e)
        {
            try
            {

                e.Effects = DragDropEffects.None;
                e.Handled = true;

                // Verify that this is a valid drop and then store the drop target
                ExplorerTreeViewItem TargetItem = GetNearestContainer(e.OriginalSource as UIElement);

                if (TargetItem != null && ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceTreeViewItem != null)
                {
                    ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.TargetTreeViewItem = TargetItem;
                    e.Effects = DragDropEffects.Move;

                }
            }
            catch (Exception)
            {
            }
        }

        private void treeView_MouseMove_RootPath(object sender, MouseEventArgs e)
        {
            try
            {
                if (e.LeftButton == MouseButtonState.Pressed)
                {
                    Point currentPosition = e.GetPosition(target_treeview);


                    if ((Math.Abs(currentPosition.X - _lastMouseDown.X) > 10.0) ||
                        (Math.Abs(currentPosition.Y - _lastMouseDown.Y) > 10.0))
                    {
                        ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceTreeViewItem = (ExplorerTreeViewItem)target_treeview.SelectedItem;
                        if (ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceTreeViewItem != null)
                        {
                            DragDropEffects finalDropEffect = DragDrop.DoDragDrop(target_treeview, target_treeview.SelectedValue,
                                DragDropEffects.Move);


                            if ((finalDropEffect == DragDropEffects.Move) && (ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.TargetTreeViewItem != null))
                            {
                                // A Move drop was accepted
                                if (!ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceTreeViewItem.Header.ToString().Equals(ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.TargetTreeViewItem.Header.ToString()))
                                {
                                    try
                                    {
                                        IDirectoryBrowser directoryBrowser = ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.TargetTreeViewItem.Tag as IDirectoryBrowser;
                                        if (directoryBrowser != null && directoryBrowser.FullName.Contains(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Target_SW"))
                                            ViewModelLocator.TargetSWSettingVM.ShowDialog_AddTreeViewItem("Would you like to Copy " + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceTreeViewItem.Header.ToString() + " into " + ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.TargetTreeViewItem.Header.ToString());
                                    }
                                    catch
                                    {

                                    }
                                }

                            }
                        }
                    }
                }
            }
            catch (Exception)
            {
            }
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {

        }
    }
}
