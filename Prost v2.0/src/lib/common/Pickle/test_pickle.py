import Pickle_Api as pa


def Origin_TC_Load(path):
    dic_test_result = pa.object_file_load(path, "rb")
    return dic_test_result
    
def Precondition_TC_Load(path):
    dic_test_result = pa.object_file_load(path, "rb")
    return dic_test_result

def Modi_TC_dump(a,path):
    a_dic = list(a)
    dump_result = pa.object_file_dump(path, a_dic, 'wb')

def Regi_TC_dump(a,path):
    a_dic = dict(a)
    dump_result = pa.object_file_dump(path, a_dic, 'wb')


def dictionary_dump(R_dictionary):
    R_dictionary_py = dict(R_dictionary)
    dump_result = pa.object_file_dump('R_path_dictionary.txt', R_dictionary_py, 'wb')
    return dump_result

def Report_dictionary_dump(R_dictionary,path):
    R_dictionary_py = dict(R_dictionary)
    dump_result = pa.object_file_dump(path, R_dictionary_py, 'wb')
    return dump_result

def Compile_dictionary_dump(R_dictionary, path):
    R_dictionary_py = dict(R_dictionary)
    dump_result = pa.object_file_dump(path, R_dictionary_py, 'wb')
    return dump_result

def GUI_Parameter(R_dictionary, path):
    R_dictionary_py = dict(R_dictionary)
    dump_result = pa.object_file_dump(path, R_dictionary_py, 'wb')
    return dump_result

def STUB_LIST_dump(a, path):
    a_dic = list(a)
    dump_result = pa.object_file_dump(path, a_dic, 'wb')
    return dump_result


def Paser_dictionary_dump(R_dictionary, path):
    R_dictionary_py = dict(R_dictionary)
    dump_result = pa.object_file_dump(path, R_dictionary_py, 'wb')
    return dump_result
