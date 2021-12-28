using GalaSoft.MvvmLight;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProstMain.Model
{
    public class TestSenarioModel : ObservableObject
    {
        public string FolderName { set; get; }
        public string FolderPath { set; get; }
        public string TestReportFilePath { set; get; }
        public string Comment { set; get; }
        public string SWComponent { set; get; }
        public string TestCoverage { set; get; }
        public string Date { set; get; }
        public string MemoryUsage { set; get; }
        public string Coverage { set; get; }
        public string ExecuteTime { set; get; }
    }
}
