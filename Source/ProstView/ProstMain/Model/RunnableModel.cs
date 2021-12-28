using GalaSoft.MvvmLight;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProstMain.Model
{
    /// <summary>
    /// Runnable Model Class
    /// </summary>
    public class RunnableModel : ObservableObject
    {
        public string RunnableNameGrid { set; get; }
        public string RunnableCoreGrid { set; get; }
        public string RunnableCycleGrid { set; get; }
        public string RunnableHeader { get; set; }

    }
}
