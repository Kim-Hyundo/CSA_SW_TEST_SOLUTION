/***************************************************************************
 **                                                                        *
 **  FILENAME:    sieve.c                                                  *
 **                                                                        *
 **  DESCRIPTION: "DMA" program                                            *
 **                                                                 .      *
 **                                                                        *
 **                                                                        *
 **                                                                        *
 **                                                                        *
 **  Copyright                                                             *
 **                                                                        *
 ***************************************************************************/


#pragma warning 557


#ifdef __CPU__
#include __SFRFILE__(__CPU__)
#endif

enum {
    TOS_CPU0=0,
    TOS_CPU1=1,
    TOS_CPU2=2
};

#define TRUE    1
#define FALSE   0
#define SIZE    8190
#define NULL    0


char flags0[SIZE + 1];
char flags1[SIZE + 1];
char flags2[SIZE + 1];
int waittime = 500;


#define RAM_SOURCE_MEM  (*( unsigned long *) 0x70001000u)
#define RAM_DESIN_MEM  (*( unsigned long *) 0x70002000u)
#define INIT_RAM_LEN 0x400
static unsigned long *pRAM_DMA_MEM = NULL;

#define BUSWIDTH_8BIT     0
#define BUSWIDTH_16BIT    1
#define BUSWIDTH_32BIT    2
#define BUSWIDTH_64BIT    3
#define BUSWIDTH_128BIT   4
#define BUSWIDTH_256BIT   5

void Delay(unsigned int ndelay)
{
    for (unsigned int i = 0; i < (ndelay); i += 1)
        __nop();                                /* Delay */
}


void RAM_Source_init(void)
{
    unsigned long *pmem;
    unsigned int i, j;

    j = 00;

    pRAM_DMA_MEM = (unsigned long *) &RAM_SOURCE_MEM;
    pmem = (unsigned long *) &RAM_SOURCE_MEM;
    for (i = 0; i < (INIT_RAM_LEN); i += 1)
    {
        pmem[i] = j | ((j+1) << 8) | ((j+2) << 16) | ((j+3) << 24);
        j = j + 4;
        if (j == 0xFC){
            j = 0x0;
        }
    }

}

void RAM_Destin_init(void)
{
    unsigned long *pmem;
    unsigned int i;

    pRAM_DMA_MEM = (unsigned long *) &RAM_DESIN_MEM;
    pmem = (unsigned long *) &RAM_DESIN_MEM;
    for (i = 0; i < (INIT_RAM_LEN); i += 1)
    {
        pmem[i] = 0;
    }

}

void DMA_init(void)
{
    // Channel 5   0x05
    DMA_CHCFGR005.U = 0xC0180200; //configuration 8Bit, Continous mode TREL = 200
    DMA_SADR005.U = 0x70002000; //Source address
    DMA_DADR005.U = 0x70003000; //Destination address

    // Channel 10  0x0A
    DMA_CHCFGR010.U = 0xC0380100; //configuration 16Bit, Continous mode TREL = 100
    DMA_SADR010.U = 0x70001E00; //Source address
    DMA_DADR010.U = 0x70002E00; //Destination address

    // Channel 15  0x0F
    DMA_CHCFGR015.U = 0xC0580080; //configuration 32Bit, Continous mode TREL = 80
    DMA_SADR015.U = 0x70001C00; //Source address
    DMA_DADR015.U = 0x70002C00; //Destination address

    // Channel 33  0x21
    DMA_CHCFGR033.U = 0xC0780040; //configuration 64Bit, Continous mode TREL = 40
    DMA_SADR033.U = 0x70001A00; //Source address
    DMA_DADR033.U = 0x70002A00; //Destination address

    // Channel 24  0x18
    DMA_CHCFGR024.U = 0xC0980020; //configuration 128Bit, Continous mode TREL = 20
    DMA_SADR024.U = 0x70001800; //Source address
    DMA_DADR024.U = 0x70002800; //Destination address

    // Channel 63  0x3f
    DMA_CHCFGR063.U = 0xC0b80010; //configuration 256Bit, Continous mode TREL = 10
    DMA_SADR063.U = 0x70001600; //Source address
    DMA_DADR063.U = 0x70002600; //Destination address

    Delay(100);
}


void DMA_start(void)
{
    DMA_CHCSR005.U = 0x80000000; //start DMA Channel 5
    Delay(waittime);
    DMA_CHCSR010.U = 0x80000000; //start DMA Channel 10
    Delay(waittime);
    DMA_CHCSR015.U = 0x80000000; //start DMA Channel 15
    Delay(waittime);
    DMA_CHCSR033.U = 0x80000000; //start DMA Channel 33
    Delay(waittime);
    DMA_CHCSR024.U = 0x80000000; //start DMA Channel 24
    Delay(waittime);
    DMA_CHCSR063.U = 0x80000000; //start DMA Channel 63
    Delay(waittime);
}


/*
 * main has code core association share and is called by all cores
 */
int main( void )
{
    __nop();                                /* Debugger puts SW breakpoint here for goto main */

    if ( __mfcr(CORE_ID) == 0 )             /* core 0 */
    {
    }

    while(1){
        if ( __mfcr(CORE_ID) == 0 )             /* core 0 */
        {
            RAM_Source_init();
            RAM_Destin_init();
            DMA_init();
            DMA_start();
            Delay(5000);

            sieve0();
        }

        if ( __mfcr(CORE_ID) == 1 )             /* core 1 */
        {
             sieve1();
        }

        if ( __mfcr(CORE_ID) == 2 )             /* core 2 */
        {
             sieve2();
        }
    }

}

int sieve0()
{
    int i, primz, k;
    int anzahl;

    anzahl = 0;

    for ( i = 0 ; i <= SIZE ; flags0[ i++ ] = TRUE ) ;

    for ( i = 0 ; i <= SIZE ; i++ )
    {
        if ( flags0[ i ] )
        {
            primz = i + i + 3;
            k = i + primz;
            while ( k <= SIZE )
            {
                flags0[ k ] = FALSE;
                k += primz;
            }
            anzahl++;
        }
    }

    return anzahl;
}

int sieve1()
{
    int i, primz, k;
    int anzahl;

    anzahl = 0;

    for ( i = 0 ; i <= SIZE ; flags1[ i++ ] = TRUE ) ;

    for ( i = 0 ; i <= SIZE ; i++ )
    {
        if ( flags1[ i ] )
        {
            primz = i + i + 3;
            k = i + primz;
            while ( k <= SIZE )
            {
                flags1[ k ] = FALSE;
                k += primz;
            }
            anzahl++;
        }
    }

    return anzahl;
}

int sieve2()
{
    int i, primz, k;
    int anzahl;

    anzahl = 0;

    for ( i = 0 ; i <= SIZE ; flags2[ i++ ] = TRUE ) ;

    for ( i = 0 ; i <= SIZE ; i++ )
    {
        if ( flags2[ i ] )
        {
            primz = i + i + 3;
            k = i + primz;
            while ( k <= SIZE )
            {
                flags2[ k ] = FALSE;
                k += primz;
            }
            anzahl++;
        }
    }

    return anzahl;
}





