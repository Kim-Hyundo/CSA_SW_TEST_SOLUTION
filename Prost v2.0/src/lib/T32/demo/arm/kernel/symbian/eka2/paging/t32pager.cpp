/*
 * t32pager
 * Copyright (C) 2008 Lauterbach Datentechnik
 *
 * Documentation see rtos_symb2_stop.pdf
 */

#include <arm_mem.h>
#include <t32pager.h>
extern void FlushDCache();


T32_pagerInfo T32_PagerTable[T32_PAGERINFO_MAXSIZE] = { {0,} ,};
T32_pagerPointer T32_PagerPointer = { T32_PagerTable, T32_PAGERINFO_MAXSIZE, 0, 0, 0x50323054 };


void copysmall(TLinAddr dest, TLinAddr source, int len, unsigned int space)
{
    unsigned char *pd, *ps;
    register int dacr_orig;
    register int dacr_set = 0xffffffff;
    
    pd = (unsigned char*) dest;
    ps = (unsigned char*) source;
    
    // set DACR to control everything
    asm ("mrc p15,0,dacr_orig,c3,c0,0");
    asm ("mcr p15,0,dacr_set,c3,c0,0");
    
    while (len-- > 0) {
        *pd++ = *ps++;
    }
    
    // restore DACR
    asm ("mcr p15,0,dacr_orig,c3,c0,0");
}


void T32_Pager(TLinAddr address, TInt space)
{
    int i;
    
    for (i = 0; i < T32_PAGERINFO_MAXSIZE ; i++)
    {
        if (!T32_PagerTable[i].action)
            break;
        if ((T32_PagerTable[i].address&~0xfff) != (unsigned long) address)
            continue;
        if (/*space == T32_PagerTable[i].space && */
            (T32_PagerTable[i].action == T32_PAGERINFO_ACTION_KEEP || 
             T32_PagerTable[i].action == T32_PAGERINFO_ACTION_SET)) {
                
            copysmall((TLinAddr) T32_PagerTable[i].origdata, (TLinAddr) T32_PagerTable[i].address, T32_PagerTable[i].len, space);
            copysmall((TLinAddr) T32_PagerTable[i].address,  (TLinAddr) T32_PagerTable[i].newdata, T32_PagerTable[i].len, space);
            
            // Flush and invalidate DCache
            FlushDCache();

            T32_PagerPointer.count++;
            break;
        }
    }
}

void T32_PageRestore(unsigned long start, unsigned long end, unsigned int space)
{
	int i;
	
	if (space == 0) 
		return;
	
	for (i = 0; i < T32_PAGERINFO_MAXSIZE ; i++)
	{
		if (!T32_PagerTable[i].action)
			break;
 		if ((T32_PagerTable[i].address&~0xfff) < start || (T32_PagerTable[i].address&~0xfff) >= end)
 			continue;
		if (space == T32_PagerTable[i].space &&
		    (T32_PagerTable[i].action == T32_PAGERINFO_ACTION_KEEP || 
		     T32_PagerTable[i].action == T32_PAGERINFO_ACTION_SET)) {
			copysmall((TLinAddr) T32_PagerTable[i].address, (TLinAddr) T32_PagerTable[i].origdata, T32_PagerTable[i].len, space);
			FlushDCache();
		}
	}
}

