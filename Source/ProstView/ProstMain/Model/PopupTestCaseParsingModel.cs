using GalaSoft.MvvmLight;
using ProstMain.ViewModel;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProstMain.Model
{
    public class PopupTestCaseParsingModel : ObservableObject
    {
        /// <summary>
        /// 테스트 사양서 파싱 완료 Dialog Show Flag
        /// </summary>
        private bool _IsTestSpecConvertPopupOpen;
        public bool IsTestSpecConvertPopupOpen
        {
            get { return _IsTestSpecConvertPopupOpen; }
            set
            {
                if (_IsTestSpecConvertPopupOpen != value)
                {
                    _IsTestSpecConvertPopupOpen = value;
                    RaisePropertyChanged("IsTestSpecConvertPopupOpen");
                }
            }
        }
        /// <summary>
        /// Parser Selected Item
        /// </summary>
        private string _ParserSelectedItem;
        public string ParserSelectedItem
        {
            get { return _ParserSelectedItem; }
            set
            {
                if (_ParserSelectedItem != value)
                {
                    _ParserSelectedItem = value;
                    RaisePropertyChanged("ParserSelectedItem");
                }
            }
        }
        /// <summary>
        /// 테스트사양서 경로
        /// </summary>
        private string _TestStatement;
        public string TestStatement
        {
            get { return _TestStatement; }
            set
            {
                if (_TestStatement != value)
                {
                    _TestStatement = value;
                    RaisePropertyChanged("TestStatement");
                }
            }
        }
        /// <summary>
        /// 테스트케이스 경로
        /// </summary>
        private string _TestcasePath;
        public string TestcasePath
        {
            get { return _TestcasePath; }
            set
            {
                if (_TestcasePath != value)
                {
                    _TestcasePath = value;
                    RaisePropertyChanged("TestcasePath");
                }
            }
        }
        /// <summary>
        /// 테스트 사양서 파싱작업 시 Rotation Image Animation 동작 Run/Stop
        /// </summary>
        private string _IsTestCaseProduction;
        public string IsTestCaseProduction
        {
            get { return _IsTestCaseProduction; }
            set
            {
                if (_IsTestCaseProduction != value)
                {
                    _IsTestCaseProduction = value;
                    RaisePropertyChanged("IsTestCaseProduction");
                }
            }
        }
        /// <summary>
        /// 테스트케이스 파싱작업 완료 Flag
        /// </summary>
        private int _IsTestcaseParserComplete;
        public int IsTestcaseParserComplete
        {
            get { return _IsTestcaseParserComplete; }
            set
            {
                if (_IsTestcaseParserComplete != value)
                {
                    _IsTestcaseParserComplete = value;
                    RaisePropertyChanged("IsTestcaseParserComplete");
                }
            }
        }
        /// <summary>
        /// 테스트사양서 파싱작업 완료 Flag
        /// </summary>
        private int _IsTestSpecParserComplete;
        public int IsTestSpecParserComplete
        {
            get { return _IsTestSpecParserComplete; }
            set
            {
                if (_IsTestSpecParserComplete != value)
                {
                    _IsTestSpecParserComplete = value;
                    RaisePropertyChanged("IsTestSpecParserComplete");
                }
            }
        }
        /// <summary>
        /// 파서 리스트 
        /// </summary>
        private ObservableCollection<string> _ParserList;
        public ObservableCollection<string> ParserList
        {
            get { return _ParserList; }
            set
            {
                if (_ParserList != value)
                {
                    _ParserList = value;
                    RaisePropertyChanged("ParserList");
                }
            }
        }

        public PopupTestCaseParsingModel()
        {
            ParserList = new ObservableCollection<string>();

            if (ViewModelLocator.MainVM.MainModel.PROGRAM_MODE == Common.Common.CUSTOMER_ALL || ViewModelLocator.MainVM.MainModel.PROGRAM_MODE == Common.Common.CUSTOMER_MANDO)
            {
                if (Directory.Exists(Common.Common.INSTALL_PATH + "\\src\\parser\\src\\Mando\\MandoUnitTest\\specification"))
                {
                    string[] files = Directory.GetFiles(Common.Common.INSTALL_PATH + "\\src\\parser\\src\\Mando\\MandoUnitTest\\specification", "*.py");
                    foreach (string f in files)
                    {
                        ParserList.Add(Path.GetFileNameWithoutExtension(f));
                    }
                }
            }
            
            if(ViewModelLocator.MainVM.MainModel.PROGRAM_MODE == Common.Common.CUSTOMER_ALL || ViewModelLocator.MainVM.MainModel.PROGRAM_MODE == Common.Common.CUSTOMER_WIA)
            {
                if (Directory.Exists(Common.Common.INSTALL_PATH + "\\src\\parser\\src\\Wia\\WiaUnitTest\\specification"))
                { 
                    string[] files = Directory.GetFiles(Common.Common.INSTALL_PATH + "\\src\\parser\\src\\Wia\\WiaUnitTest\\specification", "*.py");
                    foreach (string f in files)
                    {
                        ParserList.Add(Path.GetFileNameWithoutExtension(f));
                    }
                }
            }

            if (ParserList.Count > 0)
                ParserSelectedItem = ParserList[0];
        }
    }
}
