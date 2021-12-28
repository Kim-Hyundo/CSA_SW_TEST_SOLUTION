#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if defined(_MSC_VER)
#	include <windows.h>
	typedef          __int32 int32_t;
	typedef unsigned __int32 uint32_t;
	typedef          __int64 int64_t;
	typedef unsigned __int64 uint64_t;
#else
#	include <stdint.h>
#endif

#include "pipeproto.h"

/* 
   Data per DLL load
   
   The following structure is completely specific for your DLL.
   In this example the data for building one "printf" string is stored.
*/
typedef struct localData 
{
	unsigned char ts[8];     /* timestamp when string started */
	uint32_t h;              /* number of characters stored in wbuf */
	unsigned char wbuf[64];  /* buffer to build a string            */
} localDataT,*localDataP;


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
 *
 *  If buffer==NULL, then the Trace32 Software indicates,
 *  that all outstanding data should be flushed if possible.
 *  If ADDITIONALLY len==-1, then the processing should be re-initialized.
 */
static void process(SPipeProtoInfo *info,localDataP data,unsigned char *buffer,int len)
{
	if (buffer==NULL)
	{
		if (len==-1) 
		{
			PIPE_Puts(info,"viewprintf dll: re-initializing processing");
			data->h=0;
		}
		return;
	}
	if ( (buffer[8]&0x7) == DECITM_D32 && buffer[9]==0 ) 
	{   /* Only process D32 messages from channel 0*/

		uint32_t          h = data->h;
		unsigned char *wbuf = data->wbuf;
		int l;

		/* Start new string. Copy Timestamp of this message as timestamp for the string */
		if (h==0)
			memcpy(data->ts,buffer,8);

		/* Copy D32 message payload into local buffer */
		memcpy(&(wbuf[h]),buffer+10,4);   /* 32 bit little-endian payload data */
		h += 4; /* string is now 4 bytes longer */
		
		/* Check if string is finished by looking for "0" character */
		l=0;
		if (buffer[10]==0)
			l=h-4;
		else if (buffer[11]==0)
			l=h-3;
		else if (buffer[12]==0)
			l=h-2;
		else if (buffer[13]==0)
			l=h-1;

		/* limit string size to 43 (40+4-1) characters  */
		if (h>40)
			h=40;

		if (l>0) 
		{
			/* If the string ended (by a "0" character), log string and display in "ca.pproto.log" window */
			PIPE_LogCustom(info,data->ts,PIPE_LOG_TYPE_STRING|PIPE_LOG_TYPE_DISPLAY,wbuf,l);
			h=0;
		}
		data->h=h;
	}
}

/* called when DLL is unloaded
 * Parameters
 *  info   : Structure for calling functions inside T32
 *  data   : Pointer to structure which holds local data for this DLL.
 */
static void exitDll(SPipeProtoInfo *info,localDataP data)
{
	/* Free data, which was allocated int "PIPE_Interface" */
	free(data);
}

/* called when DLL is loaded 
 *
 * Parameters
 *  info   : Structure for calling functions inside T32
 *  argc   : numbers of parameters stored in "argv"
 *  argv   : array of pointers to "NULL" terminated command line parameters
 *
 * This function should allocate space to store local configuration data
 * for one DLL load.
 * It additionally should do all initialization which is necessary.
 */
int PIPE_Init(SPipeProtoInfo *info,int argc, char **argv)
{
	localDataP localdata;

	if (argc!=1)
	{
		PIPE_Puts(info,"usage: viewprintf");
		return 1;
	}
	/* 
	   create data set for this invocation of the DLL.
	*/
	localdata=(localDataP)malloc(sizeof(localDataT));
	localdata->h=0;

	/* Register callbacks, use "data" as localdata for the callbacks */

	/* 
	 * Parameters for PIPE_RegisterCallback:
	 *  info     : Pointer to "pipeProtoInfo" structure
	 *  type     : Type of function to register
	 *  callback : Pointer to function which will be called.
	 *  flags    : optional flags (currently always 0).
	 */
	PIPE_RegisterCallback(info, PIPE_PROCESS_CALLBACK, process, localdata, 0);
	PIPE_RegisterCallback(info, PIPE_EXIT_CALLBACK   , exitDll, localdata, 0);

	/*
	 * returning 0 means : "No Error"
	 */
	return 0;
}
