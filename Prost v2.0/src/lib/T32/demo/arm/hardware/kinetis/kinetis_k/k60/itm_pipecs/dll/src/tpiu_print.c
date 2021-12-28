

#if defined(__linux__)
#	include <stdio.h>
#	include <string.h>
#	include <stdlib.h>
#else
#	define _CRT_SECURE_NO_WARNINGS 1
#	include <stdio.h>
#	include <string.h>
#	include <windows.h>
#endif

#include "pipecsproto.h"

/*
	ITM
*/
struct spaceForItm {
	uint32_t foundTime;
	uint32_t start;
	uint32_t end;
	FILE *fp;
};


/*
 * The space we need for the whole DLL is a concatenation of all
 * the space defined above
 */
struct mySpacePerDll {
	struct spaceForItm     spItm;
};

enum {
	DECITM_D8  = 0x1,
	DECITM_D16 = 0x2,
	DECITM_D32 = 0x3,
};

#define DECITM_TYPE(msg0)    ((msg0)&0xFF)
#define DECITM_CHANNEL(msg0) (((msg0)>>8)&0xFF)


/********** Callback which will be called for ITM ATB source ***********************/
/*
	ITM decoded format :
	msg[0]:
		bit  7..0 type (see above),
		bit 15..8 channel
	msg[1]: data
*/
static void processItm(SPipeCSProtoInfo *info,void *localdata,int atbid,uint32_t *msg)
{
	struct spaceForItm *space = (struct spaceForItm *)localdata;
	if (msg==NULL) {
		/* FLUSH or INIT request */
		int rq=atbid>>16;
		atbid&=0xFFFF;
		if (rq==0) {
			if (space->fp)
				fflush(space->fp);
		} else if (rq==1) {
			// Init Request;
			space->start=0;
			space->end=0;
		} else {
			// unknown request
			;
		}
		return;
	}

	switch(DECITM_TYPE(msg[0])) {
	case DECITM_D8:
		switch(DECITM_CHANNEL(msg[0])) {
		case 2: {
			static const char *sortName[] = {
				"bubblesort", // 1
				"quicksort",  // 2
				"heapsort",   // 3
				"shellsort",  // 4
				"mergesort",  // 5
				"mergesort2", // 6
				"isort",      // 7
				"selsort",    // 8
				"rdxsort",    // 9
				"rdxsort2",   // 10
				"bitonic"     // 11
			};
			uint32_t rt;
			uint32_t sortIdx;
			sortIdx=msg[1];
			if (sortIdx==0 || sortIdx>11 || space->fp==NULL)
				break;
			sortIdx--;
			if (space->foundTime == 2) {
				// down counter so we need to subtract end time FROM start time
				rt = space->start - space->end;
				rt*=4;
				rt+=75;
				rt/=150;
				fprintf(space->fp,"%s, %d us\n",sortName[sortIdx],rt);
			}
			else {
				fprintf(space->fp,"%s\n",sortName[sortIdx]);
			}
			space->foundTime = 0;
			break;
		}
		default:
			;
		}
		break;
	case DECITM_D32:
		switch(DECITM_CHANNEL(msg[0])) {
		case 1:
			space->foundTime++;
			space->start=space->end;
			space->end=msg[1];
			break;
		case 3:
			if (space->fp==NULL)
				break;
			fprintf(space->fp,"bs 0x%08x\n",msg[1]);
			break;
		case 4:
			if (space->fp==NULL)
				break;
			fprintf(space->fp,"qs 0x%08x\n",msg[1]);
			break;
		case 5:
			if (space->fp==NULL)
				break;
			fprintf(space->fp,"hs 0x%08x\n",msg[1]);
			break;
		default:
			;
		}
		break;
	default:
		;
	}
}

/******************************************************************/
/* Callback which is called when DLL unloads. Clean up everything */
/******************************************************************/
static void exitDll(SPipeCSProtoInfo *info,void *localdata)
{
	struct mySpacePerDll *space = (struct mySpacePerDll *)localdata;

	/* here you should close all connections to other stuff */
	if (space->spItm.fp) {
		fclose(space->spItm.fp);
	}

	/* this callback should free the allocated space */
	if (space)
		free(space);
	PIPECS_PutsArea(info,NULL,"tpiu_print unloading");
}

static void executeCmd(SPipeCSProtoInfo *info,void *localdata, int argc, char **argv)
{
	struct mySpacePerDll *space = (struct mySpacePerDll *)localdata;

	if (argc<1) {
		PIPECS_PrintfArea(info,NULL,"Usage: <name>.command <command> <options>");
		PIPECS_PrintfArea(info,NULL,"  Available commands:");
		PIPECS_PrintfArea(info,NULL,"    itmopen <filename>");
	}
	if (strcmp(argv[0],"itmopen")==0) {
		if (argc<2) {
			PIPECS_PrintfArea(info,NULL,"Usage: <name>.command itmopen <filename>");
			return;
		}
		if (space->spItm.fp) {
			fclose(space->spItm.fp);
		}
		space->spItm.fp=fopen(argv[1],"wb");
		if (space->spItm.fp == NULL) {
			PIPECS_PrintfArea(info,NULL,"Could not open %s",argv[1]);
			return;
		}
		PIPECS_PrintfArea(info,NULL,"Opened %s for writing",argv[1]);
	}
	else {
		PIPECS_PrintfArea(info,NULL,"unknown command %s",argv[0]);
	}
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
int PIPECS_Init(SPipeCSProtoInfo *info, int argc, char **argv)
{
	struct mySpacePerDll *space;
	int i;
	for (i=0;i<argc;i++) {
		PIPECS_PrintfArea(info,NULL,"tpiu_print: param %d == %s",i,argv[i]);
	}

	space = (struct mySpacePerDll *)malloc(sizeof(struct mySpacePerDll));
	if (!space) {
		PIPECS_PrintfArea(info,NULL,"tpiu_print: Could not malloc space");
		return 1;
	}
	memset(space,0,sizeof(struct mySpacePerDll));

	/*
		Register Callback to receive data from TraceSource with ATBID 5,
		Decode as ITM data
	*/
	PIPECS_RegisterCallback(info,PIPECS_CALLBACK_PROCESS_ITM(5),processItm,&(space->spItm));

	/*
		Register Callback, which is called when this dll is unloaded
	*/
	PIPECS_RegisterCallback(info,PIPECS_CALLBACK_EXIT,exitDll,space);

	/*
		Register Callback, which is called when this dll is unloaded
	*/
	PIPECS_RegisterCallback(info,PIPECS_CALLBACK_CMD,executeCmd,space);
	return 0;
}
