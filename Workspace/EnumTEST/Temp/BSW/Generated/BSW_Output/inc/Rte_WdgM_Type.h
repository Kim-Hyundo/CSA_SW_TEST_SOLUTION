
/*******************************************************************************
**  FILE-NAME: Rte_WdgM_Type.h                                                     **
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
#ifndef RTE_WDGM_TYPE_H
#define RTE_WDGM_TYPE_H

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
#ifndef WDGM_LOCAL_STATUS_OK
#define WDGM_LOCAL_STATUS_OK 0U
#endif /* WDGM_LOCAL_STATUS_OK */

#ifndef WDGM_LOCAL_STATUS_FAILED
#define WDGM_LOCAL_STATUS_FAILED 1U
#endif /* WDGM_LOCAL_STATUS_FAILED */

#ifndef WDGM_LOCAL_STATUS_EXPIRED
#define WDGM_LOCAL_STATUS_EXPIRED 2U
#endif /* WDGM_LOCAL_STATUS_EXPIRED */

#ifndef WDGM_LOCAL_STATUS_DEACTIVATED
#define WDGM_LOCAL_STATUS_DEACTIVATED 4U
#endif /* WDGM_LOCAL_STATUS_DEACTIVATED */

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

