import decimal


def twos_complement(hexstr, bits):
    value = int(hexstr, 16)

    if value & (1 << (bits - 1)):
        value -= 1 << bits
    return value

def stringToDouble(str):
    return decimal.Decimal(str)


def stringToInt(str):
    return int(str)


def HexstrToInt(signed, hexstr, bits):
    result = 12345678

    if signed == "Signed":
        result = twos_complement(hexstr, bits)
    elif signed == "Unsigned":
        result = int(hexstr, 16)
    return result

 # Todo get_otherSheetData
    # 다른 시트의 데이터 전체를 가져오는 함수
    # all_sheetData : 전체 시트 데이터
    # sheet_name : 이동할 시트의 이름
    # return : all_sheetData[sheet_name] 특정 시트의 데이터
def get_otherSheetData(all_sheetData, sheet_name):
    if all_sheetData is not None and sheet_name in all_sheetData.keys():
        return all_sheetData[sheet_name]

    return None


    # Todo find_dataFromOtherSheet
    # 특정 시트에서 특정 열에 존재하는 데이터를 가진 행을 찾는 함수
    # find_sheet : 특정 시트 데이터
    # key : 탐색할 열의 이름
    # data : 찾을 데이터
    # return : find_row_data - 탐색에 성공한 행 데이터
    # return : None 찾을 수 없을 경우
def find_dataFromOtherSheet(find_sheet, key, data):
    if find_sheet is None:
        return None

    if key is None or data is None:
        return None

    for find_row_data in find_sheet:
        if key not in find_row_data.keys():
            continue
        if find_row_data[key] == data:
            return find_row_data
    return None