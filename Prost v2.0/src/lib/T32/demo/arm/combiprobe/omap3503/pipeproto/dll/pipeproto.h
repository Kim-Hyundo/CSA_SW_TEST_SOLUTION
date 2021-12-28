#ifndef _PIPEPROTO_INCLUDED
#define _PIPEPROTO_INCLUDED

#ifdef  __cplusplus
extern "C" {
#endif

#define PIPE_VERSION           1

#define PIPE_PROCESS_CALLBACK  1
#define PIPE_EXIT_CALLBACK     2

typedef struct pipeProtoInfo pipeProtoInfo;

/*
 * Register a callback function
 * Parameters
 *   info      : Pointer to pipeProtoInfo structure. This pointer is a parameter to the PIPE_Interface function.
 *   type      : Type of callback to register
 *   callback  : Pointer to callback function
 *   localdata : Pointer to local data for this invocation of the DLL
 *   flags     : Bit flags. Currently not used
 */
void PIPE_RegisterCallback(pipeProtoInfo *info,int type,void *callback,void *localdata,unsigned int flags );

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

#ifdef  __cplusplus
}
#endif

#endif
