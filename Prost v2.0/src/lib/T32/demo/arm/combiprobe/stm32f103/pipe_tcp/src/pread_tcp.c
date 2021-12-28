#ifdef LINUX
#  include <netdb.h>
#  include <sys/socket.h>
#  include <sys/stat.h>
#  include <fcntl.h>
#  include <string.h>
#  include <arpa/inet.h>
#  include <stdint.h>
#  include <unistd.h>
#  include <stdio.h>
#  include <stdlib.h>
#  include <signal.h>
#  define INVALID_SOCKET -1
#  define SOCKET_ERROR -1
#  ifdef DEBUG
#    define LOG_PRINT(_xx) fprintf(stderr,"Function %s, Line %d, Error: %s\n", __PRETTY_FUNCTION__ , __LINE__ , _xx);
#  else
#    define LOG_PRINT(_xx)
#  endif
#endif
#ifdef MS_WINDOWS
#  define _CRT_SECURE_NO_WARNINGS
#  include <stdio.h>
#  include <winsock2.h>
#  include <windows.h>
#  define ssize_t int
#  ifdef DEBUG
#    define LOG_PRINT(_xx) fprintf(stderr,"Error: %s\n", _xx);
#  else
#    define LOG_PRINT(_xx)
#  endif
#  define uint32_t unsigned int
#  define uint16_t unsigned short
#endif

#include "tcpsimple.h"
#include "mypipe.h"
#include "messages.h"

#define GET_WORD_LE(value,ptr)  (value) = ((uint32_t)(((unsigned char *)(&(ptr)))[0]))|(((uint32_t)(((unsigned char *)(&(ptr)))[1]))<<8)
#define GET_DWORD_LE(value,ptr) (value) = ((uint32_t)(((unsigned char *)(&(ptr)))[0]))|(((uint32_t)(((unsigned char *)(&(ptr)))[1]))<<8)|(((uint32_t)(((unsigned char *)(&(ptr)))[2]))<<16)|(((uint32_t)(((unsigned char *)(&(ptr)))[3]))<<24)

#define SET_WORD_LE(ptr,value)   { ((unsigned char *)(&(ptr)))[0]= (unsigned char)((uint32_t)(value)); ((unsigned char *)(&(ptr)))[1]=(unsigned char)(((uint32_t)(value))>>8); }
#define SET_DWORD_LE(ptr,value)  { ((unsigned char *)(&(ptr)))[0]= (unsigned char)((uint32_t)(value)); ((unsigned char *)(&(ptr)))[1]=(unsigned char)(((uint32_t)(value))>>8); ((unsigned char *)(&(ptr)))[2]=(unsigned char)(((uint32_t)(value))>>16); ((unsigned char *)(&(ptr)))[3]=(unsigned char)(((uint32_t)(value))>>24); }


/*********************************************************************************/
/**          Code for checking test data send from target                       **/
/*********************************************************************************/

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
   The following function receives a buffer full of STP messages
   and checks if the channel and data is correct.
   The function returns the number of bytes, left in the buffer
   after processing.
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

		if ((mc&0xFFFF)==0)
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

/*********************************************************************************/
/**          Code for communicating with TCP server                             **/
/*********************************************************************************/

static uint32_t get_status(tcp_socket_t fd)
{
	uint32_t result;

	tcp_msg_t msg;
	tcp_init_msg(&msg);

	if (tcp_recv_msg(fd,&msg))
		return STATUS_ERROR;

	if (msg.msg_type!=CLIENT_STATUS)
		return STATUS_UNKNOWN_MESSAGE;

	if (msg.msg_len!=4)
		return STATUS_UNKNOWN_MESSAGE;

	GET_DWORD_LE(result,msg.msg[0]);
	return result;
}

static int server_pipe_open(tcp_socket_t fd, unsigned int from, unsigned int to, char *pipe_name)
{
	int err;
	uint32_t status;

	tcp_msg_t msg;
	tcp_init_msg(&msg);

	msg.msg_type=SERVER_PIPE_OPEN;
	msg.msg_len=12+strlen(pipe_name)+1;
	SET_DWORD_LE(msg.msg[0],from);
	SET_DWORD_LE(msg.msg[4],to);
	strcpy((char *)(&(msg.msg[8])),pipe_name);

	err=tcp_send_msg(fd,&msg);
	if (err) return -1;

	fprintf(stderr,"Waiting for response\n");
	fflush(stderr);

	status=get_status(fd);
	if (status!=STATUS_OK) return -1; 

	return 0;
}

static int server_pipe_close(tcp_socket_t fd, char *pipe_name)
{
	int err;
	uint32_t status;

	tcp_msg_t msg;
	tcp_init_msg(&msg);

	msg.msg_type=SERVER_PIPE_CLOSE;
	msg.msg_len=strlen(pipe_name)+1;
	strcpy((char *)(&(msg.msg[0])),pipe_name);

	err=tcp_send_msg(fd,&msg);
	if (err) return err;

	status=get_status(fd);
	if (status!=STATUS_OK) return -1;

	return 0;
}

static int server_uart_write(tcp_socket_t fd,const unsigned char *buf,int len)
{
	int err;
	uint32_t status;
	
	tcp_msg_t msg;
	tcp_init_msg(&msg);

	if (len<=0 || len>8192)
		return -1;

	msg.msg_type=SERVER_UART_WRITE;
	msg.msg_len=len;
	memcpy(msg.msg,buf,len);
	
	err=tcp_send_msg(fd,&msg);
	if (err) return err;
	
	status=get_status(fd);
	if (status!=STATUS_OK) return -1;

	return 0;	
}

int main(int argc, char *argv[])
{

	tcp_socket_t fd;
	int err;

	unsigned int port;
	char *pipe_name;

	/* for reading from named pipe */
	mypipe_t pipe_handle;
	unsigned int buf_len;
	unsigned char buf[8200];

#ifdef MS_WINDOWS
	{
		WSADATA wsa;
		/* initialize windows sockets */
		err = WSAStartup(MAKEWORD(2, 0), &wsa);
		if (err != 0)
		{
			fprintf(stderr,"TCP/IP not ready, check configuration\n");
			return 1;
		}
	}
#endif

#ifdef LINUX
	signal(SIGPIPE, SIG_IGN);
#endif

	if (argc != 4) 
	{
		fprintf(stderr,"usage: pread_tcp <hostname> <port> <pipename>\n");
		return 1;
	}

	port = strtoul(argv[2],NULL,0);
	if (port<4096 || port>65499)
	{
		fprintf(stderr,"Invalid port number\n");
		return 1;
	}
	pipe_name=argv[3];

	err=tcp_open_connection(&fd,argv[1],(uint16_t)port);
	if (err)
	{
		fprintf(stderr,"Can't connect to server\n");
		return 1;
	}
	
	/* Send something to UART */
	if (server_uart_write(fd,"Hello World",11))
	{
		fprintf(stderr,"Can't write to UART\n");
		return 1;
	}

	/* Create a named pipe for reading data from it */
#ifdef LINUX
	sprintf((char *)buf,"/tmp/%s",pipe_name);
#endif
#ifdef MS_WINDOWS
	sprintf((char *)buf,"//./pipe/%s",pipe_name);
#endif

	if (mypipe_create_read(&pipe_handle,(char *)buf))
	{
		fprintf(stderr,"Can not create %s\n",buf);
		return 1;
	}
	fprintf(stderr,"Created %s for reading\n",buf);
	fprintf(stderr,"Tell server to open pipe for writing.\n");
	fflush(stderr);

	if (server_pipe_open(fd,0,255,pipe_name)==0)
		fprintf(stderr,"Server should be now connected to pipe\n");
	else
		fprintf(stderr,"Server did not open pipe\n");
	fflush(stderr);

	{
		int i;

		buf_len=0;
		for(;;)
		{
			i=mypipe_read(pipe_handle,buf+buf_len,8100);
			if (i==0)
				break;
			i+=buf_len;
			buf_len=checkdata(buf,i);
		}
	}

	server_pipe_close(fd, pipe_name);
	tcp_close_socket(fd);

	mypipe_close(pipe_handle);
	return 0;
}

