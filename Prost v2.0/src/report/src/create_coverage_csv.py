from xml.dom import minidom
import xml.etree.ElementTree as elemTree
import os, sys, csv, shutil
from datetime import datetime
from io import open
import code_coverage_parser as cp
import pickle_api as pa
import log_mod as log

##### Get Time Info #####
nowtime = datetime.now().strftime("%y%m%d_%H%M%S")
nowtime1 = datetime.now().strftime("%y/%m/%d %H:%M:%S")

def create_coverage_csv(dic_project_info):
    log.set_log("REPORT", "create_coverage_csv Processing...", log.Logtype_PFF)

    if not cp.code_coverage_parser(dic_project_info, "coverage"):
        log.set_log("REPORT", "Coverage trace data parsing fail", log.Logtype_ERR)
        return False

    if not os.path.isdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\coverage\\cov"):
        log.set_log("REPORT", "Coverage dic folder path is not exist", log.Logtype_ERR)
        return False

    #scenario_folderlist = os.listdir(dic_path['WorkingProject_Path'] + "\\Debug\\dic\\coverage\\")

    load_file_path = dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\coverage\\cov\\cov_merge.txt"
    dic_coverage_tracedata = pa.object_file_load(load_file_path, "rb")

    for scenario_name, coverage_data in dic_coverage_tracedata.items():
        file_list = os.listdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\coverage\\cov")

        if not file_list:
            log.set_log("REPORT", scenario_name + "Coverage Data Folder is empty", log.Logtype_ERR)
            return False

        if not os.path.isdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Report\\" + scenario_name + "\\coverage_report_detail\\"):
            os.makedirs(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Report\\" + scenario_name + "\\coverage_report_detail\\")


        save_file_path = dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Report\\" + scenario_name + "\\coverage_report_detail\\cov_merge"+"_" + nowtime + ".csv"
            # save_file_path = save_file_path.replace(".txt", "")


        with open(save_file_path, 'wt', encoding='utf-8', newline='') as trace_coverage_filewrite:
            csv_writer = csv.writer(trace_coverage_filewrite)

            csv_writer.writerow(["<General Information>"])
            for k, v in dic_project_info['Test_Env'].items():
                csv_writer.writerow([k, v])
            csv_writer.writerow([" "])

            csv_writer.writerow(["<Summary of Code Coverage - Statement>"])

            temp = []
            count = 0

            for scenario, covdata in dic_coverage_tracedata.items():
                if scenario_name == scenario:
                    for covdatalist in covdata:

                        del covdatalist['0%50%100']
                        if count == 0:
                            tmp = list(covdatalist.keys())
                            csv_writer.writerow(tmp)
                            count = 1
                        if covdatalist['address'] == 'multiple':
                            continue
                        for k, v in covdatalist.items():
                            temp.append(v)

                        csv_writer.writerow(temp)
                        del temp[:]  # list contents delete

    log.set_log("REPORT", "create_coverage_csv Processed", log.Logtype_PFF)
    return True

def create_mcdc_coverage_csv(dic_project_info):
    log.set_log("REPORT", "create_mcdc_coverage_csv Processing...", log.Logtype_PFF)

    if not cp.code_coverage_parser(dic_project_info, "mcdc_cov"):
        log.set_log("REPORT", "MC/DC Coverage trace data parsing fail", log.Logtype_ERR)
        return False

    if not os.path.isdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\mcdc_cov\\cov"):
        log.set_log("REPORT", "MC/DC Coverage dic folder path is not exist", log.Logtype_ERR)
        return False


    #scenario_folderlist = os.listdir(dic_path['WorkingProject_Path'] + "\\Debug\\dic\\coverage\\")

    load_file_path = dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\mcdc_cov\\cov\\cov_merge.txt"
    dic_coverage_tracedata = pa.object_file_load(load_file_path, "rb")

    for scenario_name, coverage_data in dic_coverage_tracedata.items():
        file_list = os.listdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\mcdc_cov\\cov")

        if not file_list:
            log.set_log("REPORT", scenario_name + "MC/DC Coverage Data Folder is empty", log.Logtype_ERR)
            return False

        if not os.path.isdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Report\\" + scenario_name + "\\coverage_report_detail\\"):
            os.makedirs(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Report\\" + scenario_name + "\\coverage_report_detail\\")


        save_file_path = dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Report\\" + scenario_name + "\\coverage_report_detail\\mcdc_coverage"+"_" + nowtime + ".csv"
            # save_file_path = save_file_path.replace(".txt", "")


        with open(save_file_path, 'wt', encoding='utf-8', newline='') as trace_coverage_filewrite:
            csv_writer = csv.writer(trace_coverage_filewrite)

            csv_writer.writerow(["<General Information>"])
            for k, v in dic_project_info['Test_Env'].items():
                csv_writer.writerow([k, v])
            csv_writer.writerow([" "])

            csv_writer.writerow(["<Summary of Code Coverage - MC/DC>"])

            temp = []
            count = 0

            for scenario, covdata in dic_coverage_tracedata.items():
                if scenario_name == scenario:
                    for covdatalist in covdata:

                        del covdatalist['0%50%100']
                        if count == 0:
                            tmp = list(covdatalist.keys())
                            csv_writer.writerow(tmp)
                            count = 1
                        if covdatalist['address'] == 'multiple':
                            continue
                        for k, v in covdatalist.items():
                            temp.append(v)

                        csv_writer.writerow(temp)
                        del temp[:]  # list contents delete

    log.set_log("REPORT", "create_mcdc_coverage_csv Processed", log.Logtype_PFF)
    return True