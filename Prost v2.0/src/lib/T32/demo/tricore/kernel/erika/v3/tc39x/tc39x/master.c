/* ###*B*###
 * Erika Enterprise, version 3
 * 
 * Copyright (C) 2017 - 2019 Evidence s.r.l.
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License, version 2, for more details.
 * 
 * You should have received a copy of the GNU General Public License,
 * version 2, along with this program; if not, see
 * <www.gnu.org/licenses/old-licenses/gpl-2.0.html >.
 * 
 * This program is distributed to you subject to the following
 * clarifications and special exceptions to the GNU General Public
 * License, version 2.
 * 
 * THIRD PARTIES' MATERIALS
 * 
 * Certain materials included in this library are provided by third
 * parties under licenses other than the GNU General Public License. You
 * may only use, copy, link to, modify and redistribute this library
 * following the terms of license indicated below for third parties'
 * materials.
 * 
 * In case you make modified versions of this library which still include
 * said third parties' materials, you are obligated to grant this special
 * exception.
 * 
 * The complete list of Third party materials allowed with ERIKA
 * Enterprise version 3, together with the terms and conditions of each
 * license, is present in the file THIRDPARTY.TXT in the root of the
 * project.
 * ###*E*### */

/** \file   code.c
 *  \brief  Main application.
 *
 *  This file contains the code of main application for Erika Enterprise.
 *
 *  \author Errico Guidieri
 *  \date   2018
 */

/* ERIKA Enterprise. */
#include "shared.h"
OsEE_reg myErrorCounter;

void ErrorHook(StatusType Error)
{
  (void)Error;

  ++myErrorCounter;
}

#if (defined(__TASKING__))
#define OS_CORE0_START_SEC_CODE
#include "Os_MemMap.h"
#endif /* __TASKING__ */

/* TASKs */
DeclareTask(Cpu0Task1);
DeclareTask(Cpu0Task2);
DeclareTask(Cpu0Task3);
DeclareTask(Cpu0Task4);
DeclareTask(Cpu0Task5);

/* Idle Hook */
extern void idle_hook_core0(void);
extern void free_Cpu0task1(void);

/* Counters */
OsEE_reg volatile cpu0task1_fired;
OsEE_reg volatile cpu0task2_fired;
OsEE_reg volatile cpu0task1_ended;
OsEE_reg volatile cpu0task2_ended;
OsEE_reg volatile cpu0task3_fired;
OsEE_reg volatile cpu0task3_ended;
OsEE_reg volatile cpu0task4_fired;
OsEE_reg volatile cpu0task5_fired;
OsEE_reg volatile cpu0isr2_armed;

/* Stack Pointers */
OsEE_addr volatile cpu0task1_sp;
OsEE_addr volatile cpu0task2_sp;
OsEE_addr volatile cpu0main_sp;


void free_Cpu0task1(void) {
	cpu0isr2_armed  = 0;
}

/**
 * sieve of erathostenes only executed on core 0
 */
char flags0[SIZE_FLAGS + 1];

int sieve0(void)
{
	register int i, primz, k;
	int anzahl;

	anzahl = 0;

	for (i = 0; i <= SIZE_FLAGS; flags0[i++] = 0xA0) {
	}

	for (i = 0; i <= SIZE_FLAGS; i++) {
		if (flags0[i]) {
			primz = i + i + 3;
			k = i + primz;
			while (k <= SIZE_FLAGS) {
				flags0[k] = FALSE;
				k += primz;
			}
			anzahl++;
		}
	}

	return anzahl;
}

/*
 * Cpu0TASK 1
 */
TASK(Cpu0Task1)
{
  OsEE_addr curr_sp;

  ++cpu0task1_fired;

  cpu0isr2_armed = 1U;

  curr_sp = osEE_get_SP();
  if (cpu0task1_sp == 0U) {
	  cpu0task1_sp = curr_sp;
  } else if (cpu0task1_sp != curr_sp) {
    OSEE_BREAK_POINT();
  }

  ActivateTask(Cpu0Task2);

  while (cpu0isr2_armed) {
    ; /* Wait ISR2 release */
  }

  curr_sp = osEE_get_SP();

  if (cpu0task1_sp != curr_sp) {
    OSEE_BREAK_POINT();
  }

  ++cpu0task1_ended;

  TerminateTask();
}

/*
 * Cpu0TASK 2
 */
TASK(Cpu0Task2)
{
  OsEE_addr  curr_sp;

  curr_sp = osEE_get_SP();

  if (cpu0task2_sp == NULL) {
	  cpu0task2_sp = curr_sp;
  } else if ( cpu0task2_sp != curr_sp ) {
    OSEE_BREAK_POINT();
  }

  ++cpu0task2_fired;

  ActivateTask(Cpu0Task3);
  ActivateTask(Cpu1Task3);
  cpu0task2_ended++;

  TerminateTask();
}

TASK(Cpu0Task3) {
  ++cpu0task3_fired;
  ActivateTask(Cpu0Task4);
  ++cpu0task3_ended;

  TerminateTask();
}

TASK(Cpu0Task4) {
  ++cpu0task4_fired;
  ActivateTask(Cpu0Task5);

  TerminateTask();
}

TASK(Cpu0Task5) {
  ++cpu0task5_fired;
  sieve0();
  TerminateTask();
}

void idle_hook_core0(void);
void idle_hook_core0(void)
{
  OsEE_addr volatile curr_sp = osEE_get_SP();

  if (cpu0main_sp == 0) {
	  cpu0main_sp = curr_sp;
  } else if (cpu0main_sp != curr_sp) {
	OSEE_BREAK_POINT();
  }
  idle_hook_body();
}

#if (defined(__TASKING__))
#define OS_CORE0_STOP_SEC_CODE
#include "Os_MemMap.h"
#endif /* __TASKING__ */

/*
 * MAIN TASK
 */
int main(void)
{
  StatusType       status;
  AppModeType      mode;
  CoreIdType const core_id = GetCoreID();

  if (core_id == OS_CORE_ID_MASTER) {
    StartCore(OS_CORE_ID_1, &status);
    StartCore(OS_CORE_ID_2, &status);

    mode = OSDEFAULTAPPMODE;
  } else {

    mode = DONOTCARE;
  }

  StartOS(mode);

  return 0;
}


