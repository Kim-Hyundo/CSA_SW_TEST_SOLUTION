/*
 * Author: Insub Song (insub.song@halla.com)
 * Date  : 2019.02.01
 */

#include "Rte.h"
#include "Dem.h"
#include "Rte_SWC_DiagnosticMonitor.h"
#include "Mcu.h"
#include "Os_Arch_Regs.h"
#include "App_NvM_Ram.h"

#include "SWC_Failsafe.h"
#include "FS_BatteryVoltage.h"
#include "FS_CANBusOff.h"
#include "FS_CANTimeout.h"
#include "FS_InvalidSignal.h"
#include "FS_HWFailure.h"
#include "FS_SWFailure.h"
#include "DRV_par.h"

#ifndef __PROST_TEST
extern VAR(Mcu_ResetType, ECUM_VAR_NOINIT) EcuM_GddResetReason;
#endif

extern sigerr_t fr_rdr[FR_RDR_ITEM_NUM];
extern uint8 rdr_fail_flag;
uint8 rdr_another_fail_flag = 0;
boolean chk_rdr_inhibit = FALSE;
uint8 recover_mask[RECOVER_GROUP_NUM];

#pragma noclear
struct internal_error_info int_err_info;
struct precondition precond;
uint32 eng_run_cnt_phase1, eng_run_cnt_phase2;
uint16 ign_on_tick, ign_off_tick; 
#pragma noclear restore
boolean eng_first_rcv;

struct inhibit_info inhibit_info;
boolean clear_dtc;

void FS_UpdatePrecond(void);
void FS_UpdateInfo(void);
void FS_SetDiagsta(void);
void FS_SetInhibit(void);
void FS_PostProcessing(void);

void FS_Init(void)
{
#ifndef __PROST_TEST
    Rte_Call_OpCycle_POWER_CYCLE_SetOperationCycleState(DEM_CYCLE_STATE_START);
    Rte_Memcpy(&Failsafe_NvMData, NvMBlock_Failsafe_Segment_RamBlock, sizeof(UnionNvMFailsafe));

    switch (EcuM_GddResetReason) {
#if 0   // FIXME: should be replaced with exact reset reason of ext. watchdog
    case MCU_ESR0_RESET:
    case MCU_ESR1_RESET:
#else
    case MCU_RESET_UNDEFINED:
#endif
        dump_ext_wdg_reset();
        store_in_nvm();
        break;
    case MCU_SMU_RESET:
        /* Will be deprecated */
        dump_smu_debug();
        store_in_nvm();
        break;
    case MCU_SW_RESET:
        /* Enter here after Mcu_PerformReset() */
        store_in_nvm();
        break;
    case MCU_POWER_ON_RESET:
    case MCU_SUPPLY_WDOG_RESET:
        /* Do not modify (To be explicit) */
    default:
        int_err_info = (struct internal_error_info) {0};
        eng_run_cnt_phase1 = 0;
        eng_run_cnt_phase2 = 0;
        break;
    }
#endif /* __PROST_TEST */
}

void FS_MasterLoop(void)
{
#if FS_DEBUG
    FS_HWFailureTest();
    FS_SWFailureTest();
#endif

    FS_UpdatePrecond();
    FS_UpdateInfo();
    FS_SetDiagsta();
    FS_SetInhibit();
    FS_PostProcessing();
}


void FS_UpdatePrecond(void)
{
    if ((vol_grp[VOL_BAT] > BAT_VOL_LOWER && vol_grp[VOL_BAT] < BAT_VOL_UPPER && !bat_info.high.fault && !bat_info.low.fault))
        precond.is_norm_vol = TRUE;
    else
        precond.is_norm_vol = FALSE;

    if (vol_grp[VOL_IGN_FLAG] == TRUE) {
        if (++ign_on_tick > MS2TICK(IGN_ON_DELAY)) {
            precond.is_3s_after_ign_on = TRUE;
        }
    }

    if (precond.is_3s_after_ign_on == TRUE && vol_grp[VOL_IGN_FLAG] == FALSE && vol_grp[VOL_BAT] > 0) {
        if (++ign_off_tick <= MS2TICK(IGN_OFF_DELAY)){
            precond.for_3min_after_ign_off = TRUE;
        }
        else {
            precond.for_3min_after_ign_off = FALSE;
        }
    }

#if CCAN == CANFD
    #if VEH_TYPE == NORMAL
        #define ENG_RUN_MSG EMS_02_10ms_POS
        #define ENG_RUN_SIG ENG_EngSta
        #define ISG_STA_SIG ENG_IsgSta
        #define SCC_STA_SIG CF_ECU_SSC_STAT
        #define ENG_RUN_VAL 3
    #elif VEH_TYPE == EV
        #define ENG_RUN_MSG VCU_01_10ms_POS
        #define ENG_RUN_SIG VCU_EvDrvRdySta
        #define ENG_RUN_VAL 1
    #elif VEH_TYPE == HEV
        #define ENG_RUN_MSG HCU_03_POS
        #define ENG_RUN_SIG HCU_HevRdySta
        #define ENG_RUN_VAL 1
    #endif /* VEH_TYPE */
#elif CCAN == HSCAN
    #if VEH_TYPE == NORMAL
        #define ENG_RUN_MSG EMS16_POS
        #define ENG_RUN_SIG ENG_STAT
        #define ISG_STA_SIG CF_Ems_IsgStat
        #define SCC_STA_SIG CF_ECU_SSC_STAT
        #define ENG_RUN_VAL 3
    //FIXME : Update after EV HSCAN release
    #elif VEH_TYPE == EV
        #define ENG_RUN_MSG VCU_XX_POS
        #define ENG_RUN_SIG CF_Vcu_EvRdy
        #define ENG_RUN_VAL 1
    //FIXME : Update after EV HSCAN release
    #elif VEH_TYPE == HEV
        #define ENG_RUN_MSG HCU_xx_POS
        #define ENG_RUN_SIG CF_Hcu_HevRdy
        #define ENG_RUN_VAL 1
    #endif /* VEH_TYPE */
#endif /* CCAN */

    if (!is_timeout(CHASSIS_0, ENG_RUN_MSG) && is_valid_ems()) {

        if (is_updated(CHASSIS_0, ENG_RUN_MSG)) {

            if (ref_sig.ENG_RUN_SIG == ENG_RUN_VAL || eng_first_rcv == TRUE) {
#if VEH_TYPE == NORMAL
                if (eng_run_cnt_phase1 == 0 && eng_first_rcv == FALSE)
                    eng_first_rcv = TRUE;
#endif /* VEH_TYPE */
                if (eng_run_cnt_phase1 < MS2TICK(2000)) {
                    eng_run_cnt_phase1++;        
                }
                else if (eng_run_cnt_phase2 < 3) {
                    eng_run_cnt_phase2++;
                    eng_first_rcv = FALSE;
                }
            }
#if VEH_TYPE == NORMAL
            else if ((ref_sig.ENG_RUN_SIG == 0 || ref_sig.ENG_RUN_SIG == 2)
                        && (ref_sig.ISG_STA_SIG == 1 || ref_sig.SCC_STA_SIG == 1))  {
                if (eng_run_cnt_phase1 == MS2TICK(2000) && eng_run_cnt_phase2 < 3)
                    eng_run_cnt_phase2++;
                        }
#endif /* VEH_TYPE */
            else {
                if (eng_run_cnt_phase2 > 0)
                    eng_run_cnt_phase2--;
                else
                    eng_run_cnt_phase1 = 0;
            }

            if (eng_run_cnt_phase1 == MS2TICK(2000) && eng_run_cnt_phase2 == 3)
                precond.is_eng_run = TRUE;
            else if (eng_run_cnt_phase1 == 0 || eng_run_cnt_phase2 == 0)
                precond.is_eng_run = FALSE;
        }

    } else {
        eng_run_cnt_phase1 = 0;
        eng_run_cnt_phase2 = 0;
        eng_first_rcv = FALSE;
        precond.is_eng_run = FALSE;
    }

    precond.is_not_ecan_busoff = (ecan_busoff.fault == FALSE) ? TRUE : FALSE;
    precond.is_not_acan_busoff = (acan_busoff.fault == FALSE) ? TRUE : FALSE;
}

void FS_UpdateInfo(void)
{
    if (clear_dtc) {
        clear_dtc = FALSE;
        FS_Clear_BatteryVoltage();
        FS_Clear_CANTimeout();
        FS_Clear_InvalidSignal();
        return;
    }

    FS_UpdateInfo_BatteryVoltage();
    FS_UpdateInfo_CANBusOff();
    FS_UpdateInfo_CANTimeout();
    FS_UpdateInfo_InvalidSignal();
    FS_UpdateInfo_HWFailure();
    FS_UpdateInfo_SWFailure();
    FS_UpdateInfo_VariantCoding();
}

void FS_SetDiagsta(void)
{
    FS_SetDiagsta_BatteryVoltage();
    FS_SetDiagsta_CANBusOff();
    FS_SetDiagsta_CANTimeout();
    FS_SetDiagsta_InvalidSignal();
    FS_SetDiagsta_HWFailure();
    FS_SetDiagsta_SWFailure();
    FS_SetDiagsta_VariantCoding();
}

void FS_SetInhibit(void)
{
#if FAILSAFE_OPTION
    memset(get_inhibit_ptr(), 0, sizeof(struct inhibit_info));

    FS_SetInhibit_BatteryVoltage();
    FS_SetInhibit_CANBusOff();
    FS_SetInhibit_CANTimeout();
    FS_SetInhibit_InvalidSignal();
    FS_SetInhibit_HWFailure();
    FS_SetInhibit_SWFailure();
    FS_SetInhibit_VariantCoding();
#endif
}

void FS_PostProcessing(void)
{
    struct inhibit_info *p = get_inhibit_ptr();

    if (!Get_NAVI_Option())
        p->warning.SCC_NSCCOnOffSta = 0;

    if (!Get_HDA2_Option())
        p->warning.HDA_LCFuncSta = 0;

#if CCAN == CANFD
    extern MsgGr_E2E_ECANFD_ADAS_CMD_31_50ms MsgGr_ADAS_CMD_31_50ms_IVC_D;
#elif CCAN == HSCAN
    extern MsgGr_CCAN_ADAS_CMD_31_1_50ms MsgGr_ADAS_CMD_31_1_50ms_Out;
#define MsgGr_ADAS_CMD_31_50ms_Out MsgGr_ADAS_CMD_31_1_50ms_Out
#define SWRC_LFASwSta CF_Clu_LFASwState
#endif 

    uint8 LFASwSta;
	
    uint8 HDA_CntrlModSta = MsgGr_ADAS_CMD_31_50ms_IVC_D.HDA_CntrlModSta,
          HDA_LFA_SymSta = MsgGr_ADAS_CMD_31_50ms_IVC_D.HDA_LFA_SymSta;


#if LFA_SW_INTEG == APPLIED
    LFASwSta = ref_sig.LFA_ShrtkeySwSta;
#elif LFA_SW_INTEG == NOT_APPLIED
    LFASwSta = ref_sig.SWRC_LFASwSta;
#elif LFA_SW_INTEG == MIXED
    switch (VariantCode_NvMData.stNvMVariantCode.NvM_Block_Region) {
    case Region__Europe:
    case Region__Australia:
        case Region__Russia:
        LFASwSta = ref_sig.LFA_ShrtkeySwSta;
        break;
    default:
        LFASwSta = ref_sig.SWRC_LFASwSta;
        break;
    }
#endif /* LFA_SW_INTEG */


    static enum {
        NO_POPUP = 0,
        LFA_FAIL_POPUP = 3,
        HDA_FAIL_POPUP = 4,
    } popup = NO_POPUP;

    if (popup == NO_POPUP) {
        switch (p->warning.HDA_InfoPUDis) {
        case HDA_LFA_FAULT:
            if (HDA_CntrlModSta != 0 && (HDA_LFA_SymSta == 1 || HDA_LFA_SymSta == 2 || HDA_LFA_SymSta == 3))
                popup = HDA_FAIL_POPUP;
            else if (HDA_CntrlModSta == 0 && (HDA_LFA_SymSta == 1 || HDA_LFA_SymSta == 2 || HDA_LFA_SymSta == 3))
                popup = LFA_FAIL_POPUP;
            else if (HDA_CntrlModSta == 0 && LFASwSta == 1)
                popup = LFA_FAIL_POPUP;
            else
                popup = NO_POPUP;
            break;
        case HDA_FAULT:
            if (HDA_CntrlModSta != 0 && (HDA_LFA_SymSta == 1 || HDA_LFA_SymSta == 2 || HDA_LFA_SymSta == 3))
                popup = HDA_FAIL_POPUP;
            else
                popup = NO_POPUP;
            break;
        case NO_FAULT:
            popup = NO_POPUP;
            break;
        }
    } else if (p->warning.HDA_InfoPUDis == NO_FAULT || (popup == LFA_FAIL_POPUP && p->warning.HDA_InfoPUDis == HDA_FAULT)) {
        /* Recover when NO_FAULT or last LFA popup X HDA_FAULT */
        popup = NO_POPUP;
    } else {
        /* Maintain last warning popup, except above cases */
    }

    /* Convert HDA_InfoPUDis value from FAULT to POPUP */
    p->warning.HDA_InfoPUDis = popup;
}

struct precondition *get_precond_ptr(void) { return &precond; }
struct inhibit_info *get_inhibit_ptr(void) { return &inhibit_info; }

void update_inhibit_info(struct inhibit_info new)
{
    struct inhibit_info *p = get_inhibit_ptr();

    p->scc.SccCc_Inhibit = __max(new.scc.SccCc_Inhibit, p->scc.SccCc_Inhibit);
    p->scc.SccRo_Inhibit = __max(new.scc.SccRo_Inhibit, p->scc.SccRo_Inhibit);
    p->scc.SccSf2_Inhibit = __max(new.scc.SccSf2_Inhibit, p->scc.SccSf2_Inhibit);
    p->scc.SccSf3_Inhibit = __max(new.scc.SccSf3_Inhibit, p->scc.SccSf3_Inhibit);

    p->sccml.SccMl_Inhibit = __max(new.sccml.SccMl_Inhibit, p->sccml.SccMl_Inhibit);

    p->nscc.NScc_Z_C_Inhibit = __max(new.nscc.NScc_Z_C_Inhibit, p->nscc.NScc_Z_C_Inhibit);
    p->nscc.NScc_R_Inhibit = __max(new.nscc.NScc_R_Inhibit, p->nscc.NScc_R_Inhibit);

    p->fca.FcaRo_Inhibit = __max(new.fca.FcaRo_Inhibit, p->fca.FcaRo_Inhibit);
    p->fca.FcaSf2_Inhibit = __max(new.fca.FcaSf2_Inhibit, p->fca.FcaSf2_Inhibit);
    /* CR: HKGL3-923 */
    if (new.fca.FcaRo_Inhibit == 1 && new.fca.FcaSf2_Inhibit ==1) {
        if (!chk_rdr_inhibit) {
            rdr_another_fail_flag = 1;
        }
    }
    chk_rdr_inhibit = FALSE;

    p->fca.FcaSf3_Inhibit = __max(new.fca.FcaSf3_Inhibit, p->fca.FcaSf3_Inhibit);
    p->fca.FcaRo_JC_Inhibit = __max(new.fca.FcaRo_JC_Inhibit, p->fca.FcaRo_JC_Inhibit);
    p->fca.FcaSf3_JC_Inhibit = __max(new.fca.FcaSf3_JC_Inhibit, p->fca.FcaSf3_JC_Inhibit);
    p->fca.FcaSf3_JT_Inhibit = __max(new.fca.FcaSf3_JT_Inhibit, p->fca.FcaSf3_JT_Inhibit);
    p->fca.FcaSf2_Lo_Inhibit = __max(new.fca.FcaSf2_Lo_Inhibit, p->fca.FcaSf2_Lo_Inhibit);
    p->fca.FcaSF3_LS_Inhibit = __max(new.fca.FcaSF3_LS_Inhibit, p->fca.FcaSF3_LS_Inhibit);
    p->fca.Fca_ESA_Inhibit = __max(new.fca.Fca_ESA_Inhibit, p->fca.Fca_ESA_Inhibit);

    p->lfa.Lfa_Lat_Inhibit = __max(new.lfa.Lfa_Lat_Inhibit, p->lfa.Lfa_Lat_Inhibit);
    p->lfa.LfaSf2_Inhibit = __max(new.lfa.LfaSf2_Inhibit, p->lfa.LfaSf2_Inhibit);

    p->hda.Hda_Lat_Inhibit = __max(new.hda.Hda_Lat_Inhibit, p->hda.Hda_Lat_Inhibit);
    p->hda.Hda_Long_Inhibit = __max(new.hda.Hda_Long_Inhibit, p->hda.Hda_Long_Inhibit);
    p->hda.Hda_Inhibit = __max(new.hda.Hda_Inhibit, p->hda.Hda_Inhibit);
    p->hda.HdaII_Inhibit = __max(new.hda.HdaII_Inhibit, p->hda.HdaII_Inhibit);

    p->bca.BCA_Driving_Inhibit = __max(new.bca.BCA_Driving_Inhibit, p->bca.BCA_Driving_Inhibit);
    p->bca.BCA_Driving_RDRBlk_Inhibit = __max(new.bca.BCA_Driving_RDRBlk_Inhibit, p->bca.BCA_Driving_RDRBlk_Inhibit);
    p->bca.BCA_Plus_ParallelExit_Inhibit = __max(new.bca.BCA_Plus_ParallelExit_Inhibit, p->bca.BCA_Plus_ParallelExit_Inhibit);
    p->bca.BCA_Plus_ParallelExit_RDRBlk_Inhibit = __max(new.bca.BCA_Plus_ParallelExit_RDRBlk_Inhibit, p->bca.BCA_Plus_ParallelExit_RDRBlk_Inhibit);

    p->sea.SEA_Inhibit = __max(new.sea.SEA_Inhibit, p->sea.SEA_Inhibit);

    p->rcca.RCCA_Inhibit = __max(new.rcca.RCCA_Inhibit, p->rcca.RCCA_Inhibit);
    p->rcca.RCCA_RDRBlk_Inhibit = __max(new.rcca.RCCA_RDRBlk_Inhibit, p->rcca.RCCA_RDRBlk_Inhibit);

    /* FCA_SysFlrSta depending on severity */
    uint8 FCA_warning_val[] = {3, 2, 5, 6, 1, 4, 0}; // ordered by severity
    for (int i = 0; i < ARRAY_SIZE(FCA_warning_val); i++) {
        uint8 val = FCA_warning_val[i];
        if (p->warning.FCA_SysFlrSta == val || new.warning.FCA_SysFlrSta == val) {
            p->warning.FCA_SysFlrSta = val;
            break;
        }
    }

    p->warning.SCC_SysFlrSta = __max(new.warning.SCC_SysFlrSta, p->warning.SCC_SysFlrSta);
    p->warning.SCCMode_OptUsmSta = __max(new.warning.SCCMode_OptUsmSta, p->warning.SCCMode_OptUsmSta);
    p->warning.SCC_NSCCOnOffSta = __max(new.warning.SCC_NSCCOnOffSta, p->warning.SCC_NSCCOnOffSta);
    p->warning.HDA_InfoPUDis = __max(new.warning.HDA_InfoPUDis, p->warning.HDA_InfoPUDis);
    p->warning.HDA_LCFuncSta = __max(new.warning.HDA_LCFuncSta, p->warning.HDA_LCFuncSta);

    p->warning.BCW_IndSta = __max(new.warning.BCW_IndSta, p->warning.BCW_IndSta);
}

void store_in_nvm(void)
{
    Failsafe_NvMData.stNvMFS.HW_ERR_CNT = int_err_info.hw_err_cnt;
    for (int i = ARRAY_SIZE(Failsafe_NvMData.stNvMFS.HW_ERR_INFO); i--;) {
        Failsafe_NvMData.stNvMFS.HW_ERR_INFO[i].AG_INDEX = int_err_info.hw_err[i].ag_idx;
        Failsafe_NvMData.stNvMFS.HW_ERR_INFO[i].ALARM = int_err_info.hw_err[i].alarm;
    }

    Failsafe_NvMData.stNvMFS.SW_ERR_CNT = int_err_info.sw_err_cnt;
    for (int i = ARRAY_SIZE(Failsafe_NvMData.stNvMFS.SW_ERR_INFO); i--;) {
        Failsafe_NvMData.stNvMFS.SW_ERR_INFO[i].ERROR_CODE = int_err_info.sw_err[i].error_code;
        Failsafe_NvMData.stNvMFS.SW_ERR_INFO[i].TASK_ID = int_err_info.sw_err[i].task_id;
    }

    nvm_info[NvM_FAILSAFE].wr_req = TRUE;
}


uint8 Get_ADAS_DRV_FailInfoSta(void)
{
    if (internal_hw_fault || internal_sw_fault)
        return 1;
    else if (variant_coding_fault)
        return 2;

    return 0;
}

uint8 Get_ADAS_DRV_CodingSta(void)
{
    if (variant_coding_fault)
        return 1;

    return 0;
}

uint8 Get_ADAS_DRV_ACANMonSta(void)
{
    if (acan_busoff.fault)
        return 1;
    else if (can_timeout_fault[L_FR_CMR_0] | can_timeout_fault[L_FR_CMR_1] |can_timeout_fault[L_FR_CMR_2] | 
             can_timeout_fault[L_FR_RDR_0] |
             can_timeout_fault[L_FR_C_RDR_0] | can_timeout_fault[L_FR_C_RDR_1])
        return 2;

    return 0;
}

boolean Get_NAVI_Option(void)
{
    return VariantCode_NvMData.stNvMVariantCode.NvM_Block_NSCC_HDA2_Option != NSCC_HDA2__NA;
}

boolean Get_HDA2_Option(void)
{
    return VariantCode_NvMData.stNvMVariantCode.NvM_Block_NSCC_HDA2_Option != NSCC_HDA2__NA;
}

boolean Get_ISG_Option(void)
{
    return VariantCode_NvMData.stNvMVariantCode.NvM_Block_ISG_Option != ISG__NA;
}

uint8 Get_MDPS_Option(void)
{
    return VariantCode_NvMData.stNvMVariantCode.NvM_Block_MDPS_Type;
}
//FIXME
boolean Get_BCA_Option(void)
{
    return TRUE;
}
boolean Get_SEA_Option(void)
{
    return TRUE;
}
boolean Get_RCCW_Option(void)
{
    return TRUE;
}


uint8 Get_RadarFailureFlg(void)
{
    struct inhibit_info *p = get_inhibit_ptr();
    uint32 lcan_mask = 0;
    uint8 radar_fail_flag = 0;
#if 0
    lcan_mask = (BIT(L_FR_RDR_Obj_16_50ms_POS + 1) - BIT(L_FR_RDR_Obj_01_50ms_POS)) | BIT(L_FR_RDR_Genrl_01_50ms_POS);
    if ((can_timeout_fault[L_FR_RDR] & lcan_mask) || fr_rdr[FR_RDR_C28B186_0].fault || fr_rdr[FR_RDR_NA_0].fault) {
        if (p->fca.FcaRo_Inhibit == 0 && p->fca.FcaSf2_Inhibit == 0) {
            radar_fail_flag = 1;
        }
    }
#endif
    return radar_fail_flag;
}