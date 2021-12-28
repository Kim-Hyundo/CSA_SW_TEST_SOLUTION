from lib.TestspecParser import *
import copy, decimal
import importlib.machinery

class WiaUnitTestspecParser(TestspecParser):

    def __init__(self, parameter_path):
        parameter = self.get_parameter(parameter_path)
        super().__init__(parameter, self.test_spec_format_convert, self.create_test_loc_info,self.test_spec_parser,"default","Unit", 1)
        self.col_lines = {'Start_Idx': [3, 2], 'End_Idx': [3, 9]}

    @Logdeco
    def test_spec_parser(self, spec_data):
        test_info = {}
        precond_info = []

        try:
            total_row_cnt = len(spec_data)

            start_row = self.col_lines['Start_Idx']
            start_row_idx = start_row[0] - 1
            start_col_idx = start_row[1] - 1

            end_row = self.col_lines['End_Idx']
            end_col_idx = end_row[1]

            col_name_line = spec_data[start_row_idx]

            for row_idx in range(start_row_idx + 1, total_row_cnt):
                row_tmp = spec_data[row_idx]
                dict_tmp = {}
                scenario_name = ""
                tc_title_name = ""
                tc_title = ""
                is_ok = True

                for col_idx in range(start_col_idx, end_col_idx):
                    col_name = col_name_line[col_idx]
                    col_name.strip()
                    item_tmp = row_tmp[col_idx]

                    set_log('PARSE', "Row : " + str(row_idx) + "Col : " + str(
                        col_idx) + " Parsing Complete..." + "Data = " + str(item_tmp), log_mod.Logtype_INF)

                    if not item_tmp or item_tmp == "None":
                        if item_tmp != 0 or item_tmp is None:
                            is_ok = False
                            break

                    if "TC ID" in col_name or "tc id" in col_name or "Tc Id" in col_name:
                        pass
                    elif "TEST STEP" in col_name or "test step" in col_name or "Test Step" in col_name:
                        splited_item_list = item_tmp.split("-")

                        if not splited_item_list:
                            is_ok = False
                            break

                        scenario_tmp = splited_item_list[0]
                        for i in range(1, len(splited_item_list) - 1):
                            scenario_tmp = scenario_tmp + "-" + splited_item_list[i]

                        scenario_name = str(scenario_tmp)

                        splited_item = splited_item_list[len(splited_item_list) - 1]
                        dict_tmp["Time"] = str(splited_item)
                    elif "TC TITLE" in col_name or "tc title" in col_name or "Tc Title" in col_name:
                        tc_title_name = str(item_tmp)
                    elif "PRECONDITIONS" in col_name or "preconditions" in col_name or "Preconditions" in col_name:
                        precon_dic = super().next_line_equal_split(item_tmp, "=")
                        if not precon_dic:
                            precond_info.append({scenario_name: "NONE"})
                        else:
                            precond_info.append({scenario_name: precon_dic})
                    elif "INPUT" in col_name or "input" in col_name or "Input" in col_name:
                        input_dic = super().next_line_equal_split(item_tmp, "=")
                        if not input_dic:
                            return False
                        dict_tmp["Input Data"] = input_dic
                    elif "EXPECTED OUTPUT" in col_name or "expected output" in col_name or "Expected Output" in col_name:
                        output_dic = super().next_line_equal_split(item_tmp, "=")
                        if not output_dic:
                            return False
                        dict_tmp["Output Data"] = output_dic
                    elif "TOLERANCE" in col_name or "tolerance" in col_name or "Tolerance" in col_name:
                        tolerance_dic = super().next_line_equal_split(item_tmp, "=")
                        dict_tmp["Tolerance"] = tolerance_dic

                if not is_ok:
                    continue

                if not scenario_name in test_info.keys():
                    if scenario_name == "":
                        raise
                    test_info[scenario_name] = []

                test_info[scenario_name].append(dict_tmp)
        except Exception as e:
            set_log('PARSE', "Test Spec Parsing Error" + str(e), log_mod.Logtype_ERR)
            raise

        #for tmp in test_info.values():
        #    if tmp is not None and len(tmp) > 0:
                #if tmp[0]["Time"] != "0" and tmp[0]["Time"] != "0.0" 
                 #       and tmp[0]["Time"] != "00" and tmp[0]["Time"] != "0.00":
                    #tmp_tmp = copy.deepcopy(tmp[0])
                    #tmp_tmp["Time"] = "0.0"
                    #tmp.insert(0, tmp_tmp)

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
                    value_tmp = value[0]
                    col_list.clear()
                    data_list.clear()
                    new_data_dump[scenario_name] = []

                    for value_key, value_value in value_tmp.items():
                        if value_key == "Time":
                            col_list.append(value_key)
                            data_list.append(value_value)
                            continue
                        if not value_value:
                            continue

                        for value_value_key, value_value_value in value_value.items():
                            col_list.append(value_value_key)

                    new_data_dump[scenario_name].append(list(col_list))

                    for data in value:
                        data_list.clear()

                        for value_key, value_value in data.items():
                            if value_key == "Time":
                                data_list.append(value_value)
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

                row = 1
                col = 1

                first_data = data[0]
                end_col = 1
                TestID = {'Start_Idx': [row, col], 'End_Idx': [row, end_col]}
                col = end_col + 1
                end_col = col + len(first_data['Input Data']) - 1
                InputData = {'Start_Idx': [row, col], 'End_Idx': [row, end_col]}
                col = end_col + 1
                end_col = col + len(first_data['Output Data']) - 1
                OutputData = {'Start_Idx': [row, col], 'End_Idx': [row, end_col]}
                col = end_col + 1
                end_col = col + len(first_data['Tolerance']) - 1
                Tolerance = {'Start_Idx': [row, col], 'End_Idx': [row, end_col]}

                test_loc_info[scenario] = {'Test ID': TestID, 'Input Data': InputData, 'Expect Output Data': OutputData,
                                           'Tolerance': Tolerance}
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
#            common_param['WorkingProject_Path'] = r"C:\git\Mando"

#            parameter_info['Common_Path'] = common_param

#            parser_param = {}
#            parser_param['Test_Spec_Path'] = r"C:\git\Mando\Wia_map_testcase\TestSequence_2020-02-12.xlsx"

#            parameter_info['Parser'] = parser_param

#            log_param = {}
#            log_param['Log_Level'] = "3"

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
