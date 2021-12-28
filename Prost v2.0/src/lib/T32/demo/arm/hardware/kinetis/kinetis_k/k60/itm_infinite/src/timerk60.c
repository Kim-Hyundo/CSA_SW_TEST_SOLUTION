#define SIM_SCGC6   (*((volatile unsigned int *)(0x4004803C)))
#define PIT_MCR     (*((volatile unsigned int *)(0x40037000)))
#define PIT_LDVAL0  (*((volatile unsigned int *)(0x40037100)))
#define PIT_TCTRL0  (*((volatile unsigned int *)(0x40037108)))

#define INT_SET_ENABLE(_x_)   *(((volatile unsigned int *)(0xE000E100))+((_x_)>>5)) = 1<<((_x_)&0x1F)
#define INT_CLEAR_ENABLE(_x_) *(((volatile unsigned int *)(0xE000E180))+((_x_)>>5)) = 1<<((_x_)&0x1F)


void enableTimer(unsigned int reload)
{
	unsigned int r1;
	/* Enable clock for PIT */
	r1 = SIM_SCGC6;
	r1 |= 0x00800000;
	SIM_SCGC6 = r1; 
	
	/* Enable PIT module */
	PIT_MCR = 0x0;
	
	/* Reload value for PIT Timer 0 */
	PIT_LDVAL0 = reload;
	
	/* Enable interrupt on update */
	PIT_TCTRL0 = 0x2;
	
	/* Enable PIT IRQ 68 */
	INT_SET_ENABLE(68);

	/* Now start timer */
	PIT_TCTRL0 = 0x3;
}

void disableTimer()
{
	INT_CLEAR_ENABLE(68);
	PIT_TCTRL0 = 0;
}
