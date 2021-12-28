from lib.TestcaseParser import *
import copy, decimal

class MandoUnitTestcaseParser(TestcaseParser):

    def __init__(self, parameter_path):
        parameter = self.get_parameter(parameter_path)
        super().__init__(parameter, self.test_info_parser, self.test_post_process, self.test_case_format_convert, self.test_data_mapping)

        self.min_diff = parameter['Parser']['Min_Diff']
        self.break_point = "Check_Point"
        self.test_condition["Reset"] = False
        self.test_condition["Pre-Run"] = False
        self.var_type_dict = {}
        self.var_type_dict["INT8"] = [-128, 127]
        self.var_type_dict["SIGNED INT8"] = [-128, 127]
        self.var_type_dict["UINT8"] = [0, 255]
        self.var_type_dict["UNSIGNED INT8"] = [0, 255]
        self.var_type_dict["CHAR"] = [-128, 127]
        self.var_type_dict["SIGNED CHAR"] = [-128, 127]
        self.var_type_dict["UNSIGNED CHAR"] = [0, 255]
        self.var_type_dict["INT16"] = [-32768, 32767]
        self.var_type_dict["SIGNED INT16"] = [-32768, 32767]
        self.var_type_dict["UINT16"] = [0, 65535]
        self.var_type_dict["UNSIGNED INT16"] = [0, 65535]
        self.var_type_dict["INT"] = [-2147483648, 2147483647]
        self.var_type_dict["SIGNED INT"] = [-2147483648, 2147483647]
        self.var_type_dict["SIGNED INT32"] = [-2147483648, 2147483647]
        self.var_type_dict["INT32"] = [-2147483648, 2147483647]
        self.var_type_dict["UINT32"] = [0, 4294967296]
        self.var_type_dict["UNSIGNED INT32"] = [0, 4294967296]
        self.var_type_dict["UNSIGNED INT"] = [0, 4294967296]
        self.var_type_dict["LONG"] = [-2147483648, 2147483647]
        self.var_type_dict["SIGNED LONG"] = [-2147483648, 2147483647]
        self.var_type_dict["UNSIGNED LONG"] = [0, 4294967296]
        self.var_type_dict["SHORT"] = [-32768, 32767]
        self.var_type_dict["SIGNED SHORT"] = [-32768, 32767]
        self.var_type_dict["UNSIGNED SHORT"] = [0, 65535]

        self.var_type_dict["SHORT INT"] = [-32768, 32767]
        self.var_type_dict["SHORT SIGNED INT"] = [-32768, 32767]
        self.var_type_dict["SHORT UNSIGNED INT"] = [0, 65535]

        self.var_type_dict["LONG INT"] = [-2147483648, 2147483647]
        self.var_type_dict["LONG SIGNED INT"] = [-2147483648, 2147483647]
        self.var_type_dict["LONG UNSIGNED INT"] = [0, 4294967296]


    @Logdeco
    def test_info_parser(self, data, test_loc_info, error_list):
        test_info = []
        try:
            if super().is_empty(data) or super().is_empty(test_loc_info):
                set_log('PARSE', 'Test Data is empty', log_mod.Logtype_ERR)
                raise

            total_row_cnt = len(data)
            start_loc = test_loc_info['Test ID']['Start_Idx']
            start_row_idx = start_loc[0] - 1

            comments = data[0][0]
            prev_id = "-2"
            if comments != "":
                comments_split_tmp = comments.split("||")
                self.func_name = comments_split_tmp[1].strip()
                comments_split = comments_split_tmp[0].split("&&")
                for tmp in comments_split:
                    tmp = tmp.strip()
                    if 'ECU reset before start' in tmp:
                        self.test_condition["Reset"] = True
                    if 'pre-run' in tmp:
                        self.test_condition["Pre-Run"] = True
                        pre_run_tmp = tmp.split(":")

                        if len(pre_run_tmp) < 2:
                            raise

                        pre_run_cnt = int(pre_run_tmp[1])
                        self.test_condition["Pre-Run Count"] = pre_run_cnt
                        if pre_run_cnt == 0:
                            self.test_condition["Pre-Run"] = False

            curr_id = "-1"
            new_wcet_data_cnt = 0.0
            first = True
            for row_idx in range(start_row_idx + 1, total_row_cnt):
                row_tmp = data[row_idx]
                dict_tmp = {}
                is_ok = True
                for key, value in test_loc_info.items():
                    start_row_tmp = value['Start_Idx'][0] - 1
                    start_col_tmp = value['Start_Idx'][1] - 1
                    end_col_tmp = value['End_Idx'][1]

                    dict_tmp[key] = {}
                    for col_idx in range(start_col_tmp, end_col_tmp):
                        item_tmp = row_tmp[col_idx]

                        set_log('PARSE', "Row : " + str(row_idx) + "Col : " + str(col_idx) + " Parsing Complete...",
                                log_mod.Logtype_INF)

                        if not item_tmp and "Expect Output Data" not in key:
                            if item_tmp != 0 or item_tmp is None:
                                is_ok = False
                                if curr_id != "-1":
                                    error_list[str(curr_id)] = "ERROR LINE (Data Error)"
                                break

                        if key == "Test ID":
                            curr_id = item_tmp
                            if prev_id == curr_id:
                                set_log('PARSE', 'Parsing Exception ' + "ID duplicate error!", log_mod.Logtype_ERR)
                                raise

                            prev_id = curr_id
                            dict_tmp[key] = str(item_tmp)
                            continue

                        item_tmp = str(item_tmp)

                        col_name = data[start_row_tmp][col_idx]
                        if "|" in col_name:
                            col_name_tmp = col_name.split("|")
                            if len(col_name_tmp) == 2:
                                col_name = col_name_tmp[1].strip()

                        if "|" in item_tmp:
                            item_tmp_tmp = item_tmp.split("|")
                            if len(item_tmp_tmp) == 2:
                                item_tmp = item_tmp_tmp[1].strip()

                        if "USER MACRO" in col_name.upper():
                            col_name = col_name.upper()

                        dict_tmp[key][col_name] = item_tmp

                    if not is_ok:
                        break

                if is_ok:
                    dict_tmp['Break Info'] = {'Input_Break_point': self.break_point,
                                              'Output_Break_point': self.break_point}
                    if first:
                        id_tmp = decimal.Decimal(curr_id)
                        if id_tmp != 0:
                            zero_tmp = copy.deepcopy(dict_tmp)
                            zero_tmp["Test ID"] = "0.0"
                            inp_tmp = zero_tmp["Input Data"]
                            out_tmp = zero_tmp["Expect Output Data"]
                            for key in inp_tmp.keys():
                                if "USER MACRO" in key.upper():
                                    inp_tmp[key] = "DUMMY"
                                else:
                                    inp_tmp[key] = "0"
                            for key in out_tmp.keys():
                                if "USER MACRO" in key.upper():
                                    out_tmp[key] = "DUMMY"
                                else:
                                    out_tmp[key] = "0"
                            zero_tmp["Input Data"] = inp_tmp
                            zero_tmp["Expect Output Data"] = out_tmp
                            zero_tmp["AutoGen"] = False
                            test_info.append(zero_tmp)
                        first = False

                    dict_tmp["AutoGen"] = True
                    dict_tmp["Test ID"] = str(decimal.Decimal(dict_tmp["Test ID"]) + decimal.Decimal(new_wcet_data_cnt))

                    wcet_result_list = self.wcet_test_case_add(dict_tmp)
                    wcet_result_list_cnt = len(wcet_result_list)
                    new_wcet_data_cnt = new_wcet_data_cnt + wcet_result_list_cnt

                    if wcet_result_list_cnt != 0:
                        for idx, wcet_data_tmp in enumerate(wcet_result_list):
                            wcet_data_tmp["Test ID"] = str(decimal.Decimal(wcet_data_tmp["Test ID"]) + idx)
                            test_info.append(copy.deepcopy(wcet_data_tmp))
                    else:
                        test_info.append(dict_tmp)
        except Exception as ex:
            set_log('PARSE', 'Parsing Exception ' + str(ex), log_mod.Logtype_ERR)
            raise

        return test_info

    @Logdeco
    def wcet_dfs(self, new_wcet_data, dict_tmp, inp_wcet_list, depth):
        if len(inp_wcet_list) == 0:
            return

        if depth >= len(inp_wcet_list):
            new_wcet_data.append(copy.deepcopy(dict_tmp))
            return

        var_names = list(inp_wcet_list.keys())
        datas = list(inp_wcet_list.values())
        for i in range(0, len(datas[depth])):
            dict_tmp["Input Data"][var_names[depth]] = datas[depth][i]
            self.wcet_dfs(new_wcet_data, dict_tmp, inp_wcet_list, depth + 1)
        return


    @Logdeco
    def wcet_test_case_add(self, dict_tmp):
        data_tmp = copy.deepcopy(dict_tmp)

        inp_wcet_list = {}
        new_wcet_data = []
        inp_wcet_tmp = data_tmp["Input Data"]

        try:
            for key in inp_wcet_tmp.keys():
                if "USER MACRO" not in key.upper():
                    if inp_wcet_tmp[key][0] == "[" and inp_wcet_tmp[key][len(inp_wcet_tmp[key]) - 1] == "]":
                        inp_data_tmp = inp_wcet_tmp[key][1:len(inp_wcet_tmp[key]) - 1]
                        inp_data_split = inp_data_tmp.split(",")
                        if len(inp_data_split) >= 2:
                            if "~" in inp_data_split[0]:
                                inp_range_split = inp_data_split[0].split("~")
                                start_value = decimal.Decimal(inp_range_split[0].strip())
                                end_value = decimal.Decimal(inp_range_split[1].strip())
                                interval_value = decimal.Decimal(inp_data_split[1].strip())

                                range_list = []
                                range_list.append(start_value)
                                mid_value_tmp = start_value

                                while True:
                                    mid_value_tmp = mid_value_tmp + interval_value

                                    if mid_value_tmp >= end_value:
                                        break

                                    range_list.append(mid_value_tmp)

                                range_list.append(end_value)
                                inp_wcet_list[key] = copy.deepcopy(range_list)
                            elif inp_data_split[0].upper() in self.var_type_dict.keys() or inp_data_split[0].upper() == "AUTOTYPE":
                                if inp_data_split[0].upper() == "AUTOTYPE":
                                    func_map, global_map, type_map, global_access_map = process_file("")
                                    start_value = self.var_type_dict[inp_data_split[0].upper()][0]
                                    end_value = self.var_type_dict[inp_data_split[0].upper()][1]
                                    mid_value = (start_value + end_value) / 2
                                else:
                                    start_value = self.var_type_dict[inp_data_split[0].upper()][0]
                                    end_value = self.var_type_dict[inp_data_split[0].upper()][1]
                                    mid_value = (start_value + end_value) / 2

                                if inp_data_split[1].upper().strip() == "BOUNDARY":
                                    interval_value = 1
                                    interval_cnt = int(inp_data_split[2].strip())

                                    boundary_list = []
                                    boundary_list.append(start_value)

                                    idx = 0

                                    for i in range(1,  interval_cnt + 1):
                                        boundary_list.append(start_value + (interval_value * i))

                                    boundary_list.append(mid_value)

                                    for i in range(1,  interval_cnt + 1):
                                        boundary_list.append(end_value - (interval_value * i))

                                    boundary_list.append(end_value)
                                    inp_wcet_list[key] = copy.deepcopy(boundary_list)
                                else:
                                    interval_value = int(inp_data_split[1].strip())

                                    type_range_list = []
                                    type_range_list.append(start_value)
                                    mid_value_tmp = start_value

                                    while True:
                                        mid_value_tmp = mid_value_tmp + interval_value

                                        if mid_value_tmp >= end_value:
                                            break

                                        type_range_list.append(mid_value_tmp)

                                    type_range_list.append(end_value)
                                    inp_wcet_list[key] = copy.deepcopy(type_range_list)

            self.wcet_dfs(new_wcet_data, data_tmp, inp_wcet_list, 0)
        except Exception as ex:
            set_log('PARSE', 'Parsing Exception ' + str(ex), log_mod.Logtype_ERR)
            raise

        return new_wcet_data

    @Logdeco
    def test_case_format_convert(self, test_data):
        pass

    @Logdeco
    def test_post_process(self, test_info):
        return self.min_diff_add(test_info, self.min_diff, "Test ID")

    @Logdeco
    def test_data_mapping(self, test_info, mapping_data):
        pass

    @Logdeco
    def min_diff_add(self, test_info, min_diff, item_name):
        if min_diff == "0" or min_diff == "0.0" or min_diff == "0.00":
            return test_info

        try:
            new_data_set = []

            min_diff = decimal.Decimal(str(min_diff))
            prev_row = {}

            for idx, data in enumerate(test_info):
                curr_row = data
                if idx == 0:
                    prev_row = curr_row
                    continue

                prev_time = decimal.Decimal(str(prev_row[item_name]))
                curr_time = decimal.Decimal(str(curr_row[item_name]))

                diff_value = curr_time - prev_time
                time_mok = diff_value / min_diff
                time_nmg = diff_value % min_diff

                if time_mok >= 2 and time_nmg == 0:
                    middle_row = copy.deepcopy(prev_row)
                    inout_var_tmp = {"Input Data": {}, "Expect Output Data": {}}
                    for key, value in middle_row.items():
                        if key == "Input Data" or key == "Expect Output Data":
                            for value_key, value_value in middle_row[key].items():
                                curr_value = curr_row[key][value_key]
                                inout_var_tmp[key][value_key] = (decimal.Decimal(curr_value) - decimal.Decimal(
                                    value_value)) / time_mok

                    for i in range(1, int(time_mok)):
                        new_new_row = copy.deepcopy(middle_row)
                        next_time = prev_time + (i * min_diff)
                        new_new_row[item_name] = str(next_time)
                        for key, value in inout_var_tmp["Input Data"].items():
                            new_new_row["Input Data"][key] = str(round(
                                decimal.Decimal(new_new_row["Input Data"][key]) + (i * value), 10))
                        for key, value in inout_var_tmp["Expect Output Data"].items():
                            new_new_row["Expect Output Data"][key] = str(round(
                                decimal.Decimal(new_new_row["Expect Output Data"][key]) + (i * value), 10))

                        new_new_row["AutoGen"] = False
                        new_data_set.append(new_new_row)

                        set_log('PARSE', "new_new_row : " + str(new_new_row) + " Add Complete...", log_mod.Logtype_INF)

                prev_row = curr_row

            test_info.extend(new_data_set)

            test_info = sorted(test_info, key=lambda info: (decimal.Decimal(info[item_name])))
        except Exception as e:
            set_log('PARSE', "Test Data Filling Error" + str(e), log_mod.Logtype_ERR)
            raise

        return test_info

    @Logdeco
    def get_parameter(self, parameter_path):
        try:
            parameter_info = self.data_pickle_load("[Parameter Load]", parameter_path)

            set_log('PARSE', "Parameter Data : " + str(parameter_info), log_mod.Logtype_INF)

            # parameter_info = {}
            #
            # test_env = {}
            # test_env['Test_CPU'] = r"tc27x"
            #
            # parameter_info['Test_Env'] = test_env
            #
            # common_param = {}
            # common_param['WorkingProject_Path'] = r"C:\Users\GiCheol.Shin\Desktop\test\test\Gen\20211130_\TestSpec"
            # common_param['T15_Install_Path'] = r"C:\Users\GiCheol.Shin\Desktop\Prost_v2.0\Prost v2.0"
            # common_param['Simulator'] = "FALSE"
            #
            # parameter_info['Common_Path'] = common_param
            #
            # parser_param = {}
            # parser_param['Test_Case_Path'] = r"C:\Users\GiCheol.Shin\Desktop\test\test\Gen\20211130_\TestSpec\TestCase\202111301630_Parsed_new_TestSpec.xlsx"
            # parser_param['Execution_Time'] = "TRUE"
            # parser_param['MappingTable_Path'] = ""
            # parser_param['Min_Diff'] = "0"
            #
            # parameter_info['Parser'] = parser_param
            #
            # log_param = {}
            # log_param['Log_Level'] = "3"
            #
            # parameter_info['Log'] = log_param

            if 'Common_Path' not in parameter_info.keys() or 'Parser' not in parameter_info.keys():
                raise

            common_info = parameter_info['Common_Path']

            if 'WorkingProject_Path' not in common_info.keys() or 'T15_Install_Path' not in common_info.keys() or 'Simulator' not in common_info.keys():
                raise

            parser_info = parameter_info['Parser']

            if 'Test_Case_Path' not in parser_info.keys()  or 'Execution_Time' not in parser_info.keys() or 'Min_Diff' not in parser_info.keys():
                raise
                parser_info['Elf_Path'] = ""

            log_info = parameter_info['Log']

            if 'Log_Level' not in log_info.keys():
                raise

            return parameter_info
        except Exception as ex:
            set_log('PARSE', "Parameter Receive Exception : " + str(ex), log_mod.Logtype_ERR)
            raise