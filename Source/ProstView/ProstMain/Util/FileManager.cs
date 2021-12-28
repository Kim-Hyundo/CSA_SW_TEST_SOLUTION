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

namespace ProstMain.Util
{
    class FileManager
    {
        /// <summary>
        /// File Save
        /// [Argument : string, string  //  Returnvalue : bool]
        /// </summary>
        public static bool FileSave(string filePath, string txt)
        {
            try
            {
                FileStream fs = new FileStream(filePath, FileMode.Create, FileAccess.Write);

                if (fs == null) return false;

                StreamWriter outputFile = new StreamWriter(fs, System.Text.Encoding.Default);

                outputFile.WriteLine(txt);

                outputFile.Flush();
                outputFile.Close();
                fs.Close();
            }
            catch (Exception exception)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, typeof(FileManager).Name + " :: " + exception.Message + " Line :: " + CommonUtil.GetExceptionLineNumber(exception));
                return false;
            }
            return true;
        }
        /// <summary>
        /// File Save List
        /// [Argument : string, List<string> //  Returnvalue : bool]
        /// </summary>
        public static bool FileSave_List(string filePath, List<string> lines)
        {
            try
            {
                FileStream fs = new FileStream(filePath, FileMode.Create, FileAccess.Write);

                if (fs == null) return false;

                StreamWriter outputFile = new StreamWriter(fs, System.Text.Encoding.Default);

                foreach (string line in lines)
                {
                    outputFile.WriteLine(line);
                }

                outputFile.Flush();
                outputFile.Close();
                fs.Close();
            }
            catch (Exception exception)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, typeof(FileManager).Name + " :: " + exception.Message + " Line :: " + CommonUtil.GetExceptionLineNumber(exception));
                return false;
            }
            return true;
        }
        /// <summary>
        /// File Read
        /// [Argument : string //  Returnvalue : string[]]
        /// </summary>
        public static string[] FileRead(string filePath)
        {
            string[] returnReadData = new string[] { };

            if (!File.Exists(filePath))
            {
                File.WriteAllText(filePath, "");
            }

            try
            {
                returnReadData = File.ReadAllLines(filePath,Encoding.Default);

            }
            catch (Exception exception)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, typeof(FileManager).Name + " :: " + exception.Message + " Line :: " + CommonUtil.GetExceptionLineNumber(exception));
            }

            return returnReadData;
        }
        /// <summary>
        /// File Copy
        /// [Argument : string, string //  Returnvalue : void]
        /// </summary>
        public static void FileCopy(string sourcePath, string DestPath)
        {
            File.Copy(sourcePath, DestPath, true);
        }
        /// <summary>
        /// Directory Copy
        /// [Argument : string, string, bool //  Returnvalue : void]
        /// </summary>
        public static void DirectoryCopy(string sourceDirName, string destDirName, bool copySubDirs)
        {
            DirectoryInfo dir = new DirectoryInfo(sourceDirName);

            if (!dir.Exists)
            {
                throw new DirectoryNotFoundException(
                    "Source directory does not exist or could not be found: "
                    + sourceDirName);
            }

            DirectoryInfo[] dirs = dir.GetDirectories();
            Directory.CreateDirectory(destDirName);

            if (destDirName.Contains(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath))
            {
                IncludePathModel model = new IncludePathModel();
                model.AbsolutePath = destDirName;
                model.RelativePath = "$(workspace_loc)" + destDirName.Replace(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath, "");
                ViewModelLocator.TargetSWSettingVM.AddIncludeModel(model);
            }

/*            FileInfo[] files = dir.GetFiles();
            foreach (FileInfo file in files)
            {
                string temppath = Path.Combine(destDirName, file.Name);
                file.CopyTo(temppath, true);
            }
            if (copySubDirs)
            {
                foreach (DirectoryInfo subdir in dirs)
                {
                    string temppath = Path.Combine(destDirName, subdir.Name);
                    DirectoryCopy(subdir.FullName, temppath, copySubDirs);
                }
            }*/
        }
        /// <summary>
        /// File Compare
        /// </summary>
        public class FileCompare : IEqualityComparer<FileInfo>
        {
            public FileCompare() { }

            public bool Equals(FileInfo f1, FileInfo f2)
            {
                return (f1.Name == f2.Name &&
                        f1.Length == f2.Length);
            }

            public int GetHashCode(FileInfo fi)
            {
                string s = $"{fi.Name}{fi.Length}";
                return s.GetHashCode();
            }
        }

        public static void CopyFolderSourceCode(string SourcePath, string DestinationPath)
        {
            // SourcePath의 IncludePath와 CopyPath를 먼저 추출한다
            IncludePathModel model_1 = new IncludePathModel();
            model_1.AbsolutePath = DestinationPath;
            model_1.RelativePath = "$(workspace_loc)" + DestinationPath.Replace(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath, "");
            ViewModelLocator.TargetSWSettingVM.AddIncludeModel(model_1);

            string ConvertPath = SourcePath;
            if (ConvertPath.Contains(ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceCodeRootPath))
                ConvertPath = SourcePath.Replace(ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceCodeRootPath + "\\", "$(sourcecode_root)" + @"\");
            else if (ConvertPath.Contains(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath))
                ConvertPath = SourcePath.Replace(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\", "$(workspace_loc)" + @"\");

            string convertTargetPath = DestinationPath.Replace(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\", "$(workspace_loc)" + @"\");

            if (!ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.CopyDictionary.ContainsKey(convertTargetPath))
                ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.CopyDictionary.Add(convertTargetPath, ConvertPath);


            // SourcePath의 Sub Dir의 IncludePath와 CopyPath를 추출한다
            foreach (string dirPath in Directory.GetDirectories(SourcePath, "*", SearchOption.AllDirectories))
            {
                ConvertPath = dirPath;
                if (ConvertPath.Contains(ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceCodeRootPath))
                    ConvertPath = dirPath.Replace(ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceCodeRootPath + "\\", "$(sourcecode_root)" + @"\");
                else if (ConvertPath.Contains(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath))
                    ConvertPath = dirPath.Replace(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\", "$(workspace_loc)" + @"\");

                Directory.CreateDirectory(dirPath.Replace(SourcePath, DestinationPath));

                string convertTargetPathFolder = dirPath.Replace(SourcePath, DestinationPath).Replace(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\", "$(workspace_loc)" + @"\");

                if (!ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.CopyDictionary.ContainsKey(convertTargetPathFolder))
                    ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.CopyDictionary.Add(convertTargetPathFolder, ConvertPath);

                string sourcePath = dirPath.Replace(SourcePath, DestinationPath);

                // Sub Dir의 CopyPath는 무조건 Workspace에서 참조되므로 Workspace Location만 판단
                if (sourcePath.Contains(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath))
                {
                    IncludePathModel model = new IncludePathModel();
                    model.AbsolutePath = sourcePath;
                    model.RelativePath = "$(workspace_loc)" + sourcePath.Replace(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath, "");
                    ViewModelLocator.TargetSWSettingVM.AddIncludeModel(model);
                }
            }

            // SourcePath의 Sub Dir을 포함한 File들의 CopyPath를 입력한다
            foreach (string newPath in Directory.GetFiles(SourcePath, "*.*", SearchOption.AllDirectories))
            {
                ConvertPath = newPath;
                if (ConvertPath.Contains(ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceCodeRootPath))
                    ConvertPath = newPath.Replace(ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.SourceCodeRootPath + "\\", "$(sourcecode_root)" + @"\");
                else if (ConvertPath.Contains(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath))
                    ConvertPath = newPath.Replace(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\", "$(workspace_loc)" + @"\");

                File.Copy(newPath, newPath.Replace(SourcePath, DestinationPath), true);

                string convertTargetPathFile = newPath.Replace(SourcePath, DestinationPath).Replace(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\", "$(workspace_loc)" + @"\");

                if (!ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.CopyDictionary.ContainsKey(convertTargetPathFile))
                    ViewModelLocator.TargetSWSettingVM.TargetSWSettingModel.CopyDictionary.Add(convertTargetPathFile, ConvertPath);
            }
        }

    }
}

