from Mando.MandoInterfaceTest.lib.Converter import *
from common import log_mod
from common.log_mod import *

def CType_test_1_0(data_tmp, origin_data, alldata):
    try:
        other_sheet_data = get_otherSheetData(alldata, origin_data["Sender"])

        find_data = find_dataFromOtherSheet(other_sheet_data, "Signal Name", origin_data["Signal Name"])

        if other_sheet_data is None or find_data is None:
            return False

        data_tmp["Input"] = find_data["ModelVar"]
        data_tmp["Output1"] = origin_data["ModelVar"]
        data_tmp["Output2"] = ""
    except Exception as e:
        set_log('PARSE', "CType_test_1_0 Function Error" + str(e), log_mod.Logtype_ERR)
        raise

def CType_test_1_5(data_tmp, origin_data, alldata):
    try:
        out_group_check = False

        data_tmp["Input"] = "MsgGr_" + origin_data["L1_Group_Name"] + "_" + origin_data["Sheet"]
        data_tmp["Output1"] = "MsgGr_" + origin_data["L1_Group_Name"] + "_" + origin_data["Destination"] + "->"

        if origin_data["L2_Group_Name"] != "":
            data_tmp["Input"] += "." + origin_data["L2_Group_Name"]
            data_tmp["Output1"] += origin_data["L2_Group_Name"]
            out_group_check = True

        if out_group_check:
            for i in range(3, 11):
                group_name = "L" + str(i) + "_Group_Name"
                group_size = "L" + str(i) + "_Group_Size"
                if origin_data[group_name] == "" or origin_data[group_size] == "":
                    continue

                data_tmp["Input"] += "." + origin_data[group_name]
                data_tmp["Output1"] += "." + origin_data[group_name]

        data_tmp["Input"] += "." + origin_data["Signal Name"]
        if out_group_check:
            data_tmp["Output1"] += "." + origin_data["Signal Name"]
        else:
            data_tmp["Output1"] += origin_data["Signal Name"]

        data_tmp["Output2"] = ""

    except Exception as e:
        set_log('PARSE', "CType_test_1_5 Function Error" + str(e), log_mod.Logtype_ERR)
        raise
