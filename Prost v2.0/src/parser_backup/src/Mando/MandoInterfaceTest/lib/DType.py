from Mando.MandoInterfaceTest.lib.TestValueRange import *
from common import log_mod
from common.log_mod import *

def DType_test_1_0(data_tmp, origin_data):
    try:
        data_tmp["Input"] = origin_data["ModelVar"]
        data_tmp["Output1"] = origin_data["Message"] + " :: " + origin_data["Signal Name"]
        data_tmp["Output2"] = ""
    except Exception as e:
        set_log('PARSE', "DType_test_1_0 Function Error" + str(e), log_mod.Logtype_ERR)
        raise

def DType_test_1_5(data_tmp, origin_data):
    try:
        data_tmp["Input"] = "mo_IVC." + origin_data["Message"] + "." + origin_data["Signal Name"]
        data_tmp["Output1"] = origin_data["Message"] + " :: " + origin_data["Signal Name"]
        data_tmp["Output2"] = ""
    except Exception as e:
        set_log('PARSE', "DType_test_1_5 Function Error" + str(e), log_mod.Logtype_ERR)
        raise