void WatchdogInitEarly() __attribute__ ((naked));
void WatchdogTrigger();

void WatchdogInitEarly()
{
	// please use only inline assembly here
	asm volatile (
		"str %1, [%0]\n"
		"bx r14\n"
	: : "r" (0x40076000), "r" (0x0));
}

void WatchdogInit()
{
	// intenionally left empty
}

void WatchdogTrigger()
{
	// intenionally left empty
}
