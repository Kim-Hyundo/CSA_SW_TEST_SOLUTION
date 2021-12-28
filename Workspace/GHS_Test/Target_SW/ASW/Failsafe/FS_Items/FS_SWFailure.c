/*
 * Author: Insub Song (insub.song@halla.com)
 * Date  : 2019.02.01
 */

#include "Rte_SWC_DiagnosticMonitor.h"
#include "App_NvM_Ram.h"

#include "SWC_Failsafe.h"
#include "FS_SWFailure.h"

boolean internal_sw_fault = FALSE;
boolean variant_coding_fault = FALSE;

void put_sw_err(uint8 fatal_error_code, uint8 task_id)
{
    if (!get_precond_ptr()->is_norm_vol)
        return;

    if (int_err_info.sw_err_cnt < 255)
        int_err_info.sw_err_cnt++;

    for (int i = ARRAY_SIZE(int_err_info.sw_err) - 1; i > 0; i--)
        int_err_info.sw_err[i] = int_err_info.sw_err[i - 1];

    int_err_info.sw_err[0].error_code = fatal_error_code;
    int_err_info.sw_err[0].task_id = task_id;
}


#if FS_DEBUG
uint8 sw_test_case = 0;
float div_result;

void StackOverflow(uint32 depth)
{
    double OverflowedStack[100];

    for (int i = 0; i < 100; i++)
        OverflowedStack[i] = (double)i;

    if (depth > 0)
        StackOverflow(--depth);
    else
        return;
}

void FS_SWFailureTest (void)
{
    static float dividend = 10;
    static float divisor = 1;
    int *null_ptr = (void *)0;

    switch (sw_test_case) {
    case 1: /* ProtectionHook 14 */
        divisor--;
        div_result = dividend / divisor;
        break;
    case 2: /* ProtectionHook 9 */
        StackOverflow(100);
        break;
    case 3: /* ProtectionHook 21 */
        *null_ptr += 3;
        break;
    }
    sw_test_case = 0;
}
#endif


void FS_UpdateInfo_SWFailure(void)
{
    struct precondition *p = get_precond_ptr();
    boolean meet_precond = p->is_norm_vol && p->for_3min_after_ign_off;

    if (meet_precond && int_err_info.sw_err_cnt > ERR_CNT_THR)
        internal_sw_fault = TRUE;
    else
        internal_sw_fault = FALSE;
}

void FS_SetDiagsta_SWFailure(void)
{
    SET_DTC(C160604, internal_sw_fault);
}

void FS_SetInhibit_SWFailure(void)
{
    if (internal_sw_fault) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {1,1,1,1,1,1,1,1,1},
                .scc = {1,1,1,1},
                .sccml = {1},
                .nscc = {1,1},
                .lfa = {1,1},
                .hda = {1,1,1,1},
                .warning = {3,3,3,3,HDA_LFA_FAULT,5},
            }
        );
    }
}


void FS_UpdateInfo_VariantCoding(void)
{
    struct precondition *p = get_precond_ptr();
    boolean meet_precond = nvm_loaded && p->is_norm_vol && p->is_3s_after_ign_on;

    uint8 vc_mdps_type = 0;
    if (!meet_precond) {
        variant_coding_fault = FALSE;
        return;
    }
    /* Variant coding not executed */
    if (VariantCode_W_NvMData.stNvMVariantCode_W.NvM_Block_VariantCode_W_main == 0) {
        variant_coding_fault = TRUE;
        return;
    }
    /* Variant coding executed normally */
    else {
        if(is_updated(CHASSIS_0, MDPS_01_10ms_POS)) {
            vc_mdps_type = VariantCode_NvMData.stNvMVariantCode.NvM_Block_MDPS_Type;
            if ((vc_mdps_type == MDPS__R_Type && ref_sig.MDPS_Typ == 0x0) ||
            (vc_mdps_type == MDPS__C_Type && (ref_sig.MDPS_Typ == 0x1 || ref_sig.MDPS_Typ == 0x2))) {
                variant_coding_fault = TRUE;
                return;
            }
        else {
            variant_coding_fault = FALSE;
            return;
        }
        }
    }
}

void FS_SetDiagsta_VariantCoding(void)
{
    SET_DTC(C170255, variant_coding_fault);

    static boolean variant_coding_fault_prev;
    static boolean C170255_clear_req = FALSE;

    if (variant_coding_fault_prev == TRUE && variant_coding_fault == FALSE) {
        C170255_clear_req = TRUE;
    } else if (C170255_clear_req == TRUE) {
#ifndef __PROST_TEST
        if (DEM_CLEAR_OK == Dem_ClearDTC(0x570255 /* C170255 */, DEM_DTC_FORMAT_UDS, DEM_DTC_ORIGIN_PRIMARY_MEMORY))
			C170255_clear_req = FALSE;
#else
		C170255_clear_req = FALSE;
#endif
            
    }
    variant_coding_fault_prev = variant_coding_fault;
}

void FS_SetInhibit_VariantCoding(void)
{
    if (variant_coding_fault) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {1,1,1,1,1,1,1,1,1},
                .scc = {1,1,1,1},
                .sccml = {1},
                .nscc = {1,1},
                .lfa = {1,1},
                .hda = {1,1,1,1},
                .bca = {1,0,1,0},
                .sea = {1},
                .rcca = {1,0},
                .warning = {3,3,3,3,HDA_LFA_FAULT,5,1},
            }
        );
    }
}
