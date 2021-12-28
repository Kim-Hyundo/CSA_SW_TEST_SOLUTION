
#define TRUE 1
#define FALSE 0
#define SIZE 18

const char cstr1[] = "Constant String1";

#define STM_BASE 0x54000000
int abcd, channel;
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


	abcd = 0;

	while ( TRUE )
	{
       	        sieve();
	}
}


char flags[SIZE+1];

int sieve(void)				/* sieve of erathostenes */
{
        register int i, primz, k;
	int anzahl;

	anzahl = 0;

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
                        anzahl++;
                        abcd++;
                        channel = (abcd >> 4) & 0xf;
                        //channel = 2;
                        //if (abcd < 10)
                        {
                            STP_TRACE0_D16(channel,primz);
                            STP_TRACE0_D16TS(channel, primz);
			}
                }
        }

	return anzahl;
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
