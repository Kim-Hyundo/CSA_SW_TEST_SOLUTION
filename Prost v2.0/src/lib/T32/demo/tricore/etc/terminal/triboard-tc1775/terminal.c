

int TerminalErrno;

#define BLOCKED_TERMINAL

void TerminalPutBlock(unsigned char * data, int size)
{
	volatile unsigned char * pout = (unsigned char *) 0xa0018000;

#ifdef BLOCKED_TERMINAL
	int i, j;

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
#else
	while (size > 0)
	{
		while (*pout) ;	/* wait for ready */
		*pout = *data;
		data++;
		size--;
	}
#endif
}

void TerminalGetBlock(unsigned char * data, int size)
{
	volatile unsigned char * pin = (unsigned char *) 0xa0018100;

#ifdef BLOCKED_TERMINAL
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
#else
	while (size > 0)
	{
		while (!*pin) ;	/* wait for ready */
		*data = *pin;
		*pin = 0;
		data++;
		size--;
	}
#endif
}


int TerminalGetchar()
{
	unsigned char imsg[4];

	TerminalGetBlock(imsg,1);

	return imsg[0];
}


int TerminalPuts(char * buffer)
{
	TerminalPutBlock((unsigned char *) buffer, strlen(buffer));
}


int TerminalPutPacket(unsigned char * data, int len)
{
	int i;
	unsigned char sum;

	data[-2] = 2;
	data[-1] = len;
	sum = len;
	for ( i = 0 ; i < len ; i++)
		sum += data[i];
	data[len] = sum;
	data[len+1] = 3;
	TerminalPutBlock( data-2, len+4 );
}


int TerminalGetPacket(unsigned char * data)
{
	int i, len;
	unsigned char sum;

	TerminalGetBlock( data, 2 );
	if (data[0] != 2)
		return -1;
	len = data[1];

	TerminalGetBlock( data, len+2 );
	if (data[len+1] != 3)
		return -1;

	sum = len;
	for ( i = 0 ; i < len ; i++)
		sum += data[i];

	if ( sum != data[i] )
		return -1;

	TerminalErrno = data[0];

	return len;
}


int TerminalOpenFile(char * fname, int mode)
{
	unsigned char msg[256];

	msg[2] = 0x01;
	msg[3] = mode;
	msg[4] = 0666;
	strcpy(msg+5,fname);
	TerminalPutPacket( msg+2, strlen(fname)+3 );

	if (TerminalGetPacket( msg ) == -1)
		return -1;
	if (msg[0])
		return -1;
	return msg[1];
}


int TerminalCloseFile(int handle)
{
	unsigned char msg[256];

	msg[2] = 0x02;
	msg[3] = handle;
	TerminalPutPacket( msg+2, 2 );

	if (TerminalGetPacket( msg ) == -1)
		return -1;
	if (msg[0])
		return -1;
	return 0;
}


int TerminalReadFile(int handle, char * buffer, int len)
{
	int i, blen, rlen;
	unsigned char msg[256];

	rlen = 0;
	while (len > 0) {
		blen = len;
		if (blen > 240)
			blen = 240;

		msg[2] = 0x03;
		msg[3] = handle;
		msg[4] = blen;
		TerminalPutPacket( msg+2, 3 );

		if ((blen = TerminalGetPacket( msg )) == -1)
			return -1;
		if (msg[0])
			return -1;

		blen--;
		if (blen == 0)
			break;

		for ( i = 0 ; i < blen ; i++ )
			buffer[i] = msg[i+1];

		buffer += blen;
		len -= blen;
		rlen += blen;
	}

	return rlen;
}


int TerminalWriteFile(int handle, char * buffer, int len)
{
	int i, blen, wlen;
	unsigned char msg[256];

	wlen = 0;
	while (len > 0) {
		blen = len;
		if (blen > 240)
			blen = 240;

		msg[2] = 0x04;
		msg[3] = handle;
		for ( i = 0 ; i < blen ; i++ )
			msg[i+4] = buffer[i];
		TerminalPutPacket( msg+2, 2+blen );

		if (TerminalGetPacket( msg ) == -1)
			return -1;
		if (msg[0])
			return -1;

		blen = msg[1];
		if (blen == 0)
			break;

		buffer += blen;
		len -= blen;
		wlen += blen;
	}

	return wlen;
}


int TerminalSeekFile(int handle, long pos)
{
	unsigned char msg[256];

	msg[2] = 0x05;
	msg[3] = handle;
	msg[4] = (unsigned char) (pos);
	msg[5] = (unsigned char) (pos>>8);
	msg[6] = (unsigned char) (pos>>16);
	msg[7] = (unsigned char) (pos>>24);

	TerminalPutPacket( msg+2, 6 );

	if (TerminalGetPacket( msg ) == -1)
		return -1;
	if (msg[0])
		return -1;

	return ((long)msg[1])|(((long)msg[2])<<8)|(((long)msg[3])<<16)|(((long)msg[4])<<24);
}


int TerminalTellFile(int handle)
{
	unsigned char msg[256];

	msg[2] = 0x06;
	msg[3] = handle;

	TerminalPutPacket( msg+2, 2 );

	if (TerminalGetPacket( msg ) == -1)
		return -1;
	if (msg[0])
		return -1;

	return ((long)msg[1])|(((long)msg[2])<<8)|(((long)msg[3])<<16)|(((long)msg[4])<<24);
}


int TerminalTellSizeFile(int handle)
{
	unsigned char msg[256];

	msg[2] = 0x07;
	msg[3] = handle;

	TerminalPutPacket( msg+2, 2 );

	if (TerminalGetPacket( msg ) == -1)
		return -1;
	if (msg[0])
		return -1;

	return ((long)msg[1])|(((long)msg[2])<<8)|(((long)msg[3])<<16)|(((long)msg[4])<<24);
}


int TerminalGetTempName(char * name)
{
	int i, blen;
	unsigned char msg[256];

	msg[2] = 0x08;
	
	TerminalPutPacket( msg+2, 1 );

	if ((blen = TerminalGetPacket( msg )) == -1)
		return -1;
	if (msg[0])
		return -1;

	blen--;
	
	for ( i = 0 ; i < blen ; i++ )
		name[i] = msg[i+1];
	name[i] = '\0';

	return 1;
}


int main()
{
	static char hmessage[] = "\r\nHello World!\r\n";
	static char mmessage[] = "\r\nr read file\r\nw write file\r\np performance test\r\n";
	static char pmessage[] = "Performance Test Text         \r\n";
	char imessage[256];
	char buffer[4096];
	int i, ch, handle;


	TerminalPuts( hmessage );

	while (1)
	{
		TerminalPuts( mmessage );

		ch = TerminalGetchar();

		if (ch == 'r' || ch == 'R')
		{
			handle = TerminalOpenFile("test1",0);
			if (handle == -1) {
				TerminalPuts( "failed to open file\r\n" );
				continue;
			}
			// i = TerminalReadFile(handle,buffer,4096);
			i = TerminalReadFile(handle,buffer,40);
			if (i == -1) {
				TerminalPuts( "failed to read file\r\n" );
				continue;
			}
			buffer[i] = '\0';
			TerminalPuts(buffer);

			i = TerminalCloseFile(handle);
			if (i == -1) {
				TerminalPuts( "failed to close file\r\n" );
				continue;
			}
			continue;
		}

		if (ch == 'w' || ch == 'W')
		{
			handle = TerminalOpenFile("test2",4);
			if (handle == -1) {
				TerminalPuts( "failed to open file\r\n" );
				continue;
			}
			i = TerminalWriteFile(handle,hmessage,strlen(hmessage));
			i = TerminalWriteFile(handle,pmessage,strlen(pmessage));
			
			if (i == -1) {
				TerminalPuts( "failed to write file\r\n" );
				continue;
			}

			i = TerminalCloseFile(handle);
			if (i == -1) {
				TerminalPuts( "failed to close file\r\n" );
				continue;
			}
			continue;
		}

		if (ch == 'p' || ch == 'P')
		{
			for ( i = 0 ; i < 32 ; i++ )
				TerminalPutBlock( (unsigned char *) pmessage, 32 );
			continue;
		}
	}


	return 0;
}

