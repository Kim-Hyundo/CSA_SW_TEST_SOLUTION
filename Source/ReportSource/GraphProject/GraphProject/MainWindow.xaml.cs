using CommonServiceLocator;
using GraphProject.ViewModel;
using iTextSharp.text;
using iTextSharp.text.pdf;
using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.IO;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using static iTextSharp.text.Font;
using FontFamily = iTextSharp.text.Font.FontFamily;
using Image = iTextSharp.text.Image;

namespace GraphProject
{
    /// <summary>
    /// MainWindow.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class MainWindow : Window
    {
        private bool Summary_flag = false;
        private bool Memory_flag = false;
        private bool FailList_flag = false;
        private bool Timing_flag = false;
        private bool Coverage_flag = false;

        public MainWindow()
        {
            InitializeComponent();
        }
        bool DEBUG_MODE = true;
        PdfWriter writer;
        private void createPDF(string FileName)
        {
            iTextSharp.text.Document doc = new iTextSharp.text.Document(PageSize.A4);
            try
            {
                string file_name = FileName;

                if (!file_name.Contains(".pdf"))
                    file_name += ".pdf";
                SavePdfBackgroundWorker.ReportProgress(10);
                writer = PdfWriter.GetInstance(doc, new FileStream(file_name, FileMode.Create));
                writer.PageEvent = new PDFBackgroundHelper();

                doc.SetMargins(20f, 20f, 20f, 20f);
                doc.Open();

                // FONT SETTING
                string FontPath = Environment.GetFolderPath(Environment.SpecialFolder.System) + @"\..\Fonts\H2GTRE.ttf";
                FontFactory.Register(FontPath);

                Font TitleFont = new Font(FontFactory.GetFont("HY견고딕", BaseFont.IDENTITY_H));
                TitleFont.Size = 30;
                TitleFont.SetStyle(Font.BOLD | Font.ITALIC);
                TitleFont.Color = BaseColor.BLUE;

                Font SubTitleFont = new Font(FontFactory.GetFont("HY견고딕", BaseFont.IDENTITY_H));
                SubTitleFont.Size = 19;
                SubTitleFont.SetStyle(Font.BOLD);
                SubTitleFont.Color = BaseColor.BLACK;

                // TITLE SETTING
                Paragraph MainTitle = new Paragraph("[PROST REPORT]", TitleFont);
                MainTitle.Alignment = Element.ALIGN_CENTER;
                MainTitle.SpacingAfter = 50;
                doc.Add(MainTitle);

                SavePdfBackgroundWorker.ReportProgress(20);

                Paragraph _1_TItle = new Paragraph("# SUMMARY INFORMATION", SubTitleFont);
                _1_TItle.SpacingAfter = 10;
                doc.Add(_1_TItle);

                doc.Add(CreateSummaryInformationTable());

                SavePdfBackgroundWorker.ReportProgress(30);

                Paragraph _2_TItle = new Paragraph("# TEST SW LIST", SubTitleFont);
                _2_TItle.SpacingAfter = 10;
                doc.Add(_2_TItle);

                doc.Add(CreateSWListTable());

                doc.SetPageSize(PageSize.A4.Rotate());
                doc.SetMargins(10f, 10f, 10f, 10f);
                doc.NewPage();

                SavePdfBackgroundWorker.ReportProgress(40);
                Paragraph _3_TItle = new Paragraph("# TEST RESULT INFORMATION", SubTitleFont);
                _3_TItle.SpacingAfter = 10;
                doc.Add(_3_TItle);

                doc.Add(CreateTestResultTable());

                SavePdfBackgroundWorker.ReportProgress(50);
                Paragraph _4_TItle = new Paragraph("# MEMORY USEAGE INFORMATION (Total Memory)", SubTitleFont);
                _4_TItle.SpacingAfter = 10;
                doc.Add(_4_TItle);

                doc.Add(CreateMemoryTable_TotalMemory());

                Paragraph _5_TItle = new Paragraph("# MEMORY USEAGE INFORMATION (Source File)", SubTitleFont);
                _5_TItle.SpacingAfter = 10;
                doc.Add(_5_TItle);

                doc.Add(CreateMemoryTable_SourceFile());

                Paragraph _6_TItle = new Paragraph("# EXECUTION TIMG INFORMATION", SubTitleFont);
                _6_TItle.SpacingAfter = 10;
                doc.Add(_6_TItle);

                doc.Add(CreateExecutionTimeTable());

                SavePdfBackgroundWorker.ReportProgress(60);

                if (MainViewModel.Coverage_Data != null && MainViewModel.Coverage_Data.Count > 0)
                {
                    Paragraph _7_TItle = new Paragraph("# STATEMENT COVERAGE INFORMATION", SubTitleFont);
                    _7_TItle.SpacingAfter = 10;
                    doc.Add(_7_TItle);

                    doc.Add(CreateStatementCoverageTable());

                }

                if (MainViewModel.Func_Cov_Data != null && MainViewModel.Func_Cov_Data.Count > 0)
                {
                    Paragraph _8_TItle = new Paragraph("# FUNCTION COVERAGE INFORMATION", SubTitleFont);
                    _8_TItle.SpacingAfter = 10;
                    doc.Add(_8_TItle);

                    doc.Add(CreateFunctionCoverageTable());

                }
                SavePdfBackgroundWorker.ReportProgress(80);

                if (MainViewModel.Call_Cov_Data != null && MainViewModel.Call_Cov_Data.Count > 0)
                {
                    Paragraph _9_TItle = new Paragraph("# CALL COVERAGE INFORMATION", SubTitleFont);
                    _9_TItle.SpacingAfter = 10;
                    doc.Add(_9_TItle);

                    doc.Add(CreateCallCoverageTable());
                }

                if (MainViewModel.MCDC_Cov_Data != null && MainViewModel.MCDC_Cov_Data.Count > 0)
                {
                    Paragraph _10_TItle = new Paragraph("# MC/DC COVERAGE INFORMATION", SubTitleFont);
                    _10_TItle.SpacingAfter = 10;
                    doc.Add(_10_TItle);

                    doc.Add(CreateMCDCCoverageTable());
                }


                doc.Close();

            }
            catch (Exception)
            {

            }
            finally
            {
                doc.Close();
                System.Windows.Application.Current.Dispatcher.Invoke(new Action(() =>
                {
                    DialogHost.IsOpen = false;
                }));

                SavePdfBackgroundWorker.ReportProgress(100);
            }
        }
        private PdfPTable CreateSummaryInformationTable()
        {
            PdfPTable SummaryTable = new PdfPTable(2);
            float[] widths = new float[] { 2.5f, 7.5f };

            SummaryTable.SetWidths(widths);
            SummaryTable.WidthPercentage = 100;


            SummaryTable.AddCell(CreateTableCell("Test Project", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            SummaryTable.AddCell(CreateTableCell(MainViewModel.Summary_Test_Data["Test Project"].ToString(), PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, 28f));

            SummaryTable.AddCell(CreateTableCell("Date / Time", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));

            string format = "yyyyMMddHHmm";
            string dateTime = MainViewModel.Summary_Test_Data["Date/Time"].ToString();
            DateTime dt = DateTime.ParseExact(dateTime, format, CultureInfo.InvariantCulture);
            string convert_string = dt.Year + "년 " + String.Format("{0:D2}",dt.Month) + "월 " + String.Format("{0:D2}", dt.Day) + "일 " + String.Format("{0:D2}", dt.Hour) + "시 " + String.Format("{0:D2}", dt.Minute) + "분";

            SummaryTable.AddCell(CreateTableCell(convert_string, PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, 28f));

            SummaryTable.AddCell(CreateTableCell("Test Comment", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            SummaryTable.AddCell(CreateTableCell(MainViewModel.Summary_Test_Data["Test Comment"].ToString(), PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, 28f));

            SummaryTable.AddCell(CreateTableCell("MCU/CPU", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            SummaryTable.AddCell(CreateTableCell(MainViewModel.Summary_Test_Data["MCU/CPU"].ToString(), PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, 28f));

            SummaryTable.AddCell(CreateTableCell("Compiler Type", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            SummaryTable.AddCell(CreateTableCell(MainViewModel.Summary_Test_Data["Compiler Type"].ToString(), PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, 28f));

            SummaryTable.AddCell(CreateTableCell("Compiler Version", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            SummaryTable.AddCell(CreateTableCell(MainViewModel.Summary_Test_Data["Compiler Version"].ToString(), PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, 28f));

            SummaryTable.SpacingAfter = 30;
            SummaryTable.SplitLate = false;

            return SummaryTable;
        }
        private PdfPTable CreateSWListTable()
        {
            PdfPTable SWListTable = new PdfPTable(3);
            float[] SWListTable_widths = new float[] { 4f, 4f, 4f };

            SWListTable.SetWidths(SWListTable_widths);
            SWListTable.WidthPercentage = 100;


            IronPython.Runtime.List tmp = (IronPython.Runtime.List)MainViewModel.Summary_Test_Data["Test_Code_List"];

            foreach (string sw_name in tmp)
                SWListTable.AddCell(CreateTableCell(sw_name, PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.LIGHT_GRAY, BaseColor.BLACK, 28f));

            SWListTable.SplitLate = false;
            SWListTable.SpacingAfter = 30;

            return SWListTable;
        }
        private PdfPTable CreateTestResultTable()
        {
            PdfPTable TestResultTable = new PdfPTable(8);
            float[] TestResultTable_widths = new float[] { 3f, 2f, 4f, 4f, 4f, 1f, 4f, 1f };

            TestResultTable.SetWidths(TestResultTable_widths);
            TestResultTable.WidthPercentage = 100;

            TestResultTable.AddCell(CreateTableCell("Scenario", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            TestResultTable.AddCell(CreateTableCell("TestID", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            TestResultTable.AddCell(CreateTableCell("InputData", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            TestResultTable.AddCell(CreateTableCell("ExpectedOutputData", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            TestResultTable.AddCell(CreateTableCell("ActualOutputData", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            TestResultTable.AddCell(CreateTableCell("Tol", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            TestResultTable.AddCell(CreateTableCell("ExecutionTime", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            TestResultTable.AddCell(CreateTableCell("P/F", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));

            foreach (IronPython.Runtime.PythonDictionary test_result_dic in MainViewModel.Test_Result_Data)
            {
                string TestID = test_result_dic["Test ID"].ToString();
                string Passfail = test_result_dic["PassFail"].ToString();
                string input_data = "";
                string ex_output_data = "";
                string ac_output_data = "";
                string tolerance = "";
                string execution_time = "";

                IronPython.Runtime.PythonDictionary inp = (IronPython.Runtime.PythonDictionary)test_result_dic["Input Data"];
                IronPython.Runtime.List input_keys = (IronPython.Runtime.List)inp.keys();

                IronPython.Runtime.PythonDictionary ex_out = (IronPython.Runtime.PythonDictionary)test_result_dic["Expect Output Data"];
                IronPython.Runtime.List ex_out_keys = (IronPython.Runtime.List)ex_out.keys();

                IronPython.Runtime.PythonDictionary ac_out = (IronPython.Runtime.PythonDictionary)test_result_dic["Actual Output Data"];
                IronPython.Runtime.List ac_out_keys = (IronPython.Runtime.List)ac_out.keys();

                IronPython.Runtime.PythonDictionary toler = null;
                IronPython.Runtime.List tolerance_keys = null;

                if (test_result_dic.ContainsKey("Tolerance"))
                {
                    toler = (IronPython.Runtime.PythonDictionary)test_result_dic["Tolerance"];
                    tolerance_keys = (IronPython.Runtime.List)toler.keys();
                }

                IronPython.Runtime.PythonDictionary exec_time = (IronPython.Runtime.PythonDictionary)test_result_dic["Execution time"];
                IronPython.Runtime.List exec_time_keys = (IronPython.Runtime.List)exec_time.keys();

                foreach (string key in input_keys)
                {
                    if (key.ToLower().Contains("user macro"))
                        input_data += inp[key].ToString() + "\n";
                    else
                    {
                        double numChk = 0;
                        if (Double.TryParse(inp[key].ToString(), out numChk))
                            input_data += key + " = " + String.Format("{0:0.00}", numChk) + "\n";
                        else
                            input_data += key + " = " + inp[key].ToString() + "\n";
                    }
                }

                if (input_data != "")
                    input_data = input_data.Substring(0, input_data.Length - 1);

                foreach (string key in ex_out_keys)
                {
                    if (key.ToLower().Contains("user macro"))
                        ex_output_data += ex_out[key].ToString() + "\n";
                    else
                    {
                        double numChk = 0;
                        if (Double.TryParse(ex_out[key].ToString(), out numChk))
                            ex_output_data += key + " = " + String.Format("{0:0.00}", numChk) + "\n";
                        else
                            ex_output_data += key + " = " + ex_out[key].ToString() + "\n";
                    }
                }

                if (ex_output_data != "")
                    ex_output_data = ex_output_data.Substring(0, ex_output_data.Length - 1);

                foreach (string key in ac_out_keys)
                {
                    if (key.ToLower().Contains("user macro"))
                        ac_output_data += ac_out[key].ToString() + "\n";
                    else
                    {
                        double numChk = 0;
                        if (Double.TryParse(ac_out[key].ToString(), out numChk))
                            ac_output_data += key + " = " + String.Format("{0:0.00}", numChk) + "\n";
                        else
                            ac_output_data += key + " = " + ac_out[key].ToString() + "\n";
                    }
                }

                if (ac_output_data != "")
                    ac_output_data = ac_output_data.Substring(0, ac_output_data.Length - 1);

                if (tolerance_keys != null)
                {
                    foreach (string key in tolerance_keys)
                    {
                        //tolerance += key + " = " + toler[key].ToString() + "\n";
                        tolerance += toler[key].ToString() + "\n";
                    }

                    if (tolerance != "")
                        tolerance = tolerance.Substring(0, tolerance.Length - 1);
                }

                foreach (string key in exec_time_keys)
                {
                    execution_time += key + " = " + exec_time[key].ToString() + "\n";
                }

                if (execution_time != "")
                    execution_time = execution_time.Substring(0, execution_time.Length - 1);


                if (input_data.Contains("DUMMY"))
                    continue;


                string ScenarioName = MainViewModel.curr_scenario;

                TestResultTable.AddCell(CreateTableCell(ScenarioName, PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, Etc.Common.HEIGHT_AUTO));
                TestResultTable.AddCell(CreateTableCell(TestID, PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, Etc.Common.HEIGHT_AUTO));
                TestResultTable.AddCell(CreateTableCell(input_data, PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, Etc.Common.HEIGHT_AUTO));
                TestResultTable.AddCell(CreateTableCell(ex_output_data, PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, Etc.Common.HEIGHT_AUTO));
                TestResultTable.AddCell(CreateTableCell(ac_output_data, PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, Etc.Common.HEIGHT_AUTO));
                TestResultTable.AddCell(CreateTableCell(tolerance, PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, Etc.Common.HEIGHT_AUTO));
                TestResultTable.AddCell(CreateTableCell(execution_time, PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, Etc.Common.HEIGHT_AUTO));
                TestResultTable.AddCell(CreateTableCell(Passfail, PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, Etc.Common.HEIGHT_AUTO));

            }
            TestResultTable.SpacingAfter = 30;
            return TestResultTable;
        }
        private PdfPTable CreateMemoryTable_TotalMemory()
        {
            PdfPTable MemoryUsageTable = new PdfPTable(7);
            float[] MemoryUsageTable_widths = new float[] { 4f, 4f, 4f, 4f, 4f, 4f, 4f };

            MemoryUsageTable.SetWidths(MemoryUsageTable_widths);
            MemoryUsageTable.WidthPercentage = 100;

            MemoryUsageTable.AddCell(CreateTableCell("Test Name", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            MemoryUsageTable.AddCell(CreateTableCell("Code", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            MemoryUsageTable.AddCell(CreateTableCell("Data", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            MemoryUsageTable.AddCell(CreateTableCell("Usage", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            MemoryUsageTable.AddCell(CreateTableCell("Reserved", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            MemoryUsageTable.AddCell(CreateTableCell("Total", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            MemoryUsageTable.AddCell(CreateTableCell("UsageRate", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));


            IronPython.Runtime.List Total_Memory = (IronPython.Runtime.List)MainViewModel.Summary_Data["Memory Usage"];

            foreach (IronPython.Runtime.PythonDictionary tmp in Total_Memory)
            {
                MemoryUsageTable.AddCell(CreateTableCell(tmp["Memory"].ToString(), PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, 20f));
                MemoryUsageTable.AddCell(CreateTableCell(((long)Convert.ToDouble(tmp["Code"].ToString())).ToString("0.###") + " Byte", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, 20f));
                MemoryUsageTable.AddCell(CreateTableCell(((long)Convert.ToDouble(tmp["Data"].ToString())).ToString("0.###") + " Byte", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, 20f));
                MemoryUsageTable.AddCell(CreateTableCell(((long)Convert.ToDouble(tmp["Code"].ToString()) + (long)Convert.ToDouble(tmp["Data"].ToString())).ToString("0.###") + " Byte", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, 20f));
                MemoryUsageTable.AddCell(CreateTableCell(((long)Convert.ToDouble(tmp["Reserved"].ToString())).ToString("0.###") + " Byte", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, 20f));
                MemoryUsageTable.AddCell(CreateTableCell(((long)Convert.ToDouble(tmp["Total"].ToString())).ToString("0.###") + " Byte", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, 20f));
                MemoryUsageTable.AddCell(CreateTableCell((Convert.ToDouble(tmp["Usage"].ToString())).ToString() + "%", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, 20f));
            }
            MemoryUsageTable.SpacingAfter = 30;
            return MemoryUsageTable;
        }

        private PdfPTable CreateMemoryTable_SourceFile()
        {
            PdfPTable MemoryUsageTable = new PdfPTable(7);
            float[] MemoryUsageTable_widths = new float[] { 4f, 4f, 4f, 4f, 4f, 4f, 4f };

            MemoryUsageTable.SetWidths(MemoryUsageTable_widths);
            MemoryUsageTable.WidthPercentage = 100;

            MemoryUsageTable.AddCell(CreateTableCell("Name", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            MemoryUsageTable.AddCell(CreateTableCell("RamCode", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            MemoryUsageTable.AddCell(CreateTableCell("RamData", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            MemoryUsageTable.AddCell(CreateTableCell("RomCode", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            MemoryUsageTable.AddCell(CreateTableCell("RomData", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            MemoryUsageTable.AddCell(CreateTableCell("RamUsage", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            MemoryUsageTable.AddCell(CreateTableCell("RomUsage", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));

            IronPython.Runtime.PythonDictionary SW_Memory_Data = (IronPython.Runtime.PythonDictionary)MainViewModel.Summary_Data["Target SW Data"];

            foreach (string key in SW_Memory_Data.keys())
            {
                IronPython.Runtime.PythonDictionary tmp = (IronPython.Runtime.PythonDictionary)SW_Memory_Data[key];

                MemoryUsageTable.AddCell(CreateTableCell(key, PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, 20f));
                MemoryUsageTable.AddCell(CreateTableCell(((long)Convert.ToDouble(tmp["RamCode"].ToString())).ToString("0.###") + " Byte", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, 20f));
                MemoryUsageTable.AddCell(CreateTableCell(((long)Convert.ToDouble(tmp["RamData"].ToString())).ToString("0.###") + " Byte", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, 20f));
                MemoryUsageTable.AddCell(CreateTableCell(((long)Convert.ToDouble(tmp["RomCode"].ToString())).ToString("0.###") + " Byte", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, 20f));
                MemoryUsageTable.AddCell(CreateTableCell(((long)Convert.ToDouble(tmp["RomData"].ToString())).ToString("0.###") + " Byte", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, 20f));
                MemoryUsageTable.AddCell(CreateTableCell(((long)Convert.ToDouble(tmp["RamCode"].ToString()) + (long)Convert.ToDouble(tmp["RamData"].ToString())).ToString("0.###") + " Byte", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, 20f));
                MemoryUsageTable.AddCell(CreateTableCell(((long)Convert.ToDouble(tmp["RomCode"].ToString()) + (long)Convert.ToDouble(tmp["RomData"].ToString())).ToString() + " Byte", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, 20f));
            }
            MemoryUsageTable.SpacingAfter = 30;
            return MemoryUsageTable;
        }
        private PdfPTable CreateExecutionTimeTable()
        {
            PdfPTable ExecutionTimeTable = new PdfPTable(5);
            float[] ExecutionTimeTable_widths = new float[] { 6f, 2f, 2f, 2f, 1f};

            ExecutionTimeTable.SetWidths(ExecutionTimeTable_widths);
            ExecutionTimeTable.WidthPercentage = 100;

            ExecutionTimeTable.AddCell(CreateTableCell("FunctionName", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            ExecutionTimeTable.AddCell(CreateTableCell("Min Time", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            ExecutionTimeTable.AddCell(CreateTableCell("Max Time", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            ExecutionTimeTable.AddCell(CreateTableCell("Average Time", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            ExecutionTimeTable.AddCell(CreateTableCell("ExCount", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            

            foreach (string functionName in MainViewModel.Merge_Timing_Data.keys())
            {
                IronPython.Runtime.PythonDictionary merged_data = (IronPython.Runtime.PythonDictionary)MainViewModel.Merge_Timing_Data[functionName];

                ExecutionTimeTable.AddCell(CreateTableCell(functionName.Trim(), PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, Etc.Common.HEIGHT_AUTO));
                ExecutionTimeTable.AddCell(CreateTableCell(merged_data["min"].ToString().Trim(), PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, 20f));
                ExecutionTimeTable.AddCell(CreateTableCell(merged_data["max"].ToString().Trim(), PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, 20f));
                ExecutionTimeTable.AddCell(CreateTableCell(merged_data["avr"].ToString().Trim(), PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, 20f));
                ExecutionTimeTable.AddCell(CreateTableCell(merged_data["count"].ToString().Trim(), PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, 20f));
            }

            ExecutionTimeTable.SpacingAfter = 30;
            return ExecutionTimeTable;
        }
        private PdfPTable CreateStatementCoverageTable()
        {
            PdfPTable StatementCoverageTable = new PdfPTable(2);
            float[] StatementCoverageTable_widths = new float[] { 4f, 6f};

            StatementCoverageTable.SetWidths(StatementCoverageTable_widths);
            StatementCoverageTable.WidthPercentage = 100;

            StatementCoverageTable.AddCell(CreateTableCell("FunctionName", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            StatementCoverageTable.AddCell(CreateTableCell("Coverage Rate", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));

            double total_cov = 0.0;
            double percentage = 0.0;

            foreach (IronPython.Runtime.PythonDictionary tmp in MainViewModel.Coverage_Data)
            {
                string funcname_tmp = tmp["tree"].ToString();
                string executed_tmp = tmp["statement"].ToString();

                if (funcname_tmp == "")
                    continue;

                if (executed_tmp == "" || executed_tmp == "-")
                    continue;

                StatementCoverageTable.AddCell(CreateTableCell(funcname_tmp.Trim(), PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, Etc.Common.HEIGHT_AUTO));

                if (executed_tmp.Contains("%"))
                    executed_tmp = executed_tmp.Substring(0, executed_tmp.Length - 1);

                double executed_double = Convert.ToDouble(executed_tmp);

                float Convert_Percent = ((float)((float)((491f / 100f)) * executed_double));
                StatementCoverageTable.AddCell(CreateTableCell(executed_tmp + "%", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, Etc.Common.HEIGHT_AUTO, Convert_Percent));

                total_cov += executed_double;
            }

            percentage = Math.Truncate(total_cov / MainViewModel.Coverage_Data.Count * 100) / 100;

            StatementCoverageTable.AddCell(CreateTableCell("Total", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));

            float Convert_Percent_Total = ((float)((float)((491f / 100f)) * percentage));
            StatementCoverageTable.AddCell(CreateTableCell(percentage.ToString() + "%", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f, Convert_Percent_Total));
            StatementCoverageTable.SpacingAfter = 30;
            return StatementCoverageTable;
        }
        private PdfPTable CreateFunctionCoverageTable()
        {
            PdfPTable FunctionCoverageTable = new PdfPTable(4);
            float[] FunctionCoverageTable_widths = new float[] { 3f, 3f, 2f, 1f};

            FunctionCoverageTable.SetWidths(FunctionCoverageTable_widths);
            FunctionCoverageTable.WidthPercentage = 100;

            FunctionCoverageTable.AddCell(CreateTableCell("Source FIle", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            FunctionCoverageTable.AddCell(CreateTableCell("Name", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            FunctionCoverageTable.AddCell(CreateTableCell("Address", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            FunctionCoverageTable.AddCell(CreateTableCell("Excuted", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));


            IronPython.Runtime.List func_list_tmp = (IronPython.Runtime.List)MainViewModel.Func_Cov_Data["FunctionList"];

            double total_cov = 0.0;
            double executed_cov = 0.0;
            double percentage = 0.0;

            foreach (IronPython.Runtime.PythonDictionary tmp in func_list_tmp)
            {
                FunctionCoverageTable.AddCell(CreateTableCell(tmp["File"].ToString(), PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, Etc.Common.HEIGHT_AUTO));
                FunctionCoverageTable.AddCell(CreateTableCell(tmp["Function"].ToString(), PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, Etc.Common.HEIGHT_AUTO));
                FunctionCoverageTable.AddCell(CreateTableCell(tmp["AddressRange"].ToString(), PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, Etc.Common.HEIGHT_AUTO));
                if(tmp["Coverage"].ToString()=="True")
                    FunctionCoverageTable.AddCell(CreateTableCell(tmp["Coverage"].ToString(), PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.GREEN, Etc.Common.HEIGHT_AUTO));
                else if (tmp["Coverage"].ToString() == "False")
                    FunctionCoverageTable.AddCell(CreateTableCell(tmp["Coverage"].ToString(), PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.RED, Etc.Common.HEIGHT_AUTO));

                total_cov += 1.0;
                if (tmp["Coverage"].ToString() == "True")
                    executed_cov += 1.0;
            }

            percentage = Math.Truncate(executed_cov / total_cov * 100);
            FunctionCoverageTable.AddCell(CreateTableCell("Total", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            PdfPCell cell = CreateTableCell(percentage.ToString() + "%", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f);
            cell.Colspan = 3;
            FunctionCoverageTable.AddCell(cell);

            FunctionCoverageTable.SpacingAfter = 30;
            return FunctionCoverageTable;
        }
        private PdfPTable CreateCallCoverageTable()
        {
            PdfPTable CallCoverageTable = new PdfPTable(5);
            float[] CallCoverageTable_widths = new float[] { 2f, 3f, 3f, 1f, 1f };

            CallCoverageTable.SetWidths(CallCoverageTable_widths);
            CallCoverageTable.WidthPercentage = 100;

            CallCoverageTable.AddCell(CreateTableCell("Source FIle", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            CallCoverageTable.AddCell(CreateTableCell("Caller Function Name", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            CallCoverageTable.AddCell(CreateTableCell("Called Function Name", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            CallCoverageTable.AddCell(CreateTableCell("Address", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            CallCoverageTable.AddCell(CreateTableCell("Excuted", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));

            double total_cov = 0.0;
            double executed_cov = 0.0;
            double percentage = 0.0;

            IronPython.Runtime.List data_tmp = (IronPython.Runtime.List)MainViewModel.Call_Cov_Data["FunctionList"];

            foreach (IronPython.Runtime.PythonDictionary tmp in data_tmp)
            {
                IronPython.Runtime.List tc_tmp = (IronPython.Runtime.List)tmp["TestCase"];

                string tc_list = "";
                foreach (string tc in tc_tmp)
                {
                    tc_list += tc + ", ";
                }

                CallCoverageTable.AddCell(CreateTableCell(tmp["File"].ToString(), PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, Etc.Common.HEIGHT_AUTO));
                CallCoverageTable.AddCell(CreateTableCell(tmp["Function"].ToString(), PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, Etc.Common.HEIGHT_AUTO));
                CallCoverageTable.AddCell(CreateTableCell(tmp["CalledFunction"].ToString(), PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, Etc.Common.HEIGHT_AUTO));
                CallCoverageTable.AddCell(CreateTableCell(tmp["Address"].ToString(), PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, Etc.Common.HEIGHT_AUTO));
                CallCoverageTable.AddCell(CreateTableCell(tmp["Coverage"].ToString(), PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, Etc.Common.HEIGHT_AUTO));

                total_cov += 1.0;
                if (tmp["Coverage"].ToString() == "True")
                    executed_cov += 1.0;
            }

            percentage = Math.Truncate(executed_cov / total_cov * 100);
            CallCoverageTable.AddCell(CreateTableCell("Total", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            PdfPCell cell = CreateTableCell(percentage.ToString() + "%", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f);
            cell.Colspan = 4;
            CallCoverageTable.AddCell(cell);

            CallCoverageTable.SpacingAfter = 30;
            return CallCoverageTable;
        }

        private PdfPTable CreateMCDCCoverageTable()
        {
            PdfPTable MCDCCoverageTable = new PdfPTable(2);
            float[] MCDCCoverageTable_widths = new float[] { 4f, 6f };

            MCDCCoverageTable.SetWidths(MCDCCoverageTable_widths);
            MCDCCoverageTable.WidthPercentage = 100;

            MCDCCoverageTable.AddCell(CreateTableCell("FunctionName", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));
            MCDCCoverageTable.AddCell(CreateTableCell("Coverage Rate", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));

            double total_cov = 0.0;
            double percentage = 0.0;

            foreach (IronPython.Runtime.PythonDictionary tmp in MainViewModel.MCDC_Cov_Data)
            {
                string funcname_tmp = tmp["tree"].ToString();
                string executed_tmp = tmp["mcdc"].ToString();

                if (funcname_tmp == "")
                    continue;

                if (executed_tmp == "" || executed_tmp == "-")
                    continue;

                MCDCCoverageTable.AddCell(CreateTableCell(funcname_tmp.Trim(), PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, Etc.Common.HEIGHT_AUTO));

                if (executed_tmp.Contains("%"))
                    executed_tmp = executed_tmp.Substring(0, executed_tmp.Length - 1);

                double executed_double = Convert.ToDouble(executed_tmp);

                float Convert_Percent = ((float)((float)((491f / 100f)) * executed_double));
                MCDCCoverageTable.AddCell(CreateTableCell(executed_tmp + "%", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_LEFT, BaseColor.LIGHT_GRAY, BaseColor.BLACK, Etc.Common.HEIGHT_AUTO, Convert_Percent));

                total_cov += executed_double;
            }

            percentage = Math.Truncate(total_cov / MainViewModel.Coverage_Data.Count * 100) / 100;

            MCDCCoverageTable.AddCell(CreateTableCell("Total", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f));

            float Convert_Percent_Total = ((float)((float)((491f / 100f)) * percentage));
            MCDCCoverageTable.AddCell(CreateTableCell(percentage.ToString() + "%", PdfPCell.ALIGN_MIDDLE, PdfPCell.ALIGN_CENTER, BaseColor.DARK_GRAY, BaseColor.WHITE, 28f, Convert_Percent_Total));
            MCDCCoverageTable.SpacingAfter = 30;


            return MCDCCoverageTable;
        }

        class PDFBackgroundHelper : PdfPageEventHelper
        {

            private PdfContentByte cb;
            private List<PdfTemplate> templates;
            //constructor
            public PDFBackgroundHelper()
            {
                this.templates = new List<PdfTemplate>();
            }

            public override void OnEndPage(PdfWriter writer, Document document)
            {
                try
                {
                    base.OnEndPage(writer, document);


                    bool PageVertical = false;

                    if ((int)(document.PageSize.Width / 2) == 297)
                        PageVertical = true;
                    else
                        PageVertical = false;

                    cb = writer.DirectContentUnder;
                    PdfTemplate templateM = cb.CreateTemplate(50, 50);
                    templates.Add(templateM);

                    

                    if (PageVertical)
                    {
                        iTextSharp.text.Image image = iTextSharp.text.Image.GetInstance(MainViewModel.Install_path + "\\report\\Back_A4.png");
                        image.ScaleAbsoluteHeight((int)(210 * 4));
                        image.ScaleAbsoluteWidth((int)(297 * 2));

                        image.SetAbsolutePosition(0, 0);
                        image.Alignment = Image.UNDERLYING;
                        document.Add(image);
                    }
                    else
                    {
                        iTextSharp.text.Image image = iTextSharp.text.Image.GetInstance(MainViewModel.Install_path + "\\report\\Back_A4_Rotate.png");
                        image.ScaleAbsoluteWidth((int)(210 * 4));
                        image.ScaleAbsoluteHeight((int)(297 * 2));
                        image.SetAbsolutePosition(0, 0);
                        document.Add(image);
                    }
                    

                    int pageN = writer.CurrentPageNumber;
                    String pageText = "Page " + pageN.ToString();
                    BaseFont bf = BaseFont.CreateFont(BaseFont.HELVETICA, BaseFont.CP1252, BaseFont.NOT_EMBEDDED);
                    float len;

                    if(PageVertical)
                        len = (PageSize.A4.Width / 2) - bf.GetWidthPoint(pageText, 10);
                    else
                        len = (PageSize.A4.Height / 2) - bf.GetWidthPoint(pageText, 10);
                    cb.BeginText();
                    cb.SetFontAndSize(bf, 10);
                    if (PageVertical)
                        cb.SetTextMatrix(len, document.PageSize.GetBottom(document.BottomMargin) - 8);
                    else
                        cb.SetTextMatrix(len, document.PageSize.GetBottom(document.BottomMargin));
                    cb.ShowText(pageText);
                    cb.EndText();
                    cb.AddTemplate(templateM, len, document.PageSize.GetBottom(document.BottomMargin));
                }catch(Exception)
                {

                }
            }

            public override void OnCloseDocument(PdfWriter writer, Document document)
            {
                base.OnCloseDocument(writer, document);
                BaseFont bf = BaseFont.CreateFont(BaseFont.HELVETICA, BaseFont.CP1252, BaseFont.NOT_EMBEDDED);
                foreach (PdfTemplate item in templates)
                {
                    item.BeginText();
                    item.SetFontAndSize(bf, 10);
                    item.SetTextMatrix(0, 0);
                    //item.ShowText("" + (writer.PageNumber));
                    item.EndText();
                }

            }
        }
        public PdfPCell CreateTableCell(string text, int Vertical, int Horizontal, BaseColor backcolor, BaseColor fontcolor, float cellHeight)
        {
            Font font = new Font(FontFactory.GetFont("HY견고딕", BaseFont.IDENTITY_H));
            font.Size = 11;
            font.Color = fontcolor;


            PdfPCell cell = new PdfPCell(new Phrase(text, font));
            cell.UseAscender = true;
            if (cellHeight != Etc.Common.HEIGHT_AUTO)
                cell.FixedHeight = cellHeight;

            cell.BackgroundColor = backcolor;
            cell.VerticalAlignment = Vertical;
            cell.HorizontalAlignment = Horizontal;

            return cell;
        }

        public PdfPCell CreateTableCell(string text, int Vertical, int Horizontal, BaseColor backcolor, BaseColor fontcolor, float cellHeight, float bolder_width)
        {
            Font font = new Font(FontFactory.GetFont("HY견고딕", BaseFont.IDENTITY_H));
            font.Size = 11;
            font.Color = fontcolor;


            PdfPCell cell = new PdfPCell(new Phrase(text, font));
            cell.UseAscender = true;
            if (cellHeight != Etc.Common.HEIGHT_AUTO)
                cell.FixedHeight = cellHeight;

            cell.BorderColorLeft = BaseColor.GREEN;
            cell.BorderWidthLeft = bolder_width;
            cell.PaddingTop = 2f;
            cell.PaddingBottom = 2f;
            cell.BackgroundColor = backcolor;
            cell.VerticalAlignment = Vertical;
            cell.HorizontalAlignment = Horizontal;
            

            return cell;
        }
        private void SavePdfBackgroundWorker_DoWork(string filename)
        {
            createPDF(filename);
        }
        private void SavePdfBackgroundWorker_DoWorkComplete(object sender, RunWorkerCompletedEventArgs e)
        {
            DialogHost.IsOpen = false;
        }
        private void SavePdfBackgroundWorker_ProgressChanged(object sender, ProgressChangedEventArgs e)
        {
            ViewModelLocator.MainViewModel.SavePdfProgress = e.ProgressPercentage;
        }
        BackgroundWorker SavePdfBackgroundWorker;
        private object SavePdflockObject = new object();
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            ViewModelLocator.MainViewModel.SavePdfProgress = 0;
            SaveFileDialog sfd = new SaveFileDialog() { Filter = "PDF file|*pdf", ValidateNames = true };

            if (sfd.ShowDialog() == true)
            {
                DialogHost.IsOpen = true;
                lock (SavePdflockObject)
                {
                    SavePdfBackgroundWorker = new BackgroundWorker();

                    SavePdfBackgroundWorker.DoWork += (obj, a) => SavePdfBackgroundWorker_DoWork(sfd.FileName);
                    SavePdfBackgroundWorker.RunWorkerCompleted += SavePdfBackgroundWorker_DoWorkComplete;
                    SavePdfBackgroundWorker.WorkerSupportsCancellation = true;
                    SavePdfBackgroundWorker.WorkerReportsProgress = true;
                    SavePdfBackgroundWorker.ProgressChanged += new ProgressChangedEventHandler(SavePdfBackgroundWorker_ProgressChanged);
                    SavePdfBackgroundWorker.RunWorkerAsync();
                }
            }

        }


        private string[] GetFileList(string dir_path)
        {
            return Directory.GetFiles(dir_path);
        }

        private void timing_capture()
        {
            for(int i = 0; i < TimingChartContainerViewModel.test_tmp.Count - 1; i++)
            {
                Snapshot((UIElement)TimingChartContainerViewModel.test_tmp[i], 1.0, 100, @"C:\Users\CSA_DEV\Documents\Working\timing" + i + ".png");
            }

            Snapshot((UIElement)MemoryUsageContainerViewModel.test_tmp[MemoryUsageContainerViewModel.test_tmp.Count - 1], 1.0, 100, @"C:\Users\CSA_DEV\Documents\Working\timingtitle.png");
        }

        private void memory_capture()
        {
            for (int i = 0; i < MemoryUsageContainerViewModel.test_tmp.Count - 1; i++)
            {
                Snapshot((UIElement)MemoryUsageContainerViewModel.test_tmp[i], 1.0, 100, @"C:\Users\CSA_DEV\Documents\Working\memory" + i + ".png");
            }

            Snapshot((UIElement)MemoryUsageContainerViewModel.test_tmp[MemoryUsageContainerViewModel.test_tmp.Count - 1], 1.0, 100, @"C:\Users\CSA_DEV\Documents\Working\totalmemory.png");
        }

        public void UpdateWindow()
        {
            // 화면 객체의 변경사항을 즉시 업데이트한다
            System.Windows.Threading.Dispatcher.CurrentDispatcher.Invoke(
                      System.Windows.Threading.DispatcherPriority.Background,
                      new System.Threading.ThreadStart(delegate { }));
        }

        private void Snapshot(UIElement source, double scale, int quality, string file_path)
        {
            double actualHeight = source.RenderSize.Height;
            double actualWidth = source.RenderSize.Width;

            double renderHeight = actualHeight * scale;
            double renderWidth = actualWidth * scale;

            RenderTargetBitmap renderTarget = new RenderTargetBitmap((int)renderWidth, (int)renderHeight, 96, 96, PixelFormats.Pbgra32);
            VisualBrush sourceBrush = new VisualBrush(source);

            DrawingVisual drawingVisual = new DrawingVisual();
            DrawingContext drawingContext = drawingVisual.RenderOpen();

            using (drawingContext)
            {
                //drawingContext.PushTransform(new ScaleTransform(scale, scale));
                drawingContext.DrawRectangle(sourceBrush, null, new Rect(new System.Windows.Point(0, 0), new System.Windows.Point(actualWidth, actualHeight)));
            }
            renderTarget.Render(drawingVisual);

            JpegBitmapEncoder jpgEncoder = new JpegBitmapEncoder();
            jpgEncoder.QualityLevel = quality;
            jpgEncoder.Frames.Add(BitmapFrame.Create(renderTarget));

            using (FileStream stm = File.OpenWrite(file_path))
                jpgEncoder.Save(stm);
        }

        private void TabControl_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            string tabItem = ((sender as TabControl).SelectedItem as TabItem).Header as string;

            switch (tabItem)
            {
                case "Test Summary":
                    Summary_flag = true;
                    break;
                case "Memory Usage":
                    Memory_flag = true;
                    break;
                case "Test Fail List":
                    FailList_flag = true;
                    break;
                case "Execution Time":
                    Timing_flag = true;
                    break;
                case "Coverage":
                    Coverage_flag = true;
                    break;
                default:
                    return;
            }
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            
        }
        private void TitleBar_MouseDown(object sender, MouseButtonEventArgs e)
        {
            DragMove();
            
        }

        private void CommandBinding_CanExecute(object sender, CanExecuteRoutedEventArgs e)
        {
            e.CanExecute = true;
        }

        private void CommandBinding_Executed_Close(object sender, ExecutedRoutedEventArgs e)
        {
            SystemCommands.CloseWindow(this);
        }

        private void RadioButton_Checked(object sender, RoutedEventArgs e)
        {
            RadioButton radioButton = (RadioButton)sender;
            if (radioButton != null && ContentTabControl != null)
            {
                TextBlock textBlock = (TextBlock)radioButton.Content;
                if (textBlock.Text.Equals("Test Summary"))
                    ContentTabControl.SelectedIndex = 0;
                else if (textBlock.Text.Equals("Memory Usage"))
                    ContentTabControl.SelectedIndex = 1;
                else if (textBlock.Text.Equals("Test Detail Info"))
                    ContentTabControl.SelectedIndex = 2;
                else if (textBlock.Text.Equals("Execution Time"))
                    ContentTabControl.SelectedIndex = 3;
                else if (textBlock.Text.Equals("Coverage"))
                    ContentTabControl.SelectedIndex = 4;
                else if (textBlock.Text.Equals("Total Code Coverage"))
                    ContentTabControl.SelectedIndex = 5;
                else if (textBlock.Text.Equals("Total MCDC Coverage"))
                    ContentTabControl.SelectedIndex = 6;
            }
        }
        private int DebugModeInput = 0;

        private void TextBlock_MouseLeftButtonUp_1(object sender, MouseButtonEventArgs e)
        {
            DebugModeInput++;

            if (DebugModeInput > 10)
            {
                TRANSITIONER.SelectedIndex = 1;
                DebugModeInput = 0;
            }
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            TRANSITIONER.SelectedIndex = 0;
        }
    }
}
