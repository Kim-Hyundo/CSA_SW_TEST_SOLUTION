/**************************************************************************
**                                                                        *
**  FILE        :  cstart.c                                               *
**                                                                        *
**  DESCRIPTION :                                                         *
**      The system startup code initializes the processor's registers     *
**      and the application C variables.                                  *
**                                                                        *
**  Copyright 1996-2007 Altium BV                                         *
**                                                                        *
**************************************************************************/

#include "cstart.h"                             /* include configuration */

#include <stdlib.h>
#include <stdbool.h>

#pragma weak   exit
#pragma extern _Exit
//#pragma optimize abcefgIKlpoRsy               /* preset optimizations */
#pragma tradeoff 4                              /* preset tradeoff level (for size) */

#if __USE_ARGC_ARGV
static char argcv[__ARGCV_BUFSIZE];
extern int _argcv( const char *, size_t );
#else
static char *argcv[1] = { NULL }; 
#endif

#if __SYNC_ON_HALT
#  pragma extern  _sync_on_halt         /* debugger utilty function */
#endif

/* linker definitions */
extern __far void _lc_ue_ustack[];      /* user stack end */
extern __far void _lc_ue_istack[];      /* interrupt stack end */
extern __far void _lc_u_int_tab[];      /* interrupt table */
extern __far void _lc_u_trap_tab[];     /* trap table */
extern __far void _SMALL_DATA_[];       /* centre of A0 addressable area */
extern __far void _LITERAL_DATA_[];     /* centre of A1 addressable area */
extern __far void _A8_DATA_[];          /* centre of A8 addressable area */
extern __far void _A9_DATA_[];          /* centre of A9 addressable area */

/* external functions */
extern void _c_init(void);              /* C initialization function */
extern void _call_init(void);           /* call a user function before main() */
extern void _endinit(void);             /* call a user function with protection switched off */

/* library references */
extern int main( int argc, char *argv[] );

/* prototype */
void _endinit_clear(void);
void _endinit_set  (void);

#ifdef __PROFILE_INIT__
extern void __prof_init( void );
#endif

/*********************************************************************************
 * _reset() - reset vector
 *********************************************************************************/
#pragma section code libc.reset

void _START( void )
{
        __asm("j\t__init_sp");
        /*
         * Set default Boot Configuration Value
         */
#ifndef __EBU_BOOTCFG_VALUE
#  define __EBU_BOOTCFG_VALUE  0x800C
#endif

        /*
         * Set address for the Boot Configuration Value
         * to 'Boot memory Offset Address + alignment'
         */
#if     !(__EBU_BOOTCFG_VALUE & 0x1)
        /*
         * Address Alignment is off
         */
        __asm(".align\t4");
#else
        /*                        
         * Address Alignment is on and 16 bit wide memory
         */
#if     ( !(__EBU_BOOTCFG_VALUE & 0x8000) )
        __asm(".align\t8");
#else
        /*                        
         * Address Alignment is on and 32 bit wide memory
         */
        __asm(".align\t16");
#endif
#endif                
        __asm(".word\t%0"::"i"(__EBU_BOOTCFG_VALUE));
}

/*********************************************************************************
 * _cstart() - initialize stackpointer
 *********************************************************************************/
#pragma section code libc

void __init_sp( void )
{
        /* The initialization of the stackpointer is done in a seperate function, 
           because it must be executed in a function which has no stack use.
           
           When a function uses a stack it will be updated at the start of the 
           function. In this function, however, the stackpointer has an irrelevant
           value at the start of the function. A starting value for the stackpointer
           is determined and written in this function. The update to the 
           stackpointer at the start of the function would therefore be undone.
         */
         
        /* 
         * CPU_TC.033 workaround:
         * The stack pointers are aligned to quad-word boundary
         * to workaround the TC112_COR16 functional problem.
         * Also the C compiler workaround for this CPU function problem
         * need to be enabled with --silicon-bug=cpu-tc033, to align circular
         * buffers on a quad-word boundary and to size all stack 
         * frames to an integral number of quad-words.
         */
#if      __CPU_TC033_INITIAL__
# define STACK_ALIGN    0xfffffff0
#else
# define STACK_ALIGN    0xfffffff8
#endif

        /* 
         * Load user stack pointer.
         * Disable this if not started from RESET vector. (E.g.
         * ROM monitors require to keep in control of vectors)
         */
#if  __USP_INIT
        unsigned int sp = (unsigned int)(_lc_ue_ustack) & STACK_ALIGN;
        __asm("mov.a\tsp,%0"::"d"(sp));
#endif

        __asm("j\t_start");
}

/*********************************************************************************
 * _cstart() - startup code
 *********************************************************************************/

void _start( void )
{
        /* Do a dsync before changing any of the csfr values, thus any previous
         * background state gets flushed first. Required for applications that jump
         * to the reset address.
         */
        __dsync();
        
        /* Set the PSW to its reset value in case of a warm start */
#if __USER_STACK
        __mtcr(PSW, 0x00000980);        /* clear PSW.IS */
        __isync();
#else
        __mtcr(PSW, 0x00000b80);
        __isync();
#endif

        /* Set the PCXI to its reset value in case of a warm start */
        unsigned int pcxi = __mfcr(PCXI);
        pcxi &= 0xfff0;
        __mtcr(PCXI, pcxi);
        __isync();

        /* Setup the context save area linked list. */
#if __CSA_INIT
        
        // TODO - these pointer arrays csa_area_begin/end should be placed in memory, not on the stack
        //      the simulator, however, will generate an error if 'static' is placed in front of the declarations
#  if !__CPU_TC051_INITIAL__
#  define MAX_NR_OF_CSA_AREAS     1
extern int _lc_ub_csa_01[];    /* context save area 1 begin */
extern int _lc_ue_csa_01[];    /* context save area 1 end   */
        int * csa_area_begin[] = { _lc_ub_csa_01 };        
        int * csa_area_end[]   = { _lc_ue_csa_01 };
#  else
#  define MAX_NR_OF_CSA_AREAS     3
extern int _lc_ub_csa_01[];    /* context save area 1 begin */
extern int _lc_ue_csa_01[];    /* context save area 1 end   */
extern int _lc_ub_csa_02[];    /* context save area 2 begin */
extern int _lc_ue_csa_02[];    /* context save area 2 end   */
extern int _lc_ub_csa_03[];    /* context save area 3 begin */
extern int _lc_ue_csa_03[];    /* context save area 3 end   */
        int * csa_area_begin[] = { _lc_ub_csa_01, _lc_ub_csa_02, _lc_ub_csa_03 };        
        int * csa_area_end[]   = { _lc_ue_csa_01, _lc_ue_csa_02, _lc_ue_csa_03 };
#  endif

        int  i, k;
        int  no_of_csas;
        int * csa;
        unsigned int  seg_nr, seg_idx, pcxi_val=0;
        _Bool first=true;
        
        for (i=0; i < MAX_NR_OF_CSA_AREAS; i++)
        {
                /* first calculate nr of CSAs in this area */
                no_of_csas = (csa_area_end[i] - csa_area_begin[i]) >> 4;
                
                for (k=0; k < no_of_csas; k++)
                {                        
                        csa = csa_area_begin[i] + k*16;
                        /* Store null pointer in last CSA (= very first time!) */
                        *csa = pcxi_val;                        

                        seg_nr  = __extru( (int) csa, 28, 4) << 16;
                        seg_idx = __extru( (int) csa, 6, 16);
                        pcxi_val = seg_nr | seg_idx;
                        if (first)
                        {
                                first = false;                                
                                __mtcr(LCX, pcxi_val);
                                __isync();
                        }                        
                }
                __mtcr(FCX, pcxi_val);
                __isync();
        }
#endif
        /*
         * Clear the ENDINIT bit in the WDT_CON0 register in order
         * to disable the write-protection for registers protected 
         * via the EndInit feature (for example: WDT_CON1).
         */
        _endinit_clear();
        
        /*
         * Call a function before the write-protection
         * is enabled again. In this routine one can initialize the 
         * registers protected via the EndInit feature.
         * Beware that protected registers are unlocked for the duration 
         * of the Time-out Period only!
         */
        // TODO: What to do with CALL_ENDINIT
#ifdef _CALL_ENDINIT
        _endinit();        
#endif 

        /*
         * Disable the Watchdog if requested. Watchdog is enabled by default.
         */       
#if __WATCHDOG_DISABLE
        WDT_CON1.U |= 0x8;        
#endif

        /*
         * PMI_TC.003 workaround:
         * The TLB-A and TLB-B mappings are set to a page size of 16KB.
         */
#if __PMI_TC003_INITIAL__  && defined MMU_CON
        unsigned int mmu_con = __mfcr(MMU_CON);
        mmu_con &= 0xffffffe1;      /* clear SZA and SZB */
        mmu_con |= 0x00000014;      /* set SZA=SZB=16k   */       
        __mtcr(MMU_CON, mmu_con);
        __isync();
#endif

        /*
         * Load Base Address of Trap Vector Table.
         * Disable this if not started from RESET vector. (E.g.
         * ROM monitors require to keep in control of vectors)
         */
#if __BTV_INIT
        __mtcr(BTV,  (unsigned int)_lc_u_trap_tab);
        __isync();
#endif

        /*
         * Load Base Address of Interrupt Vector Table.
         * Disable this if not started from RESET vector. (E.g.
         * ROM monitors require to keep in control of vectors)
         */
#if __BIV_INIT
        __mtcr(BIV, (unsigned int)(_lc_u_int_tab));
        __isync();
#endif

        /*
         * Load interupt stack pointer.
         * Disable this if not started from RESET vector. (E.g.
         * ROM monitors require to keep in control of vectors)
         */
#if __ISP_INIT
        unsigned int isp = (unsigned int)(_lc_ue_istack) & STACK_ALIGN;
        __mtcr(ISP, isp);
        __isync();
#endif
                                                          
        /*
         * PMU configuration.
         */
#if defined PMU_CON0 && defined __PMU_CON0_VALUE
        if(__PMU_CON0_INIT)  PMU_CON0.U = __PMU_CON0_VALUE;        
#endif
        
#if defined PMU_EIFCON && defined __PMU_EIFCON_VALUE
        if(__PMU_EIFCON_INIT)  PMU_EIFCON.U = __PMU_EIFCON_VALUE;
#endif
        
        /*
         * Data cache control (Reset 0H).
         * CPU_TC013 workaround:
         * The 16KB D-Cache is enabled to workaround
         * the CPU_TC013 functional problem.     
         * NOTE: Setting the D-Cache size must be done at the
         *       very beginning of the startup code.
         */
#if defined  DMU_CON
#  if __CPU_TC013_INITIAL__ 
        DMU_CON.U = 0x1;
#  elif defined _REGTC1765_H
        DMU_CON.U = 0xCA;
#  endif
#endif

        /*
         * Bus configuration EBU_CLC within endinit.
         */
#  if defined EBU_CLC && defined __EBU_CLC_VALUE
        if(__EBU_CLC_INIT)  EBU_CLC.U = __EBU_CLC_VALUE;
#  endif

        /*
         * Set the ENDINIT bit in the WDT_CON0 register again
         * to enable the write-protection and to prevent a time-out. 
         */
        _endinit_set();
        
        /*
         * PMU_TC.004 workaround:
         * The split mode is disabled on the LMB bus to workaround.
         */
#if __PMU_TC004_INITIAL__  && defined LFI_CON
        LFI_CON.U &= 0xfffffffe;        
#endif
        
        /*
         * Inititialize global address registers a0/a1 to support
         * __a0/__a1 storage qualifiers of the C compiler.
         */
#if __A0A1_INIT
        void * a0 = _SMALL_DATA_;        
        __asm( "mov.aa\ta0,%0"::"a"(a0) );

        void * a1 = _LITERAL_DATA_;        
        __asm( "mov.aa\ta1,%0"::"a"(a1) );
#endif

        /*
         * Inititialize global address registers a8/a9 to support
         * __a8/__a9 storage qualifiers of the C compiler. A8 and A9
         * are reserved for OS use, or for application use in cases 
         * where the application ans OS are tightly coupled.
         */
#if __A8A9_INIT
        void * a8 = _A8_DATA_;        
        __asm( "mov.aa\ta8,%0"::"a"(a8) );

        void * a9 = _A9_DATA_;        
        __asm( "mov.aa\ta9,%0"::"a"(a9) );
#endif
               
        /*
         * Initialize Bus configuration registers:
         * Set register-values according to .define's created by the GUI
         */
#if defined EBU_ADDRSEL0 && defined __EBU_ADDRSEL0_VALUE
        if(__EBU_ADDRSEL0_INIT)  EBU_ADDRSEL0.U = __EBU_ADDRSEL0_VALUE;
#endif
#if defined EBU_ADDRSEL1 && defined __EBU_ADDRSEL1_VALUE
        if(__EBU_ADDRSEL1_INIT)  EBU_ADDRSEL1.U = __EBU_ADDRSEL1_VALUE;
#endif
#if defined EBU_ADDRSEL2 && defined __EBU_ADDRSEL2_VALUE
        if(__EBU_ADDRSEL2_INIT)  EBU_ADDRSEL2.U = __EBU_ADDRSEL2_VALUE;
#endif
#if defined EBU_ADDRSEL3 && defined __EBU_ADDRSEL3_VALUE
        if(__EBU_ADDRSEL3_INIT)  EBU_ADDRSEL3.U = __EBU_ADDRSEL3_VALUE;
#endif
#if defined EBU_ADDRSEL4 && defined __EBU_ADDRSEL4_VALUE
        if(__EBU_ADDRSEL4_INIT)  EBU_ADDRSEL4.U = __EBU_ADDRSEL4_VALUE;
#endif
#if defined EBU_ADDRSEL5 && defined __EBU_ADDRSEL5_VALUE
        if(__EBU_ADDRSEL5_INIT)  EBU_ADDRSEL5.U = __EBU_ADDRSEL5_VALUE;
#endif
#if defined EBU_ADDRSEL6 && defined __EBU_ADDRSEL6_VALUE
        if(__EBU_ADDRSEL6_INIT)  EBU_ADDRSEL6.U = __EBU_ADDRSEL6_VALUE;
#endif
#if defined EBU_BCUCON && defined __EBU_BCUCON_VALUE
        if(__EBU_BCUCON_INIT)  EBU_BCUCON.U = __EBU_BCUCON_VALUE;
#endif
#if defined EBU_BFCON && defined __EBU_BFCON_VALUE
        if(__EBU_BFCON_INIT)  EBU_BFCON.U = __EBU_BFCON_VALUE;
#endif
#if defined EBU_BUSAP0 && defined __EBU_BUSAP0_VALUE
        if(__EBU_BUSAP0_INIT)  EBU_BUSAP0.U = __EBU_BUSAP0_VALUE;
#endif
#if defined EBU_BUSAP1 && defined __EBU_BUSAP1_VALUE
        if(__EBU_BUSAP1_INIT)  EBU_BUSAP1.U = __EBU_BUSAP1_VALUE;
#endif
#if defined EBU_BUSAP2 && defined __EBU_BUSAP2_VALUE
        if(__EBU_BUSAP2_INIT)  EBU_BUSAP2.U = __EBU_BUSAP2_VALUE;
#endif
#if defined EBU_BUSAP3 && defined __EBU_BUSAP3_VALUE
        if(__EBU_BUSAP3_INIT)  EBU_BUSAP3.U = __EBU_BUSAP3_VALUE;
#endif
#if defined EBU_BUSAP4 && defined __EBU_BUSAP4_VALUE
        if(__EBU_BUSAP4_INIT)  EBU_BUSAP4.U = __EBU_BUSAP4_VALUE;
#endif
#if defined EBU_BUSAP5 && defined __EBU_BUSAP5_VALUE
        if(__EBU_BUSAP5_INIT)  EBU_BUSAP5.U = __EBU_BUSAP5_VALUE;
#endif
#if defined EBU_BUSAP6 && defined __EBU_BUSAP6_VALUE
        if(__EBU_BUSAP6_INIT)  EBU_BUSAP6.U = __EBU_BUSAP6_VALUE;
#endif
#if defined EBU_BUSCON0 && defined __EBU_BUSCON0_VALUE
        if(__EBU_BUSCON0_INIT)  EBU_BUSCON0.U = __EBU_BUSCON0_VALUE;
#endif
#if defined EBU_BUSCON1 && defined __EBU_BUSCON1_VALUE
        if(__EBU_BUSCON1_INIT)  EBU_BUSCON1.U = __EBU_BUSCON1_VALUE;
#endif
#if defined EBU_BUSCON2 && defined __EBU_BUSCON2_VALUE
        if(__EBU_BUSCON2_INIT)  EBU_BUSCON2.U = __EBU_BUSCON2_VALUE;
#endif
#if defined EBU_BUSCON3 && defined __EBU_BUSCON3_VALUE
        if(__EBU_BUSCON3_INIT)  EBU_BUSCON3.U = __EBU_BUSCON3_VALUE;
#endif
#if defined EBU_BUSCON4 && defined __EBU_BUSCON4_VALUE
        if(__EBU_BUSCON4_INIT)  EBU_BUSCON4.U = __EBU_BUSCON4_VALUE;
#endif
#if defined EBU_BUSCON5 && defined __EBU_BUSCON5_VALUE
        if(__EBU_BUSCON5_INIT)  EBU_BUSCON5.U = __EBU_BUSCON5_VALUE;
#endif
#if defined EBU_BUSCON6 && defined __EBU_BUSCON6_VALUE
        if(__EBU_BUSCON6_INIT)  EBU_BUSCON6.U = __EBU_BUSCON6_VALUE;
#endif
#if defined EBU_CON && defined __EBU_CON_VALUE
        if(__EBU_CON_INIT)  EBU_CON.U = __EBU_CON_VALUE;
#endif
#if defined EBU_EMUAS && defined __EBU_EMUAS_VALUE
        if(__EBU_EMUAS_INIT)  EBU_EMUAS.U = __EBU_EMUAS_VALUE;
#endif
#if defined EBU_EMUBAP && defined __EBU_EMUBAP_VALUE
        if(__EBU_EMUBAP_INIT)  EBU_EMUBAP.U = __EBU_EMUBAP_VALUE;
#endif
#if defined EBU_EMUBC && defined __EBU_EMUBC_VALUE
        if(__EBU_EMUBC_INIT)  EBU_EMUBC.U = __EBU_EMUBC_VALUE;
#endif
#if defined EBU_EMUCON && defined __EBU_EMUCON_VALUE
        if(__EBU_EMUCON_INIT)  EBU_EMUCON.U = __EBU_EMUCON_VALUE;
#endif
#if defined EBU_EMUOVL && defined __EBU_EMUOVL_VALUE
        if(__EBU_EMUOVL_INIT)  EBU_EMUOVL.U = __EBU_EMUOVL_VALUE;
#endif
#if defined EBU_SDRMCON0 && defined __EBU_SDRMCON0_VALUE
        if(__EBU_SDRMCON0_INIT)  EBU_SDRMCON0.U = __EBU_SDRMCON0_VALUE;
#endif
#if defined EBU_SDRMCON1 && defined __EBU_SDRMCON1_VALUE
        if(__EBU_SDRMCON1_INIT)  EBU_SDRMCON1.U = __EBU_SDRMCON1_VALUE;
#endif
#if defined EBU_SDRMOD0 && defined __EBU_SDRMOD0_VALUE
        if(__EBU_SDRMOD0_INIT)  EBU_SDRMOD0.U = __EBU_SDRMOD0_VALUE;
#endif
#if defined EBU_SDRMOD1 && defined __EBU_SDRMOD1_VALUE
        if(__EBU_SDRMOD1_INIT)  EBU_SDRMOD1.U = __EBU_SDRMOD1_VALUE;
#endif
#if defined EBU_SDRMREF0 && defined __EBU_SDRMREF0_VALUE
        if(__EBU_SDRMREF0_INIT)  EBU_SDRMREF0.U = __EBU_SDRMREF0_VALUE;
#endif
#if defined EBU_SDRMREF1 && defined __EBU_SDRMREF1_VALUE
        if(__EBU_SDRMREF1_INIT)  EBU_SDRMREF1.U = __EBU_SDRMREF1_VALUE;
#endif
#if defined FBCU_CON && defined __FBCU_CON_VALUE
        if(__FBCU_CON_INIT)  FBCU_CON.U = __FBCU_CON_VALUE;
#endif
#if defined MCDBBS && defined __MCDBBS_VALUE
        if(__MCDBBS_INIT)  MCDBBS .U = __MCDBBS_VALUE;
#endif
#if defined SBCU_CON && defined __SBCU_CON_VALUE
        if(__SBCU_CON_INIT)  SBCU_CON.U = __SBCU_CON_VALUE;
#endif
        /*
         * TC112_COR15 workaround:
         * The starvation protection is disabled.
         */
#if __TC112_COR15_INITIAL__
#  if defined SBCU_CON
        SBCU_CON.U &= 0xfff7ffff;
#  endif
#endif
 
        /*
         * Initialize and clear C variables.
         */
#if __C_INIT
        _c_init();      /* initialize data */
#endif  

        /*
         * Call a user function before starting main().
         */
        // TODO: What to do with this function?
#if defined __CALL_INIT
        _call_init();        
#endif

        /* initialize profiling if required 
         */        
#ifdef __PROFILE_INIT__
        __prof_init();
#endif

        /*
         * Call C main program.
         */
#if __USE_ARGC_ARGV
        exit( main( _argcv( argcv, __ARGCV_BUFSIZE ), (char **)argcv ) );
#else
        exit( main( 0, argcv ) );                /* argc is 0 */
#endif

        /*
         * Default trap vectors are resolved from the C-library.
         */
#if __BTV_INIT
#  if __RESOLVE_TRAP_0
#    pragma extern  _trapmmu
#  endif
#  if __RESOLVE_TRAP_1
#    pragma extern  _trapprotection
#  endif
#  if __RESOLVE_TRAP_2
#    pragma extern  _trapinstruction
#  endif
#  if __RESOLVE_TRAP_3
#    pragma extern  _trapcontext
#  endif
#  if __RESOLVE_TRAP_4
#    pragma extern  _trapbus
#  endif
#  if __RESOLVE_TRAP_5
#    pragma extern  _trapassertion
#  endif
#  if __RESOLVE_TRAP_6
#    pragma extern  _trapsystem
#  endif
#  if __RESOLVE_TRAP_7
#    pragma extern  _trapnmi
#  endif
#endif
        
}

/**************************************************************************
 *
 * FUNCTION:     _endinit_clear
 *
 * DESCRIPTION:  Clears the ENDINIT bit in the WDT_CON0 register in order
 *               to disable the write-protection for registers protected
 *               via the EndInit feature (ie. WDT_CON1, BTV, BIV, ISP,
 *               mod_CLC).
 *
 *************************************************************************/
void _endinit_clear()
{
        unsigned int wdt_con0, wdt_con1;

        /*
         * 1st step: Password access (create password and send to WDT_CON0)
         */        
        wdt_con0 = WDT_CON0.U;
        wdt_con1 = WDT_CON1.U;

        wdt_con0 &= 0xffffff01;         /* clear WDTLCK, WDTHPW0, WDTHPW1 */
        wdt_con0 |= 0xf0;               /* set WDTHPW1 to 0xf */
        wdt_con1 &= 0x0c;               /* copy of WDT_CON1_WDTDR and WDT_CON1_WDTIR (d1) */
        wdt_con0 |= wdt_con1;           /* set WDTHPW1 to 0xf */
        WDT_CON0.U = wdt_con0;

        /*
         * 2nd step: Modify access, set the bit ENDINIT to 0 to allow access to
         *           registers: WDT_CON1, BTV, BIV, ISP and mod_CLC
         */
        wdt_con0 &= 0xfffffff0;         /* clear WDTHPW0, WDTLCK, ENDINIT  */
        wdt_con0 |= 0x02;               /* WDTHPW0=0, WDTLCK=1, ENDINIT=0 */
        __isync();
        WDT_CON0.U = wdt_con0;          
        wdt_con0 = WDT_CON0.U;          /* dummy read required */
}

/**************************************************************************
 *
 * FUNCTION:     _endinit_set
 *
 * DESCRIPTION:  Sets the ENDINIT bit in the WDT_CON0 register in order
 *               to enable the write-protection for registers protected
 *               via the EndInit feature (ie. WDT_CON1, BTV, BIV, ISP,
 *               mod_CLC).
 *
 *************************************************************************/
void _endinit_set()
{
        unsigned int wdt_con0, wdt_con1;

        /*
         * 1st step: Password access (create password and send to WDT_CON0)
         */        
        wdt_con0 = WDT_CON0.U;
        wdt_con1 = WDT_CON1.U;

        wdt_con0 &= 0xffffff01;         /* clear WDTLCK, WDTHPW0, WDTHPW1 */
        wdt_con0 |= 0xf0;               /* set WDTHPW1 to 0xf */
        wdt_con1 &= 0x0c;               /* copy of WDT_CON1_WDTDR and WDT_CON1_WDTIR (d1) */
        wdt_con0 |= wdt_con1;           /* set WDTHPW1 to 0xf */
        WDT_CON0.U = wdt_con0;

        /*
         * 2nd step: Modify access, set the bit ENDINIT to 1
         */
        wdt_con0 &= 0xfffffff0;         /* clear WDTHPW0, WDTLCK, ENDINIT  */
        wdt_con0 |= 0x03;               /* WDTHPW0=0, WDTLCK=1, ENDINIT=1 */
        __isync();
        WDT_CON0.U = wdt_con0;
}
