"""
Program Name : create_default_cstart_c.py
Author : Hyundo Kim
Date : 20.03.26
Description : Create Default Startup C File
"""
import os

def create_default_cstart_c(dic_project_info, template_path, target_sw_path):


    load_file_path = template_path + "\\Startup\\TASKING\\" + dic_project_info['Test_Env']['CompilerVersion'] + "\\" + dic_project_info['Test_Env']['Test_CPU']
    save_file_path = target_sw_path

    cstart_list = os.listdir(load_file_path)

    for filename in cstart_list:
        if '.c' in filename:
            with open(load_file_path + "\\" + filename, 'r', encoding='utf-8', newline='') as filereader:
                with open(save_file_path + "\\" + filename, 'w', encoding='utf-8', newline='') as filewriter:
                    header = filereader.readline()
                    filewriter.write(header)

                    for row in filereader:
                        filewriter.write(row)
    """        
    load_file_path = load_file_path + "\\cstart.c"
    save_file_path = save_file_path + "\\cstart.c"

    with open(load_file_path, 'r', encoding = 'utf-8', newline = '') as filereader:
        with open(save_file_path, 'w', encoding = 'utf-8', newline = '') as filewriter:
            header = filereader.readline()
            filewriter.write(header)

            for row in filereader:
                filewriter.write(row)
    """


#create_default_cstart_c(r"C:\Git\1.Prost\Prost\src\compiler\Template\Startup\TASKING\4.3\tc23x", r"C:\Git\1.Prost\Workspace\Project_Name\Target_SW")