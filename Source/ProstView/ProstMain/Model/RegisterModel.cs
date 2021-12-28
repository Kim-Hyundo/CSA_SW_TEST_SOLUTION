using GalaSoft.MvvmLight;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProstMain.Model
{
    /// <summary>
    /// Register Model Class
    /// </summary>
    public class RegisterModel : ObservableObject
    {
        public string RegisterName { set; get; }
        public string RegisterValue { set; get; }

    }
}
