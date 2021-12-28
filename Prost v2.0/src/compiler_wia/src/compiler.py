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

        dic_project_info = pa.object_file_load(r"C:\HyundoKim\Development\2.Mando\Test Dic\C_PROJECT_INFO_DATA_dictionary.txt", "rb")


        #Path Debug Data
        dic_project_info['Common_Path']['Project_Root_Path'] = r"C:\Git\Prost_New\Workspace\Project_Name"
        dic_project_info['Common_Path']['T15_Install_Path'] = r"C:\Git\Prost_New\Prost v2.0_mando"

        #Compiler Debug Data
        dic_project_info['Compiler']['Compiler_Path'] = r'C:\Program Files (x86)\TASKING\TriCore v4.2r2'
        dic_project_info['Compiler'][
            'Compiler_Option'] = r'-C$(TARGET) --lsl-core=vtc -t $(INC) -Wa-H"sfr/reg$(TARGET).def" -Wa-gAHLs --emit-locals=-equ,-symbols -Wa-Ogs -Wa--error-limit=42 -Wc-H"sfr/reg$(TARGET).sfr" --iso=99 --language=-gcc,-volatile,+strings --switch=auto --align=0 --default-near-size=0 --default-a0-size=0 --default-a1-size=0 -O2 --compact-max-size=200 -g --source'
        dic_project_info['Compiler'][
            'HeaderFile'] = r"C:\\Git\\Prost_New\\Workspace\\Project_Name\\temp\\C_startup_regs.txt"
        dic_project_info['Test_Env']['CompilerVersion'] = '4.2'
        # dic_project_info['Compiler']['Runnable_List'] = RUNNABLE_INFO_PAR
        # dic_project_info['Compiler']['Stub_list'] = STUB_LIST_PAR
        dic_project_info['Compiler']['Core'] = {}
        dic_project_info['Compiler']['Core']['core0'] = 'TRUE'
        dic_project_info['Compiler']['Core']['core1'] = 'FALSE'
        dic_project_info['Compiler']['Core']['core2'] = 'FALSE'

        dic_project_info['Compiler']['Runnable_List'][1] = 'ADRV_Model_EmbC_step_IDC()$$100$$core0$$IDC_Main.h'
        dic_project_info['Compiler']['Runnable_List'][2] = 'ADRV_Model_EmbC_step_IDC()$$100$$core0$$Parameter/wTuning.h'
        dic_project_info['Compiler']['Memory_Section'] = {'abs18': '    group (load_addr=mem:mpe:pflash0)\r\n        select \".zdata.*.*\";\r\n\r\n    group (copy, run_addr=mem:mpe:dspr1)\r\n        select \".zdata.*.*\";\r\n\r\n\r\n    group (run_addr=mem:mpe:dspr0)\r\n        select \".zbss.*.*\";\r\n', 'linear' : '    group (load_addr=mem:mpe:pflash0)\r\n        select \".text.*.*\";\r\n\r\n    group (copy, run_addr=mem:mpe:pspr0)\r\n        select \".text.*.*Lib_IDC_Main_BEM*\";\r\n\r\n    group (run_addr=mem:mpe:dspr1)\r\n        select \".bss.*.*\";\r\n\r\n    group (load_addr=mem:mpe:pflash0)\r\n        select \".data.*.*\";\r\n\r\n    group (run_addr=mem:mpe:dspr0)\r\n        select \".data.*.*\";\r\n'}

        dic_project_info['Compiler']['Library_List'] = {'1' : r"C:\Git\Prost_New\Workspace\Project_Name\Target_SW\Library\libControlLogic.a"}
        #dic_project_info['Test_Env']['HeaderFile_Path'] = r"C:\\test1.h"

        #Test Env Debug Data
        dic_project_info['Test_Env']['Test_CPU'] = r"tc29x"
        dic_project_info['Test_Env']['Test_Component'] = "test"
        dic_project_info['Test_Env']['Test_Code_Path'] = r"C:\Git\Prost_New\CustomerCode\Model_Code"
        dic_project_info['Test_Env']['CPU_Clock'] = '20000000'


        #Path
        dic_project_info['Compiler']['IncludePath_List'][2] = r"C:\Git\Prost_New\Workspace\Project_Name\Target_SW"
        dic_project_info['Compiler']['InitFunction_List'][1] = r'WTUN_IDC_vInit()'
        dic_project_info['Compiler']['Linker_Option'] = r'-t "../test.lsl" -Wl-OtxycL -Wl--map-file="${PROJ}.mapxml":XML -Wl-mcrfiklSmNOduQ -Wl--error-limit=42 -g'



    print("Wrong information check below param")
    print("project information : ")
    print(dic_project_info)

    log_mod.G_Log_level = int(dic_project_info['Log']['Log_Level'])
    log_mod.set_log('Start Compiler Module!', log_mod.Logtype_PRG)
    elffile_name = dic_project_info['Common_Path']['Project_Root_Path'] + "\\Target_SW\\Debug\\" + dic_project_info['Test_Env']['Test_Component'] + ".elf"

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
    res=main(True)  #Release
    #res = main(False)
    if res:
        print('Build Success')
    else:
        print('Build Failed')
