
/*******************************************************************************
**  FILE-NAME: Rte_EcuM_Type.h                                                     **
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
#ifndef RTE_ECUM_TYPE_H
#define RTE_ECUM_TYPE_H

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

/*
  polyspace:end<MISRA-C:5.3:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte Modes (Rte SWS #2627))
*/
/*******************************************************************************
* Macros Used For Modes                                                       **
*******************************************************************************/

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
#ifndef ECUM_REQUEST_RUN
#define ECUM_REQUEST_RUN 0U
#endif /* ECUM_REQUEST_RUN */

#ifndef ECUM_REQUEST_SLEEP
#define ECUM_REQUEST_SLEEP 1U
#endif /* ECUM_REQUEST_SLEEP */

#ifndef ECUM_REQUEST_RESET
#define ECUM_REQUEST_RESET 3U
#endif /* ECUM_REQUEST_RESET */

#ifndef ECUM_REQUEST_OFF
#define ECUM_REQUEST_OFF 2U
#endif /* ECUM_REQUEST_OFF */

#ifndef ECUM_BOOT_TARGET_APP
#define ECUM_BOOT_TARGET_APP 0U
#endif /* ECUM_BOOT_TARGET_APP */

#ifndef ECUM_BOOT_TARGET_OEM_BOOTLOADER
#define ECUM_BOOT_TARGET_OEM_BOOTLOADER 1U
#endif /* ECUM_BOOT_TARGET_OEM_BOOTLOADER */

#ifndef ECUM_BOOT_TARGET_SYS_BOOTLOADER
#define ECUM_BOOT_TARGET_SYS_BOOTLOADER 2U
#endif /* ECUM_BOOT_TARGET_SYS_BOOTLOADER */

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

