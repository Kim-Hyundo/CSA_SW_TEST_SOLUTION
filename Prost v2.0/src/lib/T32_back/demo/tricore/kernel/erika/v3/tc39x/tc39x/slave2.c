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
#define OS_CORE2_START_SEC_CODE
#include "Os_MemMap.h"
#endif /* __TASKING__ */

/* TASKs */
DeclareTask(Cpu2Task1);
DeclareTask(Cpu2Task2);
DeclareTask(Cpu2Task3);


/* Idle Hook */
extern void idle_hook_core2(void);
extern void free_Cpu2task1(void);

/* Counters */
OsEE_reg volatile cpu2task1_fired;
OsEE_reg volatile cpu2task2_fired;
OsEE_reg volatile cpu2task1_ended;
OsEE_reg volatile cpu2task2_ended;
OsEE_reg volatile cpu2task3_fired;
OsEE_reg volatile cpu2task3_ended;
OsEE_reg volatile cpu2task4_fired;
OsEE_reg volatile cpu2task5_fired;
OsEE_reg volatile cpu2isr2_armed;

/* Stack Pointers */
OsEE_addr volatile cpu2task1_sp;
OsEE_addr volatile cpu2task2_sp;
OsEE_addr volatile cpu2task3_sp;
OsEE_addr volatile cpu2main_sp;


void free_Cpu2task1(void) {
	cpu2isr2_armed  = 0;
}

/**
 * sieve of erathostenes only executed on core 2
 */
char flags2[SIZE_FLAGS + 1];

int sieve2(void)
{
	register int i, primz, k;
	int anzahl;

	anzahl = 0;

	for (i = 0; i <= SIZE_FLAGS; flags2[i++] = 0xA2) {
	}

	for (i = 0; i <= SIZE_FLAGS; i++) {
		if (flags2[i]) {
			primz = i + i + 3;
			k = i + primz;
			while (k <= SIZE_FLAGS) {
				flags2[k] = FALSE;
				k += primz;
			}
			anzahl++;
		}
	}

	return anzahl;
}

/*
 * Cpu2TASK 1
 */
TASK(Cpu2Task1)
{
  OsEE_addr curr_sp;

  ++cpu2task1_fired;

  cpu2isr2_armed = 1U;

  curr_sp = osEE_get_SP();
  if (cpu2task1_sp == 0U) {
	  cpu2task1_sp = curr_sp;
  } else if (cpu2task1_sp != curr_sp) {
    OSEE_BREAK_POINT();
  }

  if(cpu2task1_fired%2){
    ActivateTask(Cpu2Task2);
  } else {
	  ActivateTask(Cpu2Task3);
  }

  while (cpu2isr2_armed) {
    ; /* Wait ISR2 release */
  }

  curr_sp = osEE_get_SP();

  if (cpu2task1_sp != curr_sp) {
    OSEE_BREAK_POINT();
  }

  ++cpu2task1_ended;

  TerminateTask();
}

/*
 * Cpu2TASK 2
 */
TASK(Cpu2Task2)
{
  OsEE_addr  curr_sp;

  curr_sp = osEE_get_SP();

  if (cpu2task2_sp == NULL) {
	  cpu2task2_sp = curr_sp;
  } else if ( cpu2task2_sp != curr_sp ) {
    OSEE_BREAK_POINT();
  }

  ++cpu2task2_fired;
  sieve2();
  cpu2task2_ended++;

  TerminateTask();
}

TASK(Cpu2Task3) {
  OsEE_addr  curr_sp;

  curr_sp = osEE_get_SP();

  if (cpu2task3_sp == NULL) {
	  cpu2task3_sp = curr_sp;
  } else if ( cpu2task3_sp != curr_sp ) {
	OSEE_BREAK_POINT();
  }
  ++cpu2task3_fired;
  sieve2();
  ++cpu2task3_ended;

  TerminateTask();
}



void idle_hook_core2(void);
void idle_hook_core2(void)
{
  OsEE_addr volatile curr_sp = osEE_get_SP();

  if (cpu2main_sp == 0) {
	  cpu2main_sp = curr_sp;
  } else if (cpu2main_sp != curr_sp) {
	OSEE_BREAK_POINT();
  }
  idle_hook_body();
}

#if (defined(__TASKING__))
#define OS_CORE2_STOP_SEC_CODE
#include "Os_MemMap.h"
#endif /* __TASKING__ */
