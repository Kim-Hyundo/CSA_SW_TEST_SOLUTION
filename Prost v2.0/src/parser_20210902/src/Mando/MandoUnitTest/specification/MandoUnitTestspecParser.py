from lib.TestspecParser import *
import copy, decimal, os
import importlib.machinery

class MandoUnitTestspecParser(TestspecParser):

    def __init__(self, parameter_path):
        parameter = self.get_parameter(parameter_path)
        super().__init__(parameter, self.test_spec_format_convert, self.create_test_loc_info,self.test_spec_parser,"all","Unit", 1)
        self.col_lines = {'Start_Idx': [2, 2], 'End_Idx': [2, 10]}

    @Logdeco
    def user_script_parser(self, data_dump):
        try:
            if len(data_dump) == 0:
                set_log('PARSE', "Test User Script Sheet is empty..." + str(e), log_mod.Logtype_INF)
                return

            total_row_cnt = len(data_dump)

            start_row_idx = 1
            start_col_idx = 0

            end_col_idx = 3

            for row_idx in range(start_row_idx, total_row_cnt):
                row_tmp = data_dump[row_idx]

                script_name = row_tmp[0].strip()
                contents = row_tmp[1].strip()
                comment = row_tmp[2].strip()

                if script_name == "None" or script_name == "":
                    continue

                script_name += ".cmm"

                for col_idx in range(start_col_idx, end_col_idx):
                    set_log('PARSE', "Row : " + str(row_idx) + "Col : " + str(
                        col_idx) + " Parsing Complete..." + "Data = " + str(row_tmp[col_idx]), log_mod.Logtype_INF)

                if comment != "None" and comment != "":
                    contents = "//" + comment + "\n" + contents

                if not super().isdir(self.user_cmm_path):
                    os.makedirs(self.user_cmm_path)

                save_path = self.user_cmm_path + script_name
                super().txt_file_write(save_path, list(contents), 'w')

                set_log('PARSE', "User Script Save Complete... " + script_name , log_mod.Logtype_INF)

        except Exception as e:
            set_log('PARSE', "Test User Script Parsing Error" + str(e), log_mod.Logtype_ERR)
            raise

    @Logdeco
    def macro_script_parser(self, data_dump):
        try:
            if len(data_dump) == 0:
                set_log('PARSE', "Test Macro Script Sheet is empty..." + str(e), log_mod.Logtype_INF)
                return

            row_tmp = data_dump[1]

            enum_data = row_tmp[0].strip()

            if enum_data == "None" or enum_data == "":
                return

            set_log('PARSE', "Row : " + str(1) + "Col : " + str(
                0) + " Parsing Complete..." + "Data = " + str(enum_data), log_mod.Logtype_INF)

            save_path = self.cmm_template_path + "enum_macro.cmm"
            super().txt_file_write(save_path, enum_data, 'w')

            set_log('PARSE', "User Script Save Complete... " + str(enum_data), log_mod.Logtype_INF)

        except Exception as e:
            set_log('PARSE', "Test Macro Script Parsing Error" + str(e), log_mod.Logtype_ERR)
            raise

    @Logdeco
    def test_spec_parser(self, all_data):
        test_info = {}
        precond_info = []
        spec_data = []
        spec_sheet = ""
        is_ok = False

        try:
            for sheet_name in all_data.keys():
                if "Test Cases" in sheet_name:
                    spec_sheet = sheet_name
                    is_ok = True
                elif "PRECONDITION" in sheet_name.upper():
                    self.user_script_parser(all_data[sheet_name])
                elif "USER MACRO INPUT" in sheet_name.upper():
                    self.user_script_parser(all_data[sheet_name])
                elif "USER MACRO OUTPUT" in sheet_name.upper():
                    self.user_script_parser(all_data[sheet_name])
                elif "ENUM MACRO" in sheet_name.upper():
                    self.macro_script_parser(all_data[sheet_name])

            if not is_ok:
                raise

            spec_data = all_data[spec_sheet]
            total_row_cnt = len(spec_data)

            start_row = self.col_lines['Start_Idx']
            start_row_idx = start_row[0] - 1
            start_col_idx = start_row[1] - 2

            end_row = self.col_lines['End_Idx']
            end_col_idx = end_row[1]

            col_name_line = spec_data[start_row_idx]

            for row_idx in range(start_row_idx + 1, total_row_cnt):
                row_tmp = spec_data[row_idx]
                dict_tmp = {}
                scenario_name = ""
                tc_traceability = ""
                tc_description = ""
                tc_function = ""
                tc_method = ""
                is_ok = True
                in_out_flag = False

                for col_idx in range(start_col_idx, end_col_idx):
                    col_name = col_name_line[col_idx]
                    col_name.strip()
                    item_tmp = row_tmp[col_idx]
                    item_tmp.strip()
                    set_log('PARSE', "Row : " + str(row_idx) + "Col : " + str(
                        col_idx) + " Parsing Complete..." + "Data = " + str(item_tmp), log_mod.Logtype_INF)

                    if col_idx == start_col_idx:
                        testable = str(item_tmp).strip()
                        dict_tmp['Testable'] = testable.upper()

                        if dict_tmp['Testable'] != "O":
                            break

                    if not item_tmp:
                        if item_tmp != 0 or item_tmp is None:
                            continue

                    if "TEST CASE ID" in col_name.upper():
                        scenario_name = str(item_tmp)
                        if scenario_name == "" or scenario_name == "None" or scenario_name == None:
                            is_ok = False
                            break

                        if not scenario_name in test_info.keys():
                            if scenario_name == "":
                                raise
                            test_info[scenario_name] = []

                    elif "TEST DESCRIPTION" in col_name.upper():
                        tc_description = str(item_tmp)
                    elif "DERIVATION METHOD" in col_name.upper():
                        tc_title_name = str(item_tmp)
                    elif "TEST FUNCTION" in col_name.upper():
                        tc_function = str(item_tmp)
                    elif "PRECONDITION" in col_name.upper():
                        precon_dic = super().next_line_equal_split(item_tmp, "=")
                        if not precon_dic:
                            precond_info.append({scenario_name: "NONE"})
                        else:
                            precond_info.append({scenario_name: precon_dic})
                    elif "INPUT DATA" in col_name.upper() or "EXPECTED DATA" in col_name.upper():
                        if "Refer to" in item_tmp:
                            if in_out_flag:
                                continue
                            item_tmp = item_tmp.split('Refer to')
                            test_sheet_name = item_tmp[1].strip()
                            test_sheet = all_data[test_sheet_name]
                            test_case_total = len(test_sheet)
                            inp_list = {}
                            out_list = {}

                            col_loc = {"Time":{}, "Input Data":{}, "Expected Data":{}}
                            tc_col_line = test_sheet[0]
                            data_row = 0
                            for time_row in range(0, test_case_total):
                                tc_col_line = test_sheet[time_row]
                                if tc_col_line[0].strip().upper() == 'TIME':
                                    data_row = time_row + 2
                                    break

                            idx = 0
                            for name in tc_col_line:
                                upper_name = name.upper()
                                if upper_name  == 'TIME':
                                    col_loc['Time']['Start_Idx'] = idx
                                    col_loc['Time']['End_Idx'] = idx
                                elif 'INPUT DATA' in upper_name:
                                    col_loc['Input Data']['Start_Idx'] = idx
                                elif 'EXPECTED DATA' in upper_name:
                                    col_loc['Input Data']['End_Idx'] = idx - 1
                                    col_loc['Expected Data']['Start_Idx'] = idx
                                idx=idx+1

                            col_loc['Expected Data']['End_Idx'] = idx - 1

                            tc_var_line = test_sheet[data_row - 1]  # 변수 이름

                            time_var_lines = col_loc['Time']
                            inp_var_lines = col_loc['Input Data']
                            out_var_lines = col_loc['Expected Data']

                            for idx in range(inp_var_lines['Start_Idx'], inp_var_lines['End_Idx'] + 1):
                                inp_list[idx] = tc_var_line[idx]
                            for idx in range(out_var_lines['Start_Idx'], out_var_lines['End_Idx'] + 1):
                                out_list[idx] = tc_var_line[idx]

                            tc_cnt = 1
                            for row_idx in range(data_row, test_case_total):
                                input_dic = {}
                                output_dic = {}
                                if test_sheet[row_idx][inp_var_lines['Start_Idx']] is None or test_sheet[row_idx][inp_var_lines['Start_Idx']] == "" or test_sheet[row_idx][inp_var_lines['Start_Idx']] == "None":
                                    continue
                                for col_idx in range(time_var_lines['Start_Idx'], time_var_lines['End_Idx'] + 1):
                                    dict_tmp['Time'] = test_sheet[row_idx][col_idx]
                                    if dict_tmp['Time'] == "" or dict_tmp['Time'] == "None" or dict_tmp['Time'] is None:
                                        dict_tmp['Time'] = str(tc_cnt)
                                        tc_cnt = tc_cnt + 1

                                for col_idx in range(inp_var_lines['Start_Idx'], inp_var_lines['End_Idx'] + 1):
                                    input_dic[inp_list[col_idx]] = test_sheet[row_idx][col_idx]
                                for col_idx in range(out_var_lines['Start_Idx'], out_var_lines['End_Idx'] + 1):
                                    output_dic[out_list[col_idx]] = test_sheet[row_idx][col_idx]

                                dict_tmp['Input Data'] = input_dic
                                dict_tmp['Output Data'] = output_dic

                                test_info[scenario_name].append(copy.deepcopy(dict_tmp))

                            in_out_flag = True
                    elif "COMMENTS" in col_name.upper():
                        str_tmp = ""

                        item_split_tmp = item_tmp.split("\n")

                        for tmp in item_split_tmp:
                            str_tmp = str_tmp + tmp + "&&"

                        str_tmp = str_tmp + "||" + tc_function;

                        test_info[scenario_name].insert(0, str_tmp)

                    elif "TOLERANCE" in col_name.upper():
                        pass

                if not is_ok:
                    break

        except Exception as e:
            set_log('PARSE', "Test Spec Parsing Error" + str(e), log_mod.Logtype_ERR)
            raise

        test_info["Precond"] = []
        test_info["Precond"].append(precond_info)

        return test_info


    @Logdeco
    def test_spec_format_convert(self, spec_data):
        new_data_dump = {}

        try:
            scenario_name = ""
            col_list = []
            data_list = []

            for key, value in spec_data.items():
                if scenario_name == "" or scenario_name != key:
                    scenario_name = key
                    comments = value[0]
                    value_tmp = value[1]
                    col_list.clear()
                    data_list.clear()
                    new_data_dump[scenario_name] = []

                    for value_key, value_value in value_tmp.items():
                        if value_key == "Time":
                            col_list.append(value_key)
                            data_list.append(value_value)
                            continue
                        if value_key == "Testable":
                            continue
                        if not value_value:
                            continue

                        for value_value_key, value_value_value in value_value.items():
                            col_list.append(value_value_key)

                    first_line = ['' for _ in range(len(list(col_list)))]
                    first_line[0] = comments
                    new_data_dump[scenario_name].append(first_line)

                    new_data_dump[scenario_name].append(list(col_list))

                    for data in value:
                        if type(data) == type(""):
                            continue

                        data_list.clear()

                        for value_key, value_value in data.items():
                            if value_key == "Time":
                                data_list.append(value_value)
                                continue
                            if value_key == "Testable":
                                continue
                            if not value_value:
                                continue

                            for value_value_key, value_value_value in value_value.items():
                                data_list.append(value_value_value)

                        new_data_dump[scenario_name].append(list(data_list))
                        set_log('PARSE',
                                "new_data_dump[" + str(scenario_name) + "] : " + str(data_list) + " Add Complete...",
                                log_mod.Logtype_INF)
        except Exception as e:
            set_log('PARSE', "Test Spec Converting Error" + str(e), log_mod.Logtype_ERR)
            raise

        return new_data_dump

    @Logdeco
    def create_test_loc_info(self, spec_data):
        test_loc_info = {}
        try:
            for scenario, data in spec_data.items():
                if len(data) == 0:
                    continue
                row = 2
                col = 1

                first_data = data[1]
                end_col = 1
                TestID = {'Start_Idx': [row, col], 'End_Idx': [row, end_col]}
                col = end_col + 1
                end_col = col + len(first_data['Input Data']) - 1
                InputData = {'Start_Idx': [row, col], 'End_Idx': [row, end_col]}
                col = end_col + 1
                end_col = col + len(first_data['Output Data']) - 1
                OutputData = {'Start_Idx': [row, col], 'End_Idx': [row, end_col]}

                test_loc_info[scenario] = {'Test ID': TestID, 'Input Data': InputData, 'Expect Output Data': OutputData}
        except Exception as ex:
            set_log('PARSE', "Test Loc Info Parsing Error" + str(ex), log_mod.Logtype_ERR)
            raise

        return test_loc_info

    @Logdeco
    def get_parameter(self, parameter_path):
        try:
            parameter_info = super().data_pickle_load("[Parameter Load]", parameter_path)

            set_log('PARSE', "Parameter Data : " + str(parameter_info), log_mod.Logtype_INF)

#            parameter_info = {}
#            common_param = {}
#            common_param['WorkingProject_Path'] = r"D:\git\Mando\workspace"
#            common_param['T15_Install_Path'] = r"D:\git\Prost2\Prost v2.0"
#
#            parameter_info['Common_Path'] = common_param
#
#            parser_param = {}
#            parser_param['Test_Spec_Path'] = r"D:\git\Mando\Failsafe-TestSpec_RS4_rev9.xlsx"
#
#            parameter_info['Parser'] = parser_param
#
#            log_param = {}
#            log_param['Log_Level'] = "3"
#
#            parameter_info['Log'] = log_param

            if 'Common_Path' not in parameter_info.keys() or 'Parser' not in parameter_info.keys():
                raise

            common_info = parameter_info['Common_Path']

            if 'WorkingProject_Path' not in common_info.keys() or 'T15_Install_Path' not in common_info.keys():
                raise

            parser_info = parameter_info['Parser']

            if 'Test_Spec_Path' not in parser_info.keys():
                raise

            log_info = parameter_info['Log']

            if 'Log_Level' not in log_info.keys():
                raise

            return parameter_info
        except Exception as ex:
            set_log('PARSE', "Parameter Receive Exception : " + str(ex), log_mod.Logtype_ERR)
            raise
