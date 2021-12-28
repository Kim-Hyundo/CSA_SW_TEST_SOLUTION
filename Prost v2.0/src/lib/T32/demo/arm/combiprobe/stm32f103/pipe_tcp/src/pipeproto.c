#include <stdarg.h>
#include <stdio.h>
#include "pipeproto.h"

struct pipeProtoInfo {
    int version;
    int number;
    int (*registerCallback)(pipeProtoInfo *info,int type,void *callback,void *localdata,unsigned int flags);
    void (*puts)(pipeProtoInfo *info, const char *str);
    int (*command)(pipeProtoInfo *info, const char *str);
    int (*uartWrite)(pipeProtoInfo *info,const unsigned char * buf,int len);
};

extern int PIPE_Init(pipeProtoInfo *info, int argc, char **argv);

int PIPE_Interface(pipeProtoInfo *info, int argc, char **argv)
{
    if (info->version < PIPE_VERSION)
    {
	info->puts(info,"Library is too new to be used with this Trace32 software. Aborting load!");
	return 128;
    }

    info->version = PIPE_VERSION;
    return PIPE_Init(info,argc,argv);
}

int PIPE_RegisterCallback(pipeProtoInfo *info,int type,void *callback,void *localdata,unsigned int flags)
{
    return info->registerCallback(info,type,callback,localdata,flags);
}

void PIPE_Puts(pipeProtoInfo *info,const char *str)
{
    info->puts(info,str);
}

void PIPE_Printf(pipeProtoInfo *info,const char *format,... )
{
    char line[4096];
    va_list         ap;

    va_start(ap, format);
    vsnprintf(line,4000,format,ap);
    va_end(ap);
    info->puts(info,line);
}

int PIPE_Command(pipeProtoInfo *info,const char *str)
{
    return info->command(info,str);
}

int PIPE_UartWrite(pipeProtoInfo *info,const unsigned char * buf,int len)
{
    return info->uartWrite(info,buf,len);
}

