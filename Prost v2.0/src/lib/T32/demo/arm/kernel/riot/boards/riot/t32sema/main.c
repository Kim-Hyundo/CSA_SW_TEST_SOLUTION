/*
 * Copyright (C) 2014 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     examples
 * @{
 *
 * @file
 * @brief       TRACE32 demo application
 *
 * @author      Richard Copeman
 *
 * @}
 */

#include <stdio.h>

#include "thread.h"
#include "msg.h"
#include "mutex.h"
#include "xtimer.h"
#include "sema.h"
#include "mbox.h"
#include "list.h"
#include "rmutex.h"
#include "ringbuffer.h"


#define NUM_MSG 8
#define NUM_2_MSG 16

static sema_t sem1, sem2;

char second_thread_stack[THREAD_STACKSIZE_MAIN];
char mtx_thread_stack[512];
char mtx2_thread_stack[512];
char mtx3_thread_stack[512];

msg_t mq1[NUM_MSG];
msg_t mq2[NUM_2_MSG];
mbox_t mb1;
mbox_t mb2;

// Try a timed mutex acuisition - non-blocking
void *second_thread(void *arg)
{
    (void) arg;
    int i, ret;

    while (1) 
    {
        ret = sema_try_wait(&sem1);
        if (ret == 1)
        {
          // Mutex was unlocked - now we have it
          xtimer_sleep(2);
          // unlock and then sleep for a bit
          sema_post(&sem1);
          xtimer_sleep(2);
        }
        else
        {
          // Mutex not locked
          i++;
        }
        
        //ret = sema_try_wait(&sem2);
        ret = sema_wait(&sem1);
        if (ret == 1)
        {
          // Mutex was unlocked - now we have it
          xtimer_sleep(2);
          // unlock and then sleep for a bit
          sema_post(&sem1);
          xtimer_sleep(2);
        }
        else
        {
          // Mutex not locked
          i++;
        }
        xtimer_sleep(3);
    }

    return NULL;
}


///////////////////////////////////////////////////////////
// mtx_thread
//
// Try to acquire a mutex which is blocked by a higher 
// priority thread
void *mtx_thread(void *arg)
{
    int i, j;
	  (void) arg;
    
    i = 0;
    j = 0;
	while(1)
	{
        
		sema_wait(&sem1);
		for(i=0;i<1000;i++)
            j = i*2;
		sema_post(&sem1);
		for(i=0;i<1000;i++)
            j = i*2;
        i = j;
	}
}

static int hog_count = 0;

void *hog_mtx(void *arg)
{
    (void) arg;
    sema_wait(&sem1);

    while(1)
    {
      hog_count ++;
      xtimer_sleep(3);
    }
}
    


int main(void)
{
      
    xtimer_init();
    
    sema_create(&sem1, 1);
    sema_create(&sem2, 1);

    msg_t m;
    
    mbox_init(&mb1, mq1, NUM_MSG);
    mbox_init(&mb2, mq2, NUM_2_MSG);
    
    kernel_pid_t pid = thread_create(mtx3_thread_stack, 
                                     sizeof(mtx3_thread_stack),
                                     THREAD_PRIORITY_MAIN -2, THREAD_CREATE_STACKTEST,
                                     hog_mtx, 
                                     NULL, 
                                     "Sema_Hog");
    
    pid = thread_create(second_thread_stack,     
                                     sizeof(second_thread_stack),
                                     THREAD_PRIORITY_MAIN - 1, THREAD_CREATE_STACKTEST,
                                     second_thread, 
                                     NULL, 
                                     "sema_nonB");
                            
    pid = thread_create(mtx_thread_stack, sizeof(mtx_thread_stack),
                            THREAD_PRIORITY_MAIN + 2, THREAD_CREATE_STACKTEST,
                            mtx_thread, NULL, "sem_Wait_1");
    pid = thread_create(mtx2_thread_stack, sizeof(mtx2_thread_stack),
                            THREAD_PRIORITY_MAIN + 2, THREAD_CREATE_STACKTEST,
                            mtx_thread, NULL, "sem_wait_2");
    

    m.content.value = 1;
    (void) m;
    (void)pid;

    while (1) 
    {
        thread_sleep();
    }
}
