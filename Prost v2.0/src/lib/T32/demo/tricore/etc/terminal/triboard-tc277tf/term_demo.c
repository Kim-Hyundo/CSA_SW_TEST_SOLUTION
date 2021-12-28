/**************************************************************************

	TRACE32 Semihosting demo

	origin file:
		files/demo/etc/terminal/t32term/term_demo.c

	interface and possible defines in t32term.h

**************************************************************************/

#include <string.h>
#include <time.h>
#include "t32term.h"

#define CLOCKS_PER_SEC  50000000

#define INTERACTIVE		0
#define PERFORMANCE		1
volatile unsigned int demo_mode;

typedef unsigned int IfxCpu_mutexLock;
IfxCpu_mutexLock bufferoutLock = 0;


/************************************************************************
 *
 * IfxCpu_acquireMutex:
 * A mutex is required to Synch access to Term_Memory_Tar2HostBuffer
 * from multiple cores
 *
 */
int IfxCpu_acquireMutex (IfxCpu_mutexLock * lock)
{
    int retVal;
    volatile unsigned int spinLockVal;

    retVal = 0;

    spinLockVal = 1;
    spinLockVal = (unsigned int) __cmpswapw (((unsigned int *) lock), spinLockVal, 0);

    /* Check if the SpinLock WAS set before the attempt to acquire spinlock */
    if (spinLockVal == 0)
    {
        retVal = 1;
    }
    return retVal;
}

/************************************************************************
 *
 * IfxCpu_releaseMutex
 *
 */
void IfxCpu_releaseMutex (IfxCpu_mutexLock * lock)
{
    /*Reset the SpinLock */
    *lock = 0;
}

void sleep(unsigned int millisec)
{
    clock_t         t_start;
    clock_t         t_current;

    t_start = clock();
    do
    {
        t_current = clock();
    }
    while( (t_current - t_start) < millisec*(CLOCKS_PER_SEC/1000));
}

/************************************************************************
 *
 * main function for core 1
 *
 */
int TC1_main()
{
    char pmessage[] = "core 1:\tPerformance Test Text!\r\n";;
    while(1){
        if(demo_mode==PERFORMANCE){
            while(IfxCpu_acquireMutex(&bufferoutLock)==0);
            T32_Term_Puts( pmessage );
            IfxCpu_releaseMutex(&bufferoutLock);
        } else {
            sleep(1);
        }
    }
}

/************************************************************************
 *
 * main function for core 2
 *
 */
int TC2_main()
{
    char pmessage[] = "core 2:\tPerformance Test Text!\r\n";;
    while(1){
        if(demo_mode==PERFORMANCE){
            while(IfxCpu_acquireMutex(&bufferoutLock)==0);
            T32_Term_Puts( pmessage );
            IfxCpu_releaseMutex(&bufferoutLock);
        } else {
            sleep(1);
        }
    }
}

/************************************************************************
 *
 * main function for core 0
 *
 */
int TC0_main(void)
{
    char pmessage[] = "core 0:\tPerformance Test Text!\r\n";
    char mmessage[] = "\r\nr read file\r\nw write file\r\np performance test\r\n";
    char fmessage[] = "\r\nHello World!\r\n";

    char inFile[]   = "input.txt";
    char outFile[]  = "output.txt";

    char buffer[128];
    int i, ch, handle, pcount;

    demo_mode=INTERACTIVE;

    while(1)
    {
        if(demo_mode==PERFORMANCE){
            //Synch access Term_Memory_Tar2HostBuffer
            while(IfxCpu_acquireMutex(&bufferoutLock)==0);
            T32_Term_Puts( pmessage );
            IfxCpu_releaseMutex(&bufferoutLock);

            if(pcount++==20){
                demo_mode=INTERACTIVE;
                sleep(1);
            }
        } else { //demo_mode==INTERACTIVE
            //
            // in this mode only core 0 is writing to Term_Memory_Tar2HostBuffer
            // ==> no synch is needed
            //
            T32_Term_Puts( mmessage );
            ch=T32_Term_Getchar();
            if (ch == 'r' || ch == 'R')
            {
#if defined(T32_TERM_BLOCKED)
                handle = T32_Term_OpenFileANSI(inFile,T32_TERM_OA_R);
                if (handle == -1) {
                    T32_Term_Puts( "failed to open file\r\n" );
                    continue;
                }
                i = T32_Term_ReadFile(handle,buffer,128);
                if (i == -1) {
                    T32_Term_Puts( "failed to read file\r\n" );
                    continue;
                }
                buffer[i] = '\0';
                T32_Term_Puts(buffer);

                i = T32_Term_CloseFile(handle);
                if (i == -1) {
                    T32_Term_Puts( "failed to close file\r\n" );
                    continue;
                }
#else /*defined(T32_TERM_BLOCKED)*/
                T32_Term_Puts( "only supported with BLOCK/BUFFER mode\r\n" );
#endif /*defined(T32_TERM_BLOCKED)*/
                continue;
            }

            if (ch == 'w' || ch == 'W') {
#if defined(T32_TERM_BLOCKED)
                handle = T32_Term_OpenFileANSI(outFile,T32_TERM_OA_W);
                if (handle == -1) {
                    T32_Term_Puts( "failed to open file\r\n" );
                    continue;
                }
                i = T32_Term_WriteFile(handle,fmessage,strlen(fmessage));

                if (i == -1) {
                    T32_Term_Puts( "failed to write file\r\n" );
                    continue;
                }

                i = T32_Term_CloseFile(handle);
                if (i == -1) {
                    T32_Term_Puts( "failed to close file\r\n" );
                    continue;
                }
#else /*defined(T32_TERM_BLOCKED)*/
                T32_Term_Puts( "only supported with BLOCK/BUFFER mode\r\n" );
#endif /*defined(T32_TERM_BLOCKED)*/
                continue;
            }

            if (ch == 'p' || ch == 'P'){
                pcount=0;
                demo_mode=PERFORMANCE;
            }
        } 
    }
}

int main(void)
{
    switch(__mfcr(CORE_ID)) {
        case 0: return TC0_main();
        case 1: return TC1_main();
        case 2: return TC2_main();
    }
}
