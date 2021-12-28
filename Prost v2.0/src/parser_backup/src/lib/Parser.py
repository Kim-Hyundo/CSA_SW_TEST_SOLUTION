import abc, decimal, re, copy
from common.FileManager import *


class Parser(FileManager, metaclass=abc.ABCMeta):
    def __init__(self):
        super().__init__()

    @staticmethod
    def set_log(module, msg, log_type):
        set_log(module, msg, log_type)

    @Logdeco
    def data_pickle_load(self, title, load_path):
        try:
            data = object_file_load(load_path, "rb")

            if super().is_empty(data):
                set_log('PARSE', title + ' data is empty!', log_mod.Logtype_ERR)
                raise

            return data
        except Exception as ex:
            raise

    @Logdeco
    def data_pickle_save(self, title, data, save_path, is_save):
        try:
            if super().is_empty(data):
                set_log('PARSE', title + " data is empty!", log_mod.Logtype_ERR)
                raise

            if is_save:
                if not object_file_dump(save_path, data, "wb"):
                    set_log('PARSE', title + ' Pickle File Save Error', log_mod.Logtype_ERR)
                    raise
        except Exception as ex:
            raise

    @Logdeco
    def next_line_equal_split(self, item_tmp, delimeter):
        data_dic = {}

        try:
            data_tmp = str(item_tmp)

            if not data_tmp or data_tmp == "" or data_tmp == "-" or data_tmp == "n/a":
                set_log('PARSE', 'Data is empty', log_mod.Logtype_INF)
                return

            next_line_split = data_tmp.split("\n")

            if next_line_split:
                for line in next_line_split:
                    set_log('PARSE', 'Data Split... Data = ' + str(line), log_mod.Logtype_INF)
                    equal_split = line.split(delimeter)
                    if equal_split:
                        if len(equal_split) >= 2:
                            data_name = equal_split[0].strip()
                            data_value = equal_split[1].strip()
                            data_dic[data_name] = data_value
                        else:
                            set_log('PARSE', 'name or value data is not exist', log_mod.Logtype_INF)
                            return None
                    else:
                        set_log('PARSE', 'delimeter is not exist in string data', log_mod.Logtype_INF)
                        return None
            else:
                raise
        except Exception as ex:
            set_log('PARSE', 'data split Exception : ' + str(ex), log_mod.Logtype_ERR)
            raise

        return data_dic

    @abc.abstractmethod
    def get_parameter(self, parameter_path):
        pass

    @abc.abstractmethod
    def do_parsing(self):
        pass
