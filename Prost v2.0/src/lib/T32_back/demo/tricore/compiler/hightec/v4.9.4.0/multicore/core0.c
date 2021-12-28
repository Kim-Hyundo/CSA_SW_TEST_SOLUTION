
/************************************************************************
 *  Core 0
 */

#include "shared.h"
#include "histogram.h"

#include <math.h>

 /** the mixed waveform */
int mixed[SIZE];
 /** result of the classification */
SCLSResult result;

/** reference methods from crt0-tc39x.c */
extern void Start_Core(unsigned int coreId);


/** function intsin
 *  provides an integer valued sin function
 *  period of nValue: 2*pi*base
 *  output range +- nBase
 */
int intsin(int nValue)
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

void fill(int vec[],int nPeriod, int nOffset, int nMagnitude)
{
	int i;
	for(i=0;i < SIZE;++i)
	{
		vec[i] = nMagnitude*intsin(i*nPeriod+nOffset)/nBase;
	}
	/** write back cached data to ensure that other cores read the right values */
	int *pa = vec;
	for(i = 0; i < SIZE; i++) {
		pa = (int*)flush_cache_at((unsigned char*)pa);
	}
}



typedef struct {
	int nWeightA;
	int nWeightB;
} Smix_params;

const Smix_params mix_params = {100,100};

void mix(SInput* in) {
	int i;
	int wA = mix_params.nWeightA;
	int wB = mix_params.nWeightB;
	int s = wA+wB;
	for(i=0;i<SIZE;++i)
	{
		mixed[i] = (wA*in->a[i]+wB*in->b[i])/s;
	}
}

/** main function for core 0
 *
 */
int main(void)
{
	int nFillNow = 0;
	int k = 0;
	int nIxProcess;

	nProcessNext = 0;
	for(int i = 0; i < 6; i++) {
		nNowProcessing[i] = -1;
	}

	fill(inputBufs[0].a,32,k*3,1024*nBase);
	fill(inputBufs[0].b,64,k*5,1024*nBase);
	nProcessNext = 0;

	Start_Core(1);
	Start_Core(2);
	Start_Core(3);
	Start_Core(4);
	Start_Core(6);


	while(1)
	{
		nIxProcess = nProcessNext;
		nNowProcessing[0] = nIxProcess;
		mix(&inputBufs[nIxProcess]);
		CLS_classify(&result, mixed);

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
			for(int i=0; i < 6; i++){
				bAtLeastOneReading = bAtLeastOneReading || (nNowProcessing[i]==nFillNow);
			}
		}while(bAtLeastOneReading);

		/* 3. fill buffers */
		fill(inputBufs[nFillNow].a,32,k*3,1024*nBase);
		fill(inputBufs[nFillNow].b,64,k*5,1024*nBase);
		nProcessNext = nFillNow;
		k++;
	}
}