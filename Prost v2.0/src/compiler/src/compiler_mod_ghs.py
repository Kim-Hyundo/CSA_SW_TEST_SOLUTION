import os
import shutil
import subprocess
import log_mod as log_mod

# skc### GHS 맨밑에!
add_dir_list = list()
# template 파일들 target_sw로 복사해오기 전에 ui에서 복사해온 user 소스코드들에 대한 리스트 생성
# targetswcopy 함수 맨 처음에 리스트 생성 후
# makefile에서 컴파일 타겟 정의할 때 쓰임

#skc###GHS##############################################################################################################

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
        # errorLog(PATH_INFO, 102, 'Not Exist src folder, can not copied:' + src)
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

def search_ghs(dir, len, filelist, dirlist, dic_project_info):
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
        if os.path.isdir(full_file_name) and (os.path.basename(full_file_name) != 'Debug') and ('common' != os.path.basename(full_file_name)) and (dic_project_info['Test_Env']['Serise'] + '+' + dic_project_info['Test_Env']['MCU_rev'] != os.path.basename(full_file_name)) and ('lib' != os.path.basename(full_file_name)) and ('linker' != os.path.basename(full_file_name)) and ('build.bat' != os.path.basename(full_file_name)) and ('startup' != os.path.basename(full_file_name)) and ('main' != os.path.basename(full_file_name)):
            dirlist.append(full_file_name[len + 1:])
            search_ghs(full_file_name, len, filelist, dirlist,dic_project_info)
        else:
            fname, ext = os.path.splitext(full_file_name)
            if (ext == '.c') or (ext == '.arm'):
                filelist.append(full_file_name[len + 1:])


def create_default_cstart_c_ghs(dic_project_info, template_path, target_sw_path):
    serise_rev_dir = dic_project_info['Test_Env']['Serise'] + '+' + dic_project_info['Test_Env']['MCU_rev']

    load_file_path = template_path + "\\Startup\\" + dic_project_info['Test_Env']['CompilerVersion'] + "\\" + serise_rev_dir + '\\startup'

    if not os.path.exists(target_sw_path + '\\startup'):
        os.mkdir(target_sw_path + '\\startup')

    save_file_path = target_sw_path + '\\startup'

    cstart_list = os.listdir(load_file_path)

    for filename in cstart_list:
        if '.c' in filename or '.arm' in filename:
            with open(load_file_path + "\\" + filename, 'r', encoding='utf-8', newline='') as filereader:
                with open(save_file_path + "\\" + filename, 'w', encoding='utf-8', newline='') as filewriter:
                    header = filereader.readline()
                    filewriter.write(header)

                    for row in filereader:
                        filewriter.write(row)


# skc### targetSWCopy()#################################################################################################
def targetSWCopy_ghs(dic_project_info):
    """
    Copy T15 Template -> Target SW to test
    :return: Pass/ Fail
    """

    log_mod.set_log('#GHS# Func: targetSWCopy_ghs', log_mod.Logtype_PFF)

    target_sw_path = dic_project_info['Common_Path']['Project_Root_Path'] + "\\Target_SW"
    template_path = dic_project_info['Common_Path']['T15_Install_Path'] + "\\src\\compiler\\Template_GHS"

    # skc### 메인코어 찾기
    main_core = ''
    for core, value in dic_project_info['Compiler']['Core'].items():
        if value == 'TRUE':
            main_core = core

    # src_list = list()
    # dir_list = list()
    # search(target_sw_path, len(target_sw_path), src_list, dir_list, dic_project_info)

    # target_sw_files = os.listdir(target_sw_path)
    # for target_sw_file in target_sw_files:
    #     if '.' not in target_sw_file:
    #         if ('common' in target_sw_file) or (dic_project_info['Test_Env']['Serise'] in target_sw_file) or ('Debug' in target_sw_file) or ('lib' in target_sw_file) or ('linker' in target_sw_file) or ('main' in target_sw_file) or ('startup' in target_sw_file):
    #             shutil.rmtree(target_sw_path + '\\' + target_sw_file)
    #     else:
    #         if 'build.bat' in target_sw_file:
    #             os.remove(target_sw_path + '\\' + target_sw_file)


    # skc### Template에서 필요한 친구들 뽑아오기
    # common 폴더 그냥 복사
    copyTree(dic_project_info['Common_Path'], template_path + "\\Startup\\" + dic_project_info['Test_Env']['CompilerVersion'] + "\\common", target_sw_path + "\\common")

    serise_rev_dir = dic_project_info['Test_Env']['Serise'] + '+' + dic_project_info['Test_Env']['MCU_rev']

    # startup (.c / .arm)
    create_default_cstart_c_ghs(dic_project_info, template_path, target_sw_path)

    # lib
    # template의 lib에 보면 코어 별 lib가 있는데
    # sdl과 crypto 관련 필수 라이브러리의 경우 'lib' 폴더에 있음
    # 지금 당장 필요하지 않은 middleware(mw) rtos 관련 라이브러리는 그냥 빼버림
    copyTree(dic_project_info['Common_Path'], template_path + "\\Startup\\" + dic_project_info['Test_Env']['CompilerVersion'] + "\\" + serise_rev_dir + '\\lib', target_sw_path + '\\lib')

    # 나머지 복사하고 중복되는 lib이랑 startup 삭제
    copyTree(dic_project_info['Common_Path'], template_path + "\\Startup\\" + dic_project_info['Test_Env']['CompilerVersion'] + "\\" + serise_rev_dir, target_sw_path + '\\' + serise_rev_dir)
    if os.path.exists(target_sw_path + '\\' + serise_rev_dir + '\\lib'):
        shutil.rmtree(target_sw_path + '\\' + serise_rev_dir + '\\lib')
    if os.path.exists(target_sw_path + '\\' + serise_rev_dir + '\\startup'):
        shutil.rmtree(target_sw_path + '\\' + serise_rev_dir + '\\startup')

    # linker
    # if user project lsl==true
    # prost.lsl delete
    # copy and rename linker_script.lsl -> prost.lsl
    # test_component.lsl open and write 1st line #include prost.lsl
    # else user project lsl==false
    # copy and rename linker_script.lsl -> test_component.lsl
    if dic_project_info['Compiler']['IsExistMainls'] == 'TRUE': #이거 어떻게 해야하지?
        log_mod.set_log('#GHS# Func: user linker script exist', log_mod.Logtype_PFF)
        copyTree(dic_project_info['Common_Path'], template_path + "\\Linkerscript\\" + dic_project_info['Test_Env']['Serise'], target_sw_path)
        if os.path.isfile(target_sw_path + "\\" + "prost.lsl"):
            os.remove(target_sw_path + "\\" + "prost.lsl")

        os.rename(target_sw_path + "\\linker_script.lsl", target_sw_path + "\\" + "prost.lsl")

        f = open(target_sw_path + "\\" + dic_project_info['Test_Env']['Test_Component'] + ".lsl", "r")
        data = f.read()
        # print(data)
        f.close()

        f = open(target_sw_path + "\\" + dic_project_info['Test_Env']['Test_Component'] + ".lsl", "w")
        f.write("#include \"prost.lsl\"\n")
        f.write(data)
        f.close()

    else:
        log_mod.set_log('## Func: FALSEFALSEFLASE', log_mod.Logtype_PFF)
        copyTree(dic_project_info['Common_Path'], template_path + "\\Linkerscript_prost\\" + dic_project_info['Test_Env']['Serise'], target_sw_path+'\\linker')

    # main
    log_mod.set_log('Copy Template Code from' + template_path + "\\Main" + 'To' + target_sw_path, log_mod.Logtype_DGB)
    copyTree(dic_project_info['Common_Path'], template_path + "\\Main\\" + dic_project_info['Test_Env']['Serise'], target_sw_path+'\\main')

    # batch
    log_mod.set_log('Copy Template Code from' + template_path + "\\Batch" + 'To' + target_sw_path, log_mod.Logtype_DGB)
    copyTree(dic_project_info['Common_Path'], template_path + "\\Batch", target_sw_path)

    # makefile
    copyTree(dic_project_info['Common_Path'], template_path + "\\Makefile", target_sw_path + "\\Debug")

    # global add_dir_list
    #
    # src_list = []
    # dir_list = []
    # search(target_sw_path, len(target_sw_path), src_list, dir_list)
    #
    # target_sw_files = os.listdir(target_sw_path)
    # for target_sw_file in target_sw_files:
    #     if '.' not in target_sw_file:
    #         if ('common' not in target_sw_file) and (dic_project_info['Test_Env']['Serise'] not in target_sw_file) and ('Debug' not in target_sw_file) and ('lib' not in target_sw_file) and ('linker' not in target_sw_file) and ('main' not in target_sw_file) and ('startup' not in target_sw_file):
    #             search(target_sw_path+'\\'+target_sw_file, len(target_sw_path+'\\'+target_sw_file), src_list, dir_list)
    #     else:
    #         if '.c' in target_sw_file:
    #             src_list.append(target_sw_path + '\\' + target_sw_file)
    #
    # add_dir_list = src_list
    #
    # log_mod.set_log('#GHS# delete template files', log_mod.Logtype_INF)

    # Test Code Copy
    # copyTree(dic_project_info['Common_Path'], dic_project_info['Test_Env']['Test_Code_Path'], target_sw_path)
    return True
# skc### targetSWCopy()#################################################################################################

# skc### modifyTargetSW_ghs()###########################################################################################
def modifyTargetSW_ghs(dic_project_info):
    #log(PATH_INFO, 'Modify Target_SW Main/Startup code', info_log=True)
    log_mod.set_log('Modify Target_SW Main/Startup code', log_mod.Logtype_PFF)
    """
    Modify Target SW from Template
    :return:
    """

    try:
        createMainFunc_ghs(dic_project_info)
        modifyBatchFile_ghs(dic_project_info)

        # skc### 나중에 추가해야함
        # 이거 어떻게 해야함?
        #modifyLinkerScript_ghs(dic_project_info)
        #createStubFuncs_ghs(dic_project_info)

    except Exception as e:
        #errorLog(PATH_INFO, 105, '[Modify Target_SW]' + str(e))
        log_mod.set_log('[Modify Target_SW]' + str(e), log_mod.Logtype_ERR)
        return False
    else:
        return True
# skc### modifyTargetSW_ghs()###########################################################################################

# skc### createMainFunc_ghs()##############################################################################################
def createMainFunc_ghs(dic_project_info):
    """
    Create Main Function
    :return:
    """
    log_mod.set_log('#GHS# Func: createMainFunc_ghs', log_mod.Logtype_PFF)
    target_sw_path = dic_project_info['Common_Path']['Project_Root_Path'] + "\\Target_SW"

    f = open(target_sw_path + '\\main\\prost_main.c', 'rt')
    new_data = f.read()
    f.close()

    f = open(target_sw_path + '\\main\\prost_main.c', 'wt')

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
    #
    # new_vals = ''
    # i = 0
    # for init_func in init_funcs:
    #     new_vals += '    ' * 1 + init_func + '\n'
    #     log_mod.set_log('Init_Function: ' + init_func, log_mod.Logtype_INF)
    #
    # new_data = new_data.replace(src_key, new_vals)


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

                parameters = runnable[0].split('(')
                parameters = parameters[1][:-1]
                parameters = parameters.split(',')

                paramtmp=''
                for parameter in parameters:
                    parameter = parameter.strip()
                    if len(parameter):
                        parameter=parameter.split(' ')
                        paramtmp += parameter[1] + ','
                paramtmp = paramtmp[:-1]

                #new_vals += '    ' * 3 + func_name[0] + '(' + paramtmp + ')' + '; \n'
                new_vals += '    ' * 4 + func_name[0] + '(' +paramtmp + ')' + '; \n'

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

    # main_core = ''
    # for core, value in dic_project_info['Compiler']['Core'].items():
    #     if value == 'TRUE':
    #         main_core = core
    #         break
    #
    # os.rename(target_sw_path+'\\main\\prost_main.c', target_sw_path+'\\main\\prost_main_' + main_core + '.c')
# skc### create_mainFunc_ghs()##############################################################################################

# skc### modifyBatchFile_ghs()##############################################################################################
def modifyBatchFile_ghs(dic_project_info):
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
    #new_val = dic_project_info['Compiler']['Compiler_Path'] + "\\ccarm"

    #new_data = new_data.replace(src_key, new_val)
    new_data = new_data.replace(src_key, 'make -f makefile')

    f.write(new_data)
    f.close()
# skc### modifyBatchFile_ghs()##########################################################################################

# skc### modifyLinkerScript_ghs()#######################################################################################
def modifyLinkerScript_ghs(dic_project_info):
    """
    Runnable Code -> RAM or ROM Mapping
    :return:
    """
    # log(PATH_INFO, '## Func: modifyLinkerScript')
    log_mod.set_log('## Func: modifyLinkerScript', log_mod.Logtype_PFF)

    target_sw_path = dic_project_info['Common_Path']['Project_Root_Path'] + "\\Target_SW"

    if dic_project_info['Compiler']['IsExistMainls'] == 'TRUE':
        f = open(target_sw_path + "\\" + "prost.lsl", 'r')
    else:
        f = open(target_sw_path + "\\" + dic_project_info['Test_Env']['Test_Component'] + ".lsl", 'r')
    new_data = f.read()
    # print(new_data)
    f.close()

    if dic_project_info['Compiler']['IsExistMainls'] == 'TRUE':
        f = open(target_sw_path + "\\" + "prost.lsl", 'wt')
    else:
        f = open(target_sw_path + "\\" + dic_project_info['Test_Env']['Test_Component'] + ".lsl", 'wt')

        # f = open(target_sw_path + "\\" + dic_project_info['Test_Env']['Test_Component'] + ".lsl", 'wt')
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
# skc### modifyLinkerScript_ghs()#######################################################################################

# skc### createStubFuncs_ghs()##########################################################################################
def createStubFuncs_ghs(dic_project_info):
    """
    Create Stub Functions
    :return:
    """
    # log(PATH_INFO, '## Func: createStubFuncs')
    log_mod.set_log('## Func: createStubFuncs', log_mod.Logtype_PFF)

    target_sw_path = dic_project_info['Common_Path']['Project_Root_Path'] + "\\Target_SW"
    # stubs.c file
    f = open(target_sw_path + '\\prost_stubs.c', 'wt')

    # delay_coeff

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
        # log(PATH_INFO, 'Stub: ' + stub[0])
        log_mod.set_log('Stub: ' + stub[0], log_mod.Logtype_INF)

    f.close()
    # stubs.h file
    f = open(target_sw_path + '\\prost_stubs.h', 'wt')
    for stub in stubs:
        f.write(stub[0] + ";\n")

    f.close()
# skc### createStubFuncs_ghs()##########################################################################################

# skc### makeBuildEnviroment_ghs()######################################################################################
def makeBuildEnviroment_ghs(dic_project_info):
    """
    Auto Generation build files (makefile, subdir.mk)
    :return:
    """

    log_mod.set_log('#GHS# Func: makeBuildEnviroment_ghs', log_mod.Logtype_PFF)

    log_mod.set_log('## Func: createMakefile', log_mod.Logtype_PFF)
    target_sw_path = dic_project_info['Common_Path']['Project_Root_Path'] + "\\Target_SW"
    makefile_path = target_sw_path + "\\Debug\\Makefile"

    # makefile
    if not os.path.exists(makefile_path):
        # errorLog(PATH_INFO, 106, 'makefile does not exist')
        log_mod.set_log('makefile does not exist', log_mod.Logtype_ERR)
        return False

    f = open(makefile_path, 'rt')
    new_data = f.read()
    f.close()

    f = open(makefile_path, 'wt')

    # skc### 코어리스트, 메인 코어 구하기
    cores = list(dic_project_info['Compiler']['Core'].keys())
    main_core = ''
    for core, value in dic_project_info['Compiler']['Core'].items():
        if value == 'TRUE':
            main_core = core
            break

    # 1.Project Name
    src_key = "### $$${PROJECT_NAME}$$$"
    new_val = "PROJ = " + dic_project_info['Test_Env']['Test_Component'] + '\n\n'
    new_data = new_data.replace(src_key, new_val)

    # 2.Compiler Path
    new_val = ''
    src_key = "### $$${COMPILER_PATH}$$$"
    new_val = "COMPILER = " + dic_project_info['Compiler']['Compiler_Path']
    new_data = new_data.replace(src_key, new_val)

    # 3.Workspace Path
    new_val = ''
    src_key = "### $$${workspace_loc}$$$"
    new_val = "workspace_loc = " + dic_project_info['Common_Path']['Workspace_Path'] + '\n'

    # 경로 지정
    new_val += 'DEBUG = ' + target_sw_path + '\\Debug\n'  # skc### elf
    new_val += 'TARGET_SW = ' + target_sw_path + '\n\n'  # skc### 이건 그냥 target_sw 경로
    new_data = new_data.replace(src_key, new_val)

    # 4.-D 옵션 추가 (default define)
    new_val = ''
    src_key = "### $$${DEFINE}$$$"

    new_val += 'DIE=' + dic_project_info['Test_Env']['Die'] + '\n'
    new_val += 'SERISE=' + dic_project_info['Test_Env']['Serise'].upper() + '\n'
    new_val += 'DEVICE=' + dic_project_info['Test_Env']['Test_CPU'] + '\n'
    new_val += 'MCU_REV=' + dic_project_info['Test_Env']['MCU_rev'] + '\n'
    new_val += 'USE_PSVP=0 \n'
    new_val += '#######################################################\n'
    new_val += 'DEF += -D$(DIE) \n'
    new_val += 'DEF += -D$(SERISE) \n'
    new_val += 'DEF += -D$(DEVICE) \n'
    new_val += 'DEF += -DCY_MCU_$(MCU_REV) \n'
    new_val += 'DEF += -DCY_USE_PSVP=0 \n'
    new_val += 'DEF += -D_LINK_flash_ \n'
    new_val += 'DEF += -DCY_USE_PSVP=$(USE_PSVP) \n\n'
    new_data = new_data.replace(src_key, new_val)

    # 5.Include Path
    new_val = ''
    src_key = "### $$${INCLUDE_PATH}$$$"

    for index, include_path in dic_project_info['Compiler']['IncludePath_List'].items():
        new_val += '\nINC += -I' + include_path
    new_data = new_data.replace(src_key, new_val)

    # 6.라이브러리 -> -l옵션으로 추가
    new_val = ''
    src_key = "### $$${LIBRARY_OPTION}$$$"

    add_lib_list = list()
    add_lib_list = dic_project_info['Compiler']['Library_List']
    new_val += '\n' + 'MAIN_LIB = '
    for add_lib in add_lib_list:
        new_val += '-l' + add_lib + ' '
    new_val += '\n\n'

    # 기본적인 core 동작에만 필요한 crypto, sdl 라이브러리만 추가 <core_name>_BASIC_LIB에 코어별로 옵션으로 추가
    for core in cores:
        lib_path = target_sw_path + '\\lib\\' + core
        new_val += core + '_BASIC_LIB = -L' + lib_path + ' '
        basic_libs = os.listdir(lib_path)
        for basic_lib in basic_libs:
            new_val += '-l' + basic_lib.replace('lib', '').replace('.a', '') + ' '
        new_val += '\n'
    new_data = new_data.replace(src_key, new_val)

    # 6.컴파일 옵션 + 링커 옵션
    new_val = ''
    src_key = "### $$${COMPILER_OPTION}$$$"
    new_val = dic_project_info['Compiler']['Compiler_Option'] + ' ' + dic_project_info['Compiler']['Linker_Option']
    new_data = new_data.replace(src_key, new_val)

    # 7.링커 스크립트 경로 추가
    new_val = ''
    src_key = "### $$${LD}$$$"
    if dic_project_info['Compiler']['IsExistMainls'] == 'FALSE':
        new_val += 'MEMORY_MAP = $(TARGET_SW)\\linker\\memory_map.ld\n'
        new_val += 'LINKER_DIRECTIVES = $(TARGET_SW)\\linker\\linker_directives.ld\n\n'
    new_data = new_data.replace(src_key, new_val)

    # 8. cpu별 컴파일 옵션, define 추가
    new_val = ''
    core = ''
    src_key = "### $$${CPU}$$$"
    for core in cores:
        if 'cm0plus' == core:
            new_val += 'CPU_cm0plus = -cpu=cortexm0plus -D_CORE_cm0plus_\n'
        elif 'cm4' == core:
            new_val += 'CPU_cm4 = -cpu=cortexm4f -D_CORE_cm4_\n'
    new_data = new_data.replace(src_key, new_val)


    # 스크립트 본문
    # user_XXX_list -> 사용자가 추가한 코드 및 컴파일 후 출력된 obj 파일 경로
    # startup_XXX_list -> template에서 복사한 startup 관련 코드 및 컴파일 후 출력된 obj 파일 경로
    # main_XXX_list -> prost_main.c 코드 및 컴파일 후 출력된 obj 파일 경로
    dir_list = list()

    user_code_list = list()
    user_obj_list = list()

    search_ghs(target_sw_path, len(target_sw_path), user_code_list, dir_list, dic_project_info)

    startup_code_list = os.listdir(target_sw_path + '\\startup')
    startup_obj_list = list()

    main_code_list = os.listdir(target_sw_path + '\\main')
    main_obj_list = list()

    # 9.소스코드 컴파일 후 obj 출력
    new_val = ''
    src_key = "### $$${compile script}$$$"

    new_val += '#startup obj#######################################\n'
    for startup_code in startup_code_list:
        if (os.path.splitext(startup_code)[1] == '.c') or (os.path.splitext(startup_code)[1] == '.arm'):
            startup_obj_list.append('$(TARGET_SW)\\startup\\' + os.path.splitext(startup_code)[0] + '.o ')
            new_val += '$(TARGET_SW)\\startup\\' + os.path.splitext(startup_code)[0] + '.o : $(TARGET_SW)\\startup\\' + startup_code + '\n'
            new_val += '\t$(COMPILER) -c -MD $(DEF) $(INC) $(OPT_GLOBAL) '
            for core in cores:
                if core in startup_code:
                    new_val += '$(CPU_' + core + ') '
                    break
            new_val += '-object_dir=$(TARGET_SW)\\startup -filetype' + os.path.splitext(startup_code)[1] + ' $(TARGET_SW)\\startup\\' + startup_code + ' -o $@\n\n'

    new_val += '#main obj#######################################\n'
    for main_code in main_code_list:
        if (os.path.splitext(main_code)[1] == '.c') or (os.path.splitext(main_code)[1] == '.arm'):
            main_obj_list.append('$(TARGET_SW)\\main\\' + os.path.splitext(main_code)[0] + '.o ')
            new_val += '$(TARGET_SW)\\main\\' + os.path.splitext(main_code)[0] + '.o : $(TARGET_SW)\\main\\' + main_code + '\n'
            new_val += '\t$(COMPILER) -c -MD $(DEF) $(INC) $(OPT_GLOBAL) ' + '$(CPU_' + main_core + ') -object_dir=$(TARGET_SW)\\main -filetype' + os.path.splitext(main_code)[1] + ' $(TARGET_SW)\\main\\' + main_code + ' -o $@\n\n'

    new_val += '#user obj#######################################\n'
    for user_code in user_code_list:
        if (os.path.splitext(user_code)[1] == '.c') or (os.path.splitext(user_code)[1] == '.arm'):
            user_obj_list.append('$(TARGET_SW)\\' + os.path.splitext(user_code)[0] + '.o ')
            new_val += '$(TARGET_SW)\\' + os.path.splitext(user_code)[0] + '.o : $(TARGET_SW)\\' + user_code + '\n'
            new_val += '\t$(COMPILER) -c -MD $(DEF) $(INC) $(OPT_GLOBAL) ' + '$(CPU_' + main_core + ') -object_dir=$(TARGET_SW)\\' + user_code + ' -filetype' + os.path.splitext(user_code)[1] + ' $(TARGET_SW)\\' + user_code + ' -o $@\n\n'

    new_data = new_data.replace(src_key, new_val)

    # 10. elf 생성
    new_val = ''
    src_key = "### $$${make elf}$$$"

    new_val += '#make elf################################################\n'
    for core in cores:
        if core == main_core:
            new_val += '$(DEBUG)\\' + dic_project_info['Test_Env']['Test_Component'] + '.elf : '
        else:
            new_val += '$(DEBUG)\\' + core + '.elf : '

        link_file = ''
        for obj in startup_obj_list:
            if core in obj:
                link_file += obj
        if core == main_core:
            for obj in main_obj_list:
                link_file += obj
            for obj in user_obj_list:
                link_file += obj
        link_file += '$(MEMORY_MAP) $(LINKER_DIRECTIVES)'
        new_val += link_file + '\n'
        new_val += '\t$(COMPILER) -language=c ' + link_file + ' $(DEF) $(INC) $(OPT_GLOBAL) $(CPU_' + core + ') -MD -object_dir=$(DEBUG) $(MAIN_LIB) $(' + core + '_BASIC_LIB) -o $@\n\n'

    new_data = new_data.replace(src_key, new_val)

    # 11. target 정의
    new_val = ''
    src_key = "### $$${all}$$$"
    new_val += '#make target################################################\n'
    new_val += 'all : '
    for obj in (user_obj_list + main_obj_list + startup_obj_list):
        new_val += obj
    for core in cores:
        if core == main_core:
            new_val += '$(DEBUG)\\' + dic_project_info['Test_Env']['Test_Component'] + '.elf '
        else:
            new_val += '$(DEBUG)\\' + core + '.elf '
    new_val += '\n\n'

    new_data = new_data.replace(src_key, new_val)

    f.write(new_data)
    f.close()

    return True
# skc### makeBuildEnviroment_ghs()######################################################################################

# skc### executeGHSCompiler_ghs()######################################################################################
def executeGHSCompiler_ghs(dic_project_info):
    target_sw_path = dic_project_info['Common_Path']['Project_Root_Path'] + "\\Target_SW"
    os.chdir(target_sw_path + "\\Debug")
    proc = subprocess.Popen([target_sw_path + "\\build.bat"], stdout=subprocess.PIPE)

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
# skc### executeGHSCompiler_ghs()######################################################################################