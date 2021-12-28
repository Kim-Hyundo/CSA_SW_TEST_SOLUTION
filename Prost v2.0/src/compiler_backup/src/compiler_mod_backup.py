import os
import shutil
import subprocess
import pickle
from datetime import datetime
import log_mod as log_mod
import glob

import modify_cstart_h as mch
import create_default_cstart_c as cdc

supported_cpu_6_2 = ['tc23x', 'tc26x', 'tc27x']
supported_cpu_4_3 = ['tc23x', 'tc26x', 'tc27x']
supported_tasking = ['4.3', '6.2']

# targetSWCopy    #################################################################
def copyTree(PATH_INFO, src, dst, symlinks=False, ignore=None):
    shutil.copytree
    """
    Recursively copy a directory tree.
    :param src: source folder
    :param dst: dest folder
    :param symlinks: False
    :param ignore: None
    :return:
    """
    log_mod.set_log('## Func: copyTree', log_mod.Logtype_PFF)
    log_mod.set_log('src: ' + src + '  ->  dest: ' + dst, log_mod.Logtype_PRG)
    if not os.path.exists(src):
        log_mod.set_log('Not Exist src folder, can not copied:' + src, log_mod.Logtype_ERR)
        #errorLog(PATH_INFO, 102, 'Not Exist src folder, can not copied:' + src)
        return
    if not os.path.exists(dst):
        os.makedirs(dst)
        shutil.copystat(src, dst)
    lst = os.listdir(src)
    log_mod.set_log(src + "copied to " +dst, log_mod.Logtype_INF)
    if ignore:
        excl = ignore(src, lst)
        lst = [x for x in lst if x not in excl]
    for item in lst:
        s = os.path.join(src, item)
        d = os.path.join(dst, item)
        if symlinks and os.path.islink(s):
            if os.path.lexists(d):
                os.remove(d)
                log_mod.set_log("removed" + d, log_mod.Logtype_INF)
            os.symlink(os.readlink(s), d)
            try:
                st = os.lstat(s)
                mode = os.stat.S_IMODE(st.st_mode)
                os.lchmod(d, mode)
            except:
                pass
        elif os.path.isdir(s):
            copyTree(PATH_INFO, s, d, symlinks, ignore)
        else:
            shutil.copy2(s, d)
            log_mod.set_log(s + "copied to " + d, log_mod.Logtype_INF)


def removeAllFile(file_path):
    log_mod.set_log('## Func: removeAllFile, file_path:' + file_path, log_mod.Logtype_PFF)
    #log(PATH_INFO, '## Func: removeAllFile, file_path:' + file_path)
    files = os.listdir(file_path)

    for file in files:
        fullfilename = os.path.join(file_path, file)
        if os.path.isdir(fullfilename):
            shutil.rmtree(fullfilename)
        else:
            os.remove(fullfilename)


def targetSWCopy(dic_project_info):
    """
    Copy T15 Template -> Target SW to test
    :return: Pass/ Fail
    """
    log_mod.set_log('## Func: targetSWCopy', log_mod.Logtype_PFF)
    #log(PATH_INFO, '## Func: targetSWCopy')

    target_sw_path = dic_project_info['Common_Path']['Project_Root_Path'] + "\\Target_SW"
    template_path = dic_project_info['Common_Path']['T15_Install_Path'] + "\\src\\compiler\\Template"

    if os.path.isdir(target_sw_path + "\\Debug"):
        shutil.rmtree(target_sw_path + "\\Debug")

    #log(PATH_INFO, 'Copy from Template to Workspace', info_log=True)
    log_mod.set_log('Copy from Template to Workspace', log_mod.Logtype_INF)
    # TargetSW Folder All Clear
    """
    try:
        if not os.path.isdir(target_sw_path):
            os.mkdir(target_sw_path)
        else:
            removeAllFile(target_sw_path)
    except Exception as e:
        #errorLog(PATH_INFO, 103, '[TargetSW Copy]' + str(e))
        log_mod.set_log('[TargetSW Copy]' + str(e), log_mod.Logtype_ERR)
        return False
    """
    
    # Create Startup File(.c, .h)
    cdc.create_default_cstart_c(dic_project_info, template_path, target_sw_path)
    mch.modify_cstart_h(dic_project_info, target_sw_path)

    #copyTree(PATH_INFO, template_path + "\\Startup\\TASKING\\" + cur_tasking_ver + "\\" + PROJECT_INFO['Test_CPU'], target_sw_path)


    # Copy Template Code
    log_mod.set_log('Copy Template Code from' + template_path + "\\Batch" + 'To' + target_sw_path, log_mod.Logtype_DGB)
    copyTree(dic_project_info['Common_Path'], template_path + "\\Batch", target_sw_path)
    log_mod.set_log('Copy Template Code from' + template_path + "\\Main" + 'To' + target_sw_path, log_mod.Logtype_DGB)
    copyTree(dic_project_info['Common_Path'], template_path + "\\Main\\" + dic_project_info['Test_Env']['Test_CPU'], target_sw_path)

    copyTree(dic_project_info['Common_Path'], template_path + "\\Linkerscript\\" + dic_project_info['Test_Env']['Test_CPU'], target_sw_path)
    #if os.path.isfile(target_sw_path + "\\" + dic_project_info['Test_Env']['Test_Component'] + ".lsl"):
    #    os.remove(target_sw_path + "\\" + dic_project_info['Test_Env']['Test_Component'] + ".lsl")
    #os.rename(target_sw_path + "\\linker_script.lsl", target_sw_path + "\\" + dic_project_info['Test_Env']['Test_Component'] + ".lsl")
    copyTree(dic_project_info['Common_Path'], template_path + "\\Makefile", target_sw_path + "\\Debug")

    # Test Code Copy
    #copyTree(dic_project_info['Common_Path'], dic_project_info['Test_Env']['Test_Code_Path'], target_sw_path)
    return True


#####################################################################################


# modifyTargetSW    #################################################################
def createMainFunc(dic_project_info):
    """
    Create Main Function
    :return:
    """
    log_mod.set_log('## Func: createMainFunc', log_mod.Logtype_PFF)
    #log(PATH_INFO, '## Func: createMainFunc')
    target_sw_path = dic_project_info['Common_Path']['Project_Root_Path'] + "\\Target_SW"

    # main.c
    f = open(target_sw_path + '\\prost_main.c', 'rt')
    new_data = f.read()
    f.close()

    f = open(target_sw_path + '\\prost_main.c', 'wt')

    # 1.Include Header
    log_mod.set_log('generate header files', log_mod.Logtype_PRG)
    src_key = "$$${HEADERS}$$$"
    headers = ""

    runnables = list(dic_project_info['Compiler']['Runnable_List'].values())

    for runnable in runnables:
        header = runnable.split('$$')
        if header[3] in headers:
            continue
        headers += '#include \"' + header[3] + '\"\n'
        # log(PATH_INFO, 'Runnable_Header: ' + new_val)
        log_mod.set_log('Runnable_Header: ' + header[3], log_mod.Logtype_INF)

    new_data = new_data.replace(src_key, headers)

    # 2.Call Init Function

    log_mod.set_log('generate init function', log_mod.Logtype_PRG)
    for core_name, enable in dic_project_info['Compiler']['Core'].items():

        new_vals = ''
        src_key = "$$${INITIALIZE_" + core_name + "}$$$"

        if enable == 'TRUE':
            init_funcs = list(dic_project_info['Compiler']['InitFunction_List'].values())
            for init_func in init_funcs:
                new_vals += '    ' * 1 + init_func + '; \n'
                log_mod.set_log('Init_Function: ' + init_func, log_mod.Logtype_INF)

        else:
            new_vals += '    '

        new_data = new_data.replace(src_key, new_vals)
    # init_func = dic_project_info['Compiler']['Init_Func']

    """
    new_vals = ''
    i = 0
    for init_func in init_funcs:
        new_vals += '    ' * 1 + init_func + '\n'
        log_mod.set_log('Init_Function: ' + init_func, log_mod.Logtype_INF)

    new_data = new_data.replace(src_key, new_vals)
    """

    # 3.Runnable Flags
    log_mod.set_log('check runnable config', log_mod.Logtype_PRG)
    src_key = "$$${RUNNABLE_FLAGS}$$$"
    new_vals = 'volatile char __T15_RUNNABLE_FLAGS[' + str(len(dic_project_info['Compiler']['Runnable_List'])) + '];'
    new_data = new_data.replace(src_key, new_vals)

    # 3.Gloabal Variables Flags
    log_mod.set_log('Global Variables create', log_mod.Logtype_PRG)
    src_key = "$$${GLOBAL_VAR_FLAGS}$$$"
    #new_vals = 'volatile char __T15_RUNNABLE_FLAGS[' + str(len(dic_project_info['Compiler']['Runnable_List'])) + '];'
    new_vals = ''
    for runnable in runnables:

        runnable = runnable.split('$$')
        parameters = runnable[0].split('(')
        parameters = parameters[1][:-1]
        parameters = parameters.split(',')

        for parameter in parameters:
            parameter=parameter.strip()
            if len(parameter):
                new_vals += parameter + ';\n'

    new_data = new_data.replace(src_key, new_vals)

    # 4.Enum Func Flag List
    log_mod.set_log('Enum Func Flag create', log_mod.Logtype_PRG)
    src_key = "$$${ENUM_FUNCLIST_FLAGS}$$$"
    # new_vals = 'volatile char __T15_RUNNABLE_FLAGS[' + str(len(dic_project_info['Compiler']['Runnable_List'])) + '];'
    new_vals = ''
    for runnable in runnables:
        runnable = runnable.split('$$')
        func_name = runnable[0].split('(')
        new_vals += func_name[0] + '_flag,\n'

    new_data = new_data.replace(src_key, new_vals)

    # 4.Runnable Mapping
    for core_name, enable in dic_project_info['Compiler']['Core'].items():
        new_vals = ''
        if enable == 'TRUE':

            new_vals += '    ' * 2 + 'Check_Point();\n'
            src_key = "$$${RUNNABLES_" + core_name + "}$$$"
            runnables = list(dic_project_info['Compiler']['Runnable_List'].values())

            i = 0
            for runnable in runnables:

                runnable = runnable.split('$$')
                func_name = runnable[0].split('(')
                func_flag = func_name[0] + '_flag'
                new_vals += '    ' * 2 + 'if(loop_cnt % ' + runnable[1] + ' == 0) \n'
                new_vals += '    ' * 2 + '{\n'
                new_vals += '    ' * 3 + '__T15_RUNNABLE_FLAGS[' + str(i) + '] = 1;\n'
                new_vals += '    ' * 3 + 'if((run_func_flag & BIT('+func_flag+'))==BIT('+func_flag+'))\n'
                new_vals += '    ' * 4 + runnable[0] + '; \n'
                new_vals += '    ' * 3 + '__T15_RUNNABLE_FLAGS[' + str(i) + '] = 0;\n'
                new_vals += '    ' * 3 + '__asm("nop");\n'
                new_vals += '    ' * 2 + '}\n\n'
                i = i + 1
                #log(PATH_INFO, 'Runnable: ' + runnable[0] + ' ,Ruuanble Call Period: ' + runnable[1] + ' cycle')
                log_mod.set_log('Runnable: ' + runnable[0] + ' ,Runnable Call Period: ' + runnable[1] + ' cycle', log_mod.Logtype_INF)

            new_vals += '    ' * 2 + 'loop_cnt++;\n'
            new_vals += '    ' * 2 + 'if(loop_cnt > 100)\n'
            new_vals += '    ' * 3 + 'loop_cnt  = 1;\n'

            new_data = new_data.replace(src_key, new_vals)

        else:
            src_key = "$$${RUNNABLES_" + core_name + "}$$$"

            new_vals += '    ' * 2 + '__asm("nop");'
            new_data = new_data.replace(src_key, new_vals)

    f.write(new_data)
    f.close()

# modifyTargetSW    #################################################################
def modifyBatchFile(dic_project_info):
    """
    Modify Batch File
    :return:
    """

    # log(PATH_INFO, '## Func: modifyStartupHeader, Cpu_Clock: ' + PROJECT_INFO['Cpu_Clock'])
    log_mod.set_log('## Func: modifyBatchFile', log_mod.Logtype_PFF)
    target_sw_path = dic_project_info['Common_Path']['Project_Root_Path'] + "\\Target_SW"

    f = open(target_sw_path + '\\build.bat', 'rt')
    new_data = f.read()
    f.close()

    f = open(target_sw_path + '\\build.bat', 'wt')

    # 1.Project Name
    src_key = "$$${COMPILER_AMK_PATH}$$$"
    new_val = dic_project_info['Compiler']['Compiler_Path'] + "\\ctc\\bin\\amk"
    new_data = new_data.replace(src_key, new_val)
    f.write(new_data)
    f.close()


def modifyStartupHeader(dic_project_info):
    """
    cstart.h -> Modify
    :return:
    """
    #log(PATH_INFO, '## Func: modifyStartupHeader, Cpu_Clock: ' + PROJECT_INFO['Cpu_Clock'])
    log_mod.set_log('## Func: modifyStartupHeader, Cpu_Clock: ' + dic_project_info['Test_Env']['CPU_Clock'], log_mod.Logtype_INF)
    target_sw_path = dic_project_info['Common_Path']['Project_Root_Path'] + "\\Target_SW"
    f = open(target_sw_path + '\\cstart.h', 'rt')
    new_data = f.read()
    f.close()

    f = open(target_sw_path + '\\cstart.h', 'wt')

    # 1.Project Name
    src_key = "$$${FOSC}$$$"
    new_val = dic_project_info['Test_Env']['CPU_Clock']
    new_data = new_data.replace(src_key, new_val)
    f.write(new_data)
    f.close()


def modifyLinkerScript(dic_project_info):
    """
    Runnable Code -> RAM or ROM Mapping
    :return:
    """
    #log(PATH_INFO, '## Func: modifyLinkerScript')
    log_mod.set_log('## Func: modifyLinkerScript', log_mod.Logtype_PFF)

    target_sw_path = dic_project_info['Common_Path']['Project_Root_Path'] + "\\Target_SW"

    f = open(target_sw_path + "\\" + dic_project_info['Test_Env']['Test_Component'] + ".lsl", 'rt')
    new_data = f.read()
    f.close()

    f = open(target_sw_path + "\\" + dic_project_info['Test_Env']['Test_Component'] + ".lsl", 'wt')
    src_key = "### $$${SECTION_LAYOUT_abs18}$$$"
    new_data = new_data.replace(src_key, dic_project_info['Compiler']['Memory_Section']['abs18'])
    src_key = "### $$${SECTION_LAYOUT_linear}$$$"
    new_data = new_data.replace(src_key, dic_project_info['Compiler']['Memory_Section']['linear'])
    """
    f = open(target_sw_path + "\\" + dic_project_info['Test_Env']['Test_Component'] + ".lsl", 'wt')
    for section_type, memory in dic_project_info['Compiler']['Memory_Section'].items():
        new_vals = ''
        if section_type == 'text':
            src_key = "### $$${SECTION_TYPE_TEXT}$$$"
            load_run_memory = memory.split('$$')
            new_vals += '    ' + 'group (load_addr=mem:mpe:' + load_run_memory[0] + ')\n'
            new_vals += '    ' * 2 + 'select ".text.*.*";\n\n'
            new_vals += '    ' + 'group (copy, run_addr=mem:mpe:' + load_run_memory[1] + ')\n'
            new_vals += '    ' * 2 + 'select ".text.*.*";\n\n'
            new_data = new_data.replace(src_key, new_vals)

        elif section_type == 'zdata':
            src_key = "### $$${SECTION_TYPE_ZDATA}$$$"
            load_run_memory = memory.split('$$')
            new_vals += '    ' + 'group (load_addr=mem:mpe:' + load_run_memory[0] + ')\n'
            new_vals += '    ' * 2 + 'select ".zdata.*.*";\n\n'
            new_vals += '    ' + 'group (copy, run_addr=mem:mpe:' + load_run_memory[1] + ')\n'
            new_vals += '    ' * 2 + 'select ".zdata.*.*";\n\n'
            new_data = new_data.replace(src_key, new_vals)

        elif section_type == 'data':
            src_key = "### $$${SECTION_TYPE_DATA}$$$"
            load_run_memory = memory.split('$$')
            new_vals += '    ' + 'group (load_addr=mem:mpe:' + load_run_memory[0] + ')\n'
            new_vals += '    ' * 2 + 'select ".data.*.*";\n\n'
            new_vals += '    ' + 'group (copy, run_addr=mem:mpe:' + load_run_memory[1] + ')\n'
            new_vals += '    ' * 2 + 'select ".data.*.*";\n\n'
            new_data = new_data.replace(src_key, new_vals)

        elif section_type == 'bss':
            src_key = "### $$${SECTION_TYPE_BSS}$$$"
            new_vals += '    ' + 'group (run_addr=mem:mpe:' + memory + ')\n'
            new_vals += '    ' * 2 + 'select ".bss.*.*";\n\n'
            new_data = new_data.replace(src_key, new_vals)

        elif section_type == 'zbss':
            src_key = "### $$${SECTION_TYPE_ZBSS}$$$"
            new_vals += '    ' + 'group (run_addr=mem:mpe:' + memory + ')\n'
            new_vals += '    ' * 2 + 'select ".zbss.*.*";\n\n'
            new_data = new_data.replace(src_key, new_vals)
    """
    f.write(new_data)
    f.close()


def createStubFuncs(dic_project_info):
    """
    Create Stub Functions
    :return:
    """
    #log(PATH_INFO, '## Func: createStubFuncs')
    log_mod.set_log('## Func: createStubFuncs', log_mod.Logtype_PFF)

    target_sw_path = dic_project_info['Common_Path']['Project_Root_Path'] + "\\Target_SW"
    # stubs.c file
    f = open(target_sw_path + '\\prost_stubs.c', 'wt')

    #delay_coeff

    f.write('int delay_coeff = ' + dic_project_info['Compiler']['Delay_Coeff'] + ';\n\n')

    f.write("#pragma optimize 0\n")
    f.write("void Prost_Delay(int us)\n")
    f.write('{\n')
    f.write('    if (us <= 0)\n')
    f.write('        return;\n\n')
    f.write('    int i = 0;\n')
    f.write('    i = delay_coeff*us-delay_coeff/2;\n')
    f.write('    while(i-->2)\n')
    f.write('        __asm("nop");\n')
    f.write("}\n")
    f.write("#pragma endoptimize\n")
    f.write("\n\n")

    stubs = list(dic_project_info['Compiler']['Stub_List'].values())

    for stub in stubs:
        stub = stub.split('$$')
        f.write(stub[0] + "\n")
        f.write("{\n")
        f.write("    Prost_Delay(" + stub[1] + ");\n")
        if stub[2] != 'no return':
            f.write("    return " + stub[2] + ";\n")
        f.write("}\n")
        #log(PATH_INFO, 'Stub: ' + stub[0])
        log_mod.set_log('Stub: ' + stub[0], log_mod.Logtype_INF)


    f.close()
    # stubs.h file
    f = open(target_sw_path + '\\prost_stubs.h', 'wt')
    for stub in stubs:
        f.write(stub[0] + ";\n")

    f.close()


#def modifyTargetSW(PATH_INFO, PROJECT_INFO, RUNNABLE_INFO, STUB_LIST):
def modifyTargetSW(dic_project_info):
    #log(PATH_INFO, 'Modify Target_SW Main/Startup code', info_log=True)
    log_mod.set_log('Modify Target_SW Main/Startup code', log_mod.Logtype_PFF)
    """
    Modify Target SW from Template
    :return:
    """

    try:
        #createMainFunc(PATH_INFO, PROJECT_INFO, RUNNABLE_INFO)
        #modifyStartupHeader(PATH_INFO, PROJECT_INFO)
        #modifyLinkerScript(PATH_INFO, PROJECT_INFO, RUNNABLE_INFO)
        #createStubFuncs(PATH_INFO, STUB_LIST, PROJECT_INFO)
        createMainFunc(dic_project_info)
        modifyBatchFile(dic_project_info)
        #modifyStartupHeader(dic_project_info)
        #modifyLinkerScript(dic_project_info)
        createStubFuncs(dic_project_info)
    except Exception as e:
        #errorLog(PATH_INFO, 105, '[Modify Target_SW]' + str(e))
        log_mod.set_log('[Modify Target_SW]' + str(e), log_mod.Logtype_ERR)
        return False
    else:
        return True


#####################################################################################


# makeBuildEnviroment    ############################################################
def search(dir, len, filelist, dirlist):
    """
    search directory / souce code list
    :param dir:
    :param len:
    :param filelist:
    :param dirlist:
    :return:
    """
    files = os.listdir(dir)
    for file in files:
        full_file_name = os.path.join(dir, file)
        if os.path.isdir(full_file_name) and (os.path.basename(full_file_name) != 'Debug'):
            dirlist.append(full_file_name[len + 1:])
            search(full_file_name, len, filelist, dirlist)
        else:
            fname, ext = os.path.splitext(full_file_name)
            if ext == '.c':
                filelist.append(full_file_name[len + 1:])


def createMakefile(dic_project_info, dirlist):
    """
    Auto Generation makefile
    :param dirlist: directory list
    :return:
    """
    #log(PATH_INFO, '## Func: createMakefile')
    log_mod.set_log('## Func: createMakefile', log_mod.Logtype_PFF)
    target_sw_path = dic_project_info['Common_Path']['Project_Root_Path'] + "\\Target_SW"
    makefile_path = target_sw_path + "\\Debug\\makefile"

    # makefile
    if not os.path.exists(makefile_path):
        #errorLog(PATH_INFO, 106, 'makefile does not exist')
        log_mod.set_log('makefile does not exist', log_mod.Logtype_ERR)
        return False

    f = open(makefile_path, 'rt')
    new_data = f.read()
    f.close()

    f = open(makefile_path, 'wt')
    # 1.Project Name
    src_key = "### $$${PROJECT_NAME}$$$"
    new_val = "PROJ = " + dic_project_info['Test_Env']['Test_Component']
    new_data = new_data.replace(src_key, new_val)

    # 2.Compiler Path
    new_val = ''
    src_key = "### $$${COMPILER_PATH}$$$"
    new_val = "COMPILER = " + dic_project_info['Compiler']['Compiler_Path']
    new_data = new_data.replace(src_key, new_val)

    # 2.Workspace Path
    new_val = ''
    src_key = "### $$${workspace_loc}$$$"
    new_val = "workspace_loc = " + dic_project_info['Common_Path']['Workspace_Path']
    new_data = new_data.replace(src_key, new_val)
	
    # 3.Include Path
    new_val = ''
    src_key = "### $$${INCLUDE_PATH}$$$"
    #new_val = 'INC += -I\"' + target_sw_path + '\"'
    #for dir in dirlist:
    #    new_val += '\nINC += -I\"' + target_sw_path + '\\' + dir + '\"'

    src_list = []
    dir_list = []
    search(target_sw_path, len(target_sw_path), src_list, dir_list)
    src_key = "### $$${INCLUDE_PATH}$$$"
    new_val = 'INC += -I\"' + target_sw_path + '\"'
    #for dir in dirlist:
    #    new_val += '\nINC += -I\"' + target_sw_path + '\\' + dir + '\"'
    #new_data = new_data.replace(src_key, new_val)

    for index, include_path in dic_project_info['Compiler']['IncludePath_List'].items():
        new_val += '\nINC += -I\"' + include_path + '\"'
    new_data = new_data.replace(src_key, new_val)

    # 4.Library Path
    new_val = ''
    src_key = "### $$${LIBRARY_PATH}$$$"
    all_lib = ''
    for lib_index, lib_name in dic_project_info['Compiler']['Library_List'].items():
        all_lib += lib_name + " "
    new_val = 'LIBS += ' + all_lib
    new_data = new_data.replace(src_key, new_val)

    # 5.Target Info
    new_val = ''
    src_key = "### $$${TARGET_INFO}$$$"
    new_val = "TARGET = " + dic_project_info['Test_Env']['Test_CPU']
    new_data = new_data.replace(src_key, new_val)

    # 6.Build Option
    new_val = ''
    src_key = "### $$${COMPILER_OPTION}$$$"
    new_val = "COMPILE_OPT = " + dic_project_info['Compiler']['Compiler_Option']
    new_data = new_data.replace(src_key, new_val)

    # 7. Linker Option
    new_val = ''
    src_key = "### $$${LINKER_OPTION}$$$"
    new_val = "LINK_OPT = " + dic_project_info['Compiler']['Linker_Option']
    new_data = new_data.replace(src_key, new_val)

    # 8. Include subdik.mk path
    new_val = ''
    src_key = "### $$${SUBDIRMK_INCLUDE_PATH}$$$"
    for subdir_path in dirlist:
        for file in os.listdir(target_sw_path+"\\"+subdir_path):
            if file.endswith(".c"):
                subdir_mk_path = subdir_path + "\\subdir.mk"
                new_val += "-include " + '"' +subdir_mk_path + '"' + "\n"
                break


    new_data = new_data.replace(src_key, new_val)

    f.write(new_data)
    f.close()

    #log(PATH_INFO, 'COMPILE_OPT: ' + BUILD_OPTION['Compiler_Option'])
    #log(PATH_INFO, 'LINKER_OPT: ' + BUILD_OPTION['Linker_option'])
    log_mod.set_log('COMPILE_OPT: ' + dic_project_info['Compiler']['Compiler_Option'], log_mod.Logtype_INF)
    log_mod.set_log('LINKER_OPT: ' + dic_project_info['Compiler']['Linker_Option'], log_mod.Logtype_INF)

    return True


def createSubdirMk(dic_project_info, dirlist):
    """
    Auto Generation subdir.mk
    :param dirlist: directory list
    :param srclist: source code( *.c) list
    :return:
    """

    log_mod.set_log('## Func: createSubdirMk', log_mod.Logtype_PFF)

    target_sw_path = dic_project_info['Common_Path']['Project_Root_Path'] + "\\Target_SW"
    subdir_path = target_sw_path + "\\Debug\\subdir.mk"

    if not os.path.exists(subdir_path):
        log_mod.set_log('subdir.mk does not exist', log_mod.Logtype_ERR)
        return False

    # create sub directory and copy subdir.mk file in Debug folder
    for dir in dirlist:
        os.mkdir(target_sw_path + "\\Debug\\" + dir)
        sub_dir_srclist = os.listdir(target_sw_path + "\\" + dir)
        for src in sub_dir_srclist:
            if '.c' in src:
                shutil.copy2(subdir_path, target_sw_path + "\\Debug\\" + dir)
                break

    # create subdir.mk in Debug root folder
    f = open(subdir_path, 'rt')
    new_data = f.read()
    f.close()

    f = open(subdir_path, 'wt')

    src_key = "### $$${BUILDFILE_LIST}$$$"
    new_val = ""
    root_dir_srclist = os.listdir(target_sw_path)
    for src in root_dir_srclist:
        fname, ext = os.path.splitext(src)
        if ext == '.c':
            new_val += 'C_FILES += \"..\\' + fname + '.c\"\n'
            new_val += 'OBJ_FILES += \"' + fname + '.o\"\n'
            new_val += '\"' + fname + '.o\" : \"..\\' + fname + '.c\"\n'
            new_val += '\t@echo Compiling ${<F}\n'
            new_val += '\t@$(COMPILER)\\ctc\\bin\\cctc -o \"' + fname + '.o\" \"..\\' + fname + \
                       '.c\" $(COMPILE_OPT) -c -Wc--make-target=\"' + fname + '.o\"\n'
            new_val += '\n\n'

        #log(PATH_INFO, 'Buildfile_list: ' + fname)
        log_mod.set_log('Buildfile_list: ' + fname, log_mod.Logtype_INF)

    new_data = new_data.replace(src_key, new_val)
    f.write(new_data)
    f.close()

    # create subdir.mk in Debug sub folder
    for subdir_path in dirlist:
        sub_dir_srclist = os.listdir(target_sw_path + "\\Debug\\" + subdir_path)
        for src in sub_dir_srclist:
            if '.mk' in src:
                subdir_mk = target_sw_path + "\\Debug\\" + subdir_path + "\\subdir.mk"

                # subdir.mk
                f = open(subdir_mk, 'rt')
                new_data = f.read()
                f.close()

                f = open(subdir_mk, 'wt')
                # 2.Inculde Path
                src_key = "### $$${BUILDFILE_LIST}$$$"
                new_val = ""
                sub_dir_srclist = os.listdir(target_sw_path + "\\" + subdir_path)
                for src in sub_dir_srclist:
                    fname, ext = os.path.splitext(src)
                    if ext == '.c':
                        new_val += 'C_FILES += \"..\\' + subdir_path + "\\" + fname + '.c\"\n'
                        new_val += 'OBJ_FILES += \"' + subdir_path + "\\" + fname + '.o\"\n'
                        new_val += '\"' + subdir_path + "\\" + fname + '.o\" : \"..\\' + subdir_path + "\\" + fname + '.c\"\n'
                        new_val += '\t@echo Compiling ${<F}\n'
                        new_val += '\t@$(COMPILER)\\ctc\\bin\\cctc -o \"' + subdir_path + "\\" + fname + '.o\" \"..\\' + subdir_path + "\\" + fname + \
                                   '.c\" $(COMPILE_OPT) -c -Wc--make-target=\"' + subdir_path + "\\" + fname + '.o\"\n'
                        new_val += '\n\n'

                    # log(PATH_INFO, 'Buildfile_list: ' + fname)
                    log_mod.set_log('Buildfile_list: ' + subdir_path + "\\" + fname, log_mod.Logtype_INF)

                new_data = new_data.replace(src_key, new_val)
                f.write(new_data)
                f.close()

                break




    return True


def makeBuildEnviroment(dic_project_info):
    """
    Auto Generation build files (makefile, subdir.mk)
    :return:
    """
    #log(PATH_INFO, '## Func: makeBuildEnviroment')
    log_mod.set_log('## Func: makeBuildEnviroment', log_mod.Logtype_PFF)
    target_sw_path = dic_project_info['Common_Path']['Project_Root_Path'] + "\\Target_SW"

    src_list = []
    dir_list = []
    search(target_sw_path, len(target_sw_path), src_list, dir_list)

    if not createMakefile(dic_project_info, dir_list):
        return False
    if not createSubdirMk(dic_project_info, dir_list):
        return False

    return True


#####################################################################################

def executeTaskingCompiler(dic_project_info):
    """
    Execute Tasking Compiler (Build Start)
    :return:
    """
    #log(PATH_INFO, '## Func: executeTaskingCompiler')
    log_mod.set_log('## Func: executeTaskingCompiler', log_mod.Logtype_PFF)
    log_mod.set_log('Start Tasking Compile', log_mod.Logtype_PRG)

    target_sw_path = dic_project_info['Common_Path']['Project_Root_Path'] + "\\Target_SW"

    if not os.path.exists(dic_project_info['Compiler']['Compiler_Path'] + "\\ctc\\bin"):
        #errorLog(PATH_INFO, 108, "Compiler Path Error")
        log_mod.set_log("Compiler Path Error : " + dic_project_info['Compiler']['Compiler_Path'] + "\\ctc\\bin" , log_mod.Logtype_ERR)
        return None

    os.chdir(target_sw_path + "\\Debug")

    proc = subprocess.Popen(
        [dic_project_info['Compiler']['Compiler_Path'] + "\\ctc\\bin\\amk", '-j8', 'all', '-a'], stdout=subprocess.PIPE
    )

    last_s = ''
    #log(PATH_INFO, '=============================================', info_log=True)
    while proc.poll() is None:
        s = proc.stdout.readline().decode()
        s = s[:-1]
        if s.encode() != b'':
            last_s = s
            #log(PATH_INFO, s, build_log=True)
            log_mod.set_log(s, log_mod.Logtype_CPL)
    return last_s


#####################################################################################


def pickleLoad(pickle_path):
    try:
        with open(pickle_path, 'rb') as f:
            data = pickle.load(f)
    except Exception as e:
        print('[Pickle Load]' + str(e))
        log_mod.set_log('[Pickle Load]' + str(e), log_mod.Logtype_ERR)
        # errorLog(PATH_INFO, 101, '[Pickle Load]' + str(e))
    else:
        return data
