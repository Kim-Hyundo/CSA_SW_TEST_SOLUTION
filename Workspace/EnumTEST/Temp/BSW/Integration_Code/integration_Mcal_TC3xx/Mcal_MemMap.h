/*******************************************************************************
**  (C) 2019 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Mcal_MemMap.h                                                 **
**                                                                            **
**  TARGET    : TC3xx using Tasking complier                                  **
**                                                                            **
**  PRODUCT   :                                                               **
**                                                                            **
**  PURPOSE   : Provision for sections for memory mapping.                    **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: yes                                          **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date           By            Description                         **
********************************************************************************
** 1.0.0     14-05-2020     SH.Park       Initial version                     **
*******************************************************************************/

/*******************************************************************************
**                      Module section mapping                                **
*******************************************************************************/

#ifdef __cplusplus
extern "C"{
#endif

#define MCAL_SECTION_NOT_FOUND

#ifdef ADC_START_SEC_VAR_CLEARED_ASIL_B_CORE0_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_START_SEC_VAR_CLEARED_ASIL_B_CORE1_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_START_SEC_VAR_CLEARED_ASIL_B_CORE2_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_START_SEC_VAR_CLEARED_ASIL_B_CORE3_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_START_SEC_VAR_CLEARED_ASIL_B_CORE4_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_START_SEC_VAR_CLEARED_ASIL_B_CORE5_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_16
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_16
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_START_SEC_VAR_INIT_ASIL_B_GLOBAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_START_SEC_VAR_INIT_ASIL_B_GLOBAL_16
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_16
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_START_SEC_CONST_ASIL_B_GLOBAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_STOP_SEC_CONST_ASIL_B_GLOBAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_START_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_STOP_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_START_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_STOP_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_START_SEC_CODE_ASIL_B_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef ADC_STOP_SEC_CODE_ASIL_B_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Adc_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_START_SEC_VAR_CLEARED_QM_CORE0_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_STOP_SEC_VAR_CLEARED_QM_CORE0_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_START_SEC_VAR_CLEARED_QM_CORE1_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_STOP_SEC_VAR_CLEARED_QM_CORE1_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_START_SEC_VAR_CLEARED_QM_CORE2_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_STOP_SEC_VAR_CLEARED_QM_CORE2_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_START_SEC_VAR_CLEARED_QM_CORE3_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_STOP_SEC_VAR_CLEARED_QM_CORE3_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_START_SEC_VAR_CLEARED_QM_CORE4_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_STOP_SEC_VAR_CLEARED_QM_CORE4_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_START_SEC_VAR_CLEARED_QM_CORE5_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_STOP_SEC_VAR_CLEARED_QM_CORE5_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_START_SEC_VAR_CLEARED_QM_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_STOP_SEC_VAR_CLEARED_QM_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_START_SEC_VAR_CLEARED_QM_GLOBAL_U16
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_STOP_SEC_VAR_CLEARED_QM_GLOBAL_U16
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_START_SEC_VAR_CLEARED_QM_GLOBAL_U8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_STOP_SEC_VAR_CLEARED_QM_GLOBAL_U8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_START_SEC_VAR_INIT_QM_GLOBAL_U32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_STOP_SEC_VAR_INIT_QM_GLOBAL_U32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_START_SEC_VAR_INIT_QM_GLOBAL_U8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_STOP_SEC_VAR_INIT_QM_GLOBAL_U8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_START_SEC_CONST_QM_CORE0_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_STOP_SEC_CONST_QM_CORE0_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_START_SEC_CONST_QM_CORE1_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_STOP_SEC_CONST_QM_CORE1_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_START_SEC_CONST_QM_CORE2_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_STOP_SEC_CONST_QM_CORE2_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_START_SEC_CONST_QM_CORE3_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_STOP_SEC_CONST_QM_CORE3_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_START_SEC_CONST_QM_CORE4_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_STOP_SEC_CONST_QM_CORE4_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_START_SEC_CONST_QM_CORE5_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_STOP_SEC_CONST_QM_CORE5_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_START_SEC_CONST_QM_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_STOP_SEC_CONST_QM_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_START_SEC_CONFIG_DATA_QM_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_STOP_SEC_CONFIG_DATA_QM_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_START_SEC_CONFIG_DATA_QM_CORE0_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_STOP_SEC_CONFIG_DATA_QM_CORE0_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_START_SEC_CONFIG_DATA_QM_CORE1_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_STOP_SEC_CONFIG_DATA_QM_CORE1_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_START_SEC_CONFIG_DATA_QM_CORE2_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_STOP_SEC_CONFIG_DATA_QM_CORE2_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_START_SEC_CONFIG_DATA_QM_CORE3_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_STOP_SEC_CONFIG_DATA_QM_CORE3_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_START_SEC_CONFIG_DATA_QM_CORE4_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_STOP_SEC_CONFIG_DATA_QM_CORE4_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_START_SEC_CONFIG_DATA_QM_CORE5_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_STOP_SEC_CONFIG_DATA_QM_CORE5_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_START_SEC_CODE_QM_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef CAN_17_MCMCAN_STOP_SEC_CODE_QM_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef DIO_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Dio_MemMap.h"
#endif

#ifdef DIO_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Dio_MemMap.h"
#endif

#ifdef DIO_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Dio_MemMap.h"
#endif

#ifdef DIO_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Dio_MemMap.h"
#endif

#ifdef DIO_START_SEC_CONST_ASIL_B_GLOBAL_16
    #undef MCAL_SECTION_NOT_FOUND
    #include "Dio_MemMap.h"
#endif

#ifdef DIO_STOP_SEC_CONST_ASIL_B_GLOBAL_16
    #undef MCAL_SECTION_NOT_FOUND
    #include "Dio_MemMap.h"
#endif

#ifdef DIO_START_SEC_CONST_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Dio_MemMap.h"
#endif

#ifdef DIO_STOP_SEC_CONST_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Dio_MemMap.h"
#endif

#ifdef DIO_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Dio_MemMap.h"
#endif

#ifdef DIO_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Dio_MemMap.h"
#endif

#ifdef DIO_START_SEC_CODE_ASIL_B_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Dio_MemMap.h"
#endif

#ifdef DIO_STOP_SEC_CODE_ASIL_B_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Dio_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE0_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE0_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE0_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE0_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE1_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE1_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE1_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE1_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE2_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE2_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE2_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE2_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE3_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE3_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE3_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE3_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE4_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE4_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE4_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE4_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE5_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE5_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_CORE5_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_CORE5_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_TXBUFFER_CLEARED_QM_CORE0_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_TXBUFFER_CLEARED_QM_CORE0_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_TXBUFFER_CLEARED_QM_CORE1_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_TXBUFFER_CLEARED_QM_CORE1_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_TXBUFFER_CLEARED_QM_CORE2_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_TXBUFFER_CLEARED_QM_CORE2_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_TXBUFFER_CLEARED_QM_CORE3_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_TXBUFFER_CLEARED_QM_CORE3_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_TXBUFFER_CLEARED_QM_CORE4_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_TXBUFFER_CLEARED_QM_CORE4_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_TXBUFFER_CLEARED_QM_CORE5_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_TXBUFFER_CLEARED_QM_CORE5_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_RXBUFFER_CLEARED_QM_CORE0_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_RXBUFFER_CLEARED_QM_CORE0_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_RXBUFFER_CLEARED_QM_CORE1_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_RXBUFFER_CLEARED_QM_CORE1_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_RXBUFFER_CLEARED_QM_CORE2_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_RXBUFFER_CLEARED_QM_CORE2_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_RXBUFFER_CLEARED_QM_CORE3_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_RXBUFFER_CLEARED_QM_CORE3_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_RXBUFFER_CLEARED_QM_CORE4_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_RXBUFFER_CLEARED_QM_CORE4_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_RXBUFFER_CLEARED_QM_CORE5_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_RXBUFFER_CLEARED_QM_CORE5_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_INIT_QM_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_INIT_QM_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_GLOBAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_GLOBAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_INIT_QM_GLOBAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_INIT_QM_GLOBAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_LOCAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_LOCAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_INIT_QM_LOCAL_16
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_INIT_QM_LOCAL_16
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_INIT_QM_LOCAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_INIT_QM_LOCAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_LOCAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_LOCAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_CONST_QM_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_CONST_QM_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_CONFIG_DATA_QM_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_CONFIG_DATA_QM_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_CONFIG_DATA_QM_CORE0_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_CONFIG_DATA_QM_CORE0_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_CONFIG_DATA_QM_CORE1_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_CONFIG_DATA_QM_CORE1_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_CONFIG_DATA_QM_CORE2_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_CONFIG_DATA_QM_CORE2_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_CONFIG_DATA_QM_CORE3_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_CONFIG_DATA_QM_CORE3_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_CONFIG_DATA_QM_CORE4_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_CONFIG_DATA_QM_CORE4_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_CONFIG_DATA_QM_CORE5_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_CONFIG_DATA_QM_CORE5_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_CONFIG_DATA_QM_LOCAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_CONFIG_DATA_QM_LOCAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_CLEARED_QM_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_CLEARED_QM_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_INIT_QM_CORE0_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_INIT_QM_CORE0_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_INIT_QM_CORE1_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_INIT_QM_CORE1_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_INIT_QM_CORE2_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_INIT_QM_CORE2_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_INIT_QM_CORE3_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_INIT_QM_CORE3_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_INIT_QM_CORE4_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_INIT_QM_CORE4_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_VAR_INIT_QM_CORE5_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_VAR_INIT_QM_CORE5_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_CODE_QM_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_CODE_QM_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_CODE_QM_LOCAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_CODE_QM_LOCAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef FEE_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Fee_MemMap.h"
#endif

#ifdef FEE_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Fee_MemMap.h"
#endif

#ifdef FEE_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Fee_MemMap.h"
#endif

#ifdef FEE_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Fee_MemMap.h"
#endif

#ifdef FEE_START_SEC_VAR_INIT_ASIL_B_LOCAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Fee_MemMap.h"
#endif

#ifdef FEE_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Fee_MemMap.h"
#endif

#ifdef FEE_START_SEC_CONST_ASIL_B_LOCAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Fee_MemMap.h"
#endif

#ifdef FEE_STOP_SEC_CONST_ASIL_B_LOCAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Fee_MemMap.h"
#endif

#ifdef FEE_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Fee_MemMap.h"
#endif

#ifdef FEE_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Fee_MemMap.h"
#endif

#ifdef FEE_START_SEC_CODE_ASIL_B_LOCAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Fee_MemMap.h"
#endif

#ifdef FEE_STOP_SEC_CODE_ASIL_B_LOCAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Fee_MemMap.h"
#endif

#ifdef FEE_START_SEC_JOBENDNOTIF_CODE_ASIL_B_LOCAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Fee_MemMap.h"
#endif

#ifdef FEE_STOP_SEC_JOBENDNOTIF_CODE_ASIL_B_LOCAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Fee_MemMap.h"
#endif

#ifdef FEE_START_SEC_JOBERRNOTIF_CODE_ASIL_B_LOCAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Fee_MemMap.h"
#endif

#ifdef FEE_STOP_SEC_JOBERRNOTIF_CODE_ASIL_B_LOCAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Fee_MemMap.h"
#endif

#ifdef FEE_START_SEC_ILLEGALNOTIF_CODE_ASIL_B_LOCAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Fee_MemMap.h"
#endif

#ifdef FEE_STOP_SEC_ILLEGALNOTIF_CODE_ASIL_B_LOCAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Fee_MemMap.h"
#endif

#ifdef FEE_START_SEC_ERASEERRORNOTI_CODE_ASIL_B_LOCAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Fee_MemMap.h"
#endif

#ifdef FEE_STOP_SEC_ERASEERRORNOTI_CODE_ASIL_B_LOCAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Fee_MemMap.h"
#endif

#ifdef FEE_START_SEC_PROGERRORNOTI_CODE_ASIL_B_LOCAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Fee_MemMap.h"
#endif

#ifdef FEE_STOP_SEC_PROGERRORNOTI_CODE_ASIL_B_LOCAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Fee_MemMap.h"
#endif

#ifdef FLSLOADER_START_SEC_VAR_CLEARED_QM_LOCAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Flsloader_MemMap.h"
#endif

#ifdef FLSLOADER_STOP_SEC_VAR_CLEARED_QM_LOCAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Flsloader_MemMap.h"
#endif

#ifdef FLSLOADER_START_SEC_VAR_INIT_QM_LOCAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Flsloader_MemMap.h"
#endif

#ifdef FLSLOADER_STOP_SEC_VAR_INIT_QM_LOCAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Flsloader_MemMap.h"
#endif

#ifdef FLSLOADER_START_SEC_VAR_CLEARED_QM_LOCAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Flsloader_MemMap.h"
#endif

#ifdef FLSLOADER_STOP_SEC_VAR_CLEARED_QM_LOCAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Flsloader_MemMap.h"
#endif

#ifdef FLSLOADER_START_SEC_CONST_QM_LOCAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Flsloader_MemMap.h"
#endif

#ifdef FLSLOADER_STOP_SEC_CONST_QM_LOCAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Flsloader_MemMap.h"
#endif

#ifdef FLSLOADER_START_SEC_CONST_QM_LOCAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Flsloader_MemMap.h"
#endif

#ifdef FLSLOADER_STOP_SEC_CONST_QM_LOCAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Flsloader_MemMap.h"
#endif

#ifdef FLSLOADER_START_SEC_CODE_QM_LOCAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Flsloader_MemMap.h"
#endif

#ifdef FLSLOADER_STOP_SEC_CODE_QM_LOCAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Flsloader_MemMap.h"
#endif

#ifdef FLSLOADER_START_SEC_WRITEERASE_CODE_QM_LOCAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Flsloader_MemMap.h"
#endif

#ifdef FLSLOADER_STOP_SEC_WRITEERASE_CODE_QM_LOCAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Flsloader_MemMap.h"
#endif

#ifdef FLSLOADER_START_SEC_BUSYLOOP_CALLOUT_CODE_QM_LOCAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Flsloader_MemMap.h"
#endif

#ifdef FLSLOADER_STOP_SEC_BUSYLOOP_CALLOUT_CODE_QM_LOCAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Flsloader_MemMap.h"
#endif

#ifdef FLS_17_DMU_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Fls_17_Dmu_MemMap.h"
#endif

#ifdef FLS_17_DMU_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Fls_17_Dmu_MemMap.h"
#endif

#ifdef FLS_17_DMU_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Fls_17_Dmu_MemMap.h"
#endif

#ifdef FLS_17_DMU_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Fls_17_Dmu_MemMap.h"
#endif

#ifdef FLS_17_DMU_START_SEC_VAR_INIT_ASIL_B_LOCAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Fls_17_Dmu_MemMap.h"
#endif

#ifdef FLS_17_DMU_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Fls_17_Dmu_MemMap.h"
#endif

#ifdef FLS_17_DMU_START_SEC_VAR_INIT_ASIL_B_LOCAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Fls_17_Dmu_MemMap.h"
#endif

#ifdef FLS_17_DMU_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Fls_17_Dmu_MemMap.h"
#endif

#ifdef FLS_17_DMU_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Fls_17_Dmu_MemMap.h"
#endif

#ifdef FLS_17_DMU_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Fls_17_Dmu_MemMap.h"
#endif

#ifdef FLS_17_DMU_START_SEC_CODE_ASIL_B_LOCAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Fls_17_Dmu_MemMap.h"
#endif

#ifdef FLS_17_DMU_STOP_SEC_CODE_ASIL_B_LOCAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Fls_17_Dmu_MemMap.h"
#endif

#ifdef GPT_START_SEC_VAR_CLEARED_ASIL_B_CORE0_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_START_SEC_VAR_INIT_ASIL_B_CORE0_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_ASIL_B_CORE0_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_START_SEC_VAR_CLEARED_ASIL_B_CORE1_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_START_SEC_VAR_INIT_ASIL_B_CORE1_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_ASIL_B_CORE1_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_START_SEC_VAR_CLEARED_ASIL_B_CORE2_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_START_SEC_VAR_INIT_ASIL_B_CORE2_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_ASIL_B_CORE2_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_START_SEC_VAR_CLEARED_ASIL_B_CORE3_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_START_SEC_VAR_INIT_ASIL_B_CORE3_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_ASIL_B_CORE3_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_START_SEC_VAR_CLEARED_ASIL_B_CORE4_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_START_SEC_VAR_INIT_ASIL_B_CORE4_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_ASIL_B_CORE4_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_START_SEC_VAR_CLEARED_ASIL_B_CORE5_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_START_SEC_VAR_INIT_ASIL_B_CORE5_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_ASIL_B_CORE5_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_START_SEC_CONST_ASIL_B_CORE0_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_STOP_SEC_CONST_ASIL_B_CORE0_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_START_SEC_CONST_ASIL_B_CORE1_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_STOP_SEC_CONST_ASIL_B_CORE1_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_START_SEC_CONST_ASIL_B_CORE2_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_STOP_SEC_CONST_ASIL_B_CORE2_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_START_SEC_CONST_ASIL_B_CORE3_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_STOP_SEC_CONST_ASIL_B_CORE3_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_START_SEC_CONST_ASIL_B_CORE4_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_STOP_SEC_CONST_ASIL_B_CORE4_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_START_SEC_CONST_ASIL_B_CORE5_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_STOP_SEC_CONST_ASIL_B_CORE5_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_START_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_STOP_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_START_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_STOP_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_START_SEC_CODE_ASIL_B_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_STOP_SEC_CODE_ASIL_B_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_START_SEC_CODE_FAST_ASIL_B_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef GPT_STOP_SEC_CODE_FAST_ASIL_B_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Gpt_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_START_SEC_VAR_CLEARED_ASIL_B_CORE0_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_CORE0_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_CORE0_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_START_SEC_VAR_CLEARED_ASIL_B_CORE1_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_CORE1_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_CORE1_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_START_SEC_VAR_CLEARED_ASIL_B_CORE2_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_CORE2_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_CORE2_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_START_SEC_VAR_CLEARED_ASIL_B_CORE3_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_CORE3_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_CORE3_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_START_SEC_VAR_CLEARED_ASIL_B_CORE4_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_CORE4_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_CORE4_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_START_SEC_VAR_CLEARED_ASIL_B_CORE5_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_CORE5_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_CORE5_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_START_SEC_CONST_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_CONST_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_START_SEC_CODE_ASIL_B_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef ICU_17_TIMERIP_STOP_SEC_CODE_ASIL_B_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Icu_17_TimerIp_MemMap.h"
#endif

#ifdef IRQ_START_SEC_CODE_QM_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Irq_MemMap.h"
#endif

#ifdef IRQ_STOP_SEC_CODE_QM_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Irq_MemMap.h"
#endif

#ifdef LIN_17_ASCLIN_START_SEC_VAR_INIT_QM_LOCAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Lin_17_AscLin_MemMap.h"
#endif

#ifdef LIN_17_ASCLIN_STOP_SEC_VAR_INIT_QM_LOCAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Lin_17_AscLin_MemMap.h"
#endif

#ifdef LIN_17_ASCLIN_START_SEC_VAR_INIT_QM_LOCAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Lin_17_AscLin_MemMap.h"
#endif

#ifdef LIN_17_ASCLIN_STOP_SEC_VAR_INIT_QM_LOCAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Lin_17_AscLin_MemMap.h"
#endif

#ifdef LIN_17_ASCLIN_START_SEC_VAR_CLEARED_QM_LOCAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Lin_17_AscLin_MemMap.h"
#endif

#ifdef LIN_17_ASCLIN_START_SEC_VAR_CLEARED_QM_LOCAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Lin_17_AscLin_MemMap.h"
#endif

#ifdef LIN_17_ASCLIN_STOP_SEC_VAR_CLEARED_QM_LOCAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Lin_17_AscLin_MemMap.h"
#endif

#ifdef LIN_17_ASCLIN_START_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Lin_17_AscLin_MemMap.h"
#endif

#ifdef LIN_17_ASCLIN_STOP_SEC_VAR_CLEARED_QM_LOCAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Lin_17_AscLin_MemMap.h"
#endif

#ifdef LIN_17_ASCLIN_START_SEC_CONST_QM_LOCAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Lin_17_AscLin_MemMap.h"
#endif

#ifdef LIN_17_ASCLIN_STOP_SEC_CONST_QM_LOCAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Lin_17_AscLin_MemMap.h"
#endif

#ifdef LIN_17_ASCLIN_START_SEC_CONFIG_DATA_QM_LOCAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Lin_17_AscLin_MemMap.h"
#endif

#ifdef LIN_17_ASCLIN_STOP_SEC_CONFIG_DATA_QM_LOCAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Lin_17_AscLin_MemMap.h"
#endif

#ifdef LIN_17_ASCLIN_START_SEC_CODE_QM_LOCAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Lin_17_AscLin_MemMap.h"
#endif

#ifdef LIN_17_ASCLIN_STOP_SEC_CODE_QM_LOCAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Lin_17_AscLin_MemMap.h"
#endif

#ifdef MCALLIB_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "McalLib_MemMap.h"
#endif

#ifdef MCALLIB_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "McalLib_MemMap.h"
#endif

#ifdef MCALLIB_START_SEC_CONST_ASIL_B_GLOBAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "McalLib_MemMap.h"
#endif

#ifdef MCALLIB_STOP_SEC_CONST_ASIL_B_GLOBAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "McalLib_MemMap.h"
#endif

#ifdef MCALLIB_START_SEC_CONST_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "McalLib_MemMap.h"
#endif

#ifdef MCALLIB_STOP_SEC_CONST_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "McalLib_MemMap.h"
#endif

#ifdef MCALLIB_START_SEC_CODE_ASIL_B_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "McalLib_MemMap.h"
#endif

#ifdef MCALLIB_STOP_SEC_CODE_ASIL_B_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "McalLib_MemMap.h"
#endif

#ifdef MCU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Mcu_MemMap.h"
#endif

#ifdef MCU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Mcu_MemMap.h"
#endif

#ifdef MCU_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Mcu_MemMap.h"
#endif

#ifdef MCU_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Mcu_MemMap.h"
#endif

#ifdef MCU_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_16
    #undef MCAL_SECTION_NOT_FOUND
    #include "Mcu_MemMap.h"
#endif

#ifdef MCU_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_16
    #undef MCAL_SECTION_NOT_FOUND
    #include "Mcu_MemMap.h"
#endif

#ifdef MCU_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Mcu_MemMap.h"
#endif

#ifdef MCU_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Mcu_MemMap.h"
#endif

#ifdef MCU_17_TIMERIP_START_SEC_VAR_INIT_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Mcu_MemMap.h"
#endif

#ifdef MCU_17_TIMERIP_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Mcu_MemMap.h"
#endif

#ifdef MCU_17_TIMERIP_START_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Mcu_MemMap.h"
#endif

#ifdef MCU_17_TIMERIP_STOP_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Mcu_MemMap.h"
#endif

#ifdef MCU_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Mcu_MemMap.h"
#endif

#ifdef MCU_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Mcu_MemMap.h"
#endif

#ifdef MCU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Mcu_MemMap.h"
#endif

#ifdef MCU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Mcu_MemMap.h"
#endif

#ifdef MCU_17_TIMERIP_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_16
    #undef MCAL_SECTION_NOT_FOUND
    #include "Mcu_MemMap.h"
#endif

#ifdef MCU_17_TIMERIP_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_16
    #undef MCAL_SECTION_NOT_FOUND
    #include "Mcu_MemMap.h"
#endif

#ifdef MCU_START_SEC_CODE_ASIL_B_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Mcu_MemMap.h"
#endif

#ifdef MCU_STOP_SEC_CODE_ASIL_B_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Mcu_MemMap.h"
#endif

#ifdef MCU_17_TIMERIP_START_SEC_CODE_ASIL_B_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Mcu_MemMap.h"
#endif

#ifdef MCU_17_TIMERIP_STOP_SEC_CODE_ASIL_B_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Mcu_MemMap.h"
#endif

#ifdef MCU_17_TIMERIP_START_SEC_CODE_FAST_ASIL_B_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Mcu_MemMap.h"
#endif

#ifdef MCU_17_TIMERIP_STOP_SEC_CODE_FAST_ASIL_B_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Mcu_MemMap.h"
#endif

#ifdef OCU_START_SEC_VAR_CLEARED_ASIL_B_CORE0_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Ocu_MemMap.h"
#endif

#ifdef OCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Ocu_MemMap.h"
#endif

#ifdef OCU_START_SEC_VAR_CLEARED_ASIL_B_CORE1_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Ocu_MemMap.h"
#endif

#ifdef OCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Ocu_MemMap.h"
#endif

#ifdef OCU_START_SEC_VAR_CLEARED_ASIL_B_CORE2_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Ocu_MemMap.h"
#endif

#ifdef OCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Ocu_MemMap.h"
#endif

#ifdef OCU_START_SEC_VAR_CLEARED_ASIL_B_CORE3_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Ocu_MemMap.h"
#endif

#ifdef OCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Ocu_MemMap.h"
#endif

#ifdef OCU_START_SEC_VAR_CLEARED_ASIL_B_CORE4_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Ocu_MemMap.h"
#endif

#ifdef OCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Ocu_MemMap.h"
#endif

#ifdef OCU_START_SEC_VAR_CLEARED_ASIL_B_CORE5_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Ocu_MemMap.h"
#endif

#ifdef OCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Ocu_MemMap.h"
#endif

#ifdef OCU_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Ocu_MemMap.h"
#endif

#ifdef OCU_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Ocu_MemMap.h"
#endif

#ifdef OCU_START_SEC_CONST_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Ocu_MemMap.h"
#endif

#ifdef OCU_STOP_SEC_CONST_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Ocu_MemMap.h"
#endif

#ifdef OCU_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Ocu_MemMap.h"
#endif

#ifdef OCU_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Ocu_MemMap.h"
#endif

#ifdef OCU_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Ocu_MemMap.h"
#endif

#ifdef OCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Ocu_MemMap.h"
#endif

#ifdef OCU_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Ocu_MemMap.h"
#endif

#ifdef OCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Ocu_MemMap.h"
#endif

#ifdef OCU_START_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Ocu_MemMap.h"
#endif

#ifdef OCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Ocu_MemMap.h"
#endif

#ifdef OCU_START_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Ocu_MemMap.h"
#endif

#ifdef OCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Ocu_MemMap.h"
#endif

#ifdef OCU_START_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Ocu_MemMap.h"
#endif

#ifdef OCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Ocu_MemMap.h"
#endif

#ifdef OCU_START_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Ocu_MemMap.h"
#endif

#ifdef OCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Ocu_MemMap.h"
#endif

#ifdef OCU_START_SEC_CODE_ASIL_B_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Ocu_MemMap.h"
#endif

#ifdef OCU_STOP_SEC_CODE_ASIL_B_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Ocu_MemMap.h"
#endif

#ifdef PORT_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Port_MemMap.h"
#endif

#ifdef PORT_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Port_MemMap.h"
#endif

#ifdef PORT_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Port_MemMap.h"
#endif

#ifdef PORT_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Port_MemMap.h"
#endif

#ifdef PORT_START_SEC_CONST_ASIL_B_GLOBAL_16
    #undef MCAL_SECTION_NOT_FOUND
    #include "Port_MemMap.h"
#endif

#ifdef PORT_STOP_SEC_CONST_ASIL_B_GLOBAL_16
    #undef MCAL_SECTION_NOT_FOUND
    #include "Port_MemMap.h"
#endif

#ifdef PORT_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Port_MemMap.h"
#endif

#ifdef PORT_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Port_MemMap.h"
#endif

#ifdef PORT_START_SEC_CODE_ASIL_B_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Port_MemMap.h"
#endif

#ifdef PORT_STOP_SEC_CODE_ASIL_B_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Port_MemMap.h"
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_CORE0_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Pwm_17_GtmCcu6_MemMap.h"
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Pwm_17_GtmCcu6_MemMap.h"
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_CORE1_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Pwm_17_GtmCcu6_MemMap.h"
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Pwm_17_GtmCcu6_MemMap.h"
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_CORE2_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Pwm_17_GtmCcu6_MemMap.h"
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Pwm_17_GtmCcu6_MemMap.h"
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_CORE3_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Pwm_17_GtmCcu6_MemMap.h"
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Pwm_17_GtmCcu6_MemMap.h"
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_CORE4_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Pwm_17_GtmCcu6_MemMap.h"
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Pwm_17_GtmCcu6_MemMap.h"
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_CORE5_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Pwm_17_GtmCcu6_MemMap.h"
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Pwm_17_GtmCcu6_MemMap.h"
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Pwm_17_GtmCcu6_MemMap.h"
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Pwm_17_GtmCcu6_MemMap.h"
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Pwm_17_GtmCcu6_MemMap.h"
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Pwm_17_GtmCcu6_MemMap.h"
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Pwm_17_GtmCcu6_MemMap.h"
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Pwm_17_GtmCcu6_MemMap.h"
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Pwm_17_GtmCcu6_MemMap.h"
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Pwm_17_GtmCcu6_MemMap.h"
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Pwm_17_GtmCcu6_MemMap.h"
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Pwm_17_GtmCcu6_MemMap.h"
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Pwm_17_GtmCcu6_MemMap.h"
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Pwm_17_GtmCcu6_MemMap.h"
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Pwm_17_GtmCcu6_MemMap.h"
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Pwm_17_GtmCcu6_MemMap.h"
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Pwm_17_GtmCcu6_MemMap.h"
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Pwm_17_GtmCcu6_MemMap.h"
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Pwm_17_GtmCcu6_MemMap.h"
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Pwm_17_GtmCcu6_MemMap.h"
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_CODE_ASIL_B_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Pwm_17_GtmCcu6_MemMap.h"
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_CODE_ASIL_B_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Pwm_17_GtmCcu6_MemMap.h"
#endif

#ifdef PWM_17_GTMCCU6_START_SEC_CODE_FAST_ASIL_B_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Pwm_17_GtmCcu6_MemMap.h"
#endif

#ifdef PWM_17_GTMCCU6_STOP_SEC_CODE_FAST_ASIL_B_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Pwm_17_GtmCcu6_MemMap.h"
#endif

#ifdef SENT_START_SEC_VAR_CLEARED_QM_GLOBAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Sent_MemMap.h"
#endif

#ifdef SENT_STOP_SEC_VAR_CLEARED_QM_GLOBAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Sent_MemMap.h"
#endif

#ifdef SENT_START_SEC_VAR_CLEARED_QM_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Sent_MemMap.h"
#endif

#ifdef SENT_STOP_SEC_VAR_CLEARED_QM_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Sent_MemMap.h"
#endif

#ifdef SENT_START_SEC_CONFIG_DATA_QM_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Sent_MemMap.h"
#endif

#ifdef SENT_STOP_SEC_CONFIG_DATA_QM_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Sent_MemMap.h"
#endif

#ifdef SENT_START_SEC_CONFIG_DATA_QM_CORE0_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Sent_MemMap.h"
#endif

#ifdef SENT_STOP_SEC_CONFIG_DATA_QM_CORE0_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Sent_MemMap.h"
#endif

#ifdef SENT_START_SEC_CONFIG_DATA_QM_CORE1_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Sent_MemMap.h"
#endif

#ifdef SENT_STOP_SEC_CONFIG_DATA_QM_CORE1_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Sent_MemMap.h"
#endif

#ifdef SENT_START_SEC_CONFIG_DATA_QM_CORE2_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Sent_MemMap.h"
#endif

#ifdef SENT_STOP_SEC_CONFIG_DATA_QM_CORE2_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Sent_MemMap.h"
#endif

#ifdef SENT_START_SEC_CONFIG_DATA_QM_CORE3_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Sent_MemMap.h"
#endif

#ifdef SENT_STOP_SEC_CONFIG_DATA_QM_CORE3_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Sent_MemMap.h"
#endif

#ifdef SENT_START_SEC_CONFIG_DATA_QM_CORE4_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Sent_MemMap.h"
#endif

#ifdef SENT_STOP_SEC_CONFIG_DATA_QM_CORE4_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Sent_MemMap.h"
#endif

#ifdef SENT_START_SEC_CONFIG_DATA_QM_CORE5_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Sent_MemMap.h"
#endif

#ifdef SENT_STOP_SEC_CONFIG_DATA_QM_CORE5_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Sent_MemMap.h"
#endif

#ifdef SENT_START_SEC_CODE_QM_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Sent_MemMap.h"
#endif

#ifdef SENT_STOP_SEC_CODE_QM_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Sent_MemMap.h"
#endif

#ifdef SPI_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE0_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE1_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE2_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE3_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE4_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE5_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE0_256
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_256
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE1_256
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_256
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE2_256
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_256
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE3_256
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_256
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE4_256
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_256
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_START_SEC_VAR_CLEARED_ASIL_B_CORE5_256
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_256
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE0_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE1_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE2_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE3_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE4_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE4_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_START_SEC_CONFIG_DATA_ASIL_B_CORE5_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_STOP_SEC_CONFIG_DATA_ASIL_B_CORE5_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_START_SEC_CODE_ASIL_B_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef SPI_STOP_SEC_CODE_ASIL_B_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Spi_MemMap.h"
#endif

#ifdef UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Uart_MemMap.h"
#endif

#ifdef UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Uart_MemMap.h"
#endif

#ifdef UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Uart_MemMap.h"
#endif

#ifdef UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Uart_MemMap.h"
#endif

#ifdef UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Uart_MemMap.h"
#endif

#ifdef UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Uart_MemMap.h"
#endif

#ifdef UART_START_SEC_VAR_INIT_ASIL_B_LOCAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Uart_MemMap.h"
#endif

#ifdef UART_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Uart_MemMap.h"
#endif

#ifdef UART_START_SEC_VAR_INIT_ASIL_B_LOCAL_16
    #undef MCAL_SECTION_NOT_FOUND
    #include "Uart_MemMap.h"
#endif

#ifdef UART_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_16
    #undef MCAL_SECTION_NOT_FOUND
    #include "Uart_MemMap.h"
#endif

#ifdef UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_16
    #undef MCAL_SECTION_NOT_FOUND
    #include "Uart_MemMap.h"
#endif

#ifdef UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_16
    #undef MCAL_SECTION_NOT_FOUND
    #include "Uart_MemMap.h"
#endif

#ifdef UART_START_SEC_CONST_ASIL_B_LOCAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Uart_MemMap.h"
#endif

#ifdef UART_STOP_SEC_CONST_ASIL_B_LOCAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Uart_MemMap.h"
#endif

#ifdef UART_START_SEC_CONST_ASIL_B_LOCAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Uart_MemMap.h"
#endif

#ifdef UART_STOP_SEC_CONST_ASIL_B_LOCAL_8
    #undef MCAL_SECTION_NOT_FOUND
    #include "Uart_MemMap.h"
#endif

#ifdef UART_START_SEC_CONST_ASIL_B_LOCAL_16
    #undef MCAL_SECTION_NOT_FOUND
    #include "Uart_MemMap.h"
#endif

#ifdef UART_STOP_SEC_CONST_ASIL_B_LOCAL_16
    #undef MCAL_SECTION_NOT_FOUND
    #include "Uart_MemMap.h"
#endif

#ifdef UART_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Uart_MemMap.h"
#endif

#ifdef UART_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Uart_MemMap.h"
#endif

#ifdef UART_START_SEC_CODE_ASIL_B_LOCAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Uart_MemMap.h"
#endif

#ifdef UART_STOP_SEC_CODE_ASIL_B_LOCAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Uart_MemMap.h"
#endif

#ifdef WDG_17_SCU_START_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Wdg_17_Scu_MemMap.h"
#endif

#ifdef WDG_17_SCU_STOP_SEC_VAR_CLEARED_ASIL_B_GLOBAL_32
    #undef MCAL_SECTION_NOT_FOUND
    #include "Wdg_17_Scu_MemMap.h"
#endif

#ifdef WDG_17_SCU_START_SEC_VAR_CLEARED_ASIL_B_CORE0_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Wdg_17_Scu_MemMap.h"
#endif

#ifdef WDG_17_SCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE0_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Wdg_17_Scu_MemMap.h"
#endif

#ifdef WDG_17_SCU_START_SEC_VAR_CLEARED_ASIL_B_CORE1_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Wdg_17_Scu_MemMap.h"
#endif

#ifdef WDG_17_SCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE1_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Wdg_17_Scu_MemMap.h"
#endif

#ifdef WDG_17_SCU_START_SEC_VAR_CLEARED_ASIL_B_CORE2_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Wdg_17_Scu_MemMap.h"
#endif

#ifdef WDG_17_SCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE2_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Wdg_17_Scu_MemMap.h"
#endif

#ifdef WDG_17_SCU_START_SEC_VAR_CLEARED_ASIL_B_CORE3_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Wdg_17_Scu_MemMap.h"
#endif

#ifdef WDG_17_SCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE3_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Wdg_17_Scu_MemMap.h"
#endif

#ifdef WDG_17_SCU_START_SEC_VAR_CLEARED_ASIL_B_CORE4_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Wdg_17_Scu_MemMap.h"
#endif

#ifdef WDG_17_SCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE4_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Wdg_17_Scu_MemMap.h"
#endif

#ifdef WDG_17_SCU_START_SEC_VAR_CLEARED_ASIL_B_CORE5_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Wdg_17_Scu_MemMap.h"
#endif

#ifdef WDG_17_SCU_STOP_SEC_VAR_CLEARED_ASIL_B_CORE5_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Wdg_17_Scu_MemMap.h"
#endif

#ifdef WDG_17_SCU_START_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Wdg_17_Scu_MemMap.h"
#endif

#ifdef WDG_17_SCU_STOP_SEC_VAR_INIT_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Wdg_17_Scu_MemMap.h"
#endif

#ifdef WDG_17_SCU_START_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Wdg_17_Scu_MemMap.h"
#endif

#ifdef WDG_17_SCU_STOP_SEC_CONST_ASIL_B_GLOBAL_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Wdg_17_Scu_MemMap.h"
#endif

#ifdef WDG_17_SCU_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Wdg_17_Scu_MemMap.h"
#endif

#ifdef WDG_17_SCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Wdg_17_Scu_MemMap.h"
#endif

#ifdef WDG_17_SCU_START_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Wdg_17_Scu_MemMap.h"
#endif

#ifdef WDG_17_SCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE1_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Wdg_17_Scu_MemMap.h"
#endif

#ifdef WDG_17_SCU_START_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Wdg_17_Scu_MemMap.h"
#endif

#ifdef WDG_17_SCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE2_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Wdg_17_Scu_MemMap.h"
#endif

#ifdef WDG_17_SCU_START_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Wdg_17_Scu_MemMap.h"
#endif

#ifdef WDG_17_SCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE3_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Wdg_17_Scu_MemMap.h"
#endif

#ifdef WDG_17_SCU_START_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Wdg_17_Scu_MemMap.h"
#endif

#ifdef WDG_17_SCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE4_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Wdg_17_Scu_MemMap.h"
#endif

#ifdef WDG_17_SCU_START_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Wdg_17_Scu_MemMap.h"
#endif

#ifdef WDG_17_SCU_STOP_SEC_CONFIG_DATA_ASIL_B_CORE5_UNSPECIFIED
    #undef MCAL_SECTION_NOT_FOUND
    #include "Wdg_17_Scu_MemMap.h"
#endif

#ifdef WDG_17_SCU_START_SEC_CODE_ASIL_B_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Wdg_17_Scu_MemMap.h"
#endif

#ifdef WDG_17_SCU_STOP_SEC_CODE_ASIL_B_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Wdg_17_Scu_MemMap.h"
#endif

#ifdef WDG_17_SCU_START_SEC_CODE_FAST_ASIL_B_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Wdg_17_Scu_MemMap.h"
#endif

#ifdef WDG_17_SCU_STOP_SEC_CODE_FAST_ASIL_B_GLOBAL
    #undef MCAL_SECTION_NOT_FOUND
    #include "Wdg_17_Scu_MemMap.h"
#endif


#ifdef CAN_17_MCMCAN_START_SEC_CODE
  #undef MCAL_SECTION_NOT_FOUND
  #undef CAN_17_MCMCAN_START_SEC_CODE
  #define CAN_17_MCMCAN_START_SEC_CODE_QM_GLOBAL
  #include "Can_17_McmCan_MemMap.h"
#endif
  
#ifdef CAN_17_MCMCAN_STOP_SEC_CODE
  #undef MCAL_SECTION_NOT_FOUND
  #undef CAN_17_MCMCAN_STOP_SEC_CODE
  #define CAN_17_MCMCAN_STOP_SEC_CODE_QM_GLOBAL
  #include "Can_17_McmCan_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_START_SEC_CODE
  #undef MCAL_SECTION_NOT_FOUND
  #undef ETH_17_GETHMAC_START_SEC_CODE
  #define ETH_17_GETHMAC_START_SEC_CODE_QM_GLOBAL
  #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef ETH_17_GETHMAC_STOP_SEC_CODE
  #undef MCAL_SECTION_NOT_FOUND
  #undef ETH_17_GETHMAC_START_SEC_CODE
  #define ETH_17_GETHMAC_START_SEC_CODE_QM_GLOBAL
  #include "Eth_17_GEthMac_MemMap.h"
#endif

#ifdef FEE_START_SEC_CODE
  #undef MCAL_SECTION_NOT_FOUND
  #undef FEE_START_SEC_CODE
  #define FEE_START_SEC_CODE_ASIL_B_LOCAL
  #include "Fee_MemMap.h"
#endif

#ifdef FEE_STOP_SEC_CODE
  #undef MCAL_SECTION_NOT_FOUND
  #undef FEE_STOP_SEC_CODE
  #define FEE_STOP_SEC_CODE_ASIL_B_LOCAL
  #include "Fee_MemMap.h"
#endif

#ifdef FLS_17_DMU_START_SEC_CODE
  #undef MCAL_SECTION_NOT_FOUND
  #undef FLS_17_DMU_START_SEC_CODE
  #define FLS_17_DMU_START_SEC_CODE_ASIL_B_LOCAL
  #include "Fls_17_Dmu_MemMap.h"
#endif

#ifdef FLS_17_DMU_STOP_SEC_CODE
  #undef MCAL_SECTION_NOT_FOUND
  #undef FLS_17_DMU_STOP_SEC_CODE
  #define FLS_17_DMU_STOP_SEC_CODE_ASIL_B_LOCAL
  #include "Fls_17_Dmu_MemMap.h"
#endif


#ifdef MCAL_SECTION_NOT_FOUND
    #define SECTION_NOT_FOUND
#endif

#ifdef __cplusplus
}
#endif

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
