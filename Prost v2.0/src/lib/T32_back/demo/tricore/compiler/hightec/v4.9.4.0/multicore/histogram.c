
#include "histogram.h"
#include "shared.h"


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
