/*
 * LAUTERBACH waveform generation demo application
 *
 * This demo uses all three cores of the tricore.
 * 1. Core0 generates arrays with samples from sinusodial waveforms (inputA,inputB).
 * 2. Each core mixes inputA and inputB in a different way.
 * 3. Some statistics is done on the samples:
 *    a) sign, qualitative magnitude
 *    b) a histogram is created
 *
 * Last Changed: $LastChangedDate: $
 *  in Revision: $LastChangedRevision: $
 *           by: $LastChangedBy: $
 */

#include <math.h>

#include __SFRFILE__(__CPU__)

/** number of samples  */
#define SIZE 1024

/** number of bins in histogram */
#define BINCOUNT 16

/** base factor for scaling all values */
const int nBase = 1024;



/***********************************************************************
 *   input data
 *   the following data is triple buffered and shared among all cores
 */
#define INPUT_BUF_SETS 3
typedef struct {
	int a[SIZE];
	int b[SIZE];
} SInput;
SInput inputBufs[INPUT_BUF_SETS];

/* next buffer to process */
volatile int __far nProcessNext ;
/* last buffer processed by each core */
volatile int nNowProcessing[3];

/**************************************************************************
 *  Common classification functions
 */

typedef struct {
	unsigned int nAbsSmall;
	unsigned int nAbsAverage;
	unsigned int nAbsLarge;
	unsigned int nNeg;
	unsigned int nPos;
} SCLSResult;

/** function CLS_findAbsMax
 *  Finds the absolute maximum inside array TC_mixed.
 *  @return the found maximum value
 */
unsigned int CLS_findAbsMax(int* mixed)
{
	unsigned int nResult = 0;
	unsigned int i;
	for(i=0; i < SIZE;++i)
		nResult = __max(nResult,__abs(mixed[i]));
	return nResult;
}

/** function CLS_classifySmall
 *  Count value nValue as small by incrementing cAbsSmall.
 *  @param nValue the value to count.
 */
void CLS_classifySmall(SCLSResult* pResult, unsigned int nValue)
{
	pResult->nAbsSmall++;
}

/** function TC_classifyAverage
 *  Count value nValue as average by incrementing cAbsAverage.
 *  @param nValue the value to count.
 */
void CLS_classifyAverage(SCLSResult* pResult, unsigned int nValue)
{
	pResult->nAbsAverage++;
}

/** function TC_classifyLarge
 *  Count value nValue as large by incrementing cAbsLarge.
 *  @param nValue the value to count.
 */
void CLS_classifyLarge(SCLSResult* pResult, unsigned int nValue)
{
	pResult->nAbsLarge++;
}

/** function CLS_classifyAbs
 *  Classify positive value nValue into small, average or large with respect to absMax.
 *  @param nValue the value to classify
 *  @params nAbsMax value to take as reference (should be the largest possible value)
 */
void CLS_classifyAbs(SCLSResult* pResult, unsigned int nValue, unsigned int nAbsMax)
{
	if(nValue < nAbsMax/4)
		CLS_classifySmall(pResult, nValue);
	else if (nValue > 3*nAbsMax/4)
		CLS_classifyLarge(pResult, nValue);
	else
		CLS_classifyAverage(pResult, nValue);
}

/** function CLS_classifyNegValue
 *  Count value x as negative by incrementing cNeg;
 *  Further classify value x based on its absolute value.
 *  @param x the value to classify
 *  @param nAbsMax value to take as reference for further classification
 */
void CLS_classifyNegValue(SCLSResult* pResult, int nValue, unsigned int nAbsMax)
{
	pResult->nNeg++;
	CLS_classifyAbs(pResult, -nValue,nAbsMax);
}

/** function CLS_classifyPosValue
 *  Count value nValue as positive by incrementing cPos;
 *  Further classify value x based on its absolute value.
 *  @param nValue the value to classify
 *  @param nAbsMax value to take as reference for further classification
 */
void CLS_classifyPosValue(SCLSResult* pResult, int nValue, unsigned int nAbsMax)
{
	pResult->nPos++;
	CLS_classifyAbs(pResult, nValue,nAbsMax);
}

/** function CLS_classify
 *  Classifies the values in mixed with respect to sign and magnitude.
 *  The result is stored to pResult.
 */
void CLS_classify(SCLSResult* pResult, int* mixed)
{
	pResult->nAbsSmall = 0;
	pResult->nAbsAverage = 0;
	pResult->nAbsLarge = 0;
	pResult->nPos = 0;
	pResult->nNeg = 0;
	unsigned int nAbsMax = CLS_findAbsMax(mixed);
	for(int i = 0; i < SIZE; ++i)
	{
		int nValue = mixed[i];
		if(nValue >= 0)
			CLS_classifyPosValue(pResult, nValue,nAbsMax);
		else
			CLS_classifyNegValue(pResult, nValue,nAbsMax);
	}
}

/**************************************************************************
 *  Common histogram functions
 */

typedef struct {
	unsigned int bins[BINCOUNT];
} SHistogram;

/** function CLS_histogramFindBin
 *  Finds the appropriate bin when generating the histogram.
 *  This function is called recursively and finds the bin using a binary search.
 *  @param nValue the value for which the bin should be found
 *  @param nMinVal the lower bound of the currently considered interval
 *  @param nMaxVal the upper bound of the currently considered interval
 */
void HIST_findBin(SHistogram* pResult, int nValue, int nMinVal, int nMaxVal,int nMinIx,int nMaxIx)
{
	if(nMinIx >= nMaxIx)
	{
		pResult->bins[nMinIx]++;
		return;
	}
	int nMidVal = (nMinVal+nMaxVal)/2;
	int nMidIx = (nMinIx+nMaxIx)/2;
	if(nValue > nMidVal)
		HIST_findBin(pResult,nValue,nMidVal,nMaxVal,nMidIx+1,nMaxIx);
	else
		HIST_findBin(pResult,nValue,nMinVal,nMidVal,nMinIx,nMidIx);
}

/** function CLS_histogram
 *  Creates a histogram out of array CLS_mixed.
 */

void HIST_histogram(SHistogram* pResult,int* mixed)
{
	int i;
	for(i=0; i<BINCOUNT;++i)
		pResult->bins[i] = 0;

	int nAbsMax = CLS_findAbsMax(mixed);
	for(i=0; i < SIZE;++i)
		HIST_findBin(pResult, mixed[i],-nAbsMax,nAbsMax,0,BINCOUNT-1);
}

/************************************************************************
 *  Core 1
 */

 /** the mixed waveform */
int TC1_mixed[SIZE];

/** resulting histogramm */
SHistogram TC1_result;



void TC1_mix(SInput* in) {
	int i;
	for(i=0;i<SIZE;++i)
	{
		TC1_mixed[i] = __abs((in->a[i]+in->b[i])/2);
	}
}

int TC1_main() {
	int nIxProcess;
	while(1){
		nIxProcess = nProcessNext;
		nNowProcessing[1] = nIxProcess;
		TC1_mix(&inputBufs[nIxProcess]);
		HIST_histogram(&TC1_result, TC1_mixed);
	}
}

/************************************************************************
 *  Core 2
 */

 /** the mixed waveform */
int TC2_mixed[SIZE];

/** result of the classification */
SCLSResult TC2_result;



void TC2_mix(SInput* in) {
	int i;
	int nPreviousVal = 0;
	for(i=0;i<SIZE;++i)
	{
		int nNewVal = ((in->a[i]/nBase)*(in->b[i]/nBase)+nPreviousVal)/2;
		TC2_mixed[i] = nNewVal;
		nPreviousVal = nNewVal;
	}
}

int TC2_main() {
	int nIxProcess;
	while(1){
		nIxProcess = nProcessNext;
		nNowProcessing[2] = nIxProcess;
		TC2_mix(&inputBufs[nIxProcess]);
		CLS_classify(&TC2_result, TC2_mixed);
	}
}



/************************************************************************
 *  Core 0
 */

 /** the mixed waveform */
int TC0_mixed[SIZE];
 /** result of the classification */
SCLSResult TC0_result;

/** reference methods from cstart.c */
extern void _safety_endinit_clear(void);
extern void _safety_endinit_set(void);


void TC0_StartCore1() {
	extern void __noinline__ __noreturn__ __jump__ _start_tc1( void );
    CPU1_PC.U = (unsigned int)_start_tc1;
	_safety_endinit_clear();
	CPU1_SYSCON.B.BHALT = 0;
	_safety_endinit_set();
}

void TC0_StartCore2() {
	extern void __noinline__ __noreturn__ __jump__ _start_tc2( void );
    CPU2_PC.U = (unsigned int)_start_tc2;
	_safety_endinit_clear();
	CPU2_SYSCON.B.BHALT = 0;
	_safety_endinit_set();
}


/** function intsin
 *  provides an integer valued sin function
 *  period of nValue: 2*pi*base
 *  output range +- nBase
 */
int TC0_intsin(int nValue)
{
	float dValue = ((float)nValue)/nBase;
	int nResult = ((float)nBase)*sin(dValue);
	return nResult;
}

/** function fill
 *  Fills a vector with a sinus curve
 *  @param vec the vector to fill
 *  @param nPeriod   period of the sinus curve
 *  @param nOffset   offset to use
 *  @param nMagnitude   amplitude (is internally divided by nBase)
 */

void TC0_fill(int vec[],int nPeriod, int nOffset, int nMagnitude)
{
	int i;
	for(i=0;i < SIZE;++i)
	{
		vec[i] = nMagnitude*TC0_intsin(i*nPeriod+nOffset)/nBase;
	}
	/** write back cached data to ensure that other cores read the right values */
	int *pa = vec;
	for(int i = 0; i < SIZE; i++) {
		pa = (int*)__cacheawi_bo_post_inc((unsigned char*)pa);
	}
}



typedef struct {
	int nWeightA;
	int nWeightB;
} STC0_mix_params;

const STC0_mix_params TC0_mix_params = {100,100};

void TC0_mix(SInput* in) {
	int i;
	int wA = TC0_mix_params.nWeightA;
	int wB = TC0_mix_params.nWeightB;
	int s = wA+wB;
	for(i=0;i<SIZE;++i)
	{
		TC0_mixed[i] = (wA*in->a[i]+wB*in->b[i])/s;
	}
}

/** main function for core 0
 *
 */
int TC0_main(void)
{
	int nFillNow = 0;
	int k = 0;
	int nIxProcess;

	nProcessNext = 0;
	for(int i = 0; i < 3; i++) {
		nNowProcessing[i] = -1;
	}

	TC0_fill(inputBufs[0].a,32,k*3,1024*nBase);
	TC0_fill(inputBufs[0].b,64,k*5,1024*nBase);
	nProcessNext = 0;

	TC0_StartCore1();
	TC0_StartCore2();
	

	while(1)
	{
		nIxProcess = nProcessNext;
		nNowProcessing[0] = nIxProcess;
		TC0_mix(&inputBufs[nIxProcess]);
		CLS_classify(&TC0_result, TC0_mixed);

		/*** prepare for filling new buffer ***/
		/* 1. determine buffer to fill */
		nFillNow++;
		if(nFillNow>=INPUT_BUF_SETS) {
			nFillNow = 0;
		}

		/* 2. make sure no other core is currently reading from that buffer */
		int bAtLeastOneReading;
		do{
			bAtLeastOneReading = 0;
			for(int i=0; i < 3; i++){
				bAtLeastOneReading = bAtLeastOneReading || (nNowProcessing[i]==nFillNow);
			}
		}while(bAtLeastOneReading);

		/* 3. fill buffers */
		TC0_fill(inputBufs[nFillNow].a,32,k*3,1024*nBase);
		TC0_fill(inputBufs[nFillNow].b,64,k*5,1024*nBase);
		nProcessNext = nFillNow;
		k++;
	}
}

/**
 * main function
 */
int main(void)
{
	switch(__mfcr(CORE_ID)) {
		case 0: return TC0_main();
		case 1: return TC1_main();
		case 2: return TC2_main();
	}
}
