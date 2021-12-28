#ifdef MS_WINDOWS
#  define _CRT_SECURE_NO_WARNINGS 1
#  include <windows.h>
#endif

#ifdef LINUX
#   include <stdint.h>
#   include <stdlib.h>
#   include <string.h>
#   define INVALID_HANDLE_VALUE -1
#endif

#include <stdio.h>
#include "pipeproto.h"
#include "mypipe.h"

/* Data per DLL load */

/* The following structure is completely specific for your DLL.
   In this example several things are stored: 
*/
typedef struct localData 
{
	/* Handle to pipe to which data is written */
	mypipe_t handle;
	
	/* Range of ChannelIDs, which should be processed */
	unsigned int  from,to;

	/* Buffer for data which should be written to DLL */
	unsigned int h;
	unsigned char wbuf[8100];
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
 */
static void process(SPipeProtoInfo *info,localDataP data,unsigned char *buffer,int len)
{
	if (buffer==NULL)
	{
		/* 
		   If the processing function is called with an empty buffer,
		   it is an indication, that the data should be flushed
		*/
		if (data->handle != INVALID_HANDLE_VALUE)
			mypipe_write(data->handle,data->wbuf,data->h);
		data->h=0;
	}        
	else if ( (buffer[8]&0x7) == DECITM_D32 ) /* Only process D32 messages */
	{ 
		unsigned int      h = data->h;
		unsigned char *wbuf = data->wbuf;
		unsigned int     ch = buffer[9];  // ChannelID
		
		/* Only process data, if the channel is in the appropriate range */
		if (ch<data->from || ch>data->to)
			return;

		/* Store channel and payload into local buffer */
		wbuf[h]  = (unsigned char)ch;
		wbuf[h+1]= buffer[10];       /* 32 bit little-endian payload data */
		wbuf[h+2]= buffer[11];
		wbuf[h+3]= buffer[12];
		wbuf[h+4]= buffer[13];
		h += 5;

		/* flush buffer to pipe if we have collected at least 8000 bytes */
		if (h >= 8000)
		{
			if (data->handle != INVALID_HANDLE_VALUE)
				mypipe_write(data->handle,wbuf,h);
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
	mypipe_t handle;
	handle = data->handle;

	/* close pipe */
	if (handle!=INVALID_HANDLE_VALUE)
		mypipe_close(handle);

	/* Free data, which was allocated int "PIPE_Interface" */
	free(data);
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
	mypipe_t handle;
	char pipeName[256];
	localDataP localdata;
	unsigned int from,to;

	handle=INVALID_HANDLE_VALUE;
	if (argc!=2 && argc!=4)
	{
		PIPE_Puts(info,"usage: pproto <pipeName> [ <from channel> <to channel> ]");
		return 1;
	}
#ifdef MS_WINDOWS 
	/* extract pipe name from command line parameters */
	sprintf(pipeName,"//./pipe/%s",argv[1]);
#endif

#ifdef LINUX
	/* extract pipe name from command line parameters */
	sprintf(pipeName,"/tmp/%s",argv[1]);
#endif

	/* extract range from command line parameters, if a range was given */
	from=0;
	to=255;
	if (argc==4)
	{
		from=strtoul(argv[2],NULL,0);
		to=strtoul(argv[3],NULL,0);
	}

	/*
	   Open PIPE for writing data to it
	*/
	if (mypipe_open_write(&handle,pipeName))
	{
		PIPE_Printf(info,"Can not open %s for writing",pipeName);
		return 2;
	}
	else
		PIPE_Printf(info,"Opened pipe %s",pipeName);

	/* 
	   create data set for this invocation of the DLL and
	   store configuration data into it.
	*/
	localdata=(localDataP)malloc(sizeof(localDataT));
	localdata->handle=handle;
	localdata->from=from;
	localdata->to=to;
	localdata->h=0;

	/* Register callbacks, use "data" as localdata for the callbacks */

	/* 
	 * Parameters for PIPE_RegisterCallback:
	 *  info     : Pointer to "SPipeProtoInfo" structure
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
