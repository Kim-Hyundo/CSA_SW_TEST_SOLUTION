/* 
   Demo application which uses a Windows Named Pipe to
   receive SDTI data from a DLL loaded into T32. 

   (C) Lauterbach Datentechnik GmbH 2008
*/
#ifdef MS_WINDOWS
#  define _CRT_SECURE_NO_WARNINGS 1
#  include <windows.h>
#endif

#ifdef LINUX
#   include <stdint.h>
#   include <stdlib.h>
#   include <string.h>
#   define INVALID_HANDLE_VALUE -1
#   define DWORD unsigned int
#endif

#include <stdio.h>
#include "dll/mypipe.h"

#define nextCount(__cmp) \
	{ \
		if (__cmp & 0x80000000) \
		{ \
			__cmp <<= 1; \
			__cmp ^= 0x10904081; \
		} \
		else \
			__cmp <<= 1; \
	}

/* 
   The following function receives a buffer full of XTI messages
   and checks if the channel and data is correct
*/
static int checkdata(unsigned char *buf,int len)
{
	static unsigned int count = 0xFF00FF00,msgCnt = 0,channel = 0, errors=0;
	unsigned int c,ch,mc,d,dc;
	unsigned char *b=buf;

	if (errors>10)
		return 0;

	if (len<5)
	{
		printf("Received incomplete message :-(\n");
		return len;
	}

	/* 
	   Each message consists of
	   1 byte  Channel ID
	   4 bytes payload in little endian format
	*/
	c=count;
	ch=channel;
	mc=msgCnt;
	do
	{
		len-=5;

		dc = ((unsigned int)b[0]);
		d  = ((unsigned int)b[1]);
		d |= ((unsigned int)b[2])<<8;
		d |= ((unsigned int)b[3])<<16;
		d |= ((unsigned int)b[4])<<24;
		b+=5;

		if ( (mc&0x3) == 0)
		{
			nextCount(c);
			ch=c&0xFF;
		}
		nextCount(c);
		mc++;

		if (dc != ch || d != c)
		{
			printf("Error in Message Nr %d, ch 0x%02X, data 0x%08x, should be 0x%02x, 0x%08x\n",
			       mc,dc,d,ch,c);
			errors++;
			if (errors>10)
				return 0;
		}

		if ((mc&0xFFFF)==0)
			printf("Checked %d messages, %d bytes, %d errors\n",mc,mc*5,errors);
	} while (len>=5);
	count=c;
	msgCnt=mc;
	channel=ch;

	if (len>0)
	{
		/* This might sometimes seem to happen ... */

		printf("Received incomplete message :-(\n");
		/* copy incomplete message to start of buffer... */
		memcpy(buf,b,len);
	}
	return len;
}

int main(int argc, char **argv)
{
	mypipe_t handle;
	DWORD i;

	unsigned int len;
	unsigned char buf[8200];

	if (argc!=2)
	{
		printf("Usage: pread <pipename>\n");
		return 1;
	}
	/* Create a named pipe for reading data from it */

	if (mypipe_create_read(&handle,argv[1],1))
	{
		printf("Can not create %s\n",argv[1]);
		return 2;
	}
	printf("Connected to %s.\n",argv[1]);

	len=0;
	do
	{
		/* read data from pipe */
		i=mypipe_read(handle,buf+len,8100);

		/* stop if write end of pipe was closed */
		if (i==0)
			break;

		    i+=len;

		/* check received messages */
		len=checkdata(buf,i);
	} while(1);
	mypipe_close(handle);
	return 0;
}
