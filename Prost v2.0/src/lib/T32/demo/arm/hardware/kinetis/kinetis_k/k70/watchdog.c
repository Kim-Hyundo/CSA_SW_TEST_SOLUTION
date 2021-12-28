void WatchdogInitEarly() __attribute__ ((naked));
void WatchdogTrigger();

void WatchdogInitEarly()
{
	// please use only inline assembly here
	//
	// The watchdog has a restrictive timing. It has to be configured and unlocked within a peripod
	// of 20+256 cycles. Therefor the unlock sequence need to be done by a small target program.
	// SD:0x4005200E = 0xC520   (Key 1)
	// SD:0x4005200E = 0xD928   (Key 2)
	// SD:0x40052000 = 0x0000   (Config register)
	asm volatile ("strh %2,[%0]; strh %3,[%0]; strh %4,[%1]; bx r14" : : "r" (0x4005200E), "r" (0x40052000), "r" (0xC520), "r" (0xD928), "r" (0x0000));

}

void WatchdogInit()
{
	// intenionally left empty
}

void WatchdogTrigger()
{
	// intenionally left empty
}
