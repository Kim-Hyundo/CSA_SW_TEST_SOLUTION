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
 * @brief       TRACE32 message demo application
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


char c1_thread_stack[512];
char c2_thread_stack[512];
char c3_thread_stack[512];
char s1_thread_stack[512];

msg_t mq1[NUM_MSG];
msg_t mq2[NUM_2_MSG];

kernel_pid_t svr_pid;

rmutex_t rmtx1, rmtx2;

char rbbuf[1024];
ringbuffer_t rb1;

///////////////////////////////////////////////////////////
// mtx_thread
//
// Grab a mutex for a while and then release it 
void *client_thread(void *arg)
{
    msg_t m_snd, m_rep;
    
	(void) arg;
    
    m_snd.content.value = 0;
    m_snd.type = 1;

	while(1)
	{
        //msg_send(&m_snd,svr_pid);
        //m_snd.type = 1;
        msg_send_receive(&m_snd, &m_rep, svr_pid);
        m_snd.content.value = m_rep.content.value;
	}
}

void *TaskServer(void *arg)
{

    msg_t m_rcv, m_rep;
    int i;
    char val[6];
    
    (void) arg;
    (void) val;
    
    for(i=0;i<5;i++)
        val[i] = ringbuffer_get_one(&rb1);
    
    rmutex_lock(&rmtx1);
    
    while(1)
    {
        msg_receive(&m_rcv);
        switch (m_rcv.type)
        {
            case 1:
                m_rep.content.value = m_rcv.content.value + 1;
                msg_reply(&m_rcv,&m_rep);
                break;
            default:
                i = m_rcv.content.value;
                (void) i;
                break;
        }
        
    }
}
    


int main(void)
{
    kernel_pid_t pid;
    msg_t t_msg[5];
    xtimer_t tim[5];
    int i;
    
    
    xtimer_init();
    
    // Create and initialise some rmutexes
    //RMUTEX_INIT rmtx1;
    rmutex_init(&rmtx1);
    rmutex_init(&rmtx2);
    
    //Initialise a ringbuffer
    ringbuffer_init(&rb1, rbbuf, sizeof(rbbuf));
    for(i= 65; i<(65+26);i++)
    {
        ringbuffer_add_one(&rb1,(char)(i));
    }
    
    
    // Create Server Task - lower than clients to get a queue 
    // full of messages to debug
    svr_pid = thread_create(s1_thread_stack, 
                            sizeof(s1_thread_stack),
                            THREAD_PRIORITY_MAIN + 4, 
                            THREAD_CREATE_STACKTEST,
                            TaskServer, 
                            NULL, 
                            "Server");
    
    //Create client tasks
    pid = thread_create(c1_thread_stack,
                            sizeof(c1_thread_stack),
                            THREAD_PRIORITY_MAIN + 3, 
                            THREAD_CREATE_STACKTEST,
                            client_thread, 
                            NULL, 
                            "Client1");
    pid = thread_create(c2_thread_stack, 
                            sizeof(c2_thread_stack),
                            THREAD_PRIORITY_MAIN + 3, 
                            THREAD_CREATE_STACKTEST,
                            client_thread, 
                            NULL, 
                            "Client2");
    pid = thread_create(c3_thread_stack, 
                            sizeof(c3_thread_stack),
                            THREAD_PRIORITY_MAIN + 3, 
                            THREAD_CREATE_STACKTEST,
                            client_thread, 
                            NULL, 
                            "Client3");
    pid = pid;
    
    // Queue up some messages to be sent in future to svr_pid
    for(i = 0; i< 5; i++)
    {
        tim[i].target      = 0;
        tim[i].long_target = 0;
        t_msg[i].type = 3;
        t_msg[i].content.value = i * 5;
        xtimer_set_msg(&tim[i], 2000 + (i * 2000), &t_msg[i], svr_pid);
    }//for
    

    while (1) {
        thread_sleep();
        
    }
}
