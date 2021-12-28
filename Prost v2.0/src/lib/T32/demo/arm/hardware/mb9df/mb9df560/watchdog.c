
void WatchdogInitEarly() __attribute__ ((naked));
void WatchdogTrigger();

void WatchdogInitEarly()
{
	// please use only inline assembly here
	asm volatile ("str  %0,[%1]; str  %0,[%2]; bx r14" : : "r" (0x0), "r" (0xb060c010), "r" (0xb060c018));
}

void WatchdogInit()
{
	// cannot be disabled, just trigger here
	WatchdogInitEarly();
}

void WatchdogTrigger()
{
	WatchdogInitEarly();
}
