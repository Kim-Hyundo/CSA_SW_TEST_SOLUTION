#ifndef _PIPEPROTO_INCLUDED
#define _PIPEPROTO_INCLUDED

#ifdef  __cplusplus
extern "C" {
#endif

#define PIPE_VERSION           4

#define PIPE_PROCESS_CALLBACK  1
#define PIPE_EXIT_CALLBACK     2
#define PIPE_TASK_CALLBACK     3

typedef struct pipeProtoInfo pipeProtoInfo;

/*
 * Register a callback function
 * Parameters
 *   info      : Pointer to pipeProtoInfo structure. This pointer is a parameter to the PIPE_Interface function.
 *   type      : Type of callback to register
 *   callback  : Pointer to callback function
 *   localdata : Pointer to local data for this invocation of the DLL
 *   flags     : Bit flags. Currently not used
 * Return value
 * Returns 0 on success.
 */
int PIPE_RegisterCallback(pipeProtoInfo *info,int type,void *callback,void *localdata,unsigned int flags );

/*
 * Print a string to the "Area" window.
 * Parameters
 *   info      : Pointer to pipeProtoInfo structure. This pointer is a parameter to any callback function
 *   str       : Pointer to NUL terminated string, which will be output to "Area" window.
 */
void PIPE_Puts(pipeProtoInfo *info,const char *str);

/*
 * Print a formatted string to the "Area" window.
 * Parameters
 *   info      : Pointer to pipeProtoInfo structure. This pointer is a parameter to any callback function
 *   format    : Pointer to NUL terminated format string.
 *               Behaves like a usual "printf".
 *   ...       : Parameters to print as defined in the format string.
 */
void PIPE_Printf(pipeProtoInfo *info,const char *format,... );

/*
 * Execute a Trace32 command.
 * Parameters
 *   info      : Pointer to pipeProtoInfo structure. This pointer is a parameter to any callback function
 *   str       : Pointer to NUL terminated string, which contains Trace32 command.
 * Return value
 * Returns 0 on success. A value different from 0 means that the execution of the Trace32 produced an error.
 */
int PIPE_Command(pipeProtoInfo *info,const char *str);

/*
 * Write data to CombiProbe UART. 
 * Parameters
 *   info      : Pointer to pipeProtoInfo structure. This pointer is a parameter to any callback function
 *   buf       : Pointer to array which contains data to write to UART
 *   len       : length of data contained in "buf" array. "len" has to be >0 and <=8192.
 * Return value
 * Returns the number of bytes which were written.
 */
int PIPE_UartWrite(pipeProtoInfo *info,const unsigned char * buf,int len);

#ifdef  __cplusplus
}
#endif

#endif

