/*******************************************************************************
**  FILE-NAME : EcuM_Generated_Types.h                                        **
**                                                                            **
**  PRODUCT   : AUTOSAR EcuM Module                                           **
**                                                                            **
**  NOTE: This file is auto generated, do not edit this file manually.        **
**                                                                            **
********************************************************************************

********************************************************************************
**                      Generation Tool Information                           **
********************************************************************************
**  Tool Version: 3.0.0                                                       **
**                                                                            **
**  Change History: Refer log file (use -l option to generate log file)       **
**                                                                            **
********************************************************************************
**                      File Generation Information                           **
*******************************************************************************/

/*
 * INPUT FILE:    Configuration\Ecu\Ecud_CanSM.arxml
 *                Configuration\Ecu\Ecud_Det.arxml
 *                Configuration\Ecu\Mcal\Ecud_Gpt.arxml
 *                Configuration\Ecu\Ecud_PduR.arxml
 *                Configuration\Ecu\Ecud_EcuC.arxml
 *                Configuration\Ecu\Ecud_Xcp.arxml
 *                Configuration\Ecu\Mcal\Ecud_Can.arxml
 *                Configuration\Ecu\Mcal\Ecud_Dio.arxml
 *                Configuration\Ecu\Ecud_Dcm.arxml
 *                Configuration\Ecu\Ecud_Dem.arxml
 *                Configuration\Ecu\Ecud_CanIf.arxml
 *                Configuration\Ecu\Mcal\Ecud_Mcu.arxml
 *                Configuration\Ecu\Ecud_ComM.arxml
 *                Configuration\Ecu\Ecud_CanTp.arxml
 *                Configuration\Ecu\Mcal\Ecud_Adc.arxml
 *                Configuration\Ecu\Mcal\Ecud_Port.arxml
 *                Configuration\Ecu\Ecud_EcuM.arxml
 *                Configuration\Ecu\Ecud_CanCM.arxml
 *                Configuration\Ecu\Ecud_CanTrcv_255_Autron.arxml
 *                Configuration\Ecu\Ecud_WdgM.arxml
 *                Configuration\Ecu\Mcal\Ecud_Wdg.arxml
 *                Configuration\Ecu\Mcal\Ecud_Pwm.arxml
 *                Configuration\Ecu\Ecud_IoHwAb.arxml
 *                Configuration\Ecu\Ecud_Os.arxml
 *                Configuration\Ecu\Mcal\Ecud_Icu.arxml
 *                Configuration\Ecu\Ecud_Csm.arxml
 *                Configuration\Ecu\Ecud_Com.arxml
 *                Configuration\Ecu\Ecud_T1Ad.arxml
 *                Configuration\Ecu\Mcal\Ecud_Spi.arxml
 * GENERATED ON: The time-stamp is removed
 */

#ifndef ECUM_GENERATED_TYPES_H
#define ECUM_GENERATED_TYPES_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* polyspace<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */
#include "Std_Types.h"
/* polyspace<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */
#include "EcuM_Cfg.h"
/* polyspace<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */
#include "Rte_EcuM_Type.h"

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
typedef struct STag_EcuM_ConfigType
{
  /* EcuMConfigConsistencyHash value */
  P2CONST (uint32, ECUM_CONST, ECUM_CONST) pEcuMConfigConsistencyHash;

  /* EcuMDefaultState */
  EcuM_StateType ddEcuMDefaultState;

  /* EcuMDefaultResetModeRef reference to EcuMResetMode */
  uint8 ucEcuMDefaultResetMode;

  /* EcuMDefaultSleepModeRef reference to EcuMSleepMode */
  uint8 ucEcuMDefaultSleepMode;

  /* ucLcfgHashArrayIndex */
  uint8 ucLcfgHashArrayIndex;
  
  
  /* Pointer to BswM config structure  */
  P2CONST (void, AUTOMATIC, ECUM_CONST) pBswMConfig;

}EcuM_ConfigType;

#define ECUM_START_SEC_CONST_UNSPECIFIED
/* polyspace<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */
#include "MemMap.h"
/* Structure for Config set */

/* polyspace<MISRA-C:8.12:Not a defect:Justify with annotations> size of array is determined by configuration */
extern CONST(EcuM_ConfigType, ECUM_CONST) EcuM_GaaConfig[];
#define ECUM_STOP_SEC_CONST_UNSPECIFIED
/* polyspace<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */
#include "MemMap.h"

#define ECUM_START_SEC_CONST_32
/* polyspace<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */
#include "MemMap.h"
/* Structure for Hash value */
/* polyspace<MISRA-C:8.12:Not a defect:Justify with annotations> size of array is determined by configuration */
extern CONST(uint32, ECUM_CONST) EcuM_GaaPBcfgHashValue[];

/* polyspace<MISRA-C:8.12:Not a defect:Justify with annotations> size of array is determined by configuration */
extern CONST(uint32, ECUM_CONST) EcuM_GaaLcfgHashValue[];
#define ECUM_STOP_SEC_CONST_32
/* polyspace<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */
#include "MemMap.h"
/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#endif /* ECUM_GENERATED_TYPES_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
