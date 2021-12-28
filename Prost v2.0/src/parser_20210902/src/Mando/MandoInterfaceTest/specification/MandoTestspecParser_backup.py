from lib.TestspecParser import *
from Mando.MandoInterfaceTest.lib.AandBType import *
from Mando.MandoInterfaceTest.lib.CType import *
from Mando.MandoInterfaceTest.lib.DType import *
from Mando.MandoInterfaceTest.lib.CommonCopy import *
from Mando.MandoInterfaceTest.lib.PassFail import *
import copy, decimal
from common.Excel_Parser import excel_col_to_int

class MandoTestspecParser(TestspecParser):

    def __init__(self, parameter_path):
        parameter = self.get_parameter(parameter_path)
        super().__init__(parameter, self.test_spec_format_convert, self.create_test_loc_info,self.test_spec_parser, "all","Interface", 3)
        self.parsing_col_lines_1_0 = {}
        self.parsing_col_lines_1_5 = {}
        self.many_parsing_col_lines = {}
        self.write_col_lines = {}
        self.include_sheet_list = []
        self.SW_version = "1.5"
        self.parsing_col_lines = {}

    #######################################################################################################
    #######################################################################################################
    #######################################################################################################

    def parse_location_setting(self):
        # 1. 엑셀 테스트 사양서 파일에서 파싱하고자하는 원하는 행렬 정보를 입력
        #   이후 현재 입력된 "키 (ex - Sender, Signal Name ... etc)" 로 파싱된 데이터 값에 접근
        self.parsing_col_lines_1_0 = {'Direction': [4, 'B'],
                          'Sender': [4, 'G'],
                          'Receiver': [4, 'H'],
                          'Signal Name': [4, 'C'],
                          'ModelVar': [4, 'D'],
                          'Length': [4, 'AB'],
                          'Value Table': [4, 'AF'],
                          'Value Type': [4, 'AG'],
                          'Protocol': [4, 'I'],
                          'Factor': [4, 'AI'],
                          'Offset': [4, 'AJ'],
                          'Message': [4, 'O'],
                          'SWC': [4, 'A']}

        self.parsing_col_lines_1_5 = {'Direction': [4, 'B'],
                                      'Signal Check' : [4, 'G'],
                                      'L1_Group_Name' : [4, 'K'],
                                      'Destination': [4, 'H'],
                                      'Signal Name': [4, 'C'],
                                      'Length': [4, 'EV'],
                                      'Data Type': [4, 'AE'],
                                      'Value Table': [4, 'EZ'],
                                      'Value Type': [4, 'FA'],
                                      'Protocol': [4, 'EC'],
                                      'Factor': [4, 'FC'],
                                      'Offset': [4, 'FD'],
                                      'Message': [4, 'EI']}

        self.many_parsing_col_lines = {',', '('}

        # 2. 이후 생성될 테스트 케이스 파일에 데이터가 쓰여질 원하는 행렬 위치를 입력
        #   마찬가지로 "키" 를 통해 데이터 값에 접근할 수 있으며, 또한 "키" 이름이 각 열의 맨 위 타이틀 이름이 됨.
        #   입력하지 않은 열의 위치는 자동으로 공백이 된다.
        self.write_col_lines = {'Index': [2, 'A'],
                                'Input': [2, 'B'],
                                'Output1': [2, 'C'],
                                'Output2': [2, 'D'],
                                'Sheet': [2, 'E'],
                                'Min_Input': [2, 'G'],
                                'Min_Output1': [2, 'H'],
                                'Min_Result_Output1': [2, 'I'],
                                'Min_Output2': [2, 'J'],
                                'Min_Result_Output2': [2, 'K'],
                                'Max_Input': [2, 'M'],
                                'Max_Output1': [2, 'N'],
                                'Max_Result_Output1': [2, 'O'],
                                'Max_Output2': [2, 'P'],
                                'Max_Result_Output2': [2, 'Q'],
                                'Mid_Input': [2, 'S'],
                                'Mid_Output1': [2, 'T'],
                                'Mid_Result_Output1': [2, 'U'],
                                'Mid_Output2': [2, 'V'],
                                'Mid_Result_Output2': [2, 'W'],}

        self.include_sheet_list = ['VDISP_D', 'IVC_D', 'IDSP', 'IDC', 'SF_D', 'FAILSAFE', 'USM', 'HWIOP_D', 'DIAG', 'DEBUG_D']

        if self.SW_version == "1.0":
            self.parsing_col_lines = self.parsing_col_lines_1_0
        elif self.SW_version == "1.5":
            self.parsing_col_lines = self.parsing_col_lines_1_5

    def parsing_rule(self, data_tmp, origin_data, alldata, index):

        if self.SW_version == "1.0":
            if origin_data["Direction"] == "Rx" and origin_data["Sender"] == "ISR":
                AandBType_test_1_0(data_tmp, origin_data)
            elif origin_data["Direction"] == "Rx" and origin_data["Sender"] != "ISR":
                CType_test_1_0(data_tmp, origin_data, alldata)
            elif origin_data["Direction"] == "Tx" and origin_data["Receiver"] == "Main_CAN" and origin_data["Sheet"] == "IVC": #Dtype - IVC modelvar , signal
                DType_test_1_0(data_tmp, origin_data)
            else:
                pass

            common_copy_1_0(data_tmp, origin_data)

            pass_fail_check_1_0(data_tmp, self.write_col_lines, index)

        elif self.SW_version == "1.5":
            if origin_data["Direction"] == "Rx" and origin_data["Signal Check"] == "Ext":
                AandBType_test_1_5(data_tmp, origin_data)
            elif origin_data["Direction"] == "Tx" and origin_data["Signal Check"] == "Int":
                CType_test_1_5(data_tmp, origin_data, alldata)
            elif origin_data["Direction"] == "Tx" and origin_data["Signal Check"] == "Ext" and origin_data["Sheet"] == "IVC_D":
                DType_test_1_5(data_tmp, origin_data)
            else:
                pass

            common_copy_1_5(data_tmp, origin_data)

            pass_fail_check_1_5(data_tmp, self.write_col_lines, index)


        return data_tmp

    #######################################################################################################
    #######################################################################################################
    #######################################################################################################

        ############ test_spec_parser ############
        # TODO test_spec_parser
        # 테스트 사양서 파서 모듈
        # spec_data : 원본 데이터 를 사용자가 원하는 데이터만 뽑아서 저장
        # return : test_info
        #

    @Logdeco
    def test_spec_parser(self, spec_data):
        test_info = {}
        spec_new_data = {}
        #super().data_pickle_save("[Test Loc Data]", spec_data, r"C:\git\Mando\test2.txt", True)
        #spec_data = super().data_pickle_load("[Test Loc Data]", r"C:\git\Mando\test2.txt")
        try:
            self.parse_location_setting()
            spec_new_data = self.data_structured_process(spec_data)

            for sheet_name, data in spec_new_data.items():
                test_info_tmp = {"Case List": []}

                sub_idx = 0
                for index, origin_data in enumerate(data):
                    if "Crc" in origin_data['Signal Name'] and "Val" in origin_data['Signal Name']:
                        sub_idx = sub_idx + 1
                        continue

                    if "AlvCnt" in origin_data['Signal Name'] and "Val" in origin_data['Signal Name']:
                        sub_idx = sub_idx + 1
                        continue

                    data_tmp = {}
                    data_tmp = self.parsing_rule(data_tmp, origin_data, spec_new_data, index + 1 - sub_idx)

                    test_info_tmp["Case List"].append(copy.deepcopy(data_tmp))

                test_info[sheet_name] = copy.deepcopy(test_info_tmp)

        except Exception as e:
            set_log('PARSE', "Test Spec Parsing Error" + str(e), log_mod.Logtype_ERR)
            raise
        return test_info



    ############ data_structured_process #############
    # TODO data_structured_process
    # 데이터 포맷 변경 함수
    # orig_data : 원본 데이터에서 self.parsing_col_lines 를 기반으로 사용자가 원하는 데이터만 뽑아서 자료구조를 만듦
    # 생설될 포맷은 아래와 같다.
    # new_data = 딕셔너리 (키 - 시트이름(string), 값 - 행 위치[딕셔너리(키 - 열 이름(string) , 값 - 데이터(string))]로 이루어진 리스트])
    # new_data[시트이름] : 리스트
    # new_data[시트이름][행 위치] : 딕셔너리
    # new_data[시트이름][행 위치][열 이름] : 스트링
    # return : new_data

    @Logdeco
    def data_structured_process(self, orig_data):
        new_data = {}
        for sheet_name, data in orig_data.items():
            if sheet_name not in self.include_sheet_list:
                continue

            row_tmp = {}
            row_end = len(data)
            is_ok = False
            col_line_tmp = copy.deepcopy(self.parsing_col_lines)
            while True:
                for key, value in col_line_tmp.items():
                    row = value[0] - 1
                    col = value[1]
                    col = excel_col_to_int(col) - 1

                    if row >= row_end:
                        is_ok = True
                        break

                    if data[row][col] is None or data[row][col] == "None" or data[row][col] == "NONE":
                        row_tmp[key] = ""
                    else:
                        row_tmp[key] = data[row][col]

                    row_tmp["Index"] = str(row + 1) # self.parsing_col_lines 에 Index가 없어서 별도로 추가해줌
                    row_tmp["Sheet"] = sheet_name
                    col_line_tmp[key][0] += 1

                if is_ok:
                    break

                if sheet_name not in new_data.keys():
                    new_data[sheet_name] = []

                new_row_tmp = copy.deepcopy(row_tmp)

                split_tmp = []
                item_name = ""

                if self.SW_version == "1.0":
                    item_name = "Sender"
                elif self.SW_version == "1.5":
                    item_name = "Destination"

                split_tmp = self.data_split(new_row_tmp, item_name, 0)

                for data_tmp in split_tmp:
                    new_row_tmp[item_name] = data_tmp.strip()
                    new_data[sheet_name].append(copy.deepcopy(new_row_tmp))

        return new_data

    def data_split(self, data, item_name, index):
        result_data = []
        result_tmp = []
        result_tmp.append(data[item_name])

        is_ok = False

        if index == '75':
            print("test")

        for idx, delimeter in enumerate(self.many_parsing_col_lines):
            result_tmp_tmp = []
            for data_tmp in result_tmp:
                if delimeter in data_tmp:
                    is_ok = True
                    split_tmp = data_tmp.split(delimeter)
                    if len(self.many_parsing_col_lines) - 1 == idx:
                        result_data.append(split_tmp[index])
                    else:
                        result_tmp_tmp.extend(split_tmp)
                else:
                    result_tmp_tmp = result_tmp

            result_tmp = copy.deepcopy(result_tmp_tmp)

        if not is_ok:
            result_data = [data[item_name]]

        return result_data


    # TODO test_spec_format_convert
    # 엑셀 데이터에 저장될 수 있도록 딕셔너리를 리스트 형태로 변환 시켜주는 함수
    # spec_data : 가공된 딕셔너리 데이터
    # 사용자가 지정한 위치 첫 줄에 self.write_col_lines 의 키(열 이름)가 들어가게 된다.
    @Logdeco
    def test_spec_format_convert(self, spec_data):
        new_data_dump = {}

        try:
            for sheet_name, data in spec_data.items():
                new_data_dump[sheet_name] = []

                case_list = data["Case List"]

                total_row = len(case_list) + 5
                total_col = 0

                for col_tmp in self.write_col_lines.values():
                    tmp = excel_col_to_int(col_tmp[1])
                    if total_col < tmp:
                        total_col = tmp

                for idx in range(total_row):
                    list_tmp = ["" for _ in range(total_col)]
                    new_data_dump[sheet_name].append(list_tmp)

                caseList_cols = case_list[0].keys()
                write_col_lines_tmp = copy.deepcopy(self.write_col_lines)

                #for colname in caseList_cols:
                #    if colname in write_col_lines_tmp:
                #        colname_loc = write_col_lines_tmp[colname]
                #        colname_loc_row = colname_loc[0] - 1
                #        colname_loc_col = excel_col_to_int(colname_loc[1]) - 1
                #        new_data_dump[sheet_name][colname_loc_row][colname_loc_col] = colname

                curr_row_idx = 0
                index = 1
                for row_idx, case_data in enumerate(case_list):
                    for colname in caseList_cols:
                        if colname in write_col_lines_tmp:
                            if colname not in case_data.keys():
                                break
                            colname_loc = write_col_lines_tmp[colname]
                            colname_loc_row = colname_loc[0]
                            colname_loc_col = excel_col_to_int(colname_loc[1]) - 1
                            if colname == "Index":
                                case_data[colname] = str(index)
                                index = index + 1

                            new_data_dump[sheet_name][colname_loc_row][colname_loc_col] = case_data[colname]
                            colname_loc[0] += 1
                            curr_row_idx = colname_loc[0]

                non_write_cnt = total_row - curr_row_idx

                for idx in range(non_write_cnt):
                    new_data_dump[sheet_name].pop(len(new_data_dump[sheet_name]) - 1)

                set_log('PARSE', "new_data_dump[" + str(sheet_name) + "] : " + str(new_data_dump[sheet_name]) + " Add Complete...", log_mod.Logtype_INF)

        except Exception as e:
            set_log('PARSE', "Test Spec Converting Error" + str(e), log_mod.Logtype_ERR)
            raise

        return new_data_dump

    @Logdeco
    def create_test_loc_info(self, spec_data):
        test_loc_info = {"MDS":"MDS"}

        return test_loc_info

    @Logdeco
    def get_parameter(self, parameter_path):
        try:
            parameter_info = super().data_pickle_load("[Parameter Load]", parameter_path)

            set_log('PARSE', "Parameter Data : " + str(parameter_info), log_mod.Logtype_INF)
#           parameter_info = {}
#           common_param = {}
#           common_param['WorkingProject_Path'] = r"C:\git\Mando"
#
#           parameter_info['Common_Path'] = common_param
#
#           parser_param = {}
#           #parser_param['Test_Spec_Path'] = r"C:\git\Mando\200527_NE1_ADAS_DRV_Interface_Master_rev_1_ForMDS.xlsx"
#           parser_param['Test_Spec_Path'] = r"C:\git\Mando\200324 ADAS_DRV X21_Interface_Master - rev 8.xlsx"
#
#           parameter_info['Parser'] = parser_param
#
#           log_param = {}
#           log_param['Log_Level'] = "1"
#
#            parameter_info['Log'] = log_param

            if 'Common_Path' not in parameter_info.keys() or 'Parser' not in parameter_info.keys():
                raise

            common_info = parameter_info['Common_Path']

            if 'WorkingProject_Path' not in common_info.keys():
                raise

            parser_info = parameter_info['Parser']

            if 'Test_Spec_Path' not in parser_info.keys():
                raise

            log_info = parameter_info['Log']

            if 'Log_Level' not in log_info.keys():
                raise

            return parameter_info
        except Exception as ex:
            set_log('PARSE', "Parameter Receive Exception : " + str(ex), log_mod.Logtype_ERR)
            raise
