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

static volatile unsigned int count;
void timerInterrupt()
{
	unsigned int d1,d2,d3,d4,channel;
	
	d1=count;

	d1=nextCount(d1);
	channel=d1&0x1F;
	d1  = nextCount(d1);
	d2  = nextCount(d1);
	d3  = nextCount(d2);
	d4  = nextCount(d3);
	ITM_WAIT_FOR_CHANNEL_READY(channel);
	ITM_TRACE_DWORD(channel,d1);
	ITM_WAIT_FOR_CHANNEL_READY(channel);
	ITM_TRACE_DWORD(channel,d2);
	ITM_WAIT_FOR_CHANNEL_READY(channel);
	ITM_TRACE_DWORD(channel,d3);
	ITM_WAIT_FOR_CHANNEL_READY(channel);
	ITM_TRACE_DWORD(channel,d4);

	d1=nextCount(d1);
	channel=d1&0x1F;
	d1  = nextCount(d1);
	d2  = nextCount(d1);
	d3  = nextCount(d2);
	d4  = nextCount(d3);
	ITM_WAIT_FOR_CHANNEL_READY(channel);
	ITM_TRACE_DWORD(channel,d1);
	ITM_WAIT_FOR_CHANNEL_READY(channel);
	ITM_TRACE_DWORD(channel,d2);
	ITM_WAIT_FOR_CHANNEL_READY(channel);
	ITM_TRACE_DWORD(channel,d3);
	ITM_WAIT_FOR_CHANNEL_READY(channel);
	ITM_TRACE_DWORD(channel,d4);

	count=d4;
	TIMER_CLEAR_INT;
}

static volatile unsigned int timerReload=1999;
unsigned int countCompare = 0x1D2D5E63;

int main()
{
	count = 0xFF00FF00;

	ITM_ENABLE_ACCESS;
	ITM_TRACE_PRIV=0;
	ITM_TRACE_ENABLE=0xFFFFFFFF;
	enableTimer(timerReload);
	for(;;)
	{
		if (count==countCompare)
			break;
	}
	disableTimer();
	return 0;
}
