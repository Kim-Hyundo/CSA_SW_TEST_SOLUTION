
/*******************************************************************************
**  FILE-NAME: SchM_Adc.h                                                     **
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

/******************************************************************************/

/*******************************************************************************
* PRE-JUSTIFICATION BEGINE SECTION (MISRA-C RULE CHECKER)
* These rules will not be applied for verification based on the MISRA Rule
* in Rte generated source
*******************************************************************************/

/*
    polyspace:begin<MISRA-C:5.1:Not a defect:Justify with annotations> Number of character is depends on user configuration
*/

/*******************************************************************************
**                         Input File                                         **
*******************************************************************************/

/*******************************************************************************
**                         MULTIPLE INCLUSION PROTECTION                      **
*******************************************************************************/
#ifndef SCHM_ADC_H
#define SCHM_ADC_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Inclusion of Header Files) */
#include "SchM_Adc_Type.h"

#include "Rte.h"
/* polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Inclusion of Header Files) */

/*******************************************************************************
** Version Information                                                        **
*******************************************************************************/
/* AUTOSAR SPECIFICATION VERSION INFORMATION */

#define SCHM_Adc_AR_RELEASE_MAJOR_VERSION	4
#define SCHM_Adc_AR_RELEASE_MINOR_VERSION	0
#define SCHM_Adc_AR_REVISION_VERSION			2

/* SOFTWARE VERSION INFORMATION */

#define SCHM_Adc_SW_MAJOR_VERSION	4
#define SCHM_Adc_SW_MINOR_VERSION	0

/* RTE MODULE VERSION INFORMATION */

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

/* COMPATIBLE WITH C and C++ languages */
#ifdef __cplusplus
 extern "C" {
 #endif /* __cplusplus */

/*******************************************************************************
** RTE #DEFINES USED FOR INITIALISATION OF GLOBAL VARIABLES                   **
*******************************************************************************/

/*******************************************************************************
** Global Variables                                                           **
*******************************************************************************/

/*******************************************************************************
** Macros for Exclusive Areas                                                 **
*******************************************************************************/

/*******************************************************************************
** Prototypes for BswSchedulable entities                                     **
*******************************************************************************/

/*******************************************************************************
** Prototypes for BSW API                                                     **
*******************************************************************************/
#define EcucPartition_Main_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, RTE_CODE) SchM_Enter_Adc_KernelData(void);

extern FUNC(void, RTE_CODE) SchM_Exit_Adc_KernelData(void);

extern FUNC(void, RTE_CODE) SchM_Enter_Adc_SrcRegAccess(void);

extern FUNC(void, RTE_CODE) SchM_Exit_Adc_SrcRegAccess(void);

#define EcucPartition_Main_STOP_SEC_CODE
#include "MemMap.h"

/* COMPATIBLE WITH C and C++ languages */

 #ifdef __cplusplus
 } /* extern "C" */
 #endif /* __cplusplus */
#endif

/*******************************************************************************
* PRE-JUSTIFICATION END SECTION (MISRA-C RULE CHECKER)
*******************************************************************************/
/*
    polyspace:end<MISRA-C:5.1:Not a defect:Justify with annotations> Number of character is depends on user configuration
*/

/*******************************************************************************
**                          END OF FILE                                       **
*******************************************************************************/
