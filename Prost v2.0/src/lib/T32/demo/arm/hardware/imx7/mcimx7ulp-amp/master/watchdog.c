void WatchdogInitEarly() __attribute__ ((naked));
void WatchdogTrigger();

void WatchdogInitEarly()
{
	// please use only inline assembly here
	__asm__ volatile ("strh %1,[%0]; strh %2,[%0]; bx r14" : : "r" (0x41025004), 
"r" (0xa602), "r" (0xb480));
}

void WatchdogInit()
{
	 WatchdogInitEarly();
}

void WatchdogTrigger()
{
	 WatchdogInitEarly();
}
