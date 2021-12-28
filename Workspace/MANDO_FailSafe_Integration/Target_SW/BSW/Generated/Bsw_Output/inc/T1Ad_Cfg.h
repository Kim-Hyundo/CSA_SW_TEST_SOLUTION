/*******************************************************************************
**                                                                            **
**  (C) 2018 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: T1Ad_Cfg.h                                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : T1Ad Module                                                   **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
**  NOTE      : The provided static and generated codes of T1Ad Module        **
**              are used to apply the T1 function to the platform.            **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Generation Tool Information                           **
********************************************************************************
**  Tool Version: 1.1.0                                                       **
**                                                                            **
**  Change History: Refer log file (use -l option to generate log file)       **
**                                                                            **
********************************************************************************
**                      File Generation Information                           **
*******************************************************************************/

/*
 * INPUT FILE:    Configuration\Ecu\Ecud_CanIf.arxml
 *                Configuration\Ecu\Ecud_T1Ad.arxml
 *                Configuration\Ecu\Ecud_EcuC.arxml
 * GENERATED ON: The time-stamp is removed
 */

#ifndef T1AD_CFG_H
#define T1AD_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

#define T1AD_CFG_AR_RELEASE_MAJOR_VERSION                  4
#define T1AD_CFG_AR_RELEASE_MINOR_VERSION                  0
#define T1AD_CFG_AR_RELEASE_REVISION_VERSION               3
#define T1AD_CFG_SW_MAJOR_VERSION                          1
#define T1AD_CFG_SW_MINOR_VERSION                          1
#define T1AD_CFG_SW_PATCH_VERSION                          0

/*******************************************************************************
**                      Common Published Information                          **
*******************************************************************************/

#define T1AD_AR_RELEASE_MAJOR_VERSION                      4
#define T1AD_AR_RELEASE_MINOR_VERSION                      0
#define T1AD_AR_RELEASE_REVISION_VERSION                   3
#define T1AD_SW_MAJOR_VERSION                              1
#define T1AD_SW_MINOR_VERSION                              1
#define T1AD_SW_PATCH_VERSION                              0
#define T1AD_VENDOR_ID                                     ((uint16)76)
#define T1AD_MODULE_ID                                     ((uint16)257)

/*******************************************************************************
**                      Precompile Macros                                     **
*******************************************************************************/

/* Pre-compile option for Development Error Detect */
#define T1AD_DEV_ERROR_DETECT               STD_ON

/* Pre-compile option for Version Infor API */
#define T1AD_VERSION_INFO                   STD_ON

/* Pre-compile option for Enable/Disable T1 function */
#define T1AD_ENABLE_FUNCTION                STD_OFF



/*******************************************************************************
**                           Macros                                           **
*******************************************************************************/

/* Tx Lower Layer IF PDU Count */
#define T1AD_MAX_LOWER_IF_TX_PDU_COUNT      1

/* Rx Lower Layer IF PDU Count */
#define T1AD_MAX_LOWER_IF_RX_PDU_COUNT      1

#define T1AD_TX_PDU_LENGTH    (32)

/*******************************************************************************
**                     IF Tx Lower I-PDU Handles                              **
*******************************************************************************/
#define T1Ad_LowerIfTxPduId_T1Ad_TxPdu (PduIdType)0


#define T1AD_TX_PDU_ID T1Ad_LowerIfTxPduId_T1Ad_TxPdu


/*******************************************************************************
**                     IF Rx Lower I-PDU Handles                              **
*******************************************************************************/
#define T1Ad_LowerIfRxPduId_T1Ad_RxPdu (PduIdType)0


#define T1AD_RX_PDU_ID T1Ad_LowerIfRxPduId_T1Ad_RxPdu


/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* T1AD_CFG_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
