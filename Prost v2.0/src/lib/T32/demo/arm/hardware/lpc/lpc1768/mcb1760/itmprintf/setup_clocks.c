
#define CCLKCFG      (*((volatile unsigned int *)(0x400FC104)))
#define CLKSRCSEL    (*((volatile unsigned int *)(0x400FC10C)))
#define PLL0CFG      (*((volatile unsigned int *)(0x400FC084)))
#define PLL0CON      (*((volatile unsigned int *)(0x400FC080)))
#define PLL0FEED     (*((volatile unsigned int *)(0x400FC08C)))
#define USBCLKCFG    (*((volatile unsigned int *)(0x400FC108)))
#define PCLKSEL0     (*((volatile unsigned int *)(0x400FC1A8)))
#define PCLKSEL1     (*((volatile unsigned int *)(0x400FC1A8)))
#define PCONP        (*((volatile unsigned int *)(0x400FC0C4)))
#define CLKOUTCFG    (*((volatile unsigned int *)(0x400FC1C8)))


void exit();


void setup_clocks()
{
	PLL0CFG    = 0x0B;
	PLL0CON    = 0x1;
	PLL0FEED   = 0xAA;
	PLL0FEED   = 0x55;
	PLL0CON    = 0x3;
	PLL0FEED   = 0xAA;
	PLL0FEED   = 0x55;
	USBCLKCFG  = 0x0;
	PCLKSEL0   = 0x0;
	PCLKSEL1   = 0x0;
	PCONP      = 0x42887DE;
	CLKOUTCFG  = 0x0;
	
	exit();
}


void exit()
{
	while (1);
}
