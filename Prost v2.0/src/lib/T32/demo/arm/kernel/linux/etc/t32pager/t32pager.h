/*
 * t32pager
 * Copyright (C) 2008 Lauterbach Datentechnik (Khaled.Jmal@Lauterbach.com)
 *
 */

typedef struct
{
	unsigned char action;
	unsigned char len;
	unsigned char pagedout;
	unsigned char reserved;
	unsigned long space;
	unsigned long address;
	unsigned char newdata[4];
	unsigned char origdata[4];
}
T32_pagerInfo;

#define T32_PAGERINFO_ACTION_FREE	1
#define T32_PAGERINFO_ACTION_KEEP	2
#define T32_PAGERINFO_ACTION_SET	3
#define T32_PAGERINFO_ACTION_DELETE	4

#define T32_PAGERINFO_MAXSIZE		256

typedef struct
{
	T32_pagerInfo * ptr;
	unsigned int len;
	unsigned int lock;
	unsigned int count;
	unsigned int magic;
}
T32_pagerPointer; 

extern T32_pagerInfo T32_PagerTable[T32_PAGERINFO_MAXSIZE]; 
extern T32_pagerPointer T32_PagerPointer; 

void T32_Pager(unsigned long address, unsigned int space);
void copysmall(unsigned char * dest, unsigned char * source, int len);
void T32_PageRestore(unsigned long start, unsigned long end, unsigned int space);
