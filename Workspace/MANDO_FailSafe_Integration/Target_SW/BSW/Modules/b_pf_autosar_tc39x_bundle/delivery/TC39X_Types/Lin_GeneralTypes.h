/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2018)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME     : Lin_GeneralTypes.h                                         **
**                                                                            **
**  VERSION      : 3.0.0                                                      **
**                                                                            **
**  DATE         : 2018-07-24                                                 **
**                                                                            **
**  VARIANT      : Variant PB                                                 **
**                                                                            **
**  PLATFORM     : Infineon AURIX2G                                           **
**                                                                            **
**  AUTHOR       : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**  VENDOR       : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : This file exports Lin interface Type defnitions            **
**                                                                            **
**  SPECIFICATION(S) : Specification of Lin Driver, AUTOSAR Release 4.2.2     **
**                                                                            **
**  MAY BE CHANGED BY USER : Yes                                              **
**                                                                            **
*******************************************************************************/

#ifndef LIN_GENERALTYPES_H
#define LIN_GENERALTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
/*
Type : Lin_FramePidType  
Represents all valid protected Identifier used by Lin_SendFrame().  
*/
typedef uint8 Lin_FramePidType;

/*
Type : Lin_FrameCsModelType  
This type is used to specify the Checksum model to be used for the LIN Frame   
*/
typedef enum 
{
  LIN_ENHANCED_CS = 0, 
  LIN_CLASSIC_CS
}Lin_FrameCsModelType;

/*
Type : Lin_FrameResponseType  
This type is used to specify whether the frame processor is required to 
transmit the response part of the LIN frame   
*/
typedef enum 
{
  LIN_MASTER_RESPONSE = 0,
  LIN_SLAVE_RESPONSE,
  LIN_SLAVE_TO_SLAVE
}Lin_FrameResponseType;



/*
Type : Lin_FrameDlType   
This type is used to specify the number of SDU data bytes to copy    
*/
typedef uint8 Lin_FrameDlType;

/*
Type : Lin_PduType   
This Type is used to provide PID, checksum model, data length and SDU pointer 
from the LIN Interface to the LIN driver     
*/
typedef struct 
{
  Lin_FramePidType         Pid; 
  Lin_FrameCsModelType     Cs;         
  Lin_FrameResponseType    Drc;        
  Lin_FrameDlType          Dl;    
  uint8                    *SduPtr;
}Lin_PduType;

/*
Type : Lin_StatusType   
LIN operation states for a LIN channel or frame, as returned by the API 
service Lin_17_GetStatus().      
*/
typedef enum
{
  LIN_NOT_OK = 0,
  LIN_TX_OK,
  LIN_TX_BUSY,
  LIN_TX_HEADER_ERROR,
  LIN_TX_ERROR,
  LIN_RX_OK,
  LIN_RX_BUSY,
  LIN_RX_ERROR,
  LIN_RX_NO_RESPONSE,
  LIN_OPERATIONAL,
  LIN_CH_SLEEP,
}Lin_StatusType;

/* Changed by AUTRON -----------------------------------------------------------------------------*/
typedef enum
    {
         LINTRCV_TRCV_MODE_NORMAL, /** < @brief Transceiver mode NORMAL. */
         LINTRCV_TRCV_MODE_SLEEP,  /** < @brief Transceiver mode STANDBY. */
         LINTRCV_TRCV_MODE_STANDBY /** < @brief Transceiver mode SLEEP. */
    } LinTrcv_TrcvModeType;

typedef enum
    {
         LINTRCV_WU_ERROR,           /** < @brief Due to an error wake up reason was not detected.
                                                  This value may only be reported when error was reported
                                                  to DEM before.*/
         LINTRCV_WU_NOT_SUPPORTED,   /** < @brief The transceiver does not support any
                                                  information for the wake up reason.*/
         LINTRCV_WU_BY_BUS,          /** < @brief The transceiver has detected, that the network
                                                  has caused the wake up of the ECU.*/
         LINTRCV_WU_BY_PIN,          /** < @brief The transceiver has detected a wake-up event at
                                                  one of the transceiver's pins (not at the LIN bus).*/
         LINTRCV_WU_INTERNALLY,      /** < @brief The transceiver has detected, that the network
                                                  has been woken up by the ECU via a request to NORMAL mode.*/
         LINTRCV_WU_RESET,           /** < @brief The transceiver has detected, that the wake up
                                                  is due to an ECU reset. */
         LINTRCV_WU_POWER_ON         /** < @brief The transceiver has detected, that the wake up
                                                  is due to an ECU reset after power on.*/
    } LinTrcv_TrcvWakeupReasonType;

typedef enum
    {
         LINTRCV_WUMODE_ENABLE, /** < @brief The notification for wakeup events is enabled
                                             on the addressed network. */
         LINTRCV_WUMODE_DISABLE,/** < @brief The notification for wakeup events is disabled
                                             on the addressed network. */
         LINTRCV_WUMODE_CLEAR   /** < @brief A stored wakeup event is cleared on the
                                             addressed network. */
    } LinTrcv_TrcvWakeupModeType;
/*------------------------------------------------------------------------------------------------*/

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

#endif   /*  LIN_GENERALTYPES_H  */

