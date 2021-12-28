
#ifdef LINUX
#  include <sys/types.h>
#  include <sys/stat.h>
#  include <unistd.h>
#  include <fcntl.h>
#endif
#ifdef MS_WINDOWS
#  include <windows.h>
#endif

#include "mypipe.h"

#ifdef LINUX
int mypipe_create_read(mypipe_t *pipe,char *pipe_name)
{
	int accmode;
	mypipe_t p;
	/* Create a named pipe for reading data from it */
	mkfifo(pipe_name,0660);
	/* open pipe (without waiting for connection) */
	p=open(pipe_name,O_RDONLY|O_NONBLOCK);
	if (p<0) return -1;

	/* Now remove "O_NONBLOCK" from fifo */
	accmode = fcntl(p, F_GETFL);
	accmode &= ~O_NONBLOCK;
	fcntl(p, F_SETFL, accmode);
	*pipe=p;
	return 0;
}

int mypipe_open_write(mypipe_t *pipe,char *pipe_name)
{
	int accmode;
	mypipe_t p;
	/* open Named Pipe for writing */
	p=open(pipe_name,O_WRONLY|O_NONBLOCK);
	if (p<0) return -1;

	/* Get rid of O_NONBLOCK after opening fifo, to ensure that data is NOT lost */
	accmode = fcntl(p, F_GETFL, 0);
	accmode &= ~O_NONBLOCK;
	fcntl(p,F_SETFL,accmode);
	*pipe=p;
	return 0;
}

void mypipe_close(mypipe_t pipe)
{
	close(pipe);
}

int mypipe_write(mypipe_t pipe,unsigned char *buf,int buf_len)
{
	if (write(pipe,buf,(size_t)buf_len)<0)
		return -1;
	return 0;
}

int mypipe_read(mypipe_t pipe,unsigned char *buf,int buf_size)
{
	return ((int)read(pipe,buf,buf_size));
}

#endif

#ifdef MS_WINDOWS
int mypipe_create_read(mypipe_t *pipe,char *pipe_name)
{
	mypipe_t p;
	p=CreateNamedPipe(pipe_name,PIPE_ACCESS_INBOUND,PIPE_TYPE_BYTE,16,8192,8192,0,0);
	if (p==INVALID_HANDLE_VALUE) return -1;
	*pipe=p;

	return 0;
}

int mypipe_open_write(mypipe_t *pipe,char *pipe_name)
{
	mypipe_t p;
	/* open Named Pipe for writing */
	p=CreateFile(pipe_name,GENERIC_WRITE,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
	if (p==INVALID_HANDLE_VALUE) return -1;
	*pipe=p;

	return 0;
}

void mypipe_close(mypipe_t pipe)
{
	CloseHandle(pipe);
}

int mypipe_write(mypipe_t pipe,unsigned char *buf,int buf_len)
{
	DWORD i;
	if (!WriteFile(pipe,buf,(DWORD)buf_len,&i,NULL))
		return -1;
	return 0;
}

int mypipe_read(mypipe_t pipe,unsigned char *buf,int buf_size)
{
	DWORD r;
	if (!ReadFile(pipe,buf,(DWORD)buf_size,&r,NULL))
		return 0;
	return r;
}

#endif

