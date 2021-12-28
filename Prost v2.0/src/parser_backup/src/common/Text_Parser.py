import os
from common.log_mod import *
from common import log_mod


def txt_file_read(file_name, mode):
    try:
        if not os.path.exists(file_name):
            f = open(file_name, 'w',encoding="utf-8")
            f.close()
        
        f = open(file_name, 'r')

        if mode == 1:
            data_dump = f.readlines()
        if mode == 2:
            data_dump = f.read()

        #set_log('PARSE',       "txt_file_reader() File Read, data_dump = " + str(data_dump) + "Read Complete",log_mod.Logtype_INF)

        f.close()
    except Exception as ex:
        set_log('PARSE', "file read Exception : " + str(ex), log_mod.Logtype_ERR)
        return None

    return data_dump

def txt_file_write(file_name, data_dump, mode):
    f = open(file_name, mode,encoding="utf-8")
    for tmp in data_dump:
        f.write(tmp)
    f.close()
