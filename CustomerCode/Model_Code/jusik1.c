/*
 * File: pil_target_tc277.c
 *
 * Code generated for Simulink model 'pil_target_tc277'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 8.7 (R2014b) 08-Sep-2014
 * C/C++ source code generated on : Thu Jan 15 18:35:44 2015
 *
 * Target selection: trace32_tc_ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "jusik.h"
#pragma optimize 0
void jusik1_function0(void)
{
	unsigned int val = jrand(10000);
	while(val--)
		__asm("nop");
}
void jusik1_function1(void)
{
	unsigned int val = jrand(1000);
	while(val--)
		printf("function1 running");
}
void jusik1_function2(void)
{
	unsigned int val = jrand(20000);
	while(val++==10000)
		__asm("nop");
}
void jusik1_function3(void)
{
	unsigned int val = jrand(3000);
	while(val--)
		__asm("nop");
}
void jusik1_function4(void)
{
	unsigned int val = jrand(4000);
	while(val--)
		__asm("nop");
}
void jusik1_function5(void)
{
	unsigned int val = jrand(5000);
	while(val--)
		__asm("nop");
}
void jusik1_function6(void)
{
	unsigned int val = jrand(6000);
	while(val--)
		__asm("nop");
}
void jusik1_function7(void)
{
	unsigned int val = jrand(7000);
	while(val--)
		__asm("nop");
}
void jusik1_function8(void)
{
	unsigned int val = jrand(8000);
	while(val--)
		__asm("nop");
}
void jusik1_function9(void)
{
	unsigned int val = jrand(9000);
	while(val--)
		__asm("nop");
}
#pragma endoptimize
