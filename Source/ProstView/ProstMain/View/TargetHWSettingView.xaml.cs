using ProstMain.Model;
using ProstMain.ViewModel;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;


namespace ProstMain.View
{
    /// <summary>
    /// TargetSettingView.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class TargetHWSettingView : UserControl
    {
        bool isMarquee_Trace32InstallPath = false;
        public static TargetHWSettingView Instance { get; private set; }

        private TargetHWSettingModel _TargetHWSettingModel;
        public TargetHWSettingModel TargetHWSettingModel
        {
            get { return _TargetHWSettingModel; }
            set
            {
                if (_TargetHWSettingModel != value)
                {
                    _TargetHWSettingModel = value;
                }
            }
        }

        public TargetHWSettingView()
        {
            InitializeComponent();
            Instance = this;
            this.DataContext = ViewModelLocator.TargetHWSettingVM;
            UpdateView();
            TEXTBOX_TimerTick.PreviewTextInput += TEXTBOX_TimerTick_PreviewTextInput;

        }
        public void UpdateView()
        {
            CoreGrid.ColumnDefinitions.Clear();
            CoreGrid.Children.Clear();

                for (int i = 0; i < ViewModelLocator.TargetHWSettingVM.CoreList.Count; i++)
                {
                    ColumnDefinition c1 = new ColumnDefinition();
                    c1.Width = new GridLength(1, GridUnitType.Star);

                    CoreGrid.ColumnDefinitions.Add(c1);
                }
                for (int i = 0; i < ViewModelLocator.TargetHWSettingVM.CoreList.Count; i++)
                {
                    RadioButton radiobutton = new RadioButton();

                //radiobutton.Content = "Core " + i;
                    radiobutton.Content = ViewModelLocator.TargetHWSettingVM.CoreNameList[i];
                    radiobutton.Margin = new Thickness(10, 0, 0, 0);
                    radiobutton.VerticalAlignment = VerticalAlignment.Center;

                    radiobutton.SetValue(Control.ForegroundProperty, App.Current.Resources["StandardTextForeground"]);
                    radiobutton.SetValue(Control.BackgroundProperty, App.Current.Resources["CheckBoxBackGroundColor"]);

                    Binding myBinding = new Binding("CoreList[" + i + "]");

                    radiobutton.SetBinding(RadioButton.IsCheckedProperty, myBinding);

                    Grid.SetColumn(radiobutton, i);
                    CoreGrid.Children.Add(radiobutton);
                }
           /* }
            else if(TargetHWSettingModel.CpuName.Equals("CYT2B75CA"))
            {
                string[] temp = new string[] { "cm0plus", "cm4" };

                for (int i = 0; i < ViewModelLocator.TargetHWSettingVM.CoreList.Count; i++)
                {
                    ColumnDefinition c1 = new ColumnDefinition();
                    c1.Width = new GridLength(1, GridUnitType.Star);

                    CoreGrid.ColumnDefinitions.Add(c1);
                }
                for (int i = 0; i < ViewModelLocator.TargetHWSettingVM.CoreList.Count; i++)
                {
                    RadioButton radiobutton = new RadioButton();

                    radiobutton.Content = temp[i];
                    radiobutton.Margin = new Thickness(10, 0, 0, 0);
                    radiobutton.VerticalAlignment = VerticalAlignment.Center;

                    radiobutton.SetValue(Control.ForegroundProperty, App.Current.Resources["StandardTextForeground"]);
                    radiobutton.SetValue(Control.BackgroundProperty, App.Current.Resources["CheckBoxBackGroundColor"]);

                    Binding myBinding = new Binding("CoreList[" + i + "]");

                    radiobutton.SetBinding(RadioButton.IsCheckedProperty, myBinding);

                    Grid.SetColumn(radiobutton, i);
                    CoreGrid.Children.Add(radiobutton);
                }
            }*/
        }

        private void NumberValidationTextBox(object sender, TextCompositionEventArgs e)
        {
            Regex regex = new Regex("[^0-9]+");
            e.Handled = regex.IsMatch(e.Text);
        }


        private void TEXTBLOCK_Trace32InstallPath_MouseLeave(object sender, MouseEventArgs e)
        {
            TEXTBLOCK_Trace32InstallPath.BeginAnimation(Canvas.LeftProperty, null);
            DoubleAnimation doubleAnimation = new DoubleAnimation();
            doubleAnimation.BeginTime = null;
            TEXTBLOCK_Trace32InstallPath.BeginAnimation(Canvas.LeftProperty, doubleAnimation);
            TEXTBLOCK_Trace32InstallPath.Margin = new Thickness(0, 0, 0, 0);
            isMarquee_Trace32InstallPath = false;
        }

        private void TEXTBLOCK_Trace32InstallPath_MouseMove(object sender, MouseEventArgs e)
        {
            if (!isMarquee_Trace32InstallPath && TEXTBLOCK_Trace32InstallPath.ActualWidth > CANVAS_Trace32InstallPath.ActualWidth)
            {
                DoubleAnimation doubleAnimation = new DoubleAnimation();
                doubleAnimation.From = 0;
                doubleAnimation.To = -TEXTBLOCK_Trace32InstallPath.ActualWidth;
                doubleAnimation.RepeatBehavior = RepeatBehavior.Forever;
                doubleAnimation.Duration = new Duration(TimeSpan.FromSeconds(10));
                TEXTBLOCK_Trace32InstallPath.BeginAnimation(Canvas.LeftProperty, doubleAnimation);
                isMarquee_Trace32InstallPath = true;
            }
        }
        private void TEXTBOX_TimerTick_PreviewTextInput(object sender, TextCompositionEventArgs e)
        {
            e.Handled = !IsNumeric(e.Text);
        }
        private bool IsNumeric(string source)
        {
            Regex regex = new Regex("[^0-9.-]+");
            return !regex.IsMatch(source);
        }
    }
}

