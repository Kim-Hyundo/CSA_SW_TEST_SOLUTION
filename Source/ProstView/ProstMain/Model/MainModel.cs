using GalaSoft.MvvmLight;
using ProstMain.Util;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Messaging;
using System.Windows;
using MaterialDesignThemes.Wpf;
using System.Collections.ObjectModel;
using ProstMain.ViewModel;

namespace ProstMain.Model
{
    public class MainModel : ObservableObject
    {
        /// <summary>
        /// Version Information
        /// </summary>
        private string _VERSION;
        public string VERSION
        {
            get { return _VERSION; }
            set
            {
                if (_VERSION != value)
                {
                    _VERSION = value;
                    RaisePropertyChanged("VERSION");
                }
            }
        }
        /// <summary>
        /// MainView Dialog Show Flag
        /// </summary>
        private bool _isDialogOpen { get; set; }
        public bool isDialogOpen
        {
            get { return _isDialogOpen; }
            set
            {

                if (_isDialogOpen != value)
                {
                    _isDialogOpen = value;
                    RaisePropertyChanged("isDialogOpen");
                }
                return;
            }
        }
        /// <summary>
        /// 표시되는 Dialog Object 
        /// </summary>
        private object _DialogContent { get; set; }
        public object DialogContent
        {
            get { return _DialogContent; }
            set
            {
                if (_DialogContent != value)
                {
                    _DialogContent = value;
                    RaisePropertyChanged("DialogContent");
                }
            }
        }
        /// <summary>
        /// View 최소화 동작시 Trackbar 표시 Flag
        /// </summary>
        private Visibility _isTrackBarVisible;
        public Visibility isTrackBarVisible
        {
            get { return _isTrackBarVisible; }
            set
            {
                if (_isTrackBarVisible != value)
                {
                    _isTrackBarVisible = value;
                    RaisePropertyChanged("isTrackBarVisible");
                }
            }
        }
        /// <summary>
        /// Popup View 표시 Flag
        /// </summary>
        private bool _isPopupOpen;
        public bool isPopupOpen
        {
            get { return _isPopupOpen; }
            set
            {
                if (_isPopupOpen != value)
                {
                    _isPopupOpen = value;
                    RaisePropertyChanged("isPopupOpen");
                }
            }
        }
        /// <summary>
        /// Delete Project 동작에 폴더까지 삭제 여부에 대한 Flag
        /// </summary>
        private bool _isDeleteProjectList { get; set; }
        public bool isDeleteProjectList
        {
            get { return _isDeleteProjectList; }
            set
            {
                if (_isDeleteProjectList != value)
                {
                    _isDeleteProjectList = value;
                    RaisePropertyChanged("isDeleteProjectList");
                }
            }
        }

        /// <summary>
        /// TabView Select Index
        /// </summary>
        private int _TabControlIndex;
        public int TabControlIndex
        {
            get { return _TabControlIndex; }
            set
            {
                if (_TabControlIndex != value)
                {
                    _TabControlIndex = value;
                    RaisePropertyChanged("TabControlIndex");
                }
            }
        }
        /// <summary>
        /// TRACE32 Connection Flag
        /// </summary>
        private bool _IsTrace32Connection;
        public bool IsTrace32Connection
        {
            get { return _IsTrace32Connection; }
            set
            {
                if (_IsTrace32Connection != value)
                {
                    _IsTrace32Connection = value;
                    RaisePropertyChanged("IsTrace32Connection");
                }
            }
        }
        /// <summary>
        /// Track Bar Message 저장 Queue
        /// </summary>
        private SnackbarMessageQueue _TrackBarMessageQueue;
        public SnackbarMessageQueue TrackBarMessageQueue
        {
            get { return _TrackBarMessageQueue; }
            set
            {
                if(_TrackBarMessageQueue != value)
                {
                    _TrackBarMessageQueue = value;
                    RaisePropertyChanged("TrackBarMessageQueue");
                }
            }
        }
        /// <summary>
        /// Project Save 전 상태정보
        /// </summary>
        private int _BeforeSaveMode;
        public int BeforeSaveMode
        {
            get { return _BeforeSaveMode; }
            set
            {
                if (_BeforeSaveMode != value)
                {
                    _BeforeSaveMode = value;
                    RaisePropertyChanged("BeforeSaveMode");
                }
            }
        }
        /// <summary>
        /// Dialog Text Value
        /// </summary>
        private string _PopupDialogText;
        public string PopupDialogText
        {
            get { return _PopupDialogText; }
            set
            {
                if (_PopupDialogText != value)
                {
                    _PopupDialogText = value;
                    RaisePropertyChanged("PopupDialogText");
                }
            }
        }
        /// <summary>
        /// TestStart를 View에서 선택했는지, Trackbar에서 선택했는지 여부
        /// </summary>
        private bool _IsTrackbarRunClick;
        public bool IsTrackbarRunClick
        {
            get { return _IsTrackbarRunClick; }
            set
            {
                if (_IsTrackbarRunClick != value)
                {
                    _IsTrackbarRunClick = value;
                    RaisePropertyChanged("IsTrackbarRunClick");
                }
            }
        }
        /// <summary>
        /// Customer 정보
        /// </summary>
        private int _PROGRAM_MODE;
        public int PROGRAM_MODE
        {
            get { return _PROGRAM_MODE; }
            set
            {
                if (_PROGRAM_MODE != value)
                {
                    _PROGRAM_MODE = value;
                    RaisePropertyChanged("PROGRAM_MODE");
                }
            }
        }
        private bool _IsHidenMenuEnable;
        public bool IsHidenMenuEnable
        {
            get { return _IsHidenMenuEnable; }
            set
            {
                if (_IsHidenMenuEnable != value)
                {
                    _IsHidenMenuEnable = value;
                    RaisePropertyChanged("IsHidenMenuEnable");
                }
            }
        }
        private bool _IsTestSimulationEnable;
        public bool IsTestSimulationEnable
        {
            get { return _IsTestSimulationEnable; }
            set
            {
                if (_IsTestSimulationEnable != value)
                {
                    _IsTestSimulationEnable = value;
                    if (_IsTestSimulationEnable)
                        ViewModelLocator.MenuBarVM.IsADFileGenerator = false;
                    RaisePropertyChanged("IsTestSimulationEnable");
                }
            }
        }
        private bool _IsTestSpecParsingSucces;
        public bool IsTestSpecParsingSucces
        {
            get { return _IsTestSpecParsingSucces; }
            set
            {
                if (_IsTestSpecParsingSucces != value)
                {
                    _IsTestSpecParsingSucces = value;
                    RaisePropertyChanged("IsTestSpecParsingSucces");
                }
            }
        }
        public MainModel()
        {
            TabControlIndex = 0;
            isTrackBarVisible = Visibility.Collapsed;

            TrackBarMessageQueue = new SnackbarMessageQueue();

            VERSION = "3.3";
            PROGRAM_MODE = Common.Common.CUSTOMER_MANDO;
        }
    }
}

