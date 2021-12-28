using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using GalaSoft.MvvmLight.Ioc;
using GraphProject.Etc;
using GraphProject.Models;
using LiveCharts;
using LiveCharts.Wpf;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace GraphProject.ViewModel
{
    public class TimingChartContainerViewModel : ViewModelBase
    {
        public RelayCommand<object> SearchCommand { get; set; }
        public static List<object> test_tmp;
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

        private string _scenarioName;

        public string ScenarioName
        {
            get { return this._scenarioName; }

            set
            {
                this._scenarioName = value;
                this.RaisePropertyChanged("ScenarioName");
            }
        }

        private TimingChartModel contentAdd(string func_name, IronPython.Runtime.PythonDictionary merged_data, IronPython.Runtime.PythonDictionary Total_Timing_Dic)
        {
            ScenarioName = MainViewModel.curr_scenario;

            List<double> datas = new List<double>();

            foreach (string file_name in Total_Timing_Dic.keys())
            {
                IronPython.Runtime.PythonDictionary data = (IronPython.Runtime.PythonDictionary)Total_Timing_Dic[file_name];

                if (!data.keys().Contains(func_name))
                    continue;

                IronPython.Runtime.PythonDictionary timing_data = (IronPython.Runtime.PythonDictionary)data[func_name];

                string avr_time = timing_data["avr"].ToString();
                if (avr_time != "-")
                {
                    if (TimingChartViewModel.priority(avr_time) != 2)
                        avr_time = TimingChartViewModel.ToMicroSecond(avr_time);

                    datas.Add(Convert.ToDouble(avr_time.Substring(0, avr_time.Length - 2)));
                }
            }
            // ScenarioName

           LinearGradientBrush myLinearGradientBrush = new LinearGradientBrush();
            myLinearGradientBrush.StartPoint = new Point(0, 0);
            myLinearGradientBrush.EndPoint = new Point(1, 0);
            myLinearGradientBrush.GradientStops.Add(
                new GradientStop(Color.FromRgb(0x71, 0xCE, 0xAA), 1.0));
            myLinearGradientBrush.GradientStops.Add(
                new GradientStop(Color.FromRgb(0xD1, 0xEF, 0xCF), 0.0));

            LinearGradientBrush myLinearGradientBrush_1 = new LinearGradientBrush();
            myLinearGradientBrush_1.StartPoint = new Point(0, 0);
            myLinearGradientBrush_1.EndPoint = new Point(1, 0);
            myLinearGradientBrush_1.GradientStops.Add(
                new GradientStop(Color.FromRgb(0xDE, 0x7B, 0x4D), 0.0));
            myLinearGradientBrush_1.GradientStops.Add(
                new GradientStop(Color.FromRgb(0xDE, 0xAB, 0x4D), 1.0));

            LinearGradientBrush myLinearGradientBrush_2 = new LinearGradientBrush();
            myLinearGradientBrush_2.StartPoint = new Point(0, 0);
            myLinearGradientBrush_2.EndPoint = new Point(1, 0);
            myLinearGradientBrush_2.GradientStops.Add(
                new GradientStop(Color.FromRgb(0x46, 0x46, 0x46), 0.0));
            myLinearGradientBrush_2.GradientStops.Add(
                new GradientStop(Color.FromRgb(0x64, 0x64, 0x64), 1.0));



            TimingChartModel tcm = new TimingChartModel();
            tcm.SeriesCollection = new SeriesCollection();

            if (merged_data["count"].ToString().Trim().Equals("1"))
            {
                tcm.SeriesCollection.Add(new RowSeries
                {
                    Title = "Time",
                    Values = new ChartValues<double> { 0 },
                    Fill = myLinearGradientBrush,
                    DataLabels = true
                });
            }
            else
            {
                tcm.SeriesCollection.Add(new RowSeries
                {
                    Title = "Min",
                    Values = new ChartValues<double> { 0 },
                    Fill = myLinearGradientBrush,
                    DataLabels = true
                });
                tcm.SeriesCollection.Add(new RowSeries
                {
                    Title = "Max",
                    Values = new ChartValues<double> { 0 },
                    Fill = myLinearGradientBrush_1,
                    DataLabels = true
                });
                tcm.SeriesCollection.Add(new RowSeries
                {
                    Title = "Average",
                    Values = new ChartValues<double> { 0 },
                    Fill = myLinearGradientBrush_2,
                    DataLabels = true
                });
            }

            
            tcm.FuncName = func_name.Trim();
            if (tcm.FuncName.Equals("Rte_Call_SWC_DiagnosticMonitor_Event_DEM_E_UDS_DTC_C164686_SetEventStatus"))
            {

            }
            tcm.MaxValue = merged_data["max"].ToString().Trim();
            tcm.MinValue = merged_data["min"].ToString().Trim();
            
            tcm.AvrValue = CommonUtil.GetTimingAvrValue(merged_data["total"].ToString(), merged_data["count"].ToString());
            tcm.FuncCount = merged_data["count"].ToString().Trim();
            tcm.TotalDatas = datas;

            if (tcm.MaxValue != "-" && TimingChartViewModel.priority(tcm.MaxValue) != 2)
                tcm.MaxValue = TimingChartViewModel.ToMicroSecond(tcm.MaxValue);
            if (tcm.MinValue != "-" && TimingChartViewModel.priority(tcm.MinValue) != 2)
                tcm.MinValue = TimingChartViewModel.ToMicroSecond(tcm.MinValue);

            if (tcm.MaxValue == "-" || tcm.MinValue == "-")
            {
                tcm.Scale = "";
            }

            double max = 0.0;
            double min = 0.0;
            double avr = 0.0;
            double scale = 0.0;
            bool isok = false;

            if (tcm.MaxValue != "-" && tcm.MinValue != "-" && tcm.Scale != "-")
            {
                max = Convert.ToDouble(tcm.MaxValue.Substring(0, tcm.MaxValue.Length - 2));
                min = Convert.ToDouble(tcm.MinValue.Substring(0, tcm.MinValue.Length - 2));
                avr = Convert.ToDouble(tcm.AvrValue.Substring(0, tcm.AvrValue.Length - 2));
                scale = Math.Truncate(((Math.Abs(max - min)) / 10.0) * 10000) / 10000;
                tcm.Scale = scale.ToString() + "us";
                isok = true;
            }

            if (isok)
            {
                if (tcm.FuncCount.Equals("1"))
                {
                    ChartValues<double> timeChartValues = new ChartValues<double>();
                    timeChartValues.Add(avr);
                    tcm.SeriesCollection[0].Values = timeChartValues;
                }
                else
                {
                    ChartValues<double> maxChartValues = new ChartValues<double>();
                    ChartValues<double> minChartValues = new ChartValues<double>();
                    ChartValues<double> avgChartValues = new ChartValues<double>();


                    minChartValues.Add(min);
                    tcm.SeriesCollection[0].Values = minChartValues;

                    maxChartValues.Add(max);
                    tcm.SeriesCollection[1].Values = maxChartValues;

                    avgChartValues.Add(avr);
                    tcm.SeriesCollection[2].Values = avgChartValues;
                }

                /*List<double> area = TimingChartViewModel.AreaFilteringFunction(min, max, scale);
                ChartValues<double> count = new ChartValues<double>();*/
                /*count.Add(avr);
                count.Add(max);
                count.Add(min);*/
                
                //ChartValues<double> count = TimingChartViewModel.CountFunction(tcm.TotalDatas, area);
                //string[] labels = TimingChartViewModel.CreateLabelFunction(area);
                
                
                //tcm.SeriesCollection[0].Values = count;

                return tcm;
            }
   
            else
            {
                return null;
            }
        }


        [PreferredConstructor]
        public TimingChartContainerViewModel()
        {

            test_tmp = new List<object>();
            //CaptureCommand = new RelayCommand(captureFunction);

            IronPython.Runtime.PythonDictionary Merge_Timing_Dic = MainViewModel.Merge_Timing_Data;
            IronPython.Runtime.PythonDictionary Total_Timing_Dic = MainViewModel.Total_Timing_Data;

            int cellCount = Merge_Timing_Dic.Count;
            int numCols = 3;
            int numRows = (int)Math.Ceiling(Decimal.Divide(cellCount, numCols));


            GridContainer = new Grid();

            /*            for (int i = 0; i < numCols; ++i)
                            this.GridContainer.ColumnDefinitions.Add(new ColumnDefinition());
                        for (int i = 0; i < numRows; ++i)
                            this.GridContainer.RowDefinitions.Add(new RowDefinition());*/

            for (int i = 0; i < cellCount; ++i)
                this.GridContainer.RowDefinitions.Add(new RowDefinition());


            foreach (var g in this.GridContainer.RowDefinitions)
            {
                g.Height = new GridLength(150);
            }

/*            foreach (var g in GridContainer.ColumnDefinitions)
            {
                g.Width = new GridLength(500);
            }*/

            int iter = 0;

            foreach (string key in Merge_Timing_Dic.keys())
            {
                IronPython.Runtime.PythonDictionary merged_data = (IronPython.Runtime.PythonDictionary)Merge_Timing_Dic[key];

                TimingChartModel model = contentAdd(key, merged_data, Total_Timing_Dic);
                if (model == null)
                    continue;

                int idx = GridContainer.Children.Add(new ContentControl());
                ContentControl x = GridContainer.Children[idx] as ContentControl;

                x.Content = new TimingChartViewModel(model);
                x.SetValue(Grid.RowProperty, iter);
                //x.SetValue(Grid.ColumnProperty, iter % numCols);
                iter++;
                test_tmp.Add(x);
                //Snapshot((UIElement)x.Content, 1.0, 100, @"C:\Users\Mingi.Nam\Documents\Scanned Documents\coverage" + idx + ".png");
            }



            /*            IronPython.Runtime.PythonDictionary merged_data_1 = (IronPython.Runtime.PythonDictionary)Merge_Timing_Dic["VC_Step3"];

                        int idx_1 = GridContainer.Children.Add(new ContentControl());
                        ContentControl x_1 = GridContainer.Children[idx_1] as ContentControl;
                        x_1.Content = new TimingChartViewModel(contentAdd("VC_Step3", merged_data_1, Total_Timing_Dic));
                        x_1.SetValue(Grid.RowProperty, iter / numCols);
                        x_1.SetValue(Grid.ColumnProperty, iter % numCols);
                        iter++;
                        test_tmp.Add(x_1);*/

            SearchCommand = new RelayCommand<object>(Search);
        }

        public void Search(object e)
        {
            string str = e.ToString();

            IronPython.Runtime.PythonDictionary Merge_Timing_Dic = MainViewModel.Merge_Timing_Data;
            IronPython.Runtime.PythonDictionary Total_Timing_Dic = MainViewModel.Total_Timing_Data;
            int cellCount = 0;

            foreach (string key in Merge_Timing_Dic.keys())
            {
                if (key.Contains(str))
                    cellCount++;
            }

            GridContainer.Children.Clear();
            GridContainer.RowDefinitions.Clear();

            for (int i = 0; i < cellCount; ++i)
                this.GridContainer.RowDefinitions.Add(new RowDefinition());

            foreach (var g in this.GridContainer.RowDefinitions)
            {
                g.Height = new GridLength(150);
            }


            int iter = 0;
            foreach (string key in Merge_Timing_Dic.keys())
            {
                if (key.Contains(str))
                {
                    IronPython.Runtime.PythonDictionary merged_data = (IronPython.Runtime.PythonDictionary)Merge_Timing_Dic[key];

                    TimingChartModel model = contentAdd(key, merged_data, Total_Timing_Dic);
                    if (model == null)
                        continue;

                    int idx = GridContainer.Children.Add(new ContentControl());
                    ContentControl x = GridContainer.Children[idx] as ContentControl;

                    x.Content = new TimingChartViewModel(model);
                    x.SetValue(Grid.RowProperty, iter);
                    iter++;
                    test_tmp.Add(x);
                }
            }

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
                drawingContext.DrawRectangle(sourceBrush, null, new Rect(new Point(0, 0), new Point(actualWidth, actualHeight)));
            }
            renderTarget.Render(drawingVisual);

            JpegBitmapEncoder jpgEncoder = new JpegBitmapEncoder();
            jpgEncoder.QualityLevel = quality;
            jpgEncoder.Frames.Add(BitmapFrame.Create(renderTarget));

            using (FileStream stm = File.OpenWrite(file_path))
                jpgEncoder.Save(stm);
        }
    }
}
