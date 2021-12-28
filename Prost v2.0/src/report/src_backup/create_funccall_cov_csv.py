#!/usr/bin/python3.5
# -*- coding: utf-8 -*-

"""
Project : Report Module
Program Name : main.py
Author : Hyundo Kim
Date : 20.03.26
Description : Report Module Main
"""

import os, sys
from datetime import datetime
import pickle_api as pa
import log_mod as log
import os, sys, csv, shutil

##### Get Time Info #####
nowtime = datetime.now().strftime("%y%m%d_%H%M%S")
nowtime1 = datetime.now().strftime("%y/%m/%d %H:%M:%S")

#dic_path = {}
#dic_path['WorkingProject_Path'] = r"C:\Git\Prost_New\Workspace\Project_Name\Gen\202004291343_DataSaveTest"

def create_func_cov_csv(dic_project_info):
    log.set_log("REPORT", "create_func_cov_csv Processing...", log.Logtype_PFF)

    dic_data_merge = {}

    dic_allfunc_list = pa.object_file_load(
        dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\funclist\\allfunc_list\\dic_allfunc_list.txt", "rb")
    dic_func_cov = pa.object_file_load(
        dic_project_info['Common_Path']['WorkingProject_Path'] +"\\Debug\\dic\\funccov\\dic_func_cov.txt", "rb")

    log.set_log("REPORT", "dic_allfunc_list : " + str(dic_allfunc_list), log.Logtype_DBG)
    log.set_log("REPORT", "dic_func_cov : " + str(dic_func_cov), log.Logtype_DBG)

    for k, v in dic_func_cov.items():
        if not k in dic_data_merge.keys():
            dic_data_merge[k] = {}
            temp1={}

        for k1, v1 in v.items():
            temp = {}
            temp['Function'] = k1
            temp['Coverage'] = v1
            if not 'FunctionList' in temp1.keys():
                temp1['FunctionList'] = []
            temp1['FunctionList'].append(temp)
        dic_data_merge[k]=temp1.copy()

    log.set_log("REPORT", "1.dic_data_merge : " + str(dic_data_merge), log.Logtype_DBG)

    for k, v in dic_data_merge.items():
        for v5 in v.values():
            for v1 in v5:
                for k2, v2 in dic_allfunc_list.items():
                    for k3, v3 in v2.items():
                        if k3 == v1['Function']:
                            v1['AddressRange'] = v3

    log.set_log("REPORT", "2.dic_data_merge : " + str(dic_data_merge), log.Logtype_DBG)

    for scenario_name, contents in dic_data_merge.items():
        for funclist in contents['FunctionList']:
            for file, funcinfiles  in dic_allfunc_list['FuncInFiles'].items():
                for function in funcinfiles:
                    if funclist['Function'] == function:
                        funclist['File'] = file.replace('.txt', '.c')

    log.set_log("REPORT", "3.dic_data_merge : " + str(dic_data_merge), log.Logtype_DBG)

    for scenario_name, function_list in dic_func_cov.items():

        funccov_true_cnt = 0
        funccov_false_cnt = 0
        save_file_path = dic_project_info['Common_Path'][
                             'WorkingProject_Path'] + "\\Report\\" + scenario_name + "\\coverage_report_detail\\" + "Function_Coverage_" + nowtime + ".csv"

        for function_name, TF in function_list.items():

            if TF == 'True':
                funccov_true_cnt += 1
                #print('true : ' + function_name)
            else:
                funccov_false_cnt += 1
                #print('fail : '+ function_name)

        funccov_rate = str((funccov_true_cnt / len(dic_allfunc_list['AllFuncList'])) * 100)

        for k, v in dic_data_merge.items():
            if k == scenario_name:
                if not 'Result' in v.keys():
                    v['Result'] = {}
                temp = {}
                temp["FuncCovRate"] = funccov_rate + "%"
                temp["AllFuncCnt"] = funccov_true_cnt + funccov_false_cnt
                temp["FuncCovTrueCnt"] = funccov_true_cnt
                temp["FuncCovFalseCnt"] = funccov_false_cnt

                v['Result'] = temp.copy()

        log.set_log("REPORT", "4.dic_data_merge : " + str(dic_data_merge), log.Logtype_DBG)

        with open(save_file_path, 'wt', encoding='utf-8', newline='') as function_coverage_filewrite:
            csv_writer = csv.writer(function_coverage_filewrite)

            csv_writer.writerow(["<General Information>"])
            for k, v in dic_project_info['Test_Env'].items():
                csv_writer.writerow([k, v])
            csv_writer.writerow([" "])

            csv_writer.writerow(["<All Function List>"])
            csv_writer.writerow(["File", "Function Name", "Address Range", "True/False"])

            for list in dic_data_merge[scenario_name]['FunctionList']:
                csv_writer.writerow([list['File'], list['Function'], list['AddressRange'], list['Coverage']])

            """
            for k, v in dic_allfunc_list.items():
                for function, address_range in v.items():
                    for scenario, function_TF in dic_func_cov.items():
                        if scenario == scenario_name:
                            for function2, TF in function_TF.items():
                                if function == function2:
                                    csv_writer.writerow([function, address_range, TF])
            """
            csv_writer.writerow([""])

            csv_writer.writerow(["<Function Coverage Result>"])
            csv_writer.writerow(["Coverage Rate", funccov_rate + "%"])
            csv_writer.writerow(["All Function Count", len(dic_allfunc_list['AllFuncList'])])
            csv_writer.writerow(["True Function Count", funccov_true_cnt])
            csv_writer.writerow(["False Function Count", funccov_false_cnt])


    if not pa.object_file_dump(dic_project_info['Common_Path']['WorkingProject_Path'] + '\\Debug\\dic\\funccov\\dic_func_cov_result.txt', dic_data_merge, "wb"):
        log.set_log("REPORT", "Parsed Trace Data Pickle File Save Error", log.Logtype_ERR)
        return False

    log.set_log("REPORT", "create_func_cov_csv Processed", log.Logtype_PFF)
    return True

def create_call_cov_csv(dic_project_info):
    log.set_log("REPORT", "create_call_cov_csv Processing...", log.Logtype_PFF)

    dic_data_merge = {}

    dic_allfunc_list = pa.object_file_load(
        dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\funclist\\allfunc_list\\dic_allfunc_list.txt", "rb")
    dic_func_call_list = pa.object_file_load(
        dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\funclist\\funccall_list\\dic_funccall_list.txt", "rb")
    dic_call_cov = pa.object_file_load(
        dic_project_info['Common_Path']['WorkingProject_Path'] +"\\Debug\\dic\\callccov\\dic_call_cov.txt", "rb")

    log.set_log("REPORT", "dic_allfunc_list : " + str(dic_allfunc_list), log.Logtype_DBG)
    log.set_log("REPORT", "dic_func_call_list : " + str(dic_func_call_list), log.Logtype_DBG)
    log.set_log("REPORT", "dic_call_cov : " + str(dic_call_cov), log.Logtype_DBG)

    for scenario_name, call_cov_result_list in dic_call_cov.items():
        for call_list in dic_func_call_list:
            temp1 = {}
            temp1['Function'] = call_list['CallerFunction']
            temp1['Coverage'] = 'False'
            if not scenario_name in dic_data_merge.keys():
                dic_data_merge[scenario_name] = []
            temp = []

            for call_cov_result in call_cov_result_list:
                if call_list['Address'] == call_cov_result['Address']:
                    if call_cov_result['Coverage'] == 'True':
                        temp.append(call_cov_result['TestCase'])
                        temp1['Coverage'] = 'True'

                    temp1['CalledFunction'] = call_cov_result['CalledFunction']
                    temp1['FuncCallType'] = call_cov_result['FuncCallType']
                    temp1['Address'] = call_cov_result['Address']

            #if len(temp) != 0:
            temp1['TestCase'] = temp
            dic_data_merge[scenario_name].append(temp1)

    log.set_log("REPORT", "dic_data_merge : " + str(dic_data_merge), log.Logtype_DBG)

    dic_data_merge_final = dic_data_merge.copy()

    for scenario_name, function_list in dic_data_merge_final.items():
        temp={}
        temp['FunctionList'] = function_list
        dic_data_merge_final[scenario_name] = temp

    log.set_log("REPORT", "1.dic_data_merge_final : " + str(dic_data_merge), log.Logtype_DBG)

    for scenario_name, contents in dic_data_merge_final.items():
        for funclist in contents['FunctionList']:
            for file, funcinfiles  in dic_allfunc_list['FuncInFiles'].items():
                for function in funcinfiles:
                    if funclist['Function'] == function:
                        funclist['File'] = file.replace('.txt', '.c')

    log.set_log("REPORT", "2.dic_data_merge_final : " + str(dic_data_merge), log.Logtype_DBG)

    #Calculate Call Coverage Rate
    total_call_count = len(dic_func_call_list)
    for scenario_name, merge_call_cov_list in dic_data_merge.items():
        real_call_count = 0
        for call_cov_result in merge_call_cov_list:
            if call_cov_result['Coverage'] == 'True':
                real_call_count += 1
        call_cov_rate = str((real_call_count / total_call_count) * 100) + "%"

        for k, v in dic_data_merge_final.items():
            if k == scenario_name:

                temp = {}
                temp["CallCovRate"] = call_cov_rate
                temp["CallCovTotalCnt"] = total_call_count
                temp["CallCovTrueCnt"] = real_call_count
                temp["CallCovFalseCnt"] = total_call_count - real_call_count

                dic_data_merge_final[scenario_name]['Result'] = temp.copy()

    log.set_log("REPORT", "3.dic_data_merge_final : " + str(dic_data_merge), log.Logtype_DBG)
    """
    for scenario_name, merge_call_cov_list in dic_data_merge.items():
        real_call_count = 0
        for call_cov_result in merge_call_cov_list:
            for call_cov_list in dic_func_call_list:
                if call_cov_list['Address'] == call_cov_result['Address']:
                    real_call_count += 1
        call_cov_rate = str((real_call_count/total_call_count)*100) + "%"

        for k, v in dic_data_merge_final.items():
            if k == scenario_name:

                temp = {}
                temp["CallCovRate"] = call_cov_rate
                temp["CallCovTotalCnt"] = total_call_count
                temp["CallCovRealCnt"] = real_call_count

                dic_data_merge_final[scenario_name]['Result'] = temp.copy()

    """
    #Create CSV File
    for scenario_name, call_cov_list in dic_data_merge.items():
        save_file_path = dic_project_info['Common_Path'][
                             'WorkingProject_Path'] + "\\Report\\" + scenario_name + "\\coverage_report_detail\\" + "Call_Coverage_" + nowtime + ".csv"

        with open(save_file_path, 'wt', encoding='utf-8', newline='') as function_coverage_filewrite:
            csv_writer = csv.writer(function_coverage_filewrite)

            csv_writer.writerow(["<General Information>"])
            for k, v in dic_project_info['Test_Env'].items():
                csv_writer.writerow([k, v])
            csv_writer.writerow([" "])


            csv_writer.writerow(["<Call Coverage List>"])
            csv_writer.writerow(["File", "Function Name", "Function Call List", "Address", "Call Instruction",  "True/False", "Test Case"])

            temp_display = ""
            for call_cov_result in call_cov_list:
                if temp_display == call_cov_result['Function']:
                    csv_writer.writerow(["", "", call_cov_result['CalledFunction'], '0x' + call_cov_result['Address'],
                                         call_cov_result['FuncCallType'], call_cov_result['Coverage'],
                                         call_cov_result['TestCase']])
                else:
                    temp_display = call_cov_result['Function']
                    csv_writer.writerow([call_cov_result['File'], temp_display, call_cov_result['CalledFunction'], '0x' + call_cov_result['Address'],
                                            call_cov_result['FuncCallType'], call_cov_result['Coverage'], call_cov_result['TestCase']])
            csv_writer.writerow([" "])

            csv_writer.writerow(["<Call Coverage Result>"])
            csv_writer.writerow(["Call Coverage Rate", dic_data_merge_final[scenario_name]['Result']['CallCovRate']])
            csv_writer.writerow(
                ["Call Coverage Total Count", dic_data_merge_final[scenario_name]['Result']['CallCovTotalCnt']])
            csv_writer.writerow(
                ["Call Coverage True Count", dic_data_merge_final[scenario_name]['Result']['CallCovTrueCnt']])
            csv_writer.writerow(
                ["Call Coverage False Count", dic_data_merge_final[scenario_name]['Result']['CallCovFalseCnt']])
            csv_writer.writerow([" "])

    if not pa.object_file_dump(dic_project_info['Common_Path']['WorkingProject_Path'] + '\\Debug\\dic\\callccov\\dic_call_cov_result.txt', dic_data_merge_final, "wb"):
        log.set_log("REPORT", "Parsed Trace Data Pickle File Save Error", log.Logtype_ERR)
        return False

    log.set_log("REPORT", "create_call_cov_csv Processed", log.Logtype_PFF)
    return True

#create_call_cov_csv(dic_path)
#create_func_cov_csv(dic_path)