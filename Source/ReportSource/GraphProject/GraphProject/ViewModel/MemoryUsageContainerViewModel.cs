using GalaSoft.MvvmLight;
using GraphProject.Models;
using GraphProject.Views;
using LiveCharts;
using LiveCharts.Wpf;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;

namespace GraphProject.ViewModel
{
    public class MemoryUsageContainerViewModel : ViewModelBase
    {
        private TotalMemoryUsageModel TotalMemoryData { get; set; }
        private TotalMemoryUsageModel SwMemoryData { get; set; }

        SolidColorBrush Top3 = new SolidColorBrush(Color.FromArgb(0xFF, 0x22, 0x22, 0x22));//##ECB834
        SolidColorBrush Middle3 = new SolidColorBrush(Color.FromArgb(0xFF, 0x22, 0x22, 0x22));//##ECB834
        SolidColorBrush Bottom3 = new SolidColorBrush(Color.FromArgb(0xFF, 0x22, 0x22, 0x22));//##ECB834

        // SolidColorBrush Top3 = new SolidColorBrush(Color.FromArgb(0x4C, 0xEC, 0xB8, 0x34));//##ECB834
        // SolidColorBrush Middle3 = new SolidColorBrush(Color.FromArgb(0x4C, 0xE6, 0xA9, 0x0F));//#E6A90F
        // SolidColorBrush Bottom3 = new SolidColorBrush(Color.FromArgb(0x4C,0xD0, 0x95, 0x00));//#D09500

        SolidColorBrush grayblue = new SolidColorBrush(Color.FromRgb(0x4D, 0xA9, 0xBC));
        SolidColorBrush darkblue = new SolidColorBrush(Color.FromRgb(0x50, 0x7A, 0xBB));
        SolidColorBrush graypupple = new SolidColorBrush(Color.FromRgb(0x52, 0x46, 0xAE));
        SolidColorBrush darkpupple = new SolidColorBrush(Color.FromRgb(0x70, 0x47, 0x98));
        SolidColorBrush pupple = new SolidColorBrush(Color.FromRgb(0xA9, 0x4E, 0xC3));
        SolidColorBrush pink = new SolidColorBrush(Color.FromRgb(0xB6, 0x3E, 0x9A));

        private object _totalContentView;

        public static List<object> test_tmp;

        public object TotalContentView
        {
            get { return this._totalContentView; }

            set
            {
                this._totalContentView = value;
                this.RaisePropertyChanged("TotalContentView");
            }
        }

        private Grid _gridContainer;

        public Grid GridContainer
        {
            get { return this._gridContainer; }

            set
            {
                this._gridContainer = value;
                this.RaisePropertyChanged("GridContainer");
            }
        }

        private MemoryChartModel contentviewAdd(SolidColorBrush scb, IronPython.Runtime.PythonDictionary data, string unit)
        {
            MemoryChartModel memorychartmodel = new MemoryChartModel();

            memorychartmodel.Title = data["Memory"].ToString().ToUpper();
            memorychartmodel.TopBackground = scb;
            memorychartmodel.BottomBackground = new SolidColorBrush(Color.FromArgb(0x2C, 0x00, 0x00, 0x00));
            memorychartmodel.Labels = new[] { "Usage" };
            memorychartmodel.Formatter = (val => val.ToString("P"));

            /*
            memorychartmodel.Reserved = "0x" + ((long)Convert.ToDouble(data["Reserved"].ToString())).ToString("X");
            memorychartmodel.Free = "0x" + ((long)Convert.ToDouble(data["Free"].ToString())).ToString("X");
            memorychartmodel.Total = "0x" + ((long)Convert.ToDouble(data["Total"].ToString())).ToString("X");

            memorychartmodel.Comment = "0x" + ((long)Convert.ToDouble(data["Code"].ToString()) + (long)Convert.ToDouble(data["Data"].ToString())).ToString("X") +" Byte were used.";
            memorychartmodel.CodeUsage = "0x" + ((long)Convert.ToDouble(data["Code"].ToString())).ToString("X");
            memorychartmodel.DataUsage = "0x" + ((long)Convert.ToDouble(data["Data"].ToString())).ToString("X");
            */
            if (unit.Equals("Byte"))
            {
                memorychartmodel.Reserved = ((double)Convert.ToDouble(data["Reserved"].ToString())).ToString("0.###") + " Byte";
                memorychartmodel.Free = ((double)Convert.ToDouble(data["Free"].ToString())).ToString("0.###") + " Byte";
                memorychartmodel.Total = ((double)Convert.ToDouble(data["Total"].ToString())).ToString("0.###") + " Byte";
            }
            else if (unit.Equals("KByte"))
            {
                memorychartmodel.Reserved = ((double)Convert.ToDouble(data["Reserved"].ToString()) / 1024).ToString("0.###") + " KByte";
                memorychartmodel.Free = ((double)Convert.ToDouble(data["Free"].ToString()) / 1024).ToString("0.###") + " KByte";
                memorychartmodel.Total = ((double)Convert.ToDouble(data["Total"].ToString()) / 1024).ToString("0.###") + " KByte";
            }
            else if (unit.Equals("MByte"))
            {
                memorychartmodel.Reserved = ((double)Convert.ToDouble(data["Reserved"].ToString()) / 1024 / 1024).ToString("0.###") + " MByte";
                memorychartmodel.Free = ((double)Convert.ToDouble(data["Free"].ToString()) / 1024 / 1024).ToString("0.###") + " MByte";
                memorychartmodel.Total = ((double)Convert.ToDouble(data["Total"].ToString()) / 1024 / 1024).ToString("0.###") + " MByte";
            }

            memorychartmodel.Comment = ((long)Convert.ToDouble(data["Code"].ToString()) + (long)Convert.ToDouble(data["Data"].ToString())).ToString() + " Byte were used.";
            memorychartmodel.CodeUsage = ((long)Convert.ToDouble(data["Code"].ToString())).ToString();
            memorychartmodel.DataUsage = ((long)Convert.ToDouble(data["Data"].ToString())).ToString();

            double total = Convert.ToDouble(data["Total"].ToString());
            double total_code = Convert.ToDouble(data["Code"].ToString());
            double total_data = Convert.ToDouble(data["Data"].ToString());
            double total_free = 0.0;

            if (total > 0)
            {
                total_code = total_code / total;
                total_data = total_data / total;
                total_free = 1 - total_code - total_data;
            }

            memorychartmodel.SeriesCollection = new SeriesCollection
            {
                new StackedRowSeries
                {
                    Values = new ChartValues<double> {total_code},
                    Title = "Code",
                    DataLabels = true,
                    StackMode = StackMode.Percentage,
                    Stroke = new SolidColorBrush(Color.FromArgb(0x0,0x37,0x75,0x4A)),
                    Fill = new SolidColorBrush(Color.FromArgb(0x8F,0x37,0x75,0x4A))
                },
                new StackedRowSeries
                {
                    Values = new ChartValues<double> {total_data},
                    Title = "Data",
                    DataLabels = true,
                    StackMode = StackMode.Percentage,
                    Stroke = new SolidColorBrush(Color.FromArgb(0x0,0x72,0xA2,0x7A)),
                    Fill = new SolidColorBrush(Color.FromArgb(0x8F,0x72,0xA2,0x7A)),
                },
                new StackedRowSeries
                {
                    Values = new ChartValues<double> {total_free},
                    Title = "Not Used",
                    DataLabels = true,
                    StackMode = StackMode.Percentage,
                    Stroke = new SolidColorBrush(Color.FromArgb(0x0,0x70,0x71,0x42)),
                    Fill = new SolidColorBrush(Color.FromArgb(0x8F,0x70,0x71,0x42))
                },
            };

            return memorychartmodel;
        }

        private TotalMemoryUsageModel SWmemoryAdd(TotalMemoryUsageModel TotalMemoryUsage, IronPython.Runtime.PythonDictionary SW_Memory_Data)
        {
            long ram_code = 0;
            long rom_code = 0;
            long ram_data = 0;
            long rom_data = 0;

            long total_code = 0;
            long total_data = 0;

            List<TotalMemoryItem> SwMemoryList = new List<TotalMemoryItem>();
            List<TotalMemoryValueItem> SwMemoryValueList = new List<TotalMemoryValueItem>();

            foreach (string key in SW_Memory_Data.keys())
            {
                IronPython.Runtime.PythonDictionary tmp = (IronPython.Runtime.PythonDictionary)SW_Memory_Data[key];

                SwMemoryList.Add(new TotalMemoryItem()
                {
                    MemoryName = key,
                    MemoryCode = ((long)Convert.ToDouble(tmp["RamCode"].ToString())).ToString("0.###") + " Byte",
                    MemoryData = ((long)Convert.ToDouble(tmp["RamData"].ToString())).ToString("0.###") + " Byte",
                    MemoryUsage = ((long)Convert.ToDouble(tmp["RomCode"].ToString())).ToString("0.###") + " Byte",
                    MemoryReserved = ((long)Convert.ToDouble(tmp["RomData"].ToString())).ToString("0.###") + " Byte",
                    MemorySize = ((long)Convert.ToDouble(tmp["RamCode"].ToString()) + (long)Convert.ToDouble(tmp["RamData"].ToString())).ToString("0.###") + " Byte",
                    MemoryUsageRate = ((long)Convert.ToDouble(tmp["RomCode"].ToString()) + (long)Convert.ToDouble(tmp["RomData"].ToString())).ToString() + " Byte",
                });
                SwMemoryValueList.Add(new TotalMemoryValueItem()
                {
                    MemoryCodeValue = (long)Convert.ToDouble(tmp["RamCode"].ToString()),
                    MemoryDataValue = (long)Convert.ToDouble(tmp["RamData"].ToString()),
                    MemorySizeValue = (long)Convert.ToDouble(tmp["RamCode"].ToString()),
                    MemoryUsageValue = (long)Convert.ToDouble(tmp["RomCode"].ToString()) + (long)Convert.ToDouble(tmp["RamData"].ToString()),
                    MemoryReservedValue = (long)Convert.ToDouble(tmp["RomData"].ToString())
                });

                if (tmp["RamCode"].ToString() != "")
                {
                    double dd = Convert.ToDouble(tmp["RamCode"].ToString());
                    total_code += (long)dd;
                    ram_code += (long)dd;
                }

                if (tmp["RomCode"].ToString() != "")
                {
                    double dd = Convert.ToDouble(tmp["RomCode"].ToString());
                    total_code += (long)dd;
                    rom_code += (long)dd;
                }

                if (tmp["RamData"].ToString() != "")
                {
                    double dd = Convert.ToDouble(tmp["RamData"].ToString());
                    total_data += (long)dd;
                    ram_data += (long)dd;
                }

                if (tmp["RomData"].ToString() != "")
                {
                    double dd = Convert.ToDouble(tmp["RomData"].ToString());
                    total_data += (long)dd;
                    rom_data += (long)dd;
                }
            }

            SwMemoryList.Add(new TotalMemoryItem()
            {
                MemoryName = "Total",
                MemoryCode = ram_code + " Byte",
                MemoryData = ram_data + " Byte",
                MemoryUsage = rom_code + " Byte",
                MemoryReserved = rom_data + " Byte",
                MemorySize = ram_code + ram_data + " Byte",
                MemoryUsageRate = rom_code + rom_data + " Byte",
            });
            SwMemoryValueList.Add(new TotalMemoryValueItem()
            {
                MemoryCodeValue = ram_code,
                MemoryDataValue = ram_data,
                MemoryUsageValue = rom_code,
                MemoryReservedValue = rom_data,
                MemorySizeValue = ram_code + ram_data,
            });

            TotalMemoryUsageModel tmum = new TotalMemoryUsageModel()
            {

                TotalMemoryList = SwMemoryList,
                TotalMemoryValueList = SwMemoryValueList,
                TotalCode = total_code.ToString() + " Byte",
                TotalData = total_data.ToString() + " Byte",
                TotalReserved = "-",
                TotalFree = "-",
                TotalUsage = (total_code + total_data).ToString() + " Byte",

                StackStartAddress = TotalMemoryUsage.StackStartAddress,
                StackEndAddress = TotalMemoryUsage.StackEndAddress,
                StackUsage = TotalMemoryUsage.StackUsage,

                StackSeriesCollection = TotalMemoryUsage.StackSeriesCollection
            };

            return tmum;
        }

        private TotalMemoryUsageModel TotalmemoryAdd(IronPython.Runtime.List Total_Memory)
        {
            long total_total = 0;
            long total_code = 0;
            long total_data = 0;
            long total_reserved = 0;
            long total_free = 0;
            double total_usage = 0;

            List<TotalMemoryItem> TotalmemoryList = new List<TotalMemoryItem>();
            List<TotalMemoryValueItem> TotalmemoryValueList = new List<TotalMemoryValueItem>();

            foreach (IronPython.Runtime.PythonDictionary tmp in Total_Memory)
            {
                if (tmp["Memory"].ToString() == "Total")
                    continue;

                TotalmemoryList.Add(new TotalMemoryItem()
                {
                    MemoryName = tmp["Memory"].ToString(),
                    MemoryCode = ((long)Convert.ToDouble(tmp["Code"].ToString())).ToString("0.###") + " Byte",
                    MemoryData = ((long)Convert.ToDouble(tmp["Data"].ToString())).ToString("0.###") + " Byte",
                    MemorySize = ((long)Convert.ToDouble(tmp["Total"].ToString())).ToString("0.###") + " Byte",
                    MemoryUsage = ((long)Convert.ToDouble(tmp["Code"].ToString()) + (long)Convert.ToDouble(tmp["Data"].ToString())).ToString("0.###") + " Byte",
                    MemoryReserved = ((long)Convert.ToDouble(tmp["Reserved"].ToString())).ToString("0.###") + " Byte",
                    MemoryUsageRate = (Convert.ToDouble(tmp["Usage"].ToString())).ToString() + "%",
                });

                TotalmemoryValueList.Add(new TotalMemoryValueItem()
                {
                    MemoryCodeValue = (long)Convert.ToDouble(tmp["Code"].ToString()),
                    MemoryDataValue = (long)Convert.ToDouble(tmp["Data"].ToString()),
                    MemorySizeValue = (long)Convert.ToDouble(tmp["Total"].ToString()),
                    MemoryUsageValue = (long)Convert.ToDouble(tmp["Code"].ToString()) + (long)Convert.ToDouble(tmp["Data"].ToString()),
                    MemoryReservedValue = (long)Convert.ToDouble(tmp["Reserved"].ToString())
                });

                if (tmp["Total"].ToString() != "")
                {
                    double dd = Convert.ToDouble(tmp["Total"].ToString());
                    total_total += (long)dd;
                }
                if (tmp["Code"].ToString() != "")
                {
                    double dd = Convert.ToDouble(tmp["Code"].ToString());
                    total_code += (long)dd;
                }
                if (tmp["Data"].ToString() != "")
                {
                    double dd = Convert.ToDouble(tmp["Data"].ToString());
                    total_data += (long)dd;
                }
                if (tmp["Reserved"].ToString() != "")
                {
                    double dd = Convert.ToDouble(tmp["Reserved"].ToString());
                    total_reserved += (long)dd;
                }
                if (tmp["Free"].ToString() != "")
                {
                    double dd = Convert.ToDouble(tmp["Free"].ToString());
                    total_free += (long)dd;
                }
                if (tmp["Usage"].ToString() != "")
                {
                    double dd = Convert.ToDouble(tmp["Usage"].ToString());
                    total_usage += (double)dd;
                }
            }

            TotalmemoryList.Add(new TotalMemoryItem()
            {
                MemoryName = "Total",
                MemoryCode = total_code + " Byte",
                MemoryData = total_data + " Byte",
                MemorySize = total_total + " Byte",
                MemoryUsage = total_code + total_data + " Byte",
                MemoryReserved = total_reserved + " Byte",
                MemoryUsageRate = (total_usage).ToString() + "%",
            });

            TotalmemoryValueList.Add(new TotalMemoryValueItem()
            {
                MemoryCodeValue = total_code,
                MemoryDataValue = total_data,
                MemorySizeValue = total_total,
                MemoryUsageValue = total_code + total_data,
                MemoryReservedValue = total_reserved
            });
            long stack_start_addr = (long)Convert.ToDouble(MainViewModel.Summary_Data["Stack Start Address"].ToString());
            long stack_end_addr = (long)Convert.ToDouble(MainViewModel.Summary_Data["Stack End Address"].ToString());
            long stack_point = (long)Convert.ToDouble(MainViewModel.Summary_Data["Stack Pointer"].ToString());
            long stack_total = 0;
            long usage_tmp = 0;
            double stack_usage = 0.0;
            double stack_rate = 0.0;

            if (stack_start_addr < stack_end_addr)
            {
                stack_total = stack_end_addr - stack_start_addr;
                usage_tmp = stack_end_addr - stack_point;
            }
            else
            {
                stack_total = stack_start_addr - stack_end_addr;
                usage_tmp = stack_start_addr - stack_point;
            }


            if (stack_total != 0)
            {
                stack_rate = ((double)usage_tmp / (double)stack_total);
                //stack_rate = Math.Truncate(stack_rate * 1000000) / 1000000;
                stack_usage = (int)usage_tmp;
            }

            TotalMemoryUsageModel tmum = new TotalMemoryUsageModel()
            {
                TotalMemoryList = TotalmemoryList,
                TotalMemoryValueList = TotalmemoryValueList,
                TotalCode = total_code.ToString() + " Byte",
                TotalData = total_data.ToString() + " Byte",
                TotalReserved = total_reserved.ToString() + " Byte",
                TotalFree = total_free.ToString() + " Byte",
                TotalUsage = (total_code + total_data).ToString() + " Byte",

                StackStartAddress = "0x" + stack_start_addr.ToString("X"),
                StackEndAddress = "0x" + stack_end_addr.ToString("X"),
                StackUsage = stack_usage + " Byte",

                StackSeriesCollection = new SeriesCollection
                {
                    new StackedRowSeries
                    {
                        Values = new ChartValues<double> {stack_rate * 100},
                        Title = "Used",
                        StackMode = StackMode.Percentage,
                        Stroke = new SolidColorBrush(Color.FromArgb(0x0,0x37,0x75,0x4A)),
                        Fill = new SolidColorBrush(Color.FromArgb(0x8F,0x37,0x75,0x4A))
                    },
                    new StackedRowSeries
                    {
                        Values = new ChartValues<double> {100 - stack_rate * 100},
                        Title = "Not Used",
                        StackMode = StackMode.Percentage,
                        Stroke = new SolidColorBrush(Color.FromArgb(0x0,0x70,0x71,0x42)),
                        Fill = new SolidColorBrush(Color.FromArgb(0x8F,0x70,0x71,0x42))
                    },
                }
            };

            return tmum;
        }

        public MemoryUsageContainerViewModel()
        {
            test_tmp = new List<object>();

            IronPython.Runtime.List Total_Memory = (IronPython.Runtime.List)MainViewModel.Summary_Data["Memory Usage"];
            IronPython.Runtime.PythonDictionary SW_Memory_Data = (IronPython.Runtime.PythonDictionary)MainViewModel.Summary_Data["Target SW Data"];

            int cellCount = Total_Memory.Count;
            int numCols = 2;
            int numRows = (cellCount + 1) / numCols;

            GridContainer = new Grid();

            for (int i = 0; i < numCols; ++i)
                this.GridContainer.ColumnDefinitions.Add(new ColumnDefinition());
            for (int i = 0; i < numRows; ++i)
                this.GridContainer.RowDefinitions.Add(new RowDefinition());

            foreach (var g in this.GridContainer.RowDefinitions)
            {
                g.Height = new GridLength(230);
            }

            foreach (var g in GridContainer.ColumnDefinitions)
            {
                g.Width = new GridLength(730);
            }

            int iter = 0;

            foreach (IronPython.Runtime.PythonDictionary tmp in Total_Memory)
            {
                if (tmp["Memory"].ToString().ToUpper() == "TOTAL")
                    continue;

                int idx = GridContainer.Children.Add(new ContentControl());
                ContentControl x = GridContainer.Children[idx] as ContentControl;
                x.Content = new ChartViewModel(contentviewAdd(Top3, tmp, "Byte"),"Byte");
                x.Margin = new Thickness(5, 5, 5, 5);
                x.SetValue(Grid.RowProperty, iter / numCols);
                x.SetValue(Grid.ColumnProperty, iter % numCols);
                test_tmp.Add(x);
                iter++;
            }

            TotalMemoryData = TotalmemoryAdd(Total_Memory);
            SwMemoryData = SWmemoryAdd(TotalMemoryData, SW_Memory_Data);

            this.TotalContentView = new TotalMemoryUsageViewModel(TotalMemoryData, SwMemoryData);
        }
        public void UpdateUnit(string unit)
        {
            test_tmp = new List<object>();

            IronPython.Runtime.List Total_Memory = (IronPython.Runtime.List)MainViewModel.Summary_Data["Memory Usage"];
            IronPython.Runtime.PythonDictionary SW_Memory_Data = (IronPython.Runtime.PythonDictionary)MainViewModel.Summary_Data["Target SW Data"];

            int cellCount = Total_Memory.Count;
            int numCols = 2;
            int numRows = (cellCount + 1) / numCols;

            GridContainer.Children.Clear();
            GridContainer.ColumnDefinitions.Clear();
            GridContainer.RowDefinitions.Clear();

            for (int i = 0; i < numCols; ++i)
                this.GridContainer.ColumnDefinitions.Add(new ColumnDefinition());
            for (int i = 0; i < numRows; ++i)
                this.GridContainer.RowDefinitions.Add(new RowDefinition());

            foreach (var g in this.GridContainer.RowDefinitions)
            {
                g.Height = new GridLength(230);
            }

            foreach (var g in GridContainer.ColumnDefinitions)
            {
                g.Width = new GridLength(730);
            }

            int iter = 0;

            foreach (IronPython.Runtime.PythonDictionary tmp in Total_Memory)
            {
                if (tmp["Memory"].ToString().ToUpper() == "TOTAL")
                    continue;

                int idx = GridContainer.Children.Add(new ContentControl());
                ContentControl x = GridContainer.Children[idx] as ContentControl;
                x.Content = new ChartViewModel(contentviewAdd(Top3, tmp, unit),unit);
                x.Margin = new Thickness(5, 5, 5, 5);
                x.SetValue(Grid.RowProperty, iter / numCols);
                x.SetValue(Grid.ColumnProperty, iter % numCols);
                test_tmp.Add(x);
                iter++;
            }

            /*TotalMemoryData = TotalmemoryAdd(Total_Memory);
            SwMemoryData = SWmemoryAdd(TotalMemoryData, SW_Memory_Data);

            this.TotalContentView = new TotalMemoryUsageViewModel(TotalMemoryData, SwMemoryData);*/

            MemoryUsageContainerView.Instance.UpdateBottomContentView(GridContainer);
        }
    }
}
