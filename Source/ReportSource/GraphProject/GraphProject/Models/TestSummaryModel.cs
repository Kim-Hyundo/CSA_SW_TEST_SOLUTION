using GalaSoft.MvvmLight;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GraphProject.Models
{
    public class TestSummaryModel : ObservableObject
    {
        public string Header { get; set; }

        public List<SummaryItem> Item { get; set; }
    }

    public class SummaryItem
    {
        public string Name { get; set; }
        public object Value { get; set; }
    }
}
