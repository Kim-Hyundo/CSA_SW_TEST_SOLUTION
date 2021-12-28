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


#define NUM_MSG 8
#define NUM_2_MSG 16

static mutex_t m1 = MUTEX_INIT;
static sema_t sem1, sem2;

char second_thread_stack[THREAD_STACKSIZE_MAIN];
char mtx_thread_stack[512];
char mtx2_thread_stack[512];
char mtx3_thread_stack[512];

msg_t mq1[NUM_MSG];
msg_t mq2[NUM_2_MSG];
mbox_t mb1;
mbox_t mb2;


void *second_thread(void *arg)
{
    (void) arg;

    printf("2nd thread started, pid: %" PRIkernel_pid "\n", thread_getpid());
    msg_t m;

    while (1) {
        msg_receive(&m);
        printf("2nd: Got msg from %" PRIkernel_pid "\n", m.sender_pid);
        m.content.value++;
        msg_reply(&m, &m);
    }

    return NULL;
}


///////////////////////////////////////////////////////////
// mtx_thread
//
// Grab a mutex for a while and then release it 
void *mtx_thread(void *arg)
{
    int i, j;
	(void) arg;
    msg_t msg1;
    
    i = 0;
    j = 0;
	while(1)
	{
    mbox_get(&mb2,&msg1);
        
		mutex_lock(&m1);
		for(i=0;i<1000;i++)
            j = i*2;
		mutex_unlock(&m1);
		for(i=0;i<1000;i++)
            j = i*2;
        i = j;
	}
}

void *hog_mtx(void *arg)
{
    (void) arg;
    msg_t m1, m2;
    //mutex_lock(&m1);
    _sema_wait(&sem1, 1, 0);    //Block forever if not available
    
    m1.type = 1;
    m1.content.value = 100;
    
    m2.type = 1;
    m2.content.value = 255;
    
    mbox_put(&mb1,&m1);
    mbox_put(&mb1,&m2);
    mbox_put(&mb1,&m1);
    mbox_put(&mb1,&m2);
    
    mbox_put(&mb2,&m2);
    mbox_put(&mb2,&m2);
    mbox_put(&mb2,&m2);
    
    while(1)
    {
        xtimer_sleep(1);
    }
}
    


int main(void)
{
    printf("Starting t32demo example...\n");
    printf("1st thread started, pid: %" PRIkernel_pid "\n", thread_getpid());
    
    xtimer_init();
    
    sema_create(&sem1, 1);
    sema_create(&sem2, 1);

    msg_t m;
    
    mbox_init(&mb1, mq1, NUM_MSG);
    mbox_init(&mb2, mq2, NUM_2_MSG);
    
    kernel_pid_t pid = thread_create(second_thread_stack, sizeof(second_thread_stack),
                            THREAD_PRIORITY_MAIN - 1, THREAD_CREATE_STACKTEST,
                            second_thread, NULL, "pong");
                            
    pid = thread_create(mtx_thread_stack, sizeof(mtx_thread_stack),
                            THREAD_PRIORITY_MAIN + 2, THREAD_CREATE_STACKTEST,
                            mtx_thread, NULL, "Mtx_test");
    pid = thread_create(mtx2_thread_stack, sizeof(mtx2_thread_stack),
                            THREAD_PRIORITY_MAIN + 2, THREAD_CREATE_STACKTEST,
                            mtx_thread, NULL, "Mtx_test_2");
    pid = thread_create(mtx3_thread_stack, sizeof(mtx3_thread_stack),
                            THREAD_PRIORITY_MAIN -2, THREAD_CREATE_STACKTEST,
                            hog_mtx, NULL, "Mtx_test_3");

    m.content.value = 1;

    while (1) {
        msg_send_receive(&m, &m, pid);
        printf("1st: Got msg with content %u\n", (unsigned int)m.content.value);
    }
}
