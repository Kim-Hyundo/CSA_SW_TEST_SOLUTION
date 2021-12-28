/* For more information please take a look at ARM semihosting mechanism */

#include "t32term.h"

#pragma import(__use_no_semihosting)

int T32_Term_Errno;


int T32_Term_Getchar(void)
{
	unsigned char imsg[4];

	T32_Term_GetBlock(imsg,1);

	return imsg[0];
}


void T32_Term_Puts(const char * buffer)
{
	int i;

	for (i = 0; buffer[i] ; i++);

	T32_Term_PutBlock((unsigned char *) buffer, i);
}


static void T32_Term_PutPacket(unsigned char * data, int len)
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
	T32_Term_PutBlock( data-2, len+4 );
}


static int T32_Term_GetPacket(unsigned char * data)
{
	int i, len;
	unsigned char sum;

	T32_Term_GetBlock( data, 2 );
	if (data[0] != 2)
		return -1;
	len = data[1];

	T32_Term_GetBlock( data, len+2 );
	if (data[len+1] != 3)
		return -1;

	sum = len;
	for ( i = 0 ; i < len ; i++)
		sum += data[i];

	if ( sum != data[i] )
		return -1;

	T32_Term_Errno = data[0];

	return len;
}


int T32_Term_OpenFile(const char * fname, int mode)
{
	int i;
	unsigned char msg[256];

	msg[2] = 0x01;
	msg[3] = mode;
	msg[4] = 0;
	for (i = 0; fname[i] ; i++)
		msg[5+i] = fname[i];
	T32_Term_PutPacket( msg+2, i+3 );

	if (T32_Term_GetPacket( msg ) == -1)
		return -1;
	if (msg[0])
		return -1;
	return msg[1];
}

int T32_Term_Remove(char * fname)
{
    unsigned char   msg[256];

    msg[2] = 0x11;
    strcpy((char *) msg + 3, fname);
    T32_Term_PutPacket(msg + 2, strlen(fname) + 1);

    if (T32_Term_GetPacket(msg) == -1)
	return -1;
    if (msg[0])
	return -1;
    return 0;
}


int T32_Term_Rename(char * fname, char * fnamenew)
{
    int             len, lennew;
    unsigned char   msg[256];

    len = strlen(fname);
    lennew = strlen(fnamenew);

    msg[2] = 0x12;
    msg[3] = len;
    strcpy((char *) msg + 4, fname);
    strcpy((char *) msg + 4 + len, fnamenew);
    T32_Term_PutPacket(msg + 2, 2 + len + lennew);

    if (T32_Term_GetPacket(msg) == -1)
	return -1;
    if (msg[0])
	return -1;
    return 0;
}


int T32_Term_CloseFile(int handle)
{
	unsigned char msg[256];

	msg[2] = 0x02;
	msg[3] = handle;
	T32_Term_PutPacket( msg+2, 2 );

	if (T32_Term_GetPacket( msg ) == -1)
		return -1;
	if (msg[0])
		return -1;
	return 0;
}


int T32_Term_ReadFile(int handle, char * buffer, int len)
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
		T32_Term_PutPacket( msg+2, 3 );

		if ((blen = T32_Term_GetPacket( msg )) == -1)
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


int T32_Term_WriteFile(int handle, char * buffer, int len)
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
		T32_Term_PutPacket( msg+2, 2+blen );

		if (T32_Term_GetPacket( msg ) == -1)
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


int T32_Term_SeekFile(int handle, long pos)
{
	unsigned char msg[256];

	msg[2] = 0x05;
	msg[3] = handle;
	msg[4] = (unsigned char) (pos);
	msg[5] = (unsigned char) (pos>>8);
	msg[6] = (unsigned char) (pos>>16);
	msg[7] = (unsigned char) (pos>>24);

	T32_Term_PutPacket( msg+2, 6 );

	if (T32_Term_GetPacket( msg ) == -1)
		return -1;
	if (msg[0])
		return -1;

	return ((long)msg[1])|(((long)msg[2])<<8)|(((long)msg[3])<<16)|(((long)msg[4])<<24);
}


long T32_Term_TellFile(int handle)
{
	unsigned char msg[256];

	msg[2] = 0x06;
	msg[3] = handle;

	T32_Term_PutPacket( msg+2, 2 );

	if (T32_Term_GetPacket( msg ) == -1)
		return -1;
	if (msg[0])
		return -1;

	return ((long)msg[1])|(((long)msg[2])<<8)|(((long)msg[3])<<16)|(((long)msg[4])<<24);
}


long T32_Term_TellSizeFile(int handle)
{
	unsigned char msg[256];

	msg[2] = 0x07;
	msg[3] = handle;

	T32_Term_PutPacket( msg+2, 2 );

	if (T32_Term_GetPacket( msg ) == -1)
		return -1;
	if (msg[0])
		return -1;

	return ((long)msg[1])|(((long)msg[2])<<8)|(((long)msg[3])<<16)|(((long)msg[4])<<24);
}


int T32_Term_GetTempName(char * name)
{
	int i, blen;
	unsigned char msg[256];

	msg[2] = 0x08;

	T32_Term_PutPacket( msg+2, 1 );

	if ((blen = T32_Term_GetPacket( msg )) == -1)
		return -1;
	if (msg[0])
		return -1;

	blen--;

	for ( i = 0 ; i < blen ; i++ )
		name[i] = msg[i+1];
	name[i] = '\0';

	return 1;
}

