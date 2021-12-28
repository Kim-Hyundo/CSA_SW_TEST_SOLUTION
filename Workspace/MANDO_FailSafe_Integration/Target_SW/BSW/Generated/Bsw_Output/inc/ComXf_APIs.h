/*******************************************************************************
**                                                                            **
**  (C) 2018 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  Generate On : The time-stamp is removed
**                                                                            **
**  SRC-MODULE:           ComXf_APIs.h                                        **
**                                                                            **
**  PRODUCT   :           AUTOSAR COM Based Transformer Module                **
**                                                                            **
**  PURPOSE   :           This file contain extern declaration generic public **
**                        API's.                                              **
**                                                                            **
**  HARDWARE DEPENDANT [Yes/No]: No                                           **
**                                                                            **
**  AUTOSAR RELEASE:  4.3.0                                                   **
*******************************************************************************/

#ifndef COMXF_APIS_H
#define COMXF_APIS_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
		
/*******************************************************************************
**                       Global Data                                          **
*******************************************************************************/

/*******************************************************************************
**                       Function Prototypes                                  **
*******************************************************************************/
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ECANFD_ABS_ESC_01_10ms_MsgGr_E2E_ECANFD_ABS_ESC_01_10ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ECANFD_ABS_ESC_01_10ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_CtApISR_Gr_MsgGr_E2E_ECANFD_ADAS_CMD_10_20ms_MsgGr_E2E_ECANFD_ADAS_CMD_10_20ms(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) buffer,
  P2VAR(uint16, AUTOMATIC, COMXF_VAR) bufferLength,
  P2CONST(MsgGr_E2E_ECANFD_ADAS_CMD_10_20ms, AUTOMATIC, COMXF_CONST)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_CtApISR_Gr_MsgGr_E2E_ECANFD_ADAS_CMD_20_20ms_MsgGr_E2E_ECANFD_ADAS_CMD_20_20ms(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) buffer,
  P2VAR(uint16, AUTOMATIC, COMXF_VAR) bufferLength,
  P2CONST(MsgGr_E2E_ECANFD_ADAS_CMD_20_20ms, AUTOMATIC, COMXF_CONST)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_CtApISR_Gr_MsgGr_E2E_ECANFD_ADAS_CMD_21_50ms_MsgGr_E2E_ECANFD_ADAS_CMD_21_50ms(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) buffer,
  P2VAR(uint16, AUTOMATIC, COMXF_VAR) bufferLength,
  P2CONST(MsgGr_E2E_ECANFD_ADAS_CMD_21_50ms, AUTOMATIC, COMXF_CONST)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_CtApISR_Gr_MsgGr_E2E_ECANFD_ADAS_CMD_30_10ms_MsgGr_E2E_ECANFD_ADAS_CMD_30_10ms(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) buffer,
  P2VAR(uint16, AUTOMATIC, COMXF_VAR) bufferLength,
  P2CONST(MsgGr_E2E_ECANFD_ADAS_CMD_30_10ms, AUTOMATIC, COMXF_CONST)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_CtApISR_Gr_MsgGr_E2E_ECANFD_ADAS_CMD_31_50ms_MsgGr_E2E_ECANFD_ADAS_CMD_31_50ms(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) buffer,
  P2VAR(uint16, AUTOMATIC, COMXF_VAR) bufferLength,
  P2CONST(MsgGr_E2E_ECANFD_ADAS_CMD_31_50ms, AUTOMATIC, COMXF_CONST)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_CtApISR_Gr_MsgGr_E2E_ECANFD_ADAS_CMD_32_50ms_MsgGr_E2E_ECANFD_ADAS_CMD_32_50ms(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) buffer,
  P2VAR(uint16, AUTOMATIC, COMXF_VAR) bufferLength,
  P2CONST(MsgGr_E2E_ECANFD_ADAS_CMD_32_50ms, AUTOMATIC, COMXF_CONST)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_CtApISR_Gr_MsgGr_E2E_ECANFD_ADAS_DRV_01_200ms_MsgGr_E2E_ECANFD_ADAS_DRV_01_200ms(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) buffer,
  P2VAR(uint16, AUTOMATIC, COMXF_VAR) bufferLength,
  P2CONST(MsgGr_E2E_ECANFD_ADAS_DRV_01_200ms, AUTOMATIC, COMXF_CONST)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ECANFD_ADAS_PRK_21_20ms_MsgGr_E2E_ECANFD_ADAS_PRK_21_20ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ECANFD_ADAS_PRK_21_20ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ECANFD_CLU_01_20ms_MsgGr_E2E_ECANFD_CLU_01_20ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ECANFD_CLU_01_20ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ECANFD_CLU_02_100ms_MsgGr_E2E_ECANFD_CLU_02_100ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ECANFD_CLU_02_100ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ECANFD_EMS_01_10ms_MsgGr_E2E_ECANFD_EMS_01_10ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ECANFD_EMS_01_10ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ECANFD_EMS_02_10ms_MsgGr_E2E_ECANFD_EMS_02_10ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ECANFD_EMS_02_10ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ECANFD_ESC_01_10ms_MsgGr_E2E_ECANFD_ESC_01_10ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ECANFD_ESC_01_10ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ECANFD_ESC_03_20ms_MsgGr_E2E_ECANFD_ESC_03_20ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ECANFD_ESC_03_20ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ECANFD_ICSC_02_100ms_MsgGr_E2E_ECANFD_ICSC_02_100ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ECANFD_ICSC_02_100ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ECANFD_MDPS_01_10ms_MsgGr_E2E_ECANFD_MDPS_01_10ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ECANFD_MDPS_01_10ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ECANFD_SAS_01_10ms_MsgGr_E2E_ECANFD_SAS_01_10ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ECANFD_SAS_01_10ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ECANFD_SWRC_03_20ms_MsgGr_E2E_ECANFD_SWRC_03_20ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ECANFD_SWRC_03_20ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ECANFD_TCU_01_10ms_MsgGr_E2E_ECANFD_TCU_01_10ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ECANFD_TCU_01_10ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ECANFD_WHL_01_10ms_MsgGr_E2E_ECANFD_WHL_01_10ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ECANFD_WHL_01_10ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ECANFD_YRS_01_10ms_MsgGr_E2E_ECANFD_YRS_01_10ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ECANFD_YRS_01_10ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ECANFD_EMS_05_100ms_MsgGr_E2E_ECANFD_EMS_05_100ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ECANFD_EMS_05_100ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ECANFD_RR_C_RDR_03_50ms_MsgGr_E2E_ECANFD_RR_C_RDR_03_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ECANFD_RR_C_RDR_03_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ECANFD_CLU_11_00ms_MsgGr_E2E_ECANFD_CLU_11_00ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ECANFD_CLU_11_00ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_ADAS_DRV_01_10ms_MsgGr_E2E_ACANFD1_A_ADAS_DRV_01_10ms(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) buffer,
  P2VAR(uint16, AUTOMATIC, COMXF_VAR) bufferLength,
  P2CONST(MsgGr_E2E_ACANFD1_A_ADAS_DRV_01_10ms, AUTOMATIC, COMXF_CONST)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_01_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_01_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_FS_01_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_02_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_02_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_FS_02_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_03_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_03_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_FS_03_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_04_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_04_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_FS_04_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_05_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_05_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_FS_05_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_06_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_06_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_FS_06_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_07_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_07_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_FS_07_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_08_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_08_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_FS_08_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_09_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_09_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_FS_09_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_10_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_10_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_FS_10_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_11_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_11_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_FS_11_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_12_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_12_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_FS_12_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_13_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_13_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_FS_13_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_14_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_14_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_FS_14_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_15_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_15_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_FS_15_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_16_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_16_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_FS_16_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_17_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_17_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_FS_17_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_18_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_18_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_FS_18_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_19_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_19_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_FS_19_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_20_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_20_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_FS_20_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_21_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_21_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_FS_21_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_22_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_22_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_FS_22_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_23_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_23_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_FS_23_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_24_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_FS_24_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_FS_24_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_Genrl_01_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_Genrl_01_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_Genrl_01_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_Ln_01_50ms_MsgGr_E2E_ACANFD1_A_FR_CMR_Ln_01_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_Ln_01_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_Ln_02_50ms_MsgGr_E2E_ACANFD1_A_FR_CMR_Ln_02_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_Ln_02_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_Ln_03_50ms_MsgGr_E2E_ACANFD1_A_FR_CMR_Ln_03_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_Ln_03_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_01_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_01_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_01_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_02_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_02_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_02_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_03_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_03_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_03_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_04_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_04_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_04_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_05_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_05_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_05_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_06_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_06_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_06_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_07_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_07_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_07_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_08_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_08_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_08_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_09_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_09_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_09_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_10_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_10_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_10_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_11_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_11_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_11_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_12_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_12_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_12_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_13_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_13_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_13_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_14_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_14_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_14_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_15_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_15_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_15_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_16_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_16_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_16_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_17_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_17_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_17_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_18_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_18_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_18_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_19_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_19_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_19_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_20_30ms_MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_20_30ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_Obj_20_30ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_PP_Genrl_01_50ms_MsgGr_E2E_ACANFD1_A_FR_CMR_PP_Genrl_01_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_PP_Genrl_01_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_PP_Ln_01_50ms_MsgGr_E2E_ACANFD1_A_FR_CMR_PP_Ln_01_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_PP_Ln_01_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_CMR_PP_Ln_02_50ms_MsgGr_E2E_ACANFD1_A_FR_CMR_PP_Ln_02_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_PP_Ln_02_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_FS_01_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_FS_01_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_FS_01_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_FS_02_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_FS_02_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_FS_02_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_FS_03_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_FS_03_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_FS_03_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_FS_04_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_FS_04_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_FS_04_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_FS_05_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_FS_05_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_FS_05_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_Genrl_01_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_Genrl_01_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_Genrl_01_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_Genrl_02_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_Genrl_02_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_Genrl_02_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_ODM_01_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_ODM_01_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_ODM_01_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_01_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_01_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_01_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_02_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_02_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_02_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_03_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_03_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_03_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_04_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_04_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_04_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_05_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_05_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_05_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_06_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_06_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_06_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_07_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_07_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_07_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_08_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_08_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_08_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_09_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_09_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_09_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_10_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_10_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_10_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_11_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_11_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_11_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_12_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_12_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_12_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_13_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_13_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_13_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_14_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_14_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_14_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_15_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_15_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_15_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_16_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_16_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_16_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_17_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_17_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_17_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_18_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_18_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_18_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_19_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_19_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_19_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_20_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_20_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_20_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_21_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_21_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_21_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_22_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_22_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_22_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_23_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_23_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_23_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_24_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_24_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_24_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_25_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_25_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_25_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_26_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_26_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_26_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_27_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_27_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_27_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_28_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_28_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_28_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_29_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_29_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_29_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_30_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_30_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_30_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_31_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_31_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_31_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_32_50ms_MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_32_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_RDR_Obj_32_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Genrl_01_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Genrl_01_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_Genrl_01_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_LH_FS_01_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_LH_FS_01_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_LH_FS_01_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_LH_FS_02_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_LH_FS_02_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_LH_FS_02_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_LH_FS_03_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_LH_FS_03_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_LH_FS_03_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_LH_FS_04_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_LH_FS_04_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_LH_FS_04_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_LH_FS_05_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_LH_FS_05_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_LH_FS_05_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_LH_FS_06_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_LH_FS_06_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_LH_FS_06_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_LH_FS_07_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_LH_FS_07_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_LH_FS_07_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_LH_FS_08_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_LH_FS_08_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_LH_FS_08_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_ODM_01_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_ODM_01_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_ODM_01_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_01_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_01_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_01_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_02_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_02_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_02_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_03_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_03_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_03_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_04_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_04_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_04_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_05_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_05_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_05_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_06_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_06_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_06_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_07_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_07_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_07_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_08_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_08_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_08_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_09_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_09_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_09_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_10_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_10_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_10_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_11_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_11_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_11_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_12_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_12_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_12_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_13_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_13_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_13_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_14_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_14_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_14_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_15_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_15_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_15_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_16_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_16_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_16_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_17_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_17_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_17_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_18_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_18_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_18_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_19_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_19_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_19_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_20_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_20_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_20_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_21_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_21_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_21_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_22_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_22_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_22_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_23_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_23_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_23_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_24_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_24_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_24_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_25_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_25_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_25_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_26_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_26_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_26_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_27_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_27_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_27_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_28_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_28_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_28_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_29_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_29_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_29_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_30_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_30_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_Obj_30_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_RH_FS_01_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_RH_FS_01_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_RH_FS_01_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_RH_FS_02_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_RH_FS_02_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_RH_FS_02_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_RH_FS_03_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_RH_FS_03_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_RH_FS_03_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_RH_FS_04_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_RH_FS_04_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_RH_FS_04_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_RH_FS_05_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_RH_FS_05_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_RH_FS_05_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_RH_FS_06_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_RH_FS_06_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_RH_FS_06_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_RH_FS_07_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_RH_FS_07_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_RH_FS_07_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_CtApISR_Gr_MsgGr_E2E_ACANFD2_A_FR_C_RDR_RH_FS_08_50ms_MsgGr_E2E_ACANFD2_A_FR_C_RDR_RH_FS_08_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD2_A_FR_C_RDR_RH_FS_08_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_CtApISR_Gr_MsgGr_E2E_ECANFD_ADAS_CMD_40_50ms_MsgGr_E2E_ECANFD_ADAS_CMD_40_50ms(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) buffer,
  P2VAR(uint16, AUTOMATIC, COMXF_VAR) bufferLength,
  P2CONST(MsgGr_E2E_ECANFD_ADAS_CMD_40_50ms, AUTOMATIC, COMXF_CONST)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_CtApISR_Gr_MsgGr_E2E_ECANFD_ADAS_CMD_50_50ms_MsgGr_E2E_ECANFD_ADAS_CMD_50_50ms(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) buffer,
  P2VAR(uint16, AUTOMATIC, COMXF_VAR) bufferLength,
  P2CONST(MsgGr_E2E_ECANFD_ADAS_CMD_50_50ms, AUTOMATIC, COMXF_CONST)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Com_ComISignalGroup_MsgGr_E2E_ACANFD1_A_ADAS_DRV_02_100ms(
  P2VAR(uint8, AUTOMATIC, COMXF_VAR) buffer,
  P2VAR(uint16, AUTOMATIC, COMXF_VAR) bufferLength,
  P2CONST(MsgGr_E2E_ACANFD1_A_ADAS_DRV_02_100ms, AUTOMATIC, COMXF_CONST)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_Com_ComISignalGroup_MsgGr_E2E_ACANFD1_A_FR_CMR_Ctrl_01_10ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_Ctrl_01_10ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_Com_ComISignalGroup_MsgGr_E2E_ACANFD1_A_FR_CMR_Ctrl_02_20ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_Ctrl_02_20ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_Com_ComISignalGroup_MsgGr_E2E_ACANFD1_A_FR_CMR_RoadMrk_01_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_RoadMrk_01_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_Com_ComISignalGroup_MsgGr_E2E_ACANFD1_A_FR_CMR_RoadMrk_02_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_RoadMrk_02_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_Com_ComISignalGroup_MsgGr_E2E_ACANFD1_A_FR_CMR_RoadMrk_03_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_RoadMrk_03_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_Com_ComISignalGroup_MsgGr_E2E_ACANFD1_A_FR_CMR_RoadMrk_04_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_RoadMrk_04_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_Com_ComISignalGroup_MsgGr_E2E_ACANFD1_A_FR_CMR_RoadMrk_05_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_RoadMrk_05_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_Com_ComISignalGroup_MsgGr_E2E_ACANFD1_A_FR_CMR_TSR_01_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_TSR_01_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_Com_ComISignalGroup_MsgGr_E2E_ACANFD1_A_FR_CMR_TSR_02_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_TSR_02_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_Com_ComISignalGroup_MsgGr_E2E_ACANFD1_A_FR_CMR_TSR_03_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_TSR_03_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_Com_ComISignalGroup_MsgGr_E2E_ACANFD1_A_FR_CMR_TSR_04_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_TSR_04_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(uint8, COMXF_CODE) ComXf_Inv_Com_ComISignalGroup_MsgGr_E2E_ACANFD1_A_FR_CMR_TSR_05_50ms(
  P2CONST(uint8, AUTOMATIC, COMXF_CONST) buffer,
  VAR(uint16, COMXF_VAR) bufferLength,
  P2VAR(MsgGr_E2E_ACANFD1_A_FR_CMR_TSR_05_50ms, AUTOMATIC, COMXF_VAR)
  dataElement);
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

#define COMXF_START_APPL_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(void, COMXF_APPL_CODE) ComXf_FillUnusedBufferArea(
  P2VAR(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer,
  uint32 Lu32_ComXfBufferLength ,uint8 Lu8_ComXfUnusedAreaValue);
#define COMXF_STOP_APPL_SEC_CODE
#include "ComXf_MemMap.h"

#endif /* COMXF_APIS_H */
/*******************************************************************************
*                       End of File                                            *
*******************************************************************************/
