#from openpyxl import load_workbook
import win32com.client
from common import log_mod
from common.log_mod import *
import os, string
#-*- coding: utf-8 -*-

def excel_all_data_read(work_sheet):
    data_dump = []

    lastCol = work_sheet.UsedRange.Columns.Count + 1
    lastRow = work_sheet.UsedRange.Rows.Count + 1

    for row_idx in range(1, lastRow):
        row_dump = []
        for col_idx in range(1, lastCol):
            cell_tmp = work_sheet.Cells(row_idx, col_idx).Value
            if cell_tmp != None:
                if type(cell_tmp) == type(""):
                    cell_tmp = cell_tmp.strip()
            row_dump.append(cell_tmp)
        data_dump.append(row_dump)

    return data_dump


def excel_read_sheetnames(file_name, excel):
    try:
        load_wb = excel.Workbooks.Open(file_name)
        wb_names = load_wb.Sheets

        sheet_name_list = []

        for temp in wb_names:
            set_log('PARSE', 'Read Sheet Name, file name = ' + str(file_name) + ' sheet names = ' + str(temp.name), log_mod.Logtype_INF)
            sheet_name_list.append(temp.name)

        load_wb.Close()
    except Exception as e:
        set_log('PARSE', 'Excel File Read Error' + str(e), log_mod.Logtype_ERR)
        return
    finally:
        if excel:
            pass

    return sheet_name_list

def Sample_Copy(sample_file_name, save_path, sheet_names):
    excel = win32com.client.Dispatch("Excel.Application")
    try:
        excel.Visible = False
        load_wb = excel.Workbooks.Open(sample_file_name)
        old_sheet = load_wb.Worksheets("Sample")

        for sheet_name in sheet_names:
            old_sheet.Copy(None, load_wb.Sheets(load_wb.Sheets.Count))
            new_sheet = load_wb.Sheets(load_wb.Sheets.Count)
            new_sheet.Name = sheet_name

        excel.DisplayAlerts = False
        old_sheet.Delete()
        load_wb.SaveAs(save_path)
        load_wb.Close()
    except Exception as e:
        set_log('PARSE', 'Sample Excel Sheet Copy Error' + str(e), log_mod.Logtype_ERR)
    finally:
        if excel:
            excel.Quit()

        return True


def excel_read(file_name, sheet_name):
    excel = win32com.client.Dispatch("Excel.Application")
    data_dump = []
    all_data_dump = {}
    scenario_names = []
    scenario_names.append(sheet_name)

    if sheet_name == "all":
        scenario_names = excel_read_sheetnames(file_name, excel)

    try:
        excel.Visible = False
        load_wb = excel.Workbooks.Open(file_name)
        if sheet_name=="default":
            work_sheet = load_wb.ActiveSheet
        elif sheet_name=="all":
            pass
        else:
            work_sheet = load_wb.Sheets(sheet_name)

        for sheet_tmp in scenario_names:
            if sheet_name == "all":
                work_sheet = load_wb.Sheets(sheet_tmp)

            lastCol = work_sheet.UsedRange.Columns.Count + 1
            lastRow = work_sheet.UsedRange.Rows.Count + 1

            for row_idx in range(1, lastRow):
                row_dump = []
                for col_idx in range(1, lastCol):
                    cell_tmp = str(work_sheet.Cells(row_idx, col_idx).Value)
                    if cell_tmp != None:
                        cell_tmp = cell_tmp.encode(encoding='UTF-8', errors='strict')
                        cell_tmp = str(cell_tmp, encoding="utf-8")
                        if type(cell_tmp) == type(""):
                            cell_tmp = cell_tmp.strip()
                    row_dump.append(str(cell_tmp))
                    print("[PROGRESS]"+ str(sheet_tmp) + ":" + str(row_idx) +"/"+ str(lastRow-1))
                    set_log('PARSE',
                            "Row : " + str(row_idx) + "Col : " + str(col_idx) + " Read Complete..." + "Data = " + str(
                                cell_tmp), log_mod.Logtype_INF)
                    # log_list.append(str(row_idx) + "행" + str(col_idx) + "열 Read 완료")
                data_dump.append(row_dump)

            if sheet_name == "all":
                all_data_dump[sheet_tmp] = data_dump
                data_dump = []

        if sheet_name == "all":
            data_dump = all_data_dump

        load_wb.Save()
        load_wb.Close()
    except Exception as e:
        set_log('PARSE', 'Excel File Read Error' + str(e), log_mod.Logtype_ERR)
        raise
    finally:
        if excel:
            excel.Quit()

        return data_dump

def excel_col_to_int(excel_col):
    try:
        if excel_col == "" or not excel_col.isalpha():
            raise
        excel_col = excel_col.upper()
        excel_col = excel_col[::-1]

        sum = 0

        for idx, s in enumerate(excel_col):
            sum += (ord(s) - 64) * (26 ** idx)

        return sum
    except:
        return

def excel_write(file_name, sheet_name, data_dump, begin_row):
    excel = win32com.client.Dispatch("Excel.Application")
    isExist = False
    try:
        excel.Visible = False

        if not os.path.isfile(file_name):
            load_wb = excel.Workbooks.Add()
            load_ws = load_wb.Worksheets("Sheet1")
        else:
            load_wb = excel.Workbooks.Open(file_name)
            sheet_names = []
            wb_names = load_wb.Sheets
            for temp in wb_names:
                sheet_names.append(temp.name)
            if sheet_name in sheet_names:
                load_ws = load_wb.Worksheets(sheet_name)
            else:
                load_ws = load_wb.Worksheets.Add()
            isExist = True

        load_ws.Name = sheet_name

        startCol = 1
        startRow = begin_row #타이틀 행은 제외하고

        lastCol = len(data_dump[0]) + 1
        lastRow = len(data_dump) + 1


        for row_idx in range(startRow, lastRow):
            for col_idx in range(startCol, lastCol):
                load_ws.Cells(row_idx, col_idx).Value = data_dump[row_idx - 1][col_idx - 1]
                set_log('PARSE', "Row : " + str(row_idx) + "Col : " + str(col_idx) + " Write Complete..." + "Data = " + str(data_dump[row_idx - 1][col_idx - 1]), log_mod.Logtype_INF)

        if isExist:
            load_wb.Save()
        else:
            load_wb.SaveAs(file_name)

        load_wb.Close()
    except Exception as e:
        set_log('PARSE', "Excel File Write Error" + str(e), log_mod.Logtype_ERR)
        raise
    finally:
        if excel:
            excel.Quit()

        return True
