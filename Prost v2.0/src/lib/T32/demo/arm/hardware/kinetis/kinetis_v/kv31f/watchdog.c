void WatchdogInitEarly() __attribute__ ((naked));
void WatchdogTrigger();

void WatchdogInitEarly()
{
	// please use only inline assembly here
	//
	// The watchdog has a restrictive timing. It has to be configured and unlocked within a peripod
	// of 20+256 cycles. Therefore the unlock sequence need to be done by a small target program.
	asm volatile (
		"strh %[key1],   [%[base], #0xE]\n"
		"strh %[key2],   [%[base], #0xE]\n"
		"strh %[disable],[%[base]]\n"
		"bx r14\n" 
		: : [base] "r" (0x40052000), [key1] "r" (0x0000C520), [key2] "r" (0x0000D928), [disable] "r" (0x0000)
	);
}

void WatchdogInit()
{
	// intenionally left empty
}

void WatchdogTrigger()
{
	// intenionally left empty
}
