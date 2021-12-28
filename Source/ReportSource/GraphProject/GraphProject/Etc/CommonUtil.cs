using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.Drawing;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Media;

namespace GraphProject.Etc
{
    public class CommonUtil
    {
        private static string _InternalVersion = "Ver 3.3";
        public static string InternalVersion
        {
            get { return _InternalVersion; }
            set { _InternalVersion = value; }
        }

        private static double _ExOutputWidth;
        public static double ExOutputWidth
        {
            get { return _ExOutputWidth; }
            set { _ExOutputWidth = value; }
        }
        private static double _SenarioWidth;
        public static double SenarioWidth
        {
            get { return _SenarioWidth; }
            set { _SenarioWidth = value; }
        }
        private static double _AcOutputWidth;
        public static double AcOutputWidth
        {
            get { return _AcOutputWidth; }
            set { _AcOutputWidth = value; }
        }
        private static double _InputDataWidth;
        public static double InputDataWidth
        {
            get { return _InputDataWidth; }
            set { _InputDataWidth = value; }
        }
        private static double _TestIDWidth;
        public static double TestIDWidth
        {
            get { return _TestIDWidth; }
            set { _TestIDWidth = value; }
        }
        private static double _ExecutionTimeWidth;
        public static double ExecutionTimeWidth
        {
            get { return _ExecutionTimeWidth; }
            set { _ExecutionTimeWidth = value; }
        }
        private static double _TotalTestResultWidth;
        public static double TotalTestResultWidth
        {
            get { return _TotalTestResultWidth; }
            set { _TotalTestResultWidth = value; }
        }

        private static double _CallCoverageSourceFileWidth;
        public static double CallCoverageSourceFileWidth
        {
            get { return _CallCoverageSourceFileWidth; }
            set { _CallCoverageSourceFileWidth = value; }
        }
        private static double _CallCoverageCallerWidth;
        public static double CallCoverageCallerWidth
        {
            get { return _CallCoverageCallerWidth; }
            set { _CallCoverageCallerWidth = value; }
        }
        private static double _CallCoverageCalledWidth;
        public static double CallCoverageCalledWidth
        {
            get { return _CallCoverageCalledWidth; }
            set { _CallCoverageCalledWidth = value; }
        }
        private static double _CallCoverageTestCaseWidth;
        public static double CallCoverageTestCaseWidth
        {
            get { return _CallCoverageTestCaseWidth; }
            set { _CallCoverageTestCaseWidth = value; }
        }
        private static double _CallCoverageTotalWidth;
        public static double CallCoverageTotalWidth
        {
            get { return _CallCoverageTotalWidth; }
            set { _CallCoverageTotalWidth = value; }
        }
        private static double _FunctionCoverageSourceFileWidth;
        public static double FunctionCoverageSourceFileWidth
        {
            get { return _FunctionCoverageSourceFileWidth; }
            set { _FunctionCoverageSourceFileWidth = value; }
        }
        private static double _FunctionCoverageNameWidth;
        public static double FunctionCoverageNameWidth
        {
            get { return _FunctionCoverageNameWidth; }
            set { _FunctionCoverageNameWidth = value; }
        }
        private static double _FunctionCoverageTotalWidth;
        public static double FunctionCoverageTotalWidth
        {
            get { return _FunctionCoverageTotalWidth; }
            set { _FunctionCoverageTotalWidth = value; }
        }
        private static ObservableCollection<string> _LogMessageList = new ObservableCollection<string>();
        public static ObservableCollection<string> LogMessageList
        {
            get { return _LogMessageList; }
            set { _LogMessageList = value;}
        }

        public static System.Windows.Size MeasureTextSize(string text, System.Windows.Media.FontFamily fontFamily, System.Windows.FontStyle fontStyle, FontWeight fontWeight, FontStretch fontStretch, double fontSize)
        {
            FormattedText ft = new FormattedText(text,CultureInfo.CurrentCulture,FlowDirection.LeftToRight,new Typeface(fontFamily, fontStyle, fontWeight, fontStretch),fontSize,
                                                    System.Windows.Media.Brushes.Black);
            return new System.Windows.Size(ft.Width, ft.Height);
        }

        public static SizeF MeasureString(string s, Font font)
        {
            SizeF result;
            using (var image = new Bitmap(1, 1))
            {
                using (var g = Graphics.FromImage(image))
                {
                    result = g.MeasureString(s, font);
                }
            }

            return result;
        }
        public static int GetExceptionLineNumber(Exception ex)
        {
            var st = new StackTrace(ex, true);
            var frame = st.GetFrame(st.FrameCount - 1);
            var line = frame.GetFileLineNumber();

            return (int)line;
        }
        public static string GetTimingAvrValue(string total, string count)
        {
            try
            {
                double value = Convert.ToDouble(Regex.Match(total, @"\d+.+\d").Value);
                string unit = Regex.Replace(total, @"\d","").Replace(".","");

                int count_var;
                if (!int.TryParse(count, out count_var))
                    count_var = 1;

                return Math.Round((value / (double)count_var), 3) + unit;
            }
            catch(Exception)
            {
                return null;
            }
        }
        public static bool GetIntNumber(string str)
        {
            return Regex.Match(str, @"\d").Success;
        }
    }
}
