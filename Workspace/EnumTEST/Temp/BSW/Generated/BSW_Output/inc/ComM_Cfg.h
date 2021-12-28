/*******************************************************************************
**  FILE-NAME: ComM_Cfg.h                                                     **
**                                                                            **
**  MODULE-NAME: AUTOSAR Com Manager module                                   **
**                                                                            **
**  NOTE: This file is auto generated, do not edit this file manually.        **
**                                                                            **
********************************************************************************

********************************************************************************
**                      Generation Tool Information                           **
********************************************************************************
**  Tool Version: 1.9.5                                                       **
**                                                                            **
**  Change History: Refer log file (use -l option to generate log file)       **
**                                                                            **
********************************************************************************
**                      File Generation Information                           **
*******************************************************************************/
/*
 * INPUT FILE:    Configuration\Ecu\Ecud_ComM.arxml
 *                Configuration\Ecu\Ecud_Com.arxml
 *                Configuration\Ecu\Ecud_NvM.arxml
 *                Configuration\Ecu\Ecud_CanNm.arxml
 *                Configuration\Ecu\Ecud_CanIf.arxml
 *                Configuration\Ecu\Ecud_CanSM.arxml
 * GENERATED ON: The time-stamp is removed
 */

#ifndef COMM_CFG_H
#define COMM_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR SPECIFICATION VERSION INFORMATION */
#define COMM_CFG_AR_RELEASE_MAJOR_VERSION                  (4)
#define COMM_CFG_AR_RELEASE_MINOR_VERSION                  (0)
#define COMM_CFG_AR_RELEASE_REVISION_VERSION               (3)
#define COMM_CFG_SW_MAJOR_VERSION                          (1)
#define COMM_CFG_SW_MINOR_VERSION                          (9)
#define COMM_CFG_SW_PATCH_VERSION                          (5)

/*******************************************************************************
**                      Common Published Information                          **
*******************************************************************************/
#define COMM_AR_RELEASE_MAJOR_VERSION                      (4)
#define COMM_AR_RELEASE_MINOR_VERSION                      (0)
#define COMM_AR_RELEASE_REVISION_VERSION                   (3)
#define COMM_SW_MAJOR_VERSION                              (1)
#define COMM_SW_MINOR_VERSION                              (9)
#define COMM_SW_PATCH_VERSION                              (5)
#define COMM_VENDOR_ID                                     ((uint16)76)
#define COMM_MODULE_ID                                     ((uint16)12)

/*******************************************************************************
**                      Pre-Compile Options                                   **
*******************************************************************************/
/* Pre-compile option to enable/disable development error detection */
#define COMM_DEV_ERROR_DETECT (STD_ON)

/* 
 * Pre-compile option to enable/disable create a ComMUser per ComMPnc and a
 * ComMUser per ComMChannel
 */
#define COMM_DIRECT_USER_MAPPING (STD_OFF)

/* Pre-compile option to include Wake up inhibition functionality  */
#define COMM_WAKEUP_INHIBITION_ENABLED (STD_OFF)

/* Pre-compile option defines the mode inhibition allowed */
#define COMM_ECU_GROUP_CLASSIFICATION ((uint8)3)

/* Pre-compile option to include Mode Limitation functionality */
#define COMM_MODE_LIMITATION_ENABLED (STD_OFF)

/* Pre-compile option to enable/disable support of Partial Network Gateway  */
#define COMM_PNC_GW_ENABLED (STD_OFF)

/* Number of Pncs */
#define COMM_TOTAL_PNCS ((uint8)32)

/* Number of Channels */
#define COMM_TOTAL_CHANNELS ((uint8)4)

/* Number of Users */
#define COMM_TOTAL_USERS ((uint8)35)

/* Number of ComSingnals */
#define COMM_TOTAL_SIGNALS ((uint16)64)

/* Pre-compile option to enable/disable support of Partial Network */
#define COMM_PNC_SUPPORT (STD_ON)

/* 
 * Pre-compile option to enable/disable support of Partial Network for the
 * single configuration
 */
#define COMM_PNC_ENABLED (STD_ON)

/* Pre-compile option to enable/disable Synchronous wakeup */
#define COMM_SYNCHRONOUS_WAKE_UP (STD_OFF)

/* Pre-compile option to enable/disable the ComM_GetVersionInfo API */
#define COMM_VERSION_INFO_API (STD_ON)

/* Pre-compile option to enable/disable CanCM support */
#define COMM_CANCM_SUPPORT (STD_ON)

/* Pre-compile option to enable/disable Binary search for users */
#define COMM_USER_SEQUENTIAL (STD_ON)

/* Pre-compile option to enable/disable Binary search for Channels */
#define COMM_CHANNEL_SEQUENTIAL (STD_ON)

/* Maximum Channel Id configured */
#define COMM_MAX_CHANNELID ((uint8)3)

/* Maximum User Id configured */
#define COMM_MAX_USERID ((uint8)34)

/* Maximum PNC Id configured */
#define COMM_MAX_PNCID ((uint8)63)

/* Maximum Users assigned to channels */
#define COMM_NUMBER_OF_USERTOCHANNEL (3)

/* Maximum number of ComSignal */
#define COMM_MAX_COMSIGNAL ((uint8)0)

/* Pre-compile option for Can Network Present  */
#define COMM_CANNETWORK_PRESENT (STD_ON)

/* Pre-compile option for Fr Network Present */
#define COMM_FRNETWORK_PRESENT (STD_OFF)

/* Pre-compile option for Lin Network Present  */
#define COMM_LINNETWORK_PRESENT (STD_OFF)

/* Pre-compile option for NVRAM block descriptor  */
#define COMM_NVM_BLOCK_DESCRIPTOR (STD_OFF)

/* Pre-compile option for Ethernet Network Present */
#define COMM_ETHNETWORK_PRESENT (STD_OFF)

/* Pre-compile option for SM mode function support */
#define COMM_FUNC_BUSSMCOMMODE_SUPPORT (STD_ON)

/* Pre-compile option for NONE Nm Varient support */
#define COMM_NONE_NMVARIANT_SUPPORT (STD_OFF)

/* Pre-compile option for LIGHT Nm Varient support */
#define COMM_LIGHT_NMVARIANT_SUPPORT (STD_ON)

/* Pre-compile option for FULL Nm Varient support */
#define COMM_FULL_NMVARIANT_SUPPORT (STD_ON)

/* Pre-compile option for PASSIVE Nm Varient support */
#define COMM_PASSIVE_NMVARIANT_SUPPORT (STD_OFF)

/* 
 * Pre-compile option for optional SenderReceiver Port of Interface
 * ComM_CurrentChannelRequest
 */
#define COMM_FULLCOMM_REQ_NOTFN_ENABLED (STD_OFF)

/* Pre-compile option for Count of channels having NVM storage TRUE  */
#define COMM_DIRECT_CHANNEL (STD_ON)

/* Pre-compile option for PNC_COM_MAX_LENGTH  */
#define PNC_COM_MAX_LENGTH ((uint8)4)

/* Pre-compile option to enable/disable Bus Load Detecting Api support */
#define COMM_BUSLOAD_DETECTING (STD_OFF)

/* Pre-compile option for COMM_PNC_VECTOR */
#define COMM_PNC_VECTOR ((uint8)4)


/* Type definition for ComM_TimeType */
typedef uint32 ComM_TimeType;

/*******************************************************************************
**                      Configuration Set Handles                             **
*******************************************************************************/
#define ComMConf_ComMUser_ComMUser_ACANFD1                 (0)
#define ComMConf_ComMUser_ComMUser_ACANFD2                 (1)
#define ComMConf_ComMUser_ComMUser_DebugCANFD              (2)
#define ComMConf_ComMUser_ComMUser_PNC44                   (3)
#define ComMConf_ComMUser_ComMUser_PNC45                   (4)
#define ComMConf_ComMUser_ComMUser_PNC46                   (5)
#define ComMConf_ComMUser_ComMUser_PNC47                   (6)
#define ComMConf_ComMUser_ComMUser_PNC48                   (7)
#define ComMConf_ComMUser_ComMUser_PNC49                   (8)
#define ComMConf_ComMUser_ComMUser_PNC50                   (9)
#define ComMConf_ComMUser_ComMUser_PNC51                   (10)
#define ComMConf_ComMUser_ComMUser_PNC52                   (11)
#define ComMConf_ComMUser_ComMUser_PNC53                   (12)
#define ComMConf_ComMUser_ComMUser_PNC32                   (13)
#define ComMConf_ComMUser_ComMUser_PNC54                   (14)
#define ComMConf_ComMUser_ComMUser_PNC33                   (15)
#define ComMConf_ComMUser_ComMUser_PNC55                   (16)
#define ComMConf_ComMUser_ComMUser_PNC34                   (17)
#define ComMConf_ComMUser_ComMUser_PNC56                   (18)
#define ComMConf_ComMUser_ComMUser_PNC35                   (19)
#define ComMConf_ComMUser_ComMUser_PNC57                   (20)
#define ComMConf_ComMUser_ComMUser_PNC36                   (21)
#define ComMConf_ComMUser_ComMUser_PNC58                   (22)
#define ComMConf_ComMUser_ComMUser_PNC37                   (23)
#define ComMConf_ComMUser_ComMUser_PNC59                   (24)
#define ComMConf_ComMUser_ComMUser_PNC38                   (25)
#define ComMConf_ComMUser_ComMUser_PNC39                   (26)
#define ComMConf_ComMUser_ComMUser_PNC60                   (27)
#define ComMConf_ComMUser_ComMUser_PNC61                   (28)
#define ComMConf_ComMUser_ComMUser_PNC40                   (29)
#define ComMConf_ComMUser_ComMUser_PNC62                   (30)
#define ComMConf_ComMUser_ComMUser_PNC41                   (31)
#define ComMConf_ComMUser_ComMUser_PNC63                   (32)
#define ComMConf_ComMUser_ComMUser_PNC42                   (33)
#define ComMConf_ComMUser_ComMUser_PNC43                   (34)

#define ComMConf_ComMChannel_ComMChannel_ACANFD1           (0)
#define ComMConf_ComMChannel_ComMChannel_ACANFD2           (1)
#define ComMConf_ComMChannel_ComMChannel_DebugCANFD        (2)
#define ComMConf_ComMChannel_ComMChannel_ECANFD            (3)

#define ComMConf_ComMPnc_ComMPnc_PNC32                     (32)
#define ComMConf_ComMPnc_ComMPnc_PNC33                     (33)
#define ComMConf_ComMPnc_ComMPnc_PNC34                     (34)
#define ComMConf_ComMPnc_ComMPnc_PNC35                     (35)
#define ComMConf_ComMPnc_ComMPnc_PNC36                     (36)
#define ComMConf_ComMPnc_ComMPnc_PNC37                     (37)
#define ComMConf_ComMPnc_ComMPnc_PNC38                     (38)
#define ComMConf_ComMPnc_ComMPnc_PNC39                     (39)
#define ComMConf_ComMPnc_ComMPnc_PNC40                     (40)
#define ComMConf_ComMPnc_ComMPnc_PNC41                     (41)
#define ComMConf_ComMPnc_ComMPnc_PNC42                     (42)
#define ComMConf_ComMPnc_ComMPnc_PNC43                     (43)
#define ComMConf_ComMPnc_ComMPnc_PNC44                     (44)
#define ComMConf_ComMPnc_ComMPnc_PNC45                     (45)
#define ComMConf_ComMPnc_ComMPnc_PNC46                     (46)
#define ComMConf_ComMPnc_ComMPnc_PNC47                     (47)
#define ComMConf_ComMPnc_ComMPnc_PNC48                     (48)
#define ComMConf_ComMPnc_ComMPnc_PNC49                     (49)
#define ComMConf_ComMPnc_ComMPnc_PNC50                     (50)
#define ComMConf_ComMPnc_ComMPnc_PNC51                     (51)
#define ComMConf_ComMPnc_ComMPnc_PNC52                     (52)
#define ComMConf_ComMPnc_ComMPnc_PNC53                     (53)
#define ComMConf_ComMPnc_ComMPnc_PNC54                     (54)
#define ComMConf_ComMPnc_ComMPnc_PNC55                     (55)
#define ComMConf_ComMPnc_ComMPnc_PNC56                     (56)
#define ComMConf_ComMPnc_ComMPnc_PNC57                     (57)
#define ComMConf_ComMPnc_ComMPnc_PNC58                     (58)
#define ComMConf_ComMPnc_ComMPnc_PNC59                     (59)
#define ComMConf_ComMPnc_ComMPnc_PNC60                     (60)
#define ComMConf_ComMPnc_ComMPnc_PNC61                     (61)
#define ComMConf_ComMPnc_ComMPnc_PNC62                     (62)
#define ComMConf_ComMPnc_ComMPnc_PNC63                     (63)


/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
/*  polyspace:begin<MISRA-C:8.8:Not a defect:Justify with annotations>
    No Impact of this rule violation                                          */
#define COMM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COMM_CODE) ComM_MainFunction_0(void);
#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COMM_CODE) ComM_MainFunction_1(void);
#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COMM_CODE) ComM_MainFunction_2(void);
#define COMM_STOP_SEC_CODE
#include "MemMap.h"

#define COMM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COMM_CODE) ComM_MainFunction_3(void);
#define COMM_STOP_SEC_CODE
#include "MemMap.h"


#define COMM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, COMM_CODE) ComM_COMCbk_ComISignal_Rx_EIRA_CanNm(void);
#define COMM_STOP_SEC_CODE
#include "MemMap.h"


/*  polyspace:end<MISRA-C:8.8:Not a defect:Justify with annotations>
    No Impact of this rule violation                                          */
#endif /* COMM_CFG_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
