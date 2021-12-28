import sys
from Mando.MandoInterfaceTest.specification.MandoTestspecParser_10 import *
from Mando.MandoInterfaceTest.specification.MandoTestspecParser_15 import *
from Mando.MandoUnitTest.testcase.MandoUnitTestcaseParser import *
from Mando.MandoUnitTest.specification.MandoUnitTestspecParser import *
from lib.TraceinfoParser import *
from lib.TraceVarParser import *


def main(parameter, parser_name):
    parser = None

    try:
        if parser_name=="MandoTestspecParser_10":
            parser = MandoTestspecParser_10(parameter)
        elif parser_name == "MandoTestspecParser_15":
            parser = MandoTestspecParser_15(parameter)
        elif parser_name == "MandoUnitTestspecParser":
            parser = MandoUnitTestspecParser(parameter)
        elif parser_name=="MandoUnitTestcaseParser":
            parser = MandoUnitTestcaseParser(parameter)
        elif parser_name=="TraceInfoParser":
            parser = TraceinfoParser(parameter)
        elif parser_name=="TraceVarParser":
            parser = TraceVarParser(parameter)

        parser.do_parsing()

        if "spec" in parser_name:
            print("TestspecParser Done")
        elif "case" in parser_name:
            print("TestcaseParser Done")

    except Exception as ex:
        set_log('PARSE', 'Main Parser Exception : ' + str(ex), log_mod.Logtype_ERR)
        print("Exception")
        return

if __name__ == "__main__" :
    main(sys.argv[1], sys.argv[2])

#main(r"C:\Users\GiCheol.Shin\Desktop\test\test\Temp\C_PROJECT_INFO_DATA_dictionary.txt", "MandoUnitTestcaseParser")
#main(r"C:\Users\GiCheol.Shin\Desktop\test\test\Temp\C_PROJECT_INFO_DATA_dictionary.txt", "MandoUnitTestspecParser")
#main(r"C:\git\csa-prost\Workspace\Project_Name\Temp\P_PATH_INFO_PAR_dictionary.txt", "MandoTestcaseParser")
#main(r"C:\git\csa-prost\Workspace\Project_Name\Temp\C_PROJECT_INFO_DATA_dictionary.txt", "MandoTestspecParser_10")
#main(r"C:\git\csa-prost\Workspace\Project_Name\Temp\C_PROJECT_INFO_DATA_dictionary.txt", "MandoTestspecParser_15")
#main(r"C:\git\csa-prost\Workspace\Project_Name\Temp\C_PROJECT_INFO_DATA_dictionary.txt", "WiaUnitTestspecParser")
#main(r"C:\git\csa-prost\Workspace\Project_Name\Temp\C_PROJECT_INFO_DATA_dictionary.txt", "WiaUnitTestcaseParser")
#main(r"C:\Users\CSA_DEV\Documents\Working\Prost_v2.0\Workspace\MANDO_FailSafe\Temp\C_PROJECT_INFO_DATA_dictionary.txt", "TraceVarParser")
#main(r"C:\Users\CSA_DEV\Documents\Working\Prost_v2.0\Workspace\MANDO_FailSafe\Temp\C_PROJECT_INFO_DATA_dictionary.txt", "TraceVarParser")
#main(r"C:\git\csa-prost\Workspace\Project_Name\Temp\C_PROJECT_INFO_DATA_dictionary.txt", "MandoTestcaseParser")
