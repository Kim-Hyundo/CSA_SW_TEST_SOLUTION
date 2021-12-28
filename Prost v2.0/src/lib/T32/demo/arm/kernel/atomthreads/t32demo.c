
#include "atom.h"
#include "atommutex.h"
#include "atomtests.h"
#include "atomsem.h"
#include "atomqueue.h"
#include "atomtimer.h"



/* Test queue size */
#define QUEUE_ENTRIES       16


/* Test OS objects */
static ATOM_QUEUE queue1;
static uint8_t queue1_storage[QUEUE_ENTRIES];

uint8_t	NumTimer = 0;


/* Number of test threads */
#define NUM_TEST_THREADS      6


/* Test OS objects */
static ATOM_SEM 				sem1, sem2;
static ATOM_MUTEX 			mutex1;
static ATOM_TCB 				tcb								[NUM_TEST_THREADS];
static uint8_t 					test_thread_stack	[NUM_TEST_THREADS][TEST_THREAD_STACK_SIZE];
static uint8_t 					tt_stack					[TEST_THREAD_STACK_SIZE+256];


/* Test global data (one per thread) */
static uint32_t volatile last_time;
static int volatile last_thread_id;
static volatile int switch_cnt;
static uint32_t volatile failure_cnt[4];
static int volatile test_started;


/* Forward declarations */
static void test_thread_func  (uint32_t param);
static void sem_func1         (uint32_t param);
static void sem_func2         (uint32_t param);
static void low_prio_func     (uint32_t param);
static void q_thread_func     (uint32_t param);
static void timer_func        (uint32_t param);
static void testCallback      (void  *cb_data);



uint32_t test_start (void)
{
		atomMutexCreate (&mutex1);
		
		if (atomSemCreate (&sem1, 0) != ATOM_OK)
			while(1);
		if (atomSemCreate (&sem2, 0) != ATOM_OK)
			while(1);
			
	  atomQueueCreate (&queue1, &queue1_storage[0], sizeof(uint8_t), QUEUE_ENTRIES);

    /* 
     * Create all four threads at the same priority as each other.
     * They are given a lower priority than this thread, however,
     * to ensure that once this thread wakes up to stop the test it
     * can do so without confusing the scheduling tests by having
     * a spell in which this thread was run.
     */
    atomThreadCreate (&tcb[0], TEST_THREAD_PRIO + 1, test_thread_func, 0,
            //&test_thread_stack[0][0],
            &tt_stack,
            TEST_THREAD_STACK_SIZE+256, TRUE);
    atomThreadCreate (&tcb[1], TEST_THREAD_PRIO + 5, sem_func1, 1,
            &test_thread_stack[1][0],
            TEST_THREAD_STACK_SIZE, TRUE);
    atomThreadCreate (&tcb[2], TEST_THREAD_PRIO + 1, sem_func2, 2,
            &test_thread_stack[2][0],
            TEST_THREAD_STACK_SIZE, TRUE);

    atomThreadCreate (&tcb[3], TEST_THREAD_PRIO -1 , q_thread_func, 3,
            &test_thread_stack[3][0],
            TEST_THREAD_STACK_SIZE, TRUE);

    atomThreadCreate (&tcb[4], TEST_THREAD_PRIO + 1, low_prio_func, 4,
            &test_thread_stack[4][0],
            TEST_THREAD_STACK_SIZE, TRUE);
            
    atomThreadCreate (&tcb[5], TEST_THREAD_PRIO - 1, timer_func, 5,
            &test_thread_stack[5][0],
            TEST_THREAD_STACK_SIZE, TRUE);
    
    // Sleep forever;
    while(1)
    {
    	atomTimerDelay (10 * SYSTEM_TICKS_PER_SEC);
    }

}



// Timer callback function

static void testCallback(void  *cb_data)
{
	atomSemPut(&sem2);
}


// Wake up every 50 ticks
static void timer_func(uint32_t param)
{
	static ATOM_TIMER timer_cb;
	
	timer_cb.cb_func = testCallback;
  timer_cb.cb_data = NULL;
  timer_cb.cb_ticks = 50;
  atomTimerRegister (&timer_cb);
	
	while(1)
	{
		atomSemGet(&sem2, 0);
		
		
		//Increment the number of times the timer has fired
		NumTimer++;
		if(NumTimer > 254)
			NumTimer = 0;
		
		// Re-start the timer
		timer_cb.cb_func = testCallback;
  	timer_cb.cb_data = NULL;
  	timer_cb.cb_ticks = 50;
  	atomTimerRegister (&timer_cb);
  }//while
}


static void q_thread_func(uint32_t param)
{
	uint8_t msg, status;
	
	while(1)
	{
		// Should wait forever as nothing will send to this queue
		status = atomQueueGet(&queue1, 0, &msg);
		if(status == 0)
			;
	}
	
}


static void sem_func1 (uint32_t param)
{
	
	while(1)
	{
		atomSemGet(&sem1, 0);	//Acquire semaphore - infinite wait
		atomTimerDelay(500);	//wait 500 ticks
		atomSemPut(&sem1);		//Release semaphore
		atomTimerDelay(500);	//wait 500 ticks
	}
}



static void sem_func2 (uint32_t param)
{
	
	while(1)
	{
		atomSemGet(&sem1, 0);	//Acquire semaphore - infinite wait
		atomTimerDelay(500);	//wait 500 ticks
		atomSemPut(&sem1);		//Release semaphore
		atomTimerDelay(500);	//wait 500 ticks
	}
}

/**
 * \b test_thread_func
 *
 * Entry point for test thread.
 *
 * @param[in] param Thread ID (0 to 3)
 *
 * @return None
 */
static void test_thread_func (uint32_t param)
{
    int thread_id;
    int status, i, j;


    /* Pull out thread ID */
    thread_id = (int)param;
    i = thread_id;

    /* Run forever */
    while (1)
    {
      status = atomMutexGet(&mutex1, 0);
      if(status == 0)
      	;
    	
    	for(i=0;i < 1000; i++)
    		j = i*2;
    		
    	atomMutexPut(&mutex1);
    	
    	i = j;	//Keep the compiler happy
    	
    	for(i=0;i < 1000; i++)
    		j = i*2;
    }//while
}


static void low_prio_func(uint32_t param)
{
	// Very low priority thread that will try to acquire the mutex
	// but will essentially just block forever as it won't get it
	// Used to check if we can display blocked threads on a mutex.
	int i, j, status;
	
	while(1)
	{
    status = atomMutexGet(&mutex1, 0);
    if(status ==0)
    	;
    	
    for(i=0;i < 1000; i++)
    	j = i*2;
    		
    atomMutexPut(&mutex1);
    
    i = j;
  }
}
