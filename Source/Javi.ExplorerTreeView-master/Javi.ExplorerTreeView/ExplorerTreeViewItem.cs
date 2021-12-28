using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Controls;

namespace Javi.ExplorerTreeView
{
    public class ExplorerTreeViewItem : TreeViewItem
    {
        public string CopyPath { get; set; }
        public string SourcePath { get; set; }
    }
}
