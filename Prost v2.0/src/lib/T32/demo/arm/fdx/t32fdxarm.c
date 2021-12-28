
/**************************************************************************

	ARM DCC communication variant

	DEFINES:
		ARM7   : Use Communication Registers for ARM7
		ARM9   : Use Communication Registers for ARM9
		ARM11  : Use Communication Registers for ARM11
		XSCALE : Use Communication Registers for XSCALE
		CORTEXR: Use Communication Registers for CortexRx
		CORTEXA: Use Communication Registers for CortexAx


**************************************************************************/

#if defined(T32_FDX_DCC)||defined(T32_FDX_DCC3)


#if defined(ARM9)||defined(ARM7)

unsigned int T32_TsMon_SendStatus(void)
{
    int             status;
#ifdef __GNUC__
    __asm__ volatile("mrc p14, 0, %0, c0, c0" : "=r" (status));
#else
    __asm
    {
        MRC p14, 0, status, c0, c0;
    }
#endif
    return (status & 2);
}


void T32_TsMon_SendWord(unsigned int data)
{
#ifdef __GNUC__
    __asm__ volatile("mcr p14, 0, %0, c1, c0" : :"r" (data));
#else
    __asm
    {
        MCR p14, 0, data, c1, c0
    }
#endif
}


unsigned int T32_TsMon_ReceiveStatus(void)
{
    int             status;
#ifdef __GNUC__
    __asm__ volatile("mrc p14, 0, %0, c0, c0" : "=r" (status));
#else
    __asm
    {
        MRC p14, 0, status, c0, c0;
    }
#endif
    return (status & 1);
}


unsigned int T32_TsMon_ReceiveWord(void)
{
    unsigned int    data;
#ifdef __GNUC__
    __asm__ volatile("mrc p14, 0, %0, c1, c0" : "=r" (data));
#else
    __asm
    {
        MRC p14, 0, data, c1, c0;
    }
#endif
    return data;
}

#endif

#if defined(ARM11)||defined(CORTEXA)||defined(CORTEXR)

unsigned int T32_TsMon_SendStatus(void)
{
    int             status;
#ifdef __GNUC__
    __asm__ volatile("mrc p14, 0, %0, c0, c1" : "=r" (status));
#else
    __asm
    {
        MRC p14, 0, status, c0, c1;
    }
#endif
    return (status & 0x20000000);
}


void T32_TsMon_SendWord(unsigned int data)
{
#ifdef __GNUC__
    __asm__ volatile("mcr p14, 0, %0, c0, c5" : : "r" (data));
#else
    __asm
    {
        MCR p14, 0, data, c0, c5
    }
#endif
}


unsigned int T32_TsMon_ReceiveStatus(void)
{
    int             status;
#ifdef __GNUC__
    __asm__ volatile("mrc p14, 0, %0, c0, c1" : "=r" (status));
#else
    __asm
    {
        MRC p14, 0, status, c0, c1;
    }
#endif
    return (status & 0x40000000);
}


unsigned int T32_TsMon_ReceiveWord(void)
{
    unsigned int    data;
#ifdef __GNUC__
    __asm__ volatile("mrc p14, 0, %0, c0, c5" : "=r" (data));
#else
    __asm
    {
        MRC p14, 0, data, c0, c5;
    }
#endif
    return data;
}

#endif

#ifdef XSCALE

unsigned int T32_TsMon_SendStatus(void)
{
    int             status;
#ifdef __GNUC__
    __asm__ volatile("mrc p14, 0, %0, c14, c0" : "=r" (status));
#else
    __asm
    {
        MRC p14, 0, status, c14, c0, 0;
    }
#endif
    return (status & 0x10000000);
}


void T32_TsMon_SendWord(unsigned int data)
{
#ifdef __GNUC__
    __asm__ volatile("mcr p14, 0, %0, c8, c0" : : "r" (data));
#else
    __asm
    {
        MCR p14, 0, data, c8, c0, 0
    }
#endif
}


unsigned int T32_TsMon_ReceiveStatus(void)
{
    int             status;
#ifdef __GNUC__
    __asm__ volatile("mrc p14, 0, %0, c14, c0" : "=r" (status));
#else
    __asm
    {
        MRC p14, 0, status, c14, c0, 0;
    }
#endif
    return (status & 0x80000000);
}


unsigned int T32_TsMon_ReceiveWord(void)
{
    unsigned int    data;
#ifdef __GNUC__
    __asm__ volatile("mrc p14, 0, %0, c9, c0" : "=r" (data));
#else
    __asm
    {
        MRC p14, 0, data, c9, c0, 0;
    }
#endif
    return data;
}

#endif

#endif
/**************************************************************************

  ARM timebase (enter code here)

**************************************************************************/

unsigned long T32_Fdx_GetTimebase()
{
    return 0;
}

