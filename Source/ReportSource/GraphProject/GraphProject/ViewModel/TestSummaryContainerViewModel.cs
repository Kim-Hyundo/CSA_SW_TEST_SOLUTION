using CommonServiceLocator;
using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Ioc;
using GraphProject.Etc;
using GraphProject.Models;
using LiveCharts;
using MaterialDesignThemes.Wpf;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Media;
using System.Windows.Media.Media3D;

namespace GraphProject.ViewModel
{
    public class TestSummaryContainerViewModel : ViewModelBase
    {
        private object _summaryContentView;

        public object SummaryContentView
        {
            get { return this._summaryContentView; }

            set
            {
                this._summaryContentView = value;
                this.RaisePropertyChanged("SummaryContentView");
            }
        }

        private List<TestSummaryModel> summaryDataAdd(IronPython.Runtime.PythonDictionary summary_data, IronPython.Runtime.PythonDictionary timing_data, IronPython.Runtime.PythonDictionary func_cov, IronPython.Runtime.PythonDictionary call_cov, IronPython.Runtime.List Cov_List, IronPython.Runtime.List MCDCCov_List)
        {
            List<TestSummaryModel> tsm = new List<TestSummaryModel>();
            TestSummaryModel general_Info = new TestSummaryModel();
            general_Info.Header = "General Infomation";
            general_Info.Item = new List<SummaryItem>();

            TestSummaryModel env_Info = new TestSummaryModel();
            env_Info.Header = "Test Environment";
            env_Info.Item = new List<SummaryItem>();

            TestSummaryModel test_result = new TestSummaryModel();
            test_result.Header = "Test Result";
            test_result.Item = new List<SummaryItem>();

            foreach (string key in summary_data.keys())
            {
                if (key == "Test Project" || key == "Tester name" || key == "Date/Time" || key == "Test Comment")
                {
                    general_Info.Item.Add(new SummaryItem() { Name = key, Value = summary_data[key].ToString() });
                }
                else if (key == "PROST Version" || key == "MCU/CPU" || key == "CPU Clock Setting" || key == "Include Header" ||
                    key == "Compiler Type" || key == "Compiler Version" || key == "AutoGenEnable")
                {

                    env_Info.Item.Add(new SummaryItem() { Name = key, Value = summary_data[key].ToString() });
                }
                else if (key == "Test SW List")
                {
                    IronPython.Runtime.List tmp = (IronPython.Runtime.List)summary_data[key];
                    string sw_name_list = "";
                    foreach (string sw_name in tmp)
                    {
                        sw_name_list += sw_name + "\n";
                    }

                    if (sw_name_list.Length != 0)
                    {
                        sw_name_list = sw_name_list.Substring(0, sw_name_list.Length - 1);
                    }

                    env_Info.Item.Add(new SummaryItem() { Name = key, Value = sw_name_list });
                }
            }


            int total_test_cnt = Convert.ToInt32(timing_data["Test Sample Count"]);
            int pass_cnt = Convert.ToInt32(timing_data["Pass Count"]);
            int fail_cnt = Convert.ToInt32(timing_data["Fail Count"]);
            double rate = Math.Truncate((double)(((double)pass_cnt / (double)total_test_cnt) * 100) * 100) / 100;


            //지현 수정
            //원본
            //IronPython.Runtime.PythonDictionary Target_sw_usage = (IronPython.Runtime.PythonDictionary)MainViewModel.Summary_Data["Target SW Data"];
            IronPython.Runtime.PythonDictionary Target_sw_usage = new IronPython.Runtime.PythonDictionary();

            if (MainViewModel.Summary_Data.keys().Contains("Target SW Data"))
            {
                Target_sw_usage = (IronPython.Runtime.PythonDictionary)MainViewModel.Summary_Data["Target SW Data"];
            }

            //여기까지 수정 data
            foreach (string key in Target_sw_usage.keys())
            {
                IronPython.Runtime.PythonDictionary tmp = (IronPython.Runtime.PythonDictionary)Target_sw_usage[key];
                CalcValueWitdh(key, tmp["RamCode"].ToString(), tmp["RamData"].ToString(), tmp["RomCode"].ToString(), tmp["RomData"].ToString());
            }
            StackPanel MemoryUsagestackPanel = new StackPanel();
            MemoryUsagestackPanel.Orientation = Orientation.Vertical;

            Grid MemoryUsagegrid = new Grid();
            TextBlock tb_source = new TextBlock();
            TextBlock tb_ramcode = new TextBlock();
            TextBlock tb_ramdata = new TextBlock();
            TextBlock tb_romcode = new TextBlock();
            TextBlock tb_romdata = new TextBlock();

            ColumnDefinition MemoryUsageColumnDef_1 = new ColumnDefinition();
            ColumnDefinition MemoryUsageColumnDef_2 = new ColumnDefinition();
            ColumnDefinition MemoryUsageColumnDef_3 = new ColumnDefinition();
            ColumnDefinition MemoryUsageColumnDef_4 = new ColumnDefinition();
            ColumnDefinition MemoryUsageColumnDef_5 = new ColumnDefinition();

            tb_source.Text = "Source";
            tb_ramcode.Text = "RamCode";
            tb_ramdata.Text = "RamData";
            tb_romcode.Text = "RomCode";
            tb_romdata.Text = "RomData";

            MemoryUsageColumnDef_1.Width = new GridLength(sourcodeTextWidth + 10, GridUnitType.Pixel);
            MemoryUsageColumnDef_2.Width = new GridLength(ramcodeTextWidth + 50, GridUnitType.Pixel);
            MemoryUsageColumnDef_3.Width = new GridLength(ramdataTextWidth + 50, GridUnitType.Pixel);
            MemoryUsageColumnDef_4.Width = new GridLength(romcodeTextWidth + 50, GridUnitType.Pixel);
            MemoryUsageColumnDef_5.Width = new GridLength(romdataTextWidth + 50, GridUnitType.Pixel);

            MemoryUsagegrid.ColumnDefinitions.Add(MemoryUsageColumnDef_1);
            MemoryUsagegrid.ColumnDefinitions.Add(MemoryUsageColumnDef_2);
            MemoryUsagegrid.ColumnDefinitions.Add(MemoryUsageColumnDef_3);
            MemoryUsagegrid.ColumnDefinitions.Add(MemoryUsageColumnDef_4);
            MemoryUsagegrid.ColumnDefinitions.Add(MemoryUsageColumnDef_5);

            Grid.SetColumn(tb_source, 0);
            MemoryUsagegrid.Children.Add(tb_source);
            Grid.SetColumn(tb_ramcode, 1);
            MemoryUsagegrid.Children.Add(tb_ramcode);
            Grid.SetColumn(tb_ramdata, 2);
            MemoryUsagegrid.Children.Add(tb_ramdata);
            Grid.SetColumn(tb_romcode, 3);
            MemoryUsagegrid.Children.Add(tb_romcode);
            Grid.SetColumn(tb_romdata, 4);
            MemoryUsagegrid.Children.Add(tb_romdata);
            MemoryUsagestackPanel.Children.Add(MemoryUsagegrid);

            foreach (string key in Target_sw_usage.Keys)
            {
                IronPython.Runtime.PythonDictionary tmp = (IronPython.Runtime.PythonDictionary)Target_sw_usage[key];
                Grid MemoryUsagegrid_value = new Grid();

                TextBlock tb_source_value = new TextBlock();
                TextBlock tb_ramcode_value = new TextBlock();
                TextBlock tb_ramdata_value = new TextBlock();
                TextBlock tb_romcode_value = new TextBlock();
                TextBlock tb_romdata_value = new TextBlock();

                ColumnDefinition MemoryUsageColumnDef_1_value = new ColumnDefinition();
                ColumnDefinition MemoryUsageColumnDef_2_value = new ColumnDefinition();
                ColumnDefinition MemoryUsageColumnDef_3_value = new ColumnDefinition();
                ColumnDefinition MemoryUsageColumnDef_4_value = new ColumnDefinition();
                ColumnDefinition MemoryUsageColumnDef_5_value = new ColumnDefinition();

                tb_source_value.Text = key;
                tb_ramcode_value.Text = tmp["RamCode"].ToString();
                tb_ramdata_value.Text = tmp["RamData"].ToString();
                tb_romcode_value.Text = tmp["RomCode"].ToString();
                tb_romdata_value.Text = tmp["RomData"].ToString();

                MemoryUsageColumnDef_1_value.Width = new GridLength(sourcodeTextWidth + 10, GridUnitType.Pixel);
                MemoryUsageColumnDef_2_value.Width = new GridLength(ramcodeTextWidth + 50, GridUnitType.Pixel);
                MemoryUsageColumnDef_3_value.Width = new GridLength(ramdataTextWidth + 50, GridUnitType.Pixel);
                MemoryUsageColumnDef_4_value.Width = new GridLength(romcodeTextWidth + 50, GridUnitType.Pixel);
                MemoryUsageColumnDef_5_value.Width = new GridLength(romdataTextWidth + 50, GridUnitType.Pixel);

                MemoryUsagegrid_value.ColumnDefinitions.Add(MemoryUsageColumnDef_1_value);
                MemoryUsagegrid_value.ColumnDefinitions.Add(MemoryUsageColumnDef_2_value);
                MemoryUsagegrid_value.ColumnDefinitions.Add(MemoryUsageColumnDef_3_value);
                MemoryUsagegrid_value.ColumnDefinitions.Add(MemoryUsageColumnDef_4_value);
                MemoryUsagegrid_value.ColumnDefinitions.Add(MemoryUsageColumnDef_5_value);

                Grid.SetColumn(tb_source_value, 0);
                MemoryUsagegrid_value.Children.Add(tb_source_value);
                Grid.SetColumn(tb_ramcode_value, 1);
                MemoryUsagegrid_value.Children.Add(tb_ramcode_value);
                Grid.SetColumn(tb_ramdata_value, 2);
                MemoryUsagegrid_value.Children.Add(tb_ramdata_value);
                Grid.SetColumn(tb_romcode_value, 3);
                MemoryUsagegrid_value.Children.Add(tb_romcode_value);
                Grid.SetColumn(tb_romdata_value, 4);
                MemoryUsagegrid_value.Children.Add(tb_romdata_value);
                MemoryUsagestackPanel.Children.Add(MemoryUsagegrid_value);
            }

            StackPanel RuntimstackPanel = new StackPanel();
            RuntimstackPanel.Orientation = Orientation.Vertical;

            if (MainViewModel.timing_flags)
            {
                IronPython.Runtime.PythonDictionary Min_exe_time = (IronPython.Runtime.PythonDictionary)timing_data["Min Execution Time"];
                IronPython.Runtime.PythonDictionary Max_exe_time = (IronPython.Runtime.PythonDictionary)timing_data["Max Execution Time"];

                foreach (string key in Min_exe_time.keys())
                {
                    CalcRuntimeValueWitdh(key, Max_exe_time[key].ToString(), Min_exe_time[key].ToString());
                }

                Grid Runtimgrid1 = new Grid();
                TextBlock tb_funname = new TextBlock();
                TextBlock tb_max = new TextBlock();
                TextBlock tb_min = new TextBlock();

                tb_funname.Text = "Function";
                tb_max.Text = "Max Time";
                tb_min.Text = "Min Time";

                ColumnDefinition Runtim_ColumnDef_1 = new ColumnDefinition();
                ColumnDefinition Runtim_ColumnDef_2 = new ColumnDefinition();
                ColumnDefinition Runtim_ColumnDef_3 = new ColumnDefinition();

                Runtim_ColumnDef_1.Width = new GridLength(funtionTextWidth, GridUnitType.Pixel);
                Runtim_ColumnDef_2.Width = new GridLength(MaxtimeTextWidth + 50, GridUnitType.Pixel);
                Runtim_ColumnDef_3.Width = new GridLength(MintimeTextWidth + 50, GridUnitType.Pixel);

                Runtimgrid1.ColumnDefinitions.Add(Runtim_ColumnDef_1);
                Runtimgrid1.ColumnDefinitions.Add(Runtim_ColumnDef_2);
                Runtimgrid1.ColumnDefinitions.Add(Runtim_ColumnDef_3);

                Grid.SetColumn(tb_funname, 0);
                Runtimgrid1.Children.Add(tb_funname);
                Grid.SetColumn(tb_max, 1);
                Runtimgrid1.Children.Add(tb_max);
                Grid.SetColumn(tb_min, 2);
                Runtimgrid1.Children.Add(tb_min);
                RuntimstackPanel.Children.Add(Runtimgrid1);

                foreach (string key in Min_exe_time.keys())
                {
                    Grid Runtimgrid1_value = new Grid();
                    TextBlock tb_funname_value = new TextBlock();
                    TextBlock tb_max_value = new TextBlock();
                    TextBlock tb_min_value = new TextBlock();

                    tb_funname_value.Text = key;
                    tb_max_value.Text = Max_exe_time[key].ToString() + "us";
                    tb_min_value.Text = Min_exe_time[key].ToString() + "us";

                    ColumnDefinition Runtim_ColumnDef_1_value = new ColumnDefinition();
                    ColumnDefinition Runtim_ColumnDef_2_value = new ColumnDefinition();
                    ColumnDefinition Runtim_ColumnDef_3_value = new ColumnDefinition();

                    Runtim_ColumnDef_1_value.Width = new GridLength(funtionTextWidth + 10, GridUnitType.Pixel);
                    Runtim_ColumnDef_2_value.Width = new GridLength(MaxtimeTextWidth + 50, GridUnitType.Pixel);
                    Runtim_ColumnDef_3_value.Width = new GridLength(MintimeTextWidth + 50, GridUnitType.Pixel);

                    Runtimgrid1_value.ColumnDefinitions.Add(Runtim_ColumnDef_1_value);
                    Runtimgrid1_value.ColumnDefinitions.Add(Runtim_ColumnDef_2_value);
                    Runtimgrid1_value.ColumnDefinitions.Add(Runtim_ColumnDef_3_value);

                    Grid.SetColumn(tb_funname_value, 0);
                    Runtimgrid1_value.Children.Add(tb_funname_value);
                    Grid.SetColumn(tb_max_value, 1);
                    Runtimgrid1_value.Children.Add(tb_max_value);
                    Grid.SetColumn(tb_min_value, 2);
                    Runtimgrid1_value.Children.Add(tb_min_value);
                    RuntimstackPanel.Children.Add(Runtimgrid1_value);
                }

            }

            string func_cov_str = "";
            string call_cov_str = "";
            string total_cov_str = "";
            string mcdc_cov_str = "";

            if (MainViewModel.cov_flags)
            {
                func_cov_str += MainViewModel.curr_scenario + "  ";
                IronPython.Runtime.PythonDictionary func_cov_result = (IronPython.Runtime.PythonDictionary)func_cov["Result"];

                string func_tmp = func_cov_result["FuncCovRate"].ToString();
                func_tmp = func_tmp.Substring(0, func_tmp.Length - 1);
                double func_cov_rate = Math.Truncate(Convert.ToDouble(func_tmp) * 100) / 100;

                func_cov_str += "Total Count : " + func_cov_result["AllFuncCnt"].ToString() + "    " + "Executed : " + func_cov_result["FuncCovTrueCnt"].ToString() + "    " + "Not Executed : " + func_cov_result["FuncCovFalseCnt"].ToString() + "    "
                    + "Total Rate : " + func_cov_rate.ToString() + "%%\n";

                call_cov_str += MainViewModel.curr_scenario + "  ";
                if (call_cov != null)
                {
                    IronPython.Runtime.PythonDictionary call_cov_result = (IronPython.Runtime.PythonDictionary)call_cov["Result"];


                    string call_tmp = call_cov_result["CallCovRate"].ToString();
                    call_tmp = call_tmp.Substring(0, call_tmp.Length - 1);
                    double call_tmp_rate = Math.Truncate(Convert.ToDouble(call_tmp) * 100) / 100;

                    call_cov_str += "Total Count : " + call_cov_result["CallCovTotalCnt"].ToString() + "    " + "Executed : " + call_cov_result["CallCovTrueCnt"].ToString() + "    " + "Not Executed : " + call_cov_result["CallCovFalseCnt"].ToString() + "    "
                        + "Total Rate : " + call_tmp_rate.ToString() + "%\n";
                }

                int total_cnt = Cov_List.Count;
                double total_cov = 0.0;
                double percentage = 0.0;

                string[] funcnames = new string[total_cnt];
                int idx = 0;

                foreach (IronPython.Runtime.PythonDictionary tmp in Cov_List)
                {
                    string funcname_tmp = tmp["tree"].ToString();
                    string executed_tmp = tmp["statement"].ToString();

                    if (funcname_tmp == "")
                        continue;

                    if (executed_tmp == "" || executed_tmp == "-")
                        continue;

                    funcnames[idx++] = funcname_tmp.Trim();

                    if (executed_tmp.Contains("%"))
                        executed_tmp = executed_tmp.Substring(0, executed_tmp.Length - 1);

                        double executed_double = Convert.ToDouble(executed_tmp);
                        total_cov += executed_double;
                }
                percentage = Math.Truncate(total_cov / total_cnt * 100) / 100;

                total_cov_str = "Total : " + total_cnt + "    "
                    + "Total Rate : " + percentage.ToString() + "%\n";

                if (File.Exists(MainViewModel.curr_Workspace + "\\" + MainViewModel.curr_Project + "\\Gen\\" + MainViewModel.curr_Folder + "\\" + MainViewModel.curr_testcase + "\\" + @"Debug\dic\mcdc_cov\cov\cov_merge.txt"))
                {
                    int total_mcdc_cnt = MCDCCov_List.Count;
                    double total_mcdc_cov = 0.0;
                    double percentage_mcdc = 0.0;

                    string[] funcnames_mcdc = new string[total_mcdc_cnt];
                    ChartValues<double> executed_list = new ChartValues<double>();

                    int idx_mcdc = 0;

                    foreach (IronPython.Runtime.PythonDictionary tmp in MCDCCov_List)
                    {
                        string funcname_tmp = tmp["tree"].ToString();
                        string executed_tmp = tmp["mcdc"].ToString();

                        if (funcname_tmp == "")
                            continue;

                        if (executed_tmp == "" || executed_tmp == "-")
                            continue;

                        funcnames_mcdc[idx_mcdc++] = funcname_tmp.Trim();

                        if (executed_tmp.Contains("%"))
                            executed_tmp = executed_tmp.Substring(0, executed_tmp.Length - 1);

                        double executed_double = Convert.ToDouble(executed_tmp);
                        total_mcdc_cov += executed_double;
                        executed_list.Add(executed_double);
                    }

                    percentage_mcdc = Math.Truncate(total_mcdc_cov / total_mcdc_cnt * 100) / 100;

                    mcdc_cov_str = "Total : " + total_mcdc_cnt + "    "    + "Total Rate : " + percentage_mcdc.ToString() + "%\n";
                }
            }

            test_result.Item = new List<SummaryItem>()
            {
                new SummaryItem()
                {
                    Name = "Test Statstic",
                    Value = "Total Case : " + total_test_cnt.ToString() + " EA\n" + "Pass : " + pass_cnt.ToString() + " EA\n"
                    + "Fail : " + fail_cnt.ToString() + " EA\n" + "Pass Rate : " + rate.ToString() + " %"
                },
                new SummaryItem()
                {
                    Name = "Target SW Data Usage",
                    Value = MemoryUsagestackPanel
                },
                new SummaryItem()
                {
                    Name = "Runtime Measurement",
                    Value = RuntimstackPanel
                },
                new SummaryItem()
                {
                    Name = "Function Coverage",
                    Value = func_cov_str,
                },
                new SummaryItem()
                {
                    Name = "Call Coverage",
                    Value = call_cov_str,
                },
                new SummaryItem()
                {
                    Name = "Code Coverage",
                    Value = total_cov_str
                },
            };
            if(mcdc_cov_str != "")
            {
                test_result.Item.Add(new SummaryItem() { Name = "MCDC Coverage", Value = mcdc_cov_str });
            }

            tsm.Add(general_Info);
            tsm.Add(env_Info);
            tsm.Add(test_result);

            return tsm;
        }

        private List<TestSummaryModel> contentviewAdd()
        {
            List<TestSummaryModel> tsm = new List<TestSummaryModel>()
            {
                new TestSummaryModel()
                {
                    Header = "General Infomation",
                    Item = new List<SummaryItem>()
                    {
                        new SummaryItem()
                        {
                            Name = "Test Administor",
                            Value = "Nam Mingi"
                        },
                        new SummaryItem()
                        {
                            Name = "Job Position",
                            Value = "Administrative Manager"
                        },
                        new SummaryItem()
                        {
                            Name = "Date",
                            Value = "2020-03-03 3:40 pm"
                        },
                        new SummaryItem()
                        {
                            Name = "Comment",
                            Value = "Head lamp Test Report, It's so hard.\n I wanna go home and will eat sea food for lunch."
                        },
                    }
                },
                new TestSummaryModel()
                {
                    Header = "Test Environment",
                    Item = new List<SummaryItem>()
                    {
                        new SummaryItem()
                        {
                            Name = "Tool Version",
                            Value = "Prost v2.0.1"
                        },
                        new SummaryItem()
                        {
                            Name = "CPU",
                            Value = "Intel CORE i7 8th Gen"
                        },
                        new SummaryItem()
                        {
                            Name = "OS Evironment",
                            Value = "Window Premium OS 64bit"
                        },
                        new SummaryItem()
                        {
                            Name = "Source Version",
                            Value = "v1.0.1"
                        },
                        new SummaryItem()
                        {
                            Name = "Test Specification",
                            Value = "Test Spec-headlamp_1.2.xlsx"
                        },
                        new SummaryItem()
                        {
                            Name = "Test Case File",
                            Value = "Test Case 1.xlsx"
                        },
                    }
                },
                new TestSummaryModel()
                {
                    Header = "Test Result",
                    Item = new List<SummaryItem>()
                    {
                        new SummaryItem()
                        {
                            Name = "Test Statstic",
                            Value = "50% \n65 fail, 65 pass of total 130"
                        },
                        new SummaryItem()
                        {
                            Name = "Runtime Measurement",
                            Value = "min : 1.03us, Avg : 1.22 ms, Max : 5.32ms"
                        },
                        new SummaryItem()
                        {
                            Name = "Code Coverage",
                            Value = "75%"
                        },
                    }
                },
            };

            return tsm;

        }
        [PreferredConstructor]
        public TestSummaryContainerViewModel()
        {
            try
            {
                IronPython.Runtime.PythonDictionary summary_data = MainViewModel.Summary_Test_Data;
                IronPython.Runtime.PythonDictionary timing_data = MainViewModel.Summary_Data;
                IronPython.Runtime.PythonDictionary func_cov = MainViewModel.Func_Cov_Data;
                IronPython.Runtime.PythonDictionary call_cov = MainViewModel.Call_Cov_Data;
                IronPython.Runtime.List mcdc_cov = MainViewModel.MCDC_Cov_Data;
                IronPython.Runtime.List total_cov = MainViewModel.Coverage_Data;


                this.SummaryContentView = new TestSummaryViewModel(summaryDataAdd(summary_data, timing_data, func_cov, call_cov, total_cov, mcdc_cov));
            }
            catch (Exception)
            {
                throw;
            }
        }
        private double sourcodeTextWidth;
        private double ramcodeTextWidth;
        private double ramdataTextWidth;
        private double romcodeTextWidth;
        private double romdataTextWidth;
        private void CalcValueWitdh(string _source, string _ramcode, string _ramdata, string _romcode, string _romdata)
        {
            Font font = new Font("Roboto", 9);

            if (sourcodeTextWidth < CommonUtil.MeasureString(_source, font).Width)
                sourcodeTextWidth = CommonUtil.MeasureString(_source, font).Width;

            if (ramcodeTextWidth < CommonUtil.MeasureString(_ramcode, font).Width)
                ramcodeTextWidth = CommonUtil.MeasureString(_ramcode, font).Width;

            if (ramdataTextWidth < CommonUtil.MeasureString(_ramdata, font).Width)
                ramdataTextWidth = CommonUtil.MeasureString(_ramdata, font).Width;

            if (romcodeTextWidth < CommonUtil.MeasureString(_romcode, font).Width)
                romcodeTextWidth = CommonUtil.MeasureString(_romcode, font).Width;

            if (romdataTextWidth < CommonUtil.MeasureString(_romdata, font).Width)
                romdataTextWidth = CommonUtil.MeasureString(_romdata, font).Width;
        }
        private double funtionTextWidth;
        private double MaxtimeTextWidth;
        private double MintimeTextWidth;
        private void CalcRuntimeValueWitdh(string _function, string _Maxtime, string _Mintime)
        {
            Font font = new Font("Roboto", 9);

            if (funtionTextWidth < CommonUtil.MeasureString(_function, font).Width)
                funtionTextWidth = CommonUtil.MeasureString(_function, font).Width;

            if (MaxtimeTextWidth < CommonUtil.MeasureString(_Maxtime, font).Width)
                MaxtimeTextWidth = CommonUtil.MeasureString(_Maxtime, font).Width;

            if (MintimeTextWidth < CommonUtil.MeasureString(_Mintime, font).Width)
                MintimeTextWidth = CommonUtil.MeasureString(_Mintime, font).Width;
        }
    }
}
