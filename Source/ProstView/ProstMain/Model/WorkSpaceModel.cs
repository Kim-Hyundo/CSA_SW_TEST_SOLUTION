using GalaSoft.MvvmLight;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProstMain.Model
{
    public class WorkSpaceModel : ObservableObject
    {
        /// <summary>
        /// Selected Workspace Item
        /// </summary>
        private WorkspaceInfoModel _SelectWorkspaceItem;
        public WorkspaceInfoModel SelectWorkspaceItem
        {
            get { return _SelectWorkspaceItem; }
            set
            {
                if (_SelectWorkspaceItem != value)
                {
                    _SelectWorkspaceItem = value;
                    RaisePropertyChanged("SelectWorkspaceItem");
                }
            }
        }

        /// <summary>
        /// Workspace Path Value
        /// </summary>
        private string _WorkSpacePath;
        public string WorkSpacePath
        {
            get { return _WorkSpacePath; }
            set
            {
                if (_WorkSpacePath != value)
                {
                    _WorkSpacePath = value;
                    RaisePropertyChanged("WorkSpacePath");
                }
            }
        }
        /// <summary>
        /// Workspace Default Path Checkbox Binding Value
        /// </summary>
        private bool _IsWorkSpaceDefaultPath;
        public bool IsWorkSpaceDefaultPath
        {
            get { return _IsWorkSpaceDefaultPath; }
            set
            {
                if (_IsWorkSpaceDefaultPath != value)
                {
                    _IsWorkSpaceDefaultPath = value;
                    RaisePropertyChanged("IsWorkSpaceDefaultPath");
                }
            }
        }
        /// <summary>
        /// Selected Project Name
        /// </summary>
        private string _CurrentProjectName;
        public string CurrentProjectName
        {
            get { return _CurrentProjectName; }
            set
            {
                if(_CurrentProjectName != value)
                {
                    _CurrentProjectName = value;
                    RaisePropertyChanged("CurrentProjectName");
                }
            }
        }
        /// <summary>
        /// Whether it is the first start or not when showing the Workspace View
        /// </summary>
        private bool _IsStartUp;
        public bool IsStartUp
        {
            get { return _IsStartUp; }
            set
            {
                if (_IsStartUp != value)
                {
                    _IsStartUp = value;
                    RaisePropertyChanged("IsStartUp");
                }
            }
        }

        public WorkSpaceModel()
        {
            
        }
    }
}
