
#define TRUE 1
#define FALSE 0
#define SIZE 18

#define STM_BASE 0x54000000
#define MCBSP1_BASE 0x4902208c
//#define MCBSP1_BASE 0x4a004548

int channel;
// Address space 0
#define STP_TRACE0_D8(_channel_,_data_) {*((volatile unsigned char *) (STM_BASE + 0x1000 * _channel_)) = _data_;}
#define STP_TRACE0_D8TS(_channel_,_data_) {*((volatile unsigned char *) (STM_BASE + 0x800 + 0x1000 * _channel_)) = _data_;}
#define STP_TRACE0_D16(_channel_,_data_) {*((volatile unsigned short *) (STM_BASE + 0x1000 * _channel_)) = _data_;}
#define STP_TRACE0_D16TS(_channel_,_data_) {*((volatile unsigned short *) (STM_BASE + 0x800 + 0x1000 * _channel_)) = _data_;}
#define STP_TRACE0_D32(_channel_,_data_) {*((volatile unsigned int *) (STM_BASE + 0x1000 * _channel_)) = _data_;}
#define STP_TRACE0_D32TS(_channel_,_data_) {*((volatile unsigned int *) (STM_BASE + 0x800 + 0x1000 * _channel_)) = _data_;}

// Address space 1
#define STP_TRACE1_D8(_channel_,_data_) {*((volatile unsigned char *) (STM_BASE + 0x400 * _channel_)) = _data_;}
#define STP_TRACE1_D8TS(_channel_,_data_) {*((volatile unsigned char *) (STM_BASE + 0x200 + 0x400 * _channel_)) = _data_;}
#define STP_TRACE1_D16(_channel_,_data_) {*((volatile unsigned short *) (STM_BASE + 0x400 * _channel_)) = _data_;}
#define STP_TRACE1_D16TS(_channel_,_data_) {*((volatile unsigned short *) (STM_BASE + 0x200 + 0x400 * _channel_)) = _data_;}
#define STP_TRACE1_D32(_channel_,_data_) {*((volatile unsigned int *) (STM_BASE + 0x400 * _channel_)) = _data_;}
#define STP_TRACE1_D32TS(_channel_,_data_) {*((volatile unsigned int *) (STM_BASE + 0x200 + 0x400 * _channel_)) = _data_;}






int sieve(void);

main()
{
	/* CMI: Turn on MCBSP1 interface */
	*((volatile unsigned int *) (0x4a004548)) = 0x00030002;

	//STP_TRACE0_D8(0, 'H');
	//STP_TRACE0_D8(0, 'e');
	//STP_TRACE0_D8(0, 'l');
	//STP_TRACE0_D8(0, 'l');
	//STP_TRACE0_D8(0, 'o');
	//STP_TRACE0_D8(0, ' ');
	//STP_TRACE0_D8(0, 'w');
	//STP_TRACE0_D8(0, 'o');
	//STP_TRACE0_D8(0, 'r');
	//STP_TRACE0_D8(0, 'l');
	//STP_TRACE0_D8(0, 'd');
	//STP_TRACE0_D8TS(0, '!');


	while ( TRUE )
	{
		sieve();
	}
}


char flags[SIZE+1];

int sieve(void)          /* sieve of erathostenes */
{
	register int i, primz, k;
	unsigned int value;
	unsigned int wait;

	for ( i = 0 ; i <= SIZE ; flags[ i++ ] = TRUE ) ;

	for ( i = 0 ; i <= SIZE ; i++ )
	{
		if ( flags[ i ] )
		{
			primz = i + i + 3;
			k = i + primz;
			while ( k <= SIZE )
			{
				flags[ k ] = FALSE;
				k += primz;
			}

			channel = (i >> 2) & 0xf;

			/* CMI: Turn on/off MCBSP1 clock (Force-idle / No-idle). Interface must be enabled before accessing.*/
			*((volatile unsigned int *) (MCBSP1_BASE)) = (((k + primz) & 2)<<2);

			/* OCP-WP: Write and read to/from CM2_DEBUG_CFG */
			*((volatile unsigned int *) (0x4a0080f0)) = 0xdeadbeef;
                       	value = *((volatile unsigned int *) (0x4a0080f0));
                       	*((volatile unsigned int *) (0x4a0080f0)) = 0x12345678;
                       	value = *((volatile unsigned int *) (0x4a0080f0));
                       	*((volatile unsigned int *) (0x4a0080f0)) = 0xaabbccdd;
                       	value = *((volatile unsigned int *) (0x4a0080f0));


				//STP_TRACE0_D16(channel,primz);
				//STP_TRACE0_D16TS(channel, primz);

				//for (wait =0; wait < 10000; wait++);

				if (primz == 5)
				    channel = channel+1;
		}
	}

	return 0;
}


int background()			/* job for background-demo */
{
	register long count1, count2;

	count1 = count2 = 0;

	while ( TRUE )
	{
		while ( ++count1 ) ;
		count2++;
	}

	return TRUE;
}
