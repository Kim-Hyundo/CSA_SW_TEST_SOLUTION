using ProstMain.Model;
using ProstMain.ViewModel;
using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Windows.Data;

namespace ProstMain.Util
{
    class DirValidationRule : ValidationRule
    {
        public override ValidationResult Validate(object value, CultureInfo cultureInfo)
        {
            if (value == null)
                return new ValidationResult(false, "Directory Path Not Exists");
            else
                return Directory.Exists(value.ToString()) ? ValidationResult.ValidResult : new ValidationResult(false, "Directory Path Not Exists");

            return ValidationResult.ValidResult;
        }
    }

    class NotEmptyValidationRule : ValidationRule
    {
        public override ValidationResult Validate(object value, CultureInfo cultureInfo)
        {
            if (value == null)
                return new ValidationResult(false, "Value is Empty");
            else
                return string.IsNullOrWhiteSpace((value ?? "").ToString()) ? new ValidationResult(false, "Value is Empty") : ValidationResult.ValidResult;

            //return ValidationResult.ValidResult;
        }
    }

    class PathAvailableRule: ValidationRule
    {
        public override ValidationResult Validate(object value, CultureInfo cultureInfo)
        {
            if (value == null)
                return new ValidationResult(false, "Check the Path");
            else
                return CheckPath(value.ToString()) ? ValidationResult.ValidResult : new ValidationResult(false, "Cannot contain Korean characters or spaces");

            return ValidationResult.ValidResult;
        }

        private bool CheckPath(string s)
        {
            bool returnValue = true;
            char[] charArr = s.ToCharArray();
            foreach(char c in charArr)
            {
                if(char.GetUnicodeCategory(c) == System.Globalization.UnicodeCategory.OtherLetter)
                {
                    returnValue = false;
                }
                else
                {
                    
                }
            }
            if (s.Contains(" "))
                returnValue = false;

            return returnValue;
        }
    }

}
