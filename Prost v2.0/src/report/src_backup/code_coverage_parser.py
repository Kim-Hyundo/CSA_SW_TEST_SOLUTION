import os, sys
import pickle_api as pa
import log_mod as log

def code_coverage_parser(dic_project_info):
    log.set_log("REPORT", "code_coverage_parser Processing...", log.Logtype_PFF)
    list_coverage_rawdata = []
    dic_coverage_rawdata = {}

    if not os.path.isdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\txt\\coverage"):
        log.set_log("REPORT", "Coverage txt folder path is not exist", log.Logtype_ERR)
        return False

    scenario_folderlist = os.listdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\txt\\coverage")

    dic_all_func_list = pa.object_file_load(dic_project_info['Common_Path']['WorkingProject_Path'] +"\\Debug\\dic\\funclist\\allfunc_list\\dic_allfunc_list.txt", "rb")

    for scenario_name in scenario_folderlist:

        file_list = os.listdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\txt\\coverage\\" + scenario_name + "\\cov")

        if not file_list:
            log.set_log("REPORT", "folder is empty", log.Logtype_ERR)
            return False

        if not os.path.isdir(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\coverage\\cov"):
            os.makedirs(dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\coverage\\cov")

        for file_name in file_list:

            load_file_path = dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\txt\\coverage\\" + scenario_name + "\\cov\\" + file_name
            save_file_path = dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\coverage\\cov\\" + file_name

            line_count = 0

            with open(load_file_path, 'r', encoding='utf-8', newline='') as file:
                for line in file.readlines():
                    log.set_log("REPORT", "File : " + load_file_path + " Readline : " + line, log.Logtype_DBG)

                    temp = {}

                    if 'address' in line:
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
                        # for Target SW only
                        #if not dic_all_func_list['AllFuncList'].get(split_line[1]):
                        #    continue
                        for index, value in enumerate(list_first_line):
                            temp[list_first_line[index]] = split_line[index]

                        list_coverage_rawdata.append(temp)

                    line_count = line_count + 1

                dic_coverage_rawdata[scenario_name] = list_coverage_rawdata.copy()

            del list_coverage_rawdata[:]
            #dic_coverage_rawdata.clear()

    dic_allfunc_list = pa.object_file_load(
        dic_project_info['Common_Path']['WorkingProject_Path'] + "\\Debug\\dic\\funclist\\allfunc_list\\dic_allfunc_list.txt", "rb")

    dic_sorted_list = {}
    for scenario_name, cov_list in dic_coverage_rawdata.items():
        del_index_list = []
        sort_index_list = []

        if not scenario_name in dic_sorted_list.keys():
            dic_sorted_list[scenario_name] = []
        for index, cov_data in enumerate(cov_list):
            isTargetSW = False
            for function_inTargetSW in dic_allfunc_list['AllFuncList']:
                if function_inTargetSW == cov_data['tree']:
                    isTargetSW = True
                    sort_index_list.append(index)

        for sort_index in sort_index_list:
            dic_sorted_list[scenario_name].append(cov_list[sort_index])


    if not pa.object_file_dump(save_file_path, dic_sorted_list, "wb"):
        log.set_log("REPORT", "Parsed Trace Data Pickle File Save Error", log.Logtype_ERR)
        return False

    log.set_log("REPORT", "code_coverage_parser Processed", log.Logtype_PFF)
    return True

#code_coverage_parsing(r"C:\Git\1.Prost\Debug\Report\python\testfile\cov_merge", r"C:\Git\1.Prost\Debug\Report\python\testfile\cov_merge")
