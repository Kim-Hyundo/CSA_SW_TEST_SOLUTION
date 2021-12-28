from Mando.MandoInterfaceTest.lib.Converter import *
import decimal
from common import log_mod
from common.log_mod import *

############ valueRange_process ############
    # TODO valueRange_process
    # TC1(min), TC2(max), TC3(mid)의 Input, Output1, Output2 값을 처리하는 함수
    # 해당 함수의 내부로직의 우선 순위는 Value Type, Length 순으로 이후에 Signed, Unsigned 여부에 따라 처리되는 결과값이 달라짐
    # data_tmp : 사용자에 의해서 채워진 데이터 딕셔너리 해당 데이터를 통해 Input, Output1, Output2 값을 처리
    # origin_data : Factor와 Offset 데이터를 가져와서 Input, Output1, Output2 값을 처리하기 위해 원본 데이터도 가져옴
    # return : result - TC1(min), TC2(max), TC3(mid)의 Input, Output1, Output2 값을 가진 딕셔너리

def getTestValueRange_1_0( data_tmp, origin_data):
    result = {}
    error_type = ""
    try:
        # min_tmp - TC1(min), TC2(max), TC3(mid)의 Input, Output1, Output2 값을 만들 가공되기 전의 값
        # min_comment - 위와 동일
        # 여러 IF 문 안에서 처리하기 때문에 모두 동일하게 접근가능하도록 위에서 초기화를 미리 해둠
        min_tmp = ""
        min_tmp_tmp =""
        min_comment = ""

        max_tmp = ""
        max_comment = ""

        mid_tmp = ""
        mid_comment = ""

        # data_tmp["Value Type"] - Signed, Unsigned 데이터를 가지고 있는 항목
        sign_unsign = data_tmp["Value Type"]
        bit_length = 0

        # data_tmp["Length"] - 데이터 사이즈를 가지고 있는 항목
        # 기본적으로 string으로 저장되어 있어 int형으로 변환을 해줌
        if data_tmp["Length"] != "":
            error_type = "Length"
            bit_length = int(decimal.Decimal(data_tmp["Length"]))
            data_tmp["Length"] = str(bit_length)


        # (1) Value Table이 존재할 경우
        is_ok = True
        if data_tmp["Value Table"] != "":
            error_type = "Value Table"
            # (1) - 1 Value Table의 내용은 /로 구분되어 있으며 내부 데이터가 16진수(코멘트) (ex - 0xFF : Accelator is on) 과 같이 구성되어 있다.
            # 따라서 먼저 /를 구분자로 Split 한다.
            value_tables = []
            value_tables = data_tmp["Value Table"].split("/")
            if value_tables is not None:
                # (1) - 2 Split이 정상적으로 되었을 경우, 데이터가 두 개 이하, 두개, 두 개 이상을 경우로 나눈다.
                # 두 개 이하일 경우, min, max 두 가지로 나눌 수 없으므로 해당 조건문을 빠져 나간다.
                # 두 개 일 경우, 각각 min, max 값으로 지정한 후, mid는 (min + max / 2)의 반올림 으로 계산한다.
                # 두 개 이상일 경우, 양 끝을 min, max 값으로 지정한 후, 중간 데이타의 값을 mid로 지정한다.
                # 값을 가져오기 위해 ':' 을 구분자로 하여 데이터를 가져온다.
                if len(value_tables) >= 2:
                    min_split = value_tables[0].split(":")
                    max_split = value_tables[len(value_tables) - 1].split(":")

                    if len(min_split) == 2 and len(max_split) == 2:
                        min_tmp = min_split[0]
                        min_comment = min_split[1]
                        max_tmp = max_split[0]
                        max_comment = max_split[1]

                        # 특정 데이터들 몇몇이 '~'로 표시되어 있어 '~'을 잘라낸 뒤, 뒤의 데이터를 사용한다.
                        if "~" in min_tmp:
                            wave_tmp = min_tmp.split("~")
                            min_tmp = wave_tmp[0]

                        if "~" in max_tmp:
                            wave_tmp = max_tmp.split("~")
                            max_tmp = wave_tmp[len(wave_tmp) - 1]

                        # 원본 데이터가 16 진수로 표현되어 있어 정수로 변환한다. 이때 Signed, UnSigned를 고려해서 변환한다.
                        min_tmp = HexstrToInt(sign_unsign, min_tmp, bit_length)
                        max_tmp = HexstrToInt(sign_unsign, max_tmp, bit_length)

                        # (1) - 2.1 두개 이상일 경우
                        if len(value_tables) > 2:
                            mid_split = value_tables[int(len(value_tables) / 2)].split(":")

                            if len(mid_split) == 2:
                                mid_tmp = mid_split[0]
                                mid_comment = mid_split[1]

                                if "~" in mid_tmp:
                                    wave_tmp = mid_tmp.split("~")
                                    mid_tmp = wave_tmp[len(wave_tmp) - 1]

                                mid_tmp = HexstrToInt(sign_unsign, mid_tmp, bit_length)
                            else:
                                mid_tmp = int(round((min_tmp + max_tmp) / 2))
                                mid_comment = ""
                        # (1) - 2.2 두개일 경우
                        else:
                            mid_tmp = int((round(min_tmp + max_tmp) / 2))
                            mid_comment = ""
                    else:
                        is_ok = False
                else:
                    is_ok = False

        # (2) Value Table이 존재하지 않을 경우
        # 데이터 Length를 기반으로 하여 처리한다.
        if data_tmp["Value Table"] == "" or is_ok == False:
            error_type = "Value Table"
            # 특정 데이터 자료형이 'uint8' 로 표시되어 있는 곳이 있어 해당 데이터는 Unsigned, length 8로 처리
            if sign_unsign == "uint8":
                sign_unsign = "Unsigned"
                bit_length = 8

            if sign_unsign == "uint16":
                sign_unsign = "Unsigned"
                bit_length = 16

            if sign_unsign == "sint16":
                sign_unsign = "Signed"
                bit_length = 16

            # max는 2^n - 1로 처리, mid는 (min + max) / 2

            # min은 Signed 일 경우, 2^n * -1 로 처리, Unsigned 일 경우, 0
            if sign_unsign == "Signed":
                max_tmp = int(((1 << int(bit_length)) - 1) / 2)
                min_tmp = max_tmp + 1
                mid_tmp = 0
            elif sign_unsign == "Unsigned" or sign_unsign == "":
                max_tmp = (1 << int(bit_length)) - 1
                min_tmp = 0
                mid_tmp = int(max_tmp / 2)

            # Comment는 min, max, mid 데이터 중 일부에 '()' 안에 추가로 들어가며 요구사항에 따라 아래과 같이 연산됨
            # (원본데이터 * Factor) + Offset
            if (origin_data["Factor"] != "" and origin_data["Offset"] != ""):
                error_type = "Factor"
                min_comment = str(min_tmp * decimal.Decimal(origin_data["Factor"]) + decimal.Decimal(origin_data["Offset"]))
                max_comment = str(max_tmp * decimal.Decimal(origin_data["Factor"]) + decimal.Decimal(origin_data["Offset"]))
                mid_comment = str(mid_tmp * decimal.Decimal(origin_data["Factor"]) + decimal.Decimal(origin_data["Offset"]))

        #요구사항에 따라 16 진수로 변경하여 저장
        min_tmp = str(hex(min_tmp))
        max_tmp = str(hex(max_tmp))
        mid_tmp = str(hex(mid_tmp))

        result = {"Min_Input": min_tmp , "Min_Output1": "", "Min_Output2": "",
                  "Max_Input": max_tmp , "Max_Output1": "", "Max_Output2": "",
                  "Mid_Input": mid_tmp, "Mid_Output1": "", "Mid_Output2": ""}
    except Exception as e:
        set_log('PARSE', "getTestValueRange_1_0 Function Error" + str(e) + " Sheet = " + origin_data["Sheet"] + " Row = " + origin_data["Index"] + " Col = " + error_type, log_mod.Logtype_ERR)
        raise
    return result


def getTestValueRange_1_5( data_tmp, origin_data):
    result = {}
    error_type = ""
    error_type2 = ""
    try:
#        if origin_data["Sheet"] == "IDC" and origin_data["Index"] == "1128":
#            print("test")
        # min_tmp - TC1(min), TC2(max), TC3(mid)의 Input, Output1, Output2 값을 만들 가공되기 전의 값
        # min_comment - 위와 동일
        # 여러 IF 문 안에서 처리하기 때문에 모두 동일하게 접근가능하도록 위에서 초기화를 미리 해둠
        min_tmp = ""
        min_tmp_tmp =""
        min_comment = ""

        max_tmp = ""
        max_comment = ""

        mid_tmp = ""
        mid_comment = ""

        # data_tmp["Value Type"] - Signed, Unsigned 데이터를 가지고 있는 항목
        sign_unsign = data_tmp["Value Type"]
        bit_length = 0

        # data_tmp["Length"] - 데이터 사이즈를 가지고 있는 항목
        # 기본적으로 string으로 저장되어 있어 int형으로 변환을 해줌
        if data_tmp["Length"] != "":
            error_type = "Length"
            bit_length = int(decimal.Decimal(data_tmp["Length"]))
            data_tmp["Length"] = str(bit_length)


        # (1) Value Table이 존재할 경우
        is_ok = True
        if data_tmp["Value Table"] != "":
            error_type = "Value Table"
            # (1) - 1 Value Table의 내용은 /로 구분되어 있으며 내부 데이터가 16진수(코멘트) (ex - 0xFF : Accelator is on) 과 같이 구성되어 있다.
            # 따라서 먼저 /를 구분자로 Split 한다.
            value_tables = []
            value_tables = data_tmp["Value Table"].split("/")
            if value_tables is not None:
                # (1) - 2 Split이 정상적으로 되었을 경우, 데이터가 두 개 이하, 두개, 두 개 이상을 경우로 나눈다.
                # 두 개 이하일 경우, min, max 두 가지로 나눌 수 없으므로 해당 조건문을 빠져 나간다.
                # 두 개 일 경우, 각각 min, max 값으로 지정한 후, mid는 (min + max / 2)의 반올림 으로 계산한다.
                # 두 개 이상일 경우, 양 끝을 min, max 값으로 지정한 후, 중간 데이타의 값을 mid로 지정한다.
                # 값을 가져오기 위해 ':' 을 구분자로 하여 데이터를 가져온다.
                if len(value_tables) >= 2:
                    min_split = value_tables[0].split(":")
                    max_split = value_tables[len(value_tables) - 1].split(":")

                    if len(min_split) == 2 and len(max_split) == 2:
                        min_tmp = min_split[0]
                        min_comment = min_split[1]
                        max_tmp = max_split[0]
                        max_comment = max_split[1]

                        # 특정 데이터들 몇몇이 '~'로 표시되어 있어 '~'을 잘라낸 뒤, 뒤의 데이터를 사용한다.
                        if "~" in min_tmp:
                            wave_tmp = min_tmp.split("~")
                            min_tmp = wave_tmp[len(wave_tmp) - 1]

                        if "~" in max_tmp:
                            wave_tmp = max_tmp.split("~")
                            max_tmp = wave_tmp[len(wave_tmp) - 1]

                        # 원본 데이터가 16 진수로 표현되어 있어 정수로 변환한다. 이때 Signed, UnSigned를 고려해서 변환한다.
                        min_tmp = HexstrToInt(sign_unsign, min_tmp, bit_length)
                        max_tmp = HexstrToInt(sign_unsign, max_tmp, bit_length)

                        # (1) - 2.1 두개 이상일 경우
                        if len(value_tables) > 2:
                            mid_split = value_tables[int(len(value_tables) / 2)].split(":")

                            if len(mid_split) == 2:
                                mid_tmp = mid_split[0]
                                mid_comment = mid_split[1]

                                if "~" in mid_tmp:
                                    wave_tmp = mid_tmp.split("~")
                                    mid_tmp = wave_tmp[len(wave_tmp) - 1]

                                mid_tmp = HexstrToInt(sign_unsign, mid_tmp, bit_length)
                            else:
                                mid_tmp = int(round((min_tmp + max_tmp) / 2))
                                mid_comment = ""
                        # (1) - 2.2 두개일 경우
                        else:
                            mid_tmp = int((round(min_tmp + max_tmp) / 2))
                            mid_comment = ""
                    else:
                        is_ok = False
                else:
                    is_ok = False

        # (2) Value Table이 존재하지 않을 경우
        # 데이터 Length를 기반으로 하여 처리한다.
        if data_tmp["Value Table"] == "" or is_ok == False:
            error_type = "Value Table"
            # 특정 데이터 자료형이 'uint8' 로 표시되어 있는 곳이 있어 해당 데이터는 Unsigned, length 8로 처리
            if data_tmp["Data Type"] != "" and data_tmp["Data Type"] is not None:
                error_type = "Data Type"
                sign_unsign = data_tmp["Data Type"]
                sign_unsign = sign_unsign.strip()
            sign_unsign = sign_unsign.upper()

            if sign_unsign == "UINT8":
                sign_unsign = "UNSIGNED"
                bit_length = 8
            elif sign_unsign == "UINT16":
                sign_unsign = "UNSIGNED"
                bit_length = 16
            elif sign_unsign == "UINT32":
                sign_unsign = "UNSIGNED"
                bit_length = 32
            elif sign_unsign == "SINT16" or sign_unsign == "INT16":
                sign_unsign = "SIGNED"
                bit_length = 16
            elif sign_unsign == "SINT8" or sign_unsign == "INT8":
                sign_unsign = "SIGNED"
                bit_length = 8
            elif sign_unsign == "INT32" or sign_unsign == "FL32" or sign_unsign == "FLOAT":
                sign_unsign = "SIGNED"
                bit_length = 32
            else:
                error_type2 = "Data Type"

            # max는 2^n - 1로 처리, mid는 (min + max) / 2

            # min은 Signed 일 경우, 2^n * -1 로 처리, Unsigned 일 경우, 0
            if sign_unsign == "SIGNED":
                max_tmp = int(((1 << int(bit_length)) - 1) / 2)
                min_tmp = max_tmp + 1
                mid_tmp = 0
            elif sign_unsign == "UNSIGNED" or sign_unsign == "":
                max_tmp = (1 << int(bit_length)) - 1
                min_tmp = 0
                mid_tmp = int(max_tmp / 2)

            # Comment는 min, max, mid 데이터 중 일부에 '()' 안에 추가로 들어가며 요구사항에 따라 아래과 같이 연산됨
            # (원본데이터 * Factor) + Offset
            if (origin_data["Factor"] != "" and origin_data["Offset"] != ""):
                error_type = "Factor/Offset"
                min_comment = str(min_tmp * decimal.Decimal(origin_data["Factor"]) + decimal.Decimal(origin_data["Offset"]))
                max_comment = str(max_tmp * decimal.Decimal(origin_data["Factor"]) + decimal.Decimal(origin_data["Offset"]))
                mid_comment = str(mid_tmp * decimal.Decimal(origin_data["Factor"]) + decimal.Decimal(origin_data["Offset"]))

        #요구사항에 따라 16 진수로 변경하여 저장
        min_tmp = str(hex(min_tmp))
        max_tmp = str(hex(max_tmp))
        mid_tmp = str(hex(mid_tmp))

        result = {"Min_Input": min_tmp , "Min_Output1": "", "Min_Output2": "",
                  "Max_Input": max_tmp , "Max_Output1": "", "Max_Output2": "",
                  "Mid_Input": mid_tmp, "Mid_Output1": "", "Mid_Output2": ""}
    except Exception as e:
        set_log('PARSE', "getTestValueRange_1_5 Function Error" + str(e) + " Sheet = " + origin_data["Sheet"] + " Row = " + origin_data["Index"] + " Col = " + error_type + " " + error_type2 , log_mod.Logtype_ERR)
        raise
    return result
