/* 
   Demo application which uses a Windows Named Pipe to
   receive SDTI data from T32 in PIPE mode. 
   
   (C) Lauterbach Datentechnik GmbH 2008
*/

#include <windows.h>
#include <stdio.h>

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
   Type definitions for XTI data
*/
#define DECXTI_TYPE_IOREAD   0x01
#define DECXTI_TYPE_IOWRITE  0x02
#define DECXTI_TYPE_IOOVF    0x03
#define DECXTI_TYPE_DSP      0x04
#define DECXTI_TYPE_MCU      0x05
#define DECXTI_TYPE_CPU2     0x05
#define DECXTI_TYPE_CPU1     0x06

#define DECXTI_TYPE_WITH_TS  0x10
#define DECXTI_TYPE_ERROR    0xFF

/* 
   The data which is received should follow a deterministic pattern.
   This function checks all 32 bit messages from CPU1 to see if the messages
   match that pattern.
*/
static int checkdata(unsigned char *buf,int len,unsigned int nr)
{
	static unsigned int count = 0xFF00FF00,msgCnt = 0,msgCnt2 = 0,channel = 0, errors=0;;
	unsigned int c,ch,mc,d,dc,l;
	unsigned char *b=buf;
	
	if (errors>10)
		return 0;

	if (len<4)
	{
		printf("Received incomplete message :-(\n");
		return len;
	}

	c=count;
	ch=channel;
	mc=msgCnt;
	nr<<=7;
	do
	{
		/* read length field of message */
		dc=b[0];
		d=1;
		l=(dc&0x7F);
		while (dc&0x80)
		{
		    dc=b[d++];
		    l=(l<<7)|(dc&0x7F);
		}

		/* if length field + message content is longer than */
		/* current buffer content, stop processing          */
		if (l+d>len)
			break;

		/* skip over length field */
		b+=d;
		len-=d;

		/* now:                       */
		/* b[ 0]--b[ 7]  Timestamp    */
		/* b[ 8]         Message Type */
		/* b[ 9]         Data Size    */
		/* b[10]         Channel ID   */
		/* b[11..]       Payload      */
		if ( (b[8]&0xF)!=DECXTI_TYPE_CPU1 || (b[9]&0xF)!=2 )
		{
			/* Skip messages other than 32 bit messages from CPU1*/
			b+=l;
			len-=l;
			continue;
		}

		dc = ((unsigned int)b[10]);        // ChannelID
		d  = ((unsigned int)b[11]);        // 11-14 data in little endian
		d |= ((unsigned int)b[12])<<8;
		d |= ((unsigned int)b[13])<<16;
		d |= ((unsigned int)b[14])<<24;

		/* goto next message */
		b+=l;
		len-=l;

		do
		{
		    if ( (mc&0x3) == 0)
		    {
			    nextCount(c);
			    ch=c&0xFF;
		    }
		    nextCount(c);
		    mc++;
		} while (ch<nr || ch>nr+127);
		msgCnt2++;
		
		if (dc != ch || d != c)
		{
			printf("Error in Message Nr %d, ch 0x%02X, data 0x%08x, should be 0x%02x, 0x%08x\n",
			       msgCnt2,dc,d,ch,c);
			errors++;
			if (errors>10)
				return 0;
		}

		if ((msgCnt2&0x3FFF)==0)
			printf("Checked %d messages, %d bytes, %d errors\n",msgCnt2,msgCnt2*5,errors);
	} while (len>=4);
	count=c;
	msgCnt=mc;
	channel=ch;

	if (len>0)
	{
		/* copy incomplete message to start of buffer... */
		memcpy(buf,b,len);
	}
	return len;
}

int main(int argc, char **argv)
{
	HANDLE handle;
	DWORD i;

	unsigned int len,nr;
	unsigned char buf[8200];
	unsigned char pipeName[20];

	if (argc!=2)
	{
		printf("Usage: pread2_pipe <nr>\n");
		return 1;
	}
	nr=strtoul(argv[1],NULL,0);
	sprintf(pipeName,"//./pipe/pproto%02d",nr);
	handle=CreateNamedPipe(pipeName,PIPE_ACCESS_INBOUND,PIPE_TYPE_BYTE,16,8192,8192,0,0);
	if (handle==INVALID_HANDLE_VALUE)
	{
		printf("Can not create %s\n",pipeName);
		return 2;
	}
	printf("Created %s\n",pipeName);
	if (ConnectNamedPipe(handle,NULL)==0)
	{
		printf("Got no client connection!\n");
		return 3;
	}
	printf("Connected.\n",pipeName);
	
	len=0;
	do
	{
		ReadFile(handle,buf+len,8100,&i,NULL);
		if (i==0)
			break;
		i+=len;
		len=checkdata(buf,i,nr);
	} while(1);
	CloseHandle(handle);
	return 0;
}
