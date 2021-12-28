/**************************************************************************

	Cortex-M communication variant ('BUFFERE', memory based interface)
	(DCC channel is not available on Cortex-M)
	
**************************************************************************/

unsigned char InBuffer[256];
unsigned char OutBuffer[256];

void T32_Term_PutBlock(unsigned char * data, int size)
{
	// volatile unsigned char * pout = (unsigned char *) 0x1000;
	// requires 'TERM.METHOD BUFFERE e:0x1000 e:0x2000' in the *.cmm script

	volatile unsigned char * pout = OutBuffer;

	int i, j;

	if (!data)
		return;

	while (size > 0)
	{
		i = size;
		if ( i > 252)
			i = 252;
		while (*pout) ;	/* wait for ready */
		for (j = 0 ; j < i; j++)
			pout[j+4] = data[j];
		*pout = i;
		data += i;
		size -= i;
	}
}

void T32_Term_GetBlock(unsigned char * data, int size)
{
	// volatile unsigned char * pin = (unsigned char *) 0x2000;
	// requires 'TERM.METHOD BUFFERE e:0x1000 e:0x2000' in the *.cmm script

	volatile unsigned char * pin = InBuffer;

	static int bufsize = 0;
	static int bufindex;
	int i, j;

	while (size > 0)
	{
		if (!bufsize)
		{
			while (!*pin) ;	/* wait for ready */
			bufsize = *pin;
			bufindex = 0;
		}
		
		i = bufsize;
		if ( i > size)
			i = size;

		for ( j = 0 ; j < i ; j++)
			data[j] = pin[4+bufindex+j];

		bufindex += i;
		if (bufindex >= bufsize) {
			*pin = 0;	/* ready for next */
			bufsize = 0;
		}
		data += i;
		size -= i;
	}
}

