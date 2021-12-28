/*
 * LAUTERBACH waveform generation demo application
 *
 * This demo uses all three cores of the tricore.
 * 1. Core0 generates arrays with samples from sinusodial waveforms (inputA,inputB).
 * 2. Each core mixes inputA and inputB in a differnt way.
 * 3. Some statistics is done on the samples:
 *    a) sign, qualitative magnitude
 *    b) a histogram is created
 *
 * Last Changed: $LastChangedDate: 2018-05-29 13:46:55 +0200 (Tue, 29 May 2018) $
 *  in Revision: $LastChangedRevision: 12661 $
 *           by: $LastChangedBy: meick $
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
 * the following data is shared among all cores
 */

/** Arrays for two sinusodial waveforms. */
int __share inputA[SIZE];
int __share inputB[SIZE];

typedef union {
	int w;
	struct {
		int Core0Writing : 1;
		int Core1Reading : 1;
		int Core2Reading : 1;
	} b;
} flags_t;

/** integer field to hold status flags in uncached memory */
volatile flags_t __share nFlagsUncached ;

/***********************************************************************
 * the following data is cloned, i.e., each instance holds its own copy
 */

/** the mixed waveform */
int __clone mixed[SIZE];

/** counters for classification */
unsigned int __clone nAbsSmall,nAbsAverage,nAbsLarge,nNeg,nPos;

/** counters for each bin of the histogram */
unsigned int __clone bins[BINCOUNT];

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
}


/** function mix0
 *  Mix inputA and inputB by taking the average.
 *  Store result to cloned variable mixed.
 */
void mix0()
{
	int i;
	for(i=0;i<SIZE;++i)
	{
		mixed[i] = (inputA[i]+inputB[i])/2;
	}
}

/** function mix1
 *  Mix inputA and inputB by taking the absolute value of the average.
 *  Store result to cloned variable mixed.
 */
void mix1()
{
	int i;
	for(i=0;i<SIZE;++i)
	{
		mixed[i] = __abs((inputA[i]+inputB[i])/2);
	}
}

/** function mix2
 *  Mix inputA and inputB by multiplication.
 *  Store result to cloned variable mixed.
 */
void mix2()
{
	int i;
	int nPreviousVal = 0;
	for(i=0;i<SIZE;++i)
	{
		int nNewVal = ((inputA[i]/nBase)*(inputB[i]/nBase)+nPreviousVal)/2;
		mixed[i] = nNewVal;
		nPreviousVal = nNewVal;
	}
}

/** function findAbsMax
 *  Finds the absolute maximum inside array mixed.
 *  @return the found maximum value
 */
unsigned int findAbsMax()
{
	unsigned int nResult = 0;
	unsigned int i;
	for(i=0; i < SIZE;++i)
		nResult = __max(nResult,__abs(mixed[i]));
	return nResult;
}

/** function classifySmall
 *  Count value nValue as small by incrementing cAbsSmall.
 *  @param nValue the value to count.
 */
void classifySmall(unsigned int nValue)
{
	nAbsSmall++;
}

/** function classifyAverage
 *  Count value nValue as average by incrementing cAbsAverage.
 *  @param nValue the value to count.
 */
void classifyAverage(unsigned int nValue)
{
	nAbsAverage++;
}

/** function classifyLarge
 *  Count value nValue as large by incrementing cAbsLarge.
 *  @param nValue the value to count.
 */
void classifyLarge(unsigned int nValue)
{
	nAbsLarge++;
}

/** function classifyAbs
 *  Classify positive value nValue into small, average or large with respect to absMax.
 *  @param nValue the value to classify
 *  @params nAbsMax value to take as reference (should be the largest possible value)
 */
void classifyAbs(unsigned int nValue, unsigned int nAbsMax)
{
	if(nValue < nAbsMax/4)
		classifySmall(nValue);
	else if (nValue > 3*nAbsMax/4)
		classifyLarge(nValue);
	else
		classifyAverage(nValue);
}

/** function classifyNegValue
 *  Count value x as negative by incrementing cNeg;
 *  Further classify value x based on its absolute value.
 *  @param x the value to classify
 *  @param nAbsMax value to take as reference for further classification
 */
void classifyNegValue(int nValue, unsigned int nAbsMax)
{
	nNeg++;
	classifyAbs(-nValue,nAbsMax);
}

/** function classifyPosValue
 *  Count value nValue as positive by incrementing cPos;
 *  Further classify value x based on its absolute value.
 *  @param nValue the value to classify
 *  @param nAbsMax value to take as reference for further classification
 */
void classifyPosValue(int nValue, unsigned int nAbsMax)
{
	nPos++;
	classifyAbs(nValue,nAbsMax);
}

/** function classify
 *  Classifies the values in mixed with respect to sign and magnitude.
 *  The result can be found in cAbsSmall, cAbsAverage, cAbsLarge, cPos and cNeg.
 */
void classify()
{
	nAbsSmall = 0;
	nAbsAverage = 0;
	nAbsLarge = 0;
	nPos = 0;
	nNeg = 0;
	unsigned int nAbsMax = findAbsMax();
	for(int i = 0; i < SIZE; ++i)
	{
		int nValue = mixed[i];
		if(nValue >= 0)
			classifyPosValue(nValue,nAbsMax);
		else
			classifyNegValue(nValue,nAbsMax);
	}
}

/** function histogramFindBin
 *  Finds the appropriate bin when generating the histogram.
 *  This function is called recursively and finds the bin using a binary search.
 *  @param nValue the value for which the bin should be found
 *  @param nMinVal the lower bound of the currently considered interval
 *  @param nMaxVal the upper bound of the currently considered interval
 */
void histogramFindBin(int nValue, int nMinVal, int nMaxVal,int nMinIx,int nMaxIx)
{
	if(nMinIx >= nMaxIx)
	{
		bins[nMinIx]++;
		return;
	}
	int nMidVal = (nMinVal+nMaxVal)/2;
	int nMidIx = (nMinIx+nMaxIx)/2;
	if(nValue > nMidVal)
		histogramFindBin(nValue,nMidVal,nMaxVal,nMidIx+1,nMaxIx);
	else
		histogramFindBin(nValue,nMinVal,nMidVal,nMinIx,nMidIx);
}

/** function histogram
 *  Creates a histogram out of array mixed.
 */

void histogram()
{
	int i;
	for(i=0; i<BINCOUNT;++i)
		bins[i] = 0;

	int nAbsMax = findAbsMax();
	for(i=0; i < SIZE;++i)
		histogramFindBin(mixed[i],-nAbsMax,nAbsMax,0,BINCOUNT-1);
}

/** function analyze
 *  Perform several analyses for the values of array mixed.
 */

void analyze()
{
	classify();
	histogram();
}

/** main function for core 0
 *
 */
int main0(void)
{
	nFlagsUncached.b.Core0Writing = 0;
	nFlagsUncached.b.Core1Reading = 0;
	
	int k = 0;
	while(1)
	{
		
		while(nFlagsUncached.b.Core1Reading);
		
		nFlagsUncached.b.Core0Writing = 1;
		fill(inputA,32,k*3,1024*nBase);
		fill(inputB,64,k*5,1024*nBase);
		nFlagsUncached.b.Core0Writing = 0;
		k++;
		mix0();
		analyze();
	}
}

/** main function for core 1
 *
 */
int main1(void)
{
	while(1)
	{
		while(nFlagsUncached.b.Core0Writing);
		nFlagsUncached.b.Core1Reading = 1;
		mix1();
		nFlagsUncached.b.Core1Reading = 0;
		
		analyze();
	}
}



/**
 * main function
 */
int main(void)
{
	switch(__mfcr(CORE_ID)) {
		case 0: return main0();
		case 1: return main1();
		
	}
}