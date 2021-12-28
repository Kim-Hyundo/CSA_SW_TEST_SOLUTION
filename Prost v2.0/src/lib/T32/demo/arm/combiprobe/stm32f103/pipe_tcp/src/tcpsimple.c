#ifdef LINUX
#  include <netdb.h>
#  include <sys/socket.h>
#  include <string.h>
#  include <arpa/inet.h>
#  include <stdint.h>
#  include <unistd.h>
#  define INVALID_SOCKET -1
#  define SOCKET_ERROR -1
#  ifdef DEBUG
#    define LOG_PRINT(_xx) fprintf(stderr,"Function %s, Line %d, Error: %s\n", __PRETTY_FUNCTION__ , __LINE__ , _xx);
#  else
#    define LOG_PRINT(_xx)
#  endif
#endif

#ifdef MS_WINDOWS
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

#define GET_WORD_LE(value,ptr)  (value) = ((uint32_t)(((unsigned char *)(&(ptr)))[0]))|(((uint32_t)(((unsigned char *)(&(ptr)))[1]))<<8)
#define GET_DWORD_LE(value,ptr) (value) = ((uint32_t)(((unsigned char *)(&(ptr)))[0]))|(((uint32_t)(((unsigned char *)(&(ptr)))[1]))<<8)|(((uint32_t)(((unsigned char *)(&(ptr)))[2]))<<16)|(((uint32_t)(((unsigned char *)(&(ptr)))[3]))<<24)

#define SET_WORD_LE(ptr,value)   { ((unsigned char *)(&(ptr)))[0]= (unsigned char)((uint32_t)(value)); ((unsigned char *)(&(ptr)))[1]=(unsigned char)(((uint32_t)(value))>>8); }
#define SET_DWORD_LE(ptr,value)  { ((unsigned char *)(&(ptr)))[0]= (unsigned char)((uint32_t)(value)); ((unsigned char *)(&(ptr)))[1]=(unsigned char)(((uint32_t)(value))>>8); ((unsigned char *)(&(ptr)))[2]=(unsigned char)(((uint32_t)(value))>>16); ((unsigned char *)(&(ptr)))[3]=(unsigned char)(((uint32_t)(value))>>24); }

void tcp_init_msg(tcp_msg_p msg)
{
	msg->valid=0;
	msg->msg_type=-1;
	msg->msg_len=0;
	msg->msg = (msg->buf)+4;
	msg->buf_len=0;
}

int tcp_poll_msg(tcp_socket_t fd,tcp_msg_p msg)
{
	ssize_t ret;

	if (msg->valid)
		return 0;

	if (msg->msg_type<0)
	{
		/* receive header */
		ret = recv(fd,&(msg->buf[msg->buf_len]),4 - msg->buf_len,0);
		if (ret <= 0) return -1;
		msg->buf_len += ret;

		/* decode header */
		if (msg->buf_len == 4)
		{
			GET_WORD_LE(msg->msg_type,msg->buf[0]);
			GET_WORD_LE(msg->msg_len,msg->buf[2]);
			if (msg->msg_len > MAX_MSG_SIZE) return -1;
		}
	}
	if ( msg->msg_type>=0 )
	{
		/* receive message content */
		if ((msg->msg_len+4) > msg->buf_len)
		{
			ret = recv(fd,&(msg->buf[msg->buf_len]),msg->msg_len + 4 - msg->buf_len,0);
			if (ret <= 0) return -1;
			msg->buf_len+=ret;
		}
		if (msg->msg_len+4 <= msg->buf_len)
			msg->valid=1;
	}
	return 0;
}

int tcp_open_connection(tcp_socket_t *fd,char *hostname,unsigned short port)
{
	struct hostent *he;
	tcp_socket_t fd_int;
	struct sockaddr_in addr;    // remote Server IPv4 Adress und Port Struktur
	int ret;

	he = gethostbyname(hostname);  // hole Server IPv4 Adresse
	if (he==NULL)
	{
		LOG_PRINT("gethostbyname() failed");
		return -1;
	}

	fd_int = socket(AF_INET, SOCK_STREAM, 0); // Socket Filedeskriptor anlegen
	if (fd_int == INVALID_SOCKET)
	{
		LOG_PRINT("socket() failed");
		return -1;
	}

	memset(&addr, 0, sizeof(addr)); // remote mit 0 fuellen
	addr.sin_family = AF_INET;
	addr.sin_port = htons((unsigned short)port);
	addr.sin_addr = *((struct in_addr *) he->h_addr);

	// remote Server Verbindung aufbauen
	ret = connect(fd_int, (struct sockaddr *) &addr, sizeof(addr));
	if (ret == SOCKET_ERROR)
	{
		LOG_PRINT("connect() failed");
#ifdef MS_WINDOWS
		closesocket(fd_int);
#endif
#ifdef LINUX
		close(fd_int);
#endif
		return -1;
	}
	*fd=fd_int;
	return 0;
}

int tcp_close_socket(tcp_socket_t fd)
{
#ifdef MS_WINDOWS
	shutdown(fd,SD_BOTH);
	closesocket(fd);
#endif
#ifdef LINUX
	close(fd);
#endif
	return 0;
}

int tcp_send_msg(tcp_socket_t fd,tcp_msg_p msg)
{
	ssize_t ret;

	if (msg->msg_len<0 || msg->msg_len>MAX_MSG_SIZE)
	{
		msg->valid=0;
		return -1;
	}

	msg->valid=1;
	SET_WORD_LE(msg->buf[0],msg->msg_type);
	SET_WORD_LE(msg->buf[2],msg->msg_len);
	msg->buf_len=msg->msg_len+4;

	ret = send(fd,msg->buf,msg->buf_len,0);
	if (ret != (ssize_t)msg->buf_len)
		return -1;

	return 0;
}

static int tcp_get_block(tcp_socket_t fd,unsigned char *buf,int buf_len)
{
	ssize_t ll;
	while (buf_len>0)
	{
		ll=recv(fd, (char *)buf, buf_len,0);
		if (ll<=0)
			return -1;

		buf+=ll;
		buf_len-=ll;
	}
	return 0;
}

int tcp_recv_msg(tcp_socket_t fd,tcp_msg_p msg)
{
	int err;
	uint32_t type;
	uint32_t len;

	msg->valid=0;
	err=tcp_get_block(fd,msg->buf,4);
	if (err) return err;

	GET_WORD_LE(type,msg->buf[0]);
	GET_WORD_LE(len,msg->buf[2]);
	if (len>MAX_MSG_SIZE) return -1;

	err=tcp_get_block(fd,&(msg->buf[4]),len);
	if (err) return err;

	msg->msg_type=(int)type;
	msg->msg_len=(int)len;
	msg->valid=1;
	return 0;
}

int tcp_open_listen_socket(tcp_socket_t *fd,unsigned short port)
{
	tcp_socket_t listen_fd;
	int yes = 1;
	int  ret;                     /* Contains return value of functions. */
	struct sockaddr_in addrBind;  /* Address to bind to a port. */

	listen_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (listen_fd == INVALID_SOCKET)
		return -1;

	/* Avoid "Error Address already in use" error */
	ret = setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, (unsigned char *)(&yes), sizeof(yes));
	if (ret == SOCKET_ERROR)
	{
#ifdef MS_WINDOWS
		closesocket(listen_fd);
#endif
#ifdef LINUX
		close(listen_fd);
#endif
	return -1;
	}

	/* Initialize bind address */
	memset(&addrBind, 0, sizeof(addrBind));
	addrBind.sin_family = AF_INET;
	addrBind.sin_addr.s_addr = htonl(INADDR_ANY);
	addrBind.sin_port = htons(port);

	/* bind socket to port */
	ret = bind(listen_fd, (struct sockaddr *) &addrBind, sizeof(addrBind));
	if (ret == SOCKET_ERROR)
	{
#ifdef MS_WINDOWS
		closesocket(listen_fd);
#endif
#ifdef LINUX
		close(listen_fd);
#endif
	return -1;
	}

	ret = listen(listen_fd, 5);
	if (ret == SOCKET_ERROR)
	{
#ifdef MS_WINDOWS
		closesocket(listen_fd);
#endif
#ifdef LINUX
		close(listen_fd);
#endif
	return -1;
	}
	*fd=listen_fd;
	return 0;
}

int tcp_accept_connection(tcp_socket_t *fd,tcp_socket_t listen_fd)
{
	tcp_socket_t fd_l;

	fd_l = accept(listen_fd,NULL,NULL);
	if (fd_l == INVALID_SOCKET)
		return -1;
	*fd=fd_l;

	return 0;
}

