/* ###*B*###
 *
 * ERIKA Enterprise - a tiny RTOS for small microcontrollers
 * 
 * Copyright (C) 2002-2018 Evidence Srl
 * 
 * This file is part of ERIKA Enterprise.
 * 
 * See LICENSE file.
 *
 * ###*E*### */

/***************************************************************************
 *
 * This file is generated by RT-Druid.
 * Please do not modify it.
 *
 **************************************************************************/

#ifndef OS_EE_RTD_APPLCFG_H
#define OS_EE_RTD_APPLCFG_H

/***************************************************************************
 *
 * OS Configuration
 *
 **************************************************************************/
#include "ee_oscfg.h"

#if (defined(__cplusplus))
extern "C" {
#endif

/***************************************************************************
 *
 * Version Check
 *
 **************************************************************************/
#define OS_EE_RTD_GEN_VERSION 12345

/***************************************************************************
 *
 * Arrays size
 *
 **************************************************************************/
#define OSEE_TASK_ARRAY_SIZE      (16U)
#define OSEE_SN_ARRAY_SIZE        (16U)
#define OSEE_STACK_ARRAY_SIZE     (10U)
#define OSEE_COUNTERS_ARRAY_SIZE  (3U)
#define OSEE_ALARMS_ARRAY_SIZE    (6U)

/***************************************************************************
 *
 * CPU0 TASKs declaration
 *
 **************************************************************************/
#define Cpu0Task1 (1U)
#define Cpu0Task2 (2U)
#define Cpu0Task3 (3U)
#define Cpu0Task4 (4U)
#define Cpu0Task5 (5U)

/***************************************************************************
 *
 * CPU0 Stack Size declaration
 *
 **************************************************************************/
#define osEE_task_stack_1_StackSize (128U)
#define osEE_task_stack_2_StackSize (128U)

/***************************************************************************
 *
 * CPU0 RESOURCEs Macro Declaration
 *
 **************************************************************************/

/***************************************************************************
 *
 * CPU0 COUNTERs Macro Declaration
 *
 **************************************************************************/
#define system_timer_cpu0 (0U)

/***************************************************************************
 *
 * CPU0 ALARMs Declaration
 *
 **************************************************************************/
#define AlarmCpu0Task1 (0U)
#define AlarmFreeCpu0Task1 (1U)

/***************************************************************************
 *
 * CPU0 Schedule Tables Declaration
 *
 **************************************************************************/
/***************************************************************************
 *
 * CPU1 TASKs declaration
 *
 **************************************************************************/
#define Cpu1Task1 (7U)
#define Cpu1Task2 (8U)
#define Cpu1Task3 (9U)
#define Cpu1Task4 (10U)
#define Cpu1Task5 (11U)

/***************************************************************************
 *
 * CPU1 Stack Size declaration
 *
 **************************************************************************/
#define osEE_task_stack_4_StackSize (128U)
#define osEE_task_stack_5_StackSize (128U)

/***************************************************************************
 *
 * CPU1 RESOURCEs Macro Declaration
 *
 **************************************************************************/

/***************************************************************************
 *
 * CPU1 COUNTERs Macro Declaration
 *
 **************************************************************************/
#define system_timer_cpu1 (1U)

/***************************************************************************
 *
 * CPU1 ALARMs Declaration
 *
 **************************************************************************/
#define AlarmCpu1Task1 (2U)
#define AlarmFreeCpu1Task1 (3U)

/***************************************************************************
 *
 * CPU1 Schedule Tables Declaration
 *
 **************************************************************************/
/***************************************************************************
 *
 * CPU2 TASKs declaration
 *
 **************************************************************************/
#define Cpu2Task1 (13U)
#define Cpu2Task2 (14U)
#define Cpu2Task3 (15U)

/***************************************************************************
 *
 * CPU2 Stack Size declaration
 *
 **************************************************************************/
#define osEE_task_stack_7_StackSize (128U)
#define osEE_task_stack_8_StackSize (128U)
#define osEE_task_stack_9_StackSize (128U)

/***************************************************************************
 *
 * CPU2 RESOURCEs Macro Declaration
 *
 **************************************************************************/

/***************************************************************************
 *
 * CPU2 COUNTERs Macro Declaration
 *
 **************************************************************************/
#define system_timer_cpu2 (2U)

/***************************************************************************
 *
 * CPU2 ALARMs Declaration
 *
 **************************************************************************/
#define AlarmCpu2Task1 (4U)
#define AlarmFreeCpu2Task1 (5U)

/***************************************************************************
 *
 * CPU2 Schedule Tables Declaration
 *
 **************************************************************************/

/***************************************************************************
 *
 * EVENTs declaration
 *
 **************************************************************************/

/***************************************************************************
 *
 * AppMode Declaration
 *
 **************************************************************************/



#if (defined(__cplusplus))
}
#endif
/***************************************************************************
 *
 * End
 *
 **************************************************************************/

#endif /* OS_EE_RTD_APPLCFG_H */
