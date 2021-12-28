/*
  In App.xaml:
  <Application.Resources>
      <vm:ViewModelLocator xmlns:vm="clr-namespace:ProstMain"
                           x:Key="Locator" />
  </Application.Resources>
  
  In the View:
  DataContext="{Binding Source={StaticResource Locator}, Path=ViewModelName}"

  You can also use Blend to do all this with the tool's support.
  See http://www.galasoft.ch/mvvm
*/

using CommonServiceLocator;
using GalaSoft.MvvmLight.Ioc;

namespace ProstMain.ViewModel
{
    /// <summary>
    /// This class contains static references to all the view models in the
    /// application and provides an entry point for the bindings.
    /// </summary>
    public class ViewModelLocator
    {
        /// <summary>
        /// Initializes a new instance of the ViewModelLocator class.
        /// </summary>
        public ViewModelLocator()
        {
            ServiceLocator.SetLocatorProvider(() => SimpleIoc.Default);

            ////if (ViewModelBase.IsInDesignModeStatic)
            ////{
            ////    // Create design time view services and models
            ////    SimpleIoc.Default.Register<IDataService, DesignDataService>();
            ////}
            ////else
            ////{
            ////    // Create run time view services and models
            ////    SimpleIoc.Default.Register<IDataService, DataService>();
            ////}

            SimpleIoc.Default.Register<MainViewModel>();
            SimpleIoc.Default.Register<MenuBarViewModel>();
            SimpleIoc.Default.Register<WorkSpaceViewModel>();
            SimpleIoc.Default.Register<ProjectExplorerViewModel>();
            SimpleIoc.Default.Register<LoadingViewModel>();
            SimpleIoc.Default.Register<ProjectSettingViewModel>();
            SimpleIoc.Default.Register<TargetHWSettingViewModel>();
            SimpleIoc.Default.Register<TargetSWSettingViewModel>();
            SimpleIoc.Default.Register<CompilerSettingViewModel>();
            SimpleIoc.Default.Register<CommandViewModel>();
            SimpleIoc.Default.Register<ToolbarViewModel>();
            SimpleIoc.Default.Register<ReportSettingViewModel>();
            SimpleIoc.Default.Register<ETCSettingViewModel>();

            // POPUP
            SimpleIoc.Default.Register<PopupTestStatusViewModel>();
            SimpleIoc.Default.Register<PopupBuildStatusViewModel>();
            SimpleIoc.Default.Register<PopupTestCaseParsingViewModel>();

            // CustomControl
            SimpleIoc.Default.Register<HistoryViewModel>();
        }

        public static MainViewModel MainVM
        {
            get
            {
                return ServiceLocator.Current.GetInstance<MainViewModel>();
            }
        }
        public static MenuBarViewModel MenuBarVM
        {
            get
            {
                return ServiceLocator.Current.GetInstance<MenuBarViewModel>();
            }
        }
        public static WorkSpaceViewModel WorkSpaceVM
        {
            get
            {
                return ServiceLocator.Current.GetInstance<WorkSpaceViewModel>();
            }
        }
        public static ProjectExplorerViewModel ProjectExplorerVM
        {
            get
            {
                return ServiceLocator.Current.GetInstance<ProjectExplorerViewModel>();
            }
        }
        public static LoadingViewModel LoadingVM
        {
            get
            {
                return ServiceLocator.Current.GetInstance<LoadingViewModel>();
            }
        }
        public static ProjectSettingViewModel ProjectSettingVM
        {
            get
            {
                return ServiceLocator.Current.GetInstance<ProjectSettingViewModel>();
            }
        }
        public static TargetHWSettingViewModel TargetHWSettingVM
        {
            get
            {
                return ServiceLocator.Current.GetInstance<TargetHWSettingViewModel>();
            }
        }
        public static TargetSWSettingViewModel TargetSWSettingVM
        {
            get
            {
                return ServiceLocator.Current.GetInstance<TargetSWSettingViewModel>();
            }
        }
        public static CompilerSettingViewModel CompilerSettingVM
        {
            get
            {
                return ServiceLocator.Current.GetInstance<CompilerSettingViewModel>();
            }
        }
        public static ReportSettingViewModel ReportSettingVM
        {
            get
            {
                return ServiceLocator.Current.GetInstance<ReportSettingViewModel>();
            }
        }
        public static CommandViewModel CommandVM
        {
            get
            {
                return ServiceLocator.Current.GetInstance<CommandViewModel>();
            }
        }
        public static HistoryViewModel HistoryVM
        {
            get
            {
                return ServiceLocator.Current.GetInstance<HistoryViewModel>();
            }
        }
        public static ToolbarViewModel ToolbarVM
        {
            get
            {
                return ServiceLocator.Current.GetInstance<ToolbarViewModel>();
            }
        }
        public static PopupTestStatusViewModel PopupTestStatusVM
        {
            get
            {
                return ServiceLocator.Current.GetInstance<PopupTestStatusViewModel>();
            }
        }
        public static PopupBuildStatusViewModel PopupBuildStatusVM
        {
            get
            {
                return ServiceLocator.Current.GetInstance<PopupBuildStatusViewModel>();
            }
        }
        public static PopupTestCaseParsingViewModel PopupTestCaseParsingVM
        {
            get
            {
                return ServiceLocator.Current.GetInstance<PopupTestCaseParsingViewModel>();
            }
        }
        public static ETCSettingViewModel ETCSettingVM
        {
            get
            {
                return ServiceLocator.Current.GetInstance<ETCSettingViewModel>();
            }
        }
        public static void Cleanup()
        {
            // TODO Clear the ViewModels
        }
    }
}