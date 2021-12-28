using GalaSoft.MvvmLight;
using LiveCharts;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GraphProject.Models
{
    public class TotalMemoryUsageModel : ObservableObject
    {
        public List<TotalMemoryItem> TotalMemoryList { get; set; }
        public List<TotalMemoryValueItem> TotalMemoryValueList { get; set; }

        public string Header1 { get; set; }
        public string Header2 { get; set; }
        public string Header3 { get; set; }
        public string Header4 { get; set; }
        public string Header5 { get; set; }
        public string Header6 { get; set; }

        public string TotalCode { get; set; }
        public string TotalData { get; set; }
        public string TotalReserved { get; set; }
        public string TotalFree { get; set; }
        public string TotalUsage { get; set; }

        public string StackStartAddress { get; set; }
        public string StackEndAddress { get; set; }
        public string StackUsage { get; set; }

        public SeriesCollection StackSeriesCollection { get; set; }

        public string[] StackLabels { get; set; }
        public Func<double, string> StackFormatter { get; set; }
    }

    public class TotalMemoryItem
    {
        public string MemoryCode { get; set; }
        public string MemoryData { get; set; }
        public string MemoryName { get; set; }
        public string MemorySize { get; set; }
        public string MemoryUsage { get; set; }
        public string MemoryReserved { get; set; }
        public string MemoryUsageRate { get; set; }
    }

    public class TotalMemoryValueItem
    {
        public long MemoryCodeValue { get; set; }
        public long MemoryDataValue { get; set; }
        public long MemorySizeValue { get; set; }
        public long MemoryUsageValue { get; set; }
        public long MemoryReservedValue { get; set; }
    }
}
