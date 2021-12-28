using GalaSoft.MvvmLight;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProstMain.Model
{
    /// <summary>
    /// Runnable Stub Model Class
    /// </summary>
    public class RunnableStubModel : ObservableObject
    {
        public string RunnableSTUBDelayGrid { set; get; }
        public string RunnableSTUBReturnGrid { set; get; }
        public string RunnableSTUBFunctionGrid { set; get; }
    }
}
