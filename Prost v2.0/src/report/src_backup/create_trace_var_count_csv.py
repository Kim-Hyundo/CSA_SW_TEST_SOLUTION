import os, sys, csv, shutil
from datetime import datetime
from io import open
import pickle_api as pa
import log_mod as log

##### Get Time Info #####
nowtime = datetime.now().strftime("%y%m%d_%H%M%S")
nowtime1 = datetime.now().strftime("%y/%m/%d %H:%M:%S")

def create_trace_var_count_csv(dic_project_info):
    log.set_log("REPORT", "create_trace_var_count_csv Processing...", log.Logtype_PFF)

    dic_trace_var_count = {}
    dic_trace_timing_merged_file = {}

    if not os.path.isdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\trace\\"):
        log.set_log("REPORT", "Trace folder path is not exist", log.Logtype_ERR)
        return False

    scenario_folderlist = os.listdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\trace\\")

    for scenario_name in scenario_folderlist:
        file_list = os.listdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\trace\\" + scenario_name)

        if not file_list:
            log.set_log("REPORT", scenario_name + "Trace Var Count Folder is empty", log.Logtype_ERR)
            return False

        if not os.path.isdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Report\\" + scenario_name + "\\trace_var_count_report_detail\\"):
            os.makedirs(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Report\\" + scenario_name + "\\trace_var_count_report_detail\\")

        for file_name in file_list:
            load_file_path = dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\trace\\" + scenario_name + "\\" + file_name
            log.set_log("REPORT", "Trace Var Count dic file load path : " + load_file_path, log.Logtype_DBG)
            save_file_path = dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Report\\" + scenario_name + "\\trace_var_count_report_detail\\var_count_report"+"_" + nowtime + ".csv"
            log.set_log("REPORT", "Trace Var Count csv file save path : " + save_file_path, log.Logtype_DBG)

            dic_trace_var_count = pa.object_file_load(load_file_path, "rb")

            if 'trace_var_merged_dic.txt' == file_name:

                with open(save_file_path, 'wt', encoding='utf-8', newline='') as trace_var_count_filewrite:
                    csv_writer = csv.writer(trace_var_count_filewrite)

                    csv_writer.writerow(["<General Information>"])
                    for k, v in dic_project_info['Test_Env'].items():
                        csv_writer.writerow([k, v])
                    csv_writer.writerow([" "])

                    count = 0

                    csv_writer.writerow(["<Var Count Result>"])

                    for varname, info in dic_trace_var_count.items():
                        if count == 0:
                            csv_writer.writerow(list(info.keys()))
                            count = 1
                        csv_writer.writerow(list(info.values()))

    log.set_log("REPORT", "create_trace_var_count_csv Processed", log.Logtype_PFF)

    return True