
/*******************************************************************************
**  FILE-NAME: Rte_CtApUSM.h                                                     **
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
 #ifndef RTE_CTAPUSM_H
      #define RTE_CTAPUSM_H
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
#include "Rte_DataHandleType.h"
#include "Rte_CtApUSM_Type.h"

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
#define Rte_InitValue_PpSH_FaultReaction_DeSH_FaultReaction {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0}, {0, 0, 0, 0}, {0}, {0, 0}, {0}, {0, 0, 0, 0, 0}, {0, 0}, {0, 0, 0}, {0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0}, {0, 0, 0, 0}}
#define Rte_InitValue_PpUSM_to_ASW_DeUSM_to_ASW {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define Rte_InitValue_PpUSM_to_IDC_DeUSM_to_IDC {0, 0, 0, 0, 0, 0, 0}

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
struct Rte_CDS_CtApUSM
{

  /* Data Handles Section */
P2VAR(Rte_DE_MsgGr_E2E_ACANFD1_A_FR_RDR_Genrl_01_50ms, AUTOMATIC, RTE_DATA) RCtApUSM_10ms_PpA_FR_RDR_Genrl_01_50ms_DeA_FR_RDR_Genrl_01_50ms;
P2VAR(Rte_DE_MsgGr_E2E_ECANFD_CLU_02_100ms, AUTOMATIC, RTE_DATA) RCtApUSM_10ms_PpCLU_02_100ms_DeCLU_02_100ms;
P2VAR(Rte_DE_MsgGr_E2E_ECANFD_ESC_01_10ms, AUTOMATIC, RTE_DATA) RCtApUSM_10ms_PpESC_01_10ms_DeESC_01_10ms;
P2VAR(Rte_DE_MsgGr_ECANFD_HU_GW_PE_01, AUTOMATIC, RTE_DATA) RCtApUSM_10ms_PpHU_GW_PE_01_DeHU_GW_PE_01;
P2VAR(Rte_DE_MsgGr_ECANFD_HU_USM_E_01, AUTOMATIC, RTE_DATA) RCtApUSM_10ms_PpHU_USM_E_01_DeHU_USM_E_01;
P2VAR(Rte_DE_MsgGr_ECANFD_HU_USM_E_02, AUTOMATIC, RTE_DATA) RCtApUSM_10ms_PpHU_USM_E_02_DeHU_USM_E_02;
P2VAR(Rte_DE_MsgGr_ECANFD_HU_USM_E_04, AUTOMATIC, RTE_DATA) RCtApUSM_10ms_PpHU_USM_E_04_DeHU_USM_E_04;
P2VAR(Rte_DE_MsgGr_ECANFD_HU_USM_E_08, AUTOMATIC, RTE_DATA) RCtApUSM_10ms_PpHU_USM_E_08_DeHU_USM_E_08;
P2VAR(Rte_DE_MsgGr_E2E_ECANFD_ICSC_02_100ms, AUTOMATIC, RTE_DATA) RCtApUSM_10ms_PpICSC_02_100ms_DeICSC_02_100ms;
P2VAR(Rte_DE_Dt_RECORD_IDC, AUTOMATIC, RTE_DATA) RCtApUSM_10ms_PpIDC_DeIDC;
P2VAR(Rte_DE_Dt_RECORD_SH_FaultReaction, AUTOMATIC, RTE_DATA) RCtApUSM_10ms_PpSH_FaultReaction_DeSH_FaultReaction;
P2VAR(Rte_DE_MsgGr_E2E_ECANFD_SWRC_03_20ms, AUTOMATIC, RTE_DATA) RCtApUSM_10ms_PpSWRC_03_20ms_DeSWRC_03_20ms;
P2VAR(Rte_DE_MsgGr_E2E_ECANFD_TCU_01_10ms, AUTOMATIC, RTE_DATA) RCtApUSM_10ms_PpTCU_01_10ms_DeTCU_01_10ms;
P2VAR(Rte_DE_Dt_RECORD_USM_to_ASW, AUTOMATIC, RTE_DATA) RCtApUSM_10ms_PpUSM_to_ASW_DeUSM_to_ASW;
P2VAR(Rte_DE_Dt_RECORD_USM_to_IDC, AUTOMATIC, RTE_DATA) RCtApUSM_10ms_PpUSM_to_IDC_DeUSM_to_IDC;

  /* PerInstance Memory Handle section */

 /* Inter-runnable Variable Handles section */

 /* Calibration Parameter Handles Section */

 /* Exclusive-area Handles section */

  /* Port API section For all PDS */

 /* Inter Runnable Variable API section */

/*Inter Runnable Triggering API section*/

};

/*
  polyspace:end<MISRA-C:5.7:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte SWS #3724)
*/
/*******************************************************************************
** Component instance handles                                                 **
*******************************************************************************/
#define EcucPartition_Main_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern const struct Rte_CDS_CtApUSM Rte_Inst_CtApUSM;
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

/*******************************************************************************
** Prototypes for Rte API                                                     **
*******************************************************************************/
#define EcucPartition_Main_START_SEC_CODE
#include "MemMap.h"

#define EcucPartition_Main_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** API Mapping                                                                **
*******************************************************************************/

/*******************************************************************************
** Client Server Macro                                                        **
*******************************************************************************/

/*******************************************************************************
** Prototypes for Runnable entities                                           **
*******************************************************************************/
/*
  polyspace:begin<MISRA-C:8.8:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte SWS #1132)
*/

#define CtApUSM_START_SEC_CODE
#include "CtApUSM_MemMap.h"
FUNC(void, CtApUSM_CODE) RCtApUSM_10ms(void);

#define CtApUSM_STOP_SEC_CODE
#include "CtApUSM_MemMap.h"

/*
  polyspace:end<MISRA-C:8.8:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Rte SWS #1132)
*/

#ifndef Rte_IRead_RCtApUSM_10ms_PpIDC_DeIDC
#define Rte_IRead_RCtApUSM_10ms_PpIDC_DeIDC() \
( \
  &(Rte_Inst_CtApUSM).RCtApUSM_10ms_PpIDC_DeIDC->value \
)
#endif
#ifndef Rte_IRead_RCtApUSM_10ms_PpA_FR_RDR_Genrl_01_50ms_DeA_FR_RDR_Genrl_01_50ms
#define Rte_IRead_RCtApUSM_10ms_PpA_FR_RDR_Genrl_01_50ms_DeA_FR_RDR_Genrl_01_50ms() \
( \
  &(Rte_Inst_CtApUSM).RCtApUSM_10ms_PpA_FR_RDR_Genrl_01_50ms_DeA_FR_RDR_Genrl_01_50ms->value \
)
#endif
#ifndef Rte_IRead_RCtApUSM_10ms_PpCLU_02_100ms_DeCLU_02_100ms
#define Rte_IRead_RCtApUSM_10ms_PpCLU_02_100ms_DeCLU_02_100ms() \
( \
  &(Rte_Inst_CtApUSM).RCtApUSM_10ms_PpCLU_02_100ms_DeCLU_02_100ms->value \
)
#endif
#ifndef Rte_IRead_RCtApUSM_10ms_PpESC_01_10ms_DeESC_01_10ms
#define Rte_IRead_RCtApUSM_10ms_PpESC_01_10ms_DeESC_01_10ms() \
( \
  &(Rte_Inst_CtApUSM).RCtApUSM_10ms_PpESC_01_10ms_DeESC_01_10ms->value \
)
#endif
#ifndef Rte_IRead_RCtApUSM_10ms_PpHU_GW_PE_01_DeHU_GW_PE_01
#define Rte_IRead_RCtApUSM_10ms_PpHU_GW_PE_01_DeHU_GW_PE_01() \
( \
  &(Rte_Inst_CtApUSM).RCtApUSM_10ms_PpHU_GW_PE_01_DeHU_GW_PE_01->value \
)
#endif
#ifndef Rte_IRead_RCtApUSM_10ms_PpHU_USM_E_01_DeHU_USM_E_01
#define Rte_IRead_RCtApUSM_10ms_PpHU_USM_E_01_DeHU_USM_E_01() \
( \
  &(Rte_Inst_CtApUSM).RCtApUSM_10ms_PpHU_USM_E_01_DeHU_USM_E_01->value \
)
#endif
#ifndef Rte_IRead_RCtApUSM_10ms_PpHU_USM_E_02_DeHU_USM_E_02
#define Rte_IRead_RCtApUSM_10ms_PpHU_USM_E_02_DeHU_USM_E_02() \
( \
  &(Rte_Inst_CtApUSM).RCtApUSM_10ms_PpHU_USM_E_02_DeHU_USM_E_02->value \
)
#endif
#ifndef Rte_IRead_RCtApUSM_10ms_PpHU_USM_E_04_DeHU_USM_E_04
#define Rte_IRead_RCtApUSM_10ms_PpHU_USM_E_04_DeHU_USM_E_04() \
( \
  &(Rte_Inst_CtApUSM).RCtApUSM_10ms_PpHU_USM_E_04_DeHU_USM_E_04->value \
)
#endif
#ifndef Rte_IRead_RCtApUSM_10ms_PpHU_USM_E_08_DeHU_USM_E_08
#define Rte_IRead_RCtApUSM_10ms_PpHU_USM_E_08_DeHU_USM_E_08() \
( \
  &(Rte_Inst_CtApUSM).RCtApUSM_10ms_PpHU_USM_E_08_DeHU_USM_E_08->value \
)
#endif
#ifndef Rte_IRead_RCtApUSM_10ms_PpICSC_02_100ms_DeICSC_02_100ms
#define Rte_IRead_RCtApUSM_10ms_PpICSC_02_100ms_DeICSC_02_100ms() \
( \
  &(Rte_Inst_CtApUSM).RCtApUSM_10ms_PpICSC_02_100ms_DeICSC_02_100ms->value \
)
#endif
#ifndef Rte_IRead_RCtApUSM_10ms_PpSH_FaultReaction_DeSH_FaultReaction
#define Rte_IRead_RCtApUSM_10ms_PpSH_FaultReaction_DeSH_FaultReaction() \
( \
  &(Rte_Inst_CtApUSM).RCtApUSM_10ms_PpSH_FaultReaction_DeSH_FaultReaction->value \
)
#endif
#ifndef Rte_IRead_RCtApUSM_10ms_PpSWRC_03_20ms_DeSWRC_03_20ms
#define Rte_IRead_RCtApUSM_10ms_PpSWRC_03_20ms_DeSWRC_03_20ms() \
( \
  &(Rte_Inst_CtApUSM).RCtApUSM_10ms_PpSWRC_03_20ms_DeSWRC_03_20ms->value \
)
#endif
#ifndef Rte_IRead_RCtApUSM_10ms_PpTCU_01_10ms_DeTCU_01_10ms
#define Rte_IRead_RCtApUSM_10ms_PpTCU_01_10ms_DeTCU_01_10ms() \
( \
  &(Rte_Inst_CtApUSM).RCtApUSM_10ms_PpTCU_01_10ms_DeTCU_01_10ms->value \
)
#endif
#ifndef Rte_IWrite_RCtApUSM_10ms_PpUSM_to_ASW_DeUSM_to_ASW
#define Rte_IWrite_RCtApUSM_10ms_PpUSM_to_ASW_DeUSM_to_ASW(Val) \
( \
  (Rte_Inst_CtApUSM).RCtApUSM_10ms_PpUSM_to_ASW_DeUSM_to_ASW->isWritten = RTE_TRUE, \
  (void)Rte_Memcpy(&((Rte_Inst_CtApUSM).RCtApUSM_10ms_PpUSM_to_ASW_DeUSM_to_ASW->value), Val, sizeof(Dt_RECORD_USM_to_ASW)) \
)
#endif
#ifndef Rte_IWrite_RCtApUSM_10ms_PpUSM_to_IDC_DeUSM_to_IDC
#define Rte_IWrite_RCtApUSM_10ms_PpUSM_to_IDC_DeUSM_to_IDC(Val) \
( \
  (Rte_Inst_CtApUSM).RCtApUSM_10ms_PpUSM_to_IDC_DeUSM_to_IDC->isWritten = RTE_TRUE, \
  (void)Rte_Memcpy(&((Rte_Inst_CtApUSM).RCtApUSM_10ms_PpUSM_to_IDC_DeUSM_to_IDC->value), Val, sizeof(Dt_RECORD_USM_to_IDC)) \
)
#endif
#ifndef Rte_IWriteRef_RCtApUSM_10ms_PpUSM_to_ASW_DeUSM_to_ASW
#define Rte_IWriteRef_RCtApUSM_10ms_PpUSM_to_ASW_DeUSM_to_ASW() \
( \
  (Rte_Inst_CtApUSM).RCtApUSM_10ms_PpUSM_to_ASW_DeUSM_to_ASW->isWritten = RTE_TRUE, \
  &(Rte_Inst_CtApUSM).RCtApUSM_10ms_PpUSM_to_ASW_DeUSM_to_ASW->value \
)
#endif
#ifndef Rte_IWriteRef_RCtApUSM_10ms_PpUSM_to_IDC_DeUSM_to_IDC
#define Rte_IWriteRef_RCtApUSM_10ms_PpUSM_to_IDC_DeUSM_to_IDC() \
( \
  (Rte_Inst_CtApUSM).RCtApUSM_10ms_PpUSM_to_IDC_DeUSM_to_IDC->isWritten = RTE_TRUE, \
  &(Rte_Inst_CtApUSM).RCtApUSM_10ms_PpUSM_to_IDC_DeUSM_to_IDC->value \
)
#endif

/*******************************************************************************
** Runnables Mapping                                                          **
*******************************************************************************/
#ifndef RTE_RUNNABLE_RCtApUSM_10ms
#define RTE_RUNNABLE_RCtApUSM_10ms RCtApUSM_10ms
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

