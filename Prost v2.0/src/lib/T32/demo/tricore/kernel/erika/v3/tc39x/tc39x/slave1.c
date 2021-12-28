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


#include "shared.h"

#if (defined(__TASKING__))
#define OS_CORE1_START_SEC_CODE
#include "Os_MemMap.h"
#endif /* __TASKING__ */

/* TASKs */
DeclareTask(Cpu1Task1);
DeclareTask(Cpu1Task2);
DeclareTask(Cpu1Task3);
DeclareTask(Cpu1Task4);
DeclareTask(Cpu1Task5);

/* Idle Hook */
extern void idle_hook_core1(void);
extern void free_Cpu1task1(void);

/* Counters */
OsEE_reg volatile cpu1task1_fired;
OsEE_reg volatile cpu1task2_fired;
OsEE_reg volatile cpu1task1_ended;
OsEE_reg volatile cpu1task2_ended;
OsEE_reg volatile cpu1task3_fired;
OsEE_reg volatile cpu1task3_ended;
OsEE_reg volatile cpu1task4_fired;
OsEE_reg volatile cpu1task5_fired;
OsEE_reg volatile cpu1isr2_armed;

/* Stack Pointers */
OsEE_addr volatile cpu1task1_sp;
OsEE_addr volatile cpu1task2_sp;
OsEE_addr volatile cpu1main_sp;


void free_Cpu1task1(void) {
	cpu1isr2_armed  = 0;
}

/**
 * sieve of erathostenes only executed on core 1
 */
char flags1[SIZE_FLAGS + 1];

int sieve1(void)
{
	register int i, primz, k;
	int anzahl;

	anzahl = 0;

	for (i = 0; i <= SIZE_FLAGS; flags1[i++] = 0xA1) {
	}

	for (i = 0; i <= SIZE_FLAGS; i++) {
		if (flags1[i]) {
			primz = i + i + 3;
			k = i + primz;
			while (k <= SIZE_FLAGS) {
				flags1[k] = FALSE;
				k += primz;
			}
			anzahl++;
		}
	}

	return anzahl;
}

/*
 * Cpu1TASK 1
 */
TASK(Cpu1Task1)
{
  OsEE_addr curr_sp;

  ++cpu1task1_fired;

  cpu1isr2_armed = 1U;

  curr_sp = osEE_get_SP();
  if (cpu1task1_sp == 0U) {
	  cpu1task1_sp = curr_sp;
  } else if (cpu1task1_sp != curr_sp) {
    OSEE_BREAK_POINT();
  }

  ActivateTask(Cpu1Task2);

  while (cpu1isr2_armed) {
    ; /* Wait ISR2 release */
  }

  curr_sp = osEE_get_SP();

  if (cpu1task1_sp != curr_sp) {
    OSEE_BREAK_POINT();
  }

  ++cpu1task1_ended;

  TerminateTask();
}

/*
 * Cpu1TASK 2
 */
TASK(Cpu1Task2)
{
  OsEE_addr  curr_sp;

  curr_sp = osEE_get_SP();

  if (cpu1task2_sp == NULL) {
	  cpu1task2_sp = curr_sp;
  } else if ( cpu1task2_sp != curr_sp ) {
    OSEE_BREAK_POINT();
  }

  ++cpu1task2_fired;

  cpu1task2_ended++;

  TerminateTask();
}

TASK(Cpu1Task3) {
  ++cpu1task3_fired;
  if(cpu1task3_fired%10){
	  ActivateTask(Cpu1Task4);
  } else {
	  ActivateTask(Cpu1Task5);
  }
  ++cpu1task3_ended;

  TerminateTask();
}

TASK(Cpu1Task4) {
  ++cpu1task4_fired;
  sieve1();
  TerminateTask();
}

TASK(Cpu1Task5) {
  ++cpu1task5_fired;
  sieve1();
  TerminateTask();
}

void idle_hook_core1(void);
void idle_hook_core1(void)
{
  OsEE_addr volatile curr_sp = osEE_get_SP();

  if (cpu1main_sp == 0) {
	  cpu1main_sp = curr_sp;
  } else if (cpu1main_sp != curr_sp) {
	OSEE_BREAK_POINT();
  }
  idle_hook_body();
}

#if (defined(__TASKING__))
#define OS_CORE1_STOP_SEC_CODE
#include "Os_MemMap.h"
#endif /* __TASKING__ */
