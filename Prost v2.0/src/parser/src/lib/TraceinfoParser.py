from lib.Parser import *


class TraceinfoParser(Parser):

    def __init__(self, parameter_path):
        super().__init__()
        parameter = self.get_parameter(parameter_path)

        self.gen_path = parameter['Common_Path']['WorkingProject_Path']
        self.folder_path = self.gen_path + "\\Debug\\txt\\timing"
        self.save_path = self.gen_path + "\\Debug\\dic\\timing"

        self.log_level = parameter['Log']['Log_Level']

        log_mod.G_Log_level = int(self.log_level)

    @Logdeco
    def priority(self, tmp):
        if "ns" in tmp:
            return 1
        elif "us" in tmp:
            return 2
        elif "ms" in tmp:
            return 3
        elif "s" in tmp:
            return 4

    @Logdeco
    def timing_merge(self, prev_dump, curr_dump):
        try:
            for key, value in prev_dump.items():
                if key in curr_dump.keys():
                    for value_key, value_value in value.items():
                        set_log('PARSE',
                                "Trace Data Merging, Data = " + str(value_key) + " , " + str(value_value) + "Merging Complete",
                                log_mod.Logtype_INF)

                        if value_value == "-":
                            continue
                        if curr_dump[key][value_key] == "-":
                            curr_dump[key][value_key] = value_value
                            continue
        
                        if value_key == "count":
                            curr_dump[key][value_key] = str(decimal.Decimal(curr_dump[key][value_key])+decimal.Decimal(value_value))
                            continue
        
                        if value_key == "total":
                            curr_dump[key][value_key] = self.timeSum(value_value, curr_dump[key][value_key]);
                            continue
        
                        prev_priority = self.priority(value_value)
                        curr_priority = self.priority(curr_dump[key][value_key])
        
                        if prev_priority < curr_priority:
                            if value_key == "max":
                                pass
                            elif value_key == "min":
                                curr_dump[key][value_key] = value_value
                        elif prev_priority == curr_priority:
                            prev_tmp = ""
                            curr_tmp = ""
        
                            if prev_priority == 4:
                                prev_tmp = value_value[:len(value_value) - 1]
                                curr_tmp = curr_dump[key][value_key][:len(curr_dump[key][value_key]) - 1]
                            else:
                                prev_tmp = value_value[:len(value_value) - 2]
                                curr_tmp = curr_dump[key][value_key][:len(curr_dump[key][value_key]) - 2]
        
                            if value_key == "max":
                                if decimal.Decimal(prev_tmp) > decimal.Decimal(curr_tmp):
                                    curr_dump[key][value_key] = value_value
                            elif value_key == "min":
                                if decimal.Decimal(prev_tmp) < decimal.Decimal(curr_tmp):
                                    curr_dump[key][value_key] = value_value
                        else:
                            if value_key == "max":
                                curr_dump[key][value_key] = value_value
                            elif value_key == "min":
                                pass
                else:
                    curr_dump[key] = value
        except Exception as ex:
            set_log('PARSE', 'Trace Timing Merge Exception : ' + str(ex), log_mod.Logtype_ERR)
            raise

        return curr_dump
    
    @Logdeco
    def timeSum(self, op1, op2):
        op1_tmp = 0
        op2_tmp = 0
        priority_diff=int(0)
        result = 0
        op1_priority = self.priority(op1)
        op2_priority = self.priority(op2)
    
        if op1_priority == 4:
            op1_tmp = decimal.Decimal(op1[:len(op1) - 1])
            op2_tmp = decimal.Decimal(op2[:len(op2) - 1])
        else:
            op1_tmp = decimal.Decimal(op1[:len(op1) - 2])
            op2_tmp = decimal.Decimal(op2[:len(op2) - 2])
    
        if op1_priority < op2_priority:
            priority_diff=op2_priority-op1_priority
            op1_tmp=decimal.Decimal(op1_tmp*decimal.Decimal(0.001**priority_diff))
            result = round(op1_tmp + op2_tmp, 3)
            result = self.prioritytoUnit(op2_priority, str(result))
        elif op1_priority > op2_priority:
            priority_diff = op1_priority-op2_priority
            op2_tmp = decimal.Decimal(op2_tmp * decimal.Decimal(0.001 ** priority_diff))
            result = round(op1_tmp + op2_tmp, 3)
            result = self.prioritytoUnit(op1_priority, str(result))
        else:
            result = round(op1_tmp + op2_tmp, 3)
            result = self.prioritytoUnit(op1_priority, str(result))
        return result

    def prioritytoUnit(self, tmp, data):
        if tmp == 1:
            return data + "ns"
        elif tmp == 2:
            return data + "us"
        elif tmp == 3:
            return data + "ms"
        elif tmp == 4:
            return data + "s"

    @Logdeco
    def timing_info_extract(self, trace_data):
        data_dump = {}
        col_names = []
        decimal_count = 0
        last_str = ""
        is_start = False

        if len(trace_data) <= 5:
            set_log('PARSE', "Trace Data Extracting, not exist data", log_mod.Logtype_INF)
            return
     
        trace_data = trace_data[3:len(trace_data)]
        # col_names [0] - range [1] - total [2] - min [3] - max [4] - avr [5] - count

        try:
            for str_tmp in trace_data:
                if str_tmp:
                    set_log('PARSE', "Trace Data Extracting, Data = " + str(str_tmp) + "Extracting Complete",
                            log_mod.Logtype_INF)

                    if not is_start:
                        if str_tmp[0] == "_":
                            is_start = True
                            col_names = re.split('[|_\n]', str_tmp)

                            while "" in col_names:
                                col_names.remove("")
                            continue
                    else:
                        value_tmp = re.split('[|]', str_tmp)

                        while "" in value_tmp:
                            value_tmp.remove("")

                        func_name = value_tmp[1]
                        func_name_tmp = func_name.split("\\")

                        if len(func_name_tmp) != 0:
                            last_str = func_name_tmp[len(func_name_tmp) - 1]

                        func_name = last_str.strip()

                        count = value_tmp[6]
                        count_tmp = count.split(".")

                        if len(count_tmp) != 0:
                            decimal_count = count_tmp[0]

                        value_tmp[6] = decimal_count.strip()

                        time_data_tmp = {}
                        for i in range(2, 7):
                            time_data_tmp[col_names[i].strip()] = value_tmp[i].strip()

                        data_dump[func_name] = time_data_tmp
        except Exception as ex:
            set_log('PARSE', 'Trace Timing Data Extract Exception : ' + str(ex), log_mod.Logtype_ERR)
            raise

        return data_dump

    @Logdeco
    def get_parameter(self, parameter_path):
        try:
            parameter_info = super().data_pickle_load("[Parameter Load]", parameter_path)

            set_log('PARSE', "Parameter Data : " + str(parameter_info), log_mod.Logtype_INF)

            if 'Common_Path' not in parameter_info.keys() or 'Parser' not in parameter_info.keys():
                raise

            common_info = parameter_info['Common_Path']

            if 'WorkingProject_Path' not in common_info.keys() or 'T15_Install_Path' not in common_info.keys():
                raise

            log_info = parameter_info['Log']

            if 'Log_Level' not in log_info.keys():
                raise

            return parameter_info
        except Exception as ex:
            set_log('PARSE', "Parameter Receive Exception : " + str(ex), log_mod.Logtype_ERR)
            raise

    @Logdeco
    def do_parsing(self):
        try:
            if not super().isdir(self.folder_path):
                set_log('PARSE', 'Folder Path is not exist.', log_mod.Logtype_ERR)
                raise

            if not super().isdir(self.save_path):
                os.makedirs(self.save_path)

            scenario_list = os.listdir(self.folder_path)

            if super().is_empty(scenario_list):
                set_log('PARSE', "Scenario Data is empty!", log_mod.Logtype_ERR)
                raise

            for scenario_folder in scenario_list:
                file_have_folder = self.folder_path + "\\" + scenario_folder
                file_list = os.listdir(file_have_folder)

                if super().is_empty(file_list):
                    set_log('PARSE', "Folder is empty!", log_mod.Logtype_ERR)
                    raise

                total_data_dump = {}

                set_log('PARSE', 'Trace Timing Data Parsing Start...', log_mod.Logtype_PRG)
                for file_name in file_list:
                    load_file_path = file_have_folder + "\\" + file_name

                    set_log('PARSE', 'Trace Txt Read Start...', log_mod.Logtype_PRG)
                    trace_data = super().txt_file_read(load_file_path, 1)
                    set_log('PARSE', 'Trace Txt Read Complete...', log_mod.Logtype_PRG)

                    if not trace_data:
                        set_log('PARSE', 'Trace Data is empty.', log_mod.Logtype_ERR)
                    else:
                        set_log('PARSE', 'Timing Data Extracting from txt Start...', log_mod.Logtype_PRG)

                        data_dump = self.timing_info_extract(trace_data)

                        set_log('PARSE', 'Timing Data Extracting from txt Complete...', log_mod.Logtype_PRG)

                        if not data_dump:
                            set_log('PARSE', 'Trace Data is empty.', log_mod.Logtype_ERR)
                        else:
                            total_data_dump[file_name] = data_dump

                set_log('PARSE', 'Trace Timing Data Parsing Complete...', log_mod.Logtype_PRG)

                scenario_save_path = self.save_path + "\\" + scenario_folder

                if not super().isdir(scenario_save_path):
                    os.makedirs(scenario_save_path)

                total_data_file_path = scenario_save_path + "\\" + "trace_time_data.txt"

                super().data_pickle_save("[Trace Timing Total Data]", total_data_dump, total_data_file_path, True)

                data_dump = total_data_dump
                total_merge_data = {}

                set_log('PARSE', 'Trace Timing Data Merge & Save Start...', log_mod.Logtype_PRG)

                for file_name, func_names in data_dump.items():
                    curr_file_name = file_name
                    if len(total_merge_data) == 0:
                        total_merge_data["result"] = data_dump[curr_file_name]
                        continue

                    merge_data = self.timing_merge(dict(data_dump[curr_file_name]), total_merge_data["result"])
                    total_merge_data["result"] = merge_data

                merge_file_save_path = scenario_save_path + "\\" + "trace_timing_merged_file.txt"

                super().data_pickle_save("[Trace Timing Merge Data]",
                                         total_merge_data["result"], merge_file_save_path, True)

                set_log('PARSE', 'Trace Timing Data Merge & Save Complete...', log_mod.Logtype_PRG)
        except Exception as ex:
            set_log('PARSE', 'Trace Timing Info Parser Exception : ' + str(ex), log_mod.Logtype_ERR)
            raise
