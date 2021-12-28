
#ifndef _HISTOGRAM_H_
#define _HISTOGRAM_H_

/**************************************************************************
 *  Common histogram functions
 */
 
#if (COREID==0)||(COREID==2)||(COREID==4)
# define BINCOUNT 16
#else
# define BINCOUNT 32
#endif

typedef struct {
	unsigned int bins[BINCOUNT];
} SHistogram;

void HIST_histogram(SHistogram* pResult,int* mixed);

#endif
