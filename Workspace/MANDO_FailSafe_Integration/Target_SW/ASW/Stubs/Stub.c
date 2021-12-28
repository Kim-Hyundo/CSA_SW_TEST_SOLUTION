/*
 * Stub.h
 *
 *  Created on: 2020. 9. 7.
 *      Author: taejun3.kim
 */

#ifndef STUB_H_
#define STUB_H_

#include "App_NvM_Ram.h"
#include "Rte_CtApFAILSAFE.h"
#include "SWC_Failsafe.h"

volatile boolean BSW_InitCompleted = TRUE;
volatile struct reference_signal ref_sig;

uint16 vol_grp[VOL_GRP_NUM];


//////////////// NvM Stubs

uint8 NvMBlock_Failsafe_Segment_DefaultBlock[FAILSAFE_MEM_SIZE];
UnionNvMFailsafe Failsafe_NvMData;

nvm_info_t nvm_info[NvM_NUM];
boolean nvm_loaded = 1;

UnionNvMVariantCode VariantCode_NvMData = {
    .stNvMVariantCode = {
        .NvM_Block_Region = Region__All,
        .NvM_Block_Vehicle_Type = VT__All,
        .NvM_Block_MDPS_Type = MDPS__All,
        .NvM_Block_ISG_Option = ISG__NA,
        .NvM_Block_Transmission_Option = TA__AT,
        .NvM_Block_Body_Type = BT__Type1,
        .NvM_Block_Drive_Type = DT__LHD,
        .NvM_Block_NSCC_HDA2_Option = NSCC_HDA2__NSCC_ZCR_HDA2,
        .NvM_Block_DRV_FUNCTION_SET_1 = FUNCTION_SET_1__APPLIED,
        .NvM_Block_DRV_FUNCTION_SET_2 = FUNCTION_SET_2__APPLIED,
    }
};
UnionNvMVariantCode_W VariantCode_W_NvMData;

/////////////// Failsafe flags
#include "SWC_Failsafe.h"

//CtApISR.c
volatile uint32 e2e_err_flags[MSG_GRP_NUM];
volatile uint32 msg_received_flags[MSG_GRP_NUM];
volatile uint32 msg_received_buf[MSG_GRP_NUM];

//CtApIVC.c
MsgGr_E2E_ECANFD_ADAS_CMD_31_50ms MsgGr_ADAS_CMD_31_50ms_IVC_D;
MsgGr_E2E_ECANFD_ADAS_CMD_30_10ms MsgGr_ADAS_CMD_30_10ms_IVC_D;



/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/


/******************************************************************************
* Global Variables
******************************************************************************/


#endif /* STUB_H_ */
