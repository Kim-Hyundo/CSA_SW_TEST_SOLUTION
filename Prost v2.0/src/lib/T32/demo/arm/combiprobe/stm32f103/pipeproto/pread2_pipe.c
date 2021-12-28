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

#define DECITM_D8   1
#define DECITM_D16  2
#define DECITM_D32  3

static int checkdata(unsigned char *buf,int len,unsigned int nr)
{
	static unsigned int count = 0xFF00FF00,msgCnt = 0,msgCnt2 = 0, channel = 0, errors=0;
	unsigned int c,ch,mc,l,d,dc;
	unsigned char *b=buf;
	
	if (errors>10)
		return 0;

	if (len<4)
	{
		/* do not process messages with less than 4 bytes */
		return len;
	}

	c=count;
	ch=channel;
	mc=msgCnt;
	nr<<=4;
	while (len>=4)
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
		/* b[ 9]         Channel ID   */
		/* b[10..]       Payload      */

		if ( b[8]!=DECITM_D32 )
		{
			/* Skip messages other than D32 */
			b+=l;
			len-=l;
			continue;
		}

		dc = ((unsigned int)b[9]);        // ChannelID
		d  = ((unsigned int)b[10]);       // 10-13 data in little endian
		d |= ((unsigned int)b[11])<<8;
		d |= ((unsigned int)b[12])<<16;
		d |= ((unsigned int)b[13])<<24;

		/* calculate next message */
		b+=l;
		len-=l;

		do
		{
		    if ( (mc&0x3) == 0)
		    {
			    nextCount(c);
			    ch=c&0x1F;
		    }
		    nextCount(c);
		    mc++;
		} while (ch<nr || ch>nr+15);
		msgCnt2++;
		
		if (dc != ch || d != c)
		{
			printf("Error in Message Nr %u, ch 0x%02X, data 0x%08x, should be 0x%02x, 0x%08x\n",
			       msgCnt2,dc,d,ch,c);
			errors++;
			if (errors>10)
				return 0;
		}

		if ((msgCnt2&0xFFFF)==0)
			printf("Checked %u messages, %u bytes, %u errors\n",msgCnt2,msgCnt2*5,errors);
	}
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
