import os, sys, csv, shutil
from datetime import datetime
from io import open
import pickle_api as pa
import log_mod as log

##### Get Time Info #####
nowtime = datetime.now().strftime("%y%m%d_%H%M%S")
nowtime1 = datetime.now().strftime("%y/%m/%d %H:%M:%S")

def create_timing_csv(dic_project_info):
    log.set_log("REPORT", "create_timing_csv Processing...", log.Logtype_PFF)

    dic_trace_time_data = {}
    dic_trace_timing_merged_file = {}

    if not os.path.isdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\timing\\"):
        log.set_log("REPORT", "Timing folder path is not exist", log.Logtype_ERR)
        return False

    scenario_folderlist = os.listdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\timing\\")

    for scenario_name in scenario_folderlist:
        file_list = os.listdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\timing\\" + scenario_name)

        if not file_list:
            log.set_log("REPORT", scenario_name + "Timing Data Folder is empty", log.Logtype_ERR)
            return False

        if not os.path.isdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Report\\" + scenario_name + "\\timing_report_detail\\"):
            os.makedirs(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Report\\" + scenario_name + "\\timing_report_detail\\")

        for file_name in file_list:
            load_file_path = dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\timing\\" + scenario_name + "\\" + file_name
            log.set_log("REPORT", "Timing txt file load path : " + load_file_path, log.Logtype_DBG)
            save_file_path = dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Report\\" + scenario_name + "\\timing_report_detail\\" + file_name[:-4] + "_" + nowtime + ".csv"
            log.set_log("REPORT", "Timing dic file save path : " + save_file_path, log.Logtype_DBG)

            dic_timing_tracedata = pa.object_file_load(load_file_path, "rb")

            if 'trace_time_data.txt' == file_name:

                if scenario_name in dic_trace_time_data.keys():
                    dic_trace_time_data[scenario_name] = {}
                dic_trace_time_data[scenario_name] = dic_timing_tracedata.copy()

            if 'trace_timing_merged_file.txt' == file_name:

                if scenario_name in dic_trace_timing_merged_file.keys():
                    dic_trace_timing_merged_file[scenario_name] = {}
                dic_trace_timing_merged_file[scenario_name] = dic_timing_tracedata.copy()

            with open(save_file_path, 'wt', encoding='utf-8', newline='') as trace_timing_filewrite:
                csv_writer = csv.writer(trace_timing_filewrite)

                csv_writer.writerow(["<General Information>"])
                for k, v in dic_project_info['Test_Env'].items():
                    csv_writer.writerow([k, v])
                csv_writer.writerow([" "])

                csv_writer.writerow(["<Summary of Execution Time(us)>"])

                temp = []
                count = 0

                for func, timingdata in dic_timing_tracedata.items():
                    if "merged" in file_name:
                        if func == '(root)':
                            continue
                    temp.append(func)
                    if count == 0:
                        tmp = list(timingdata.keys())
                        tmp.insert(0, "")
                        csv_writer.writerow(tmp)
                        count = 1

                    for k1, v1 in timingdata.items():
                        if "merged" in file_name:
                            if 'ms' in v1:
                                v1 = v1.replace("ms", "")
                                tmp = float(v1)
                                tmp = tmp * 1000
                                v1 = str(tmp)
                            elif 'us' in v1:
                                v1 = v1.replace("us", "")
                            elif 's' in v1:
                                v1 = v1.replace("s", "")
                                tmp = float(v1)
                                tmp = tmp * 1000000
                                v1 = str(tmp)

                        temp.append(v1)

                    csv_writer.writerow(temp)
                    del temp[:]  # list contents delete

    if not pa.object_file_dump(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\timing\\dic_trace_time_data.txt", dic_trace_time_data, "wb"):
        log.set_log("REPORT", "trace_time_data Parsed Trace Data Pickle File Save Error", log.Logtype_ERR)
        return False
    if not pa.object_file_dump(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\timing\\dic_trace_timing_merged_file.txt", dic_trace_timing_merged_file, "wb"):
        log.set_log("REPORT", "trace_timing_merged_file Trace Data Pickle File Save Error", log.Logtype_ERR)
        return False
    log.set_log("REPORT", "create_timing_csv Processed", log.Logtype_PFF)
    return True