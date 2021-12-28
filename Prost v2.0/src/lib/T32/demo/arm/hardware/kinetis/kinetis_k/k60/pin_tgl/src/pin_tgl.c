// For testing latencies if you use two K60 boards in parallel
// Let a GPIO toggle, so that it is easy to see if a CPU is
// running or stopped.

#include <stdarg.h>
#define uint32_t unsigned int
#include "timerk60.h"

extern volatile uint32_t gSimOpt[128];
extern volatile uint32_t gPortE[32];
extern volatile uint32_t gGpioE[32];

void timerInterrupt() __attribute__((interrupt));

volatile unsigned int intCntL,intCntH;

void timerInterrupt()
{
	unsigned int l,h;
	l=intCntL;
	l++;
	if (l>=1000) {
		// just to be able to put a breakpoint here
		// so that we have some running time of the program
		h=intCntH;
		h++;
		intCntH=h;
		l=0;
	}
	intCntL=l;
	TIMER_CLEAR_INT;
}

// adopt via debugger to get longer running time
static volatile unsigned int timerReload=9999;

int main()
{	
	volatile uint32_t h;
	uint32_t v;
	// turn on clocks for various modules, including PortE
	gSimOpt[0xE] = 0xFFFF;

	// Configure PTE26 as GPIO connected on TWR-K60D100M to 
	// CLK_SEL J10, pin 4
	gPortE[26] = 0x100;

	// GPIOE_PDDR (direction) Configure PTE26 as output
	v=0x04000000;
	gGpioE[0x5] = v;

	enableTimer(timerReload);
	for(;;)
	{
		// h++ gives just some small delay
		h++;
		h++;
		h++;
		h++;
		h++;
		h++;
		h++;
		h++;
		gGpioE[0x1]=v;
		// h++ gives just some small delay
		h++;
		h++;
		h++;
		h++;
		h++;
		h++;
		h++;
		h++;
		gGpioE[0x2]=v;
	}
	return 0;
}
