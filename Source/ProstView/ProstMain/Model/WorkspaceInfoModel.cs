using GalaSoft.MvvmLight;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProstMain.Model
{
    public class WorkspaceInfoModel : ObservableObject
    {
        private string _WorkspaceName;
        public string WorkspaceName
        {
            get { return _WorkspaceName; }
            set
            {
                if (_WorkspaceName != value)
                {
                    _WorkspaceName = value;
                    RaisePropertyChanged("WorkspaceName");
                }
            }
        }
        private string _WorkspacePath;
        public string WorkspacePath
        {
            get { return _WorkspacePath; }
            set
            {
                if (_WorkspacePath != value)
                {
                    _WorkspacePath = value;
                    RaisePropertyChanged("WorkspacePath");
                }
            }
        }
        private string _DefaultPath;
        public string DefaultPath
        {
            get { return _DefaultPath; }
            set
            {
                if (_DefaultPath != value)
                {
                    _DefaultPath = value;
                    RaisePropertyChanged("DefaultPath");
                }
            }
        }
        private bool _DefaultPathCheck;
        public bool DefaultPathCheck
        {
            get { return _DefaultPathCheck; }
            set
            {
                if (_DefaultPathCheck != value)
                {
                    _DefaultPathCheck = value;
                    RaisePropertyChanged("DefaultPathCheck");
                }
            }
        }

    }
}
