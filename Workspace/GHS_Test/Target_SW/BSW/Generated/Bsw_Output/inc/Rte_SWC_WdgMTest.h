
/*******************************************************************************
**  FILE-NAME: Rte_SWC_WdgMTest.h                                                     **
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

/*******************************************************************************
**                         MULTIPLE INCLUSION PROTECTION                      **
*******************************************************************************/
 #ifndef RTE_SWC_WDGMTEST_H
      #define RTE_SWC_WDGMTEST_H
 /*
  * CAUTION:
  *
  * Do NOT
  *
  *   #define RTE_ALLOW_CROSS_HEADER_INCLUSION
  *
  * in ASW/BSW code. The symbol shall be used only for RTE internally.
  */
 #ifndef RTE_ALLOW_CROSS_HEADER_INCLUSION
      #ifdef RTE_APPLICATION_HEADER_FILE
      #error Multiple application header files included.
      #endif
      #define RTE_APPLICATION_HEADER_FILE
      #endif

/*******************************************************************************
**                  Include Section                                           **
*******************************************************************************/
/* polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Inclusion of Header Files) */
#include "Rte_SWC_WdgMTest_Type.h"

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
** Init Macro
*******************************************************************************/

/******************************************************************************
** Type Definitions for Rte API                                               **
*******************************************************************************/

/*******************************************************************************
** Global Variables                                                           **
*******************************************************************************/

/*******************************************************************************
** Global Variables for Per Instance Memory                                   **
*******************************************************************************/

/*******************************************************************************
** Invalid Value Const Variables                                              **
*******************************************************************************/

/*******************************************************************************
** Macros for Direct API functions defined in PDS                             **
*******************************************************************************/

/*******************************************************************************
** Macros for InDirect(port oriented) API functions defined in PDS            **
*******************************************************************************/

/*******************************************************************************
** Type Definitions for port handles of PDS                                   **
*******************************************************************************/

/*******************************************************************************
** Type Definitions for component instance handles                            **
*******************************************************************************/
/*
  polyspace:begin<MISRA-C:5.7:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte SWS #3724)
*/
struct Rte_CDS_SWC_WdgMTest
{
  VAR(uint8, RTE_DATA) _dummy;
};

/*
  polyspace:end<MISRA-C:5.7:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte SWS #3724)
*/
/*******************************************************************************
** Component instance handles                                                 **
*******************************************************************************/
#define EcucPartition_Main_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern const struct Rte_CDS_SWC_WdgMTest Rte_Inst_SWC_WdgMTest;
#define EcucPartition_Main_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
** Global Variables for Component Instance Handle                             **
*******************************************************************************/

/*******************************************************************************
** Type Definitions for component instance handles                            **
*******************************************************************************/

/*******************************************************************************
** Type Definitions for PerInstanceMemory (Exists only for multiple instances)**
*******************************************************************************/

/*******************************************************************************
** Macros for Direct API functions                                            **
*******************************************************************************/

/*******************************************************************************
** Macros for Exclusive Areas                                                 **
*******************************************************************************/

/*******************************************************************************
** Macros for ApplicationError in Client Server                               **
*******************************************************************************/

#ifndef RTE_E_WdgM_AliveSupervision_E_NOT_OK
#define RTE_E_WdgM_AliveSupervision_E_NOT_OK 1U
#endif

#ifndef RTE_E_WdgM_API_E_NOT_OK
#define RTE_E_WdgM_API_E_NOT_OK 1U
#endif

/*******************************************************************************
** Prototypes for Rte API                                                     **
*******************************************************************************/
#define EcucPartition_Main_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_WdgMTest_SE_WdgMTest_CheckpointReached(
	/* polyspace<MISRA2012:D4.5:Not a defect:Justify with annotations> User defines parameter name */
	IN WdgM_CheckpointIdType ddCheckpointID);

#define EcucPartition_Main_STOP_SEC_CODE
#include "MemMap.h"

#define EcucPartition_Main_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_WdgMTest_WdgM_API_R_GetFirstExpiredSEID(
	/* polyspace<MISRA2012:D4.5:Not a defect:Justify with annotations> User defines parameter name */
	OUT P2VAR(WdgM_SupervisedEntityIdType, AUTOMATIC, RTE_APPL_DATA) pSEID);

#define EcucPartition_Main_STOP_SEC_CODE
#include "MemMap.h"

#define EcucPartition_Main_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_WdgMTest_WdgM_API_R_GetGlobalStatus(
	/* polyspace<MISRA2012:D4.5:Not a defect:Justify with annotations> User defines parameter name */
	OUT P2VAR(WdgM_GlobalStatusType, AUTOMATIC, RTE_APPL_DATA) pStatus);

#define EcucPartition_Main_STOP_SEC_CODE
#include "MemMap.h"

#define EcucPartition_Main_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_SWC_WdgMTest_WdgM_API_R_SetMode(
	/* polyspace<MISRA2012:D4.5:Not a defect:Justify with annotations> User defines parameter name */
	IN WdgM_ModeType ddMode,
	/* polyspace<MISRA2012:D4.5:Not a defect:Justify with annotations> User defines parameter name */
	IN uint16 usCallerID);

#define EcucPartition_Main_STOP_SEC_CODE
#include "MemMap.h"

#define EcucPartition_Main_START_SEC_CODE
#include "MemMap.h"

extern FUNC(Rte_ModeType_WdgM_Mode, RTE_CODE) Rte_Mode_SWC_WdgMTest_globalMode_currentMode(void);

#define EcucPartition_Main_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** API Mapping                                                                **
*******************************************************************************/

#ifndef Rte_Mode_globalMode_currentMode
#define Rte_Mode_globalMode_currentMode  Rte_Mode_SWC_WdgMTest_globalMode_currentMode
#endif

#ifndef Rte_Call_SE_WdgMTest_CheckpointReached
#define Rte_Call_SE_WdgMTest_CheckpointReached Rte_Call_SWC_WdgMTest_SE_WdgMTest_CheckpointReached
#endif

#ifndef Rte_Call_WdgM_API_R_GetFirstExpiredSEID
#define Rte_Call_WdgM_API_R_GetFirstExpiredSEID Rte_Call_SWC_WdgMTest_WdgM_API_R_GetFirstExpiredSEID
#endif

#ifndef Rte_Call_WdgM_API_R_GetGlobalStatus
#define Rte_Call_WdgM_API_R_GetGlobalStatus Rte_Call_SWC_WdgMTest_WdgM_API_R_GetGlobalStatus
#endif

#ifndef Rte_Call_WdgM_API_R_SetMode
#define Rte_Call_WdgM_API_R_SetMode Rte_Call_SWC_WdgMTest_WdgM_API_R_SetMode
#endif

/*******************************************************************************
** Client Server Macro                                                        **
*******************************************************************************/

/*******************************************************************************
** Prototypes for Runnable entities                                           **
*******************************************************************************/
/*
  polyspace:begin<MISRA-C:8.8:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte SWS #1132)
*/

#define SWC_WdgMTest_START_SEC_CODE
#include "SWC_WdgMTest_MemMap.h"
FUNC(void, SWC_WdgMTest_CODE) RE_WdgMTest(void);

FUNC(void, SWC_WdgMTest_CODE) RE_WdgMTestGlobalMode(void);

#define SWC_WdgMTest_STOP_SEC_CODE
#include "SWC_WdgMTest_MemMap.h"

/*
  polyspace:end<MISRA-C:8.8:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte SWS #1132)
*/

/*******************************************************************************
** Runnables Mapping                                                          **
*******************************************************************************/
#ifndef RTE_RUNNABLE_RE_WdgMTest
#define RTE_RUNNABLE_RE_WdgMTest RE_WdgMTest
#endif
#ifndef RTE_RUNNABLE_RE_WdgMTestGlobalMode
#define RTE_RUNNABLE_RE_WdgMTestGlobalMode RE_WdgMTestGlobalMode
#endif

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

