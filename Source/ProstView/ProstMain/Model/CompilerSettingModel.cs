using GalaSoft.MvvmLight;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProstMain.Model
{
    public class CompilerSettingModel : ObservableObject
    {
        /// <summary>
        /// TASKING Compiler Install Path
        /// </summary>
        private string _CompilerPath;
        public string CompilerPath
        {
            get { return _CompilerPath; }
            set
            {
                if (_CompilerPath != value)
                {
                    _CompilerPath = value;
                    RaisePropertyChanged("CompilerPath");
                }
            }
        }

        /// <summary>
        /// Compiler Option
        /// </summary>
        private string _CompilerOption;
        public string CompilerOption
        {
            get { return _CompilerOption; }
            set
            {
                if (_CompilerOption != value)
                {
                    _CompilerOption = value;
                    RaisePropertyChanged("CompilerOption");
                }
            }
        }
        /// <summary>
        /// Linker Option
        /// </summary>
        private string _LinkerOption;
        public string LinkerOption
        {
            get { return _LinkerOption; }
            set
            {
                if (_LinkerOption != value)
                {
                    _LinkerOption = value;
                    RaisePropertyChanged("LinkerOption");
                }
            }
        }
        /// <summary>
        /// Compiler Version :: 4.2 / 4.3 / 6.2
        /// </summary>
        private string _CompilerVersion;
        public string CompilerVersion
        {
            get { return _CompilerVersion; }
            set
            {
                if (_CompilerVersion != value)
                {
                    _CompilerVersion = value;
                    RaisePropertyChanged("CompilerVersion");
                }
            }
        }
        /// <summary>
        /// Compiler Type :: TASKING
        /// </summary>
        private string _CompilerType;
        public string CompilerType
        {
            get { return _CompilerType; }
            set
            {
                if (_CompilerType != value)
                {
                    _CompilerType = value;
                    RaisePropertyChanged("CompilerType");
                }
            }
        }
        /// <summary>
        /// Guild Line 표시 Value
        /// </summary>
        private string _IsVisibleCompileGuild;
        public string IsVisibleCompileGuild
        {
            get { return _IsVisibleCompileGuild; }
            set
            {
                if (_IsVisibleCompileGuild != value)
                {
                    _IsVisibleCompileGuild = value;
                    RaisePropertyChanged("IsVisibleCompileGuild");
                }
            }
        }

    }
}
