from lib.TestcaseParser import *
import copy, decimal

class WiaUnitTestcaseParser(TestcaseParser):

    def __init__(self, parameter_path):
        parameter = self.get_parameter(parameter_path)
        super().__init__(parameter, self.test_info_parser, self.test_post_process, self.test_case_format_convert, self.test_data_mapping)

        self.min_diff = parameter['Parser']['Min_Diff']
        self.break_point = "Check_Point"
        self.mapping_data_loc = {'Start_Idx': [2, 1], 'End_Idx': [2, 9]}
        self.mapping_col_names = ['Num', 'CAN Name', 'Message', 'Startbit', 'Length', 'Value Type', 'Initial Value', 'Factor', 'Offset', 'Structure']
        self.mapping_data = []

    @Logdeco
    def test_info_parser(self, data, test_loc_info, error_list):
        test_info = []

        try:
            if super().is_empty(data) or super().is_empty(test_loc_info):
                set_log('PARSE', 'Test Data is empty', log_mod.Logtype_ERR)
                raise

            total_row_cnt = len(data)
            start_loc = test_loc_info['Test ID']['Start_Idx']
            start_row_idx = start_loc[0]

            curr_id = "-1"
            first = True
            for row_idx in range(start_row_idx, total_row_cnt):
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
                                inp_tmp[key] = "0"
                            for key in out_tmp.keys():
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
        new_data_dump = {}

        try:
            scenario_name = ""
            col_list = []
            data_list = []

            for key, value in test_data.items():
                if scenario_name == "" or scenario_name != key:
                    scenario_name = key
                    value_tmp = value[0]
                    col_list.clear()
                    data_list.clear()
                    new_data_dump[scenario_name] = []

                    for value_key, value_value in value_tmp.items():
                        if value_key != "Test ID" and value_key != "Input Data" and value_key != "Expect Output Data" and value_key != "Tolerance":
                            continue
                        if value_key == "Test ID":
                            col_list.append("Time")
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
                            if value_key != "Test ID" and value_key != "Input Data" and value_key != "Expect Output Data" and value_key != "Tolerance":
                                continue
                            if value_key == "Test ID":
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
            set_log('PARSE', "Test Case Converting Error" + str(e), log_mod.Logtype_ERR)
            raise

        return new_data_dump

    @Logdeco
    def test_post_process(self, test_info):
        test_info = self.min_diff_add(test_info, self.min_diff, "Test ID")
        return test_info

    @Logdeco
    def test_data_mapping(self, test_info, mapping_data):
        map_bitset = ""

        if self.mapping_flag:
            mapping_data = self.mapping_data_process(mapping_data)

            for idx, data in enumerate(test_info):
                map_bitset = self.mapping_create_bitset(mapping_data)
                data['Input Data'] = self.mapper(copy.deepcopy(data['Input Data']), mapping_data, map_bitset)

        return test_info


    @Logdeco
    def min_diff_add(self, test_info, min_diff, item_name):
        try:
            new_data_set = []

            min_diff = decimal.Decimal(str(min_diff))
            if min_diff == 0:
                return test_info

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
    def mapper(self, var_dic, mapping_data, mapdata_tmp):
        new_var_dic = {}
        try:
            if var_dic is None:
                raise

            if mapping_data is None or len(mapping_data) == 0 \
                    or mapdata_tmp is None or len(mapdata_tmp) == 0:
                return var_dic

            unit_size = 32

            removed_list = {}
            for var_name, var_value in var_dic.items():
                isfound = False
                for mapdata in mapping_data:
                    if var_name == mapdata['CAN Name']:
                        isfound = True
                        removed_list[var_name] = ""
                        message = mapdata['Message']
                        start_bit = mapdata['Startbit']
                        length = mapdata['Length']
                        value_type = mapdata['Value Type']

                        offset = decimal.Decimal(mapdata['Offset'])
                        factor = decimal.Decimal(mapdata['Factor'])

                        if factor is None or offset is None or factor == 0:
                            set_log('PARSE', "Offset Factor Error", log_mod.Logtype_INF)
                            raise

                        result_value = int((decimal.Decimal(var_value) - offset) / factor)

                        if result_value < 0:
                            if value_type == "Unsigned":
                                result_value = 0
                                result_value = format(result_value, '0' + str(length) + 'b')
                            else:
                                result_value = abs(result_value)
                                result_value = format(result_value, '0' + str(length) + 'b')
                                result_value = self.findTwoscomplement(result_value)
                        else:
                            result_value = format(result_value, '0' + str(length) + 'b')

                        all_bit_set = mapdata_tmp[message]['result']

                        if len(all_bit_set) < start_bit + length:
                            set_log('PARSE', "all_bit_set Size Error", log_mod.Logtype_INF)
                            raise

                        bit_subset = all_bit_set[start_bit: start_bit + length]
                        zero_subset = format(0, '0' + str(length) + 'b')

                        if bit_subset != zero_subset:
                            set_log('PARSE', "Redundant data in bitset", log_mod.Logtype_INF)
                            raise

                        all_bit_set = all_bit_set[:start_bit] + result_value + all_bit_set[start_bit + length:]
                        mapdata_tmp[message]['result'] = all_bit_set

                if not isfound:
                    new_var_dic[var_name] = var_value

            for key, value in mapdata_tmp.items():
                unit_cnt = value['Unit cnt']
                all_bit_set = value['result']
                new_var_name = ""
                curr_pos = 0
                for i in range(1, unit_cnt + 1):
                    if len(str(i)) == 1:
                        new_var_name = key + "Bitset_0" + str(i)
                    else:
                        new_var_name = key + "_Bitset_" + str(i)
                    new_var_value = "0y" + all_bit_set[curr_pos:curr_pos + unit_size]

                    curr_pos = curr_pos + unit_size
                    new_var_dic[new_var_name] = new_var_value

            return new_var_dic
        except Exception as ex:
            set_log('PARSE', "Test Spec Mapping Error " + str(ex), log_mod.Logtype_ERR)
            return

    @Logdeco
    def mapping_create_bitset(self, mapping_data):
        try:
            unit_size = 32
            mapdata_tmp = {}

            for mapdata in mapping_data:
                message = mapdata['Message']

                if message not in mapdata_tmp.keys():
                    mapdata_tmp[message] = {}
                    mapdata_tmp[message]['Max bit'] = 0
                    mapdata_tmp[message]['Unit cnt'] = 0

                start_bit = mapdata['Startbit']
                length = mapdata['Length']

                if start_bit == "" or length == "":
                    set_log('PARSE', "start bit, length Error", log_mod.Logtype_INF)
                    raise

                if mapdata_tmp[message]['Max bit'] < (start_bit + length):
                    mapdata_tmp[message]['Max bit'] = (start_bit + length)

            for value in mapdata_tmp.values():
                max_bit = value['Max bit']

                unit_cnt = (int)(max_bit / unit_size)

                if max_bit % unit_size != 0:
                    unit_cnt = unit_cnt + 1
                value['Unit cnt'] = unit_cnt
                value['result'] = ""
                for i in range(0, unit_cnt):
                    value['result'] = value['result'] + "00000000000000000000000000000000"
            return mapdata_tmp
        except Exception as ex:
            set_log('PARSE', "Test Spec Mapping bitset Create Error " + str(ex), log_mod.Logtype_ERR)
            raise

    @Logdeco
    def mapping_data_process(self, mapping_data):
        try:
            result = []
            total_row_cnt = len(mapping_data)

            start_row = self.mapping_data_loc['Start_Idx']
            start_row_idx = start_row[0] - 1
            start_col_idx = start_row[1] - 1

            end_row = self.mapping_data_loc['End_Idx']
            end_col_idx = end_row[1]

            for row_idx in range(start_row_idx, total_row_cnt):
                row_tmp = mapping_data[row_idx]
                dict_tmp = {}
                for col_idx in range(start_col_idx, end_col_idx):
                    col_name = self.mapping_col_names[col_idx]
                    item_tmp = row_tmp[col_idx]
                    next_line_split = item_tmp.split("\n")

                    dict_tmp[col_name] = next_line_split[0]

                    if col_name == 'Startbit' or col_name == 'Length' or col_name == 'Initial Value':
                        dict_tmp[col_name] = int(decimal.Decimal(dict_tmp[col_name]))
                    elif col_name == 'Factor' or col_name == 'Offset':
                        dict_tmp[col_name] = decimal.Decimal(dict_tmp[col_name])
                    elif col_name == "Message":
                        if "_" in dict_tmp[col_name]:
                            under_bar_split = dict_tmp[col_name].split("_")
                            message = ""
                            for tmp in under_bar_split:
                                if "ms" not in tmp:
                                    message += tmp
                            dict_tmp[col_name] = message
                    elif col_name == "Structure":
                        dict_tmp["Message"] = dict_tmp[col_name] + "." + dict_tmp["Message"]

                result.append(dict_tmp)

            return result
        except Exception as ex:
            set_log('PARSE', "Test Spec Mapping Data Parsing Error " + str(ex), log_mod.Logtype_ERR)
            raise
    @Logdeco
    # Function to find two's complement
    def findTwoscomplement(self, str):
        n = len(str)
        i = n - 1
        while (i >= 0):
            if (str[i] == '1'):
                break
            i -= 1
        if (i == -1):
            return '1' + str

        k = i - 1
        while (k >= 0):

            if (str[k] == '1'):
                str = list(str)
                str[k] = '0'
                str = ''.join(str)
            else:
                str = list(str)
                str[k] = '1'
                str = ''.join(str)

            k -= 1
        return str

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
#            common_param['WorkingProject_Path'] = r"C:\git\Mando"
#            common_param['T15_Install_Path'] = r"C:\git\Mando"

#            parameter_info['Common_Path'] = common_param

#            parser_param = {}
#            parser_param['Test_Case_Path'] = r"C:\git\Mando\TestCase\202012071402_Parsed_new_TestSequence_2020-02-12.xlsx"
#            parser_param['MappingTable_Path'] = r"C:\git\Mando\Wia_map_testcase\Mapping_TestCase.xlsx"
#            parser_param['Execution_Time'] = "FALSE"
#            parser_param['Min_Diff'] = "0.01"

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

            if 'Test_Case_Path' not in parser_info.keys()  or 'Execution_Time' not in parser_info.keys() or 'Min_Diff' not in parser_info.keys() or 'MappingTable_Path' not in parser_info.keys():
                raise
#                parser_info['Elf_Path'] = ""

            log_info = parameter_info['Log']

            if 'Log_Level' not in log_info.keys():
                raise

            return parameter_info
        except Exception as ex:
            set_log('PARSE', "Parameter Receive Exception : " + str(ex), log_mod.Logtype_ERR)
            raise