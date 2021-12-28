// -----------------------------------------------------------------------
// <copyright file="ExplorerTreeView.cs">
// All rights reserved.
// </copyright>
// -----------------------------------------------------------------------

namespace Javi.ExplorerTreeView
{
    using System;
    using System.Collections.Generic;
    using System.IO;
    using System.Text;
    using System.Windows;
    using System.Windows.Controls;
    using System.Windows.Controls.Primitives;
    using WSF;
    using WSF.Enums;
    using WSF.IDs;
    using WSF.Interfaces;

    /// <summary>
    /// This control displays a file system tree akin the navigation pane in the windows explorer application.
    /// Based on https://blog.khmylov.com/2010/11/18/wpf-explorer-treeview-with-selectedpath-binding/
    /// which inherits from https://www.codeproject.com/Articles/21248/A-Simple-WPF-Explorer-Tree
    /// see also https://joshsmithonwpf.wordpress.com/2007/11/09/reaction-to-a-simple-wpf-explorer-tree/
    /// Uses the nuget package Dirkster.WSF to get all known folders from the windows shell.
    /// </summary>
    public class ExplorerTreeView : TreeView
    {
        #region Dependency properties

        public ExplorerTreeViewItem SelectedExplorerTreeViewItem
        {
            get
            {
                return (ExplorerTreeViewItem)GetValue(SelectedExplorerTreeViewItemProperty);
            }
            set
            {
                SetValue(SelectedExplorerTreeViewItemProperty, value);
            }
        }
        public static readonly DependencyProperty SelectedExplorerTreeViewItemProperty = DependencyProperty
            .Register("SelectedExplorerTreeViewItem", typeof(ExplorerTreeViewItem), typeof(ExplorerTreeView), new UIPropertyMetadata(null));

        public bool UnloadItemsOnCollapse
        {
            get
            {
                return (bool)GetValue(UnloadItemsOnCollapseProperty);
            }
            set
            {
                SetValue(UnloadItemsOnCollapseProperty, value);
            }
        }
        public static readonly DependencyProperty UnloadItemsOnCollapseProperty = DependencyProperty
            .Register("UnloadItemsOnCollapse", typeof(bool), typeof(ExplorerTreeView), new UIPropertyMetadata(true));

        public bool Sort
        {
            get
            {
                return (bool)GetValue(SortProperty);
            }
            set
            {
                SetValue(SortProperty, value);
            }
        }
        public static readonly DependencyProperty SortProperty = DependencyProperty
            .Register("Sort", typeof(bool), typeof(ExplorerTreeView), new UIPropertyMetadata(true));

        public ExplorerTreeViewRootEnum Root
        {
            get
            {
                return (ExplorerTreeViewRootEnum)GetValue(RootProperty);
            }
            set
            {
                SetValue(RootProperty, value);
            }
        }
        public static readonly DependencyProperty RootProperty = DependencyProperty
            .Register("Root", typeof(ExplorerTreeViewRootEnum), typeof(ExplorerTreeView), 
                      new UIPropertyMetadata(ExplorerTreeViewRootEnum.Desktop, 
                                             (o, e) => ((ExplorerTreeView)o).InitExplorer()));

        public string CustomPath
        {
            get
            {
                return (string)GetValue(CustomPathProperty);
            }
            set
            {
                SetValue(CustomPathProperty, value);
            }
        }
        public static readonly DependencyProperty CustomPathProperty = DependencyProperty
            .Register(nameof(CustomPath), typeof(string), typeof(ExplorerTreeView), new UIPropertyMetadata((object)"C:\\", (PropertyChangedCallback)((o, e) => ((Javi.ExplorerTreeView.ExplorerTreeView)o).InitExplorer())));

        public static readonly DependencyProperty CopyDicProperty = DependencyProperty.
            Register(nameof(CopyDic), typeof(Dictionary<string, string>), typeof(ExplorerTreeView), new UIPropertyMetadata((object)new Dictionary<string, string>(), (PropertyChangedCallback)((o, e) => ((ExplorerTreeView)o).InitExplorer())));

        public Dictionary<string,string> CopyDic
        {
            get
            {
                return (Dictionary<string, string>)GetValue(ExplorerTreeView.CopyDicProperty);
            }
            set
            {
                SetValue(CopyDicProperty, value);
            }
        }

        public string WorkSpacePath
        {
            get
            {
                return (string)GetValue(WorkSpacePathProperty);
            }
            set
            {
                SetValue(WorkSpacePathProperty, value);
            }
        }
        public static readonly DependencyProperty WorkSpacePathProperty = DependencyProperty
            .Register(nameof(WorkSpacePath), typeof(string), typeof(ExplorerTreeView), new UIPropertyMetadata(""));

        public string SourceCodePath
        {
            get
            {
                return (string)GetValue(SourceCodePathProperty);
            }
            set
            {
                SetValue(SourceCodePathProperty, value);
            }
        }
        public static readonly DependencyProperty SourceCodePathProperty = DependencyProperty
            .Register(nameof(SourceCodePath), typeof(string), typeof(ExplorerTreeView), new UIPropertyMetadata(""));



        #endregion

        #region fields
        private bool IsExplorerTreeViewLoaded = false;
        #endregion

        /// <summary>
        /// This event is raised if an error occurs while creating the file system tree.
        /// </summary>
        public event EventHandler<ExplorerTreeViewErrorEventArgs> ExplorerError;

        /// <summary>
        /// Invocator for <see cref="ExplorerError"/> event.
        /// </summary>
        /// <param name="e"></param>
        private void InvokeExplorerError(ExplorerTreeViewErrorEventArgs e)
        {
            ExplorerError?.Invoke(this, e);
        }

        /// <summary>
        /// Initializes a new instance of the <see cref="ExplorerTreeView"/> class.
        /// </summary>
        public ExplorerTreeView()
        {
            Loaded += ExplorerTreeView_Loaded;

            SelectedItemChanged += new RoutedPropertyChangedEventHandler<object>(OnSelectedItemChanged);

            AddHandler(ExplorerTreeViewItem.ExpandedEvent, new RoutedEventHandler(OnItemExpanded));
            AddHandler(ExplorerTreeViewItem.CollapsedEvent, new RoutedEventHandler(OnItemCollapsed));
            
        }
        private ExplorerTreeViewItem CreateFolderItem(object tag,string header,string copypath)
        {
            ExplorerTreeViewItem explorerTreeViewItem = new ExplorerTreeViewItem();
            explorerTreeViewItem.Tag = tag;
            explorerTreeViewItem.Header = (object)header;
            if (copypath != null && copypath != "")
                explorerTreeViewItem.CopyPath = copypath;
            explorerTreeViewItem.Items.Add((object)"*");
            return explorerTreeViewItem;
        }
        private ExplorerTreeViewItem CreateFileItem(object tag, string header, string copypath)
        {
            ExplorerTreeViewItem explorerTreeViewItem = new ExplorerTreeViewItem();
            explorerTreeViewItem.Tag = tag;
            explorerTreeViewItem.Header = (object)header;
            int num = copypath == null ? 0 : (copypath != "" ? 1 : 0);
            explorerTreeViewItem.CopyPath = num == 0 ? "" : copypath;
            return explorerTreeViewItem;
        }

        private void ExplorerTreeView_Loaded(object sender, RoutedEventArgs e)
        {
            if (!this.IsExplorerTreeViewLoaded)
            {
                this.IsExplorerTreeViewLoaded = true;
                InitExplorer();
            }
        }

        /// <summary>
        /// This method is invoked when user selects a node.
        /// It causes <see cref="SelectedFolder"/> to update its value.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void OnSelectedItemChanged(object sender, RoutedEventArgs e)
        {
            SelectedExplorerTreeViewItem = (ExplorerTreeViewItem)((ExplorerTreeView)sender).SelectedItem;
        }

        /// <summary>
        /// Occurs when tree node is expanded.
        /// Reloads node sub-folders, if required.
        /// May raise <see cref="ExplorerError"/> on some IO exceptions.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void OnItemExpanded(object sender, RoutedEventArgs e)
        {
            var item = (ExplorerTreeViewItem)e.OriginalSource;

            if (UnloadItemsOnCollapse || !HasSubFolders(item))
            {
                item.Items.Clear();
                IterateFolders(item.Tag as IDirectoryBrowser, item.Items, item.CopyPath);
            }
        }

        /// <summary>
        /// Occurs when tree node is collapsed.
        /// Unloads node sub-folders, if <see cref="UnloadItemsOnCollapse"/> is set to True.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void OnItemCollapsed(object sender, RoutedEventArgs e)
        {
            if (UnloadItemsOnCollapse)
            {
                var item = (ExplorerTreeViewItem)e.OriginalSource;
                item.Items.Clear();
                item.Items.Add("*");
            }
        }

        /// <summary>
        /// Checks whether specified <see cref="ExplorerTreeViewItem"/> has any real sub-folder nodes.
        /// </summary>
        /// <param name="item">Node to check.</param>
        /// <returns></returns>
        private static bool HasSubFolders(ExplorerTreeViewItem item)
        {
            if (item.Items.Count == 0)
            {
                return false;
            }

            return item.Items[0] is ExplorerTreeViewItem;
        }

        private static ExplorerTreeViewItem CreateItem(Object tag, string header)
        {
            var item = new ExplorerTreeViewItem
            {
                Tag = tag,
                Header = header
            };

            item.Items.Add("*");

            return item;
        }

        /// <summary>
        /// Populates tree with initial drive nodes. 
        /// </summary>
        public void InitExplorer()
        {

            Items.Clear();
            IDirectoryBrowser root = null;
            try
            {
                switch (this.Root)
                {
                    case ExplorerTreeViewRootEnum.MyComputer:
                        root = Browser.Create(KF_IID.ID_FOLDERID_ComputerFolder);
                        break;
                    case ExplorerTreeViewRootEnum.Documents:
                        root = Browser.Create(KF_IID.ID_FOLDERID_Documents);
                        break;
                    case ExplorerTreeViewRootEnum.Downloads:
                        root = Browser.Create(KF_IID.ID_FOLDERID_Downloads);
                        break;
                    case ExplorerTreeViewRootEnum.Music:
                        root = Browser.Create(KF_IID.ID_FOLDERID_Music);
                        break;
                    case ExplorerTreeViewRootEnum.Videos:
                        root = Browser.Create(KF_IID.ID_FOLDERID_Videos);
                        break;
                    case ExplorerTreeViewRootEnum.Custom:
                        root = Browser.Create(this.CustomPath);
                        break;
                    default:
                        root = Browser.Create(KF_IID.ID_FOLDERID_Desktop);
                        break;
                }
            }
            catch (Exception ex)
            {
                Console.Write(ex.Message);
            }

            ExplorerTreeViewItem folderItem = CreateFolderItem((object)root, root.Name, "");
            folderItem.SourcePath = root.FullName;
            this.Items.Add((object)folderItem);
            this.IterateFolders(root, folderItem.Items, "");
            folderItem.IsExpanded = true;
        }
        public void ExpandedItem(ExplorerTreeViewItem item)
        {
            item.IsExpanded = true;
        }
        private void IterateFolders(IDirectoryBrowser browser, ItemCollection items, string ParentCopyPath)
        {
            try
            {
                List<IDirectoryBrowser> directoryBrowserList = new List<IDirectoryBrowser>();
                foreach (IDirectoryBrowser childItem in Browser.GetChildItems(browser.PathShell))
                {
                    DirectoryInfo directoryInfo = new DirectoryInfo(childItem.FullName);
                    if ((directoryInfo.Attributes & FileAttributes.Hidden) != FileAttributes.Hidden && (directoryInfo.Attributes & FileAttributes.System) != FileAttributes.System)
                        directoryBrowserList.Add(childItem);
                }
                foreach (IDirectoryBrowser directoryBrowser in directoryBrowserList)
                {
                    FileAttributes attributes = File.GetAttributes(directoryBrowser.FullName);
                    if (attributes != FileAttributes.Hidden && attributes != FileAttributes.System)
                    {
                        ExplorerTreeViewItem explorerTreeViewItem = (ExplorerTreeViewItem)null;

                        foreach (string key in this.CopyDic.Keys)
                        {
                            string convertPath = key;
                            if (key.Contains("$(workspace_loc)"))
                                convertPath = key.Replace("$(workspace_loc)", WorkSpacePath);
                            else if (key.Contains("$(sourcecode_root)"))
                                convertPath = key.Replace("$(sourcecode_root)", SourceCodePath);

                            if (convertPath == directoryBrowser.FullName)
                            {
                                explorerTreeViewItem = this.CreateFolderItem((object)directoryBrowser, directoryBrowser.Label, this.CopyDic[key]);
                                break;
                            }
                        }
                        if (explorerTreeViewItem == null)
                            explorerTreeViewItem = this.CreateFolderItem((object)directoryBrowser, directoryBrowser.Label, ParentCopyPath);

                        items.Add((object)explorerTreeViewItem);
                    }
                }
                foreach (string file in Directory.GetFiles(browser.PathShell))
                {
                    FileInfo fileInfo = new FileInfo(file);
                    if ((fileInfo.Attributes & FileAttributes.Hidden) != FileAttributes.Hidden && (fileInfo.Attributes & FileAttributes.System) != FileAttributes.System)
                    {
                        ExplorerTreeViewItem explorerTreeViewItem = (ExplorerTreeViewItem)null;
                        foreach (string key in this.CopyDic.Keys)
                        {
                            string convertPath = key;
                            if (key.Contains("$(workspace_loc)"))
                                convertPath = key.Replace("$(workspace_loc)", WorkSpacePath);
                            else if (key.Contains("$(sourcecode_root)"))
                                convertPath = key.Replace("$(sourcecode_root)", SourceCodePath);

                            if (convertPath == file)
                            {
                                explorerTreeViewItem = CreateFileItem((object)file, Path.GetFileName(file), this.CopyDic[key]);
                                break;
                            }
                        }
                        if (explorerTreeViewItem == null)
                            explorerTreeViewItem = ParentCopyPath != null && !(ParentCopyPath == "") ? CreateFileItem((object)file, Path.GetFileName(file), ParentCopyPath + "\\" + Path.GetFileName(file)) : this.CreateFileItem((object)file, Path.GetFileName(file), ParentCopyPath);

                        items.Add((object)explorerTreeViewItem);
                    }
                }
                if (this.Sort && browser.SpecialPathId != KF_IID.ID_FOLDERID_Desktop)
                    directoryBrowserList.Sort((Comparison<IDirectoryBrowser>)((x, y) => this.SortIDirectoryBrowser(x, y)));

            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
                InvokeExplorerError(new ExplorerTreeViewErrorEventArgs(ex));
            }
        }

        private int SortIDirectoryBrowser(IDirectoryBrowser x, IDirectoryBrowser y)
        {
            CompareStringNatural compareStringNatural = new CompareStringNatural();
            bool xIsDrive = IsDrive(x);
            bool yIsDrive = IsDrive(y);
            if (xIsDrive && yIsDrive)
            {
                return compareStringNatural.Compare(x.PathFileSystem, y.PathFileSystem);
            }
            else if (xIsDrive)
            {
                return 1;
            }
            else if (yIsDrive)
            {
                return -1;
            }
            else
            {
                return compareStringNatural.Compare(x.Label, y.Label);
            }
        }

        private bool IsDrive(IDirectoryBrowser directoryBrowser)
        {
            try
            {
                if ((directoryBrowser.ItemType & DirectoryItemFlags.Drive) == DirectoryItemFlags.Drive) { return true; }
                if (directoryBrowser.PathFileSystem != null && new DirectoryInfo(directoryBrowser.PathFileSystem).Parent == null) { return true; }
            }
            catch (Exception)
            {
                // ignore
            }

            return false;
        }

        /// <summary>
        /// Returns full path of the selected node.
        /// </summary>
        /// <returns></returns>
        private string GetSelectedFolder()
        {
            var item = (ExplorerTreeViewItem)SelectedItem;
            if (item == null) { return null; }

            IDirectoryBrowser directoryBrowser = item.Tag as IDirectoryBrowser;
            if ((directoryBrowser.ItemType & DirectoryItemFlags.FileSystemDirectory) == DirectoryItemFlags.FileSystemDirectory)
            {
                return directoryBrowser.PathFileSystem;
            }
            else
            {
                if (PInvoke.SHParseDisplayName(directoryBrowser.ParseName, IntPtr.Zero, out IntPtr pidl, 0, out uint dummy) == 0)
                {
                    var path = new StringBuilder(260);
                    if (PInvoke.SHGetPathFromIDListW(pidl, path))
                    {
                        return path.ToString();
                    }
                }
            }

            return null;
        }

    }
}