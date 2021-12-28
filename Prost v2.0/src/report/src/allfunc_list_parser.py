import os, sys
import pickle_api as pa
import log_mod as log

import xml.etree.ElementTree as elemTree

def allfunc_list_parser(dic_project_info):
    funclist = {}
    dic_allfunclist_rawdata = {}

    if not os.path.isdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\txt\\funccall_cov\\all"):
        log.set_log("REPORT", "Coverage folder path is not exist", log.Logtype_ERR)
        return False

    if not os.path.isdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\funclist\\allfunc_list"):
        os.makedirs(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\funclist\\allfunc_list")

    file_list = os.listdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\txt\\funccall_cov\\all")
    file_list_txt = [file for file in file_list if file.endswith(".txt")]

    if not file_list_txt:
        log.set_log("REPORT", "folder is empty", log.Logtype_ERR)
        return False

    save_file_path = dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\funclist\\allfunc_list\\dic_allfunc_list.txt"

    funcinfiles = {}
    for file_name in file_list_txt:

        load_file_path = dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\txt\\funccall_cov\\all\\" + file_name

        line_count = 0

        with open(load_file_path, 'r', encoding='utf-8', newline='') as file:
            for line in file.readlines():
                #line = line.replace("_", "")
                if line == '\n':
                    continue
                if 'cocofun' in line:
                    continue
                line = line.replace(" ", "")
                line = line.strip()
                split_line = line.split('|')

                if line_count == 0:
                    line_count = line_count + 1
                    continue
                elif line_count == 1:
                    list_first_line = split_line
                else:
                    funclist[split_line[0]] = split_line[2]
                    if not file_name in funcinfiles.keys():
                        funcinfiles[file_name] = []
                    funcinfiles[file_name].append(split_line[0])

                line_count = line_count + 1

    dic_allfunclist_rawdata['AllFuncList'] = funclist.copy()
    dic_allfunclist_rawdata['FuncInFiles'] = funcinfiles.copy()

    if not pa.object_file_dump(save_file_path, dic_allfunclist_rawdata, "wb"):
        log.set_log("REPORT", "Parsed Trace Data Pickle File Save Error", log.Logtype_ERR)
        return False

    funclist.clear()

    return True

def allfunc_list_parser_from_mapxml(dic_project_info):
    funclist = {}
    temp_func_list = {}
    dic_allfunclist_rawdata = {}

    # Get XML Root Tag
    tree = elemTree.parse(dic_project_info['Common_Path']['XML_Path'])

    # Get XML Sub Tag
    # part_tag = tree.find('./part[8]') #for WIA ./part[8]
    part_tag = tree.find('./part[7]')  # for Mando ./part[7]
    sub_part_tag = part_tag.find("./part[2]")
    table_tag = sub_part_tag.find("table")

    dic_sw_usage = {}

    for i in table_tag.iter("row"):
        dic_sw_usage_temp = {}

        memory_area = i.text
        link_result = memory_area.split(';')
        targetsw_name_and_cd_area = link_result[2].split('.')  # target sw name(ex) func1,func14 and code,data area parse

        if len(targetsw_name_and_cd_area) < 3:
            continue

        if targetsw_name_and_cd_area[1] == 'text':


            file_name = targetsw_name_and_cd_area[2]
            temp = targetsw_name_and_cd_area[3].split(' ')

            #find func name
            funcname = temp[0]

            #find func start addr
            func_start_addr = link_result[4]
            func_start_addr = func_start_addr[2:]

            # find func end addr
            func_end_addr = hex(int(link_result[4],0) + int(link_result[3],0) - 1)
            func_end_addr = func_end_addr[2:]

            # calculate func addr range
            func_addr_range = 'P:'+func_start_addr+'--'+func_end_addr

            funclist[funcname] = func_addr_range

            dic_allfunclist_rawdata['AllFuncList'] = funclist
            #print('asd')


    if not os.path.isdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\txt\\funccall_cov\\all"):
        log.set_log("REPORT", "Coverage folder path is not exist", log.Logtype_ERR)
        return False

    if not os.path.isdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\funclist\\allfunc_list"):
        os.makedirs(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\funclist\\allfunc_list")

    file_list = os.listdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\txt\\funccall_cov\\all")
    file_list_txt = [file for file in file_list if file.endswith(".txt")]

    if not file_list_txt:
        log.set_log("REPORT", "folder is empty", log.Logtype_ERR)
        return False

    save_file_path = dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\funclist\\allfunc_list\\dic_allfunc_list.txt"

    funcinfiles = {}
    for file_name in file_list_txt:

        load_file_path = dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\txt\\funccall_cov\\all\\" + file_name

        line_count = 0

        with open(load_file_path, 'r', encoding='utf-8', newline='') as file:
            for line in file.readlines():
                #line = line.replace("_", "")
                if line == '\n':
                    continue
                if 'cocofun' in line:
                    continue
                line = line.replace(" ", "")
                line = line.strip()
                split_line = line.split('|')

                if line_count == 0:
                    line_count = line_count + 1
                    continue
                elif line_count == 1:
                    list_first_line = split_line
                else:
                    funclist[split_line[0]] = split_line[2]
                    if not file_name in funcinfiles.keys():
                        funcinfiles[file_name] = []
                    funcinfiles[file_name].append(split_line[0])

                line_count = line_count + 1

    dic_allfunclist_rawdata['AllFuncList'] = funclist.copy()
    dic_allfunclist_rawdata['FuncInFiles'] = funcinfiles.copy()

    if not pa.object_file_dump(save_file_path, dic_allfunclist_rawdata, "wb"):
        log.set_log("REPORT", "Parsed Trace Data Pickle File Save Error", log.Logtype_ERR)
        return False

    funclist.clear()

    return True


#code_coverage_parsing(r"C:\Git\1.Prost\Debug\Report\python\testfile\cov_merge", r"C:\Git\1.Prost\Debug\Report\python\testfile\cov_merge")
#allfunc_list_parser(dic_path)
"""
if __name__ == "__main__":

    result = main()
    if result:
        log.set_log("REPORT", "Report Module Pass", log.Logtype_PRG)
    else:
        log.set_log("REPORT", "Report Module Fail", log.Logtype_ERR)

#code Backup

import os, sys
import pickle_api as pa
import log_mod as log

dic_path = {}
dic_path['DebugData'] = r"C:\Temp\FuncCallList"


def func_list_parser(dic_path):
    #dic_coverage_rawdata = []
    funclist = {}
    dic_allfunclist_rawdata = {}

    if not os.path.isdir(dic_path['WorkingProject_Path'] + "\\Debug\\txt\\funclist\\all"):
        log.set_log("REPORT", "Coverage folder path is not exist", log.Logtype_ERR)
        #print(1)
        return False

    scenario_folderlist = os.listdir(dic_path['DebugData'])

    for scenario_name in scenario_folderlist:

        file_list = os.listdir(dic_path['DebugData'] + "\\" + scenario_name)
        #print(file_list)
        file_list_txt = [file for file in file_list if file.endswith(".txt")]
        #print(file_list_txt)

        if not file_list_txt:
            log.set_log("REPORT", "folder is empty", log.Logtype_ERR)
            return False

        for file_name in file_list_txt:

            load_file_path = dic_path['DebugData'] + "\\" + scenario_name + "\\" + file_name
            save_file_path = r"C:\Temp\Test\\" + file_name
            #save_file_path = save_file_path.replace(".txt", "")

            line_count = 0

            with open(load_file_path, 'r', encoding='utf-8', newline='') as file:
                for line in file.readlines():

                    line = line.replace("_", "")
                    line = line.replace(" ", "")
                    line = line.strip()
                    split_line = line.split('|')

                    if line_count == 0:
                        line_count = line_count + 1
                        continue
                    elif line_count == 1:
                        list_first_line = split_line
                    else:
                        funclist[split_line[0]] = split_line[2]

                    line_count = line_count + 1


        dic_allfunclist_rawdata[scenario_name] = funclist.copy()

        if not pa.object_file_dump(save_file_path, dic_allfunclist_rawdata, "wb"):
            log.set_log("REPORT", "Parsed Trace Data Pickle File Save Error", log.Logtype_ERR)
            return False

        funclist.clear()

    return True

#code_coverage_parsing(r"C:\Git\1.Prost\Debug\Report\python\testfile\cov_merge", r"C:\Git\1.Prost\Debug\Report\python\testfile\cov_merge")
func_list_parser(dic_path)
"""