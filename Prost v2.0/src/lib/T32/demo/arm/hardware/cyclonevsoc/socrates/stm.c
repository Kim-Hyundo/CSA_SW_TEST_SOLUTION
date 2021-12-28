#include <stdint.h>

void* STM_StimulusBase = (void*)0xfc000000;

enum {
  STP_G_DMTS = 0x00,  /* Data, marked with timestamp, guaranteed */
  STP_G_DM   = 0x08,  /* Data, marked,                guaranteed */
  STP_G_DTS  = 0x10,  /* Data,        with timestamp, guaranteed */
  STP_G_D    = 0x18,  /* Data,                        guaranteed */
  STP_I_DMTS = 0x80,  /* Data, marked with timestamp             */
  STP_I_DM   = 0x88,  /* Data, marked,                           */
  STP_I_DTS  = 0x90,  /* Data,        with timestamp             */
  STP_I_D    = 0x98   /* Data,                                   */
} eStimulusType;


#define STP_TRACE_D8( channel,stimuliport,type,data)   ((*(volatile unsigned char  *)((STM_StimulusBase)+0x1000*(channel)+(stimuliport)*0x100+(type)))=(unsigned char )(data))
#define STP_TRACE_D16(channel,stimuliport,type,data)   ((*(volatile unsigned short *)((STM_StimulusBase)+0x1000*(channel)+(stimuliport)*0x100+(type)))=(unsigned short)(data))
#define STP_TRACE_D32(channel,stimuliport,type,data)   ((*(volatile unsigned long  *)((STM_StimulusBase)+0x1000*(channel)+(stimuliport)*0x100+(type)))=(unsigned long )(data))



extern signed short int plot1, plot2;

void STM_StmMessages(void)
{
	STP_TRACE_D16(0, 1, STP_G_DTS, plot1);
	STP_TRACE_D16(0, 2, STP_G_DTS, plot2);
}

