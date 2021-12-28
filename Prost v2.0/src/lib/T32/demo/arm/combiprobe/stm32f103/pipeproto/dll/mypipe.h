#ifdef LINUX
#  define mypipe_t int
#endif

#ifdef MS_WINDOWS
#  define mypipe_t HANDLE
#endif

extern int mypipe_create_read(mypipe_t *pipe,char *pipe_name,int wait);
extern int mypipe_open_write(mypipe_t *pipe,char *pipe_name);
extern void mypipe_close(mypipe_t pipe);

extern int mypipe_write(mypipe_t pipe,unsigned char *buf,int buf_len);
extern int mypipe_read(mypipe_t pipe,unsigned char *buf,int buf_size);

