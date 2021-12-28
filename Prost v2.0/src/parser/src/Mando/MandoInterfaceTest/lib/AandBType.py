from common import log_mod
from common.log_mod import *

def AandBType_test_1_0(data_tmp, origin_data):
    try:
        origin_data["Message"] = origin_data["Message"].replace("_ASW", "", 1)
        data_tmp["Input"] = origin_data["Message"] + " :: " + origin_data["Signal Name"]
        data_tmp["Output1"] = "MsgGr_" + origin_data["Message"] + "_" + origin_data["SWC"] + "->" + origin_data["Signal Name"]
        data_tmp["Output2"] = origin_data["ModelVar"]
    except Exception as e:
        set_log('PARSE', "AandBType_test_1_0 Function Error" + str(e), log_mod.Logtype_ERR)
        raise


def AandBType_test_1_5(data_tmp, origin_data):
    try:
        origin_data["Message"] = origin_data["Message"]
        data_tmp["Input"] = origin_data["Message"] + " :: " + origin_data["Signal Name"]
        data_tmp["Output1"] = "MsgGr_" + origin_data["Message"] + "_" + origin_data["Sheet"] + "->" + origin_data["Signal Name"]
        #data_tmp["Output2"] = origin_data["ModelVar"]
        data_tmp["Output2"] = ""
    except Exception as e:
        set_log('PARSE', "AandBType_test_1_5 Function Error" + str(e), log_mod.Logtype_ERR)
        raise