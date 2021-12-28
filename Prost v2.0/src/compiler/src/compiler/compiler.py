import argparse
import compiler_mod as mod

# MAIN    ###########################################################################
# call example
# In C#, Call this Python API


def main():
    parser = argparse.ArgumentParser()

    parser.add_argument('PATH_INFO', type=str) #skc 테스트 소스코드 path
    parser.add_argument('PROJECT_INFO', type=str) #skc 테스트 프로젝트 path
    parser.add_argument('BUILD_OPTION', type=str)
    parser.add_argument('STUB_LIST', type=str)
    parser.add_argument('RUNNABLE_INFO', type=str)

    args = parser.parse_args() #skc parser 인자 파싱 및 추가한 argument들을 객체로 반환함

    #skc pickleload(~) ~path의 파일 open후 return
    #skc 밑은 parse_args()를 통해 반환된 객체들에 pickeload함수를 통해 각 객체에 해당하는 parameter 값들을 저장함
    # Path information -> Compiler\Temp
    PATH_INFO_PAR = mod.pickleLoad(args.PATH_INFO)
    PROJECT_INFO_PAR = mod.pickleLoad(args.PROJECT_INFO)

    # Workspace\Project\Temp
    BUILD_OPTION_PAR = mod.pickleLoad(args.BUILD_OPTION)
    STUB_LIST_PAR = mod.pickleLoad(args.STUB_LIST)
    RUNNABLE_INFO_PAR = mod.pickleLoad(args.RUNNABLE_INFO)

    if PATH_INFO_PAR is None or PROJECT_INFO_PAR is None or BUILD_OPTION_PAR \
            is None or STUB_LIST_PAR is None or RUNNABLE_INFO_PAR is None:
        print("Wrong information needed for build.")
        return

     ##### for Test #######
    #PATH_INFO_PAR = {'Workspace_Path': r'C:\Prost\Workspace',
    #                 'Testcode_Path': r'C:\Prost\01.CustomerCode',
    #                 'Compiler_Path': r'C:\Program Files (x86)\TASKING\TriCore v6.2r2',
    #                 'T15_Install_Path': r'C:\Prost', 'Test_Project': 'Project_Name',
    #                 'Log_Path': r'C:\Prost\Workspace\Project_Name\Gen\20191021_Time\Project_Name.log'}
    #PROJECT_INFO_PAR = {'Test_Component': 'VC', 'Test_CPU': 'tc27xd',
    #                    'Cpu_Clock': '20000000', 'Runnable_Header': 'VC.h$$VO.h'}
    #BUILD_OPTION_PAR = {
    #    'Compiler_Option': '-C$(TARGET) $(INC) -g ' + '--default-near-size=0 --default-a0-size=0 --default-a1-size=0 '
    #                       + '--language=-gcc --language=+volatile --language=+strings '
    #                       + '-O2 -OR--tradeoff=4 -Wa-Ogs -Wl-OtxycL --eabi-compliant --eabi=+no-clear',
    #    'Linker_option': '"../$(PROJ).lsl" -Wl--make-target="$(PROJ).elf" -lrt -lcs_fpu -lfp_fpu'}
    #STUB_LIST_PAR = {1: 'void RTE_Test_func1(int mode)$$0$$no return',
    #                 2: 'int RTE_Test_func2(void)$$150$$10',
    #                 3: 'int RTE_Test_func3(int a, int b)$$100$$20'}
    #RUNNABLE_INFO_PAR = {1: 'VC_Step3()$$5$$core0$$pflash0',
    #                     2: 'VC_Step1()$$1$$core1$$pspr0',
    #                     3: 'VC_Step2()$$3$$core0$$pspr0',
    #                     4: 'VC_Step4()$$10$$core1$$pflash0'}

    res = False
    mod.log(PATH_INFO_PAR, 'Start Compiler Module!')
    if mod.targetSWCopy(PATH_INFO_PAR, PROJECT_INFO_PAR):
        if mod.modifyTargetSW(PATH_INFO_PAR, PROJECT_INFO_PAR, RUNNABLE_INFO_PAR, STUB_LIST_PAR):
            if mod.makeBuildEnviroment(PATH_INFO_PAR, PROJECT_INFO_PAR, BUILD_OPTION_PAR):
                last_log = mod.executeTaskingCompiler(PATH_INFO_PAR)
                if 'Linking to ' in last_log:
                    res = True
    return res


if __name__ == '__main__':
    res = main()
    if res:
        print('Build Success')
    else:
        print('Build Failed')
