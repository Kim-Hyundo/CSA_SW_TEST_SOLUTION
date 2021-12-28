#include <sys/types.h>
#include <sys/stat.h>
#include <sys/signal.h>
#include <errno.h>

#undef errno
extern int errno;


static char gOutBuf[256];


int _close(int __fildes)
{
	return -1;
}


int _fstat( int __fd, struct stat *__sbuf )
{
	__sbuf->st_mode = S_IFCHR; /* character special device */
	return 0;
}


pid_t _getpid(void)
{
	return 1;
}


int _isatty(int __fildes )
{
	return 1; /* IS a terminal */
}


int _kill(pid_t __pid, int __signal)
{
	errno = EINVAL;
	return -1;
}


_off_t _lseek(int __fildes, _off_t __offset, int __whence )
{
	return 0;
}


int _read(int __fd, void *__buf, size_t __nbyte)
{
	return 0;
}


caddr_t _sbrk(ptrdiff_t __incr)
{
	extern char __heap_start[]; /* Defined by the linker */
	static caddr_t heap_end = NULL;
	caddr_t prev_heap_end;

	if (heap_end == NULL) {
		heap_end = (caddr_t)__heap_start;
	}
	prev_heap_end = heap_end;
	heap_end += __incr;
	return prev_heap_end;
}


int _write(int __fd, const char *__buf, size_t __nbyte )
{
	static int outidx = 0;
	size_t i;

	for (i = 0; i < __nbyte; i++) {
		gOutBuf[outidx % sizeof(gOutBuf)] = __buf[i];
		outidx++;
	}
	return __nbyte;
}


/*******************************************************/

void *__dso_handle = 0;

/*
__value_in_regs ulldiv_t __aeabi_uldivmod( unsigned long long n, unsigned long long d)
ulldiv_t __aeabi_uldivmod( unsigned long long n, unsigned long long d)
{
	return 0;
}

unsigned __aeabi_uidiv(unsigned numerator, unsigned denominator)
{
	return 0;
}
*/

