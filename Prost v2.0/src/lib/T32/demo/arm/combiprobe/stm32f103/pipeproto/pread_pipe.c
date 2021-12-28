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

static int checkdata(unsigned char *buf,int len)
{
	static unsigned int count = 0xFF00FF00,msgCnt = 0,channel = 0, errors=0;;
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

		/* goto next message */
		b+=l;
		len-=l;
		
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
			printf("Checked %u messages, %u bytes,%u errors\n",mc,mc*5,errors);
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

	unsigned int len;
	unsigned char buf[8200];

	if (argc!=2)
	{
		printf("Usage: pread <pipename>\n");
		return 1;
	}

	/* Create a named windows pipe with the given pipe name */
	/* pipe name has to be something like \\.\pipe\<name>   */
	handle=CreateNamedPipe(argv[1],PIPE_ACCESS_INBOUND,PIPE_TYPE_BYTE,16,8192,8192,0,0);
	if (handle==INVALID_HANDLE_VALUE)
	{
		printf("Can not create %s\n",argv[1]);
		return 2;
	}
	printf("Created %s\n",argv[1]);

	/* Now wait for T32 to connect to this pipe */
	if (ConnectNamedPipe(handle,NULL)==0)
	{
		printf("Got no client connection!\n");
		return 3;
	}
	printf("Connected.\n",argv[1]);
	
	len=0;
	do
	{
		/* Read from pipe up to 8100 bytes */
		ReadFile(handle,buf+len,8100,&i,NULL);

		/* if this returns with i==0, then T32 disconnected from pipe */
		if (i==0)
			break;

		/* Now check content of buffer */
		i+=len;
		len=checkdata(buf,i);
	} while(1);
	CloseHandle(handle);
	return 0;
}
