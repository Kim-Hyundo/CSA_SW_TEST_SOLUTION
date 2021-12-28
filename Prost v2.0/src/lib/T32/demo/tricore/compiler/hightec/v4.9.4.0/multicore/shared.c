

#include "shared.h"

SInput inputBufs[INPUT_BUF_SETS];

/* next buffer to process */
volatile int nProcessNext ;
/* last buffer processed by each core */
volatile int nNowProcessing[6];

/** function CLS_findAbsMax
 *  Finds the absolute maximum inside array TC_mixed.
 *  @return the found maximum value
 */
unsigned int CLS_findAbsMax(int* mixed)
{
	unsigned int nResult = 0;
	unsigned int i;
	for(i=0; i < SIZE;++i)
		nResult = max(nResult,abs(mixed[i]));
	return nResult;
}

/** function CLS_classifySmall
 *  Count value nValue as small by incrementing cAbsSmall.
 *  @param nValue the value to count.
 */
static void CLS_classifySmall(SCLSResult* pResult, unsigned int nValue)
{
	pResult->nAbsSmall++;
}

/** function TC_classifyAverage
 *  Count value nValue as average by incrementing cAbsAverage.
 *  @param nValue the value to count.
 */
static void CLS_classifyAverage(SCLSResult* pResult, unsigned int nValue)
{
	pResult->nAbsAverage++;
}

/** function TC_classifyLarge
 *  Count value nValue as large by incrementing cAbsLarge.
 *  @param nValue the value to count.
 */
static void CLS_classifyLarge(SCLSResult* pResult, unsigned int nValue)
{
	pResult->nAbsLarge++;
}

/** function CLS_classifyAbs
 *  Classify positive value nValue into small, average or large with respect to absMax.
 *  @param nValue the value to classify
 *  @params nAbsMax value to take as reference (should be the largest possible value)
 */
static void CLS_classifyAbs(SCLSResult* pResult, unsigned int nValue, unsigned int nAbsMax)
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
static void CLS_classifyNegValue(SCLSResult* pResult, int nValue, unsigned int nAbsMax)
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
static void CLS_classifyPosValue(SCLSResult* pResult, int nValue, unsigned int nAbsMax)
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