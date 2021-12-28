#ifndef _PIPEPROTO_INCLUDED
#define _PIPEPROTO_INCLUDED

#ifdef  __cplusplus
extern "C" {
#endif

#define PIPE_VERSION           8

/**************************************/
/** Types for PIPE_RegisterCallback  **/
/**************************************/
#define PIPE_PROCESS_CALLBACK       1
#define PIPE_EXIT_CALLBACK          2
#define PIPE_TASK_CALLBACK          3
#define PIPE_CMD_CALLBACK           4
#define PIPE_DISPLAYCUSTOM_CALLBACK 5

/***************************/
/** Types for PIPE_Log... **/
/***************************/
#define PIPE_LOG_TYPE_DUMMY        0x0
#define PIPE_LOG_TYPE_PROGRAM      0x1
#define PIPE_LOG_TYPE_READ         0x2
#define PIPE_LOG_TYPE_WRITE        0x3
#define PIPE_LOG_TYPE_STRING       0x4
/* Cycle or String will be produced by callback function  */
#define PIPE_LOG_TYPE_CUSTOMCYCLE  0x5
#define PIPE_LOG_TYPE_CUSTOMSTRING 0x6
/* Tell Calback function to produce string or cycle       */
#define PIPE_LOG_TYPE_CUSTOM       0x7

/* Bit flags for PIPE_LOG_TYPE_READ, PIPE_LOG_TYPE_WRITE */
#define PIPE_LOG_TYPE_WITHADDRESS  0x10000
#define PIPE_LOG_TYPE_WITHDATA     0x20000
/* Bit flags for PIPE_LOG_TYPE_READ, PIPE_LOG_TYPE_WRITE, PIPE_LOG_TYPE_PROGRAM */
#define PIPE_LOG_TYPE_WITHSPACEID  0x40000

/* Bit flags for PIPE_LOG_TYPE_STRING,PIPE_LOG_TYPE_CUSTOM */
/* Set this flag to log an entry to screen */
#define PIPE_LOG_TYPE_DISPLAY      0x80000

/* structure passed to custom display function */
typedef struct SPipeProtoCustomInfo
{
	int type;
	union {
		struct {
			int len;
			char *buf;
		} str;
		struct {
			unsigned int address;
			unsigned int spaceid;
			int           datasize;
			unsigned char data[8];
		} cycle;
	} content;
} SPipeProtoCustomInfo;

typedef struct SPipeProtoInfo SPipeProtoInfo;

/*
 * Register a callback function
 * Parameters
 *   info      : Pointer to SPipeProtoInfo structure. This pointer is a parameter to the PIPE_Interface function.
 *   type      : Type of callback to register
 *   callback  : Pointer to callback function
 *   localdata : Pointer to local data for this invocation of the DLL
 *   flags     : Bit flags. Currently not used
 * Return value
 * Returns 0 on success.
 */
int PIPE_RegisterCallback(SPipeProtoInfo *info,int type,void *callback,void *localdata,unsigned int flags );

/*
 * Print a string to the "Area" window.
 * Parameters
 *   info      : Pointer to SPipeProtoInfo structure. This pointer is a parameter to any callback function
 *   str       : Pointer to NUL terminated string, which will be output to "Area" window.
 */
void PIPE_Puts(SPipeProtoInfo *info,const char *str);

/*
 * Print a formatted string to the "Area" window.
 * Parameters
 *   info      : Pointer to SPipeProtoInfo structure. This pointer is a parameter to any callback function
 *   format    : Pointer to NUL terminated format string.
 *               Behaves like a usual "printf".
 *   ...       : Parameters to print as defined in the format string.
 */
void PIPE_Printf(SPipeProtoInfo *info,const char *format,... );

/*
 * Execute a Trace32 command.
 * Parameters
 *   info      : Pointer to SPipeProtoInfo structure. This pointer is a parameter to any callback function
 *   str       : Pointer to NUL terminated string, which contains Trace32 command.
 * Return value
 * Returns 0 on success. A value different from 0 means that the execution of the Trace32 produced an error.
 */
int PIPE_Command(SPipeProtoInfo *info,const char *str);

/*
 * Write data to CombiProbe UART. 
 * Parameters
 *   info      : Pointer to SPipeProtoInfo structure. This pointer is a parameter to any callback function
 *   buf       : Pointer to array which contains data to write to UART
 *   len       : length of data contained in "buf" array. "len" has to be >0 and <=8192.
 * Return value
 * Returns the number of bytes which were written.
 */
int PIPE_UartWrite(SPipeProtoInfo *info,const unsigned char * buf,int len);

/*
 * For CustomTraces: Log a Cycle in Trace32. 
 * Parameters
 *   info      : Pointer to SPipeProtoInfo structure. This pointer is a parameter to any callback function
 *   ts        : Pointer to array which contains timestamp as 8 bytes in little endian.
 *   cyc       : Description of cycle to be logged. 
 *               PIPE_LOG_TYPE_PROGRAM, PIPE_LOG_TYPE_READ, PIPE_LOG_TYPE_WRITE are allowed.
 *               READ and WRITE cycles may include address,data and spaceid.
 */
typedef struct SPipeProtoCycleInfo  /* Structure describing cycle to be logged */
{
	int type;               /* type of cycle + flags for included fields  */
	unsigned int address;   /* address of cycle                           */
	unsigned int spaceid;   /* spaceid of cycle                           */
	int datasize;           /* number of data bytes of cycle              */
	unsigned char data[8];  /* data transferred in cycle in little endian */
} SPipeProtoCycleInfo;
void PIPE_LogCycle(SPipeProtoInfo *info,const unsigned char * ts,const SPipeProtoCycleInfo *cyc);

/*
 * For CustomTraces: Log custom data to be decoded later. 
 * Parameters
 *   info      : Pointer to SPipeProtoInfo structure. This pointer is a parameter to any callback function
 *   ts        : Pointer to array which contains timestamp as 8 bytes in little endian.
 *   type      : PIPE_LOG_TYPE_CUSTOM,PIPE_LOG_TYPE_CUSTOMSTRING,PIPE_LOG_TYPE_CUSTOMCYCLE and PIPE_LOG_TYPE_STRING are allowed.
 *               CUSTOM types require that you registered a "PIPE_DISPLAYCUSTOM_CALLBACK" function to decode the custom data.
 *   buf       : Buffer which holds your custom data.
 *   len       : Number of bytes your custom data occupies.
 */
void PIPE_LogCustom(SPipeProtoInfo *info,const unsigned char * ts,int type,const unsigned char *buf,int len);

#ifdef  __cplusplus
}
#endif

#endif

