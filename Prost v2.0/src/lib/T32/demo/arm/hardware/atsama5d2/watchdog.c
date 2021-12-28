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
	// WDT_MR - set WDDIS
	*((unsigned int*)0xF8048044) |= 0x8000;
}

void WatchdogTrigger()
{
	// intenionally left empty
}
