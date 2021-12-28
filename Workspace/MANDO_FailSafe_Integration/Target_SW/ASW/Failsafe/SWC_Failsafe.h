#ifndef FAILSAFE_H
#define FAILSAFE_H

#include "Platform_Types.h"
#include "DRV_par.h"

#define BIT(nr) (1UL << (nr))
#define CLEAR_BIT(nr) (0UL << (nr))

#define TEST_BIT(var,nr) ((var) & ((uint8)((0x01U) << (nr))))
#define ARRAY_SIZE(x) (sizeof((x))/sizeof((x)[0]))
#define MS2TICK(ms) ((ms) / 10UL)

#define SET_DTC(DTC, FAULT_CONDITION) \
    Rte_Call_Event_DEM_E_UDS_DTC_##DTC##_SetEventStatus((FAULT_CONDITION) ? DEM_EVENT_STATUS_FAILED : DEM_EVENT_STATUS_PASSED)

#define IGN_ON_DELAY  3000  // ms
#define IGN_OFF_DELAY 180000 // ms
#define BAT_VOL_UPPER 16000 // mV
#define BAT_VOL_LOWER 9000  // mV
#define ERR_CNT_THR   3

#define FS_DEBUG    0

struct internal_error_info {
    uint8 hw_err_cnt;
    uint8 sw_err_cnt;
    struct {
        uint8 ag_idx;
        uint32 alarm;
    } hw_err[12];
    struct {
        uint8 error_code;
        uint8 task_id;
    } sw_err[5];
};

struct reference_signal {
#if VEH_TYPE == NORMAL
    /* EMS */
    uint8 ENG_EngSpdErrSta;      // EMS_01_10ms
    uint8 ENG_IsgSta;            // EMS_01_10ms
    uint8 ENG_EngSta;            // EMS_02_10ms
    uint16 ENG_AccelPdlVal;      // EMS_02_10ms
    uint8 ENG_AppAccelPdlSta;    // EMS_02_10ms
    uint8 CF_ECU_SSC_STAT;       // EMS_03_10ms
    /* TCU */
    uint8 TCU_GearSlctDis;       // TCU_01_10ms
#elif VEH_TYPE == EV
    /* VCU */
    uint8 VCU_EvDrvRdySta;       // VCU_01_10ms
    uint8 VCU_GearPosSta;        // VCU_01_10ms
    uint8 VCU_AccPedDepVal;      // VCU_01_10ms
#elif VEH_TYPE == HEV
    /* EMS */
    uint16 HEV_AccelPdlVal;      // EMS_07_10ms
    uint8 HEV_EngSpdErrSta;      // EMS_11_10ms
    /* HCU */
    uint8 HCU_HevRdySta;         // HCU_03_10ms
    /* HTCU */
    uint8 HTCU_GearSlctrDis;     // HTCU_04_10ms
#endif /* VEH_TYPE */
    /* BCM */
    uint8 BCM_Ign1InSta;         // BCM_02_200ms
    /* SBCM */
    uint8 SBCM_AST_DiagSta;      // SBCM_AST_02_200ms
    uint8 SBCM_DRV_DiagSta;      // SBCM_DRV_01_200ms
    /* CLU */
    uint16 CLU_DisSpdVal;        // CLU_01_20ms
    uint8 CLU_HDALCFuncOnSetReq; // CLU_11_00ms
    /* ESC */
    uint8 ABS_DiagSta;           // ABS_ESC_01_10ms
    uint8 ESC_CylPrsrSta;        // ESC_01_10ms
    uint16 ESC_CylPrsrVal;       // ESC_01_10ms
    uint8 ESC_IMURstStaAck;      // ESC_01_10ms
    uint8 ESC_Sta;               // ESC_01_10ms
    uint8 FCA_EquipSta;          // ESC_03_20ms
    uint8 FCA_AvlblSta;          // ESC_03_20ms
    uint8 SCC_EnblReq;           // ESC_03_20ms
    uint16 WHL_SpdFLVal;         // WHL_01_10ms
    uint16 WHL_SpdFRVal;         // WHL_01_10ms
    uint16 WHL_SpdRLVal;         // WHL_01_10ms
    uint16 WHL_SpdRRVal;         // WHL_01_10ms
    uint8 WHL_PlsFLVal;          // WHL_01_10ms
    uint8 WHL_PlsFRVal;          // WHL_01_10ms
    uint8 WHL_PlsRLVal;          // WHL_01_10ms
    uint8 WHL_PlsRRVal;          // WHL_01_10ms
    /* MDPS */
    uint16 MDPS_StrTqSnsrVal;    // MDPS_01_10ms
    uint8 MDPS_LkaToiActvSta;    // MDPS_01_10ms
    uint8 MDPS_LkaToiUnblSta;    // MDPS_01_10ms
    uint8 MDPS_LkaToiFltSta;     // MDPS_01_10ms
    uint8 MDPS_LkaFailSta;       // MDPS_01_10ms
    uint8 MDPS_LkaPlgInSta;      // MDPS_01_10ms
    uint8 MDPS_Typ;              // MDPS_01_10ms
    /* SAS */
    sint16 SAS_AnglVal;          // SAS_01_10ms
    uint8 SAS_SpdVal;            // SAS_01_10ms
    /* SWRC */
    uint8 SWRC_LFASwSta;         // SWRC_03_20ms
    /* YRS */
    uint16 YRS_YawRtVal;         // YRS_01_10ms
    uint16 YRS_LongAccelVal;     // YRS_01_10ms
    uint16 YRS_LatAccelVal;      // YRS_01_10ms
    uint8 YRS_AcuRstSta;         // YRS_01_10ms
    /* ICU */
    uint8 ExtLamp_TrnSigLmpLftBlnkngSta; // ICU_04_200ms & used in F010_InputOutput service
    uint8 ExtLamp_TrnSigLmpRtBlnkngSta;  // ICU_04_200ms & used in F010_InputOutput service
    uint8 Lamp_RrTrnSigLmpLftOpnSta;     // ICU_06_200ms
    uint8 Lamp_RrTrnSigLmpRtOpnSta;      // ICU_06_200ms
    uint8 Lamp_FrTrnSigLmpLftOpnSta;     // ICU_06_200ms
    uint8 Lamp_FrTrnSigLmpRtOpnSta;      // ICU_06_200ms

    /* NAVI */
    uint8 HU_NaviStatus;                // HU_CLU_PE_05
    uint8 HU_AliveStatus;               // HU_GW_PE_01
    uint8 HU_AdasSupport;               // HU_MON_PE_01
    uint8 HU_DistributeInfo;            // HU_MON_PE_01
    uint8 HU_NaviHandshakingSupport;    // HU_MON_PE_01
    uint8 HU_Navi_RspADASMapMsg ;       // HU_MON_PE_01
    uint8 POS_CyclicCounter;         // HU_NAVI_V2_POS_PE
    uint8 SEG_CalculatedRoute;       // HU_NAVI_V2_SEG_E

    /* Front Camera */
    uint8 FR_CMR_Genrl_FlInfoSta; // L_FR_CMR_Genrl_01_30ms
    uint8 LFA_ShrtkeySwSta;       // A_FR_CMR_Ctrl_01
    /* Front Radar */
    uint8 FR_RDR_Genrl_FlInfoSta; // L_FR_RDR_Genrl_01_50ms
    /* Front-Rear Corner Radar */
    uint8 FR_C_RDR_LocalFlInfoSta_Flt; // L_FR_C_RDR_Genrl_01_50ms
    uint8 FR_C_RDR_Genrl_FlInfoSta_Blkg; // L_FR_C_RDR_Genrl_01_50ms
};

struct precondition {
    boolean is_norm_vol;
    boolean is_3s_after_ign_on;
    boolean for_3min_after_ign_off;
    boolean is_eng_run;
    boolean is_not_ecan_busoff;
    boolean is_not_acan_busoff;
};


/* HDA_InfoPUDis */
enum {
    NO_FAULT      = 0,
    HDA_FAULT     = 1, // FS_02
    HDA_LFA_FAULT = 2, // FS_01
};

typedef struct {
    uint8 FcaRo_Inhibit;
    uint8 FcaSf2_Inhibit;
    uint8 FcaSf3_Inhibit;
    uint8 FcaSf3_JT_Inhibit;
    uint8 FcaRo_JC_Inhibit;
    uint8 FcaSf3_JC_Inhibit;
    uint8 FcaSf2_Lo_Inhibit;
    uint8 FcaSF3_LS_Inhibit;
    uint8 Fca_ESA_Inhibit;
} fca_inhibit_t;

typedef struct {
    uint8 SccCc_Inhibit;
    uint8 SccRo_Inhibit;
    uint8 SccSf2_Inhibit;
    uint8 SccSf3_Inhibit;
} scc_inhibit_t;

typedef struct {
    uint8 SccMl_Inhibit;
} sccml_inhibit_t;

typedef struct {
    uint8 NScc_Z_C_Inhibit;
    uint8 NScc_R_Inhibit;
} nscc_inhibit_t;

typedef struct {
    uint8 Lfa_Lat_Inhibit;
    uint8 LfaSf2_Inhibit;
} lfa_inhibit_t;

typedef struct {
    uint8 Hda_Lat_Inhibit;
    uint8 Hda_Long_Inhibit;
    uint8 Hda_Inhibit;
    uint8 HdaII_Inhibit;
} hda_inhibit_t;

typedef struct {
    uint8 BCA_Driving_Inhibit;
    uint8 BCA_Driving_RDRBlk_Inhibit;
    uint8 BCA_Plus_ParallelExit_Inhibit;
    uint8 BCA_Plus_ParallelExit_RDRBlk_Inhibit; 
} bca_inhibit_t;

typedef struct {
    uint8 SEA_Inhibit;
} sea_inhibit_t;

typedef struct {
    uint8 RCCA_Inhibit;
    uint8 RCCA_RDRBlk_Inhibit;
} rcca_inhibit_t;

typedef struct {
    uint8 FCA_SysFlrSta;
    uint8 SCC_SysFlrSta;
    uint8 SCCMode_OptUsmSta;
    uint8 SCC_NSCCOnOffSta;
    uint8 HDA_InfoPUDis;
    uint8 HDA_LCFuncSta;
    uint8 BCW_IndSta;
} warning_t;

struct inhibit_info {
    scc_inhibit_t scc;
    sccml_inhibit_t sccml;
    nscc_inhibit_t nscc;
    fca_inhibit_t fca;
    lfa_inhibit_t lfa;
    hda_inhibit_t hda;
    bca_inhibit_t bca;
    sea_inhibit_t sea;
    rcca_inhibit_t rcca;
    warning_t warning;
};


/* Voltage enum */
enum {
    VOL_IGN,
    VOL_IGN_FLAG,
    VOL_BAT,
    VOL_BUCK5P0,
    VOL_PMIC5P0,
    VOL_PMIC3P3,
    VOL_PMIC1P25,
    VOL_BUCKPG5P0,
    VOL_GRP_NUM
};

/* Message type definition */
enum msg_type {
    CHASSIS_0,
    CHASSIS_1,
    L_FR_CMR_0,
    L_FR_RDR_0,    
    L_FR_C_RDR_0,
    L_FR_C_RDR_1,
    L_FR_CMR_1,
    L_FR_CMR_2,
    L_FR_RDR_1,  
    MSG_GRP_NUM,
};

/* Chassis CAN Time-out Flags Bit Position */
enum chassis_0_msgs {
	ABS_ESC_01_10ms_POS,
    BCM_02_200ms_POS,
	BCM_10_200ms_POS,
	CLU_01_20ms_POS,
	CLU_02_100ms_POS,
#if VEH_TYPE == NORMAL
	EMS_01_10ms_POS,
	EMS_02_10ms_POS,
    EMS_03_10ms_POS,
    EMS_05_100ms_POS,
    EMS_08_100ms_POS,
    TCU_01_10ms_POS,
#elif VEH_TYPE == EV
    VCU_01_10ms_POS,
    VCU_03_100ms_POS,
#endif
	ESC_01_10ms_POS,
	ESC_03_20ms_POS,
	HU_CLU_PE_05_POS,
	HU_GW_PE_01_POS,
	HU_MON_PE_01_POS,
    HU_NAVI_V2_POS_PE_POS,
	ICSC_02_100ms_POS,
    ICU_02_200ms_POS,
	ICU_04_200ms_POS,
	ICU_06_200ms_POS,
	ICU_07_200ms_POS,
	MDPS_01_10ms_POS,
    MFSW_01_200ms_POS,
	SAS_01_10ms_POS,
    SBCM_AST_02_200ms_POS,
	SBCM_DRV_01_200ms_POS,
	SWRC_03_20ms_POS,
	WHL_01_10ms_POS,
	YRS_01_10ms_POS,
	CHASSIS_0_NUM
};
extern char compiler_assert_CHASSIS_0_NUM_exceed_32[(CHASSIS_0_NUM > 32) ? (-1) : (1)];

/* Chassis CAN Time-out Flags Bit Position */
enum chassis_1_msgs {
    ADAS_PRK_21_20ms_POS,
	BCM_09_200ms_POS,
    CLU_11_00ms_POS,
    FR_CMR_02_100ms_POS,
	HU_NAVI_V2_META_E_POS,	
	HU_NAVI_V2_PROLONG_E_POS,
	HU_NAVI_V2_PROSHORT_E_00_POS,
	HU_NAVI_V2_PROSHORT_SUB_E_POS,
	HU_NAVI_V2_SEG_E_POS,
	HU_NAVI_V2_SEG_SUB_E_POS,
	HU_NAVI_V2_STUB_E_POS,
#if HU_USM == NOT_APPLIED
    CLU_12_00ms_POS,
    CLU_13_00ms_POS,
#elif HU_USM == APPLIED
	HU_USM_E_01_POS,
	HU_USM_E_02_POS,
	HU_USM_E_04_POS,
	HU_USM_E_08_POS,
#endif
    MFSW_02_200ms_POS,
    RR_C_RDR_03_50ms_POS,
	SBCM_RL_01_200ms_POS,
	SBCM_RR_01_200ms_POS,
	HOD_01_100ms_POS,
	ICU_08_200ms_POS,
	IEB_01_10ms_POS,
	CHASSIS_1_NUM
};
extern char compiler_assert_CHASSIS_1_NUM_exceed_32[(CHASSIS_1_NUM > 32) ? (-1) : (1)];

/* Front Camera CAN Time-out Flags Bit Position */
enum l_fr_cmr_0_msgs {
    A_FR_CMR_Ctrl_01_10ms_POS,
	A_FR_CMR_Genrl_01_30ms_POS,
	A_FR_CMR_Ln_01_50ms_POS,
	A_FR_CMR_Ln_02_50ms_POS,
	A_FR_CMR_Ln_03_50ms_POS,
    A_FR_CMR_Obj_01_30ms_POS,
	A_FR_CMR_Obj_02_30ms_POS,
	A_FR_CMR_Obj_03_30ms_POS,
	A_FR_CMR_Obj_04_30ms_POS,
	A_FR_CMR_Obj_05_30ms_POS,
	A_FR_CMR_Obj_06_30ms_POS,
	A_FR_CMR_Obj_07_30ms_POS,
	A_FR_CMR_Obj_08_30ms_POS,
	A_FR_CMR_Obj_09_30ms_POS,
	A_FR_CMR_Obj_10_30ms_POS,
	A_FR_CMR_Obj_11_30ms_POS,
	A_FR_CMR_Obj_12_30ms_POS,
	A_FR_CMR_Obj_13_30ms_POS,
	A_FR_CMR_Obj_14_30ms_POS,
	A_FR_CMR_Obj_15_30ms_POS,
	A_FR_CMR_Obj_16_30ms_POS,
	A_FR_CMR_Obj_17_30ms_POS,
	A_FR_CMR_Obj_18_30ms_POS,
	A_FR_CMR_Obj_19_30ms_POS,
	A_FR_CMR_Obj_20_30ms_POS,
    A_FR_CMR_FS_01_30ms_POS,
	A_FR_CMR_FS_02_30ms_POS,
	A_FR_CMR_FS_03_30ms_POS,
	A_FR_CMR_FS_04_30ms_POS,
	A_FR_CMR_FS_05_30ms_POS,
	A_FR_CMR_FS_06_30ms_POS,
    A_FR_CMR_FS_07_30ms_POS,
    L_FR_CMR_0_NUM,
};
extern char compiler_assert_L_FR_CMR_0_NUM_exceed_32[(L_FR_CMR_0_NUM > 32) ? (-1) : (1)];

enum l_fr_cmr_1_msgs {    
    A_FR_CMR_FS_08_30ms_POS,
	A_FR_CMR_FS_09_30ms_POS,
	A_FR_CMR_FS_10_30ms_POS,
	A_FR_CMR_FS_11_30ms_POS,
	A_FR_CMR_FS_12_30ms_POS,
	A_FR_CMR_FS_13_30ms_POS,
	A_FR_CMR_FS_14_30ms_POS,
	A_FR_CMR_FS_15_30ms_POS,
	A_FR_CMR_FS_16_30ms_POS,
	A_FR_CMR_FS_17_30ms_POS,
	A_FR_CMR_FS_18_30ms_POS,
	A_FR_CMR_FS_19_30ms_POS,
	A_FR_CMR_FS_20_30ms_POS,
	A_FR_CMR_FS_21_30ms_POS,
	A_FR_CMR_FS_22_30ms_POS,
	A_FR_CMR_FS_23_30ms_POS,
	A_FR_CMR_FS_24_30ms_POS,    
    L_FR_CMR_1_NUM,
};
extern char compiler_assert_L_FR_CMR_1_NUM_exceed_32[(L_FR_CMR_1_NUM > 32) ? (-1) : (1)];

enum l_fr_cmr_2_msgs {
    A_FR_CMR_PP_Genrl_01_50ms_POS,
    A_FR_CMR_Ctrl_02_20ms_POS,
	A_FR_CMR_PP_Ln_01_50ms_POS,
	A_FR_CMR_PP_Ln_02_50ms_POS,
    A_FR_CMR_RoadMrk_01_50ms_POS,
    A_FR_CMR_RoadMrk_02_50ms_POS,
    A_FR_CMR_RoadMrk_03_50ms_POS,
    A_FR_CMR_RoadMrk_04_50ms_POS,
    A_FR_CMR_RoadMrk_05_50ms_POS,
    A_FR_CMR_TSR_01_50ms_POS,
    A_FR_CMR_TSR_02_50ms_POS,    
    A_FR_CMR_TSR_03_50ms_POS,
    A_FR_CMR_TSR_04_50ms_POS,
    A_FR_CMR_TSR_05_50ms_POS,
    L_FR_CMR_2_NUM,
};
extern char compiler_assert_L_FR_CMR_2_NUM_exceed_32[(L_FR_CMR_2_NUM > 32) ? (-1) : (1)];

/* Front Radar CAN Time-out Flags Bit Position */

enum l_fr_rdr_0_msgs {
    A_FR_RDR_Genrl_01_50ms_POS,
	A_FR_RDR_Genrl_02_50ms_POS,
    A_FR_RDR_ODM_01_50ms_POS,
    A_FR_RDR_Obj_01_50ms_POS,
	A_FR_RDR_Obj_02_50ms_POS,
	A_FR_RDR_Obj_03_50ms_POS,
	A_FR_RDR_Obj_04_50ms_POS,
	A_FR_RDR_Obj_05_50ms_POS,
	A_FR_RDR_Obj_06_50ms_POS,
	A_FR_RDR_Obj_07_50ms_POS,
	A_FR_RDR_Obj_08_50ms_POS,
	A_FR_RDR_Obj_09_50ms_POS,
	A_FR_RDR_Obj_10_50ms_POS,
	A_FR_RDR_Obj_11_50ms_POS,
	A_FR_RDR_Obj_12_50ms_POS,
	A_FR_RDR_Obj_13_50ms_POS,
	A_FR_RDR_Obj_14_50ms_POS,
	A_FR_RDR_Obj_15_50ms_POS,
	A_FR_RDR_Obj_16_50ms_POS,
	A_FR_RDR_Obj_17_50ms_POS,
	A_FR_RDR_Obj_18_50ms_POS,
	A_FR_RDR_Obj_19_50ms_POS,
	A_FR_RDR_Obj_20_50ms_POS,
	A_FR_RDR_Obj_21_50ms_POS,
	A_FR_RDR_Obj_22_50ms_POS,
	A_FR_RDR_Obj_23_50ms_POS,
	A_FR_RDR_Obj_24_50ms_POS,
	A_FR_RDR_Obj_25_50ms_POS,
	A_FR_RDR_Obj_26_50ms_POS,
	A_FR_RDR_Obj_27_50ms_POS,
	A_FR_RDR_Obj_28_50ms_POS,
	A_FR_RDR_Obj_29_50ms_POS,
    L_FR_RDR_0_NUM,
};
extern char compiler_assert_L_FR_RDR_0_NUM_exceed_32[(L_FR_RDR_0_NUM > 32) ? (-1) : (1)];

enum l_fr_rdr_1_msgs {
    A_FR_RDR_Obj_30_50ms_POS,
	A_FR_RDR_Obj_31_50ms_POS,
	A_FR_RDR_Obj_32_50ms_POS,
    A_FR_RDR_FS_01_50ms_POS,
	A_FR_RDR_FS_02_50ms_POS,
	A_FR_RDR_FS_03_50ms_POS,
	A_FR_RDR_FS_04_50ms_POS,
	A_FR_RDR_FS_05_50ms_POS,
    L_FR_RDR_1_NUM,
};
extern char compiler_assert_L_FR_RDR_1_NUM_exceed_32[(L_FR_RDR_1_NUM > 32) ? (-1) : (1)];

/* Front Corner Radar CAN Time-out Flags Bit Position */
enum l_fr_c_rdr_0_msgs {
	A_FR_C_RDR_Genrl_01_50ms_POS,
	A_FR_C_RDR_ODM_01_50ms_POS,
	A_FR_C_RDR_Obj_01_50ms_POS,
	A_FR_C_RDR_Obj_02_50ms_POS,
	A_FR_C_RDR_Obj_03_50ms_POS,
	A_FR_C_RDR_Obj_04_50ms_POS,
	A_FR_C_RDR_Obj_05_50ms_POS,
	A_FR_C_RDR_Obj_06_50ms_POS,
	A_FR_C_RDR_Obj_07_50ms_POS,
	A_FR_C_RDR_Obj_08_50ms_POS,
	A_FR_C_RDR_Obj_09_50ms_POS,
	A_FR_C_RDR_Obj_10_50ms_POS,
	A_FR_C_RDR_Obj_11_50ms_POS,
	A_FR_C_RDR_Obj_12_50ms_POS,
	A_FR_C_RDR_Obj_13_50ms_POS,
	A_FR_C_RDR_Obj_14_50ms_POS,
	A_FR_C_RDR_Obj_15_50ms_POS,
	A_FR_C_RDR_Obj_16_50ms_POS,
	A_FR_C_RDR_Obj_17_50ms_POS,
	A_FR_C_RDR_Obj_18_50ms_POS,
	A_FR_C_RDR_Obj_19_50ms_POS,
	A_FR_C_RDR_Obj_20_50ms_POS,
	A_FR_C_RDR_Obj_21_50ms_POS,
	A_FR_C_RDR_Obj_22_50ms_POS,
	A_FR_C_RDR_Obj_23_50ms_POS,
	A_FR_C_RDR_Obj_24_50ms_POS,
	A_FR_C_RDR_Obj_25_50ms_POS,
	A_FR_C_RDR_Obj_26_50ms_POS,
	A_FR_C_RDR_Obj_27_50ms_POS,
	A_FR_C_RDR_Obj_28_50ms_POS,
	A_FR_C_RDR_Obj_29_50ms_POS,
	A_FR_C_RDR_Obj_30_50ms_POS,
    L_FR_C_RDR_0_NUM,
};
extern char compiler_assert_L_FR_C_RDR_0_NUM_exceed_32[(L_FR_C_RDR_0_NUM > 32) ? (-1) : (1)];

enum l_fr_c_rdr_1_msgs {
    A_FR_C_RDR_LH_FS_01_50ms_POS,
	A_FR_C_RDR_LH_FS_02_50ms_POS,
	A_FR_C_RDR_LH_FS_03_50ms_POS,
	A_FR_C_RDR_LH_FS_04_50ms_POS,
	A_FR_C_RDR_LH_FS_05_50ms_POS,
	A_FR_C_RDR_LH_FS_06_50ms_POS,
	A_FR_C_RDR_LH_FS_07_50ms_POS,
	A_FR_C_RDR_LH_FS_08_50ms_POS,
	A_FR_C_RDR_RH_FS_01_50ms_POS,
	A_FR_C_RDR_RH_FS_02_50ms_POS,
	A_FR_C_RDR_RH_FS_03_50ms_POS,
	A_FR_C_RDR_RH_FS_04_50ms_POS,
	A_FR_C_RDR_RH_FS_05_50ms_POS,
	A_FR_C_RDR_RH_FS_06_50ms_POS,
	A_FR_C_RDR_RH_FS_07_50ms_POS,
	A_FR_C_RDR_RH_FS_08_50ms_POS,
    L_FR_C_RDR_1_NUM,
};
extern char compiler_assert_L_FR_C_RDR_1_NUM_exceed_32[(L_FR_C_RDR_1_NUM > 32) ? (-1) : (1)];

/* Forcing Recover */
enum {
    RECOVER_GROUP_0,
    RECOVER_GROUP_1,
    RECOVER_GROUP_2,
    RECOVER_GROUP_3,
    RECOVER_GROUP_4,
    RECOVER_GROUP_5,
    RECOVER_GROUP_6,
    RECOVER_GROUP_7,
    RECOVER_GROUP_NUM,
};
extern uint8 recover_mask[RECOVER_GROUP_NUM];

/* Recover group 0 */
enum {
    VOL_HIGH,
    VOL_LOW,
    ECAN_BUSOFF,
    ACAN_BUSOFF,
    GROUP_0_NUM,
};
extern char compiler_assert_GROUP_0_exceed_8[(GROUP_0_NUM > 8) ? (-1) : (1)];

/* Recover group 1 */
enum {
#if CCAN == CANFD
    ABS_ESC_TIMEOUT,
    VCU_HCU_TIMEOUT,
    BCM_TIMEOUT,
    CLU_TIMEOUT,
    EMS_TIMEOUT,
    ESC_TIMEOUT,
    FR_CMR_TIMEOUT,
    FR_RDR_TIMEOUT,
#elif CCAN == HSCAN
    CGW1_TIMEOUT,
    CGW2_TIMEOUT,
    CGW8_TIMEOUT,
    CGW_PC4_TIMEOUT,
    CGW_PC5_TIMEOUT,
    CLU11_TIMEOUT,
    CLU13_TIMEOUT,
    EMS12_TIMEOUT,
#endif /* CCAN */
    GROUP_1_NUM,
};
extern char compiler_assert_GROUP_1_exceed_8[(GROUP_1_NUM > 8) ? (-1) : (1)];

/* Recover group 2 */
enum {
#if CCAN == CANFD
    HU_CLU_PE_TIMEOUT,
    HU_GW_PE_TIMEOUT,
    HU_MON_PE_TIMEOUT,
    HU_NAVI_V2_POS_PE_TIMEOUT,
    ICSC_TIMEOUT,
    ICU_TIMEOUT,
    MDPS_TIMEOUT,
    MFSW_TIMEOUT,
#elif CCAN == HSCAN
    EMS16_TIMEOUT,
    ESP12_TIMEOUT,
    HU_CLU_PE_05_TIMEOUT,
    HU_GW_PE_01_TIMEOUT,
    HU_MON_PE_01_TIMEOUT,
    MDPS11_TIMEOUT,
    MDPS12_TIMEOUT,
    NAVI_V2_POS_E_POS_TIMEOUT,
#endif /* CCAN */
    GROUP_2_NUM,
};
extern char compiler_assert_GROUP_2_exceed_8[(GROUP_2_NUM > 8) ? (-1) : (1)];

/* Recover group 3 */
enum {
#if CCAN == CANFD
    RR_C_RDR_TIMEOUT,
    SAS_TIMEOUT,
    SWRC_TIMEOUT,
    TCU_TIMEOUT,
    WHL_TIMEOUT,
    YRS_TIMEOUT,
    SBCM_TIMEOUT,
#elif CCAN == HSCAN
    P_STS_TIMEOUT,
    RR_C_RDR_02_TIMEOUT,
    SAS11_TIMEOUT,
    TCS11_TIMEOUT,
    TCS13_TIMEOUT,
    VSM11_TIMEOUT,
    WHL_SPD11_TIMEOUT,
#endif /* CCAN */
    GROUP_3_NUM,
};
extern char compiler_assert_GROUP_3_exceed_8[(GROUP_3_NUM > 8) ? (-1) : (1)];

/* Recover group 4 */
enum {
    L_FR_CMR_TIMEOUT,
    L_FR_RDR_TIMEOUT,
    L_FR_C_RDR_TIMEOUT,
    GROUP_4_NUM,
};
extern char compiler_assert_GROUP_4_exceed_8[(GROUP_4_NUM > 8) ? (-1) : (1)];

/* Recover group 5 */
enum {
#if CCAN == CANFD
    CLU_INVALID_SIGNAL,
    ESC_INVALID_SIGNAL,
    MDPS_INVALID_SIGNAL,
    SAS_INVALID_SIGNAL,
    EMS_INVALID_SIGNAL,
    TCU_INVALID_SIGNAL,
    YRS_INVALID_SIGNAL,
    SWRC_INVALID_SIGNAL,
#elif CCAN == HSCAN
    CGW_INVALID_SIGNAL,
    CLU_INVALID_SIGNAL,
    ESC_INVALID_SIGNAL,
    MDPS_INVALID_SIGNAL,
    SAS_INVALID_SIGNAL,
    EMS_INVALID_SIGNAL,
    TCU_INVALID_SIGNAL,
    NAVI_INVALID_SIGNAL,
#endif /* CCAN */
    GROUP_5_NUM,
};
extern char compiler_assert_GROUP_5_exceed_8[(GROUP_5_NUM > 8) ? (-1) : (1)];

/* Recover group 6 */
enum {
#if CCAN == CANFD
    VCU_HCU_INVALID_SIGNAL,
    ICSC_INVALID_SIGNAL,
    ICU_INVALID_SIGNAL,
    NAVI_INVALID_SIGNAL,
    FR_CMR_INVALID_SIGNAL,
    FR_RDR_INVALID_SIGNAL,
    FR_C_RDR_INVALID_SIGNAL,
#elif CCAN == HSCAN
    FR_CMR_INVALID_SIGNAL,
    FR_RDR_INVALID_SIGNAL,
    FR_C_RDR_INVALID_SIGNAL,
    RESERVED2,
    RESERVED3,
    RESERVED4,
    RESERVED5,
    RESERVED6,
#endif /* CCAN */
    GROUP_6_NUM,
};
extern char compiler_assert_GROUP_6_exceed_8[(GROUP_6_NUM > 8) ? (-1) : (1)];

/* Recover group 7 */
enum {
    GROUP_7_NUM,
};
extern char compiler_assert_GROUP_7_exceed_8[(GROUP_7_NUM > 8) ? (-1) : (1)];


/* Failsafe */
extern struct internal_error_info int_err_info;
extern volatile struct reference_signal ref_sig;
extern uint16 vol_grp[VOL_GRP_NUM];
extern boolean internal_sw_fault;
extern boolean internal_hw_fault;
extern uint32 can_timeout_fault[MSG_GRP_NUM];
extern boolean clear_dtc;

void FS_Init(void);
void FS_MasterLoop(void);
void update_inhibit_info(struct inhibit_info new);
void store_in_nvm(void);
struct precondition *get_precond_ptr(void);
struct inhibit_info *get_inhibit_ptr(void);
boolean Get_NAVI_Option(void);
boolean Get_HDA2_Option(void);
boolean Get_BCA_Option(void);
boolean Get_SEA_Option(void);
boolean Get_RCCW_Option(void);


static inline boolean is_timeout(uint8 msg_grp, uint8 pos)
{
    return !!(can_timeout_fault[msg_grp] & BIT(pos));
}

static inline boolean internal_error_occurred(void)
{
    return !!(int_err_info.hw_err_cnt > ERR_CNT_THR || int_err_info.sw_err_cnt > ERR_CNT_THR);
}


/* SWC_ISR */
extern volatile uint32 e2e_err_flags[MSG_GRP_NUM];
extern volatile uint32 msg_received_flags[MSG_GRP_NUM]; 
extern volatile uint32 msg_received_bus[MSG_GRP_NUM];

static inline boolean is_updated(uint8 msg_grp, uint8 pos)
{
    return !!(msg_received_flags[msg_grp] & BIT(pos));
}

static inline boolean is_e2e_err(uint8 msg_grp, uint8 pos)
{
    return !!(e2e_err_flags[msg_grp] & BIT(pos));
}

#endif  /* FAILSAFE_H */
