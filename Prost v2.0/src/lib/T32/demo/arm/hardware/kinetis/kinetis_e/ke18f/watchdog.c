void WatchdogInitEarly() __attribute__ ((naked));
void WatchdogTrigger();

void WatchdogInitEarly()
{
	// please use only inline assembly here
	//
	// The watchdog has a restrictive timing. It has to be configured and unlocked within a peripod
	// of 20+256 cycles. Therefore the unlock sequence need to be done by a small target program.
	asm volatile ("str %[key], [%[base], #4]; str %[ffff], [%[base], #8]; ldr %[key], [%[base], #0]; bic %[key], %[disable]; str %[key], [%[base], #0]; bx r14" : : [base] "r" (0x40052000), [key] "r" (0xD928C520), [ffff] "r" (0xffff), [disable] "r" (0x80));
}

void WatchdogInit()
{
	// intenionally left empty
}

void WatchdogTrigger()
{
	// intenionally left empty
}
