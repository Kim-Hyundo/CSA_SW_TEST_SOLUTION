from Mando.MandoInterfaceTest.lib.TestValueRange import *
from common import log_mod
from common.log_mod import *

def common_copy_1_0(data_tmp, origin_data):
    try:
        data_tmp["Index"] = origin_data["Index"]
        data_tmp["Sheet"] = "Sheet : " + origin_data["Sheet"] + " / Index : " + origin_data["Index"]

        data_tmp["Length"] = origin_data["Length"]

        data_tmp["Value Table"] = origin_data["Value Table"]

        data_tmp["Value Type"] = origin_data["Value Type"]

        data_tmp["Protocol"] = origin_data["Protocol"]

        data_tmp["Factor/Offset"] = origin_data["Factor"] + "/" + origin_data["Offset"]

        # 여기에서 부터 TC1(min), TC2(max), TC3(mid)의 Input, Output1, Output2 값을 채우는 부분
        data_result = getTestValueRange_1_0(data_tmp, origin_data)

        data_tmp["Min_Input"] = data_result["Min_Input"]
        data_tmp["Min_Output1"] = data_result["Min_Output1"]
        data_tmp["Min_Output2"] = data_result["Min_Output2"]

        data_tmp["Max_Input"] = data_result["Max_Input"]
        data_tmp["Max_Output1"] = data_result["Max_Output1"]
        data_tmp["Max_Output2"] = data_result["Max_Output2"]

        data_tmp["Mid_Input"] = data_result["Mid_Input"]
        data_tmp["Mid_Output1"] = data_result["Mid_Output1"]
        data_tmp["Mid_Output2"] = data_result["Mid_Output2"]
    except Exception as e:
        set_log('PARSE', "common_copy_1_0 Function Error" + str(e), log_mod.Logtype_ERR)
        raise

def common_copy_1_5(data_tmp, origin_data):
    try:
        data_tmp["Index"] = origin_data["Index"]
        data_tmp["Sheet"] = "Sheet : " + origin_data["Sheet"] + " / Index : " + origin_data["Index"]

        data_tmp["Length"] = origin_data["Length"]

        data_tmp["Data Type"] = origin_data["Data Type"]

        data_tmp["Value Table"] = origin_data["Value Table"]

        data_tmp["Value Type"] = origin_data["Value Type"]

        data_tmp["Protocol"] = origin_data["Protocol"]

        data_tmp["Factor/Offset"] = origin_data["Factor"] + "/" + origin_data["Offset"]

        # 여기에서 부터 TC1(min), TC2(max), TC3(mid)의 Input, Output1, Output2 값을 채우는 부분
        data_result = getTestValueRange_1_5(data_tmp, origin_data)

        data_tmp["Min_Input"] = data_result["Min_Input"]
        data_tmp["Min_Output1"] = data_result["Min_Output1"]
        data_tmp["Min_Output2"] = data_result["Min_Output2"]

        data_tmp["Max_Input"] = data_result["Max_Input"]
        data_tmp["Max_Output1"] = data_result["Max_Output1"]
        data_tmp["Max_Output2"] = data_result["Max_Output2"]

        data_tmp["Mid_Input"] = data_result["Mid_Input"]
        data_tmp["Mid_Output1"] = data_result["Mid_Output1"]
        data_tmp["Mid_Output2"] = data_result["Mid_Output2"]
    except Exception as e:
        set_log('PARSE', "common_copy_1_5 Function Error" + str(e), log_mod.Logtype_ERR)
        raise