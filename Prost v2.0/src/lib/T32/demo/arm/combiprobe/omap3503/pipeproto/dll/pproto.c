#ifdef MS_WINDOWS
#  define _CRT_SECURE_NO_WARNINGS 1
#  include <windows.h>
#endif

#ifdef LINUX
#   include <stdint.h>
#   include <stdlib.h>
#   include <string.h>
#   define INVALID_HANDLE_VALUE -1
#   define DWORD unsigned int
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
	/* Handle to pipe to which data is written to. */
	mypipe_t handle;
	
	/* Range of ChannelIDs, which should be processed */
	DWORD from,to;

	/* Buffer for data which is recevied by the DLL */
	DWORD h;
	unsigned char wbuf[8100];
} localDataT,*localDataP;


/*
   Type definitions for XTIv2/SDTI data
*/
#define DECXTI_TYPE_IOREAD   0x01
#define DECXTI_TYPE_IOWRITE  0x02
#define DECXTI_TYPE_IOOVF    0x03
#define DECXTI_TYPE_DSP      0x04
#define DECXTI_TYPE_MCU      0x05
#define DECXTI_TYPE_CPU2     0x05
#define DECXTI_TYPE_CPU1     0x06

#define DECXTI_TYPE_WITH_TS  0x10
#define DECXTI_TYPE_ERROR    0xFF

/* 
Values are always in little-endian (least significant byte first).
Data is structured in this way:

Byte offset  Meaning

0x00--0x07 : 64 Bit Absolute TimeStamp
             Scale 0x100 = 20 ns.
             Example: 0x12345678 equals 
                      0x12345678 / 0x100 * 20 ns = 23860929,375 ns

      0x08 : Bit 3-0 Type (see above)
             Bit 4   With Timestamp Flag.
                     If set XTI Message contained a timestamp.

      0x09 : Bit 3-0 : Data Size 0 : 8 Bit, 1 : 16 Bit, 2 : 32 Bit
             For IOREAD, IOWRITE (NOKIA XTI-v2) only:
                 Bit 7-4 : MASTER
                           0 : MCU
                           1 : DSP 
                           2 : DMA 
                           3 : Other

For DSP,MCU/CPU2,CPU1 Messages:
      0x0A : Channel
      0x0B...  : Data (8,16 or 32 Bit)
      
For IOREAD, IOWRITE Messages:
      0x0A--0xD : Address 32 bit
      0x0E      : Data (8,16 or 32 Bit)
*/

/* Processing function
 *
 * The following function will be called, each time a XTIv2/SDTI message is decoded 
 * 
 * Parameters
 *  info   : Structure for calling functions inside T32 software.
 *  data   : Pointer to structure which holds local data for this DLL.
 *  buffer : Pointer to byte buffer which holds STP message.
 *  len    : Length of byte buffer which holds STP message.
 */
static void process(pipeProtoInfo *info,localDataP data,unsigned char *buffer,int len)
{
	if (buffer==NULL)
	{
		/* 
		   If the processing function is called with an empty buffer,
		   it is an indication, that the data should be flushed
		*/
		mypipe_write(data->handle,data->wbuf,data->h);
		data->h=0;
	}
	else if ( (buffer[8]&0xF) == DECXTI_TYPE_CPU1 && (buffer[9]&0xF)==2 ) 
	{ 
		/* Only process 32bit messages from CPU1 */
		DWORD             h = data->h;
		unsigned char *wbuf = data->wbuf;
		unsigned int     ch = buffer[10];  // ChannelID

		/* Only process data, if the channel is in the appropriate range */
		if (ch<data->from || ch>data->to)
			return;

		/* Store channel and payload into local buffer */
		wbuf[h]  = (unsigned char)ch;

		wbuf[h+1]= buffer[11];       /* 32 bit little-endian payload data */
		wbuf[h+2]= buffer[12];
		wbuf[h+3]= buffer[13];
		wbuf[h+4]= buffer[14];
		h += 5;

		/* flush buffer to pipe if we have collected at least 8000 bytes */
		if (h >= 8000)
		{
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
static void exitDll(pipeProtoInfo *info,localDataP data)
{
	mypipe_t handle;
	handle = data->handle;

	/* close pipe */
	if (handle!=INVALID_HANDLE_VALUE)
		mypipe_close(handle);

	/* Free data, which was allocated in "PIPE_Interface" */
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
int PIPE_Init(pipeProtoInfo *info,int argc, char **argv)
{
	mypipe_t handle;
	char pipeName[256];
	localDataP localdata;
	DWORD from,to;

	handle=INVALID_HANDLE_VALUE;
	if (argc!=2 && argc!=4)
	{
		PIPE_Puts(info,"usage: pproto <pipeName> [ <from channel> <to channel> ]");
		return 1;
	}
	/* extract pipe name from command line parameters */
#ifdef MS_WINDOWS
	sprintf_s(pipeName,250,"//./pipe/%s",argv[1]);
#endif

#ifdef LINUX
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
		PIPE_Printf(info,"Can not open %s",pipeName);
		return 2;
	}
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
	 *  info     : Pointer to "pipeProtoInfo" structure
	 *  type     : Type of function to register
	 *  callback : Pointer to function which will be called.
	 *  flags    : optional flags (currently always 0).
	 */
	PIPE_RegisterCallback(info, PIPE_PROCESS_CALLBACK, process, localdata, 0);
	PIPE_RegisterCallback(info, PIPE_EXIT_CALLBACK   , exitDll, localdata, 0);

	return 0;
}
