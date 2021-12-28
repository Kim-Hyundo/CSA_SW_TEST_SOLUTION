/*******************************************************************************
**  FILE-NAME: NvM_Cfg.h                                                      **
**                                                                            **
**  MODULE-NAME: AUTOSAR NVRAM Manager Module                                 **
**                                                                            **
**  NOTE: This file is auto generated, do not edit this file manually.        **
**                                                                            **
********************************************************************************

********************************************************************************
**                      Generation Tool Information                           **
********************************************************************************
**  Tool Version: 1.5.0                                                       **
**                                                                            **
**  Change History: Refer log file (use -l option to generate log file)       **
**                                                                            **
********************************************************************************
**                      File Generation Information                           **
*******************************************************************************/

/*
 * INPUT FILE:    Configuration\Ecu\Ecud_BswM.arxml
 *                Configuration\Ecu\Ecud_Dem.arxml
 *                Configuration\Ecu\Ecud_NvM.arxml
 *                Configuration\Ecu\Ecud_Os.arxml
 *                Configuration\Ecu\Mcal\Ecud_Fee.arxml
 *                Configuration\Ecu\Mcal\Ecud_Fls.arxml
 * GENERATED ON: The time-stamp is removed
 */

#ifndef NVM_CFG_H
#define NVM_CFG_H

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/*
polyspace-begin MISRA-C3:1.1 [Justified:Low] "No Impact of this rule violation (AUTOSAR Standard-NvM SWS Chap 5.1.2)"
polyspace-begin MISRA-C3:5.1 [Justified:Low] "No Impact of this rule violation (AUTOSAR Standard)"
polyspace-begin MISRA-C3:8.12 [Justified:Low] "No Impact of this rule violation (for library)"
*/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "NvM_Types.h"

/*******************************************************************************
**                      Common Published Information                          **
*******************************************************************************/
#define NVM_AR_RELEASE_MAJOR_VERSION                       (4)
#define NVM_AR_RELEASE_MINOR_VERSION                       (0)
#define NVM_AR_RELEASE_REVISION_VERSION                    (3)
#define NVM_SW_MAJOR_VERSION                               (1)
#define NVM_SW_MINOR_VERSION                               (5)
#define NVM_SW_PATCH_VERSION                               (0)
#define NVM_VENDOR_ID                                      ((uint16)76)
#define NVM_MODULE_ID                                      ((uint16)20)

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* Defines the set of functionality required by NvM */
#define NVM_API_CONFIG_CLASS                (NVM_API_CONFIG_CLASS_3)

/* Defines Dem Container is present or not */
#define NVM_DEMERROR_REPORT                 STD_ON

/* Defines compiled config Id */
#define NVM_COMPILED_CONFIG_ID              ((uint16)59)

/* Defines number of CRC bytes processed in one scan cycle */
#define NVM_CRC_NUM_OF_BYTES                ((uint16)16)

/* 
 * Defines the number of least significant bits which shall be used to
 * address a certain dataset of a NVRAM block within the interface to the
 * memory hardware abstraction
 */
#define NVM_DATASET_SELECTION_BITS          ((uint8)2)

/* Enables/Disables Development error detection */
#define NVM_DEV_ERROR_DETECT                STD_ON

/* Defines PM is enable or not */
#define NVM_PM_ENABLE                       STD_OFF

/* Enables or Disables Dynamic configuration during Readall */
#define NVM_DYNAMIC_CONFIGURATION           STD_OFF

/* Enables or Disables the Fast Mode during Readall/WriteAll */
#define NVM_DRV_MODE_SWITCH                 STD_ON

/* Enables or Disables Prioritization for Blocks */
#define NVM_JOB_PRIORITIZATION              STD_ON

/* Enable if NVM_JOB_PRIORITIZATION is STD_ON */
#define NVM_IMM_JOB_PRIORITY                STD_ON

/* Enables/Disables Lower layer Callback notification */
#define NVM_POLLING_MODE                    STD_OFF

/* Enables or Disables inclusion of SetRamBlockStatus API */
#define NVM_SET_RAM_BLOCK_STATUS_API        STD_OFF

/* Enables or Disables GetVersionInfo API */
#define NVM_VERSION_INFO_API                STD_ON

/* 
 * Notifies Dataset block is configured/not configured,If any one of the
 * block is configured as DATASET
 */
#define NVM_DATASET_PRESENT                 STD_ON

/* 
 * Enables/Disables CRC Support,If parameter NvMBlockUseCrc is configured
 * for any one of the block then CRC Support should be STD_ON
 */
#define NVM_CRC_SUPPORT                     STD_ON

/* Enables/Disables NvMMultiBlockCallback */
#define NVM_MULTIBLKCBK_ENABLE              STD_ON

/* 
 * Enables/Disables InitBlockCallback,If any one block NvMInitBlockCallback
 * is configured then Init Callback should be STD_ON
 */
#define NVM_INIT_CALLBACK                   STD_ON

/* 
 * Enables/Disables SignleBlockCallback If any one block
 * NvMSingleBlockCallback is configured then Single block Callback should be ON
 */
#define NVM_SINGLE_BLOCK_CALLBACK           STD_ON

/* 
 * Defines the number of retries to let the application copy data to or
 * from the NvM modules mirror before postponing the current job
 */
#define NVM_REPEAT_MIRROR_OPERATIONS        ((uint8)3)

/* 
 * Should be generated if NVM_JOB_PRIORITIZATION is STD_ON and
 * NVM_IMM_JOB_PRIORITY is STD_ON.Defines the number of queue entries for the
 * immediate priority write queue
 */
#define NVM_SIZE_IMMEDIATE_JOB_QUEUE        ((uint8)1)

/* Defines the number of queue entries for the std priority queue */
#define NVM_SIZE_STANDARD_JOB_QUEUE         ((uint8)30)

/* 
 * Enables/Disables explicit synchronization mechanism If any one block
 * NvMBlockUseSyncMechanism is configured as TRUE then synchronization
 * mechanism should be STD_ON
 */
#define NVM_BLOCK_USE_SYNC_MECHANISM        STD_OFF

/* 
 * Enables/Disables Write Verification If any one block
 * NvMWriteVerification is configured as TRUE then Write Verification should be
 * STD_ON
 */
#define NVM_WRITE_VERIFICATION              STD_ON

/* 
 * If any one block NvMRamBlockDataAddress is configured then RAM Block
 * Data Address should be STD_ON
 */
#define NVM_RAM_BLOCK_DATA_ADDRESS          STD_ON

/* Macro for Max NvMNvBlockLength configured */
#define NVM_MIRROR_BUFFER                   ((uint16)308)

/* Defines number of blocks with dataset management that are configured */
#define NVM_DATASET_INDEX                   ((uint16)1)

/* Defines the Multiblock callback configured by NvMMultiBlockCallback */
#define NVM_MULTI_BLOCK_CBK                 (BswM_NvM_CurrentJobMode)

/* 
 * If any one block NvMStaticBlockIDCheck is configured then it should be
 * STD_ON
 */
#define NVM_STATIC_ID_CHECK                 STD_OFF

/* Total number of blocks configured for ReadAll */
#define NVM_TOTAL_NUM_OF_READALL_BLOCKS     25

/* Total number of blocks configured for WriteAll */
#define NVM_TOTAL_NUM_OF_WRITEALL_BLOCKS    19

/* Total number of blocks not configured for ReadAll */
#define NVM_BLOCKS_NOT_CONFIG_READALL       2

/* Total number of blocks not configured for WriteAll */
#define NVM_BLOCKS_NOT_CONFIG_WRITEALL      8

/* Defines Maximum data length for NvMWriteVerificationDataSize */
#define NVM_MAX_WRITE_VER_BLK_LENGTH        ((uint16)4)

/* Macro for knowing size of CRC and SID configured */
#define NVM_CRC_SID_SIZE                    6

/* Macro for knowing CRC Type configured */
#define NVM_CRC8_SUPPORT                    STD_ON

/* Macro for knowing CRC Type configured */
#define NVM_CRC16_SUPPORT                   STD_ON

/* Macro for knowing CRC Type configured */
#define NVM_CRC32_SUPPORT                   STD_ON

/* 
 * Informs whether to initimate BswM about the current status of Multiblock
 * job. If it is STD_ON, then the multiblock status should be informed to BswM
 */
#define NVM_BSWM_MULTI_BLOCK_JOB_STATUS_INFORMATION STD_ON

/* Os Alarm for trigger Memory Mainfunction */
#define NVM_OS_ALARM                        (OsAlarm_BSW_Mem_Process)

/* Tick value for trigger Memory Mainfunction */
#define NVM_TICKS_BURST_MODE                1

/* Tick value for trigger Memory Mainfunction */
#define NVM_TICKS_NORMAL_MODE               4

/* configure the time for the periodic cyclic task */
#define NVM_TASK_TIME                       5

/* Macro for knowing whether fast WriteAll function for Dem is supported */
#define NVM_BSWM_DEM_WRITENVDATA_CALL       STD_OFF

/* Total number of NVRAM blocks */
#define NVM_TOTAL_NUM_OF_NVRAM_BLOCKS       ((NvM_BlockIdType)28)



/*******************************************************************************
**                      Configuration Set Handles                             **
*******************************************************************************/
#define NvMConf_NvMBlockDescriptor_NvMBlock_ConfigID       ((NvM_BlockIdType)1)
#define NvMConf_NvMBlockDescriptor_NvMBlock_DemNonVolatileData\
  ((NvM_BlockIdType)2)
#define NvMConf_NvMBlockDescriptor_NvMBlock_DemEventStatusNvRamBlock\
  ((NvM_BlockIdType)3)
#define NvMConf_NvMBlockDescriptor_NvMBlock_DemPrimaryEventMemoryEntry_0\
  ((NvM_BlockIdType)4)
#define NvMConf_NvMBlockDescriptor_NvMBlock_DemPrimaryEventMemoryEntry_1\
  ((NvM_BlockIdType)5)
#define NvMConf_NvMBlockDescriptor_NvMBlock_DemPrimaryEventMemoryEntry_2\
  ((NvM_BlockIdType)6)
#define NvMConf_NvMBlockDescriptor_NvMBlock_DemPrimaryEventMemoryEntry_3\
  ((NvM_BlockIdType)7)
#define NvMConf_NvMBlockDescriptor_NvMBlock_DemPrimaryEventMemoryEntry_4\
  ((NvM_BlockIdType)8)
#define NvMConf_NvMBlockDescriptor_NvMBlock_DemPrimaryEventMemoryEntry_5\
  ((NvM_BlockIdType)9)
#define NvMConf_NvMBlockDescriptor_NvMBlock_DemPrimaryEventMemoryEntry_6\
  ((NvM_BlockIdType)10)
#define NvMConf_NvMBlockDescriptor_NvMBlock_DemPrimaryEventMemoryEntry_7\
  ((NvM_BlockIdType)11)
#define NvMConf_NvMBlockDescriptor_NvMBlock_DemPrimaryEventMemoryEntry_8\
  ((NvM_BlockIdType)12)
#define NvMConf_NvMBlockDescriptor_NvMBlock_DemPrimaryEventMemoryEntry_9\
  ((NvM_BlockIdType)13)
#define NvMConf_NvMBlockDescriptor_NvMBlock_DemSecondaryEventMemoryEntry_0\
  ((NvM_BlockIdType)14)
#define NvMConf_NvMBlockDescriptor_NvMBlock_Test_Native_6  ((NvM_BlockIdType)15)
#define NvMConf_NvMBlockDescriptor_NvMBlock_IntTst_TestBlock1\
  ((NvM_BlockIdType)16)
#define NvMConf_NvMBlockDescriptor_NvMBlock_IntTst_TestBlock2\
  ((NvM_BlockIdType)17)
#define NvMConf_NvMBlockDescriptor_NvMBlock_IntTst_TestBlock3\
  ((NvM_BlockIdType)18)
#define NvMConf_NvMBlockDescriptor_NvMBlock_IDC_DCD_Segment ((NvM_BlockIdType)19)
#define NvMConf_NvMBlockDescriptor_NvMBlock_IDC_USM_Segment ((NvM_BlockIdType)20)
#define NvMConf_NvMBlockDescriptor_NvMBlock_VDISP_Segment  ((NvM_BlockIdType)21)
#define NvMConf_NvMBlockDescriptor_NvMBlock_IDS_Segment    ((NvM_BlockIdType)22)
#define NvMConf_NvMBlockDescriptor_NvMBlock_Failsafe_Segment\
  ((NvM_BlockIdType)23)
#define NvMConf_NvMBlockDescriptor_NvMBlock_Variant_Code_Segment\
  ((NvM_BlockIdType)24)
#define NvMConf_NvMBlockDescriptor_NvMBlock_Variant_Code_W_Segment\
  ((NvM_BlockIdType)25)
#define NvMConf_NvMBlockDescriptor_NvMBlock_SystemVariable_Segment\
  ((NvM_BlockIdType)26)
#define NvMConf_NvMBlockDescriptor_NvMBlock_Traceability_Segment\
  ((NvM_BlockIdType)27)

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define NVM_START_SEC_CONST_16
#include "MemMap.h"

extern CONST(uint16, NVM_CONST) NvM_GaaReadAll[];

extern CONST(uint16, NVM_CONST) NvM_GaaWriteAll[];

extern CONST(uint16, NVM_CONST) NvM_GaaNotReadAll[];

extern CONST(uint16, NVM_CONST) NvM_GaaNotWriteAll[];

#define NVM_STOP_SEC_CONST_16
#include "MemMap.h"

#define NVM_START_SEC_VAR_NO_INIT_8
#include "MemMap.h"
extern VAR(uint8, NVM_VAR_NOINIT) NvM_GaaWriteVerificationBuffer[];
#define NVM_STOP_SEC_VAR_NO_INIT_8
#include "MemMap.h"


extern void (BswM_NvM_CurrentJobMode)
            (uint8 ServiceId, NvM_RequestResultType JobResult);
/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/
/*
polyspace-end MISRA-C3:1.1 [Justified:Low] "No Impact of this rule violation (AUTOSAR Standard-NvM SWS Chap 5.1.2)"
polyspace-end MISRA-C3:5.1 [Justified:Low] "No Impact of this rule violation (AUTOSAR Standard)"
polyspace-end MISRA-C3:8.12 [Justified:Low] "No Impact of this rule violation (for library)"
*/
#endif /* NVM_CFG_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
