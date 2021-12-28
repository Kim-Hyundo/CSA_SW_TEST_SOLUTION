# Release Note
# Release Version :
# Release Date :
# usage : call main function from C# program
# call parameter :
#


import argparse
import compiler_mod as mod
import log_mod as log_mod
import os

import pickle_api as pa

import compiler_mod_ghs as mod_ghs

# MAIN    ###########################################################################
# call example
# In C#, Call this Python API
def main(test=True):
    if test:
        res = False
        parser = argparse.ArgumentParser()

        parser.add_argument('PROJECT_INFO', type=str)

        args = parser.parse_args()

        # Project information
        dic_project_info = mod.pickleLoad(args.PROJECT_INFO)

        print("project information : ")
        print(dic_project_info)

        if dic_project_info is None:
            print("Wrong information check below param")
            return res
        #res=True
    else:
        ##### for Test #######
        res = False

        #dic_project_info = pa.object_file_load("C:\Prost_v2.0\Workspace\MANDO_FailSafe_Integration\Temp\C_PROJECT_INFO_DATA_dictionary.txt", "rb")
        dic_project_info = pa.object_file_load(r"C:\Users\GiCheol.Shin\Desktop\test\test\Temp\C_PROJECT_INFO_DATA_dictionary.txt", "rb")


        # skc### 가라데이터들
        dic_project_info['Test_Env']['Test_Component'] = 'Demo'
        #dic_project_info['Compiler']['Compiler Type'] = 'GHS'
        dic_project_info['Test_Env']['Test_compilerType'] = 'GHS'
        dic_project_info['Compiler']['IsExistMainls'] = 'FALSE'
        dic_project_info['Test_Env']['Test_CPU'] = 'CYT2B75CA(rev_d)'
        dic_project_info['Test_Env']['CompilerVersion'] = '2021.1.4'
        dic_project_info['Compiler']['Core'] = {'cm0plus': 'FALSE', 'cm4': 'TRUE'}
        dic_project_info['Compiler']['Compiler_Path'] = r"C:\ghs\comp_202114"
        dic_project_info['Common_Path']['Workspace_Path'] = r"C:\Users\GiCheol.Shin\Desktop\test"
        dic_project_info['Common_Path']['Project_Root_Path'] = r"C:\Users\GiCheol.Shin\Desktop\test\make_main"
        dic_project_info['Common_Path']['T15_Install_Path'] = r"C:\Prost_v2.0\Prost v2.0"
        dic_project_info['Compiler']['Runnable_List'].clear()
        dic_project_info['Compiler']['Runnable_List'][1] = 'Demo_Test()$$1$$cm4$$Demo.h'
        dic_project_info['Compiler']['Runnable_List'][2] = 'plus()$$1$$cm4$$plus.h'
        dic_project_info['Compiler']['Runnable_List'][3] = 'minus()$$1$$cm4$$minus.h'
        dic_project_info['Compiler']['IncludePath_List'].clear()
        dic_project_info['Compiler']['IncludePath_List'][1] = r"$(workspace_loc)\make_main\Target_SW"
        # dic_project_info['Compiler']['IncludePath_List'][2] = r"$(workspace_loc)\make_main\Target_SW\common"
        # dic_project_info['Compiler']['IncludePath_List'][3] = r"$(workspace_loc)\make_main\Target_SW\common\hdr"
        # dic_project_info['Compiler']['IncludePath_List'][4] = r"$(workspace_loc)\make_main\Target_SW\common\hdr\cmsis"
        # dic_project_info['Compiler']['IncludePath_List'][5] = r"$(workspace_loc)\make_main\Target_SW\common\hdr\cmsis\include"
        # dic_project_info['Compiler']['IncludePath_List'][6] = r"$(workspace_loc)\make_main\Target_SW\common\src"
        # dic_project_info['Compiler']['IncludePath_List'][7] = r"$(workspace_loc)\make_main\Target_SW\common\src\drivers"
        # dic_project_info['Compiler']['IncludePath_List'][8] = r"$(workspace_loc)\make_main\Target_SW\common\src\startup"
        # dic_project_info['Compiler']['IncludePath_List'][9] = r"$(workspace_loc)\make_main\Target_SW\CYT2B7+rev_d"
        # dic_project_info['Compiler']['IncludePath_List'][10] = r"$(workspace_loc)\make_main\Target_SW\CYT2B7+rev_d\hdr"
        # dic_project_info['Compiler']['IncludePath_List'][11] = r"$(workspace_loc)\make_main\Target_SW\CYT2B7+rev_d\hdr\ip"
        # dic_project_info['Compiler']['IncludePath_List'][12] = r"$(workspace_loc)\make_main\Target_SW\CYT2B7+rev_d\hdr\mcureg"
        # dic_project_info['Compiler']['IncludePath_List'][13] = r"$(workspace_loc)\make_main\Target_SW\CYT2B7+rev_d\src\drivers"
        # dic_project_info['Compiler']['IncludePath_List'][14] = r"$(workspace_loc)\make_main\Target_SW\CYT2B7+rev_d\src\interrupts"
        # dic_project_info['Compiler']['IncludePath_List'][15] = r"$(workspace_loc)\make_main\Target_SW\CYT2B7+rev_d\src\system"
        dic_project_info['Compiler']['IncludePath_List'][16] = r"$(workspace_loc)\make_main\Target_SW\Demo"
        dic_project_info['Compiler']['IncludePath_List'][17] = r"$(workspace_loc)\make_main\Target_SW\Demo\minus"
        # dic_project_info['Compiler']['Compiler_Option'] = ''
        # dic_project_info['Compiler']['Compiler_Option'] += 'OPT_GLOBAL += -G \n'
        # dic_project_info['Compiler']['Compiler_Option'] += 'OPT_GLOBAL += -dual_debug \n'
        # dic_project_info['Compiler']['Compiler_Option'] += 'OPT_GLOBAL += -C99 \n'
        # dic_project_info['Compiler']['Compiler_Option'] += 'OPT_GLOBAL += -align4 \n'
        # dic_project_info['Compiler']['Compiler_Option'] += 'OPT_GLOBAL += --short_enum \n'
        # dic_project_info['Compiler']['Compiler_Option'] += 'OPT_GLOBAL += --no_commons \n'
        # dic_project_info['Compiler']['Compiler_Option'] += 'OPT_GLOBAL += --no_alternative_tokens \n'
        # dic_project_info['Compiler']['Compiler_Option'] += 'OPT_GLOBAL += -asm3g \n'
        # dic_project_info['Compiler']['Compiler_Option'] += 'OPT_GLOBAL += -preprocess_assembly_files \n'
        # dic_project_info['Compiler']['Compiler_Option'] += 'OPT_GLOBAL += --preprocess_linker_directive_full \n'
        # dic_project_info['Compiler']['Compiler_Option'] += 'OPT_GLOBAL += -nostartfiles \n'
        # dic_project_info['Compiler']['Compiler_Option'] += 'OPT_GLOBAL += -globalcheck=normal \n'
        # dic_project_info['Compiler']['Compiler_Option'] += 'OPT_GLOBAL += -globalcheck_qualifiers \n'
        # dic_project_info['Compiler']['Compiler_Option'] += 'OPT_GLOBAL += --prototype_errors \n'
        # dic_project_info['Compiler']['Compiler_Option'] += 'OPT_GLOBAL += -Wformat \n'
        # dic_project_info['Compiler']['Compiler_Option'] += 'OPT_GLOBAL += -Wimplicit-int \n'
        # dic_project_info['Compiler']['Compiler_Option'] += 'OPT_GLOBAL += -Wshadow \n'
        # dic_project_info['Compiler']['Compiler_Option'] += 'OPT_GLOBAL += -Wtrigraphs \n'
        # dic_project_info['Compiler']['Compiler_Option'] += 'OPT_GLOBAL += -Wundef \n'
        # dic_project_info['Compiler']['Compiler_Option'] += 'OPT_GLOBAL += -reject_duplicates \n'
        # dic_project_info['Compiler']['Compiler_Option'] += 'OPT_GLOBAL += -object_dir=objs \n'
        # dic_project_info['Compiler']['Compiler_Option'] += 'OPT_GLOBAL +=:sourceDir=. \n'
        # dic_project_info['Compiler']['Compiler_Option'] += 'OPT_GLOBAL += --no_wrap_diagnostics \n'
        # dic_project_info['Test_Env']['CPU_Clock'] = '240000'
        # dic_project_info['Compiler']['Memory_Section'] = {'abs18': '\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n', 'linear': '\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n'}
        # dic_project_info['Compiler']['Delay_Coeff'] = '25'
        # dic_project_info['Compiler']['Stub_List'] = []
        # dic_project_info['Compiler']['Register_List'] = []
        # dic_project_info['Compiler']['Linker_Option'] = []
        # dic_project_info['Compiler']['Library_List'] = []

        # skc### 실제 들어가야하는 로직들
        #if 'GHS' == dic_project_info['Compiler']['Compiler Type']:
        # if 'GHS' == dic_project_info['Test_Env']['Test_compilerType']:
        #
        #     # 시리즈 별 define을 위한 dictionary 추가
        #     # Die에 보드 이름이 들어가 있는데 실제로 보드와 관련된 bsp들이 들어가는건 아니고 그야말로 그냥 define용임 이거 define 안하면 컴파일 에러남
        #     if 'CYT2B7' in dic_project_info['Test_Env']['Test_CPU']:
        #         dic_project_info['Test_Env']['Serise'] = 'CYT2B7'
        #         dic_project_info['Test_Env']['Die'] = 'tviibe1m'
        #     elif 'CYT2B9' in dic_project_info['Test_Env']['Test_CPU']:
        #         dic_project_info['Test_Env']['Serise'] = 'CYT2B9'
        #         dic_project_info['Test_Env']['Die'] = 'tviibe2m'
        #     elif 'CYT2BL' in dic_project_info['Test_Env']['Test_CPU']:
        #         dic_project_info['Test_Env']['Serise'] = 'CYT2BL'
        #         dic_project_info['Test_Env']['Die'] = 'tviibe4m'
        #     elif 'CYT2B6' in dic_project_info['Test_Env']['Test_CPU']:
        #         dic_project_info['Test_Env']['Serise'] = 'CYT2B6'
        #         dic_project_info['Test_Env']['Die'] = 'tviibe512k'
        #     elif 'CYT4BB' in dic_project_info['Test_Env']['Test_CPU']:
        #         dic_project_info['Test_Env']['Serise'] = 'CYT2BB'
        #         dic_project_info['Test_Env']['Die'] = 'tviibh4m'
        #     elif 'CYT4BF' in dic_project_info['Test_Env']['Test_CPU']:
        #         dic_project_info['Test_Env']['Serise'] = 'CYT2BF'
        #         dic_project_info['Test_Env']['Die'] = 'tviibh8m'
        #     elif 'CYT3DL' in dic_project_info['Test_Env']['Test_CPU']:
        #         dic_project_info['Test_Env']['Serise'] = 'CYT3DL'
        #         dic_project_info['Test_Env']['Die'] = 'tviic2d4m'
        #     elif 'CYT4DN' in dic_project_info['Test_Env']['Test_CPU']:
        #         dic_project_info['Test_Env']['Serise'] = 'CYT4DN'
        #         dic_project_info['Test_Env']['Die'] = 'tviic2d6m'
        #     elif 'CYT4EN' in dic_project_info['Test_Env']['Test_CPU']:
        #         dic_project_info['Test_Env']['Serise'] = 'CYT4EN'
        #         dic_project_info['Test_Env']['Die'] = 'tviic2d6mddr'
        #     elif 'CYT2CL' in dic_project_info['Test_Env']['Test_CPU']:
        #         dic_project_info['Test_Env']['Serise'] = 'CYT2CL'
        #         dic_project_info['Test_Env']['Die'] = 'tviice4m'
        #
        #     if 'rev_a' in dic_project_info['Test_Env']['Test_CPU']:
        #         dic_project_info['Test_Env']['MCU_rev'] = 'rev_a'
        #     elif 'rev_b' in dic_project_info['Test_Env']['Test_CPU']:
        #         dic_project_info['Test_Env']['MCU_rev'] = 'rev_b'
        #     elif 'rev_c' in dic_project_info['Test_Env']['Test_CPU']:
        #         dic_project_info['Test_Env']['MCU_rev'] = 'rev_c'
        #     elif 'rev_d' in dic_project_info['Test_Env']['Test_CPU']:
        #         dic_project_info['Test_Env']['MCU_rev'] = 'rev_d'
        #
        #     # mcu 이름 끝에 알파벳 하나는 S아니면 E인데 그냥 동작온도범위라서 신경안써도 될듯 칩 스펙, 패키지 다 똑같음
        #     dic_project_info['Test_Env']['Test_CPU'] = dic_project_info['Test_Env']['Test_CPU'].split('(')[0] + 'S'
        # # skc###

        # skc###
        # #Path Debug Data
        # dic_project_info['Common_Path']['Project_Root_Path'] = r"C:\HyundoKim\Development\2.Mando_New\WorkSpace\MANDO_FailSafe_Integration"
        # dic_project_info['Common_Path']['T15_Install_Path'] = r"C:\HyundoKim\Development\2.Mando_New\Prost v2.0"
        #
        # #Compiler Debug Data
        # dic_project_info['Compiler']['Compiler_Path'] = r'C:\ghs'
        # dic_project_info['Compiler'][
        #     'Compiler_Option'] = r'-C$(TARGET) --lsl-core=vtc -t $(INC) -Wa-H"sfr/reg$(TARGET).def" -Wa-gAHLs --emit-locals=-equ,-symbols -Wa-Ogs -Wa--error-limit=42 -Wc-H"sfr/reg$(TARGET).sfr" --iso=99 --language=-gcc,-volatile,+strings --switch=auto --align=0 --default-near-size=0 --default-a0-size=0 --default-a1-size=0 -O2 --compact-max-size=200 -g --source'
        # dic_project_info['Compiler'][
        #     'HeaderFile'] = r"C:\\Git\\Prost_New\\Workspace\\Project_Name\\temp\\C_startup_regs.txt"
        # dic_project_info['Test_Env']['CompilerVersion'] = '6.2'
        # # dic_project_info['Compiler']['Runnable_List'] = RUNNABLE_INFO_PAR
        # # dic_project_info['Compiler']['Stub_list'] = STUB_LIST_PAR
        # dic_project_info['Compiler']['Core'] = {}
        #
        # dic_project_info['Compiler']['Core']['core0'] = 'TRUE'
        # dic_project_info['Compiler']['Core']['core1'] = 'FALSE'
        # dic_project_info['Compiler']['Core']['core2'] = 'FALSE'
        # dic_project_info['Compiler']['Runnable_List'][1] = 'ADRV_Model_EmbC_step_IDC(int a, int b)$$100$$core0$$IDC_Main.h'
        # dic_project_info['Compiler']['Runnable_List'][2] = 'ADRV_Model_EmbC_step_IDC(int c, float d)$$100$$core0$$Parameter/wTuning.h'
        # dic_project_info['Compiler']['Memory_Section'] = {'abs18': '    group (load_addr=mem:mpe:pflash0)\r\n        select \".zdata.*.*\";\r\n\r\n    group (copy, run_addr=mem:mpe:dspr1)\r\n        select \".zdata.*.*\";\r\n\r\n\r\n    group (run_addr=mem:mpe:dspr0)\r\n        select \".zbss.*.*\";\r\n', 'linear' : '    group (load_addr=mem:mpe:pflash0)\r\n        select \".text.*.*\";\r\n\r\n    group (copy, run_addr=mem:mpe:pspr0)\r\n        select \".text.*.*Lib_IDC_Main_BEM*\";\r\n\r\n    group (run_addr=mem:mpe:dspr1)\r\n        select \".bss.*.*\";\r\n\r\n    group (load_addr=mem:mpe:pflash0)\r\n        select \".data.*.*\";\r\n\r\n    group (run_addr=mem:mpe:dspr0)\r\n        select \".data.*.*\";\r\n'}
        #
        # dic_project_info['Compiler']['Library_List'] = {'1' : r"C:\Git\Prost_New\Workspace\Project_Name\Target_SW\Library\libControlLogic.a"}
        # #dic_project_info['Test_Env']['HeaderFile_Path'] = r"C:\\test1.h"
        #
        # #Test Env Debug Data
        # dic_project_info['Test_Env']['Test_CPU'] = r"cyt4bb"
        # dic_project_info['Test_Env']['Test_Component'] = "MANDO_FailSafe_Integration"
        # dic_project_info['Test_Env']['Test_Code_Path'] = r"C:\Git\Prost_New\CustomerCode\Model_Code"
        # dic_project_info['Test_Env']['CPU_Clock'] = '20000000'
        #
        #
        # #Path
        # dic_project_info['Compiler']['IncludePath_List'][2] = r"C:\Git\Prost_New\Workspace\Project_Name\Target_SW"
        # dic_project_info['Compiler']['InitFunction_List'][1] = r'WTUN_IDC_vInit()'
        # dic_project_info['Compiler']['Linker_Option'] = r'-t "../test.lsl" -Wl-OtxycL -Wl--map-file="${PROJ}.mapxml":XML -Wl-mcrfiklSmNOduQ -Wl--error-limit=42 -g'
        # skc###


    print("Wrong information check below param")
    print("project information : ")
    print(dic_project_info)

    # skc### 실제 들어가야하는 로직들
    # if 'GHS' == dic_project_info['Compiler']['Compiler Type']:
    if 'GHS' == dic_project_info['Test_Env']['Test_CompilerType']:

        # 시리즈 별 define을 위한 dictionary 추가
        # Die에 보드 이름이 들어가 있는데 실제로 보드와 관련된 bsp들이 들어가는건 아니고 그야말로 그냥 define용임 이거 define 안하면 컴파일 에러남
        if 'CYT2B7' in dic_project_info['Test_Env']['Test_CPU']:
            dic_project_info['Test_Env']['Serise'] = 'CYT2B7'
            dic_project_info['Test_Env']['Die'] = 'tviibe1m'
        elif 'CYT2B9' in dic_project_info['Test_Env']['Test_CPU']:
            dic_project_info['Test_Env']['Serise'] = 'CYT2B9'
            dic_project_info['Test_Env']['Die'] = 'tviibe2m'
        elif 'CYT2BL' in dic_project_info['Test_Env']['Test_CPU']:
            dic_project_info['Test_Env']['Serise'] = 'CYT2BL'
            dic_project_info['Test_Env']['Die'] = 'tviibe4m'
        elif 'CYT2B6' in dic_project_info['Test_Env']['Test_CPU']:
            dic_project_info['Test_Env']['Serise'] = 'CYT2B6'
            dic_project_info['Test_Env']['Die'] = 'tviibe512k'
        elif 'CYT4BB' in dic_project_info['Test_Env']['Test_CPU']:
            dic_project_info['Test_Env']['Serise'] = 'CYT2BB'
            dic_project_info['Test_Env']['Die'] = 'tviibh4m'
        elif 'CYT4BF' in dic_project_info['Test_Env']['Test_CPU']:
            dic_project_info['Test_Env']['Serise'] = 'CYT2BF'
            dic_project_info['Test_Env']['Die'] = 'tviibh8m'
        elif 'CYT3DL' in dic_project_info['Test_Env']['Test_CPU']:
            dic_project_info['Test_Env']['Serise'] = 'CYT3DL'
            dic_project_info['Test_Env']['Die'] = 'tviic2d4m'
        elif 'CYT4DN' in dic_project_info['Test_Env']['Test_CPU']:
            dic_project_info['Test_Env']['Serise'] = 'CYT4DN'
            dic_project_info['Test_Env']['Die'] = 'tviic2d6m'
        elif 'CYT4EN' in dic_project_info['Test_Env']['Test_CPU']:
            dic_project_info['Test_Env']['Serise'] = 'CYT4EN'
            dic_project_info['Test_Env']['Die'] = 'tviic2d6mddr'
        elif 'CYT2CL' in dic_project_info['Test_Env']['Test_CPU']:
            dic_project_info['Test_Env']['Serise'] = 'CYT2CL'
            dic_project_info['Test_Env']['Die'] = 'tviice4m'

        if 'rev_a' in dic_project_info['Test_Env']['Test_CPU']:
            dic_project_info['Test_Env']['MCU_rev'] = 'rev_a'
        elif 'rev_b' in dic_project_info['Test_Env']['Test_CPU']:
            dic_project_info['Test_Env']['MCU_rev'] = 'rev_b'
        elif 'rev_c' in dic_project_info['Test_Env']['Test_CPU']:
            dic_project_info['Test_Env']['MCU_rev'] = 'rev_c'
        elif 'rev_d' in dic_project_info['Test_Env']['Test_CPU']:
            dic_project_info['Test_Env']['MCU_rev'] = 'rev_d'

        # mcu 이름 끝에 알파벳 하나는 S아니면 E인데 그냥 동작온도범위라서 신경안써도 될듯 칩 스펙, 패키지 다 똑같음
        dic_project_info['Test_Env']['Test_CPU'] = dic_project_info['Test_Env']['Test_CPU'].split('(')[0] + 'S'
    # skc###

    log_mod.G_Log_level = int(dic_project_info['Log']['Log_Level'])
    log_mod.set_log('Start Compiler Module!', log_mod.Logtype_PRG)
    elffile_name = dic_project_info['Common_Path']['Project_Root_Path'] + "\\Target_SW\\Debug\\" + dic_project_info['Test_Env']['Test_Component'] + ".elf"

    # skc### GHS
    #if 'GHS' == dic_project_info['Compiler']['Compiler Type']:
    if 'GHS' == dic_project_info['Test_Env']['Test_CompilerType']:
        if mod_ghs.targetSWCopy_ghs(dic_project_info):
            if mod_ghs.modifyTargetSW_ghs(dic_project_info):
                if mod_ghs.makeBuildEnviroment_ghs(dic_project_info):
                    last_log = mod_ghs.executeGHSCompiler_ghs(dic_project_info)
                    if os.path.isfile(elffile_name):
                        res = True
    else:
        if mod.targetSWCopy(dic_project_info):
            if mod.modifyTargetSW(dic_project_info):
                if mod.makeBuildEnviroment(dic_project_info):
                    last_log = mod.executeTaskingCompiler(dic_project_info)
                    if os.path.isfile(elffile_name):
                        res = True

                #if 'Linking to ' in last_log:
                #    res = True

    return res

if __name__ == '__main__':
    res = main(True)  #Release
    #res = main(False)
    if res:
        print('Build Success')
    else:
        print('Build Failed')
