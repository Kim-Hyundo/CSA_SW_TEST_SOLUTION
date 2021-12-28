void WatchdogInitEarly() __attribute__ ((naked));
void WatchdogTrigger();

void WatchdogInitEarly()
{
	// please use only inline assembly here
	// intenionally left empty
	__asm__ volatile ("str %1,[%0]; bx r14" : : "r" (0x00002200), "r" (0xA2050000));
}

void WatchdogInit()
{
	// intenionally left empty
}

void WatchdogTrigger()
{
	// intenionally left empty
}
