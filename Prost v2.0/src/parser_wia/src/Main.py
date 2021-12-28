import sys
from Wia.WiaUnitTest.testcase.WiaUnitTestcaseParser import *
from Wia.WiaUnitTest.specification.WiaUnitTestspecParser import *
from lib.TraceinfoParser import *
from lib.TraceVarParser import *


def main(parameter, parser_name):
    parser = None

    try:
        if parser_name == "WiaUnitTestspecParser":
            parser = WiaUnitTestspecParser(parameter)
        elif parser_name=="WiaUnitTestcaseParser":
            parser = WiaUnitTestcaseParser(parameter)
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

#main(r"C:\git\csa-prost\Workspace\Project_Name\Temp\C_PROJECT_INFO_DATA_dictionary.txt", "MandoUnitTestcaseParser")
#main(r"C:\git\csa-prost\Workspace\Project_Name\Temp\C_PROJECT_INFO_DATA_dictionary.txt", "MandoUnitTestspecParser")
#main(r"C:\git\csa-prost\Workspace\Project_Name\Temp\P_PATH_INFO_PAR_dictionary.txt", "MandoTestcaseParser")
#main(r"C:\git\csa-prost\Workspace\Project_Name\Temp\C_PROJECT_INFO_DATA_dictionary.txt", "MandoTestspecParser_10")
#main(r"C:\git\csa-prost\Workspace\Project_Name\Temp\C_PROJECT_INFO_DATA_dictionary.txt", "MandoTestspecParser_15")
#main(r"C:\git\csa-prost\Workspace\Project_Name\Temp\C_PROJECT_INFO_DATA_dictionary.txt", "WiaUnitTestspecParser")
#main(r"C:\git\csa-prost\Workspace\Project_Name\Temp\C_PROJECT_INFO_DATA_dictionary.txt", "WiaUnitTestcaseParser")
#main(r"C:\Users\CSA_DEV\Documents\Working\Prost_v2.0\Workspace\MANDO_FailSafe\Temp\C_PROJECT_INFO_DATA_dictionary.txt", "TraceVarParser")
#main(r"C:\Users\CSA_DEV\Documents\Working\Prost_v2.0\Workspace\MANDO_FailSafe\Temp\C_PROJECT_INFO_DATA_dictionary.txt", "TraceVarParser")
#main(r"C:\git\csa-prost\Workspace\Project_Name\Temp\C_PROJECT_INFO_DATA_dictionary.txt", "MandoTestcaseParser")
