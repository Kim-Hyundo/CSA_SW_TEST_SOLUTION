
/*******************************************************************************
(C) 2012 KPIT Cummins Infosystems Limited, Hyundai Motor Company,             **
**  Hyundai MOBIS Company and KEFICO Corporation                              **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: App_NvM_Ram.h                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR NvM Module                                            **
**                                                                            **
**  PURPOSE   : C header for App_NvM_Sub_Functions.c                          **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By             Description                         **
********************************************************************************
** 1.0.0     29-Dec-2012   AJAMEERPASHA   Initial Version                     **
*******************************************************************************/
#ifndef APP_NVM_RAM_H
#define APP_NVM_RAM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
#include "Dem_Ram.h"

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/
enum {
    NvM_IDC_DCD,
    NvM_IDC_USM,
    NvM_VDISP,
    NvM_IDS,
    NvM_FAILSAFE,
    NvM_VARIANT_CODE,
    NvM_VARIANT_CODE_W,
    NvM_SystemVariable,
    NvM_Traceability,
    NvM_NUM,
};

#define IDC_DCD_MEM_SIZE        308
#define IDC_USM_MEM_SIZE        12
#define VDISP_MEM_SIZE          8
#define IDS_MEM_SIZE            8
#define FAILSAFE_MEM_SIZE       112
#define VARIANT_CODE_MEM_SIZE   4
#define VARIANT_CODE_W_MEM_SIZE 2
#define SYS_VAR_MEM_SIZE        4
#define TRACEABILITY_MEM_SIZE   36

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
typedef volatile struct {
    boolean busy;
    boolean wr_req;
} nvm_info_t;

extern boolean nvm_loaded;
extern boolean nvm_erase;
extern nvm_info_t nvm_info[NvM_NUM];


extern uint8 NvMBlock_IntTst_TestBlock1_Ram_Block[10];
extern uint8 NvMBlock_IntTst_TestBlock2_Ram_Block[10];

extern uint8 NvMBlock_IDC_DCD_Segment_RamBlock[IDC_DCD_MEM_SIZE];
extern uint8 NvMBlock_IDC_DCD_Segment_DefaultBlock[IDC_DCD_MEM_SIZE];

extern uint8 NvMBlock_IDC_USM_Segment_RamBlock[IDC_USM_MEM_SIZE];
extern uint8 NvMBlock_IDC_USM_Segment_DefaultBlock[IDC_USM_MEM_SIZE];

extern uint8 NvMBlock_VDISP_Segment_RamBlock[VDISP_MEM_SIZE];
extern uint8 NvMBlock_VDISP_Segment_DefaultBlock[VDISP_MEM_SIZE];

extern uint8 NvMBlock_IDS_Segment_RamBlock[IDS_MEM_SIZE];
extern uint8 NvMBlock_IDS_Segment_DefaultBlock[IDS_MEM_SIZE];

extern uint8 NvMBlock_Failsafe_Segment_RamBlock[FAILSAFE_MEM_SIZE];
extern uint8 NvMBlock_Failsafe_Segment_DefaultBlock[FAILSAFE_MEM_SIZE];

extern uint8 NvMBlock_Variant_Code_Segment_RamBlock[VARIANT_CODE_MEM_SIZE];
extern uint8 NvMBlock_Variant_Code_Segment_DefaultBlock[VARIANT_CODE_MEM_SIZE];

extern uint8 NvMBlock_Variant_Code_W_Segment_RamBlock[VARIANT_CODE_W_MEM_SIZE];
extern uint8 NvMBlock_Variant_Code_W_Segment_DefaultBlock[VARIANT_CODE_W_MEM_SIZE];

extern uint8 NvMBlock_SystemVariable_Segment_RamBlock[SYS_VAR_MEM_SIZE];
extern uint8 NvMBlock_SystemVariable_Segment_DefaultBlock[SYS_VAR_MEM_SIZE];

extern uint8 NvMBlock_Traceability_Segment_RamBlock[TRACEABILITY_MEM_SIZE];
extern uint8 NvMBlock_Traceability_Segment_DefaultBlock[TRACEABILITY_MEM_SIZE];


enum {
	Region__All = 0,
	Region__Korea = 1,
	Region__Normal = 2,
	Region__MiddleEast = 3,
	Region__Europe = 4,
	Region__Australia = 5,
	Region__Canada = 6,
	Region__US = 7,
	Region__China = 8,
	Region__Russia = 9,
	Region__India = 10,
	Region__Brazil = 11,
	Region__Mexico = 12,
	Region__Turkey = 13,
	Region__EastWestEurope = 14,
	Region__Vietnam = 15,
	Region__Indonesia = 16,
};

enum {
    VT__All = 0,
    VT__Type1 = 1,
    VT__Type2 = 2,
    VT__Type3 = 3,
    VT__Type4 = 4,
    VT__Type5 = 5,
    VT__Type6 = 6,
};

enum {
	MDPS__All = 0,
	MDPS__C_Type = 1,
	MDPS__R_Type = 2,
};

enum {
    ISG__NA = 0,
    ISG__Applied = 1,
};

enum {
	TA__AT = 0,
	TA__MT = 1,
};

enum {
    DT__LHD = 0,
    DT__RHD = 1,
};

enum {
    BT_All = 0,
    BT__Type1 = 1,
    BT__Type2 = 2,
    BT__Type3 = 3,
};

enum {
    NSCC_HDA2__NA = 0,
    NSCC_HDA2__NSCC_Z_HDA2 = 1,
    NSCC_HDA2__NSCC_ZC_HDA2 = 2,
    NSCC_HDA2__NSCC_ZCR_HDA2 = 3,
    NSCC_HDA2__NSCC_C_HDA2 = 4,
    NSCC_HDA2__NSCC_CR_HDA2 = 5,
};

enum { /* FCA-JT/JC, FCA-LO/LS, FCA w/ ESA */
    FUNCTION_SET_1__NA = 0,
    FUNCTION_SET_1__APPLIED = 1,
};

enum { /* FCA-CAR/PED/CYC, SCC w/ S&G, LFA */
    FUNCTION_SET_2__NA = 0,
    FUNCTION_SET_2__APPLIED = 1,
};


/* Variant Code */
typedef struct {
    /* Byte 0 */
    uint32 NvM_Block_Region:5;
    uint32 NvM_Block_Vehicle_Type:3;

    /* Byte 1 */
    uint32 NvM_Block_MDPS_Type:2;
    uint32 NvM_Block_ISG_Option:1;
    uint32 NvM_Block_Transmission_Option:2;
    uint32 NvM_Block_Body_Type:2;
    uint32 NvM_Block_Drive_Type:1;

    /* Byte 2 */
    uint32 RESERVED_0:1;
    uint32 NvM_Block_NSCC_HDA2_Option:4;
    uint32 NvM_Block_DRV_FUNCTION_SET_1:1;
    uint32 NvM_Block_DRV_FUNCTION_SET_2:1;
    uint32 RESERVED_1:1;

    /* Byte 3 */
    uint8 RESERVED_2;
} variant_code_t;

typedef union {
    struct {
        uint8 NvM_u8_DCD_CutoutAccelTimeCurrentPattern_SEGMENT;
        uint8 NvM_u8_DCD_NoCarAccelCurrentPattern_SEGMENT;
        uint8 NvM_u8_DCD_HeadwayDistCurrentPattern_SEGMENT;
        uint8 NvM_u8_DCD_FollowingAccelCurrentPattern_SEGMENT;
        uint8 NvM_DataBuf_BUS_1_Y_SEGMENT[40];
        uint8 NvM_DataBuf_BUS_2_Y_SEGMENT[40];
        uint8 NvM_DataBuf_BUS_2_MovMaxAvg_Y_Array_SEGMENT[40];
        uint8 NvM_DataBuf_BUS_3_Y_SEGMENT[40];
        uint8 NvM_DataBuf_BUS_4_Y_SEGMENT[40];
        uint8 NvM_DataBuf_BUS_1_MovAvg_i_SUB_Array_SEGMENT[20];
        uint8 NvM_DataBuf_BUS_2_MovAvg_i_SUB_Array_SEGMENT[20];
        uint8 NvM_DataBuf_BUS_3_MovAvg_i_SUB_Array_SEGMENT[20];
        uint8 NvM_DataBuf_BUS_4_MovAvg_i_SUB_Array_SEGMENT[20];
        uint8 NvM_u16_DCD_CutoutAccelTime_LS_i_SEGMENT[2];
        uint8 NvM_u16_DCD_CutoutAccelTime_MS_i_SEGMENT[2];
        uint8 NvM_u16_DCD_CutoutAccelTime_HS_i_SEGMENT[2];
        uint8 NvM_u16_DCD_NoCarAccel_LS_i_SEGMENT[2];
        uint8 NvM_u16_DCD_NoCarAccel_MS_i_SEGMENT[2];
        uint8 NvM_u16_DCD_NoCarAccel_HS_i_SEGMENT[2];
        uint8 NvM_u16_DCD_HeadwayDist_LS_i_SEGMENT[2];
        uint8 NvM_u16_DCD_HeadwayDist_MS_i_SEGMENT[2];
        uint8 NvM_u16_DCD_HeadwayDist_HS_i_SEGMENT[2];
        uint8 NvM_u16_DCD_FollowingAccel_LS_i_SEGMENT[2];
        uint8 NvM_u16_DCD_FollowingAccel_MS_i_SEGMENT[2];
        uint8 NvM_u16_DCD_FollowingAccel_HS_i_SEGMENT[2];
    } stDCD;
    uint8 u8DCD[IDC_DCD_MEM_SIZE];
} UnionNvMDCD;
extern char compiler_assert_DCD_invalid[sizeof(UnionNvMDCD) != IDC_DCD_MEM_SIZE ? -1 : 1];

typedef union {
    struct {
        uint8 NvM_Block_HDA_OptUsmSta_SEGMENT;
        uint8 NvM_Block_LFA_OptUsmSta_SEGMENT;
        uint8 NvM_Block_HDA_LCFuncOptUsmSta_SEGMENT;
        uint8 NvM_Block_SCC_SnstvtyModRetVal_SEGMENT;
        uint8 NvM_Block_SCC_NSCCOnOffSta_SEGMENT;
        uint8 NvM_Block_SCCMode_OptUsmSta_SEGMENT;
        uint8 NvM_Block_SCC_HeadwayDstSetValDefault_SEGMENT;
		uint8 Reserved[5];
    } stUSM;
    uint8 u8USM[IDC_USM_MEM_SIZE];
} UnionNvMUSM;
extern char compiler_assert_USM_invalid[sizeof(UnionNvMUSM) != IDC_USM_MEM_SIZE ? -1 : 1];

typedef union {
    struct {
        uint8 NvM_Block_AebModeNValueSet_SEGMENT;
        uint8 NvM_Block_FCA_SysFlrSta_SEGMENT;
        uint8 NvM_Block_JnctnNValueSet_SEGMENT;
        uint8 NvM_Block_BCA_Prestate_SEGMENT;
        uint8 NvM_Block_BCA_Plus_ParallelExit_Prestate_SEGMENT;
        uint8 NvM_Block_RCCA_Prestate_SEGMENT;
        uint8 NvM_Block_SEA_Prestate_SEGMENT;
        uint8 NvM_Block_BCW_SnstvtyModRetVal_Prestate_SEGMENT;
    } stNvMIDS;
    uint8 u8NvMIDS[IDS_MEM_SIZE];
} UnionNvMIDS;

extern char compiler_assert_IDS_invalid[sizeof(UnionNvMIDS) != IDS_MEM_SIZE ? -1 : 1];

typedef union {
    struct {
        uint8 NvM_Block_YAW_RATE_OFFSET_VDISP_SEGMENT[2];
        uint8 NvM_Block_SAS_ANGLE_OFFSET_VDISP_SEGMENT[2];
        uint8 NvM_Block_YAW_RATE_OFFSET_VDISP_SUB_SEGMENT[2];
        uint8 NvM_Block_SAS_ANGLE_OFFSET_VDISP_SUB_SEGMENT[2];
    } stNvMVDISP;
    uint8 u8NvMVDISP[VDISP_MEM_SIZE];
} UnionNvMVDISP;
extern char compiler_assert_VDISP_invalid[sizeof(UnionNvMVDISP) != VDISP_MEM_SIZE ? -1 : 1];

typedef union {
    struct {
        uint8 HW_ERR_CNT;
        uint8 SW_ERR_CNT;
        struct {
            uint8 AG_INDEX;
            uint32 ALARM;
        } HW_ERR_INFO[12];
        struct {
            uint8 ERROR_CODE;
            uint8 TASK_ID;
        } SW_ERR_INFO[5];
    } stNvMFS;
    uint8 u8NvMFS[FAILSAFE_MEM_SIZE];
} UnionNvMFailsafe;

extern char compiler_assert_FAILSAFE_invalid[sizeof(UnionNvMFailsafe) != FAILSAFE_MEM_SIZE ? -1 : 1];

typedef union {
    variant_code_t stNvMVariantCode;
    uint8 u8NvMVariantCode[VARIANT_CODE_MEM_SIZE];
} UnionNvMVariantCode;
extern char compiler_assert_VARIANT_invalid[sizeof(UnionNvMVariantCode) != VARIANT_CODE_MEM_SIZE ? -1 : 1];

typedef union {
    struct {
        uint8 NvM_Block_VariantCode_W_main;
        uint8 NvM_Block_VariantCode_W_sub;
    } stNvMVariantCode_W;
    uint8 u8NvMVariantCode_W[VARIANT_CODE_W_MEM_SIZE];
} UnionNvMVariantCode_W;
extern char compiler_assert_VARIANT_W_invalid[sizeof(UnionNvMVariantCode_W) != VARIANT_CODE_W_MEM_SIZE ? -1 : 1];

typedef union {
    struct {
        uint8 NvM_Block_TX_Opt;
        uint8 NvM_Block_ZCAN_Logger_Opt;
        uint8 NvM_Block_VX1000_En;
        uint8 NvM_Block_SF_EXECUTION_TIME_MAX;
    } stNvMSystemVariable;
    uint8 u8NvMSystemVariable[SYS_VAR_MEM_SIZE];
} UnionNvMSystemVariable;
extern char compiler_assert_SYS_VAR_invalid[sizeof(UnionNvMSystemVariable) != SYS_VAR_MEM_SIZE ? -1 : 1];

typedef union {
    struct {
        uint8 NvM_Block_PartNumber[15];
        uint8 NvM_Block_ManufacturingDate[4];
        uint8 NvM_Block_SerialNumber[13];
        uint8 NvM_Block_SupplierCode[4];
    } stNvMTraceability;
    uint8 u8NvMTraceability[TRACEABILITY_MEM_SIZE];
} UnionNvMTraceability;
extern char compiler_assert_TRACEABILITY_invalid[sizeof(UnionNvMTraceability) != TRACEABILITY_MEM_SIZE ? -1 : 1];


extern UnionNvMDCD IDC_DCD_NvMData;
extern UnionNvMDCD IDC_DCD_Firmware_NvMData;
extern UnionNvMUSM IDC_USM_NvMData;
extern UnionNvMIDS IDS_NvMData;
extern UnionNvMVDISP VDISP_NvMData;
extern UnionNvMFailsafe Failsafe_NvMData;
extern UnionNvMVariantCode VariantCode_NvMData;
extern UnionNvMVariantCode_W VariantCode_W_NvMData;
extern UnionNvMSystemVariable SystemVariableNvMData;
extern UnionNvMTraceability TraceabilityNvMData;
/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /*APP_NVM_RAM_H*/
/*******************************************************************************
**                       End of File                                          **
*******************************************************************************/
