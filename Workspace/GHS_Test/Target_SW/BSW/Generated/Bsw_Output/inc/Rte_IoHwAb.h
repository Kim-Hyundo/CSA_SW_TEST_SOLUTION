
/*******************************************************************************
**  FILE-NAME: Rte_IoHwAb.h                                                     **
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
 #ifndef RTE_IOHWAB_H
      #define RTE_IOHWAB_H
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
#include "Rte_IoHwAb_Type.h"

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
struct Rte_CDS_IoHwAb
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
extern const struct Rte_CDS_IoHwAb Rte_Inst_IoHwAb;
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

#ifndef RTE_E_IoHwAb_If_AnaInDir_E_BUSY
#define RTE_E_IoHwAb_If_AnaInDir_E_BUSY 4U
#endif

#ifndef RTE_E_IoHwAb_If_AnaInDir_E_SETUP_BUFFER_FAIL
#define RTE_E_IoHwAb_If_AnaInDir_E_SETUP_BUFFER_FAIL 6U
#endif

#ifndef RTE_E_IoHwAb_If_AnaInDir_E_WRONG_LENGTH
#define RTE_E_IoHwAb_If_AnaInDir_E_WRONG_LENGTH 5U
#endif

#ifndef RTE_E_IoHwAb_If_Gpt_E_NOT_SUPPORTED
#define RTE_E_IoHwAb_If_Gpt_E_NOT_SUPPORTED 10U
#endif

#ifndef RTE_E_IoHwAb_If_AnaIn_E_BUSY
#define RTE_E_IoHwAb_If_AnaIn_E_BUSY 7U
#endif

/*******************************************************************************
** Prototypes for Rte API                                                     **
*******************************************************************************/
#define EcucPartition_Main_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_IoHwAb_R_IoHwAbGptLogical_IoHwAbTest_Cbk_Notification(void);

#define EcucPartition_Main_STOP_SEC_CODE
#include "MemMap.h"

#define EcucPartition_Main_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_IoHwAb_R_VolMon_Cbk_Notification(void);

#define EcucPartition_Main_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** API Mapping                                                                **
*******************************************************************************/
#ifndef Rte_Call_R_IoHwAbGptLogical_IoHwAbTest_Cbk_Notification
#define Rte_Call_R_IoHwAbGptLogical_IoHwAbTest_Cbk_Notification Rte_Call_IoHwAb_R_IoHwAbGptLogical_IoHwAbTest_Cbk_Notification
#endif

#ifndef Rte_Call_R_VolMon_Cbk_Notification
#define Rte_Call_R_VolMon_Cbk_Notification Rte_Call_IoHwAb_R_VolMon_Cbk_Notification
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

#define IoHwAb_START_SEC_CODE
#include "IoHwAb_MemMap.h"
FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_AnaInDirReadDirect(IN VAR(IoHwAb_IndexType, AUTOMATIC) ChIdx, OUT P2VAR(IoHwAb_ValueType, AUTOMATIC, RTE_APPL_DATA) Value, IN VAR(IoHwAb_LengthType, AUTOMATIC) AnaInDirLength);

FUNC(void, IoHwAb_CODE) IoHwAb_AnaInFreeze(IN VAR(IoHwAb_IndexType, AUTOMATIC) ChIdx);

FUNC(void, IoHwAb_CODE) IoHwAb_AnaInRead(IN VAR(IoHwAb_IndexType, AUTOMATIC) ChIdx, OUT P2VAR(IoHwAb_ValueType, AUTOMATIC, RTE_APPL_DATA) Value);

FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_AnaInReadDirect(IN VAR(IoHwAb_IndexType, AUTOMATIC) ChIdx, OUT P2VAR(IoHwAb_ValueType, AUTOMATIC, RTE_APPL_DATA) Value);

FUNC(void, IoHwAb_CODE) IoHwAb_AnaInUnfreeze(IN VAR(IoHwAb_IndexType, AUTOMATIC) ChIdx);

FUNC(void, IoHwAb_CODE) IoHwAb_DigDirIsInput(IN VAR(IoHwAb_IndexType, AUTOMATIC) ChIdx, OUT P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_APPL_DATA) blResult);

FUNC(void, IoHwAb_CODE) IoHwAb_DigDirIsOutput(IN VAR(IoHwAb_IndexType, AUTOMATIC) ChIdx, OUT P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_APPL_DATA) blResult);

FUNC(void, IoHwAb_CODE) IoHwAb_DigDirReadDirect(IN VAR(IoHwAb_IndexType, AUTOMATIC) ChIdx, OUT P2VAR(IoHwAb_LevelType, AUTOMATIC, RTE_APPL_DATA) Level);

FUNC(void, IoHwAb_CODE) IoHwAb_DigDirSetToInput(IN VAR(IoHwAb_IndexType, AUTOMATIC) ChIdx);

FUNC(void, IoHwAb_CODE) IoHwAb_DigDirSetToOutput(IN VAR(IoHwAb_IndexType, AUTOMATIC) ChIdx);

FUNC(void, IoHwAb_CODE) IoHwAb_DigDirWriteDirect(IN VAR(IoHwAb_IndexType, AUTOMATIC) ChIdx, IN VAR(IoHwAb_LevelType, AUTOMATIC) Level);

FUNC(void, IoHwAb_CODE) IoHwAb_DigInFreeze(IN VAR(IoHwAb_IndexType, AUTOMATIC) ChIdx);

FUNC(void, IoHwAb_CODE) IoHwAb_DigInIsFrozen(IN VAR(IoHwAb_IndexType, AUTOMATIC) ChIdx, OUT P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_APPL_DATA) DigInResult);

FUNC(void, IoHwAb_CODE) IoHwAb_DigInRead(IN VAR(IoHwAb_IndexType, AUTOMATIC) ChIdx, OUT P2VAR(IoHwAb_LevelType, AUTOMATIC, RTE_APPL_DATA) Level);

FUNC(void, IoHwAb_CODE) IoHwAb_DigInReadDirect(IN VAR(IoHwAb_IndexType, AUTOMATIC) ChIdx, OUT P2VAR(IoHwAb_LevelType, AUTOMATIC, RTE_APPL_DATA) Level);

FUNC(void, IoHwAb_CODE) IoHwAb_DigInReadRaw(IN VAR(IoHwAb_IndexType, AUTOMATIC) ChIdx, OUT P2VAR(IoHwAb_LevelType, AUTOMATIC, RTE_APPL_DATA) Level);

FUNC(void, IoHwAb_CODE) IoHwAb_DigInUnfreeze(IN VAR(IoHwAb_IndexType, AUTOMATIC) ChIdx);

FUNC(void, IoHwAb_CODE) IoHwAb_DigInWrite(IN VAR(IoHwAb_IndexType, AUTOMATIC) ChIdx, IN VAR(IoHwAb_LevelType, AUTOMATIC) Level);

FUNC(void, IoHwAb_CODE) IoHwAb_DigOutRead(IN VAR(IoHwAb_IndexType, AUTOMATIC) ChIdx, OUT P2VAR(IoHwAb_LevelType, AUTOMATIC, RTE_APPL_DATA) Level);

FUNC(void, IoHwAb_CODE) IoHwAb_DigOutReadDirect(IN VAR(IoHwAb_IndexType, AUTOMATIC) ChIdx, OUT P2VAR(IoHwAb_LevelType, AUTOMATIC, RTE_APPL_DATA) Level);

FUNC(void, IoHwAb_CODE) IoHwAb_DigOutWrite(IN VAR(IoHwAb_IndexType, AUTOMATIC) ChIdx, IN VAR(IoHwAb_LevelType, AUTOMATIC) Level);

FUNC(void, IoHwAb_CODE) IoHwAb_DigOutWriteDirect(IN VAR(IoHwAb_IndexType, AUTOMATIC) ChIdx, IN VAR(IoHwAb_LevelType, AUTOMATIC) Level);

FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_GptDisableNotification(IN VAR(IoHwAb_IndexType, AUTOMATIC) ChIdx);

FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_GptEnableNotification(IN VAR(IoHwAb_IndexType, AUTOMATIC) ChIdx);

FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_GptGetTimeElapsed(IN VAR(IoHwAb_IndexType, AUTOMATIC) ChIdx, OUT P2VAR(IoHwAb_GptValueType, AUTOMATIC, RTE_APPL_DATA) Value);

FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_GptGetTimeRemaining(IN VAR(IoHwAb_IndexType, AUTOMATIC) ChIdx, OUT P2VAR(IoHwAb_GptValueType, AUTOMATIC, RTE_APPL_DATA) Value);

FUNC(void, IoHwAb_CODE) Gpt_Notification(void);

FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_GptStartTimer(IN VAR(IoHwAb_IndexType, AUTOMATIC) ChIdx, IN VAR(IoHwAb_GptValueType, AUTOMATIC) Value);

FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_GptStopTimer(IN VAR(IoHwAb_IndexType, AUTOMATIC) ChIdx);

FUNC(void, IoHwAb_CODE) IoHwAb_VolMonGetStatus(OUT P2VAR(IoHwAb_StatusType, AUTOMATIC, RTE_APPL_DATA) VolMonStatus);

FUNC(void, IoHwAb_CODE) IoHwAb_VolMonIsThresholdOver(IN VAR(IoHwAb_ThresholdType, AUTOMATIC) Threshold, OUT P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_APPL_DATA) VolMonResult);

FUNC(void, IoHwAb_CODE) IoHwAb_VolMonIsThresholdUnder(IN VAR(IoHwAb_ThresholdType, AUTOMATIC) Threshold, OUT P2VAR(IoHwAb_BoolType, AUTOMATIC, RTE_APPL_DATA) VolMonResult);

FUNC(void, IoHwAb_CODE) IoHwAb_VolMonNotification(void);

FUNC(void, IoHwAb_CODE) IoHwAb_VolMonRead(OUT P2VAR(IoHwAb_ValueType, AUTOMATIC, RTE_APPL_DATA) Value);

#define IoHwAb_STOP_SEC_CODE
#include "IoHwAb_MemMap.h"

/*
  polyspace:end<MISRA-C:8.8:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte SWS #1132)
*/

/*******************************************************************************
** Runnables Mapping                                                          **
*******************************************************************************/
#ifndef RTE_RUNNABLE_IoHwAb_Re_AnaInDir_ReadDirect
#define RTE_RUNNABLE_IoHwAb_Re_AnaInDir_ReadDirect IoHwAb_AnaInDirReadDirect
#endif
#ifndef RTE_RUNNABLE_IoHwAb_Re_AnaIn_Freeze
#define RTE_RUNNABLE_IoHwAb_Re_AnaIn_Freeze IoHwAb_AnaInFreeze
#endif
#ifndef RTE_RUNNABLE_IoHwAb_Re_AnaIn_Read
#define RTE_RUNNABLE_IoHwAb_Re_AnaIn_Read IoHwAb_AnaInRead
#endif
#ifndef RTE_RUNNABLE_IoHwAb_Re_AnaIn_ReadDirect
#define RTE_RUNNABLE_IoHwAb_Re_AnaIn_ReadDirect IoHwAb_AnaInReadDirect
#endif
#ifndef RTE_RUNNABLE_IoHwAb_Re_AnaIn_Unfreeze
#define RTE_RUNNABLE_IoHwAb_Re_AnaIn_Unfreeze IoHwAb_AnaInUnfreeze
#endif
#ifndef RTE_RUNNABLE_IoHwAb_Re_DigDir_IsInput
#define RTE_RUNNABLE_IoHwAb_Re_DigDir_IsInput IoHwAb_DigDirIsInput
#endif
#ifndef RTE_RUNNABLE_IoHwAb_Re_DigDir_IsOutput
#define RTE_RUNNABLE_IoHwAb_Re_DigDir_IsOutput IoHwAb_DigDirIsOutput
#endif
#ifndef RTE_RUNNABLE_IoHwAb_Re_DigDir_ReadDirect
#define RTE_RUNNABLE_IoHwAb_Re_DigDir_ReadDirect IoHwAb_DigDirReadDirect
#endif
#ifndef RTE_RUNNABLE_IoHwAb_Re_DigDir_SetToInput
#define RTE_RUNNABLE_IoHwAb_Re_DigDir_SetToInput IoHwAb_DigDirSetToInput
#endif
#ifndef RTE_RUNNABLE_IoHwAb_Re_DigDir_SetToOutput
#define RTE_RUNNABLE_IoHwAb_Re_DigDir_SetToOutput IoHwAb_DigDirSetToOutput
#endif
#ifndef RTE_RUNNABLE_IoHwAb_Re_DigDir_WriteDirect
#define RTE_RUNNABLE_IoHwAb_Re_DigDir_WriteDirect IoHwAb_DigDirWriteDirect
#endif
#ifndef RTE_RUNNABLE_IoHwAb_Re_DigIn_Freeze
#define RTE_RUNNABLE_IoHwAb_Re_DigIn_Freeze IoHwAb_DigInFreeze
#endif
#ifndef RTE_RUNNABLE_IoHwAb_Re_DigIn_IsFrozen
#define RTE_RUNNABLE_IoHwAb_Re_DigIn_IsFrozen IoHwAb_DigInIsFrozen
#endif
#ifndef RTE_RUNNABLE_IoHwAb_Re_DigIn_Read
#define RTE_RUNNABLE_IoHwAb_Re_DigIn_Read IoHwAb_DigInRead
#endif
#ifndef RTE_RUNNABLE_IoHwAb_Re_DigIn_ReadDirect
#define RTE_RUNNABLE_IoHwAb_Re_DigIn_ReadDirect IoHwAb_DigInReadDirect
#endif
#ifndef RTE_RUNNABLE_IoHwAb_Re_DigIn_ReadRaw
#define RTE_RUNNABLE_IoHwAb_Re_DigIn_ReadRaw IoHwAb_DigInReadRaw
#endif
#ifndef RTE_RUNNABLE_IoHwAb_Re_DigIn_Unfreeze
#define RTE_RUNNABLE_IoHwAb_Re_DigIn_Unfreeze IoHwAb_DigInUnfreeze
#endif
#ifndef RTE_RUNNABLE_IoHwAb_Re_DigIn_Write
#define RTE_RUNNABLE_IoHwAb_Re_DigIn_Write IoHwAb_DigInWrite
#endif
#ifndef RTE_RUNNABLE_IoHwAb_Re_DigOut_Read
#define RTE_RUNNABLE_IoHwAb_Re_DigOut_Read IoHwAb_DigOutRead
#endif
#ifndef RTE_RUNNABLE_IoHwAb_Re_DigOut_ReadDirect
#define RTE_RUNNABLE_IoHwAb_Re_DigOut_ReadDirect IoHwAb_DigOutReadDirect
#endif
#ifndef RTE_RUNNABLE_IoHwAb_Re_DigOut_Write
#define RTE_RUNNABLE_IoHwAb_Re_DigOut_Write IoHwAb_DigOutWrite
#endif
#ifndef RTE_RUNNABLE_IoHwAb_Re_DigOut_WriteDirect
#define RTE_RUNNABLE_IoHwAb_Re_DigOut_WriteDirect IoHwAb_DigOutWriteDirect
#endif
#ifndef RTE_RUNNABLE_IoHwAb_Re_Gpt_DisableNotification
#define RTE_RUNNABLE_IoHwAb_Re_Gpt_DisableNotification IoHwAb_GptDisableNotification
#endif
#ifndef RTE_RUNNABLE_IoHwAb_Re_Gpt_EnableNotification
#define RTE_RUNNABLE_IoHwAb_Re_Gpt_EnableNotification IoHwAb_GptEnableNotification
#endif
#ifndef RTE_RUNNABLE_IoHwAb_Re_Gpt_GetTimeElapsed
#define RTE_RUNNABLE_IoHwAb_Re_Gpt_GetTimeElapsed IoHwAb_GptGetTimeElapsed
#endif
#ifndef RTE_RUNNABLE_IoHwAb_Re_Gpt_GetTimeRemaining
#define RTE_RUNNABLE_IoHwAb_Re_Gpt_GetTimeRemaining IoHwAb_GptGetTimeRemaining
#endif
#ifndef RTE_RUNNABLE_IoHwAb_Re_Gpt_Gpt_Notification_Cbk
#define RTE_RUNNABLE_IoHwAb_Re_Gpt_Gpt_Notification_Cbk Gpt_Notification
#endif
#ifndef RTE_RUNNABLE_IoHwAb_Re_Gpt_StartTimer
#define RTE_RUNNABLE_IoHwAb_Re_Gpt_StartTimer IoHwAb_GptStartTimer
#endif
#ifndef RTE_RUNNABLE_IoHwAb_Re_Gpt_StopTimer
#define RTE_RUNNABLE_IoHwAb_Re_Gpt_StopTimer IoHwAb_GptStopTimer
#endif
#ifndef RTE_RUNNABLE_IoHwAb_Re_VolMon_GetStatus
#define RTE_RUNNABLE_IoHwAb_Re_VolMon_GetStatus IoHwAb_VolMonGetStatus
#endif
#ifndef RTE_RUNNABLE_IoHwAb_Re_VolMon_IsThresholdOver
#define RTE_RUNNABLE_IoHwAb_Re_VolMon_IsThresholdOver IoHwAb_VolMonIsThresholdOver
#endif
#ifndef RTE_RUNNABLE_IoHwAb_Re_VolMon_IsThresholdUnder
#define RTE_RUNNABLE_IoHwAb_Re_VolMon_IsThresholdUnder IoHwAb_VolMonIsThresholdUnder
#endif
#ifndef RTE_RUNNABLE_IoHwAb_Re_VolMon_Notification
#define RTE_RUNNABLE_IoHwAb_Re_VolMon_Notification IoHwAb_VolMonNotification
#endif
#ifndef RTE_RUNNABLE_IoHwAb_Re_VolMon_Read
#define RTE_RUNNABLE_IoHwAb_Re_VolMon_Read IoHwAb_VolMonRead
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

