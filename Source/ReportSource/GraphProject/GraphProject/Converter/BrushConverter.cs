using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Data;
using System.Windows.Media;

namespace GraphProject.Converter
{
    [ValueConversion(typeof(string), typeof(Brush))]
    public class BrushConverter : IValueConverter
    {
        public Brush FalseBrush { get; set; }
        public Brush TrueBrush { get; set; }

        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            if (value.ToString() == "Pass" || value.ToString() == "True")
                return TrueBrush;
            else if (value.ToString() == "Fail" || value.ToString() == "False")
                return FalseBrush;

            return TrueBrush;
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {
            return null;
        }
    }

}
