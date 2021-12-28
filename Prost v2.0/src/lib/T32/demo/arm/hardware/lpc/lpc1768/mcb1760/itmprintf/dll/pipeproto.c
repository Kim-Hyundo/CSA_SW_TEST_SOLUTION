#define _CRT_SECURE_NO_WARNINGS 1
#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#if defined(_MSC_VER)
	typedef          __int32 int32_t;
	typedef unsigned __int32 uint32_t;
	typedef          __int64 int64_t;
	typedef unsigned __int64 uint64_t;
#else
#	include <stdint.h>
#endif
#include "pipeproto.h"

struct SPipeProtoInfo {
	int version;
	int number;

	/* The following TRACE32 GUI functions can be called by the DLL. */
	int (*registerCallback)(SPipeProtoInfo *info,int type,void *callback,void *localdata,unsigned int flags);
	void (*puts)(SPipeProtoInfo *info, const char *str);
	int (*command)(SPipeProtoInfo *info, const char *str);
	int (*uartWrite)(SPipeProtoInfo *info,const unsigned char * buf,int len);
	void (*log)(SPipeProtoInfo *info,const unsigned char * ts,int type,const unsigned char *buf,int len);

	void *array; /* internal parameters */
	void *file;
};

extern int PIPE_Init(SPipeProtoInfo *info, int argc, char **argv);

int PIPE_Interface(SPipeProtoInfo *info, int argc, char **argv)
{
	if (info->version < PIPE_VERSION)
	{
		info->puts(info,"Library is too new to be used with this Trace32 software. Aborting load!");
		return 128;
	}

	info->version = PIPE_VERSION;
	return PIPE_Init(info,argc,argv);
}

int PIPE_RegisterCallback(SPipeProtoInfo *info,int type,void *callback,void *localdata,unsigned int flags)
{
	return info->registerCallback(info,type,callback,localdata,flags);
}

void PIPE_Puts(SPipeProtoInfo *info,const char *str)
{
	info->puts(info,str);
}

void PIPE_Printf(SPipeProtoInfo *info,const char *format,... )
{
	char line[4096];
	va_list ap;

	va_start(ap, format);
	vsnprintf(line,4000,format,ap);
	va_end(ap);
	info->puts(info,line);
}

int PIPE_Command(SPipeProtoInfo *info,const char *str)
{
	return info->command(info,str);
}

int PIPE_UartWrite(SPipeProtoInfo *info,const unsigned char * buf,int len)
{
	return info->uartWrite(info,buf,len);
}

void PIPE_LogCycle(SPipeProtoInfo *info,const unsigned char * ts,const SPipeProtoCycleInfo *cyc)
{
	unsigned char buf[32],*b;
	int len;
	int type;
	type=cyc->type;
	len=0;
	b=buf;
	if ((type&PIPE_LOG_TYPE_WITHADDRESS)||((type&0xFFFF)==PIPE_LOG_TYPE_PROGRAM))
	{
		unsigned int address;
		address=cyc->address;
		b[0]=(unsigned char)address;address>>=8;
		b[1]=(unsigned char)address;address>>=8;
		b[2]=(unsigned char)address;address>>=8;
		b[3]=(unsigned char)address;
		len+=4;
		b+=4;
	}
	if (type&PIPE_LOG_TYPE_WITHSPACEID)
	{
		unsigned int spaceid;
		spaceid=cyc->spaceid;
		b[0]=(unsigned char)spaceid;spaceid>>=8;
		b[1]=(unsigned char)spaceid;
		len+=2;
		b+=2;
	}
	if (type&PIPE_LOG_TYPE_WITHDATA)
	{
		int datasize;
		datasize=cyc->datasize;
		if (datasize<1||datasize>8)
			type&= (~PIPE_LOG_TYPE_WITHDATA);
		else
		{
			b[0]=(unsigned char)datasize;
			memcpy(b+1,cyc->data,datasize);
			len++;
			len+=datasize;
		}
	}
	info->log(info,ts,type,buf,len);
}

/* Use for String and Custom trace entries*/
void PIPE_LogCustom(SPipeProtoInfo *info,const unsigned char * ts,int type,const unsigned char *buf,int len)
{
	info->log(info,ts,type,buf,len);
}
