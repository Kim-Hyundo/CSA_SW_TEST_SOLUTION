/* ----------------------------------------------------------------------- 
   Draw Test Programm for TriCore
   drawing mathematical waveforms sin, cos, exp
   - 32 bit
   - double precision

   $LastChangedDate: 2010-01-15 10:06:39 +0100 (Fri, 15 Jan 2010) $
   $LastChangedRevision: 3278 $
   $LastChangedBy: mobermeir $
   ----------------------------------------------------------------------- */



#include "math.h"
#include "float.h"



/* ----------------------------------------------------------------------- 
   Global Variables and Structures
*/
double P1;
double P2;
double P3;
double P4;
double P5;
double P6;
double P8;


void func_Wave(void);


#define TABSIZE  5400
#define STEPSIZE 0.0055


/* ----------------------------------------------------------------------- 
   main() function
*/
void main(void)
{
	while(1)
		func_Wave();
}


/* ----------------------------------------------------------------------- 
   Sinus function
*/
void func_Wave(void)
{
 	int    Counter;
 	double Val,Val2,Val3,Val4;
	double x_Amp;

	x_Amp = TABSIZE;
	Val   = 0.1;
	Val2  = Val;
	Val3  = Val;
	Val4  = TABSIZE*STEPSIZE + 5;

	for (Counter = 0; Counter != TABSIZE; Counter++) {
		P1 = sin(Val+10) * (x_Amp*2);
		P2 = sin(Val4)   * (x_Amp-500);
		P3 = cos(Val3)   * (x_Amp*2);
		P4 = cos(Val2)   * (x_Amp-100) * 3.1415;
		P5 = exp((2.0)   * (Val*8)/50);
		P8 = P1 + P2 - P3 + P4 - P5;   /* no opimizing by compiler, all variables are used */

		x_Amp -= 1;
		Val   += STEPSIZE;
		Val2  += Val/1000;
		Val3  += Val2/1000;
		Val4  -= STEPSIZE;
	}
	return;
}



/* ----------------------------------------------------------------------- */
