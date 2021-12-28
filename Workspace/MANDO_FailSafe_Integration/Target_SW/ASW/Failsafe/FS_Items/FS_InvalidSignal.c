/*
 * Author: Insub Song (insub.song@halla.com)
 * Date  : 2019.02.01
 */


#include "Rte_SWC_DiagnosticMonitor.h"
#include "App_NvM_Ram.h"

#include "SWC_Failsafe.h"
#include "FS_InvalidSignal.h"
#include "DRV_par.h"

#pragma noclear
boolean is_navi_boot;
uint16 navi_boot_tick;
#pragma noclear restore

uint8 rdr_fail_flag = 0;
extern uint8 rdr_another_fail_flag;
extern boolean chk_rdr_inhibit;

#if CCAN == CANFD
#if VEH_TYPE == NORMAL
static sigerr_t ems[EMS_ITEM_NUM];
static sigerr_t tcu[TCU_ITEM_NUM];
#elif VEH_TYPE == EV
static sigerr_t vcu[VCU_ITEM_NUM];
#elif VEH_TYPE == HEV
static sigerr_t ems[EMS_ITEM_NUM];
static sigerr_t hcu[HCU_ITEM_NUM];
static sigerr_t htcu[HTCU_ITEM_NUM];
#endif /* VEH_TYPE */
static sigerr_t bcm[BCM_ITEM_NUM];
static sigerr_t clu[CLU_ITEM_NUM];
static sigerr_t esc[ESC_ITEM_NUM];
static sigerr_t icu[ICU_ITEM_NUM];
static sigerr_t mdps[MDPS_ITEM_NUM];
static sigerr_t sas[SAS_ITEM_NUM];
static sigerr_t sbcm[SBCM_ITEM_NUM];
static sigerr_t yrs[YRS_ITEM_NUM];
static sigerr_t swrc[SWRC_ITEM_NUM];
static sigerr_t icsc[ICSC_ITEM_NUM];

#elif CCAN == HSCAN
static sigerr_t ems[EMS_ITEM_NUM];
static sigerr_t tcu[TCU_ITEM_NUM];
static sigerr_t cgw[CGW_ITEM_NUM];
static sigerr_t clu[CLU_ITEM_NUM];
static sigerr_t esc[ESC_ITEM_NUM];
static sigerr_t mdps[MDPS_ITEM_NUM];
static sigerr_t sas[SAS_ITEM_NUM];
#endif /* CCAN */
static sigerr_t navi[NAVI_ITEM_NUM];
static sigerr_t fr_cmr[FR_CMR_ITEM_NUM];
static sigerr_t fr_c_rdr[FR_C_RDR_ITEM_NUM];
sigerr_t fr_rdr[FR_RDR_ITEM_NUM];

boolean is_coding_navi_mismatch(void) { return navi[NAVI_C174686_0].fault; }

boolean is_valid_ems(void)
{
#if CCAN == CANFD
#if VEH_TYPE == NORMAL
    return !(ems[EMS_C161386_1].fault || ems[EMS_C161386_2].fault);
#elif VEH_TYPE == EV
    return !vcu[VCU_C161C86_0].fault;
#elif VEH_TYPE == HEV
    return !hcu[HCU_C161C86_0].fault;
#endif /* VEH_TYPE */
#elif CCAN == HSCAN
    return !(ems[EMS_C161386_0].fault || ems[EMS_C161386_1].fault);
#endif /* CCAN */
}

#define ALV_CNT_LIM 0xF
#define MAX_DELTA   10
#define FINAL_XOR   0xFF
#if CCAN == CANFD
#define INIT_VAL    0x00
#elif CCAN == HSCAN /* FIXME: Check the initial value for HSCAN after spec releases*/
#define INIT_VAL    0xFF
#endif
/* Look-up table with polynomial(=0x1D) */
static const uint8 CRC_TABLE[256] = {
    0x00, 0x1D, 0x3A, 0x27, 0x74, 0x69, 0x4E, 0x53, 0xE8, 0xF5, 0xD2, 0xCF, 0x9C, 0x81, 0xA6, 0xBB,
    0xCD, 0xD0, 0xF7, 0xEA, 0xB9, 0xA4, 0x83, 0x9E, 0x25, 0x38, 0x1F, 0x02, 0x51, 0x4C, 0x6B, 0x76,
    0x87, 0x9A, 0xBD, 0xA0, 0xF3, 0xEE, 0xC9, 0xD4, 0x6F, 0x72, 0x55, 0x48, 0x1B, 0x06, 0x21, 0x3C,
    0x4A, 0x57, 0x70, 0x6D, 0x3E, 0x23, 0x04, 0x19, 0xA2, 0xBF, 0x98, 0x85, 0xD6, 0xCB, 0xEC, 0xF1,
    0x13, 0x0E, 0x29, 0x34, 0x67, 0x7A, 0x5D, 0x40, 0xFB, 0xE6, 0xC1, 0xDC, 0x8F, 0x92, 0xB5, 0xA8,
    0xDE, 0xC3, 0xE4, 0xF9, 0xAA, 0xB7, 0x90, 0x8D, 0x36, 0x2B, 0x0C, 0x11, 0x42, 0x5F, 0x78, 0x65,
    0x94, 0x89, 0xAE, 0xB3, 0xE0, 0xFD, 0xDA, 0xC7, 0x7C, 0x61, 0x46, 0x5B, 0x08, 0x15, 0x32, 0x2F,
    0x59, 0x44, 0x63, 0x7E, 0x2D, 0x30, 0x17, 0x0A, 0xB1, 0xAC, 0x8B, 0x96, 0xC5, 0xD8, 0xFF, 0xE2,
    0x26, 0x3B, 0x1C, 0x01, 0x52, 0x4F, 0x68, 0x75, 0xCE, 0xD3, 0xF4, 0xE9, 0xBA, 0xA7, 0x80, 0x9D,
    0xEB, 0xF6, 0xD1, 0xCC, 0x9F, 0x82, 0xA5, 0xB8, 0x03, 0x1E, 0x39, 0x24, 0x77, 0x6A, 0x4D, 0x50,
    0xA1, 0xBC, 0x9B, 0x86, 0xD5, 0xC8, 0xEF, 0xF2, 0x49, 0x54, 0x73, 0x6E, 0x3D, 0x20, 0x07, 0x1A,
    0x6C, 0x71, 0x56, 0x4B, 0x18, 0x05, 0x22, 0x3F, 0x84, 0x99, 0xBE, 0xA3, 0xF0, 0xED, 0xCA, 0xD7,
    0x35, 0x28, 0x0F, 0x12, 0x41, 0x5C, 0x7B, 0x66, 0xDD, 0xC0, 0xE7, 0xFA, 0xA9, 0xB4, 0x93, 0x8E,
    0xF8, 0xE5, 0xC2, 0xDF, 0x8C, 0x91, 0xB6, 0xAB, 0x10, 0x0D, 0x2A, 0x37, 0x64, 0x79, 0x5E, 0x43,
    0xB2, 0xAF, 0x88, 0x95, 0xC6, 0xDB, 0xFC, 0xE1, 0x5A, 0x47, 0x60, 0x7D, 0x2E, 0x33, 0x14, 0x09,
    0x7F, 0x62, 0x45, 0x58, 0x0B, 0x16, 0x31, 0x2C, 0x97, 0x8A, 0xAD, 0xB0, 0xE3, 0xFE, 0xD9, 0xC4
};

static enum {
    E2E_PASS = 0,
    E2E_FAIL = 1,
};

static inline uint8 check_ac(uint8 *prev, uint8 *curr, uint8 max_ac)
{
    uint8 ret = E2E_FAIL;
    uint8 max_delta, delta = (*curr - *prev + (max_ac + 1)) % (max_ac + 1);

    switch (max_ac) {
    case 3: // 2-bit
        max_delta = 2;
        break;
    case 7: // 3-bit
        max_delta = 4;
        break;
    case 14: // 4-bit
    case 15:
    default:
        max_delta = 10;
        break;
    }

    if ((delta > 0 && delta <= max_delta) || (*prev == (max_ac + 1)))
        ret = E2E_PASS;
    *prev = *curr;

    return ret;
}

static uint8 calc_crc(uint8 *ptr, uint8 dlc)
{
    uint8 crc = INIT_VAL;
    while (dlc--)
        crc = CRC_TABLE[crc ^ *ptr++];
    crc ^= FINAL_XOR;
    return crc;
}

typedef struct {
    uint8 *data_ptr;
    uint8 data_len;
} signal_data_t;

#if CCAN == CANFD
boolean CallOutRx_BCM_02_200ms(void *SignalDataPtr, uint8 status)
{
    uint8 BCM_02_200ms_bytes[9];
    uint8 crc;
    signal_data_t *info = SignalDataPtr;
    memcpy(&BCM_02_200ms_bytes[1], info->data_ptr, info->data_len);
    crc = BCM_02_200ms_bytes[1];
    /* TODO: if BCM_02 ID changed, below ID value should be changed */
    BCM_02_200ms_bytes[0] = 0xE0; /* LOWER */
    BCM_02_200ms_bytes[1] = 0xFB; /* UPPER */
    if(crc != calc_crc(BCM_02_200ms_bytes, 9)) {
        e2e_err_flags[CHASSIS_0] |= BIT(BCM_02_200ms_POS);
    }
    else {
        e2e_err_flags[CHASSIS_0] &= ~BIT(BCM_02_200ms_POS);
    }
    return TRUE;
}

#elif CCAN == HSCAN
uint8 EMS16_bytes[8];
uint8 TCS11_bytes[8];
uint8 TCS13_bytes[8];
boolean CallOutRx_EMS16(void *SignalDataPtr, uint8 status)
{
    signal_data_t *info = SignalDataPtr;
    memcpy(EMS16_bytes, info->data_ptr, info->data_len);

    static uint8 EMS16_AlvCnt_prev = 4;
    uint8 EMS16_AlvCnt = (EMS16_bytes[7] & 0x30) >> 4,
          EMS16_Checksum = EMS16_bytes[7] & 0xF;

    uint8 chksum = 0; // 4-bit checksum
    for (int i = 0; i <= 6; i++)
        chksum += EMS16_bytes[i] + (EMS16_bytes[i] >> 4);
    chksum += (EMS16_bytes[7] >> 4);
    chksum = (0x10 - (chksum & 0xF)) & 0xF;

    if (check_ac(&EMS16_AlvCnt_prev, &EMS16_AlvCnt, 3) ||
        (chksum != EMS16_Checksum))
        e2e_err_flags[CHASSIS_0] |= BIT(EMS16_POS);
    else
        e2e_err_flags[CHASSIS_0] &= ~BIT(EMS16_POS);

    return TRUE;
}

boolean CallOutRx_TCS11(void *SignalDataPtr, uint8 status)
{
    signal_data_t *info = SignalDataPtr;
    memcpy(TCS11_bytes, info->data_ptr, info->data_len);

    static uint8 TCS11_AlvCnt_prev = 16;
    uint8 TCS11_AlvCnt = (TCS11_bytes[6] & 0xF0) >> 4,
          TCS11_Checksum = TCS11_bytes[7];

    uint8 chksum = 0;
    for (int i = 0; i <= 6; i++)
        chksum += TCS11_bytes[i];

    if (check_ac(&TCS11_AlvCnt_prev, &TCS11_AlvCnt, 15) ||
        (chksum != TCS11_Checksum))
        e2e_err_flags[CHASSIS_0] |= BIT(TCS11_POS);
    else
        e2e_err_flags[CHASSIS_0] &= ~BIT(TCS11_POS);

    return TRUE;
}

boolean CallOutRx_TCS13(void *SignalDataPtr, uint8 status)
{
    signal_data_t *info = SignalDataPtr;
    memcpy(TCS13_bytes, info->data_ptr, info->data_len);

    static uint8 TCS13_AlvCnt_prev = 8;
    uint8 TCS13_AlvCnt = (TCS13_bytes[1] & 0xE0) >> 5,
          TCS13_Checksum = TCS13_bytes[6] & 0xF;

    uint8 chksum = 0; // 4-bit checksum
    for (int i = 0; i <= 5; i++)
        chksum += TCS13_bytes[i] + (TCS13_bytes[i] >> 4);
    chksum += (TCS13_bytes[6] >> 4);
    chksum = (0x10 - (chksum & 0xF)) & 0xF;

    if (check_ac(&TCS13_AlvCnt_prev, &TCS13_AlvCnt, 7) ||
        (chksum != TCS13_Checksum))
        e2e_err_flags[CHASSIS_0] |= BIT(TCS13_POS);
    else
        e2e_err_flags[CHASSIS_0] &= ~BIT(TCS13_POS);

    return TRUE;
}

void UpdateRx_E2E_P_STS(MsgGr_CCAN_P_STS *P_STS)
{
    if (!is_updated(CHASSIS_0, P_STS_POS))
        return;

    static uint8 P_STS_AlvCnt_prev = 16;

    if (check_ac(&P_STS_AlvCnt_prev, &P_STS->P_STS_AliveCounter, 15))
        e2e_err_flags[CHASSIS_0] |= BIT(P_STS_POS);
    else
        e2e_err_flags[CHASSIS_0] &= ~BIT(P_STS_POS);
}

void UpdateRx_E2E_CLU11(MsgGr_CCAN_CLU11 *CLU11)
{
    if (!is_updated(CHASSIS_0, CLU11_POS))
        return;

    static uint8 CLU11_AlvCnt_prev = 16;

    if (check_ac(&CLU11_AlvCnt_prev, &CLU11->CF_Clu_AliveCnt1, 15))
        e2e_err_flags[CHASSIS_0] |= BIT(CLU11_POS);
    else
        e2e_err_flags[CHASSIS_0] &= ~BIT(CLU11_POS);
}

void UpdateRx_E2E_SAS11(MsgGr_CCAN_SAS11 *SAS11)
{
    if (!is_updated(CHASSIS_0, SAS11_POS))
        return;

    static uint8 SAS11_AlvCnt_prev = 16;

    uint8 bytes[4] = {
        [0] = SAS11->SAS_Angle & 0xFF,
        [1] = SAS11->SAS_Angle >> 8,
        [2] = SAS11->SAS_Speed,
        [3] = SAS11->SAS_Stat,
    };

    uint8 chksum = 0;
    for (int i = 0; i <= 3; i++)
        chksum ^= bytes[i];
    chksum = (chksum >> 4) ^ (chksum & 0xF) ^ (SAS11->MsgCount);

    if (check_ac(&SAS11_AlvCnt_prev, &SAS11->MsgCount, 15) ||
        (chksum != SAS11->CheckSum))
        e2e_err_flags[CHASSIS_0] |= BIT(SAS11_POS);
    else
        e2e_err_flags[CHASSIS_0] &= ~BIT(SAS11_POS);
}

void UpdateTx_E2E_ADAS_CMD_10_1_20ms(MsgGr_CCAN_ADAS_CMD_10_1_20ms *ADAS_CMD_10_1_20ms)
{
    ADAS_CMD_10_1_20ms->ADAS_CMD_AlvCnt10_1Val = ++ADAS_CMD_10_1_20ms->ADAS_CMD_AlvCnt10_1Val % ALV_CNT_LIM;

    uint8 bytes[7] = {
        [0] = ADAS_CMD_10_1_20ms->ADAS_CMD_AlvCnt10_1Val << 4,
        [1] = ADAS_CMD_10_1_20ms->FCA_StbltActvReq << 5 | ADAS_CMD_10_1_20ms->FCA_WrngLvlSta << 3 | ADAS_CMD_10_1_20ms->FCA_HydrlcBstAsstReq << 1 | ADAS_CMD_10_1_20ms->FCA_PrefillActvReq,
        [2] = ADAS_CMD_10_1_20ms->FCA_DclReqVal & 0xFF,
        [3] = ADAS_CMD_10_1_20ms->FCA_PartialActvReq << 5 | ADAS_CMD_10_1_20ms->FCA_VehStpReq << 4 | ADAS_CMD_10_1_20ms->FCA_FullActvReq << 3 | ADAS_CMD_10_1_20ms->FCA_SysFlrSta,
        [5] = ADAS_CMD_10_1_20ms->FCA_WrngTrgtDis << 7,
        [6] = ADAS_CMD_10_1_20ms->FCA_WrngSndSta << 6 | ADAS_CMD_10_1_20ms->ADAS_DRV_FCA_Plus_Sta << 4 | ADAS_CMD_10_1_20ms->FCA_WrngTrgtDis >> 1,
    };
    ADAS_CMD_10_1_20ms->ADAS_CMD_Crc10_1Val = calc_crc(bytes, sizeof(bytes));
}

void UpdateTx_E2E_ADAS_CMD_10_2_200ms(MsgGr_CCAN_ADAS_CMD_10_2_200ms *ADAS_CMD_10_2_200ms)
{
    ADAS_CMD_10_2_200ms->ADAS_CMD_AlvCnt10_2Val = ++ADAS_CMD_10_2_200ms->ADAS_CMD_AlvCnt10_2Val % ALV_CNT_LIM;

    uint8 bytes[7] = {
        [0] = ADAS_CMD_10_2_200ms->ADAS_CMD_AlvCnt10_2Val << 4,
        [1] = ADAS_CMD_10_2_200ms->Nmode_FCAOff_Sta << 6 | ADAS_CMD_10_2_200ms->FCA_SnstvtyModRetVal << 3 | ADAS_CMD_10_2_200ms->FCA_OnOffEquipSta,
        [2] = ADAS_CMD_10_2_200ms->FCA_Jnctn_OnOffEquipSta,
#if 1 /* FIXME: Remove after resolving padding issue */
        [5] = 0xFF,
        [6] = 0xFF,
#endif
    };
    ADAS_CMD_10_2_200ms->ADAS_CMD_Crc10_2Val = calc_crc(bytes, sizeof(bytes));
}

void UpdateTx_E2E_ADAS_CMD_20_1_20ms(MsgGr_CCAN_ADAS_CMD_20_1_20ms *ADAS_CMD_20_1_20ms)
{
    ADAS_CMD_20_1_20ms->ADAS_CMD_AlvCnt20_1Val = ++ADAS_CMD_20_1_20ms->ADAS_CMD_AlvCnt20_1Val % ALV_CNT_LIM;

    uint8 bytes[7] = {
        [0] = ADAS_CMD_20_1_20ms->ADAS_CMD_AlvCnt20_1Val << 4,
        [1] = ADAS_CMD_20_1_20ms->SCC_AccelReqVal & 0xFF,
        [2] = (ADAS_CMD_20_1_20ms->SCC_AccelReqRawVal << 3 | ADAS_CMD_20_1_20ms->SCC_AccelReqVal >> 8) & 0xFF,
        [3] = (ADAS_CMD_20_1_20ms->SCC_JrkUppLimVal << 6 | ADAS_CMD_20_1_20ms->SCC_AccelReqRawVal >> 5) & 0xFF,
        [4] = (ADAS_CMD_20_1_20ms->SCC_JrkLwrLimVal << 5 | ADAS_CMD_20_1_20ms->SCC_JrkUppLimVal >> 2) & 0xFF,
        [5] = (ADAS_CMD_20_1_20ms->SCC_AccelLimBandUppVal << 4 | ADAS_CMD_20_1_20ms->SCC_JrkLwrLimVal >> 3) & 0xFF,
        [6] = ADAS_CMD_20_1_20ms->SCC_AccelLimBandLwrVal << 2 | ADAS_CMD_20_1_20ms->SCC_AccelLimBandUppVal >> 4,
    };
    ADAS_CMD_20_1_20ms->ADAS_CMD_Crc20_1Val = calc_crc(bytes, sizeof(bytes));
}

void UpdateTx_E2E_ADAS_CMD_20_2_20ms(MsgGr_CCAN_ADAS_CMD_20_2_20ms *ADAS_CMD_20_2_20ms)
{
    ADAS_CMD_20_2_20ms->ADAS_CMD_AlvCnt20_2Val = ++ADAS_CMD_20_2_20ms->ADAS_CMD_AlvCnt20_2Val % ALV_CNT_LIM;

    uint8 bytes[7] = {
        [0] = ADAS_CMD_20_2_20ms->ADAS_CMD_AlvCnt20_2Val << 4,
        [1] = ADAS_CMD_20_2_20ms->SCC_ObjDstVal & 0xFF,
        [2] = ADAS_CMD_20_2_20ms->SCC_TakeoverReq << 7 | ADAS_CMD_20_2_20ms->SCC_OpSta << 4 | ADAS_CMD_20_2_20ms->SCC_MainOnOffSta << 3 | ADAS_CMD_20_2_20ms->SCC_ObjDstVal >> 8,
        [3] = (ADAS_CMD_20_2_20ms->SCC_HeadwayDstSetVal << 5 | ADAS_CMD_20_2_20ms->SCC_DrvAlrtDis << 3 | ADAS_CMD_20_2_20ms->SCC_InfoDis) & 0xFF,
        [4] = (ADAS_CMD_20_2_20ms->SCC_TrgtSpdSetVal << 1 | ADAS_CMD_20_2_20ms->SCC_HeadwayDstSetVal >> 3) & 0xFF,
        [5] = (ADAS_CMD_20_2_20ms->SCC_TrgtDstVal << 2 | ADAS_CMD_20_2_20ms->SCC_VehStpReq << 1 | ADAS_CMD_20_2_20ms->SCC_TrgtSpdSetVal >> 7) & 0xFF,
        [6] = ADAS_CMD_20_2_20ms->SCC_TrgtDstVal >> 6,
    };
    ADAS_CMD_20_2_20ms->ADAS_CMD_Crc20_2Val = calc_crc(bytes, sizeof(bytes));
}

void UpdateTx_E2E_ADAS_CMD_20_3_20ms(MsgGr_CCAN_ADAS_CMD_20_3_20ms *ADAS_CMD_20_3_20ms)
{
    ADAS_CMD_20_3_20ms->ADAS_CMD_AlvCnt20_3Val = ++ADAS_CMD_20_3_20ms->ADAS_CMD_AlvCnt20_3Val % ALV_CNT_LIM;

    uint8 bytes[7] = {
        [0] = ADAS_CMD_20_3_20ms->ADAS_CMD_AlvCnt20_3Val << 4,
        [1] = ADAS_CMD_20_3_20ms->SCC_ObjRelSpdVal & 0xFF,
        [2] = (ADAS_CMD_20_3_20ms->SCC_ObjLatPosVal << 4 | ADAS_CMD_20_3_20ms->SCC_ObjRelSpdVal >> 8) & 0xFF,
        [3] = ADAS_CMD_20_3_20ms->SCC_SysFlrSta << 5 | ADAS_CMD_20_3_20ms->SCC_ObjLatPosVal >> 4,
        [4] = (ADAS_CMD_20_3_20ms->SCC_NSCCOpSta << 7) & 0xFF,
        [5] = (ADAS_CMD_20_3_20ms->SCC_SnstvtyModRetVal << 6 | ADAS_CMD_20_3_20ms->SCC_ObjSta << 3 | ADAS_CMD_20_3_20ms->SCC_NSCCOnOffSta << 1 | ADAS_CMD_20_3_20ms->SCC_NSCCOpSta >> 1) & 0xFF,
        [6] = ADAS_CMD_20_3_20ms->SCC_NSCCInfoPUDis << 5 | ADAS_CMD_20_3_20ms->SCC_NSCCAutoSetSpdUpdtSta << 3 | ADAS_CMD_20_3_20ms->SCC_NSCCAutoSetSpdSta << 1 | ADAS_CMD_20_3_20ms->SCC_SnstvtyModRetVal >> 2,
    };
    ADAS_CMD_20_3_20ms->ADAS_CMD_Crc20_3Val = calc_crc(bytes, sizeof(bytes));
}

void UpdateTx_E2E_ADAS_CMD_21_1_50ms(MsgGr_CCAN_ADAS_CMD_21_1_50ms *ADAS_CMD_21_1_50ms)
{
    ADAS_CMD_21_1_50ms->ADAS_CMD_AlvCnt21_1Val = ++ADAS_CMD_21_1_50ms->ADAS_CMD_AlvCnt21_1Val % ALV_CNT_LIM;

    uint8 bytes[7] = {
        [0] = ADAS_CMD_21_1_50ms->ADAS_CMD_AlvCnt21_1Val << 4,
        [1] = ADAS_CMD_21_1_50ms->SCCML_LearningChar1Sta << 5 | ADAS_CMD_21_1_50ms->SCCMode_OptUsmSta,
        [2] = ADAS_CMD_21_1_50ms->SCCML_LearningChar3Sta << 3 | ADAS_CMD_21_1_50ms->SCCML_LearningChar2Sta,
    };
    ADAS_CMD_21_1_50ms->ADAS_CMD_Crc21_1Val = calc_crc(bytes, sizeof(bytes));
}

void UpdateTx_E2E_ADAS_CMD_30_1_10ms(MsgGr_CCAN_ADAS_CMD_30_1_10ms *ADAS_CMD_30_1_10ms)
{
    ADAS_CMD_30_1_10ms->ADAS_CMD_Crc30_1Val = 0xFF;
    ADAS_CMD_30_1_10ms->ADAS_CMD_AlvCnt30_1Val = ++ADAS_CMD_30_1_10ms->ADAS_CMD_AlvCnt30_1Val % 16;

    uint8 bytes[8] = {
        [0] = 0xFF, // ADAS_CMD_30_1_10ms->ADAS_CMD_Crc30_1Val,
        [1] = (ADAS_CMD_30_1_10ms->LKA_RHLnWrnSta << 6) | (ADAS_CMD_30_1_10ms->LKA_LHLnWrnSta << 4) | (ADAS_CMD_30_1_10ms->LKA_SysWrn),
        [2] = (ADAS_CMD_30_1_10ms->ADAS_StrTqReqVal & 0xFF),
        [3] = (ADAS_CMD_30_1_10ms->LKA_RcgSta << 6) | (ADAS_CMD_30_1_10ms->LKA_HndsoffSnd << 5) | (ADAS_CMD_30_1_10ms->LKA_ToiFltSta << 4) | (ADAS_CMD_30_1_10ms->LKA_ActToiSta << 3) | (ADAS_CMD_30_1_10ms->ADAS_StrTqReqVal >> 8),
        [4] = (ADAS_CMD_30_1_10ms->ADAS_CMD_AlvCnt30_1Val << 4) | (ADAS_CMD_30_1_10ms->LKA_SysIndReq),
        [5] = ADAS_CMD_30_1_10ms->ADAS_Damping_Gain,
        [6] = 0x00, // ADAS_CMD_30_1_10ms->ADAS_CMD_Chksum30_1Val,
        [7] = ADAS_CMD_30_1_10ms->FCA_ESA_CtrlSta << 5,
    };

    uint8 chksum = 0;
    for (int i = 0; i < 8; i++)
        chksum += bytes[i];

    ADAS_CMD_30_1_10ms->ADAS_CMD_Chksum30_1Val = chksum;
}

void UpdateTx_E2E_ADAS_CMD_30_2_20ms(MsgGr_CCAN_ADAS_CMD_30_2_20ms *ADAS_CMD_30_2_20ms)
{
    ADAS_CMD_30_2_20ms->ADAS_CMD_AlvCnt30_2Val = ++ADAS_CMD_30_2_20ms->ADAS_CMD_AlvCnt30_2Val % ALV_CNT_LIM;

    uint8 bytes[7] = {
        [0] = ADAS_CMD_30_2_20ms->ADAS_CMD_AlvCnt30_2Val << 4,
        [1] = (ADAS_CMD_30_2_20ms->FCA_LS_WrnSta << 6 | ADAS_CMD_30_2_20ms->FCA_LO_WrnSta << 3) & 0xFF,
        [2] = (ADAS_CMD_30_2_20ms->FCA_ESA_WrnSta << 6 | ADAS_CMD_30_2_20ms->FCA_LS_WrnSta >> 2) & 0xFF,
        [3] = ADAS_CMD_30_2_20ms->LKA_UsmMod << 4 | ADAS_CMD_30_2_20ms->LKA_OptUsmSta << 1 | ADAS_CMD_30_2_20ms->FCA_ESA_WrnSta >> 2,
    };
    ADAS_CMD_30_2_20ms->ADAS_CMD_Crc30_2Val = calc_crc(bytes, sizeof(bytes));
}

void UpdateTx_E2E_ADAS_CMD_31_1_50ms(MsgGr_CCAN_ADAS_CMD_31_1_50ms *ADAS_CMD_31_1_50ms)
{
    ADAS_CMD_31_1_50ms->ADAS_CMD_AlvCnt31_1Val = ++ADAS_CMD_31_1_50ms->ADAS_CMD_AlvCnt31_1Val % ALV_CNT_LIM;

    uint8 bytes[7] = {
        [0] = ADAS_CMD_31_1_50ms->ADAS_CMD_AlvCnt31_1Val << 4,
        [1] = ADAS_CMD_31_1_50ms->HDA_InfoPUDis << 5 | ADAS_CMD_31_1_50ms->HDA_CntrlModSta << 3 | ADAS_CMD_31_1_50ms->HDA_OptUsmSta,
        [2] = ADAS_CMD_31_1_50ms->HDA_InfoPUDis1 << 3 | ADAS_CMD_31_1_50ms->HDA_LFA_SymSta << 1 | ADAS_CMD_31_1_50ms->HDA_LFA_WrnSnd,
    };
    ADAS_CMD_31_1_50ms->ADAS_CMD_Crc31_1Val = calc_crc(bytes, sizeof(bytes));
}

void UpdateTx_E2E_ADAS_CMD_32_1_50ms(MsgGr_CCAN_ADAS_CMD_32_1_50ms *ADAS_CMD_32_1_50ms)
{
    ADAS_CMD_32_1_50ms->ADAS_CMD_AlvCnt32_1Val = ++ADAS_CMD_32_1_50ms->ADAS_CMD_AlvCnt32_1Val % ALV_CNT_LIM;

    uint8 bytes[7] = {
        [0] = ADAS_CMD_32_1_50ms->ADAS_CMD_AlvCnt32_1Val << 4,
        [1] = (ADAS_CMD_32_1_50ms->HDA_LeftLCAvailSta << 6 | ADAS_CMD_32_1_50ms->HDA_LCFuncSta << 3 | ADAS_CMD_32_1_50ms->HDA_LCFuncOptUsmSta) & 0xFF,
        [2] = (ADAS_CMD_32_1_50ms->HDA_FrntLeftVehLongPos << 7 | ADAS_CMD_32_1_50ms->HDA_PathSta << 4 | ADAS_CMD_32_1_50ms->HDA_RightLCAvailSta << 1 | ADAS_CMD_32_1_50ms->HDA_LeftLCAvailSta >> 2) & 0xFF,
        [3] = ADAS_CMD_32_1_50ms->HDA_FrntLeftVehLongPos >> 1 & 0xFF,
        [4] = (ADAS_CMD_32_1_50ms->HDA_FrntLeftVehLatPos << 2 | ADAS_CMD_32_1_50ms->HDA_FrntLeftVehLongPos >> 9) & 0xFF,
        [5] = ADAS_CMD_32_1_50ms->HDA_FrntLeftVehSta << 2 | ADAS_CMD_32_1_50ms->HDA_FrntLeftVehLatPos >> 6,
    };
    ADAS_CMD_32_1_50ms->ADAS_CMD_Crc32_1Val = calc_crc(bytes, sizeof(bytes));
}

void UpdateTx_E2E_ADAS_CMD_32_2_50ms(MsgGr_CCAN_ADAS_CMD_32_2_50ms *ADAS_CMD_32_2_50ms)
{
    ADAS_CMD_32_2_50ms->ADAS_CMD_AlvCnt32_2Val = ++ADAS_CMD_32_2_50ms->ADAS_CMD_AlvCnt32_2Val % ALV_CNT_LIM;

    uint8 bytes[7] = {
        [0] = ADAS_CMD_32_2_50ms->ADAS_CMD_AlvCnt32_2Val << 4,
        [1] = ADAS_CMD_32_2_50ms->HDA_FrntRightVehLongPos & 0xFF,
        [2] = (ADAS_CMD_32_2_50ms->HDA_FrntRightVehLatPos << 3 | ADAS_CMD_32_2_50ms->HDA_FrntRightVehLongPos >> 8) & 0xFF,
        [3] = ADAS_CMD_32_2_50ms->HDA_FrntRightVehSta << 3 | ADAS_CMD_32_2_50ms->HDA_FrntRightVehLatPos >> 5,
    };
    ADAS_CMD_32_2_50ms->ADAS_CMD_Crc32_2Val = calc_crc(bytes, sizeof(bytes));
}

void UpdateTx_E2E_ADAS_CMD_32_3_50ms(MsgGr_CCAN_ADAS_CMD_32_3_50ms *ADAS_CMD_32_3_50ms)
{
    ADAS_CMD_32_3_50ms->ADAS_CMD_AlvCnt32_3Val = ++ADAS_CMD_32_3_50ms->ADAS_CMD_AlvCnt32_3Val % ALV_CNT_LIM;

    uint8 bytes[7] = {
        [0] = ADAS_CMD_32_3_50ms->ADAS_CMD_AlvCnt32_3Val << 4,
        [1] = ADAS_CMD_32_3_50ms->HDA_LeftVehLongPos & 0xFF,
        [2] = (ADAS_CMD_32_3_50ms->HDA_LeftVehLatPos << 1 | ADAS_CMD_32_3_50ms->HDA_LeftVehLongPos >> 8) & 0xFF,
        [3] = (ADAS_CMD_32_3_50ms->HDA_RightVehLongPos << 4 | ADAS_CMD_32_3_50ms->HDA_LeftVehSta << 1 | ADAS_CMD_32_3_50ms->HDA_LeftVehLatPos >> 7) & 0xFF,
        [4] = (ADAS_CMD_32_3_50ms->HDA_RightVehLatPos << 5 | ADAS_CMD_32_3_50ms->HDA_RightVehLongPos >> 4) & 0xFF,
        [5] = ADAS_CMD_32_3_50ms->HDA_RightVehSta << 5 | ADAS_CMD_32_3_50ms->HDA_RightVehLatPos >> 3,
    };
    ADAS_CMD_32_3_50ms->ADAS_CMD_Crc32_3Val = calc_crc(bytes, sizeof(bytes));
}

void UpdateTx_E2E_ADAS_CMD_32_4_50ms(MsgGr_CCAN_ADAS_CMD_32_4_50ms *ADAS_CMD_32_4_50ms)
{
    ADAS_CMD_32_4_50ms->ADAS_CMD_AlvCnt32_4Val = ++ADAS_CMD_32_4_50ms->ADAS_CMD_AlvCnt32_4Val % ALV_CNT_LIM;

    uint8 bytes[7] = {
        [0] = ADAS_CMD_32_4_50ms->ADAS_CMD_AlvCnt32_4Val << 4,
        [1] = ADAS_CMD_32_4_50ms->HDA_InfoPUDis2 << 4,
        [2] = ADAS_CMD_32_4_50ms->HDA_LaneCvrtLvlVal,
        [4] = ADAS_CMD_32_4_50ms->HDA_LeftLineLatPos << 5 & 0xFF,
        [5] = ADAS_CMD_32_4_50ms->HDA_RightLineLatPos << 3 | ADAS_CMD_32_4_50ms->HDA_LeftLineLatPos >> 3,
        [6] = ADAS_CMD_32_4_50ms->HDA_LCTurnSigReq << 3 | ADAS_CMD_32_4_50ms->HDA_LCFuncWrnSnd << 1 | ADAS_CMD_32_4_50ms->HDA_RightLineLatPos >> 5,
    };
    ADAS_CMD_32_4_50ms->ADAS_CMD_Crc32_4Val = calc_crc(bytes, sizeof(bytes));
}

void UpdateTx_E2E_ADAS_DRV_01_1_200ms(MsgGr_CCAN_ADAS_DRV_01_1_200ms *ADAS_DRV_01_1_200ms)
{
    ADAS_DRV_01_1_200ms->ADAS_DRV_AlvCnt01_1Val = ++ADAS_DRV_01_1_200ms->ADAS_DRV_AlvCnt01_1Val % ALV_CNT_LIM;

    uint8 bytes[7] = {
        [0] = ADAS_DRV_01_1_200ms->ADAS_DRV_AlvCnt01_1Val << 4,
        [1] = ADAS_DRV_01_1_200ms->ADAS_DRV_ACANMonSta << 6 | ADAS_DRV_01_1_200ms->ADAS_DRV_CodingSta << 5 |
              ADAS_DRV_01_1_200ms->ADAS_DRV_FailInfoSta << 3 | ADAS_DRV_01_1_200ms->ADAS_DRV_MDPSCtrlSta << 2 |
              ADAS_DRV_01_1_200ms->ADAS_DRV_SCCEquipSta << 1 | ADAS_DRV_01_1_200ms->ADAS_DRV_FCAEquipSta,
    };
    ADAS_DRV_01_1_200ms->ADAS_DRV_Crc01_1Val = calc_crc(bytes, sizeof(bytes));
}
#endif /* for HSCAN */


void update_info(sigerr_t *info, boolean meet_precond, boolean detect_cond, boolean recover_cond, uint16 detect_thr, uint16 recover_thr)
{
    if (!meet_precond)
        info->detect_cnt = 0;

    if (meet_precond && detect_cond) {
        info->recover_cnt = 0;
        if (++info->detect_cnt >= detect_thr) {
            info->detect_cnt = detect_thr;
            info->fault = TRUE;
        }
    } else if (recover_cond) {
        info->detect_cnt = 0;
        if (++info->recover_cnt >= recover_thr) {
            info->recover_cnt = recover_thr;
            info->fault = FALSE;
        }
    }
}

#if CCAN == CANFD
static void update_clu(void)
{
    struct precondition *p = get_precond_ptr();
    boolean meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_eng_run && p->is_not_ecan_busoff;

    uint16 CLU_DisSpdVal = ref_sig.CLU_DisSpdVal;
    uint8 CLU_HDALCFuncOnSetReq = ref_sig.CLU_HDALCFuncOnSetReq;

    if (!is_timeout(CHASSIS_0, CLU_01_20ms_POS)) {
        update_info(&clu[CLU_C165686_0], meet_precond,
                    is_e2e_err(CHASSIS_0, CLU_01_20ms_POS) || (CLU_DisSpdVal == 0x3FF),
                    is_updated(CHASSIS_0, CLU_01_20ms_POS) && !is_e2e_err(CHASSIS_0, CLU_01_20ms_POS) && (CLU_DisSpdVal != 0x3FF),
                    MS2TICK(2000), VALID_CNT_THR);
    }

    if (!is_timeout(CHASSIS_0, CLU_02_100ms_POS)) {
        update_info(&clu[CLU_C165686_1], meet_precond,
                    is_e2e_err(CHASSIS_0, CLU_02_100ms_POS),
                    is_updated(CHASSIS_0, CLU_02_100ms_POS) && !is_e2e_err(CHASSIS_0, CLU_02_100ms_POS),
                    MS2TICK(2000), VALID_CNT_THR);
    }
}

static void update_esc(void)
{
    struct precondition *p = get_precond_ptr();
    boolean meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_eng_run && p->is_not_ecan_busoff;

    uint8 ESC_CylPrsrSta = ref_sig.ESC_CylPrsrSta;
    uint16 ESC_CylPrsrVal = ref_sig.ESC_CylPrsrVal;
    uint8 ABS_DiagSta = ref_sig.ABS_DiagSta;
    uint8 ESC_Sta = ref_sig.ESC_Sta;
    uint8 FCA_EquipSta = ref_sig.FCA_EquipSta;
    uint8 FCA_AvlblSta = ref_sig.FCA_AvlblSta;
    uint8 SCC_EnblReq = ref_sig.SCC_EnblReq;
    uint16 WHL_SpdFLVal = ref_sig.WHL_SpdFLVal;
    uint16 WHL_SpdFRVal = ref_sig.WHL_SpdFRVal;
    uint16 WHL_SpdRLVal = ref_sig.WHL_SpdRLVal;
    uint16 WHL_SpdRRVal = ref_sig.WHL_SpdRRVal;
    uint8 WHL_PlsFLVal = ref_sig.WHL_PlsFLVal;
    uint8 WHL_PlsFRVal = ref_sig.WHL_PlsFRVal;
    uint8 WHL_PlsRLVal = ref_sig.WHL_PlsRLVal;
    uint8 WHL_PlsRRVal = ref_sig.WHL_PlsRRVal;

    if (!is_timeout(CHASSIS_0, ESC_01_10ms_POS) && !is_timeout(CHASSIS_0, ESC_03_20ms_POS) && !is_timeout(CHASSIS_0, WHL_01_10ms_POS)) {
        uint8 WHL_SPD_FAULT_CNT = 0;
        if (WHL_SpdFLVal == 0x3FFF) WHL_SPD_FAULT_CNT++;
        if (WHL_SpdFRVal == 0x3FFF) WHL_SPD_FAULT_CNT++;
        if (WHL_SpdRLVal == 0x3FFF) WHL_SPD_FAULT_CNT++;
        if (WHL_SpdRRVal == 0x3FFF) WHL_SPD_FAULT_CNT++;

        update_info(&esc[ESC_C164286_0], meet_precond,
                    is_e2e_err(CHASSIS_0, ESC_01_10ms_POS) || is_e2e_err(CHASSIS_0, ESC_03_20ms_POS) || is_e2e_err(CHASSIS_0, WHL_01_10ms_POS) || (ESC_CylPrsrSta == 0 && ESC_CylPrsrVal == 0xFFF) || WHL_SPD_FAULT_CNT >= 2,
                    is_updated(CHASSIS_0, ESC_03_20ms_POS) && !is_e2e_err(CHASSIS_0, ESC_01_10ms_POS) && !is_e2e_err(CHASSIS_0, ESC_03_20ms_POS) && !is_e2e_err(CHASSIS_0, WHL_01_10ms_POS) && (ESC_CylPrsrSta == 1 && ESC_CylPrsrVal != 0xFFF) && WHL_SPD_FAULT_CNT <= 1,
                    MS2TICK(100), VALID_CNT_THR);
    }

    if (!is_timeout(CHASSIS_0, ABS_ESC_01_10ms_POS) && !is_timeout(CHASSIS_0, ESC_03_20ms_POS)) {
        update_info(&esc[ESC_C164286_1], meet_precond,
                    FCA_EquipSta == 0 || (FCA_AvlblSta == 1 && ABS_DiagSta == 0) || FCA_AvlblSta == 2,
                    is_updated(CHASSIS_0, ESC_03_20ms_POS) && FCA_EquipSta == 1 && FCA_AvlblSta == 0,
                    MS2TICK(500), VALID_CNT_THR);
    }

    if (!is_timeout(CHASSIS_0, ABS_ESC_01_10ms_POS) && !is_timeout(CHASSIS_0, ESC_03_20ms_POS)) {
        update_info(&esc[ESC_NA_0], meet_precond,
                    FCA_AvlblSta == 1 && ABS_DiagSta == 1,
                    is_updated(CHASSIS_0, ESC_03_20ms_POS) && FCA_AvlblSta == 0,
                    MS2TICK(500), VALID_CNT_THR);
    }

    if (!is_timeout(CHASSIS_0, ESC_03_20ms_POS)) {
        update_info(&esc[ESC_C16B881_0], meet_precond,
                    FCA_AvlblSta == 3,
                    is_updated(CHASSIS_0, ESC_03_20ms_POS) && FCA_AvlblSta == 0,
                    MS2TICK(500), VALID_CNT_THR);
    }

    if (!is_timeout(CHASSIS_0, ABS_ESC_01_10ms_POS) && !is_timeout(CHASSIS_0, ESC_03_20ms_POS)) {
        update_info(&esc[ESC_C136081_0], meet_precond,
                    (SCC_EnblReq == 1 && ABS_DiagSta == 0) || SCC_EnblReq == 2,
                    is_updated(CHASSIS_0, ESC_03_20ms_POS) && SCC_EnblReq == 0,
                    MS2TICK(500), VALID_CNT_THR);
    }

    if (!is_timeout(CHASSIS_0, ABS_ESC_01_10ms_POS) && !is_timeout(CHASSIS_0, ESC_03_20ms_POS)) {
        update_info(&esc[ESC_NA_1], meet_precond,
                    SCC_EnblReq == 1 && ABS_DiagSta == 1,
                    is_updated(CHASSIS_0, ESC_03_20ms_POS) && SCC_EnblReq == 0,
                    MS2TICK(500), VALID_CNT_THR);
    }

    if (!is_timeout(CHASSIS_0, ESC_03_20ms_POS)) {
        update_info(&esc[ESC_C163881_0], meet_precond,
                    SCC_EnblReq == 3,
                    is_updated(CHASSIS_0, ESC_03_20ms_POS) && SCC_EnblReq == 0,
                    MS2TICK(500), VALID_CNT_THR);
    }

    if (!is_timeout(CHASSIS_0, ABS_ESC_01_10ms_POS)) {
        update_info(&esc[ESC_C164282_0], meet_precond,
                    is_e2e_err(CHASSIS_0, ABS_ESC_01_10ms_POS),
                    is_updated(CHASSIS_0, ABS_ESC_01_10ms_POS) && !is_e2e_err(CHASSIS_0, ABS_ESC_01_10ms_POS),
                    MS2TICK(500), VALID_CNT_THR);
    }

    if (!is_timeout(CHASSIS_0, ESC_01_10ms_POS)) {
        update_info(&esc[ESC_C164286_2], meet_precond,
                    ESC_Sta == 0xF,
                    is_updated(CHASSIS_0, ESC_01_10ms_POS) && ESC_Sta != 0xF,
                    MS2TICK(100), 1);
    }

    if (!is_timeout(CHASSIS_0, WHL_01_10ms_POS)) {
        update_info(&esc[ESC_C164281_0], meet_precond,
                    WHL_PlsFLVal == 0xFF || WHL_PlsFRVal == 0xFF || WHL_PlsRLVal == 0xFF || WHL_PlsRRVal == 0xFF,
                    is_updated(CHASSIS_0, WHL_01_10ms_POS) && p->is_norm_vol && 
                    (WHL_PlsFLVal != 0xFF && WHL_PlsFRVal != 0xFF && WHL_PlsRLVal != 0xFF && WHL_PlsRRVal != 0xFF),
                    MS2TICK(500), 1);
    }
    
}

static void update_mdps(void)
{
    struct precondition *p = get_precond_ptr();
    boolean meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_eng_run && p->is_not_ecan_busoff;

    extern MsgGr_E2E_ECANFD_ADAS_CMD_30_10ms MsgGr_ADAS_CMD_30_10ms_IVC_D;

    uint16 MDPS_StrTqSnsrVal = ref_sig.MDPS_StrTqSnsrVal;
    uint8 MDPS_LkaToiActvSta = ref_sig.MDPS_LkaToiActvSta;
    uint8 MDPS_LkaToiUnblSta = ref_sig.MDPS_LkaToiUnblSta;
    uint8 MDPS_LkaToiFltSta = ref_sig.MDPS_LkaToiFltSta;
    uint8 MDPS_LkaFailSta = ref_sig.MDPS_LkaFailSta;
    uint8 MDPS_Type = ref_sig.MDPS_Typ;
    uint8 ADAS_ActToiSta = MsgGr_ADAS_CMD_30_10ms_IVC_D.ADAS_ActToiSta;

    if (!is_timeout(CHASSIS_0, MDPS_01_10ms_POS)) {
        update_info(&mdps[MDPS_C168886_0], meet_precond,
                    is_e2e_err(CHASSIS_0, MDPS_01_10ms_POS) || (MDPS_StrTqSnsrVal == 0x1FFF),
                    is_updated(CHASSIS_0, MDPS_01_10ms_POS) && !is_e2e_err(CHASSIS_0, MDPS_01_10ms_POS) && (MDPS_StrTqSnsrVal != 0x1FFF),
                    MS2TICK(500), VALID_CNT_THR);
    }

    if (!is_timeout(CHASSIS_0, MDPS_01_10ms_POS)) {
        update_info(&mdps[MDPS_C223986_0], meet_precond,
                    MDPS_LkaToiFltSta != 0x0,
                    is_updated(CHASSIS_0, MDPS_01_10ms_POS) && (MDPS_LkaToiFltSta == 0x0),
                    MS2TICK(100), VALID_CNT_THR);
    }
#if CCAN == CANFD
    if (!is_timeout(CHASSIS_0, MDPS_01_10ms_POS)) {
        update_info(&mdps[MDPS_C223986_1], meet_precond,
                    MDPS_Type == 0x7,
                    is_updated(CHASSIS_0, MDPS_01_10ms_POS) && (MDPS_Type != 0x7),
                    MS2TICK(100), VALID_CNT_THR);
    }
#endif /* CCAN */
    /* ADAS_ActToiSta and MDPS_LkaToiActvSta mismatch */
    static uint8 MDPS_LkaToiUnblSta_prev;
    static uint8 MDPS_LkaToiFltSta_prev;
    static uint8 MDPS_LkaFailSta_prev;
    static uint8 rampdown_tick_remain;

    if (!is_timeout(CHASSIS_0, MDPS_01_10ms_POS)) {
        if (ADAS_ActToiSta == 1 && ((MDPS_LkaToiUnblSta_prev == 0 && MDPS_LkaToiUnblSta == 1) ||
                                    (MDPS_LkaToiFltSta_prev == 0 && MDPS_LkaToiFltSta == 1) ||
                                    (MDPS_LkaFailSta_prev == 0 && MDPS_LkaFailSta == 1))) {
            rampdown_tick_remain = MS2TICK(1000);
        } else if (rampdown_tick_remain) {
            rampdown_tick_remain--;
        }

        meet_precond &= (rampdown_tick_remain == 0);
        update_info(&mdps[MDPS_C168886_1], meet_precond,
                    ADAS_ActToiSta != MDPS_LkaToiActvSta,
                    is_updated(CHASSIS_0, MDPS_01_10ms_POS) && (ADAS_ActToiSta == MDPS_LkaToiActvSta),
                    MS2TICK(500), VALID_CNT_THR);
    }

    MDPS_LkaToiUnblSta_prev = MDPS_LkaToiUnblSta;
    MDPS_LkaToiFltSta_prev = MDPS_LkaToiFltSta;
    MDPS_LkaFailSta_prev = MDPS_LkaFailSta;
}

static void update_sas(void)
{
    struct precondition *p = get_precond_ptr();
    boolean meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_eng_run && p->is_not_ecan_busoff;

    sint16 SAS_AnglVal = ref_sig.SAS_AnglVal;
    uint8 SAS_SpdVal = ref_sig.SAS_SpdVal;

    if (!is_timeout(CHASSIS_0, SAS_01_10ms_POS)) {
        update_info(&sas[SAS_C181486_0], meet_precond,
                    is_e2e_err(CHASSIS_0, SAS_01_10ms_POS) || SAS_AnglVal == 0x7FFF || SAS_SpdVal == 0xFF,
                    is_updated(CHASSIS_0, SAS_01_10ms_POS) && !is_e2e_err(CHASSIS_0, SAS_01_10ms_POS) && SAS_AnglVal != 0x7FFF && SAS_SpdVal != 0xFF,
                    MS2TICK(100), VALID_CNT_THR);
    }
}

#if VEH_TYPE == NORMAL
static void update_ems(void)
{
    struct precondition *p = get_precond_ptr();
    boolean meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_not_ecan_busoff;

    uint8 ENG_EngSpdErrSta = ref_sig.ENG_EngSpdErrSta;
    uint8 ENG_EngSta = ref_sig.ENG_EngSta;
    uint16 ENG_AccelPdlVal = ref_sig.ENG_AccelPdlVal;
    uint8 ENG_AppAccelPdlSta = ref_sig.ENG_AppAccelPdlSta;

    if (!is_timeout(CHASSIS_0, EMS_01_10ms_POS)) {
        update_info(&ems[EMS_C161386_0], meet_precond,
                    is_e2e_err(CHASSIS_0, EMS_01_10ms_POS) || ENG_EngSpdErrSta == 1,
                    is_updated(CHASSIS_0, EMS_01_10ms_POS) && !is_e2e_err(CHASSIS_0, EMS_01_10ms_POS) && ENG_EngSpdErrSta == 0,
                    MS2TICK(500), VALID_CNT_THR);
    }

    if (!is_timeout(CHASSIS_0, EMS_02_10ms_POS)) {
        update_info(&ems[EMS_C161386_1], meet_precond,
                    is_e2e_err(CHASSIS_0, EMS_02_10ms_POS) || ENG_EngSta == 7 || ENG_AccelPdlVal == 0x3FF,
                    is_updated(CHASSIS_0, EMS_02_10ms_POS) && !is_e2e_err(CHASSIS_0, EMS_02_10ms_POS) && ENG_EngSta != 7 && ENG_AccelPdlVal != 0x3FF,
                    MS2TICK(500), VALID_CNT_THR);
    }

    if (!is_timeout(CHASSIS_0, EMS_02_10ms_POS)) {
        update_info(&ems[EMS_C161386_2], meet_precond,
                    ENG_AppAccelPdlSta == 3,
                    is_updated(CHASSIS_0, EMS_02_10ms_POS) && ENG_AppAccelPdlSta != 3,
                    MS2TICK(500), VALID_CNT_THR);
    }
}

static void update_tcu(void)
{
    struct precondition *p = get_precond_ptr();
    boolean meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_eng_run && p->is_not_ecan_busoff;

    uint8 TCU_GearSlctDis = ref_sig.TCU_GearSlctDis;

    if (!is_timeout(CHASSIS_0, TCU_01_10ms_POS)) {
        update_info(&tcu[TCU_C164686_0], meet_precond,
                    is_e2e_err(CHASSIS_0, TCU_01_10ms_POS) || TCU_GearSlctDis == 0xF,
                    is_updated(CHASSIS_0, TCU_01_10ms_POS) && !is_e2e_err(CHASSIS_0, TCU_01_10ms_POS) && TCU_GearSlctDis != 0xF,
                    MS2TICK(500), VALID_CNT_THR);
    }
}

#elif VEH_TYPE == EV
static void update_vcu(void)
{
    struct precondition *p = get_precond_ptr();
    boolean meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_not_ecan_busoff;

    uint8 VCU_GearPosSta = ref_sig.VCU_GearPosSta;
    uint8 VCU_AccPedDepVal = ref_sig.VCU_AccPedDepVal;

    if (!is_timeout(CHASSIS_0, VCU_01_10ms_POS)) {
        update_info(&vcu[VCU_C161C86_0], meet_precond,
                    is_e2e_err(CHASSIS_0, VCU_01_10ms_POS) || VCU_GearPosSta == 0xF || VCU_AccPedDepVal == 0xFF,
                    is_updated(CHASSIS_0, VCU_01_10ms_POS) && !is_e2e_err(CHASSIS_0, VCU_01_10ms_POS) && VCU_GearPosSta != 0xF && VCU_AccPedDepVal != 0xFF,
                    MS2TICK(500), VALID_CNT_THR);
    }

    if (!is_timeout(CHASSIS_0, VCU_03_100ms_POS)) {
        update_info(&vcu[VCU_C161C86_1], meet_precond,
                    is_e2e_err(CHASSIS_0, VCU_03_100ms_POS),
                    is_updated(CHASSIS_0, VCU_03_100ms_POS) && !is_e2e_err(CHASSIS_0, VCU_03_100ms_POS),
                    MS2TICK(2000), VALID_CNT_THR);
    }
}

#elif VEH_TYPE == HEV
static void update_ems(void)
{
    struct precondition *p = get_precond_ptr();
    boolean meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_not_ecan_busoff;

    uint16 HEV_AccelPdlVal = ref_sig.HEV_AccelPdlVal;
    uint8 HEV_EngSpdErrSta = ref_sig.HEV_EngSpdErrSta;

    if (!is_timeout(CHASSIS_0, EMS_07_POS) && !is_timeout(CHASSIS_0, EMS_11_POS)) {
        update_info(&ems[EMS_C161386_0], meet_precond,
                    is_e2e_err(CHASSIS_0, EMS_07_POS) || is_e2e_err(CHASSIS_0, EMS_11_POS) || HEV_AccelPdlVal == 0xFF || HEV_EngSpdErrSta == 0x1,
                    is_updated(CHASSIS_0, EMS_07_POS) && !is_e2e_err(CHASSIS_0, EMS_07_POS) && !is_e2e_err(CHASSIS_0, EMS_11_POS) && HEV_AccelPdlVal != 0xFF && HEV_EngSpdErrSta == 0x0,
                    MS2TICK(500), VALID_CNT_THR);
    }
}

static void update_hcu(void)
{
    struct precondition *p = get_precond_ptr();
    boolean meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_not_ecan_busoff;

    uint8 HCU_HevRdySta = ref_sig.HCU_HevRdySta;

    if (!is_timeout(CHASSIS_0, HCU_03_POS)) {
        update_info(&hcu[HCU_C161C86_0], meet_precond,
                    is_e2e_err(CHASSIS_0, HCU_03_POS) || HCU_HevRdySta == 0x3,
                    is_updated(CHASSIS_0, HCU_03_POS) && !is_e2e_err(CHASSIS_0, HCU_03_POS) && HCU_HevRdySta != 0x3,
                    MS2TICK(500), VALID_CNT_THR);
    }

    if (!is_timeout(CHASSIS_0, HCU_05_POS)) {
        update_info(&hcu[HCU_C161C86_1], meet_precond,
                    is_e2e_err(CHASSIS_0, HCU_05_POS),
                    is_updated(CHASSIS_0, HCU_05_POS) && !is_e2e_err(CHASSIS_0, HCU_05_POS),
                    MS2TICK(500), VALID_CNT_THR);
    }
}

static void update_htcu(void)
{
    struct precondition *p = get_precond_ptr();
    boolean meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_eng_run && p->is_not_ecan_busoff;

    uint8 HTCU_GearSlctrDis = ref_sig.HTCU_GearSlctrDis;

    if (!is_timeout(CHASSIS_0, HTCU_04_POS)) {
        update_info(&htcu[HTCU_C164686_0], meet_precond,
                    is_e2e_err(CHASSIS_0, HTCU_04_POS) || HTCU_GearSlctrDis == 0xF,
                    is_updated(CHASSIS_0, HTCU_04_POS) && !is_e2e_err(CHASSIS_0, HTCU_04_POS) && HTCU_GearSlctrDis != 0xF,
                    MS2TICK(500), VALID_CNT_THR);
    }
}
#endif /* VEH_TYPE */

static void update_icu(void)
{
    struct precondition *p = get_precond_ptr();
    boolean meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_eng_run && p->is_not_ecan_busoff;

    uint8 Lamp_RrTrnSigLmpLftOpnSta = ref_sig.Lamp_RrTrnSigLmpLftOpnSta;
    uint8 Lamp_RrTrnSigLmpRtOpnSta = ref_sig.Lamp_RrTrnSigLmpRtOpnSta;
    uint8 Lamp_FrTrnSigLmpLftOpnSta = ref_sig.Lamp_FrTrnSigLmpLftOpnSta;
    uint8 Lamp_FrTrnSigLmpRtOpnSta = ref_sig.Lamp_FrTrnSigLmpRtOpnSta;

    if (!is_timeout(CHASSIS_0, ICU_06_200ms_POS)) {
        update_info(&icu[ICU_C183E86_0], meet_precond,
                    Lamp_RrTrnSigLmpLftOpnSta == 1 || Lamp_RrTrnSigLmpLftOpnSta == 3 || Lamp_RrTrnSigLmpRtOpnSta == 1 || Lamp_RrTrnSigLmpRtOpnSta == 3 || Lamp_FrTrnSigLmpLftOpnSta == 1 || Lamp_FrTrnSigLmpLftOpnSta == 3 || Lamp_FrTrnSigLmpRtOpnSta == 1 || Lamp_FrTrnSigLmpRtOpnSta == 3,
                    is_updated(CHASSIS_0, ICU_06_200ms_POS) && Lamp_RrTrnSigLmpLftOpnSta == 0 && Lamp_RrTrnSigLmpRtOpnSta == 0 && Lamp_FrTrnSigLmpLftOpnSta == 0 && Lamp_FrTrnSigLmpRtOpnSta == 0,
                    MS2TICK(2000), 1);
    }

    if (!Get_HDA2_Option())
        icu[ICU_C183E86_0].fault = FALSE;
}

static void update_yrs(void)
{
    struct precondition *p = get_precond_ptr();
    boolean meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_eng_run && p->is_not_ecan_busoff;

    uint16 YRS_YawRtVal = ref_sig.YRS_YawRtVal;
    uint16 YRS_LatAccelVal = ref_sig.YRS_LatAccelVal;
    uint16 YRS_LongAccelVal = ref_sig.YRS_LongAccelVal;

    if (!is_timeout(CHASSIS_0, YRS_01_10ms_POS)) {
        update_info(&yrs[YRS_C184286_0], meet_precond,
                    is_e2e_err(CHASSIS_0, YRS_01_10ms_POS) || YRS_YawRtVal == 0xFFFF || YRS_LatAccelVal == 0xFFFF || YRS_LongAccelVal == 0xFFFF,
                    is_updated(CHASSIS_0, YRS_01_10ms_POS) && !is_e2e_err(CHASSIS_0, YRS_01_10ms_POS) && YRS_YawRtVal != 0xFFFF && YRS_LatAccelVal != 0xFFFF && YRS_LongAccelVal != 0xFFFF,
                    MS2TICK(100), VALID_CNT_THR);
    }
}

static void update_swrc(void)
{
    struct precondition *p = get_precond_ptr();
    boolean meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_eng_run && p->is_not_ecan_busoff;

#if NO_SWRC == NOT_APPLIED
    if (!is_timeout(CHASSIS_0, SWRC_03_20ms_POS)) {
        update_info(&swrc[SWRC_C183D82_0], meet_precond,
                    is_e2e_err(CHASSIS_0, SWRC_03_20ms_POS),
                    is_updated(CHASSIS_0, SWRC_03_20ms_POS) && !is_e2e_err(CHASSIS_0, SWRC_03_20ms_POS),
                    MS2TICK(120000), VALID_CNT_THR);
    }
#endif /* NO_SWRC */
}

static void update_bcm(void)
{
    struct precondition *p = get_precond_ptr();
    boolean meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_eng_run && p->is_not_ecan_busoff;

    uint8 BCM_Ign1InSta = ref_sig.BCM_Ign1InSta;
    /*BCM_C181281_2: develop as invalid signal due to it uses same DTC with invalid signal*/
    update_info(&bcm[BCM_C181281_2], meet_precond,
                !is_updated(CHASSIS_0, BCM_02_200ms_POS),
                is_updated(CHASSIS_0, BCM_02_200ms_POS),
                MS2TICK(1000), 1);

    if (bcm[BCM_C181281_2].fault) {
        can_timeout_fault[CHASSIS_0] |= BIT(BCM_02_200ms_POS);
    }
    else {
        can_timeout_fault[CHASSIS_0] &= ~BIT(BCM_02_200ms_POS);
    }

    if (!is_timeout(CHASSIS_0, BCM_02_200ms_POS)) {
        update_info(&bcm[BCM_C181281_0], meet_precond,
                BCM_Ign1InSta == 0x3,
                is_updated(CHASSIS_0, BCM_02_200ms_POS) && BCM_Ign1InSta != 0x3,
                MS2TICK(1000), 1);
        update_info(&bcm[BCM_C181281_1], meet_precond,
                is_e2e_err(CHASSIS_0, BCM_02_200ms_POS),
                is_updated(CHASSIS_0, BCM_02_200ms_POS) && !is_e2e_err(CHASSIS_0, BCM_02_200ms_POS),
                MS2TICK(1000), 1);
    }
}

static void update_sbcm(void)
{
    struct precondition *p = get_precond_ptr();
    boolean meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->for_3min_after_ign_off && p->is_eng_run && p->is_not_ecan_busoff;
    
    uint8 SBCM_AST_DiagSta = ref_sig.SBCM_AST_DiagSta;
    uint8 SBCM_DRV_DiagSta = ref_sig.SBCM_DRV_DiagSta;

    if(!is_timeout(CHASSIS_0, SBCM_AST_02_200ms_POS)) {
        update_info(&sbcm[SBCM_C185481_0], meet_precond,
                    SBCM_AST_DiagSta == 0x2,
                    is_updated(CHASSIS_0, SBCM_AST_02_200ms_POS) && SBCM_AST_DiagSta != 0x2,
                    MS2TICK(1000), 1);
    }

    if(!is_timeout(CHASSIS_0, SBCM_DRV_01_200ms_POS)) {
        update_info(&sbcm[SBCM_C185381_0], meet_precond,
                    SBCM_DRV_DiagSta == 0x2,
                    is_updated(CHASSIS_0, SBCM_DRV_01_200ms_POS) && SBCM_DRV_DiagSta != 0x2,
                    MS2TICK(1000), 1);
    }
}

static void update_icsc(void)
{
    struct precondition *p = get_precond_ptr();
    boolean meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_eng_run && p->is_not_ecan_busoff;

#if ICSC_MSG == APPLIED
    if (!is_timeout(CHASSIS_0, ICSC_02_100ms_POS)) {
        update_info(&icsc[ICSC_C187002_0], meet_precond,
                    is_e2e_err(CHASSIS_0, ICSC_02_100ms_POS),
                    is_updated(CHASSIS_0, ICSC_02_100ms_POS) && !is_e2e_err(CHASSIS_0, ICSC_02_100ms_POS),
                    MS2TICK(500), VALID_CNT_THR);
    }
#endif /* ICSC_MSG */
}

#elif CCAN == HSCAN
static void update_cgw(void)
{
    struct precondition *p = get_precond_ptr();
    boolean meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_eng_run && p->is_not_ecan_busoff;

    if (!is_timeout(CHASSIS_0, P_STS_POS)) {
        update_info(&cgw[CGW_C181786_0], meet_precond,
                    is_e2e_err(CHASSIS_0, P_STS_POS),
                    is_updated(CHASSIS_0, P_STS_POS),
                    MS2TICK(2000), VALID_CNT_THR);
    }
}

static void update_clu(void)
{
    struct precondition *p = get_precond_ptr();
    boolean meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_eng_run && p->is_not_ecan_busoff;

    uint16 CF_Clu_Vanz = ref_sig.CF_Clu_Vanz;
    uint8 CF_Clu_HDALCFuncOnSetReq = ref_sig.CF_Clu_HDALCFuncOnSetReq;

    if (!is_timeout(CHASSIS_0, CLU11_POS)) {
        update_info(&clu[CLU_C165686_0], meet_precond,
                    is_e2e_err(CHASSIS_0, CLU11_POS) || (CF_Clu_Vanz == 0x1FF),
                    is_updated(CHASSIS_0, CLU11_POS) && !is_e2e_err(CHASSIS_0, CLU11_POS) && (CF_Clu_Vanz != 0x1FF),
                    MS2TICK(2000), VALID_CNT_THR);
    }

    update_info(&clu[CLU_C165686_1], meet_precond,
                CF_Clu_HDALCFuncOnSetReq == 0x3,
                is_updated(CHASSIS_0, CLU25_POS) && CF_Clu_HDALCFuncOnSetReq != 0x3,
                MS2TICK(2000), VALID_CNT_THR);

    if (!Get_HDA2_Option())
        clu[CLU_C165686_1].fault = FALSE;
}

static void update_esc(void)
{
    struct precondition *p = get_precond_ptr();
    boolean meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_eng_run && p->is_not_ecan_busoff;

    uint8 CYL_PRES_STAT = ref_sig.CYL_PRES_STAT;
    uint16 CYL_PRES = ref_sig.CYL_PRES;
    uint8 ABS_DIAG = ref_sig.ABS_DIAG;
    uint8 FCA_EQUIP = ref_sig.FCA_EQUIP;
    uint8 CF_VSM_Avail = ref_sig.CF_VSM_Avail;
    uint8 SCCEnable = ref_sig.SCCEnable;
    uint8 SCC_EQUIP = ref_sig.SCC_EQUIP;
    uint16 YAW_RATE = ref_sig.YAW_RATE;
    uint8 YAW_RATE_STAT = ref_sig.YAW_RATE_STAT;
    uint16 LAT_ACCEL = ref_sig.LAT_ACCEL;
    uint8 LAT_ACCEL_STAT = ref_sig.LAT_ACCEL_STAT;
    uint16 LONG_ACCEL = ref_sig.LONG_ACCEL;
    uint8 LONG_ACCEL_STAT = ref_sig.LONG_ACCEL_STAT;
    uint16 WHL_SPD_FL = ref_sig.WHL_SPD_FL;
    uint16 WHL_SPD_FR = ref_sig.WHL_SPD_FR;
    uint16 WHL_SPD_RL = ref_sig.WHL_SPD_RL;
    uint16 WHL_SPD_RR = ref_sig.WHL_SPD_RR;

    if (!is_timeout(CHASSIS_0, TCS11_POS) && !is_timeout(CHASSIS_0, TCS13_POS) && !is_timeout(CHASSIS_0, ESP12_POS)) {
        uint8 WHL_SPD_FAULT_CNT = 0;
        if (WHL_SPD_FL == 0x3FFF) WHL_SPD_FAULT_CNT++;
        if (WHL_SPD_FR == 0x3FFF) WHL_SPD_FAULT_CNT++;
        if (WHL_SPD_RL == 0x3FFF) WHL_SPD_FAULT_CNT++;
        if (WHL_SPD_RR == 0x3FFF) WHL_SPD_FAULT_CNT++;

        update_info(&esc[ESC_C164286_0], meet_precond,
                    is_e2e_err(CHASSIS_0, TCS11_POS) || is_e2e_err(CHASSIS_0, TCS13_POS) || (CYL_PRES_STAT == 1 && CYL_PRES == 0xFFF) || (YAW_RATE == 0x1FFF && YAW_RATE_STAT == 1) || (LONG_ACCEL == 0x7FF && LONG_ACCEL_STAT == 1) || (LAT_ACCEL == 0x7FF && LAT_ACCEL_STAT == 1) || WHL_SPD_FAULT_CNT >= 2,
                    is_updated(CHASSIS_0, TCS13_POS) && !is_e2e_err(CHASSIS_0, TCS11_POS) && !is_e2e_err(CHASSIS_0, TCS13_POS) && (CYL_PRES_STAT == 0 && CYL_PRES != 0xFFF) && (YAW_RATE != 0x1FFF && YAW_RATE_STAT == 0) && (LONG_ACCEL != 0x7FF && LONG_ACCEL_STAT == 0) && (LAT_ACCEL != 0x7FF && LAT_ACCEL_STAT == 0) && WHL_SPD_FAULT_CNT <= 1,
                    MS2TICK(100), VALID_CNT_THR);
    }

    if (!is_timeout(CHASSIS_0, TCS11_POS) && !is_timeout(CHASSIS_0, TCS13_POS)) {
        update_info(&esc[ESC_C164286_1], meet_precond,
                    FCA_EQUIP == 0 || (CF_VSM_Avail == 1 && ABS_DIAG == 0) || CF_VSM_Avail == 2,
                    is_updated(CHASSIS_0, TCS13_POS) && FCA_EQUIP == 1 && CF_VSM_Avail == 0,
                    MS2TICK(500), VALID_CNT_THR);
    }

    if (!is_timeout(CHASSIS_0, TCS11_POS) && !is_timeout(CHASSIS_0, TCS13_POS)) {
        update_info(&esc[ESC_NA_0], meet_precond,
                    CF_VSM_Avail == 1 && ABS_DIAG == 1,
                    is_updated(CHASSIS_0, TCS13_POS) && CF_VSM_Avail == 0,
                    MS2TICK(500), VALID_CNT_THR);
    }

    if (!is_timeout(CHASSIS_0, TCS13_POS)) {
        update_info(&esc[ESC_C16B881_0], meet_precond,
                    CF_VSM_Avail == 3,
                    is_updated(CHASSIS_0, TCS13_POS) && CF_VSM_Avail == 0,
                    MS2TICK(500), VALID_CNT_THR);
    }

    if (!is_timeout(CHASSIS_0, TCS11_POS) && !is_timeout(CHASSIS_0, TCS13_POS)) {
        update_info(&esc[ESC_C136081_0], meet_precond,
                    SCC_EQUIP == 0 || (SCCEnable == 1 && ABS_DIAG == 0) || SCCEnable == 2,
                    is_updated(CHASSIS_0, TCS13_POS) && SCC_EQUIP == 1 && SCCEnable == 0,
                    MS2TICK(500), VALID_CNT_THR);
    }

    if (!is_timeout(CHASSIS_0, TCS11_POS) && !is_timeout(CHASSIS_0, TCS13_POS)) {
        update_info(&esc[ESC_NA_1], meet_precond,
                    SCCEnable == 1 && ABS_DIAG == 1,
                    is_updated(CHASSIS_0, TCS13_POS) && SCCEnable == 0,
                    MS2TICK(500), VALID_CNT_THR);
    }

    if (!is_timeout(CHASSIS_0, TCS13_POS)) {
        update_info(&esc[ESC_C163881_0], meet_precond,
                    SCCEnable == 3,
                    is_updated(CHASSIS_0, TCS13_POS) && SCCEnable == 0,
                    MS2TICK(500), VALID_CNT_THR);
    }
}

static void update_mdps(void)
{
    struct precondition *p = get_precond_ptr();
    boolean meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_eng_run && p->is_not_ecan_busoff;

    extern MsgGr_CCAN_ADAS_CMD_30_1_10ms MsgGr_ADAS_CMD_30_1_10ms_Out;

    uint16 CR_Mdps_StrColTq = ref_sig.CR_Mdps_StrColTq;
    uint8 CF_Mdps_ToiActive = ref_sig.CF_Mdps_ToiActive;
    uint8 CF_Mdps_ToiUnavail = ref_sig.CF_Mdps_ToiUnavail;
    uint8 CF_Mdps_FailStat = ref_sig.CF_Mdps_FailStat;
    uint8 CF_Mdps_ToiFlt = ref_sig.CF_Mdps_ToiFlt;
    uint8 LKA_ActToiSta = MsgGr_ADAS_CMD_30_1_10ms_Out.LKA_ActToiSta;

    if (!is_timeout(CHASSIS_0, MDPS12_POS)) {
        update_info(&mdps[MDPS_C168886_0], meet_precond,
                    CR_Mdps_StrColTq == 0x7FF,
                    is_updated(CHASSIS_0, MDPS12_POS) && (CR_Mdps_StrColTq != 0x7FF),
                    MS2TICK(500), VALID_CNT_THR);
    }

    if (!is_timeout(CHASSIS_0, MDPS12_POS)) {
        update_info(&mdps[MDPS_C223986_0], meet_precond,
                    CF_Mdps_ToiFlt != 0x0,
                    is_updated(CHASSIS_0, MDPS12_POS) && (CF_Mdps_ToiFlt == 0x0),
                    MS2TICK(100), VALID_CNT_THR);
    }

    /* ADAS_ActToiSta and MDPS_LkaToiActvSta mismatch */
    static uint8 CF_Mdps_ToiUnavail_prev;
    static uint8 CF_Mdps_ToiFlt_prev;
    static uint8 CF_Mdps_FailStat_prev;
    static uint8 rampdown_tick_remain;

    if (!is_timeout(CHASSIS_0, MDPS12_POS)) {
        if (LKA_ActToiSta == 1 && ((CF_Mdps_ToiUnavail_prev == 0 && CF_Mdps_ToiUnavail == 1) ||
                                   (CF_Mdps_ToiFlt_prev == 0 && CF_Mdps_ToiFlt == 1) ||
                                   (CF_Mdps_FailStat_prev == 0 && CF_Mdps_FailStat == 1))) {
            rampdown_tick_remain = MS2TICK(1000);
        } else if (rampdown_tick_remain) {
            rampdown_tick_remain--;
        }

        meet_precond &= (rampdown_tick_remain == 0);
        update_info(&mdps[MDPS_C168886_1], meet_precond,
                    LKA_ActToiSta != CF_Mdps_ToiActive,
                    is_updated(CHASSIS_0, MDPS12_POS) && (LKA_ActToiSta == CF_Mdps_ToiActive),
                    MS2TICK(500), VALID_CNT_THR);
    }

    CF_Mdps_ToiUnavail_prev = CF_Mdps_ToiUnavail;
    CF_Mdps_ToiFlt_prev = CF_Mdps_ToiFlt;
    CF_Mdps_FailStat_prev = CF_Mdps_FailStat;
}

static void update_sas(void)
{
    struct precondition *p = get_precond_ptr();
    boolean meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_eng_run && p->is_not_ecan_busoff;

    sint16 SAS_Angle = ref_sig.SAS_Angle;
    uint8 SAS_Speed = ref_sig.SAS_Speed;

    if (!is_timeout(CHASSIS_0, SAS11_POS)) {
        update_info(&sas[SAS_C181486_0], meet_precond,
                    is_e2e_err(CHASSIS_0, SAS11_POS) || SAS_Angle == 0x7FFF || SAS_Speed == 0xFF,
                    is_updated(CHASSIS_0, SAS11_POS) && !is_e2e_err(CHASSIS_0, SAS11_POS) && SAS_Angle != 0x7FFF && SAS_Speed != 0xFF,
                    MS2TICK(100), VALID_CNT_THR);
    }
}

static void update_ems(void)
{
    struct precondition *p = get_precond_ptr();
    boolean meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_not_ecan_busoff;

    uint8 F_N_ENG = ref_sig.F_N_ENG;
    uint8 ENG_STAT = ref_sig.ENG_STAT;
    uint16 PV_AV_CAN = ref_sig.PV_AV_CAN;
    uint8 CF_Ems_AclAct = ref_sig.CF_Ems_AclAct;

    if (!is_timeout(CHASSIS_0, EMS12_POS) && !is_timeout(CHASSIS_0, EMS16_POS)) {
        update_info(&ems[EMS_C161386_0], meet_precond,
                    is_e2e_err(CHASSIS_0, EMS16_POS) || PV_AV_CAN == 0xFF || ENG_STAT == 0x7 || F_N_ENG == 1,
                    is_updated(CHASSIS_0, EMS12_POS) && !is_e2e_err(CHASSIS_0, EMS16_POS) && PV_AV_CAN != 0xFF && ENG_STAT != 0x7 && F_N_ENG == 0,
                    MS2TICK(500), VALID_CNT_THR);
    }

    if (!is_timeout(CHASSIS_0, EMS16_POS)) {
        update_info(&ems[EMS_C161386_1], meet_precond,
                    CF_Ems_AclAct == 3,
                    is_updated(CHASSIS_0, EMS16_POS) && CF_Ems_AclAct != 3,
                    MS2TICK(500), VALID_CNT_THR);
    }
}

static void update_tcu(void)
{
    struct precondition *p = get_precond_ptr();
    boolean meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_eng_run && p->is_not_ecan_busoff;

    uint8 G_SEL_DISP = ref_sig.G_SEL_DISP;

    update_info(&tcu[TCU_C164686_0], meet_precond,
                G_SEL_DISP == 0xF,
                is_updated(CHASSIS_0, CGW_PC5_POS) && G_SEL_DISP != 0xF,
                MS2TICK(500), VALID_CNT_THR);
}
#endif /* CCAN */

static void update_navi(void)
{
    struct precondition *p = get_precond_ptr();
    boolean meet_precond;

    uint8 HU_AdasSupport = ref_sig.HU_AdasSupport;
    uint8 HU_DistributeInfo = ref_sig.HU_DistributeInfo;
    uint8 HU_NaviHandshakingSupport = ref_sig.HU_NaviHandshakingSupport;

    enum {
        RECOVER = 0,
        DETECT = 1,
        UNDEFINED = 2,
    } status = UNDEFINED;

    switch (VariantCode_NvMData.stNvMVariantCode.NvM_Block_NSCC_HDA2_Option) {
    case NSCC_HDA2__NSCC_ZCR_HDA2:
        /* All option on */
        if (HU_DistributeInfo != 1 && HU_DistributeInfo != 0xFF)
            status = DETECT;
        else if (HU_DistributeInfo == 1)
            status = RECOVER;
        break;
    case NSCC_HDA2__NSCC_C_HDA2:
        /* Only NSCC-C on */
        if (HU_DistributeInfo != 2 && HU_DistributeInfo != 3 && HU_DistributeInfo != 4 && HU_DistributeInfo != 5 && HU_DistributeInfo != 0xFF)
            status = DETECT;
        else if (HU_DistributeInfo == 2 || HU_DistributeInfo == 3 || HU_DistributeInfo == 4 || HU_DistributeInfo == 5)
            status = RECOVER;
        break;
    case NSCC_HDA2__NSCC_ZC_HDA2:
        /* NSCC-Z/C on */
        if (HU_DistributeInfo != 6 && HU_DistributeInfo != 0xFF)
            status = DETECT;
        else if (HU_DistributeInfo == 6)
            status = RECOVER;
        break;
    case NSCC_HDA2__NA:
    default:
        /* All option off */
        status = RECOVER;
        break;
    }

    meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_not_ecan_busoff;
    if (!is_timeout(CHASSIS_0, HU_MON_PE_01_POS)) {
        update_info(&navi[NAVI_C174686_0], meet_precond,
#if MAP_VER == V2_3
                    (HU_AdasSupport != 5 && HU_AdasSupport != 7) || (HU_NaviHandshakingSupport != 1 && HU_NaviHandshakingSupport != 3) || status == DETECT,
                    HU_AdasSupport == 5 && HU_NaviHandshakingSupport == 1 && status == RECOVER,
#elif MAP_VER == V2
                    (HU_AdasSupport != 3 && HU_AdasSupport != 4 && HU_AdasSupport != 7) || status == DETECT,
                    (HU_AdasSupport == 3 || HU_AdasSupport == 4) && status == RECOVER,
#else
    #error Undefined map version
#endif 
                    MS2TICK(12000), MS2TICK(12000));
    }


#if NAVI_VER == GEN6
#define SAMPLE_HOLD_TIME   300
#elif NAVI_VER == GEN5
#define SAMPLE_HOLD_TIME   750
#else
#error Undefined AVN type
#endif /* NAVI_VER */

    static uint16 sample_delay = MS2TICK(SAMPLE_HOLD_TIME);
    static uint8 POS_CyclicCounter_prev = 0xFF;
    static boolean is_normal_cyclic_counter = TRUE;
    static boolean is_normal_resp_map_msg = FALSE;

    boolean navi_option = Get_NAVI_Option();
    uint8 HU_NaviStatus = ref_sig.HU_NaviStatus;
    uint8 HU_AliveStatus= ref_sig.HU_AliveStatus;
    uint8 HU_Navi_RspADASMapMsg = ref_sig.HU_Navi_RspADASMapMsg;
    uint8 POS_CyclicCounter = ref_sig.POS_CyclicCounter;
    uint8 SEG_CalculatedRoute = ref_sig.SEG_CalculatedRoute;

    meet_precond = navi_option && p->is_eng_run && p->is_norm_vol && p->is_not_ecan_busoff && !is_coding_navi_mismatch() &&
                   HU_NaviStatus == 1 && HU_AliveStatus == 1 && !is_timeout(CHASSIS_0, HU_CLU_PE_05_POS) &&
                   !is_timeout(CHASSIS_0, HU_GW_PE_01_POS) && (SEG_CalculatedRoute == 0 || SEG_CalculatedRoute == 1) &&
#if MAP_VER == V2_3
            (HU_AdasSupport == 5);
#elif MAP_VER == V2
            (HU_AdasSupport == 3 || HU_AdasSupport == 4);
#else
    #error Undefined map version
#endif /* MAP_VER */          
    if (!is_timeout(CHASSIS_0, HU_NAVI_V2_POS_PE_POS)) {
        if (sample_delay == 0) {
            is_normal_cyclic_counter = FALSE;
            sample_delay = MS2TICK(SAMPLE_HOLD_TIME);
        } else {
            if (POS_CyclicCounter != POS_CyclicCounter_prev) {
                if ((4 + POS_CyclicCounter - POS_CyclicCounter_prev) % 4 == 1 || POS_CyclicCounter_prev == 0xFF)
                    is_normal_cyclic_counter = TRUE;
                else
                    is_normal_cyclic_counter = FALSE;

                sample_delay = MS2TICK(SAMPLE_HOLD_TIME);
                POS_CyclicCounter_prev = POS_CyclicCounter;
            }
            sample_delay--;
        }

        update_info(&navi[NAVI_C183186_0], meet_precond,
                    !is_normal_cyclic_counter,
                    is_normal_cyclic_counter,
                    MS2TICK(12000), MS2TICK(NAVI_VER == GEN6 ? 600 : 1500));
    }
    

#if CCAN == CANFD
#if NO_EOL_STD == NOT_APPLIED
    if (HU_NaviStatus == 1 && !is_timeout(CHASSIS_0, HU_CLU_PE_05_POS)) {

         if (navi_boot_tick >= MS2TICK(5000)) {
            navi_boot_tick = MS2TICK(5000);
            is_navi_boot = TRUE;
        } else {
            navi_boot_tick++;
            is_navi_boot = FALSE;
        }
    } else {
        navi_boot_tick = 0;
        is_navi_boot = FALSE;
    }

    meet_precond =  navi_option && p->is_eng_run && p->is_norm_vol && p->is_not_ecan_busoff && !is_coding_navi_mismatch() && 
                    HU_AliveStatus == 1 &&  !is_timeout(CHASSIS_0, HU_GW_PE_01_POS) && is_navi_boot && HU_NaviHandshakingSupport == 0x1 &&
#if MAP_VER == V2_3
            (HU_AdasSupport == 5);
#elif MAP_VER == V2
            (HU_AdasSupport == 4);
#else
    #error Undefined map version
#endif /* MAP_VER */  

    uint16 check_bit = 0;
    switch (VariantCode_NvMData.stNvMVariantCode.NvM_Block_NSCC_HDA2_Option) {
        case NSCC_HDA2__NSCC_Z_HDA2:
            check_bit = 0x0024;
        break;
        case NSCC_HDA2__NSCC_ZC_HDA2:
            check_bit = 0x0026;
            break;
        case NSCC_HDA2__NSCC_ZCR_HDA2:
        case NSCC_HDA2__NSCC_CR_HDA2:
            check_bit = 0x0067;
            break;
        case NSCC_HDA2__NSCC_C_HDA2:
            check_bit = 0x0022;
            break;   
        case NSCC_HDA2__NA: 
        default:
            check_bit = 0x0000;
            break; 
    }
    if ((HU_Navi_RspADASMapMsg & check_bit) == check_bit) {
        is_normal_resp_map_msg = TRUE;
    } else {
        is_normal_resp_map_msg = FALSE;
    }
    update_info(&navi[NAVI_C183186_1], meet_precond,
                    !is_normal_resp_map_msg,
                    is_updated(CHASSIS_0, HU_MON_PE_01_POS) && is_normal_resp_map_msg,
                    MS2TICK(6000), 3);
#endif /* NO_EOL_STD */
#endif /* CCAN */

    if (!navi_option) {
        for (int i = 0; i < NAVI_ITEM_NUM; i++)
            navi[i].fault = FALSE;
    }
}

static void update_fr_cmr(void)
{
    struct precondition *p = get_precond_ptr();
    boolean meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_eng_run && p->is_not_acan_busoff;

    uint8 FR_CMR_Genrl_FlInfoSta = ref_sig.FR_CMR_Genrl_FlInfoSta;
    uint8 LFA_ShrtkeySwSta = ref_sig.LFA_ShrtkeySwSta;
    if (!is_timeout(L_FR_CMR_0, A_FR_CMR_Genrl_01_30ms_POS)) {
        update_info(&fr_cmr[FR_CMR_28B086_0], meet_precond,
                    FR_CMR_Genrl_FlInfoSta == 2,
                    FR_CMR_Genrl_FlInfoSta != 2,
                    MS2TICK(500), MS2TICK(500));

        update_info(&fr_cmr[FR_CMR_NA_0], meet_precond,
                    FR_CMR_Genrl_FlInfoSta == 1,
                    FR_CMR_Genrl_FlInfoSta != 1,
                    MS2TICK(500), MS2TICK(500));
    }

#if LFA_SW_INTEG == APPLIED
    if (!is_timeout(L_FR_CMR_0, A_FR_CMR_Ctrl_01_10ms_POS)) {
        update_info(&fr_cmr[FR_CMR_28B086_1], meet_precond,
                    LFA_ShrtkeySwSta == 3,
                    LFA_ShrtkeySwSta == 0 || LFA_ShrtkeySwSta == 1,
                    MS2TICK(500), MS2TICK(500));
    }
#endif /* LFA_SW_INTEG */
}

static void update_fr_rdr(void)
{
    struct precondition *p = get_precond_ptr();
    boolean meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_eng_run && p->is_not_acan_busoff;

    uint8 FR_RDR_Genrl_FlInfoSta = ref_sig.FR_RDR_Genrl_FlInfoSta;
    if (!is_timeout(L_FR_RDR_0, A_FR_RDR_Genrl_01_50ms_POS)) {
        update_info(&fr_rdr[FR_RDR_C28B186_0], meet_precond,
                    FR_RDR_Genrl_FlInfoSta == 2,
                    FR_RDR_Genrl_FlInfoSta != 2,
                    MS2TICK(500), MS2TICK(500));

        update_info(&fr_rdr[FR_RDR_NA_0], meet_precond,
                    FR_RDR_Genrl_FlInfoSta == 1,
                    FR_RDR_Genrl_FlInfoSta != 1,
                    MS2TICK(500), MS2TICK(500));
    }
}

static void update_fr_c_rdr(void)
{
    struct precondition *p = get_precond_ptr();
    boolean meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->is_eng_run && p->is_not_acan_busoff;

    uint8 FR_C_RDR_LocalFlInfoSta_Flt = ref_sig.FR_C_RDR_LocalFlInfoSta_Flt;
    uint8 FR_C_RDR_Genrl_FlInfoSta_Blkg = ref_sig.FR_C_RDR_Genrl_FlInfoSta_Blkg;
    if (!is_timeout(L_FR_C_RDR_0, A_FR_C_RDR_Genrl_01_50ms_POS)) {
        update_info(&fr_c_rdr[FR_C_RDR_C188186_0], meet_precond,
                    (FR_C_RDR_LocalFlInfoSta_Flt >= 0x4 && FR_C_RDR_LocalFlInfoSta_Flt <= 0xF),
                    !(FR_C_RDR_LocalFlInfoSta_Flt >= 0x4 && FR_C_RDR_LocalFlInfoSta_Flt <= 0xF),
                    MS2TICK(500), MS2TICK(500));

        update_info(&fr_c_rdr[FR_C_RDR_NA_0], meet_precond,
                    (FR_C_RDR_Genrl_FlInfoSta_Blkg >= 0x4 && FR_C_RDR_Genrl_FlInfoSta_Blkg <= 0xF),
                    !(FR_C_RDR_Genrl_FlInfoSta_Blkg >= 0x4 && FR_C_RDR_Genrl_FlInfoSta_Blkg <= 0xF),
                    MS2TICK(500), MS2TICK(500));

        meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->for_3min_after_ign_off && p->is_eng_run && p->is_not_acan_busoff;
        update_info(&fr_c_rdr[FR_C_RDR_C188186_1], meet_precond,
                    (FR_C_RDR_LocalFlInfoSta_Flt != 0x0 && FR_C_RDR_LocalFlInfoSta_Flt != 0x4 && FR_C_RDR_LocalFlInfoSta_Flt != 0x8 && FR_C_RDR_LocalFlInfoSta_Flt != 0xC),
                    !(FR_C_RDR_LocalFlInfoSta_Flt != 0x0 && FR_C_RDR_LocalFlInfoSta_Flt != 0x4 && FR_C_RDR_LocalFlInfoSta_Flt != 0x8 && FR_C_RDR_LocalFlInfoSta_Flt != 0xC),
                    MS2TICK(500), MS2TICK(500));

        update_info(&fr_c_rdr[FR_C_RDR_NA_1], meet_precond,
                    (FR_C_RDR_Genrl_FlInfoSta_Blkg != 0x0 && FR_C_RDR_Genrl_FlInfoSta_Blkg != 0x4 && FR_C_RDR_Genrl_FlInfoSta_Blkg != 0x8 && FR_C_RDR_Genrl_FlInfoSta_Blkg != 0xC),
                    !(FR_C_RDR_Genrl_FlInfoSta_Blkg != 0x0 && FR_C_RDR_Genrl_FlInfoSta_Blkg != 0x4 && FR_C_RDR_Genrl_FlInfoSta_Blkg != 0x8 && FR_C_RDR_Genrl_FlInfoSta_Blkg != 0xC),
                    MS2TICK(500), MS2TICK(500));
    }
}

/* CR: HKGL3-923 */
void update_rdr_fail_flg(void)
{
    struct inhibit_info *p = get_inhibit_ptr();
    uint32 lcan_mask = 0;

    /* Failsafe 51, 66, 67 (GL3 P1 ~) */ 
    lcan_mask = (BIT(A_FR_RDR_Obj_16_50ms_POS + 1) - BIT(A_FR_RDR_Obj_01_50ms_POS)) | BIT(A_FR_RDR_Genrl_01_50ms_POS);
    if ((can_timeout_fault[L_FR_RDR_0] & lcan_mask) || fr_rdr[FR_RDR_C28B186_0].fault || fr_rdr[FR_RDR_NA_0].fault) {
        if (rdr_another_fail_flag == 0) {
            rdr_fail_flag = 1;
        } else {
            rdr_fail_flag = 0;
        }
    } 
    else {        
        rdr_fail_flag = 0;
    } 
    rdr_another_fail_flag = 0;
}

void FS_UpdateInfo_InvalidSignal(void)
{
    /* Chassis CAN */
#if CCAN == CANFD
#if VEH_TYPE == NORMAL
    update_ems();
    update_tcu();
#elif VEH_TYPE == EV
    update_vcu();
#elif VEH_TYPE == HEV
    update_ems();
    update_hcu();
    update_htcu();
#endif /* VEH_TYPE */
    update_clu();
    update_esc();
    update_icsc();
    update_icu();
    update_mdps();
    update_sas();
    update_yrs();
    update_swrc();
    update_bcm();
    update_sbcm();

#elif CCAN == HSCAN
    update_ems();
    update_tcu();
    update_cgw();
    update_clu();
    update_esc();
    update_mdps();
    update_sas();
#endif /* CCAN */

    /* NAVI */
    update_navi();

    /* Local CAN */
    update_fr_cmr();
    update_fr_rdr();
    update_fr_c_rdr();

    /* Radar Blockage Flag (CR: HKGL3-923) */
    update_rdr_fail_flg();

#if CCAN == CANFD
    /* Recover group 5 */
    int i;
    if (TEST_BIT(recover_mask[RECOVER_GROUP_5], CLU_INVALID_SIGNAL))
        for (i = CLU_ITEM_NUM; i--; ) clu[i].fault = FALSE;
    if (TEST_BIT(recover_mask[RECOVER_GROUP_5], ESC_INVALID_SIGNAL))
        for (i = ESC_ITEM_NUM; i--; ) esc[i].fault = FALSE;
    if (TEST_BIT(recover_mask[RECOVER_GROUP_5], MDPS_INVALID_SIGNAL))
        for (i = MDPS_ITEM_NUM; i--; ) mdps[i].fault = FALSE;
    if (TEST_BIT(recover_mask[RECOVER_GROUP_5], SAS_INVALID_SIGNAL))
        for (i = SAS_ITEM_NUM; i--; ) sas[i].fault = FALSE;
#if VEH_TYPE == NORMAL
    if (TEST_BIT(recover_mask[RECOVER_GROUP_5], EMS_INVALID_SIGNAL))
        for (i = EMS_ITEM_NUM; i--; ) ems[i].fault = FALSE;
    if (TEST_BIT(recover_mask[RECOVER_GROUP_5], TCU_INVALID_SIGNAL))
        for (i = TCU_ITEM_NUM; i--; ) tcu[i].fault = FALSE;
#elif VEH_TYPE == HEV
    if (TEST_BIT(recover_mask[RECOVER_GROUP_5], EMS_INVALID_SIGNAL))
        for (i = EMS_ITEM_NUM; i--; ) ems[i].fault = FALSE;
    if (TEST_BIT(recover_mask[RECOVER_GROUP_5], TCU_INVALID_SIGNAL))
        for (i = HTCU_ITEM_NUM; i--; ) htcu[i].fault = FALSE;
#endif /* VEH_TYPE */
    if (TEST_BIT(recover_mask[RECOVER_GROUP_5], YRS_INVALID_SIGNAL))
        for (i = YRS_ITEM_NUM; i--; ) yrs[i].fault = FALSE;
    if (TEST_BIT(recover_mask[RECOVER_GROUP_5], SWRC_INVALID_SIGNAL))
        for (i = SWRC_ITEM_NUM; i--; ) swrc[i].fault = FALSE;

    /* Recover group 6 */
#if VEH_TYPE == EV
   if (TEST_BIT(recover_mask[RECOVER_GROUP_6], VCU_HCU_INVALID_SIGNAL))
        for (i = VCU_ITEM_NUM; i--; ) vcu[i].fault = FALSE;
#elif VEH_TYPE == HEV
   if (TEST_BIT(recover_mask[RECOVER_GROUP_6], VCU_HCU_INVALID_SIGNAL))
        for (i = HCU_ITEM_NUM; i--; ) hcu[i].fault = FALSE;
#endif /* VEH_TYPE */
    if (TEST_BIT(recover_mask[RECOVER_GROUP_6], ICSC_INVALID_SIGNAL))
        for (i = ICSC_ITEM_NUM; i--; ) icsc[i].fault = FALSE;
    if (TEST_BIT(recover_mask[RECOVER_GROUP_6], ICU_INVALID_SIGNAL))
        for (i = ICU_ITEM_NUM; i--; ) icu[i].fault = FALSE;
    if (TEST_BIT(recover_mask[RECOVER_GROUP_6], NAVI_INVALID_SIGNAL))
        for (i = NAVI_ITEM_NUM; i--; ) navi[i].fault = FALSE;
    if (TEST_BIT(recover_mask[RECOVER_GROUP_6], FR_CMR_INVALID_SIGNAL))
        for (i = FR_CMR_ITEM_NUM; i--; ) fr_cmr[i].fault = FALSE;
    if (TEST_BIT(recover_mask[RECOVER_GROUP_6], FR_RDR_INVALID_SIGNAL))
        for (i = FR_RDR_ITEM_NUM; i--; ) fr_rdr[i].fault = FALSE;
    if (TEST_BIT(recover_mask[RECOVER_GROUP_6], FR_C_RDR_INVALID_SIGNAL))
        for (i = FR_C_RDR_ITEM_NUM; i--; ) fr_c_rdr[i].fault = FALSE;

#elif CCAN == HSCAN
    /* Recover group 5 */
    int i;
    if (TEST_BIT(recover_mask[RECOVER_GROUP_5], CGW_INVALID_SIGNAL))
        for (i = CGW_ITEM_NUM; i--; ) cgw[i].fault = FALSE;
    if (TEST_BIT(recover_mask[RECOVER_GROUP_5], CLU_INVALID_SIGNAL))
        for (i = CLU_ITEM_NUM; i--; ) clu[i].fault = FALSE;
    if (TEST_BIT(recover_mask[RECOVER_GROUP_5], ESC_INVALID_SIGNAL))
        for (i = ESC_ITEM_NUM; i--; ) esc[i].fault = FALSE;
    if (TEST_BIT(recover_mask[RECOVER_GROUP_5], MDPS_INVALID_SIGNAL))
        for (i = MDPS_ITEM_NUM; i--; ) mdps[i].fault = FALSE;
    if (TEST_BIT(recover_mask[RECOVER_GROUP_5], SAS_INVALID_SIGNAL))
        for (i = SAS_ITEM_NUM; i--; ) sas[i].fault = FALSE;
    if (TEST_BIT(recover_mask[RECOVER_GROUP_5], EMS_INVALID_SIGNAL))
        for (i = EMS_ITEM_NUM; i--; ) ems[i].fault = FALSE;
    if (TEST_BIT(recover_mask[RECOVER_GROUP_5], TCU_INVALID_SIGNAL))
        for (i = TCU_ITEM_NUM; i--; ) tcu[i].fault = FALSE;
    if (TEST_BIT(recover_mask[RECOVER_GROUP_6], NAVI_INVALID_SIGNAL))
        for (i = NAVI_ITEM_NUM; i--; ) navi[i].fault = FALSE;

    /* Recover group 6 */
    if (TEST_BIT(recover_mask[RECOVER_GROUP_6], FR_CMR_INVALID_SIGNAL))
        for (i = FR_CMR_ITEM_NUM; i--; ) fr_cmr[i].fault = FALSE;
    if (TEST_BIT(recover_mask[RECOVER_GROUP_6], FR_RDR_INVALID_SIGNAL))
        for (i = FR_RDR_ITEM_NUM; i--; ) fr_rdr[i].fault = FALSE;
    if (TEST_BIT(recover_mask[RECOVER_GROUP_6], FR_C_RDR_INVALID_SIGNAL))
        for (i = FR_C_RDR_ITEM_NUM; i--; ) fr_c_rdr[i].fault = FALSE;
#endif /* CCAN */
}

void FS_SetDiagsta_InvalidSignal(void)
{
    /* Chassis CAN */
#if CCAN == CANFD
#if VEH_TYPE == NORMAL
    /* EMS */
    SET_DTC(C161386, ems[EMS_C161386_0].fault || ems[EMS_C161386_1].fault || ems[EMS_C161386_2].fault);
    /* TCU */
    SET_DTC(C164686, tcu[TCU_C164686_0].fault);
#elif VEH_TYPE == EV
    /* VCU */
    SET_DTC(C161C86, vcu[VCU_C161C86_0].fault || vcu[VCU_C161C86_1].fault);
#elif VEH_TYPE == HEV
    /* EMS */
    SET_DTC(C161386, ems[EMS_C161386_0].fault);
    /* HCU */
    SET_DTC(C161C86, hcu[HCU_C161C86_0].fault || hcu[HCU_C161C86_1].fault);
    /* HTCU */
    SET_DTC(C164686, htcu[HTCU_C164686_0].fault);
#endif /* VEH_TYPE */
    /* CLU */
    SET_DTC(C165686, clu[CLU_C165686_0].fault || clu[CLU_C165686_1].fault);
    /* BCM */
    SET_DTC(C181281, bcm[BCM_C181281_0].fault || bcm[BCM_C181281_1].fault || bcm[BCM_C181281_2].fault); 
    /* ESC */
    SET_DTC(C164286, esc[ESC_C164286_0].fault || esc[ESC_C164286_1].fault || esc[ESC_C164286_2].fault);
    SET_DTC(C16B881, esc[ESC_C16B881_0].fault);
    SET_DTC(C136081, esc[ESC_C136081_0].fault);
    SET_DTC(C163881, esc[ESC_C163881_0].fault);
    SET_DTC(C164282, esc[ESC_C164282_0].fault);
    SET_DTC(C164281, esc[ESC_C164281_0].fault);
    /* ICU */
    SET_DTC(C183E86, icu[ICU_C183E86_0].fault);
    /* MDPS */
    SET_DTC(C168886, mdps[MDPS_C168886_0].fault || mdps[MDPS_C168886_1].fault);
    SET_DTC(C223986, mdps[MDPS_C223986_0].fault || mdps[MDPS_C223986_1].fault);
    /* SAS */
    SET_DTC(C181486, sas[SAS_C181486_0].fault);
    /* SBCM */
    SET_DTC(C185481, sbcm[SBCM_C185481_0].fault);
    SET_DTC(C185381, sbcm[SBCM_C185381_0].fault);
    /* YRS */
    SET_DTC(C184286, yrs[YRS_C184286_0].fault);
    /* SWRC */
    SET_DTC(C183D82, swrc[SWRC_C183D82_0].fault);
    /* ICSC */
    SET_DTC(C187002, icsc[ICSC_C187002_0].fault);

#elif CCAN == HSCAN
    /*CGW*/
    SET_DTC(C181786, cgw[CGW_C181786_0].fault);
    /*CLU*/
    SET_DTC(C165686, clu[CLU_C165686_0].fault || clu[CLU_C165686_1].fault);
    /*ESC*/
    SET_DTC(C164286, esc[ESC_C164286_0].fault || esc[ESC_C164286_1].fault);
    SET_DTC(C16B881, esc[ESC_C16B881_0].fault);
    SET_DTC(C136081, esc[ESC_C136081_0].fault);
    SET_DTC(C163881, esc[ESC_C163881_0].fault);
    /*MDPS*/
    SET_DTC(C168886, mdps[MDPS_C168886_0].fault || mdps[MDPS_C168886_1].fault);
    SET_DTC(C223986, mdps[MDPS_C223986_0].fault);
    /*SAS*/
    SET_DTC(C181486, sas[SAS_C181486_0].fault);
    /*EMS*/
    SET_DTC(C161386, ems[EMS_C161386_0].fault || ems[EMS_C161386_1].fault);
    /*TCU*/
    SET_DTC(C164686, tcu[TCU_C164686_0].fault);
#endif /* CCAN */

    /* Navi */
    SET_DTC(C174686, navi[NAVI_C174686_0].fault);
    SET_DTC(C183186, navi[NAVI_C183186_0].fault || navi[NAVI_C183186_1].fault);

    /* ADAS CAN */
    SET_DTC(C28B086, fr_cmr[FR_CMR_28B086_0].fault || fr_cmr[FR_CMR_28B086_1].fault);
    SET_DTC(C28B186, fr_rdr[FR_RDR_C28B186_0].fault);
    SET_DTC(C188186, fr_c_rdr[FR_C_RDR_C188186_0].fault || fr_c_rdr[FR_C_RDR_C188186_1].fault);
}

void FS_SetInhibit_InvalidSignal(void)
{
#if CCAN == CANFD
#if VEH_TYPE == NORMAL
    /* EMS */
    if (ems[EMS_C161386_0].fault) {
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
    if (ems[EMS_C161386_1].fault) {
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
    if (ems[EMS_C161386_2].fault) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {1,1,1,1,1,1,1,1,1},
                .scc = {0,0,0,0},
                .sccml = {0},
                .nscc = {0,0},
                .lfa = {0,0},
                .hda = {0,0,0,0},
                .bca = {1,0,1,0},
                .sea = {1},
                .rcca = {1,0},
                .warning = {3,0,0,0,NO_FAULT,0,1},
            }
        );
    }

    /* TCU */
    if (tcu[TCU_C164686_0].fault) {
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
    /* VCU */
    if (vcu[VCU_C161C86_0].fault) {
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
    if (vcu[VCU_C161C86_1].fault) {
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
    /* EMS */
    if (ems[EMS_C161386_0].fault) {
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

    /* HCU */
    if (hcu[HCU_C161C86_0].fault) {
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
    if (hcu[HCU_C161C86_1].fault) {
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

    /* HTCU */
    if (htcu[HTCU_C164686_0].fault) {
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

    /* CLU */
    if (clu[CLU_C165686_0].fault) {
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
    if (clu[CLU_C165686_1].fault) {
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
    /* BCM */
    if (bcm[BCM_C181281_0].fault) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,0,0,0,0,0,0,0},
                .scc = {0,0,0,0},
                .sccml = {0},
                .nscc = {0,0},
                .lfa = {0,0},
                .hda = {0,0,0,0},
                .bca = {1,0,1,0},
                .sea = {1},
                .rcca = {1,0},
                .warning = {0,0,0,0,NO_FAULT,0,1},
            }
        );
    }
    if (bcm[BCM_C181281_1].fault) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,0,0,0,0,0,0,0},
                .scc = {0,0,0,0},
                .sccml = {0},
                .nscc = {0,0},
                .lfa = {0,0},
                .hda = {0,0,0,0},
                .bca = {1,0,1,0},
                .sea = {1},
                .rcca = {1,0},
                .warning = {0,0,0,0,NO_FAULT,0,1},
            }
        );
    }
    if (bcm[BCM_C181281_2].fault) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,0,0,0,0,0,0,0},
                .scc = {0,0,0,0},
                .sccml = {0},
                .nscc = {0,0},
                .lfa = {0,0},
                .hda = {0,0,0,0},
                .bca = {1,0,1,0},
                .sea = {1},
                .rcca = {1,0},
                .warning = {0,0,0,0,NO_FAULT,0,1},
            }
        );
    }


    /* ESC */
    if (esc[ESC_C164286_0].fault) {
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
    if (esc[ESC_C164286_1].fault) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {1,1,1,1,1,1,1,1,1},
                .scc = {0,0,0,0},
                .sccml = {0},
                .nscc = {0,0},
                .lfa = {0,0},
                .hda = {0,0,0,0},
                .bca = {0,0,0,0},
                .sea = {0},
                .rcca = {0,0},
                .warning = {3,0,0,0,NO_FAULT,0,1},
            }
        );
    }
    if (esc[ESC_C164286_2].fault) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,0,0,0,0,1,1,1},
                .scc = {0,0,0,0},
                .sccml = {0},
                .nscc = {0,0},
                .lfa = {1,1},
                .hda = {1,1,1,1},
                .bca = {0,0,0,0},
                .sea = {0},
                .rcca = {0,0},
                .warning = {0,0,0,0,HDA_LFA_FAULT,5,1},
            }
        );
    }
    if (esc[ESC_NA_0].fault) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {1,1,1,1,1,1,1,1,1},
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
    if (esc[ESC_C16B881_0].fault) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {1,1,1,1,1,1,1,1,1},
                .scc = {0,0,0,0},
                .sccml = {0},
                .nscc = {0,0},
                .lfa = {0,0},
                .hda = {0,0,0,0},
                .bca = {0,0,0,0},
                .sea = {0},
                .rcca = {0,0},
                .warning = {3,0,0,0,NO_FAULT,0,1},
            }
        );
    }
    if (esc[ESC_C136081_0].fault) {
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
    if (esc[ESC_NA_1].fault) {
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
                .warning = {0,0,0,0,HDA_FAULT,5,1},
            }
        );
    }
    if (esc[ESC_C163881_0].fault) {
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
    if (esc[ESC_C164282_0].fault) {
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

    if (esc[ESC_C164281_0].fault) {
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
                .rcca = {0,0},
                .warning = {0,0,0,0,NO_FAULT,0,1},
            }
        );
    }

    /* ICU */
    if (icu[ICU_C183E86_0].fault) {
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

    /* MDPS */
    if (mdps[MDPS_C168886_0].fault || mdps[MDPS_C168886_1].fault) {
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
    if (mdps[MDPS_C223986_0].fault) {
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
    if (mdps[MDPS_C223986_1].fault) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,0,0,0,0,0,0,0},
                .scc = {0,0,0,0},
                .sccml = {0},
                .nscc = {0,0},
                .lfa = {1,1},
                .hda = {1,0,1,1},
                .bca = {1,0,0,0},
                .sea = {0},
                .rcca = {0,0},
                .warning = {0,0,0,0,HDA_LFA_FAULT,5,1},
            }
        );
    }
    /* SAS */
    if (sas[SAS_C181486_0].fault) {
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
    /* SBCM */
    if (mdps[SBCM_C185481_0].fault) {
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
    if (mdps[SBCM_C185381_0].fault) {
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

    /* ICSC */
    if (icsc[ICSC_C187002_0].fault) {
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

    /* YRS */
    if (yrs[YRS_C184286_0].fault) {
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

    /* SWRC */
    if (swrc[SWRC_C183D82_0].fault) {
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

#elif CCAN == HSCAN
    /* CGW */
    if (cgw[CGW_C181786_0].fault) {
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

    /* CLU */
    if (clu[CLU_C165686_0].fault) {
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
    if (clu[CLU_C165686_1].fault) {
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

    /* ESC */
    if (esc[ESC_C164286_0].fault) {
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
    if (esc[ESC_C164286_1].fault) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {1,1,1,1,1,1,1,1,1},
                .scc = {0,0,0,0},
                .sccml = {0},
                .nscc = {0,0},
                .lfa = {0,0},
                .hda = {0,0,0,0},
                .warning = {3,0,0,0,NO_FAULT,0},
            }
        );
    }
    if (esc[ESC_NA_0].fault) {
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
    if (esc[ESC_C16B881_0].fault) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {1,1,1,1,1,1,1,1,1},
                .scc = {0,0,0,0},
                .sccml = {0},
                .nscc = {0,0},
                .lfa = {0,0},
                .hda = {0,0,0,0},
                .warning = {3,0,0,0,NO_FAULT,0},
            }
        );
    }
    if (esc[ESC_C136081_0].fault) {
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
    if (esc[ESC_NA_1].fault) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,0,0,0,0,0,0,0},
                .scc = {1,1,1,1},
                .sccml = {1},
                .nscc = {1,1},
                .lfa = {0,0},
                .hda = {0,1,1,1},
                .warning = {0,0,0,0,HDA_FAULT,5},
            }
        );
    }
    if (esc[ESC_C163881_0].fault) {
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

    /* MDPS */
    if (mdps[MDPS_C168886_0].fault || mdps[MDPS_C168886_1].fault) {
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
    if (mdps[MDPS_C223986_0].fault) {
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

    /* SAS */
    if (sas[SAS_C181486_0].fault) {
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

    /* EMS */
    if (ems[EMS_C161386_0].fault) {
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
    if (ems[EMS_C161386_1].fault) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {1,1,1,1,1,1,1,1,1},
                .scc = {0,0,0,0},
                .sccml = {0},
                .nscc = {0,0},
                .lfa = {0,0},
                .hda = {0,0,0,0},
                .warning = {3,0,0,0,NO_FAULT,0},
            }
        );
    }

    /* TCU */
    if (tcu[TCU_C164686_0].fault) {
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
#endif /* CCAN */

    /* Navi */
    if (navi[NAVI_C174686_0].fault) {
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
    if (navi[NAVI_C183186_0].fault) {
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
    if (navi[NAVI_C183186_1].fault) {
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
#endif /* CCAN */
    /* Front Camera */
    if (fr_cmr[FR_CMR_28B086_0].fault) {
        update_inhibit_info(
            (struct inhibit_info) {
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
    if (fr_cmr[FR_CMR_28B086_1].fault) {
        update_inhibit_info(
            (struct inhibit_info) {
                .fca = {0,0,0,0,0,0,0,0,0},
                .scc = {0,0,0,0},
                .sccml = {0},
                .nscc = {0,0},
                .lfa = {1,1},
                .hda = {1,0,1,1},
                .bca = {0,0,0,0},
                .sea = {0},
                .rcca = {0,0},
                .warning = {0,0,0,0,HDA_LFA_FAULT,5,1},
            }
        );
    }
    if (fr_cmr[FR_CMR_NA_0].fault) {
        update_inhibit_info(
            (struct inhibit_info) {
                .fca = {0,1,1,1,1,1,1,1,1},
                .scc = {0,0,1,1},
                .sccml = {0},
                .nscc = {0,1},
                .lfa = {1,1},
                .hda = {1,0,1,1},
                .bca = {1,0,0,0},
                .sea = {0},
                .rcca = {0,0},
                .warning = {5,0,0,0,HDA_LFA_FAULT,5,1},
            }
        );
    }
    /* Front Radar */
    if (fr_rdr[FR_RDR_C28B186_0].fault) {
        chk_rdr_inhibit = TRUE;
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
    if (fr_rdr[FR_RDR_NA_0].fault) {
        chk_rdr_inhibit = TRUE;
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
                .warning = {6,2,0,0,HDA_FAULT,5,1},
            }
        );
    }

    /* Front Corner Radar */
        if (fr_c_rdr[FR_C_RDR_C188186_0].fault) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,1,0,1,1,1,1,1},
                .scc = {0,0,0,1},
                .sccml = {0},
                .nscc = {0,1},
                .lfa = {0,0},
                .hda = {0,0,0,1},
                .bca = {1,0,1,0},
                .sea = {0},
                .rcca = {0,0},
                .warning = {3,0,0,0,NO_FAULT,5,1},
            }
        );
    }
    if (fr_c_rdr[FR_C_RDR_C188186_1].fault) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,1,0,0,0,1,1,1},
                .scc = {0,0,0,0},
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
    if (fr_c_rdr[FR_C_RDR_NA_0].fault) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,1,0,1,1,1,1,1},
                .scc = {0,0,0,1},
                .sccml = {0},
                .nscc = {0,1},
                .lfa = {0,0},
                .hda = {0,0,0,1},
                .bca = {0,1,0,1},
                .sea = {0},
                .rcca = {0,0},
                .warning = {6,0,0,0,NO_FAULT,5,1},
            }
        );
    }
    if (fr_c_rdr[FR_C_RDR_NA_1].fault) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {0,0,1,0,0,0,1,1,1},
                .scc = {0,0,0,0},
                .sccml = {0},
                .nscc = {0,1},
                .lfa = {0,0},
                .hda = {0,0,0,1},
                .bca = {0,1,0,1},
                .sea = {1},
                .rcca = {0,1},
                .warning = {6,0,0,0,NO_FAULT,5,1},
            }
        );
    }
}

void FS_Clear_InvalidSignal(void)
{
#if CCAN == CANFD
#if VEH_TYPE == NORMAL
    memset(ems, 0, sizeof(ems));
    memset(tcu, 0, sizeof(tcu));
#elif VEH_TYPE == EV
    memset(vcu, 0, sizeof(vcu));
#elif VEH_TYPE == HEV
    memset(ems, 0, sizeof(ems));
    memset(hcu, 0, sizeof(hcu));
    memset(htcu, 0, sizeof(htcu));
#endif /* VEH_TYPE */
    memset(bcm, 0, sizeof(bcm));
    memset(clu, 0, sizeof(clu));
    memset(esc, 0, sizeof(esc));
    memset(icu, 0, sizeof(icu));
    memset(icsc, 0, sizeof(icsc));
    memset(mdps, 0, sizeof(mdps));
    memset(sas, 0, sizeof(sas));
    memset(sbcm, 0, sizeof(sbcm));
    memset(yrs, 0, sizeof(yrs));
    memset(swrc, 0, sizeof(swrc));

#elif CCAN == HSCAN
    memset(ems, 0, sizeof(ems));
    memset(tcu, 0, sizeof(tcu));
    memset(cgw, 0, sizeof(cgw));
    memset(clu, 0, sizeof(clu));
    memset(esc, 0, sizeof(esc));
    memset(mdps, 0, sizeof(mdps));
    memset(sas, 0, sizeof(sas));
#endif /* CCAN */

    memset(navi, 0, sizeof(navi));
    memset(fr_cmr, 0, sizeof(fr_cmr));
    memset(fr_rdr, 0, sizeof(fr_rdr));
    memset(fr_c_rdr, 0, sizeof(fr_c_rdr));
}