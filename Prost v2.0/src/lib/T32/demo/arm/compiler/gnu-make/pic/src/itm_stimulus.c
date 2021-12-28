
#define TRUE  1
#define FALSE 0
#define NULL  0x0

void* pStimulusBase = NULL;
int   mcount        = 0;

char  bByteStimulusEnable      = 0;
char  bWordStimulusEnable      = 0;
char  bLongStimulusEnable      = 0;
char  bQuadStimulusEnable      = 0;
char  bAlternateStimulusEnable = 0;

char            pPrintfString[512] = {0,};
unsigned char   nByteStimulus = 0;
unsigned short  nWordStimulus = 0;
unsigned int    nLongStimulus = 0;
unsigned long   nQuadStimulus = 0;

#define ITM_TRACE_BYTE(_pstimport_,_data_)      ((*(volatile unsigned char *)_pstimport_)=(_data_))
#define ITM_TRACE_SHORT(_pstimport_,_data_)     ((*(volatile unsigned short *)_pstimport_)=(_data_))
#define ITM_TRACE_LONG(_pstimport_,_data_)      ((*(volatile unsigned long *) _pstimport_)=(_data_))
#define ITM_WAIT_FOR_CHANNEL_READY(_pstimport_) while(*((volatile unsigned long*)_pstimport_)==0)

void (*monHook)(void) __attribute__ ((section (".data"))) = 0;
extern void (*watchdogTrigger)(void);

void vTransferHook()
{
  asm("nop");
}

void itmPrint(void* pStimulus, char * pString)
{
  int i;
  unsigned long tmp;
  while (*pString) {
    tmp=0;
    // pack multiple bytes into one unsigned long
    for (i=0; i<4; i++) {
      if (*pString) {
        tmp |= ((*pString)<<(i*8));
        pString++;
      }
    }
    ITM_WAIT_FOR_CHANNEL_READY(pStimulus);
    ITM_TRACE_LONG(pStimulus, tmp);
  }
  // send a zero as delimiter
  ITM_WAIT_FOR_CHANNEL_READY(pStimulus);
  ITM_TRACE_LONG(pStimulus, 0x0);
}

int main()
{
  int i;

  while(TRUE)
  {
    vTransferHook();
    
    if (monHook)
      monHook();
    if (watchdogTrigger)
      watchdogTrigger();
    
    if (pPrintfString[0]!=0x0) {
      itmPrint(pStimulusBase, pPrintfString);
    }
    
    if (bByteStimulusEnable) {
      ITM_WAIT_FOR_CHANNEL_READY(pStimulusBase);
      ITM_TRACE_BYTE(pStimulusBase, nByteStimulus);
    }
    if (bWordStimulusEnable) {
      ITM_WAIT_FOR_CHANNEL_READY(pStimulusBase);
      ITM_TRACE_SHORT(pStimulusBase, nWordStimulus);
    }
    if (bLongStimulusEnable) {
      ITM_WAIT_FOR_CHANNEL_READY(pStimulusBase);
      ITM_TRACE_LONG(pStimulusBase, nLongStimulus);
    }
    
    if (bAlternateStimulusEnable) {
      if (bByteStimulusEnable) nByteStimulus = ~nByteStimulus;
      if (bWordStimulusEnable) nWordStimulus = ~nWordStimulus;
      if (bLongStimulusEnable) nLongStimulus = ~nLongStimulus;
    }
    
    for (i=0; i<500000; i++);
  }
}

