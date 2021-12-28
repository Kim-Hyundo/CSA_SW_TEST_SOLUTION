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

                        set_log('PARSE', "Row : " + str(row_idx) + "Col : " + str(col_idx) + " Parsing Complete...", log_mod.Logtype_INF)

                        if not item_tmp:
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
                    dict_tmp['Break Info'] = {'Input_Break_point': self.break_point, 'Output_Break_point': self.break_point}
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
                    test_info.append(dict_tmp)

        except Exception as ex:
            set_log('PARSE', 'Parsing Exception ' + str(ex), log_mod.Logtype_ERR)
            raise

        return test_info

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

#            parameter_info = {}

#            test_env = {}
#            test_env['Test_CPU'] = r"tc27x"

#            parameter_info['Test_Env'] = test_env

#            common_param = {}
#            common_param['WorkingProject_Path'] = r"D:\git\Mando\workspace"
#            common_param['T15_Install_Path'] = r"D:\git\Prost2\Prost v2.0"
            # common_param['Simulator'] = "FALSE"

#            parameter_info['Common_Path'] = common_param

#            parser_param = {}
#            parser_param['Test_Case_Path'] = r"D:\git\Mando\workspace\TestCase\202101040949_Parsed_new_Failsafe-TestSpec_RS4_rev9.xlsx"
#            parser_param['Execution_Time'] = "TRUE"
#            parser_param['MappingTable_Path'] = ""
#            parser_param['Min_Diff'] = "0"

#            parameter_info['Parser'] = parser_param

#            log_param = {}
#            log_param['Log_Level'] = "3"

#            parameter_info['Log'] = log_param

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