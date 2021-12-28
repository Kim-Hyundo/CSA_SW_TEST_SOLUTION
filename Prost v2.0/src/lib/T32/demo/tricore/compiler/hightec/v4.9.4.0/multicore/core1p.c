
/************************************************************************
 *  Core 1+
 */

#include "histogram.h"
#include "shared.h"

 /** the mixed waveform */
int mixed[SIZE];

/** resulting histogramm */
SHistogram result;


#if (COREID==1)
void mix(SInput* in) {
	int i;
	for(i=0;i<SIZE;++i)
	{
		mixed[i] = abs((in->a[i]+in->b[i])/2);
	}
}
#elif (COREID==2)
void mix(SInput* in) {
	int i;
	int nPreviousVal = 0;
	for(i=0;i<SIZE;++i)
	{
		int nNewVal = ((in->a[i]/nBase)*(in->b[i]/nBase)+nPreviousVal)/2;
		mixed[i] = nNewVal;
		nPreviousVal = nNewVal;
	}
}
#elif (COREID==3)
void mix(SInput* in) {
	int i;
	for(i=0;i<SIZE;++i)
	{
		mixed[i] = (in->a[i]-in->b[i]);
	}
}
#elif (COREID==4)
void mix(SInput* in) {
	int i;
	for(i=0;i<SIZE;++i)
	{
		mixed[i] = abs((in->a[i]-in->b[i]));
	}
}
#else
void mix(SInput* in) {
	int i;
	mixed[0] = (in->a[0]+in->b[0])/2;
	mixed[1] = (in->a[0]+in->b[0])/2;
	for(i=2;i<SIZE;++i)
	{
		mixed[i] = ((in->a[i]+in->b[i])+mixed[i-1]+mixed[i-2])/4;
	}
}
#endif

int main() {
	int nIxProcess;
	while(1){
		nIxProcess = nProcessNext;
		nNowProcessing[1] = nIxProcess;
		mix(&inputBufs[nIxProcess]);
		HIST_histogram(&result, mixed);
	}
}
