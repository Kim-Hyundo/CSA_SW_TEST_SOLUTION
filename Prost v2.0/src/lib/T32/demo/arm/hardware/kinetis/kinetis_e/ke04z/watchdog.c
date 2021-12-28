void WatchdogInitEarly() __attribute__ ((naked));
void WatchdogTrigger();

void WatchdogInitEarly()
{
	// please use only inline assembly here
	//
	// The watchdog has a restrictive timing. It has to be configured and unlocked within a peripod
	// of 20+256 cycles. Therefore the unlock sequence need to be done by a small target program.
	asm volatile ("strb %[control2], [%[base], #1]; \
	               strh %[counter1], [%[base], #2]; \
	               strh %[counter2], [%[base], #2]; \
	               strh %[timeout],  [%[base], #4]; \
	               strh %[control1], [%[base], #0]; \
	               bx r14" : :                      \
	               [base]     "r" (0x40052000),     \
	               [control2] "r" (0x0),            \
	               [control1] "r" (0x20),           \
	               [counter1] "r" (0x20C5),         \
	               [counter2] "r" (0x28D9),         \
	               [timeout]  "r" (0xFFFF)
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
