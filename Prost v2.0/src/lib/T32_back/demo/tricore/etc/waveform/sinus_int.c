/* ----------------------------------------------------------------------- 
   Draw Test Programm for TriCore
   drawing mathematical waveforms sin, cos, exp
   - 32 bit
   - integer precision

   $LastChangedDate: 2009-02-09 15:26:29 +0100 (Mon, 09 Feb 2009) $
   $LastChangedRevision: 2896 $
   $LastChangedBy: mobermaier $
   ----------------------------------------------------------------------- */



#include "math.h"
#include "float.h"



/* ----------------------------------------------------------------------- 
   Global Variables and Structures
*/
unsigned short int P1;
unsigned short int P2;
unsigned short int P3;
unsigned short int P4;
unsigned short int P5;
unsigned short int P6;
unsigned short int P8;


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
		P1 = (int)(sin(Val+10) * (x_Amp*2))   + 0x8000;
		P2 = (int)(sin(Val4)   * (x_Amp-500)) + 0x8000;
		P3 = (int)(cos(Val3)   * (x_Amp*2))   + 0x8000;
		P4 = (int)(((cos(Val2) * (x_Amp-100)) * 3.1415)) + 0x8000;
		P5 = (int)(exp((2.0)   * ((Val*8)/50))) + 0x8000;
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
