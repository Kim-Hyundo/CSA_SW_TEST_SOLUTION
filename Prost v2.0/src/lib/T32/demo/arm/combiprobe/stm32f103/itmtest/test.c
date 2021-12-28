static volatile unsigned int  *g_itmBase = (volatile unsigned int *)0xE0000000;

#define ITM_ENABLE_ACCESS  g_itmBase[0x3EC]=0xC5ACCE55
#define ITM_TRACE_PRIV     g_itmBase[0x390]
#define ITM_TRACE_ENABLE   g_itmBase[0x380]

#define ITM_TRACE_BYTE(_channel_,_data_) (*((volatile unsigned char *)(g_itmBase+(_channel_))))=(_data_)
#define ITM_TRACE_WORD(_channel_,_data_) (*((volatile unsigned short *)(g_itmBase+(_channel_))))=(_data_)
#define ITM_TRACE_DWORD(_channel_,_data_) (*(g_itmBase+(_channel_)))=(_data_)
#define ITM_WAIT_FOR_CHANNEL_READY(_channel_) while ((*(g_itmBase+(_channel_)))==0)

int wait(int k)
{
	int i;
	int j=0;

	for (i=1;i<k;i++)
		j+=i;

	return j;
}

static inline unsigned int nextCount(unsigned int cmp)
{
	if (cmp&0x80000000)
	{
		cmp<<=1;
		cmp^=0x10904081;
	}
	else
		cmp<<=1;
	return cmp;
}

void timerInterrupt() __attribute__((interrupt));

static unsigned int count;
void timerInterrupt()
{
#	define TIM2_SR    (*((volatile unsigned short *)(0x40000010)))

	unsigned int d1,d2,d3,d4,channel;
	
	d1=nextCount(count);
	channel=d1&0x1F;
	d1  = nextCount(d1);
	d2  = nextCount(d1);
	d3  = nextCount(d2);
	d4  = nextCount(d3);
	count=d4;

	ITM_WAIT_FOR_CHANNEL_READY(channel);
	ITM_TRACE_DWORD(channel,d1);
	ITM_WAIT_FOR_CHANNEL_READY(channel);
	ITM_TRACE_DWORD(channel,d2);
	ITM_WAIT_FOR_CHANNEL_READY(channel);
	ITM_TRACE_DWORD(channel,d3);
	ITM_WAIT_FOR_CHANNEL_READY(channel);
	ITM_TRACE_DWORD(channel,d4);
	ITM_WAIT_FOR_CHANNEL_READY(channel);
	ITM_TRACE_BYTE(channel,(unsigned char)d1);

	d1=nextCount(count);
	channel=d1&0x1F;
	d1  = nextCount(d1);
	d2  = nextCount(d1);
	d3  = nextCount(d2);
	d4  = nextCount(d3);
	count=d4;

	ITM_WAIT_FOR_CHANNEL_READY(channel);
	ITM_TRACE_DWORD(channel,d1);
	ITM_WAIT_FOR_CHANNEL_READY(channel);
	ITM_TRACE_DWORD(channel,d2);
	ITM_WAIT_FOR_CHANNEL_READY(channel);
	ITM_TRACE_DWORD(channel,d3);
	ITM_WAIT_FOR_CHANNEL_READY(channel);
	ITM_TRACE_DWORD(channel,d4);
	ITM_WAIT_FOR_CHANNEL_READY(channel);
	ITM_TRACE_BYTE(channel,(unsigned char)d1);
	
	TIM2_SR=0;
}

static volatile unsigned int timerReload=7999;

void enableTimer()
{
#	define RCC_APB1ENR (*((volatile unsigned int *)(0x4002101C)))
#	define TIM2_CR1    (*((volatile unsigned short *)(0x40000000)))
#	define TIM2_DIER   (*((volatile unsigned short *)(0x4000000C)))
#	define TIM2_ARR   (*((volatile unsigned short *)(0x4000002C)))
#	define INT_SET_ENABLE(_x_) (*(((volatile unsigned int *)(0xE000E100))+_x_))

	/* Enable clock for TIM2 */
	RCC_APB1ENR = 0x1;
	
	/* Update TIM2 on overflow */
	TIM2_CR1 = 0x4;
	
	/* Reload value for TIM2   */
	TIM2_ARR = timerReload;
	
	/* Enable interrupt on update */
	TIM2_DIER = 0x1;
	
	/* Enable TIM2 IRQ 28 */
	INT_SET_ENABLE(0)=0x10000000;
	
	/* Now start timer */
	TIM2_CR1 = 0x5;
}

int main()
{
	count = 0xFF00FF00;

	ITM_ENABLE_ACCESS;
	ITM_TRACE_PRIV=0;
	ITM_TRACE_ENABLE=0xFFFFFFFF;
	
	enableTimer();
	while(1)
	{
		wait(10000);
	}
	return 0;
}
