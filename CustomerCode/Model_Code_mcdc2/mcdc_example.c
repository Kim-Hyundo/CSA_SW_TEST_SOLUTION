#include "mcdc_example.h"
#include "stdio.h"
#include "calc_util.h"
 

int mcdctest_example0(int a, int b, int c)
{

	if (a > 0 &&  (b == 3 || c == 0))
		return ALLOW;

	return DENY;	
}

int mcdctest_example1(int MyUserID, int MySSN, int MyPassWord)
{
	int ValidUserID=1234, ValidSSN=123, ValidPassword=7890;

	if (MyUserID == ValidUserID || (MySSN == ValidSSN &&  MyPassWord == ValidPassword))
		return 0;//ALLOW;
	else 
		return 1;//DENY;
	
}
int mcdctest_example2(int A, int B, int C, int D)
{
	if ((A || B) && (C || D))
		return ALLOW;
	else 
		return DENY;
	
}
int mcdctest_example3(int a,int b, int c)
{
	if( (a > 0 || b > 0) && c > 0)
		return ALLOW;
	else 
		return DENY;
	
}
int mcdctest_example4(int A, int B, int C)
{
	if( (A && B) || (!A && C)) // A, B, C + 1
		return ALLOW;
	else 
		return DENY;
	
}
