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
  *((unsigned long*)0x40011C00) = 0x1ACCE551;
  *((unsigned long*)0x40011C00) = 0xE5331AAE;
  *((unsigned char*)0x40011008) = 0x0;
}

void WatchdogTrigger()
{
	// intenionally left empty
}
