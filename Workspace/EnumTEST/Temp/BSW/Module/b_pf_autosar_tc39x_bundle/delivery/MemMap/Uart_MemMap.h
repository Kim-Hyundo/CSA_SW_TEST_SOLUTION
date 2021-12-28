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
**  FILENAME  : Uart_MemMap.h                                                 **
**                                                                            **
**  VERSION   :  <to be filled>                                               **
**                                                                            **
**  DATE      : 14/03/2019                                                    **
**                                                                            **
**  VARIANT   : NA                                                            **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY :                                                            **
**                                                                            **
**  DESCRIPTION  : This file contains the mapping of Memory Section           **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
**  SPECIFICATION(S) : Specification of UART Driver,                          **
**   AUTOSAR Release <4.2.2>                                                  **
**                                                                            **
**  MAY BE CHANGED BY USER : Yes                                              **
**                                                                            **
*******************************************************************************/
#define MEMMAP_ERROR
#if ((APP_SW == DEMO_APP) || (APP_SW == TEST_APP))
/*DATA Section*/
/*To be used for all global or static variables.*/
/*Variable to be cleared at startup or reset is palced here - .bss*/
#if defined UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
#ifdef _TASKING_C_TRICORE_
#pragma section farbss "ClearedData.Cpu0.8bit"
#elif defined _GNU_C_TRICORE_
#pragma section  "ClearedData.Cpu0.8bit" aw
#elif defined _GHS_C_TRICORE_
#pragma ghs section bss = ".ClearedData.Cpu0.8bit"
#elif defined _DIABDATA_C_TRICORE_
#pragma section DATA "InitData.Cpu0.8bit" "ClearedData.Cpu0.8bit" far-absolute RW
#endif
#undef  UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
#undef MEMMAP_ERROR
#elif defined UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
#ifdef _TASKING_C_TRICORE_
#pragma section farbss restore
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma section 
#endif
#undef  UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
#undef MEMMAP_ERROR

#elif defined UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
#ifdef _TASKING_C_TRICORE_
#pragma section farbss "ClearedData.Cpu0.32bit"
#pragma align 4
#elif defined _GNU_C_TRICORE_
#pragma section  "ClearedData.Cpu0.32bit" aw 4
#elif defined _GHS_C_TRICORE_
#pragma ghs section bss = ".ClearedData.Cpu0.32bit"
#elif defined _DIABDATA_C_TRICORE_
#pragma section DATA "InitData.Cpu0.32bit" "ClearedData.Cpu0.32bit" far-absolute RW
#endif
#undef  UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
#undef MEMMAP_ERROR
#elif defined UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section farbss restore
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma section 
#endif
#undef  UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
#undef MEMMAP_ERROR

#elif defined UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
#ifdef _TASKING_C_TRICORE_
#pragma section farbss "ClearedData.Cpu0.Unspecified"
#pragma align 4
#elif defined _GNU_C_TRICORE_
#pragma section  "ClearedData.Cpu0.Unspecified" aw 4
#elif defined _GHS_C_TRICORE_
#pragma ghs section bss = ".ClearedData.Cpu0.Unspecified"
#elif defined _DIABDATA_C_TRICORE_
#pragma section DATA "InitData.Cpu0.Unspecified" "ClearedData.Cpu0.Unspecified" far-absolute RW
#endif
#undef  UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
#undef MEMMAP_ERROR
#elif defined UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section farbss restore
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma section 
#endif
#undef  UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
#undef MEMMAP_ERROR

#elif defined UART_START_SEC_VAR_INIT_ASIL_B_LOCAL_8
#ifdef _TASKING_C_TRICORE_
#pragma section fardata "InitData.Cpu0.8bit"
#elif defined _GNU_C_TRICORE_
#pragma section "InitData.Cpu0.8bit" aw
#elif defined _GHS_C_TRICORE_
#pragma ghs section data = ".InitData.Cpu0.8bit"
#elif defined _DIABDATA_C_TRICORE_
#pragma section DATA "InitData.Cpu0.8bit"  "ClearedData.Cpu0.8bit" far-absolute RW
#endif
#undef  UART_START_SEC_VAR_INIT_ASIL_B_LOCAL_8
#undef MEMMAP_ERROR
#elif defined UART_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_8
#ifdef _TASKING_C_TRICORE_
#pragma section fardata restore
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma section 
#endif
#undef  UART_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_8
#undef MEMMAP_ERROR

#elif defined UART_START_SEC_VAR_INIT_ASIL_B_LOCAL_16
#ifdef _TASKING_C_TRICORE_
#pragma section fardata "InitData.Cpu0.16bit"
#pragma align 2
#elif defined _GNU_C_TRICORE_
#pragma section "InitData.Cpu0.16bit" aw 2
#elif defined _GHS_C_TRICORE_
#pragma ghs section data = ".InitData.Cpu0.16bit"
#elif defined _DIABDATA_C_TRICORE_
#pragma section DATA "InitData.Cpu0.16bit"  "ClearedData.Cpu0.16bit" far-absolute RW
#endif
#undef  UART_START_SEC_VAR_INIT_ASIL_B_LOCAL_16
#undef MEMMAP_ERROR
#elif defined UART_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_16
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section fardata restore
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma section 
#endif
#undef  UART_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_16
#undef MEMMAP_ERROR

#elif defined UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_16
#ifdef _TASKING_C_TRICORE_
#pragma section farbss "ClearedData.Cpu0.16bit"
#pragma align 2
#elif defined _GNU_C_TRICORE_
#pragma section  "ClearedData.Cpu0.16bit" aw 2
#elif defined _GHS_C_TRICORE_
#pragma ghs section bss = ".ClearedData.Cpu0.16bit"
#elif defined _DIABDATA_C_TRICORE_
#pragma section DATA "InitData.Cpu0.16bit" "ClearedData.Cpu0.16bit" far-absolute RW
#endif
#undef  UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_16
#undef MEMMAP_ERROR
#elif defined UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_16
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section farbss restore
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma section 
#endif
#undef  UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_16
#undef MEMMAP_ERROR

/***************** Static Global Constants Sections ************************/
#elif defined UART_START_SEC_CONST_ASIL_B_LOCAL_32
#ifdef _TASKING_C_TRICORE_
#pragma section farrom  "Const.Cpu0.32bit"
#pragma align 4
#elif defined _GNU_C_TRICORE_
#pragma section  "Const.Cpu0.32bit" a 4
#elif defined _GHS_C_TRICORE_
#pragma ghs section rodata = ".Const.Cpu0.32bit"
#elif defined _DIABDATA_C_TRICORE_
#pragma section CONST "Const.Cpu0.32bit" far-absolute R
#endif
#undef  UART_START_SEC_CONST_ASIL_B_LOCAL_32
#undef MEMMAP_ERROR
#elif defined UART_STOP_SEC_CONST_ASIL_B_LOCAL_32
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section farrom restore
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma section 
#endif
#undef  UART_STOP_SEC_CONST_ASIL_B_LOCAL_32
#undef MEMMAP_ERROR

#elif defined UART_START_SEC_CONST_ASIL_B_LOCAL_8
#ifdef _TASKING_C_TRICORE_
#pragma section farrom  "Const.Cpu0.8bit"
#elif defined _GNU_C_TRICORE_
#pragma section  "Const.Cpu0.8bit" a
#elif defined _GHS_C_TRICORE_
#pragma ghs section rodata = ".Const.Cpu0.8bit"
#elif defined _DIABDATA_C_TRICORE_
#pragma section CONST "Const.Cpu0.8bit" far-absolute R
#endif
#undef  UART_START_SEC_CONST_ASIL_B_LOCAL_8
#undef MEMMAP_ERROR
#elif defined UART_STOP_SEC_CONST_ASIL_B_LOCAL_8
#ifdef _TASKING_C_TRICORE_
#pragma section farrom restore
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma section 
#endif
#undef  UART_STOP_SEC_CONST_ASIL_B_LOCAL_8
#undef MEMMAP_ERROR

#elif defined UART_START_SEC_CONST_ASIL_B_LOCAL_16
#ifdef _TASKING_C_TRICORE_
#pragma section farrom  "Const.Cpu0.16bit"
#pragma align 2
#elif defined _GNU_C_TRICORE_
#pragma section  "Const.Cpu0.16bit" a 2
#elif defined _GHS_C_TRICORE_
#pragma ghs section rodata = ".Const.Cpu0.16bit"
#elif defined _DIABDATA_C_TRICORE_
#pragma section CONST "Const.Cpu0.16bit" far-absolute R
#endif
#undef  UART_START_SEC_CONST_ASIL_B_LOCAL_16
#undef MEMMAP_ERROR
#elif defined UART_STOP_SEC_CONST_ASIL_B_LOCAL_16
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section farrom restore
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma section 
#endif
#undef  UART_STOP_SEC_CONST_ASIL_B_LOCAL_16
#undef MEMMAP_ERROR

/******************* Config Data Sections *************************/
#elif defined UART_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
#ifdef _TASKING_C_TRICORE_
#pragma section farrom "Config.Cpu0.Unspecified"
#pragma align 4
#elif defined _GNU_C_TRICORE_
#pragma section "Config.Cpu0.Unspecified" a 4
#elif defined _GHS_C_TRICORE_
#pragma ghs section rodata = ".Config.Cpu0.Unspecified"
#elif defined _DIABDATA_C_TRICORE_
#pragma section CONST "Config.Cpu0.Unspecified" far-absolute R
#endif
#undef  UART_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
#undef MEMMAP_ERROR
#elif defined UART_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
#ifdef _TASKING_C_TRICORE_
#pragma align restore
#pragma section farrom restore
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma section 
#endif
#undef  UART_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
#undef MEMMAP_ERROR

/* Code Sections */
/*
To be used for mapping code to application block, boot block, external flash etc.
codePeriod is the typical period time value and unit of the ExecutableEntitys in this MemorySection.
The name part _{codePeriod} is optional. Units are:
- US microseconds
- MS milli second
- S second
*/
#elif defined UART_START_SEC_CODE_ASIL_B_LOCAL
#ifdef _TASKING_C_TRICORE_
#pragma section code "Code.Cpu0"
#elif defined _GNU_C_TRICORE_
#pragma section "Code.Cpu0" ax
#elif defined _GHS_C_TRICORE_
#pragma ghs section text  = ".Code.Cpu0"
#elif defined _DIABDATA_C_TRICORE_
#pragma section CODE "Code.Cpu0" RX
#endif
#undef  UART_START_SEC_CODE_ASIL_B_LOCAL
#undef MEMMAP_ERROR
#elif defined UART_STOP_SEC_CODE_ASIL_B_LOCAL
#ifdef _TASKING_C_TRICORE_
#pragma section code restore
#elif defined _GNU_C_TRICORE_
#pragma section
#elif defined _GHS_C_TRICORE_
#pragma ghs section
#elif defined _DIABDATA_C_TRICORE_
#pragma section 
#endif
#undef  UART_STOP_SEC_CODE_ASIL_B_LOCAL
#undef MEMMAP_ERROR

#endif

#else  /*#if ((APP_SW == DEMO_APP) || (APP_SW == TEST_APP))*/ 
/***********************************EMPTY SECTIONS***********************************/
#if defined UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
#undef  UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
#undef MEMMAP_ERROR
#elif defined UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
#undef  UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_8
#undef MEMMAP_ERROR
#elif defined UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
#undef  UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
#undef MEMMAP_ERROR
#elif defined UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
#undef  UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_32
#undef MEMMAP_ERROR
#elif defined UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
#undef  UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
#undef MEMMAP_ERROR
#elif defined UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
#undef  UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_UNSPECIFIED
#undef MEMMAP_ERROR
#elif defined UART_START_SEC_VAR_INIT_ASIL_B_LOCAL_8
#undef  UART_START_SEC_VAR_INIT_ASIL_B_LOCAL_8
#undef MEMMAP_ERROR
#elif defined UART_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_8
#undef  UART_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_8
#undef MEMMAP_ERROR
#elif defined UART_START_SEC_VAR_INIT_ASIL_B_LOCAL_16
#undef  UART_START_SEC_VAR_INIT_ASIL_B_LOCAL_16
#undef MEMMAP_ERROR
#elif defined UART_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_16
#undef  UART_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_16
#undef MEMMAP_ERROR
#elif defined UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_16
#undef  UART_START_SEC_VAR_CLEARED_ASIL_B_LOCAL_16
#undef MEMMAP_ERROR
#elif defined UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_16
#undef  UART_STOP_SEC_VAR_CLEARED_ASIL_B_LOCAL_16
#undef MEMMAP_ERROR
#elif defined UART_START_SEC_CONST_ASIL_B_LOCAL_32
#undef  UART_START_SEC_CONST_ASIL_B_LOCAL_32
#undef MEMMAP_ERROR
#elif defined UART_STOP_SEC_CONST_ASIL_B_LOCAL_32
#undef  UART_STOP_SEC_CONST_ASIL_B_LOCAL_32
#undef MEMMAP_ERROR
#elif defined UART_START_SEC_CONST_ASIL_B_LOCAL_8
#undef  UART_START_SEC_CONST_ASIL_B_LOCAL_8
#undef MEMMAP_ERROR
#elif defined UART_STOP_SEC_CONST_ASIL_B_LOCAL_8
#undef  UART_STOP_SEC_CONST_ASIL_B_LOCAL_8
#undef MEMMAP_ERROR
#elif defined UART_START_SEC_CONST_ASIL_B_LOCAL_16
#undef  UART_START_SEC_CONST_ASIL_B_LOCAL_16
#undef MEMMAP_ERROR
#elif defined UART_STOP_SEC_CONST_ASIL_B_LOCAL_16
#undef  UART_STOP_SEC_CONST_ASIL_B_LOCAL_16
#undef MEMMAP_ERROR
#elif defined UART_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
#undef  UART_START_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
#undef MEMMAP_ERROR
#elif defined UART_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
#undef  UART_STOP_SEC_CONFIG_DATA_ASIL_B_LOCAL_UNSPECIFIED
#undef MEMMAP_ERROR
#elif defined UART_START_SEC_CODE_ASIL_B_LOCAL
#undef  UART_START_SEC_CODE_ASIL_B_LOCAL
#undef MEMMAP_ERROR
#elif defined UART_STOP_SEC_CODE_ASIL_B_LOCAL
#undef  UART_STOP_SEC_CODE_ASIL_B_LOCAL
#undef MEMMAP_ERROR
#endif

#endif /*#if ((APP_SW == DEMO_APP) || (APP_SW == TEST_APP))*/ 

#if defined MEMMAP_ERROR
#error "uart_MemMap.h, wrong pragma command"
#endif
