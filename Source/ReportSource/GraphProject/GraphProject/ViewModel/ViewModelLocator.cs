/*
  In App.xaml:
  <Application.Resources>
      <vm:ViewModelLocator xmlns:vm="clr-namespace:GraphProject"
                           x:Key="Locator" />
  </Application.Resources>
  
  In the View:
  DataContext="{Binding Source={StaticResource Locator}, Path=ViewModelName}"

  You can also use Blend to do all this with the tool's support.
  See http://www.galasoft.ch/mvvm
*/

using CommonServiceLocator;
using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Ioc;
using static System.Net.Mime.MediaTypeNames;

namespace GraphProject.ViewModel
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
            SimpleIoc.Default.Register<ChartViewModel>();
            SimpleIoc.Default.Register<MemoryUsageContainerViewModel>();
            SimpleIoc.Default.Register<TestFailListViewModel>();
            SimpleIoc.Default.Register<TestFailListContainerViewModel>();
            SimpleIoc.Default.Register<TestFailGridViewModel>();
            SimpleIoc.Default.Register<TestSummaryViewModel>();
            SimpleIoc.Default.Register<TestSummaryContainerViewModel>();
            SimpleIoc.Default.Register<TotalMemoryUsageViewModel>();
            SimpleIoc.Default.Register<TestCoverageViewModel>();
            SimpleIoc.Default.Register<TestCoverageContainerViewModel>();
            SimpleIoc.Default.Register<TotalTestCoverageViewModel>();
            SimpleIoc.Default.Register<TotalTestCoverageContainerViewModel>();
            SimpleIoc.Default.Register<TotalMCDCCoverageContainerViewModel>();
            SimpleIoc.Default.Register<TotalMCDCCoverageViewModel>();
            SimpleIoc.Default.Register<TotalTestCoverageContainerViewModel>();
            SimpleIoc.Default.Register<TimingChartContainerViewModel>();
            SimpleIoc.Default.Register<TimingChartViewModel>();
        }
        public static void SetAndReg()
        {
            ServiceLocator.SetLocatorProvider(() => SimpleIoc.Default);

            SimpleIoc.Default.Register<MainViewModel>();
            SimpleIoc.Default.Register<MemoryUsageContainerViewModel>();
            SimpleIoc.Default.Register<TestFailGridViewModel>();
            SimpleIoc.Default.Register<TimingChartContainerViewModel>();
            SimpleIoc.Default.Register<TotalTestCoverageContainerViewModel>();
            SimpleIoc.Default.Register<TotalMCDCCoverageContainerViewModel>();
        }
        public static MainViewModel MainViewModel
        {
            get
            {
                return ServiceLocator.Current.GetInstance<MainViewModel>();
            }
        }

        public ChartViewModel ChartViewModel
        {
            get
            {
                return ServiceLocator.Current.GetInstance<ChartViewModel>();
            }
        }

        public MemoryUsageContainerViewModel MemoryUsageContainerViewModel
        {
            get
            {
                return ServiceLocator.Current.GetInstance<MemoryUsageContainerViewModel>();
            }
        }

        public TestFailListViewModel TestFailListViewModel
        {
            get
            {
                return ServiceLocator.Current.GetInstance<TestFailListViewModel>();
            }
        }

        public TestFailListContainerViewModel TestFailListContainerViewModel
        {
            get
            {
                return ServiceLocator.Current.GetInstance<TestFailListContainerViewModel>();
            }
        }

        public TestFailGridViewModel TestFailGridViewModel
        {
            get
            {
                return ServiceLocator.Current.GetInstance<TestFailGridViewModel>();
            }
        }

        public TestSummaryContainerViewModel TestSummaryContainerViewModel
        {
            get
            {
                return ServiceLocator.Current.GetInstance<TestSummaryContainerViewModel>();
            }
        }

        public TotalMemoryUsageViewModel TotalMemoryUsageViewModel
        {
            get
            {
                return ServiceLocator.Current.GetInstance<TotalMemoryUsageViewModel>();
            }
        }

        public TestCoverageViewModel TestCoverageViewModel
        {
            get
            {
                return ServiceLocator.Current.GetInstance<TestCoverageViewModel>();
            }
        }
        public TotalTestCoverageViewModel TotalTestCoverageViewModel
        {
            get
            {
                return ServiceLocator.Current.GetInstance<TotalTestCoverageViewModel>();
            }
        }

        public TotalMCDCCoverageViewModel TotalMCDCCoverageViewModel
        {
            get
            {
                return ServiceLocator.Current.GetInstance<TotalMCDCCoverageViewModel>();
            }
        }
        public TotalMCDCCoverageContainerViewModel TotalMCDCCoverageContainerViewModel
        {
            get
            {
                return ServiceLocator.Current.GetInstance<TotalMCDCCoverageContainerViewModel>();
            }
        }
        public TestCoverageContainerViewModel TestCoverageContainerViewModel
        {
            get
            {
                return ServiceLocator.Current.GetInstance<TestCoverageContainerViewModel>();
            }
        }

        public TimingChartContainerViewModel TimingChartContainerViewModel
        {
            get
            {
                return ServiceLocator.Current.GetInstance<TimingChartContainerViewModel>();
            }
        }

        public TimingChartViewModel TimingChartViewModel
        {
            get
            {
                return ServiceLocator.Current.GetInstance<TimingChartViewModel>();
            }
        }
        public TotalTestCoverageContainerViewModel TotalTestCoverageContainerViewModel
        {
            get
            {
                return ServiceLocator.Current.GetInstance<TotalTestCoverageContainerViewModel>();
            }
        }



        public static void Cleanup()
        {
            // TODO Clear the ViewModels
        }
    }
}