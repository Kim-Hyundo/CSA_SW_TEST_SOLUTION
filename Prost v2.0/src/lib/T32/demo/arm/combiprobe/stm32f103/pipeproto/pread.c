/* 
   Demo application which uses a named pipe to
   receive ITM data from a DLL loaded by T32 in PIPE mode. 
   
   (C) Lauterbach Datentechnik GmbH 2010
*/

#ifdef MS_WINDOWS
#  define _CRT_SECURE_NO_WARNINGS 1
#  include <windows.h>

#  include <time.h>
	int gettimeofday(struct timeval *tv, void *tz)
	{
		FILETIME    ft;
		ULONGLONG   ms_time, ux_time;

		if (tv) {
			GetSystemTimeAsFileTime(&ft);

			/* Time since January 1, 1601 (UTC) in microseconds: */
			ms_time = (((ULONGLONG)ft.dwHighDateTime)<<32 | ft.dwLowDateTime) / 10;

			/* Time since the EPOCH (January 1, 1970 (UTC)) in microseconds */
			ux_time = ms_time - 11644473600000000ULL;

			tv->tv_sec  = (long)(ux_time / 1000000UL);
			tv->tv_usec = (long)(ux_time % 1000000UL);
		}
		return 0;
	}
#endif

/* gettimeofday for windows */

#ifdef LINUX
#   include <stdint.h>
#   include <stdlib.h>
#   include <string.h>
#   include <sys/time.h>
#   define INVALID_HANDLE_VALUE -1
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
   The following function receives a buffer full of ITM messages
   and checks if the channel and data is correct
*/
static int checkdata(unsigned char *buf,int len)
{
	static unsigned int count = 0xFF00FF00,msgCnt = 0,channel = 0, errors=0;;
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
			ch=c&0x1F;
		}
		nextCount(c);
		mc++;

		if (dc != ch || d != c)
		{
			printf("Error in Message Nr %u, ch 0x%02X, data 0x%08x, should be 0x%02x, 0x%08x\n",
			       mc,dc,d,ch,c);
			errors++;
			if (errors>10)
				return 0;
		}

		if ((mc&0x1FFFF)==0)
			printf("Checked %u messages, %u bytes, %u errors\n",mc,mc*5,errors);
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
	unsigned int i;

	struct timeval start,stop;
	unsigned int hh = 0;

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
	printf("Connected to %s\n",argv[1]);

	len=0;
	do
	{
		/* read data from pipe */
		i=mypipe_read(handle,buf+len,8100);

		/* stop if write end of pipe was closed */
		if (i==0)
			break;

		if (hh==0)
			gettimeofday(&start,NULL);
		hh+=i;
		i+=len;
		if (hh>50000000)
		{
			unsigned long long us;
			gettimeofday(&stop,NULL);
			us=stop.tv_sec - start.tv_sec;
			us*=1000000;
			us+=stop.tv_usec;
			us-=start.tv_usec;
			printf("received %d bytes in %.3fs\n",hh,((double)us/1000000.0));
			printf("rate %.3f bytes/s\n",(((double)hh)*1000000.0)/(double)us);
			hh=0;
		}

		/* check received messages */
		len=checkdata(buf,i);
	} while(1);
	mypipe_close(handle);
	return 0;
}
