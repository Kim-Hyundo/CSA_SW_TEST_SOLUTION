#include <windows.h>
#include <stdio.h>


#define DECITM_D8   1
#define DECITM_D16  2
#define DECITM_D32  3

#define ITM_ENTRY_QS    1
#define ITM_ENTRY_IS    2
#define ITM_QS_START    3
#define ITM_EXIT     0x80

static char *g_StrIndent = "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-";
static char *g_Indent;

static int printdata(unsigned char *buf,int len)
{
	unsigned int l;
	unsigned char *b=buf;
	
	if (len<4)
	{
		/* do not process messages with less than 4 bytes */
		return len;
	}
	while (len>=4)
	{
		/* read length field of message */
		l=b[0]+1;
		/* if length field + message content is longer than */
		/* current buffer content, stop processing          */
		if (len<l)
			break;

		/* now:                       */
		/* b[ 1]--b[ 8]  Timestamp    */
		/* b[ 9]         Message Type */
		/* b[10]         Channel ID   */
		/* b[11..]       Payload      */
		if ( b[9]!=DECITM_D8 )
		{
			/* Skip messages other than D8 */
			b+=l;
			len-=l;
			continue;
		}

		switch(b[11])
		{
		case ITM_ENTRY_QS:
			{
				/* process quicksort entry */
				unsigned int aleft,aright;
				l+=15+15; /* dword + dword */
				if (len<l)
					break;

				/* we expect:
				   b[12] length field of first dword message

				   b[27] length field of 2nd dword message

				   b[42] next message
				*/
				aleft=b[23];
				aleft|=((unsigned int)b[24])<<8;
				aleft|=((unsigned int)b[25])<<16;
				aleft|=((unsigned int)b[26])<<24;

				aright=b[38];
				aright|=((unsigned int)b[39])<<8;
				aright|=((unsigned int)b[40])<<16;
				aright|=((unsigned int)b[41])<<24;
				printf("%sqs_h(0x%08x,0x%08x)\n",g_Indent,aleft,aright);
				g_Indent-=2;
			}
			break;
		case ITM_ENTRY_IS:
			{
				/* process insertion sort entry */
				unsigned int aleft,aright;
				l+=15+15; /* dword + dword */
				if (len<l) 
					break;

				/* we expect:
				   b[12] length field of first dword message

				   b[27] length field of 2nd dword message

				   b[42] next message
				*/
				aleft=b[23];
				aleft|=((unsigned int)b[24])<<8;
				aleft|=((unsigned int)b[25])<<16;
				aleft|=((unsigned int)b[26])<<24;

				aright=b[38];
				aright|=((unsigned int)b[39])<<8;
				aright|=((unsigned int)b[40])<<16;
				aright|=((unsigned int)b[41])<<24;
				printf("%sis_h(0x%08x,0x%08x)\n",g_Indent,aleft,aright);
				g_Indent-=2;
			}
			break;
		case ITM_EXIT:
			{
				/* process ITM EXIT */
				g_Indent+=2;
			}
			break;
		case ITM_QS_START:
			{
				printf("---------------------------------------------\n");
			}
			break;
		default:
			;
		}
		if (len<l)
			break;
		/* goto next message */
		b+=l;
		len-=l;
	}
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
	g_Indent=g_StrIndent+80;

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
		len=printdata(buf,i);
	} while(1);
	CloseHandle(handle);
	return 0;
}
