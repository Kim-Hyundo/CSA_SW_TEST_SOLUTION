using GalaSoft.MvvmLight;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GraphProject.Models
{
    public class CoverageModel : ObservableObject
    {
        private string _ModuleName;
        public string ModuleName
        {
            get { return this._ModuleName; }

            set
            {
                this._ModuleName = value;
                this.RaisePropertyChanged("ModuleName");
            }
        }
        private string _ModuleCoveragePercent;
        public string ModuleCoveragePercent
        {
            get { return this._ModuleCoveragePercent; }

            set
            {
                this._ModuleCoveragePercent = value;
                this.RaisePropertyChanged("ModuleCoveragePercent");
            }
        }
        private ObservableCollection<CoverageFunctionModel> _CoverageList_Function;
        public ObservableCollection<CoverageFunctionModel> CoverageList_Function
        {
            get { return this._CoverageList_Function; }
            set
            {
                this._CoverageList_Function = value;
                this.RaisePropertyChanged("CoverageList_Function");
            }
        }

        public class CoverageFunctionModel : ObservableObject
        {
            private string _FunctionName;
            public string FunctionName
            {
                get { return this._FunctionName; }

                set
                {
                    this._FunctionName = value;
                    this.RaisePropertyChanged("FunctionName");
                }
            }
            private string _FunctionStatementCoveragePercent;
            public string FunctionStatementCoveragePercent
            {
                get { return this._FunctionStatementCoveragePercent; }

                set
                {
                    this._FunctionStatementCoveragePercent = value;
                    this.RaisePropertyChanged("FunctionStatementCoveragePercent");
                }
            }
        }
    }
}
