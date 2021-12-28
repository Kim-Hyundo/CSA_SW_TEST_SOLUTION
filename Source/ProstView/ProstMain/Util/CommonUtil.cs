using BinaryTools.Elf;
using BinaryTools.Elf.Io;
using ProstMain.Model;
using ProstMain.ViewModel;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Input;
using System.Windows.Threading;
using Xunit;
using Xunit.Sdk;
using System.Text.RegularExpressions;

namespace ProstMain.Util
{
    class CommonUtil
    {
        public CommonUtil()
        {

        }
        /// <summary>
        /// Kill Python Process
        /// [Argument : void  //  Returnvalue : void]
        /// </summary>
        public static void ExitPythonProcess()
        {
            try
            {
                Process[] processList = Process.GetProcesses();
                foreach (Process proc in processList)
                {
                    if (proc.ProcessName.Equals("python"))
                        proc.Kill();
                }
            }
            catch (Exception ex)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, ex.Message);
            }
        }
        /// <summary>
        /// Kill Excel Process
        /// [Argument : void  //  Returnvalue : void]
        /// </summary>
        public static void ExitExcelProcess()
        {
            try
            {
                Process[] processList = Process.GetProcesses();
                foreach (Process proc in processList)
                {
                    /*if (proc.ProcessName.Equals("python"))
                        proc.Kill();*/
                    if (proc.ProcessName.Equals("EXCEL"))
                        proc.Kill();
                }
            }catch(Exception ex)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, ex.Message);
            }
        }
        /// <summary>
        /// Kill TRACE32 Process
        /// [Argument : void  //  Returnvalue : void]
        /// </summary>
        public static void ExitTRACE32Process()
        {
            try
            {
                Process[] processList = Process.GetProcesses();
                foreach (Process proc in processList)
                {
                    if (proc.ProcessName.Equals("t32mtc")||proc.ProcessName.Equals("t32marm"))
                        proc.Kill();
                }
            }
            catch (Exception ex)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, ex.Message);
            }
        }
        /// <summary>
        /// Exception Information Source Line
        /// [Argument : Exception  //  Returnvalue : int]
        /// </summary>
        public static int GetExceptionLineNumber(Exception ex)
        {
            var st = new StackTrace(ex, true);
            var frame = st.GetFrame(st.FrameCount - 1);
            var line = frame.GetFileLineNumber();

            return (int)line;
        }
        /// <summary>
        /// 라이선스 파일 체크
        /// [Argument : void  //  Returnvalue : bool]
        /// </summary>
        public static bool LicenseCheck()
        {
            string LicenseApp = Common.Common.INSTALL_PATH + @"\src\license\LicenseCheck\LicenseCheck.exe";


            ProcessStartInfo start = new ProcessStartInfo();
            start.FileName = LicenseApp;
            start.UseShellExecute = false;
            start.RedirectStandardOutput = true;
            start.WindowStyle = ProcessWindowStyle.Hidden;
            start.CreateNoWindow = true;
            start.Arguments = "\"" + Common.Common.INSTALL_PATH + "\\etc" + "\" " + ViewModelLocator.TargetHWSettingVM.TargetHWSettingModel.Trace32IPAddress;


            using (Process process = Process.Start(start))
            {
                using (StreamReader reader = process.StandardOutput)
                {
                    string result = reader.ReadLine();
                    if (result.Contains("Pass"))
                        return true;
                    else if (result.Contains("Fail"))
                        return false;
                }
            }

            return false;
        }
        /// <summary>
        /// Merge Statement Coverage
        /// [Argument : IronPython.Runtime.List  //  Returnvalue : double]
        /// </summary>
        public static double merge_StateCoverage(IronPython.Runtime.List Cov_List)
        {
            int total_cnt = Cov_List.Count;
            double total_cov = 0.0;

            string[] funcnames = new string[total_cnt];

            int idx = 0;

            foreach (IronPython.Runtime.PythonDictionary tmp in Cov_List)
            {
                string funcname_tmp = tmp["tree"].ToString();
                string executed_tmp = tmp["statement"].ToString();

                if (funcname_tmp == "")
                    continue;

                if (executed_tmp == "")
                    continue;

                funcnames[idx++] = funcname_tmp.Trim();

                if (executed_tmp.Contains("%"))
                    executed_tmp = executed_tmp.Substring(0, executed_tmp.Length - 1);

                double executed_double = Convert.ToDouble(executed_tmp);
                total_cov += executed_double;
            }

            return Math.Truncate(total_cov / total_cnt * 100) / 100;
            
        }
        /// <summary>
        /// Merge Function Coverage
        /// [Argument : IronPython.Runtime.List  //  Returnvalue : double]
        /// </summary>
        public static double merge_FunctionCoverage(IronPython.Runtime.PythonDictionary Func_List)
        {
            IronPython.Runtime.List func_list_tmp = (IronPython.Runtime.List)Func_List["FunctionList"];

            double total_cov = 0.0;
            double executed_cov = 0.0;

            foreach (IronPython.Runtime.PythonDictionary tmp in func_list_tmp)
            {
                total_cov += 1.0;
                if (tmp["Coverage"].ToString() == "True")
                    executed_cov += 1.0;
            }

            return Math.Round((executed_cov / total_cov * 100),2);
        }
        /// <summary>
        /// Merge Call Coverage
        /// [Argument : IronPython.Runtime.List  //  Returnvalue : double]
        /// </summary>
        public static double merge_CallCoverage(IronPython.Runtime.PythonDictionary Call_List)
        {
            double total_cov = 0.0;
            double executed_cov = 0.0;

            IronPython.Runtime.List data_tmp = (IronPython.Runtime.List)Call_List["FunctionList"];
            foreach (IronPython.Runtime.PythonDictionary tmp in data_tmp)
            {
                IronPython.Runtime.List tc_tmp = (IronPython.Runtime.List)tmp["TestCase"];

                string tc_list = "";

                foreach (string tc in tc_tmp)
                {
                    tc_list += tc + ", ";
                }
                total_cov += 1.0;
                if (tmp["Coverage"].ToString() == "True")
                    executed_cov += 1.0;
            }

            return Math.Round((executed_cov / total_cov * 100),2);
        }
        /// <summary>
        /// ELF 파일 기반으로 소스코드 리스트 추출
        /// [Argument : void  //  Returnvalue : bool]
        /// </summary>
        public static bool GetSourceList()
        {
            try
            {
                FileStream stream = null;

                if (!File.Exists(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TimeCreateFolderPath + "\\Build\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + ".elf"))
                    stream = new FileStream(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TimeCreateFolderPath + "\\Build\\" + Path.GetFileName(ViewModelLocator.PopupBuildStatusVM.PopupBuildStatusModel.DirectELFFilePath), FileMode.Open, FileAccess.Read);
                else
                    stream = new FileStream(ViewModelLocator.ProjectSettingVM.ProjectSettingModel.TimeCreateFolderPath + "\\Build\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + ".elf", FileMode.Open, FileAccess.Read);


                var reader = new EndianBinaryReader(stream, EndianBitConverter.NativeEndianness);

                ElfFile elfFile = ElfFile.ReadElfFile(reader);

                Assert.IsAssignableFrom<ElfSymbolTable>(elfFile.Sections[3]);
                ElfSymbolTable symbolTable = elfFile.Sections[3] as ElfSymbolTable;
                foreach (ElfSymbolTableEntry entry in symbolTable)
                {
                    if (entry.Type == ElfSymbolType.File)
                    {
                        ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.TestCodeList.Add(entry.Name.Substring(0, entry.Name.Length - 4));
                    }
                }
                return true;
            }
            catch(Exception ex)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, typeof(CommonUtil).Name + " :: " + ex.Message + " Line :: " + CommonUtil.GetExceptionLineNumber(ex));
                return false;
            }
        }
        /// <summary>
        /// ELF 파일 기반으로 ELF Simbol 추출
        /// [Argument : string  //  Returnvalue : IronPython.Runtime.List]
        /// </summary>
        public static IronPython.Runtime.List GetELFtoSourceSymbol(string elfPath)
        {
            if (elfPath == "")
                return null;

            IronPython.Runtime.List symbollist = new IronPython.Runtime.List();
            var stream = new FileStream(elfPath, FileMode.Open, FileAccess.Read);

            var reader = new EndianBinaryReader(stream, EndianBitConverter.NativeEndianness);
            ElfFile elfFile = ElfFile.ReadElfFile(reader);
                                 
            for(int i = 0; i < elfFile.Sections.Count; i++)
            {
                if(elfFile.Sections[i].GetType().Name == "ElfSymbolTable")
                {
                    ElfSymbolTable symbolTable_temp = elfFile.Sections[i] as ElfSymbolTable;

                    foreach (ElfSymbolTableEntry entry in symbolTable_temp)
                    {
                        if (entry.Type == ElfSymbolType.File)
                            symbollist.Add(entry.Name);
                    }
                    break;
                }
            }
                                 
            //Assert.IsAssignableFrom<ElfSymbolTable>(elfFile.Sections[3]);
            //ElfSymbolTable symbolTable = elfFile.Sections[3] as ElfSymbolTable;
            //foreach (ElfSymbolTableEntry entry in symbolTable)
            //{
            //    if (entry.Type == ElfSymbolType.File)
            //        symbollist.Add(entry.Name);
            //}
            
            return symbollist;
        }
        /// <summary>
        /// 해당 경로가 폴더인지 체크
        /// [Argument : string  //  Returnvalue : int]
        /// </summary>
        public static int IsDirectory(string path)
        {
            if (!File.Exists(path))
            {
                if (!Directory.Exists(path))
                    return Common.Common.NOT_EXIST;
            }

            FileAttributes fa = File.GetAttributes(path);
            if ((fa & FileAttributes.Directory) != 0)
                return Common.Common.FOLDER;
            else
                return Common.Common.FILE;
        }
        /// <summary>
        /// Clear Folder and Clear Sub Folder
        /// [Argument : string  //  Returnvalue : void]
        /// </summary>
        public static void ClearAttributes(string currentDir)
        {
            if (Directory.Exists(currentDir))
            {
                DirectoryInfo di = new DirectoryInfo(currentDir);

                foreach (DirectoryInfo dir in di.GetDirectories())
                {
                    ClearAttributes(dir.FullName);
                    dir.Delete();
                }
                foreach (FileInfo file in di.GetFiles())
                    file.Delete();
            }
        }
        /// <summary>
        /// 해당경로의 폴더가 없을 경우 상위폴더를 생성
        /// [Argument : string  //  Returnvalue : bool]
        /// </summary>
        public static bool CreateDirectoryRecursively(string path)
        {
            try
            {
                string[] pathParts = path.Split('\\');
                for (var i = 0; i < pathParts.Length; i++)
                {
                    // Correct part for drive letters
                    if (i == 0 && pathParts[i].Contains(":"))
                    {
                        pathParts[i] = pathParts[i] + "\\";
                    } // Do not try to create last part if it has a period (is probably the file name)
                    else if (i == pathParts.Length - 1 && pathParts[i].Contains("."))
                    {
                        return true;
                    }
                    if (i > 0)
                    {
                        pathParts[i] = Path.Combine(pathParts[i - 1], pathParts[i]);
                    }
                    if (!Directory.Exists(pathParts[i]))
                    {
                        Directory.CreateDirectory(pathParts[i]);

                        string ConvertRelativePath = "";
                        IncludePathModel includePathmodel = new IncludePathModel();
                        includePathmodel.AbsolutePath = pathParts[i];

                        if(pathParts[i].Contains(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath))
                            ConvertRelativePath = pathParts[i].Replace(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\","$(workspace_loc)" + @"\");
                        
                        includePathmodel.RelativePath = ConvertRelativePath;
                        ViewModelLocator.TargetSWSettingVM.AddIncludeModel(includePathmodel);
                    }
                }
                return true;
            }
            catch (Exception ex)
            {
                return false;
            }

        }
        public static bool IsHex(IEnumerable<char> chars)
        {
            bool isHex;
            foreach (var c in chars)
            {
                isHex = ((c >= '0' && c <= '9') ||
                         (c >= 'a' && c <= 'f') ||
                         (c >= 'A' && c <= 'F'));

                if (!isHex)
                    return false;
            }
            return true;
        }
        public static string GetRelativeToAbsolutePath(string path)
        {
            string convertPath = path;
            if (path.Equals("$(workspace_loc)"))
                convertPath = ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath;
            else if (path.Contains("$(workspace_loc)"))
                convertPath = path.Replace("$(workspace_loc)", ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath);

            return convertPath;
        }

        public static string GetAbsoluteToRelativePath(string path)
        {
            string convertPath = path;
            if (path.Equals(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath))
                convertPath = "$(workspace_loc)";
            else if (path.Contains(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath))
                convertPath = path.Replace(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath, "$(workspace_loc)");

            return convertPath;
        }
        private static readonly Regex _regex = new Regex("[^0-9.-]+"); //regex that matches disallowed text
        public static bool IsTextAllowed(string text)
        {
            return !_regex.IsMatch(text);
        }
        public static string GetFreeFileNumber(string path)
        {
            string pathOnly = path.Substring(0, path.LastIndexOf('\\') + 1);
            string nameOnly = Path.GetFileNameWithoutExtension(path);
            string extOnly = Path.GetExtension(path);
            string[] files = Directory.GetFiles(pathOnly, nameOnly + "*" + extOnly);
            if (files.Length == 0)
                return "";
            int largest = files.Max(f => GetFileNumber(f));
            return string.Format("{0}{1}{2}{3}", pathOnly, nameOnly, largest + 1, extOnly);
        }
        public static Regex fileNumber = new Regex("\\d+$", RegexOptions.Compiled);
        public static int GetFileNumber(string file)
        {
            Match m = fileNumber.Match(Path.GetFileNameWithoutExtension(file));
            if (!m.Success) return 0;
            return int.Parse(m.Value);
        }

    }

}
