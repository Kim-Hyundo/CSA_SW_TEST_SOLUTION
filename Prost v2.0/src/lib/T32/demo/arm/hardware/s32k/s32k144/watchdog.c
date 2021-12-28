void WatchdogInitEarly() __attribute__ ((naked));
void WatchdogTrigger();

void WatchdogInitEarly()
{
	// please use only inline assembly here
	// The watchdog has a restrictive timing. It has to be configured and unlocked within a peripod
	// of 128 cycles. Therefor the unlock sequence need to be done by a small target program.
	// SD:0x40052004 = 0xD928C520   (Key)
	// SD:0x40052000 = 0x00002120   (Control register)
	// SD:0x40052008 = 0x0000FFFF   (Timeout value)
	__asm__ volatile ("str %[key],[%[wdog_base],0x4]; str %[cs_val],[%[wdog_base],0x0]; str %[toval_val],[%[wdog_base],0x8]; bx r14" ::[key] "r" (0xD928C520), [cs_val] "r" (0x00002120), [toval_val] "r" (0xffff), [wdog_base] "r" (0x40052000));
}

void WatchdogInit()
{
	// intenionally left empty
}

void WatchdogTrigger()
{
	// intenionally left empty
}
