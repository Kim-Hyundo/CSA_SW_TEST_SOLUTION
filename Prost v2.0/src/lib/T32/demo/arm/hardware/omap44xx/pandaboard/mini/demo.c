#define TRUE 1
#define FALSE 0
#define SIZE 18

#define STM_BASE 0x54000000
#define MCBSP1_BASE 0x4902208c
#define CM2_DEBUG_CFG_BASE 0x4a0080f0

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
unsigned int value;

main()
{
	/* PRINTFTRACE: Message must be terminated by a timestamped packet. */
	STP_TRACE0_D8(0, 'H');
	STP_TRACE0_D8(0, 'e');
	STP_TRACE0_D8(0, 'l');
	STP_TRACE0_D8(0, 'l');
	STP_TRACE0_D8(0, 'o');
	STP_TRACE0_D8(0, ' ');
	STP_TRACE0_D8(0, 'w');
	STP_TRACE0_D8(0, 'o');
	STP_TRACE0_D8(0, 'r');
	STP_TRACE0_D8(0, 'l');
	STP_TRACE0_D8(0, 'd');
	STP_TRACE0_D8TS(0, '!');

	/* CMI: Turn on MCBSP1 interface */
	*((volatile unsigned int *) (0x4a004548)) = 0x00030002;

	while ( TRUE )
	{
       	        sieve();
	}
}


char flags[SIZE+1];

int sieve(void)				/* sieve of erathostenes */
{
        register int i, primz, k;

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

                                /* CMI: Turn on/off MCBSP1 clock (Force-idle / No-idle). Interface must be enabled before accessing.*/
				*((volatile unsigned int *) (MCBSP1_BASE)) = (((k + primz) & 2)<<2);

                        }
		 	/* OCP-WP: Write and read to/from CM2_DEBUG_CFG */
                       	*((volatile unsigned int *) (CM2_DEBUG_CFG_BASE)) = 0xdeadbeef;
                       	value = *((volatile unsigned int *) (CM2_DEBUG_CFG_BASE));
                }
        }
	return 0;
}
