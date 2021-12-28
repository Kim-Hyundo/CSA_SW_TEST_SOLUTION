using CommonServiceLocator;
using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Command;
using GalaSoft.MvvmLight.Ioc;
using GraphProject.Models;
using GraphProject.Views;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Controls;

namespace GraphProject.ViewModel
{
    public class TotalMemoryUsageViewModel : ViewModelBase
    {
        public TotalMemoryUsageModel totalMemoryUsageModel { get; set; } = new TotalMemoryUsageModel();
        public TotalMemoryUsageModel TotalMemoryUsageData { get; set; } = new TotalMemoryUsageModel();
        public TotalMemoryUsageModel SwMemoryUsageData { get; set; } = new TotalMemoryUsageModel();

        public RelayCommand ComboSelectCommand { get; set; }
        public RelayCommand UnitComboSelectCommand { get; set; }

        private ComboBoxItem _unitmode;

        public ComboBoxItem UnitMode
        {
            get { return _unitmode; }
            set
            {
                if (_unitmode != value)
                {
                    _unitmode = value;
                    RaisePropertyChanged("UnitMode");
                }
            }
        }

        private ComboBoxItem _memorymode;

        public ComboBoxItem MemoryMode
        {
            get { return _memorymode; }
            set
            {
                if (_memorymode != value)
                {
                    _memorymode = value;
                    RaisePropertyChanged("MemoryMode");
                }
            }
        }
        [PreferredConstructor]
        public TotalMemoryUsageViewModel() { }

        public TotalMemoryUsageViewModel(TotalMemoryUsageModel tmum, TotalMemoryUsageModel sw_tmum)
        {
            this.totalMemoryUsageModel = tmum;
            this.TotalMemoryUsageData = tmum;
            this.SwMemoryUsageData = sw_tmum;

            totalMemoryUsageModel.Header1 = "Code";
            totalMemoryUsageModel.Header2 = "Data";
            totalMemoryUsageModel.Header3 = "Usage";
            totalMemoryUsageModel.Header4 = "Reserved";
            totalMemoryUsageModel.Header5 = "Total";
            totalMemoryUsageModel.Header6 = "UsageRate";

            ComboSelectCommand = new RelayCommand(ComboSelectFunction);
            UnitComboSelectCommand = new RelayCommand(UnitComboSelectFunction);
        }


        private void ComboSelectFunction()
        {
            if (MemoryMode == null) return;

            if (MemoryMode.Content.ToString() == "Total Memory")
            {
                totalMemoryUsageModel = TotalMemoryUsageData;

                totalMemoryUsageModel.Header1 = "Code";
                totalMemoryUsageModel.Header2 = "Data";
                totalMemoryUsageModel.Header3 = "Usage";
                totalMemoryUsageModel.Header4 = "Reserved";
                totalMemoryUsageModel.Header5 = "Total";
                totalMemoryUsageModel.Header6 = "UsageRate";
            }
            else if (MemoryMode.Content.ToString() == "Source File")
            {
                totalMemoryUsageModel = SwMemoryUsageData;

                totalMemoryUsageModel.Header1 = "RamCode";
                totalMemoryUsageModel.Header2 = "RamData";
                totalMemoryUsageModel.Header3 = "RomCode";
                totalMemoryUsageModel.Header4 = "RomData";
                totalMemoryUsageModel.Header5 = "RamUsage";
                totalMemoryUsageModel.Header6 = "RomUsage";
            }

            ChangeDataUnit();
        }
        private void UnitComboSelectFunction()
        {
            if (UnitMode == null) return;

            ChangeDataUnit();
            ServiceLocator.Current.GetInstance<MemoryUsageContainerViewModel>().UpdateUnit(UnitMode.Content.ToString());
            
        }
        public void ChangeDataUnit()
        {
            if (UnitMode == null) return;

            if (UnitMode.Content.ToString() == "Byte")
            {
                for (int i=0;i< totalMemoryUsageModel.TotalMemoryList.Count;i++)
                {
                    totalMemoryUsageModel.TotalMemoryList[i].MemoryCode = totalMemoryUsageModel.TotalMemoryValueList[i].MemoryCodeValue.ToString("0.###") + " Byte";
                    totalMemoryUsageModel.TotalMemoryList[i].MemoryData = totalMemoryUsageModel.TotalMemoryValueList[i].MemoryDataValue.ToString("0.###") + " Byte";
                    totalMemoryUsageModel.TotalMemoryList[i].MemoryUsage = totalMemoryUsageModel.TotalMemoryValueList[i].MemoryUsageValue.ToString("0.###") + " Byte";
                    totalMemoryUsageModel.TotalMemoryList[i].MemoryReserved = totalMemoryUsageModel.TotalMemoryValueList[i].MemoryReservedValue.ToString("0.###") + " Byte";
                    totalMemoryUsageModel.TotalMemoryList[i].MemorySize = totalMemoryUsageModel.TotalMemoryValueList[i].MemorySizeValue.ToString("0.###") + " Byte";
                }
                
            }
            else if (UnitMode.Content.ToString() == "KByte")
            {
                for (int i = 0; i < totalMemoryUsageModel.TotalMemoryList.Count; i++)
                {
                    if (totalMemoryUsageModel.TotalMemoryValueList[i].MemoryCodeValue != 0)
                        totalMemoryUsageModel.TotalMemoryList[i].MemoryCode = ((double)totalMemoryUsageModel.TotalMemoryValueList[i].MemoryCodeValue / 1024).ToString("0.###") + " KByte";
                    else
                        totalMemoryUsageModel.TotalMemoryList[i].MemoryCode = totalMemoryUsageModel.TotalMemoryValueList[i].MemoryCodeValue + " KByte";

                    if (totalMemoryUsageModel.TotalMemoryValueList[i].MemoryDataValue != 0)
                        totalMemoryUsageModel.TotalMemoryList[i].MemoryData = ((double)totalMemoryUsageModel.TotalMemoryValueList[i].MemoryDataValue / 1024).ToString("0.###") + " KByte";
                    else
                        totalMemoryUsageModel.TotalMemoryList[i].MemoryData = totalMemoryUsageModel.TotalMemoryValueList[i].MemoryDataValue + " KByte";

                    if (totalMemoryUsageModel.TotalMemoryValueList[i].MemoryUsageValue != 0)
                        totalMemoryUsageModel.TotalMemoryList[i].MemoryUsage = ((double)totalMemoryUsageModel.TotalMemoryValueList[i].MemoryUsageValue / 1024).ToString("0.###") + " KByte";
                    else
                        totalMemoryUsageModel.TotalMemoryList[i].MemoryUsage = totalMemoryUsageModel.TotalMemoryValueList[i].MemoryUsageValue + " KByte";

                    if (totalMemoryUsageModel.TotalMemoryValueList[i].MemoryReservedValue != 0)
                        totalMemoryUsageModel.TotalMemoryList[i].MemoryReserved = ((double)totalMemoryUsageModel.TotalMemoryValueList[i].MemoryReservedValue / 1024).ToString("0.###") + " KByte";
                    else
                        totalMemoryUsageModel.TotalMemoryList[i].MemoryReserved = totalMemoryUsageModel.TotalMemoryValueList[i].MemoryReservedValue + " KByte";

                    if (totalMemoryUsageModel.TotalMemoryValueList[i].MemorySizeValue != 0)
                        totalMemoryUsageModel.TotalMemoryList[i].MemorySize = ((double)totalMemoryUsageModel.TotalMemoryValueList[i].MemorySizeValue / 1024).ToString("0.###") + " KByte";
                    else
                        totalMemoryUsageModel.TotalMemoryList[i].MemorySize = totalMemoryUsageModel.TotalMemoryValueList[i].MemorySizeValue + " KByte";
                }
            }
            else if (UnitMode.Content.ToString() == "MByte")
            {
                for (int i = 0; i < totalMemoryUsageModel.TotalMemoryList.Count; i++)
                {
                    if (totalMemoryUsageModel.TotalMemoryValueList[i].MemoryCodeValue != 0)
                        totalMemoryUsageModel.TotalMemoryList[i].MemoryCode = ((double)totalMemoryUsageModel.TotalMemoryValueList[i].MemoryCodeValue / 1024 / 1024).ToString("0.###") + " MByte";
                    else
                        totalMemoryUsageModel.TotalMemoryList[i].MemoryCode = totalMemoryUsageModel.TotalMemoryValueList[i].MemoryCodeValue + " MByte";

                    if (totalMemoryUsageModel.TotalMemoryValueList[i].MemoryDataValue != 0)
                        totalMemoryUsageModel.TotalMemoryList[i].MemoryData = ((double)totalMemoryUsageModel.TotalMemoryValueList[i].MemoryDataValue / 1024 / 1024).ToString("0.###") + " MByte";
                    else
                        totalMemoryUsageModel.TotalMemoryList[i].MemoryData = totalMemoryUsageModel.TotalMemoryValueList[i].MemoryDataValue + " MByte";

                    if (totalMemoryUsageModel.TotalMemoryValueList[i].MemoryUsageValue != 0)
                        totalMemoryUsageModel.TotalMemoryList[i].MemoryUsage = ((double)totalMemoryUsageModel.TotalMemoryValueList[i].MemoryUsageValue / 1024 / 1024).ToString("0.###") + " MByte";
                    else
                        totalMemoryUsageModel.TotalMemoryList[i].MemoryUsage = totalMemoryUsageModel.TotalMemoryValueList[i].MemoryUsageValue + " MByte";

                    if (totalMemoryUsageModel.TotalMemoryValueList[i].MemoryReservedValue != 0)
                        totalMemoryUsageModel.TotalMemoryList[i].MemoryReserved = ((double)totalMemoryUsageModel.TotalMemoryValueList[i].MemoryReservedValue / 1024 / 1024).ToString("0.###") + " MByte";
                    else
                        totalMemoryUsageModel.TotalMemoryList[i].MemoryReserved = totalMemoryUsageModel.TotalMemoryValueList[i].MemoryReservedValue + " MByte";

                    if (totalMemoryUsageModel.TotalMemoryValueList[i].MemorySizeValue != 0)
                        totalMemoryUsageModel.TotalMemoryList[i].MemorySize = ((double)totalMemoryUsageModel.TotalMemoryValueList[i].MemorySizeValue / 1024 / 1024).ToString("0.###") + " MByte";
                    else
                        totalMemoryUsageModel.TotalMemoryList[i].MemorySize = totalMemoryUsageModel.TotalMemoryValueList[i].MemorySizeValue + " MByte";
                }
            }

            TotalMemoryUsageView.Instance.UpdateMemoryDataView();
        }
    }
}
