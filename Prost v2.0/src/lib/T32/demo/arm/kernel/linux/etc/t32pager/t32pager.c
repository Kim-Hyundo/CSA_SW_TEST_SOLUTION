/*
 * t32pager
 * Copyright (C) 2008 Lauterbach Datentechnik (Khaled.Jmal@Lauterbach.com)
 *
 */

#include <linux/t32pager.h>
#include <asm/cacheflush.h>

T32_pagerInfo T32_PagerTable[T32_PAGERINFO_MAXSIZE] = { {0,} ,};
T32_pagerPointer T32_PagerPointer = { T32_PagerTable, T32_PAGERINFO_MAXSIZE, 0, 0, 0x50323054 };


void copysmall(unsigned char * dest, unsigned char * source, int len)
{
	while (len-- > 0) {
		*dest++ = *source++;
	}
}

void T32_Pager(unsigned long address, unsigned int space)
{
	int i;
	int result = 0;

	T32_PagerPointer.lock = 1;

	for (i = 0; i < T32_PAGERINFO_MAXSIZE ; i++)
	{
		if (!T32_PagerTable[i].action)
			break;
 		if ((T32_PagerTable[i].address&~0xfff) != address)
 			continue;
		if (space == T32_PagerTable[i].space &&
		    (T32_PagerTable[i].action == T32_PAGERINFO_ACTION_KEEP ||
		     T32_PagerTable[i].action == T32_PAGERINFO_ACTION_SET)) {
			copysmall(T32_PagerTable[i].origdata, (unsigned char *) T32_PagerTable[i].address, T32_PagerTable[i].len);
			copysmall((unsigned char *) T32_PagerTable[i].address, T32_PagerTable[i].newdata, T32_PagerTable[i].len);

			T32_PagerPointer.count++;
			result = 1;
		}
	}

	T32_PagerPointer.lock = 0;

	if (result)
		__cpuc_flush_user_all();
}

void T32_PageRestore(unsigned long start, unsigned long end, unsigned int space)
{
	int i;
	int result = 0;

	if (space == 0)
		return;

	T32_PagerPointer.lock = 1;

	for (i = 0; i < T32_PAGERINFO_MAXSIZE ; i++)
	{
		if (!T32_PagerTable[i].action)
			break;
 		if ((T32_PagerTable[i].address&~0xfff) < start || (T32_PagerTable[i].address&~0xfff) >= end)
 			continue;
		if (space == T32_PagerTable[i].space &&
		    (T32_PagerTable[i].action == T32_PAGERINFO_ACTION_KEEP ||
		     T32_PagerTable[i].action == T32_PAGERINFO_ACTION_SET)) {
			copysmall((unsigned char *) T32_PagerTable[i].address, T32_PagerTable[i].origdata, T32_PagerTable[i].len);
			result = 1;
		}
	}

	T32_PagerPointer.lock = 0;

	if (result)
		__cpuc_flush_user_all();
}

