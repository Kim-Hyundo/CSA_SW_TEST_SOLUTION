using GalaSoft.MvvmLight;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProstMain.Model
{
    /// <summary>
    /// Project Model Class
    /// </summary>
    public class ProjectExplorerListModel : ObservableObject
    {

        private string _ItemName;

        public string ItemName
        {
            get { return _ItemName; }
            set { _ItemName = value; RaisePropertyChanged("ItemName"); }
        }

        private string _FolderImage;

        public string FolderImage
        {
            get { return _FolderImage; }
            set { _FolderImage = value; RaisePropertyChanged("FolderImage"); }
        }

        private string _ListType;
        public string ListType
        {
            get { return _ListType; }
            set { _ListType = value; RaisePropertyChanged("ListType"); }
        }

        private ObservableCollection<ProjectExplorerSubListModel> _SubItem = new ObservableCollection<ProjectExplorerSubListModel>();

        public ObservableCollection<ProjectExplorerSubListModel> SubItem
        {
            get { return _SubItem; }
            set { _SubItem = value; RaisePropertyChanged("SubItem"); }

        }

        public ProjectExplorerListModel()
        {

        }

    }
}
