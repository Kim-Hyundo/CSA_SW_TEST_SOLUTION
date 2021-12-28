import win32com.client
import sys
import numpy as np
import time

def excel_read_sheetnames(file_name, excel):
    try:
        load_wb = excel.Workbooks.Open(file_name)
        wb_names = load_wb.Sheets

        sheet_name_list = []

        for temp in wb_names:
            sheet_name_list.append(temp.name)

        load_wb.Close()
    except Exception as e:
        return
    finally:
        if excel:
            pass

    return sheet_name_list

excel = win32com.client.Dispatch("Excel.Application")
data_dump = []
all_data_dump = {}
scenario_names = []
sheet_name = "all"
file_name = r"C:\git\Mando\200324 ADAS_DRV X21_Interface_Master - rev 8.xlsx"
scenario_names.append(sheet_name)

if sheet_name == "all":
    scenario_names = excel_read_sheetnames(file_name, excel)

try:
    excel.Visible = False
    load_wb = excel.Workbooks.Open(file_name)

    start = time.time()

    for sheet_tmp in scenario_names:
        work_sheet = load_wb.Sheets(sheet_tmp)

        if 'win32com' in sys.modules:
            rows = work_sheet.UsedRange.Value
            arr = np.ndarray([len(rows), len(rows[0])], dtype=object)
            for r, row in enumerate(rows):
                for c, val in enumerate(row):
                    arr[r][c] = val

    print(time.time() - start)

    for tmp in arr:
        print(tmp)

    load_wb.Save()
    load_wb.Close()

except Exception as e:
    raise
finally:
    if excel:
        excel.Quit()
