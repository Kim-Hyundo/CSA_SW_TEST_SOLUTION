from lib.Parser import *
import copy

class TraceVarParser(Parser):

    def __init__(self, parameter_path):
        super().__init__()
        parameter = self.get_parameter(parameter_path)

        self.gen_path = parameter['Common_Path']['WorkingProject_Path']
        self.install_path = parameter['Common_Path']['T15_Install_Path']
        self.cpu_info = parameter['Test_Env']['Test_CPU']

        self.folder_path = self.gen_path + "\\Debug\\txt\\trace"
        self.save_path = self.gen_path + "\\Debug\\dic\\trace"
        self.memory_map_path = self.install_path + "\\src\\parser\\memory\\" + self.cpu_info

        self.log_level = parameter['Log']['Log_Level']
        log_mod.G_Log_level = int(self.log_level)

        self.merge_col_names = ["Symbol", "Address", "MemoryBank"]
        self.memory_map_data = []
        self.reserved_address_data = []
        self.core_list = []
        self.test = 0


    def variables_merge(self, new_data, result_data, core_num):
        try:

            if result_data is None or len(result_data) == 0:
                print("test")
            else:
                self.test = len(result_data)

            if self.test == 415:
                print("test")

            symbol_tmp = new_data["Symbol"]
            memory_bank_tmp = ""
            target = ""
            found = False
            address_str = "0x" + new_data["Address"]
            address = int(address_str, 16)

            if new_data["Cycle"] == "wr-data":
                target = "Write Access Counter " + core_num

            if new_data["Cycle"] == "rd-data":
                target = "Read Access Counter " + core_num

            if symbol_tmp == "":
                for reserved_data in self.reserved_address_data:
                    if reserved_data["Start Address"] <= address <= reserved_data["End Address"]:
                        symbol_tmp = reserved_data["Memory"]
                        address_str = hex(reserved_data["Start Address"]) + "--" + hex(reserved_data["End Address"])
                        found = True
                        break

                if not found:
                    symbol_tmp = "None matched"

            is_ok = True
            if symbol_tmp in result_data.keys():
                is_ok = False

            result_data_tmp = {}

            if is_ok:
                found = False

                for memory_data in self.memory_map_data:
                    if memory_data["Start Address"] <= address <= memory_data["End Address"]:
                        memory_bank_tmp = memory_data["Memory"]
                        found = True
                        break

                if not found or symbol_tmp == "None matched":
                    memory_bank_tmp = ""

                result_data_tmp["Symbol"] = symbol_tmp
                result_data_tmp["Address"] = address_str
                result_data_tmp["MemoryBank"] = memory_bank_tmp

                for core_tmp in self.core_list:
                    result_data_tmp["Read Access Counter " + core_tmp] = 0
                    result_data_tmp["Write Access Counter " + core_tmp] = 0

                result_data_tmp[target] = result_data_tmp[target] + 1
                result_data_tmp["Total"] = 1
                result_data[symbol_tmp] = copy.deepcopy(result_data_tmp)
            else:
                result_data_tmp = result_data[symbol_tmp]
                result_data_tmp[target] = result_data_tmp[target] + 1
                result_data_tmp["Total"] = result_data_tmp["Total"] + 1

        except Exception as ex:
            set_log('PARSE', 'Trace Timing Merge Exception : ' + str(ex), log_mod.Logtype_ERR)
            raise

        return result_data

    @Logdeco
    def timing_info_extract(self, result_data, trace_data, file_name):
        col_names = []
        last_str = ""
        is_start = False

        if len(trace_data) <= 5:
            set_log('PARSE', "Trace Data Extracting, not exist data", log_mod.Logtype_INF)
            return

        trace_data = trace_data[2:len(trace_data)]
        total_cnt = len(trace_data) - 2

        try:
            for curr_idx, str_tmp in enumerate(trace_data):
                if str_tmp:
                    if curr_idx % 1000 == 0:
                        set_log('PARSE', "Extracting Complete (" + str(curr_idx) + " / " + str(total_cnt) + ")", log_mod.Logtype_INF)

                    if len(str_tmp) < 26:
                        continue

                    str_tmp_or_split = str_tmp.split("|")

                    if len(str_tmp_or_split) <= 2:
                        continue

                    record = str_tmp_or_split[0].strip()

                    if record == "":
                        continue

                    core_num = "core" + str_tmp_or_split[1].strip()

                    other_str_tmp = str_tmp_or_split[2].strip()
                    #other_str_tmp = " ".join(other_str_tmp)
                    other_str_tmp_split = other_str_tmp.split()

                    if len(other_str_tmp_split) < 2:
                        continue

                    address = other_str_tmp_split[0].strip()

                    if ":" not in address:
                        continue

                    address_tmp = address.split(":")
                    address = address_tmp[1].strip()

                    cycle = other_str_tmp_split[1].strip()

                    if "wr-data" != cycle and "rd-data" != cycle:
                        continue

                    if core_num not in self.core_list:
                        self.core_list.append(core_num)
                        self.merge_col_names.append("Read Access Counter " + core_num)
                        self.merge_col_names.append("Write Access Counter " + core_num)
                        self.core_list.sort()

                    symbol = ""
                    if "rd-data" in cycle:
                        symbol = other_str_tmp_split[2].strip()
                    if "wr-data" in cycle:
                        symbol = other_str_tmp_split[3].strip()

                    if "us" in symbol or "\\" not in symbol:
                        symbol = ""

                    # symbol_tmp = symbol.split("+")
                    # symbol = symbol_tmp[0].strip()

                    data_dump_tmp = {}
                    data_dump_tmp["Address"] = address
                    data_dump_tmp["Cycle"] = cycle
                    data_dump_tmp["Symbol"] = symbol

                    self.variables_merge(data_dump_tmp, result_data, core_num)

        except Exception as ex:
            set_log('PARSE', 'Trace Timing Data Extract Exception : ' + str(ex), log_mod.Logtype_ERR)
            raise

        return result_data

    def print_data(self, save_path, result_data):
        curr_idx = 0
        with open(save_path, "w") as f:
            col_lines = ""
            for col_name in self.merge_col_names:
                col_lines = col_lines + col_name + " , "

            f.write(col_lines + "\n")
            total_cnt = len(result_data)
            for key, value in result_data.items():
                data_lines = ""
                for data_value in value.values():
                    data_lines = data_lines + str(data_value) + " , "

                f.write(data_lines + "\n")
                curr_idx = curr_idx + 1
                set_log('PARSE', "Trace Data printing, Data = " + str(data_lines) + "Printing Complete (" + str(curr_idx) + " / " + str(total_cnt) + ")", log_mod.Logtype_INF)

    @Logdeco
    def read_memory_data(self, trace_data):
        data_dump = []
        col_names = ["Start Address", "End Address", "Memory"]

        try:
            for str_tmp in trace_data:
                if str_tmp:
                    set_log('PARSE', "Trace Data Extracting, Data = " + str(str_tmp) + "Extracting Complete",
                            log_mod.Logtype_INF)

                    value_tmp = str_tmp.split(" ")

                    while "" in value_tmp:
                        value_tmp.remove("")

                    memory_data_tmp = {}
                    for i in range(0, 3):
                        memory_data_tmp[col_names[i].strip()] = value_tmp[i].strip()

                    if "0x" not in memory_data_tmp["Start Address"]:
                        memory_data_tmp["Start Address"] = "0x" + memory_data_tmp["Start Address"]

                    memory_data_tmp["Start Address"] = int(memory_data_tmp["Start Address"], 16)

                    if "0x" not in memory_data_tmp["End Address"]:
                        memory_data_tmp["End Address"] = "0x" + memory_data_tmp["End Address"]

                    memory_data_tmp["End Address"] = int(memory_data_tmp["End Address"], 16)

                    data_dump.append(memory_data_tmp)

        except Exception as ex:
            set_log('PARSE', 'Trace Memory Data Extract Exception : ' + str(ex), log_mod.Logtype_ERR)
            raise

        return data_dump

    @Logdeco
    def get_parameter(self, parameter_path):
        try:
            parameter_info = super().data_pickle_load("[Parameter Load]", parameter_path)

            set_log('PARSE', "Parameter Data : " + str(parameter_info), log_mod.Logtype_INF)
#            parameter_info = {}

#            test_env = {}
#            test_env['Test_CPU'] = r"tc39x"
#            parameter_info['Test_Env'] = test_env

#            common_info = {}
#            common_info['WorkingProject_Path'] = r"C:\Users\CSA_DEV\Documents\Working\Prost_v2.0\Workspace\MANDO_FailSafe\Gen\20201201_FailSafe\Failsafe_TestSpec"
#            common_info['T15_Install_Path'] = r"C:\Users\CSA_DEV\Documents\Working\Prost_v2.0\Prost v2.0"
#            parameter_info['Common_Path'] = common_info

#            log_info = {}
#            log_info['Log_Level'] = "3"
#            parameter_info['Log'] = log_info

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

            ######################################################################################################
            ######################################################################################################

            for scenario_folder in scenario_list:
                scenario_folder_path = self.folder_path + "\\" + scenario_folder

                memory_file_list = os.listdir(self.memory_map_path)
                file_list = os.listdir(scenario_folder_path)

                if "memory_map.txt" not in memory_file_list and "reserved_address.txt" not in memory_file_list:
                    set_log('PARSE', "import file is not exist", log_mod.Logtype_ERR)
                    raise

                if super().is_empty(file_list):
                    set_log('PARSE', "Folder is empty!", log_mod.Logtype_ERR)
                    raise

                ######################################################################################################
                ######################################################################################################

                memory_map_txt = self.memory_map_path + "\\memory_map.txt"
                reserved_address_txt = self.memory_map_path + "\\reserved_address.txt"

                trace_data = super().txt_file_read(memory_map_txt, 1)
                data_dump = self.read_memory_data(trace_data)

                if data_dump is None or len(data_dump) == 0:
                    set_log('PARSE', 'Map Data is empty.', log_mod.Logtype_ERR)
                    raise

                self.memory_map_data = copy.deepcopy(data_dump)

                trace_data = super().txt_file_read(reserved_address_txt, 1)
                data_dump = self.read_memory_data(trace_data)

                if data_dump is None or len(data_dump) == 0:
                    set_log('PARSE', 'Reserved Address Data is empty.', log_mod.Logtype_ERR)
                    raise

                self.reserved_address_data = copy.deepcopy(data_dump)

                set_log('PARSE', 'Trace Timing Data Parsing Complete...', log_mod.Logtype_PRG)

                ######################################################################################################
                ######################################################################################################

                result_data = {}

                set_log('PARSE', 'Trace Var Data Parsing Start...', log_mod.Logtype_PRG)

                for file_name in file_list:
                    load_file_path = scenario_folder_path + "\\" + file_name

                    set_log('PARSE', 'Trace Txt Read Start...', log_mod.Logtype_PRG)
                    trace_data = super().txt_file_read(load_file_path, 1)
                    set_log('PARSE', 'Trace Txt Read Complete...', log_mod.Logtype_PRG)

                    if not trace_data:
                        set_log('PARSE', 'Trace Data is empty.', log_mod.Logtype_ERR)
                    else:
                        set_log('PARSE', 'Timing Data Extracting from txt Start...', log_mod.Logtype_PRG)

                        result_data = self.timing_info_extract(result_data, trace_data, file_name)

                        set_log('PARSE', 'Timing Data Extracting from txt Complete...', log_mod.Logtype_PRG)

                        if not data_dump:
                            set_log('PARSE', 'Trace Data is empty.', log_mod.Logtype_ERR)
                            raise

                ######################################################################################################
                ######################################################################################################

                scenario_save_path = self.save_path + "\\" + scenario_folder

                if not super().isdir(scenario_save_path):
                    os.makedirs(scenario_save_path)

                total_data_file_path = scenario_save_path + "\\" + "trace_var_data.txt"

                #set_log('PARSE', 'Trace Timing Data Merge & Save Start...', log_mod.Logtype_PRG)


                ######################################################################################################
                ######################################################################################################


                merge_file_save_path = scenario_save_path + "\\" + "trace_var_merged_dic.txt"
                merge_file_txt_path = scenario_save_path + "\\" + "trace_var_merged_text.txt"

                super().data_pickle_save("[Trace Variables Merge Data]",
                                         result_data, merge_file_save_path, True)

                self.merge_col_names.append("Total")

                self.print_data(merge_file_txt_path, result_data)

                set_log('PARSE', 'Trace Variables Data Merge & Save Complete...', log_mod.Logtype_PRG)
        except Exception as ex:
            set_log('PARSE', 'Trace Variables Info Parser Exception : ' + str(ex), log_mod.Logtype_ERR)
            raise
