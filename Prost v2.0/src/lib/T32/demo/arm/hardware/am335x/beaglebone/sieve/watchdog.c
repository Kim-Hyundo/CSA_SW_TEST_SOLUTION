void WatchdogInit()
{
	// write magic1&magic2 to WDT_WSPR
	*((unsigned long*)0x44E35048) = 0xAAAA;
	*((unsigned long*)0x44E35048) = 0x5555;
}

void WatchdogTrigger()
{
	// intenionally left empty
}
