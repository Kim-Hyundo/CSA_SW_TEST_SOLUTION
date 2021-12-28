/*
 * File:        ping.c
 *
 * uC/OS Real-time multitasking kernel for the ARM processor.
 *
 * This program is an example of using semaphore to
 * implement task rendevous.
 *
 * Created by Marco Graziano (marcog@crl.com).
 *
 */

#include	"../../includes.h"               /* uC/OS interface */

/* allocate memory for tasks' stacks */
#ifdef SEMIHOSTED
#define STACKSIZE       (SEMIHOSTED_STACK_NEEDS+64)
#else
#define	STACKSIZE	256
#endif
unsigned int Stack1[STACKSIZE];
unsigned int Stack2[STACKSIZE];

/* semaphores event control blocks */
OS_EVENT *Sem1;
OS_EVENT *Sem2;

/*
 * Task running at the highest priority. 
 */
void
 Task1(void *i)
{
    INT8U Reply;

    for (;;)
    {
        /* wait for the semaphore  */
        OSSemPend(Sem2, 0, &Reply);

        uHALr_printf("1+");

        /* wait a short while */
		//OSTimeDly(100);

        uHALr_printf("1-");

        /* signal the semaphore */
        OSSemPost(Sem1);
    }
}

void
 Task2(void *i)
{
    INT8U Reply;

    for (;;)
    {
        /* wait for the semaphore */
        OSSemPend(Sem1, 0, &Reply);

      uHALr_printf("[");

        /* wait a short while */
		//OSTimeDly(1000);

        uHALr_printf("2]");

        /* signal the semaphore */
        OSSemPost(Sem2);
    }
}

/*
 * Main function.
 */
int
 Main(int argc, char **argv)
{
    INT8U error;
    char Id1 = '1';
    char Id2 = '2';

    /* do target (uHAL based ARM system) initialisation */
    ARMTargetInit();

    /* needed by uC/OS */
    OSInit();

    OSTimeSet(0);
    /* 
     * create the semaphores
     */
    Sem1 = OSSemCreate(1);
    OSEventNameSet (Sem1, "Sem1", &error);
    Sem2 = OSSemCreate(1);

    /* 
     * create the tasks in uC/OS and assign decreasing
     * priority to them 
     */
    OSTaskCreateExt(Task1, (void *)&Id1, (OS_STK *)&Stack1[STACKSIZE - 1], 11, 
        11, &Stack1[0], STACKSIZE, 0, OS_TASK_OPT_STK_CLR);
    OSTaskNameSet (11, "Task1", &error);
    
    OSTaskCreateExt(Task2, (void *)&Id2, (OS_STK *)&Stack2[STACKSIZE - 1], 12,
        12, &Stack2[0], STACKSIZE, 0, OS_TASK_OPT_STK_CLR);
    OSTaskNameSet (12, "Task2", &error);

    /* Start the (uHAL based ARM system) system running */
    ARMTargetStart();

    /* start the game */
    OSStart();

    /* never reached */

    return 0;
}                               /* main */
