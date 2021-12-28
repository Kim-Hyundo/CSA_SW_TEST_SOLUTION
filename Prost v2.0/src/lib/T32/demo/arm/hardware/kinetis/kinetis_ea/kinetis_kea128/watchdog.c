void WatchdogInitEarly() __attribute__ ((naked));
void WatchdogTrigger();

void WatchdogInitEarly()
{
	// please use only inline assembly here
	// intenionally left empty
}

void WatchdogInit()
{
	asm volatile (
		"strb %5, [%0, #1]\n"
		"strh %1, [%0, #2]\n"
		"strh %2, [%0, #2]\n"
		"strh %3, [%0, #4]\n"
		"strh %4, [%0, #0]\n"
	: : "r" (0x40052000), "r" (0x20c5), "r" (0x28D9), "r" (0xFFFF), "r" (0x20), "r" (0x0));
}

void WatchdogTrigger()
{
	// intenionally left empty
}
