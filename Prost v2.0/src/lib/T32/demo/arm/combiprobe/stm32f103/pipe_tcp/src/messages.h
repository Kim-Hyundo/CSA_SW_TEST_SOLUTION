/* messages to server */
#define SERVER_PIPE_OPEN  1
#define SERVER_PIPE_CLOSE 2
#define SERVER_UART_WRITE 3

/* messages to client */
#define CLIENT_STATUS 1
/* result of CLIENT_STATUS */
#  define STATUS_OK 0
#  define STATUS_ERROR 1
#  define STATUS_UNKNOWN_MESSAGE 2
