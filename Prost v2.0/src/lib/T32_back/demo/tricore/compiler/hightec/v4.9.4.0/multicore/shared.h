#ifndef _SHARED_H_
#define _SHARED_H_

/** number of samples  */
#define SIZE 1024

/** base factor for scaling all values */
static const int nBase = 1024;

#define max(a,b) ((a<b)?a:b)
#define abs(a) ((a>=0)?a:-a)

/***********************************************************************
 *   input data
 *   the following data is triple buffered and shared among all cores
 */
#define INPUT_BUF_SETS 3
typedef struct {
	int a[SIZE];
	int b[SIZE];
} SInput;
extern SInput inputBufs[INPUT_BUF_SETS];

/* next buffer to process */
extern volatile int nProcessNext ;
/* last buffer processed by each core */
extern volatile int nNowProcessing[6];

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

/** function CLS_classify
 *  Classifies the values in mixed with respect to sign and magnitude.
 *  The result is stored to pResult.
 */
void CLS_classify(SCLSResult* pResult, int* mixed);


/** function CLS_findAbsMax
 *  Finds the absolute maximum inside array TC_mixed.
 *  @return the found maximum value
 */
unsigned int CLS_findAbsMax(int* mixed);


inline void* flush_cache_at(void* p) {
	__asm__ ("cachea.wi [%1+]0x20"
			: "+a" (p));
	return p;
}

#endif