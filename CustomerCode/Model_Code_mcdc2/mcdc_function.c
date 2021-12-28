#include "mcdc_function.h"
#include "stdio.h"
#include "calc_util.h"

#pragma optimize 0

int g_num;
int a,b,result;    

void mcdctest_function0(void)
{
	int a = 0, b = 3, c =4;
	__asm("mul\t%0,%1,%2" : "=d"(result) : "d"(a), "d"(b) );

	if (a > 0 &&  b == 3)
		__asm("mul\t%0,%1,%2" : "=d"(result) : "d"(a), "d"(b) );
	else 
		__asm("mul\t%0,%1,%2" : "=d"(result) : "d"(a), "d"(b) );

	if (a > 0 &&  b == 3 && c > 4)
		__asm("mul\t%0,%1,%2" : "=d"(result) : "d"(a), "d"(b) );
	else 
		__asm("mul\t%0,%1,%2" : "=d"(result) : "d"(a), "d"(b) );
}

#pragma pack 0
int mcdctest_function1(int i)
{
	packed_struct pstruct;
	
	pstruct.uc1 = 'c';
	pstruct.us1 = 1;
	pstruct.us2 = 2; 
	pstruct.us3 = 3;  

	if (pstruct.us1 == 1 && i > 3) 
	 	return 10;
	else
	{
	 	g_num = 0;
	 	return 0;
	}
}

int mcdctest_function2(int cnt)
{
	int  w,x = 4,y = x,z;
	w = add( 1, 2 );
    z = add( x, y );

	if(w > 2 && z < 10 )
		__asm("mul\t%0,%1,%2" : "=d"(result) : "d"(x), "d"(y) );
	else 
		__asm( "mov %0,#0xFF" : "=d"(result));	

    return -1;
}

void mcdctest_function3(unsigned char *CMD)
{
	crc_check(CMD);
}
void mcdctest_function4(int num1, int num2, int num3, int num4)
{
	if (((num1 == 10 && num2 > 20) || (num3 & 0x0001) == 0 )&& num4 >= 40 )
    	add(num1, num2);
	else
	{
		add(num3, num4);
	}
	
}
void mcdctest_function5(int shift)
{
    char num1 = 113;    //  113: 0111 0001
    char num2 = -15;    //  -15: 1111 0001
    char num3, num4, num5, num6;
 
    num3 = num1 << shift;    
    num4 = num2 << shift;    
 
    num5 = num1 << shift*2;    
    num6 = num2 << shift*2;    
 

	if(num3 < 0 && num4 < 0 && num5 >= 0 && num6 > 0)
		num3 >> shift;
	else
	{
		num3 >> (shift + 3);  	
	}
}
void mcdctest_function6(char* s1, char* s2, char* s3)
{
	int ret = 0;
	char s4[100] = {0,};

	__asm( "nop" );
	
	if(strlen(s1) > 0 && strcmp(s1, s2) != 0 && strcmp(s2, s3) == 0)
		g_num = 60;
	else
	{
		g_num = 61;
	}

	strcpy(s4, s1);

	if(strlen(s1) > 0 && strcmp(s1, s2) != 0 && strcmp(s1, s4) == 0)
		g_num = 62;
	else
	{
		g_num = 63;
	}
	   
}
void mcdctest_function7(void)
{
    unsigned char num1 = 1;    // 0000 0001
    unsigned char num2 = 3;    // 0000 0011
	unsigned char num3 = 162;
	unsigned char num4, num5 = 4; 

	if((num1 & num2) && (num1 | num2)&& num1 ^ num2)
		g_num = 70;
	num4 = ~num3;
	num5 >>= 2;

	if (num4 == 93 && ((unsigned char)num2 << 3) == 24 || num5 > 1)
		g_num = 71;
}
int mcdctest_function8(void)
{
	unsigned char num1 = 1;    // 0000 0001
    unsigned char num2 = 3;    // 0000 0011
	unsigned char num3 = 162;
	unsigned char num4, num5 = 4;
	int i = 0;
 
	for(i = 0; i < 100; i++)
	{
		num1 = i;
	}

	if((num1 & num2) && (num1 | num2)&& num1 ^ num2)
		g_num = 80;
	num4 = ~num3;
	num5 >>= 2;

	if (num4 == 93 && ((unsigned char)num2 << 3) == 24 || num5 > 1)
		g_num = 81;

}
void mcdctest_function9(int cnt)
{

	switch(cnt % 2)
	{
		case 0:
			break;
		case 1:
			break;
	}

}
#pragma endoptimize
