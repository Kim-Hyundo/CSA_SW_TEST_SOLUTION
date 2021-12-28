// ITM demo for S32V234 with ITM channel 0 - 3

#define TRUE  1
#define FALSE 0
#define NULL  0x0
#define STR_SIZE 512

void* pStimulusBase = NULL;
volatile unsigned int* pITMBase = NULL;

// Byte, Long, Quad stimulus is not supported: Channel width is 32-bit only
char  bLongStimulusEnable = 0;
char  bAlternateStimulusEnable = 0;

char            pPrintfString[4][STR_SIZE] = {0};           // Each STM channel has its own string
unsigned int    nLongStimulus = 0;

#define STP_TRACE_D32(_pitmbase_, _channel_, _data_)   ((*(volatile unsigned int   *)(_pitmbase_+ 0x4 * _channel_))=(unsigned int  )(_data_))
#define STP_WAIT_CHX(_pitmbase_, _channel_) {while ((*(volatile unsigned int   *)(_pitmbase_ + 0x4 * _channel_)) != 1);}
void vTransferHook()
{
	asm("nop");
}

void itmPrint(unsigned long nChannel, char * pString)
{
	if (pString[STR_SIZE - 1] != 0)        // String must be zero terminated in order to work!
		return;

	if (pString[0]) {
		do {
			STP_WAIT_CHX(pStimulusBase, nChannel);
			STP_TRACE_D32(pStimulusBase, nChannel, *pString);
		} while (pString++[0]);
	}
}

void(*monHook)(void) __attribute__((section(".data"))) = 0;
extern void(*watchdogTrigger)(void);

int main()
{
	unsigned int nChannel = 0;

	if (pITMBase == 0)
		while(1);                       // Safe fallback if ITM base is not defined
	else
		*(pITMBase + 0x1) = 0x5;        // Map ITM registers by setting PDBGPAGE[S9_DBG_PAGE]=0x5 (S5);

	while (TRUE) {
		vTransferHook();

		if (monHook)
			monHook();
		if (watchdogTrigger)
			watchdogTrigger();

		for (nChannel = 0; nChannel < 4; nChannel++) {
			if (pStimulusBase == NULL)
				continue;               // Safe fallback if stimulus base is not defined

			if (pPrintfString[nChannel][0] != 0x0) {
				itmPrint(nChannel, pPrintfString[nChannel]);
			}

			if (bLongStimulusEnable) {
				STP_WAIT_CHX(pStimulusBase, nChannel);
				STP_TRACE_D32(pStimulusBase, nChannel, nLongStimulus);
			}
		}

		if (bAlternateStimulusEnable) {
			if (bLongStimulusEnable) nLongStimulus = ~nLongStimulus;
		}
	}
}
