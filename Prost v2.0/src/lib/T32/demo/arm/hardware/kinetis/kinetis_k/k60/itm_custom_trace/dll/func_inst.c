#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "pipeproto.h"

/* Data per DLL load */

/*
   Type definitions for ITM data
*/
#define DECITM_D8   1
#define DECITM_D16  2
#define DECITM_D32  3

/* Processing function
 *
 * The following function will be called, each time a STP message is decoded 
 * 
 * Parameters
 *  info   : Structure for calling functions inside T32
 *  data   : Pointer to structure which holds local data for this DLL.
 *  buffer : Pointer to byte buffer which holds STP message
 *  len    : Length of byte buffer which holds STP message.
 */
static void process(SPipeProtoInfo *info,void * data,unsigned char *buffer,int len)
{
	if (buffer==NULL)
		return;
	if ( (buffer[8]&0x7) == DECITM_D32 && buffer[9]==5 ) /* Only process D32 messages on channel 5*/
	{
		SPipeProtoCycleInfo cyc;
		cyc.type=PIPE_LOG_TYPE_PROGRAM;
		cyc.address=*((unsigned int *)(buffer+10));
		PIPE_LogCycle(info,buffer,&cyc);
	}
}

/* called when DLL is loaded 
 *
 * Parameters
 *  info   : Structure for calling functions inside T32
 *  argc   : numbers of parameters stored in "argv"
 *  argv   : array of pointers to "NUL" terminated command line parameters
 *
 * This function should allocate space to store local configuration data
 * for one DLL load.
 * It additionally should do all initialization which is necessary.
 */
int PIPE_Init(SPipeProtoInfo *info,int argc, char **argv)
{
	if (argc!=1)
	{
		PIPE_Puts(info,"usage: pproto3");
		return 1;
	}
	/* 
	 * Parameters for PIPE_RegisterCallback:
	 *  info     : Pointer to "SPipeProtoInfo" structure
	 *  type     : Type of function to register
	 *  callback : Pointer to function which will be called.
	 *  flags    : optional flags (currently always 0).
	 */
	PIPE_RegisterCallback(info, PIPE_PROCESS_CALLBACK, process, NULL, 0);

	return 0;
}
