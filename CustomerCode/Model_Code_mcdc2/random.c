/*
 * random.c
 *
 *  Created on: 2020. 4. 14.
 *      Author: jusik2
 */
#include "jusik.h"

unsigned int jrand(int max)
{
	unsigned int *pTimer;
	pTimer=0xF0000010;
	return (*pTimer)%max;
}

