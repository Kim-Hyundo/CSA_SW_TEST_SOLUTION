
/* 
   super funny, to re-enable the interrupt you have to
   read from one of the timer registers after resetting the TimerInterruptFlag.
*/
#define TIMER_CLEAR_INT do { \
	unsigned int value; \
	*((volatile unsigned int *)0x4003710C) = 0x1; \
	value = *((volatile unsigned int *)0x40037100); \
} while (0)


extern void enableTimer(unsigned int reload);
extern void disableTimer();