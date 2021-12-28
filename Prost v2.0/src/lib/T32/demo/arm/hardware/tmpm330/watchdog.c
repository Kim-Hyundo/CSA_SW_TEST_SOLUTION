void WatchdogInitEarly() __attribute__ ((naked));
void WatchdogTrigger();

void WatchdogInitEarly()
{
	// please use only inline assembly here
	// intenionally left empty
	// SD:0x40040000 = 0x00000001   (Disabling timer)
	// SD:0x40040004 = 0x000000B1   (Write key)
	asm volatile ("strh %1,[%0]; strh %3,[%2]; bx r14" : : "r" (0x40040000), "r" (0x00000001), "r" (0x40040004), "r" (0x000000B1));
}

void WatchdogInit()
{
	// intenionally left empty
}

void WatchdogTrigger()
{
	// intenionally left empty
}
