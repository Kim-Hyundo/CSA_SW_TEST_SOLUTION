using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using ProstMain.Model;
using ProstMain.Popup;
using ProstMain.Util;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProstMain.ViewModel
{
    public class PopupTestStatusViewModel : ViewModelBase
    {
        public RelayCommand StopTestStatusCommand { get; set; }
        public RelayCommand PauseTestCommand { get; set; }
        public RelayCommand StepTestCommand { get; set; }
        public RelayCommand RestartTestCommand { get; set; }
        public RelayCommand CloseTestStatusViewCommand { get; set; }


        private PopupTestStatusModel _PopupTestStatusModel;
        public PopupTestStatusModel PopupTestStatusModel
        {
            get { return _PopupTestStatusModel; }
            set
            {
                if (_PopupTestStatusModel != value)
                {
                    _PopupTestStatusModel = value;
                    RaisePropertyChanged("PopupTestStatusModel");
                }
            }
        }

        public PopupTestStatusViewModel()
        {
            PopupTestStatusModel = new PopupTestStatusModel();

            StopTestStatusCommand = new RelayCommand(StopTestStatus);
            PauseTestCommand = new RelayCommand(PauseTest);
            RestartTestCommand = new RelayCommand(RestartTest);
            StepTestCommand = new RelayCommand(StepTest);

            CloseTestStatusViewCommand = new RelayCommand(CloseTestStatusView);
        }

        public void StopTestStatus()
        {
            CommonUtil.ExitExcelProcess();
            CommonUtil.ExitPythonProcess();


            if (FunctionWorkHandler.getInstance().CoverageSimulatorControlThread != null)
                FunctionWorkHandler.getInstance().CoverageSimulatorControlThread.Abort();

            FunctionWorkHandler.getInstance().StopTest();
            PopupTestStatusModel.TestStateMode = Common.Common.STOP;

            if (Common.Common.m_PopupTestStatusView != null && Common.Common.m_PopupTestStatusView.IsActive)
                Common.Common.m_PopupTestStatusView.Close();

            FunctionWorkHandler.getInstance().RestartTest();
        }
        private void PauseTest()
        {
            FunctionWorkHandler.getInstance().PauseTest();
            PopupTestStatusModel.TestStateMode = Common.Common.PAUSE;
        }
        private void RestartTest()
        {
            FunctionWorkHandler.getInstance().RestartTest();
            PopupTestStatusModel.TestStateMode = Common.Common.RUNNING;
        }
        private void StepTest()
        {
            FunctionWorkHandler.getInstance().StepTest();
            PopupTestStatusModel.TestStateMode = Common.Common.STEP_RUNNING;
        }

        public void ShowPopupTestStatus()
        {
            PopupTestStatusModel.IsTestStatusPopupOpen = false;

            FunctionWorkHandler.getInstance().Process_TestRun();

            Common.Common.m_PopupTestStatusView = new PopupTestStatusView();

            Common.Common.m_PopupTestStatusView.Width = 550;

            if (ViewModelLocator.MenuBarVM.IsADFileGenerator)
                Common.Common.m_PopupTestStatusView.Height = 350;
            else
                Common.Common.m_PopupTestStatusView.Height = 280;
            Common.Common.m_PopupTestStatusView.Owner = App.Current.MainWindow;
            Common.Common.m_PopupTestStatusView.Show();
        }
        private void CloseTestStatusView()
        {
            PopupTestStatusModel.IsTestStatusPopupOpen = false;
            if (Common.Common.m_PopupTestStatusView != null)
            {
                Common.Common.m_PopupTestStatusView.Close();
                Common.Common.m_PopupTestStatusView = null;
            }
        }
    }
}
