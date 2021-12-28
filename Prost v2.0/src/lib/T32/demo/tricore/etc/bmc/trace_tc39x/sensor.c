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

#define FILL_IMPL_NO_FLUSH 0
#define FILL_IMPL_BLOCK_FLUSH 1
#define FILL_IMPL_PIPE_FLUSH 2

#ifndef FILL_IMPL
# define FILL_IMPL FILL_IMPL_BLOCK_FLUSH
#endif

#ifndef IMPL
# error "IMPL not set"
#endif

#ifndef DATA_LAYOUT
# error "DATA_LAYOUT not set"
#endif



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
volatile int nNowProcessing[6];

#define SENSOR_SAMPLES 256
#define SENSOR_COUNT 32
#define SENSOR_BUFS 2

typedef struct {
	float samples[SENSOR_SAMPLES];
} TSensorData;


#if DATA_LAYOUT == 0

TSensorData sensorData[SENSOR_COUNT][SENSOR_BUFS];

inline TSensorData* getSensorData(unsigned nSensor, unsigned nBuf) {
	return &sensorData[nSensor][nBuf];
}

#elif DATA_LAYOUT == 1

TSensorData sensorData[SENSOR_BUFS][SENSOR_COUNT];

inline TSensorData* getSensorData(unsigned nSensor, unsigned nBuf) {
	return &sensorData[nBuf][nSensor];
}

#else
# error "unknown value for DATA_LAYOUT"
#endif

/* next buffer to process */
volatile int __far nProcessNextSensor ;
/* last buffer processed by each core */
volatile int nNowProcessingSensor[6];


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

/** function HIST_findBin
 *  Finds the appropriate bin when generating the histogram.
 *  This function is called recursively and finds the bin using a binary search.
 *  @param nValue the value for which the bin should be found
 *  @param nMinVal the lower bound of the currently considered interval
 *  @param nMaxVal the upper bound of the currently considered interval
 */
static void HIST_findBin(SHistogram* pResult, int nValue, int nMinVal, int nMaxVal,int nMinIx,int nMaxIx)
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


/** function HIST_histogram
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

/** sensor group metrics */
#define SENSOR_GROUP_SIZE 4
#define SENSOR_GROUP_COUNT 4
#define SENSOR_GROUP_SPACING 4

typedef struct {
	float cor[SENSOR_GROUP_SIZE][SENSOR_GROUP_SIZE];
} TSensorGroupMetrics;

float TC1_sensorAvg[SENSOR_COUNT];
float TC1_sensorStdDev[SENSOR_COUNT];
TSensorGroupMetrics TC1_sensorGroupMetrics[SENSOR_GROUP_COUNT];

inline unsigned TC1_getSensorForGroup(unsigned nGroup, unsigned nIx)
{
	return nGroup + nIx*SENSOR_GROUP_SPACING;
}

inline unsigned TC1_getGroupForSensor(unsigned nId)
{
	if(nId < SENSOR_GROUP_COUNT*SENSOR_GROUP_SPACING) {
		return nId % SENSOR_GROUP_SPACING;
	}
	return ~0;
}

inline unsigned TC1_getGroupIndexForSensor(unsigned nId)
{
	return nId / SENSOR_GROUP_SPACING;
}

void TC1_mix(SInput* in) {
	int i;
	for(i=0;i<SIZE;++i)
	{
		TC1_mixed[i] = __abs((in->a[i]+in->b[i])/2);
	}
}

float getAverage(TSensorData* s)
{
	float nSum = 0;
	for(unsigned i = 0; i < SENSOR_SAMPLES; i++) {
		nSum += s->samples[i];
	}
	return nSum / SENSOR_SAMPLES;
}

float getStandardDeviation(TSensorData* s, float nAvg)
{
	float nSqSum = 0;
	for(unsigned i = 0; i < SENSOR_SAMPLES; i++) {
		nSqSum += s->samples[i]*s->samples[i];
	}
	float x = (nSqSum / SENSOR_SAMPLES - nAvg);
	x = sqrt(x);
	return x;
}

void getAverageAndStandardDeviation(TSensorData* s, float* pnRetAvg, float* pnRetStdDev)
{
	float nSum = 0;
	float nSqSum = 0;
	float a, b, c;
	a = s->samples[0];
	for(unsigned i = 0; i+2 < SENSOR_SAMPLES; i+=2) {
		b = s->samples[i+1];
		nSum += a;
		nSqSum += a*a;
		c = s->samples[i+2];
		nSum += b;
		nSqSum += b*b;
		a = c;
	}
	b = s->samples[SENSOR_SAMPLES - 1];
	nSum += a;
	nSqSum += a*a;
	nSum += b;
	nSqSum += b*b;

	float nAvg = nSum / SENSOR_SAMPLES;
	float x = (nSqSum / SENSOR_SAMPLES - nAvg);
	float nStdDev = sqrt(x);
	*pnRetAvg = nAvg;
	*pnRetStdDev = nStdDev;
}

float getCorrelationCoefficient(TSensorData* sensorA, float nSensorAAvg, float nSensorAStdDev, TSensorData* sensorB, float nSensorBAvg, float nSensorBStdDev)
{
	float nCrossSum = 0;
	for(unsigned i = 0; i < SENSOR_SAMPLES; i+=2) {
		nCrossSum += (sensorA->samples[i]*sensorB->samples[i]);
		nCrossSum += (sensorA->samples[i+1]*sensorB->samples[i+1]);
	}
	float r = (nCrossSum - SENSOR_SAMPLES*nSensorAAvg*nSensorBAvg)/((SENSOR_SAMPLES*nSensorAStdDev*nSensorBStdDev));
	return r;
}

#if IMPL == 0

void TC1_computeSensorMetrics(unsigned nBuf)
{
	for(unsigned i = 0; i < SENSOR_COUNT; i++) {
		TC1_sensorAvg[i] = getAverage(getSensorData(i,nBuf));
	}
	for(unsigned i = 0; i < SENSOR_COUNT; i++) {
		TC1_sensorStdDev[i] = getStandardDeviation(getSensorData(i,nBuf), TC1_sensorAvg[i]);
	}
	for(unsigned g = 0; g < SENSOR_GROUP_COUNT; g++) {
		TSensorGroupMetrics* pGm = &TC1_sensorGroupMetrics[g];
		for(unsigned i = 0; i < SENSOR_GROUP_SIZE; i++) {
			TSensorData* pDataI = getSensorData(TC1_getSensorForGroup(g,i), nBuf);
			for(unsigned j = 0; j < i; j++) {
				TSensorData* pDataJ = getSensorData(TC1_getSensorForGroup(g,j), nBuf);
				pGm->cor[i][j] = getCorrelationCoefficient(
						pDataI, TC1_sensorAvg[i], TC1_sensorStdDev[i],
						pDataJ, TC1_sensorAvg[j], TC1_sensorStdDev[j]
					);
				pGm->cor[j][i] = pGm->cor[i][j];
			}
			pGm->cor[i][i] = 1.0f;
		}
	}

}

#elif IMPL == 1

void TC1_computeSensorMetrics(unsigned nBuf)
{
	for(unsigned i = 0; i < SENSOR_COUNT; i++) {
		TSensorData* pDataI = getSensorData(i,nBuf);
		TC1_sensorAvg[i] = getAverage(pDataI);
		TC1_sensorStdDev[i] = getStandardDeviation(pDataI, TC1_sensorAvg[i]);

		unsigned g = TC1_getGroupForSensor(i);
		if(g == ~0) {
			continue;
		}
		unsigned gi = TC1_getGroupIndexForSensor(i);
		TSensorGroupMetrics* pGm = &TC1_sensorGroupMetrics[g];

		for(unsigned gj = 0; gj < gi; gj++) {
			unsigned j = TC1_getSensorForGroup(g, gj);
			TSensorData* pDataJ = getSensorData(j,nBuf);
			pGm->cor[gi][gj] = getCorrelationCoefficient(
					pDataI, TC1_sensorAvg[i], TC1_sensorStdDev[i],
					pDataJ, TC1_sensorAvg[j], TC1_sensorStdDev[j]
				);
			pGm->cor[gj][gi] = pGm->cor[gi][gj];
		}
		pGm->cor[gi][gi] = 1.0f;
	}
}

#elif IMPL == 2

void TC1_computeSensorMetrics(unsigned nBuf)
{
	for(unsigned i = 0; i < SENSOR_COUNT; i++) {
		TSensorData* pDataI = getSensorData(i,nBuf);
		getAverageAndStandardDeviation(pDataI, &TC1_sensorAvg[i], &TC1_sensorStdDev[i]);

		unsigned g = TC1_getGroupForSensor(i);
		if(g == ~0) {
			continue;
		}
		unsigned gi = TC1_getGroupIndexForSensor(i);
		TSensorGroupMetrics* pGm = &TC1_sensorGroupMetrics[g];

		for(unsigned gj = 0; gj < gi; gj++) {
			unsigned j = TC1_getSensorForGroup(g, gj);
			TSensorData* pDataJ = getSensorData(j,nBuf);
			pGm->cor[gi][gj] = getCorrelationCoefficient(
					pDataI, TC1_sensorAvg[i], TC1_sensorStdDev[i],
					pDataJ, TC1_sensorAvg[j], TC1_sensorStdDev[j]
				);
			pGm->cor[gj][gi] = pGm->cor[gi][gj];
		}
		pGm->cor[gi][gi] = 1.0f;
	}
}

#else
# error "Unknown value for IMPL"
#endif

int TC1_main() {
	int nIxProcess;
	while(1){
		nIxProcess = nProcessNext;
		nNowProcessing[1] = nIxProcess;
		TC1_mix(&inputBufs[nIxProcess]);
		HIST_histogram(&TC1_result, TC1_mixed);

		int nNextSensorBuf = (nNowProcessingSensor[1] + 1) % SENSOR_BUFS;
		while(nProcessNextSensor != nNextSensorBuf);
		nNowProcessingSensor[1] = nNextSensorBuf;
		TC1_computeSensorMetrics(nNextSensorBuf);
	}
}


/************************************************************************
 *  Core 0
 */

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

void TC0_getSensorData(unsigned nSensor, unsigned nBuf)
{
	static float fIteration = 0;
    /* mock up data */
    float* data = getSensorData(nSensor,nBuf)->samples;
	for(unsigned i=0;i < SENSOR_SAMPLES;++i)
	{
		data[i] = sin(i*23.0f + fIteration);
	}
	unsigned char *pa = (unsigned char *)data;
	for(int i = 0; i < SIZE; i++) {
		pa = __cacheawi_bo_post_inc(pa);
	}
    fIteration += 1.0f;
}


/** main function for core 0
 *
 */
int TC0_main(void)
{
	int nFillNow = 0;
	int k = 0;
	int nNextSensorRead = 0;

	nProcessNext = 0;
	nProcessNextSensor = -1;
	for(int i = 0; i < 6; i++) {
		nNowProcessing[i] = -1;
		nNowProcessingSensor[i] = -1;
	}

	TC0_fill(inputBufs[0].a,32,k*3,1024*nBase);
	TC0_fill(inputBufs[0].b,64,k*5,1024*nBase);
	nProcessNext = 0;

	TC0_StartCore1();


	while(1)
	{
		for(unsigned i = 0; i < SENSOR_COUNT; i++) {
			TC0_getSensorData(i, nNextSensorRead);
		}
		nProcessNextSensor = nNextSensorRead;
		nNextSensorRead++;
		if(nNextSensorRead >= SENSOR_BUFS) {
			nNextSensorRead = 0;
		}

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
	}
}
