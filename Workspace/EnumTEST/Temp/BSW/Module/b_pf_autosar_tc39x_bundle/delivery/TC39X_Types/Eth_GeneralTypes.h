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
**  FILENAME     : Eth_GeneralTypes.h                                         **
**                                                                            **
**  VERSION      : 5.0.0                                                      **
**                                                                            **
**  DATE         : 2019-06-14                                                 **
**                                                                            **
**  VARIANT      : Variant PB                                                 **
**                                                                            **
**  PLATFORM     : Infineon AURIX2G                                           **
**                                                                            **
**  AUTHOR       : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**  VENDOR       : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : Type Definition for ETH module                             **
**                                                                            **
**  SPECIFICATION(S) : AUTOSAR_SWS_EthernetDriver.pdf, AUTOSAR Release 4.2.2  **
**                                                                            **
**  MAY BE CHANGED BY USER : Yes                                              **
**                                                                            **
*******************************************************************************/
/* [cover parentID={02E963B3-0809-4549-A097-7621EFA30E8E}]
[/cover] */
#ifndef ETH_GENERALTYPES_H
#define ETH_GENERALTYPES_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Include Communication Stack Types */
#include "ComStack_Types.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* [cover parentID={E5F983BE-07BC-491a-88EC-2769CF667C1D}] */
typedef uint16 Eth_FrameType;

/* [cover parentID={BD6101D5-1685-4c46-BB5D-40A2C68F6E12}] */
typedef uint8 Eth_DataType;

/* [cover parentID={9B3DB455-B3B5-47c1-938F-DB195AED1CF8}] */
typedef enum
{
  ETH_MODE_DOWN   = 0x0U,
  ETH_MODE_ACTIVE = 0x1U
}Eth_ModeType;

/* [cover parentID={06E8EA99-99C0-447c-BAB8-CEA3043FB649}] */
typedef enum
{
  ETH_STATE_UNINIT   = 0x0U,
  ETH_STATE_INIT     = 0x1U
}Eth_StateType;
/*[/cover] */


/* Added for compatibility with AS4.1 */
/* [cover parentID={BDAFE9DD-1BE4-4a80-8155-304968BD7C19}] */
typedef enum
{
  ETH_RECEIVED = 0x0U,
  ETH_NOT_RECEIVED,
  ETH_RECEIVED_MORE_DATA_AVAILABLE
} Eth_RxStatusType;
/* [cover parentID={EBEF3D7C-B522-4bab-9C9C-49DD0A07DA4F}] */
typedef enum
{
  ETH_ADD_TO_FILTER = 0x0U,
  ETH_REMOVE_FROM_FILTER
} Eth_FilterActionType;

/* [cover parentID={31610027-C922-48ba-A512-90E0F5996F6F}] */
typedef enum
{
  ETH_OK=0x0U,
  ETH_E_NOT_OK,
  ETH_E_NO_ACCESS
}Eth_ReturnType;
/*[/cover] */

/* [cover parentID={06942102-DFC0-443c-944A-4794B2962603}] */
typedef enum
{
  ETH_VALID = 0x0U,
  ETH_INVALID,
  ETH_UNCERTAIN
}Eth_TimeStampQualType;
/* [cover parentID={F8A4A4C4-F873-4d21-A834-B1716374B502}] */
typedef struct
{
  uint32 nanoseconds;
  uint32 seconds;
  uint16 secondsHi;
}Eth_TimeStampType;
/* [cover parentID={6FC1C2B8-4DC8-4acf-973D-81544DF0582F}] */
typedef struct
{
  Eth_TimeStampType diff;
  boolean sign;
}Eth_TimeIntDiffType;

/* [cover parentID={E6EDFDCC-2FB2-495d-824D-A47DE34AAC19}] */
typedef struct
{
  Eth_TimeIntDiffType IngressTimeStampDelta ;
  Eth_TimeIntDiffType OriginTimeStampDelta ;
}Eth_RateRatioType;

/* [cover parentID={137DCFF3-A8F0-4a14-99D6-A83E7975A0EA}] */
typedef uint32 Eth_BufIdxType;

/* Changed by AUTRON -----------------------------------------------------------------------------*/
/*
* SWS_EthTrcv_00099:
* EthTrcv_ModeType DataType: This type defines the transceiver modes.
* EthTrcv_ModeType DataType shall be of enumeration type.,
* The range for datatype EthTrcv_ModeType is:
* 1. ETHTRCV_MODE_DOWN: Value 0x00 represents Transceiver disabled.
* 2. ETHTRCV_MODE_ACTIVE: Value 0x01 represents Transceiver enabled.
*/
typedef enum ETag_EthTrcv_ModeType
{
  ETHTRCV_MODE_DOWN,
  ETHTRCV_MODE_ACTIVE
} EthTrcv_ModeType;

/*
* SWS_EthTrcv_00100:
* EthTrcv_LinkStateType DataType: This type defines the Ethernet link state. The
*       link state changes after an Ethernet cable gets plugged in and transceivers
*       on both ends negotiated the transmission parameters (i.e. baud rate and duplex
*       mode).
* EthTrcv_LinkStateType DataType shall be of enumeration type.
* The range for datatype EthTrcv_LinkStateType is:
* 1. ETHTRCV_LINK_STATE_DOWN: Value 0x00 represents 0x00: No physical Ethernet
* connection established.
* 2. ETHTRCV_LINK_STATE_ACTIVE: Value 0x01 represents physical Ethernet
* connection established.
*/
typedef enum ETag_EthTrcv_LinkStateType
{
  ETHTRCV_LINK_STATE_DOWN,
  ETHTRCV_LINK_STATE_ACTIVE
} EthTrcv_LinkStateType;
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
/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

/*******************************************************************************
**                            LOW Level Driver Definitions                    **
*******************************************************************************/

/*******************************************************************************
**                            LOW Level Driver Definitions                    **
*******************************************************************************/


#endif /* ETH_GENERALTYPES_H */

