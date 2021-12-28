/*******************************************************************************
**  FILE-NAME: PduR_Com.h                                                     **
**                                                                            **
**  MODULE-NAME: AUTOSAR Pdu Router Module                                    **
**                                                                            **
**  NOTE: This file is auto generated, do not edit this file manually.        **
**                                                                            **
********************************************************************************

********************************************************************************
**                      Generation Tool Information                           **
********************************************************************************
**  Tool Version: 2.4.0                                                       **
**                                                                            **
**  Change History: Refer log file (use -l option to generate log file)       **
**                                                                            **
********************************************************************************
**                      File Generation Information                           **
*******************************************************************************/

/*
 * INPUT FILE(s):    Configuration\Ecu\Ecud_CanIf.arxml
 *                Configuration\Ecu\Ecud_PduR.arxml
 *                Configuration\Ecu\Ecud_Com.arxml
 *                Configuration\Ecu\Ecud_Dcm.arxml
 *                Configuration\Ecu\Ecud_CanTp.arxml
 *                Configuration\Ecu\Ecud_EcuC.arxml
 * GENERATED ON: The time-stamp is removed
 */

#ifndef PDUR_COM_H
#define PDUR_COM_H


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "PduR.h"
#include "PduR_TxUp.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/


/*******************************************************************************
**                      Common Published Information                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define PDUR_START_SEC_CODE
#include "MemMap.h"

/* Extern Declaration for PduR_ComTransmit() API */

extern FUNC(Std_ReturnType, PDUR_CODE) PduR_ComTransmit(PduIdType TxPduId,
P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr);

#define PDUR_STOP_SEC_CODE
#include "MemMap.h"
#endif /* PDUR_COM_H*/


/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

