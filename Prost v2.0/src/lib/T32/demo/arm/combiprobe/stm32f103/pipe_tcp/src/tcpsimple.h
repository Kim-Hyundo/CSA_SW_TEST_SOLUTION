/* maximum size of message payload */
#define MAX_MSG_SIZE    8192

#ifdef MS_WINDOWS
#define tcp_socket_t SOCKET
#endif

#ifdef LINUX
#define tcp_socket_t int
#endif

#if !defined(tcp_socket_t)
#define tcp_socket_t int
#endif

/* for a TCP server, open a listen socket */
extern int tcp_open_listen_socket(tcp_socket_t *fd,unsigned short port);


/* for a TCP server, accept an incoming connection */
extern int tcp_accept_connection(tcp_socket_t *fd,tcp_socket_t listen_fd);

/* for a TCP client, open a connection to a server */
extern int tcp_open_connection(tcp_socket_t *fd,char *hostname,uint16_t port);

/* close a socket */
extern int tcp_close_socket(tcp_socket_t fd);

/* message structure which is used to communicate */
typedef struct tcp_msg
{
	int valid; /* true if message is valid */

	int msg_type;       /* message type */
	int msg_len;        /* length of payload */
	unsigned char *msg; /* payload */

	/* internal data to build message buffer */
	int buf_len;
	unsigned char buf[MAX_MSG_SIZE+16];
} tcp_msg_t,*tcp_msg_p;
/* initialize a message structure */
extern void tcp_init_msg(tcp_msg_p msg);

/* send, receive and poll for message */
extern int tcp_send_msg(tcp_socket_t fd,tcp_msg_p msg);
extern int tcp_recv_msg(tcp_socket_t fd,tcp_msg_p msg);
extern int tcp_poll_msg(tcp_socket_t fd,tcp_msg_p msg);
