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
import shutil

import create_report_csv as rep_csv
import create_coverage_csv as cov_csv
import create_timing_csv as time_csv
import create_funccall_cov_csv as funccall_cov_csv
import create_trace_var_count_csv as var_count_csv

import allfunc_list_parser as aflp
import funccall_cov_list_parser as fcclp

import pickle_api as pa
import log_mod as log


##### Release #####
def main(path1):

    dic_project_info = pa.object_file_load(path1, "rb")

    log.G_Log_level = int(dic_project_info['Log']['Log_Level'])

    log.set_log("REPORT", "Report Module Processing...", log.Logtype_PRG)    
    log.set_log("REPORT", path1 + " : " + str(dic_project_info), log.Logtype_INF)
    
    dic_project_info['Common_Path']['XML_Path'] = dic_project_info['Common_Path']['BuildProject_Path'] + "\\Build\\" + \
                                                  dic_project_info['Test_Env']['Test_Component'] + ".mapxml"

    #General Information File Copy for Report UI
    shutil.copyfile(dic_project_info['Common_Path']['Project_Root_Path'] + '\\Temp\\R_test_dictionary.txt', \
                    dic_project_info['Common_Path']['WorkingProject_Path'] + '\\Debug\\dic\\project_info\\R_test_dictionary.txt')

    for scenario, test_result in dic_project_info['Report']['Test_Info'].items():
        autogen_false_idx_list = []
        if dic_project_info['Report']['AutoGen_En'] == True:
            for index, value in enumerate(test_result): #Sorting AutoGen=False Data
                if value['AutoGen'] == False:
                    autogen_false_idx_list.append(value)
            for value in autogen_false_idx_list:
                test_result.remove(value)

        if not rep_csv.create_report_csv(dic_project_info, scenario, test_result):
            log.set_log("REPORT", "Report csv create fail", log.Logtype_ERR)
            return False
        if not rep_csv.create_statistics_csv(dic_project_info, scenario, test_result):
            log.set_log("REPORT", "Statistics csv create fail", log.Logtype_ERR)
            return False

    if dic_project_info['Report']['AD_File_Opt'] == "TRUE":
        if not aflp.allfunc_list_parser(dic_project_info):
            log.set_log("REPORT", "Func Coverage report csv create fail", log.Logtype_ERR)
            return False

        if not cov_csv.create_coverage_csv(dic_project_info):
            log.set_log("REPORT", "Statement Coverage report csv create fail", log.Logtype_ERR)
            return False

        if not cov_csv.create_mcdc_coverage_csv(dic_project_info):
            log.set_log("REPORT", "MC/DC Coverage report csv create fail", log.Logtype_ERR)
            return False

        if not time_csv.create_timing_csv(dic_project_info):
            log.set_log("REPORT", "Timing report csv create fail", log.Logtype_ERR)
            return False

        if not fcclp.func_cov_list_parser(dic_project_info):
            log.set_log("REPORT", "Func Coverage report csv create fail", log.Logtype_ERR)
            return False

        if not fcclp.call_cov_list_parser(dic_project_info):
            log.set_log("REPORT", "Call Coverage report csv create fail", log.Logtype_ERR)
            return False

        if not funccall_cov_csv.create_func_cov_csv(dic_project_info):
            log.set_log("REPORT", "Func Coverage report csv create fail", log.Logtype_ERR)
            return False

        if not funccall_cov_csv.create_call_cov_csv(dic_project_info):
            log.set_log("REPORT", "Call Coverage report csv create fail", log.Logtype_ERR)
            return False
        
        if not var_count_csv.create_trace_var_count_csv(dic_project_info):
            log.set_log("REPORT", "Trace Var Count report csv create fail", log.Logtype_ERR)
            return False

    return True

if __name__ == "__main__":
    path1 = str(sys.argv[1])
    result = main(path1)
    
    if result:
        log.set_log("REPORT", "Report Module Pass", log.Logtype_PRG)
    else:
        log.set_log("REPORT", "Report Module Fail", log.Logtype_PRG)


"""




##### Debug #####
def main():


    # Read Dictionary File, Path
    dic_project_info = pa.object_file_load(r"C:\HyundoKim\Development\2.Mando\FailSafe\MANDO_FailSafe\Temp\C_PROJECT_INFO_DATA_dictionary.txt", "rb")

    dic_project_info['Log']['Log_Level'] = 1
    log.G_Log_level = int(dic_project_info['Log']['Log_Level'])

    dic_testtttttt = pa.object_file_load(
        r"C:\HyundoKim\Development\2.Mando\FailSafe\MANDO_FailSafe\Gen\20201203_FailSafe\Failsafe_TestSpec\Debug\dic\trace\DCU15_FAILSAFE_001\trace_var_merged_dic.txt", "rb")

    dic_allfunc_list = pa.object_file_load(r"C:\Git\Prost_New\Workspace\Project_Name\Gen\202004291343_DataSaveTest\Debug\dic\funclist\allfunc_list\dic_allfunc.txt", "rb")
    dic_funccall_list = pa.object_file_load(
        r"C:\Git\Prost_New\Workspace\Project_Name\Gen\202004291343_DataSaveTest\Debug\dic\funclist\funccall_list\dic_funccall_list.txt",
        "rb")
    dic_func_cov = pa.object_file_load(
        r"C:\Git\Prost_New\Workspace\Project_Name\Gen\202004291343_DataSaveTest\Debug\dic\funccov\dic_func_cov_result.txt",
        "rb")
    dic_call_cov = pa.object_file_load(
        r"C:\Git\Prost_New\Workspace\Project_Name\Gen\202004291343_DataSaveTest\Debug\dic\callccov\dic_call_cov_result.txt",
        "rb")
    dic_testttttt = pa.object_file_load(
        r"C:\Git\Prost_New\Workspace\Project_Name\Gen\202004291343_DataSaveTest\Debug\dic\test_result\test_result.txt",
        "rb")
    dic_testttttt1 = pa.object_file_load(
        r"C:\Git\Prost_New\Workspace\Project_Name\Gen\202004291343_DataSaveTest\Debug\dic\report_summary\report_summary.txt",
        "rb")
    dic_general_info = pa.object_file_load(
        r"C:\Git\Prost_New\Workspace\Project_Name\Temp\R_test_dictionary.txt",
        "rb")

    dic_timing_test = pa.object_file_load(
        r"C:\Git\Prost_New\Workspace\Project_Name\Gen\202004291343_DataSaveTest\Debug\dic\timing\dic_trace_timing_merged_file.txt",
        "rb")


    # Path Info Data for Debug
    dic_project_info['Common_Path'][
        'WorkingProject_Path'] = r'C:\HyundoKim\Development\2.Mando_New\WorkSpace\MANDO_FailSafe_Integration\Gen\20210421_TRACE32_20_02\Failsafe-TestSpec_RS4_0104 (1)'
    dic_project_info['Common_Path'][
        'BuildProject_Path'] = r'C:\HyundoKim\Development\2.Mando\FailSafe\MANDO_FailSafe\Gen\20201203_FailSafe'
    dic_project_info['Common_Path']['XML_Path'] = dic_project_info['Common_Path']['BuildProject_Path'] + "\\Build\\" + \
                                                  dic_project_info['Test_Env']['Test_Component'] + ".mapxml"
    dic_project_info['Common_Path']['Project_Root_Path'] = r"C:\HyundoKim\Development\2.Mando\FailSafe\MANDO_FailSafe"
    dic_project_info['Common_Path']['Workspace'] = r"C:\HyundoKim\Development\2.Mando\FailSafe\Workspace"
    # debug
    #dic_project_info['Report']['Stack_Info']['SWITS-002-1']['Stack End Address'] = "0x01"
    #dic_project_info['Report']['Stack_Info']['SWITS-002-1']['Stack Pointer'] = "0x01"
    #dic_project_info['Report']['Stack_Info']['SWITS-002-1']['Stack Start Address'] = "0x01"
    #dic_project_info['Report']['Stack_Info']['SWITS-002-2']['Stack End Address'] = "0x01"
    #dic_project_info['Report']['Stack_Info']['SWITS-002-2']['Stack Pointer'] = "0x01"
    #dic_project_info['Report']['Stack_Info']['SWITS-002-2']['Stack Start Address'] = "0x01"
    #dic_project_info['Report']['AD_File_Opt'] = 'True'
    # debug

    #dic_project_info['Test_Env']['Test_Code_List'].append('IDC_Main.c')
    #dic_project_info['Test_Env']['Test_Code_List'].append('test.c')

    #if not 'Test SW List' in dic_project_info.keys():
    #    dic_project_info['Test SW List'] = []
    #dic_project_info['Test SW List'].append('VC.c')
    #dic_project_info['Test SW List'].append('VC1.c')


    #del dic_test_result['SWITS-002-2']
    #for k, v in dic_test_result.items():
    #    # print(k, v)
    #    temp = v[0]
    #    temp['Execution time']['VC_Step2()'] = '100'
    #    # dic_test_result['SWITS-002-1']

    #dic_project_info['Report']['AD_File_Opt'] = False


    log.set_log("REPORT", "Report Module Processing...", log.Logtype_PRG)
    log.set_log("REPORT", str(dic_project_info), log.Logtype_INF)

    #log.set_log("REPORT", str(dic_path), log.Logtype_INF)
    #log.set_log("REPORT", str(dic_test_result), log.Logtype_INF)
    #log.set_log("REPORT", str(dic_stack_info), log.Logtype_INF)

    shutil.copyfile(dic_project_info['Common_Path']['Project_Root_Path'] + '\\Temp\\R_test_dictionary.txt', \
                    dic_project_info['Common_Path']['WorkingProject_Path'] + '\\Debug\\dic\\project_info\\R_test_dictionary.txt')

    #for list in dic_project_info['Report']['Test_Info']['SWITS-002-2']:
    #    list['Execution time']['VC_Step3()'] = 'N/A'



    for scenario, test_result in dic_project_info['Report']['Test_Info'].items():
        autogen_false_idx_list = []
        if dic_project_info['Report']['AutoGen_En'] == True:
            for index, value in enumerate(test_result):  # Sorting AutoGen=False Data
                if value['AutoGen'] == False:
                    autogen_false_idx_list.append(value)
            for value in autogen_false_idx_list:
                test_result.remove(value)

        if not rep_csv.create_report_csv(dic_project_info, scenario, test_result):
            log.set_log("REPORT", "Report csv create fail", log.Logtype_ERR)
            return False
        if not rep_csv.create_statistics_csv(dic_project_info, scenario, test_result):
            log.set_log("REPORT", "Statistics csv create fail", log.Logtype_ERR)
            return False
    
    if dic_project_info['Report']['AD_File_Opt'] == "TRUE":
        #if not aflp.allfunc_list_parser_from_mapxml(dic_project_info):
        if not aflp.allfunc_list_parser(dic_project_info):
            log.set_log("REPORT", "Func Coverage report csv create fail", log.Logtype_ERR)
            return False
    
        if not cov_csv.create_coverage_csv(dic_project_info):
            log.set_log("REPORT", "Coverage report csv create fail", log.Logtype_ERR)
            return False

        if not cov_csv.create_mcdc_coverage_csv(dic_project_info):
            log.set_log("REPORT", "MC/DC Coverage report csv create fail", log.Logtype_ERR)
            return False
    
        if not time_csv.create_timing_csv(dic_project_info):
            log.set_log("REPORT", "Timing report csv create fail", log.Logtype_ERR)
            return False
    
        if not fcclp.func_cov_list_parser(dic_project_info):
            log.set_log("REPORT", "Func Coverage report csv create fail", log.Logtype_ERR)
            return False
    
        if not fcclp.call_cov_list_parser(dic_project_info):
            log.set_log("REPORT", "Call Coverage report csv create fail", log.Logtype_ERR)
            return False
    
        if not funccall_cov_csv.create_func_cov_csv(dic_project_info):
            log.set_log("REPORT", "Func Coverage report csv create fail", log.Logtype_ERR)
            return False
    
        if not funccall_cov_csv.create_call_cov_csv(dic_project_info):
            log.set_log("REPORT", "Call Coverage report csv create fail", log.Logtype_ERR)
            return False

        if not var_count_csv.create_trace_var_count_csv(dic_project_info):
            log.set_log("REPORT", "Trace Var Count report csv create fail", log.Logtype_ERR)
            return False


    return True

if __name__ == "__main__":
    
    result = main()
    if result:
        log.set_log("REPORT", "Report Module Pass", log.Logtype_PRG)
    else:
        log.set_log("REPORT", "Report Module Fail", log.Logtype_ERR)
"""
