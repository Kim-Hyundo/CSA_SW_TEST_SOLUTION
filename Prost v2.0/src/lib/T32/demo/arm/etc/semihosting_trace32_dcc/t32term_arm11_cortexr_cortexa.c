
/**************************************************************************

	ARM11, Cortex-R, Cortex-A DCC communication variant (DCC3 or DCC method)
	
**************************************************************************/

#define DCC3

#ifdef DCC3

void T32_Term_PutBlock(const unsigned char * data, int size)
{
    int             len;
    unsigned long   ch, k;

	if (!data)
		return;

    while (size > 0) {
	len = size;
	if (len > 3)
	    len = 3;
	ch = data[0] | (data[1] << 8) | (data[2]) << 16 | ((len - 1) << 24);
	do /* Wait for Terminal Ready */
	{
		__asm
		{
			MRC	p14, 0, k, c0, c1;
		}
	} while (k & 0x20000000);
	__asm
	{
		MCR	p14, 0, ch, c0, c5
	}
	data += len;
	size -= len;
    }
}

void T32_Term_GetBlock(unsigned char * data, int size)
{
    static int      bufsize = 0;
    static int      bufindex;
    static unsigned char buf[4];
    int             i, j;
    unsigned long   ch;

    while (size > 0) {
	if (!bufsize) {
	    do /* Wait for input byte */
	    {
		__asm
		{
			MRC	p14, 0, ch, c0, c1;
		}
	    } while (!(ch & 0x40000000));
	    __asm
	    {
		MRC	p14, 0, ch, c0, c5;
	    }
	    buf[0] = ch & 0xff;
	    buf[1] = (ch >> 8) & 0xff;
	    buf[2] = (ch >> 16) & 0xff;
	    bufsize = (ch >> 24) + 1;
	    bufindex = 0;
	}
	i = bufsize;
	if (i > size)
	    i = size;

	for (j = 0; j < i; j++)
	    data[j] = buf[bufindex + j];

	bufindex += i;
	bufsize -= i;
	data += i;
	size -= i;
    }
}

#else

void T32_Term_PutBlock(const unsigned char * data, int size)
{
	register unsigned int k, len;

	if (!data)
		return;

	while (size > 0)
	{
		do /* Wait for Terminal Ready */
		{
			__asm
			{
				MRC	p14, 0, k, c0, c1;
			}
		}while (k & 0x20000000);
		k = *data;
		__asm
		{
			MCR	p14, 0, k, c0, c5
		}
		size--;
		data++;
	}
}

void T32_Term_GetBlock(unsigned char * data, int size)
{
	register unsigned int k, len;

	while (size > 0)
	{
		do /* Wait for input byte */
		{
			__asm
			{
				MRC	p14, 0, k, c0, c1;
			}
		}while (!(k & 0x40000000));
		__asm
		{
			MRC	p14, 0, k, c0, c5;
		}
		*data = k;
		size--;
		data++;
	}
}

#endif
