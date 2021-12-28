
/*******************************************************************************
**  FILE-NAME: Rte_BswM_Type.h                                                     **
**                                                                            **
**  MODULE-NAME: AUTOSAR RTE GENERATION TOOL                                  **
**                                                                            **
**  NOTE: This file is auto generated, do not edit this file manually.        **
**                                                                            **
********************************************************************************

********************************************************************************
**                      Generation Tool Information                           **
********************************************************************************
**  Tool Version: 4.9.0                                                   **
**                                                                            **
**  Change History: Refer log file (use -l option to generate log file)       **
**                                                                            **
********************************************************************************
**                      File Generation Information                           **
*******************************************************************************/
/*
 * INPUT FILE:
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\Ecu\ECUCD_EcucValueCollection.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\Ecu\Ecud_Com.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\Ecu\Ecud_ComXf.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\Ecu\Ecud_E2EXf.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\Ecu\Ecud_EcuC.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\Ecu\Ecud_Os.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\Ecu\Ecud_Rte.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\Ecu\Ecud_Xcp.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Bswmd\Bswmd_Adc.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Bswmd\Bswmd_BswM.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Bswmd\Bswmd_Can.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Bswmd\Bswmd_CanCM.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Bswmd\Bswmd_CanIf.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Bswmd\Bswmd_CanSM.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Bswmd\Bswmd_CanTp.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Bswmd\Bswmd_CanTrcv_255_Autron.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Bswmd\Bswmd_Com.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Bswmd\Bswmd_ComM.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Bswmd\Bswmd_ComXf.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Bswmd\Bswmd_Crc.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Bswmd\Bswmd_Dcm.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Bswmd\Bswmd_Dem.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Bswmd\Bswmd_Det.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Bswmd\Bswmd_E2EXf.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Bswmd\Bswmd_Fls.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Bswmd\Bswmd_FlsLoader.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Bswmd\Bswmd_Gpt.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Bswmd\Bswmd_Icu.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Bswmd\Bswmd_Mcu.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Bswmd\Bswmd_MemIf.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Bswmd\Bswmd_NvM.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Bswmd\Bswmd_Os.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Bswmd\Bswmd_PduR.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Bswmd\Bswmd_Pwm.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Bswmd\Bswmd_Spi.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Bswmd\Bswmd_Wdg.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Bswmd\Bswmd_Xcp.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Composition\EcuExtract.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\DBImport\ACANFD1.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\DBImport\ACANFD2.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\DBImport\DebugCANFD.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\DBImport\ECANFD.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\DataTypes\AUTOSAR_DataTypes.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Swcd_App\App_ADAS_DRV.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Swcd_App\App_Dcm.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Swcd_App\App_Dem.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Swcd_App\App_Mode.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Swcd_App\App_NvM.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Swcd_App\App_WdgM.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Swcd_Bsw\MODE_PortInterfaces.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Swcd_Bsw\Swcd_Bsw_BswM.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Swcd_Bsw\Swcd_Bsw_EcuM_Slave.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Swcd_Bsw\Swcd_Bsw_Os.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Swcd_Bsw\Swcd_ComM.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Swcd_Bsw\Swcd_Det.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Configuration\System\Transformer\Transformer.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Generated\Bsw_Output\bswmd\Bswmd_Csm.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Generated\Bsw_Output\bswmd\Bswmd_EcuM.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Generated\Bsw_Output\bswmd\Bswmd_IoHwAb.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Generated\Bsw_Output\bswmd\Bswmd_WdgIf.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Generated\Bsw_Output\bswmd\Bswmd_WdgM.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Generated\Bsw_Output\bswmd\Bswmd_Wdg_76_Acw.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Generated\Bsw_Output\swcd\Swcd_Bsw_Csm.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Generated\Bsw_Output\swcd\Swcd_Bsw_Dcm.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Generated\Bsw_Output\swcd\Swcd_Bsw_Dem.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Generated\Bsw_Output\swcd\Swcd_Bsw_EcuM.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Generated\Bsw_Output\swcd\Swcd_Bsw_NvM.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Generated\Bsw_Output\swcd\Swcd_IoHwAb.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Generated\Bsw_Output\swcd\Swcd_WdgM.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Static_Code\Integration_Code\integration_T1\swcd\Ecud_Rte_T1Ad_6Core.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Static_Code\Integration_Code\integration_T1\swcd\Swcd_Asw_T1Ad_6Core.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Static_Code\Modules\b_autosar_sys_EcuM_R40\generator\EcuM_PortInterface.arxml
 *      D:\02_DCU-15\01_HKMC_RS4\01_develop\Static_Code\Modules\b_autosar_sys_WdgM_R40\generator\Swcd_WdgM_Fixed.arxml

 * GENERATED ON: The time-stamp is removed
*/

/*******************************************************************************
* PRE-JUSTIFICATION BEGINE SECTION (MISRA-C RULE CHECKER)
* These rules will not be applied for verification based on the MISRA Rule
* in Rte generated source
*******************************************************************************/
/*
  polyspace:begin<MISRA-C:5.1:Not a defect:Justify with annotations> Number of character is depends on user configuration
  polyspace:begin<MISRA-C:19.1:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Memory Mapping)
  polyspace:begin<MISRA-C:19.4:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte SWS #1154, #6713)
  polyspace:begin<MISRA-C:19.6:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Memory Mapping)
  polyspace:begin<MISRA-C:19.7:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte SWS #1236)
*/

/******************************************************************************/

/*******************************************************************************
**                         MULTIPLE INCLUSION PROTECTION                      **
*******************************************************************************/
#ifndef RTE_BSWM_TYPE_H
#define RTE_BSWM_TYPE_H

/*******************************************************************************
**                  Include Section                                           **
*******************************************************************************/
/* polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Inclusion of Header Files) */
#include "Rte_Type.h"

/* polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Inclusion of Header Files) */

/* COMPATIBLE WITH C and C++ languages */
#ifdef __cplusplus
 extern "C"
 {
#endif

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#ifdef RTE_VENDOR_ID
  #if (RTE_VENDOR_ID != 76)
    #error "Rte_Cfg.h : Mismatch in Rte Specification Vendor Id"
  #endif
#else
  #define RTE_VENDOR_ID 76
#endif

#ifdef RTE_MODULE_ID
  #if (RTE_MODULE_ID != 2)
    #error "Rte_Cfg.h : Mismatch in Rte Specification Module Id"
  #endif
#else
  #define RTE_MODULE_ID 2
#endif

#ifdef RTE_SW_MAJOR_VERSION
  #if (RTE_SW_MAJOR_VERSION != 4)
    #error "Rte_Cfg.h : Mismatch in Rte Specification Major Version"
  #endif
#else
  #define RTE_SW_MAJOR_VERSION 4
#endif

#ifdef RTE_SW_MINOR_VERSION
  #if (RTE_SW_MINOR_VERSION != 9)
    #error "Rte_Cfg.h : Mismatch in Rte Specification Minor Version"
  #endif
#else
  #define RTE_SW_MINOR_VERSION 9
#endif

#ifdef RTE_SW_PATCH_VERSION
  #if (RTE_SW_PATCH_VERSION != 0)
    #error "Rte_Cfg.h : Mismatch in Rte Specification Patch Version"
  #endif
#else
  #define RTE_SW_PATCH_VERSION 0
#endif

#ifdef RTE_AR_RELEASE_MAJOR_VERSION
  #if (RTE_AR_RELEASE_MAJOR_VERSION != 4)
    #error "Rte_Cfg.h : Mismatch in Rte Specification Release Major Version"
  #endif
#else
  #define RTE_AR_RELEASE_MAJOR_VERSION 4
#endif

#ifdef RTE_AR_RELEASE_MINOR_VERSION
  #if (RTE_AR_RELEASE_MINOR_VERSION != 0)
    #error "Rte_Cfg.h : Mismatch in Rte Specification Release Minor Version"
  #endif
#else
  #define RTE_AR_RELEASE_MINOR_VERSION 0
#endif

#ifdef RTE_AR_RELEASE_REVISION_VERSION
  #if (RTE_AR_RELEASE_REVISION_VERSION != 3)
    #error "Rte_Cfg.h : Mismatch in Rte Specification Release Revision Version"
  #endif
#else
  #define RTE_AR_RELEASE_REVISION_VERSION 3
#endif

/*******************************************************************************
** Type Definitions for Modes                                                 **
*******************************************************************************/
/*
  polyspace:begin<MISRA-C:5.3:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte Modes (Rte SWS #2627))
*/
#ifndef RTE_MODETYPE_MDG_CanSMBORState
#define RTE_MODETYPE_MDG_CanSMBORState
typedef uint8 Rte_ModeType_MDG_CanSMBORState;
#endif

#ifndef RTE_MODETYPE_MDG_ComMMode
#define RTE_MODETYPE_MDG_ComMMode
typedef uint8 Rte_ModeType_MDG_ComMMode;
#endif

#ifndef RTE_MODETYPE_DcmDiagnosticSessionControl
#define RTE_MODETYPE_DcmDiagnosticSessionControl
typedef uint8 Rte_ModeType_DcmDiagnosticSessionControl;
#endif

#ifndef RTE_MODETYPE_EcuMode
#define RTE_MODETYPE_EcuMode
typedef EcuM_StateType Rte_ModeType_EcuMode;
#endif

#ifndef RTE_MODETYPE_MDG_InitState
#define RTE_MODETYPE_MDG_InitState
typedef uint8 Rte_ModeType_MDG_InitState;
#endif

#ifndef RTE_MODETYPE_MDG_PduGroup
#define RTE_MODETYPE_MDG_PduGroup
typedef uint8 Rte_ModeType_MDG_PduGroup;
#endif

#ifndef RTE_MODETYPE_MDG_WakeupEvent
#define RTE_MODETYPE_MDG_WakeupEvent
typedef uint8 Rte_ModeType_MDG_WakeupEvent;
#endif

/*
  polyspace:end<MISRA-C:5.3:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte Modes (Rte SWS #2627))
*/
/*******************************************************************************
* Macros Used For Modes                                                       **
*******************************************************************************/
#ifndef RTE_TRANSITION_MDG_CanSMBORState
#define RTE_TRANSITION_MDG_CanSMBORState ((Rte_ModeType_MDG_CanSMBORState)255U)
#endif

#ifndef RTE_MODE_MDG_CanSMBORState_COMPLETE
#define RTE_MODE_MDG_CanSMBORState_COMPLETE ((Rte_ModeType_MDG_CanSMBORState)0U)
#endif

#ifndef RTE_MODE_MDG_CanSMBORState_START
#define RTE_MODE_MDG_CanSMBORState_START ((Rte_ModeType_MDG_CanSMBORState)1U)
#endif

#ifndef RTE_TRANSITION_MDG_ComMMode
#define RTE_TRANSITION_MDG_ComMMode ((Rte_ModeType_MDG_ComMMode)255U)
#endif

#ifndef RTE_MODE_MDG_ComMMode_FULL_COM
#define RTE_MODE_MDG_ComMMode_FULL_COM ((Rte_ModeType_MDG_ComMMode)2U)
#endif

#ifndef RTE_MODE_MDG_ComMMode_NO_COM
#define RTE_MODE_MDG_ComMMode_NO_COM ((Rte_ModeType_MDG_ComMMode)0U)
#endif

#ifndef RTE_MODE_MDG_ComMMode_SILENT_COM
#define RTE_MODE_MDG_ComMMode_SILENT_COM ((Rte_ModeType_MDG_ComMMode)1U)
#endif

#ifndef RTE_TRANSITION_DcmDiagnosticSessionControl
#define RTE_TRANSITION_DcmDiagnosticSessionControl ((Rte_ModeType_DcmDiagnosticSessionControl)0U)
#endif

#ifndef RTE_MODE_DcmDiagnosticSessionControl_DCM_DEFAULT_SESSION
#define RTE_MODE_DcmDiagnosticSessionControl_DCM_DEFAULT_SESSION ((Rte_ModeType_DcmDiagnosticSessionControl)1U)
#endif

#ifndef RTE_MODE_DcmDiagnosticSessionControl_DCM_ECU_PROGRAMMING_MODE
#define RTE_MODE_DcmDiagnosticSessionControl_DCM_ECU_PROGRAMMING_MODE ((Rte_ModeType_DcmDiagnosticSessionControl)5U)
#endif

#ifndef RTE_MODE_DcmDiagnosticSessionControl_DCM_EXTENDED_DIAGNOSTIC_MODE
#define RTE_MODE_DcmDiagnosticSessionControl_DCM_EXTENDED_DIAGNOSTIC_MODE ((Rte_ModeType_DcmDiagnosticSessionControl)16U)
#endif

#ifndef RTE_MODE_DcmDiagnosticSessionControl_DCM_EXTENDED_DIAGNOSTIC_SESSION
#define RTE_MODE_DcmDiagnosticSessionControl_DCM_EXTENDED_DIAGNOSTIC_SESSION ((Rte_ModeType_DcmDiagnosticSessionControl)3U)
#endif

#ifndef RTE_MODE_DcmDiagnosticSessionControl_DCM_PROGRAMMING_SESSION
#define RTE_MODE_DcmDiagnosticSessionControl_DCM_PROGRAMMING_SESSION ((Rte_ModeType_DcmDiagnosticSessionControl)2U)
#endif

#ifndef RTE_MODE_DcmDiagnosticSessionControl_DCM_QUIESCENT_CURRENT_DIAGNOSTIC_MODE_START
#define RTE_MODE_DcmDiagnosticSessionControl_DCM_QUIESCENT_CURRENT_DIAGNOSTIC_MODE_START ((Rte_ModeType_DcmDiagnosticSessionControl)80U)
#endif

#ifndef RTE_MODE_DcmDiagnosticSessionControl_DCM_SAFETY_SYSTEM_DIAGNOSTIC_SESSION
#define RTE_MODE_DcmDiagnosticSessionControl_DCM_SAFETY_SYSTEM_DIAGNOSTIC_SESSION ((Rte_ModeType_DcmDiagnosticSessionControl)4U)
#endif

#ifndef RTE_MODE_DcmDiagnosticSessionControl_DCM_SLEEP_MODE_START_REQUEST
#define RTE_MODE_DcmDiagnosticSessionControl_DCM_SLEEP_MODE_START_REQUEST ((Rte_ModeType_DcmDiagnosticSessionControl)81U)
#endif

#ifndef RTE_TRANSITION_EcuMode
#define RTE_TRANSITION_EcuMode ((Rte_ModeType_EcuMode)0U)
#endif

#ifndef RTE_MODE_EcuMode_ECUM_STATE_APP_POST_RUN
#define RTE_MODE_EcuMode_ECUM_STATE_APP_POST_RUN ((Rte_ModeType_EcuMode)51U)
#endif

#ifndef RTE_MODE_EcuMode_ECUM_STATE_APP_RUN
#define RTE_MODE_EcuMode_ECUM_STATE_APP_RUN ((Rte_ModeType_EcuMode)50U)
#endif

#ifndef RTE_MODE_EcuMode_ECUM_STATE_OFF
#define RTE_MODE_EcuMode_ECUM_STATE_OFF ((Rte_ModeType_EcuMode)128U)
#endif

#ifndef RTE_MODE_EcuMode_ECUM_STATE_PREP_SHUTDOWN
#define RTE_MODE_EcuMode_ECUM_STATE_PREP_SHUTDOWN ((Rte_ModeType_EcuMode)68U)
#endif

#ifndef RTE_MODE_EcuMode_ECUM_STATE_RESET
#define RTE_MODE_EcuMode_ECUM_STATE_RESET ((Rte_ModeType_EcuMode)144U)
#endif

#ifndef RTE_MODE_EcuMode_ECUM_STATE_RUN
#define RTE_MODE_EcuMode_ECUM_STATE_RUN ((Rte_ModeType_EcuMode)48U)
#endif

#ifndef RTE_MODE_EcuMode_ECUM_STATE_SHUTDOWN
#define RTE_MODE_EcuMode_ECUM_STATE_SHUTDOWN ((Rte_ModeType_EcuMode)64U)
#endif

#ifndef RTE_MODE_EcuMode_ECUM_STATE_SLEEP
#define RTE_MODE_EcuMode_ECUM_STATE_SLEEP ((Rte_ModeType_EcuMode)80U)
#endif

#ifndef RTE_MODE_EcuMode_ECUM_STATE_STARTUP_ONE
#define RTE_MODE_EcuMode_ECUM_STATE_STARTUP_ONE ((Rte_ModeType_EcuMode)17U)
#endif

#ifndef RTE_MODE_EcuMode_ECUM_STATE_STARTUP_THREE
#define RTE_MODE_EcuMode_ECUM_STATE_STARTUP_THREE ((Rte_ModeType_EcuMode)19U)
#endif

#ifndef RTE_MODE_EcuMode_ECUM_STATE_STARTUP_TWO
#define RTE_MODE_EcuMode_ECUM_STATE_STARTUP_TWO ((Rte_ModeType_EcuMode)18U)
#endif

#ifndef RTE_TRANSITION_MDG_InitState
#define RTE_TRANSITION_MDG_InitState ((Rte_ModeType_MDG_InitState)255U)
#endif

#ifndef RTE_MODE_MDG_InitState_COMPLETE
#define RTE_MODE_MDG_InitState_COMPLETE ((Rte_ModeType_MDG_InitState)1U)
#endif

#ifndef RTE_MODE_MDG_InitState_START
#define RTE_MODE_MDG_InitState_START ((Rte_ModeType_MDG_InitState)0U)
#endif

#ifndef RTE_TRANSITION_MDG_PduGroup
#define RTE_TRANSITION_MDG_PduGroup ((Rte_ModeType_MDG_PduGroup)255U)
#endif

#ifndef RTE_MODE_MDG_PduGroup_START
#define RTE_MODE_MDG_PduGroup_START ((Rte_ModeType_MDG_PduGroup)1U)
#endif

#ifndef RTE_MODE_MDG_PduGroup_STOP
#define RTE_MODE_MDG_PduGroup_STOP ((Rte_ModeType_MDG_PduGroup)0U)
#endif

#ifndef RTE_TRANSITION_MDG_WakeupEvent
#define RTE_TRANSITION_MDG_WakeupEvent ((Rte_ModeType_MDG_WakeupEvent)255U)
#endif

#ifndef RTE_MODE_MDG_WakeupEvent_EXTERNAL_WDG
#define RTE_MODE_MDG_WakeupEvent_EXTERNAL_WDG ((Rte_ModeType_MDG_WakeupEvent)4U)
#endif

#ifndef RTE_MODE_MDG_WakeupEvent_GPT
#define RTE_MODE_MDG_WakeupEvent_GPT ((Rte_ModeType_MDG_WakeupEvent)5U)
#endif

#ifndef RTE_MODE_MDG_WakeupEvent_INITIAL_MODE
#define RTE_MODE_MDG_WakeupEvent_INITIAL_MODE ((Rte_ModeType_MDG_WakeupEvent)32U)
#endif

#ifndef RTE_MODE_MDG_WakeupEvent_INTERNAL_RESET
#define RTE_MODE_MDG_WakeupEvent_INTERNAL_RESET ((Rte_ModeType_MDG_WakeupEvent)2U)
#endif

#ifndef RTE_MODE_MDG_WakeupEvent_INTERNAL_WDG
#define RTE_MODE_MDG_WakeupEvent_INTERNAL_WDG ((Rte_ModeType_MDG_WakeupEvent)3U)
#endif

#ifndef RTE_MODE_MDG_WakeupEvent_POWER
#define RTE_MODE_MDG_WakeupEvent_POWER ((Rte_ModeType_MDG_WakeupEvent)0U)
#endif

#ifndef RTE_MODE_MDG_WakeupEvent_RESET
#define RTE_MODE_MDG_WakeupEvent_RESET ((Rte_ModeType_MDG_WakeupEvent)1U)
#endif

/*******************************************************************************
** Type Definitions for Implementation Datatypes                              **
*******************************************************************************/

/*******************************************************************************
** Type Definitions for Range Types                                           **
*******************************************************************************/

/*******************************************************************************
** Type Definitions for Invalid Value Types                                   **
*******************************************************************************/

/*******************************************************************************
** Type Definitions for Enumeration constants                                 **
*******************************************************************************/
/* polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> Number of type definitions for enumeration constants is depends on user configuration */
#ifndef BSWM_ECUMODETRANSITION_END
#define BSWM_ECUMODETRANSITION_END 0U
#endif /* BSWM_ECUMODETRANSITION_END */

#ifndef BSWM_ECUMODETRANSITION_ONGOING
#define BSWM_ECUMODETRANSITION_ONGOING 1U
#endif /* BSWM_ECUMODETRANSITION_ONGOING */

#ifndef BSWM_SHUTDOWNTARGET_RUN
#define BSWM_SHUTDOWNTARGET_RUN 0U
#endif /* BSWM_SHUTDOWNTARGET_RUN */

#ifndef BSWM_SHUTDOWNTARGET_SLEEP
#define BSWM_SHUTDOWNTARGET_SLEEP 1U
#endif /* BSWM_SHUTDOWNTARGET_SLEEP */

#ifndef BSWM_SHUTDOWNTARGET_OFF
#define BSWM_SHUTDOWNTARGET_OFF 2U
#endif /* BSWM_SHUTDOWNTARGET_OFF */

#ifndef BSWM_SHUTDOWNTARGET_RESET
#define BSWM_SHUTDOWNTARGET_RESET 3U
#endif /* BSWM_SHUTDOWNTARGET_RESET */

#ifndef ECUM_STATE_STARTUP
#define ECUM_STATE_STARTUP 16U
#endif /* ECUM_STATE_STARTUP */

#ifndef ECUM_STATE_STARTUP_ONE
#define ECUM_STATE_STARTUP_ONE 17U
#endif /* ECUM_STATE_STARTUP_ONE */

#ifndef ECUM_STATE_STARTUP_TWO
#define ECUM_STATE_STARTUP_TWO 18U
#endif /* ECUM_STATE_STARTUP_TWO */

#ifndef ECUM_STATE_STARTUP_THREE
#define ECUM_STATE_STARTUP_THREE 19U
#endif /* ECUM_STATE_STARTUP_THREE */

#ifndef ECUM_STATE_STARTUP_FOUR
#define ECUM_STATE_STARTUP_FOUR 20U
#endif /* ECUM_STATE_STARTUP_FOUR */

#ifndef ECUM_STATE_WAKEUP
#define ECUM_STATE_WAKEUP 32U
#endif /* ECUM_STATE_WAKEUP */

#ifndef ECUM_STATE_WAKEUP_ONE
#define ECUM_STATE_WAKEUP_ONE 33U
#endif /* ECUM_STATE_WAKEUP_ONE */

#ifndef ECUM_STATE_WAKEUP_VALIDATION
#define ECUM_STATE_WAKEUP_VALIDATION 34U
#endif /* ECUM_STATE_WAKEUP_VALIDATION */

#ifndef ECUM_STATE_WAKEUP_REACTION
#define ECUM_STATE_WAKEUP_REACTION 35U
#endif /* ECUM_STATE_WAKEUP_REACTION */

#ifndef ECUM_STATE_WAKEUP_TWO
#define ECUM_STATE_WAKEUP_TWO 36U
#endif /* ECUM_STATE_WAKEUP_TWO */

#ifndef ECUM_STATE_WAKEUP_WAKESLEEP
#define ECUM_STATE_WAKEUP_WAKESLEEP 37U
#endif /* ECUM_STATE_WAKEUP_WAKESLEEP */

#ifndef ECUM_STATE_WAKEUP_TTII
#define ECUM_STATE_WAKEUP_TTII 38U
#endif /* ECUM_STATE_WAKEUP_TTII */

#ifndef ECUM_STATE_RUN
#define ECUM_STATE_RUN 48U
#endif /* ECUM_STATE_RUN */

#ifndef ECUM_STATE_APP_RUN
#define ECUM_STATE_APP_RUN 50U
#endif /* ECUM_STATE_APP_RUN */

#ifndef ECUM_STATE_APP_POST_RUN
#define ECUM_STATE_APP_POST_RUN 51U
#endif /* ECUM_STATE_APP_POST_RUN */

#ifndef ECUM_STATE_SHUTDOWN
#define ECUM_STATE_SHUTDOWN 64U
#endif /* ECUM_STATE_SHUTDOWN */

#ifndef ECUM_STATE_PREP_SHUTDOWN
#define ECUM_STATE_PREP_SHUTDOWN 68U
#endif /* ECUM_STATE_PREP_SHUTDOWN */

#ifndef ECUM_STATE_GO_SLEEP
#define ECUM_STATE_GO_SLEEP 73U
#endif /* ECUM_STATE_GO_SLEEP */

#ifndef ECUM_STATE_GO_OFF_ONE
#define ECUM_STATE_GO_OFF_ONE 77U
#endif /* ECUM_STATE_GO_OFF_ONE */

#ifndef ECUM_STATE_GO_OFF_TWO
#define ECUM_STATE_GO_OFF_TWO 78U
#endif /* ECUM_STATE_GO_OFF_TWO */

#ifndef ECUM_STATE_SLEEP
#define ECUM_STATE_SLEEP 80U
#endif /* ECUM_STATE_SLEEP */

#ifndef ECUM_STATE_OFF
#define ECUM_STATE_OFF 128U
#endif /* ECUM_STATE_OFF */

#ifndef ECUM_STATE_RESET
#define ECUM_STATE_RESET 144U
#endif /* ECUM_STATE_RESET */

#ifndef BSWM_ECUSTATE_READY
#define BSWM_ECUSTATE_READY 0U
#endif /* BSWM_ECUSTATE_READY */

#ifndef BSWM_ECUSTATE_ENTRY_STARTUP_TWO
#define BSWM_ECUSTATE_ENTRY_STARTUP_TWO 18U
#endif /* BSWM_ECUSTATE_ENTRY_STARTUP_TWO */

#ifndef BSWM_ECUSTATE_ENTRY_STARTUP_THREE
#define BSWM_ECUSTATE_ENTRY_STARTUP_THREE 19U
#endif /* BSWM_ECUSTATE_ENTRY_STARTUP_THREE */

#ifndef BSWM_ECUSTATE_ENTRY_RUN
#define BSWM_ECUSTATE_ENTRY_RUN 48U
#endif /* BSWM_ECUSTATE_ENTRY_RUN */

#ifndef BSWM_ECUSTATE_ENTRY_SHUTDOWN
#define BSWM_ECUSTATE_ENTRY_SHUTDOWN 64U
#endif /* BSWM_ECUSTATE_ENTRY_SHUTDOWN */

#ifndef BSWM_ECUSTATE_ENTRY_PREP_SHUTDOWN
#define BSWM_ECUSTATE_ENTRY_PREP_SHUTDOWN 68U
#endif /* BSWM_ECUSTATE_ENTRY_PREP_SHUTDOWN */

#ifndef BSWM_ECUSTATE_ENTRY_SLEEP
#define BSWM_ECUSTATE_ENTRY_SLEEP 80U
#endif /* BSWM_ECUSTATE_ENTRY_SLEEP */

#ifndef BSWM_ECUSTATE_ENTRY_OFF
#define BSWM_ECUSTATE_ENTRY_OFF 128U
#endif /* BSWM_ECUSTATE_ENTRY_OFF */

#ifndef BSWM_ECUSTATE_ENTRY_RESET
#define BSWM_ECUSTATE_ENTRY_RESET 144U
#endif /* BSWM_ECUSTATE_ENTRY_RESET */

#ifndef BSWM_ECUSTATE_EXIT_STARTUP_TWO
#define BSWM_ECUSTATE_EXIT_STARTUP_TWO 274U
#endif /* BSWM_ECUSTATE_EXIT_STARTUP_TWO */

#ifndef BSWM_ECUSTATE_EXIT_STARTUP_THREE
#define BSWM_ECUSTATE_EXIT_STARTUP_THREE 275U
#endif /* BSWM_ECUSTATE_EXIT_STARTUP_THREE */

#ifndef BSWM_ECUSTATE_EXIT_RUN
#define BSWM_ECUSTATE_EXIT_RUN 304U
#endif /* BSWM_ECUSTATE_EXIT_RUN */

#ifndef BSWM_ECUSTATE_EXIT_SHUTDOWN
#define BSWM_ECUSTATE_EXIT_SHUTDOWN 320U
#endif /* BSWM_ECUSTATE_EXIT_SHUTDOWN */

#ifndef BSWM_ECUSTATE_EXIT_PREP_SHUTDOWN
#define BSWM_ECUSTATE_EXIT_PREP_SHUTDOWN 324U
#endif /* BSWM_ECUSTATE_EXIT_PREP_SHUTDOWN */

#ifndef BSWM_ECUSTATE_EXIT_SLEEP
#define BSWM_ECUSTATE_EXIT_SLEEP 336U
#endif /* BSWM_ECUSTATE_EXIT_SLEEP */

#ifndef COMM_MODE_NO_COM
#define COMM_MODE_NO_COM 0U
#endif /* COMM_MODE_NO_COM */

#ifndef COMM_MODE_FULL_COM
#define COMM_MODE_FULL_COM 2U
#endif /* COMM_MODE_FULL_COM */

/* polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> Number of type definitions for enumeration constants is depends on user configuration */

/* COMPATIBLE WITH C and C++ languages */
#ifdef __cplusplus
 }
#endif

#endif

/*******************************************************************************
* PRE-JUSTIFICATION END SECTION (MISRA-C RULE CHECKER)
*******************************************************************************/
/*
  polyspace:end<MISRA-C:5.1:Not a defect:Justify with annotations> Number of character is depends on user configuration
  polyspace:end<MISRA-C:19.1:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Memory Mapping)
  polyspace:end<MISRA-C:19.4:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte SWS #1154, #6713)
  polyspace:end<MISRA-C:19.6:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Memory Mapping)
  polyspace:end<MISRA-C:19.7:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte SWS #1236)
*/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

