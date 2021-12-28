void WatchdogInitEarly() __attribute__ ((naked));
void WatchdogTrigger();

void WatchdogInitEarly()
{
	// please use only inline assembly here
	// intenionally left empty
	__asm__ volatile ("bx r14");
}

void WatchdogInit()
{
	unsigned long* pWDT_MR = (unsigned long*)0x400E1854;
	*pWDT_MR |= 0x8000;
	if (!(*pWDT_MR&0x8000)) {
		// Error: Cannot disable Watchdog
		asm("bkpt #0");
	}
}

void WatchdogTrigger()
{
	// intenionally left empty
}
