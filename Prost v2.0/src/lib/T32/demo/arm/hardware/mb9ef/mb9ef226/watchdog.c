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
	if ((*((unsigned int*)0xB0608048)&0x01000000)==0x0) {
		*((unsigned int*)0xB0608000) = 0xEDACCE55;
		*((unsigned int*)0xB0608048) = 0x01000000;
	}
}

void WatchdogTrigger()
{
	*((unsigned int*)0xB0608010) = *((unsigned int*)0xB060802c);
	*((unsigned int*)0xB0608018) = *((unsigned int*)0xB0608030);
}
