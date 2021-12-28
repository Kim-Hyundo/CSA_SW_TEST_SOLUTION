import os, sys
import pickle_api as pa
import log_mod as log

def call_cov_list_parser(dic_project_info):
    log.set_log("REPORT", "call_cov_list_parser Processing...", log.Logtype_PFF)

    targetsw_call_list_flag = True
    dic_call_cov_rawdata = {}
    dic_func_call_list_rawdata = []

    # Function Coverage Folder Check
    if not os.path.isdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\txt\\funccall_cov\\call"):
        log.set_log("REPORT", "Function Coverage folder path is not exist", log.Logtype_ERR)
        return False

    # Scenario Folder List Collect
    scenario_folderlist = os.listdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\txt\\funccall_cov\\call")

    dic_allfunc_list = pa.object_file_load(
        dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\funclist\\allfunc_list\\dic_allfunc_list.txt", "rb")

    # Function Coverage Data Parsing for Scenario
    for scenario_name in scenario_folderlist:
        list_call_cov_rawdata = []

        # Testcase Folder List Collect in Scenario Folder
        testcase_folderlist = os.listdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\txt\\funccall_cov\\call\\" + scenario_name)

        for testcase in testcase_folderlist:
            # Testcase Directory existance Check
            if not os.path.isdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\txt\\funccall_cov\\call\\" + scenario_name + "\\" + testcase):
                log.set_log("REPORT", dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\txt\\funccall_cov\\call\\" + scenario_name + "\\" + testcase + " Directory is empty/not exist", log.Logtype_ERR)
                return False

            # Function Coverage Data(.txt) File Check
            file_list = os.listdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\txt\\funccall_cov\\call\\" + scenario_name + "\\" + testcase)
            file_list_txt = [file for file in file_list if file.endswith(".txt")]

            log.set_log("REPORT", "Function Coverage Data(.txt) File List : " + str(file_list_txt), log.Logtype_DBG)

            if not file_list_txt:
                log.set_log("REPORT", "folder is empty", log.Logtype_ERR)
                return False

            for file_name in file_list_txt:
                load_file_path = dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\txt\\funccall_cov\\call\\" + scenario_name + "\\" + testcase +"\\" + file_name

                if not ".txt" in file_name:
                    log.set_log("REPORT", "Function Coverage File is not correct : " + load_file_path, log.Logtype_ERR)
                    return False
                else:
                    log.set_log("REPORT", "Function Coverage File Name : " + load_file_path, log.Logtype_INF)
                    file_name = file_name.replace('.txt', '')

                with open(load_file_path, 'r', encoding='utf-8', newline='') as file:
                    for line in file.readlines():

                        log.set_log("REPORT", "Coverage File : " + load_file_path + " ReadLine : " + line,
                                    log.Logtype_DBG)

                        # Collect for target sw Function/call Coverage data
                        temp = line.split()

                        if ('call' in line) or ('calla' in line) or ('calli' in line):
                            if (':' in temp[2]) or  (':' in temp[2]) or  (':' in temp[2]):
                                temp[2] = temp[2][-4:]
                            if ('call' != temp[2]) and ('calla' != temp[2]) and ('calli' != temp[2]):
                                del temp[2]

                        if len(temp) < 3:
                            continue

                        #Collect for target sw call list
                        if targetsw_call_list_flag == True:
                            if ('call' in line) or ('calla' in line) or ('calli' in line):
                                if not temp[-1] in dic_allfunc_list['AllFuncList'].keys():
                                    continue
                                # all component parsing
                                line1 = line.replace(";", "")
                                line1 = line.replace("\r\n", "")
                                line1 = line.split()

                                if (':' in line1[2]) or (':' in line1[2]) or (':' in line1[2]):
                                    line1[2] = line1[2][-4:]
                                elif ('call' != line1[2]) and ('calla' != line1[2]) and ('calli' != line1[2]):
                                    del line1[2]

                                # Address, Opcode parsing
                                temp1 = line1[1].split(':')  # temp[0]=Memory area(ex)P: D:, temp[1]=Address|Opcode
                                temp1 = temp1[1].split('|')  # temp[0]=Address, temp[1]=Opcode

                                call_list = {}
                                # call_list['Scenario'] = scenario_name
                                call_list['CallerFunction'] = file_name
                                call_list['Address'] = temp1[0]
                                call_list['OPCODE'] = temp1[1]
                                call_list['FuncCallType'] = line1[2]
                                call_list['FuncCallAddress'] = line1[3]
                                call_list['CalledFunction'] = line1[-1]

                                dic_func_call_list_rawdata.append(call_list)


                        if ('call' in temp[2]) or ('calla' in temp[2]) or ('calli' in temp[2]):
                            if not temp[-1] in dic_allfunc_list['AllFuncList'].keys():
                                continue

                            call_cov_rawdata = {}
                            call_cov_rawdata['TestCase'] = testcase
                            call_cov_rawdata['CallerFunction'] = file_name
                            call_cov_rawdata['FuncCallType'] = temp[2]
                            call_cov_rawdata['FuncCallAddress'] = temp[-3]
                            call_cov_rawdata['CalledFunction'] = temp[-1]
                            if temp[0] == 'ok':
                                call_cov_rawdata['Coverage'] = 'True'
                            else:
                                call_cov_rawdata['Coverage'] = 'False'
                            # Address, Opcode parsing
                            temp1 = temp[1].split(':')  # temp[0]=Memory area(ex)P: D:, temp[1]=Address|Opcode
                            temp1 = temp1[1].split('|')  # temp[0]=Address, temp[1]=Opcode
                            call_cov_rawdata['Address'] = temp1[0]

                            list_call_cov_rawdata.append(call_cov_rawdata)

            targetsw_call_list_flag = False

        dic_call_cov_rawdata[scenario_name] = list_call_cov_rawdata

    # Function Coverage Dictionary Save Folder Check if not exist then Create
    if not os.path.isdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\funclist\\funccall_list"):
        os.makedirs(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\funclist\\funccall_list")

    func_call_list_save_file_path = dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\funclist\\funccall_list\\dic_funccall_list.txt"

    if not pa.object_file_dump(func_call_list_save_file_path, dic_func_call_list_rawdata, "wb"):
        log.set_log("REPORT", "Parsed Trace Data Pickle File Save Error", log.Logtype_ERR)
        return False

    # Call Coverage Dictionary Save Folder Check if not exist then Create
    if not os.path.isdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\callccov"):
        os.makedirs(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\callccov")

    call_cov_save_file_path = dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\callccov\\dic_call_cov.txt"

    if not pa.object_file_dump(call_cov_save_file_path, dic_call_cov_rawdata, "wb"):
        log.set_log("REPORT", "Call Coverage Parsed Trace Data Pickle File Save Error", log.Logtype_ERR)
        return False

    log.set_log("REPORT", "call_cov_list_parser Processed", log.Logtype_PFF)
    return True

def func_cov_list_parser(dic_project_info):
    log.set_log("REPORT", "func_cov_list_parser Processing...", log.Logtype_PFF)

    dic_func_cov_rawdata = {}

    # Function Coverage Folder Check
    if not os.path.isdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\txt\\funccall_cov\\call"):
        log.set_log("REPORT", "Function Coverage folder path is not exist", log.Logtype_ERR)
        return False

    # Scenario Folder List Collect
    scenario_folderlist = os.listdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\txt\\funccall_cov\\call")

    # Function Coverage Data Parsing for Scenario
    for scenario_name in scenario_folderlist:

        func_cov_rawdata = {}

        # Testcase Folder List Collect in Scenario Folder
        testcase_folderlist = os.listdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\txt\\funccall_cov\\call\\" + scenario_name)

        for testcase in testcase_folderlist:
            # Testcase Directory existance Check
            if not os.path.isdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\txt\\funccall_cov\\call\\" + scenario_name + "\\" + testcase):
                log.set_log("REPORT", dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\txt\\funccall_cov\\call\\" + scenario_name + "\\" + testcase + " Directory is empty/not exist", log.Logtype_ERR)
                return False

            # Function Coverage Data(.txt) File Check
            file_list = os.listdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\txt\\funccall_cov\\call\\" + scenario_name + "\\" + testcase)
            file_list_txt = [file for file in file_list if file.endswith(".txt")]

            log.set_log("REPORT", "Function Coverage Data(.txt) File List : " + str(file_list_txt), log.Logtype_DBG)

            if not file_list_txt:
                log.set_log("REPORT", "folder is empty", log.Logtype_ERR)
                return False

            for file_name in file_list_txt:
                if 'cocofun' in file_name:
                    continue
                load_file_path = dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\txt\\funccall_cov\\call\\" + scenario_name + "\\" + testcase +"\\" + file_name

                if not ".txt" in file_name:
                    log.set_log("REPORT", "Function Coverage File is not correct : " + load_file_path, log.Logtype_ERR)
                    return False
                else:
                    log.set_log("REPORT", "Function Coverage File Name : " + load_file_path, log.Logtype_INF)
                    file_name = file_name.replace('.txt', '')

                with open(load_file_path, 'r', encoding='utf-8', newline='') as file:
                    for line in file.readlines():
                        log.set_log("REPORT", "Coverage File : " + load_file_path + " ReadLine : " + line,
                                    log.Logtype_DBG)
                        temp = line.split()
                        if len(temp) < 3:
                            continue

                        if temp[0] == 'ok':
                            func_cov_rawdata[file_name] = 'True'

                        else:
                            if file_name in func_cov_rawdata.keys():
                                continue
                            else:
                                func_cov_rawdata[file_name] = 'False'

        dic_func_cov_rawdata[scenario_name] = func_cov_rawdata

    # Function Coverage Dictionary Save Folder Check if not exist then Create
    if not os.path.isdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\funccov"):
        os.makedirs(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\funccov")

    func_cov_save_file_path = dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\funccov\\dic_func_cov.txt"

    if not pa.object_file_dump(func_cov_save_file_path, dic_func_cov_rawdata, "wb"):
        log.set_log("REPORT", "Func Coverage Parsed Trace Data Pickle File Save Error", log.Logtype_ERR)
        return False

    log.set_log("REPORT", "func_cov_list_parser Processed", log.Logtype_PFF)
    return True


"""
def func_cov_list_parser(dic_path):
    targetsw_call_list_flag = True
    dic_func_cov_rawdata = {}
    dic_call_cov_rawdata = {}
    dic_func_call_list_rawdata = []

    # Function Coverage Folder Check
    if not os.path.isdir(dic_path['WorkingProject_Path'] + "\\Debug\\txt\\funccall_cov\\call"):
        log.set_log("REPORT", "Function Coverage folder path is not exist", log.Logtype_ERR)
        return False

    # Scenario Folder List Collect
    scenario_folderlist = os.listdir(dic_path['WorkingProject_Path'] + "\\Debug\\txt\\funccall_cov\\call")

    # Function Coverage Data Parsing for Scenario
    for scenario_name in scenario_folderlist:

        func_cov_rawdata = {}
        list_call_cov_rawdata = []

        # Testcase Folder List Collect in Scenario Folder
        testcase_folderlist = os.listdir(dic_path['WorkingProject_Path'] + "\\Debug\\txt\\funccall_cov\\call\\" + scenario_name)

        for testcase in testcase_folderlist:
            # Testcase Directory existance Check
            if not os.path.isdir(dic_path['WorkingProject_Path'] + "\\Debug\\txt\\funccall_cov\\call\\" + scenario_name + "\\" + testcase):
                log.set_log("REPORT", dic_path['WorkingProject_Path'] + "\\Debug\\txt\\funccall_cov\\call\\" + scenario_name + "\\" + testcase + " Directory is empty/not exist", log.Logtype_ERR)
                return False

            # Function Coverage Data(.txt) File Check
            file_list = os.listdir(dic_path['WorkingProject_Path'] + "\\Debug\\txt\\funccall_cov\\call\\" + scenario_name + "\\" + testcase)
            file_list_txt = [file for file in file_list if file.endswith(".txt")]

            if not file_list_txt:
                log.set_log("REPORT", "folder is empty", log.Logtype_ERR)
                return False

            for file_name in file_list_txt:
                load_file_path = dic_path['WorkingProject_Path'] + "\\Debug\\txt\\funccall_cov\\call\\" + scenario_name + "\\" + testcase +"\\" + file_name

                if not ".txt" in file_name:
                    log.set_log("REPORT", "Function Coverage File is not correct : " + load_file_path, log.Logtype_ERR)
                    return False
                else:
                    log.set_log("REPORT", "Function Coverage File Name : " + load_file_path, log.Logtype_INF)
                    file_name = file_name.strip('.txt')

                with open(load_file_path, 'r', encoding='utf-8', newline='') as file:
                    for line in file.readlines():

                        #Collect for target sw call list
                        if targetsw_call_list_flag == True:
                            if ('call' in line) or ('calla' in line) or ('calli' in line):
                                # all component parsing
                                line1 = line.replace(";", "")
                                line1 = line.replace("\r\n", "")
                                line1 = line.split()

                                # Address, Opcode parsing
                                temp = line1[1].split(':')  # temp[0]=Memory area(ex)P: D:, temp[1]=Address|Opcode
                                temp = temp[1].split('|')  # temp[0]=Address, temp[1]=Opcode

                                call_list = {}
                                # call_list['Scenario'] = scenario_name
                                call_list['CallerFunction'] = file_name
                                call_list['Address'] = temp[0]
                                call_list['OPCODE'] = temp[1]
                                call_list['FuncCallType'] = line1[2]
                                call_list['FuncCallAddress'] = line1[3]
                                call_list['CalledFunction'] = line1[-1]

                                dic_func_call_list_rawdata.append(call_list)

                        # Collect for target sw Function/call Coverage data
                        temp = line.split()

                        if len(temp) < 3:
                            continue

                        if temp[0] == 'ok':

                            func_cov_rawdata[file_name] = 'True'

                            if ('call' in temp[2]) or ('calla' in temp[2]) or ('calli' in temp[2]):
                                call_cov_rawdata = {}
                                call_cov_rawdata['TestCase'] = testcase
                                call_cov_rawdata['CallerFunction'] = file_name
                                call_cov_rawdata['FuncCallType'] = temp[2]
                                call_cov_rawdata['FuncCallAddress'] = temp[-3]
                                call_cov_rawdata['CalledFunction'] = temp[-1]
                                call_cov_rawdata['Coverage'] = 'True'
                                # Address, Opcode parsing
                                temp1 = temp[1].split(':')  # temp[0]=Memory area(ex)P: D:, temp[1]=Address|Opcode
                                temp1 = temp1[1].split('|')  # temp[0]=Address, temp[1]=Opcode
                                call_cov_rawdata['Address'] = temp1[0]

                                list_call_cov_rawdata.append(call_cov_rawdata)

                        else:
                            if file_name in func_cov_rawdata.keys():
                                continue
                            else:
                                func_cov_rawdata[file_name] = 'False'


            targetsw_call_list_flag = False

        dic_func_cov_rawdata[scenario_name] = func_cov_rawdata
        dic_call_cov_rawdata[scenario_name] = list_call_cov_rawdata

    # Function Coverage Dictionary Save Folder Check if not exist then Create
    if not os.path.isdir(dic_path['WorkingProject_Path'] + "\\Debug\\dic\\funclist\\funccall_list"):
        os.makedirs(dic_path['WorkingProject_Path'] + "\\Debug\\dic\\funclist\\funccall_list")

    func_call_list_save_file_path = dic_path['WorkingProject_Path'] + "\\Debug\\dic\\funclist\\funccall_list\\dic_funccall_list.txt"

    # Function Coverage Dictionary Save Folder Check if not exist then Create
    if not os.path.isdir(dic_path['WorkingProject_Path'] + "\\Debug\\dic\\funccov"):
        os.makedirs(dic_path['WorkingProject_Path'] + "\\Debug\\dic\\funccov")

    func_cov_save_file_path = dic_path['WorkingProject_Path'] + "\\Debug\\dic\\funccov\\dic_func_cov.txt"

    # Call Coverage Dictionary Save Folder Check if not exist then Create
    if not os.path.isdir(dic_path['WorkingProject_Path'] + "\\Debug\\dic\\callccov"):
        os.makedirs(dic_path['WorkingProject_Path'] + "\\Debug\\dic\\callccov")

    call_cov_save_file_path = dic_path['WorkingProject_Path'] + "\\Debug\\dic\\callccov\\dic_call_cov.txt"

    if not pa.object_file_dump(func_call_list_save_file_path, dic_func_call_list_rawdata, "wb"):
        log.set_log("REPORT", "Parsed Trace Data Pickle File Save Error", log.Logtype_ERR)
        return False

    if not pa.object_file_dump(func_cov_save_file_path, dic_func_cov_rawdata, "wb"):
        log.set_log("REPORT", "Func Coverage Parsed Trace Data Pickle File Save Error", log.Logtype_ERR)
        return False

    if not pa.object_file_dump(call_cov_save_file_path, dic_call_cov_rawdata, "wb"):
        log.set_log("REPORT", "Call Coverage Parsed Trace Data Pickle File Save Error", log.Logtype_ERR)
        return False

    return True
"""
#code_coverage_parsing(r"C:\Git\1.Prost\Debug\Report\python\testfile\cov_merge", r"C:\Git\1.Prost\Debug\Report\python\testfile\cov_merge")
#func_cov_list_parser(dic_path)