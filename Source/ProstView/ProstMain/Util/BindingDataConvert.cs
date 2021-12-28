using Javi.ExplorerTreeView;
using MaterialDesignThemes.Wpf;
using ProstMain.Model;
using ProstMain.ViewModel;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using WSF.Interfaces;

namespace ProstMain.Util
{
    /// <summary>
    /// PopupBuildStartView에서 SW/HW/Compiler 설정값의 이상유무를 Line의 색상으로 변경하는 Convert
    /// [Argument : int  //  Returnvalue : string (Color Value)]
    /// </summary>
    public class LineColorConvert : IValueConverter
    {

        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            if ((int)value == Common.Common.PASS)
                return "Green";
            else if ((int)value == Common.Common.FAIL)
                return "Red";
            else
                return App.Current.Resources["StandardTextForeground"];
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {

            return DependencyProperty.UnsetValue;
        }
    }
    /// <summary>
    /// Build간 SW/HW/Compiler 설정값의 이상유무를 TabControl 색상으로 변경하는 Convert
    /// [Argument : int  //  Returnvalue : string (Color Value)]
    /// </summary>
    public class HeaderColorConvert : IValueConverter
    {

        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            if ((int)value == Common.Common.PASS)
                return "";
            else if ((int)value == Common.Common.FAIL)
                return "Red";
            else
                return "";
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {

            return DependencyProperty.UnsetValue;
        }
    }
    /// <summary>
    /// Build간 SW/HW/Compiler 설정값의 이상유무를 해당 이미지로 반환하는 Convert
    /// [Argument : int  //  Returnvalue : string (Color Value)]
    /// </summary>
    public class CheckDataConvert : IValueConverter
    {

        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            if ((int)value == Common.Common.PASS)
                return "/ProstMain;component/Resources/ic_enter.png";
            else if ((int)value == Common.Common.FAIL)
                return "/ProstMain;component/Resources/icon_back.png";
            else
                return "";
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {

            return DependencyProperty.UnsetValue;
        }
    }
    /// <summary>
    /// LogType에 따라 색상값을 반환하는 Convert
    /// [Argument : string  //  Returnvalue : string (Color Value)]
    /// </summary>
    public class LogTextColorConvert : IValueConverter
    {

        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            if (ViewModelLocator.MenuBarVM.ProstThema == Common.Common.THEMA_DARK)
            {
                string str_value = (string)value;
                if (str_value.Contains("[INF]"))
                    return "White";
                else if (str_value.Contains("[PRG]"))
                    return "LightBlue";
                else if (str_value.Contains("[PFF]"))
                    return "MediumPurple";
                else if (str_value.Contains("[ERR]"))
                    return "Red";
                else if (str_value.Contains("[CPL]"))
                {
                    if (str_value.Contains("[CPL]ctc E"))
                        return "Red";
                    else if (str_value.Contains("[CPL]ctc W"))
                        return "Orange";
                    else
                        return "LightGreen";
                }
                else if (str_value.Contains("[WARN]"))
                    return "Orange";
            }
            else
            {
                string str_value = (string)value;
                if (str_value.Contains("[INF]"))
                    return "Gray";
                else if (str_value.Contains("[PRG]"))
                    return "Blue";
                else if (str_value.Contains("[PFF]"))
                    return "Purple";
                else if (str_value.Contains("[ERR]"))
                    return "Red";
                else if (str_value.Contains("[CPL]"))
                    return "Green";
                else if (str_value.Contains("[WARN]"))
                    return "Orange";
                else
                    return "Black";
            }
            return "White";
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {

            return DependencyProperty.UnsetValue;
        }
    }
    /// <summary>
    /// TestStep이 0일 때 Ninepatch 이미지 버그로 인해 보이지 않도록 처리하는 Convert
    /// [Argument : double  //  Returnvalue : Visibility]
    /// </summary>
    public class TestStepZeroConver : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            if (value == null)
                return Visibility.Collapsed;

            double convert_value = 0;
            double.TryParse(value.ToString(), out convert_value);

            if (convert_value < 1)
                return Visibility.Collapsed;
            else
                return Visibility.Visible;
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {

            return DependencyProperty.UnsetValue;
        }
    }
    /// <summary>
    /// Build, Test시 작업이 시작될 때 Progressbar가 보이도록 하는 Convert
    /// [Argument : bool  //  Returnvalue : Visibility]
    /// </summary>
    public class ProgressVisibleConvert : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            if (value == null)
                return Visibility.Collapsed;

            if ((bool)value)
                return Visibility.Visible;
            else
                return Visibility.Collapsed;
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {

            return DependencyProperty.UnsetValue;
        }
    }
    /// <summary>
    /// PopupBuildStartView의 진행률을 해당 Progressbar 길이의 맞게 계산 후 반환하는 Convert
    /// [Argument : double  //  Returnvalue : double]
    /// </summary>
    public class BuildProgressConvert : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            if (value == null)
                return 0;

            double convert_value = 0;
            double.TryParse(value.ToString(), out convert_value);

            if (convert_value < 1)
                return 0;
            else
                return (425.0/100.0)* convert_value;
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {

            return DependencyProperty.UnsetValue;
        }
    }
    /// <summary>
    /// Trackbar 진행률을 해당 Progressbar 길이의 맞게 계산 후 반환하는 Convert
    /// [Argument : double  //  Returnvalue : double]
    /// </summary>
    public class BuildProgressTrackbarConvert : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            if (value == null || (double)value == 0)
                return 0;

            return (242.0 / 100.0) * (double)value;
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {

            return DependencyProperty.UnsetValue;
        }
    }
    /// <summary>
    /// Path의 FullName을 FileName으로만 잘라서 반환하는 Convert
    /// [Argument : string  //  Returnvalue : string]
    /// </summary>
    public class PathFullNameConvert : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            if (value == null)
                return "";

            return Path.GetFileName(value.ToString());

        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {

            return DependencyProperty.UnsetValue;
        }
    }
    /// <summary>
    /// ExploreTreeView의 CopyPath의 Value검사 및 괄호를 추가하여 반환하는 Convert
    /// [Argument : ExplorerTreeViewItem  //  Returnvalue : string]
    /// </summary>

    public class ExploreTreeViewCopyPathConvert : IValueConverter
    {

        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            if (value is ExplorerTreeViewItem node)
            {
                if (node.CopyPath == null || node.CopyPath == "")
                    return "";
                else 
                    return "[" + node.CopyPath + "]";
            }
            else
                return "";
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {

            return DependencyProperty.UnsetValue;
        }
    }
    /// <summary>
    /// Include Path에 Display되는 값을 반환
    /// [Argument : IncludePathModel  //  Returnvalue : string]
    /// </summary>
    public class IncludePathDisplayConvert : IValueConverter
    {

        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            IncludePathModel model = (IncludePathModel)value;

            if (model == null)
                return "";

            if (model.RelativePath == "")
                return model.AbsolutePath;
            else
                return model.RelativePath;
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {

            return DependencyProperty.UnsetValue;
        }
    }
    /// <summary>
    /// Test의 현재 상태에 따라 StepTest 버튼을 Enable/Disable
    /// [Argument : int  //  Returnvalue : bool]
    /// </summary>
    public class StepTestEnableConvert : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            if (value == null)
                return false;

            if ((int)value == Common.Common.PAUSE || (int)value == Common.Common.STEP_RUNNING)
                return true;
            else
                return false;
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {

            return DependencyProperty.UnsetValue;
        }
    }

    public class BoolToGridRowHeightConverter : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            return ((bool)value == true) ? new GridLength(1.5, GridUnitType.Star) : new GridLength(0);
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {    // Don't need any convert back
            return null;
        }
    }

    public class HidenmenuVisibleConvert : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            if (value == null)
                return Visibility.Collapsed;

            if((bool)value)
                return Visibility.Visible;
            else
                return Visibility.Collapsed;
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {

            return DependencyProperty.UnsetValue;
        }
    }
    public class TabItemWidthConvert : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            if (value == null)
                return 0;

            return (double)((double)value / 6);

            return 0;
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {

            return DependencyProperty.UnsetValue;
        }
    }
    public class TestStepProgressVisibleConver : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            if (value == null)
                return Visibility.Hidden;

            if ((int)value <= 1)
                return Visibility.Hidden;
            else
                return Visibility.Visible;
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {

            return DependencyProperty.UnsetValue;
        }
    }
    public class NoneVisibleConvert : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            if (value == null)
                return true;

            if (value.ToString() == "None")
                return true;
            else
                return false;
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {

            return DependencyProperty.UnsetValue;
        }
    }

}
