using MaterialDesignThemes.Wpf;
using ProstMain.ViewModel;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace ProstMain.View
{
    /// <summary>
    /// MenuBar.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class MenuBarView : UserControl
    {
        public MenuBarView()
        {
            InitializeComponent();

            var ifLeft = SystemParameters.MenuDropAlignment;
            if (ifLeft)
            {
                // change to false
                var t = typeof(SystemParameters);
                var field = t.GetField("_menuDropAlignment", BindingFlags.NonPublic | BindingFlags.Static);
                field.SetValue(null, false);
                ifLeft = SystemParameters.MenuDropAlignment;
            }
        }

        private void ThemaClick_Dark(object sender, RoutedEventArgs e)
        {
            changeThema(false);
            App.Current.Resources["TrackBarButtonBackground"] = new SolidColorBrush(Color.FromRgb(0x21, 0x21, 0x21)); 
            App.Current.Resources["PrimaryHueMidBrush"] = new SolidColorBrush(Color.FromRgb(0x21, 0x21, 0x21));
            App.Current.Resources["ButtonBackground"] = new SolidColorBrush(Color.FromRgb(0x3f, 0x3f, 0x46));
            App.Current.Resources["MenuBarForeground"] = new SolidColorBrush(Colors.LightGray);
            App.Current.Resources["StandardTextForeground"] = new SolidColorBrush(Colors.White);
            App.Current.Resources["ContextMenuBackground"] = new SolidColorBrush(Color.FromRgb(0x42, 0x42, 0x42));
            App.Current.Resources["TopBarBackground"] = new SolidColorBrush(Color.FromRgb(0x42, 0x42, 0x42));
            App.Current.Resources["ToolBarBackground"] = new SolidColorBrush(Color.FromRgb(0x42,0x42,0x42));
            App.Current.Resources["StandardBackground"] = new SolidColorBrush(Color.FromRgb(0x2d, 0x2d, 0x30));
            App.Current.Resources["GroupBoxHeaderGradient"] = new SolidColorBrush(Colors.Black);
            App.Current.Resources["CheckBoxBackGroundColor"] = new SolidColorBrush(Colors.White);
            App.Current.Resources["ButtonForeground"] = new SolidColorBrush(Colors.White);
            App.Current.Resources["DataGridBackGround"] = new SolidColorBrush(Color.FromRgb(0x31, 0x2f, 0x16));

            App.Current.Resources["TextBoxBackGround"] = new SolidColorBrush(Colors.Black);
            App.Current.Resources["PopupBackground"] = new SolidColorBrush(Color.FromRgb(0x2D, 0x2D, 0x30));

            topMenu.Background = (SolidColorBrush)Application.Current.Resources["PrimaryHueMidBrush"];

            ViewModelLocator.MenuBarVM.ProstThema = Common.Common.THEMA_DARK;

            ViewModelLocator.ToolbarVM.ToolbarModel.NewIconImagePath = "/ProstMain;component/Resources/New_Icon.png";
            ViewModelLocator.ToolbarVM.ToolbarModel.SaveIconImagePath = "/ProstMain;component/Resources/Save_Icon.png";
            ViewModelLocator.ToolbarVM.ToolbarModel.BuildIconImagePath = "/ProstMain;component/Resources/Build_Icon.png";
            ViewModelLocator.ToolbarVM.ToolbarModel.TestIconImagePath = "/ProstMain;component/Resources/Test_Icon.png";
            ViewModelLocator.ToolbarVM.ToolbarModel.ReportIconImagePath = "/ProstMain;component/Resources/Report_Icon.png";


        }

        private void ThemaClick_Ligh(object sender, RoutedEventArgs e)
        {
            changeThema(true);
            App.Current.Resources["TrackBarButtonBackground"] = new SolidColorBrush(Color.FromRgb(0xd4, 0xb2, 0x63));
            App.Current.Resources["PrimaryHueMidBrush"] = new SolidColorBrush(Color.FromRgb(0x2f, 0x63, 0x6f));
            App.Current.Resources["ButtonBackground"] = new SolidColorBrush(Colors.LightGray);
            App.Current.Resources["MenuBarForeground"] = new SolidColorBrush(Colors.LightGray);
            App.Current.Resources["StandardTextForeground"] = new SolidColorBrush(Color.FromRgb(0x3e, 0x3e, 0x42));
            App.Current.Resources["ContextMenuBackground"] = new SolidColorBrush(Colors.LightGray);
            App.Current.Resources["TopBarBackground"] = new SolidColorBrush(Colors.LightGray);
            App.Current.Resources["ToolBarBackground"] = new SolidColorBrush(Color.FromRgb(0xd2, 0x9b, 0x00));
            App.Current.Resources["StandardBackground"] = new SolidColorBrush(Colors.White);
            App.Current.Resources["ButtonForeground"] = new SolidColorBrush(Color.FromRgb(0x3e, 0x3e, 0x42));

            App.Current.Resources["GroupBoxHeaderGradient"] = new SolidColorBrush(Color.FromRgb(0x2F, 0x63, 0x6F));
            App.Current.Resources["TextBoxBackGround"] = new SolidColorBrush(Color.FromRgb(0x2f, 0x63, 0x6f));
            App.Current.Resources["CheckBoxBackGroundColor"] = new SolidColorBrush(Color.FromRgb(0x2F, 0x63, 0x6F));
            App.Current.Resources["DataGridBackGround"] = new SolidColorBrush(Colors.White);
            App.Current.Resources["PopupBackground"] = new SolidColorBrush(Color.FromRgb(0x48, 0x48, 0x48));


            topMenu.Background = (SolidColorBrush)Application.Current.Resources["PrimaryHueMidBrush"];

            ViewModelLocator.MenuBarVM.ProstThema = Common.Common.THEMA_LIGHT;

            ViewModelLocator.ToolbarVM.ToolbarModel.NewIconImagePath = "/ProstMain;component/Resources/New_Icon_Light.png";
            ViewModelLocator.ToolbarVM.ToolbarModel.SaveIconImagePath = "/ProstMain;component/Resources/Save_Icon_Light.png";
            ViewModelLocator.ToolbarVM.ToolbarModel.BuildIconImagePath = "/ProstMain;component/Resources/Build_Icon_Light.png";
            ViewModelLocator.ToolbarVM.ToolbarModel.TestIconImagePath = "/ProstMain;component/Resources/Test_Icon_Light.png";
            ViewModelLocator.ToolbarVM.ToolbarModel.ReportIconImagePath = "/ProstMain;component/Resources/Report_Icon_Light.png";
        }

        private void changeThema(bool isLight)
        {
            if (isLight)
            {
                ITheme theme = Application.Current.Resources.GetTheme();
                IBaseTheme baseTheme = new MaterialDesignLightTheme();
                theme.SetBaseTheme(baseTheme);
                Application.Current.Resources.SetTheme(theme);
            }
            else
            {
                ITheme theme = Application.Current.Resources.GetTheme();
                IBaseTheme baseTheme = new MaterialDesignDarkTheme();
                theme.SetBaseTheme(baseTheme);
                Application.Current.Resources.SetTheme(theme);

            }
        }

    }
}
