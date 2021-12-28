/*******************************************************************************
**  (C) 2014-2017 HYUNDAI AUTRON Co., Ltd.                                    **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: MemMap.h                                                      **
**                                                                            **
**  TARGET    : MCU(TC2xx, ..) using TASKING complier                         **
**                                                                            **
**  PRODUCT   : AUTOSAR BSW R4.0.3 Modules                                    **
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
** Revision  Date          By     Description                                 **
********************************************************************************
** 1.1.55    06-10-2020    #25914, #25933, #25935, #25914                     **
** 1.1.54    29-09-2020    #25890                                             **
** 1.1.53    09-04-2020    #23450                                             **
** 1.1.48    18-05-2020    #23452                                             **
** 1.1.44    11-11-2019    #20113                                             **
** 1.1.43    25-04-2019    #17252, #17253                                     **
** 1.1.42    26-03-2019    #16335                                             **
** 1.1.41    15-01-2019    #15432                                             **
** 1.1.40    04-01-2019    #15275                                             **
** 1.1.37    04-12-2018    #13737                                             **
** 1.1.36    27-11-2018    #14923                                             **
** 1.1.34    21-09-2018    #14111                                             **
** 1.1.33    17-09-2018    #13924                                             **
** 1.1.32    17-09-2018    #14111                                             **
** 1.1.28    28-06-2018    #13194                                             **
** 1.1.26    20-02-2018    #11714                                             **
** 1.1.24    31-01-2018    #11097                                             **
** 1.1.23    19-01-2018    #11252, #11332                                     **
** 1.1.22    15-01-2018    #11251                                             **
** 1.1.21    12-01-2018    #11120 Add E2EXf Memmap Section                    **
** 1.1.19    26-09-2017    #9885                                              **
** 1.1.18    25-09-2017    #10074                                             **
** 1.1.17    19-09-2017    #9992                                              **
** 1.1.16    08-09-2017    #9878                                              **
** 1.1.15    30-08-2017    #6139                                              **
** 1.1.15    30-08-2017    #6139                                              **
** 1.1.13    11-07-2107    #8576                                              **
** 1.1.12    11-07-2017    #9166                                              **
** 1.1.8     15-05-2017    #8516                                              **
** 1.1.6     04-07-2017    #8078                                              **
** 1.1.5     04-04-2017    #8062, #8063                                       **
** 1.1.4     23-03-2017    #7405                                              **
** 1.1.3     22-03-2017    #7406                                              **
** 1.1.1     07-02-2017    #7348                                              **
** 1.1.0     23-01-2017    #7229                                              **
** 1.0.5     01-12-2016    #6829                                              **
** 1.0.4     29-11-2016    #6781 #6782 #6796                                  **
** 1.0.3     21-11-2016    #5032                                              **
** 1.0.2     15-11-2016    Integrated Memmap for GHS compiler                 **
** 1.0.1     15-11-2016    Integrated Memmap for TASKING compiler             **
** 1.0.0     29-Apr-2014   MJ.Woo Initial Version                             **
*******************************************************************************/

/*******************************************************************************
* PRE-JUSTIFICATION BEGINE SECTION (MISRA-C RULE CHECKER)
* These rules will not be applied for varification based on the MISRA Rule
* in Rte generated source
*******************************************************************************/
/* polyspace:begin<MISRA-C:19.6:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Memory Mapping) */



/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "HwResource.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR specification version information */
#define MEMMAP_AR_MAJOR_VERSION   4
#define MEMMAP_AR_MINOR_VERSION   0
#define MEMMAP_AR_PATCH_VERSION   3

/* File version information */
#define MEMMAP_SW_MAJOR_VERSION   1
#define MEMMAP_SW_MINOR_VERSION   0

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Module section mapping                                **
*******************************************************************************/
/*
 * The symbol 'START_WITH_IF' is undefined.
 *
 * Thus, the preprocessor continues searching for defined symbols.
 * This first #ifdef makes integration of delivered parts of MemMap.h
 * easier because every supplier starts with #elif
 */
#if defined (START_WITH_IF)
/* -------------------------------------------------------------------------- */
/*                                ETHDIAG                                     */
/* -------------------------------------------------------------------------- */
#elif defined (ETHDIAG_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       ETHDIAG_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "ETHDIAG_RAM_VAR_CLEARED_BOOLEAN"
  #pragma clear
  #pragma align 0

#elif defined (ETHDIAG_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       ETHDIAG_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (ETHDIAG_START_SEC_VAR_CLEARED_8)
  #undef       ETHDIAG_START_SEC_VAR_CLEARED_8
  #pragma section all "ETHDIAG_RAM_VAR_CLEARED_8"
  #pragma clear
  #pragma align 0

#elif defined (ETHDIAG_STOP_SEC_VAR_CLEARED_8)
  #undef       ETHDIAG_STOP_SEC_VAR_CLEARED_8
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (ETHDIAG_START_SEC_VAR_CLEARED_16)
  #undef       ETHDIAG_START_SEC_VAR_CLEARED_16
  #pragma section all "ETHDIAG_RAM_VAR_CLEARED_16"
  #pragma clear
  #pragma align 0

#elif defined (ETHDIAG_STOP_SEC_VAR_CLEARED_16)
  #undef       ETHDIAG_STOP_SEC_VAR_CLEARED_16
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (ETHDIAG_START_SEC_VAR_CLEARED_32)
  #undef       ETHDIAG_START_SEC_VAR_CLEARED_32
  #pragma section all "ETHDIAG_RAM_VAR_CLEARED_32"
  #pragma clear
  #pragma align 4

#elif defined (ETHDIAG_STOP_SEC_VAR_CLEARED_32)
  #undef       ETHDIAG_STOP_SEC_VAR_CLEARED_32
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (ETHDIAG_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       ETHDIAG_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "ETHDIAG_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma clear
  #pragma align 4

#elif defined (ETHDIAG_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       ETHDIAG_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (ETHDIAG_START_SEC_CONST_BOOLEAN)
  #undef       ETHDIAG_START_SEC_CONST_BOOLEAN
  #pragma section all "ETHDIAG_ROM_CONST_BOOLEAN"
  #pragma align 0

#elif defined (ETHDIAG_STOP_SEC_CONST_BOOLEAN)
  #undef       ETHDIAG_STOP_SEC_CONST_BOOLEAN
  #pragma align restore
  #pragma section all restore

#elif defined (ETHDIAG_START_SEC_CONST_8)
  #undef       ETHDIAG_START_SEC_CONST_8
  #pragma section all "ETHDIAG_ROM_CONST_8"
  #pragma align 0

#elif defined (ETHDIAG_STOP_SEC_CONST_8)
  #undef       ETHDIAG_STOP_SEC_CONST_8
  #pragma align restore
  #pragma section all restore

#elif defined (ETHDIAG_START_SEC_CONST_16)
  #undef       ETHDIAG_START_SEC_CONST_16
  #pragma section all "ETHDIAG_ROM_CONST_16"
  #pragma align 0  

#elif defined (ETHDIAG_STOP_SEC_CONST_16)
  #undef       ETHDIAG_STOP_SEC_CONST_16
  #pragma align restore
  #pragma section all restore

#elif defined (ETHDIAG_START_SEC_CONST_32)
  #undef       ETHDIAG_START_SEC_CONST_32
  #pragma section all "ETHDIAG_ROM_CONST_32"
  #pragma align 4

#elif defined (ETHDIAG_STOP_SEC_CONST_32)
  #undef       ETHDIAG_STOP_SEC_CONST_32
  #pragma align restore
  #pragma section all restore

#elif defined (ETHDIAG_START_SEC_CONST_UNSPECIFIED)
  #undef       ETHDIAG_START_SEC_CONST_UNSPECIFIED
  #pragma section all "ETHDIAG_ROM_CONST_UNSPECIFIED"
  #pragma align 4
  
#elif defined (ETHDIAG_STOP_SEC_CONST_UNSPECIFIED)
  #undef       ETHDIAG_STOP_SEC_CONST_UNSPECIFIED
  #pragma align restore
  #pragma section all restore

#elif defined (ETHDIAG_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       ETHDIAG_START_SEC_VAR_NO_INIT_BOOLEAN
  #pragma section all "ETHDIAG_RAM_VAR_NO_INIT_BOOLEAN"
  #pragma noclear
  #pragma align 0

#elif defined (ETHDIAG_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       ETHDIAG_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (ETHDIAG_START_SEC_VAR_NO_INIT_8)
  #undef       ETHDIAG_START_SEC_VAR_NO_INIT_8
  #pragma section all "ETHDIAG_RAM_VAR_NO_INIT_8"
  #pragma noclear
  #pragma align 0

#elif defined (ETHDIAG_STOP_SEC_VAR_NO_INIT_8)
  #undef       ETHDIAG_STOP_SEC_VAR_NO_INIT_8
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (ETHDIAG_START_SEC_VAR_NO_INIT_16)
  #undef       ETHDIAG_START_SEC_VAR_NO_INIT_16
  #pragma section all "ETHDIAG_RAM_VAR_NO_INIT_16"
  #pragma noclear
  #pragma align 0

#elif defined (ETHDIAG_STOP_SEC_VAR_NO_INIT_16)
  #undef       ETHDIAG_STOP_SEC_VAR_NO_INIT_16
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (ETHDIAG_START_SEC_VAR_NO_INIT_32)
  #undef       ETHDIAG_START_SEC_VAR_NO_INIT_32
  #pragma section all "ETHDIAG_RAM_VAR_NO_INIT_32"
  #pragma noclear
  #pragma align 4

#elif defined (ETHDIAG_STOP_SEC_VAR_NO_INIT_32)
  #undef       ETHDIAG_STOP_SEC_VAR_NO_INIT_32
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (ETHDIAG_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       ETHDIAG_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "ETHDIAG_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
  #pragma align 4

#elif defined (ETHDIAG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       ETHDIAG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (ETHDIAG_START_SEC_VAR_INIT_BOOLEAN)
  #undef       ETHDIAG_START_SEC_VAR_INIT_BOOLEAN
  #pragma section all "ETHDIAG_RAM_VAR_INIT_BOOLEAN"
  #pragma clear
  #pragma align 0
#elif defined (ETHDIAG_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       ETHDIAG_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (ETHDIAG_START_SEC_VAR_INIT_8)
  #undef       ETHDIAG_START_SEC_VAR_INIT_8
  #pragma section all "ETHDIAG_RAM_VAR_INIT_8"
  #pragma clear
  #pragma align 0
#elif defined (ETHDIAG_STOP_SEC_VAR_INIT_8)
  #undef       ETHDIAG_STOP_SEC_VAR_INIT_8
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (ETHDIAG_START_SEC_VAR_INIT_16)
  #undef       ETHDIAG_START_SEC_VAR_INIT_16
  #pragma section all "ETHDIAG_RAM_VAR_INIT_16"
  #pragma clear
  #pragma align 0
#elif defined (ETHDIAG_STOP_SEC_VAR_INIT_16)
  #undef       ETHDIAG_STOP_SEC_VAR_INIT_16
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (ETHDIAG_START_SEC_VAR_INIT_32)
  #undef       ETHDIAG_START_SEC_VAR_INIT_32
  #pragma section all "ETHDIAG_RAM_VAR_INIT_32"
  #pragma clear
  #pragma align 4
#elif defined (ETHDIAG_STOP_SEC_VAR_INIT_32)
  #undef       ETHDIAG_STOP_SEC_VAR_INIT_32
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (ETHDIAG_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       ETHDIAG_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all "ETHDIAG_RAM_VAR_INIT_UNSPECIFIED"
  #pragma clear
  #pragma align 4
#elif defined (ETHDIAG_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       ETHDIAG_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (ETHDIAG_START_SEC_CODE)
  #undef       ETHDIAG_START_SEC_CODE
  #pragma section code "ETHDIAG_CODE"
  #pragma section farrom "ETHDIAG_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "ETHDIAG_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "ETHDIAG_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (ETHDIAG_STOP_SEC_CODE)
  #undef       ETHDIAG_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

/* -------------------------------------------------------------------------- */
/*                                ATM                                         */
/* -------------------------------------------------------------------------- */
#elif defined (ATM_START_SEC_CONST_8)
  #undef       ATM_START_SEC_CONST_8
  #pragma section all "ATM_ROM_CONST_8"
#elif defined (ATM_STOP_SEC_CONST_8)
  #undef       ATM_STOP_SEC_CONST_8
  #pragma section all restore

#elif defined (ATM_START_SEC_CONST_UNSPECIFIED)
  #undef       ATM_START_SEC_CONST_UNSPECIFIED
  #pragma section all "ATM_ROM_CONST_UNSPECIFIED"
#elif defined (ATM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       ATM_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (ATM_START_SEC_CODE)
  #undef       ATM_START_SEC_CODE
  #pragma section code "ATM_CODE"
  #pragma section farrom "ATM_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "ATM_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "ATM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (ATM_STOP_SEC_CODE)
  #undef       ATM_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

/* -------------------------------------------------------------------------- */
/*                                CANTP                                       */
/* -------------------------------------------------------------------------- */
#elif defined (CANTP_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CANTP_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "CANTP_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (CANTP_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CANTP_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (CANTP_START_SEC_VAR_CLEARED_8)
  #undef       CANTP_START_SEC_VAR_CLEARED_8
  #pragma section all "CANTP_RAM_VAR_CLEARED_8"
#elif defined (CANTP_STOP_SEC_VAR_CLEARED_8)
  #undef       CANTP_STOP_SEC_VAR_CLEARED_8
  #pragma section all restore

#elif defined (CANTP_START_SEC_VAR_CLEARED_16)
  #undef       CANTP_START_SEC_VAR_CLEARED_16
  #pragma section all "CANTP_RAM_VAR_CLEARED_16"
#elif defined (CANTP_STOP_SEC_VAR_CLEARED_16)
  #undef       CANTP_STOP_SEC_VAR_CLEARED_16
  #pragma section all restore

#elif defined (CANTP_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CANTP_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "CANTP_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (CANTP_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CANTP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (CANTP_START_SEC_CONST_8)
  #undef       CANTP_START_SEC_CONST_8
  #pragma section all "CANTP_ROM_CONST_8"
#elif defined (CANTP_STOP_SEC_CONST_8)
  #undef       CANTP_STOP_SEC_CONST_8
  #pragma section all restore

#elif defined (CANTP_START_SEC_CONST_16)
  #undef       CANTP_START_SEC_CONST_16
  #pragma section all "CANTP_ROM_CONST_16"
#elif defined (CANTP_STOP_SEC_CONST_16)
  #undef       CANTP_STOP_SEC_CONST_16
  #pragma section all restore

#elif defined (CANTP_START_SEC_CONST_UNSPECIFIED)
  #undef       CANTP_START_SEC_CONST_UNSPECIFIED
  #pragma section all "CANTP_ROM_CONST_UNSPECIFIED"
#elif defined (CANTP_STOP_SEC_CONST_UNSPECIFIED)
  #undef       CANTP_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (CANTP_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       CANTP_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "CANTP_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#elif defined (CANTP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       CANTP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma clear
  #pragma section all restore

#elif defined (CANTP_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CANTP_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all "CANTP_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (CANTP_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CANTP_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all restore

#elif defined (CANTP_START_SEC_VAR_INIT_BOOLEAN)
  #undef       CANTP_START_SEC_VAR_INIT_BOOLEAN
  #pragma section all "CANTP_RAM_VAR_INIT_BOOLEAN"
#elif defined (CANTP_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       CANTP_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma section all restore

#elif defined (CANTP_START_SEC_VAR_INIT_8)
  #undef       CANTP_START_SEC_VAR_INIT_8
  #pragma section all "CANTP_RAM_VAR_INIT_8"
#elif defined (CANTP_STOP_SEC_VAR_INIT_8)
  #undef       CANTP_STOP_SEC_VAR_INIT_8
  #pragma section all restore

#elif defined (CANTP_START_SEC_VAR_INIT_16)
  #undef       CANTP_START_SEC_VAR_INIT_16
  #pragma section all "CANTP_RAM_VAR_INIT_16"
#elif defined (CANTP_STOP_SEC_VAR_INIT_16)
  #undef       CANTP_STOP_SEC_VAR_INIT_16
  #pragma section all restore

#elif defined (CANTP_START_SEC_CODE)
  #undef       CANTP_START_SEC_CODE
  #pragma section code "CANTP_CODE"
  #pragma section farrom "CANTP_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "CANTP_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "CANTP_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (CANTP_STOP_SEC_CODE)
  #undef       CANTP_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

/* -------------------------------------------------------------------------- */
/*                 DCM                                                      */
/* -------------------------------------------------------------------------- */
#elif defined (DCM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN)
  #undef       DCM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
  #pragma section all "DCM_RAM_VAR_POWER_ON_CLEARED_BOOLEAN"
#elif defined (DCM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN)
  #undef       DCM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (DCM_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       DCM_START_SEC_VAR_NO_INIT_BOOLEAN
  #pragma section all "DCM_RAM_VAR_NO_INIT_BOOLEAN"
  #pragma noclear
#elif defined (DCM_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       DCM_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #pragma clear
  #pragma section all restore

#elif defined (DCM_START_SEC_VAR_NO_INIT_8)
  #undef       DCM_START_SEC_VAR_NO_INIT_8
  #pragma section all "DCM_RAM_VAR_NO_INIT_8"
  #pragma noclear
#elif defined (DCM_STOP_SEC_VAR_NO_INIT_8)
  #undef       DCM_STOP_SEC_VAR_NO_INIT_8
  #pragma clear
  #pragma section all restore

#elif defined (DCM_START_SEC_VAR_NO_INIT_16)
  #undef       DCM_START_SEC_VAR_NO_INIT_16
  #pragma section all "DCM_RAM_VAR_NO_INIT_16"
  #pragma noclear
#elif defined (DCM_STOP_SEC_VAR_NO_INIT_16)
  #undef       DCM_STOP_SEC_VAR_NO_INIT_16
  #pragma clear
  #pragma section all restore

#elif defined (DCM_START_SEC_VAR_NO_INIT_32)
  #undef       DCM_START_SEC_VAR_NO_INIT_32
  #pragma section all "DCM_RAM_VAR_NO_INIT_32"
  #pragma noclear
#elif defined (DCM_STOP_SEC_VAR_NO_INIT_32)
  #undef       DCM_STOP_SEC_VAR_NO_INIT_32
  #pragma clear
  #pragma section all restore

#elif defined (DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "DCM_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#elif defined (DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma clear
  #pragma section all restore

#elif defined (DCM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       DCM_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "DCM_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (DCM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       DCM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (DCM_START_SEC_VAR_CLEARED_8)
  #undef       DCM_START_SEC_VAR_CLEARED_8
  #pragma section all "DCM_RAM_VAR_CLEARED_8"
#elif defined (DCM_STOP_SEC_VAR_CLEARED_8)
  #undef       DCM_STOP_SEC_VAR_CLEARED_8
  #pragma section all restore

#elif defined (DCM_START_SEC_VAR_CLEARED_16)
  #undef       DCM_START_SEC_VAR_CLEARED_16
  #pragma section all "DCM_RAM_VAR_CLEARED_16"
#elif defined (DCM_STOP_SEC_VAR_CLEARED_16)
  #undef       DCM_STOP_SEC_VAR_CLEARED_16
  #pragma section all restore

#elif defined (DCM_START_SEC_VAR_CLEARED_32)
  #undef       DCM_START_SEC_VAR_CLEARED_32
  #pragma section all "DCM_RAM_VAR_CLEARED_32"
#elif defined (DCM_STOP_SEC_VAR_CLEARED_32)
  #undef       DCM_STOP_SEC_VAR_CLEARED_32
  #pragma section all restore

#elif defined (DCM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       DCM_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "DCM_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       DCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (DCM_START_SEC_VAR_INIT_BOOLEAN)
  #undef       DCM_START_SEC_VAR_INIT_BOOLEAN
  #pragma section all "DCM_RAM_VAR_INIT_BOOLEAN"
#elif defined (DCM_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       DCM_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma section all restore

#elif defined (DCM_START_SEC_VAR_INIT_8)
  #undef       DCM_START_SEC_VAR_INIT_8
  #pragma section all "DCM_RAM_VAR_INIT_8"
#elif defined (DCM_STOP_SEC_VAR_INIT_8)
  #undef       DCM_STOP_SEC_VAR_INIT_8
  #pragma section all restore

#elif defined (DCM_START_SEC_VAR_INIT_16)
  #undef       DCM_START_SEC_VAR_INIT_16
  #pragma section all "DCM_RAM_VAR_INIT_16"
#elif defined (DCM_STOP_SEC_VAR_INIT_16)
  #undef       DCM_STOP_SEC_VAR_INIT_16
  #pragma section all restore

#elif defined (DCM_START_SEC_VAR_INIT_32)
  #undef       DCM_START_SEC_VAR_INIT_32
  #pragma section all "DCM_RAM_VAR_INIT_32"
#elif defined (DCM_STOP_SEC_VAR_INIT_32)
  #undef       DCM_STOP_SEC_VAR_INIT_32
  #pragma section all restore

#elif defined (DCM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       DCM_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all "DCM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (DCM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       DCM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all restore

#elif defined (DCM_START_SEC_CONST_BOOLEAN)
  #undef       DCM_START_SEC_CONST_BOOLEAN
  #pragma section all "DCM_ROM_CONST_BOOLEAN"
#elif defined (DCM_STOP_SEC_CONST_BOOLEAN)
  #undef       DCM_STOP_SEC_CONST_BOOLEAN
  #pragma section all restore

#elif defined (DCM_START_SEC_CONST_8)
  #undef       DCM_START_SEC_CONST_8
  #pragma section all "DCM_ROM_CONST_8"
#elif defined (DCM_STOP_SEC_CONST_8)
  #undef       DCM_STOP_SEC_CONST_8
  #pragma section all restore

#elif defined (DCM_START_SEC_CONST_16)
  #undef       DCM_START_SEC_CONST_16
  #pragma section all "DCM_ROM_CONST_16"
#elif defined (DCM_STOP_SEC_CONST_16)
  #undef       DCM_STOP_SEC_CONST_16
  #pragma section all restore

#elif defined (DCM_START_SEC_CONST_UNSPECIFIED)
  #undef       DCM_START_SEC_CONST_UNSPECIFIED
  #pragma section all "DCM_ROM_CONST_UNSPECIFIED"
#elif defined (DCM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       DCM_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (DCM_START_SEC_CODE)
  #undef       DCM_START_SEC_CODE
  #pragma section code "DCM_CODE"
  #pragma section farrom "DCM_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "DCM_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "DCM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (DCM_STOP_SEC_CODE)
  #undef       DCM_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (DCM_START_SEC_CALLOUT_CODE)
  #undef       DCM_START_SEC_CALLOUT_CODE
  #pragma section code "DCM_CODE"
  #pragma section farrom "DCM_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "DCM_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "DCM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (DCM_STOP_SEC_CALLOUT_CODE)
  #undef       DCM_STOP_SEC_CALLOUT_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

/* -------------------------------------------------------------------------- */
/*             Dem                                                           */
/* -------------------------------------------------------------------------- */
#elif defined (DEM_START_SEC_CONST_BOOLEAN)
  #undef       DEM_START_SEC_CONST_BOOLEAN
  #pragma section all "DEM_ROM_CONST_BOOLEAN"
#elif defined (DEM_STOP_SEC_CONST_BOOLEAN)
  #undef       DEM_STOP_SEC_CONST_BOOLEAN
  #pragma section all restore

#elif defined (DEM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       DEM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
  #pragma section all "DEM_RAM_VAR_POWER_ON_CLEARED_UNSPECIFIED"
  #pragma noclear
#elif defined (DEM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       DEM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
  #pragma clear
  #pragma section all restore

#elif defined (DEM_START_SEC_VAR_CLEARED_8)
  #undef       DEM_START_SEC_VAR_CLEARED_8
  #pragma section all "DEM_RAM_VAR_CLEARED_8"
#elif defined (DEM_STOP_SEC_VAR_CLEARED_8)
  #undef       DEM_STOP_SEC_VAR_CLEARED_8
  #pragma section all restore

#elif defined (DEM_START_SEC_VAR_CLEARED_16)
  #undef       DEM_START_SEC_VAR_CLEARED_16
  #pragma section all "DEM_RAM_VAR_CLEARED_16"
#elif defined (DEM_STOP_SEC_VAR_CLEARED_16)
  #undef       DEM_STOP_SEC_VAR_CLEARED_16
  #pragma section all restore

#elif defined (DEM_START_SEC_VAR_CLEARED_32)
  #undef       DEM_START_SEC_VAR_CLEARED_32
  #pragma section all "DEM_RAM_VAR_CLEARED_32"
#elif defined (DEM_STOP_SEC_VAR_CLEARED_32)
  #undef       DEM_STOP_SEC_VAR_CLEARED_32
  #pragma section all restore

#elif defined (DEM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       DEM_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "DEM_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (DEM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       DEM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (DEM_START_SEC_VAR_NO_INIT_8)
  #undef       DEM_START_SEC_VAR_NO_INIT_8
  #pragma section all "DEM_RAM_VAR_NO_INIT_8"
  #pragma noclear
#elif defined (DEM_STOP_SEC_VAR_NO_INIT_8)
  #undef       DEM_STOP_SEC_VAR_NO_INIT_8
  #pragma clear
  #pragma section all restore

#elif defined (DEM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef DEM_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all "DEM_RAM_VAR_INIT_UNSPECIFIED"
  #pragma noclear

#elif defined (DEM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef DEM_STOP_SEC_VAR_INIT_UNSPECIFIED

  #pragma section all restore

#elif defined (DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "DEM_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#elif defined (DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma clear
  #pragma section all restore

#elif defined (DEM_START_SEC_CONST_UNSPECIFIED)
  #undef       DEM_START_SEC_CONST_UNSPECIFIED
  #pragma section all "DEM_ROM_CONST_UNSPECIFIED"
#elif defined (DEM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       DEM_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (DEM_START_SEC_CODE)
  #undef       DEM_START_SEC_CODE
  #pragma section code "DEM_CODE"
  #pragma section farrom "DEM_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "DEM_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "DEM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (DEM_STOP_SEC_CODE)
  #undef       DEM_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (DEM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef DEM_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "DEM_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (DEM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef DEM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore
/* -------------------------------------------------------------------------- */
/*                              Det                                           */
/* -------------------------------------------------------------------------- */
#elif defined (DET_START_SEC_VAR_NO_INIT_16)
  #undef       DET_START_SEC_VAR_NO_INIT_16
  #pragma section all "DET_RAM_VAR_NO_INIT_16"
  #pragma noclear
#elif defined (DET_STOP_SEC_VAR_NO_INIT_16)
  #undef       DET_STOP_SEC_VAR_NO_INIT_16
  #pragma clear
  #pragma section all restore

#elif defined (DET_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       DET_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "DET_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (DET_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       DET_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (DET_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       DET_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "DET_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (DET_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       DET_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (DET_START_SEC_CONST_UNSPECIFIED)
  #undef       DET_START_SEC_CONST_UNSPECIFIED
  #pragma section all "DET_ROM_CONST_UNSPECIFIED"
#elif defined (DET_STOP_SEC_CONST_UNSPECIFIED)
  #undef       DET_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (DET_START_SEC_CODE)
  #undef       DET_START_SEC_CODE
  #pragma section code "DET_CODE"
  #pragma section farrom "DET_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "DET_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "DET_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (DET_STOP_SEC_CODE)
  #undef       DET_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

/* -------------------------------------------------------------------------- */
/*                                 E2E                                        */
/* -------------------------------------------------------------------------- */

#elif defined (E2E_START_SEC_CODE)
  #undef       E2E_START_SEC_CODE
  #pragma section code "E2E_CODE"
  #pragma section farrom "E2E_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "E2E_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "E2E_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (E2E_STOP_SEC_CODE)
  #undef       E2E_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore
#elif defined (E2E_START_SEC_CODE_ASIL_D)
  #undef       E2E_START_SEC_CODE_ASIL_D
  #pragma section code "E2E_CODE"
  #pragma section farrom "E2E_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "E2E_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "E2E_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (E2E_STOP_SEC_CODE_ASIL_D)
  #undef       E2E_STOP_SEC_CODE_ASIL_D
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

/* -------------------------------------------------------------------------- */
/*                             E2EXf                                          */
/* -------------------------------------------------------------------------- */

#elif defined (E2EXF_START_SEC_VAR_INIT_BOOLEAN)
  #undef       E2EXF_START_SEC_VAR_INIT_BOOLEAN
  #pragma section all "E2EXF_RAM_VAR_INIT_BOOLEAN"
#elif defined (E2EXF_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       E2EXF_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma section all restore

#elif defined (E2EXF_START_SEC_VAR_INIT_ASIL_D_BOOLEAN)
  #undef       E2EXF_START_SEC_VAR_INIT_ASIL_D_BOOLEAN
  #pragma section all "E2EXF_RAM_VAR_INIT_BOOLEAN"
#elif defined (E2EXF_STOP_SEC_VAR_INIT_ASIL_D_BOOLEAN)
  #undef       E2EXF_STOP_SEC_VAR_INIT_ASIL_D_BOOLEAN
  #pragma section all restore

#elif defined (E2EXF_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       E2EXF_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "E2EXF_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#elif defined (E2EXF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       E2EXF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma clear
  #pragma section all restore

#elif defined (E2EXF_START_SEC_VAR_NO_INIT_ASIL_D_UNSPECIFIED)
  #undef       E2EXF_START_SEC_VAR_NO_INIT_ASIL_D_UNSPECIFIED
  #pragma section all "E2EXF_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#elif defined (E2EXF_STOP_SEC_VAR_NO_INIT_ASIL_D_UNSPECIFIED)
  #undef       E2EXF_STOP_SEC_VAR_NO_INIT_ASIL_D_UNSPECIFIED
  #pragma clear
  #pragma section all restore
  
#elif defined (E2EXF_START_SEC_VAR_NO_INIT_ASIL_D_PTR)
  #undef       E2EXF_START_SEC_VAR_NO_INIT_ASIL_D_PTR
  #pragma section all "E2EXF_RAM_VAR_NO_INIT_PTR"
  #pragma noclear
#elif defined (E2EXF_STOP_SEC_VAR_NO_INIT_ASIL_D_PTR)
  #undef       E2EXF_STOP_SEC_VAR_NO_INIT_ASIL_D_PTR
  #pragma clear
  #pragma section all restore

#elif defined (E2EXF_START_SEC_VAR_NO_INIT_ASIL_D_8)
  #undef       E2EXF_START_SEC_VAR_NO_INIT_ASIL_D_8
  #pragma section all "E2EXF_RAM_VAR_NO_INIT_8"
  #pragma noclear
#elif defined (E2EXF_STOP_SEC_VAR_NO_INIT_ASIL_D_8)
  #undef       E2EXF_STOP_SEC_VAR_NO_INIT_ASIL_D_8
  #pragma clear
  #pragma section all restore
  
#elif defined (E2EXF_START_SEC_CONST_UNSPECIFIED)
  #undef       E2EXF_START_SEC_CONST_UNSPECIFIED
  #pragma section all "E2EXF_ROM_CONST_UNSPECIFIED"
#elif defined (E2EXF_STOP_SEC_CONST_UNSPECIFIED)
  #undef       E2EXF_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore
  
#elif defined (E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED)
  #undef       E2EXF_START_SEC_CONST_ASIL_D_UNSPECIFIED
  #pragma section all "E2EXF_ROM_CONST_UNSPECIFIED"
#elif defined (E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED)
  #undef       E2EXF_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
  #pragma section all restore
  
#elif defined (E2EXF_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED)
  #undef       E2EXF_START_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
  #pragma section all "E2EXF_ROM_CONST_UNSPECIFIED"
#elif defined (E2EXF_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED)
  #undef       E2EXF_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_D_UNSPECIFIED
  #pragma section all restore

#elif defined (E2EXF_START_SEC_CODE)
  #undef       E2EXF_START_SEC_CODE
  #pragma section code "E2EXF_CODE"
  #pragma section farrom "E2EXF_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "E2EXF_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "E2EXF_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (E2EXF_STOP_SEC_CODE)
  #undef       E2EXF_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (E2EXF_START_SEC_CODE_ASIL_D)
  #undef       E2EXF_START_SEC_CODE_ASIL_D
  #pragma section code "E2EXF_CODE"
  #pragma section farrom "E2EXF_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "E2EXF_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "E2EXF_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (E2EXF_STOP_SEC_CODE_ASIL_D)
  #undef       E2EXF_STOP_SEC_CODE_ASIL_D
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore
  
/* -------------------------------------------------------------------------- */
/*                             SomeIpXf                                       */
/* -------------------------------------------------------------------------- */
#elif defined (SOMEIPXF_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef      SOMEIPXF_START_SEC_VAR_NO_INIT_BOOLEAN
  #pragma section all "SOMEIPXF_RAM_VAR_NO_INIT_BOOLEAN"
  #pragma noclear
#elif defined (SOMEIPXF_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef      SOMEIPXF_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #pragma clear
  #pragma section all restore

#elif defined (SOMEIPXF_START_SEC_VAR_NO_INIT_8)
  #undef      SOMEIPXF_START_SEC_VAR_NO_INIT_8
  #pragma section all "SOMEIPXF_RAM_VAR_NO_INIT_8"
  #pragma noclear
#elif defined (SOMEIPXF_STOP_SEC_VAR_NO_INIT_8)
  #pragma clear
  #pragma section all restore

#elif defined (SOMEIPXF_START_SEC_VAR_NO_INIT_16)
  #undef      SOMEIPXF_START_SEC_VAR_NO_INIT_16
  #pragma section all "SOMEIPXF_RAM_VAR_NO_INIT_16"
  #pragma noclear
#elif defined (SOMEIPXF_STOP_SEC_VAR_NO_INIT_16)
  #undef      SOMEIPXF_STOP_SEC_VAR_NO_INIT_16
  #pragma clear
  #pragma section all restore

#elif defined (SOMEIPXF_START_SEC_VAR_NO_INIT_32)
  #undef      SOMEIPXF_START_SEC_VAR_NO_INIT_32
  #pragma section all "SOMEIPXF_RAM_VAR_NO_INIT_32"
  #pragma noclear
#elif defined (SOMEIPXF_STOP_SEC_VAR_NO_INIT_32)
  #undef      SOMEIPXF_STOP_SEC_VAR_NO_INIT_32
  #pragma clear
  #pragma section all restore

#elif defined (SOMEIPXF_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef      SOMEIPXF_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "SOMEIPXF_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#elif defined (SOMEIPXF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #pragma clear
  #pragma section all restore

#elif defined (SOMEIPXF_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef      SOMEIPXF_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "SOMEIPXF_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (SOMEIPXF_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef      SOMEIPXF_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (SOMEIPXF_START_SEC_VAR_CLEARED_8)
  #undef      SOMEIPXF_START_SEC_VAR_CLEARED_8
  #pragma section all "SOMEIPXF_RAM_VAR_CLEARED_8"
#elif defined (SOMEIPXF_STOP_SEC_VAR_CLEARED_8)
  #undef      SOMEIPXF_STOP_SEC_VAR_CLEARED_8
  #pragma section all restore

#elif defined (SOMEIPXF_START_SEC_VAR_CLEARED_16)
  #undef      SOMEIPXF_START_SEC_VAR_CLEARED_16
  #pragma section all "SOMEIPXF_RAM_VAR_CLEARED_16"
#elif defined (SOMEIPXF_STOP_SEC_VAR_CLEARED_16)
  #undef      SOMEIPXF_STOP_SEC_VAR_CLEARED_16
  #pragma section all restore

#elif defined (SOMEIPXF_START_SEC_VAR_CLEARED_32)
  #undef      SOMEIPXF_START_SEC_VAR_CLEARED_32
  #pragma section all "SOMEIPXF_RAM_VAR_CLEARED_32"
#elif defined (SOMEIPXF_STOP_SEC_VAR_CLEARED_32)
  #undef      SOMEIPXF_STOP_SEC_VAR_CLEARED_32
  #pragma section all restore

#elif defined (SOMEIPXF_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef      SOMEIPXF_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "SOMEIPXF_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (SOMEIPXF_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef      SOMEIPXF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (SOMEIPXF_START_SEC_VAR_INIT_BOOLEAN)
  #undef      SOMEIPXF_START_SEC_VAR_INIT_BOOLEAN
 #pragma section all "SOMEIPXF_RAM_VAR_INIT_BOOLEAN"
#elif defined (SOMEIPXF_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef      SOMEIPXF_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma section all restore

#elif defined (SOMEIPXF_START_SEC_VAR_INIT_8)
  #undef      SOMEIPXF_START_SEC_VAR_INIT_8
  #pragma section all "SOMEIPXF_RAM_VAR_INIT_8"
#elif defined (SOMEIPXF_STOP_SEC_VAR_INIT_8)
  #undef      SOMEIPXF_STOP_SEC_VAR_INIT_8
  #pragma section all restore

#elif defined (SOMEIPXF_START_SEC_VAR_INIT_16)
  #undef      SOMEIPXF_START_SEC_VAR_INIT_16
  #pragma section all "SOMEIPXF_RAM_VAR_INIT_16"
#elif defined (SOMEIPXF_STOP_SEC_VAR_INIT_16)
  #undef      SOMEIPXF_STOP_SEC_VAR_INIT_16
  #pragma section all restore

#elif defined (SOMEIPXF_START_SEC_VAR_INIT_32)
  #undef      SOMEIPXF_START_SEC_VAR_INIT_32
  #pragma section all "SOMEIPXF_RAM_VAR_INIT_32"
#elif defined (SOMEIPXF_STOP_SEC_VAR_INIT_32)
  #undef      SOMEIPXF_STOP_SEC_VAR_INIT_32
  #pragma section all restore

#elif defined (SOMEIPXF_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef      SOMEIPXF_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all "SOMEIPXF_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (SOMEIPXF_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef      SOMEIPXF_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all restore

#elif defined (SOMEIPXF_START_SEC_CONST_BOOLEAN)
  #undef      SOMEIPXF_START_SEC_CONST_BOOLEAN
  #pragma section all "SOMEIPXF_ROM_CONST_BOOLEAN"
#elif defined (SOMEIPXF_STOP_SEC_CONST_BOOLEAN)
  #undef      SOMEIPXF_STOP_SEC_CONST_BOOLEAN
  #pragma section all restore

#elif defined (SOMEIPXF_START_SEC_CONST_8)
  #undef      SOMEIPXF_START_SEC_CONST_8
  #pragma section all "SOMEIPXF_ROM_CONST_8"
#elif defined (SOMEIPXF_STOP_SEC_CONST_8)
  #undef      SOMEIPXF_STOP_SEC_CONST_8
  #pragma section all restore

#elif defined (SOMEIPXF_START_SEC_CONST_16)
  #undef      SOMEIPXF_START_SEC_CONST_16
  #pragma section all "SOMEIPXF_ROM_CONST_16"
#elif defined (SOMEIPXF_STOP_SEC_CONST_16)
  #undef      SOMEIPXF_STOP_SEC_CONST_16
  #pragma section all restore

#elif defined (SOMEIPXF_START_SEC_CONST_UNSPECIFIED)
  #undef      SOMEIPXF_START_SEC_CONST_UNSPECIFIED
  #pragma section all "SOMEIPXF_ROM_CONST_UNSPECIFIED"
#elif defined (SOMEIPXF_STOP_SEC_CONST_UNSPECIFIED)
  #undef      SOMEIPXF_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (SOMEIPXF_START_SEC_CODE)
  #undef      SOMEIPXF_START_SEC_CODE
  #pragma section code "SOMEIPXF_CODE"
  #pragma section farrom "SOMEIPXF_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "SOMEIPXF_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "SOMEIPXF_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (SOMEIPXF_STOP_SEC_CODE)
  #undef      SOMEIPXF_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (SOMEIPXF_START_SEC_CALLOUT_CODE)
  #undef      SOMEIPXF_START_SEC_CALLOUT_CODE
  #pragma section code "SOMEIPXF_CALLOUT_CODE"
  #pragma section farrom "SOMEIPXF_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "SOMEIPXF_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "SOMEIPXF_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (SOMEIPXF_STOP_SEC_CALLOUT_CODE)
  #undef      SOMEIPXF_STOP_SEC_CALLOUT_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (SOMEIPXF_START_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED)
  #undef      SOMEIPXF_START_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED
  #pragma section all "SOMEIPXF_ROM_DBTOC_CONST_UNSPECIFIED"
#elif defined (SOMEIPXF_STOP_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED)
  #undef      SOMEIPXF_STOP_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED
  #pragma section all restore

/* -------------------------------------------------------------------------- */
/*                 RegMon                                                     */
/* -------------------------------------------------------------------------- */
#elif defined (REGMON_START_SEC_CODE)
  #undef       REGMON_START_SEC_CODE
  #pragma section code "REGMON_CODE"
  #pragma section farrom "REGMON_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "REGMON_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "REGMON_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (REGMON_STOP_SEC_CODE)
  #undef       REGMON_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (REGMON_START_SEC_VAR_UNSPECIFIED)
  #undef       REGMON_START_SEC_VAR_UNSPECIFIED
  #pragma section all "REGMON_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (REGMON_STOP_SEC_VAR_UNSPECIFIED)
  #undef       REGMON_STOP_SEC_VAR_UNSPECIFIED
  #pragma section all restore

#elif defined (REGMON_START_SEC_CONST_UNSPECIFIED)
  #undef       REGMON_START_SEC_CONST_UNSPECIFIED
  #pragma section all "REGMON_ROM_CONST_UNSPECIFIED"
#elif defined (REGMON_STOP_SEC_CONST_UNSPECIFIED)
  #undef       REGMON_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

/* -------------------------------------------------------------------------- */
/*                                 OS                                         */
/* -------------------------------------------------------------------------- */

#elif defined (OS_START_SEC_VAR_NO_INIT_8)
  #undef       OS_START_SEC_VAR_NO_INIT_8
  #pragma section all "OS_RAM_VAR_NO_INIT_8"
  #pragma noclear
#elif defined (OS_STOP_SEC_VAR_NO_INIT_8)
  #undef       OS_STOP_SEC_VAR_NO_INIT_8
  #pragma clear
  #pragma section all restore

#elif defined (OS_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       OS_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "OS_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#elif defined (OS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       OS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma clear
  #pragma section all restore

#elif defined (OS_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       OS_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "OS_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (OS_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       OS_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (OS_START_SEC_VAR_CLEARED_8)
  #undef       OS_START_SEC_VAR_CLEARED_8
  #pragma section all "OS_RAM_VAR_CLEARED_8"
#elif defined (OS_STOP_SEC_VAR_CLEARED_8)
  #undef       OS_STOP_SEC_VAR_CLEARED_8
  #pragma section all restore

#elif defined (OS_START_SEC_VAR_CLEARED_16)
  #undef       OS_START_SEC_VAR_CLEARED_16
  #pragma section all "OS_RAM_VAR_CLEARED_16"
#elif defined (OS_STOP_SEC_VAR_CLEARED_16)
  #undef       OS_STOP_SEC_VAR_CLEARED_16
  #pragma section all restore

#elif defined (OS_START_SEC_VAR_CLEARED_32)
  #undef       OS_START_SEC_VAR_CLEARED_32
  #pragma section all "OS_RAM_VAR_CLEARED_32"
  #pragma align 4
#elif defined (OS_STOP_SEC_VAR_CLEARED_32)
  #undef       OS_STOP_SEC_VAR_CLEARED_32
  #pragma align restore
  #pragma section all restore

#elif defined (OS_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OS_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "OS_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (OS_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (OS_START_SEC_SAFETY_VAR_CLEARED_UNSPECIFIED)
  #undef       OS_START_SEC_SAFETY_VAR_CLEARED_UNSPECIFIED
  #pragma section all "OS_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (OS_STOP_SEC_SAFETY_VAR_CLEARED_UNSPECIFIED)
  #undef       OS_STOP_SEC_SAFETY_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (OS_START_SEC_STACK_CORE0_CLEARED_UNSPECIFIED)
  #undef       OS_START_SEC_STACK_CORE0_CLEARED_UNSPECIFIED
  #pragma section all "OS_RAM_STACK_CORE0_CLEARED_UNSPECIFIED"
#elif defined (OS_STOP_SEC_STACK_CORE0_CLEARED_UNSPECIFIED)
  #undef       OS_STOP_SEC_STACK_CORE0_CLEARED_UNSPECIFIED
  #pragma section all restore
  
#elif defined (OS_START_SEC_STACK_CORE1_CLEARED_UNSPECIFIED)
  #undef       OS_START_SEC_STACK_CORE1_CLEARED_UNSPECIFIED
  #pragma section all "OS_RAM_STACK_CORE1_CLEARED_UNSPECIFIED"
#elif defined (OS_STOP_SEC_STACK_CORE1_CLEARED_UNSPECIFIED)
  #undef       OS_STOP_SEC_STACK_CORE1_CLEARED_UNSPECIFIED
  #pragma section all restore
  
#elif defined (OS_START_SEC_STACK_CORE2_CLEARED_UNSPECIFIED)
  #undef       OS_START_SEC_STACK_CORE2_CLEARED_UNSPECIFIED
  #pragma section all "OS_RAM_STACK_CORE2_CLEARED_UNSPECIFIED"
#elif defined (OS_STOP_SEC_STACK_CORE2_CLEARED_UNSPECIFIED)
  #undef       OS_STOP_SEC_STACK_CORE2_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (OS_START_SEC_STACK_CORE3_CLEARED_UNSPECIFIED)
  #undef       OS_START_SEC_STACK_CORE3_CLEARED_UNSPECIFIED
  #pragma section all "OS_RAM_STACK_CORE3_CLEARED_UNSPECIFIED"
#elif defined (OS_STOP_SEC_STACK_CORE3_CLEARED_UNSPECIFIED)
  #undef       OS_STOP_SEC_STACK_CORE3_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (OS_START_SEC_STACK_CORE4_CLEARED_UNSPECIFIED)
  #undef       OS_START_SEC_STACK_CORE4_CLEARED_UNSPECIFIED
  #pragma section all "OS_RAM_STACK_CORE4_CLEARED_UNSPECIFIED"
#elif defined (OS_STOP_SEC_STACK_CORE4_CLEARED_UNSPECIFIED)
  #undef       OS_STOP_SEC_STACK_CORE4_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (OS_START_SEC_STACK_CORE5_CLEARED_UNSPECIFIED)
  #undef       OS_START_SEC_STACK_CORE5_CLEARED_UNSPECIFIED
  #pragma section all "OS_RAM_STACK_CORE5_CLEARED_UNSPECIFIED"
#elif defined (OS_STOP_SEC_STACK_CORE5_CLEARED_UNSPECIFIED)
  #undef       OS_STOP_SEC_STACK_CORE5_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (OS_START_SEC_VAR_INIT_32)
  #undef       OS_START_SEC_VAR_INIT_32
  #pragma section all "OS_RAM_VAR_INIT_32"
  #pragma align 4
#elif defined (OS_STOP_SEC_VAR_INIT_32)
  #undef       OS_STOP_SEC_VAR_INIT_32
  #pragma align restore
  #pragma section all restore

#elif defined (OS_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       OS_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all "OS_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (OS_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       OS_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all restore

#elif defined (OS_START_SEC_CONST_32)
  #undef       OS_START_SEC_CONST_32
  #pragma section all "OS_ROM_CONST_32"
  #pragma align 4
#elif defined (OS_STOP_SEC_CONST_32)
  #undef       OS_STOP_SEC_CONST_32
  #pragma align restore
  #pragma section all restore

#elif defined (OS_START_SEC_CONST_UNSPECIFIED)
  #undef       OS_START_SEC_CONST_UNSPECIFIED
  #pragma section all "OS_ROM_CONST_UNSPECIFIED"
#elif defined (OS_STOP_SEC_CONST_UNSPECIFIED)
  #undef       OS_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (OS_START_SEC_CODE)
  #undef       OS_START_SEC_CODE
  #pragma section code "OS_CODE"
  #pragma section farrom "OS_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "OS_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "OS_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (OS_STOP_SEC_CODE)
  #undef       OS_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (OS_START_SEC_API_CODE)
  #undef       OS_START_SEC_API_CODE
  #pragma section all "OS_API_CODE"
  #pragma warning 545
#elif defined (OS_STOP_SEC_API_CODE)
  #undef       OS_STOP_SEC_API_CODE
  #pragma warning restore
  #pragma section all restore

#elif defined (OS_START_SEC_SAFETY_CODE)
  #undef       OS_START_SEC_SAFETY_CODE
  #pragma section code "OS_SAFETY_CODE"
  #pragma section farrom "OS_ROM_SAFETY_CONST_UNSPECIFIED"
  #pragma section farbss "OS_RAM_SAFETY_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "OS_RAM_SAFETY_VAR_INIT_UNSPECIFIED"
#elif defined (OS_STOP_SEC_SAFETY_CODE)
  #undef       OS_STOP_SEC_SAFETY_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

/* OS IOC - INIT_UNSPECIFIED */
#elif defined (IOC_START_SEC_VAR_INIT_CORE0_UNSPECIFIED)
  #undef       IOC_START_SEC_VAR_INIT_CORE0_UNSPECIFIED
  #pragma section all "IOC_RAM_VAR_INIT_CORE0_UNSPECIFIED"
#elif defined (IOC_STOP_SEC_VAR_INIT_CORE0_UNSPECIFIED)
  #undef       IOC_STOP_SEC_VAR_INIT_CORE0_UNSPECIFIED
  #pragma section all restore
#elif defined (IOC_START_SEC_VAR_INIT_CORE1_UNSPECIFIED)
  #undef       IOC_START_SEC_VAR_INIT_CORE1_UNSPECIFIED
  #pragma section all "IOC_RAM_VAR_INIT_CORE1_UNSPECIFIED"
#elif defined (IOC_STOP_SEC_VAR_INIT_CORE1_UNSPECIFIED)
  #undef       IOC_STOP_SEC_VAR_INIT_CORE1_UNSPECIFIED
  #pragma section all restore
#elif defined (IOC_START_SEC_VAR_INIT_CORE2_UNSPECIFIED)
  #undef       IOC_START_SEC_VAR_INIT_CORE2_UNSPECIFIED
  #pragma section all "IOC_RAM_VAR_INIT_CORE2_UNSPECIFIED"
#elif defined (IOC_STOP_SEC_VAR_INIT_CORE2_UNSPECIFIED)
  #undef       IOC_STOP_SEC_VAR_INIT_CORE2_UNSPECIFIED
  #pragma section all restore
#elif defined (IOC_START_SEC_VAR_INIT_CORE3_UNSPECIFIED)
  #undef       IOC_START_SEC_VAR_INIT_CORE3_UNSPECIFIED
  #pragma section all "IOC_RAM_VAR_INIT_CORE3_UNSPECIFIED"
#elif defined (IOC_STOP_SEC_VAR_INIT_CORE3_UNSPECIFIED)
  #undef       IOC_STOP_SEC_VAR_INIT_CORE3_UNSPECIFIED
  #pragma section all restore
#elif defined (IOC_START_SEC_VAR_INIT_CORE4_UNSPECIFIED)
  #undef       IOC_START_SEC_VAR_INIT_CORE4_UNSPECIFIED
  #pragma section all "IOC_RAM_VAR_INIT_CORE4_UNSPECIFIED"
#elif defined (IOC_STOP_SEC_VAR_INIT_CORE4_UNSPECIFIED)
  #undef       IOC_STOP_SEC_VAR_INIT_CORE4_UNSPECIFIED
  #pragma section all restore
#elif defined (IOC_START_SEC_VAR_INIT_CORE5_UNSPECIFIED)
  #undef       IOC_START_SEC_VAR_INIT_CORE5_UNSPECIFIED
  #pragma section all "IOC_RAM_VAR_INIT_CORE5_UNSPECIFIED"
#elif defined (IOC_STOP_SEC_VAR_INIT_CORE5_UNSPECIFIED)
  #undef       IOC_STOP_SEC_VAR_INIT_CORE5_UNSPECIFIED
  #pragma section all restore

#elif defined (IOC_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       IOC_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all "IOC_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (IOC_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       IOC_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all restore

/* OS IOC - NO_INIT_UNSPECIFIED */
#elif defined (IOC_START_SEC_VAR_NO_INIT_CORE0_UNSPECIFIED)
  #undef       IOC_START_SEC_VAR_NO_INIT_CORE0_UNSPECIFIED
  #pragma section all "IOC_RAM_VAR_NO_INIT_CORE0_UNSPECIFIED"
  #pragma noclear
#elif defined (IOC_STOP_SEC_VAR_NO_INIT_CORE0_UNSPECIFIED)
  #undef       IOC_STOP_SEC_VAR_NO_INIT_CORE0_UNSPECIFIED
  #pragma clear
  #pragma section all restore
#elif defined (IOC_START_SEC_VAR_NO_INIT_CORE1_UNSPECIFIED)
  #undef       IOC_START_SEC_VAR_NO_INIT_CORE1_UNSPECIFIED
  #pragma section all "IOC_RAM_VAR_NO_INIT_CORE1_UNSPECIFIED"
  #pragma noclear
#elif defined (IOC_STOP_SEC_VAR_NO_INIT_CORE1_UNSPECIFIED)
  #undef       IOC_STOP_SEC_VAR_NO_INIT_CORE1_UNSPECIFIED
  #pragma clear
  #pragma section all restore
#elif defined (IOC_START_SEC_VAR_NO_INIT_CORE2_UNSPECIFIED)
  #undef       IOC_START_SEC_VAR_NO_INIT_CORE2_UNSPECIFIED
  #pragma section all "IOC_RAM_VAR_NO_INIT_CORE2_UNSPECIFIED"
  #pragma noclear
#elif defined (IOC_STOP_SEC_VAR_NO_INIT_CORE2_UNSPECIFIED)
  #undef       IOC_STOP_SEC_VAR_NO_INIT_CORE2_UNSPECIFIED
  #pragma clear
  #pragma section all restore
#elif defined (IOC_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       IOC_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "IOC_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#elif defined (IOC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       IOC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma clear
  #pragma section all restore

/* -------------------------------------------------------------------------- */
/*                 LinSM                                                      */
/* -------------------------------------------------------------------------- */
#elif defined (LINSM_START_SEC_CONST_UNSPECIFIED)
  #undef       LINSM_START_SEC_CONST_UNSPECIFIED
  #pragma section all "LINSM_ROM_CONST_UNSPECIFIED"
#elif defined (LINSM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       LINSM_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (LINSM_START_SEC_CONST_8)
  #undef       LINSM_START_SEC_CONST_8
  #pragma section all "LINSM_ROM_CONST_8"
#elif defined (LINSM_STOP_SEC_CONST_8)
  #undef       LINSM_STOP_SEC_CONST_8
  #pragma section all restore

#elif defined (LINSM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       LINSM_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "LINSM_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (LINSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       LINSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (LINSM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINSM_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "LINSM_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (LINSM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINSM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (LINSM_START_SEC_VAR_CLEARED_8)
  #undef       LINSM_START_SEC_VAR_CLEARED_8
  #pragma section all "LINSM_RAM_VAR_CLEARED_8"
#elif defined (LINSM_STOP_SEC_VAR_CLEARED_8)
  #undef       LINSM_STOP_SEC_VAR_CLEARED_8
  #pragma section all restore

#elif defined (LINSM_START_SEC_CODE)
  #undef       LINSM_START_SEC_CODE
  #pragma section code "LINSM_CODE"
  #pragma section farrom "LINSM_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "LINSM_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "LINSM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (LINSM_STOP_SEC_CODE)
  #undef       LINSM_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore


/* -------------------------------------------------------------------------- */
/*                 LinTrcv                                                      */
/* -------------------------------------------------------------------------- */
#elif defined (LINTRCV_START_SEC_CONST_UNSPECIFIED)
  #undef       LINTRCV_START_SEC_CONST_UNSPECIFIED
  #pragma section all "LINTRCV_ROM_CONST_UNSPECIFIED"
#elif defined (LINTRCV_STOP_SEC_CONST_UNSPECIFIED)
  #undef       LINTRCV_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (LINTRCV_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       LINTRCV_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "LINTRCV_RAM_VAR_NO_INIT_UNSPECIFIED"
#elif defined (LINTRCV_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       LINTRCV_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all restore

#elif defined (LINTRCV_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINTRCV_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "LINTRCV_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (LINTRCV_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINTRCV_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (LINTRCV_START_SEC_CODE)
  #undef       LINTRCV_START_SEC_CODE
  #pragma section code "LINTRCV_CODE"
  #pragma section farrom "LINTRCV_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "LINTRCV_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "LINTRCV_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (LINTRCV_STOP_SEC_CODE)
  #undef       LINTRCV_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (LINTRCV_7259GE_START_SEC_CONST_UNSPECIFIED)
  #undef       LINTRCV_7259GE_START_SEC_CONST_UNSPECIFIED
  #pragma section all "LINTRCV_ROM_CONST_UNSPECIFIED"
#elif defined (LINTRCV_7259GE_STOP_SEC_CONST_UNSPECIFIED)
  #undef       LINTRCV_7259GE_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (LINTRCV_7259GE_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       LINTRCV_7259GE_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "LINTRCV_RAM_VAR_NO_INIT_UNSPECIFIED"
#elif defined (LINTRCV_7259GE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       LINTRCV_7259GE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all restore

#elif defined (LINTRCV_7259GE_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINTRCV_7259GE_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "LINTRCV_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (LINTRCV_7259GE_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINTRCV_7259GE_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (LINTRCV_7259GE_START_SEC_CODE)
  #undef       LINTRCV_7259GE_START_SEC_CODE
  #pragma section code "LINTRCV_CODE"
  #pragma section farrom "LINTRCV_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "LINTRCV_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "LINTRCV_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (LINTRCV_7259GE_STOP_SEC_CODE)
  #undef       LINTRCV_7259GE_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

/* -------------------------------------------------------------------------- */
/*                             LinNm                                          */
/* -------------------------------------------------------------------------- */
#elif defined (LINNM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINNM_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "LINNM_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (LINNM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINNM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (LINNM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       LINNM_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "LINNM_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#elif defined (LINNM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       LINNM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma clear
  #pragma section all restore

#elif defined (LINNM_START_SEC_CONST_UNSPECIFIED)
  #undef       LINNM_START_SEC_CONST_UNSPECIFIED
  #pragma section all "LINNM_ROM_CONST_UNSPECIFIED"
#elif defined (LINNM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       LINNM_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (LINNM_START_SEC_CODE)
  #undef       LINNM_START_SEC_CODE
  #pragma section code "LINNM_CODE"
  #pragma section farrom "LINNM_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "LINNM_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "LINNM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (LINNM_STOP_SEC_CODE)
  #undef       LINNM_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

/* -------------------------------------------------------------------------- */
/*             FiM                                                            */
/* -------------------------------------------------------------------------- */

#elif defined (FIM_START_SEC_CODE)
  #undef       FIM_START_SEC_CODE
  #pragma section code "FIM_CODE"
  #pragma section farrom "FIM_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "FIM_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "FIM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (FIM_STOP_SEC_CODE)
  #undef       FIM_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (FIM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       FIM_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "FIM_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#elif defined (FIM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       FIM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma clear
  #pragma section all restore

#elif defined (FIM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       FIM_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "FIM_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (FIM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       FIM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (FIM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       FIM_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "FIM_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (FIM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       FIM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (FIM_START_SEC_CONST_UNSPECIFIED)
  #undef       FIM_START_SEC_CONST_UNSPECIFIED
  #pragma section all "FIM_ROM_CONST_UNSPECIFIED"
#elif defined (FIM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       FIM_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore


/* -------------------------------------------------------------------------- */
/*                 FRSM                                                       */
/* -------------------------------------------------------------------------- */
#elif defined (FRSM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       FRSM_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "FRSM_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (FRSM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       FRSM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

  #elif defined (FRSM_START_SEC_VAR_CLEARED_8)
  #undef       FRSM_START_SEC_VAR_CLEARED_8
  #pragma section all "FRSM_RAM_VAR_CLEARED_8"
#elif defined (FRSM_STOP_SEC_VAR_CLEARED_8)
  #undef       FRSM_STOP_SEC_VAR_CLEARED_8
  #pragma section all restore

#elif defined (FRSM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       FRSM_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "FRSM_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (FRSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       FRSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (FRSM_START_SEC_VAR_NO_INIT_8)
  #undef       FRSM_START_SEC_VAR_NO_INIT_8
  #pragma section all "FRSM_RAM_VAR_NO_INIT_8"
  #pragma noclear
#elif defined (FRSM_STOP_SEC_VAR_NO_INIT_8)
  #undef       FRSM_STOP_SEC_VAR_NO_INIT_8
  #pragma clear
  #pragma section all restore

#elif defined (FRSM_START_SEC_CONST_UNSPECIFIED)
  #undef       FRSM_START_SEC_CONST_UNSPECIFIED
  #pragma section all "FRSM_ROM_CONST_UNSPECIFIED"
#elif defined (FRSM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       FRSM_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (FRSM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       FRSM_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "FRSM_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#elif defined (FRSM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       FRSM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma clear
  #pragma section all restore

#elif defined (FRSM_START_SEC_CODE)
  #undef       FRSM_START_SEC_CODE
  #pragma section code "FRSM_CODE"
  #pragma section farrom "FRSM_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "FRSM_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "FRSM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (FRSM_STOP_SEC_CODE)
  #undef       FRSM_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

/* -------------------------------------------------------------------------- */
/*             FrIf                                                           */
/* -------------------------------------------------------------------------- */
#elif defined (FRIF_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       FRIF_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "FRIF_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (FRIF_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       FRIF_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (FRIF_START_SEC_CONST_UNSPECIFIED)
  #undef       FRIF_START_SEC_CONST_UNSPECIFIED
  #pragma section all "FRIF_ROM_CONST_UNSPECIFIED"
#elif defined (FRIF_STOP_SEC_CONST_UNSPECIFIED)
  #undef       FRIF_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (FRIF_START_SEC_VAR_NO_INIT_8)
  #undef       FRIF_START_SEC_VAR_NO_INIT_8
  #pragma section all "FRIF_RAM_VAR_NO_INIT_8"
  #pragma noclear
#elif defined (FRIF_STOP_SEC_VAR_NO_INIT_8)
  #undef       FRIF_STOP_SEC_VAR_NO_INIT_8
  #pragma clear
  #pragma section all restore

#elif defined (FRIF_START_SEC_VAR_NO_INIT_8)
  #undef       FRIF_START_SEC_VAR_NO_INIT_8
  #pragma section all "FRIF_RAM_VAR_NO_INIT_8"
  #pragma noclear
#elif defined (FRIF_STOP_SEC_VAR_NO_INIT_8)
  #undef       FRIF_STOP_SEC_VAR_NO_INIT_8
  #pragma clear
  #pragma section all restore

#elif defined (FRIF_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       FRIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "FRIF_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#elif defined (FRIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       FRIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma clear
  #pragma section all restore

#elif defined (FRIF_START_SEC_VAR_CLEARED_16)
  #undef       FRIF_START_SEC_VAR_CLEARED_16
  #pragma section all "FRIF_RAM_VAR_CLEARED_16"
#elif defined (FRIF_STOP_SEC_VAR_CLEARED_16)
  #undef       FRIF_STOP_SEC_VAR_CLEARED_16
  #pragma section all restore

#elif defined (FRIF_START_SEC_CONST_8)
  #undef       FRIF_START_SEC_CONST_8
  #pragma section all "FRIF_ROM_CONST_8"
#elif defined (FRIF_STOP_SEC_CONST_8)
  #undef       FRIF_STOP_SEC_CONST_8
  #pragma section all restore

#elif defined (FRIF_START_SEC_CONST_UNSPECIFIED)
  #undef       FRIF_START_SEC_CONST_UNSPECIFIED
  #pragma section all "FRIF_ROM_CONST_UNSPECIFIED"
#elif defined (FRIF_STOP_SEC_CONST_UNSPECIFIED)
  #undef       FRIF_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (FRIF_START_SEC_CODE)
  #undef       FRIF_START_SEC_CODE
  #pragma section code "FRIF_CODE"
  #pragma section farrom "FRIF_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "FRIF_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "FRIF_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (FRIF_STOP_SEC_CODE)
  #undef       FRIF_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

/* -------------------------------------------------------------------------- */
/*                 CANIF                                                      */
/* -------------------------------------------------------------------------- */
#elif defined (CANIF_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CANIF_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "CANIF_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (CANIF_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CANIF_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (CANIF_START_SEC_VAR_CLEARED_8)
  #undef       CANIF_START_SEC_VAR_CLEARED_8
  #pragma section all "CANIF_RAM_VAR_CLEARED_8"
#elif defined (CANIF_STOP_SEC_VAR_CLEARED_8)
  #undef       CANIF_STOP_SEC_VAR_CLEARED_8
  #pragma section all restore

#elif defined (CANIF_START_SEC_VAR_NO_INIT_8)
  #undef       CANIF_START_SEC_VAR_NO_INIT_8
  #pragma section all "CANIF_RAM_VAR_NO_INIT_8"
  #pragma noclear
#elif defined (CANIF_STOP_SEC_VAR_NO_INIT_8)
  #undef       CANIF_STOP_SEC_VAR_NO_INIT_8
  #pragma clear
  #pragma section all restore

#elif defined (CANIF_START_SEC_CONST_8)
  #undef       CANIF_START_SEC_CONST_8
  #pragma section all "CANIF_ROM_CONST_8"
#elif defined (CANIF_STOP_SEC_CONST_8)
  #undef       CANIF_STOP_SEC_CONST_8
  #pragma section all restore

 #elif defined (CANIF_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CANIF_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all "CANIF_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all restore

#elif defined (CANIF_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       CANIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "CANIF_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#elif defined (CANIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       CANIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma clear
  #pragma section all restore

#elif defined (CANIF_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CANIF_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "CANIF_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (CANIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CANIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (CANIF_START_SEC_CONST_UNSPECIFIED)
  #undef       CANIF_START_SEC_CONST_UNSPECIFIED
  #pragma section all "CANIF_ROM_CONST_UNSPECIFIED"
#elif defined (CANIF_STOP_SEC_CONST_UNSPECIFIED)
  #undef       CANIF_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

 #elif defined (CANIF_START_SEC_CODE)
  #undef        CANIF_START_SEC_CODE
  #pragma section code "CANIF_CODE"
  #pragma section farrom "CANIF_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "CANIF_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "CANIF_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (CANIF_STOP_SEC_CODE)
  #undef       CANIF_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

/* -------------------------------------------------------------------------- */
/*                 CANTRCV                                                    */
/* -------------------------------------------------------------------------- */

#elif defined (CANTRCV_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CANTRCV_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "CANTRCV_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (CANTRCV_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CANTRCV_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (CANTRCV_START_SEC_VAR_CLEARED_8)
  #undef       CANTRCV_START_SEC_VAR_CLEARED_8
  #pragma section all "CANTRCV_RAM_VAR_CLEARED_8"
#elif defined (CANTRCV_STOP_SEC_VAR_CLEARED_8)
  #undef       CANTRCV_STOP_SEC_VAR_CLEARED_8
  #pragma section all restore

#elif defined (CANTRCV_START_SEC_VAR_CLEARED_16)
  #undef       CANTRCV_START_SEC_VAR_CLEARED_16
  #pragma section all "CANTRCV_RAM_VAR_CLEARED_16"
#elif defined (CANTRCV_STOP_SEC_VAR_CLEARED_16)
  #undef       CANTRCV_STOP_SEC_VAR_CLEARED_16
  #pragma section all restore

#elif defined (CANTRCV_START_SEC_VAR_CLEARED_32)
  #undef       CANTRCV_START_SEC_VAR_CLEARED_32
  #pragma section all "CANTRCV_RAM_VAR_CLEARED_32"
#elif defined (CANTRCV_STOP_SEC_VAR_CLEARED_32)
  #undef       CANTRCV_STOP_SEC_VAR_CLEARED_32
  #pragma section all restore

#elif defined (CANTRCV_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CANTRCV_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "CANTRCV_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (CANTRCV_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CANTRCV_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (CANTRCV_START_SEC_VAR_UNSPECIFIED)
  #undef       CANTRCV_START_SEC_VAR_UNSPECIFIED
  #pragma section all "CANTRCV_RAM_VAR_UNSPECIFIED"
#elif defined (CANTRCV_STOP_SEC_VAR_UNSPECIFIED)
  #undef       CANTRCV_STOP_SEC_VAR_UNSPECIFIED
  #pragma section all restore

#elif defined (CANTRCV_START_SEC_CONST_8)
  #undef       CANTRCV_START_SEC_CONST_8
  #pragma section all "CANTRCV_ROM_CONST_8"
#elif defined (CANTRCV_STOP_SEC_CONST_8)
  #undef       CANTRCV_STOP_SEC_CONST_8
  #pragma section all restore

#elif defined (CANTRCV_START_SEC_CONST_16)
  #undef       CANTRCV_START_SEC_CONST_16
  #pragma section all "CANTRCV_ROM_CONST_16"
#elif defined (CANTRCV_STOP_SEC_CONST_16)
  #undef       CANTRCV_STOP_SEC_CONST_16
  #pragma section all restore

#elif defined (CANTRCV_START_SEC_CONST_UNSPECIFIED)
  #undef       CANTRCV_START_SEC_CONST_UNSPECIFIED
  #pragma section all "CANTRCV_ROM_CONST_UNSPECIFIED"
#elif defined (CANTRCV_STOP_SEC_CONST_UNSPECIFIED)
  #undef       CANTRCV_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (CANTRCV_START_SEC_CODE)
  #undef       CANTRCV_START_SEC_CODE
  #pragma section code "CANTRCV_CODE"
  #pragma section farrom "CANTRCV_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "CANTRCV_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "CANTRCV_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (CANTRCV_STOP_SEC_CODE)
  #undef       CANTRCV_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (CANTRCV_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CANTRCV_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all "CANTRCV_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (CANTRCV_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CANTRCV_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all restore

#elif defined (CANTRCV_START_SEC_VAR_INIT_BOOLEAN)
  #undef       CANTRCV_START_SEC_VAR_INIT_BOOLEAN
  #pragma section all "CANTRCV_RAM_VAR_INIT_BOOLEAN"
#elif defined (CANTRCV_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       CANTRCV_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma section all restore

#elif defined (CANTRCV_START_SEC_VAR_INIT_8)
  #undef       CANTRCV_START_SEC_VAR_INIT_8
  #pragma section all "CANTRCV_RAM_VAR_INIT_8"
#elif defined (CANTRCV_STOP_SEC_VAR_INIT_8)
  #undef       CANTRCV_STOP_SEC_VAR_INIT_8
  #pragma section all restore

#elif defined (CANTRCV_START_SEC_VAR_INIT_16)
  #undef       CANTRCV_START_SEC_VAR_INIT_16
  #pragma section all "CANTRCV_RAM_VAR_INIT_16"
#elif defined (CANTRCV_STOP_SEC_VAR_INIT_16)
  #undef       CANTRCV_STOP_SEC_VAR_INIT_16
  #pragma section all restore

/* -------------------------------------------------------------------------- */
/*                 BswM                                                       */
/* -------------------------------------------------------------------------- */

#elif defined (BSWM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       BSWM_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "BSWM_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (BSWM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       BSWM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (BSWM_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       BSWM_START_SEC_VAR_NO_INIT_BOOLEAN
  #pragma section all "BSWM_RAM_VAR_NO_INIT_BOOLEAN"
  #pragma noclear
#elif defined (BSWM_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       BSWM_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #pragma clear
  #pragma section all restore

#elif defined (BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       BSWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "BSWM_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#elif defined (BSWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       BSWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma clear
  #pragma section all restore

#elif defined (BSWM_START_SEC_CONST_UNSPECIFIED)
  #undef       BSWM_START_SEC_CONST_UNSPECIFIED
  #pragma section all "BSWM_ROM_CONST_UNSPECIFIED"
#elif defined (BSWM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       BSWM_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (BSWM_START_SEC_CODE)
  #undef       BSWM_START_SEC_CODE
  #pragma section code "BSWM_CODE"
  #pragma section farrom "BSWM_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "BSWM_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "BSWM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (BSWM_STOP_SEC_CODE)
  #undef       BSWM_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "BSWM_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore

/* -------------------------------------------------------------------------- */
/*             ComM                                                           */
/* -------------------------------------------------------------------------- */
#elif defined (COMM_START_SEC_VAR_POWER_ON_CLEARED_8)
  #undef       COMM_START_SEC_VAR_POWER_ON_CLEARED_8
  #pragma section all "COMM_RAM_VAR_POWER_ON_CLEARED_8"
#elif defined (COMM_STOP_SEC_VAR_POWER_ON_CLEARED_8)
  #undef       COMM_STOP_SEC_VAR_POWER_ON_CLEARED_8
  #pragma section all restore

#elif defined (COMM_START_SEC_VAR_POWER_ON_CLEARED_16)
  #undef       COMM_START_SEC_VAR_POWER_ON_CLEARED_16
  #pragma section all "COMM_RAM_VAR_POWER_ON_CLEARED_16"
#elif defined (COMM_STOP_SEC_VAR_POWER_ON_CLEARED_16)
  #undef       COMM_STOP_SEC_VAR_POWER_ON_CLEARED_16
  #pragma section all restore

#elif defined (COMM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       COMM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
  #pragma section all "COMM_RAM_VAR_POWER_ON_CLEARED_UNSPECIFIED"
#elif defined (COMM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       COMM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (COMM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN)
  #undef       COMM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
  #pragma section all "COMM_RAM_VAR_POWER_ON_CLEARED_BOOLEAN"
#elif defined (COMM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN)
  #undef       COMM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (COMM_START_SEC_VAR_CLEARED_8)
  #undef       COMM_START_SEC_VAR_CLEARED_8
  #pragma section all "COMM_RAM_VAR_CLEARED_8"
#elif defined (COMM_STOP_SEC_VAR_CLEARED_8)
  #undef       COMM_STOP_SEC_VAR_CLEARED_8
  #pragma section all restore

#elif defined (COMM_START_SEC_VAR_CLEARED_16)
  #undef       COMM_START_SEC_VAR_CLEARED_16
  #pragma section all "COMM_RAM_VAR_CLEARED_16"
#elif defined (COMM_STOP_SEC_VAR_CLEARED_16)
  #undef       COMM_STOP_SEC_VAR_CLEARED_16
  #pragma section all restore

#elif defined (COMM_START_SEC_VAR_CLEARED_32)
  #undef       COMM_START_SEC_VAR_CLEARED_32
  #pragma section all "COMM_RAM_VAR_CLEARED_32"
#elif defined (COMM_STOP_SEC_VAR_CLEARED_32)
  #undef       COMM_STOP_SEC_VAR_CLEARED_32
  #pragma section all restore

#elif defined (COMM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       COMM_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "COMM_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (COMM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       COMM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (COMM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       COMM_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "COMM_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (COMM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       COMM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (COMM_START_SEC_VAR_NO_INIT_8)
  #undef       COMM_START_SEC_VAR_NO_INIT_8
  #pragma section all "COMM_RAM_VAR_NO_INIT_8"
  #pragma noclear
#elif defined (COMM_STOP_SEC_VAR_NO_INIT_8)
  #undef       COMM_STOP_SEC_VAR_NO_INIT_8
  #pragma clear
  #pragma section all restore

#elif defined (COMM_START_SEC_VAR_NO_INIT_16)
  #undef       COMM_START_SEC_VAR_NO_INIT_16
  #pragma section all "COMM_RAM_VAR_NO_INIT_16"
  #pragma noclear
#elif defined (COMM_STOP_SEC_VAR_NO_INIT_16)
  #undef       COMM_STOP_SEC_VAR_NO_INIT_16
  #pragma clear
  #pragma section all restore

#elif defined (COMM_START_SEC_VAR_NO_INIT_32)
  #undef       COMM_START_SEC_VAR_NO_INIT_32
  #pragma section all "COMM_RAM_VAR_NO_INIT_32"
  #pragma noclear
#elif defined (COMM_STOP_SEC_VAR_NO_INIT_32)
  #undef       COMM_STOP_SEC_VAR_NO_INIT_32
  #pragma clear
  #pragma section all restore

#elif defined (COMM_START_SEC_VAR_SAVED_ZONE_16)
  #undef       COMM_START_SEC_VAR_SAVED_ZONE_16
  #pragma section all "COMM_RAM_VAR_SAVED_ZONE_16"
  #pragma noclear
#elif defined (COMM_STOP_SEC_VAR_SAVED_ZONE_16)
  #undef       COMM_STOP_SEC_VAR_SAVED_ZONE_16
  #pragma clear
  #pragma section all restore

#elif defined (COMM_START_SEC_VAR_SAVED_ZONE_8)
  #undef       COMM_START_SEC_VAR_SAVED_ZONE_8
  #pragma section all "COMM_RAM_VAR_SAVED_ZONE_8"
  #pragma noclear
#elif defined (COMM_STOP_SEC_VAR_SAVED_ZONE_8)
  #undef       COMM_STOP_SEC_VAR_SAVED_ZONE_8
  #pragma clear
  #pragma section all restore

#elif defined (COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       COMM_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "COMM_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#elif defined (COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       COMM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma clear
  #pragma section all restore

#elif defined (COMM_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
  #undef       COMM_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
  #pragma section all "COMM_RAM_VAR_SAVED_ZONE_UNSPECIFIED"
  #pragma noclear
#elif defined (COMM_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
  #undef       COMM_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
  #pragma clear
  #pragma section all restore

#elif defined (COMM_START_SEC_CONST_8)
  #undef       COMM_START_SEC_CONST_8
  #pragma section all "COMM_ROM_CONST_8"
#elif defined (COMM_STOP_SEC_CONST_8)
  #undef       COMM_STOP_SEC_CONST_8
  #pragma section all restore

#elif defined (COMM_START_SEC_CONST_UNSPECIFIED)
  #undef       COMM_START_SEC_CONST_UNSPECIFIED
  #pragma section all "COMM_ROM_CONST_UNSPECIFIED"
#elif defined (COMM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       COMM_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (COMM_START_SEC_CODE)
  #undef       COMM_START_SEC_CODE
  #pragma section code "COMM_CODE"
  #pragma section farrom "COMM_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "COMM_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "COMM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (COMM_STOP_SEC_CODE)
  #undef       COMM_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

/* -------------------------------------------------------------------------- */
/*             LINIF                                                          */
/* -------------------------------------------------------------------------- */
#elif defined (LINIF_START_SEC_CODE)
  #undef       LINIF_START_SEC_CODE
  #pragma section code "LINIF_CODE"
  #pragma section farrom "LINIF_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "LINIF_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "LINIF_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (LINIF_STOP_SEC_CODE)
  #undef       LINIF_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (LINIF_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINIF_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "LINIF_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (LINIF_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINIF_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (LINIF_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       LINIF_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "LINIF_RAM_VAR_NO_INIT_UNSPECIFIED"
#elif defined (LINIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       LINIF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all restore

#elif defined (LINIF_START_SEC_CONST_UNSPECIFIED)
  #undef       LINIF_START_SEC_CONST_UNSPECIFIED
  #pragma section all "LINIF_ROM_CONST_UNSPECIFIED"
#elif defined (LINIF_STOP_SEC_CONST_UNSPECIFIED)
  #undef       LINIF_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (LINIF_START_SEC_DBTOC_CONST_UNSPECIFIED)
  #undef       LINIF_START_SEC_DBTOC_CONST_UNSPECIFIED
  #pragma section all "LINIF_ROM_CONFIG_UNSPECIFIED"
#elif defined (LINIF_STOP_SEC_DBTOC_CONST_UNSPECIFIED)
  #undef       LINIF_STOP_SEC_DBTOC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (LINIF_START_SEC_CONST_8)
  #undef       LINIF_START_SEC_CONST_8
  #pragma section all "LINIF_ROM_CONST_8"
#elif defined (LINIF_STOP_SEC_CONST_8)
  #undef       LINIF_STOP_SEC_CONST_8
  #pragma section all restore

#elif defined (LINIF_START_SEC_CONST_UNSPECIFIED)
  #undef       LINIF_START_SEC_CONST_UNSPECIFIED
  #pragma section all "LINIF_ROM_CONFIG_UNSPECIFIED"
#elif defined (LINIF_STOP_SEC_CONST_UNSPECIFIED)
  #undef       LINIF_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (LINIF_START_SEC_VAR_NO_INIT_8)
  #undef       LINIF_START_SEC_VAR_NO_INIT_8
  #pragma section all "LINIF_RAM_VAR_NO_INIT_8"
#elif defined (LINIF_STOP_SEC_VAR_NO_INIT_8)
  #undef       LINIF_STOP_SEC_VAR_NO_INIT_8
  #pragma section all restore

/* -------------------------------------------------------------------------- */
/*             LINTP                                                          */
/* -------------------------------------------------------------------------- */

#elif defined (LINTP_START_SEC_CODE)
  #undef       LINTP_START_SEC_CODE
  #pragma section code "LINTP_CODE"
  #pragma section farrom "LINTP_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "LINTP_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "LINTP_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (LINTP_STOP_SEC_CODE)
  #undef       LINTP_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (LINTP_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINTP_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "LINTP_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (LINTP_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       LINTP_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (LINTP_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       LINTP_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "LINTP_RAM_VAR_NO_INIT_UNSPECIFIED"
#elif defined (LINTP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       LINTP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all restore

#elif defined (LINTP_START_SEC_VAR_CLEARED_16)
  #undef       LINTP_START_SEC_VAR_CLEARED_16
  #pragma section all "LINTP_RAM_VAR_CLEARED_16"
#elif defined (LINTP_STOP_SEC_VAR_CLEARED_16)
  #undef       LINTP_STOP_SEC_VAR_CLEARED_16
  #pragma section all restore

#elif defined (LINTP_START_SEC_VAR_NO_INIT_8)
  #undef       LINTP_START_SEC_VAR_NO_INIT_8
  #pragma section all "LINTP_RAM_VAR_NO_INIT_8"
#elif defined (LINTP_STOP_SEC_VAR_NO_INIT_8)
  #undef       LINTP_STOP_SEC_VAR_NO_INIT_8
  #pragma section all restore

#elif defined (LINTP_START_SEC_DBTOC_CONST_UNSPECIFIED)
  #undef       LINTP_START_SEC_DBTOC_CONST_UNSPECIFIED
  #pragma section all "LINTP_ROM_CONFIG_UNSPECIFIED"
#elif defined (LINTP_STOP_SEC_DBTOC_CONST_UNSPECIFIED)
  #undef       LINTP_STOP_SEC_DBTOC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (LINTP_START_SEC_CONST_UNSPECIFIED)
  #undef       LINTP_START_SEC_CONST_UNSPECIFIED
  #pragma section all "LINTP_ROM_CONFIG_UNSPECIFIED"
#elif defined (LINTP_STOP_SEC_CONST_UNSPECIFIED)
  #undef       LINTP_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

/* -------------------------------------------------------------------------- */
/*             Com                                                            */
/* -------------------------------------------------------------------------- */

#elif defined (COM_START_SEC_VAR_POWER_ON_CLEARED_8)
  #undef       COM_START_SEC_VAR_POWER_ON_CLEARED_8
  #pragma section all "COM_RAM_VAR_POWER_ON_CLEARED_8"
#elif defined (COM_STOP_SEC_VAR_POWER_ON_CLEARED_8)
  #undef       COM_STOP_SEC_VAR_POWER_ON_CLEARED_8
  #pragma section all restore

#elif defined (COM_START_SEC_VAR_POWER_ON_CLEARED_16)
  #undef       COM_START_SEC_VAR_POWER_ON_CLEARED_16
  #pragma section all "COM_RAM_VAR_POWER_ON_CLEARED_16"
#elif defined (COM_STOP_SEC_VAR_POWER_ON_CLEARED_16)
  #undef       COM_STOP_SEC_VAR_POWER_ON_CLEARED_16
  #pragma section all restore

#elif defined (COM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       COM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
  #pragma section all "COM_RAM_VAR_POWER_ON_CLEARED_UNSPECIFIED"
#elif defined (COM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       COM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (COM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN)
  #undef       COM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
  #pragma section all "COM_RAM_VAR_POWER_ON_CLEARED_BOOLEAN"
#elif defined (COM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN)
  #undef       COM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (COM_START_SEC_VAR_CLEARED_8)
  #undef       COM_START_SEC_VAR_CLEARED_8
  #pragma section all "COM_RAM_VAR_CLEARED_8"
#elif defined (COM_STOP_SEC_VAR_CLEARED_8)
  #undef       COM_STOP_SEC_VAR_CLEARED_8
  #pragma section all restore

#elif defined (COM_START_SEC_VAR_CLEARED_16)
  #undef       COM_START_SEC_VAR_CLEARED_16
  #pragma section all "COM_RAM_VAR_CLEARED_16"
#elif defined (COM_STOP_SEC_VAR_CLEARED_16)
  #undef       COM_STOP_SEC_VAR_CLEARED_16
  #pragma section all restore

#elif defined (COM_START_SEC_ETH_VAR_CLEARED_16)
  #undef       COM_START_SEC_ETH_VAR_CLEARED_16
  #pragma section all "COM_RAM_ETH_VAR_CLEARED_16"
#elif defined (COM_STOP_SEC_ETH_VAR_CLEARED_16)
  #undef       COM_STOP_SEC_ETH_VAR_CLEARED_16
  #pragma section all restore
  
#elif defined (COM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       COM_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "COM_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (COM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       COM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (COM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       COM_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "COM_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (COM_START_SEC_ETH_VAR_CLEARED_UNSPECIFIED)
  #undef       COM_START_SEC_ETH_VAR_CLEARED_UNSPECIFIED
  #pragma section all "COM_RAM_ETH_VAR_CLEARED_UNSPECIFIED"
#elif defined (COM_STOP_SEC_ETH_VAR_CLEARED_UNSPECIFIED)
  #undef       COM_STOP_SEC_ETH_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore
  
#elif defined (COM_START_SEC_VAR_CLEARED_UNSPECIFIED_ALIGN4)
  #undef       COM_START_SEC_VAR_CLEARED_UNSPECIFIED_ALIGN4
  #pragma section all "COM_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma align 4
#elif defined (COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED_ALIGN4)
  #undef       COM_STOP_SEC_VAR_CLEARED_UNSPECIFIED_ALIGN4
  #pragma align restore
  #pragma section all restore

#elif defined (COM_START_SEC_VAR_NOINIT_8)
  #undef       COM_START_SEC_VAR_NOINIT_8
  #pragma section all "COM_RAM_VAR_NO_INIT_8"
  #pragma noclear
#elif defined (COM_STOP_SEC_VAR_NOINIT_8)
  #undef       COM_STOP_SEC_VAR_NOINIT_8
  #pragma clear
  #pragma section all restore

#elif defined (COM_START_SEC_VAR_NOINIT_16)
  #undef       COM_START_SEC_VAR_NOINIT_16
  #pragma section all "COM_RAM_VAR_NO_INIT_16"
  #pragma noclear
#elif defined (COM_STOP_SEC_VAR_NOINIT_16)
  #undef       COM_STOP_SEC_VAR_NOINIT_16
  #pragma clear
  #pragma section all restore

#elif defined (COM_START_SEC_VAR_NOINIT_32)
  #undef       COM_START_SEC_VAR_NOINIT_32
  #pragma section all "COM_RAM_VAR_NO_INIT_32"
  #pragma noclear
#elif defined (COM_STOP_SEC_VAR_NOINIT_32)
  #undef       COM_STOP_SEC_VAR_NOINIT_32
  #pragma clear
  #pragma section all restore

#elif defined (COM_START_SEC_VAR_SAVED_ZONE_16)
  #undef       COM_START_SEC_VAR_SAVED_ZONE_16
  #pragma section all "COM_SAVED_RAM_16"
  #pragma noclear
#elif defined (COM_STOP_SEC_VAR_SAVED_ZONE_16)
  #undef       COM_STOP_SEC_VAR_SAVED_ZONE_16
  #pragma clear
  #pragma section all restore

#elif defined (COM_START_SEC_VAR_SAVED_ZONE_8)
  #undef       COM_START_SEC_VAR_SAVED_ZONE_8
  #pragma section all "COM_SAVED_RAM_8"
  #pragma noclear
#elif defined (COM_STOP_SEC_VAR_SAVED_ZONE_8)
  #undef       COM_STOP_SEC_VAR_SAVED_ZONE_8
  #pragma clear
  #pragma section all restore

#elif defined (COM_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
  #undef       COM_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
  #pragma section all "COM_SAVED_RAM_UNSPECIFIED"
  #pragma noclear
#elif defined (COM_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
  #undef       COM_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
  #pragma clear
  #pragma section all restore

#elif defined (COM_START_SEC_CONST_8)
  #undef       COM_START_SEC_CONST_8
  #pragma section all "COM_ROM_CONST_8"
#elif defined (COM_STOP_SEC_CONST_8)
  #undef       COM_STOP_SEC_CONST_8
  #pragma section all restore

#elif defined (COM_START_SEC_CONST_16)
  #undef       COM_START_SEC_CONST_16
  #pragma section all "COM_ROM_CONST_16"
#elif defined (COM_STOP_SEC_CONST_16)
  #undef       COM_STOP_SEC_CONST_16
  #pragma section all restore

#elif defined (COM_START_SEC_CONST_32)
  #undef       COM_START_SEC_CONST_32
  #pragma section all "COM_ROM_CONST_32"
#elif defined (COM_STOP_SEC_CONST_32)
  #undef       COM_STOP_SEC_CONST_32
  #pragma section all restore

#elif defined (COM_START_SEC_CONST_UNSPECIFIED)
  #undef       COM_START_SEC_CONST_UNSPECIFIED
  #pragma section all "COM_ROM_CONST_UNSPECIFIED"
#elif defined (COM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       COM_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (COM_START_SEC_CODE)
  #undef       COM_START_SEC_CODE
  #pragma section code "COM_CODE"
  #pragma section farrom "COM_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "COM_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "COM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (COM_STOP_SEC_CODE)
  #undef       COM_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (COM_START_SEC_APPL_CODE)
  #undef       COM_START_SEC_APPL_CODE
  #pragma section code "COM_APPL_CODE"
  #pragma section farrom "COM_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "COM_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "COM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (COM_STOP_SEC_APPL_CODE)
  #undef       COM_STOP_SEC_APPL_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (COM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       COM_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "COM_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#elif defined (COM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       COM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma clear
  #pragma section all restore

#elif defined (COM_START_SEC_VAR_NOINIT_UNSPECIFIED)
  #undef       COM_START_SEC_VAR_NOINIT_UNSPECIFIED
  #pragma section all "COM_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#elif defined (COM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
  #undef       COM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #pragma clear
  #pragma section all restore

#elif defined (COM_START_SEC_VAR_NO_INIT_8)
  #undef       COM_START_SEC_VAR_NO_INIT_8
  #pragma section all "COM_RAM_VAR_NO_INIT_8"
  #pragma noclear
#elif defined (COM_STOP_SEC_VAR_NO_INIT_8)
  #undef       COM_STOP_SEC_VAR_NO_INIT_8
  #pragma clear
  #pragma section all restore

#elif defined (COM_START_SEC_VAR_INIT_16)
  #undef       COM_START_SEC_VAR_INIT_16
  #pragma section all "COM_RAM_VAR_INIT_16"
#elif defined (COM_STOP_SEC_VAR_INIT_16)
  #undef       COM_STOP_SEC_VAR_INIT_16
  #pragma section all restore

#elif defined (COM_START_SEC_VAR_NO_INIT_16)
  #undef       COM_START_SEC_VAR_NO_INIT_16
  #pragma section all "COM_RAM_VAR_NO_INIT_16"
  #pragma noclear
#elif defined (COM_STOP_SEC_VAR_NO_INIT_16)
  #undef       COM_STOP_SEC_VAR_NO_INIT_16
  #pragma clear
  #pragma section all restore

#elif defined (COM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       COM_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all "COM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (COM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       COM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all restore

#elif defined (COM_START_SEC_VAR_INIT_32)
  #undef       COM_START_SEC_VAR_INIT_32
  #pragma section all "COM_RAM_VAR_INIT_32"
#elif defined (COM_STOP_SEC_VAR_INIT_32)
  #undef       COM_STOP_SEC_VAR_INIT_32
  #pragma section all restore

#elif defined (COM_START_SEC_VAR_INIT_8)
  #undef       COM_START_SEC_VAR_INIT_8
  #pragma section all "COM_RAM_VAR_INIT_8"
#elif defined (COM_STOP_SEC_VAR_INIT_8)
  #undef       COM_STOP_SEC_VAR_INIT_8
  #pragma section all restore

/* -------------------------------------------------------------------------- */
/*             			PduR                                                      */
/* -------------------------------------------------------------------------- */
#elif defined (PDUR_START_SEC_CODE)
  #undef       PDUR_START_SEC_CODE
  #pragma section code "PDUR_CODE"
  #pragma section farrom "PDUR_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "PDUR_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "PDUR_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (PDUR_STOP_SEC_CODE)
  #undef       PDUR_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (PDUR_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       PDUR_START_SEC_VAR_CLEARED_BOOLEAN
	#pragma section all "PDUR_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (PDUR_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       PDUR_STOP_SEC_VAR_CLEARED_BOOLEAN

#elif defined (PDUR_START_SEC_VAR_INIT_32)
  #undef       PDUR_START_SEC_VAR_INIT_32
  #pragma section all "PDUR_RAM_VAR_INIT_32"
#elif defined (PDUR_STOP_SEC_VAR_INIT_32)
  #undef       PDUR_STOP_SEC_VAR_INIT_32
  #pragma section all restore

#elif defined (PDUR_START_SEC_CONST_UNSPECIFIED)
  #undef       PDUR_START_SEC_CONST_UNSPECIFIED
  #pragma section all "PDUR_ROM_CONST_UNSPECIFIED"
#elif defined (PDUR_STOP_SEC_CONST_UNSPECIFIED)
  #undef       PDUR_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (PDUR_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       PDUR_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all "PDUR_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (PDUR_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       PDUR_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all restore

#elif defined (PDUR_START_SEC_VAR_CLEARED_8)
  #undef       PDUR_START_SEC_VAR_CLEARED_8
  #pragma section all "PDUR_RAM_VAR_CLEARED_8"
#elif defined (PDUR_STOP_SEC_VAR_CLEARED_8)
  #undef       PDUR_STOP_SEC_VAR_CLEARED_8
  #pragma section all restore

#elif defined (PDUR_START_SEC_VAR_NO_INIT_8)
  #undef       PDUR_START_SEC_VAR_NO_INIT_8
  #pragma section all "PDUR_RAM_VAR_NO_INIT_8"
  #pragma noclear
#elif defined (PDUR_STOP_SEC_VAR_NO_INIT_8)
  #undef       PDUR_STOP_SEC_VAR_NO_INIT_8
  #pragma clear
  #pragma section all restore

#elif defined (PDUR_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       PDUR_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "PDUR_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#elif defined (PDUR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       PDUR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma clear
  #pragma section all restore

#elif defined (PDUR_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       PDUR_START_SEC_VAR_CLEARED_UNSPECIFIED
	#pragma section all "PDUR_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (PDUR_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       PDUR_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (PDUR_START_SEC_VAR_NO_INIT_16)
  #undef       PDUR_START_SEC_VAR_NO_INIT_16
  #pragma section all "PDUR_RAM_VAR_NO_INIT_16"
  #pragma noclear
#elif defined (PDUR_STOP_SEC_VAR_NO_INIT_16)
  #undef       PDUR_STOP_SEC_VAR_NO_INIT_16
  #pragma clear
  #pragma section all restore

/* -------------------------------------------------------------------------- */
/*             IpduM                                                          */
/* -------------------------------------------------------------------------- */
#elif defined (IPDUM_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       IPDUM_START_SEC_VAR_NO_INIT_BOOLEAN
  #pragma section all "IPDUM_RAM_VAR_NO_INIT_BOOLEAN"
  #pragma noclear
#elif defined (IPDUM_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       IPDUM_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #pragma clear
  #pragma section all restore

#elif defined (IPDUM_START_SEC_VAR_NO_INIT_8)
  #undef       IPDUM_START_SEC_VAR_NO_INIT_8
  #pragma section all "IPDUM_RAM_VAR_NO_INIT_8"
  #pragma noclear
#elif defined (IPDUM_STOP_SEC_VAR_NO_INIT_8)
  #undef       IPDUM_STOP_SEC_VAR_NO_INIT_8
  #pragma clear
  #pragma section all restore

#elif defined (IPDUM_START_SEC_VAR_NO_INIT_16)
  #undef       IPDUM_START_SEC_VAR_NO_INIT_16
  #pragma section all "IPDUM_RAM_VAR_NO_INIT_16"
  #pragma noclear
#elif defined (IPDUM_STOP_SEC_VAR_NO_INIT_16)
  #undef       IPDUM_STOP_SEC_VAR_NO_INIT_16
  #pragma clear
  #pragma section all restore

#elif defined (IPDUM_START_SEC_VAR_NO_INIT_32)
  #undef       IPDUM_START_SEC_VAR_NO_INIT_32
  #pragma section all "IPDUM_RAM_VAR_NO_INIT_32"
  #pragma noclear
#elif defined (IPDUM_STOP_SEC_VAR_NO_INIT_32)
  #undef       IPDUM_STOP_SEC_VAR_NO_INIT_32
  #pragma clear
  #pragma section all restore

#elif defined (IPDUM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       IPDUM_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "IPDUM_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#elif defined (IPDUM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       IPDUM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma clear
  #pragma section all restore

#elif defined (IPDUM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       IPDUM_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "IPDUM_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (IPDUM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       IPDUM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (IPDUM_START_SEC_VAR_CLEARED_8)
  #undef       IPDUM_START_SEC_VAR_CLEARED_8
  #pragma section all "IPDUM_RAM_VAR_CLEARED_8"
#elif defined (IPDUM_STOP_SEC_VAR_CLEARED_8)
  #undef       IPDUM_STOP_SEC_VAR_CLEARED_8
  #pragma section all restore

#elif defined (IPDUM_START_SEC_VAR_CLEARED_16)
  #undef       IPDUM_START_SEC_VAR_CLEARED_16
  #pragma section all "IPDUM_RAM_VAR_CLEARED_16"
#elif defined (IPDUM_STOP_SEC_VAR_CLEARED_16)
  #undef       IPDUM_STOP_SEC_VAR_CLEARED_16
  #pragma section all restore

#elif defined (IPDUM_START_SEC_VAR_CLEARED_32)
  #undef       IPDUM_START_SEC_VAR_CLEARED_32
  #pragma section all "IPDUM_RAM_VAR_CLEARED_32"
#elif defined (IPDUM_STOP_SEC_VAR_CLEARED_32)
  #undef       IPDUM_STOP_SEC_VAR_CLEARED_32
  #pragma section all restore

#elif defined (IPDUM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       IPDUM_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "IPDUM_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (IPDUM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       IPDUM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (IPDUM_START_SEC_VAR_INIT_BOOLEAN)
  #undef       IPDUM_START_SEC_VAR_INIT_BOOLEAN
  #pragma section all "IPDUM_RAM_VAR_INIT_BOOLEAN"
#elif defined (IPDUM_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       IPDUM_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma section all restore

#elif defined (IPDUM_START_SEC_VAR_INIT_8)
  #undef       IPDUM_START_SEC_VAR_INIT_8
  #pragma section all "IPDUM_RAM_VAR_INIT_8"
#elif defined (IPDUM_STOP_SEC_VAR_INIT_8)
  #undef       IPDUM_STOP_SEC_VAR_INIT_8
  #pragma section all restore

#elif defined (IPDUM_START_SEC_VAR_INIT_16)
  #undef       IPDUM_START_SEC_VAR_INIT_16
  #pragma section all "IPDUM_RAM_VAR_INIT_16"
#elif defined (IPDUM_STOP_SEC_VAR_INIT_16)
  #undef       IPDUM_STOP_SEC_VAR_INIT_16
  #pragma section all restore

#elif defined (IPDUM_START_SEC_VAR_INIT_32)
  #undef       IPDUM_START_SEC_VAR_INIT_32
  #pragma section all "IPDUM_RAM_VAR_INIT_32"
#elif defined (IPDUM_STOP_SEC_VAR_INIT_32)
  #undef       IPDUM_STOP_SEC_VAR_INIT_32
  #pragma section all restore

#elif defined (IPDUM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       IPDUM_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all "IPDUM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (IPDUM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       IPDUM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all restore

#elif defined (IPDUM_START_SEC_CONST_BOOLEAN)
  #undef       IPDUM_START_SEC_CONST_BOOLEAN
  #pragma section all "IPDUM_ROM_CONST_BOOLEAN"
#elif defined (IPDUM_STOP_SEC_CONST_BOOLEAN)
  #undef       IPDUM_STOP_SEC_CONST_BOOLEAN
  #pragma section all restore

#elif defined (IPDUM_START_SEC_CONST_8)
  #undef       IPDUM_START_SEC_CONST_8
  #pragma section all "IPDUM_ROM_CONST_8"
#elif defined (IPDUM_STOP_SEC_CONST_8)
  #undef       IPDUM_STOP_SEC_CONST_8
  #pragma section all restore

#elif defined (IPDUM_START_SEC_CONST_16)
  #undef       IPDUM_START_SEC_CONST_16
  #pragma section all "IPDUM_ROM_CONST_16"
#elif defined (IPDUM_STOP_SEC_CONST_16)
  #undef       IPDUM_STOP_SEC_CONST_16
  #pragma section all restore

#elif defined (IPDUM_START_SEC_CONST_UNSPECIFIED)
  #undef       IPDUM_START_SEC_CONST_UNSPECIFIED
  #pragma section all "IPDUM_ROM_CONST_UNSPECIFIED"
#elif defined (IPDUM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       IPDUM_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (IPDUM_START_SEC_CODE)
  #undef       IPDUM_START_SEC_CODE
  #pragma section code "IPDUM_CODE"
  #pragma section farrom "IPDUM_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "IPDUM_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "IPDUM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (IPDUM_STOP_SEC_CODE)
  #undef       IPDUM_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

/* -------------------------------------------------------------------------- */
/*             			CanSM                                                     */
/* -------------------------------------------------------------------------- */
#elif defined (CANSM_START_SEC_CODE)
  #undef       CANSM_START_SEC_CODE
  #pragma section code "CANSM_CODE"
  #pragma section farrom "CANSM_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "CANSM_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "CANSM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (CANSM_STOP_SEC_CODE)
  #undef       CANSM_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (CANSM_START_SEC_CONST_UNSPECIFIED)
  #undef       CANSM_START_SEC_CONST_UNSPECIFIED
  #pragma section all "CANSM_ROM_CONST_UNSPECIFIED"
#elif defined (CANSM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       CANSM_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (CANSM_START_SEC_CONST_8)
  #undef       CANSM_START_SEC_CONST_8
  #pragma section all "CANSM_ROM_CONST_8"
#elif defined (CANSM_STOP_SEC_CONST_8)
  #undef       CANSM_STOP_SEC_CONST_8
  #pragma section all restore

#elif defined (CANSM_START_SEC_CONST_16)
  #undef       CANSM_START_SEC_CONST_16
  #pragma section all "CANSM_ROM_CONST_16"
#elif defined (CANSM_STOP_SEC_CONST_16)
  #undef       CANSM_STOP_SEC_CONST_16
  #pragma section all restore

#elif defined (CANSM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CANSM_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "CANSM_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (CANSM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CANSM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (CANSM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CANSM_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "CANSM_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (CANSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CANSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (CANSM_START_SEC_VAR_CLEARED_16)
  #undef       CANSM_START_SEC_VAR_CLEARED_16
  #pragma section all "CANSM_RAM_VAR_CLEARED_16"
#elif defined (CANSM_STOP_SEC_VAR_CLEARED_16)
  #undef       CANSM_STOP_SEC_VAR_CLEARED_16
  #pragma section all restore

#elif defined (CANSM_START_SEC_VAR_CLEARED_8)
  #undef       CANSM_START_SEC_VAR_CLEARED_8
  #pragma section all "CANSM_RAM_VAR_CLEARED_8"
#elif defined (CANSM_STOP_SEC_VAR_CLEARED_8)
  #undef       CANSM_STOP_SEC_VAR_CLEARED_8
  #pragma section all restore

#elif defined (CANSM_START_SEC_VAR_INIT_BOOLEAN)
  #undef       CANSM_START_SEC_VAR_INIT_BOOLEAN
  #pragma section all "CANSM_RAM_VAR_INIT_BOOLEAN"
#elif defined (CANSM_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       CANSM_STOP_SEC_VAR_INIT_BOOLEAM
  #pragma section all restore

#elif defined (CANSM_START_SEC_VAR_INIT_8)
  #undef       CANSM_START_SEC_VAR_INIT_8
  #pragma section all "CANSM_RAM_VAR_INIT_8"
#elif defined (CANSM_STOP_SEC_VAR_INIT_8)
  #undef       CANSM_STOP_SEC_VAR_INIT_8
  #pragma section all restore

#elif defined (CANSM_START_SEC_VAR_INIT_16)
  #undef       CANSM_START_SEC_VAR_INIT_16
  #pragma section all "CANSM_RAM_VAR_INIT_16"
#elif defined (CANSM_STOP_SEC_VAR_INIT_16)
  #undef       CANSM_STOP_SEC_VAR_INIT_16
  #pragma section all restore

#elif defined (CANSM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CANSM_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all "CANSM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (CANSM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CANSM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all restore
/* -------------------------------------------------------------------------- */
/*                  CanNM                                                     */
/* -------------------------------------------------------------------------- */
#elif defined (CANNM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CANNM_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "CANNM_RAM_VAR_CLEARED_BOOLEAN"
  #pragma clear
  #pragma align 0

#elif defined (CANNM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CANNM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (CANNM_START_SEC_VAR_CLEARED_8)
  #undef       CANNM_START_SEC_VAR_CLEARED_8
  #pragma section all "CANNM_RAM_VAR_CLEARED_8"
  #pragma clear
  #pragma align 0

#elif defined (CANNM_STOP_SEC_VAR_CLEARED_8)
  #undef       CANNM_STOP_SEC_VAR_CLEARED_8
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (CANNM_START_SEC_VAR_CLEARED_16)
  #undef       CANNM_START_SEC_VAR_CLEARED_16
  #pragma section all "CANNM_RAM_VAR_CLEARED_16"
  #pragma clear
  #pragma align 0

#elif defined (CANNM_STOP_SEC_VAR_CLEARED_16)
  #undef       CANNM_STOP_SEC_VAR_CLEARED_16
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (CANNM_START_SEC_VAR_CLEARED_32)
  #undef       CANNM_START_SEC_VAR_CLEARED_32
  #pragma section all "CANNM_RAM_VAR_CLEARED_32"
  #pragma clear
  #pragma align 0

#elif defined (CANNM_STOP_SEC_VAR_CLEARED_32)
  #undef       CANNM_STOP_SEC_VAR_CLEARED_32
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (CANNM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CANNM_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "CANNM_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma clear
  #pragma align 0

#elif defined (CANNM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CANNM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (CANNM_START_SEC_CONST_BOOLEAN)
  #undef       CANNM_START_SEC_CONST_BOOLEAN
  #pragma section all "CANNM_ROM_CONST_BOOLEAN"
  #pragma align 0

#elif defined (CANNM_STOP_SEC_CONST_BOOLEAN)
  #undef       CANNM_STOP_SEC_CONST_BOOLEAN
  #pragma align restore
  #pragma section all restore

#elif defined (CANNM_START_SEC_CONST_8)
  #undef       CANNM_START_SEC_CONST_8
  #pragma section all "CANNM_ROM_CONST_8"
  #pragma align 0

#elif defined (CANNM_STOP_SEC_CONST_8)
  #undef       CANNM_STOP_SEC_CONST_8
  #pragma align restore
  #pragma section all restore

#elif defined (CANNM_START_SEC_CONST_16)
  #undef       CANNM_START_SEC_CONST_16
  #pragma section all "CANNM_ROM_CONST_16"
  #pragma align 0

#elif defined (CANNM_STOP_SEC_CONST_16)
  #undef       CANNM_STOP_SEC_CONST_16
  #pragma align restore
  #pragma section all restore

#elif defined (CANNM_START_SEC_CONST_32)
  #undef       CANNM_START_SEC_CONST_32
  #pragma section all "CANNM_ROM_CONST_32"
  #pragma align 0

#elif defined (CANNM_STOP_SEC_CONST_32)
  #undef       CANNM_STOP_SEC_CONST_32
  #pragma align restore
  #pragma section all restore

#elif defined (CANNM_START_SEC_CONST_UNSPECIFIED)
  #undef       CANNM_START_SEC_CONST_UNSPECIFIED
  #pragma section all "CANNM_ROM_CONST_UNSPECIFIED"
  #pragma align 0

#elif defined (CANNM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       CANNM_STOP_SEC_CONST_UNSPECIFIED
  #pragma align restore
  #pragma section all restore

#elif defined (CANNM_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       CANNM_START_SEC_VAR_NO_INIT_BOOLEAN
  #pragma section all "CANNM_RAM_VAR_NO_INIT_BOOLEAN"
  #pragma noclear
  #pragma align 0

#elif defined (CANNM_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       CANNM_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (CANNM_START_SEC_VAR_NO_INIT_8)
  #undef       CANNM_START_SEC_VAR_NO_INIT_8
  #pragma section all "CANNM_RAM_VAR_NO_INIT_8"
  #pragma noclear
  #pragma align 0

#elif defined (CANNM_STOP_SEC_VAR_NO_INIT_8)
  #undef       CANNM_STOP_SEC_VAR_NO_INIT_8
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (CANNM_START_SEC_VAR_NO_INIT_16)
  #undef       CANNM_START_SEC_VAR_NO_INIT_16
  #pragma section all "CANNM_RAM_VAR_NO_INIT_16"
  #pragma noclear
  #pragma align 0

#elif defined (CANNM_STOP_SEC_VAR_NO_INIT_16)
  #undef       CANNM_STOP_SEC_VAR_NO_INIT_16
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (CANNM_START_SEC_VAR_NO_INIT_32)
  #undef       CANNM_START_SEC_VAR_NO_INIT_32
  #pragma section all "CANNM_RAM_VAR_NO_INIT_32"
  #pragma noclear
  #pragma align 0

#elif defined (CANNM_STOP_SEC_VAR_NO_INIT_32)
  #undef       CANNM_STOP_SEC_VAR_NO_INIT_32
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (CANNM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       CANNM_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "CANNM_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
  #pragma align 0

#elif defined (CANNM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       CANNM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (CANNM_START_SEC_VAR_INIT_BOOLEAN)
  #undef       CANNM_START_SEC_VAR_INIT_BOOLEAN
  #pragma section all "CANNM_RAM_VAR_INIT_BOOLEAN"
  #pragma clear
  #pragma align 0

#elif defined (CANNM_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       CANNM_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (CANNM_START_SEC_VAR_INIT_8)
  #undef       CANNM_START_SEC_VAR_INIT_8
  #pragma section all "CANNM_RAM_VAR_INIT_8"
  #pragma clear
  #pragma align 0

#elif defined (CANNM_STOP_SEC_VAR_INIT_8)
  #undef       CANNM_STOP_SEC_VAR_INIT_8
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (CANNM_START_SEC_VAR_INIT_16)
  #undef       CANNM_START_SEC_VAR_INIT_16
  #pragma section all "CANNM_RAM_VAR_INIT_16"
  #pragma clear
  #pragma align 0

#elif defined (CANNM_STOP_SEC_VAR_INIT_16)
  #undef       CANNM_STOP_SEC_VAR_INIT_16
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (CANNM_START_SEC_VAR_INIT_32)
  #undef       CANNM_START_SEC_VAR_INIT_32
  #pragma section all "CANNM_RAM_VAR_INIT_32"
  #pragma clear
  #pragma align 0

#elif defined (CANNM_STOP_SEC_VAR_INIT_32)
  #undef       CANNM_STOP_SEC_VAR_INIT_32
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (CANNM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CANNM_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all "CANNM_RAM_VAR_INIT_UNSPECIFIED"
  #pragma clear
  #pragma align 0

#elif defined (CANNM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CANNM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (CANNM_START_SEC_CODE)
  #undef       CANNM_START_SEC_CODE
  #pragma section code "CANNM_CODE"
  #pragma section farrom "CANNM_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "CANNM_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "CANNM_RAM_VAR_INIT_UNSPECIFIED"

#elif defined (CANNM_STOP_SEC_CODE)
  #undef       CANNM_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore
  
/* -------------------------------------------------------------------------- */
/*             			CanCM                                                     */
/* -------------------------------------------------------------------------- */
#elif defined (CANCM_START_SEC_CONST_8)
  #undef      CANCM_START_SEC_CONST_8
  #pragma section all "CANCM_ROM_CONST_8"
#elif defined (CANCM_STOP_SEC_CONST_8)
  #undef      CANCM_STOP_SEC_CONST_8
  #pragma section all restore
#elif defined (CANCM_START_SEC_CONST_UNSPECIFIED)
  #undef      CANCM_START_SEC_CONST_UNSPECIFIED
  #pragma section all "CANCM_ROM_CONST_UNSPECIFIED"
#elif defined (CANCM_STOP_SEC_CONST_UNSPECIFIED)
  #undef      CANCM_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore
#elif defined (CANCM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef      CANCM_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "CANCM_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (CANCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef      CANCM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore
#elif defined (CANCM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef      CANCM_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "CANCM_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#elif defined (CANCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef      CANCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma clear
  #pragma section all restore
#elif defined (CANCM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef      CANCM_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "CANCM_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (CANCM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef      CANCM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore
#elif defined (CANCM_START_SEC_CODE)
  #undef      CANCM_START_SEC_CODE
  #pragma section code "CANCM_CODE"
  #pragma section farrom "CANCM_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "CANCM_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "CANCM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (CANCM_STOP_SEC_CODE)
  #undef      CANCM_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

/* -------------------------------------------------------------------------- */
/*             			OSEKNm                                                    */
/* -------------------------------------------------------------------------- */
#elif defined (OSEKNM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       OSEKNM_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "OSEKNM_RAM_VAR_CLEARED_BOOLEAN"
  #pragma clear
  #pragma align 0

#elif defined (OSEKNM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       OSEKNM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (OSEKNM_START_SEC_VAR_CLEARED_8)
  #undef       OSEKNM_START_SEC_VAR_CLEARED_8
  #pragma section all "OSEKNM_RAM_VAR_CLEARED_8"
  #pragma clear
  #pragma align 0

#elif defined (OSEKNM_STOP_SEC_VAR_CLEARED_8)
  #undef       OSEKNM_STOP_SEC_VAR_CLEARED_8
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (OSEKNM_START_SEC_VAR_CLEARED_16)
  #undef       OSEKNM_START_SEC_VAR_CLEARED_16
  #pragma section all "OSEKNM_RAM_VAR_CLEARED_16"
  #pragma clear
  #pragma align 0

#elif defined (OSEKNM_STOP_SEC_VAR_CLEARED_16)
  #undef       OSEKNM_STOP_SEC_VAR_CLEARED_16
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (OSEKNM_START_SEC_VAR_CLEARED_32)
  #undef       OSEKNM_START_SEC_VAR_CLEARED_32
  #pragma section all "OSEKNM_RAM_VAR_CLEARED_32"
  #pragma clear
  #pragma align 4

#elif defined (OSEKNM_STOP_SEC_VAR_CLEARED_32)
  #undef       OSEKNM_STOP_SEC_VAR_CLEARED_32
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (OSEKNM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OSEKNM_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "OSEKNM_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma clear
  #pragma align 4

#elif defined (OSEKNM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OSEKNM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (OSEKNM_START_SEC_CONST_BOOLEAN)
  #undef       OSEKNM_START_SEC_CONST_BOOLEAN
  #pragma section all "OSEKNM_ROM_CONST_BOOLEAN"
  #pragma align 0

#elif defined (OSEKNM_STOP_SEC_CONST_BOOLEAN)
  #undef       OSEKNM_STOP_SEC_CONST_BOOLEAN
  #pragma align restore
  #pragma section all restore

#elif defined (OSEKNM_START_SEC_CONST_8)
  #undef       OSEKNM_START_SEC_CONST_8
  #pragma section all "OSEKNM_ROM_CONST_8"
  #pragma align 0

#elif defined (OSEKNM_STOP_SEC_CONST_8)
  #undef       OSEKNM_STOP_SEC_CONST_8
  #pragma align restore
  #pragma section all restore

#elif defined (OSEKNM_START_SEC_CONST_16)
  #undef       OSEKNM_START_SEC_CONST_16
  #pragma section all "OSEKNM_ROM_CONST_16"
  #pragma align 0  

#elif defined (OSEKNM_STOP_SEC_CONST_16)
  #undef       OSEKNM_STOP_SEC_CONST_16
  #pragma align restore
  #pragma section all restore

#elif defined (OSEKNM_START_SEC_CONST_32)
  #undef       OSEKNM_START_SEC_CONST_32
  #pragma section all "OSEKNM_ROM_CONST_32"
  #pragma align 4

#elif defined (OSEKNM_STOP_SEC_CONST_32)
  #undef       OSEKNM_STOP_SEC_CONST_32
  #pragma align restore
  #pragma section all restore

#elif defined (OSEKNM_START_SEC_CONST_UNSPECIFIED)
  #undef       OSEKNM_START_SEC_CONST_UNSPECIFIED
  #pragma section all "OSEKNM_ROM_CONST_UNSPECIFIED"
  #pragma align 4
  
#elif defined (OSEKNM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       OSEKNM_STOP_SEC_CONST_UNSPECIFIED
  #pragma align restore
  #pragma section all restore

#elif defined (OSEKNM_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       OSEKNM_START_SEC_VAR_NO_INIT_BOOLEAN
  #pragma section all "OSEKNM_RAM_VAR_NO_INIT_BOOLEAN"
  #pragma noclear
  #pragma align 0

#elif defined (OSEKNM_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       OSEKNM_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (OSEKNM_START_SEC_VAR_NO_INIT_8)
  #undef       OSEKNM_START_SEC_VAR_NO_INIT_8
  #pragma section all "OSEKNM_RAM_VAR_NO_INIT_8"
  #pragma noclear
  #pragma align 0

#elif defined (OSEKNM_STOP_SEC_VAR_NO_INIT_8)
  #undef       OSEKNM_STOP_SEC_VAR_NO_INIT_8
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (OSEKNM_START_SEC_VAR_NO_INIT_16)
  #undef       OSEKNM_START_SEC_VAR_NO_INIT_16
  #pragma section all "OSEKNM_RAM_VAR_NO_INIT_16"
  #pragma noclear
  #pragma align 0

#elif defined (OSEKNM_STOP_SEC_VAR_NO_INIT_16)
  #undef       OSEKNM_STOP_SEC_VAR_NO_INIT_16
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (OSEKNM_START_SEC_VAR_NO_INIT_32)
  #undef       OSEKNM_START_SEC_VAR_NO_INIT_32
  #pragma section all "OSEKNM_RAM_VAR_NO_INIT_32"
  #pragma noclear
  #pragma align 4

#elif defined (OSEKNM_STOP_SEC_VAR_NO_INIT_32)
  #undef       OSEKNM_STOP_SEC_VAR_NO_INIT_32
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (OSEKNM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       OSEKNM_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "OSEKNM_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
  #pragma align 4

#elif defined (OSEKNM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       OSEKNM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (OSEKNM_START_SEC_VAR_INIT_BOOLEAN)
  #undef       OSEKNM_START_SEC_VAR_INIT_BOOLEAN
  #pragma section all "OSEKNM_RAM_VAR_INIT_BOOLEAN"
  #pragma clear
  #pragma align 0
#elif defined (OSEKNM_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       OSEKNM_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (OSEKNM_START_SEC_VAR_INIT_8)
  #undef       OSEKNM_START_SEC_VAR_INIT_8
  #pragma section all "OSEKNM_RAM_VAR_INIT_8"
  #pragma clear
  #pragma align 0
#elif defined (OSEKNM_STOP_SEC_VAR_INIT_8)
  #undef       OSEKNM_STOP_SEC_VAR_INIT_8
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (OSEKNM_START_SEC_VAR_INIT_16)
  #undef       OSEKNM_START_SEC_VAR_INIT_16
  #pragma section all "OSEKNM_RAM_VAR_INIT_16"
  #pragma clear
  #pragma align 0
#elif defined (OSEKNM_STOP_SEC_VAR_INIT_16)
  #undef       OSEKNM_STOP_SEC_VAR_INIT_16
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (OSEKNM_START_SEC_VAR_INIT_32)
  #undef       OSEKNM_START_SEC_VAR_INIT_32
  #pragma section all "OSEKNM_RAM_VAR_INIT_32"
  #pragma clear
  #pragma align 4
#elif defined (OSEKNM_STOP_SEC_VAR_INIT_32)
  #undef       OSEKNM_STOP_SEC_VAR_INIT_32
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (OSEKNM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       OSEKNM_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all "OSEKNM_RAM_VAR_INIT_UNSPECIFIED"
  #pragma clear
  #pragma align 4
#elif defined (OSEKNM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       OSEKNM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (OSEKNM_START_SEC_CODE)
  #undef       OSEKNM_START_SEC_CODE
  #pragma section code "OSEKNM_CODE"
  #pragma section farrom "OSEKNM_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "OSEKNM_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "OSEKNM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (OSEKNM_STOP_SEC_CODE)
  #undef       OSEKNM_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

/* -------------------------------------------------------------------------- */
/*             			ECUM                                                      */
/* -------------------------------------------------------------------------- */
#elif defined (ECUM_START_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED)
  #undef       ECUM_START_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED
  #pragma section all "ECUM_ROM_CONFIG_UNSPECIFIED"
#elif defined (ECUM_STOP_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED)
  #undef       ECUM_STOP_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (ECUM_START_SEC_CODE)
  #undef       ECUM_START_SEC_CODE
  #pragma section code "ECUM_CODE"
  #pragma section farrom "ECUM_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "ECUM_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "ECUM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (ECUM_STOP_SEC_CODE)
  #undef       ECUM_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (ECUM_START_SEC_CONFIG_CONST_32)
  #undef       ECUM_START_SEC_CONFIG_CONST_32
  #pragma section all "ECUM_ROM_CONFIG_CONST_32"
#elif defined (ECUM_STOP_SEC_CONFIG_CONST_32)
  #undef       ECUM_STOP_SEC_CONFIG_CONST_32
  #pragma section all restore

#elif defined (ECUM_START_SEC_CONST_32)
  #undef       ECUM_START_SEC_CONST_32
  #pragma section all "ECUM_ROM_CONST_32"
#elif defined (ECUM_STOP_SEC_CONST_32)
  #undef       ECUM_STOP_SEC_CONST_32
  #pragma section all restore

#elif defined (ECUM_START_SEC_CONST_8)
  #undef       ECUM_START_SEC_CONST_8
  #pragma section all "ECUM_ROM_CONST_8"
#elif defined (ECUM_STOP_SEC_CONST_8)
  #undef       ECUM_STOP_SEC_CONST_8
  #pragma section all restore

#elif defined (ECUM_START_SEC_CONST_UNSPECIFIED)
  #undef       ECUM_START_SEC_CONST_UNSPECIFIED
  #pragma section all "ECUM_ROM_CONST_UNSPECIFIED"
#elif defined (ECUM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       ECUM_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (ECUM_START_SEC_CALLOUT_CODE)
  #undef       ECUM_START_SEC_CALLOUT_CODE
  #pragma section code "ECUM_CALLOUT_CODE"
  #pragma section farrom "ECUM_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "ECUM_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "ECUM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (ECUM_STOP_SEC_CALLOUT_CODE)
  #undef       ECUM_STOP_SEC_CALLOUT_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (ECUM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       ECUM_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "ECUM_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (ECUM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       ECUM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (ECUM_START_SEC_VAR_POWER_ON_CLEARED_16)
  #undef       ECUM_START_SEC_VAR_POWER_ON_CLEARED_16
  #pragma section all "ECUM_RAM_VAR_POWER_ON_CLEARED_16"
#elif defined (ECUM_STOP_SEC_VAR_POWER_ON_CLEARED_16)
  #undef       ECUM_STOP_SEC_VAR_POWER_ON_CLEARED_16
  #pragma section all restore

#elif defined (ECUM_START_SEC_VAR_CLEARED_32)
  #undef       ECUM_START_SEC_VAR_CLEARED_32
  #pragma section all "ECUM_RAM_VAR_CLEARED_32"
#elif defined (ECUM_STOP_SEC_VAR_CLEARED_32)
  #undef       ECUM_STOP_SEC_VAR_CLEARED_32
  #pragma section all restore

#elif defined (ECUM_START_SEC_VAR_CLEARED_16)
  #undef       ECUM_START_SEC_VAR_CLEARED_16
  #pragma section all "ECUM_RAM_VAR_CLEARED_16"
#elif defined (ECUM_STOP_SEC_VAR_CLEARED_16)
  #undef       ECUM_STOP_SEC_VAR_CLEARED_16
  #pragma section all restore

#elif defined (ECUM_START_SEC_VAR_CLEARED_8)
  #undef       ECUM_START_SEC_VAR_CLEARED_8
  #pragma section all "ECUM_RAM_VAR_CLEARED_8"
#elif defined (ECUM_STOP_SEC_VAR_CLEARED_8)
  #undef       ECUM_STOP_SEC_VAR_CLEARED_8
  #pragma section all restore

#elif defined (ECUM_START_SEC_VAR_NO_INIT_8)
  #undef       ECUM_START_SEC_VAR_NO_INIT_8
  #pragma section all "ECUM_RAM_VAR_NO_INIT_8"
  #pragma noclear
#elif defined (ECUM_STOP_SEC_VAR_NO_INIT_8)
  #undef       ECUM_STOP_SEC_VAR_NO_INIT_8
  #pragma clear
  #pragma section all restore

#elif defined (ECUM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       ECUM_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "ECUM_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#elif defined (ECUM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       ECUM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma clear
  #pragma section all restore

#elif defined (ECUM_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
  #undef       ECUM_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
  #pragma section all "ECUM_RAM_VAR_SAVED_ZONE_UNSPECIFIED"
  #pragma noclear
#elif defined (ECUM_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
  #undef       ECUM_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
  #pragma clear
  #pragma section all restore

#elif defined (ECUM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       ECUM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
  #pragma section all "ECUM_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (ECUM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       ECUM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
  #pragma section all restore

/* -------------------------------------------------------------------------- */
/*                 NM                                                         */
/* -------------------------------------------------------------------------- */

#elif defined (NM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       NM_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "NM_RAM_VAR_CLEARED_BOOLEAN"
  #pragma clear
  #pragma align 0

#elif defined (NM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       NM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (NM_START_SEC_VAR_CLEARED_8)
  #undef       NM_START_SEC_VAR_CLEARED_8
  #pragma section all "NM_RAM_VAR_CLEARED_8"
  #pragma clear
  #pragma align 0

#elif defined (NM_STOP_SEC_VAR_CLEARED_8)
  #undef       NM_STOP_SEC_VAR_CLEARED_8
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (NM_START_SEC_VAR_CLEARED_16)
  #undef       NM_START_SEC_VAR_CLEARED_16
  #pragma section all "NM_RAM_VAR_CLEARED_16"
  #pragma clear
  #pragma align 0

#elif defined (NM_STOP_SEC_VAR_CLEARED_16)
  #undef       NM_STOP_SEC_VAR_CLEARED_16
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (NM_START_SEC_VAR_CLEARED_32)
  #undef       NM_START_SEC_VAR_CLEARED_32
  #pragma section all "NM_RAM_VAR_CLEARED_32"
  #pragma clear
  #pragma align 4

#elif defined (NM_STOP_SEC_VAR_CLEARED_32)
  #undef       NM_STOP_SEC_VAR_CLEARED_32
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (NM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       NM_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "NM_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma clear
  #pragma align 4

#elif defined (NM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       NM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (NM_START_SEC_VAR_POWER_ON_INIT_BOOLEAN)
  #undef       NM_START_SEC_VAR_POWER_ON_INIT_BOOLEAN
  #pragma section all "NM_RAM_VAR_INIT_BOOLEAN"
  #pragma align 0
  
#elif defined (NM_STOP_SEC_VAR_POWER_ON_INIT_BOOLEAN)
  #undef       NM_STOP_SEC_VAR_POWER_ON_INIT_BOOLEAN
  #pragma align restore
  #pragma section all restore

#elif defined (NM_START_SEC_VAR_POWER_ON_INIT_8)
  #undef       NM_START_SEC_VAR_POWER_ON_INIT_8
  #pragma section all "NM_RAM_VAR_INIT_8"
  #pragma align 0
  
#elif defined (NM_STOP_SEC_VAR_POWER_ON_INIT_8)
  #undef       NM_STOP_SEC_VAR_POWER_ON_INIT_8
  #pragma align restore
  #pragma section all restore

#elif defined (NM_START_SEC_VAR_POWER_ON_INIT_16)
  #undef       NM_START_SEC_VAR_POWER_ON_INIT_16
  #pragma section all "NM_RAM_VAR_INIT_16"
  #pragma align 0
  
#elif defined (NM_STOP_SEC_VAR_POWER_ON_INIT_16)
  #undef       NM_STOP_SEC_VAR_POWER_ON_INIT_16
  #pragma align restore
  #pragma section all restore

#elif defined (NM_START_SEC_VAR_POWER_ON_INIT_32)
  #undef       NM_START_SEC_VAR_POWER_ON_INIT_32
  #pragma section all "NM_RAM_VAR_INIT_32"
  #pragma align 4
  
#elif defined (NM_STOP_SEC_VAR_POWER_ON_INIT_32)
  #undef       NM_STOP_SEC_VAR_POWER_ON_INIT_32
  #pragma align restore
  #pragma section all restore

#elif defined (NM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
  #undef       NM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
  #pragma section all "NM_RAM_VAR_INIT_UNSPECIFIED"
  #pragma align 4
  
#elif defined (NM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
  #undef       NM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
  #pragma align restore
  #pragma section all restore

#elif defined (NM_START_SEC_VAR_INIT_BOOLEAN)
  #undef       NM_START_SEC_VAR_INIT_BOOLEAN
  #pragma section all "NM_RAM_VAR_INIT_BOOLEAN"
  #pragma clear
  #pragma align 0
#elif defined (NM_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       NM_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (NM_START_SEC_VAR_INIT_8)
  #undef       NM_START_SEC_VAR_INIT_8
  #pragma section all "NM_RAM_VAR_INIT_8"
  #pragma clear
  #pragma align 0
#elif defined (NM_STOP_SEC_VAR_INIT_8)
  #undef       NM_STOP_SEC_VAR_INIT_8
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (NM_START_SEC_VAR_INIT_16)
  #undef       NM_START_SEC_VAR_INIT_16
  #pragma section all "NM_RAM_VAR_INIT_16"
  #pragma clear
  #pragma align 0
#elif defined (NM_STOP_SEC_VAR_INIT_16)
  #undef       NM_STOP_SEC_VAR_INIT_16
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (NM_START_SEC_VAR_INIT_32)
  #undef       NM_START_SEC_VAR_INIT_32
  #pragma section all "NM_RAM_VAR_INIT_32"
  #pragma clear
  #pragma align 4
#elif defined (NM_STOP_SEC_VAR_INIT_32)
  #undef       NM_STOP_SEC_VAR_INIT_32
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (NM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       NM_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all "NM_RAM_VAR_INIT_UNSPECIFIED"
  #pragma clear
  #pragma align 4
#elif defined (NM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       NM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (NM_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       NM_START_SEC_VAR_NO_INIT_BOOLEAN
  #pragma section all "NM_RAM_VAR_NO_INIT_BOOLEAN"
  #pragma noclear
  #pragma align 0

#elif defined (NM_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       NM_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (NM_START_SEC_VAR_NO_INIT_8)
  #undef       NM_START_SEC_VAR_NO_INIT_8
  #pragma section all "NM_RAM_VAR_NO_INIT_8"
  #pragma noclear
  #pragma align 0

#elif defined (NM_STOP_SEC_VAR_NO_INIT_8)
  #undef       NM_STOP_SEC_VAR_NO_INIT_8
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (NM_START_SEC_VAR_NO_INIT_16)
  #undef       NM_START_SEC_VAR_NO_INIT_16
  #pragma section all "NM_RAM_VAR_NO_INIT_16"
  #pragma noclear
  #pragma align 0

#elif defined (NM_STOP_SEC_VAR_NO_INIT_16)
  #undef       NM_STOP_SEC_VAR_NO_INIT_16
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (NM_START_SEC_VAR_NO_INIT_32)
  #undef       NM_START_SEC_VAR_NO_INIT_32
  #pragma section all "NM_RAM_VAR_NO_INIT_32"
  #pragma noclear
  #pragma align 4

#elif defined (NM_STOP_SEC_VAR_NO_INIT_32)
  #undef       NM_STOP_SEC_VAR_NO_INIT_32
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (NM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       NM_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "NM_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
  #pragma align 4

#elif defined (NM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       NM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (NM_START_SEC_CONST_BOOLEAN)
  #undef       NM_START_SEC_CONST_BOOLEAN
  #pragma section all "NM_ROM_CONST_BOOLEAN"
  #pragma align 0

#elif defined (NM_STOP_SEC_CONST_BOOLEAN)
  #undef       NM_STOP_SEC_CONST_BOOLEAN
  #pragma align restore
  #pragma section all restore

#elif defined (NM_START_SEC_CONST_8)
  #undef       NM_START_SEC_CONST_8
  #pragma section all "NM_ROM_CONST_8"
  #pragma align 0

#elif defined (NM_STOP_SEC_CONST_8)
  #undef       NM_STOP_SEC_CONST_8
  #pragma align restore
  #pragma section all restore

#elif defined (NM_START_SEC_CONST_16)
  #undef       NM_START_SEC_CONST_16
  #pragma section all "NM_ROM_CONST_16"
  #pragma align 0  

#elif defined (NM_STOP_SEC_CONST_16)
  #undef       NM_STOP_SEC_CONST_16
  #pragma align restore
  #pragma section all restore

#elif defined (NM_START_SEC_CONST_32)
  #undef       NM_START_SEC_CONST_32
  #pragma section all "NM_ROM_CONST_32"
  #pragma align 4

#elif defined (NM_STOP_SEC_CONST_32)
  #undef       NM_STOP_SEC_CONST_32
  #pragma align restore
  #pragma section all restore

#elif defined (NM_START_SEC_CONST_UNSPECIFIED)
  #undef       NM_START_SEC_CONST_UNSPECIFIED
  #pragma section all "NM_ROM_CONST_UNSPECIFIED"
  #pragma align 4
  
#elif defined (NM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       NM_STOP_SEC_CONST_UNSPECIFIED
  #pragma align restore
  #pragma section all restore

#elif defined (NM_START_SEC_CODE)
  #undef       NM_START_SEC_CODE
  #pragma section code "NM_CODE"
  #pragma section farrom "NM_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "NM_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "NM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (NM_STOP_SEC_CODE)
  #undef       NM_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

/* -------------------------------------------------------------------------- */
/*                                 MemIf                                      */
/* -------------------------------------------------------------------------- */

#elif defined (MEMIF_START_SEC_CODE)
  #undef       MEMIF_START_SEC_CODE
  #pragma section code "MEMIF_CODE"
  #pragma section farrom "MEMIF_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "MEMIF_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "MEMIF_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (MEMIF_STOP_SEC_CODE)
  #undef       MEMIF_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

/* -------------------------------------------------------------------------- */
/*                                 Crc                                        */
/* -------------------------------------------------------------------------- */

#elif defined (CRC_START_SEC_CODE)
  #undef       CRC_START_SEC_CODE
  #pragma section code "CRC_CODE"
  #pragma section farrom "CRC_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "CRC_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "CRC_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (CRC_STOP_SEC_CODE)
  #undef       CRC_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (CRC_START_SEC_CONST_8)
  #undef       CRC_START_SEC_CONST_8
  #pragma section all "CRC_ROM_CONST_8"
#elif defined (CRC_STOP_SEC_CONST_8)
  #undef       CRC_STOP_SEC_CONST_8
  #pragma section all restore

#elif defined (CRC_START_SEC_CONST_16)
  #undef       CRC_START_SEC_CONST_16
  #pragma section all "CRC_ROM_CONST_16"
#elif defined (CRC_STOP_SEC_CONST_16)
  #undef       CRC_STOP_SEC_CONST_16
  #pragma section all restore

#elif defined (CRC_START_SEC_CONST_32)
  #undef       CRC_START_SEC_CONST_32
  #pragma section all "CRC_ROM_CONST_32"
#elif defined (CRC_STOP_SEC_CONST_32)
  #undef       CRC_STOP_SEC_CONST_32
  #pragma section all restore

/* for CRC R44 */
#elif defined (CRC_START_SEC_CODE_ASIL_D)
  #undef       CRC_START_SEC_CODE_ASIL_D
  #pragma section code "CRC_CODE"
  #pragma section farrom "CRC_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "CRC_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "CRC_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (CRC_STOP_SEC_CODE_ASIL_D)
  #undef       CRC_STOP_SEC_CODE_ASIL_D
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (CRC_START_SEC_CONST_ASIL_D_8)
  #undef       CRC_START_SEC_CONST_ASIL_D_8
  #pragma section all "CRC_ROM_CONST_8"
#elif defined (CRC_STOP_SEC_CONST_ASIL_D_8)
  #undef       CRC_STOP_SEC_CONST_ASIL_D_8
  #pragma section all restore

#elif defined (CRC_START_SEC_CONST_ASIL_D_16)
  #undef       CRC_START_SEC_CONST_ASIL_D_16
  #pragma section all "CRC_ROM_CONST_16"
#elif defined (CRC_STOP_SEC_CONST_ASIL_D_16)
  #undef       CRC_STOP_SEC_CONST_ASIL_D_16
  #pragma section all restore

#elif defined (CRC_START_SEC_CONST_ASIL_D_32)
  #undef       CRC_START_SEC_CONST_ASIL_D_32
  #pragma section all "CRC_ROM_CONST_32"
#elif defined (CRC_STOP_SEC_CONST_ASIL_D_32)
  #undef       CRC_STOP_SEC_CONST_ASIL_D_32
  #pragma section all restore

#elif defined (CRC_START_SEC_CONST_ASIL_D_UNSPECIFIED)
  #undef       CRC_START_SEC_CONST_ASIL_D_UNSPECIFIED
  #pragma section all "CRC_ROM_CONST_UNSPECIFIED"  
  
#elif defined (CRC_STOP_SEC_CONST_ASIL_D_UNSPECIFIED)
  #undef       CRC_STOP_SEC_CONST_ASIL_D_UNSPECIFIED
  #pragma section all restore
/* -------------------------------------------------------------------------- */
/*                                 NvM                                        */
/* -------------------------------------------------------------------------- */
#elif defined (NVM_START_SEC_CODE)
  #undef       NVM_START_SEC_CODE
  #pragma section code "NVM_CODE"
  #pragma section farrom "NVM_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "NVM_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "NVM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (NVM_STOP_SEC_CODE)
  #undef       NVM_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (NVM_START_SEC_VAR_CLEARED_8)
 #undef        NVM_START_SEC_VAR_CLEARED_8
 #pragma section all "NVM_RAM_VAR_CLEARED_8"
#elif defined (NVM_STOP_SEC_VAR_CLEARED_8)
 #undef        NVM_STOP_SEC_VAR_CLEARED_8
 #pragma section all restore

#elif defined (NVM_START_SEC_VAR_CLEARED_16)
  #undef       NVM_START_SEC_VAR_CLEARED_16
  #pragma section all "NVM_RAM_VAR_CLEARED_16"
#elif defined (NVM_STOP_SEC_VAR_CLEARED_16)
  #undef       NVM_STOP_SEC_VAR_CLEARED_16
  #pragma section all restore

#elif defined (NVM_START_SEC_VAR_POWER_ON_CLEARED_16)
  #undef       NVM_START_SEC_VAR_POWER_ON_CLEARED_16
  #pragma section all "NVM_RAM_VAR_POWER_ON_CLEARED_16"
#elif defined (NVM_STOP_SEC_VAR_POWER_ON_CLEARED_16)
  #undef       NVM_STOP_SEC_VAR_POWER_ON_CLEARED_16
  #pragma section all restore

#elif defined (NVM_START_SEC_VAR_POWER_ON_CLEARED_8)
  #undef       NVM_START_SEC_VAR_POWER_ON_CLEARED_8
  #pragma section all "NVM_RAM_VAR_POWER_ON_CLEARED_8"
#elif defined (NVM_STOP_SEC_VAR_POWER_ON_CLEARED_8)
  #undef       NVM_STOP_SEC_VAR_POWER_ON_CLEARED_8
  #pragma section all restore

#elif defined (NVM_START_SEC_VAR_NO_INIT_8)
  #undef       NVM_START_SEC_VAR_NO_INIT_8
  #pragma section all "NVM_RAM_VAR_NO_INIT_8"
  #pragma noclear
#elif defined (NVM_STOP_SEC_VAR_NO_INIT_8)
  #undef       NVM_STOP_SEC_VAR_NO_INIT_8
  #pragma clear
  #pragma section all restore

#elif defined (NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       NVM_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "NVM_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#elif defined (NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       NVM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma clear
  #pragma section all restore

#elif defined (NVM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       NVM_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "NVM_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (NVM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       NVM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (NVM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       NVM_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
  #pragma section all "NVM_RAM_VAR_POWER_ON_CLEARED_UNSPECIFIED"
#elif defined (NVM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       NVM_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (NVM_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       NVM_START_SEC_VAR_NO_INIT_BOOLEAN
  #pragma section all "NVM_RAM_VAR_NO_INIT_BOOLEAN"
  #pragma noclear
#elif defined (NVM_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       NVM_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #pragma clear
  #pragma section all restore

#elif defined (NVM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN)
  #undef       NVM_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
  #pragma section all "NVM_RAM_VAR_POWER_ON_CLEARED_BOOLEAN"
#elif defined (NVM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN)
  #undef       NVM_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (NVM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       NVM_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "NVM_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (NVM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       NVM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (NVM_START_SEC_CONST_8)
  #undef       NVM_START_SEC_CONST_8
  #pragma section all "NVM_ROM_CONST_8"
#elif defined (NVM_STOP_SEC_CONST_8)
  #undef       NVM_STOP_SEC_CONST_8
  #pragma section all restore

#elif defined (NVM_START_SEC_CONST_16)
  #undef       NVM_START_SEC_CONST_16
  #pragma section all "NVM_ROM_CONST_16"
#elif defined (NVM_STOP_SEC_CONST_16)
  #undef       NVM_STOP_SEC_CONST_16
  #pragma section all restore

#elif defined (NVM_START_SEC_CONST_UNSPECIFIED)
  #undef       NVM_START_SEC_CONST_UNSPECIFIED
  #pragma section all "NVM_ROM_CONST_UNSPECIFIED"
#elif defined (NVM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       NVM_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (NVM_START_SEC_VAR_NO_INIT_16)
  #undef       NVM_START_SEC_VAR_NO_INIT_16
  #pragma section all "NVM_RAM_VAR_NO_INIT_16"
  #pragma noclear
#elif defined (NVM_STOP_SEC_VAR_NO_INIT_16)
  #undef       NVM_STOP_SEC_VAR_NO_INIT_16
  #pragma clear
  #pragma section all restore

#elif defined (NVM_START_SEC_VAR_NO_INIT_32)
  #undef       NVM_START_SEC_VAR_NO_INIT_32
  #pragma section all "NVM_RAM_VAR_NO_INIT_32"
  #pragma noclear
#elif defined (NVM_STOP_SEC_VAR_NO_INIT_32)
  #undef       NVM_STOP_SEC_VAR_NO_INIT_32
  #pragma clear
  #pragma section all restore

#elif defined (NVM_START_SEC_VAR_INIT_8)
  #undef       NVM_START_SEC_VAR_INIT_8
  #pragma section all "NVM_RAM_VAR_INIT_8"
#elif defined (NVM_STOP_SEC_VAR_INIT_8)
  #undef       NVM_STOP_SEC_VAR_INIT_8
  #pragma section all restore

#elif defined (NVM_START_SEC_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED)
  #undef       NVM_START_SEC_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED
  #pragma section all "NVM_RAM_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED"
#elif defined (NVM_STOP_SEC_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED)
  #undef       NVM_STOP_SEC_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED
  #pragma section all restore

  
/* -------------------------------------------------------------------------- */
/*                                 Eep                                        */
/* -------------------------------------------------------------------------- */
#elif defined (EEP_START_SEC_CODE)
  #undef       EEP_START_SEC_CODE
  #pragma section code "EEP_CODE"
  #pragma section farrom "EEP_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "EEP_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "EEP_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (EEP_STOP_SEC_CODE)
  #undef       EEP_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (EEP_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       EEP_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "EEP_RAM_VAR_POWER_ON_CLEARED_BOOLEAN"
#elif defined (EEP_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       EEP_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (EEP_START_SEC_VAR_CLEARED_8)
  #undef       EEP_START_SEC_VAR_CLEARED_8
  #pragma section all "EEP_RAM_VAR_POWER_ON_CLEARED_8"
#elif defined (EEP_STOP_SEC_VAR_CLEARED_8)
  #undef       EEP_STOP_SEC_VAR_CLEARED_8
  #pragma section all restore

#elif defined (EEP_START_SEC_VAR_CLEARED_16)
  #undef       EEP_START_SEC_VAR_CLEARED_16
  #pragma section all "EEP_RAM_VAR_POWER_ON_CLEARED_16"
#elif defined (EEP_STOP_SEC_VAR_CLEARED_16)
  #undef       EEP_STOP_SEC_VAR_CLEARED_16
  #pragma section all restore

#elif defined (EEP_START_SEC_VAR_CLEARED_32)
  #undef       EEP_START_SEC_VAR_CLEARED_32
  #pragma section all "EEP_RAM_VAR_POWER_ON_CLEARED_32"
#elif defined (EEP_STOP_SEC_VAR_CLEARED_32)
  #undef       EEP_STOP_SEC_VAR_CLEARED_32
  #pragma section all restore

#elif defined (EEP_START_SEC_VAR_POWER_ON_CLEARED_8)
  #undef       EEP_START_SEC_VAR_POWER_ON_CLEARED_8
  #pragma section all "EEP_RAM_VAR_POWER_ON_CLEARED_8"
#elif defined (EEP_STOP_SEC_VAR_POWER_ON_CLEARED_8)
  #undef       EEP_STOP_SEC_VAR_POWER_ON_CLEARED_8
  #pragma section all restore

#elif defined (EEP_START_SEC_VAR_POWER_ON_CLEARED_16)
  #undef       EEP_START_SEC_VAR_POWER_ON_CLEARED_16
  #pragma section all "EEP_RAM_VAR_POWER_ON_CLEARED_16"
#elif defined (EEP_STOP_SEC_VAR_POWER_ON_CLEARED_16)
  #undef       EEP_STOP_SEC_VAR_POWER_ON_CLEARED_16
  #pragma section all restore

#elif defined (EEP_START_SEC_VAR_POWER_ON_CLEARED_32)
  #undef       EEP_START_SEC_VAR_POWER_ON_CLEARED_32
  #pragma section all "EEP_RAM_VAR_POWER_ON_CLEARED_32"
#elif defined (EEP_STOP_SEC_VAR_POWER_ON_CLEARED_32)
  #undef       EEP_STOP_SEC_VAR_POWER_ON_CLEARED_32
  #pragma section all restore

#elif defined (EEP_START_SEC_CONST_UNSPECIFIED)
  #undef       EEP_START_SEC_CONST_UNSPECIFIED
  #pragma section all "EEP_ROM_CONST_UNSPECIFIED"
#elif defined (EEP_STOP_SEC_CONST_UNSPECIFIED)
  #undef       EEP_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (EEP_START_SEC_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED)
  #undef       EEP_START_SEC_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED
  #pragma section all "EEP_RAM_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED"
#elif defined (EEP_STOP_SEC_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED)
  #undef       EEP_STOP_SEC_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED
  #pragma section all restore
  
#elif defined (EEP_START_SEC_VAR_INIT_8)
  #undef       EEP_START_SEC_VAR_INIT_8
  #pragma section all "EEP_RAM_VAR_INIT_8" 
#elif defined (EEP_STOP_SEC_VAR_INIT_8)
  #undef       EEP_STOP_SEC_VAR_INIT_8
  #pragma section all restore

#elif defined (EEP_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       EEP_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all "EEP_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (EEP_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       EEP_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all restore

#elif defined (EEP_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       EEP_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "EEP_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (EEP_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       EEP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore
/* -------------------------------------------------------------------------- */
/*                                 Ea                                         */
/* -------------------------------------------------------------------------- */
#elif defined (EA_START_SEC_CODE)
  #undef       EA_START_SEC_CODE
  #pragma section code "EA_CODE"
  #pragma section farrom "EA_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "EA_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "EA_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (EA_STOP_SEC_CODE)
  #undef       EA_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (EA_START_SEC_NO_INIT_VAR_BOOLEAN)
  #undef       EA_START_SEC_NO_INIT_VAR_BOOLEAN
  #pragma section all "EA_RAM_VAR_NO_INIT_BOOLEAN"
  #pragma noclear
#elif defined (EA_STOP_SEC_NO_INIT_VAR_BOOLEAN)
  #undef       EA_STOP_SEC_NO_INIT_VAR_BOOLEAN
  #pragma clear
  #pragma section all restore

#elif defined (EA_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       EA_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "EA_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (EA_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       EA_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (EA_START_SEC_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED)
  #undef       EA_START_SEC_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED
  #pragma section all "EA_RAM_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED"
#elif defined (EA_STOP_SEC_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED)
  #undef       EA_STOP_SEC_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED
  #pragma section all restore

#elif defined (EA_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
  #undef       EA_START_SEC_VAR_SAVED_ZONE_UNSPECIFIED
  #pragma section all "EA_RAM_VAR_SAVED_ZONE_UNSPECIFIED"
  #pragma noclear
#elif defined (EA_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED)
  #undef       EA_STOP_SEC_VAR_SAVED_ZONE_UNSPECIFIED
  #pragma clear
  #pragma section all restore

#elif defined (EA_START_SEC_CONST_16)
  #undef       EA_START_SEC_CONST_16
  #pragma section all "EA_ROM_CONST_16"
#elif defined (EA_STOP_SEC_CONST_16)
  #undef       EA_STOP_SEC_CONST_16
  #pragma section all restore

#elif defined (EA_START_SEC_CONST_UNSPECIFIED)
  #undef       EA_START_SEC_CONST_UNSPECIFIED
  #pragma section all "EA_ROM_CONST_UNSPECIFIED"
#elif defined (EA_STOP_SEC_CONST_UNSPECIFIED)
  #undef       EA_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (EA_START_SEC_NO_INIT_VAR_16)
  #undef       EA_START_SEC_NO_INIT_VAR_16
  #pragma section all "EA_RAM_VAR_NO_INIT_16"
  #pragma noclear
#elif defined (EA_STOP_SEC_NO_INIT_VAR_16)
  #undef       EA_STOP_SEC_NO_INIT_VAR_16
  #pragma clear
  #pragma section all restore

#elif defined (EA_START_SEC_NO_INIT_VAR_8)
  #undef       EA_START_SEC_NO_INIT_VAR_8
  #pragma section all "EA_RAM_VAR_NO_INIT_8"
  #pragma noclear
#elif defined (EA_STOP_SEC_NO_INIT_VAR_8)
  #undef       EA_STOP_SEC_NO_INIT_VAR_8
  #pragma clear
  #pragma section all restore

#elif defined (EA_START_SEC_NO_INIT_VAR_UNSPECIFIED)
  #undef       EA_START_SEC_NO_INIT_VAR_UNSPECIFIED
  #pragma section all "EA_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#elif defined (EA_STOP_SEC_NO_INIT_VAR_UNSPECIFIED)
  #undef       EA_STOP_SEC_NO_INIT_VAR_UNSPECIFIED
  #pragma clear
  #pragma section all restore

/* -------------------------------------------------------------------------- */
/*                 RTE                                                        */
/* -------------------------------------------------------------------------- */
#elif defined (BSWMODULEDESCRIPTION_CALIB_START_SEC_CODE)
  #undef       BSWMODULEDESCRIPTION_CALIB_START_SEC_CODE
  #pragma section code "RTE_CODE"
  #pragma section farrom "RTE_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "RTE_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "RTE_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (BSWMODULEDESCRIPTION_CALIB_STOP_SEC_CODE)
  #undef       BSWMODULEDESCRIPTION_CALIB_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

/* -------------------------------------------------------------------------- */
/*                 CAL                                                        */
/* -------------------------------------------------------------------------- */
#elif defined (CAL_START_SEC_CODE)
  #undef       CAL_START_SEC_CODE
  #pragma section code " CAL_CODE"
  #pragma section farrom " CAL_ROM_CONST_UNSPECIFIED"
  #pragma section farbss " CAL_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata " CAL_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (CAL_STOP_SEC_CODE)
  #undef       CAL_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (CAL_START_SEC_CONST_32)
  #undef       CAL_START_SEC_CONST_32
  #pragma section farrom " CAL_ROM_CONST_32"
#elif defined (CAL_STOP_SEC_CONST_32)
  #undef       CAL_STOP_SEC_CONST_32
  #pragma section farrom restore

#elif defined (CAL_START_SEC_CONST_UNSPECIFIED)
  #undef       CAL_START_SEC_CONST_UNSPECIFIED
  #pragma section farrom " CAL_ROM_CONST_UNSPECIFIED"
#elif defined (CAL_STOP_SEC_CONST_UNSPECIFIED)
  #undef       CAL_STOP_SEC_CONST_UNSPECIFIED
  #pragma section farrom restore

/* -------------------------------------------------------------------------- */
/*                 CSM                                                        */
/* -------------------------------------------------------------------------- */
#elif defined (CSM_START_SEC_CODE)
  #undef       CSM_START_SEC_CODE
  #pragma section code "CSM_CODE"
  #pragma section farrom "CSM_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "CSM_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "CSM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (CSM_STOP_SEC_CODE)
  #undef       CSM_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (CSM_START_SEC_CONST_8)
  #undef       CSM_START_SEC_CONST_8
  #pragma section all "CSM_ROM_CONST_8"
#elif defined (CSM_STOP_SEC_CONST_8)
  #undef       CSM_STOP_SEC_CONST_8
  #pragma section all restore

#elif defined (CSM_START_SEC_CONST_UNSPECIFIED)
  #undef       CSM_START_SEC_CONST_UNSPECIFIED
  #pragma section all "CSM_ROM_CONST_UNSPECIFIED"
#elif defined (CSM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       CSM_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (CSM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CSM_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "CSM_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (CSM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CSM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (CSM_START_SEC_VAR_CLEARED_8)
  #undef       CSM_START_SEC_VAR_CLEARED_8
  #pragma section all="CSM_RAM_VAR_CLEARED_8"
#elif defined (CSM_STOP_SEC_VAR_CLEARED_8)
  #undef       CSM_STOP_SEC_VAR_CLEARED_8
  #pragma section all restore

#elif defined (CSM_START_SEC_VAR_CLEARED_16)
  #undef       CSM_START_SEC_VAR_CLEARED_16
  #pragma section all="CSM_RAM_VAR_CLEARED_16"
#elif defined (CSM_STOP_SEC_VAR_CLEARED_16)
  #undef       CSM_STOP_SEC_VAR_CLEARED_16
  #pragma section all restore
  
#elif defined (CSM_START_SEC_VAR_CLEARED_32)
  #undef       CSM_START_SEC_VAR_CLEARED_32
  #pragma section all="CSM_RAM_VAR_CLEARED_32"
#elif defined (CSM_STOP_SEC_VAR_CLEARED_32)
  #undef       CSM_STOP_SEC_VAR_CLEARED_32
  #pragma section all restore
    
#elif defined (CSM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       CSM_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "CSM_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#elif defined (CSM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       CSM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all restore

#elif defined (CSM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CSM_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "CSM_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (CSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore

/* -------------------------------------------------------------------------- */
/*                 CRYPTOLIB                                                  */
/* -------------------------------------------------------------------------- */
#elif defined (CRYPTOLIB_START_SEC_CODE)
  #undef       CRYPTOLIB_START_SEC_CODE
  #pragma section code "CRYPTOLIB_CODE"
  #pragma section farrom "CRYPTOLIB_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "CRYPTOLIB_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "CRYPTOLIB_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (CRYPTOLIB_STOP_SEC_CODE)
  #undef       CRYPTOLIB_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (CRYPTOLIB_START_SEC_VAR_INIT_BOOLEAN)
  #undef       CRYPTOLIB_START_SEC_VAR_INIT_BOOLEAN
  #pragma section all "CRYPTOLIB_RAM_VAR_INIT_BOOLEAN"
#elif defined (CRYPTOLIB_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       CRYPTOLIB_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma section all restore

#elif defined (CRYPTOLIB_START_SEC_VAR_INIT_8)
  #undef       CRYPTOLIB_START_SEC_VAR_INIT_8
  #pragma section all "CRYPTOLIB_RAM_VAR_INIT_8"
#elif defined (CRYPTOLIB_STOP_SEC_VAR_INIT_8)
  #undef       CRYPTOLIB_STOP_SEC_VAR_INIT_8
  #pragma section all restore

#elif defined (CRYPTOLIB_START_SEC_VAR_INIT_16)
  #undef       CRYPTOLIB_START_SEC_VAR_INIT_16
  #pragma section all "CRYPTOLIB_RAM_VAR_INIT_16"
#elif defined (CRYPTOLIB_STOP_SEC_VAR_INIT_16)
  #undef       CRYPTOLIB_STOP_SEC_VAR_INIT_16
  #pragma section all restore

#elif defined (CRYPTOLIB_START_SEC_VAR_INIT_32)
  #undef       CRYPTOLIB_START_SEC_VAR_INIT_32
  #pragma section all "CRYPTOLIB_RAM_VAR_INIT_32"
#elif defined (CRYPTOLIB_STOP_SEC_VAR_INIT_32)
  #undef       CRYPTOLIB_STOP_SEC_VAR_INIT_32
  #pragma section all restore

#elif defined (CRYPTOLIB_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CRYPTOLIB_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all "CRYPTOLIB_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (CRYPTOLIB_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       CRYPTOLIB_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all restore

#elif defined (CRYPTOLIB_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CRYPTOLIB_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "CRYPTOLIB_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (CRYPTOLIB_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       CRYPTOLIB_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (CRYPTOLIB_START_SEC_VAR_CLEARED_8)
  #undef       CRYPTOLIB_START_SEC_VAR_CLEARED_8
  #pragma section all "CRYPTOLIB_RAM_VAR_CLEARED_8"
#elif defined (CRYPTOLIB_STOP_SEC_VAR_CLEARED_8)
  #undef       CRYPTOLIB_STOP_SEC_VAR_CLEARED_8
  #pragma section all restore

#elif defined (CRYPTOLIB_START_SEC_VAR_CLEARED_32)
  #undef       CRYPTOLIB_START_SEC_VAR_CLEARED_32
  #pragma section all "CRYPTOLIB_RAM_VAR_CLEARED_32"
#elif defined (CRYPTOLIB_STOP_SEC_VAR_CLEARED_32)
  #undef       CRYPTOLIB_STOP_SEC_VAR_CLEARED_32
  #pragma section all restore

#elif defined (CRYPTOLIB_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CRYPTOLIB_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "CRYPTOLIB_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (CRYPTOLIB_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       CRYPTOLIB_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore

/* -------------------------------------------------------------------------- */
/*                 WDGIF                                                      */
/* -------------------------------------------------------------------------- */
#elif defined (WDGIF_START_SEC_CODE)
  #undef       WDGIF_START_SEC_CODE
  #pragma section code "WDGIF_CODE"
  #pragma section farrom "WDGIF_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "WDGIF_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "WDGIF_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (WDGIF_STOP_SEC_CODE)
  #undef       WDGIF_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (WDGIF_START_SEC_CONST_UNSPECIFIED)
  #undef       WDGIF_START_SEC_CONST_UNSPECIFIED
  #pragma section all "WDGIF_ROM_CONST_UNSPECIFIED"
#elif defined (WDGIF_STOP_SEC_CONST_UNSPECIFIED)
  #undef       WDGIF_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

/* ---------------------------------------------------------------------------*/
/*                           WDG_76_ACW                                       */
/* -------------------------------------------------------------------------- */
#elif defined (WDG_76_ACW_START_SEC_CODE)
  #undef       WDG_76_ACW_START_SEC_CODE
  #pragma section code "WDG_76_ACW_CODE"
  #pragma section farrom "WDG_76_ACW_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "WDG_76_ACW_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "WDG_76_ACW_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (WDG_76_ACW_STOP_SEC_CODE)
  #undef       WDG_76_ACW_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (WDG_76_ACW_START_SEC_VAR_CLEARED_32)
  #undef       WDG_76_ACW_START_SEC_VAR_CLEARED_32
  #pragma section all "WDG_76_ACW_RAM_VAR_CLEARED_32"
#elif defined (WDG_76_ACW_STOP_SEC_VAR_CLEARED_32)
  #undef       WDG_76_ACW_STOP_SEC_VAR_CLEARED_32
  #pragma section all restore

#elif defined (WDG_76_ACW_START_SEC_VAR_UNSPECIFIED)
  #undef       WDG_76_ACW_START_SEC_VAR_UNSPECIFIED
  #pragma section all "WDG_76_ACW_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (WDG_76_ACW_STOP_SEC_VAR_UNSPECIFIED)
  #undef       WDG_76_ACW_STOP_SEC_VAR_UNSPECIFIED
  #pragma section all restore

#elif defined (WDG_76_ACW_START_SEC_CONST_8)
  #undef       WDG_76_ACW_START_SEC_CONST_8
  #pragma section all "WDG_76_ACW_ROM_CONST_8"
#elif defined (WDG_76_ACW_STOP_SEC_CONST_8)
  #undef       WDG_76_ACW_STOP_SEC_CONST_8
  #pragma section all restore

#elif defined (WDG_76_ACW_START_SEC_CONST_16)
  #undef       WDG_76_ACW_START_SEC_CONST_16
  #pragma section all "WDG_76_ACW_ROM_CONST_16"
#elif defined (WDG_76_ACW_STOP_SEC_CONST_16)
  #undef       WDG_76_ACW_STOP_SEC_CONST_16
  #pragma section all restore

#elif defined (WDG_76_ACW_START_SEC_CONST_32)
  #undef       WDG_76_ACW_START_SEC_CONST_32
  #pragma section all "WDG_76_ACW_ROM_CONST_32"
#elif defined (WDG_76_ACW_STOP_SEC_CONST_32)
  #undef       WDG_76_ACW_STOP_SEC_CONST_32
  #pragma section all restore

#elif defined (WDG_76_ACW_START_SEC_CONST_UNSPECIFIED)
  #undef       WDG_76_ACW_START_SEC_CONST_UNSPECIFIED
  #pragma section all "WDG_76_ACW_ROM_CONST_UNSPECIFIED"
#elif defined (WDG_76_ACW_STOP_SEC_CONST_UNSPECIFIED)
  #undef       WDG_76_ACW_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

/* -------------------------------------------------------------------------- */
/*                 WDGM                                                       */
/* -------------------------------------------------------------------------- */

#elif defined (WDGM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       WDGM_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "WDGM_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (WDGM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       WDGM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (WDGM_START_SEC_CONST_UNSPECIFIED)
  #undef       WDGM_START_SEC_CONST_UNSPECIFIED
  #pragma section all "WDGM_ROM_CONST_UNSPECIFIED"
#elif defined (WDGM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       WDGM_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (WDGM_START_SEC_CODE)
  #undef       WDGM_START_SEC_CODE
  #pragma section code "WDGM_CODE"
  #pragma section farrom "WDGM_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "WDGM_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "WDGM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (WDGM_STOP_SEC_CODE)
  #undef       WDGM_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (WDGM_START_SEC_PUBLIC_CODE)
  #undef       WDGM_START_SEC_PUBLIC_CODE
  #pragma section code "WDGM_PUBLIC_CODE"
  #pragma section farrom "WDGM_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "WDGM_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "WDGM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (WDGM_STOP_SEC_PUBLIC_CODE)
  #undef       WDGM_STOP_SEC_PUBLIC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (WDGM_START_SEC_VAR_CLEARED_8)
  #undef       WDGM_START_SEC_VAR_CLEARED_8
  #pragma section all "WDGM_RAM_VAR_CLEARED_8"
#elif defined (WDGM_STOP_SEC_VAR_CLEARED_8)
  #undef       WDGM_STOP_SEC_VAR_CLEARED_8
  #pragma section all restore

#elif defined (WDGM_START_SEC_VAR_CLEARED_16)
  #undef       WDGM_START_SEC_VAR_CLEARED_16
  #pragma section all "WDGM_RAM_VAR_CLEARED_16"
#elif defined (WDGM_STOP_SEC_VAR_CLEARED_16)
  #undef       WDGM_STOP_SEC_VAR_CLEARED_16
  #pragma section all restore

#elif defined (WDGM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       WDGM_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "WDGM_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (WDGM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       WDGM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (WDGM_START_SEC_CONST_8)
  #undef       WDGM_START_SEC_CONST_8
  #pragma section all "WDGM_ROM_CONST_8"
#elif defined (WDGM_STOP_SEC_CONST_8)
  #undef       WDGM_STOP_SEC_CONST_8
  #pragma section all restore

#elif defined (WDGM_START_SEC_CONST_16)
  #undef       WDGM_START_SEC_CONST_16
  #pragma section all "WDGM_ROM_CONST_16"
#elif defined (WDGM_STOP_SEC_CONST_16)
  #undef       WDGM_STOP_SEC_CONST_16
  #pragma section all restore

#elif defined (WDGM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       WDGM_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "WDGM_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#elif defined (WDGM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       WDGM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma clear
  #pragma section all restore

// sinil start, 13.04.02
// WdgM_GusFreeRunningCounter
#elif defined (WDGM_START_SEC_VAR_CLEARED_32)
  #undef       WDGM_START_SEC_VAR_CLEARED_32
  #pragma section all "WDGM_RAM_VAR_CLEARED_32"
#elif defined (WDGM_STOP_SEC_VAR_CLEARED_32)
  #undef       WDGM_STOP_SEC_VAR_CLEARED_32
  #pragma section all restore
// sinil end, 13.04.02

#elif defined (WDGM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       WDGM_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all "WDGM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (WDGM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       WDGM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all restore

#elif defined (WDGM_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       WDGM_START_SEC_VAR_NO_INIT_BOOLEAN
  #pragma section all "WDGM_RAM_VAR_NO_INIT_BOOLEAN"
  #pragma noclear
#elif defined (WDGM_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       WDGM_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #pragma clear
  #pragma section all restore

/* -------------------------------------------------------------------------- */
/*			  Xcp												                                          */
/* -------------------------------------------------------------------------- */
#elif defined (XCP_START_SEC_VAR_CLEARED_8)
  #undef       XCP_START_SEC_VAR_CLEARED_8
  #pragma section all "XCP_RAM_VAR_CLEARED_8"
  #pragma align 4
#elif defined (XCP_STOP_SEC_VAR_CLEARED_8)
  #undef       XCP_STOP_SEC_VAR_CLEARED_8
  #pragma align restore
  #pragma section all restore

#elif defined (XCP_START_SEC_VAR_CLEARED_16)
  #undef       XCP_START_SEC_VAR_CLEARED_16
  #pragma section all "XCP_RAM_VAR_CLEARED_16"
  #pragma align 4
#elif defined (XCP_STOP_SEC_VAR_CLEARED_16)
  #undef       XCP_STOP_SEC_VAR_CLEARED_16
  #pragma align restore
  #pragma section all restore

#elif defined (XCP_START_SEC_CONST_8)
  #undef       XCP_START_SEC_CONST_8
  #pragma section all "XCP_ROM_CONST_8"
  #pragma align 4
#elif defined (XCP_STOP_SEC_CONST_8)
  #undef       XCP_STOP_SEC_CONST_8
  #pragma align restore
  #pragma section all restore

#elif defined (XCP_START_SEC_VAR_CLEARED_32)
  #undef       XCP_START_SEC_VAR_CLEARED_32
  #pragma section all "XCP_RAM_VAR_CLEARED_32"
  #pragma align 4
#elif defined (XCP_STOP_SEC_VAR_CLEARED_32)
  #undef       XCP_STOP_SEC_VAR_CLEARED_32
  #pragma align restore
  #pragma section all restore

#elif defined (XCP_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       XCP_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "XCP_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma align 4
#elif defined (XCP_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       XCP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma align restore
  #pragma section all restore

#elif defined (XCP_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN)
  #undef       XCP_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
  #pragma section all "XCP_RAM_VAR_CLEARED_BOOLEAN"
  #pragma align 4
#elif defined (XCP_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN)
  #undef       XCP_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
  #pragma align restore
  #pragma section all restore

#elif defined (XCP_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       XCP_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
  #pragma section all "XCP_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma align 4
#elif defined (XCP_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED)
  #undef       XCP_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
  #pragma align restore
  #pragma section all restore

#elif defined (XCP_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       XCP_START_SEC_VAR_NO_INIT_BOOLEAN
  #pragma section all "XCP_RAM_VAR_NO_INIT_BOOLEAN"
  #pragma align 4
  #pragma noclear
#elif defined (XCP_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       XCP_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #pragma clear
  #pragma align restore
  #pragma section all restore

#elif defined (XCP_START_SEC_VAR_NO_INIT_8)
  #undef       XCP_START_SEC_VAR_NO_INIT_8
  #pragma section all "XCP_RAM_VAR_NO_INIT_8"
  #pragma align 4
  #pragma noclear
#elif defined (XCP_STOP_SEC_VAR_NO_INIT_8)
  #undef       XCP_STOP_SEC_VAR_NO_INIT_8
  #pragma clear
  #pragma align restore
  #pragma section all restore

#elif defined (XCP_START_SEC_VAR_NO_INIT_32)
  #undef       XCP_START_SEC_VAR_NO_INIT_32
  #pragma section all "XCP_RAM_VAR_NO_INIT_32"
  #pragma align 4
  #pragma noclear
#elif defined (XCP_STOP_SEC_VAR_NO_INIT_32)
  #undef       XCP_STOP_SEC_VAR_NO_INIT_32
  #pragma clear
  #pragma align restore
  #pragma section all restore

#elif defined (XCP_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       XCP_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "XCP_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma align 4
  #pragma noclear
#elif defined (XCP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       XCP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma clear
  #pragma align restore
  #pragma section all restore

#elif defined (XCP_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       XCP_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "XCP_RAM_VAR_CLEARED_BOOLEAN"
  #pragma align 4
#elif defined (XCP_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       XCP_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma align restore
  #pragma section all restore

#elif defined (XCP_START_SEC_CONST_UNSPECIFIED)
  #undef       XCP_START_SEC_CONST_UNSPECIFIED
  #pragma section all "XCP_ROM_CONST_UNSPECIFIED"
  #pragma align 4
#elif defined (XCP_STOP_SEC_CONST_UNSPECIFIED)
  #undef       XCP_STOP_SEC_CONST_UNSPECIFIED
  #pragma align restore
  #pragma section all restore

#elif defined (XCP_START_SEC_CODE)
  #undef       XCP_START_SEC_CODE
  #pragma section code "XCP_CODE"
  #pragma section farrom "XCP_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "XCP_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "XCP_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (XCP_STOP_SEC_CODE)
  #undef       XCP_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (XCP_START_SEC_VAR_POWER_ON_CLEARED_8)
  #undef       XCP_START_SEC_VAR_POWER_ON_CLEARED_8
  #pragma section all "XCP_RAM_VAR_CLEARED_8"
  #pragma align 4
#elif defined (XCP_STOP_SEC_VAR_POWER_ON_CLEARED_8)
  #undef       XCP_STOP_SEC_VAR_POWER_ON_CLEARED_8
  #pragma align restore
  #pragma section all restore

#elif defined (XCP_START_SEC_VAR_CALIBRATION_ROM)
  #undef       XCP_START_SEC_VAR_CALIBRATION_ROM
  #pragma align 4
  #pragma section all "XCP_ROM_CALIBRATION_ROM"
#elif defined (XCP_STOP_SEC_VAR_CALIBRATION_ROM)
  #undef       XCP_STOP_SEC_VAR_CALIBRATION_ROM
  #pragma align restore
  #pragma section all restore

#elif defined (XCP_START_SEC_VAR_CALIBRATION_RAM)
  #undef       XCP_START_SEC_VAR_CALIBRATION_RAM
  #pragma align 4
  #pragma section all "XCP_ROM_CALIBRATION_RAM"
#elif defined (XCP_STOP_SEC_VAR_CALIBRATION_RAM)
  #undef       XCP_STOP_SEC_VAR_CALIBRATION_RAM
  #pragma align restore
  #pragma section all restore

/* -------------------------------------------------------------------------- */
/*                 CoSvAb                                                     */
/* -------------------------------------------------------------------------- */
#elif defined (COSVAB_START_SEC_CODE)
  #undef       COSVAB_START_SEC_CODE
  #pragma section code "COSVAB_CODE"
  #pragma section farrom "COSVAB_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "COSVAB_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "COSVAB_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (COSVAB_STOP_SEC_CODE)
  #undef       COSVAB_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (COSVAB_START_SEC_VAR_INIT_8)
  #undef       COSVAB_START_SEC_VAR_INIT_8
  #pragma section all "COSVAB_RAM_VAR_INIT_8"
#elif defined (COSVAB_STOP_SEC_VAR_INIT_8)
  #undef       COSVAB_STOP_SEC_VAR_INIT_8
  #pragma section all restore

#elif defined (COSVAB_START_SEC_VAR_CLEARED_32)
  #undef       COSVAB_START_SEC_VAR_CLEARED_32
  #pragma section all "COSVAB_RAM_VAR_CLEARED_32"
#elif defined (COSVAB_STOP_SEC_VAR_CLEARED_32)
  #undef       COSVAB_STOP_SEC_VAR_CLEARED_32
  #pragma section all restore

#elif defined (COSVAB_START_SEC_CONST_32)
  #undef       COSVAB_START_SEC_CONST_32
  #pragma section all "COSVAB_ROM_CONST_32"
#elif defined (COSVAB_STOP_SEC_CONST_32)
  #undef       COSVAB_STOP_SEC_CONST_32
  #pragma section all restore

#elif defined (COSVAB_START_SEC_CONST_UNSPECIFIED)
  #undef       COSVAB_START_SEC_CONST_UNSPECIFIED
  #pragma section all "COSVAB_ROM_CONST_UNSPECIFIED"
#elif defined (COSVAB_STOP_SEC_CONST_UNSPECIFIED)
  #undef       COSVAB_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

/* -------------------------------------------------------------------------- */
/*                 IoHwAb                                                     */
/* -------------------------------------------------------------------------- */
#elif defined (IOHWAB_START_SEC_CODE)
  #undef       IOHWAB_START_SEC_CODE
  #pragma section code "IOHWAB_CODE"
  #pragma section farrom "IOHWAB_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "IOHWAB_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "IOHWAB_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (IOHWAB_STOP_SEC_CODE)
  #undef       IOHWAB_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (IOHWAB_START_SEC_VAR_CLEARED_8)
  #undef       IOHWAB_START_SEC_VAR_CLEARED_8
  #pragma section all "IOHWAB_RAM_VAR_CLEARED_8"
#elif defined (IOHWAB_STOP_SEC_VAR_CLEARED_8)
  #undef       IOHWAB_STOP_SEC_VAR_CLEARED_8
  #pragma section all restore

#elif defined (IOHWAB_START_SEC_VAR_CLEARED_16)
  #undef       IOHWAB_START_SEC_VAR_CLEARED_16
  #pragma section all "IOHWAB_RAM_VAR_CLEARED_16"
#elif defined (IOHWAB_STOP_SEC_VAR_CLEARED_16)
  #undef       IOHWAB_STOP_SEC_VAR_CLEARED_16
  #pragma section all restore
#elif defined (IOHWAB_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       IOHWAB_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "IOHWAB_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (IOHWAB_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       IOHWAB_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (IOHWAB_START_SEC_CONST_8)
  #undef       IOHWAB_START_SEC_CONST_8
  #pragma section all "IOHWAB_ROM_CONST_8"
#elif defined (IOHWAB_STOP_SEC_CONST_8)
  #undef       IOHWAB_STOP_SEC_CONST_8
  #pragma section all restore

#elif defined (IOHWAB_START_SEC_CONST_16)
  #undef       IOHWAB_START_SEC_CONST_16
  #pragma section all "IOHWAB_ROM_CONST_16"
#elif defined (IOHWAB_STOP_SEC_CONST_16)
  #undef       IOHWAB_STOP_SEC_CONST_16
  #pragma section all restore

#elif defined (IOHWAB_START_SEC_CONST_UNSPECIFIED)
  #undef       IOHWAB_START_SEC_CONST_UNSPECIFIED
  #pragma section all "IOHWAB_ROM_CONST_UNSPECIFIED"
#elif defined (IOHWAB_STOP_SEC_CONST_UNSPECIFIED)
  #undef       IOHWAB_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

/* -------------------------------------------------------------------------- */
/*                               J1939TP                                      */
/* -------------------------------------------------------------------------- */
#elif defined (J1939TP_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       J1939TP_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "J1939TP_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (J1939TP_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       J1939TP_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (J1939TP_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       J1939TP_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "J1939TP_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#elif defined (J1939TP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       J1939TP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma clear
  #pragma section all restore

#elif defined (J1939TP_START_SEC_CONST_8)
  #undef       J1939TP_START_SEC_CONST_8
  #pragma section all "J1939TP_ROM_CONST_8"
#elif defined (J1939TP_STOP_SEC_CONST_8)
  #undef       J1939TP_STOP_SEC_CONST_8
  #pragma section all restore

#elif defined (J1939TP_START_SEC_CONST_16)
  #undef       J1939TP_START_SEC_CONST_16
  #pragma section all "J1939TP_ROM_CONST_16"
#elif defined (J1939TP_STOP_SEC_CONST_16)
  #undef       J1939TP_STOP_SEC_CONST_16
  #pragma section all restore

#elif defined (J1939TP_START_SEC_CONST_UNSPECIFIED)
  #undef       J1939TP_START_SEC_CONST_UNSPECIFIED
  #pragma section all "J1939TP_ROM_CONST_UNSPECIFIED"
#elif defined (J1939TP_STOP_SEC_CONST_UNSPECIFIED)
  #undef       J1939TP_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (J1939TP_START_SEC_CODE)
  #undef       J1939TP_START_SEC_CODE
  #pragma section code "J1939TP_CODE"
  #pragma section farrom "J1939TP_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "J1939TP_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "J1939TP_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (J1939TP_STOP_SEC_CODE)
  #undef       J1939TP_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

/* -------------------------------------------------------------------------- */
/*                               J1939Rm                                      */
/* -------------------------------------------------------------------------- */
#elif defined (J1939RM_START_SEC_VAR_NO_INIT_8)
  #undef       J1939RM_START_SEC_VAR_NO_INIT_8
  #pragma section all "J1939RM_RAM_VAR_NO_INIT_8"
  #pragma noclear
#elif defined (J1939RM_STOP_SEC_VAR_NO_INIT_8)
  #undef       J1939RM_STOP_SEC_VAR_NO_INIT_8
  #pragma clear
  #pragma section all restore

#elif defined (J1939RM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       J1939RM_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "J1939RM_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#elif defined (J1939RM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       J1939RM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma clear
  #pragma section all restore

#elif defined (J1939RM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       J1939RM_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "J1939RM_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (J1939RM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       J1939RM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (J1939RM_START_SEC_VAR_CLEARED_8)
  #undef       J1939RM_START_SEC_VAR_CLEARED_8
  #pragma section all "J1939RM_RAM_VAR_CLEARED_8"
#elif defined (J1939RM_STOP_SEC_VAR_CLEARED_8)
  #undef       J1939RM_STOP_SEC_VAR_CLEARED_8
  #pragma section all restore

#elif defined (J1939RM_START_SEC_VAR_CLEARED_16)
  #undef       J1939RM_START_SEC_VAR_CLEARED_16
  #pragma section all "J1939RM_RAM_VAR_CLEARED_16"
#elif defined (J1939RM_STOP_SEC_VAR_CLEARED_16)
  #undef       J1939RM_STOP_SEC_VAR_CLEARED_16
  #pragma section all restore

#elif defined (J1939RM_START_SEC_VAR_INIT_8)
  #undef       J1939RM_START_SEC_VAR_INIT_8
  #pragma section all "J1939RM_RAM_VAR_INIT_8"
#elif defined (J1939RM_STOP_SEC_VAR_INIT_8)
  #undef       J1939RM_STOP_SEC_VAR_INIT_8
  #pragma section all restore

#elif defined (J1939RM_START_SEC_VAR_INIT_32)
  #undef       J1939RM_START_SEC_VAR_INIT_32
  #pragma section all "J1939RM_RAM_VAR_INIT_32"
#elif defined (J1939RM_STOP_SEC_VAR_INIT_32)
  #undef       J1939RM_STOP_SEC_VAR_INIT_32
  #pragma section all restore

#elif defined (J1939RM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       J1939RM_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all "J1939RM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (J1939RM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       J1939RM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all restore

#elif defined (J1939RM_START_SEC_CONST_8)
  #undef       J1939RM_START_SEC_CONST_8
  #pragma section all "J1939RM_ROM_CONST_8"
#elif defined (J1939RM_STOP_SEC_CONST_8)
  #undef       J1939RM_STOP_SEC_CONST_8
  #pragma section all restore

#elif defined (J1939RM_START_SEC_CONST_UNSPECIFIED)
  #undef       J1939RM_START_SEC_CONST_UNSPECIFIED
  #pragma section all "J1939RM_ROM_CONST_UNSPECIFIED"
#elif defined (J1939RM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       J1939RM_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (J1939RM_START_SEC_CODE)
  #undef       J1939RM_START_SEC_CODE
  #pragma section code "J1939RM_CODE"
  #pragma section farrom "J1939RM_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "J1939RM_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "J1939RM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (J1939RM_STOP_SEC_CODE)
  #undef       J1939RM_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (J1939RM_START_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED)
  #undef       J1939RM_START_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED
  #pragma section all "J1939RM_ROM_CONFIG_UNSPECIFIED"
#elif defined (J1939RM_STOP_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED)
  #undef       J1939RM_STOP_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED
  #pragma section all restore

/* -------------------------------------------------------------------------- */
/*                               J1939Nm                                      */
/* -------------------------------------------------------------------------- */
#elif defined (J1939NM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       J1939NM_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "J1939NM_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (J1939NM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       J1939NM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (J1939NM_START_SEC_VAR_CLEARED_8)
  #undef       J1939NM_START_SEC_VAR_CLEARED_8
  #pragma section all "J1939NM_RAM_VAR_CLEARED_8"
#elif defined (J1939NM_STOP_SEC_VAR_CLEARED_8)
  #undef       J1939NM_STOP_SEC_VAR_CLEARED_8
  #pragma section all restore

#elif defined (J1939NM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       J1939NM_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "J1939NM_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#elif defined (J1939NM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       J1939NM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma clear
  #pragma section all restore

#elif defined (J1939NM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       J1939NM_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all "J1939NM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (J1939NM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       J1939NM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all restore

#elif defined (J1939NM_START_SEC_CONST_8)
  #undef       J1939NM_START_SEC_CONST_8
  #pragma section all "J1939NM_ROM_CONST_8"
#elif defined (J1939NM_STOP_SEC_CONST_8)
  #undef       J1939NM_STOP_SEC_CONST_8
  #pragma section all restore

#elif defined (J1939NM_START_SEC_CONST_UNSPECIFIED)
  #undef       J1939NM_START_SEC_CONST_UNSPECIFIED
  #pragma section all "J1939NM_ROM_CONST_UNSPECIFIED"
#elif defined (J1939NM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       J1939NM_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (J1939NM_START_SEC_CODE)
  #undef       J1939NM_START_SEC_CODE
  #pragma section code "J1939NM_CODE"
  #pragma section farrom "J1939NM_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "J1939NM_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "J1939NM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (J1939NM_STOP_SEC_CODE)
  #undef       J1939NM_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

/* -------------------------------------------------------------------------- */
/*                               J1939Dcm                                     */
/* -------------------------------------------------------------------------- */
#elif defined (J1939DCM_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       J1939DCM_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "J1939DCM_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (J1939DCM_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       J1939DCM_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (J1939DCM_START_SEC_VAR_NO_INIT_8)
  #undef       J1939DCM_START_SEC_VAR_NO_INIT_8
  #pragma section all "J1939DCM_RAM_VAR_NO_INIT_8"
  #pragma noclear
#elif defined (J1939DCM_STOP_SEC_VAR_NO_INIT_8)
  #undef       J1939DCM_STOP_SEC_VAR_NO_INIT_8
  #pragma clear
  #pragma section all restore

#elif defined (J1939DCM_START_SEC_VAR_NO_INIT_32)
  #undef       J1939DCM_START_SEC_VAR_NO_INIT_32
  #pragma section all "J1939DCM_RAM_VAR_NO_INIT_32"
  #pragma noclear
#elif defined (J1939DCM_STOP_SEC_VAR_NO_INIT_32)
  #undef       J1939DCM_STOP_SEC_VAR_NO_INIT_32
  #pragma clear
  #pragma section all restore

#elif defined (J1939DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       J1939DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "J1939DCM_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#elif defined (J1939DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       J1939DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma clear
  #pragma section all restore

#elif defined (J1939DCM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       J1939DCM_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all "J1939DCM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (J1939DCM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       J1939DCM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all restore

#elif defined (J1939DCM_START_SEC_CONST_INIT_UNSPECIFIED)
  #undef       J1939DCM_START_SEC_CONST_INIT_UNSPECIFIED
  #pragma section all "J1939DCM_ROM_CONST_INIT_UNSPECIFIED"
#elif defined (J1939DCM_STOP_SEC_CONST_INIT_UNSPECIFIED)
  #undef       J1939DCM_STOP_SEC_CONST_INIT_UNSPECIFIED
  #pragma section all restore

#elif defined (J1939DCM_START_SEC_CONST_8)
  #undef       J1939DCM_START_SEC_CONST_8
  #pragma section all "J1939DCM_ROM_CONST_8"
#elif defined (J1939DCM_STOP_SEC_CONST_8)
  #undef       J1939DCM_STOP_SEC_CONST_8
  #pragma section all restore

#elif defined (J1939DCM_START_SEC_CONST_32)
  #undef       J1939DCM_START_SEC_CONST_32
  #pragma section all "J1939DCM_ROM_CONST_32"
#elif defined (J1939DCM_STOP_SEC_CONST_32)
  #undef       J1939DCM_STOP_SEC_CONST_32
  #pragma section all restore

#elif defined (J1939DCM_START_SEC_CONST_UNSPECIFIED)
  #undef       J1939DCM_START_SEC_CONST_UNSPECIFIED
  #pragma section all "J1939DCM_ROM_CONST_UNSPECIFIED"
#elif defined (J1939DCM_STOP_SEC_CONST_UNSPECIFIED)
  #undef       J1939DCM_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (J1939DCM_START_SEC_CODE)
  #undef       J1939DCM_START_SEC_CODE
  #pragma section code "J1939DCM_CODE"
  #pragma section farrom "J1939DCM_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "J1939DCM_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "J1939DCM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (J1939DCM_STOP_SEC_CODE)
  #undef       J1939DCM_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

/* -------------------------------------------------------------------------- */
/*                              OS Profiler                                   */
/* -------------------------------------------------------------------------- */

#elif defined (OPF_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       OPF_START_SEC_VAR_NO_INIT_BOOLEAN
  #pragma section all "OPF_RAM_VAR_NO_INIT_BOOLEAN"
  #pragma noclear
#elif defined (OPF_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       OPF_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #pragma clear
  #pragma section all restore

#elif defined (OPF_START_SEC_VAR_NO_INIT_8)
  #undef       OPF_START_SEC_VAR_NO_INIT_8
  #pragma section all "OPF_RAM_VAR_NO_INIT_8"
  #pragma noclear
#elif defined (OPF_STOP_SEC_VAR_NO_INIT_8)
  #undef       OPF_STOP_SEC_VAR_NO_INIT_8
  #pragma clear
  #pragma section all restore

#elif defined (OPF_START_SEC_VAR_NO_INIT_16)
  #undef       OPF_START_SEC_VAR_NO_INIT_16
  #pragma section all "OPF_RAM_VAR_NO_INIT_16"
  #pragma noclear
#elif defined (OPF_STOP_SEC_VAR_NO_INIT_16)
  #undef       OPF_STOP_SEC_VAR_NO_INIT_16
  #pragma clear
  #pragma section all restore

#elif defined (OPF_START_SEC_VAR_NO_INIT_32)
  #undef       OPF_START_SEC_VAR_NO_INIT_32
  #pragma section all "OPF_RAM_VAR_NO_INIT_32"
  #pragma align 4
  #pragma noclear
#elif defined (OPF_STOP_SEC_VAR_NO_INIT_32)
  #undef       OPF_STOP_SEC_VAR_NO_INIT_32
  #pragma clear
  #pragma align restore
  #pragma section all restore

#elif defined (OPF_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       OPF_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "OPF_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#elif defined (OPF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       OPF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma clear
  #pragma section all restore

#elif defined (OPF_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       OPF_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "OPF_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (OPF_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       OPF_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (OPF_START_SEC_VAR_CLEARED_8)
  #undef       OPF_START_SEC_VAR_CLEARED_8
  #pragma section all "OPF_RAM_VAR_CLEARED_8"
#elif defined (OPF_STOP_SEC_VAR_CLEARED_8)
  #undef       OPF_STOP_SEC_VAR_CLEARED_8
  #pragma section all restore

#elif defined (OPF_START_SEC_VAR_CLEARED_16)
  #undef       OPF_START_SEC_VAR_CLEARED_16
  #pragma section all "OPF_RAM_VAR_CLEARED_16"
#elif defined (OPF_STOP_SEC_VAR_CLEARED_16)
  #undef       OPF_STOP_SEC_VAR_CLEARED_16
  #pragma section all restore

#elif defined (OPF_START_SEC_VAR_CLEARED_32)
  #undef       OPF_START_SEC_VAR_CLEARED_32
  #pragma section all "OPF_RAM_VAR_CLEARED_32"
  #pragma align 4
#elif defined (OPF_STOP_SEC_VAR_CLEARED_32)
  #undef       OPF_STOP_SEC_VAR_CLEARED_32
  #pragma align restore
  #pragma section all restore

#elif defined (OPF_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OPF_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "OPF_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (OPF_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OPF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (OPF_START_CORE1_SEC_VAR_CLEARED_BOOLEAN)
  #undef       OPF_START_CORE1_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "OPF_RAM_CORE1_VAR_CLEARED_BOOLEAN"
#elif defined (OPF_STOP_CORE1_SEC_VAR_CLEARED_BOOLEAN)
  #undef       OPF_STOP_CORE1_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (OPF_START_CORE1_SEC_VAR_CLEARED_8)
  #undef       OPF_START_CORE1_SEC_VAR_CLEARED_8
  #pragma section all "OPF_RAM_CORE1_VAR_CLEARED_8"
#elif defined (OPF_STOP_CORE1_SEC_VAR_CLEARED_8)
  #undef       OPF_STOP_CORE1_SEC_VAR_CLEARED_8
  #pragma section all restore

#elif defined (OPF_START_CORE1_SEC_VAR_CLEARED_16)
  #undef       OPF_START_CORE1_SEC_VAR_CLEARED_16
  #pragma section all "OPF_RAM_CORE1_VAR_CLEARED_16"
#elif defined (OPF_STOP_CORE1_SEC_VAR_CLEARED_16)
  #undef       OPF_STOP_CORE1_SEC_VAR_CLEARED_16
  #pragma section all restore

#elif defined (OPF_START_CORE1_SEC_VAR_CLEARED_32)
  #undef       OPF_START_CORE1_SEC_VAR_CLEARED_32
  #pragma section all "OPF_RAM_CORE1_VAR_CLEARED_32"
  #pragma align 4
#elif defined (OPF_STOP_CORE1_SEC_VAR_CLEARED_32)
  #undef       OPF_STOP_CORE1_SEC_VAR_CLEARED_32
  #pragma align restore
  #pragma section all restore

#elif defined (OPF_START_CORE1_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OPF_START_CORE1_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "OPF_RAM_CORE1_VAR_CLEARED_UNSPECIFIED"
#elif defined (OPF_STOP_CORE1_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OPF_STOP_CORE1_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (OPF_START_CORE2_SEC_VAR_CLEARED_BOOLEAN)
  #undef       OPF_START_CORE2_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "OPF_RAM_CORE2_VAR_CLEARED_BOOLEAN"
#elif defined (OPF_STOP_CORE2_SEC_VAR_CLEARED_BOOLEAN)
  #undef       OPF_STOP_CORE2_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (OPF_START_CORE2_SEC_VAR_CLEARED_8)
  #undef       OPF_START_CORE2_SEC_VAR_CLEARED_8
  #pragma section all "OPF_RAM_CORE2_VAR_CLEARED_8"
#elif defined (OPF_STOP_CORE2_SEC_VAR_CLEARED_8)
  #undef       OPF_STOP_CORE2_SEC_VAR_CLEARED_8
  #pragma section all restore

#elif defined (OPF_START_CORE2_SEC_VAR_CLEARED_16)
  #undef       OPF_START_CORE2_SEC_VAR_CLEARED_16
  #pragma section all "OPF_RAM_CORE2_VAR_CLEARED_16"
#elif defined (OPF_STOP_CORE2_SEC_VAR_CLEARED_16)
  #undef       OPF_STOP_CORE2_SEC_VAR_CLEARED_16
  #pragma section all restore

#elif defined (OPF_START_CORE2_SEC_VAR_CLEARED_32)
  #undef       OPF_START_CORE2_SEC_VAR_CLEARED_32
  #pragma section all "OPF_RAM_CORE2_VAR_CLEARED_32"
  #pragma align 4
#elif defined (OPF_STOP_CORE2_SEC_VAR_CLEARED_32)
  #undef       OPF_STOP_CORE2_SEC_VAR_CLEARED_32
  #pragma align restore
  #pragma section all restore

#elif defined (OPF_START_CORE2_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OPF_START_CORE2_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "OPF_RAM_CORE2_VAR_CLEARED_UNSPECIFIED"
#elif defined (OPF_STOP_CORE2_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OPF_STOP_CORE2_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (OPF_START_CORE3_SEC_VAR_CLEARED_BOOLEAN)
  #undef       OPF_START_CORE3_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "OPF_RAM_CORE3_VAR_CLEARED_BOOLEAN"
#elif defined (OPF_STOP_CORE3_SEC_VAR_CLEARED_BOOLEAN)
  #undef       OPF_STOP_CORE3_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (OPF_START_CORE3_SEC_VAR_CLEARED_8)
  #undef       OPF_START_CORE3_SEC_VAR_CLEARED_8
  #pragma section all "OPF_RAM_CORE3_VAR_CLEARED_8"
#elif defined (OPF_STOP_CORE3_SEC_VAR_CLEARED_8)
  #undef       OPF_STOP_CORE3_SEC_VAR_CLEARED_8
  #pragma section all restore

#elif defined (OPF_START_CORE3_SEC_VAR_CLEARED_16)
  #undef       OPF_START_CORE3_SEC_VAR_CLEARED_16
  #pragma section all "OPF_RAM_CORE3_VAR_CLEARED_16"
#elif defined (OPF_STOP_CORE3_SEC_VAR_CLEARED_16)
  #undef       OPF_STOP_CORE3_SEC_VAR_CLEARED_16
  #pragma section all restore

#elif defined (OPF_START_CORE3_SEC_VAR_CLEARED_32)
  #undef       OPF_START_CORE3_SEC_VAR_CLEARED_32
  #pragma section all "OPF_RAM_CORE3_VAR_CLEARED_32"
  #pragma align 4
#elif defined (OPF_STOP_CORE3_SEC_VAR_CLEARED_32)
  #undef       OPF_STOP_CORE3_SEC_VAR_CLEARED_32
  #pragma align restore
  #pragma section all restore

#elif defined (OPF_START_CORE3_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OPF_START_CORE3_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "OPF_RAM_CORE3_VAR_CLEARED_UNSPECIFIED"
#elif defined (OPF_STOP_CORE3_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OPF_STOP_CORE3_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (OPF_START_CORE4_SEC_VAR_CLEARED_BOOLEAN)
  #undef       OPF_START_CORE4_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "OPF_RAM_CORE4_VAR_CLEARED_BOOLEAN"
#elif defined (OPF_STOP_CORE4_SEC_VAR_CLEARED_BOOLEAN)
  #undef       OPF_STOP_CORE4_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (OPF_START_CORE4_SEC_VAR_CLEARED_8)
  #undef       OPF_START_CORE4_SEC_VAR_CLEARED_8
  #pragma section all "OPF_RAM_CORE4_VAR_CLEARED_8"
#elif defined (OPF_STOP_CORE4_SEC_VAR_CLEARED_8)
  #undef       OPF_STOP_CORE4_SEC_VAR_CLEARED_8
  #pragma section all restore

#elif defined (OPF_START_CORE4_SEC_VAR_CLEARED_16)
  #undef       OPF_START_CORE4_SEC_VAR_CLEARED_16
  #pragma section all "OPF_RAM_CORE4_VAR_CLEARED_16"
#elif defined (OPF_STOP_CORE4_SEC_VAR_CLEARED_16)
  #undef       OPF_STOP_CORE4_SEC_VAR_CLEARED_16
  #pragma section all restore

#elif defined (OPF_START_CORE4_SEC_VAR_CLEARED_32)
  #undef       OPF_START_CORE4_SEC_VAR_CLEARED_32
  #pragma section all "OPF_RAM_CORE4_VAR_CLEARED_32"
  #pragma align 4
#elif defined (OPF_STOP_CORE4_SEC_VAR_CLEARED_32)
  #undef       OPF_STOP_CORE4_SEC_VAR_CLEARED_32
  #pragma align restore
  #pragma section all restore

#elif defined (OPF_START_CORE4_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OPF_START_CORE4_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "OPF_RAM_CORE4_VAR_CLEARED_UNSPECIFIED"
#elif defined (OPF_STOP_CORE4_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OPF_STOP_CORE4_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (OPF_START_CORE5_SEC_VAR_CLEARED_BOOLEAN)
  #undef       OPF_START_CORE5_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "OPF_RAM_CORE5_VAR_CLEARED_BOOLEAN"
#elif defined (OPF_STOP_CORE5_SEC_VAR_CLEARED_BOOLEAN)
  #undef       OPF_STOP_CORE5_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (OPF_START_CORE5_SEC_VAR_CLEARED_8)
  #undef       OPF_START_CORE5_SEC_VAR_CLEARED_8
  #pragma section all "OPF_RAM_CORE5_VAR_CLEARED_8"
#elif defined (OPF_STOP_CORE5_SEC_VAR_CLEARED_8)
  #undef       OPF_STOP_CORE5_SEC_VAR_CLEARED_8
  #pragma section all restore

#elif defined (OPF_START_CORE5_SEC_VAR_CLEARED_16)
  #undef       OPF_START_CORE5_SEC_VAR_CLEARED_16
  #pragma section all "OPF_RAM_CORE5_VAR_CLEARED_16"
#elif defined (OPF_STOP_CORE5_SEC_VAR_CLEARED_16)
  #undef       OPF_STOP_CORE5_SEC_VAR_CLEARED_16
  #pragma section all restore

#elif defined (OPF_START_CORE5_SEC_VAR_CLEARED_32)
  #undef       OPF_START_CORE5_SEC_VAR_CLEARED_32
  #pragma section all "OPF_RAM_CORE5_VAR_CLEARED_32"
  #pragma align 4
#elif defined (OPF_STOP_CORE5_SEC_VAR_CLEARED_32)
  #undef       OPF_STOP_CORE5_SEC_VAR_CLEARED_32
  #pragma align restore
  #pragma section all restore

#elif defined (OPF_START_CORE5_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OPF_START_CORE5_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "OPF_RAM_CORE5_VAR_CLEARED_UNSPECIFIED"
#elif defined (OPF_STOP_CORE5_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OPF_STOP_CORE5_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (OPF_START_SEC_VAR_INIT_BOOLEAN)
  #undef       OPF_START_SEC_VAR_INIT_BOOLEAN
  #pragma section all "OPF_RAM_VAR_INIT_BOOLEAN"
#elif defined (OPF_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       OPF_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma section all restore

#elif defined (OPF_START_SEC_VAR_INIT_8)
  #undef       OPF_START_SEC_VAR_INIT_8
  #pragma section all "OPF_RAM_VAR_INIT_8"
#elif defined (OPF_STOP_SEC_VAR_INIT_8)
  #undef       OPF_STOP_SEC_VAR_INIT_8
  #pragma section all restore

#elif defined (OPF_START_SEC_VAR_INIT_16)
  #undef       OPF_START_SEC_VAR_INIT_16
  #pragma section all "OPF_RAM_VAR_INIT_16"
#elif defined (OPF_STOP_SEC_VAR_INIT_16)
  #undef       OPF_STOP_SEC_VAR_INIT_16
  #pragma section all restore

#elif defined (OPF_START_SEC_VAR_INIT_32)
  #undef       OPF_START_SEC_VAR_INIT_32
  #pragma section all "OPF_RAM_VAR_INIT_32"
  #pragma align 4
#elif defined (OPF_STOP_SEC_VAR_INIT_32)
  #undef       OPF_STOP_SEC_VAR_INIT_32
  #pragma align restore
  #pragma section all restore

#elif defined (OPF_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       OPF_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all "OPF_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (OPF_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       OPF_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all restore

#elif defined (OPF_START_SEC_CONST_BOOLEAN)
  #undef       OPF_START_SEC_CONST_BOOLEAN
  #pragma section all "OPF_ROM_CONST_BOOLEAN"
#elif defined (OPF_STOP_SEC_CONST_BOOLEAN)
  #undef       OPF_STOP_SEC_CONST_BOOLEAN
  #pragma section all restore

#elif defined (OPF_START_SEC_CONST_8)
  #undef       OPF_START_SEC_CONST_8
  #pragma section all "OPF_ROM_CONST_8"
#elif defined (OPF_STOP_SEC_CONST_8)
  #undef       OPF_STOP_SEC_CONST_8
  #pragma section all restore

#elif defined (OPF_START_SEC_CONST_16)
  #undef       OPF_START_SEC_CONST_16
  #pragma section all "OPF_ROM_CONST_16"
#elif defined (OPF_STOP_SEC_CONST_16)
  #undef       OPF_STOP_SEC_CONST_16
  #pragma section all restore

#elif defined (OPF_START_SEC_CONST_32)
  #undef       OPF_START_SEC_CONST_32
  #pragma section all "OPF_ROM_CONST_32"
  #pragma align 4
#elif defined (OPF_STOP_SEC_CONST_32)
  #undef       OPF_STOP_SEC_CONST_32
  #pragma align restore
  #pragma section all restore

#elif defined (OPF_START_SEC_CONST_UNSPECIFIED)
  #undef       OPF_START_SEC_CONST_UNSPECIFIED
  #pragma section all "OPF_ROM_CONST_UNSPECIFIED"
#elif defined (OPF_STOP_SEC_CONST_UNSPECIFIED)
  #undef       OPF_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (OPF_START_SEC_CODE)
  #undef       OPF_START_SEC_CODE
  #pragma section code "OPF_CODE"
  #pragma section farrom "OPF_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "OPF_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "OPF_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (OPF_STOP_SEC_CODE)
  #undef       OPF_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

/* -------------------------------------------------------------------------- */
/*                              OS Profiler CDD                               */
/* -------------------------------------------------------------------------- */

#elif defined (OSPROFILERCDD_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       OSPROFILERCDD_START_SEC_VAR_NO_INIT_BOOLEAN
  #pragma section all "OSPROFILERCDD_RAM_VAR_NO_INIT_BOOLEAN"
  #pragma noclear
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #pragma clear
  #pragma section all restore

#elif defined (OSPROFILERCDD_START_SEC_VAR_NO_INIT_8)
  #undef       OSPROFILERCDD_START_SEC_VAR_NO_INIT_8
  #pragma section all "OSPROFILERCDD_RAM_VAR_NO_INIT_8"
  #pragma noclear
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_NO_INIT_8)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_NO_INIT_8
  #pragma clear
  #pragma section all restore

#elif defined (OSPROFILERCDD_START_SEC_VAR_NO_INIT_16)
  #undef       OSPROFILERCDD_START_SEC_VAR_NO_INIT_16
  #pragma section all "OSPROFILERCDD_RAM_VAR_NO_INIT_16"
  #pragma noclear
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_NO_INIT_16)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_NO_INIT_16
  #pragma clear
  #pragma section all restore

#elif defined (OSPROFILERCDD_START_SEC_VAR_NO_INIT_32)
  #undef       OSPROFILERCDD_START_SEC_VAR_NO_INIT_32
  #pragma section all "OSPROFILERCDD_RAM_VAR_NO_INIT_32"
  #pragma align 4
  #pragma noclear
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_NO_INIT_32)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_NO_INIT_32
  #pragma clear
  #pragma align restore
  #pragma section all restore

#elif defined (OSPROFILERCDD_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       OSPROFILERCDD_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "OSPROFILERCDD_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma clear
  #pragma section all restore

#elif defined (OSPROFILERCDD_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       OSPROFILERCDD_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "OSPROFILERCDD_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (OSPROFILERCDD_START_SEC_VAR_CLEARED_8)
  #undef       OSPROFILERCDD_START_SEC_VAR_CLEARED_8
  #pragma section all "OSPROFILERCDD_RAM_VAR_CLEARED_8"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_CLEARED_8)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_CLEARED_8
  #pragma section all restore

#elif defined (OSPROFILERCDD_START_SEC_VAR_CLEARED_16)
  #undef       OSPROFILERCDD_START_SEC_VAR_CLEARED_16
  #pragma section all "OSPROFILERCDD_RAM_VAR_CLEARED_16"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_CLEARED_16)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_CLEARED_16
  #pragma section all restore

#elif defined (OSPROFILERCDD_START_SEC_VAR_CLEARED_32)
  #undef       OSPROFILERCDD_START_SEC_VAR_CLEARED_32
  #pragma section all "OSPROFILERCDD_RAM_VAR_CLEARED_32"
  #pragma align 4
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_CLEARED_32)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_CLEARED_32
  #pragma align restore
  #pragma section all restore

#elif defined (OSPROFILERCDD_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OSPROFILERCDD_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "OSPROFILERCDD_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (OSPROFILERCDD_START_SEC_VAR_INIT_BOOLEAN)
  #undef       OSPROFILERCDD_START_SEC_VAR_INIT_BOOLEAN
  #pragma section all "OSPROFILERCDD_RAM_VAR_INIT_BOOLEAN"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma section all restore

#elif defined (OSPROFILERCDD_START_SEC_VAR_INIT_8)
  #undef       OSPROFILERCDD_START_SEC_VAR_INIT_8
  #pragma section all "OSPROFILERCDD_RAM_VAR_INIT_8"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_INIT_8)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_INIT_8
  #pragma section all restore

#elif defined (OSPROFILERCDD_START_SEC_VAR_INIT_16)
  #undef       OSPROFILERCDD_START_SEC_VAR_INIT_16
  #pragma section all "OSPROFILERCDD_RAM_VAR_INIT_16"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_INIT_16)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_INIT_16
  #pragma section all restore

#elif defined (OSPROFILERCDD_START_SEC_VAR_INIT_32)
  #undef       OSPROFILERCDD_START_SEC_VAR_INIT_32
  #pragma section all "OSPROFILERCDD_RAM_VAR_INIT_32"
  #pragma align 4
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_INIT_32)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_INIT_32
  #pragma align restore
  #pragma section all restore

#elif defined (OSPROFILERCDD_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       OSPROFILERCDD_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all "OSPROFILERCDD_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (OSPROFILERCDD_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       OSPROFILERCDD_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all restore

#elif defined (OSPROFILERCDD_START_SEC_CONST_BOOLEAN)
  #undef       OSPROFILERCDD_START_SEC_CONST_BOOLEAN
  #pragma section all "OSPROFILERCDD_ROM_CONST_BOOLEAN"
#elif defined (OSPROFILERCDD_STOP_SEC_CONST_BOOLEAN)
  #undef       OSPROFILERCDD_STOP_SEC_CONST_BOOLEAN
  #pragma section all restore

#elif defined (OSPROFILERCDD_START_SEC_CONST_8)
  #undef       OSPROFILERCDD_START_SEC_CONST_8
  #pragma section all "OSPROFILERCDD_ROM_CONST_8"
#elif defined (OSPROFILERCDD_STOP_SEC_CONST_8)
  #undef       OSPROFILERCDD_STOP_SEC_CONST_8
  #pragma section all restore

#elif defined (OSPROFILERCDD_START_SEC_CONST_16)
  #undef       OSPROFILERCDD_START_SEC_CONST_16
  #pragma section all "OSPROFILERCDD_ROM_CONST_16"
#elif defined (OSPROFILERCDD_STOP_SEC_CONST_16)
  #undef       OSPROFILERCDD_STOP_SEC_CONST_16
  #pragma section all restore

#elif defined (OSPROFILERCDD_START_SEC_CONST_32)
  #undef       OSPROFILERCDD_START_SEC_CONST_32
  #pragma section all "OSPROFILERCDD_ROM_CONST_32"
  #pragma align 4
#elif defined (OSPROFILERCDD_STOP_SEC_CONST_32)
  #undef       OSPROFILERCDD_STOP_SEC_CONST_32
  #pragma align restore
  #pragma section all restore

#elif defined (OSPROFILERCDD_START_SEC_CONST_UNSPECIFIED)
  #undef       OSPROFILERCDD_START_SEC_CONST_UNSPECIFIED
  #pragma section all "OSPROFILERCDD_ROM_CONST_UNSPECIFIED"
#elif defined (OSPROFILERCDD_STOP_SEC_CONST_UNSPECIFIED)
  #undef       OSPROFILERCDD_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (OSPROFILERCDD_START_SEC_CODE)
  #undef       OSPROFILERCDD_START_SEC_CODE
  #pragma section code "OSPROFILERCDD_CODE"
  #pragma section farrom "OSPROFILERCDD_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "OSPROFILERCDD_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "OSPROFILERCDD_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (OSPROFILERCDD_STOP_SEC_CODE)
  #undef       OSPROFILERCDD_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore


/* -------------------------------------------------------------------------- */
/*                                 RamTst                                     */
/* -------------------------------------------------------------------------- */
#elif defined (RAMTST_START_SEC_CODE)
#undef RAMTST_START_SEC_CODE
#pragma section code " RAMTST_CODE"
#pragma section farrom " RAMTST_ROM_CONST_UNSPECIFIED"
#pragma section farbss " RAMTST_RAM_VAR_CLEARED_UNSPECIFIED"
#pragma section fardata " RAMTST_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (RAMTST_STOP_SEC_CODE)
#undef RAMTST_STOP_SEC_CODE
#pragma section fardata restore
#pragma section farbss restore
#pragma section farrom restore
#pragma section code restore

#elif defined (RAMTST_START_SEC_VAR_CLEARED_BOOLEAN)
#undef RAMTST_START_SEC_VAR_CLEARED_BOOLEAN
#pragma section all "RAMTST_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (RAMTST_STOP_SEC_VAR_CLEARED_BOOLEAN)
#undef RAMTST_STOP_SEC_VAR_CLEARED_BOOLEAN
#pragma section all restore

#elif defined (RAMTST_START_SEC_VAR_CLEARED_UNSPECIFIED)
#undef RAMTST_START_SEC_VAR_CLEARED_UNSPECIFIED
#pragma section all "RAMTST_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (RAMTST_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
#undef RAMTST_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#pragma section all restore

#elif defined (RAMTST_START_SEC_CONST_UNSPECIFIED)
#undef RAMTST_START_SEC_CONST_UNSPECIFIED
#pragma section all "RAMTST_ROM_CONST_UNSPECIFIED"
#elif defined (RAMTST_STOP_SEC_CONST_UNSPECIFIED)
#undef RAMTST_STOP_SEC_CONST_UNSPECIFIED
#pragma section all restore

#elif defined (RAMTST_START_SEC_VAR_CLEARED_8)
#undef RAMTST_START_SEC_VAR_CLEARED_8
#pragma section all "RAMTST_RAM_VAR_CLEARED_8"
#elif defined (RAMTST_STOP_SEC_VAR_CLEARED_8)
#undef RAMTST_STOP_SEC_VAR_CLEARED_8
#pragma section all restore

/* -------------------------------------------------------------------------- */
/*                 ETHIF                                                      */
/* -------------------------------------------------------------------------- */
#elif defined (ETHIF_START_SEC_CODE)
   #undef      ETHIF_START_SEC_CODE
   #pragma section code "ETHIF_CODE"
   #pragma section farrom "ETHIF_ROM_CONST_UNSPECIFIED"
   #pragma section farbss "ETHIF_RAM_VAR_CLEARED_UNSPECIFIED"
   #pragma section fardata "ETHIF_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (ETHIF_STOP_SEC_CODE)
   #undef      ETHIF_STOP_SEC_CODE
   #pragma section fardata restore
   #pragma section farbss restore
   #pragma section farrom restore
   #pragma section code restore

#elif defined (ETHIF_START_SEC_VAR_CLEARED_8)
   #undef      ETHIF_START_SEC_VAR_CLEARED_8
   #pragma section all "ETHIF_RAM_VAR_CLEARED_8"
#elif defined (ETHIF_STOP_SEC_VAR_CLEARED_8)
   #undef      ETHIF_STOP_SEC_VAR_CLEARED_8
   #pragma section all restore

#elif defined (ETHIF_START_SEC_VAR_CLEARED_UNSPECIFIED)
   #undef      ETHIF_START_SEC_VAR_CLEARED_UNSPECIFIED
   #pragma section all "ETHIF_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (ETHIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
   #undef      ETHIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
   #pragma section all restore

#elif defined (ETHIF_START_SEC_CONST_8)
   #undef      ETHIF_START_SEC_CONST_8
   #pragma section all "ETHIF_ROM_CONST_8"
#elif defined (ETHIF_STOP_SEC_CONST_8)
   #undef      ETHIF_STOP_SEC_CONST_8
   #pragma section all restore

#elif defined (ETHIF_START_SEC_CONST_UNSPECIFIED)
   #undef      ETHIF_START_SEC_CONST_UNSPECIFIED
   #pragma section all "ETHIF_ROM_CONST_UNSPECIFIED"
#elif defined (ETHIF_STOP_SEC_CONST_UNSPECIFIED)
   #undef      ETHIF_STOP_SEC_CONST_UNSPECIFIED
   #pragma section all restore

/* -------------------------------------------------------------------------- */
/*                 ETHSM                                                      */
/* -------------------------------------------------------------------------- */
#elif defined (ETHSM_START_SEC_CODE)
   #undef      ETHSM_START_SEC_CODE
   #pragma section code "ETHSM_CODE"
   #pragma section farrom "ETHSM_ROM_CONST_UNSPECIFIED"
   #pragma section farbss "ETHSM_RAM_VAR_CLEARED_UNSPECIFIED"
   #pragma section fardata "ETHSM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (ETHSM_STOP_SEC_CODE)
   #undef      ETHSM_STOP_SEC_CODE
   #pragma section fardata restore
   #pragma section farbss restore
   #pragma section farrom restore
   #pragma section code restore

#elif defined (ETHSM_START_SEC_VAR_CLEARED_BOOLEAN)
   #undef      ETHSM_START_SEC_VAR_CLEARED_BOOLEAN
   #pragma section all "ETHSM_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (ETHSM_STOP_SEC_VAR_CLEARED_BOOLEAN)
   #undef      ETHSM_STOP_SEC_VAR_CLEARED_BOOLEAN
   #pragma section all restore

#elif defined (ETHSM_START_SEC_VAR_INIT_UNSPECIFIED)
   #undef      ETHSM_START_SEC_VAR_INIT_UNSPECIFIED
   #pragma section all "ETHSM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (ETHSM_STOP_SEC_VAR_INIT_UNSPECIFIED)
   #undef      ETHSM_STOP_SEC_VAR_INIT_UNSPECIFIED
   #pragma section all restore

#elif defined (ETHSM_START_SEC_CONST_8)
   #undef      ETHSM_START_SEC_CONST_8
   #pragma section all "ETHSM_ROM_CONST_8"
#elif defined (ETHSM_STOP_SEC_CONST_8)
   #undef      ETHSM_STOP_SEC_CONST_8
   #pragma section all restore

#elif defined (ETHSM_START_SEC_VAR_CLEARED_UNSPECIFIED)
   #undef      ETHSM_START_SEC_VAR_CLEARED_UNSPECIFIED
   #pragma section all "ETHSM_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (ETHSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
   #undef      ETHSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
   #pragma section all restore

#elif defined (ETHSM_START_SEC_CONST_UNSPECIFIED)
   #undef      ETHSM_START_SEC_CONST_UNSPECIFIED
   #pragma section all "ETHSM_ROM_CONST_UNSPECIFIED"
#elif defined (ETHSM_STOP_SEC_CONST_UNSPECIFIED)
   #undef      ETHSM_STOP_SEC_CONST_UNSPECIFIED
   #pragma section all restore

/* -------------------------------------------------------------------------- */
/*                 ETHTRCV                                                    */
/* -------------------------------------------------------------------------- */
#elif defined (ETHTRCV_START_SEC_CODE)
  #undef      ETHTRCV_START_SEC_CODE
  #pragma section code "ETHTRCV_CODE"
  #pragma section farrom "ETHTRCV_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "ETHTRCV_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "ETHTRCV_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (ETHTRCV_STOP_SEC_CODE)
  #undef      ETHTRCV_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (ETHTRCV_PEF7071_START_SEC_CODE)
   #undef      ETHTRCV_PEF7071_START_SEC_CODE
   #pragma section code "ETHTRCV_CODE"
   #pragma section farrom "ETHTRCV_ROM_CONST_UNSPECIFIED"
   #pragma section farbss "ETHTRCV_RAM_VAR_CLEARED_UNSPECIFIED"
   #pragma section fardata "ETHTRCV_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (ETHTRCV_PEF7071_STOP_SEC_CODE)
   #undef      ETHTRCV_PEF7071_STOP_SEC_CODE
   #pragma section fardata restore
   #pragma section farbss restore
   #pragma section farrom restore
   #pragma section code restore

#elif defined (ETHTRCV_PEF7071_START_SEC_CONST_UNSPECIFIED)
   #undef      ETHTRCV_PEF7071_START_SEC_CONST_UNSPECIFIED
   #pragma section all "ETHTRCV_ROM_CONST_UNSPECIFIED"
#elif defined (ETHTRCV_PEF7071_STOP_SEC_CONST_UNSPECIFIED)
   #undef      ETHTRCV_PEF7071_STOP_SEC_CONST_UNSPECIFIED
   #pragma section all restore

#elif defined (ETHTRCV_PEF7071_START_SEC_VAR_CLEARED_UNSPECIFIED)
   #undef      ETHTRCV_PEF7071_START_SEC_VAR_CLEARED_UNSPECIFIED
   #pragma section all "ETHTRCV_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (ETHTRCV_PEF7071_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
   #undef      ETHTRCV_PEF7071_STOP_SEC_VAR_CLEARED_UNSPECIFIED
   #pragma section all restore

#elif defined (ETHTRCV_PEF7071_START_SEC_VAR_NO_INIT_UNSPECIFIED)
   #undef      ETHTRCV_PEF7071_START_SEC_VAR_NO_INIT_UNSPECIFIED
   #pragma section all "ETHTRCV_RAM_VAR_NO_INIT_UNSPECIFIED"
#elif defined (ETHTRCV_PEF7071_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
   #undef      ETHTRCV_PEF7071_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
   #pragma section all restore

#elif defined (ETHTRCV_BCM89811_START_SEC_CODE)
  #undef      ETHTRCV_BCM89811_START_SEC_CODE
  #pragma section code "ETHTRCV_CODE"
  #pragma section farrom "ETHTRCV_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "ETHTRCV_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "ETHTRCV_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (ETHTRCV_BCM89811_STOP_SEC_CODE)
  #undef      ETHTRCV_BCM89811_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (ETHTRCV_BCM89811_START_SEC_CONST_UNSPECIFIED)
  #undef      ETHTRCV_BCM89811_START_SEC_CONST_UNSPECIFIED
  #pragma section all "ETHTRCV_ROM_CONST_UNSPECIFIED"
#elif defined (ETHTRCV_BCM89811_STOP_SEC_CONST_UNSPECIFIED)
  #undef      ETHTRCV_BCM89811_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (ETHTRCV_BCM89811_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef      ETHTRCV_BCM89811_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "ETHTRCV_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (ETHTRCV_BCM89811_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef      ETHTRCV_BCM89811_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (ETHTRCV_BCM89811_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef      ETHTRCV_BCM89811_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "ETHTRCV_RAM_VAR_NO_INIT_UNSPECIFIED"
#elif defined (ETHTRCV_BCM89811_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef      ETHTRCV_BCM89811_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all restore

/* -------------------------------------------------------------------------- */
/*                 ETHSWT                                                    */
/* -------------------------------------------------------------------------- */
#elif defined (ETHSWT_START_SEC_CODE)
  #undef      ETHSWT_START_SEC_CODE
  #pragma section code "ETHSWT_CODE"
  #pragma section farrom "ETHSWT_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "ETHSWT_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "ETHSWT_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (ETHSWT_STOP_SEC_CODE)
  #undef      ETHSWT_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (ETHSWT_BCM89531_START_SEC_CODE)
  #undef      ETHSWT_BCM89531_START_SEC_CODE
  #pragma section code "ETHSWT_CODE"
  #pragma section farrom "ETHSWT_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "ETHSWT_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "ETHSWT_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (ETHSWT_BCM89531_STOP_SEC_CODE)
  #undef      ETHSWT_BCM89531_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

#elif defined (ETHSWT_BCM89531_START_SEC_CONST_UNSPECIFIED)
  #undef      ETHSWT_BCM89531_START_SEC_CONST_UNSPECIFIED
  #pragma section all "ETHSWT_ROM_CONST_UNSPECIFIED"
#elif defined (ETHSWT_BCM89531_STOP_SEC_CONST_UNSPECIFIED)
  #undef      ETHSWT_BCM89531_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (ETHSWT_BCM89531_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef      ETHSWT_BCM89531_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "ETHSWT_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (ETHSWT_BCM89531_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef      ETHSWT_BCM89531_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (ETHSWT_BCM89531_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef      ETHSWT_BCM89531_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "ETHSWT_RAM_VAR_NO_INIT_UNSPECIFIED"
#elif defined (ETHSWT_BCM89531_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef      ETHSWT_BCM89531_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all restore

/* -------------------------------------------------------------- */
/*                               SOAD                             */
/* -------------------------------------------------------------- */
#elif defined (SOAD_START_SEC_VAR_CLEARED_8)
   #undef      SOAD_START_SEC_VAR_CLEARED_8
   #pragma section all "SOAD_RAM_VAR_CLEARED_8"
#elif defined (SOAD_STOP_SEC_VAR_CLEARED_8)
   #undef      SOAD_STOP_SEC_VAR_CLEARED_8
   #pragma section all restore

#elif defined (SOAD_START_SEC_VAR_CLEARED_16)
   #undef      SOAD_START_SEC_VAR_CLEARED_16
   #pragma section all "SOAD_RAM_VAR_CLEARED_16"
#elif defined (SOAD_STOP_SEC_VAR_CLEARED_16)
   #undef      SOAD_STOP_SEC_VAR_CLEARED_16
   #pragma section all restore
   
#elif defined (SOAD_START_SEC_VAR_CLEARED_32)
   #undef      SOAD_START_SEC_VAR_CLEARED_32
   #pragma section all "SOAD_RAM_VAR_CLEARED_32"
   #pragma align 4
#elif defined (SOAD_STOP_SEC_VAR_CLEARED_32)
   #undef      SOAD_STOP_SEC_VAR_CLEARED_32
   #pragma align restore
   #pragma section all restore
   
#elif defined (SOAD_START_SEC_VAR_CLEARED_UNSPECIFIED)
   #undef      SOAD_START_SEC_VAR_CLEARED_UNSPECIFIED
   #pragma section all "SOAD_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (SOAD_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
   #undef      SOAD_STOP_SEC_VAR_CLEARED_UNSPECIFIED
   #pragma section all restore
   
#elif defined (SOAD_START_SEC_VAR_CLEARED_BOOLEAN)
   #undef      SOAD_START_SEC_VAR_CLEARED_BOOLEAN
   #pragma section all "SOAD_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (SOAD_STOP_SEC_VAR_CLEARED_BOOLEAN)
   #undef      SOAD_STOP_SEC_VAR_CLEARED_BOOLEAN
   #pragma section all restore

#elif defined (SOAD_START_SEC_VAR_CLEARED_8)
   #undef      SOAD_START_SEC_VAR_CLEARED_8
   #pragma section all "SOAD_RAM_VAR_CLEARED_8"
#elif defined (SOAD_STOP_SEC_VAR_CLEARED_8)
   #undef      SOAD_STOP_SEC_VAR_CLEARED_8
   #pragma section all restore

#elif defined (SOAD_START_SEC_VAR_CLEARED_16)
   #undef      SOAD_START_SEC_VAR_CLEARED_16
   #pragma section all "SOAD_RAM_VAR_CLEARED_16"
#elif defined (SOAD_STOP_SEC_VAR_CLEARED_16)
   #undef      SOAD_STOP_SEC_VAR_CLEARED_16
   #pragma section all restore

#elif defined (SOAD_START_SEC_VAR_CLEARED_32)
   #undef      SOAD_START_SEC_VAR_CLEARED_32
   #pragma section all "SOAD_RAM_VAR_CLEARED_32"
   #pragma align 4
#elif defined (SOAD_STOP_SEC_VAR_CLEARED_32)
   #undef      SOAD_STOP_SEC_VAR_CLEARED_32
   #pragma align restore
   #pragma section all restore

#elif defined (SOAD_START_SEC_VAR_CLEARED_UNSPECIFIED)
   #undef      SOAD_START_SEC_VAR_CLEARED_UNSPECIFIED
   #pragma section all "SOAD_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (SOAD_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
   #undef      SOAD_STOP_SEC_VAR_CLEARED_UNSPECIFIED
   #pragma section all restore

#elif defined (SOAD_START_SEC_CONST_BOOLEAN)
   #undef      SOAD_START_SEC_CONST_BOOLEAN
   #pragma section all "SOAD_ROM_CONST_BOOLEAN"
#elif defined (SOAD_STOP_SEC_CONST_BOOLEAN)
   #undef      SOAD_STOP_SEC_CONST_BOOLEAN
   #pragma section all restore

#elif defined (SOAD_START_SEC_CONST_8)
   #undef      SOAD_START_SEC_CONST_8
   #pragma section all "SOAD_ROM_CONST_8"
#elif defined (SOAD_STOP_SEC_CONST_8)
   #undef      SOAD_STOP_SEC_CONST_8
   #pragma section all restore

#elif defined (SOAD_START_SEC_CONST_16)
   #undef      SOAD_START_SEC_CONST_16
   #pragma section all "SOAD_ROM_CONST_16"
#elif defined (SOAD_STOP_SEC_CONST_16)
   #undef      SOAD_STOP_SEC_CONST_16
   #pragma section all restore

#elif defined (SOAD_START_SEC_CONST_32)
   #undef      SOAD_START_SEC_CONST_32
   #pragma section all "SOAD_ROM_CONST_32"
   #pragma align 4
#elif defined (SOAD_STOP_SEC_CONST_32)
   #undef      SOAD_STOP_SEC_CONST_32
   #pragma align restore
   #pragma section all restore

#elif defined (SOAD_START_SEC_CONST_UNSPECIFIED)
   #undef      SOAD_START_SEC_CONST_UNSPECIFIED
   #pragma section all "SOAD_ROM_CONST_UNSPECIFIED"
#elif defined (SOAD_STOP_SEC_CONST_UNSPECIFIED)
   #undef      SOAD_STOP_SEC_CONST_UNSPECIFIED
   #pragma section all restore

#elif defined (SOAD_START_SEC_CODE)
   #undef      SOAD_START_SEC_CODE
   #pragma section code "SOAD_CODE"
   #pragma section farrom "SOAD_ROM_CONST_UNSPECIFIED"
   #pragma section farbss "SOAD_RAM_VAR_CLEARED_UNSPECIFIED"
   #pragma section fardata "SOAD_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (SOAD_STOP_SEC_CODE)
   #undef      SOAD_STOP_SEC_CODE
   #pragma section fardata restore
   #pragma section farbss restore
   #pragma section farrom restore
   #pragma section code restore

/* -------------------------------------------------------------------------- */
/*             DOIP                                                        */
/* -------------------------------------------------------------------------- */
#elif defined (DOIP_START_SEC_CODE)
   #undef      DOIP_START_SEC_CODE
   #pragma section code "DOIP_CODE"
   #pragma section farrom "DOIP_ROM_CONST_UNSPECIFIED"
   #pragma section farbss "DOIP_RAM_VAR_CLEARED_UNSPECIFIED"
   #pragma section fardata "DOIP_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (DOIP_STOP_SEC_CODE)
   #undef      DOIP_STOP_SEC_CODE
   #pragma section fardata restore
   #pragma section farbss restore
   #pragma section farrom restore
   #pragma section code restore

#elif defined (DOIP_START_SEC_CONST_UNSPECIFIED)
   #undef      DOIP_START_SEC_CONST_UNSPECIFIED
   #pragma section all "DOIP_ROM_CONST_ROM_UNSPECIFIED"
#elif defined (DOIP_STOP_SEC_CONST_UNSPECIFIED)
   #undef      DOIP_STOP_SEC_CONST_UNSPECIFIED
   #pragma section all restore

#elif defined (DOIP_START_SEC_VAR_NO_INIT_UNSPECIFIED)
   #undef      DOIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
   #pragma section all "DOIP_RAM_VAR_NO_INIT_UNSPECIFIED"
#elif defined (DOIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
   #undef      DOIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
   #pragma section all restore

#elif defined (DOIP_START_SEC_VAR_NO_INIT_8)
   #undef      DOIP_START_SEC_VAR_NO_INIT_8
   #pragma section all "DOIP_RAM_VAR_NO_INIT_8"
#elif defined (DOIP_STOP_SEC_VAR_NO_INIT_8)
   #undef      DOIP_STOP_SEC_VAR_NO_INIT_8
   #pragma section all restore

#elif defined (DOIP_START_SEC_VAR_CLEARED_BOOLEAN)
   #undef      DOIP_START_SEC_VAR_CLEARED_BOOLEAN
	 #pragma section all "DOIP_RAM_CLEARED_BOOLEAN"
#elif defined (DOIP_STOP_SEC_VAR_CLEARED_BOOLEAN)
   #undef      DOIP_STOP_SEC_VAR_CLEARED_BOOLEAN
   #pragma section all restore

#elif defined (DOIP_START_SEC_VAR_INIT_UNSPECIFIED)
   #undef      DOIP_START_SEC_VAR_INIT_UNSPECIFIED
   #pragma section all "DOIP_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (DOIP_STOP_SEC_VAR_INIT_UNSPECIFIED)
   #undef      DOIP_STOP_SEC_VAR_INIT_UNSPECIFIED
   #pragma section all restore

#elif defined (DOIP_START_SEC_VAR_CLEARED_UNSPECIFIED)
   #undef      DOIP_START_SEC_VAR_CLEARED_UNSPECIFIED
   #pragma section all "DOIP_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (DOIP_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
   #undef      DOIP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
   #pragma section all restore

/* -------------------------------------------------------------------------- */
/*             UDPNM                                                          */
/* -------------------------------------------------------------------------- */
#elif defined (UDPNM_START_SEC_CODE)
   #undef      UDPNM_START_SEC_CODE
   #pragma section code "UDPNM_CODE"
   #pragma section farrom "UDPNM_ROM_CONST_UNSPECIFIED"
   #pragma section farbss "UDPNM_RAM_VAR_CLEARED_UNSPECIFIED"
   #pragma section fardata "UDPNM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (UDPNM_STOP_SEC_CODE)
   #undef      UDPNM_STOP_SEC_CODE
   #pragma section fardata restore
   #pragma section farbss restore
   #pragma section farrom restore
   #pragma section code restore

#elif defined (UDPNM_START_SEC_VAR_CLEARED_BOOLEAN)
   #undef      UDPNM_START_SEC_VAR_CLEARED_BOOLEAN
   #pragma section all "UDPNM_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (UDPNM_STOP_SEC_VAR_CLEARED_BOOLEAN)
   #undef      UDPNM_STOP_SEC_VAR_CLEARED_BOOLEAN
   #pragma section all restore

#elif defined (UDPNM_START_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED)
   #undef      UDPNM_START_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED
   #pragma section all "UDPNM_DBTOC_CONFIG_CONST_UNSPECIFIED"
#elif defined (UDPNM_STOP_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED)
   #undef      UDPNM_STOP_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED
   #pragma section all restore

#elif defined (UDPNM_START_SEC_VAR_NO_INIT_8)
   #undef      UDPNM_START_SEC_VAR_NO_INIT_8
   #pragma section all "UDPNM_RAM_VAR_NO_INIT_8"
#elif defined (UDPNM_STOP_SEC_VAR_NO_INIT_8)
   #undef      UDPNM_STOP_SEC_VAR_NO_INIT_8
   #pragma section all restore

#elif defined (UDPNM_START_SEC_VAR_NO_INIT_UNSPECIFIED)
   #undef      UDPNM_START_SEC_VAR_NO_INIT_UNSPECIFIED
   #pragma section all "UDPNM_RAM_VAR_NO_INIT_UNSPECIFIED"
#elif defined (UDPNM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
   #undef      UDPNM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
   #pragma section all restore

#elif defined (UDPNM_START_SEC_CONST_8)
   #undef      UDPNM_START_SEC_CONST_8
   #pragma section all "UDPNM_ROM_CONST_8"
#elif defined (UDPNM_STOP_SEC_CONST_8)
   #undef      UDPNM_STOP_SEC_CONST_8
   #pragma section all restore

#elif defined (UDPNM_START_SEC_CONST_UNSPECIFIED)
   #undef      UDPNM_START_SEC_CONST_UNSPECIFIED
   #pragma section all "UDPNM_ROM_CONST_UNSPECIFIED"
#elif defined (UDPNM_STOP_SEC_CONST_UNSPECIFIED)
   #undef      UDPNM_STOP_SEC_CONST_UNSPECIFIED
   #pragma section all restore

#elif defined (UDPNM_START_SEC_VAR_CLEARED_UNSPECIFIED)
   #undef      UDPNM_START_SEC_VAR_CLEARED_UNSPECIFIED
   #pragma section all "UDPNM_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (UDPNM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
   #undef      UDPNM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
   #pragma section all restore

/* ------------------------------------------------------ */
/*                        TCPIP                           */
/* ------------------------------------------------------ */
#elif defined (TCPIP_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef      TCPIP_START_SEC_VAR_NO_INIT_BOOLEAN
  #pragma section all "TCPIP_RAM_VAR_NO_INIT_BOOLEAN"
  #pragma noclear
#elif defined (TCPIP_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef      TCPIP_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #pragma clear
  #pragma section all restore

#elif defined (TCPIP_START_SEC_VAR_NO_INIT_8)
  #undef      TCPIP_START_SEC_VAR_NO_INIT_8
  #pragma section all "TCPIP_RAM_VAR_NO_INIT_8"
  #pragma noclear
#elif defined (TCPIP_STOP_SEC_VAR_NO_INIT_8)
  #undef      TCPIP_STOP_SEC_VAR_NO_INIT_8
  #pragma clear
  #pragma section all restore

#elif defined (TCPIP_START_SEC_VAR_NO_INIT_16)
  #undef      TCPIP_START_SEC_VAR_NO_INIT_16
  #pragma section all "TCPIP_RAM_VAR_NO_INIT_16"
  #pragma noclear
#elif defined (TCPIP_STOP_SEC_VAR_NO_INIT_16)
  #undef      TCPIP_STOP_SEC_VAR_NO_INIT_16
  #pragma clear
  #pragma section all restore

#elif defined (TCPIP_START_SEC_VAR_NO_INIT_32)
  #undef      TCPIP_START_SEC_VAR_NO_INIT_32
  #pragma section all "TCPIP_RAM_VAR_NO_INIT_32"
  #pragma noclear
  #pragma align 4
#elif defined (TCPIP_STOP_SEC_VAR_NO_INIT_32)
  #undef      TCPIP_STOP_SEC_VAR_NO_INIT_32
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef      TCPIP_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "TCPIP_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
#elif defined (TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef      TCPIP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma clear
  #pragma section all restore

#elif defined (TCPIP_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef      TCPIP_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "TCPIP_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (TCPIP_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef      TCPIP_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all restore

#elif defined (TCPIP_START_SEC_VAR_CLEARED_8)
  #undef      TCPIP_START_SEC_VAR_CLEARED_8
  #pragma section all "TCPIP_RAM_VAR_CLEARED_8"
#elif defined (TCPIP_STOP_SEC_VAR_CLEARED_8)
  #undef      TCPIP_STOP_SEC_VAR_CLEARED_8
  #pragma section all restore

#elif defined (TCPIP_START_SEC_VAR_CLEARED_16)
  #undef      TCPIP_START_SEC_VAR_CLEARED_16
  #pragma section all "TCPIP_RAM_VAR_CLEARED_16"
#elif defined (TCPIP_STOP_SEC_VAR_CLEARED_16)
  #undef      TCPIP_STOP_SEC_VAR_CLEARED_16
  #pragma section all restore

#elif defined (TCPIP_START_SEC_VAR_CLEARED_32)
  #undef      TCPIP_START_SEC_VAR_CLEARED_32
  #pragma section all "TCPIP_RAM_VAR_CLEARED_32"
  #pragma align 4
#elif defined (TCPIP_STOP_SEC_VAR_CLEARED_32)
  #undef      TCPIP_STOP_SEC_VAR_CLEARED_32
  #pragma align restore
  #pragma section all restore

#elif defined (TCPIP_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef      TCPIP_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "TCPIP_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (TCPIP_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef      TCPIP_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore

#elif defined (TCPIP_START_SEC_VAR_INIT_BOOLEAN)
  #undef      TCPIP_START_SEC_VAR_INIT_BOOLEAN
  #pragma section all "TCPIP_RAM_VAR_INIT_BOOLEAN"
#elif defined (TCPIP_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef      TCPIP_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma section all restore

#elif defined (TCPIP_START_SEC_VAR_INIT_8)
  #undef      TCPIP_START_SEC_VAR_INIT_8
  #pragma section all "TCPIP_RAM_VAR_INIT_8"
#elif defined (TCPIP_STOP_SEC_VAR_INIT_8)
  #undef      TCPIP_STOP_SEC_VAR_INIT_8
  #pragma section all restore

#elif defined (TCPIP_START_SEC_VAR_INIT_16)
  #undef      TCPIP_START_SEC_VAR_INIT_16
  #pragma section all "TCPIP_RAM_VAR_INIT_16"
#elif defined (TCPIP_STOP_SEC_VAR_INIT_16)
  #undef      TCPIP_STOP_SEC_VAR_INIT_16
  #pragma section all restore

#elif defined (TCPIP_START_SEC_VAR_INIT_32)
  #undef      TCPIP_START_SEC_VAR_INIT_32
  #pragma section all "TCPIP_RAM_VAR_INIT_32"
  #pragma align 4
#elif defined (TCPIP_STOP_SEC_VAR_INIT_32)
  #undef      TCPIP_STOP_SEC_VAR_INIT_32
  #pragma align restore
  #pragma section all restore

#elif defined (TCPIP_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef      TCPIP_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all "TCPIP_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (TCPIP_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef      TCPIP_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all restore

#elif defined (TCPIP_START_SEC_CONST_BOOLEAN)
  #undef      TCPIP_START_SEC_CONST_BOOLEAN
  #pragma section all "TCPIP_ROM_CONST_BOOLEAN"
#elif defined (TCPIP_STOP_SEC_CONST_BOOLEAN)
  #undef      TCPIP_STOP_SEC_CONST_BOOLEAN
  #pragma section all restore

#elif defined (TCPIP_START_SEC_CONST_8)
  #undef      TCPIP_START_SEC_CONST_8
  #pragma section all "TCPIP_ROM_CONST_8"
#elif defined (TCPIP_STOP_SEC_CONST_8)
  #undef      TCPIP_STOP_SEC_CONST_8
  #pragma section all restore

#elif defined (TCPIP_START_SEC_CONST_16)
  #undef      TCPIP_START_SEC_CONST_16
  #pragma section all "TCPIP_ROM_CONST_16"
#elif defined (TCPIP_STOP_SEC_CONST_16)
  #undef      TCPIP_STOP_SEC_CONST_16
  #pragma section all restore

#elif defined (TCPIP_START_SEC_CONST_32)
  #undef      TCPIP_START_SEC_CONST_32
  #pragma section all "TCPIP_ROM_CONST_32"
  #pragma align 4
#elif defined (TCPIP_STOP_SEC_CONST_32)
  #undef      TCPIP_STOP_SEC_CONST_32
  #pragma align restore
  #pragma section all restore

#elif defined (TCPIP_START_SEC_CONST_UNSPECIFIED)
  #undef      TCPIP_START_SEC_CONST_UNSPECIFIED
  #pragma section all "TCPIP_ROM_CONST_UNSPECIFIED"
#elif defined (TCPIP_STOP_SEC_CONST_UNSPECIFIED)
  #undef      TCPIP_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore

#elif defined (TCPIP_START_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED)
  #undef      TCPIP_START_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED
  #pragma section all "TCPIP_ROM_DBTOC_CONFIG_CONST_UNSPECIFIED"
#elif defined (TCPIP_STOP_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED)
  #undef      TCPIP_STOP_SEC_DBTOC_CONFIG_CONST_UNSPECIFIED
  #pragma section all restore
  
#elif defined (TCPIP_START_SEC_CODE)
   #undef      TCPIP_START_SEC_CODE
   #pragma section code "TCPIP_CODE"
   #pragma section farrom "TCPIP_ROM_CONST_UNSPECIFIED"
   #pragma section farbss "TCPIP_RAM_VAR_CLEARED_UNSPECIFIED"
   #pragma section fardata "TCPIP_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (TCPIP_STOP_SEC_CODE)
   #undef      TCPIP_STOP_SEC_CODE
   #pragma section fardata restore
   #pragma section farbss restore
   #pragma section farrom restore
   #pragma section code restore

/* -------------------------------------------------------------------------- */
/*                                 RomTst                                     */
/* -------------------------------------------------------------------------- */
#elif defined (ROMTST_START_SEC_CODE)
   #undef ROMTST_START_SEC_CODE
   #pragma section code "ROMTST_CODE"
   #pragma section code "ROMTST_CODE"
  #pragma section farrom "ROMTST_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "ROMTST_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "ROMTSTRAM_VAR_INIT_UNSPECIFIED"
#elif defined (ROMTST_STOP_SEC_CODE)
   #undef ROMTST_STOP_SEC_CODE
   #pragma section fardata restore
   #pragma section farbss restore
   #pragma section farrom restore
   #pragma section code restore
#elif defined (ROMTST_START_SEC_VAR_CLEARED_BOOLEAN)
   #undef ROMTST_START_SEC_VAR_CLEARED_BOOLEAN
   #pragma section all "ROMTST_RAM_VAR_CLEARED_BOOLEAN"
#elif defined (ROMTST_STOP_SEC_VAR_CLEARED_BOOLEAN)
   #undef ROMTST_STOP_SEC_VAR_CLEARED_BOOLEAN
   #pragma section all restore
#elif defined (ROMTST_START_SEC_VAR_CLEARED_UNSPECIFIED)
   #undef ROMTST_START_SEC_VAR_CLEARED_UNSPECIFIED
   #pragma section all "ROMTST_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (ROMTST_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
   #undef ROMTST_STOP_SEC_VAR_CLEARED_UNSPECIFIED
   #pragma section all restore
#elif defined (ROMTST_START_SEC_CONST_UNSPECIFIED)
   #undef ROMTST_START_SEC_CONST_UNSPECIFIED
   #pragma section all "ROMTST_ROM_CONST_UNSPECIFIED"
#elif defined (ROMTST_STOP_SEC_CONST_UNSPECIFIED)
   #undef ROMTST_STOP_SEC_CONST_UNSPECIFIED
   #pragma section all restore
#elif defined (ROMTST_START_SEC_VAR_CLEARED_8)
   #undef ROMTST_START_SEC_VAR_CLEARED_8
   #pragma section all "ROMTST_RAM_VAR_CLEARED_8"
#elif defined (ROMTST_STOP_SEC_VAR_CLEARED_8)
   #undef ROMTST_STOP_SEC_VAR_CLEARED_8
   #pragma section all restore
/* --------------------------------------------------------------------------*/
/*                               CDD_ROUTER                                  */
/* --------------------------------------------------------------------------*/
#elif defined (CDD_ROUTER_START_SEC_CONST_8)
  #undef CDD_ROUTER_START_SEC_CONST_8
  #pragma section all "CDD_ROUTER_ROM_CONST_8"  
#elif defined (CDD_ROUTER_STOP_SEC_CONST_8)
  #undef CDD_ROUTER_STOP_SEC_CONST_8
  #pragma section all restore
#elif defined (CDD_ROUTER_START_SEC_CONST_UNSPECIFIED)
  #undef CDD_ROUTER_START_SEC_CONST_UNSPECIFIED
  #pragma section all "CDD_ROUTER_ROM_CONST_UNSPECIFIED"  
#elif defined (CDD_ROUTER_STOP_SEC_CONST_UNSPECIFIED)
  #undef CDD_ROUTER_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore
#elif defined (CDD_ROUTER_START_SEC_CODE)
  #undef CDD_ROUTER_START_SEC_CODE
  #pragma section code "CDD_ROUTER_CODE"
  #pragma section farrom "CDD_ROUTER_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "CDD_ROUTER_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "CDD_ROUTER_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (CDD_ROUTER_STOP_SEC_CODE)
  #undef CDD_ROUTER_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore   
/* --------------------------------------------------------------------------*/
/*                               IDSM                                        */
/* --------------------------------------------------------------------------*/
#elif defined (IDSM_START_SEC_CONST_8)
  #undef IDSM_START_SEC_CONST_8
  #pragma section all "IDSM_ROM_CONST_8"  
#elif defined (IDSM_STOP_SEC_CONST_8)
  #undef IDSM_STOP_SEC_CONST_8
  #pragma section all restore
#elif defined (IDSM_START_SEC_CONST_16)
  #undef       IDSM_START_SEC_CONST_16
  #pragma section all "IDSM_ROM_CONST_16"  
#elif defined (IDSM_STOP_SEC_CONST_16)
  #undef       IDSM_STOP_SEC_CONST_16
  #pragma section all restore
#elif defined (IDSM_START_SEC_CONST_32)
  #undef       IDSM_START_SEC_CONST_32
  #pragma section all "IDSM_ROM_CONST_32"  
#elif defined (IDSM_STOP_SEC_CONST_32)
  #undef       IDSM_STOP_SEC_CONST_32
  #pragma section all restore
#elif defined (IDSM_START_SEC_CONST_UNSPECIFIED)
  #undef IDSM_START_SEC_CONST_UNSPECIFIED
  #pragma section all "IDSM_ROM_CONST_UNSPECIFIED"  
#elif defined (IDSM_STOP_SEC_CONST_UNSPECIFIED)
  #undef IDSM_STOP_SEC_CONST_UNSPECIFIED
  #pragma section all restore
#elif defined (IDSM_START_SEC_VAR_CLEARED_8)
  #undef       IDSM_START_SEC_VAR_CLEARED_8
  #pragma section all "IDSM_RAM_VAR_CLEARED_8"  
#elif defined (IDSM_STOP_SEC_VAR_CLEARED_8)
  #undef       IDSM_STOP_SEC_VAR_CLEARED_8
  #pragma section all restore
#elif defined (IDSM_START_SEC_VAR_CLEARED_16)
  #undef       IDSM_START_SEC_VAR_CLEARED_16
  #pragma section all "IDSM_RAM_VAR_CLEARED_16"  
#elif defined (IDSM_STOP_SEC_VAR_CLEARED_16)
  #undef       IDSM_STOP_SEC_VAR_CLEARED_16
  #pragma section all restore
#elif defined (IDSM_START_SEC_VAR_CLEARED_32)
  #undef       IDSM_START_SEC_VAR_CLEARED_32
  #pragma section all "IDSM_RAM_VAR_CLEARED_32"  
#elif defined (IDSM_STOP_SEC_VAR_CLEARED_32)
  #undef       IDSM_STOP_SEC_VAR_CLEARED_32
  #pragma section all restore
#elif defined (IDSM_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       IDSM_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "IDSM_RAM_VAR_CLEARED_UNSPECIFIED"  
#elif defined (IDSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       IDSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all restore
#elif defined (IDSM_START_SEC_VAR_INIT_8)
  #undef       IDSM_START_SEC_VAR_INIT_8
  #pragma section all "IDSM_RAM_VAR_INIT_8" 
#elif defined (IDSM_STOP_SEC_VAR_INIT_8)
  #undef       IDSM_STOP_SEC_VAR_INIT_8
  #pragma section all restore
#elif defined (IDSM_START_SEC_VAR_INIT_16)
  #undef       IDSM_START_SEC_VAR_INIT_16
  #pragma section all "IDSM_RAM_VAR_INIT_16" 
#elif defined (IDSM_STOP_SEC_VAR_INIT_16)
  #undef       IDSM_STOP_SEC_VAR_INIT_16
  #pragma section all restore
#elif defined (IDSM_START_SEC_VAR_INIT_32)
  #undef       IDSM_START_SEC_VAR_INIT_32
  #pragma section all "IDSM_RAM_VAR_INIT_32" 
#elif defined (IDSM_STOP_SEC_VAR_INIT_32)
  #undef       IDSM_STOP_SEC_VAR_INIT_32
  #pragma section all restore  
#elif defined (IDSM_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       IDSM_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all "IDSM_RAM_VAR_INIT_UNSPECIFIED" 
#elif defined (IDSM_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       IDSM_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all restore
#elif defined (IDSM_START_SEC_CODE)
  #undef IDSM_START_SEC_CODE
  #pragma section code "IDSM_CODE"
  #pragma section farrom "IDSM_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "IDSM_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "IDSM_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (IDSM_STOP_SEC_CODE)
  #undef IDSM_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore
/* --------------------------------------------------------------------------*/
/*                               COMXF                                       */
/* --------------------------------------------------------------------------*/
#elif defined (COMXF_START_SEC_CODE)
  #undef COMXF_START_SEC_CODE
  #pragma section code "COMXF_CODE"
  #pragma section farrom "COMXF_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "COMXF_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "COMXF_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (COMXF_STOP_SEC_CODE)
  #undef COMXF_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore
#elif defined (COMXF_START_SEC_CODE_ASIL_D)
  #undef COMXF_START_SEC_CODE_ASIL_D
  #pragma section code "COMXF_CODE"
  #pragma section farrom "COMXF_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "COMXF_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "COMXF_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (COMXF_STOP_SEC_CODE_ASIL_D)
  #undef COMXF_STOP_SEC_CODE_ASIL_D
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore  
#elif defined (COMXF_START_APPL_SEC_CODE)
  #undef COMXF_START_APPL_SEC_CODE
  #pragma section code "COMXF_CODE"
  #pragma section farrom "COMXF_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "COMXF_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "COMXF_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (COMXF_STOP_APPL_SEC_CODE)
  #undef COMXF_STOP_APPL_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore
#elif defined (COMXF_START_APPL_SEC_CODE_ASIL_D)
  #undef COMXF_START_APPL_SEC_CODE_ASIL_D
  #pragma section code "COMXF_CODE"
  #pragma section farrom "COMXF_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "COMXF_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "COMXF_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (COMXF_STOP_APPL_SEC_CODE_ASIL_D)
  #undef COMXF_STOP_APPL_SEC_CODE_ASIL_D
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore  
#elif defined (COMXF_START_SEC_VAR_INIT_BOOLEAN)
  #undef COMXF_START_SEC_VAR_INIT_BOOLEAN
  #pragma section all "COMXF_RAM_VAR_INIT_BOOLEAN"
#elif defined (COMXF_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef COMXF_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma section all restore
#elif defined (COMXF_START_SEC_VAR_INIT_ASIL_D_BOOLEAN)
  #undef COMXF_START_SEC_VAR_INIT_ASIL_D_BOOLEAN
  #pragma section all "COMXF_RAM_VAR_INIT_ASIL_D_BOOLEAN"
#elif defined (COMXF_STOP_SEC_VAR_INIT_ASIL_D_BOOLEAN)
  #undef COMXF_STOP_SEC_VAR_INIT_ASIL_D_BOOLEAN
  #pragma section all restore  
#elif defined (COMXF_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef COMXF_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "COMXF_RAM_VAR_NO_INIT_UNSPECIFIED"
#elif defined (COMXF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef COMXF_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all restore
#elif defined (COMXF_START_SEC_LCONFIG_DATA_UNSPECIFIED)
  #undef COMXF_START_SEC_LCONFIG_DATA_UNSPECIFIED
  #pragma section all "COMXF_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (COMXF_STOP_SEC_LCONFIG_DATA_UNSPECIFIED)
  #undef COMXF_STOP_SEC_LCONFIG_DATA_UNSPECIFIED
  #pragma section all restore
#elif defined (COMXF_START_SEC_PBCONFIG_DATA_UNSPECIFIED)
  #undef COMXF_START_SEC_PBCONFIG_DATA_UNSPECIFIED
  #pragma section all "COMXF_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (COMXF_STOP_SEC_PB_CONFIG_DATA_UNSPECIFIED)
  #undef COMXF_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
  #pragma section all restore
#elif defined (COMXF_START_SEC_DBTOCCONFIG_DATA_UNSPECIFIED)
  #undef COMXF_START_SEC_DBTOCCONFIG_DATA_UNSPECIFIED
  #pragma section all "COMXF_RAM_VAR_CLEARED_UNSPECIFIED"
#elif defined (COMXF_STOP_SEC_DBTOCCONFIG_DATA_UNSPECIFIED)
  #undef COMXF_STOP_SEC_DBTOCCONFIG_DATA_UNSPECIFIED
  #pragma section all restore
#elif defined (COMXF_START_SEC_CONFIG_DATA_UNSPECIFIED)
  #undef COMXF_START_SEC_CONFIG_DATA_UNSPECIFIED
  #pragma section all "COMXF_ROM_CONST_UNSPECIFIED"
#elif defined (COMXF_STOP_SEC_CONFIG_DATA_UNSPECIFIED)
  #undef COMXF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
  #pragma section all restore
#elif defined (COMXF_START_SEC_CONFIG_DATA_ASIL_D_UNSPECIFIED)
  #undef COMXF_START_SEC_CONFIG_DATA_ASIL_D_UNSPECIFIED
  #pragma section all "COMXF_ROM_CONST_UNSPECIFIED"
#elif defined (COMXF_STOP_SEC_CONFIG_DATA_ASIL_D_UNSPECIFIED)
  #undef COMXF_STOP_SEC_CONFIG_DATA_ASIL_D_UNSPECIFIED
  #pragma section all restore  
  
/* --------------------------------------------------------------------------*/
/*                               T1AD                                        */
/* --------------------------------------------------------------------------*/
#elif defined (T1AD_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       T1AD_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "T1AD_RAM_VAR_CLEARED_BOOLEAN"
  #pragma clear
  #pragma align 0

#elif defined (T1AD_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       T1AD_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (T1AD_START_SEC_VAR_CLEARED_8)
  #undef       T1AD_START_SEC_VAR_CLEARED_8
  #pragma section all "T1AD_RAM_VAR_CLEARED_8"
  #pragma clear
  #pragma align 0

#elif defined (T1AD_STOP_SEC_VAR_CLEARED_8)
  #undef       T1AD_STOP_SEC_VAR_CLEARED_8
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (T1AD_START_SEC_VAR_CLEARED_16)
  #undef       T1AD_START_SEC_VAR_CLEARED_16
  #pragma section all "T1AD_RAM_VAR_CLEARED_16"
  #pragma clear
  #pragma align 0

#elif defined (T1AD_STOP_SEC_VAR_CLEARED_16)
  #undef       T1AD_STOP_SEC_VAR_CLEARED_16
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (T1AD_START_SEC_VAR_CLEARED_32)
  #undef       T1AD_START_SEC_VAR_CLEARED_32
  #pragma section all "T1AD_RAM_VAR_CLEARED_32"
  #pragma clear
  #pragma align 4

#elif defined (T1AD_STOP_SEC_VAR_CLEARED_32)
  #undef       T1AD_STOP_SEC_VAR_CLEARED_32
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (T1AD_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       T1AD_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "T1AD_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma clear
  #pragma align 4

#elif defined (T1AD_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       T1AD_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (T1AD_START_SEC_CONST_BOOLEAN)
  #undef       T1AD_START_SEC_CONST_BOOLEAN
  #pragma section all "T1AD_ROM_CONST_BOOLEAN"
  #pragma align 0

#elif defined (T1AD_STOP_SEC_CONST_BOOLEAN)
  #undef       T1AD_STOP_SEC_CONST_BOOLEAN
  #pragma align restore
  #pragma section all restore

#elif defined (T1AD_START_SEC_CONST_8)
  #undef       T1AD_START_SEC_CONST_8
  #pragma section all "T1AD_ROM_CONST_8"
  #pragma align 0

#elif defined (T1AD_STOP_SEC_CONST_8)
  #undef       T1AD_STOP_SEC_CONST_8
  #pragma align restore
  #pragma section all restore

#elif defined (T1AD_START_SEC_CONST_16)
  #undef       T1AD_START_SEC_CONST_16
  #pragma section all "T1AD_ROM_CONST_16"
  #pragma align 0  

#elif defined (T1AD_STOP_SEC_CONST_16)
  #undef       T1AD_STOP_SEC_CONST_16
  #pragma align restore
  #pragma section all restore

#elif defined (T1AD_START_SEC_CONST_32)
  #undef       T1AD_START_SEC_CONST_32
  #pragma section all "T1AD_ROM_CONST_32"
  #pragma align 4

#elif defined (T1AD_STOP_SEC_CONST_32)
  #undef       T1AD_STOP_SEC_CONST_32
  #pragma align restore
  #pragma section all restore

#elif defined (T1AD_START_SEC_CONST_UNSPECIFIED)
  #undef       T1AD_START_SEC_CONST_UNSPECIFIED
  #pragma section all "T1AD_ROM_CONST_UNSPECIFIED"
  #pragma align 4
  
#elif defined (T1AD_STOP_SEC_CONST_UNSPECIFIED)
  #undef       T1AD_STOP_SEC_CONST_UNSPECIFIED
  #pragma align restore
  #pragma section all restore

#elif defined (T1AD_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       T1AD_START_SEC_VAR_NO_INIT_BOOLEAN
  #pragma section all "T1AD_RAM_VAR_NO_INIT_BOOLEAN"
  #pragma noclear
  #pragma align 0

#elif defined (T1AD_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       T1AD_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (T1AD_START_SEC_VAR_NO_INIT_8)
  #undef       T1AD_START_SEC_VAR_NO_INIT_8
  #pragma section all "T1AD_RAM_VAR_NO_INIT_8"
  #pragma noclear
  #pragma align 0

#elif defined (T1AD_STOP_SEC_VAR_NO_INIT_8)
  #undef       T1AD_STOP_SEC_VAR_NO_INIT_8
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (T1AD_START_SEC_VAR_NO_INIT_16)
  #undef       T1AD_START_SEC_VAR_NO_INIT_16
  #pragma section all "T1AD_RAM_VAR_NO_INIT_16"
  #pragma noclear
  #pragma align 0

#elif defined (T1AD_STOP_SEC_VAR_NO_INIT_16)
  #undef       T1AD_STOP_SEC_VAR_NO_INIT_16
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (T1AD_START_SEC_VAR_NO_INIT_32)
  #undef       T1AD_START_SEC_VAR_NO_INIT_32
  #pragma section all "T1AD_RAM_VAR_NO_INIT_32"
  #pragma noclear
  #pragma align 4

#elif defined (T1AD_STOP_SEC_VAR_NO_INIT_32)
  #undef       T1AD_STOP_SEC_VAR_NO_INIT_32
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (T1AD_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       T1AD_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "T1AD_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
  #pragma align 4

#elif defined (T1AD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       T1AD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (T1AD_START_SEC_VAR_INIT_BOOLEAN)
  #undef       T1AD_START_SEC_VAR_INIT_BOOLEAN
  #pragma section all "T1AD_RAM_VAR_INIT_BOOLEAN"
  #pragma clear
  #pragma align 0
#elif defined (T1AD_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       T1AD_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (T1AD_START_SEC_VAR_INIT_8)
  #undef       T1AD_START_SEC_VAR_INIT_8
  #pragma section all "T1AD_RAM_VAR_INIT_8"
  #pragma clear
  #pragma align 0
#elif defined (T1AD_STOP_SEC_VAR_INIT_8)
  #undef       T1AD_STOP_SEC_VAR_INIT_8
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (T1AD_START_SEC_VAR_INIT_16)
  #undef       T1AD_START_SEC_VAR_INIT_16
  #pragma section all "T1AD_RAM_VAR_INIT_16"
  #pragma clear
  #pragma align 0
#elif defined (T1AD_STOP_SEC_VAR_INIT_16)
  #undef       T1AD_STOP_SEC_VAR_INIT_16
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (T1AD_START_SEC_VAR_INIT_32)
  #undef       T1AD_START_SEC_VAR_INIT_32
  #pragma section all "T1AD_RAM_VAR_INIT_32"
  #pragma clear
  #pragma align 4
#elif defined (T1AD_STOP_SEC_VAR_INIT_32)
  #undef       T1AD_STOP_SEC_VAR_INIT_32
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (T1AD_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       T1AD_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all "T1AD_RAM_VAR_INIT_UNSPECIFIED"
  #pragma clear
  #pragma align 4
#elif defined (T1AD_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       T1AD_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (T1AD_START_SEC_CODE)
  #undef       T1AD_START_SEC_CODE
  #pragma section code "T1AD_CODE"
  #pragma section farrom "T1AD_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "T1AD_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "T1AD_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (T1AD_STOP_SEC_CODE)
  #undef       T1AD_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore
  
/* --------------------------------------------------------------------------*/
/*                               PROVAD                                      */
/* --------------------------------------------------------------------------*/
#elif defined (PROVAD_START_SEC_VAR_CLEARED_BOOLEAN)
  #undef       PROVAD_START_SEC_VAR_CLEARED_BOOLEAN
  #pragma section all "PROVAD_RAM_VAR_CLEARED_BOOLEAN"
  #pragma clear
  #pragma align 0

#elif defined (PROVAD_STOP_SEC_VAR_CLEARED_BOOLEAN)
  #undef       PROVAD_STOP_SEC_VAR_CLEARED_BOOLEAN
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (PROVAD_START_SEC_VAR_CLEARED_8)
  #undef       PROVAD_START_SEC_VAR_CLEARED_8
  #pragma section all "PROVAD_RAM_VAR_CLEARED_8"
  #pragma clear
  #pragma align 0

#elif defined (PROVAD_STOP_SEC_VAR_CLEARED_8)
  #undef       PROVAD_STOP_SEC_VAR_CLEARED_8
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (PROVAD_START_SEC_VAR_CLEARED_16)
  #undef       PROVAD_START_SEC_VAR_CLEARED_16
  #pragma section all "PROVAD_RAM_VAR_CLEARED_16"
  #pragma clear
  #pragma align 0

#elif defined (PROVAD_STOP_SEC_VAR_CLEARED_16)
  #undef       PROVAD_STOP_SEC_VAR_CLEARED_16
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (PROVAD_START_SEC_VAR_CLEARED_32)
  #undef       PROVAD_START_SEC_VAR_CLEARED_32
  #pragma section all "PROVAD_RAM_VAR_CLEARED_32"
  #pragma clear
  #pragma align 4

#elif defined (PROVAD_STOP_SEC_VAR_CLEARED_32)
  #undef       PROVAD_STOP_SEC_VAR_CLEARED_32
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (PROVAD_START_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       PROVAD_START_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma section all "PROVAD_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma clear
  #pragma align 4

#elif defined (PROVAD_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
  #undef       PROVAD_STOP_SEC_VAR_CLEARED_UNSPECIFIED
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (PROVAD_START_SEC_CONST_BOOLEAN)
  #undef       PROVAD_START_SEC_CONST_BOOLEAN
  #pragma section all "PROVAD_ROM_CONST_BOOLEAN"
  #pragma align 0

#elif defined (PROVAD_STOP_SEC_CONST_BOOLEAN)
  #undef       PROVAD_STOP_SEC_CONST_BOOLEAN
  #pragma align restore
  #pragma section all restore

#elif defined (PROVAD_START_SEC_CONST_8)
  #undef       PROVAD_START_SEC_CONST_8
  #pragma section all "PROVAD_ROM_CONST_8"
  #pragma align 0

#elif defined (PROVAD_STOP_SEC_CONST_8)
  #undef       PROVAD_STOP_SEC_CONST_8
  #pragma align restore
  #pragma section all restore

#elif defined (PROVAD_START_SEC_CONST_16)
  #undef       PROVAD_START_SEC_CONST_16
  #pragma section all "PROVAD_ROM_CONST_16"
  #pragma align 0  

#elif defined (PROVAD_STOP_SEC_CONST_16)
  #undef       PROVAD_STOP_SEC_CONST_16
  #pragma align restore
  #pragma section all restore

#elif defined (PROVAD_START_SEC_CONST_32)
  #undef       PROVAD_START_SEC_CONST_32
  #pragma section all "PROVAD_ROM_CONST_32"
  #pragma align 4

#elif defined (PROVAD_STOP_SEC_CONST_32)
  #undef       PROVAD_STOP_SEC_CONST_32
  #pragma align restore
  #pragma section all restore

#elif defined (PROVAD_START_SEC_CONST_UNSPECIFIED)
  #undef       PROVAD_START_SEC_CONST_UNSPECIFIED
  #pragma section all "PROVAD_ROM_CONST_UNSPECIFIED"
  #pragma align 4
  
#elif defined (PROVAD_STOP_SEC_CONST_UNSPECIFIED)
  #undef       PROVAD_STOP_SEC_CONST_UNSPECIFIED
  #pragma align restore
  #pragma section all restore

#elif defined (PROVAD_START_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       PROVAD_START_SEC_VAR_NO_INIT_BOOLEAN
  #pragma section all "PROVAD_RAM_VAR_NO_INIT_BOOLEAN"
  #pragma noclear
  #pragma align 0

#elif defined (PROVAD_STOP_SEC_VAR_NO_INIT_BOOLEAN)
  #undef       PROVAD_STOP_SEC_VAR_NO_INIT_BOOLEAN
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (PROVAD_START_SEC_VAR_NO_INIT_8)
  #undef       PROVAD_START_SEC_VAR_NO_INIT_8
  #pragma section all "PROVAD_RAM_VAR_NO_INIT_8"
  #pragma noclear
  #pragma align 0

#elif defined (PROVAD_STOP_SEC_VAR_NO_INIT_8)
  #undef       PROVAD_STOP_SEC_VAR_NO_INIT_8
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (PROVAD_START_SEC_VAR_NO_INIT_16)
  #undef       PROVAD_START_SEC_VAR_NO_INIT_16
  #pragma section all "PROVAD_RAM_VAR_NO_INIT_16"
  #pragma noclear
  #pragma align 0

#elif defined (PROVAD_STOP_SEC_VAR_NO_INIT_16)
  #undef       PROVAD_STOP_SEC_VAR_NO_INIT_16
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (PROVAD_START_SEC_VAR_NO_INIT_32)
  #undef       PROVAD_START_SEC_VAR_NO_INIT_32
  #pragma section all "PROVAD_RAM_VAR_NO_INIT_32"
  #pragma noclear
  #pragma align 4

#elif defined (PROVAD_STOP_SEC_VAR_NO_INIT_32)
  #undef       PROVAD_STOP_SEC_VAR_NO_INIT_32
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (PROVAD_START_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       PROVAD_START_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma section all "PROVAD_RAM_VAR_NO_INIT_UNSPECIFIED"
  #pragma noclear
  #pragma align 4

#elif defined (PROVAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED)
  #undef       PROVAD_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (PROVAD_START_SEC_VAR_INIT_BOOLEAN)
  #undef       PROVAD_START_SEC_VAR_INIT_BOOLEAN
  #pragma section all "PROVAD_RAM_VAR_INIT_BOOLEAN"
  #pragma clear
  #pragma align 0
#elif defined (PROVAD_STOP_SEC_VAR_INIT_BOOLEAN)
  #undef       PROVAD_STOP_SEC_VAR_INIT_BOOLEAN
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (PROVAD_START_SEC_VAR_INIT_8)
  #undef       PROVAD_START_SEC_VAR_INIT_8
  #pragma section all "PROVAD_RAM_VAR_INIT_8"
  #pragma clear
  #pragma align 0
#elif defined (PROVAD_STOP_SEC_VAR_INIT_8)
  #undef       PROVAD_STOP_SEC_VAR_INIT_8
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (PROVAD_START_SEC_VAR_INIT_16)
  #undef       PROVAD_START_SEC_VAR_INIT_16
  #pragma section all "PROVAD_RAM_VAR_INIT_16"
  #pragma clear
  #pragma align 0
#elif defined (PROVAD_STOP_SEC_VAR_INIT_16)
  #undef       PROVAD_STOP_SEC_VAR_INIT_16
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (PROVAD_START_SEC_VAR_INIT_32)
  #undef       PROVAD_START_SEC_VAR_INIT_32
  #pragma section all "PROVAD_RAM_VAR_INIT_32"
  #pragma clear
  #pragma align 4
#elif defined (PROVAD_STOP_SEC_VAR_INIT_32)
  #undef       PROVAD_STOP_SEC_VAR_INIT_32
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (PROVAD_START_SEC_VAR_INIT_UNSPECIFIED)
  #undef       PROVAD_START_SEC_VAR_INIT_UNSPECIFIED
  #pragma section all "PROVAD_RAM_VAR_INIT_UNSPECIFIED"
  #pragma clear
  #pragma align 4
#elif defined (PROVAD_STOP_SEC_VAR_INIT_UNSPECIFIED)
  #undef       PROVAD_STOP_SEC_VAR_INIT_UNSPECIFIED
  #pragma align restore
  #pragma clear
  #pragma section all restore

#elif defined (PROVAD_START_SEC_CODE)
  #undef       PROVAD_START_SEC_CODE
  #pragma section code "PROVAD_CODE"
  #pragma section farrom "PROVAD_ROM_CONST_UNSPECIFIED"
  #pragma section farbss "PROVAD_RAM_VAR_CLEARED_UNSPECIFIED"
  #pragma section fardata "PROVAD_RAM_VAR_INIT_UNSPECIFIED"
#elif defined (PROVAD_STOP_SEC_CODE)
  #undef       PROVAD_STOP_SEC_CODE
  #pragma section fardata restore
  #pragma section farbss restore
  #pragma section farrom restore
  #pragma section code restore

/* -------------------------------------------------------------------------- /
/ MuxDemuxIf /
/ -------------------------------------------------------------------------- */
#elif defined (MuxDemuxIf_START_SEC_CODE)
#undef MuxDemuxIf_START_SEC_CODE
#pragma ghs section text=".text.DEFAULT_CODE" 
#pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST" 
#pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED" 
#pragma ghs section data=".data.DEFAULT_RAM_VAR_INIT" 
#elif defined (MuxDemuxIf_STOP_SEC_CODE)
#undef MuxDemuxIf_STOP_SEC_CODE
#pragma ghs section
#elif defined (MuxDemuxIf_START_SEC_CONST_8)
#undef MuxDemuxIf_START_SEC_CONST_8
#pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST" 
#elif defined (MuxDemuxIf_STOP_SEC_CONST_8)
#undef MuxDemuxIf_STOP_SEC_CONST_8
#pragma ghs section

#elif defined (MuxDemuxIf_START_SEC_VAR_CLEARED_UNSPECIFIED)
 #undef MuxDemuxIf_START_SEC_VAR_CLEARED_UNSPECIFIED 

#pragma ghs section bss=".bss.DEFAULT_RAM_VAR_CLEARED" 
#elif defined (MuxDemuxIf_STOP_SEC_VAR_CLEARED_UNSPECIFIED)
 #undef MuxDemuxIf_STOP_SEC_VAR_CLEARED_UNSPECIFIED
 #pragma ghs section


#elif defined (MuxDemuxIf_START_SEC_CONST_UNSPECIFIED)
 #undef MuxDemuxIf_START_SEC_CONST_UNSPECIFIED 

#pragma ghs section rodata=".rodata.DEFAULT_ROM_CONST" 
#elif defined (MuxDemuxIf_STOP_SEC_CONST_UNSPECIFIED)
 #undef MuxDemuxIf_STOP_SEC_CONST_UNSPECIFIED
 #pragma ghs section

/*************************** Stack section ************************************/

/******************************END*********************************************/

#else
  #define SECTION_NOT_FOUND

  #if defined (USE_OS_MEMMAP)
    #define OS_DO_NOT_RAISE_ERROR

    #if defined (SECTION_NOT_FOUND)
      #undef SECTION_NOT_FOUND
      #include "Os_MemMap.h"
    #endif

    #undef OS_DO_NOT_RAISE_ERROR
  #endif

  #if defined (SECTION_NOT_FOUND)
    #undef SECTION_NOT_FOUND
    #include "Rte_MemMap.h"
  #endif

  #if defined (SECTION_NOT_FOUND)
    #undef SECTION_NOT_FOUND
    #include "Mcal_MemMap.h"
  #endif

  #if defined (SECTION_NOT_FOUND)
    #error "MemMap.h: No valid section define found"
  #endif
#endif  /* START_WITH_IF */

/* -------------------------------------------------------------------------- */
/* End of module section mapping                                              */
/* -------------------------------------------------------------------------- */

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

/*******************************************************************************
* PRE-JUSTIFICATION END SECTION (MISRA-C RULE CHECKER)
*******************************************************************************/
/* polyspace:end<MISRA-C:19.6:Not a defect:Justify with annotations> No Impact of this rule violation (AUTOSAR Standard : Memory Mapping) */


/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
