using GalaSoft.MvvmLight;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProstMain.Model
{
    public class ProjectExplorerSubListModel : ObservableObject
    {
        private string _ItemName;
        public string ItemName
        {
            get { return _ItemName; }
            set { _ItemName = value; RaisePropertyChanged("ItemName"); }
        }

        private string _ListType;
        public string ListType
        {
            get { return _ListType; }
            set { _ListType = value; RaisePropertyChanged("ListType"); }
        }

        private string _FolderImage;
        public string FolderImage
        {
            get { return _FolderImage; }
            set { _FolderImage = value; RaisePropertyChanged("FolderImage"); }
        }

        private string _ParentName;
        public string ParentName
        {
            get { return _ParentName; }
            set { _ParentName = value; RaisePropertyChanged("ParentName"); }
        }

        private int _CurrentComboPropertyIndex;
        public int CurrentComboPropertyIndex
        {
            get { return _CurrentComboPropertyIndex; }
            set
            {
                if (_CurrentComboPropertyIndex != value)
                {
                    _CurrentComboPropertyIndex = value;
                    RaisePropertyChanged("CurrentComboPropertyIndex");
                }
            }
        }



        public ProjectExplorerSubListModel()
        {
        }


    }
}
