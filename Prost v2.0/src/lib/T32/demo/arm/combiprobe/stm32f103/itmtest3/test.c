#include <stdarg.h>

static volatile unsigned int  *ITM_BASE = (volatile unsigned int *)0xE0000000;

#define ITM_ENABLE_ACCESS  { ITM_BASE[0x3EC]=0xC5ACCE55; }
#define ITM_TRACE_PRIV     ITM_BASE[0x390]
#define ITM_TRACE_ENABLE   ITM_BASE[0x380]

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


static unsigned int count2,numInt2;
void timerInterrupt2() __attribute__((interrupt));
void timerInterrupt2()
{
#	define TIM2_SR    (*((volatile unsigned short *)(0x40000010)))

	unsigned int d1,d2;
	
	TIM2_SR=0;

	d2 = 0;
	do
	{
		d1=nextCount(count2);
		count2=d1;
		d2++;
	} while ( (d1&0xF) != 0x7 );
	numInt2 = d2;
}

static unsigned int count3,numInt3;
void timerInterrupt3() __attribute__((interrupt));
void timerInterrupt3()
{
#	define TIM3_SR    (*((volatile unsigned short *)(0x40000410)))

	unsigned int d1,d2;
	
	TIM3_SR=0;

	d2 = 0;
	do
	{
		d1=nextCount(count3);
		count3=d1;
		d2++;
	} while ( (d1&0x1F) != 0x15 );
	numInt3 = d2;
}

static unsigned int count4,numInt4;
void timerInterrupt4() __attribute__((interrupt));
void timerInterrupt4()
{
#	define TIM4_SR    (*((volatile unsigned short *)(0x40000810)))

	unsigned int d1,d2;

	TIM4_SR=0;

	d2 = 0;
	do
	{
		d1=nextCount(count4);
		count4=d1;
		d2++;
	} while ( (d1&0x3F) != 0x22 );
	numInt4 = d2;
	ITM_TRACE_D32(0x7,d2);
}



static volatile unsigned int timerReload2=1999;
static volatile unsigned int timerReload3=2899;
static volatile unsigned int timerReload4=4699;

void enableTimer()
{
#	define RCC_APB1ENR (*((volatile unsigned int *)(0x4002101C)))	

#	define TIM2_CR1    (*((volatile unsigned short *)(0x40000000)))
#	define TIM2_DIER   (*((volatile unsigned short *)(0x4000000C)))
#	define TIM2_ARR    (*((volatile unsigned short *)(0x4000002C)))

#	define TIM3_CR1    (*((volatile unsigned short *)(0x40000400)))
#	define TIM3_DIER   (*((volatile unsigned short *)(0x4000040C)))
#	define TIM3_ARR    (*((volatile unsigned short *)(0x4000042C)))

#	define TIM4_CR1    (*((volatile unsigned short *)(0x40000800)))
#	define TIM4_DIER   (*((volatile unsigned short *)(0x4000080C)))
#	define TIM4_ARR    (*((volatile unsigned short *)(0x4000082C)))


#	define INT_SET_ENABLE(_x_) (*(((volatile unsigned int *)(0xE000E100))+_x_))

#	define INT_SET_PRIO(_x_)   (*(((volatile unsigned int *)(0xE000E400))+_x_))

	/* Enable clock for TIM2,TIM3,TIM4 */
	RCC_APB1ENR = 0x7;

	/* Update TIM2 on overflow */
	TIM2_CR1 = 0x4;
	/* Reload value for TIM2   */
	TIM2_ARR = timerReload2;
	/* Enable interrupt on update */
	TIM2_DIER = 0x1;

	/* Update TIM3 on overflow */
	TIM3_CR1 = 0x4;
	/* Reload value for TIM3   */
	TIM3_ARR = timerReload3;
	/* Enable interrupt on update */
	TIM3_DIER = 0x1;

	/* Update TIM4 on overflow */
	TIM4_CR1 = 0x4;
	/* Reload value for TIM4   */
	TIM4_ARR = timerReload4;
	/* Enable interrupt on update */
	TIM4_DIER = 0x1;


	/* TIM2, PRIO 0x00, TIM3 PRIO 0x40, TIM4 PRIO 0x80 */
	INT_SET_PRIO(7)=0x0000804000;
	/* Enable TIM2,3,4 IRQ 28,29,30 */
	INT_SET_ENABLE(0)=0x70000000;

	/* Now start timer */
	TIM2_CR1 = 0x5;

	/* Now start timer */
	TIM3_CR1 = 0x5;

	/* Now start timer */
	TIM4_CR1 = 0x5;
}

int main()
{
	count2  = 0xFF00FF00;
	numInt2 = 0;

	count3  = 0x12345678;
	numInt3 = 0;

	count4  = 0x98765432;
	numInt4 = 0;

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
