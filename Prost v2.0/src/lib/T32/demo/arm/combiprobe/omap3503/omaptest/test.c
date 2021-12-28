
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

static unsigned int count;
static void writeXtiData()
{
	static volatile unsigned int  *g_xtiBase     = (volatile unsigned int *)0x54600000;
	unsigned int d1,d2,d3,d4,channel;
	
	d1=nextCount(count);
	channel=(d1&0xFF)<<10;
	d1  = nextCount(d1);
	d2  = nextCount(d1);
	d3  = nextCount(d2);
	d4  = nextCount(d3);
	count=d4;
	
	g_xtiBase[channel]=d1;
	g_xtiBase[channel]=d2;
	g_xtiBase[channel]=d3;
	g_xtiBase[channel]=d4;
	*(volatile unsigned char *)(g_xtiBase+channel)=d1;

	d1=nextCount(count);
	channel=(d1&0xFF)<<10;
	d1  = nextCount(d1);
	d2  = nextCount(d1);
	d3  = nextCount(d2);
	d4  = nextCount(d3);
	count=d4;

	g_xtiBase[channel]=d1;
	g_xtiBase[channel]=d2;
	g_xtiBase[channel]=d3;
	g_xtiBase[channel]=d4;
	*(volatile unsigned char *)(g_xtiBase+channel)=d1;
}

unsigned int timerReload = 100;
int main()
{
	count = 0xFF00FF00;
	//count=1;
	while(1)
	{
		wait(timerReload);
		writeXtiData();
	}
	return 0;
}
