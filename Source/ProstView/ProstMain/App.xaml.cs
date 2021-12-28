using IWshRuntimeLibrary;
using MaterialDesignThemes.Wpf;
using ProstMain.Common;
using ProstMain.Model;
using ProstMain.Util;
using ProstMain.View;
using ProstMain.ViewModel;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;


namespace ProstMain
{
    /// <summary>
    /// App.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class App : Application
    {

        
        protected override void OnStartup(StartupEventArgs e)
        {
            try
            {
                base.OnStartup(e);

                ITheme theme = Application.Current.Resources.GetTheme();
                IBaseTheme baseTheme = new MaterialDesignDarkTheme();
                theme.SetBaseTheme(baseTheme);
                Application.Current.Resources.SetTheme(theme);

                SetupExceptionHandling();

                CheckProgram();

            }catch(Exception ex)
            {
                MessageBox.Show("[Error] " + ex.Message);
            }


        }
        private void SetupExceptionHandling()
        {
            this.Dispatcher.UnhandledException += new System.Windows.Threading.DispatcherUnhandledExceptionEventHandler(Dispatcher_UnhandledException);
            this.Dispatcher.UnhandledExceptionFilter += new System.Windows.Threading.DispatcherUnhandledExceptionFilterEventHandler(Dispatcher_UnhandledExceptionFilter);


        }
        void Dispatcher_UnhandledExceptionFilter(object sender, System.Windows.Threading.DispatcherUnhandledExceptionFilterEventArgs e)
        {
            e.RequestCatch = true;
        }
        void Dispatcher_UnhandledException(object sender, System.Windows.Threading.DispatcherUnhandledExceptionEventArgs e)
        {
            ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, e.Exception.ToString());
            string errorMessage = string.Format("An unhandled exception occurred: {0}", e.Exception.Message);
            MessageBox.Show(errorMessage, "Error", MessageBoxButton.OK, MessageBoxImage.Error);

            e.Handled = true;
        }
        protected override void OnExit(ExitEventArgs e)
        {
            base.OnExit(e);
        }
       
        int m_CheckStep;
        int m_ErrorCheckCount = 0;
        private void CheckProgram()
        {
            m_CheckStep = 0;
            m_ErrorCheckCount = 0;
            this.MainWindow = Common.Common.loadingView;
            Common.Common.loadingView.Show();

            Thread.Sleep(100);

            
            Task.Factory.StartNew(() =>
            {
                while (true)
                {
                    switch (m_CheckStep)
                    {
                        case Common.Common.FILE_CHECK:
                            ViewModelLocator.LoadingVM.LoadingModel.LoadingText = "Verifying installation file...";
                            ViewModelLocator.LoadingVM.LoadingModel.LoadingProgress = 25;
                            //ReadMappingList();
                            if (true)
                            {
                                m_CheckStep++;
                                Thread.Sleep(1000);
                            }
                            break;
                        case Common.Common.VERSION_CHECK:
                            ViewModelLocator.LoadingVM.LoadingModel.LoadingText = "Verifying version...";
                            ViewModelLocator.LoadingVM.LoadingModel.LoadingProgress = 50;

                            if (true)
                            {
                                m_CheckStep++;
                                Thread.Sleep(1000);
                            }
                            break;
                        case Common.Common.LICENSE_CHECK:
                            ViewModelLocator.LoadingVM.LoadingModel.LoadingText = "Verifying license...";
                            ViewModelLocator.LoadingVM.LoadingModel.LoadingProgress = 75;

                            try
                            {
                                
                                if (Util.CommonUtil.LicenseCheck())
                                {
                                    m_CheckStep++;
                                    Thread.Sleep(1000);
                                    break;
                                }
                                else if (m_ErrorCheckCount > 3)
                                {
                                    ErrorCheck();
                                    return;
                                }
                                m_ErrorCheckCount++;
                            }
                            catch (Exception ex)
                            {
                                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, typeof(App).Name + " :: " + ex.Message + " Line :: " + CommonUtil.GetExceptionLineNumber(ex));
                                MessageBox.Show("라이선스 파일이 잘못되었거나, 존재하지 않습니다.");
                                ErrorCheck();

                            }

                            //m_CheckStep++;
                            Thread.Sleep(1000);
                            break;
                        case Common.Common.CHECK_COMPLETE:
                            //CommonUtil.ExitTRACE32Process();
                            ViewModelLocator.LoadingVM.LoadingModel.LoadingText = "Start Prost...";
                            ViewModelLocator.LoadingVM.LoadingModel.LoadingProgress = 100;

                            Thread.Sleep(1000);
                            this.Dispatcher.Invoke(() =>
                            {
                                if (ViewModelLocator.WorkSpaceVM.WorkSpaceModel.IsWorkSpaceDefaultPath)
                                {
                                    Common.Common.loadingView.Close();
                                    ViewModelLocator.WorkSpaceVM.WorkSpaceModel.IsStartUp = true;
                                    ViewModelLocator.WorkSpaceVM.OkClick();
                                    
                                }
                                else
                                {
                                    App.Current.MainWindow = Common.Common.workspaceView;
                                    Common.Common.workspaceView.Show();
                                    Common.Common.loadingView.Close();
                                    ViewModelLocator.WorkSpaceVM.WorkSpaceModel.IsStartUp = true;
                                }
                            });
                            return;
                    }
                }
            });
        }


        private void ErrorCheck()
        {
            string str_message = "";
            switch(m_CheckStep)
            {
                case Common.Common.FILE_CHECK:
                    str_message = "File Check Error";
                    break;
                case Common.Common.VERSION_CHECK:
                    str_message = "Version Check Error";
                    break;
                case Common.Common.LICENSE_CHECK:
                    str_message = "License Check Error";
                    break;
            }
            MessageBoxResult mbResult = MessageBox.Show(str_message);
            if (mbResult == MessageBoxResult.OK)
            {
                System.Diagnostics.Process.GetCurrentProcess().Kill();
            }
        }
    }
}
