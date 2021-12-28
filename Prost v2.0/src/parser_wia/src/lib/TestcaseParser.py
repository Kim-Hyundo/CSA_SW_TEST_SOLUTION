from lib.Parser import *
import os, copy

class TestcaseParser(Parser):

    def __init__(self, parameter, test_info_parser, test_post_process, test_case_format_convert, test_data_mapping):
        super().__init__()

        self.testcase_file_path = parameter['Parser']['Test_Case_Path']
        self.gen_path = parameter['Common_Path']['WorkingProject_Path']
        self.install_path = parameter['Common_Path']['T15_Install_Path']
        self.cpu_info = parameter['Test_Env']['Test_CPU']
        self.time_flags = parameter['Parser']['Execution_Time']
        #self.elf_path = parameter['Parser']['Elf_Path']
        self.mapping_table_path = parameter['Parser']['MappingTable_Path']
        self.mapping_data_loc = {}
        self.mapping_flag = False
        self.log_level = parameter['Log']['Log_Level']

        self.test_case_save_path = self.gen_path + "\\TestCase\\"
        self.test_info_backup_txt = self.gen_path + "\\TestCase\\test_info_backup.txt"
        self.test_case_list_txt = self.gen_path + "\\TestCase\\test_case_modified_log.txt"
        self.test_loc_info_txt = self.gen_path + "\\TestCase\\test_loc_info.txt"
        self.cmm_sequence_path = self.gen_path + "\\Cmm\\Sequence\\cmm_sequence.txt"
        self.cmm_template_path = self.install_path + "\\src\\parser\\Cmm\\Templete"
        self.user_cmm_path = self.install_path + "\\etc\\UserMacroScript"

        #self.mapping_table_path = self.gen_path + "\\MappingTable"
        self.result_file_path = self.gen_path + "\\parse_result.txt"
        log_mod.G_Log_level = int(self.log_level)

        self.scenario_names = ""
        self.test_info_merge = {}
        self.test_info_merge_orig = {}
        self.cmm_list_merge = {}

        self.test_condition = {}
        self.test_condition['Reset'] = False
        self.test_condition['Pre-Run'] = False
        self.test_condition['Pre-Run Count'] = 0

        self.test_info_parser = test_info_parser
        self.test_post_process = test_post_process
        self.test_case_format_convert = test_case_format_convert
        self.test_data_mapping = test_data_mapping


    @abc.abstractmethod
    def test_info_parser(self, data_dump, test_loc_info, error_list):
        pass

    @abc.abstractmethod
    def get_parameter(self, parameter_path):
        pass

    @Logdeco
    def cmm_sequence_file_create(self, test_info, error_list, script_path, time_measure_flags):
        try:
            if not test_info:
                set_log('PARSE', 'Test Info Data is Empty.', log_mod.Logtype_ERR)
                raise

            cmm_list = {}
            delimeter = ","
            first_flag = True
            tc_name = ""

            for test_info_tmp in test_info:
                tc_name = ""
                inp_var_list = ""
                out_var_list = ""
                input_break_info = ""
                output_break_info = ""
                is_ok = True
                inp_passfail_macro_list = []
                out_passfail_macro_list = []

                for key, value in test_info_tmp.items():
                    if "ID" in key or "Id" in key or "id" in key or "iD" in key:
                        if value in error_list.keys():
                            is_ok = False
                            break
                        tc_name = value
                    if "Input" in key or "INPUT" in key or "input" in key:
                        for value_key, value_value in value.items():
                            if "USER MACRO" in value_key.upper():
                                inp_passfail_macro_list.append(value_value.split("\n"))
                                continue
                            inp_var_list += value_key + "=" + str(value_value) + delimeter
                    if "Output" in key or "OUTPUT" in key or "output" in key:
                        for value_key, value_value in value.items():
                            if "USER MACRO" in value_key.upper():
                                out_passfail_macro_list.append(value_value.split("\n"))
                                continue
                            out_var_list += value_key + "=" + str(value_value) + delimeter
                    if "Break" in key or "BREAK" in key or "break" in key:
                        input_break_info = value["Input_Break_point"]
                        output_break_info = value["Output_Break_point"]

                if not is_ok:
                    continue

                cmm_list[tc_name] = []

                if first_flag:
                    if self.test_condition["Reset"]:
                        cmm_list[tc_name].append("system.RESetTarget")
                        cmm_list[tc_name].append("go main_core0")

                    if self.test_condition["Pre-Run"]:
                        for i in range(self.test_condition["Pre-Run Count"]):
                            cmm_list[tc_name].append("CD.DO \"" + script_path + "\\go.cmm\" " + input_break_info + "\n")

                    cmm_list[tc_name].append("CD.DO \"" + script_path + "\\go.cmm\" " + input_break_info + "\n")
                    if time_measure_flags == "TRUE":
                        cmm_list[tc_name].append("CD.DO \"" + script_path + "\\stm_save.cmm\" " + self.cpu_info + "\n")
                    first_flag = False

                if len(inp_passfail_macro_list) != 0:
                    for macro in inp_passfail_macro_list:
                        for macro_tmp in macro:
                            macro_tmp = macro_tmp.strip()
                            script_cmd_tmp = macro_tmp + ".cmm\""
                            if "(" in macro_tmp:
                                script_cmd_tmp = macro_tmp[:macro_tmp.find('(')] + ".cmm\""
                                macro_tmp = macro_tmp[macro_tmp.find('(') + 1: macro_tmp.rfind(')')]
                                gwalho_cnt = macro_tmp.count('(')
                                gwalho_idx = 0
                                for idx in range(0, gwalho_cnt):
                                    start_idx = macro_tmp.find('(', gwalho_idx)
                                    end_idx =  macro_tmp.find(')', gwalho_idx + 1)
                                    g_tmp = macro_tmp[start_idx: end_idx + 1]
                                    g_tmp = g_tmp.replace(",", "#")
                                    macro_tmp = macro_tmp.replace(macro_tmp[start_idx: end_idx + 1], g_tmp)

                                macro_tmp_split = macro_tmp.split(",")
                                for tmp in macro_tmp_split:
                                    tmp = tmp.replace("#", ",")
                                    script_cmd_tmp += " " + tmp.strip()

                            if "DUMMY" in script_cmd_tmp:
                                cmm_list[tc_name].append("CD.DO \"" + script_path + "\\" + script_cmd_tmp + "\"\n")
                            else:
                                cmm_list[tc_name].append("CD.DO \"" + self.user_cmm_path + "\\" + script_cmd_tmp + "\n")

                if inp_var_list != "":
                    cmm_list[tc_name].append("CD.DO \"" + script_path + "\\write.cmm\" " + inp_var_list + "\n")

                cmm_list[tc_name].append("CD.DO \"" + script_path + "\\go.cmm\" " + output_break_info + "\n")

                if len(out_passfail_macro_list) != 0:
                    for macro in out_passfail_macro_list:
                        for macro_tmp in macro:
                            if "==" in macro_tmp:
                                macro_tmp = macro_tmp[:macro_tmp.find('==')]
                            macro_tmp = macro_tmp.strip()
                            script_cmd_tmp = macro_tmp + ".cmm\""
                            if "(" in macro_tmp:
                                script_cmd_tmp = macro_tmp[:macro_tmp.find('(')] + ".cmm\""
                                macro_tmp = macro_tmp[macro_tmp.find('(') + 1: macro_tmp.rfind(')')]
                                gwalho_cnt = macro_tmp.count('(')
                                gwalho_idx = 0
                                for idx in range(0, gwalho_cnt):
                                    start_idx = macro_tmp.find('(', gwalho_idx)
                                    end_idx = macro_tmp.find(')', gwalho_idx + 1)
                                    g_tmp = macro_tmp[start_idx: end_idx + 1]
                                    g_tmp = g_tmp.replace(",", "#")
                                    macro_tmp = macro_tmp.replace(macro_tmp[start_idx: end_idx + 1], g_tmp)

                                macro_tmp_split = macro_tmp.split(",")
                                for tmp in macro_tmp_split:
                                    tmp = tmp.replace("#", ",")
                                    script_cmd_tmp += " " + tmp.strip()
                            if "DUMMY" in script_cmd_tmp:
                                cmm_list[tc_name].append("CD.DO \"" + script_path + "\\" + script_cmd_tmp + "\"\n")
                            else:
                                cmm_list[tc_name].append("CD.DO \"" + self.user_cmm_path + "\\" + script_cmd_tmp + "\n")

                set_log('PARSE', "test_info_tmp : " + str(test_info_tmp) + " Add Complete...", log_mod.Logtype_INF)

        except Exception as ex:
            set_log('PARSE', 'Test Info Data is Empty.', log_mod.Logtype_ERR)
            raise

        return cmm_list

    @Logdeco
    def do_parsing(self):
        try:
            excel = win32com.client.Dispatch("Excel.Application")
            if ".XLSX" in self.testcase_file_path or ".XLS" in self.testcase_file_path or ".xlsx" in self.testcase_file_path or ".xls" in self.testcase_file_path:
                self.scenario_names = excel_read_sheetnames(self.testcase_file_path, excel)
            ##############################################  Test Parsing location Detect ############################################
            test_loc_info = super().data_pickle_load("[Test Location Info Load]", self.test_loc_info_txt)

            #Tolerance = {'Start_Idx': [row, col], 'End_Idx': [row, end_col]}

            mapping_data = []
            if os.path.isfile(self.mapping_table_path):
                mapping_data = excel_read(self.mapping_table_path, "default", excel)
                if mapping_data is not None:
                    self.mapping_flag = True

            for sheet_name in self.scenario_names:
                if sheet_name not in test_loc_info.keys():
                    continue

                data_dump = excel_read(self.testcase_file_path, sheet_name, excel)

                if super().is_empty(data_dump):
                    set_log('PARSE', "Excel read data is empty!", log_mod.Logtype_ERR)
                    raise

                set_log('PARSE', 'Excel File Read Complete...', log_mod.Logtype_PRG)

                ##############################################  Test Case Parsing &  Save ############################################

                set_log('PARSE', 'Test Data Extracting...', log_mod.Logtype_PRG)

                error_list = {}

                test_info = self.test_info_parser(data_dump, test_loc_info[sheet_name], error_list)
                test_info = self.test_post_process(test_info)
                self.test_info_merge_orig[sheet_name] = copy.deepcopy(test_info)

                if self.mapping_flag:
                    test_info = self.test_data_mapping(test_info, mapping_data)

                self.test_info_merge[sheet_name] = test_info

                set_log('PARSE', 'Test Data Extracting Complete...', log_mod.Logtype_PRG)

                ############################################### CMM Script File Create ########################################

                set_log('PARSE', 'Cmm Sequence Generating...', log_mod.Logtype_PRG)

                cmm_list = self.cmm_sequence_file_create(test_info, error_list, self.cmm_template_path, self.time_flags)
                self.cmm_list_merge[sheet_name] = cmm_list

                set_log('PARSE', 'Cmm Sequence Generating Complete...', log_mod.Logtype_PRG)

                super().data_pickle_save("[Test Info Merge Data]", self.test_info_merge_orig, self.test_info_backup_txt, True)

                super().data_pickle_save("[Cmm List Merge Data]", self.cmm_list_merge, self.cmm_sequence_path, True)

            final_data = {'Test_Info': self.test_info_merge, 'Test_Sequence': self.cmm_list_merge}

            super().data_pickle_save("[Final Data]", final_data, self.result_file_path, True)

            if self.mapping_flag:
                self.test_info_merge = self.test_case_format_convert(self.test_info_merge_orig)

                for sheet_name in self.scenario_names:
                    if sheet_name not in test_loc_info.keys():
                        continue

                    test_case_filename_split = self.testcase_file_path.split("\\")
                    name_only = test_case_filename_split[len(test_case_filename_split) - 1]
                    save_file_name = "mapped_" + name_only
                    if len(self.test_case_save_path + save_file_name) >= 217:
                        set_log('PARSE', 'Save File Path too long...', log_mod.Logtype_ERR)
                        raise

                    #excel_write(self.test_case_save_path + save_file_name, sheet_name, self.test_info_merge_orig[sheet_name], 1, excel)

            set_log('PARSE', 'Result Data = ' + str(final_data), log_mod.Logtype_INF)

            set_log('PARSE', 'TestCase Parsing Complete...', log_mod.Logtype_PRG)
            excel.Quit()
        except Exception as ex:
            set_log('PARSE', 'Exception Error : ' + str(ex), log_mod.Logtype_ERR)
            raise
