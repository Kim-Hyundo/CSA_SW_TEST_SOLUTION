#include <stdarg.h>

static volatile unsigned int  *g_itmBase = (volatile unsigned int *)0xE0000000;

#define ITM_ENABLE_ACCESS  { g_itmBase[0x3EC]=0xC5ACCE55; }
#define ITM_TRACE_PRIV     g_itmBase[0x390]
#define ITM_TRACE_ENABLE   g_itmBase[0x380]

static volatile unsigned int *ITM_BASE = (volatile unsigned int *)0xE0000000;
#define ITM_TRACE_D8(_channel_,_data_) { \
	volatile unsigned int *_ch_=ITM_BASE+(_channel_); \
	while ( *_ch_ == 0); \
	(*((volatile unsigned char *)(_ch_)))=(_data_); \
}

#define ITM_TRACE_D16(_channel_,_data_) { \
	volatile unsigned int *_ch_=ITM_BASE+(_channel_); \
	while ( *_ch_ == 0); \
	(*((volatile unsigned short *)(_ch_)))=(_data_); \
}

#define ITM_TRACE_D32(_channel_,_data_) { \
	volatile unsigned int *_ch_=ITM_BASE+(_channel_); \
	while ( *_ch_ == 0); \
	*_ch_ = (_data_); \
}

extern int vsprintf(char *buf, const char *fmt, va_list args);

void ITM_printf(const char *format,...)
{
	union {
		char c[100];
		unsigned int i[25];
	} line;
	unsigned int v;
	int i,j,l;
	va_list ap;

	va_start(ap, format);
	l=vsprintf(&(line.c[0]),format,ap);
	l++;
	va_end(ap);
	i=0;j=0;
	while (i<l)
	{
		v=line.i[j];
		i+=4;
		j++;
		if (i>l)
			v&=(0xFFFFFFFF>>((i-l)*8));
		ITM_TRACE_D32(0,v);
	}
}

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

static unsigned int count,numInt;
void timerInterrupt()
{
#	define TIM2_SR    (*((volatile unsigned short *)(0x40000010)))

	unsigned int d1,d2,d3,d4,channel;
	
	d1=nextCount(count);
	count=d1;
	numInt++;
	if ( (d1&0x3FFF) == 0x1123 )
	{
		ITM_printf("count == %08x after %d tries",d1,numInt);
		numInt=0;
	}

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
	numInt= 0;

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
