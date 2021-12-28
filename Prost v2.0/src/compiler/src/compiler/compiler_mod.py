import os
import shutil
import subprocess
import pickle
from datetime import datetime

supported_cpu_6_2 = ['tc23x', 'tc26xb', 'tc27xd']
supported_cpu_4_3 = ['tc23x', 'tc26x', 'tc27xb']
supported_tasking = ['4.3', '6.2']


# Logging    #################################################################
def cur_date():
    now = datetime.now()
    return '%s-%s-%s' % (now.year, str(now.month).zfill(2), str(now.day).zfill(2))


def cur_time():
    now = datetime.now()
    return '%s:%s:%s.%s' % (str(now.hour).zfill(2), str(now.minute).zfill(2),
                            str(now.second).zfill(2), str(int(now.microsecond) // 1000).zfill(3))


def log(PATH_INFO, msg, error_log=False, build_log=False):
    f = open(PATH_INFO['Log_Path'], 'a')

    if error_log:
        msg = '[' + cur_time() + '][COMP]' + msg

        print('\x1b[1;31m' + msg + '\x1b[1;m', flush=True)
        f.write(msg + '\n')
    elif build_log:
        msg = '[' + cur_time() + '][COMP][010(TSK)]' + msg

        print(msg, flush=True)
        f.write(msg)
    else:
        msg = '[' + cur_time() + '][COMP][000(INF)]' + msg

        print(msg, flush=True)
        f.write(msg + '\n')

    f.close()


def errorLog(PATH_INFO, err_code, msg):
    msg = '[' + str(err_code) + '(ERR)] ' + str(msg)
    log(PATH_INFO, msg, error_log=True)


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
    if not os.path.exists(src):
        errorLog(PATH_INFO, 102, 'Not Exist src folder, can not copied:' + src)
        return
    if not os.path.exists(dst):
        os.makedirs(dst)
        shutil.copystat(src, dst)
    lst = os.listdir(src)
    if ignore:
        excl = ignore(src, lst)
        lst = [x for x in lst if x not in excl]
    for item in lst:
        s = os.path.join(src, item)
        d = os.path.join(dst, item)
        if symlinks and os.path.islink(s):
            if os.path.lexists(d):
                os.remove(d)
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


def removeAllFile(file_path):
    files = os.listdir(file_path)

    for file in files:
        fullfilename = os.path.join(file_path, file)
        if os.path.isdir(fullfilename):
            shutil.rmtree(fullfilename)
        else:
            os.remove(fullfilename)


def targetSWCopy(PATH_INFO, PROJECT_INFO):
    """
    Copy T15 Template -> Target SW to test
    :return: Pass/ Fail
    """
    target_sw_path = PATH_INFO['Workspace_Path'] + "\\" + PATH_INFO['Test_Project'] + "\\Target_SW"
    template_path = PATH_INFO['T15_Install_Path'] + "\\Debug\\Compiler\\Template"
    log(PATH_INFO, 'Copy from Template to Workspace')
    # TargetSW Folder All Clear
    try:
        if not os.path.isdir(target_sw_path): #skc 타켓 소프트웨어 path dir 생성
            os.mkdir(target_sw_path)
        else:
            removeAllFile(target_sw_path) #skc 이미 있으면 해당 dir내 파일 삭제
    except Exception as e:
        errorLog(PATH_INFO, 103, '[TargetSW Copy]' + str(e))
        return False

    # Copy Startup Code
    for ver in supported_tasking: #skc supported_tasking = ['4.3', '6.2'] 무슨버전인지는 모르겟지만 여튼 버전확인
        if ver in PATH_INFO['Compiler_Path']:
            cur_tasking_ver = ver
            break
    else:
        errorLog(PATH_INFO, 109, os.path.basename(PATH_INFO['Compiler_Path']) + ' is not supported')
        return False

#skc 버전별 지원 코어 확인
    if cur_tasking_ver is '4.3':
        if PROJECT_INFO['Test_CPU'] not in supported_cpu_4_3: #skc supported_cpu_4_3 = ['tc23x', 'tc26x', 'tc27xb']
            errorLog(PATH_INFO, 109, PROJECT_INFO['Test_CPU'] + " is not supported")
            return False
    elif cur_tasking_ver is '6.2':
        if PROJECT_INFO['Test_CPU'] not in supported_cpu_6_2: #skc supported_cpu_6_2 = ['tc23x', 'tc26xb', 'tc27xd']
            errorLog(PATH_INFO, 109, PROJECT_INFO['Test_CPU'] + " is not supported")
            return False

    #skc copytree->2번째 인수(path)의 파일을 3번째 인수(path)로 복사
    copyTree(PATH_INFO, template_path + "\\Startup\\TASKING\\" + cur_tasking_ver + "\\" + PROJECT_INFO['Test_CPU'],
             target_sw_path)

    # Copy Template Code
    copyTree(PATH_INFO, template_path + "\\Batch", target_sw_path)
    copyTree(PATH_INFO, template_path + "\\Main", target_sw_path)

    copyTree(PATH_INFO, template_path + "\\Linkerscript", target_sw_path)
    if os.path.isfile(target_sw_path + "\\" + PROJECT_INFO['Test_Component'] + ".lsl"):
        os.remove(target_sw_path + "\\" + PROJECT_INFO['Test_Component'] + ".lsl")
    os.rename(target_sw_path + "\\linker_script.lsl", target_sw_path + "\\" + PROJECT_INFO['Test_Component'] + ".lsl")
    copyTree(PATH_INFO, template_path + "\\Makefile", target_sw_path + "\\Debug")

    # Test Code Copy
    copyTree(PATH_INFO, PATH_INFO['Testcode_Path'], target_sw_path)
    return True
#skc 말 그대로 프로젝트 디렉토리(main gui에서 입력받음)에서 workspace 디렉토리로 폴더, 파일만 복사해옴


#####################################################################################


# modifyTargetSW    #################################################################
def createMainFunc(PATH_INFO, PROJECT_INFO, RUNNABLE_INFO):
    """
    Create Main Function
    :return:
    """
    target_sw_path = PATH_INFO['Workspace_Path'] + "\\" + PATH_INFO['Test_Project'] + "\\Target_SW"
    # main.c
    f = open(target_sw_path + '\\main.c', 'rt') #skc rt->read text
    new_data = f.read()
    f.close()

    f = open(target_sw_path + '\\main.c', 'wt') #skc wt->write text

    # 1.Project Name
    src_key = "$$${HEADERS}$$$"
    new_vals = PROJECT_INFO['Runnable_Header']
    new_vals = new_vals.split('$$')
    headers = ""
    for new_val in new_vals:
        headers += '#include \"' + new_val + '\"\n'

    new_data = new_data.replace(src_key, headers) #skc src_key->include header로 수정

    # 2.Runnable Flags
    src_key = "$$${RUNNABLE_FLAGS}$$$" #?skc 특정함수 실행 여부 저장하는 flag list
    new_vals = 'volatile char __T15_RUNNABLE_FLAGS[' + str(len(RUNNABLE_INFO)) + '];'
    new_data = new_data.replace(src_key, new_vals)

    # 3.Runnable Mapping
    src_key = "$$${RUNNABLES}$$$"
    runnables = list(RUNNABLE_INFO.values())

    new_vals = ''
    i = 0
    for runnable in runnables:
        runnable = runnable.split('$$') #?skc runnable[0], runnable[1] 뭐지
        new_vals += '    ' * 2 + 'if(loop_cnt % ' + runnable[1] + ' == 0) \n'
        new_vals += '    ' * 2 + '{\n'
        new_vals += '    ' * 3 + '__T15_RUNNABLE_FLAGS[' + str(i) + '] = 1;\n'
        new_vals += '    ' * 3 + runnable[0] + '; \n'
        new_vals += '    ' * 3 + '__T15_RUNNABLE_FLAGS[' + str(i) + '] = 0;\n'
        new_vals += '    ' * 2 + '}\n\n'
        i = i + 1

    new_data = new_data.replace(src_key, new_vals)
    f.write(new_data)
    f.close()


def modifyStartupHeader(PATH_INFO, PROJECT_INFO):
    """
    cstart.h -> Modify
    :return:
    """
    target_sw_path = PATH_INFO['Workspace_Path'] + "\\" + PATH_INFO['Test_Project'] + "\\Target_SW"
    f = open(target_sw_path + '\\cstart.h', 'rt')
    new_data = f.read()
    f.close()

    f = open(target_sw_path + '\\cstart.h', 'wt')

    # 1.Project Name
    src_key = "$$${FOSC}$$$"
    new_val = PROJECT_INFO['Cpu_Clock']
    new_data = new_data.replace(src_key, new_val)
    f.write(new_data)
    f.close()


def modifyLinkerScript(PATH_INFO, PROJECT_INFO, RUNNABLE_INFO):
    """
    Runnable Code -> RAM or ROM Mapping
    :return:
    """
    target_sw_path = PATH_INFO['Workspace_Path'] + "\\" + PATH_INFO['Test_Project'] + "\\Target_SW"
    f = open(target_sw_path + "\\" + PROJECT_INFO['Test_Component'] + ".lsl", 'a')
    f.write('\n\nsection_layout mpe:vtc:linear\n')
    f.write('{\n')

    runnables = list(RUNNABLE_INFO.values())

    new_vals = ''
    i = 0
    for runnable in runnables:
        runnable = runnable.split('$$')
        if 'pspr' in runnable[3] or 'dspr' in runnable[3]:
            new_vals += '    ' + 'group (copy, run_addr=mem:mpe:' + runnable[3] + ')\n'
        else:
            new_vals += '    ' + 'group (run_addr=mem:mpe:' + runnable[3] + ')\n'
        runnable_name = runnable[0].split('(')
        new_vals += '    ' * 2 + 'select ".text.*.' + runnable_name[0] + '";\n\n'

    f.write(new_vals)
    f.write('}\n')


def createStubFuncs(PATH_INFO, STUB_LIST):
    """

    :return:
    """
    target_sw_path = PATH_INFO['Workspace_Path'] + "\\" + PATH_INFO['Test_Project'] + "\\Target_SW"
    # stubs.c file
    f = open(target_sw_path + '\\stubs.c', 'wt')

    f.write("void delay(int us)\n")
    f.write("{\n")
    f.write("    volatile int i;\n")
    f.write("    for(i=0; i<us*15; i++);\n")
    f.write("}\n")
    f.write("\n\n")

    stubs = list(STUB_LIST.values())

    for stub in stubs:
        stub = stub.split('$$')
        f.write(stub[0] + "\n")
        f.write("{\n")
        f.write("    delay(" + stub[1] + ");\n")
        if stub[2] != 'no return':
            f.write("    return " + stub[2] + ";\n")
        f.write("}\n")

    f.close()
    # stubs.h file
    f = open(target_sw_path + '\\stubs.h', 'wt')
    for stub in stubs:
        f.write(stub[0] + ";\n")

    f.close()


def modifyTargetSW(PATH_INFO, PROJECT_INFO, RUNNABLE_INFO, STUB_LIST):
    log(PATH_INFO, 'Modify Target_SW Main/Startup code')
    """
    Modify Target SW from Template
    :return:
    """
    try:
        createMainFunc(PATH_INFO, PROJECT_INFO, RUNNABLE_INFO)
        modifyStartupHeader(PATH_INFO, PROJECT_INFO)
        modifyLinkerScript(PATH_INFO, PROJECT_INFO, RUNNABLE_INFO)
        createStubFuncs(PATH_INFO, STUB_LIST)
    except Exception as e:
        errorLog(PATH_INFO, 105, '[Modify Target_SW]' + str(e))
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


def createMakefile(PATH_INFO, PROJECT_INFO, BUILD_OPTION, dirlist):
    """
    Auto Generation makefile
    :param dirlist: directory list
    :return:
    """
    target_sw_path = PATH_INFO['Workspace_Path'] + "\\" + PATH_INFO['Test_Project'] + "\\Target_SW"
    makefile_path = target_sw_path + "\\Debug\\makefile"

    # makefile
    if not os.path.exists(makefile_path):
        errorLog(PATH_INFO, 106, 'makefile does not exist')
        return False

    f = open(makefile_path, 'rt')
    new_data = f.read()
    f.close()

    f = open(makefile_path, 'wt')
    # 1.Project Name
    src_key = "### $$${PROJECT_NAME}$$$"
    new_val = "PROJ = " + PROJECT_INFO['Test_Component']
    new_data = new_data.replace(src_key, new_val)

    # 1.Compiler Path
    src_key = "### $$${COMPILER_PATH}$$$"
    new_val = "COMPILER = " + PATH_INFO['Compiler_Path']
    new_data = new_data.replace(src_key, new_val)

    # 2.Include Path
    src_key = "### $$${INCLUDE_PATH}$$$"
    new_val = 'INC += -I\"' + target_sw_path + '\"'
    for dir in dirlist:
        new_val += '\nINC += -I\"' + target_sw_path + '\\' + dir + '\"'
    new_data = new_data.replace(src_key, new_val)

    # 3.Target Info
    src_key = "### $$${TARGET_INFO}$$$"
    new_val = "TARGET = " + PROJECT_INFO['Test_CPU']
    new_data = new_data.replace(src_key, new_val)

    # 4.Build Option
    src_key = "### $$${COMPILER_OPTION}$$$"
    new_val = "COMPILE_OPT = " + BUILD_OPTION['Compiler_Option']
    new_data = new_data.replace(src_key, new_val)

    src_key = "### $$${LINKER_OPTION}$$$"
    new_val = "LINK_OPT = " + BUILD_OPTION['Linker_option']
    new_data = new_data.replace(src_key, new_val)

    f.write(new_data)
    f.close()

    return True


def createSubdirMk(PATH_INFO, dirlist, srclist):
    """
    Auto Generation subdir.mk
    :param dirlist: directory list
    :param srclist: source code( *.c) list
    :return:
    """
    target_sw_path = PATH_INFO['Workspace_Path'] + "\\" + PATH_INFO['Test_Project'] + "\\Target_SW"
    subdir_path = target_sw_path + "\\Debug\\subdir.mk"

    # makefile
    if not os.path.exists(subdir_path):
        errorLog(PATH_INFO, 107, 'subdir.mk does not exist')
        return False

    # create sub directory in Debug folder
    for dir in dirlist:
        os.mkdir(target_sw_path + "\\Debug\\" + dir)

    # subdir.mk
    f = open(subdir_path, 'rt')
    new_data = f.read()
    f.close()

    f = open(subdir_path, 'wt')
    # 2.Inculde Path
    src_key = "### $$${BUILDFILE_LIST}$$$"
    new_val = ""
    for src in srclist:
        fname, ext = os.path.splitext(src)
        if ext == '.c':
            new_val += 'C_FILES += \"..\\' + fname + '.c\"\n'
            new_val += 'OBJ_FILES += \"' + fname + '.o\"\n'
            new_val += '\"' + fname + '.o\" : \"..\\' + fname + '.c\"\n'
            new_val += '\t@echo Compiling ${<F}\n'
            new_val += '\t@$(COMPILER)\\ctc\\bin\\cctc -o \"' + fname + '.o\" \"..\\' + fname + \
                       '.c\" $(COMPILE_OPT) -c -Wc--make-target=\"' + fname + '.o\"\n'
            new_val += '\n\n'
    new_data = new_data.replace(src_key, new_val)
    f.write(new_data)
    f.close()

    return True


def makeBuildEnviroment(PATH_INFO, PROJECT_INFO, BUILD_OPTION):
    """
    Auto Generation build files (makefile, subdir.mk)
    :return:
    """
    log(PATH_INFO, 'Make Build Environment')
    target_sw_path = PATH_INFO['Workspace_Path'] + "\\" + PATH_INFO['Test_Project'] + "\\Target_SW"

    src_list = []
    dir_list = []
    search(target_sw_path, len(target_sw_path), src_list, dir_list)

    if not createMakefile(PATH_INFO, PROJECT_INFO, BUILD_OPTION, dir_list):
        return False
    if not createSubdirMk(PATH_INFO, dir_list, src_list):
        return False

    return True


#####################################################################################

def executeTaskingCompiler(PATH_INFO):
    """
    Execute Tasking Compiler (Build Start)
    :return:
    """
    log(PATH_INFO, 'Start Tasking Compile')
    target_sw_path = PATH_INFO['Workspace_Path'] + "\\" + PATH_INFO['Test_Project'] + "\\Target_SW"

    if not os.path.exists(PATH_INFO['Compiler_Path'] + "\\ctc\\bin"):
        errorLog(PATH_INFO, 108, "Compiler Path Error")
        return None

    os.chdir(target_sw_path + "\\Debug")

    proc = subprocess.Popen(
        [PATH_INFO['Compiler_Path'] + "\\ctc\\bin\\amk", '-j8', 'all', '-a'], stdout=subprocess.PIPE
    )

    last_s = ''
    log(PATH_INFO, '=============================================')
    while proc.poll() is None:
        s = proc.stdout.readline().decode()
        s = s[:-1]
        if s.encode() != b'':
            last_s = s
            log(PATH_INFO, s, build_log=True)
    log(PATH_INFO, '=============================================')
    return last_s


#####################################################################################


def pickleLoad(pickle_path):
    try:
        with open(pickle_path, 'rb') as f: #skc 'rb' -> read byte / f -> open() func return object
            data = pickle.load(f)
    except Exception as e:
        print('[Pickle Load]' + str(e))
        # errorLog(PATH_INFO, 101, '[Pickle Load]' + str(e))
    else:
        return data
