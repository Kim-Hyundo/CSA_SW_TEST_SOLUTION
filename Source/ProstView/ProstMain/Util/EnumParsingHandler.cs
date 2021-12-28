﻿using ProstMain.Model;
using ProstMain.ViewModel;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Threading.Tasks;

namespace ProstMain.Util
{
    public class EnumParsingHandler
    {
        List<DefineModel> m_list;
        List<EnumModel> m_enumlist;
        private static class LazyHolder
        {
            public static readonly EnumParsingHandler INSTANCE = new EnumParsingHandler();
        }
        public static EnumParsingHandler getInstance()
        {
            return LazyHolder.INSTANCE;
        }
        public EnumParsingHandler()
        {
            m_enumlist = new List<EnumModel>();
            m_list = new List<DefineModel>();
        }
        public void doParsing()
        {
            List<HeaderFileModel> m_fileList = new List<HeaderFileModel>();
            m_list.Clear();
            m_enumlist.Clear();

            ViewModelLocator.ETCSettingVM.EnumScriptDialogViewContent = "Get Header File Info...";
            foreach (string n in Directory.GetFiles(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Target_SW", "*.h", SearchOption.AllDirectories))
                m_fileList.Add(new HeaderFileModel() { filename = Path.GetFileName(n), filepath = n });

            ViewModelLocator.ETCSettingVM.EnumScriptDialogViewContent = "Read Header Files...";
            foreach (HeaderFileModel model in m_fileList)
            {
                ReadHeaderFile(model.filepath);
            }
            ViewModelLocator.ETCSettingVM.EnumScriptDialogViewContent = "Get Enum Value...";
            foreach (HeaderFileModel model in m_fileList)
            {
                EnumScript(model.filepath);
            }

            ViewModelLocator.ETCSettingVM.EnumScriptDialogViewContent = "Make EnumScript...";
            List<string> SaveEnumList = new List<string>();
            SaveEnumList.Add("B::\n");
            foreach (EnumModel model in m_enumlist)
                SaveEnumList.Add("y.new.macro " + model.valueName + " " + model.value);

            SaveEnumList.Add("ENDDO\n");
            string GenNumPath = ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Temp\\EnumScript.cmm";
            if (File.Exists(GenNumPath))
                GenNumPath = CommonUtil.GetFreeFileNumber(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + "\\" + ViewModelLocator.WorkSpaceVM.WorkSpaceModel.CurrentProjectName + "\\Temp\\EnumScript.cmm");
            FileManager.FileSave_List(GenNumPath, SaveEnumList);

            if (GenNumPath.Contains(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath))
                ViewModelLocator.ETCSettingVM.EnumScriptPath = @"$(workspace_loc)\" + GenNumPath.Replace(ViewModelLocator.WorkSpaceVM.WorkSpaceModel.WorkSpacePath + @"\", "");
            else
                ViewModelLocator.ETCSettingVM.EnumScriptPath = GenNumPath;

            System.Windows.Application.Current.Dispatcher.Invoke(new Action(() =>
            {
                ViewModelLocator.MainVM.MainModel.isDialogOpen = false;
                ViewModelLocator.MainVM.showTrackBarMessage("Create Enum Script..");
                GC.Collect();
                GC.WaitForPendingFinalizers();
            }));
        }
        public void ReadHeaderFile(string path)
        {
            try
            {
                using (var streamReader = File.OpenText(path))
                {
                    var lines = streamReader.ReadToEnd().Split("\r\n".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);

                    bool SkipDefine = false;
                    int index = 1;
                    //foreach (var line in lines)
                    for (int i = 0; i < lines.Length; i++)
                    {
                        ViewModelLocator.ETCSettingVM.EnumScriptDialogViewContent = "Read Header Files line... [" + index + "/" + lines.Length + "]";
                        //                        foreach (string data in readData)
                        //                        {
                        if (lines[i].TrimStart().StartsWith("#if") || lines[i].TrimStart().StartsWith("#elif"))
                        {
                            if (lines[i].TrimStart().StartsWith("#if"))
                            {
                                string[] value = lines[i].Replace("#if", "").Trim().Split(new string[] { "==" }, StringSplitOptions.RemoveEmptyEntries);

                                //foreach (DefineModel m in m_list)
                                for (int j = 0; j < m_list.Count; j++)
                                {
                                    if (m_list[j].valueName.Equals(value[0].Trim()))
                                    {
                                        if (m_list[j].value != value[1].Trim())
                                            SkipDefine = true;
                                        else
                                            SkipDefine = false;
                                    }
                                }
                            }
                            else if (lines[i].TrimStart().StartsWith("#elif"))
                            {
                                string[] value = lines[i].Replace("#elif", "").Trim().Split(new string[] { "==" }, StringSplitOptions.RemoveEmptyEntries);

                                //foreach (DefineModel m in m_list)
                                for (int k = 0; k < m_list.Count; k++)
                                {
                                    if (m_list[k].valueName.Equals(value[0].Trim()))
                                    {
                                        if (m_list[k].value != value[1].Trim())
                                            SkipDefine = true;
                                        else
                                            SkipDefine = false;
                                    }
                                }
                            }
                        }
                        else if (lines[i].TrimStart().StartsWith("#endif"))
                            SkipDefine = false;

                        if (SkipDefine)
                            continue;

                        if (lines[i].TrimStart().StartsWith("#define"))
                        {
                            string[] temp = lines[i].TrimStart().Split(new string[] { " " }, StringSplitOptions.RemoveEmptyEntries);

                            if (temp.Length > 2)
                            {
                                if (!temp[1].Contains("(") && !temp[1].Contains(")") && temp[2] != "")
                                {
                                    Console.WriteLine("Value Name :: " + temp[1]);
                                    m_list.Add(new DefineModel() { valueType = temp[0], valueName = temp[1], value = temp[2] });
                                }
                            }
                        }
                        index++;
                    }
                }

            }
            catch (Exception ex)
            {
                ProstLog.getInstance().Log(Common.Common.MODULE_MAIN_GUI, Common.Common.LOGTYPE_ERR, typeof(EnumParsingHandler).Name + " :: " + ex.Message + " Line :: " + CommonUtil.GetExceptionLineNumber(ex));
            }
        }

        public void EnumScript(string path)
        {
            using (var streamReader = File.OpenText(path))
            {
                var lines = streamReader.ReadToEnd().Split("\r\n".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);

                //string[] readData = File.ReadLines(path).ToArray();
                bool isStartEnum = false;
                bool SkipEnum = false;

                int m_enumIndex = 0;
                foreach (var line in lines)
                {
                    if (line.TrimStart().StartsWith("enum"))
                        isStartEnum = true;
                    else if (isStartEnum)
                    {
                        if (line.TrimStart().StartsWith("#if"))
                        {
                            if (line.Contains("&&") || line.Contains("||"))
                            {
                                MatchCollection matches = Regex.Matches(line, "==");
                                if (matches.Count == 1)  //#if SPEED == ( S_10 || S_20 )
                                {
                                    bool SkipEnum_Flag;
                                    string[] value = line.Replace("#if","").Trim().Split(new string[] { "==" }, StringSplitOptions.RemoveEmptyEntries); ;
                                    value[1] = value[1].Replace("(", "");
                                    value[1] = value[1].Replace(")", "");

                                    string[] temp = value[1].Trim().Split(new string[] { "||" }, StringSplitOptions.RemoveEmptyEntries);
                                    bool[] SkipEnum_flags = new bool[temp.Length];
                                    for (int i = 0; i < temp.Length; i++)
                                    {
                                        DefineModel model = m_list.Where(p => p.valueName.Equals(value[0].Trim())).FirstOrDefault();
                                        if (model.value == temp[i].Trim())
                                            SkipEnum_flags[i] = true;
                                        else
                                            SkipEnum_flags[i] = false;
                                    }

                                    SkipEnum_Flag = SkipEnum_flags[0] || SkipEnum_flags[1];

                                    if (temp.Length > 2)
                                    {
                                        for (int i = 2; i < temp.Length; i++)
                                        {
                                            SkipEnum_Flag = SkipEnum_Flag || SkipEnum_flags[i];
                                        }
                                    }

                                    if (SkipEnum_Flag) //조건에 맞으면
                                        SkipEnum = false;
                                    else
                                        SkipEnum = true;
                                }
                                else
                                {
                                    bool SkipEnum_Flag;
                                    string[] value = line.Replace("#if", "").Trim().Split(new string[] { "&&", "||" }, StringSplitOptions.RemoveEmptyEntries);
                                    int count = value.Length;  //#if안의 조건 갯수 저장
                                    bool[] SkipEnum_flags = new bool[count];
                                    for (int i = 0; i < value.Length; i++)
                                    {
                                        string[] temp = value[i].Trim().Split(new string[] { "==" }, StringSplitOptions.RemoveEmptyEntries);
                                        temp[0] = temp[0].Replace("(", "");
                                        temp[1] = temp[1].Replace(")", "");

                                        DefineModel model = m_list.Where(p => p.valueName.Equals(temp[0].Trim())).FirstOrDefault();
                                        if (model.value == temp[1].Trim())

                                            SkipEnum_flags[i] = true;
                                        else
                                            SkipEnum_flags[i] = false;
                                    }
                                    string[] op_value = line.Replace("#if", "").Replace(" == ", "").Trim().Split(new string[] { " " }, StringSplitOptions.RemoveEmptyEntries);

                                    if (op_value[1] == "&&")
                                        SkipEnum_Flag = SkipEnum_flags[0] && SkipEnum_flags[1];
                                    else if (op_value[1] == "||")
                                        SkipEnum_Flag = SkipEnum_flags[0] || SkipEnum_flags[1];
                                    else
                                        continue;


                                    if (value.Length > 2)
                                    {
                                        int j = 3;
                                        for (int i = 2; i < value.Length; i++)
                                        {
                                            if (op_value[j] == "&&")
                                                SkipEnum_Flag = SkipEnum_Flag && SkipEnum_flags[i];
                                            else if (op_value[j] == "||")
                                                SkipEnum_Flag = SkipEnum_Flag || SkipEnum_flags[i];
                                            else
                                                continue;
                                            j = j + 2;
                                        }
                                    }
                                    if (SkipEnum_Flag) //조건에 맞으면
                                        SkipEnum = false;
                                    else
                                        SkipEnum = true;
                                }
                            }
                            else        //#if (FCA_VER == V_1_1A)  && 조건이나 || 조건 없는 조건문
                            {
                                string[] value = line.Replace("#if", "").Trim().Split(new string[] { "==" }, StringSplitOptions.RemoveEmptyEntries);

                                DefineModel model = m_list.Where(p => p.valueName.Equals(value[0].Trim())).FirstOrDefault();
                                if (model.value == value[1].Trim())
                                    SkipEnum = false;
                                else
                                    SkipEnum = true;
                            }
                        }
                        else if (line.TrimStart().StartsWith("#elif"))
                        {
                            if(line.Contains("&&") || line.Contains("||"))
                            {
                                MatchCollection matches = Regex.Matches(line, "==");
                                if (matches.Count == 1)  //#if SPEED == ( S_10 || S_20 )
                                {
                                    bool SkipEnum_Flag;
                                    string[] value = line.Replace("#elif", "").Trim().Split(new string[] { "==" }, StringSplitOptions.RemoveEmptyEntries); ;
                                    value[1] = value[1].Replace("(", "");
                                    value[1] = value[1].Replace(")", "");

                                    string[] temp = value[1].Trim().Split(new string[] { "||" }, StringSplitOptions.RemoveEmptyEntries);
                                    bool[] SkipEnum_flags = new bool[temp.Length];
                                    for (int i = 0; i < temp.Length; i++)
                                    {
                                        DefineModel model = m_list.Where(p => p.valueName.Equals(value[0].Trim())).FirstOrDefault();
                                        if (model.value == temp[i].Trim())

                                            SkipEnum_flags[i] = true;
                                        else
                                            SkipEnum_flags[i] = false;
                                    }

                                    SkipEnum_Flag = SkipEnum_flags[0] || SkipEnum_flags[1];

                                    if (temp.Length > 2)
                                    {
                                        for (int i = 2; i < temp.Length; i++)
                                        {
                                            SkipEnum_Flag = SkipEnum_Flag || SkipEnum_flags[i];
                                        }
                                    }

                                    if (SkipEnum_Flag) //조건에 맞으면
                                        SkipEnum = false;
                                    else
                                        SkipEnum = true;
                                }
                                else
                                {
                                    bool SkipEnum_Flag;
                                    string[] value = line.Replace("#elif", "").Trim().Split(new string[] { "&&", "||" }, StringSplitOptions.RemoveEmptyEntries);
                                    int count = value.Length;  //#if안의 조건 갯수 저장
                                    bool[] SkipEnum_flags = new bool[count];
                                    for (int i = 0; i < value.Length; i++)
                                    {
                                        string[] temp = value[i].Trim().Split(new string[] { "==" }, StringSplitOptions.RemoveEmptyEntries);
                                        temp[0] = temp[0].Replace("(", "");
                                        temp[1] = temp[1].Replace(")", "");

                                        DefineModel model = m_list.Where(p => p.valueName.Equals(temp[0].Trim())).FirstOrDefault();
                                        if (model.value == temp[1].Trim())

                                            SkipEnum_flags[i] = true;
                                        else
                                            SkipEnum_flags[i] = false;
                                    }
                                    string[] op_value = line.Replace("#elif", "").Replace(" == ", "").Trim().Split(new string[] { " " }, StringSplitOptions.RemoveEmptyEntries);

                                    if (op_value[1] == "&&")
                                        SkipEnum_Flag = SkipEnum_flags[0] && SkipEnum_flags[1];
                                    else if (op_value[1] == "||")
                                        SkipEnum_Flag = SkipEnum_flags[0] || SkipEnum_flags[1];
                                    else
                                        continue;


                                    if (value.Length > 2)
                                    {
                                        int j = 3;
                                        for (int i = 2; i < value.Length; i++)
                                        {
                                            if (op_value[j] == "&&")
                                                SkipEnum_Flag = SkipEnum_Flag && SkipEnum_flags[i];
                                            else if (op_value[j] == "||")
                                                SkipEnum_Flag = SkipEnum_Flag || SkipEnum_flags[i];
                                            else
                                                continue;
                                            j = j + 2;
                                        }
                                    }
                                    if (SkipEnum_Flag) //조건에 맞으면
                                        SkipEnum = false;
                                    else
                                        SkipEnum = true;
                                }
                            }
                            else
                            {
                                string[] value = line.Replace("#elif", "").Trim().Split(new string[] { "==" }, StringSplitOptions.RemoveEmptyEntries);

                                DefineModel model = m_list.Where(p => p.valueName.Equals(value[0].Trim())).FirstOrDefault();
                                if (model.value == value[1].Trim())
                                    SkipEnum = false;
                                else
                                    SkipEnum = true;
                            }

                        }
                        else if (line.TrimStart().StartsWith("#endif"))
                        {
                            SkipEnum = false;
                        }
                        else if (line.TrimStart().StartsWith("}"))
                        {
                            isStartEnum = false;
                            SkipEnum = false;
                            m_enumIndex = 0;
                        }
                        else
                        {
                            if (SkipEnum)
                                continue;

                            string[] temp = line.Split(new string[] { "," }, StringSplitOptions.RemoveEmptyEntries);
                            foreach (string t in temp)
                            {
                                if (t.Contains("//") || t.Trim() == "" || t.Contains("/*"))
                                    continue;

                                string[] temp1 = t.Trim().Split(new string[] { "=" }, StringSplitOptions.RemoveEmptyEntries);
                                /*if (t == "")
                                    continue;*/

                                if (temp1.Length == 1)
                                {
                                    m_enumlist.Add(new EnumModel() { value = m_enumIndex.ToString(), valueName = t.Trim() });
                                    m_enumIndex++;
                                }
                                else
                                {
                                    if (CommonUtil.IsHex(temp1[1].Trim().Replace("0x", "")))
                                    {
                                        m_enumIndex = Convert.ToInt32(temp1[1].Trim());
                                        m_enumlist.Add(new EnumModel() { value = m_enumIndex.ToString(), valueName = temp1[0].Trim().Replace("=", "") });
                                    }

                                    else
                                    {
                                        m_enumlist.Add(new EnumModel() { value = m_enumIndex.ToString(), valueName = t.Trim() });
                                        m_enumIndex++;
                                    }

                                }

                            }
                        }

                    }
                }
            }
        }
        public class DefineModel
        {
            public string valueType;
            public string valueName;
            public string value;
        }
        public class EnumModel
        {
            public string valueName;
            public string value;
        }
        public class HeaderFileModel
        {
            public string filename;
            public string filepath;
            public bool isOpened;
        }
    }
}
