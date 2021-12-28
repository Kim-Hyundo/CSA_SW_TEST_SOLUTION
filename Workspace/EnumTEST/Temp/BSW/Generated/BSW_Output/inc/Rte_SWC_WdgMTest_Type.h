
/*******************************************************************************
**  FILE-NAME: Rte_SWC_WdgMTest_Type.h                                                     **
**                                                                            **
**  MODULE-NAME: AUTOSAR RTE GENERATION TOOL                                  **
**                                                                            **
**  NOTE: This file is auto generated, do not edit this file manually.        **
**                                                                            **
********************************************************************************

********************************************************************************
**                      Generation Tool Information                           **
********************************************************************************
**  Tool Version: 4.10.3                                                   **
**                                                                            **
**  Change History: Refer log file (use -l option to generate log file)       **
**                                                                            **
********************************************************************************
**                      File Generation Information                           **
*******************************************************************************/
/*
 * INPUT FILE:
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\Ecu\ECUCD_EcucValueCollection.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\Ecu\Ecud_Com.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\Ecu\Ecud_ComXf.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\Ecu\Ecud_Det.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\Ecu\Ecud_E2EXf.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\Ecu\Ecud_EcuC.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\Ecu\Ecud_Os.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\Ecu\Ecud_Rte.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Bswmd\Bswmd_Adc.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Bswmd\Bswmd_BswM.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Bswmd\Bswmd_Can.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Bswmd\Bswmd_CanCM.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Bswmd\Bswmd_CanIf.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Bswmd\Bswmd_CanNm.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Bswmd\Bswmd_CanSM.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Bswmd\Bswmd_CanTp.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Bswmd\Bswmd_CanTrcv_255_Autron.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Bswmd\Bswmd_Com.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Bswmd\Bswmd_ComM.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Bswmd\Bswmd_ComXf.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Bswmd\Bswmd_Crc.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Bswmd\Bswmd_CryptoLib.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Bswmd\Bswmd_Dcm.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Bswmd\Bswmd_Dem.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Bswmd\Bswmd_Det.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Bswmd\Bswmd_Dio.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Bswmd\Bswmd_E2EXf.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Bswmd\Bswmd_Fee.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Bswmd\Bswmd_Fls.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Bswmd\Bswmd_FlsLoader.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Bswmd\Bswmd_Gpt.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Bswmd\Bswmd_Icu.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Bswmd\Bswmd_Irq.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Bswmd\Bswmd_Mcu.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Bswmd\Bswmd_MemIf.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Bswmd\Bswmd_Nm.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Bswmd\Bswmd_NvM.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Bswmd\Bswmd_PduR.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Bswmd\Bswmd_Port.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Bswmd\Bswmd_Pwm.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Bswmd\Bswmd_Spi.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Bswmd\Bswmd_Wdg.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Bswmd\Bswmd_Xcp.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Composition\EcuExtract.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\DBImport\ACANFD1.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\DBImport\ACANFD2.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\DBImport\DebugCANFD.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\DBImport\ECANFD.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\DataTypes\AUTOSAR_DataTypes.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Swcd_App\App_ADAS_DRV.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Swcd_App\App_Dcm.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Swcd_App\App_Dem.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Swcd_App\App_Failsafe.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Swcd_App\App_Mode.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Swcd_App\App_NM.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Swcd_App\App_NvM.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Swcd_App\App_WdgM.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Swcd_Bsw\MODE_PortInterfaces.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Swcd_Bsw\Swcd_Bsw_BswM.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Swcd_Bsw\Swcd_Bsw_EcuM_Slave.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Swcd_Bsw\Swcd_Bsw_Os.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Swcd_Bsw\Swcd_ComM.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Swcd_Bsw\Swcd_Det.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Configuration\System\Transformer\Transformer.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Generated\Bsw_Output\bswmd\Bswmd_Csm.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Generated\Bsw_Output\bswmd\Bswmd_EcuM.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Generated\Bsw_Output\bswmd\Bswmd_IoHwAb.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Generated\Bsw_Output\bswmd\Bswmd_Os.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Generated\Bsw_Output\bswmd\Bswmd_WdgIf.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Generated\Bsw_Output\bswmd\Bswmd_WdgM.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Generated\Bsw_Output\bswmd\Bswmd_Wdg_76_Acw.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Generated\Bsw_Output\swcd\Swcd_Bsw_Csm.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Generated\Bsw_Output\swcd\Swcd_Bsw_Dcm.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Generated\Bsw_Output\swcd\Swcd_Bsw_Dem.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Generated\Bsw_Output\swcd\Swcd_Bsw_EcuM.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Generated\Bsw_Output\swcd\Swcd_Bsw_NvM.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Generated\Bsw_Output\swcd\Swcd_IoHwAb.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Generated\Bsw_Output\swcd\Swcd_WdgM.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Static_Code\Integration_Code\integration_T1\swcd\Ecud_Rte_T1Ad_6Core.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Static_Code\Integration_Code\integration_T1\swcd\Swcd_Asw_T1Ad_6Core.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Static_Code\Modules\b_autosar_sys_EcuM_R40\generator\EcuM_PortInterface.arxml
 *      D:\Project\01_HKMC\05_DCU15_Dev\RS4\Static_Code\Modules\b_autosar_sys_WdgM_R40\generator\Swcd_WdgM_Fixed.arxml

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
#ifndef RTE_SWC_WDGMTEST_TYPE_H
#define RTE_SWC_WDGMTEST_TYPE_H

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
  #if (RTE_SW_MINOR_VERSION != 10)
    #error "Rte_Cfg.h : Mismatch in Rte Specification Minor Version"
  #endif
#else
  #define RTE_SW_MINOR_VERSION 10
#endif

#ifdef RTE_SW_PATCH_VERSION
  #if (RTE_SW_PATCH_VERSION != 3)
    #error "Rte_Cfg.h : Mismatch in Rte Specification Patch Version"
  #endif
#else
  #define RTE_SW_PATCH_VERSION 3
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
#ifndef RTE_MODETYPE_DcmApplicationUpdated
#define RTE_MODETYPE_DcmApplicationUpdated
typedef uint8 Rte_ModeType_DcmApplicationUpdated;
#endif

#ifndef RTE_MODETYPE_DcmCommunicationControl
#define RTE_MODETYPE_DcmCommunicationControl
typedef uint8 Rte_ModeType_DcmCommunicationControl;
#endif

#ifndef RTE_MODETYPE_DcmControlDTCSetting
#define RTE_MODETYPE_DcmControlDTCSetting
typedef uint8 Rte_ModeType_DcmControlDTCSetting;
#endif

#ifndef RTE_MODETYPE_DcmDiagnosticSessionControl
#define RTE_MODETYPE_DcmDiagnosticSessionControl
typedef uint8 Rte_ModeType_DcmDiagnosticSessionControl;
#endif

#ifndef RTE_MODETYPE_DcmEcuReset
#define RTE_MODETYPE_DcmEcuReset
typedef uint8 Rte_ModeType_DcmEcuReset;
#endif

#ifndef RTE_MODETYPE_DcmModeRapidPowerShutDown
#define RTE_MODETYPE_DcmModeRapidPowerShutDown
typedef uint8 Rte_ModeType_DcmModeRapidPowerShutDown;
#endif

#ifndef RTE_MODETYPE_MDG_CanSMBORState
#define RTE_MODETYPE_MDG_CanSMBORState
typedef uint8 Rte_ModeType_MDG_CanSMBORState;
#endif

#ifndef RTE_MODETYPE_MDG_CanSMState
#define RTE_MODETYPE_MDG_CanSMState
typedef uint8 Rte_ModeType_MDG_CanSMState;
#endif

#ifndef RTE_MODETYPE_MDG_ComMMode
#define RTE_MODETYPE_MDG_ComMMode
typedef uint8 Rte_ModeType_MDG_ComMMode;
#endif

#ifndef RTE_MODETYPE_MDG_InitState
#define RTE_MODETYPE_MDG_InitState
typedef uint8 Rte_ModeType_MDG_InitState;
#endif

#ifndef RTE_MODETYPE_MDG_LinSMState
#define RTE_MODETYPE_MDG_LinSMState
typedef uint8 Rte_ModeType_MDG_LinSMState;
#endif

#ifndef RTE_MODETYPE_MDG_PduGroup
#define RTE_MODETYPE_MDG_PduGroup
typedef uint8 Rte_ModeType_MDG_PduGroup;
#endif

#ifndef RTE_MODETYPE_MDG_WakeupEvent
#define RTE_MODETYPE_MDG_WakeupEvent
typedef uint8 Rte_ModeType_MDG_WakeupEvent;
#endif

#ifndef RTE_MODETYPE_WdgM_Mode
#define RTE_MODETYPE_WdgM_Mode
typedef uint8 Rte_ModeType_WdgM_Mode;
#endif

/*
  polyspace:end<MISRA-C:5.3:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte Modes (Rte SWS #2627))
*/
/*******************************************************************************
* Macros Used For Modes                                                       **
*******************************************************************************/
#ifndef RTE_TRANSITION_DcmApplicationUpdated
#define RTE_TRANSITION_DcmApplicationUpdated ((Rte_ModeType_DcmApplicationUpdated)255U)
#endif

#ifndef RTE_MODE_DcmApplicationUpdated_APP_NOT_UPDATED
#define RTE_MODE_DcmApplicationUpdated_APP_NOT_UPDATED ((Rte_ModeType_DcmApplicationUpdated)0U)
#endif

#ifndef RTE_MODE_DcmApplicationUpdated_APP_UPDATED
#define RTE_MODE_DcmApplicationUpdated_APP_UPDATED ((Rte_ModeType_DcmApplicationUpdated)1U)
#endif

#ifndef RTE_TRANSITION_DcmCommunicationControl
#define RTE_TRANSITION_DcmCommunicationControl ((Rte_ModeType_DcmCommunicationControl)12U)
#endif

#ifndef RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_DISABLE_TX_NM
#define RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_DISABLE_TX_NM ((Rte_ModeType_DcmCommunicationControl)0U)
#endif

#ifndef RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM
#define RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM ((Rte_ModeType_DcmCommunicationControl)1U)
#endif

#ifndef RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM_NM
#define RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM_NM ((Rte_ModeType_DcmCommunicationControl)2U)
#endif

#ifndef RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NM
#define RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NM ((Rte_ModeType_DcmCommunicationControl)3U)
#endif

#ifndef RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NORMAL
#define RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NORMAL ((Rte_ModeType_DcmCommunicationControl)4U)
#endif

#ifndef RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NORM_NM
#define RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NORM_NM ((Rte_ModeType_DcmCommunicationControl)5U)
#endif

#ifndef RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NM
#define RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NM ((Rte_ModeType_DcmCommunicationControl)6U)
#endif

#ifndef RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM
#define RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM ((Rte_ModeType_DcmCommunicationControl)7U)
#endif

#ifndef RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM_NM
#define RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM_NM ((Rte_ModeType_DcmCommunicationControl)8U)
#endif

#ifndef RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NM
#define RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NM ((Rte_ModeType_DcmCommunicationControl)9U)
#endif

#ifndef RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM
#define RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM ((Rte_ModeType_DcmCommunicationControl)10U)
#endif

#ifndef RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM_NM
#define RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM_NM ((Rte_ModeType_DcmCommunicationControl)11U)
#endif

#ifndef RTE_TRANSITION_DcmControlDTCSetting
#define RTE_TRANSITION_DcmControlDTCSetting ((Rte_ModeType_DcmControlDTCSetting)2U)
#endif

#ifndef RTE_MODE_DcmControlDTCSetting_DISABLEDTCSETTING
#define RTE_MODE_DcmControlDTCSetting_DISABLEDTCSETTING ((Rte_ModeType_DcmControlDTCSetting)0U)
#endif

#ifndef RTE_MODE_DcmControlDTCSetting_ENABLEDTCSETTING
#define RTE_MODE_DcmControlDTCSetting_ENABLEDTCSETTING ((Rte_ModeType_DcmControlDTCSetting)1U)
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

#ifndef RTE_TRANSITION_DcmEcuReset
#define RTE_TRANSITION_DcmEcuReset ((Rte_ModeType_DcmEcuReset)255U)
#endif

#ifndef RTE_MODE_DcmEcuReset_EXECUTE
#define RTE_MODE_DcmEcuReset_EXECUTE ((Rte_ModeType_DcmEcuReset)6U)
#endif

#ifndef RTE_MODE_DcmEcuReset_HARD
#define RTE_MODE_DcmEcuReset_HARD ((Rte_ModeType_DcmEcuReset)1U)
#endif

#ifndef RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER
#define RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER ((Rte_ModeType_DcmEcuReset)4U)
#endif

#ifndef RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER
#define RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER ((Rte_ModeType_DcmEcuReset)5U)
#endif

#ifndef RTE_MODE_DcmEcuReset_KEYONOFF
#define RTE_MODE_DcmEcuReset_KEYONOFF ((Rte_ModeType_DcmEcuReset)2U)
#endif

#ifndef RTE_MODE_DcmEcuReset_NONE
#define RTE_MODE_DcmEcuReset_NONE ((Rte_ModeType_DcmEcuReset)0U)
#endif

#ifndef RTE_MODE_DcmEcuReset_SOFT
#define RTE_MODE_DcmEcuReset_SOFT ((Rte_ModeType_DcmEcuReset)3U)
#endif

#ifndef RTE_TRANSITION_DcmModeRapidPowerShutDown
#define RTE_TRANSITION_DcmModeRapidPowerShutDown ((Rte_ModeType_DcmModeRapidPowerShutDown)2U)
#endif

#ifndef RTE_MODE_DcmModeRapidPowerShutDown_DISABLE_RAPIDPOWERSHUTDOWN
#define RTE_MODE_DcmModeRapidPowerShutDown_DISABLE_RAPIDPOWERSHUTDOWN ((Rte_ModeType_DcmModeRapidPowerShutDown)0U)
#endif

#ifndef RTE_MODE_DcmModeRapidPowerShutDown_ENABLE_RAPIDPOWERSHUTDOWN
#define RTE_MODE_DcmModeRapidPowerShutDown_ENABLE_RAPIDPOWERSHUTDOWN ((Rte_ModeType_DcmModeRapidPowerShutDown)1U)
#endif

#ifndef RTE_TRANSITION_MDG_CanSMBORState
#define RTE_TRANSITION_MDG_CanSMBORState ((Rte_ModeType_MDG_CanSMBORState)255U)
#endif

#ifndef RTE_MODE_MDG_CanSMBORState_COMPLETE
#define RTE_MODE_MDG_CanSMBORState_COMPLETE ((Rte_ModeType_MDG_CanSMBORState)0U)
#endif

#ifndef RTE_MODE_MDG_CanSMBORState_START
#define RTE_MODE_MDG_CanSMBORState_START ((Rte_ModeType_MDG_CanSMBORState)1U)
#endif

#ifndef RTE_TRANSITION_MDG_CanSMState
#define RTE_TRANSITION_MDG_CanSMState ((Rte_ModeType_MDG_CanSMState)255U)
#endif

#ifndef RTE_MODE_MDG_CanSMState_BUS_OFF
#define RTE_MODE_MDG_CanSMState_BUS_OFF ((Rte_ModeType_MDG_CanSMState)3U)
#endif

#ifndef RTE_MODE_MDG_CanSMState_CHANGE_BAUDRATE
#define RTE_MODE_MDG_CanSMState_CHANGE_BAUDRATE ((Rte_ModeType_MDG_CanSMState)4U)
#endif

#ifndef RTE_MODE_MDG_CanSMState_FULL_COM
#define RTE_MODE_MDG_CanSMState_FULL_COM ((Rte_ModeType_MDG_CanSMState)2U)
#endif

#ifndef RTE_MODE_MDG_CanSMState_NO_COM
#define RTE_MODE_MDG_CanSMState_NO_COM ((Rte_ModeType_MDG_CanSMState)0U)
#endif

#ifndef RTE_MODE_MDG_CanSMState_SILENT_COM
#define RTE_MODE_MDG_CanSMState_SILENT_COM ((Rte_ModeType_MDG_CanSMState)1U)
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

#ifndef RTE_TRANSITION_MDG_InitState
#define RTE_TRANSITION_MDG_InitState ((Rte_ModeType_MDG_InitState)255U)
#endif

#ifndef RTE_MODE_MDG_InitState_COMPLETE
#define RTE_MODE_MDG_InitState_COMPLETE ((Rte_ModeType_MDG_InitState)1U)
#endif

#ifndef RTE_MODE_MDG_InitState_START
#define RTE_MODE_MDG_InitState_START ((Rte_ModeType_MDG_InitState)0U)
#endif

#ifndef RTE_TRANSITION_MDG_LinSMState
#define RTE_TRANSITION_MDG_LinSMState ((Rte_ModeType_MDG_LinSMState)255U)
#endif

#ifndef RTE_MODE_MDG_LinSMState_FULL_COM
#define RTE_MODE_MDG_LinSMState_FULL_COM ((Rte_ModeType_MDG_LinSMState)1U)
#endif

#ifndef RTE_MODE_MDG_LinSMState_NO_COM
#define RTE_MODE_MDG_LinSMState_NO_COM ((Rte_ModeType_MDG_LinSMState)0U)
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

#ifndef RTE_TRANSITION_WdgM_Mode
#define RTE_TRANSITION_WdgM_Mode ((Rte_ModeType_WdgM_Mode)5U)
#endif

#ifndef RTE_MODE_WdgM_Mode_SUPERVISION_DEACTIVATED
#define RTE_MODE_WdgM_Mode_SUPERVISION_DEACTIVATED ((Rte_ModeType_WdgM_Mode)4U)
#endif

#ifndef RTE_MODE_WdgM_Mode_SUPERVISION_EXPIRED
#define RTE_MODE_WdgM_Mode_SUPERVISION_EXPIRED ((Rte_ModeType_WdgM_Mode)2U)
#endif

#ifndef RTE_MODE_WdgM_Mode_SUPERVISION_FAILED
#define RTE_MODE_WdgM_Mode_SUPERVISION_FAILED ((Rte_ModeType_WdgM_Mode)1U)
#endif

#ifndef RTE_MODE_WdgM_Mode_SUPERVISION_OK
#define RTE_MODE_WdgM_Mode_SUPERVISION_OK ((Rte_ModeType_WdgM_Mode)0U)
#endif

#ifndef RTE_MODE_WdgM_Mode_SUPERVISION_STOPPED
#define RTE_MODE_WdgM_Mode_SUPERVISION_STOPPED ((Rte_ModeType_WdgM_Mode)3U)
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
#ifndef WDGM_SE_INIT
#define WDGM_SE_INIT 300U
#endif /* WDGM_SE_INIT */

#ifndef WDGM_SE_WDGMTEST
#define WDGM_SE_WDGMTEST 400U
#endif /* WDGM_SE_WDGMTEST */

#ifndef WDGM_GLOBAL_STATUS_OK
#define WDGM_GLOBAL_STATUS_OK 0U
#endif /* WDGM_GLOBAL_STATUS_OK */

#ifndef WDGM_GLOBAL_STATUS_FAILED
#define WDGM_GLOBAL_STATUS_FAILED 1U
#endif /* WDGM_GLOBAL_STATUS_FAILED */

#ifndef WDGM_GLOBAL_STATUS_EXPIRED
#define WDGM_GLOBAL_STATUS_EXPIRED 2U
#endif /* WDGM_GLOBAL_STATUS_EXPIRED */

#ifndef WDGM_GLOBAL_STATUS_STOPPED
#define WDGM_GLOBAL_STATUS_STOPPED 3U
#endif /* WDGM_GLOBAL_STATUS_STOPPED */

#ifndef WDGM_GLOBAL_STATUS_DEACTIVATED
#define WDGM_GLOBAL_STATUS_DEACTIVATED 4U
#endif /* WDGM_GLOBAL_STATUS_DEACTIVATED */

#ifndef WDGM_WDGMMODE0
#define WDGM_WDGMMODE0 0U
#endif /* WDGM_WDGMMODE0 */

#ifndef WDGM_WDGMMODE1
#define WDGM_WDGMMODE1 1U
#endif /* WDGM_WDGMMODE1 */

#ifndef WDGM_SE_INIT_CP_INIT_AS0
#define WDGM_SE_INIT_CP_INIT_AS0 0U
#endif /* WDGM_SE_INIT_CP_INIT_AS0 */

#ifndef WDGM_SE_INIT_CP_INIT_ILS_0
#define WDGM_SE_INIT_CP_INIT_ILS_0 1U
#endif /* WDGM_SE_INIT_CP_INIT_ILS_0 */

#ifndef WDGM_SE_INIT_CP_INIT_ILS_1
#define WDGM_SE_INIT_CP_INIT_ILS_1 2U
#endif /* WDGM_SE_INIT_CP_INIT_ILS_1 */

#ifndef WDGM_SE_INIT_CP_INIT_AS1
#define WDGM_SE_INIT_CP_INIT_AS1 3U
#endif /* WDGM_SE_INIT_CP_INIT_AS1 */

#ifndef WDGM_SE_INIT_CP_INIT_AS2
#define WDGM_SE_INIT_CP_INIT_AS2 4U
#endif /* WDGM_SE_INIT_CP_INIT_AS2 */

#ifndef WDGM_SE_INIT_CP_INIT_AS3
#define WDGM_SE_INIT_CP_INIT_AS3 5U
#endif /* WDGM_SE_INIT_CP_INIT_AS3 */

#ifndef WDGM_SE_INIT_CP_INIT_AS4
#define WDGM_SE_INIT_CP_INIT_AS4 6U
#endif /* WDGM_SE_INIT_CP_INIT_AS4 */

#ifndef WDGM_SE_INIT_CP_INIT_AS5
#define WDGM_SE_INIT_CP_INIT_AS5 7U
#endif /* WDGM_SE_INIT_CP_INIT_AS5 */

#ifndef WDGM_SE_WDGMTEST_CP_WDGMTEST_AS0
#define WDGM_SE_WDGMTEST_CP_WDGMTEST_AS0 0U
#endif /* WDGM_SE_WDGMTEST_CP_WDGMTEST_AS0 */

#ifndef WDGM_SE_WDGMTEST_CP_WDGMTEST_ILS_0
#define WDGM_SE_WDGMTEST_CP_WDGMTEST_ILS_0 1U
#endif /* WDGM_SE_WDGMTEST_CP_WDGMTEST_ILS_0 */

#ifndef WDGM_SE_WDGMTEST_CP_WDGMTEST_ILS_1
#define WDGM_SE_WDGMTEST_CP_WDGMTEST_ILS_1 2U
#endif /* WDGM_SE_WDGMTEST_CP_WDGMTEST_ILS_1 */

#ifndef WDGM_SE_WDGMTEST_CP_WDGMTEST_ILS_2
#define WDGM_SE_WDGMTEST_CP_WDGMTEST_ILS_2 3U
#endif /* WDGM_SE_WDGMTEST_CP_WDGMTEST_ILS_2 */

#ifndef WDGM_SE_WDGMTEST_CP_WDGMTEST_DS0
#define WDGM_SE_WDGMTEST_CP_WDGMTEST_DS0 4U
#endif /* WDGM_SE_WDGMTEST_CP_WDGMTEST_DS0 */

#ifndef WDGM_SE_WDGMTEST_CP_WDGMTEST_DS1
#define WDGM_SE_WDGMTEST_CP_WDGMTEST_DS1 5U
#endif /* WDGM_SE_WDGMTEST_CP_WDGMTEST_DS1 */

#ifndef WDGM_SE_WDGMTEST_CP_WDGMTEST_AS1
#define WDGM_SE_WDGMTEST_CP_WDGMTEST_AS1 6U
#endif /* WDGM_SE_WDGMTEST_CP_WDGMTEST_AS1 */

#ifndef WDGM_SE_WDGMTEST_CP_WDGMTEST_AS2
#define WDGM_SE_WDGMTEST_CP_WDGMTEST_AS2 7U
#endif /* WDGM_SE_WDGMTEST_CP_WDGMTEST_AS2 */

#ifndef WDGM_SE_WDGMTEST_CP_WDGMTEST_AS3
#define WDGM_SE_WDGMTEST_CP_WDGMTEST_AS3 8U
#endif /* WDGM_SE_WDGMTEST_CP_WDGMTEST_AS3 */

#ifndef WDGM_SE_WDGMTEST_CP_WDGMTEST_AS4
#define WDGM_SE_WDGMTEST_CP_WDGMTEST_AS4 9U
#endif /* WDGM_SE_WDGMTEST_CP_WDGMTEST_AS4 */

#ifndef WDGM_SE_WDGMTEST_CP_WDGMTEST_AS5
#define WDGM_SE_WDGMTEST_CP_WDGMTEST_AS5 10U
#endif /* WDGM_SE_WDGMTEST_CP_WDGMTEST_AS5 */

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

