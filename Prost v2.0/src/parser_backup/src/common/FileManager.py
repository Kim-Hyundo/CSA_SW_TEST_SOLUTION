from common.LogDeco import *
from common.Pickle_Api import *
from common.Excel_Parser import *
from common.Text_Parser import *
import time, datetime, numpy as np


class FileManager:

    def __init__(self):
        pass

    @Logdeco
    def isfile(self, file_path):
        if not os.path.isfile(file_path):
            return False
        return True

    @Logdeco
    def isdir(self, dir_path, create=False):
        if not os.path.isdir(dir_path):
            if create:
                os.makedirs(dir_path)
                return True
            else:
                return False
        return True

    @Logdeco
    def ismodified(self, file_path, temp_path):
        if self.isfile(file_path):
            if not self.isdir(temp_path):
                return False

            file_curr_date = time.ctime(os.path.getmtime(file_path))
            file_history = object_file_load(temp_path, "rb")

            if file_path not in file_history.keys():
                return False

            if file_curr_date == file_history[file_path]:
                return True
            else:
                return False

        return False

    @Logdeco
    def object_file_load(self, filename, mode):
        return object_file_load(filename, mode)

    @Logdeco
    def object_file_dump(self, filename, data, mode):
        return object_file_dump(filename, data, mode)

    @Logdeco
    def excel_read(self, file_name, sheet_name, log_level):
        return excel_read(file_name, sheet_name, log_level)

    @Logdeco
    def excel_write(self, file_name, sheet_name, data):
        return excel_write(file_name, sheet_name, data)

    @Logdeco
    def get_excelsheetnames(self, file_path):
        return excel_read_sheetnames(file_path)

    @Logdeco
    def txt_file_read(self, file_name, mode):
        return txt_file_read(file_name, mode)

    @Logdeco
    def txt_file_write(self, file_name, data, mode):
        txt_file_write(file_name, data, mode)

    @Logdeco
    def is_empty(self, data):
        if isinstance( data, np.ndarray):
            if not data.any():
                return True
        else:
            if not data:
                return True
        return False
