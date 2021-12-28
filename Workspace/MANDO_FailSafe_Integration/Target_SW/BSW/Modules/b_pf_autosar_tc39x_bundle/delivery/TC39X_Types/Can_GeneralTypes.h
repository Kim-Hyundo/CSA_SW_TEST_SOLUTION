/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2019)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME     : Can_GeneralTypes.h                                         **
**                                                                            **
**  VERSION      : 5.0.0                                                      **
**                                                                            **
**  DATE         : 2019-05-31                                                 **
**                                                                            **
**  VARIANT      : Variant PB                                                 **
**                                                                            **
**  PLATFORM     : Infineon AURIX2G                                           **
**                                                                            **
**  AUTHOR       : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**  VENDOR       : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : Type Definition for CAN module                             **
**                                                                            **
**  SPECIFICATION(S) : AUTOSAR_SWS_CANDriver.pdf, AUTOSAR Release 4.2.2       **
**                                                                            **
**  MAY BE CHANGED BY USER : Yes                                              **
**                                                                            **
*******************************************************************************/
/* [cover parentID={FC23F8DB-1357-4c6e-933C-8FCD57054CB4}]
[/cover] */
#ifndef CAN_GENERALTYPES_H
#define CAN_GENERALTYPES_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
/* CAN id Type Mixed is supported */
typedef uint32 Can_IdType;

/* Maximum of hardware objects in the CAN hardware unit is more than 256 */
/* [cover parentID={646642D9-0684-44a3-BCAA-BF397A3EAED4}]
[/cover] */
typedef uint16 Can_HwHandleType;

/* Hardware Object Handle Type */
/* [cover parentID={0730F7D7-885E-4209-98B8-DA01836215D3}]
[/cover] */
typedef struct
{
  Can_IdType CanId;       /* Standard/Extended CAN ID of CAN L-PDU */
  Can_HwHandleType Hoh;   /* ID of the corresponding Hardware Object */
  uint8 ControllerId;     /* ControllerId provided by CanIf */
} Can_HwType;

/* CAN protocol data unit type. Used to provide ID, DLC and SDU from
   CAN Interface to CAN driver */
 /* [cover parentID={29716CC9-D2A2-40ec-BAC2-7429FB4F2237}]
[/cover] */
typedef struct
{
  PduIdType swPduHandle;    /* SW Handle that will identify the request in
                               the confirmation callback function. */
  uint8 length;             /* DLC */
  Can_IdType id;            /* Identifier of L-PDU */
  uint8 *sdu;               /* Pointer to L-SDU */
} Can_PduType;

/* Types for return values of CAN Driver APIs */
/* [cover parentID={2073BA4C-6728-4782-92EA-BC45E9F4F8DA}]
[/cover] */
typedef enum
{
  CAN_OK,        /* success */
  CAN_NOT_OK,    /* error occurred or wakeup occurred during sleep transition */
  CAN_BUSY       /* transmit request could not be processed because no transmit 
                    object was available */
} Can_ReturnType;

/* CAN state transition data type */
/* [cover parentID={A959DCE9-C34D-454e-AFAE-6FC833B785B2}]
[/cover] */
typedef enum
{
  CAN_T_START,    /* CAN controller transition value to request state STARTED */
  CAN_T_STOP,     /* CAN controller transition value to request state STOPPED */
  CAN_T_SLEEP,    /* CAN controller transition value to request state SLEEP */
  CAN_T_WAKEUP    /* CAN controller transition value to request state STOPPED
                     from state SLEEP  */
} Can_StateTransitionType;

/* CAN Transceiver Network Mode data type */
/* [cover parentID={9734F24E-4772-4b90-8950-448B3129902C}]
[/cover] */
typedef enum
{
  CANTRCV_TRCVMODE_NORMAL,
  CANTRCV_TRCVMODE_SLEEP,
  CANTRCV_TRCVMODE_STANDBY
} CanTrcv_TrcvModeType;

/* CAN Transceiver Wakeup Mode data type */
/* [cover parentID={02E06BBA-41CD-4e00-AEF7-AB334DE71238}]
[/cover] */
typedef enum
{
  CANTRCV_WUMODE_ENABLE,
  CANTRCV_WUMODE_DISABLE,
  CANTRCV_WUMODE_CLEAR
} CanTrcv_TrcvWakeupModeType;

/* CAN Transceiver Wake up Reason type */
/* [cover parentID={4B37FDED-E197-4287-9509-E088948E57B6}]
[/cover] */
typedef enum
{
  CANTRCV_WU_ERROR,
  CANTRCV_WU_NOT_SUPPORTED,
  CANTRCV_WU_BY_BUS,
  CANTRCV_WU_INTERNALLY,
  CANTRCV_WU_RESET,
  CANTRCV_WU_POWER_ON,
  CANTRCV_WU_BY_PIN,
  CANTRCV_WU_BY_SYSERR
} CanTrcv_TrcvWakeupReasonType;
/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#endif /* #ifndef CAN_GENERALTYPES_H */

