/* @(#) pSOSystem ARM/V2.2.3: apps/pdemo/demo.c  1.5 98/02/19 11:21:00 */
/***********************************************************************/
/*                                                                     */
/*   MODULE:  apps/pdemo/demo.c                                        */
/*   DATE:    98/02/19                                                 */
/*   PURPOSE: A sample application for the host debugger.              */
/*                                                                     */
/*---------------------------------------------------------------------*/
/*                                                                     */
/*           Copyright 1991 - 1997, Integrated Systems, Inc.           */
/*                      ALL RIGHTS RESERVED                            */
/*                                                                     */
/*   Permission is hereby granted to licensees of Integrated Systems,  */
/*   Inc. products to use or abstract this computer program for the    */
/*   sole purpose of implementing a product based on Integrated        */
/*   Systems, Inc. products.   No other rights to reproduce, use,      */
/*   or disseminate this computer program, whether in part or in       */
/*   whole, are granted.                                               */
/*                                                                     */
/*   Integrated Systems, Inc. makes no representation or warranties    */
/*   with respect to the performance of this computer program, and     */
/*   specifically disclaims any responsibility for any damages,        */
/*   special or consequential, connected with the use of this program. */
/*                                                                     */
/*---------------------------------------------------------------------*/
/*                                                                     */
/*   This sample application contains the following tasks:             */
/*                                                                     */
/*   "ROOT":   Starts the other tasks, then deletes itself             */
/*   "MEM1":   Requests memory segments of various sizes               */
/*   "MEM2":   Receives memory segments from "MEM1" and frees them     */
/*   "IO1 ":   Reads a block from the RAM disk                         */
/*   "IO2 ":   Writes a block to the RAM disk                          */
/*   "SRCE":   Sends messages to Queue "SS  "                          */
/*   "SINK":   Consumes messages from Queue "SS  "                     */
/*   "NUMS":   Fills global array with numbers                         */
/*   "CHAR":   Fills global array with characters from A-Z             */
/*   "LOAD":   demo loader task                                        */
/*                                                                     */
/***********************************************************************/
#include "sys_conf.h"
#include <psos.h>
#include <probe.h>
#include <pna.h>
#include <phile.h>
#include <drv_intf.h>
#include <string.h>
#include "demo.h"

/*---------------------------------------------------------------------*/
/* Function Prototypes                                                 */
/*---------------------------------------------------------------------*/
void mem1(void);
void mem2(void);
void source(void);
void sink(void);
void io1(void);
void io2(void);
void numbers(void);
void characters(void);
void process_data(char *);
void print_message(char *);
extern void demoload(void);

/*---------------------------------------------------------------------*/
/* Global variables                                                    */
/*---------------------------------------------------------------------*/
char pbuf[LENGTH + 4];              /* buffer used by 'PTN1' partition */
unsigned short values[NVALUES];     /* array shared by NUMS and CHAR   */

/***********************************************************************/
/*        root: Sets up the evaluation program execution.              */
/*                                                                     */
/*        NOTE: Executes as task 'ROOT'.                               */
/***********************************************************************/
void root(void)
{
unsigned long qidss, qid;
unsigned long iopb[4], ioretval;
unsigned long date, time, ticks;
unsigned long tid[10];
void *data_ptr;
unsigned long rc;
unsigned long ptid, nbufs;
unsigned long smid;
void *seg_ptr;
unsigned long rnid, rsize;

/*---------------------------------------------------------------------*/
/* Set date to May 1, 1995, time to 8:30 AM, and start the system      */
/* clock running.                                                      */
/*---------------------------------------------------------------------*/
date = (1995 << 16) + (5 << 8) + 1;
time = (8 << 16) + (30 << 8);
ticks = 0;
tm_set(date, time, ticks);

#if !SC_AUTOINIT
de_init(DEV_TIMER, iopb, &ioretval, &data_ptr);
de_init(DEV_SERIAL, iopb, &ioretval, &data_ptr);
#endif

/*---------------------------------------------------------------------*/
/* Now initialize the RAM disk driver.  Although this application      */
/* does not use the pHILE+ file system manager, it does read and write */
/* blocks from the "RAM disk" device.  The reading and writing of      */
/* these "disk" blocks is done  by direct calls to de_read() and       */
/* de_write().  Tasks 'IO1 ' and 'IO2 ' make these calls.              */
/*---------------------------------------------------------------------*/
iopb[0] = NUM_BLOCKS;
de_init(DEV_RAMDISK, iopb, &ioretval, &data_ptr);

/*---------------------------------------------------------------------*/
/* Create application tasks and start them.                            */
/*---------------------------------------------------------------------*/
#ifdef i960
t_create("MEM1", 48,  6144,   0, 0, &tid[0]);
t_create("MEM2", 47,  6144,   0, 0, &tid[1]);
t_create("IO1 ", 30,  6144,   0, 0, &tid[2]);
t_create("IO2 ", 30,  6144,   0, 0, &tid[3]);
t_create("SRCE", 128, 6144,   0, 0, &tid[4]);
t_create("SINK", 80,  6144,   0, 0, &tid[5]);
t_create("NUMS", 16,  6144,   0, 0, &tid[6]);
t_create("CHAR", 16,  6144,   0, 0, &tid[7]);
t_create("LOAD", 129, 6144,   0, 0, &tid[8]);
#else
t_create("MEM1", 48,  4096, 512, 0, &tid[0]);
t_create("MEM2", 47,  4096, 512, 0, &tid[1]);
t_create("IO1 ", 30,  4096, 1024, 0, &tid[2]);
t_create("IO2 ", 30,  4096, 1024, 0, &tid[3]);
t_create("SRCE", 128, 4096, 256, 0, &tid[4]);
t_create("SINK", 80,  4096, 256, 0, &tid[5]);
t_create("NUMS", 16,  4096, 256, 0, &tid[6]);
t_create("CHAR", 16,  4096, 256, 0, &tid[7]);
t_create("LOAD", 129, 4096, 256, 0, &tid[8]);
#endif

#ifdef i960
t_start(tid[0], T_PREEMPT | T_NOTSLICE, mem1,    0);
t_start(tid[1], T_PREEMPT | T_NOTSLICE, mem2,    0);
t_start(tid[2], T_PREEMPT | T_TSLICE,   io1,     0);
t_start(tid[3], T_PREEMPT | T_TSLICE,   io2,     0);
t_start(tid[4], T_PREEMPT | T_NOTSLICE, source,  0);
t_start(tid[5], T_PREEMPT | T_TSLICE,   sink,    0);
t_start(tid[6], T_PREEMPT | T_TSLICE,   numbers, 0);
t_start(tid[7], T_PREEMPT | T_TSLICE,   characters, 0);
t_start(tid[8], T_PREEMPT | T_TSLICE,   demoload, 0);
#else
t_start(tid[0], T_USER | T_PREEMPT | T_NOTSLICE, mem1,    0);
t_start(tid[1], T_USER | T_PREEMPT | T_NOTSLICE, mem2,    0);
t_start(tid[2], T_USER | T_PREEMPT | T_TSLICE,   io1,     0);
t_start(tid[3], T_USER | T_PREEMPT | T_TSLICE,   io2,     0);
t_start(tid[4], T_SUPV | T_PREEMPT | T_NOTSLICE, source,  0);
t_start(tid[5], T_SUPV | T_PREEMPT | T_NOTSLICE, sink,    0);
t_start(tid[6], T_USER | T_PREEMPT | T_TSLICE,   numbers, 0);
t_start(tid[7], T_USER | T_PREEMPT | T_TSLICE,   characters, 0);
t_start(tid[8], T_USER | T_PREEMPT | T_TSLICE,   demoload, 0);
#endif

/*---------------------------------------------------------------------*/
/* Create the queue which will be used by SOURCE and SINK.  Also,      */
/* create the partition that will be used by IO1 and IO2 and the       */
/* semaphore used by NUMS and CHAR.                                    */
/*---------------------------------------------------------------------*/
rc = q_create("SS  ", 8, Q_PRIOR | Q_LIMIT, &qidss);
if (rc != NOERR)
    k_fatal(0, 0);

rc = pt_create("PTN1", (void *) (((unsigned long) pbuf + 4) & 0xFFFFFFFC),
           (void  *) 0, LENGTH, BLOCK_SIZE, PT_NODEL, &ptid, &nbufs);
if (rc != NOERR)
    k_fatal(0, 0);

rc = sm_create("SEM1", 1, SM_FIFO, &smid);
if (rc != NOERR)
    k_fatal(0, 0);

/*---------------------------------------------------------------------*/
/* Create the message queue that MEM1 & MEM2 will use for              */
/* communication.                                                      */
/*---------------------------------------------------------------------*/
q_create("QMEM", 0, Q_FIFO  | Q_NOLIMIT | Q_SYSBUF, &qid);

/*---------------------------------------------------------------------*/
/* Obtain a chunk of memory from region 0, and "subdivide" it by       */
/* creating a new memory region with it.  Note that we get four bytes  */
/* more than we need so that we can insure alignment on a longword     */
/* boundary, which pSOS+ requires when creating a memory region.       */
/*---------------------------------------------------------------------*/
rn_getseg(0, RNSIZE + 4, RN_NOWAIT, 0, &seg_ptr);
seg_ptr = (void *)((unsigned long)((char *)seg_ptr + 3) & ~3);
rn_create("RMEM", seg_ptr, RNSIZE, 128, 0, &rnid, &rsize);


/*---------------------------------------------------------------------*/
/* Delete self. If deletion fails, call k_fatal.                       */
/*---------------------------------------------------------------------*/
rc = t_delete(0);
if (rc != NOERR)
   k_fatal(0,0);
}

/***********************************************************************/
/*        mem1: Obtains memory segments and sends their addresses to   */
/*              'MEM2' via message queue 'QMEM'.                       */
/*                                                                     */
/*        NOTE: Executes as task 'MEM1'.                               */
/***********************************************************************/
void mem1(void)
{
unsigned long size, rc, qid, rnid;
unsigned long date, time, ticks;
MEMMSG *current_msg;
MEMMSG msgarray[MAX_MSG];
void *seg_ptr;
static int i;
unsigned long ntimes = 0;

i = 0;    /* initialize i */
/*---------------------------------------------------------------------*/
/* Create a circular linked list to store messages.                    */
/*---------------------------------------------------------------------*/
while (i < MAX_MSG - 1)
    {
    msgarray[i].next = &msgarray[i+1];
    i++;
    }
msgarray[MAX_MSG-1].next = &msgarray[0];

current_msg = msgarray;

for (;;)
    {
    rc = q_ident("QMEM", 0, &qid);
    if (rc == NOERR) break;
    tm_wkafter(5);
    }

for (;;)
    {
    rn_ident("RMEM", &rnid);
    if (rc == NOERR) break;
    tm_wkafter(5);
    }

for (;;)
    {
    ntimes++;    /* number of times in this loop */

    /*-----------------------------------------------------------------*/
    /* Request memory segments.  For each segment, send a message to   */
    /* queue 'QMEM' which contains its address, size, and region.  If  */
    /* a segment cannot be allocated, wait for 5 ticks.                */
    /*-----------------------------------------------------------------*/
    tm_get(&date, &time, &ticks);
    ticks = (ticks & 7) + 1;          /* Random number from 1 to 8  */
    size = ticks * 128;               /* Sizes from 128 to 1K bytes */
    rc = rn_getseg(rnid, size, RN_NOWAIT, 0, &seg_ptr);
    if (rc != NOERR)
        tm_wkafter(5);                /* Ran out of memory.  Sleep. */
    else
        {
        /*------------------------------------------------------------*/
        /* Load the current message with the information and send it  */
        /* to the queue. Move on to the next message.                 */
        /*------------------------------------------------------------*/
        current_msg->address = (unsigned long)seg_ptr;
        current_msg->size = size;
        current_msg->unused[0] = ntimes;
        current_msg->unused[1] = 0;

        q_send(qid, (unsigned long *)current_msg);

        current_msg = current_msg->next;
        }
    }
}

/***********************************************************************/
/*        mem2: Grabs segments from 'MEM1' and frees them.             */
/*                                                                     */
/*        NOTE: Executes as task 'MEM2'.  Zeros each segment before    */
/*              freeing it to simulate use of the segment.             */
/***********************************************************************/
void mem2(void)
{
unsigned long qid, rnid;
MEMMSG message;
unsigned char *mem_ptr;
unsigned long seg_size, rc;

for (;;)
    {
    rc = q_ident("QMEM", 0, &qid);
    if (rc == NOERR) break;
    tm_wkafter(5);
    }

for (;;)
    {
    rn_ident("RMEM", &rnid);
    if (rc == NOERR) break;
    tm_wkafter(5);
    }

for (;;)
    {
    rc = q_receive(qid, Q_WAIT, 0, (unsigned long *) &message);
    if (rc == NOERR)
        {
        mem_ptr = (unsigned char *) (message.address);
        seg_size = message.size;
        while (message.size--)
            *mem_ptr++ = 0;
        rn_retseg(rnid, (void *)(message.address)); /* Return seg back to RMEM */
        }
    else
        tm_wkafter(5);
    }
}

/***********************************************************************/
/*      source: Sends messages to queue 'SS  '.                        */
/*                                                                     */
/*        NOTE: This code executes as task 'SRCE' and sends messages   */
/*              to queue 'SS  '.  If the queue becomes full, the task  */
/*              suspends itself.                                       */
/***********************************************************************/
void source(void)
{
unsigned long qid, rc;
unsigned long msg[MSGLEN];
unsigned long msgid;

q_ident("SS  ", 0, &qid);         /* Get the queue ID */
msgid = 0;

for (;;)
    {
    msg[0] = msgid++ & 0xFFFF;    /* first 2 bytes of message are zero; */
                                  /* next 2 bytes contain message ID.   */
    rc = q_send(qid, msg);
    if (rc != NOERR)              /* If queue full or if no more */
        t_suspend(0L);            /* buffers, give up. */
    }
}

/***********************************************************************/
/*        sink: Take messages from queue 'SS  '                        */
/*                                                                     */
/*        NOTE: This code executes as task 'SINK'.  It repeatedly re-  */
/*              quests messages from queue 'SS  '.  When none are      */
/*              available, it resumes 'SRCE', then pauses for a while. */
/***********************************************************************/
void sink(void)
{
unsigned long qidss, tidsrce, rc;
unsigned long date, time, ticks;
unsigned long msg[MSGLEN];

q_ident("SS  ", 0, &qidss);
t_ident("SRCE", 0, &tidsrce);

for (;;)
    {
    rc = q_receive(qidss, Q_NOWAIT, 0, msg);
    if (rc == ERR_NOMSG)
        {
        t_resume(tidsrce);              /* No more messages at   */
        tm_get(&date, &time, &ticks);   /* the queue.  Resume    */
        ticks = ticks & 0xF;            /* SRCE and sleep for a  */
        tm_wkafter(ticks);              /* random amount of time.*/
        }
    else if (rc == NOERR)
        {
        if ((msg[0] & 0xFF000000) != 0)      /* Print the message if the */
            print_message((char *)msg);      /* first byte is non-zero.  */
        }
    else if (rc == ERR_OBJID)
        tm_wkafter(5);
    }
}

/***********************************************************************/
/*         io1: Repeatedly read from the "RAM disk" device.            */
/*                                                                     */
/*        NOTE: This code runs as task 'IO1 ' and competes with task   */
/*              'IO2 ' for access to the "RAM disk" device.            */
/***********************************************************************/
void io1(void)
{
unsigned long ioretval;             /* I/O device return value */
struct buffer_header iopb;          /* I/O parameter block */
unsigned long ptid;
unsigned long rc;
char *bufaddr;

rc = pt_ident("PTN1", 0, &ptid);
if (rc != NOERR)
   t_suspend(0);

for (;;)
    {
    iopb.b_blockno = 0;             /* read from block 0 */
    iopb.b_bcount = 1;              /* read 1 block */

    do {
       rc = pt_getbuf(ptid, (void **) &bufaddr);
       if (rc == NOERR)
           {
           iopb.b_bufptr = bufaddr;        /* addr of data block */
           process_data(bufaddr);          /* simulate processing data */

           de_read(DEV_RAMDISK, &iopb, &ioretval);
           }
       else
           {
           tm_wkafter(5);
           }
       } while (rc != NOERR);

    rc = pt_retbuf(ptid, bufaddr);
    }
}

/***********************************************************************/
/*         io2: Repeatedly write to the "RAM disk" device.             */
/*                                                                     */
/*                                                                     */
/*        NOTE: This code runs as task 'IO2 ' and competes with task   */
/*              'IO1 ' for access to the "RAM disk" device.            */
/***********************************************************************/
void io2(void)
{
unsigned long ioretval;             /* I/O device return value */
struct buffer_header iopb;          /* I/O parameter block */
unsigned long ptid;
unsigned long rc;
char *bufaddr;

rc = pt_ident("PTN1", 0, &ptid);
if (rc != NOERR)
    t_suspend(0);

for (;;)
    {
    iopb.b_blockno = 0;             /* write to block 0 */
    iopb.b_bcount = 1;              /* write 1 block */

    do {
       rc = pt_getbuf(ptid, (void **) &bufaddr);
       if (rc == NOERR)
           {
           iopb.b_bufptr = bufaddr;  /* addr of data block */
           process_data(bufaddr);    /* simulate processing data */

           de_write(DEV_RAMDISK, &iopb, &ioretval);
           rc = pt_retbuf(ptid, bufaddr);
           }
       else
           {
           tm_wkafter(5);            /* sleep and try again for buffer */
           }
       } while (rc != NOERR);
    }
}

/***********************************************************************/
/*     numbers: Access a global array and fill it with numbers.        */
/*                                                                     */
/*        NOTE: Runs as task 'NUMS'.                                   */
/***********************************************************************/
void numbers(void)
{
unsigned long rc;
unsigned long smid;
unsigned long timeout = 0;
unsigned short count;

rc = sm_ident("SEM1", 0, &smid);
if (rc != NOERR)
    t_suspend(0);

while (1)
    {
    /*------------------------------------------------------------------*/
    /* Get the semaphore token, waiting forever. When token is          */
    /* obtained, access the global array and fill it with all numbers.  */
    /* Then, release the semaphore token so CHAR can access the array.  */
    /*------------------------------------------------------------------*/

    rc = sm_p(smid, SM_WAIT, timeout);
    if (rc == NOERR)
        {
        for (count = 0; count < NVALUES; count++)
            values[count] = count;

        sm_v(smid);
        }

    /* sleep for 2 ticks before attempting to access semaphore again */
    tm_wkafter(2);

    }

}

/***********************************************************************/
/*     characters:  Access a global array and fill it with characters. */
/*                                                                     */
/*        NOTE: Runs as task 'CHAR'.                                   */
/***********************************************************************/
void characters(void)
{
unsigned long rc;
unsigned long smid;
unsigned long timeout = 0;
unsigned short count;
char newchar;

rc = sm_ident("SEM1", 0, &smid);
if (rc != NOERR)
   t_suspend(0);

while (1)
    {
    /*------------------------------------------------------------------*/
    /* Get the semaphore token, waiting forever. When token             */
    /* is obtained, access the global array and fill it with characters */
    /* from A-Z. Then, release the semaphore token so NUMS can access   */
    /* the array.                                                       */
    /*------------------------------------------------------------------*/

    rc = sm_p(smid, SM_WAIT, timeout);
    if (rc == NOERR)
        {
        newchar = 'A';
        count = 0;
        while (count < NVALUES)
            {
            values[count++] = newchar++;
            if (newchar == (char) ('Z' + 1))
                newchar = 'A';
            }

        sm_v(smid);
        }

    }

}

/***********************************************************************/
/*     print_message:  Print a specified message as ASCII characters.  */
/*                                                                     */
/*        NOTE: Called by 'SINK'                                       */
/***********************************************************************/
void print_message(char *inbuf)
{
int i;
char outbuf[(MSGLEN * 4) + 2];

for (i = 0; i < (MSGLEN * 4); i++)
    {
    /*-----------------------------------------------------------------*/
    /* Copy each printable character in the input buffer to the output */
    /* buffer. If a character is not printable, set the corresponding  */
    /* character in the output buffer to a period.                     */
    /*-----------------------------------------------------------------*/

    if ((inbuf[i] >= ' ') && (inbuf[i] <= '~'))
        outbuf[i] = inbuf[i];
    else
        outbuf[i] = '.';
    }
outbuf[i++] = '\n';                  /* append a newline and      */
outbuf[i] = '\0';                    /* null-terminate the buffer */

db_output(outbuf, strlen(outbuf));   /* print the output buffer   */
}
