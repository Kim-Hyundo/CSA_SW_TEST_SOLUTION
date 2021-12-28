#include "timerk60.h"

static volatile unsigned int  *g_itmBase = (volatile unsigned int *)0xE0000000;

#define ITM_ENABLE_ACCESS  g_itmBase[0x3EC]=0xC5ACCE55
#define ITM_TRACE_PRIV     g_itmBase[0x390]
#define ITM_TRACE_ENABLE   g_itmBase[0x380]

#define ITM_TRACE_BYTE(_channel_,_data_) (*((volatile unsigned char *)(g_itmBase+(_channel_))))=(_data_)
#define ITM_TRACE_WORD(_channel_,_data_) (*((volatile unsigned short *)(g_itmBase+(_channel_))))=(_data_)
#define ITM_TRACE_DWORD(_channel_,_data_) (*(g_itmBase+(_channel_)))=(_data_)
#define ITM_WAIT_FOR_CHANNEL_READY(_channel_) while ((*(g_itmBase+(_channel_)))==0)

static inline unsigned int nextCount(unsigned int cmp)
{
	cmp += 0x1001001;
	return cmp;
}

void timerInterrupt() __attribute__((interrupt));

static volatile unsigned int count;
void timerInterrupt()
{
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
	
	TIMER_CLEAR_INT;
}

volatile unsigned int gIterations;
volatile unsigned int timerReload=1999;

int main()
{
	count = 0x1001001;

	ITM_ENABLE_ACCESS;
	ITM_TRACE_PRIV=0;
	ITM_TRACE_ENABLE=0xFFFFFFFF;
	
	enableTimer(timerReload);
	for(;;) {
		gIterations++;
	}
	return 0;
}
