from lib.Parser import *
import os, time

class TestspecParser(Parser):

    def __init__(self, parameter, test_spec_format_convert, create_test_loc_info, test_spec_parser, read_mode, company, excel_begin_row):
        super().__init__()
        self.col_lines = {}
        self.gen_path = parameter['Common_Path']['WorkingProject_Path']
        self.test_spec_filepath = parameter['Parser']['Test_Spec_Path']
        self.install_path = parameter['Common_Path']['T15_Install_Path']
        self.log_level = parameter['Log']['Log_Level']
        self.test_case_save_path = self.gen_path + "\\TestCase\\"
        self.test_spec_info_backup_txt = self.test_case_save_path + "test_spec_info_backup.txt"
        self.test_loc_info_txt = self.test_case_save_path + "test_loc_info.txt"
        self.test_precond_txt = self.test_case_save_path + "precond_data.txt"

        self.sample_testcase_path = os.path.abspath("./TestCase_Sample.xlsx")
        self.read_mode = read_mode
        self.company = company
        self.excel_begin_row = excel_begin_row
        self.user_cmm_path = self.gen_path + "\\Cmm\\UserMacroScript\\"
        self.cmm_template_path = self.install_path + "\\src\\parser\\Cmm\\Templete"

        log_mod.G_Log_level = int(self.log_level)
        self.test_spec_format_convert = test_spec_format_convert
        self.create_test_loc_info = create_test_loc_info
        self.test_spec_parser = test_spec_parser

    @abc.abstractmethod
    def test_spec_parser(self, spec_data, col_lines):
        pass

    @abc.abstractmethod
    def test_spec_format_convert(self, spec_data):
        pass

    @abc.abstractmethod
    def create_test_loc_info(self, sepc_data):
        pass

    @abc.abstractmethod
    def get_parameter(self, parameter_path):
        pass

    @Logdeco
    def do_parsing(self):
        try:
            if not super().isfile(self.test_spec_filepath):
                set_log('PARSE', 'TestCase File Spec is not exist.', log_mod.Logtype_ERR)
                raise

            dt = datetime.datetime.now()
            data_str = dt.strftime("%Y%m%d%H%M")
            test_case_filename_split = self.test_spec_filepath.split("\\")
            name_only = test_case_filename_split[len(test_case_filename_split) - 1]
            save_file_name = data_str + "_Parsed_new_" + name_only

            if len(self.test_case_save_path + save_file_name) >= 217:
                set_log('PARSE', 'Save File Path too long...', log_mod.Logtype_ERR)
                raise

            excel = win32com.client.Dispatch("Excel.Application")

            ##############################################  Original Test Case Excel Parsing #######################################
            set_log('PARSE', 'Excel File Read Start...', log_mod.Logtype_PRG)

            data_dump = excel_read(self.test_spec_filepath, self.read_mode, excel)

            if super().is_empty(data_dump):
               set_log('PARSE', "Excel read data is empty!", log_mod.Logtype_ERR)
               raise

            set_log('PARSE', 'Excel File Read Complete...', log_mod.Logtype_PRG)
            ##############################################  Test Case Parsing ############################################
            set_log('PARSE', 'Test Spec Parsing Start...', log_mod.Logtype_PRG)

            spec_data = self.test_spec_parser(data_dump)
            #spec_data = self.test_spec_parser()

            if super().is_empty(spec_data):
                set_log('PARSE', 'Parsed TestCase Spec File is Empty.', log_mod.Logtype_ERR)
                raise

            set_log('PARSE', 'Parsed Spec Data Format Converting Start...', log_mod.Logtype_PRG)

            ##############################################  Test Info Parsing ############################################

            if "Precond" in spec_data.keys():
                precond_data = copy.deepcopy(spec_data["Precond"])
                del spec_data["Precond"]
                super().data_pickle_save("[Test Precond Data]", precond_data, self.test_precond_txt, True)

            test_loc_info = self.create_test_loc_info(spec_data)

            super().data_pickle_save("[Test Loc Data]", test_loc_info, self.test_loc_info_txt, True)

            spec_data = self.test_spec_format_convert(spec_data)

            super().data_pickle_save("[Test Spec Data]", spec_data, self.test_spec_info_backup_txt, True)

            set_log('PARSE', 'Parsed Spec Data Format Converting Complete...', log_mod.Logtype_PRG)

            set_log('PARSE', 'Test Spec Parsing Complete...', log_mod.Logtype_PRG)
            ##############################################  Test Case Generate ################################################
            set_log('PARSE', 'Test Case File Generating Start...', log_mod.Logtype_PRG)


            if self.company == "Interface":
                Sample_Copy(self.sample_testcase_path, self.test_case_save_path + save_file_name, spec_data.keys(), excel)

            for sheet_name, data in spec_data.items():
                excel_write(self.test_case_save_path + save_file_name, sheet_name, data, self.excel_begin_row, excel)

            set_log('PARSE', 'Test Case File Generating Complete...', log_mod.Logtype_PRG)
            print("TESTCASEPATH::" + self.test_case_save_path + save_file_name)
            excel.Quit()
        except Exception as ex:
            set_log('PARSE', 'Exception Error : ' + str(ex), log_mod.Logtype_ERR)
            raise
