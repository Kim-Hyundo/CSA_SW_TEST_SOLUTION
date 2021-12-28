#include <stdint.h>

void WatchdogInit()
{
	// intenionally left empty
}

void WatchdogTrigger()
{
	*((volatile uint32_t*)0xFFD0200C) = 0x76;
}
