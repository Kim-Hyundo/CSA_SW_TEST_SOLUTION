/*
 * Author: Insub Song (insub.song@halla.com)
 * Date  : 2019.02.01
 */

#include "Rte_SWC_DiagnosticMonitor.h"
#include "App_NvM_Ram.h"

#include "SWC_Failsafe.h"
#include "FS_CANTimeout.h"
#include "FS_InvalidSignal.h"
#include "DRV_par.h"

extern boolean is_coding_navi_mismatch(void);

uint32 can_timeout_fault[MSG_GRP_NUM];
uint16 can_timeout_tick[MSG_GRP_NUM][32];

#if CCAN == CANFD
boolean can_timeout_disable = FALSE; /* CAN Timeout Disable caused by ACU reset */
uint16 can_timeout_dis_time_remain; /* disable time remaining */
static sigerr_t MDPS_01_indir;

#elif CCAN == HSCAN
boolean can_timeout_disable = FALSE;
static sigerr_t TCU11_indir;
static sigerr_t EMS11_indir;
static sigerr_t EMS_H12_indir;
static sigerr_t NAVI_V2_POS_indir;
#endif /* CCAN */

void FS_UpdateInfo_CANTimeout(void)
{
    struct precondition *p = get_precond_ptr();
    boolean meet_precond;
    boolean navi_option = Get_NAVI_Option();
    boolean hda_option = Get_HDA2_Option();
    uint8 mdps_option = Get_MDPS_Option();
    uint8 HU_AliveStatus = ref_sig.HU_AliveStatus;
    uint8 HU_AdasSupport = ref_sig.HU_AdasSupport;

#if CCAN == CANFD
    meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_not_ecan_busoff;
    if (meet_precond && ref_sig.YRS_AcuRstSta == 1 && ref_sig.ESC_IMURstStaAck == 1 && can_timeout_disable == FALSE) {
        can_timeout_disable = TRUE;
        can_timeout_dis_time_remain = MS2TICK(1000);
    } else if (is_updated(CHASSIS_0, YRS_01_10ms_POS) && ref_sig.YRS_AcuRstSta == 0 && ref_sig.ESC_IMURstStaAck == 0 && can_timeout_dis_time_remain == 0) {
        can_timeout_disable = FALSE;
    } else if (can_timeout_dis_time_remain) {
        can_timeout_dis_time_remain--;
    }
#endif /* for CANFD */


    /* Chassis CAN */
    for (int pos = CHASSIS_0_NUM; pos--;) {
#if CCAN == CANFD
        switch (pos) {
        case ABS_ESC_01_10ms_POS:
        case BCM_10_200ms_POS:
        case CLU_01_20ms_POS:
        case CLU_02_100ms_POS:
        case ESC_01_10ms_POS:
        case ESC_03_20ms_POS:
        case ICSC_02_100ms_POS:
        case ICU_02_200ms_POS:
        case ICU_04_200ms_POS:
        case ICU_06_200ms_POS:
        case MDPS_01_10ms_POS:
        case MFSW_01_200ms_POS:
        case SAS_01_10ms_POS:
        case SWRC_03_20ms_POS:
#if VEH_TYPE == NORMAL
        case TCU_01_10ms_POS:
#elif VEH_TYPE == HEV
        case HTCU_04_POS:
#endif /* VEH_TYPE */
        case WHL_01_10ms_POS:
        case YRS_01_10ms_POS:
            meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_eng_run && p->is_not_ecan_busoff;
            break;
        case SBCM_AST_02_200ms_POS:
        case SBCM_DRV_01_200ms_POS:
            meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->for_3min_after_ign_off && p->is_eng_run && p->is_not_ecan_busoff;
            break;
        case HU_CLU_PE_05_POS:
        case HU_GW_PE_01_POS:
        case HU_MON_PE_01_POS:
            meet_precond = navi_option && !is_coding_navi_mismatch() && p->is_norm_vol && p->is_3s_after_ign_on && p->is_eng_run && p->is_not_ecan_busoff;
            break;
        case HU_NAVI_V2_POS_PE_POS:
            meet_precond = navi_option && !is_coding_navi_mismatch() && HU_AliveStatus == 1 &&p->is_norm_vol && p->is_3s_after_ign_on && p->is_eng_run && p->is_not_ecan_busoff;
#if MAP_VER == V2_3
            (HU_AdasSupport == 5);
#elif MAP_VER == V2
            (HU_AdasSupport == 3 || HU_AdasSupport == 4);
#else
    #error Undefined map version
#endif /* MAP_VER */
            break;
#if VEH_TYPE == NORMAL
        case EMS_01_10ms_POS:
        case EMS_02_10ms_POS:
            meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_not_ecan_busoff;
            break;
        case EMS_03_10ms_POS:
            meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_not_ecan_busoff && Get_ISG_Option();
            break;
        case EMS_05_100ms_POS:
            meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_eng_run && p->is_not_ecan_busoff;
            break;
#elif VEH_TYPE == EV
        case VCU_01_10ms_POS:
        case VCU_03_100ms_POS:
            meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_not_ecan_busoff;
            break;
#elif VEH_TYPE == HEV
        case EMS_07_POS:
        case EMS_11_POS:
        case HCU_03_POS:
        case HCU_05_POS:
            meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_not_ecan_busoff;
            break;
#endif /* VEH_TYPE */
        default:
            continue;
        }
        meet_precond &= !can_timeout_disable;

#elif CCAN == HSCAN
        switch (pos) {
        case CGW1_POS:
        case CGW2_POS:
        case CGW8_POS:
        case CGW_PC4_POS:
        case CGW_PC5_POS:
        case CLU11_POS:
        case CLU13_POS:
        case ESP12_POS:
        case HU_MON_PE_01_POS:
        case MDPS11_POS:
        case MDPS12_POS:
        case P_STS_POS:
        case RR_C_RDR_02_50ms_POS:
        case SAS11_POS:
        case TCS11_POS:
        case TCS13_POS:
        case VSM11_POS:
        case WHL_SPD11_POS:
            meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_eng_run && p->is_not_ecan_busoff;
            break;
        case HU_CLU_PE_05_POS:
        case HU_GW_PE_01_POS:
            meet_precond = navi_option && !is_coding_navi_mismatch() && p->is_norm_vol && p->is_3s_after_ign_on && p->is_eng_run && p->is_not_ecan_busoff;
            break;
        case EMS12_POS:
        case EMS16_POS:
            meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_not_ecan_busoff;
            break;
        default:
            continue;
        }
#endif /* CCAN */


        if (is_updated(CHASSIS_0, (uint8)pos) || ecan_timeout_val[pos] == NO_DETECTION) {
#if CCAN == CANFD
            if (pos == HU_NAVI_V2_POS_PE_POS) {
#if MAP_VER == V2_3
                if (HU_AdasSupport == 5) {
                    can_timeout_tick[CHASSIS_0][HU_NAVI_V2_POS_PE_POS] = 0;
                    can_timeout_fault[CHASSIS_0] &= ~BIT(HU_NAVI_V2_POS_PE_POS);
                }
#elif MAP_VER == V2
                if (HU_AdasSupport == 3 || HU_AdasSupport == 4) {
                    can_timeout_tick[CHASSIS_0][HU_NAVI_V2_POS_PE_POS] = 0;
                    can_timeout_fault[CHASSIS_0] &= ~BIT(HU_NAVI_V2_POS_PE_POS);
                }
#else
    #error Undefined map version
#endif /* MAP_VER */
            } else {
                can_timeout_tick[CHASSIS_0][pos] = 0;
                can_timeout_fault[CHASSIS_0] &= ~BIT(pos);
            }
#elif CCAN == HSCAN
            can_timeout_tick[CHASSIS_0][pos] = 0;
            can_timeout_fault[CHASSIS_0] &= ~BIT(pos);
#endif /* CCAN */
	    } else if (meet_precond) {

            if (++can_timeout_tick[CHASSIS_0][pos] >= ecan_timeout_val[pos]) {
                can_timeout_tick[CHASSIS_0][pos] = ecan_timeout_val[pos];
                can_timeout_fault[CHASSIS_0] |= BIT(pos);
            }
        } else {
            can_timeout_tick[CHASSIS_0][pos] = 0;
        }
    }

    /* Indirect timeout detection */
#if CCAN == CANFD
    uint8 MDPS_LkaPlgInSta = ref_sig.MDPS_LkaPlgInSta;

    meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_eng_run && p->is_not_ecan_busoff;
    update_info(&MDPS_01_indir, meet_precond,
                MDPS_LkaPlgInSta != 1,
                is_updated(CHASSIS_0, MDPS_01_10ms_POS) && MDPS_LkaPlgInSta == 1,
                MS2TICK(500), 0);

#elif CCAN == HSCAN
    uint8 TCU11_STS = ref_sig.TCU11_STS;
    uint8 EMS11_STS = ref_sig.EMS11_STS;
    uint8 EMS_H12_STS = ref_sig.EMS_H12_STS;
    uint16 POS_V2_RangeAvgSpeed = ref_sig.POS_V2_RangeAvgSpeed;

    meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_not_ecan_busoff;
    update_info(&EMS11_indir, meet_precond,
                EMS11_STS == 1,
                is_updated(CHASSIS_0, P_STS_POS) && EMS11_STS == 0,
                MS2TICK(2000), 0);
    update_info(&EMS_H12_indir, meet_precond,
                EMS_H12_STS == 1,
                is_updated(CHASSIS_0, P_STS_POS) && EMS_H12_STS == 0,
                MS2TICK(2000), 0);

    meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_eng_run && p->is_not_ecan_busoff;
    update_info(&TCU11_indir, meet_precond,
                TCU11_STS == 1,
                is_updated(CHASSIS_0, P_STS_POS) && TCU11_STS == 0,
                MS2TICK(2000), 0);

    meet_precond = navi_option && !is_coding_navi_mismatch() && HU_AliveStatus == 1 &&p->is_norm_vol && p->is_3s_after_ign_on && p->is_eng_run && p->is_not_ecan_busoff;
    update_info(&NAVI_V2_POS_indir, meet_precond,
                POS_V2_RangeAvgSpeed == 0x1FE,
                is_updated(CHASSIS_0, NAVI_V2_POS_E_POS) && POS_V2_RangeAvgSpeed != 0x1FE,
                MS2TICK(12000), 3);
#endif /* CCAN */

    if (!navi_option) {
#if CCAN == CANFD
        can_timeout_fault[CHASSIS_0] &= ~(BIT(HU_CLU_PE_05_POS) | BIT(HU_GW_PE_01_POS) | BIT(HU_MON_PE_01_POS) | BIT(HU_NAVI_V2_POS_PE_POS));
#elif CCAN == HSCAN
        can_timeout_fault[CHASSIS_0] &= ~(BIT(HU_CLU_PE_05_POS) | BIT(HU_GW_PE_01_POS));
        NAVI_V2_POS_indir.fault = FALSE;
#endif /* CCAN */
    }
    if (!hda_option) {
#if CCAN == CANFD
        can_timeout_fault[CHASSIS_0] &= ~(BIT(ICU_06_200ms_POS));
#elif CCAN == HSCAN
        can_timeout_fault[CHASSIS_0] &= ~(BIT(CGW5_POS) | BIT(CGW11_POS) | BIT(RR_C_RDR_02_POS));
#endif /* CCAN */
    }
    if (mdps_option != MDPS__R_Type) {
#if CCAN == CANFD
        can_timeout_fault[CHASSIS_0] &= ~(BIT(MFSW_01_200ms_POS));
#endif /* CCAN */        
    }


    /* ADAS CAN */
    meet_precond = (!can_timeout_disable) && p->is_norm_vol && p->is_3s_after_ign_on && p->is_eng_run && p->is_not_acan_busoff;
    for (int msg_num = 0, type = L_FR_CMR_0; type <= L_FR_C_RDR_1; type++) {
        switch (type) {
            case L_FR_CMR_0:
                msg_num = L_FR_CMR_0_NUM;
                break;
            case L_FR_RDR_0:
                msg_num = L_FR_RDR_0_NUM;
                break;
            case L_FR_C_RDR_0:
                msg_num = L_FR_C_RDR_0_NUM;
                break;
            case L_FR_C_RDR_1:
                msg_num = L_FR_C_RDR_1_NUM;
                break;
        }

        for (int pos = msg_num; pos--;) {
            if (is_updated((uint8)type, (uint8)pos)) {
                can_timeout_tick[type][pos] = 0;
                can_timeout_fault[type] &= ~BIT(pos);
            } else if (meet_precond) {
                if (++can_timeout_tick[type][pos] >= acan_timeout_val) {
                    can_timeout_tick[type][pos] = acan_timeout_val;
                    can_timeout_fault[type] |= BIT(pos);
                }
            } else {
                can_timeout_tick[type][pos] = 0;
            }
        }
    }
    uint32 recov_mask;
    recov_mask = BIT(A_FR_CMR_FS_07_30ms_POS + 1) - BIT(A_FR_CMR_Obj_11_30ms_POS);
    can_timeout_fault[L_FR_CMR_0] &= ~recov_mask;
    recov_mask = (BIT(A_FR_RDR_Obj_29_50ms_POS + 1) - BIT(A_FR_RDR_Obj_17_50ms_POS)) | BIT(A_FR_RDR_Genrl_02_50ms_POS);
    can_timeout_fault[L_FR_RDR_0] &= ~recov_mask;

#if CCAN == CANFD
    /* Recover group 1 */
    if (TEST_BIT(recover_mask[RECOVER_GROUP_1], ABS_ESC_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~BIT(ABS_ESC_01_10ms_POS);
#if VEH_TYPE == EV
    if (TEST_BIT(recover_mask[RECOVER_GROUP_1], VCU_HCU_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~(BIT(VCU_01_10ms_POS) | BIT(VCU_03_100ms_POS));
#elif VEH_TYPE == HEV
    if (TEST_BIT(recover_mask[RECOVER_GROUP_1], VCU_HCU_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~(BIT(HCU_03_POS) | BIT(HCU_05_POS));
#endif /* VEH_TYPE */
    if (TEST_BIT(recover_mask[RECOVER_GROUP_1], BCM_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~(BIT(BCM_10_200ms_POS));
    if (TEST_BIT(recover_mask[RECOVER_GROUP_1], CLU_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~(BIT(CLU_01_20ms_POS) | BIT(CLU_02_100ms_POS));
#if VEH_TYPE == NORMAL
    if (TEST_BIT(recover_mask[RECOVER_GROUP_1], EMS_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~(BIT(EMS_01_10ms_POS) | BIT(EMS_02_10ms_POS) | BIT(EMS_03_10ms_POS) | BIT(EMS_05_100ms_POS));
#elif VEH_TYPE == HEV
    if (TEST_BIT(recover_mask[RECOVER_GROUP_1], EMS_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~(BIT(EMS_07_POS) | BIT(EMS_11_POS));
#endif /* VEH_TYPE */
    if (TEST_BIT(recover_mask[RECOVER_GROUP_1], ESC_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~(BIT(ESC_01_10ms_POS) | BIT(ESC_03_20ms_POS));

    /* Recover group 2 */
    if (TEST_BIT(recover_mask[RECOVER_GROUP_2], HU_CLU_PE_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~BIT(HU_CLU_PE_05_POS);
    if (TEST_BIT(recover_mask[RECOVER_GROUP_2], HU_GW_PE_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~BIT(HU_GW_PE_01_POS);
    if (TEST_BIT(recover_mask[RECOVER_GROUP_2], HU_MON_PE_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~BIT(HU_MON_PE_01_POS);
    if (TEST_BIT(recover_mask[RECOVER_GROUP_2], HU_NAVI_V2_POS_PE_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~BIT(HU_NAVI_V2_POS_PE_POS);
    if (TEST_BIT(recover_mask[RECOVER_GROUP_2], ICSC_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~BIT(ICSC_02_100ms_POS);
    if (TEST_BIT(recover_mask[RECOVER_GROUP_2], ICU_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~(BIT(ICU_02_200ms_POS) | BIT(ICU_04_200ms_POS) | BIT(ICU_06_200ms_POS));
    if (TEST_BIT(recover_mask[RECOVER_GROUP_2], MDPS_TIMEOUT)) {
        can_timeout_fault[CHASSIS_0] &= ~BIT(MDPS_01_10ms_POS);
        MDPS_01_indir.fault = FALSE;
    }
    if (TEST_BIT(recover_mask[RECOVER_GROUP_2], MFSW_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~(BIT(MFSW_01_200ms_POS));

    /* Recover group 3 */
    if (TEST_BIT(recover_mask[RECOVER_GROUP_3], RR_C_RDR_TIMEOUT))
        //can_timeout_fault[CHASSIS_0] &= ~BIT(RR_C_RDR_02_50ms_POS);
    if (TEST_BIT(recover_mask[RECOVER_GROUP_3], SAS_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~BIT(SAS_01_10ms_POS);
    if (TEST_BIT(recover_mask[RECOVER_GROUP_3], SWRC_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~BIT(SWRC_03_20ms_POS);
#if VEH_TYPE == NORMAL
    if (TEST_BIT(recover_mask[RECOVER_GROUP_3], TCU_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~BIT(TCU_01_10ms_POS);
#elif VEH_TYPE == HEV
    if (TEST_BIT(recover_mask[RECOVER_GROUP_3], TCU_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~BIT(HTCU_04_POS);
#endif /* VEH_TYPE */
    if (TEST_BIT(recover_mask[RECOVER_GROUP_3], WHL_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~BIT(WHL_01_10ms_POS);
    if (TEST_BIT(recover_mask[RECOVER_GROUP_3], YRS_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~BIT(YRS_01_10ms_POS);
    if (TEST_BIT(recover_mask[RECOVER_GROUP_3], SBCM_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~(BIT(SBCM_AST_02_200ms_POS) | BIT(SBCM_DRV_01_200ms_POS));

#elif CCAN == HSCAN
    /* Recover group 1 */
    if (TEST_BIT(recover_mask[RECOVER_GROUP_1], CGW1_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~BIT(CGW1_POS);
    if (TEST_BIT(recover_mask[RECOVER_GROUP_1], CGW2_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~BIT(CGW2_POS);
    if (TEST_BIT(recover_mask[RECOVER_GROUP_1], CGW8_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~BIT(CGW8_POS);
    if (TEST_BIT(recover_mask[RECOVER_GROUP_1], CGW_PC4_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~BIT(CGW_PC4_POS);
    if (TEST_BIT(recover_mask[RECOVER_GROUP_1], CGW_PC5_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~BIT(CGW_PC5_POS);
    if (TEST_BIT(recover_mask[RECOVER_GROUP_1], CLU11_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~BIT(CLU11_POS);
    if (TEST_BIT(recover_mask[RECOVER_GROUP_1], CLU13_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~BIT(CLU13_POS);
    if (TEST_BIT(recover_mask[RECOVER_GROUP_1], EMS12_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~BIT(EMS12_POS);

    /* Recover group 2 */
    if (TEST_BIT(recover_mask[RECOVER_GROUP_2], EMS16_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~BIT(EMS16_POS);
    if (TEST_BIT(recover_mask[RECOVER_GROUP_2], ESP12_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~BIT(ESP12_POS);
    if (TEST_BIT(recover_mask[RECOVER_GROUP_2], HU_CLU_PE_05_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~BIT(HU_CLU_PE_05_POS);
    if (TEST_BIT(recover_mask[RECOVER_GROUP_2], HU_GW_PE_01_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~BIT(HU_GW_PE_01_POS);
    if (TEST_BIT(recover_mask[RECOVER_GROUP_2], HU_MON_PE_01_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~BIT(HU_MON_PE_01_POS);
    if (TEST_BIT(recover_mask[RECOVER_GROUP_2], MDPS11_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~BIT(MDPS11_POS);
    if (TEST_BIT(recover_mask[RECOVER_GROUP_2], MDPS12_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~BIT(MDPS12_POS);
    if (TEST_BIT(recover_mask[RECOVER_GROUP_2], NAVI_V2_POS_E_POS_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~BIT(NAVI_V2_POS_E_POS);

    /* Recover group 3 */
    if (TEST_BIT(recover_mask[RECOVER_GROUP_3], P_STS_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~BIT(P_STS_POS);
    if (TEST_BIT(recover_mask[RECOVER_GROUP_3], RR_C_RDR_02_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~BIT(RR_C_RDR_02_50ms_POS);
    if (TEST_BIT(recover_mask[RECOVER_GROUP_3], SAS11_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~BIT(SAS11_POS);
    if (TEST_BIT(recover_mask[RECOVER_GROUP_3], TCS11_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~BIT(TCS11_POS);
    if (TEST_BIT(recover_mask[RECOVER_GROUP_3], TCS13_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~BIT(TCS13_POS);
    if (TEST_BIT(recover_mask[RECOVER_GROUP_3], VSM11_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~BIT(VSM11_POS);
    if (TEST_BIT(recover_mask[RECOVER_GROUP_3], WHL_SPD11_TIMEOUT))
        can_timeout_fault[CHASSIS_0] &= ~BIT(WHL_SPD11_POS);
#endif /* CCAN */

    /* Recover group 4 */
    if (TEST_BIT(recover_mask[RECOVER_GROUP_4], L_FR_CMR_TIMEOUT))
        can_timeout_fault[L_FR_CMR_0] = 0UL;
    if (TEST_BIT(recover_mask[RECOVER_GROUP_4], L_FR_RDR_TIMEOUT))
        can_timeout_fault[L_FR_RDR_0] = 0UL;
    if (TEST_BIT(recover_mask[RECOVER_GROUP_4], L_FR_C_RDR_TIMEOUT)) {
        can_timeout_fault[L_FR_C_RDR_0] = 0UL;
        can_timeout_fault[L_FR_C_RDR_1] = 0UL;
    }

}

void FS_SetDiagsta_CANTimeout(void)
{
    /* Chassis CAN */
    uint32 ecan_mask;

#if CCAN == CANFD
#if VEH_TYPE == NORMAL
    ecan_mask = BIT(EMS_01_10ms_POS) | BIT(EMS_02_10ms_POS) | BIT(EMS_03_10ms_POS) | BIT(EMS_05_100ms_POS);
    SET_DTC(C161187, can_timeout_fault[CHASSIS_0] & ecan_mask);

    ecan_mask = BIT(TCU_01_10ms_POS);
    SET_DTC(C161287, can_timeout_fault[CHASSIS_0] & ecan_mask);

#elif VEH_TYPE == EV
    ecan_mask = BIT(VCU_01_10ms_POS) | BIT(VCU_03_100ms_POS);
    SET_DTC(C161487, can_timeout_fault[CHASSIS_0] & ecan_mask);

#elif VEH_TYPE == HEV
    ecan_mask = BIT(EMS_07_POS) | BIT(EMS_11_POS);
    SET_DTC(C161187, can_timeout_fault[CHASSIS_0] & ecan_mask);

    ecan_mask = BIT(HCU_03_POS) | BIT(HCU_05_POS);
    SET_DTC(C161487, can_timeout_fault[CHASSIS_0] & ecan_mask);

    ecan_mask = BIT(HTCU_04_POS);
    SET_DTC(C161287, can_timeout_fault[CHASSIS_0] & ecan_mask);
#endif /* VEH_TYPE */

    ecan_mask = BIT(CLU_01_20ms_POS) | BIT(CLU_02_100ms_POS);
    SET_DTC(C162887, can_timeout_fault[CHASSIS_0] & ecan_mask);

    ecan_mask = BIT(ABS_ESC_01_10ms_POS) | BIT(ESC_01_10ms_POS) | BIT(ESC_03_20ms_POS) | BIT(WHL_01_10ms_POS);
    SET_DTC(C165B87, can_timeout_fault[CHASSIS_0] & ecan_mask);

    ecan_mask = BIT(MDPS_01_10ms_POS);
    SET_DTC(C168787, !!(can_timeout_fault[CHASSIS_0] & ecan_mask) || MDPS_01_indir.fault);

    ecan_mask = BIT(SAS_01_10ms_POS);
    SET_DTC(C162387, can_timeout_fault[CHASSIS_0] & ecan_mask);

    ecan_mask = BIT(ICU_02_200ms_POS) | BIT(ICU_04_200ms_POS) | BIT(ICU_06_200ms_POS);
    SET_DTC(C181287, can_timeout_fault[CHASSIS_0] & ecan_mask);

    ecan_mask = BIT(HU_MON_PE_01_POS) | BIT(HU_CLU_PE_05_POS) | BIT(HU_GW_PE_01_POS);
    SET_DTC(C167A87, can_timeout_fault[CHASSIS_0] & ecan_mask);

    ecan_mask = BIT(MFSW_01_200ms_POS);
    SET_DTC(B164087, can_timeout_fault[CHASSIS_0] & ecan_mask);

    ecan_mask = BIT(YRS_01_10ms_POS);
    SET_DTC(C165C87, can_timeout_fault[CHASSIS_0] & ecan_mask);

    ecan_mask = BIT(SWRC_03_20ms_POS);
    SET_DTC(B169887, can_timeout_fault[CHASSIS_0] & ecan_mask);

    ecan_mask = BIT(ICSC_02_100ms_POS);
    SET_DTC(C186687, can_timeout_fault[CHASSIS_0] & ecan_mask);

    ecan_mask = BIT(HU_NAVI_V2_POS_PE_POS);
    SET_DTC(C186387, can_timeout_fault[CHASSIS_0] & ecan_mask);

    ecan_mask = BIT(BCM_10_200ms_POS);
    SET_DTC(B160487, can_timeout_fault[CHASSIS_0] & ecan_mask);

    ecan_mask = BIT(SBCM_AST_02_200ms_POS);
    SET_DTC(C185287, can_timeout_fault[CHASSIS_0] & ecan_mask);

    ecan_mask = BIT(SBCM_DRV_01_200ms_POS);
    SET_DTC(C185187, can_timeout_fault[CHASSIS_0] & ecan_mask); 

#elif CCAN == HSCAN
    ecan_mask = BIT(CLU11_POS) | BIT(CLU13_POS);
    SET_DTC(C162887, can_timeout_fault[CHASSIS_0] & ecan_mask);

    ecan_mask = BIT(TCS11_POS) | BIT(TCS13_POS) | BIT(ESP12_POS) | BIT(VSM11_POS) | BIT(WHL_SPD11_POS);
    SET_DTC(C165B87, can_timeout_fault[CHASSIS_0] & ecan_mask);

    ecan_mask = BIT(MDPS11_POS) | BIT(MDPS12_POS);
    SET_DTC(C168787, can_timeout_fault[CHASSIS_0] & ecan_mask);

    ecan_mask = BIT(SAS11_POS);
    SET_DTC(C162387, can_timeout_fault[CHASSIS_0] & ecan_mask);

    ecan_mask = BIT(CGW1_POS) | BIT(CGW2_POS) | BIT(CGW8_POS) | BIT(CGW_PC4_POS) | BIT(CGW_PC5_POS) | BIT(P_STS_POS);
    SET_DTC(C181287, can_timeout_fault[CHASSIS_0] & ecan_mask);

    ecan_mask = BIT(HU_MON_PE_01_POS) | BIT(HU_CLU_PE_05_POS) | BIT(HU_GW_PE_01_POS);
    SET_DTC(C167A87, can_timeout_fault[CHASSIS_0] & ecan_mask);

    ecan_mask = BIT(EMS12_POS) | BIT(EMS16_POS);
    SET_DTC(C161187, !!(can_timeout_fault[CHASSIS_0] & ecan_mask) || EMS11_indir.fault || EMS_H12_indir.fault);

    SET_DTC(C186387, NAVI_V2_POS_indir.fault);
    SET_DTC(C161287, TCU11_indir.fault);
#endif /* CCAN */

    /* Local CAN */
    SET_DTC(C28AA87, can_timeout_fault[L_FR_CMR_0]);
    SET_DTC(C28AB87, can_timeout_fault[L_FR_RDR_0]);
    SET_DTC(C188087, !!(can_timeout_fault[L_FR_C_RDR_0]) || !!(can_timeout_fault[L_FR_C_RDR_1]));
}

void FS_SetInhibit_CANTimeout(void)
{
    /* Chassis-CAN */
#if CCAN == CANFD
    /* CAN Timeout Disable ACU */
    if (can_timeout_disable) {
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
                .warning = {0,0,0,0,0,0,1},
            }
        );
    }

#if VEH_TYPE == NORMAL
    if (can_timeout_fault[CHASSIS_0] & BIT(EMS_01_10ms_POS)) {
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

    if (can_timeout_fault[CHASSIS_0] & BIT(EMS_02_10ms_POS)) {
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

    if (can_timeout_fault[CHASSIS_0] & BIT(EMS_03_10ms_POS)) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,0,0,0,0,0,0,0},
                .scc = {1,1,1,1},
                .sccml = {1},
                .nscc = {1,1},
                .lfa = {0,0},
                .hda = {0,1,1,1},
                .bca = {0,0,0,0},
                .sea = {0},
                .rcca = {0,0},
                .warning = {0,3,3,3,HDA_FAULT,5,1},
            }
        );
    }

    if (can_timeout_fault[CHASSIS_0] & BIT(EMS_05_100ms_POS)) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,0,0,0,0,0,0,0},
                .scc = {0,0,0,0},
                .sccml = {0},
                .nscc = {0,0},
                .lfa = {0,0},
                .hda = {0,0,0,0},
                .bca = {0,0,1,0},
                .sea = {0},
                .rcca = {1,0},
                .warning = {0,0,0,0,NO_FAULT,0,1},
            }
        );
    }

    if (can_timeout_fault[CHASSIS_0] & BIT(TCU_01_10ms_POS)) {
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

#elif VEH_TYPE == EV
    if (can_timeout_fault[CHASSIS_0] & BIT(VCU_01_10ms_POS)) {
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

    if (can_timeout_fault[CHASSIS_0] & BIT(VCU_03_100ms_POS)) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,0,0,0,0,0,0,0},
                .scc = {1,1,1,1},
                .sccml = {1},
                .nscc = {1,1},
                .lfa = {0,0},
                .hda = {0,0,0,0},
                .warning = {0,3,3,3,NO_FAULT,0},
            }
        );
    }

#elif VEH_TYPE == HEV
    if (can_timeout_fault[CHASSIS_0] & BIT(EMS_07_POS)) {
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

    if (can_timeout_fault[CHASSIS_0] & BIT(EMS_11_POS)) {
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

    if (can_timeout_fault[CHASSIS_0] & BIT(HCU_03_POS)) {
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

    if (can_timeout_fault[CHASSIS_0] & BIT(HCU_05_POS)) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {1,1,1,1,1,1,1,1,1},
                .scc = {0,0,0,0},
                .sccml = {0},
                .nscc = {0,0},
                .lfa = {0,0},
                .hda = {0,0,0,0},
                .warning = {0,0,0,0,NO_FAULT,0},
            }
        );
    }

    if (can_timeout_fault[CHASSIS_0] & BIT(HTCU_04_POS)) {
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
#endif /* VEH_TYPE */

    if (can_timeout_fault[CHASSIS_0] & BIT(CLU_01_20ms_POS)) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,0,0,0,0,0,0,0},
                .scc = {1,1,1,1},
                .sccml = {1},
                .nscc = {1,1},
                .lfa = {1,1},
                .hda = {1,1,1,1},
                .bca = {1,0,1,0},
                .sea = {1},
                .rcca = {1,0},
                .warning = {0,3,3,3,HDA_LFA_FAULT,5,1},
            }
        );
    }

    if (can_timeout_fault[CHASSIS_0] & BIT(CLU_02_100ms_POS)) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,0,0,0,0,0,0,0},
                .scc = {0,0,0,0},
                .sccml = {0},
                .nscc = {0,0},
                .lfa = {0,0},
                .hda = {0,0,0,0},
                .bca = {0,0,0,0},
                .sea = {0},
                .rcca = {0,0},
                .warning = {0,0,0,0,NO_FAULT,0,1},
            }
        );
    }

    if (can_timeout_fault[CHASSIS_0] & BIT(ABS_ESC_01_10ms_POS)) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {1,1,1,1,1,1,1,1,1},
                .scc = {1,1,1,1},
                .sccml = {1},
                .nscc = {1,1},
                .lfa = {1,1},
                .hda = {1,1,1,1},
                .bca = {0,0,0,0},
                .sea = {0},
                .rcca = {0,0},
                .warning = {3,3,3,3,HDA_LFA_FAULT,5,1},
            }
        );
    }

    if (can_timeout_fault[CHASSIS_0] & BIT(ESC_01_10ms_POS)) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {1,1,1,1,1,1,1,1,1},
                .scc = {1,1,1,1},
                .sccml = {1},
                .nscc = {1,1},
                .lfa = {1,1},
                .hda = {1,1,1,1},
                .bca = {0,0,0,0},
                .sea = {0},
                .rcca = {0,0},
                .warning = {3,3,3,3,HDA_LFA_FAULT,5,1},
            }
        );
    }

    if (can_timeout_fault[CHASSIS_0] & BIT(ESC_03_20ms_POS)) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {1,1,1,1,1,1,1,1,1},
                .scc = {1,1,1,1},
                .sccml = {1},
                .nscc = {1,1},
                .lfa = {1,1},
                .hda = {1,1,1,1},
                .bca = {0,0,0,0},
                .sea = {0},
                .rcca = {0,0},
                .warning = {3,3,3,3,HDA_LFA_FAULT,5,1},
            }
        );
    }

    if (can_timeout_fault[CHASSIS_0] & BIT(WHL_01_10ms_POS)) {
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

    if (can_timeout_fault[CHASSIS_0] & BIT(MDPS_01_10ms_POS)) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,0,0,0,0,1,1,1},
                .scc = {0,0,0,0},
                .sccml = {0},
                .nscc = {0,0},
                .lfa = {1,1},
                .hda = {1,0,1,1},
                .bca = {1,0,0,0},
                .sea = {0},
                .rcca = {0,0},
                .warning = {3,0,0,0,HDA_LFA_FAULT,5,1},
            }
        );
    }

    if (MDPS_01_indir.fault) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,0,0,0,0,1,1,1},
                .scc = {0,0,0,0},
                .sccml = {0},
                .nscc = {0,0},
                .lfa = {1,1},
                .hda = {1,0,1,1},
                .bca = {1,0,0,0},
                .sea = {0},
                .rcca = {0,0},
                .warning = {3,0,0,0,HDA_LFA_FAULT,5,1},
            }
        );
    }

    if (can_timeout_fault[CHASSIS_0] & BIT(SAS_01_10ms_POS)) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {1,1,1,1,1,1,1,1,1},
                .scc = {1,1,1,1},
                .sccml = {1},
                .nscc = {1,1},
                .lfa = {1,1},
                .hda = {1,1,1,1},
                .bca = {1,0,1,0},
                .sea = {0},
                .rcca = {1,0},
                .warning = {3,3,3,3,HDA_LFA_FAULT,5,1},
            }
        );
    }

    if (can_timeout_fault[CHASSIS_0] & BIT(ICU_02_200ms_POS)) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,0,0,0,0,0,0,0},
                .scc = {1,1,1,1},
                .sccml = {1},
                .nscc = {1,1},
                .lfa = {0,0},
                .hda = {0,1,1,1},
                .bca = {1,0,1,0},
                .sea = {1},
                .rcca = {1,0},
                .warning = {0,3,3,3,HDA_FAULT,5,1},
            }
        );
    }

    if (can_timeout_fault[CHASSIS_0] & BIT(ICU_04_200ms_POS)) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {1,1,1,1,1,1,1,1,1},
                .scc = {0,0,0,0},
                .sccml = {0},
                .nscc = {0,0},
                .lfa = {1,1},
                .hda = {1,0,1,1},
                .bca = {0,0,0,0},
                .sea = {0},
                .rcca = {0,0},
                .warning = {3,0,0,0,HDA_LFA_FAULT,5,1},
            }
        );
    }

    if (can_timeout_fault[CHASSIS_0] & BIT(ICU_06_200ms_POS)) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,0,0,0,0,0,0,0},
                .scc = {0,0,0,0},
                .sccml = {0},
                .nscc = {0,0},
                .lfa = {0,0},
                .hda = {0,0,0,1},
                .bca = {0,0,0,0},
                .sea = {0},
                .rcca = {0,0},
                .warning = {0,0,0,0,NO_FAULT,5,1},
            }
        );
    }

    if (can_timeout_fault[CHASSIS_0] & BIT(MFSW_01_200ms_POS)) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,0,1,0,0,1,1,1},
                .scc = {0,0,0,0},
                .sccml = {0},
                .nscc = {0,0},
                .lfa = {1,1},
                .hda = {1,0,1,1},
                .bca = {1,0,1,0},
                .sea = {1},
                .rcca = {1,0},
                .warning = {3,0,0,0,HDA_LFA_FAULT,5,1},
            }
        );
    }

    if (can_timeout_fault[CHASSIS_0] & BIT(YRS_01_10ms_POS)) {
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

    if (can_timeout_fault[CHASSIS_0] & BIT(SWRC_03_20ms_POS)) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,0,0,0,0,0,0,0},
                .scc = {1,1,1,1},
                .sccml = {1},
                .nscc = {1,1},
                .lfa = {1,1},
                .hda = {1,1,1,1},
                .bca = {0,0,0,0},
                .sea = {0},
                .rcca = {0,0},
                .warning = {0,3,3,3,HDA_LFA_FAULT,5,1},
            }
        );
    }

    if (can_timeout_fault[CHASSIS_0] & BIT(ICSC_02_100ms_POS)) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,0,0,0,0,0,0,0},
                .scc = {0,0,0,0},
                .sccml = {0},
                .nscc = {0,0},
                .lfa = {0,0},
                .hda = {0,0,0,0},
                .bca = {0,0,0,0},
                .sea = {0},
                .rcca = {0,0},
                .warning = {0,0,0,0,NO_FAULT,0,1},
            }
        );
    }

    if (can_timeout_fault[CHASSIS_0] & BIT(BCM_10_200ms_POS)) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,1,1,1,1,1,1,1,1},
                .scc = {0,0,1,1},
                .sccml = {0},
                .nscc = {0,1},
                .lfa = {1,1},
                .hda = {1,0,1,1},
                .bca = {1,0,1,0},
                .sea = {1},
                .rcca = {1,0},
                .warning = {3,0,0,0,HDA_LFA_FAULT,5,1},
            }
        );
    }

    if (can_timeout_fault[CHASSIS_0] & BIT(SBCM_AST_02_200ms_POS)) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,0,0,0,0,0,0,0},
                .scc = {0,0,0,0},
                .sccml = {0},
                .nscc = {0,0},
                .lfa = {0,0},
                .hda = {0,0,0,0},
                .bca = {0,0,0,0},
                .sea = {0},
                .rcca = {0,0},
                .warning = {0,0,0,0,NO_FAULT,0,2},
            }
        );
    }

    if (can_timeout_fault[CHASSIS_0] & BIT(SBCM_DRV_01_200ms_POS)) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,0,0,0,0,0,0,0},
                .scc = {0,0,0,0},
                .sccml = {0},
                .nscc = {0,0},
                .lfa = {0,0},
                .hda = {0,0,0,0},
                .bca = {0,0,0,0},
                .sea = {0},
                .rcca = {0,0},
                .warning = {0,0,0,0,NO_FAULT,0,2},
            }
        );
    }

#elif CCAN == HSCAN
    if (can_timeout_fault[CHASSIS_0] & BIT(CLU11_POS)) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,0,0,0,0,0,0,0},
                .scc = {1,1,1,1},
                .sccml = {1},
                .nscc = {1,1},
                .lfa = {1,1},
                .hda = {1,1,1,1},
                .warning = {0,3,3,3,HDA_LFA_FAULT,5},
            }
        );
    }

    if (can_timeout_fault[CHASSIS_0] & BIT(CLU13_POS)) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,0,0,0,0,0,0,0},
                .scc = {0,0,0,0},
                .sccml = {0},
                .nscc = {0,0},
                .lfa = {0,0},
                .hda = {0,0,0,0},
                .warning = {0,0,0,0,NO_FAULT,0},
            }
        );
    }

    if (can_timeout_fault[CHASSIS_0] & (BIT(TCS11_POS) | BIT(TCS13_POS) | BIT(ESP12_POS) | BIT(VSM11_POS) | BIT(WHL_SPD11_POS))) {
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

    if (can_timeout_fault[CHASSIS_0] & (BIT(MDPS11_POS) | BIT(MDPS12_POS))) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,0,0,0,0,1,1,1},
                .scc = {0,0,0,0},
                .sccml = {0},
                .nscc = {0,0},
                .lfa = {1,1},
                .hda = {1,0,1,1},
                .warning = {3,0,0,0,HDA_LFA_FAULT,5},
            }
        );
    }

    if (can_timeout_fault[CHASSIS_0] & BIT(SAS11_POS)) {
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

    if (can_timeout_fault[CHASSIS_0] & (BIT(CGW1_POS) | BIT(CGW_PC4_POS) | BIT(CGW_PC5_POS) | BIT(P_STS_POS))) {
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

    if (can_timeout_fault[CHASSIS_0] & BIT(CGW2_POS)) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,0,0,0,0,0,0,0},
                .scc = {1,1,1,1},
                .sccml = {1},
                .nscc = {1,1},
                .lfa = {0,0},
                .hda = {0,1,1,1},
                .warning = {0,3,3,3,HDA_FAULT,5},
            }
        );
    }

    if (can_timeout_fault[CHASSIS_0] & BIT(CGW8_POS)) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,0,0,0,0,1,1,1},
                .scc = {0,0,0,0},
                .sccml = {0},
                .nscc = {0,0},
                .lfa = {1,1},
                .hda = {1,0,1,1},
                .warning = {3,0,0,0,HDA_LFA_FAULT,5},
            }
        );
    }

    if (can_timeout_fault[CHASSIS_0] & (BIT(EMS12_POS) | BIT(EMS16_POS))) {
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

    if (EMS11_indir.fault) {
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

    if (EMS_H12_indir.fault) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,0,0,0,0,0,0,0},
                .scc = {1,1,1,1},
                .sccml = {1},
                .nscc = {1,1},
                .lfa = {0,0},
                .hda = {0,0,0,0},
                .warning = {0,3,3,3,NO_FAULT,0},
            }
        );
    }

    if (TCU11_indir.fault) {
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

    if (can_timeout_fault[CHASSIS_0] & BIT(RR_C_RDR_02_50ms_POS)) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,0,0,0,0,0,0,0},
                .scc = {0,0,0,0},
                .sccml = {0},
                .nscc = {0,0},
                .lfa = {0,0},
                .hda = {0,0,0,1},
                .warning = {0,0,0,0,NO_FAULT,5},
            }
        );
    }
#endif /* CCAN */

    /* NAVI */
    if (can_timeout_fault[CHASSIS_0] & (BIT(HU_CLU_PE_05_POS) | BIT(HU_GW_PE_01_POS) | BIT(HU_MON_PE_01_POS))) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,0,0,0,0,0,0,0},
                .scc = {0,0,0,0},
                .sccml = {0},
                .nscc = {1,1},
                .lfa = {0,0},
                .hda = {0,0,1,1},
                .bca = {0,0,0,0},
                .sea = {0},
                .rcca = {0,0},
                .warning = {0,0,0,3,HDA_FAULT,5,1},
            }
        );
    }

#if CCAN == CANFD
    if (can_timeout_fault[CHASSIS_0] & BIT(HU_NAVI_V2_POS_PE_POS)) {
#elif CCAN == HSCAN
    if (NAVI_V2_POS_indir.fault) {
#endif /* CCAN */
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,0,0,0,0,0,0,0},
                .scc = {0,0,0,0},
                .sccml = {0},
                .nscc = {1,1},
                .lfa = {0,0},
                .hda = {0,0,1,1},
                .bca = {0,0,0,0},
                .sea = {0},
                .rcca = {0,0},
                .warning = {0,0,0,3,HDA_FAULT,5,1},
            }
        );
    }

    /* ADAS CAN */
    uint32 acan_mask;

    /* L_FR_RDR_Obj_01 ~ L_FR_RDR_Obj_16, L_FR_RDR_Genrl_01 */
    acan_mask = (BIT(A_FR_RDR_Obj_16_50ms_POS + 1) - BIT(A_FR_RDR_Obj_01_50ms_POS)) | BIT(A_FR_RDR_Genrl_01_50ms_POS);
    if (can_timeout_fault[L_FR_RDR_0] & acan_mask) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {1,1,1,1,1,1,1,1,1},
                .scc = {1,1,1,1},
                .sccml = {1},
                .nscc = {1,1},
                .lfa = {0,1},
                .hda = {0,1,1,1},
                .bca = {1,0,0,0},
                .sea = {0},
                .rcca = {0,0},
                .warning = {3,3,3,3,HDA_FAULT,5,1},
            }
        );
    }

    /* L_FR_RDR_ODM_01 */
    acan_mask = BIT(A_FR_RDR_ODM_01_50ms_POS);
    if (can_timeout_fault[L_FR_RDR_0] & acan_mask) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,0,0,0,0,0,0,0},
                .scc = {0,0,0,1},
                .sccml = {0},
                .nscc = {0,0},
                .lfa = {0,0},
                .hda = {0,0,0,0},
                .bca = {0,0,0,0},
                .sea = {0},
                .rcca = {0,0},
                .warning = {0,0,0,0,NO_FAULT,0,1},
            }
        );
    }

    /* L_FR_C_RDR_Obj_30_50ms ~ L_FR_C_RDR_Obj_01_50ms*/
    acan_mask = BIT(A_FR_C_RDR_Obj_30_50ms_POS + 1) - BIT(A_FR_C_RDR_Obj_01_50ms_POS);
    if (can_timeout_fault[L_FR_C_RDR_0] & acan_mask) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,1,0,1,1,1,1,1},
                .scc = {0,0,0,1},
                .sccml = {0},
                .nscc = {0,1},
                .lfa = {0,0},
                .hda = {0,0,0,1},
                .bca = {1,0,1,0},
                .sea = {1},
                .rcca = {1,0},
                .warning = {3,0,0,0,NO_FAULT,5,1},
            }
        );
    }
    
    /* L_FR_C_RDR_LH_FS_01 ~ L_FR_C_RDR_LH_FS_08, L_FR_C_RDR_RH_FS_01 ~ L_FR_C_RDR_RH_FS_08 */
    acan_mask = BIT(A_FR_C_RDR_RH_FS_08_50ms_POS + 1) - BIT(A_FR_C_RDR_LH_FS_01_50ms_POS);
    if ((can_timeout_fault[L_FR_C_RDR_1]) & acan_mask) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,1,0,1,1,1,1,1},
                .scc = {0,0,0,1},
                .sccml = {0},
                .nscc = {0,1},
                .lfa = {0,0},
                .hda = {0,0,0,1},
                .bca = {1,0,1,0},
                .sea = {1},
                .rcca = {1,0},
                .warning = {3,0,0,0,NO_FAULT,5,1},
            }
        );
    }

    /* L_FR_C_RDR_Genrl_01 */
    acan_mask = BIT(A_FR_C_RDR_Genrl_01_50ms_POS);
    if ((can_timeout_fault[L_FR_C_RDR_0]) & acan_mask) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,1,0,1,1,1,1,1},
                .scc = {0,0,0,1},
                .sccml = {0},
                .nscc = {0,1},
                .lfa = {0,0},
                .hda = {0,0,0,1},
                .bca = {1,0,1,0},
                .sea = {1},
                .rcca = {1,0},
                .warning = {3,0,0,0,NO_FAULT,5,1},
            }
        );
    }

    /* L_FR_C_RDR_ODM_01 */
    acan_mask = BIT(A_FR_C_RDR_ODM_01_50ms_POS);
    if ((can_timeout_fault[L_FR_C_RDR_0]) & acan_mask) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,0,0,0,0,0,0,0},
                .scc = {0,0,0,1},
                .sccml = {0},
                .nscc = {0,0},
                .lfa = {0,0},
                .hda = {0,0,0,0},
                .bca = {0,0,0,0},
                .sea = {0},
                .rcca = {0,0},
                .warning = {0,0,0,0,NO_FAULT,0,1},
            }
        );
    }

    /* L_FR_CMR_Obj_01 ~ L_FR_CMR_Obj_10 */
    acan_mask = BIT(A_FR_CMR_Obj_10_30ms_POS + 1) - BIT(A_FR_CMR_Obj_01_30ms_POS);
    if (can_timeout_fault[L_FR_CMR_0] & acan_mask) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,1,1,1,1,1,1,1,1},
                .scc = {0,0,1,1},
                .sccml = {0},
                .nscc = {0,1},
                .lfa = {0,1},
                .hda = {0,0,0,1},
                .bca = {1,0,0,0},
                .sea = {0},
                .rcca = {0,0},
                .warning = {3,0,0,0,NO_FAULT,5,1},
            }
        );
    }

    /* L_FR_CMR_Ln_01, L_FR_CMR_Ln_03 */
    acan_mask = BIT(A_FR_CMR_Ln_01_50ms_POS) | BIT(A_FR_CMR_Ln_03_50ms_POS);
    if (can_timeout_fault[L_FR_CMR_0] & acan_mask) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,0,0,0,0,1,1,1},
                .scc = {0,0,1,1},
                .sccml = {0},
                .nscc = {0,1},
                .lfa = {1,1},
                .hda = {1,0,1,1},
                .bca = {1,0,0,0},
                .sea = {0},
                .rcca = {0,0},
                .warning = {3,0,0,0,HDA_LFA_FAULT,5,1},
            }
        );
    }

    /* L_FR_CMR_Ln_02 */
    acan_mask = BIT(A_FR_CMR_Ln_02_50ms_POS);
    if (can_timeout_fault[L_FR_CMR_0] & acan_mask) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,0,0,0,0,1,1,0},
                .scc = {0,0,0,0},
                .sccml = {0},
                .nscc = {0,1},
                .lfa = {0,0},
                .hda = {0,0,0,1},
                .bca = {1,0,0,0},
                .sea = {0},
                .rcca = {0,0},
                .warning = {3,0,0,0,NO_FAULT,5,1},
            }
        );
    }

    /* L_FR_CMR_Genrl_01 */
    acan_mask = BIT(A_FR_CMR_Genrl_01_30ms_POS);
    if (can_timeout_fault[L_FR_CMR_0] & acan_mask) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,1,1,1,1,1,1,1,1},
                .scc = {0,0,1,1},
                .sccml = {0},
                .nscc = {0,1},
                .lfa = {1,1},
                .hda = {1,0,1,1},
                .bca = {1,0,0,0},
                .sea = {0},
                .rcca = {0,0},
                .warning = {3,0,0,0,HDA_LFA_FAULT,5,1},
            }
        );
    }

    /* A_ADAS_CMD_30, A_FR_CMR_Ctrl_01*/
    acan_mask = BIT(A_FR_CMR_Ctrl_01_10ms_POS);
    if (can_timeout_fault[L_FR_CMR_0] & acan_mask) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,0,0,0,0,1,1,1},
                .scc = {0,0,0,0},
                .sccml = {0},
                .nscc = {0,0},
                .lfa = {1,1},
                .hda = {1,0,1,1},
                .bca = {1,0,0,0},
                .sea = {0},
                .rcca = {0,0},
                .warning = {3,0,0,0,HDA_LFA_FAULT,5,1},
            }
        );
    }
}

void FS_Clear_CANTimeout(void)
{
    memset(can_timeout_tick, 0, sizeof(can_timeout_tick));
    memset(can_timeout_fault, 0 , sizeof(can_timeout_fault));

    /* Indirect timeout clear */
#if CCAN == CANFD
    memset(&MDPS_01_indir, 0, sizeof(MDPS_01_indir));
#elif CCAN == HSCAN
    memset(&TCU11_indir, 0, sizeof(TCU11_indir));
    memset(&EMS11_indir, 0, sizeof(EMS11_indir));
    memset(&EMS_H12_indir, 0, sizeof(EMS_H12_indir));
    memset(&NAVI_V2_POS_indir, 0, sizeof(NAVI_V2_POS_indir));
#endif /* CCAN */
}
