from common import log_mod
from common.log_mod import *

def pass_fail_check_1_0(data_tmp, write_col_lines, index):
    try:
        data_tmp["Min_Result_Output1"] = if_condition("=", "Min_Input", "Min_Output1", write_col_lines, index, data_tmp)
        data_tmp["Min_Result_Output2"] = ""

        data_tmp["Max_Result_Output1"] = if_condition("=", "Max_Input", "Max_Output1", write_col_lines, index, data_tmp)
        data_tmp["Max_Result_Output2"] = ""

        data_tmp["Mid_Result_Output1"] = if_condition("=", "Mid_Input", "Mid_Output1", write_col_lines, index, data_tmp)
        data_tmp["Mid_Result_Output2"] = ""
    except Exception as e:
        set_log('PARSE', "pass_fail_check_1_0 Function Error" + str(e), log_mod.Logtype_ERR)
        raise

def pass_fail_check_1_5(data_tmp, write_col_lines, index):
    try:
        data_tmp["Min_Result_Output1"] = if_condition("=", "Min_Input", "Min_Output1", write_col_lines, index, data_tmp)
        data_tmp["Min_Result_Output2"] = ""

        data_tmp["Max_Result_Output1"] = if_condition("=", "Max_Input", "Max_Output1", write_col_lines, index, data_tmp)
        data_tmp["Max_Result_Output2"] = ""

        data_tmp["Mid_Result_Output1"] = if_condition("=", "Mid_Input", "Mid_Output1", write_col_lines, index, data_tmp)
        data_tmp["Mid_Result_Output2"] = ""
    except Exception as e:
        set_log('PARSE', "pass_fail_check_1_5 Function Error" + str(e), log_mod.Logtype_ERR)
        raise


#조건문 생성 함수
def if_condition(operator, opnd1, opnd2, write_col_lines, index, data_tmp):
    condition = ""
    try:
        #사용 가능한 연산자 리스트
        all_operator = ["=", "<", "<=", ">", ">="]

        #입력받은 연산자가 연산자 리스트에 존재하지 않을 경우, 올바르지 않은 연산자 입력
        if not any(oprt in operator for oprt in all_operator):
            return ""

        #존재하지 않은 피연산자 이름을 입력할 경우
        if opnd1 not in write_col_lines.keys() or opnd2 not in write_col_lines.keys():
            return ""

        #행의 경우, index으로 다음행으로 이동하도록 계산
        opnd1_col = write_col_lines[opnd1][1]
        opnd2_col = write_col_lines[opnd2][1]
        opnd1_row = write_col_lines[opnd1][0] + index
        opnd2_row = write_col_lines[opnd2][0] + index

        opnd1_loc = opnd1_col + str(opnd1_row)
        opnd2_loc = opnd2_col + str(opnd2_row)

        #최종 수식 완성, 조건에 해당하면 TRUE, 아니면 FALSE 입력
        condition = "=IF(" + opnd1_loc + operator + opnd2_loc + ",\"PASS\",IF(ISBLANK(" + opnd2_loc + "),\"N/A\",\"FAIL\"))"

    except Exception as e:
        set_log('PARSE', "if_condition Function Error" + str(e) , log_mod.Logtype_ERR)
        raise
    return condition


