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
#    define LOG_PRINT(_xx) PIPE_Printf(info,"Error: %s\n", _xx);
#  else
#    define LOG_PRINT(_xx)
#  endif
#  define uint32_t unsigned int
#  define uint16_t unsigned short
#endif


#include "pipeproto.h"
#include "tcpsimple.h"
#include "mypipe.h"
#include "messages.h"

#define GET_WORD_LE(value,ptr)  (value) = ((uint32_t)(((unsigned char *)(&(ptr)))[0]))|(((uint32_t)(((unsigned char *)(&(ptr)))[1]))<<8)
#define GET_DWORD_LE(value,ptr) (value) = ((uint32_t)(((unsigned char *)(&(ptr)))[0]))|(((uint32_t)(((unsigned char *)(&(ptr)))[1]))<<8)|(((uint32_t)(((unsigned char *)(&(ptr)))[2]))<<16)|(((uint32_t)(((unsigned char *)(&(ptr)))[3]))<<24)

#define SET_WORD_LE(ptr,value)   { ((unsigned char *)(&(ptr)))[0]= (unsigned char)((uint32_t)(value)); ((unsigned char *)(&(ptr)))[1]=(unsigned char)(((uint32_t)(value))>>8); }
#define SET_DWORD_LE(ptr,value)  { ((unsigned char *)(&(ptr)))[0]= (unsigned char)((uint32_t)(value)); ((unsigned char *)(&(ptr)))[1]=(unsigned char)(((uint32_t)(value))>>8); ((unsigned char *)(&(ptr)))[2]=(unsigned char)(((uint32_t)(value))>>16); ((unsigned char *)(&(ptr)))[3]=(unsigned char)(((uint32_t)(value))>>24); }

/* maximum size of message */
#define MAX_MSG_SIZE    8192

#define MAX_TRACE_ENDPOINTS 5
#define MAX_PIPENAME_LENGTH 64

typedef struct pipeEndpoint
{
	int valid;
	
	/* range of ITM channels to receive messages from */
	unsigned int from,to;
	
	/* example: Export trace data via namedPipe */
	mypipe_t handle;
	unsigned int buf_len;
	unsigned char buf[8200];
	unsigned char pipe_name[MAX_PIPENAME_LENGTH+8];
} pipeEndpointT,*pipeEndpointP;

#define MAX_CONNECTIONS 5

typedef struct connection
{
	tcp_socket_t fd;
	tcp_msg_t msg;
} connectionT,*connectionP;


/* Data per DLL load */

/* 
   The following structure is completely specific for your DLL.
   In this example several things are stored: 
*/
typedef struct localData 
{
	/* socket to listen to for new connections */
	tcp_socket_t listen_fd;
	
	/* number of open TCP/IP connections */
	int connectionNum;
	connectionT connections[MAX_CONNECTIONS];

	/* pipe endpoints (not routed via TCP/IP) */
	pipeEndpointT pipes[MAX_TRACE_ENDPOINTS];
} localDataT,*localDataP;


/*
   Type definitions for ITM data
*/
#define DECITM_D8   1
#define DECITM_D16  2
#define DECITM_D32  3

/* Processing function
 *
 * The following function will be called, each time a STP message is decoded 
 * 
 * Parameters
 *  info   : Structure for calling functions inside T32 software.
 *  data   : Pointer to structure which holds local data for this DLL.
 *  buffer : Pointer to byte buffer which holds STP message.
 *  len    : Length of byte buffer which holds STP message.
 *
 * Format of buffer:
 * Byte  0-7  : 64 Bit Timestamp in Little Endian order.
 *             Scale: 256 == 0x100 == 20ns.
 *             Example: A value of 0x1234 means a time of (0x1234/0x100)*20 ns == 364 ns
 *
 * Byte    8  : Type of ITM data message (see defines above).
 *
 * Byte    9  : ITM channel
 * Byte 10-.. : ITM data message payload in Little Endian order.
 */
static void process(pipeProtoInfo *info,localDataP data,unsigned char *buffer,int len)
{
	pipeEndpointP pipes=data->pipes;
	int i;

	if (buffer==NULL)
	{
		/* 
		   If the processing function is called with an empty buffer,
		   it is an indication, that the data should be flushed
		*/
		for (i=0;i<MAX_TRACE_ENDPOINTS;i++)
		{
			if (pipes[i].valid)
			{
				mypipe_write(pipes[i].handle,pipes[i].buf,pipes[i].buf_len);
				pipes[i].buf_len=0;
			}
		}
	}
	/* In this example only D32 messages are processed */
	else if ( (buffer[8]&0xF) == DECITM_D32 ) 
	{ 
		int               h;
		unsigned char  *buf;
		/* channel number */
		unsigned int     ch = buffer[9];

		/* export data to connected pipes */
		for (i=0;i<MAX_TRACE_ENDPOINTS;i++)
		{
			if (!pipes[i].valid)
				continue;

			/* Only process data, if STP master and channel is in the correct range */
			if (ch<pipes[i].from || ch>pipes[i].to)
				continue;

			h=pipes[i].buf_len;
			buf=pipes[i].buf;

			/* Store channel and payload into local buffer */
			buf[h]  = (unsigned char)ch;
			buf[h+1]= buffer[10];       /* 32 bit little-endian payload data */
			buf[h+2]= buffer[11];
			buf[h+3]= buffer[12];
			buf[h+4]= buffer[13];
			h += 5;

			/* flush buffer to pipe if we have collected at least 8000 bytes */
			if (h >= 8000)
			{
				mypipe_write(pipes[i].handle,buf,h);
				h=0;
			}
			pipes[i].buf_len=h;
		}
	}

}

/* open a named pipe for writing */
static uint32_t pipe_open(pipeProtoInfo *info,localDataP data,tcp_msg_p msg)
{
	int i,j,m;
	pipeEndpointP pipe;
	char pipe_name[MAX_PIPENAME_LENGTH+16];

	/* ensure that pipename is NULL terminated */
	msg->msg[msg->msg_len]=0;

	/* find free endpoint structure */	
	i=0;
	pipe=data->pipes;
	while (i<MAX_TRACE_ENDPOINTS)
	{
		if (!pipe->valid)
			break;
		pipe++;
		i++;
	}
	if (i>=MAX_TRACE_ENDPOINTS)
	{
		PIPE_Puts(info,"Too many endpoints already opened.");
		return STATUS_ERROR;
	}

	/* read "from, to"  from message in little-endian */
	GET_DWORD_LE(pipe->from,msg->msg[0]);
	GET_DWORD_LE(pipe->to,msg->msg[4]);
	pipe->buf_len=0;

	/* read Named Pipename from messge */
	i=0;
	m=8;
#ifdef MS_WINDOWS
	sprintf(pipe_name,"//./pipe/");
	j=9;
#endif
#ifdef LINUX
	sprintf(pipe_name,"/tmp/");
	j=5;
#endif
	for(;;)
	{
		if (i>=MAX_PIPENAME_LENGTH)
		{
			PIPE_Puts(info,"PipeName is too long");
			return STATUS_ERROR;
		}
		pipe->pipe_name[i]=msg->msg[m];
		pipe_name[j]=msg->msg[m];
		if (msg->msg[m]==0)
			break;
		m++;
		i++;
		j++;
	}

	if (mypipe_open_write(&(pipe->handle),pipe_name))
	{
		PIPE_Printf(info,"Can not open %s for writing",pipe_name);
		return STATUS_ERROR;
	}
	PIPE_Printf(info,"Opened trace pipe %s, from channel %d to channel %d",pipe_name,pipe->from,pipe->to);
	pipe->valid=1;
	return STATUS_OK;
}

/* close a named pipe */
static uint32_t pipe_close(pipeProtoInfo *info,localDataP data,tcp_msg_p msg)
{
	int i;
	pipeEndpointP pipe;

	/* ensure that pipe_name is DEFINITELY null terminated */
	msg->msg[msg->msg_len]=0;

	/* search endpoints for pipe_name */
	i=0;
	pipe=data->pipes;
	while (i<MAX_TRACE_ENDPOINTS)
	{
		if ( pipe->valid && !strcmp((char *)msg->msg,(char *)pipe->pipe_name) )
		{
			/* close pipe and endpoint */
			mypipe_close(pipe->handle);
			pipe->valid=0;
			PIPE_Printf(info,"Closed trace pipe %s",pipe->pipe_name);
		}
		pipe++;
		i++;
	}
	return STATUS_OK;
}

/* write to CombiProbe UART */
static uint32_t uart_write(pipeProtoInfo *info,localDataP data,tcp_msg_p msg)
{
	int len;
	if (msg->msg_len<=0 || msg->msg_len>8192)
		return STATUS_ERROR;

	len=PIPE_UartWrite(info,msg->msg,msg->msg_len);
	if (len!=msg->msg_len)
		return STATUS_ERROR;

	return STATUS_OK;
}

/* Process message received from a client */
static uint32_t process_message(pipeProtoInfo *info,localDataP data,tcp_msg_p msg)
{
	uint32_t status;
	PIPE_Printf(info,"Received Message. Type %d, length %d",msg->msg_type,msg->msg_len);
	status=0;
	switch(msg->msg_type)
	{
		case SERVER_PIPE_OPEN:
			status=pipe_open(info,data,msg);
			break;
		case SERVER_PIPE_CLOSE:
			status=pipe_close(info,data,msg);
			break;
		case SERVER_UART_WRITE:
			status=uart_write(info,data,msg);
			break;
		default:
			status=STATUS_UNKNOWN_MESSAGE;
			;
	}
	/* consume message */
	tcp_init_msg(msg);
	return status;
}

/* close a TCP connection */
static void close_connection(pipeProtoInfo *info,localDataP data,connectionP con)
{
	if (con->fd == INVALID_SOCKET)
		return;
	
	tcp_close_socket(con->fd);
	con->fd = INVALID_SOCKET;
	data->connectionNum--;

	PIPE_Printf(info,"Closed connection, %d connections open",data->connectionNum);
	return;
}

/* accept a TCP connection */
static void accept_connection(pipeProtoInfo *info,localDataP data)
{
	int i;
	tcp_socket_t fd;
	if (tcp_accept_connection(&fd,data->listen_fd))
	{
		PIPE_Puts(info, "accept() returned error?!");
		return;
	}

	for (i=0;i<MAX_CONNECTIONS;i++)
	{
		if (data->connections[i].fd == INVALID_SOCKET)
		{
			/* initialize connection structure */
			data->connections[i].fd = fd;
		    tcp_init_msg(&(data->connections[i].msg));

			data->connectionNum++;
			PIPE_Printf(info,"Accepted connection, %d connections open",data->connectionNum);
			return;
		}
	}
	PIPE_Puts(info,"Rejected connection?!");
}

/* 
   This is the main polling loop.
   This function will be called periodically to check
   for client requests.
*/
static void task(pipeProtoInfo *info,localDataP data)
{
	int i,ret,fdmax;
	fd_set socket_set;
	struct timeval to;

	tcp_msg_t response;
	tcp_init_msg(&response);

	to.tv_sec = 0;
	to.tv_usec = 0;
	fdmax=data->listen_fd;
	FD_ZERO(&socket_set);
	if (data->connectionNum < MAX_CONNECTIONS)
	{
		FD_SET(data->listen_fd,&socket_set);
	}
	
	for (i=0;i<MAX_CONNECTIONS;i++)
	{
		if (data->connections[i].fd != INVALID_SOCKET)
		{
			FD_SET(data->connections[i].fd,&socket_set);
			if (data->connections[i].fd>(tcp_socket_t)fdmax)
				fdmax=data->connections[i].fd;
		}
	}
	ret = select(fdmax+1, &socket_set, NULL, NULL, &to);
	if (ret == SOCKET_ERROR)
	{
		PIPE_Puts(info,"select() returned error?!");
		return;
	}
	for (i=0;i<MAX_CONNECTIONS;i++)
	{
		if (data->connections[i].fd != INVALID_SOCKET)
		{
			if (FD_ISSET(data->connections[i].fd,&socket_set))
			{
				tcp_msg_p msg=&(data->connections[i].msg);
				if (tcp_poll_msg(data->connections[i].fd,msg))
					close_connection(info,data,&(data->connections[i]));
				else if (msg->valid)
				{
					uint32_t status;

					status=process_message(info,data,msg);

					response.msg_type=CLIENT_STATUS;
					response.msg_len=4;
					SET_DWORD_LE(response.msg[0],status);

					tcp_send_msg(data->connections[i].fd,&response);
				}
			}
		}
	}
	if (data->connectionNum < MAX_CONNECTIONS)
	{
		if (FD_ISSET(data->listen_fd,&socket_set))
			accept_connection(info,data);
	}
}

/* called when DLL is unloaded
 * Parameters
 *  info   : Structure for calling functions inside T32
 *  data   : Pointer to structure which holds local data for this DLL.
 */
static void exit_dll(pipeProtoInfo *info,localDataP data)
{
	int i;
	pipeEndpointP pipes=data->pipes;

	/* close listen socket */
	if (data->listen_fd != INVALID_SOCKET)
		tcp_close_socket(data->listen_fd);
	
	for (i=0;i<MAX_CONNECTIONS;i++)
		close_connection(info,data,&(data->connections[i]));
	
	for (i=0;i<MAX_TRACE_ENDPOINTS;i++)
	{
		if (!pipes[i].valid)
			continue;
		mypipe_close(pipes[i].handle);
		pipes[i].valid=0;
	}

	/* Free data, which was allocated in "PIPE_Interface" */
	free(data);
	
	PIPE_Puts(info,"DLL unloaded");
}

/* called when DLL is loaded 
 *
 * Parameters
 *  info   : Structure for calling functions inside T32
 *  argc   : numbers of parameters stored in "argv"
 *  argv   : array of pointers to "NUL" terminated command line parameters
 *
 * This function should allocate space to store local configuration data
 * for one DLL load.
 * It additionally should do all initialization which is necessary.
 */
int PIPE_Init(pipeProtoInfo *info,int argc, char **argv)
{
	/* char command[1000]; */
	int port,i;
	localDataP localdata;
	tcp_socket_t listen_fd;

#ifdef MS_WINDOWS
	{
		WSADATA wsa;
		/* initialize windows sockets */
		if (WSAStartup(MAKEWORD(2, 0), &wsa) != 0)
		{
			PIPE_Puts(info,"TCP/IP not ready, check configuration");
			return 1;
		}
	}
#endif

#ifdef LINUX
	signal(SIGPIPE, SIG_IGN);
#endif

	if (argc!=2)
	{
		PIPE_Puts(info,"usage: pproto_tcp <port>");
		return 1;
	}

	/* extract range from command line parameters, if a range was given */
	port=strtoul(argv[1],NULL,0);
	if (port<4096 || port>65499)
	{
		PIPE_Puts(info,"port has to be in the range 4096..65499");
		return 2;
	}
	
	if (tcp_open_listen_socket(&listen_fd,port))
	{
		PIPE_Printf(info,"Could not open Port %d for listening to new connections",port);
		return 3;
	}
	PIPE_Printf(info,"TCP/IP server ready on port %d",port);

	/* 
	   create data set for this invocation of the DLL and
	   store configuration data into it.
	*/
	localdata=(localDataP)malloc(sizeof(localDataT));
	localdata->listen_fd=listen_fd;
	localdata->connectionNum=0;
	for (i=0;i<MAX_CONNECTIONS;i++)
		localdata->connections[i].fd=INVALID_SOCKET;

	/* Register callbacks, use "data" as localdata for the callbacks */

	/* 
	 * Parameters for PIPE_RegisterCallback:
	 *  info     : Pointer to "pipeProtoInfo" structure
	 *  type     : Type of function to register
	 *  callback : Pointer to function which will be called.
	 *  flags    : optional flags (currently always 0).
	 */
	PIPE_RegisterCallback(info, PIPE_PROCESS_CALLBACK, process, localdata, 0);
	PIPE_RegisterCallback(info, PIPE_EXIT_CALLBACK   , exit_dll, localdata, 0);
	PIPE_RegisterCallback(info, PIPE_TASK_CALLBACK   , task,    localdata, 0);

	return 0;
}

