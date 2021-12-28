/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  FILE-NAME : BswM_ActionList.h                                             **
**                                                                            **
**  PRODUCT   : AUTOSAR BswM Module                                           **
**                                                                            **
**  NOTE: This file is auto generated, do not edit this file manually.        **
**                                                                            **
********************************************************************************

********************************************************************************
**                      Generation Tool Information                           **
********************************************************************************
**  Tool Version: 2.6.1                                                       **
**                                                                            **
**  Change History: Refer log file (use -l option to generate log file)       **
**                                                                            **
********************************************************************************
**                      File Generation Information                           **
*******************************************************************************/

/*
 * INPUT FILE:    Configuration\Ecu\Ecud_Com.arxml
 *                Configuration\Ecu\Ecud_ComM.arxml
 *                Configuration\Ecu\Ecud_EcuC.arxml
 *                Configuration\Ecu\Ecud_EcuM.arxml
 *                Configuration\Ecu\Ecud_BswM.arxml
 *                Configuration\Ecu\Ecud_Os.arxml
 *                Configuration\Ecu\Ecud_NvM.arxml
 * GENERATED ON: The time-stamp is removed
 */

#ifndef BSWM_ACTIONLIST_H
#define BSWM_ACTIONLIST_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define BSWM_START_SEC_CODE
#include "MemMap.h"


extern FUNC(void, BSWM_CODE) BswM_DeadlineMonitoringControl(uint8 dmindex);
      
extern FUNC(void, BSWM_CODE) BswM_PduGroupSwitch(uint8 pgsindex);
      

extern FUNC(void, BSWM_CODE) AL_ComModeAllow_ALL_FALSE(void);

extern FUNC(void, BSWM_CODE) AL_ComModeAllow_ALL_TRUE(void);

extern FUNC(void, BSWM_CODE) AL_ComModeRequest_ALL_FULL_COM(void);

extern FUNC(void, BSWM_CODE) AL_ComModeRequest_ALL_NO_COM(void);

extern FUNC(void, BSWM_CODE) AL_DriverDeinit(void);

extern FUNC(void, BSWM_CODE) AL_DriverInitThree(void);

extern FUNC(void, BSWM_CODE) AL_DriverInitTwo(void);

extern FUNC(void, BSWM_CODE) AL_DriverPreDeinit(void);

extern FUNC(void, BSWM_CODE) AL_RteStart(void);

extern FUNC(void, BSWM_CODE) AL_RteStop(void);

extern FUNC(void, BSWM_CODE) TrueAL_CanBorNotification_ACANFD1_COMPLETE(void);

extern FUNC(void, BSWM_CODE) TrueAL_CanBorNotification_ACANFD1_START(void);

extern FUNC(void, BSWM_CODE) TrueAL_CanBorNotification_ACANFD2_COMPLETE(void);

extern FUNC(void, BSWM_CODE) TrueAL_CanBorNotification_ACANFD2_START(void);

extern FUNC(void, BSWM_CODE) TrueAL_CanBorNotification_DebugCANFD_COMPLETE(void);

extern FUNC(void, BSWM_CODE) TrueAL_CanBorNotification_DebugCANFD_START(void);

extern FUNC(void, BSWM_CODE) TrueAL_CanBorNotification_ECANFD_COMPLETE(void);

extern FUNC(void, BSWM_CODE) TrueAL_CanBorNotification_ECANFD_START(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComControl_ACANFD1_DISABLE_DM(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComControl_ACANFD1_DISABLE_RX(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComControl_ACANFD1_DISABLE_TX(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComControl_ACANFD1_ENABLE_DM(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComControl_ACANFD1_ENABLE_RX(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComControl_ACANFD1_ENABLE_TX(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComControl_ACANFD2_DISABLE_DM(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComControl_ACANFD2_DISABLE_RX(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComControl_ACANFD2_DISABLE_TX(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComControl_ACANFD2_ENABLE_DM(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComControl_ACANFD2_ENABLE_RX(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComControl_ACANFD2_ENABLE_TX(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComControl_ALL_DISABLE_TX_RX(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComControl_ALL_ENABLE_TX_RX(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComControl_DebugCANFD_DISABLE_DM(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComControl_DebugCANFD_DISABLE_RX(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComControl_DebugCANFD_DISABLE_TX(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComControl_DebugCANFD_ENABLE_DM(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComControl_DebugCANFD_ENABLE_RX(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComControl_DebugCANFD_ENABLE_TX(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComControl_ECANFD_DISABLE_DM(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComControl_ECANFD_DISABLE_RX(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComControl_ECANFD_DISABLE_TX(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComControl_ECANFD_ENABLE_DM(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComControl_ECANFD_ENABLE_RX(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComControl_ECANFD_ENABLE_TX(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComModeNotification_ACANFD1_FULL_COM(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComModeNotification_ACANFD1_NO_COM(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComModeNotification_ACANFD1_SILENT_COM(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComModeNotification_ACANFD2_FULL_COM(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComModeNotification_ACANFD2_NO_COM(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComModeNotification_ACANFD2_SILENT_COM(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComModeNotification_DebugCANFD_FULL_COM(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComModeNotification_DebugCANFD_NO_COM(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComModeNotification_DebugCANFD_SILENT_COM(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComModeNotification_ECANFD_FULL_COM(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComModeNotification_ECANFD_NO_COM(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComModeNotification_ECANFD_SILENT_COM(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComModeRequest_ACANFD1_FULL_COM(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComModeRequest_ACANFD1_NO_COM(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComModeRequest_ACANFD2_FULL_COM(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComModeRequest_ACANFD2_NO_COM(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComModeRequest_DebugCANFD_FULL_COM(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComModeRequest_DebugCANFD_NO_COM(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComModeRequest_ECANFD_FULL_COM(void);

extern FUNC(void, BSWM_CODE) TrueAL_ComModeRequest_ECANFD_NO_COM(void);

extern FUNC(void, BSWM_CODE) TrueAL_DiagnosticSessionNotification_DEFAULT_SESSION(void);

extern FUNC(void, BSWM_CODE) TrueAL_DiagnosticSessionNotification_ECU_PROGRAMMING_MODE(void);

extern FUNC(void, BSWM_CODE) TrueAL_DiagnosticSessionNotification_EXTENDED_DIAGNOSTIC_MODE(void);

extern FUNC(void, BSWM_CODE) TrueAL_DiagnosticSessionNotification_EXTENDED_DIAGNOSTIC_SESSION(void);

extern FUNC(void, BSWM_CODE) TrueAL_DiagnosticSessionNotification_PROGRAMMING_SESSION(void);

extern FUNC(void, BSWM_CODE) TrueAL_DiagnosticSessionNotification_QUIESCENT_CURRENT_DIAGNOSTIC_MODE_START(void);

extern FUNC(void, BSWM_CODE) TrueAL_DiagnosticSessionNotification_SAFETY_SYSTEM_DIAGNOSTIC_SESSION(void);

extern FUNC(void, BSWM_CODE) TrueAL_DiagnosticSessionNotification_SLEEP_MODE_START_REQUEST(void);

extern FUNC(void, BSWM_CODE) TrueAL_EcuStateTo_OFF(void);

extern FUNC(void, BSWM_CODE) TrueAL_EcuStateTo_RESET(void);

extern FUNC(void, BSWM_CODE) TrueAL_EcuStateTo_RUN_From_SLEEP(void);

extern FUNC(void, BSWM_CODE) TrueAL_EcuStateTo_RUN_From_STARTUP(void);

extern FUNC(void, BSWM_CODE) TrueAL_EcuStateTo_SHUTDOWN(void);

extern FUNC(void, BSWM_CODE) TrueAL_EcuStateTo_SLEEP(void);

extern FUNC(void, BSWM_CODE) TrueAL_EcuStateTo_STARTUP_THREE(void);

extern FUNC(void, BSWM_CODE) TrueAL_EcuStateTo_STARTUP_TWO(void);

extern FUNC(void, BSWM_CODE) TrueAL_EcuState_OFF(void);

extern FUNC(void, BSWM_CODE) TrueAL_EcuState_RESET(void);

extern FUNC(void, BSWM_CODE) TrueAL_EcuState_RUN(void);

extern FUNC(void, BSWM_CODE) TrueAL_EcuState_SHUTDOWN(void);

extern FUNC(void, BSWM_CODE) TrueAL_EcuState_SLEEP(void);

extern FUNC(void, BSWM_CODE) TrueAL_EcuState_STARTUP_THREE(void);

extern FUNC(void, BSWM_CODE) TrueAL_EcuState_STARTUP_TWO(void);

extern FUNC(void, BSWM_CODE) TrueAL_ShutdownTargetTo_OFF(void);

extern FUNC(void, BSWM_CODE) TrueAL_ShutdownTargetTo_RESET(void);

extern FUNC(void, BSWM_CODE) TrueAL_ShutdownTargetTo_RUN(void);

extern FUNC(void, BSWM_CODE) TrueAL_ShutdownTargetTo_SLEEP(void);


#define BSWM_STOP_SEC_CODE
#include "MemMap.h"
#endif /* BSWM_ACTIONLIST_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
