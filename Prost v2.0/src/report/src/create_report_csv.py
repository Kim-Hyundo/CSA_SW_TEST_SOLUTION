import os, sys, csv, shutil
from xml.dom import minidom
from datetime import datetime
import xml.etree.ElementTree as elemTree
from io import open
import pickle_api as pa
import log_mod as log

##### Global Variable #####
dic_report_summary = {}
dic_report_result = {}
statistics_data = {}
executionTimes = {}
maxExecutionTime = ''
minExecutionTime = ''

##### Get Time Info #####
nowtime = datetime.now().strftime("%y%m%d_%H%M%S")
nowtime1 = datetime.now().strftime("%y/%m/%d %H:%M:%S")

def gen_statistics_data(scenario, dic_test_result):
    log.set_log("REPORT", "gen_statistics_data Processing...", log.Logtype_PFF)

    gen_passfail_info(dic_test_result)
    gen_minmax_executiontime(dic_test_result)

    log.set_log("REPORT", scenario + " statistics_data : " + str(statistics_data), log.Logtype_DBG)
    log.set_log("REPORT", "gen_statistics_data Processed", log.Logtype_PFF)

def gen_passfail_info(dic_test_result):
    log.set_log("REPORT", "gen_passfail_info Processing...", log.Logtype_PFF)

    passRateCnt = 0
    failRateCnt = 0
    pf_decision = True

    for test_result in dic_test_result:
        if 'Expect Output Data' in test_result.keys():
            if 'USER MACRO OUTPUT' in test_result['Expect Output Data'].keys():
                test_result['Expect Output Data']['USER MACRO OUTPUT'] = test_result['Expect Output Data'][
                    'USER MACRO OUTPUT'].replace(" ", "")
                test_result['Actual Output Data']['USER MACRO OUTPUT'] = test_result['Actual Output Data'][
                    'USER MACRO OUTPUT'].replace(" ", "")

                #test_result['Expect Output Data']['USER MACRO Output']="DTC_CODE==0xC110117"
                #test_result['Actual Output Data']['USER MACRO Output'] = "DTC_CODE==202440983"
                # if expect output data inlude 0x for actual output data int to hex
                if test_result['Expect Output Data']['USER MACRO OUTPUT'].find("0x") != -1:
                    dectohextmp = test_result['Actual Output Data']['USER MACRO OUTPUT'].split('==')
                    dectohex_actual=dectohextmp[-1]
                    dectohex_actual=hex(int(dectohex_actual))
                    dectohex_actual=dectohex_actual.upper()

                    actual_output_data=dectohextmp[0]+'=='+dectohex_actual
                    test_result['Actual Output Data']['USER MACRO OUTPUT']=actual_output_data

                    expoutputtmp = test_result['Expect Output Data']['USER MACRO OUTPUT'].split('==')
                    expect_output = expoutputtmp[-1]
                    expect_output=expect_output.upper()

                    expect_output_data = expoutputtmp[0] + '==' + expect_output
                    test_result['Expect Output Data']['USER MACRO OUTPUT'] = expect_output_data

                if test_result['Expect Output Data']['USER MACRO OUTPUT'].replace(" ","").replace("\n","") == test_result['Actual Output Data']['USER MACRO OUTPUT'].replace(" ","").replace("\n",""):
                    pf_decision = True
                else:
                    pf_decision = False
            else:
                for index, (key, elem) in enumerate(test_result['Expect Output Data'].items()):

                    if 'Tolerance' in test_result.keys():
                        diff_abs = abs(float(list(test_result['Expect Output Data'].values())[index]) - float(list(test_result['Actual Output Data'].values())[index]))
                        if diff_abs <= float(list(test_result['Tolerance'].values())[index]):
                            pf_decision = True
                        else:
                            pf_decision = False
                            break

                    if float( list( test_result['Expect Output Data'].values() )[index]) == float(list(test_result['Actual Output Data'].values())[index]):
                        pf_decision = True
                    else:
                        pf_decision = False
                        break
            if pf_decision == True:
                test_result['PassFail'] = 'Pass'
                passRateCnt = passRateCnt + 1
            elif pf_decision == False:
                test_result['PassFail'] = 'Fail'
                failRateCnt = failRateCnt + 1

    statistics_data['passCnt'] = passRateCnt
    statistics_data['failCnt'] = failRateCnt
    statistics_data['testSampleCnt'] = len(dic_test_result)
    statistics_data['passRate'] = str(
        statistics_data['passCnt'] / float(statistics_data['testSampleCnt']) * 100.0) + "%"
    statistics_data['failRate'] = str(
        statistics_data['failCnt'] / float(statistics_data['testSampleCnt']) * 100.0) + "%"

    log.set_log("REPORT", "gen_passfail_info Processed", log.Logtype_PFF)

def gen_minmax_executiontime(dic_test_result):
    for test_result in dic_test_result:
        if 'Execution time' in test_result.keys():
            for index, (key, elem) in enumerate(test_result['Execution time'].items()):
                if not key in executionTimes.keys():
                    executionTimes[key] = []
                if elem == "N/A":
                    executionTimes[key].append("N/A")
                    continue
                executionTimes[key].append(elem)

    for k, v in executionTimes.items():
        while 'N/A' in v:
            v.remove('N/A')  # 'Smith' 삭제
        executionTimes[k] = v

    for key in executionTimes:
        maxExecutionTime = 'maxExecutionTime_' + key
        minExecutionTime = 'minExecutionTime_' + key

        if len(executionTimes[key]) < 1:
            executionTimes[key].append("0")

        smallest = executionTimes[key][0]
        for i in executionTimes[key]:
            if float(i) <= float(smallest):
                smallest = i
        statistics_data[minExecutionTime] = smallest

        log.set_log("REPORT", key + " Min Execution Time : " + ":" + smallest, log.Logtype_DBG)

        largest = executionTimes[key][0]
        for i in executionTimes[key]:
            if float(i) >= float(largest):
                largest = i
        statistics_data[maxExecutionTime] = largest

        log.set_log("REPORT", key + " Max Execution Time : " + ":" + largest, log.Logtype_DBG)

        if statistics_data[minExecutionTime] == '-':
            statistics_data[minExecutionTime] = statistics_data[maxExecutionTime]

def get_total_memory_usage(dic_project_info, dic_test_result):
    log.set_log("REPORT", "get_total_memory_usage Processing...", log.Logtype_PFF)

    total_usage = 0
    total_memory_usage = {}
    list_brom = [];
    list_lmuram = [];
    list_flash = [];
    list_dspr = [];
    list_pspr = [];
    list_mcs = [];
    list_total = []

    # Get XML Root Tag
    tree = elemTree.parse(dic_project_info['Common_Path']['XML_Path'])

    # Get XML Sub Tag
    part_tag = tree.find('./part[2]')
    table_tag = part_tag.find("part").find("table")

    for i in table_tag.iter("row"):
        memory_area = i.text
        if 'brom' in memory_area:
            list_brom.append(memory_area)
        if 'lmuram' in memory_area:
            list_lmuram.append(memory_area)
        if 'flash' in memory_area:
            list_flash.append(memory_area)
        if 'dspr' in memory_area:
            list_dspr.append(memory_area)
        if 'pspr' in memory_area:
            list_pspr.append(memory_area)
        if 'mcs' in memory_area:
            list_mcs.append(memory_area)
        if 'Total' in memory_area:
            list_total.append(memory_area)

    list_brom.sort();
    list_lmuram.sort();
    list_mcs.sort();
    list_flash.sort();
    list_dspr.sort();
    list_pspr.sort()

    for i in range(len(list_total)):
        total_tmp = list_total[i].split(';')

    for i in range(len(list_flash)):
        temp = list_flash[i].split(';')
        total_memory_usage[temp[0].replace("mpe:", "")] = [int(temp[1], 0), int(temp[2], 0), int(temp[3], 0), int(temp[4], 0), int(temp[5], 0), \
                                                     round(((int(temp[-1], 0) - int(temp[-2], 0) - int(temp[-3], 0)) / int(total_tmp[-1],
                                                                                                        0)) * 100, 3)]

    for i in range(len(list_brom)):
        temp = list_brom[i].split(';')
        total_memory_usage[temp[0].replace("mpe:", "")] = [int(temp[1], 0), int(temp[2], 0), int(temp[3], 0), int(temp[4], 0), int(temp[5], 0), \
                                                     round(((int(temp[-1], 0) - int(temp[-2], 0) - int(temp[-3], 0)) / int(total_tmp[-1],
                                                                                                        0)) * 100, 3)]

    for i in range(len(list_lmuram)):
        temp = list_lmuram[i].split(';')
        total_memory_usage[temp[0].replace("mpe:", "")] = [int(temp[1], 0), int(temp[2], 0), int(temp[3], 0), int(temp[4], 0), int(temp[5], 0), \
                                                     round(((int(temp[-1], 0) - int(temp[-2], 0) - int(temp[-3], 0)) / int(total_tmp[-1],
                                                                                                        0)) * 100, 3)]

    for i in range(len(list_dspr)):
        temp = list_dspr[i].split(';')
        total_memory_usage[temp[0].replace("mpe:", "")] = [int(temp[1], 0), int(temp[2], 0), int(temp[3], 0), int(temp[4], 0), int(temp[5], 0), \
                                                     round(((int(temp[-1], 0) - int(temp[-2], 0) - int(temp[-3], 0)) / int(total_tmp[-1],
                                                                                                        0)) * 100, 3)]

    for i in range(len(list_pspr)):
        temp = list_pspr[i].split(';')
        total_memory_usage[temp[0].replace("mpe:", "")] = [int(temp[1], 0), int(temp[2], 0), int(temp[3], 0), int(temp[4], 0), int(temp[5], 0), \
                                                     round(((int(temp[-1], 0) - int(temp[-2], 0) - int(temp[-3], 0)) / int(total_tmp[-1],
                                                                                                        0)) * 100, 3)]

    for i in range(len(list_mcs)):
        temp = list_mcs[i].split(';')
        total_memory_usage[temp[0].replace("mpe:", "")] = [int(temp[1], 0), int(temp[2], 0), int(temp[3], 0), int(temp[4], 0), int(temp[5], 0), \
                                                     round(((int(temp[-1], 0) - int(temp[-2], 0) - int(temp[-3], 0)) / int(total_tmp[-1],
                                                                                                        0)) * 100, 3)]

    for k, v in total_memory_usage.items():
        total_usage += v[-1]

    total_memory_usage['Total'] = [int(total_tmp[1], 0), int(total_tmp[2], 0), int(total_tmp[3], 0), int(total_tmp[4], 0), int(total_tmp[5], 0), round(total_usage, 3)]

    log.set_log("REPORT", "get_total_memory_usage Processed", log.Logtype_PFF)

    return total_memory_usage

def get_targetsw_memory_usage(dic_project_info, dic_test_result):
    log.set_log("REPORT", "get_targetsw_memory_usage Processing...", log.Logtype_PFF)

    data_usage = {}
    code_usage = {}

    # Get XML Root Tag
    tree = elemTree.parse(dic_project_info['Common_Path']['XML_Path'])

    # Get XML Sub Tag


    if dic_project_info['Test_Env']['CompilerVersion'] == '4.3':        #for WIA ./part[8]
        part_tag = tree.find('./part[8]')
    elif dic_project_info['Test_Env']['CompilerVersion'] == '4.2' or dic_project_info['Test_Env']['CompilerVersion'] == '6.2':        # for WIA ./part[8]
        part_tag = tree.find('./part[7]')
	
    sub_part_tag = part_tag.find("./part[2]")
    table_tag = sub_part_tag.find("table")

    dic_sw_usage = {}

    for i in table_tag.iter("row"):
        dic_sw_usage_temp = {}

        memory_area = i.text
        link_result = memory_area.split(';')
        targetsw_name_and_cd_area = link_result[2].split('.')   #target sw name(ex) func1,func14 and code,data area parse

        if len(targetsw_name_and_cd_area) < 3:
            continue

        if targetsw_name_and_cd_area[2] + '.c' in dic_project_info['Test_Env']['Test_Code_List']:
            if 'bss' in targetsw_name_and_cd_area[1] or 'text' in targetsw_name_and_cd_area[1]:
                if not targetsw_name_and_cd_area[2] in dic_sw_usage:
                    dic_sw_usage[targetsw_name_and_cd_area[2]] = []

                dic_sw_usage_temp['ChipName'] = link_result[0]
                dic_sw_usage_temp['Size'] = link_result[3]
                dic_sw_usage_temp['Section'] = targetsw_name_and_cd_area[1]
                dic_sw_usage_temp['TargetSW'] = targetsw_name_and_cd_area[2]
                dic_sw_usage[targetsw_name_and_cd_area[2]].append(dic_sw_usage_temp)

    #Calculate Usage
    dic_sw_usage_summary = {}
    for target_sw, usage_list in dic_sw_usage.items():
        rom_text_size_sum = 0
        rom_bss_size_sum = 0
        ram_text_size_sum = 0
        ram_bss_size_sum = 0
        for v in usage_list:
            # ROM USAGE
            if ('pflash' in v['ChipName']) or ('dflash' in v['ChipName']) or ('brom' in v['ChipName']) :
                if 'text' == v['Section']:
                    rom_text_size_sum += int(v['Size'], 16)
                elif 'bss' == v['Section']:
                    rom_bss_size_sum += int(v['Size'], 16)
            # RAM USAGE
            else:
                if 'text' == v['Section']:
                    ram_text_size_sum += int(v['Size'], 16)
                elif 'bss' == v['Section']:
                    ram_bss_size_sum += int(v['Size'], 16)

        if not target_sw in dic_sw_usage_summary.keys():
            dic_sw_usage_summary[target_sw] = {}

        dic_sw_usage_summary[target_sw]['Total'] = rom_text_size_sum + rom_bss_size_sum + ram_text_size_sum + ram_bss_size_sum
        dic_sw_usage_summary[target_sw]['RomCode'] = rom_text_size_sum
        dic_sw_usage_summary[target_sw]['RomData'] = rom_bss_size_sum
        dic_sw_usage_summary[target_sw]['RamCode'] = ram_text_size_sum
        dic_sw_usage_summary[target_sw]['RamData'] = ram_bss_size_sum
    log.set_log("REPORT", "get_targetsw_memory_usage Processed", log.Logtype_PFF)

    return dic_sw_usage_summary

"""
def get_targetsw_memory_usage(dic_path, dic_test_result, dic_project_info):
    log.set_log("REPORT", "get_targetsw_memory_usage Processing...", log.Logtype_PFF)

    data_usage = {}
    code_usage = {}

    # Get XML Root Tag
    tree = elemTree.parse(dic_path['XML_Path'])

    # Get XML Sub Tag
    part_tag = tree.find('./part[4]')
    table_tag = part_tag.find("table")

    for i in table_tag.iter("row"):
        memory_area = i.text
        link_result = memory_area.split(';')

        if link_result[0].replace(".o", ".c") in dic_project_info['Test SW List']:
            if '.bss' in link_result[1]:
                if link_result[0] not in data_usage.keys():
                    data_usage[link_result[0]] = []

                data_usage[link_result[0]].append(int(link_result[-1], 0))

            elif '.text' in link_result[1]:
                if link_result[0] not in code_usage.keys():
                    code_usage[link_result[0]] = []

                code_usage[link_result[0]].append(int(link_result[-1], 0))

    log.set_log("REPORT", "get_targetsw_memory_usage Processed", log.Logtype_PFF)

    return data_usage, code_usage
"""
def create_report_csv(dic_project_info, scenario, dic_test_result):
    log.set_log("REPORT", "create_report_csv Processing...", log.Logtype_PFF)


    #dic_report_result['Scenario'] = scenario

    # Create Report CSV File
    if not os.path.isdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Report\\" + scenario):
        os.makedirs(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Report\\" + scenario)

    log.set_log("REPORT", scenario + " Report folder path : " + dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Report\\", log.Logtype_DBG)

    gen_statistics_data(scenario, dic_test_result)

    filename = dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Report\\" + scenario + "\\" + "Test_Report" + "_" + scenario + "_" + nowtime + ".csv"

    log.set_log("REPORT", scenario + " Report file path : " + filename, log.Logtype_DBG)

    # Sorting Display Data
    sort_dic_test_result = []

    for list_tmp in dic_test_result:
        new_dic_tmp = {}
        new_dic_tmp['Test ID'] = list_tmp['Test ID']
        new_dic_tmp['Input Data'] = list_tmp['Input Data']
        new_dic_tmp[' '] = ' '
        new_dic_tmp['Expect Output Data'] = list_tmp['Expect Output Data']
        new_dic_tmp['Actual Output Data'] = list_tmp['Actual Output Data']
        new_dic_tmp['  '] = ' '

        if 'Tolerance' in list_tmp.keys():
            new_dic_tmp['Tolerance'] = list_tmp['Tolerance']

        if 'Execution time' in list_tmp.keys():
            new_dic_tmp['Execution time'] = list_tmp['Execution time']

        new_dic_tmp['PassFail'] = list_tmp['PassFail']

        sort_dic_test_result.append(new_dic_tmp)

    # Write CSV File
    #with open(filename, 'wt', encoding='utf-8', newline='') as filewrite:  #No Korean
    with open(filename, 'wt', encoding='ANSI', newline='') as filewrite:    #Korean
        csv_writer = csv.writer(filewrite)

        csv_writer.writerow(["<General Information>"])
        for k, v in dic_project_info['Test_Env'].items():
            csv_writer.writerow([k, v])

        csv_writer.writerow([" "])

        test_result = []
        test_result_temp = {}

        csv_writer.writerow(["<Test Result>"])
        for i in sort_dic_test_result:
            for k, v in i.items():
                if isinstance(v, dict):
                    for k1, v1 in v.items():
                        if k == 'Input Data':
                            result = "{}(입력)".format(k1)
                            test_result_temp[result] = v1
                        elif k == 'Expect Output Data':
                            result = "{}(예상 출력)".format(k1)
                            test_result_temp[result] = v1
                        elif k == 'Actual Output Data':
                            result = "{}(실제 출력)".format(k1)
                            test_result_temp[result] = v1
                        elif k == 'Execution time':
                            result = "{}(실행 시간)(us)".format(k1, k)
                            test_result_temp[result] = v1
                        elif k == 'Tolerance':
                            result = "{}({})".format(k, k1)
                            test_result_temp[result] = v1

                else:  # Test ID, PassFail, Execution Time
                    if k == 'PassFail':
                        result = "결과"
                        test_result_temp[result] = v
                    else:
                        test_result_temp[k] = v

            test_result.append(test_result_temp)
            test_result_temp = {}

        temp = []
        count = 0

        for i in test_result:
            for index, (key, elem) in enumerate(i.items()):
                if count == 0:
                    csv_writer.writerow(list(i.keys()))
                    count = 1
                # csv_writer.writerow(list(i.keys()))
                temp.append(elem)
            csv_writer.writerow(temp)
            del temp[:]  # list contents delete

    filewrite.close()

    if not scenario in dic_report_result.keys():
        dic_report_result[scenario] = []
    dic_report_result[scenario] = dic_test_result

    # Save Test Result Dictionary for Report UI
    if not os.path.isdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\test_result"):
        os.makedirs(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\test_result")

    if not pa.object_file_dump(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\test_result\\test_result.txt", dic_report_result, "wb"):
        log.set_log("REPORT", "Parsed Trace Data Pickle File Save Error", log.Logtype_ERR)
        return False

    log.set_log("REPORT", "create_report_csv Processed", log.Logtype_PFF)
    return True

def create_statistics_csv(dic_project_info, scenario, dic_test_result):
    log.set_log("REPORT", "create_statistics_csv Processing...", log.Logtype_PFF)


    #dic_report_summary['Scenario'] = scenario
    #if not scenario in dic_report_summary.keys():
    dic_report_summary[scenario] = {}
    report_summary_temp = {}

    report_summary_temp['EnumScriptPath']=dic_project_info['Common_Path']['EnumScriptPath']
    #create_statistics_data(dic_path, dic_test_result)

    # Create Statistics CSV File
    if not os.path.isdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Report\\" + scenario):
        os.makedirs(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Report\\" + scenario)


    filename = dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Report\\" + scenario + "\\" + "Test_Summary"  + "_" + scenario + "_" + nowtime + ".csv"

    with open(filename, 'wt', encoding='utf-8', newline='') as statistic_filewrite:
        csv_writer = csv.writer(statistic_filewrite)

        csv_writer.writerow(["<General Information>"])
        for k, v in dic_project_info['Test_Env'].items():
            csv_writer.writerow([k, v])
        csv_writer.writerow([" "])

        csv_writer.writerow(["<Summary of Test Result>"])
        #csv_writer.writerow([" "])  # Test Case Location
        csv_writer.writerow(["Test Sample Count", statistics_data['testSampleCnt']])
        report_summary_temp['Test Sample Count'] = statistics_data['testSampleCnt']
        csv_writer.writerow(["Pass Count", statistics_data['passCnt']])
        report_summary_temp['Pass Count'] = statistics_data['passCnt']
        csv_writer.writerow(["Pass Rate", statistics_data['passRate']])
        report_summary_temp['Pass Rate'] = statistics_data['passRate']
        csv_writer.writerow(["Fail Count", statistics_data['failCnt']])
        report_summary_temp['Fail Count'] = statistics_data['failCnt']
        csv_writer.writerow(["Fail Rate", statistics_data['failRate']])
        report_summary_temp['Fail Rate'] = statistics_data['failRate']
        csv_writer.writerow([" "])

        csv_writer.writerow(["<Summary of SW Execution Time(us)>"])
        for key in executionTimes:
            maxExecutionTime = 'maxExecutionTime_' + key
            minExecutionTime = 'minExecutionTime_' + key
            maxExecutionTime_dp = 'Max Execution Time({})'.format(key)
            minExecutionTime_dp = 'Min Execution Time({})'.format(key)

            if statistics_data[maxExecutionTime] == '0':
                statistics_data[maxExecutionTime] = 'N/A'
            if statistics_data[minExecutionTime] == '0':
                statistics_data[minExecutionTime] = 'N/A'

            csv_writer.writerow([maxExecutionTime_dp, statistics_data[maxExecutionTime]])
            csv_writer.writerow([minExecutionTime_dp, statistics_data[minExecutionTime]])

            if not 'Max Execution Time' in report_summary_temp.keys():
                report_summary_temp['Max Execution Time'] = {}
            report_summary_temp['Max Execution Time'][key] = statistics_data[maxExecutionTime]
            if not 'Min Execution Time' in report_summary_temp.keys():
                report_summary_temp['Min Execution Time'] = {}
            report_summary_temp['Min Execution Time'][key] = statistics_data[minExecutionTime]

        csv_writer.writerow([" "])

        csv_writer.writerow(["<Stack Usage>"])
        for k, v in dic_project_info['Report']['Stack_Info'].items():
            if k == scenario:
                for k1, v1 in v.items():
                    csv_writer.writerow([k1, v1])
                    if str(v1) == "N/A":
                        report_summary_temp[k1] = str(v1)
                    else:
                        report_summary_temp[k1] = str(int(v1, 0))
        csv_writer.writerow([" "])

        if dic_project_info['Test_Env']['Test_CompilerType'] == 'TASKING':
            # Get Memory Usage
            total_memory_usage = get_total_memory_usage(dic_project_info, dic_test_result)
            dic_sw_usage_summary = get_targetsw_memory_usage(dic_project_info, dic_test_result)

            csv_writer.writerow(["<Total Memory Usage(Bytes)>"])
            csv_writer.writerow(["Memory", "Code", "Data", "Reserved", "Free", "Total", "Usage"])
            for k, v in total_memory_usage.items():
                temp = str(v) + " %"
                csv_writer.writerow([k, str(v[0]), str(v[1]), str(v[2]), str(v[3]), str(v[4]), str(v[5]) + "%"])
                if not 'Memory Usage' in report_summary_temp.keys():
                    report_summary_temp['Memory Usage'] = []

                temp = {}
                temp['Memory'] = k
                temp['Code'] = str(v[0])
                temp['Data'] = str(v[1])
                temp['Reserved'] = str(v[2])
                temp['Free'] = str(v[3])
                temp['Total'] = str(v[4])
                temp['Usage'] = str(v[5])

                report_summary_temp['Memory Usage'].append(temp)

            csv_writer.writerow([" "])

            csv_writer.writerow(["<Data/Code Usage for Target SW(Bytes)>"])

            """
            code_data_usage_merge={}
            for k, v in data_usage.items():
                if not k in code_data_usage_merge.keys():
                    code_data_usage_merge[k] = {}
                code_data_usage_merge[k]['Data'] = sum(v)
            for k, v in code_usage.items():
                if not k in code_data_usage_merge.keys():
                    code_data_usage_merge[k] = {}
                code_data_usage_merge[k]['Code'] = sum(v)
    
            for k, v in code_data_usage_merge.items():
                if not 'Data' in v.keys():
                    v['Data'] = 'N/A'
                if not 'Code' in v.keys():
                    v['Code'] = 'N/A'
    
            csv_writer.writerow(["File", 'Data', 'Code'])
            
            for k, v in code_data_usage_merge.items():
                csv_writer.writerow([k, v['Data'], v['Code']])
            """
            for target_sw_name, usage in dic_sw_usage_summary.items():
                csv_writer.writerow([target_sw_name, 'Total', usage['Total']])
                csv_writer.writerow([' ', 'ROM Code', usage['RomCode']])
                csv_writer.writerow([' ', 'ROM Data', usage['RomData']])
                csv_writer.writerow([' ', 'RAM Code', usage['RamCode']])
                csv_writer.writerow([' ', 'RAM Data', usage['RamData']])
                csv_writer.writerow([' '])


            report_summary_temp['Target SW Data'] = dic_sw_usage_summary


        """
        for k, v in data_usage.items():
            for k1, v1 in code_usage.items():
                if k == k1:
                    csv_writer.writerow([k, 'Data', sum(v)])
                    csv_writer.writerow([k1, 'Code', sum(v1)])

                    if not 'Target SW Data' in report_summary_temp.keys():
                        report_summary_temp['Target SW Data'] = {}
                    report_summary_temp['Target SW Data'][k] = sum(v)
                    if not 'Target SW Code' in report_summary_temp.keys():
                        report_summary_temp['Target SW Code'] = {}
                    report_summary_temp['Target SW Code'][k1] = sum(v1)
        """
    dic_report_summary[scenario] = report_summary_temp

    statistic_filewrite.close()

    statistics_data.clear()
    executionTimes.clear()

    #Save Report Summary Dictionary for Report UI
    if not os.path.isdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\report_summary"):
        os.makedirs(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\report_summary")

    if not pa.object_file_dump(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\report_summary\\report_summary.txt", dic_report_summary, "wb"):
        log.set_log("REPORT", "Parsed Trace Data Pickle File Save Error", log.Logtype_ERR)
        return False

    log.set_log("REPORT", "create_statistics_csv Processed", log.Logtype_PFF)
    return True


##### Create XML File #####
def create_XML_file(dic_path, dic_test_result):
    log.set_log("REPORT", "create_XML_file Processing...", log.Logtype_PFF)

    # .xsl File Copy
    shutil.copy2("Report.xsl", dic_path['WorkingProject_Path'] + "\\Report\\" + "Report.xsl")
    shutil.copy2("Statistics.xsl", dic_path['WorkingProject_Path'] + "\\Report\\" + "Statistics.xsl")

    # statistics XML
    xml = make_statistics_XML_contents(dic_path)

    dom = minidom.parseString(xml)
    pi = dom.createProcessingInstruction('xml-stylesheet', 'type="text/xsl" href="Statistics.xsl"')
    root = dom.firstChild
    dom.insertBefore(pi, root)

    filename = dic_path['WorkingProject_Path'] + "\\Report\\" + "Statistics" + "_" + nowtime + ".xml"

    try:
        f = open(filename, "w")
    except:
        log.set_log("REPORT", "File Write Error", log.Logtype_ERR)
        return False
    else:
        f.write(dom.toprettyxml())
        f.close()

    # test result XML
    xml = make_report_XML_contents(dic_test_result)

    dom = minidom.parseString(xml)
    pi = dom.createProcessingInstruction('xml-stylesheet', 'type="text/xsl" href="Report.xsl"')
    root = dom.firstChild
    dom.insertBefore(pi, root)

    filename = dic_path['WorkingProject_Path'] + "\\Report\\" + "Report" + "_" + nowtime + ".xml"

    try:
        f = open(filename, "w")
    except:
        log.set_log("REPORT", "File Write Error", log.Logtype_ERR)
        return False
    else:
        f.write(dom.toprettyxml())
        f.close()

    log.set_log("REPORT", "create_XML_file Processed", log.Logtype_PFF)
    return True

def make_statistics_XML_contents(dic_path):
    log.set_log("REPORT", "make_statistics_XML_contents Processing...", log.Logtype_PFF)

    memoryusage = ""

    total_memory_usage = get_total_memory_usage(dic_path)

    for k, v in total_memory_usage.items():
        temp = """
		    <area>
			    <name>{}</name>
                <code>{}</code>
                <data>{}</data>
                <reserved>{}</reserved>
                <free>{}</free>
                <total>{}</total>
			    <usage>{}%</usage>
		    </area>""".format(k, str(v[0]), str(v[1]), str(v[2]), str(v[3]), str(v[4]), str(v[5]))

        memoryusage = memoryusage + temp

    xml = """
    <statistics>
        <testresult>
            <count>{}</count>
            <pass>{}</pass>
            <fail>{}</fail>
        </testresult>
        <memoryusage>{}</memoryusage>
    </statistics>""".format(statistics_data['testSampleCnt'], statistics_data['passRate'], statistics_data['failRate'], memoryusage)

#    xml = """
#        <statistics>
#            <testresult>
#                <count>{}</count>
#                <pass>{}</pass>
#                <fail>{}</fail>
#                <maxtime>{}</maxtime>
#                <mintime>{}</mintime>
#            </testresult>
#            <memoryusage>{}</memoryusage>
#        </statistics>""".format(statistics_data['testSampleCnt'], statistics_data['passRate'],
#                                statistics_data['failRate'],
#                                statistics_data['maxExecutionTime'], statistics_data['minExecutionTimer'], memoryusage)
    log.set_log("REPORT", "make_statistics_XML_contents Processed", log.Logtype_PFF)
    return xml

def make_report_XML_contents(dic_test_result):
    log.set_log("REPORT", "make_report_XML_contents Processing...", log.Logtype_PFF)

    testresult = ""

    v_input_data = ""
    v_expect_data = ""
    v_actual_data = ""
    v_testid = ""
    v_pass_fail = ""
    v_execution_time = ""

    for i in dic_test_result:
        for k, v in i.items():
            if isinstance(v, dict):
                for k1, v1 in v.items():
                    if k == 'Input Data':
                        v_input_data = v_input_data + k1 + '=' + v1 + ' '
                    elif k == 'Expect Output Data':
                        v_expect_data = v_expect_data + k1 + '=' + v1 + ' '
                    elif k == 'Actual Output Data':
                        v_actual_data = v_actual_data + k1 + '=' + v1 + ' '
            else:
                if k == 'Test ID':
                    v_testid = v
                elif k == 'PassFail':
                    v_pass_fail = v
                elif k == 'Execution time':
                    v_execution_time = v

        temp = """
                        	<count>
		                        <testid>{}</testid>
		                        <input>{}</input>
		                        <expectoutput>{}</expectoutput>
		                        <actualoutput>{}</actualoutput>
		                        <passfail>{}</passfail>
		                        <executiontime>{}</executiontime>
	                        </count>""".format(v_testid, v_input_data, v_expect_data, v_actual_data, v_pass_fail,
                                               v_execution_time)

        v_input_data = ""
        v_expect_data = ""
        v_actual_data = ""
        testresult = testresult + temp

    xml = """
    <testresult>{}</testresult>""".format(testresult)

    log.set_log("REPORT", "make_report_XML_contents Processed", log.Logtype_PFF)
    return xml
