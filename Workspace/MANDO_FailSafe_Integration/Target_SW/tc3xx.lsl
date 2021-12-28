//****************************************************************************
//**                                                                         *
//**  FILE        :  tc3xx.lsl                                               *
//**                                                                         *
//**  DESCRIPTION :  LSL description: Infineon TC38X                         *
//**                 This 2nd Generation AURIX derivative has:               *
//**                            4 TriCore cores                              *
//**                            7 MCS cores                                  *
//**                            1 XC800 cores                                *
//**                 LSL description: Infineon TC39X                         *
//**                 This 2nd Generation AURIX derivative has:               *
//**                            6 TriCore cores                              *
//**                            10 MCS cores                                 *
//**                            1 XC800 cores                                *
//**                                                                         *
//**  Copyright 2011-2018 TASKING BV                                         *
//**                                                                         *
//****************************************************************************

#if defined(__PROC_TC38X__) || defined(__PROC_TC39X__) 
#include "tc1v1_6_2.lsl"
#define GTM_BASE_ADDR           0xf0100000
#define GTM_MCS_COPYTABLE_SPACE vtc:linear
#define GTM_CPU_ENDIANNESS little

#ifdef    __REDEFINE_ON_CHIP_ITEMS
#define GTM_REDEFINE_ON_CHIP_ITEMS
#endif  // __REDEFINE_ON_CHIP_ITEMS

#ifndef GTM_MCS_RAM0_SIZE
# define GTM_MCS_RAM0_SIZE              0x2000
#endif

#if defined(__PROC_TC38X__) 
#include "gtm31_07.lsl"
#elif defined(__PROC_TC39X__)
#include "gtm31_10.lsl"
#endif

#ifndef __VSTACK_XDATA
#define __VSTACK_XDATA 1k
#endif

#include "arch_scr2g.lsl"

#ifndef XC800INIT_FILL
#define XC800INIT_FILL          0
#endif

#define SCR_BASE_ADDR           0xf0240000

#ifndef    __REDEFINE_ON_CHIP_ITEMS

// Specify a multi-core processor environment (mpe)

processor mpe
{
#if defined(__PROC_TC38X__)
        derivative = tc38x;
#elif defined(__PROC_TC39X__)
        derivative = tc39x;
#endif
}
#endif  // __REDEFINE_ON_CHIP_ITEMS

#ifndef CSA_TC0
#define CSA_TC0         256                      /* number of context blocks tc0 */
#endif

#ifndef CSA_TC1
#define CSA_TC1         192                      /* number of context blocks tc1 */
#endif

#ifndef CSA_TC2
#define CSA_TC2         192                      /* number of context blocks tc2 */
#endif

#ifndef CSA_TC3
#define CSA_TC3         192                      /* number of context blocks tc3 */
#endif

#if defined(__PROC_TC39X__)
#ifndef CSA_TC4
#define CSA_TC4         192                      /* number of context blocks tc4 */
#endif

#ifndef CSA_TC5
#define CSA_TC5         192                      /* number of context blocks tc5 */
#endif
#endif

#ifndef CSA_START_TC0
#define CSA_START_TC0   0xd0004000              /* start address of CSA tc0 */
#endif

#ifndef CSA_START_TC1
#define CSA_START_TC1   0xd0004000              /* start address of CSA tc1 */
#endif

#ifndef CSA_START_TC2
#define CSA_START_TC2   0xd0004000              /* start address of CSA tc2 */
#endif

#ifndef CSA_START_TC3
#define CSA_START_TC3   0xd0004000              /* start address of CSA tc3 */
#endif
#if defined(__PROC_TC39X__)
#ifndef CSA_START_TC4
#define CSA_START_TC4   0xd0004000              /* start address of CSA tc4 */
#endif

#ifndef CSA_START_TC5
#define CSA_START_TC5   0xd0004000              /* start address of CSA tc5 */
#endif
#endif

#ifndef USTACK_TC0
#define USTACK_TC0      5k                     /* user stack size tc0 */
#endif

#ifndef USTACK_TC1
#define USTACK_TC1      1k                      /* user stack size tc1 */
#endif

#ifndef USTACK_TC2
#define USTACK_TC2      1k                      /* user stack size tc2 */
#endif

#ifndef USTACK_TC3
#define USTACK_TC3      1k                      /* user stack size tc3 */
#endif
#if defined(__PROC_TC39X__)
#ifndef USTACK_TC4
#define USTACK_TC4      1k                      /* user stack size tc4 */
#endif

#ifndef USTACK_TC5
#define USTACK_TC5      1k                      /* user stack size tc5 */
#endif
#endif

#ifndef ISTACK_TC0
#define ISTACK_TC0      5k                      /* interrupt stack size tc0 */
#endif

#ifndef ISTACK_TC1
#define ISTACK_TC1      15k                      /* interrupt stack size tc1 */
#endif

#ifndef ISTACK_TC2
#define ISTACK_TC2      10k                      /* interrupt stack size tc2 */
#endif

#ifndef ISTACK_TC3
#define ISTACK_TC3      5k                      /* interrupt stack size tc3 */
#endif
#if defined(__PROC_TC39X__)
#ifndef ISTACK_TC4
#define ISTACK_TC4      5k                      /* interrupt stack size tc4 */
#endif

#ifndef ISTACK_TC5
#define ISTACK_TC5      5k                      /* interrupt stack size tc5 */
#endif
#endif

#ifndef XVWBUF
#define XVWBUF          0                       /* buffer used by debugger */
#endif

#ifndef INTTAB
#define INTTAB          0x800f0000              /* start address of interrupt table */
#endif
#ifndef TRAPTAB
#if defined(__PROC_TC38X__)
#define TRAPTAB         (INTTAB + 0x8000)      /* start address of trap table */
#elif defined(__PROC_TC39X__)
#define TRAPTAB         (INTTAB + 0xc000)      /* start address of trap table */
#endif
#endif

#ifndef INTTAB0
#define INTTAB0         (INTTAB)
#endif
#ifndef INTTAB1
#define INTTAB1         (INTTAB0 + 0x2000)
#endif
#ifndef INTTAB2
#define INTTAB2         (INTTAB1 + 0x2000)
#endif
#ifndef INTTAB3
#define INTTAB3         (INTTAB2 + 0x2000)
#endif
#if defined(__PROC_TC39X__)
#ifndef INTTAB4
#define INTTAB4         (INTTAB3 + 0x2000)
#endif
#ifndef INTTAB5
#define INTTAB5         (INTTAB4 + 0x2000)
#endif
#endif

#ifndef TRAPTAB0
#define TRAPTAB0        (TRAPTAB)
#endif
#ifndef TRAPTAB1
#define TRAPTAB1        (TRAPTAB0 + 0x100)
#endif
#ifndef TRAPTAB2
#define TRAPTAB2        (TRAPTAB1 + 0x100)
#endif
#ifndef TRAPTAB3
#define TRAPTAB3        (TRAPTAB2 + 0x100)
#endif
#if defined(__PROC_TC39X__)
#ifndef TRAPTAB4
#define TRAPTAB4        (TRAPTAB3 + 0x100)
#endif
#ifndef TRAPTAB5
#define TRAPTAB5        (TRAPTAB4 + 0x100)
#endif
#endif

#ifndef RESET
#if defined(__FBL_USED__)
  #if defined(__HSM_USED__)
#define RESET           0x80048000              /* internal flash start address tc0 */
  #else
  #define RESET           0x80020000              /* internal flash start address tc0 */
  #endif
#else
#define RESET           0x80000000              /* internal flash start address tc0 */
#endif
#endif

/***********************************/
/* Because ECLIPSE is generating Ax_START instead of Ax_START_ADDRESS */
/***********************************/
#ifndef A0_START_ADDRESS
#ifdef  A0_START
#define A0_START_ADDRESS A0_START
#endif
#endif
#ifndef A1_START_ADDRESS
#ifdef  A1_START
#define A1_START_ADDRESS A1_START
#endif
#endif
#ifndef A8_START_ADDRESS
#ifdef  A8_START
#define A8_START_ADDRESS A8_START
#endif
#endif
#ifndef A9_START_ADDRESS
#ifdef  A9_START
#define A9_START_ADDRESS A9_START
#endif
#endif
/***********************************/

#if defined(__PROC_TC38X__)
derivative tc38x
extends gtm31_07
#elif defined(__PROC_TC39X__)
derivative tc39x
extends gtm31_10
#endif
{
        core tc0
        {
                architecture = TC1V1.6.2;
                space_id_offset = 100;  // add 100 to all space IDs in the architecture definition
                copytable_space = vtc:linear;   // use the copy table in the virtual core for 'bss' and initialized data sections
        }

        core tc1
        {
                architecture = TC1V1.6.2;
                space_id_offset = 200;  // add 200 to all space IDs in the architecture definition
                copytable_space = vtc:linear;   // use the copy table in the virtual core for 'bss' and initialized data sections
        }

        core tc2
        {
                architecture = TC1V1.6.2;
                space_id_offset = 300;  // add 300 to all space IDs in the architecture definition
                copytable_space = vtc:linear;   // use the copy table in the virtual core for 'bss' and initialized data sections
        }

        core tc3
        {
                architecture = TC1V1.6.2;
                space_id_offset = 400;  // add 400 to all space IDs in the architecture definition
                copytable_space = vtc:linear;   // use the copy table in the virtual core for 'bss' and initialized data sections
        }
#if defined(__PROC_TC39X__)
        core tc4
        {
                architecture = TC1V1.6.2;
                space_id_offset = 500;  // add 500 to all space IDs in the architecture definition
                copytable_space = vtc:linear;   // use the copy table in the virtual core for 'bss' and initialized data sections
        }

        core tc5
        {
                architecture = TC1V1.6.2;
                space_id_offset = 600;  // add 600 to all space IDs in the architecture definition
                copytable_space = vtc:linear;   // use the copy table in the virtual core for 'bss' and initialized data sections
        }
#endif

        core vtc
        {
                architecture = TC1V1.6.2;
                import tc0;                      // add all address spaces of core tc0 to core vtc for linking and locating
                import tc1;                      //                             tc1
                import tc2;                      //                             tc2
                import tc3;                      //                             tc3
#if defined(__PROC_TC39X__)
                import tc4;                      //                             tc4
                import tc5;                      //                             tc5
#endif
        }

        core xc800
        {
                architecture = scr2g;
        }

        bus sri
        {
                mau = 8;
                width = 32;

                // map shared addresses one-to-one to real cores and virtual core, segments starting from 0x0
                map (dest=bus:tc0:fpi_bus, src_offset=0, dest_offset=0, size=0x10000000);
                map (dest=bus:tc0:fpi_bus, src_offset=0x20000000, dest_offset=0x20000000, size=0x10000000);
                map (dest=bus:tc1:fpi_bus, src_offset=0, dest_offset=0, size=0x10000000);
                map (dest=bus:tc1:fpi_bus, src_offset=0x20000000, dest_offset=0x20000000, size=0x10000000);
                map (dest=bus:tc2:fpi_bus, src_offset=0, dest_offset=0, size=0x10000000);
                map (dest=bus:tc2:fpi_bus, src_offset=0x20000000, dest_offset=0x20000000, size=0x10000000);
                map (dest=bus:tc3:fpi_bus, src_offset=0, dest_offset=0, size=0x10000000);
                map (dest=bus:tc3:fpi_bus, src_offset=0x20000000, dest_offset=0x20000000, size=0x10000000);
#if defined(__PROC_TC39X__)
                map (dest=bus:tc4:fpi_bus, src_offset=0, dest_offset=0, size=0x10000000);
                map (dest=bus:tc4:fpi_bus, src_offset=0x20000000, dest_offset=0x20000000, size=0x10000000);
                map (dest=bus:tc5:fpi_bus, src_offset=0, dest_offset=0, size=0x10000000);
                map (dest=bus:tc5:fpi_bus, src_offset=0x20000000, dest_offset=0x20000000, size=0x10000000);
#endif
                map (dest=bus:vtc:fpi_bus, src_offset=0, dest_offset=0, size=0x10000000);
                map (dest=bus:vtc:fpi_bus, src_offset=0x20000000, dest_offset=0x20000000, size=0x10000000);

                // map shared addresses one-to-one to real cores and virtual core, segments starting from 0x8
                map (dest=bus:tc0:fpi_bus, src_offset=0x80000000, dest_offset=0x80000000, size=0x40000000);
                map (dest=bus:tc1:fpi_bus, src_offset=0x80000000, dest_offset=0x80000000, size=0x40000000);
                map (dest=bus:tc2:fpi_bus, src_offset=0x80000000, dest_offset=0x80000000, size=0x40000000);
                map (dest=bus:tc3:fpi_bus, src_offset=0x80000000, dest_offset=0x80000000, size=0x40000000);
#if defined(__PROC_TC39X__)
                map (dest=bus:tc4:fpi_bus, src_offset=0x80000000, dest_offset=0x80000000, size=0x40000000);
                map (dest=bus:tc5:fpi_bus, src_offset=0x80000000, dest_offset=0x80000000, size=0x40000000);
#endif
                map (dest=bus:vtc:fpi_bus, src_offset=0x80000000, dest_offset=0x80000000, size=0x40000000);

                // map shared addresses one-to-one to real cores and virtual core, segments starting from 0xe
                map (dest=bus:tc0:fpi_bus, src_offset=0xe0000000, dest_offset=0xe0000000, size=0x20000000);
                map (dest=bus:tc1:fpi_bus, src_offset=0xe0000000, dest_offset=0xe0000000, size=0x20000000);
                map (dest=bus:tc2:fpi_bus, src_offset=0xe0000000, dest_offset=0xe0000000, size=0x20000000);
                map (dest=bus:tc3:fpi_bus, src_offset=0xe0000000, dest_offset=0xe0000000, size=0x20000000);
#if defined(__PROC_TC39X__)
                map (dest=bus:tc4:fpi_bus, src_offset=0xe0000000, dest_offset=0xe0000000, size=0x20000000);
                map (dest=bus:tc5:fpi_bus, src_offset=0xe0000000, dest_offset=0xe0000000, size=0x20000000);
#endif
                map (dest=bus:vtc:fpi_bus, src_offset=0xe0000000, dest_offset=0xe0000000, size=0x20000000);
                
                // map local memory
                map (dest=bus:tc0:fpi_bus, src_offset=0x70000000, dest_offset=0x70000000, size=0x00100000, priority=2, exec_priority=0);
                map (dest=bus:tc1:fpi_bus, src_offset=0x60000000, dest_offset=0x60000000, size=0x00100000, priority=2, exec_priority=0);
                map (dest=bus:tc2:fpi_bus, src_offset=0x50000000, dest_offset=0x50000000, size=0x00100000, priority=2, exec_priority=0);
                map (dest=bus:tc3:fpi_bus, src_offset=0x40000000, dest_offset=0x40000000, size=0x00100000, priority=2, exec_priority=0);
#if defined(__PROC_TC39X__)
                map (dest=bus:tc4:fpi_bus, src_offset=0x30000000, dest_offset=0x30000000, size=0x00100000, priority=2, exec_priority=0);
                map (dest=bus:tc5:fpi_bus, src_offset=0x10000000, dest_offset=0x10000000, size=0x00100000, priority=2, exec_priority=0);
#endif
                map (dest=bus:tc0:fpi_bus, src_offset=0x70100000, dest_offset=0x70100000, size=0xff00000, exec_priority=2);
                map (dest=bus:tc1:fpi_bus, src_offset=0x60100000, dest_offset=0x60100000, size=0xff00000, exec_priority=2);
                map (dest=bus:tc2:fpi_bus, src_offset=0x50100000, dest_offset=0x50100000, size=0xff00000, exec_priority=2);
                map (dest=bus:tc3:fpi_bus, src_offset=0x40100000, dest_offset=0x40100000, size=0xff00000, exec_priority=2);
#if defined(__PROC_TC39X__)
                map (dest=bus:tc4:fpi_bus, src_offset=0x30100000, dest_offset=0x30100000, size=0xff00000, exec_priority=2);
                map (dest=bus:tc5:fpi_bus, src_offset=0x10100000, dest_offset=0x10100000, size=0xff00000, exec_priority=2);
#endif
                map (dest=bus:tc0:fpi_bus, src_offset=0x10000000, dest_offset=0x10000000, size=0x10000000);
                map (dest=bus:tc0:fpi_bus, src_offset=0x30000000, dest_offset=0x30000000, size=0x40000000);
                map (dest=bus:tc1:fpi_bus, src_offset=0x10000000, dest_offset=0x10000000, size=0x10000000);
                map (dest=bus:tc1:fpi_bus, src_offset=0x30000000, dest_offset=0x30000000, size=0x30000000);
                map (dest=bus:tc1:fpi_bus, src_offset=0x70000000, dest_offset=0x70000000, size=0x10000000);
                map (dest=bus:tc2:fpi_bus, src_offset=0x10000000, dest_offset=0x10000000, size=0x10000000);
                map (dest=bus:tc2:fpi_bus, src_offset=0x30000000, dest_offset=0x30000000, size=0x20000000);
                map (dest=bus:tc2:fpi_bus, src_offset=0x60000000, dest_offset=0x60000000, size=0x20000000);
                map (dest=bus:tc3:fpi_bus, src_offset=0x10000000, dest_offset=0x10000000, size=0x10000000);
                map (dest=bus:tc3:fpi_bus, src_offset=0x30000000, dest_offset=0x30000000, size=0x10000000);
                map (dest=bus:tc3:fpi_bus, src_offset=0x50000000, dest_offset=0x50000000, size=0x30000000);
#if defined(__PROC_TC39X__)
                map (dest=bus:tc4:fpi_bus, src_offset=0x10000000, dest_offset=0x10000000, size=0x10000000);
                map (dest=bus:tc4:fpi_bus, src_offset=0x40000000, dest_offset=0x40000000, size=0x40000000);
                map (dest=bus:tc5:fpi_bus, src_offset=0x30000000, dest_offset=0x30000000, size=0x50000000);
                map (dest=bus:vtc:fpi_bus, src_offset=0x10000000, dest_offset=0x10000000, size=0x10000000);
#endif
                map (dest=bus:vtc:fpi_bus, src_offset=0x30000000, dest_offset=0x30000000, size=0x50000000);
                map (dest=bus:aei, src_offset=GTM_BASE_ADDR, dest_offset=0, size=0x100000000-GTM_BASE_ADDR);
                map (dest=bus:xc800:code_bus, src_offset=SCR_BASE_ADDR, dest_offset=0, size=8k);
        }

#ifndef    __REDEFINE_ON_CHIP_ITEMS
#ifndef __CPP_RUN_TIME_ENTRY_FLAG 
#define __CPP_RUN_TIME_ENTRY_FLAG mem:dspr0
#endif 

        section_layout :vtc:linear
        {
                group (ordered, run_addr=__CPP_RUN_TIME_ENTRY_FLAG)
                {
                        // C++ run-time variable "main_called" that ensures the global object constructors to execute exactly once.
                        // main_called is initialized so its name gets a data prefix: .sect '.data.__section_main_called' 
                        select ".data.__section_main_called"; 
                        // C++ run-time variables to make destructors concurrent
                        select ".data.__section_dtor_finalizer"; 
                }
        }
#endif  // __REDEFINE_ON_CHIP_ITEMS

#ifndef    __REDEFINE_ON_CHIP_ITEMS


        memory dspr0 // Data Scratch Pad Ram CPU0
        {
                mau = 8;
                size = 240k;
                type = ram;
                map (dest=bus:tc0:fpi_bus, dest_offset=0xd0000000, size=240k, priority=1, exec_priority=0);
                map (dest=bus:sri, dest_offset=0x70000000, size=240k);
        }

        memory pspr0 // Program Scratch Pad Ram CPU0
        {
                mau = 8;
                size = 64k;
                type = ram;
                map (dest=bus:tc0:fpi_bus, dest_offset=0xc0000000, size=64k, exec_priority=1);
                map (dest=bus:sri, dest_offset=0x70100000, size=64k);
        }

        memory dspr1 // Data Scratch Pad Ram CPU1
        {
                mau = 8;
                size = 240k;
                type = ram;
                map (dest=bus:tc1:fpi_bus, dest_offset=0xd0000000, size=240k, priority=1, exec_priority=0);
                map (dest=bus:sri, dest_offset=0x60000000, size=240k);
        }

        memory pspr1 // Program Scratch Pad Ram CPU1
        {
                mau = 8;
                size = 64k;
                type = ram;
                map (dest=bus:tc1:fpi_bus, dest_offset=0xc0000000, size=64k, exec_priority=1);
                map (dest=bus:sri, dest_offset=0x60100000, size=64k);
        }

        memory dspr2 // Data Scratch Pad Ram CPU2
        {
                mau = 8;
                size = 96k;
                type = ram;
                map (dest=bus:tc2:fpi_bus, dest_offset=0xd0000000, size=96k, priority=1, exec_priority=0);
                map (dest=bus:sri, dest_offset=0x50000000, size=96k);
        }

        memory pspr2 // Program Scratch Pad Ram CPU2
        {
                mau = 8;
                size = 64k;
                type = ram;
                map (dest=bus:tc2:fpi_bus, dest_offset=0xc0000000, size=64k, exec_priority=1);
                map (dest=bus:sri, dest_offset=0x50100000, size=64k);
        }

        memory dspr3 // Data Scratch Pad Ram CPU3
        {
                mau = 8;
                size = 96k;
                type = ram;
                map (dest=bus:tc3:fpi_bus, dest_offset=0xd0000000, size=96k, priority=1, exec_priority=0);
                map (dest=bus:sri, dest_offset=0x40000000, size=96k);
        }

        memory pspr3 // Program Scratch Pad Ram CPU3
        {
                mau = 8;
                size = 64k;
                type = ram;
                map (dest=bus:tc3:fpi_bus, dest_offset=0xc0000000, size=64k, exec_priority=1);
                map (dest=bus:sri, dest_offset=0x40100000, size=64k);
        }
#if defined(__PROC_TC39X__)
        memory dspr4 // Data Scratch Pad Ram CPU4
        {
                mau = 8;
                size = 96k;
                type = ram;
                map (dest=bus:tc4:fpi_bus, dest_offset=0xd0000000, size=96k, priority=1, exec_priority=0);
                map (dest=bus:sri, dest_offset=0x30000000, size=96k);
        }

        memory pspr4 // Program Scratch Pad Ram CPU4
        {
                mau = 8;
                size = 64k;
                type = ram;
                map (dest=bus:tc4:fpi_bus, dest_offset=0xc0000000, size=64k, exec_priority=1);
                map (dest=bus:sri, dest_offset=0x30100000, size=64k);
        }

        memory dspr5 // Data Scratch Pad Ram CPU5
        {
                mau = 8;
                size = 96k;
                type = ram;
                map (dest=bus:tc5:fpi_bus, dest_offset=0xd0000000, size=96k, priority=1, exec_priority=0);
                map (dest=bus:sri, dest_offset=0x10000000, size=96k);
        }

        memory pspr5 // Program Scratch Pad Ram CPU5
        {
                mau = 8;
                size = 64k;
                type = ram;
                map (dest=bus:tc5:fpi_bus, dest_offset=0xc0000000, size=64k, exec_priority=1);
                map (dest=bus:sri, dest_offset=0x10100000, size=64k);
        }
#endif


#if (defined(__PROC_TC39X__) && (__TC39X_OTA__ == 1))
        memory pflash0 // Program Flash CPU0 // Sector A : pflash0 ~ pflash1
        { 
                mau = 8;
                size = 3M; //DH
                type = rom;
                map     cached (dest=bus:sri, dest_offset=0x80000000,           size=3M); //DH
                map not_cached (dest=bus:sri, dest_offset=0xa0000000, reserved, size=3M); //DH
        }
        memory pflash1 // Program Flash CPU1
        {
                mau = 8;
                size = 1M; //DH
                type = rom;
                map     cached (dest=bus:sri, dest_offset=0x80300000,           size=1M); //DH
                map not_cached (dest=bus:sri, dest_offset=0xa0300000, reserved, size=1M); //DH
        }
#else
        memory pflash0 // Program Flash CPU0
        {
                mau = 8;
                size = 3M;
                type = rom;
                map     cached (dest=bus:sri, dest_offset=0x80000000,           size=3M);
                map not_cached (dest=bus:sri, dest_offset=0xa0000000, reserved, size=3M);
        }
        memory pflash1 // Program Flash CPU1
        {
                mau = 8;
                size = 3M;
                type = rom;
                map     cached (dest=bus:sri, dest_offset=0x80300000,           size=3M);
                map not_cached (dest=bus:sri, dest_offset=0xa0300000, reserved, size=3M);
        }
        memory pflash2 // Program Flash CPU2
        {
                mau = 8;
                size = 3M;
                type = rom;
                map     cached (dest=bus:sri, dest_offset=0x80600000,           size=3M);
                map not_cached (dest=bus:sri, dest_offset=0xa0600000, reserved, size=3M);
        }
#if defined(__PROC_TC38X__)
        memory pflash3 // Program Flash CPU3
        {
                mau = 8;
                size = 1M;
                type = rom;
                map     cached (dest=bus:sri, dest_offset=0x80900000,           size=1M);
                map not_cached (dest=bus:sri, dest_offset=0xa0900000, reserved, size=1M);
        }
#elif defined(__PROC_TC39X__)
        memory pflash3 // Program Flash CPU3
        {
                mau = 8;
                size = 3M;
                type = rom;
                map     cached (dest=bus:sri, dest_offset=0x80900000,           size=3M);
                map not_cached (dest=bus:sri, dest_offset=0xa0900000, reserved, size=3M);
        }
        memory pflash4 // Program Flash CPU4
        {
                mau = 8;
                size = 3M;
                type = rom;
                map     cached (dest=bus:sri, dest_offset=0x80c00000,           size=3M);
                map not_cached (dest=bus:sri, dest_offset=0xa0c00000, reserved, size=3M);
        }
        memory pflash5 // Program Flash CPU5
        {
                mau = 8;
                size = 1M;
                type = rom;
                map     cached (dest=bus:sri, dest_offset=0x80f00000,           size=1M);
                map not_cached (dest=bus:sri, dest_offset=0xa0f00000, reserved, size=1M);
        }
#endif
#endif

        memory brom
        {
                mau = 8;
                size = 64k;
                type = reserved rom;
                map     cached (dest=bus:sri, dest_offset=0x8fff0000,           size=64k);
                map not_cached (dest=bus:sri, dest_offset=0xafff0000, reserved, size=64k);
        }

#if defined(__PROC_TC38X__)
        memory dflash0
        {
                mau = 8;
                size = 512k;
                type = reserved nvram;
                map (dest=bus:sri, dest_offset=0xaf000000, size=512k);
        }
#elif defined(__PROC_TC39X__)
        memory dflash0
        {
                mau = 8;
                size = 1024k;
                type = reserved nvram;
                map (dest=bus:sri, dest_offset=0xaf000000, size=1024k);
        }
#endif

        memory dflash0_ucb
        {
                mau = 8;
                size = 24k;
                type = reserved nvram;
                map (dest=bus:sri, dest_offset=0xaf400000, size=24k);
        }

        memory dflash0_cfs
        {
                mau = 8;
                size = 64k;
                type = reserved nvram;
                map (dest=bus:sri, dest_offset=0xaf800000, size=64k);
        }

        memory dflash1
        {
                mau = 8;
                size = 128k;
                type = reserved nvram;
                map (dest=bus:sri, dest_offset=0xafc00000, size=128k);
        }


        memory dlmucpu0 // DLMU CPU0
        {
                mau = 8;
                size = 64k;
                type = ram;
                map     cached (dest=bus:sri, dest_offset=0x90000000,           size=64k);
                map not_cached (dest=bus:sri, dest_offset=0xb0000000, reserved, size=64k);
        }
        memory dlmucpu1 // DLMU CPU1
        {
                mau = 8;
                size = 64k;
                type = ram;
                map     cached (dest=bus:sri, dest_offset=0x90010000,           size=64k);
                map not_cached (dest=bus:sri, dest_offset=0xb0010000, reserved, size=64k);
        }
        memory dlmucpu2 // DLMU CPU2
        {
                mau = 8;
                size = 64k;
                type = ram;
                map     cached (dest=bus:sri, dest_offset=0x90020000,           size=64k);
                map not_cached (dest=bus:sri, dest_offset=0xb0020000, reserved, size=64k);
        }
        memory dlmucpu3 // DLMU CPU3
        {
                mau = 8;
                size = 64k;
                type = ram;
                map     cached (dest=bus:sri, dest_offset=0x90030000,           size=64k);
                map not_cached (dest=bus:sri, dest_offset=0xb0030000, reserved, size=64k);
        }
#if defined(__PROC_TC39X__)
        memory dlmucpu4 // DLMU CPU4
        {
                mau = 8;
                size = 64k;
                type = ram;
                map     cached (dest=bus:sri, dest_offset=0x90100000,           size=64k);
                map not_cached (dest=bus:sri, dest_offset=0xb0100000, reserved, size=64k);
        }
        memory dlmucpu5 // DLMU CPU5
        {
                mau = 8;
                size = 64k;
                type = ram;
                map     cached (dest=bus:sri, dest_offset=0x90110000,           size=64k);
                map not_cached (dest=bus:sri, dest_offset=0xb0110000, reserved, size=64k);
        }
#endif

#if defined(__PROC_TC38X__)
        memory lmuram0
        {
                mau = 8;
                size = 128k;
                type = ram;
                priority = 2;
                map     cached (dest=bus:sri, dest_offset=0x90040000,           size=0k);
                map not_cached (dest=bus:sri, dest_offset=0xb0040000, reserved, size=0k);
        }
#elif defined(__PROC_TC39X__)	
        memory lmuram0
        {
                mau = 8;
                size = 256k;
                type = ram;
                priority = 2;
                map     cached (dest=bus:sri, dest_offset=0x90040000,           size=0k);
                map not_cached (dest=bus:sri, dest_offset=0xb0040000, reserved, size=0k);
        }
        memory lmuram1
        {
                mau = 8;
                size = 256k;
                type = reserved ram; /* only 256k global lmuram available because of erratum LMU_TC.002 according to documentation */
                map     cached (dest=bus:sri, dest_offset=0x90080000,           size=0k);
                map not_cached (dest=bus:sri, dest_offset=0xb0080000, reserved, size=0k);
        }
        memory lmuram2
        {
                mau = 8;
                size = 256k;
                type = reserved ram; /* only 256k global lmuram available because of erratum LMU_TC.002 according to documentation */
                map     cached (dest=bus:sri, dest_offset=0x900c0000,           size=0k);
                map not_cached (dest=bus:sri, dest_offset=0xb00c0000, reserved, size=0k);
        }
#endif


        memory dam0ram0
        {
                mau = 8;
                size = 32k;
                type = reserved ram;
                map     cached (dest=bus:sri, dest_offset=0x90400000,           size=0k);
                map not_cached (dest=bus:sri, dest_offset=0xb0400000, reserved, size=0k);
        }
        memory dam0ram1
        {
                mau = 8;
                size = 32k;
                type = reserved ram;
                map     cached (dest=bus:sri, dest_offset=0x90408000,           size=0k);
                map not_cached (dest=bus:sri, dest_offset=0xb0408000, reserved, size=0k);
        }
#if defined(__PROC_TC39X__)	
        memory dam1ram0
        {
                mau = 8;
                size = 32k;
                type = reserved ram;
                map     cached (dest=bus:sri, dest_offset=0x90410000,           size=0k);
                map not_cached (dest=bus:sri, dest_offset=0xb0410000, reserved, size=0k);
        }
        memory dam1ram1
        {
                mau = 8;
                size = 32k;
                type = reserved ram;
                map     cached (dest=bus:sri, dest_offset=0x90418000,           size=0k);
                map not_cached (dest=bus:sri, dest_offset=0xb0418000, reserved, size=0k);
        }
#endif

        memory tram
        {
                mau = 8;
                size = 8k;
                type = reserved ram;
                map     cached (dest=bus:sri, dest_offset=0x98000000,           size=8k);
                map not_cached (dest=bus:sri, dest_offset=0xb8000000, reserved, size=8k);
        }

#if defined(__PROC_TC39X__)	
        memory emem0
        {
                mau = 8;
                size = 1M;
                type = reserved ram;
                map     cached (dest=bus:sri, dest_offset=0x99000000,           size=0M);
                map not_cached (dest=bus:sri, dest_offset=0xb9000000, reserved, size=0M);
        }
        memory emem1
        {
                mau = 8;
                size = 1M;
                type = reserved ram;
                map     cached (dest=bus:sri, dest_offset=0x99100000,           size=0M);
                map not_cached (dest=bus:sri, dest_offset=0xb9100000, reserved, size=0M);
        }
        memory emem2
        {
                mau = 8;
                size = 1M;
                type = reserved ram;
                map     cached (dest=bus:sri, dest_offset=0x99200000,           size=0M);
                map not_cached (dest=bus:sri, dest_offset=0xb9200000, reserved, size=0M);
        }
        memory emem3
        {
                mau = 8;
                size = 1M;
                type = reserved ram;
                map     cached (dest=bus:sri, dest_offset=0x99300000,           size=0M);
                map not_cached (dest=bus:sri, dest_offset=0xb9300000, reserved, size=0M);
        }


        memory xtm
        {
                mau = 8;
                size = 512k;
                type = reserved ram;
                map (dest=bus:sri, dest_offset=0xb9400000, size=512k);
        }
#endif

        memory scr_iram
        {
            mau = 8;
            type = ram;
            size = 256;
            map ( dest=bus:xc800:idata_bus, src_offset=0x0, dest_offset=0x0, size=256 );
        }
        memory scr_xram
        {
            mau = 8;
            type = nvram;
            size = 8k;
            map ( dest=bus:xc800:xdata_bus, src_offset=0x0, dest_offset=0x0, size=8k );
            map ( dest=bus:xc800:code_bus, src_offset=0x0, dest_offset=0x0, size=8k );
        }
        memory scr_bootrom
        {
            mau = 8;
            type = reserved rom;
            size = 2k;
            map ( dest=bus:xc800:code_bus, src_offset=0x0, dest_offset=0xd000, size=2k );
        }

#endif  // __REDEFINE_ON_CHIP_ITEMS

        section_setup :vtc:linear
        {
#ifndef __LINKONLY__
                start_address
                (
                        symbol = "_START"
                );
#endif
        }

        section_setup :tc0:linear
        {
                stack "ustack_tc0"
                (
                        min_size = (USTACK_TC0),
                        fixed,
                        align = 8,
                        id = 0
                );

                stack "istack_tc0"
                (
                        min_size = (ISTACK_TC0),
                        fixed,
                        align = 8,
                        id = 1
                );
        }

        section_setup :tc1:linear
        {
                stack "ustack_tc1"
                (
                        min_size = (USTACK_TC1),
                        fixed,
                        align = 8,
                        id = 2
                );

                stack "istack_tc1"
                (
                        min_size = (ISTACK_TC1),
                        fixed,
                        align = 8,
                        id = 3
                );
        }

        section_setup :tc2:linear
        {
                stack "ustack_tc2"
                (
                        min_size = (USTACK_TC2),
                        fixed,
                        align = 8,
                        id = 4
                );

                stack "istack_tc2"
                (
                        min_size = (ISTACK_TC2),
                        fixed,
                        align = 8,
                        id = 5
                );
        }

        section_setup :tc3:linear
        {
                stack "ustack_tc3"
                (
                        min_size = (USTACK_TC3),
                        fixed,
                        align = 8,
                        id = 6
                );

                stack "istack_tc3"
                (
                        min_size = (ISTACK_TC3),
                        fixed,
                        align = 8,
                        id = 7
                );
        }
#if defined(__PROC_TC39X__)
        section_setup :tc4:linear
        {
                stack "ustack_tc4"
                (
                        min_size = (USTACK_TC4),
                        fixed,
                        align = 8,
                        id = 8
                );

                stack "istack_tc4"
                (
                        min_size = (ISTACK_TC4),
                        fixed,
                        align = 8,
                        id = 9
                );
        }

        section_setup :tc5:linear
        {
                stack "ustack_tc5"
                (
                        min_size = (USTACK_TC5),
                        fixed,
                        align = 8,
                        id = 10
                );

                stack "istack_tc5"
                (
                        min_size = (ISTACK_TC5),
                        fixed,
                        align = 8,
                        id = 11
                );
        }
#endif
        section_layout :tc0:linear
        {
                "_lc_ue_ustack" := "_lc_ue_ustack_tc0"; /* common cstart interface for first or single core */
                "_lc_ue_istack" := "_lc_ue_istack_tc0"; /* common cstart interface for first or single core */
        }

        section_setup :vtc:linear
        {
                copytable
                (
                        align = 4,
                        dest = linear
                        ,
                        table
                        {
                                symbol = "_lc_ub_table_tc1";
                                space = :tc1:linear, :tc1:abs24, :tc1:abs18, :tc1:csa;
                        }
                        ,
                        table
                        {
                                symbol = "_lc_ub_table_tc2";
                                space = :tc2:linear, :tc2:abs24, :tc2:abs18, :tc2:csa;
                        }
                        ,
                        table
                        {
                                symbol = "_lc_ub_table_tc3";
                                space = :tc3:linear, :tc3:abs24, :tc3:abs18, :tc3:csa;
                        }
#if defined(__PROC_TC39X__)
                        ,
                        table
                        {
                                symbol = "_lc_ub_table_tc4";
                                space = :tc4:linear, :tc4:abs24, :tc4:abs18, :tc4:csa;
                        }
                        ,
                        table
                        {
                                symbol = "_lc_ub_table_tc5";
                                space = :tc5:linear, :tc5:abs24, :tc5:abs18, :tc5:csa;
                        }
#endif
                );

                mpu_data_table;
        }
        section_layout :tc0:csa
        {
                group  (ordered, align = 64, attributes=rw, run_addr=(CSA_START_TC0))
                        reserved "csa_tc0" (size = 64 * (CSA_TC0));
                "_lc_ub_csa_01" := "_lc_ub_csa_tc0"; /* common cstart interface for first or single core */
                "_lc_ue_csa_01" := "_lc_ue_csa_tc0"; /* common cstart interface for first or single core */
        }

        section_layout :tc1:csa
        {
                group  (ordered, align = 64, attributes=rw, run_addr=(CSA_START_TC1))
                        reserved "csa_tc1" (size = 64 * (CSA_TC1));
        }

        section_layout :tc2:csa
        {
                group  (ordered, align = 64, attributes=rw, run_addr=(CSA_START_TC2))
                        reserved "csa_tc2" (size = 64 * (CSA_TC2));
        }

        section_layout :tc3:csa
        {
                group  (ordered, align = 64, attributes=rw, run_addr=(CSA_START_TC3))
                        reserved "csa_tc3" (size = 64 * (CSA_TC3));
        }
#if defined(__PROC_TC39X__)
        section_layout :tc4:csa
        {
                group  (ordered, align = 64, attributes=rw, run_addr=(CSA_START_TC4))
                        reserved "csa_tc4" (size = 64 * (CSA_TC4));
        }

        section_layout :tc5:csa
        {
                group  (ordered, align = 64, attributes=rw, run_addr=(CSA_START_TC5))
                        reserved "csa_tc5" (size = 64 * (CSA_TC5));
        }
#endif
        section_layout :vtc:linear
        {
#if (XVWBUF>0)
                group (align = 4) reserved "_xvwbuffer_" (size=XVWBUF, attributes=rw);
                "_lc_ub_xvwbuffer" = "_lc_ub__xvwbuffer_";
                "_lc_ue_xvwbuffer" = "_lc_ue__xvwbuffer_";
#endif

#ifndef __REDEFINE_BASE_ADDRESS_GROUPS
#include        "base_address_groups.lsl"
#endif

                "_SMALL_DATA_TC0" := "_SMALL_DATA_";
                "_SMALL_DATA_TC1" := "_SMALL_DATA_";
                "_SMALL_DATA_TC2" := "_SMALL_DATA_";
                "_SMALL_DATA_TC3" := "_SMALL_DATA_";
#if defined(__PROC_TC39X__)
                "_SMALL_DATA_TC4" := "_SMALL_DATA_";
                "_SMALL_DATA_TC5" := "_SMALL_DATA_";
#endif

                "_LITERAL_DATA_TC0" := "_LITERAL_DATA_";
                "_LITERAL_DATA_TC1" := "_LITERAL_DATA_";
                "_LITERAL_DATA_TC2" := "_LITERAL_DATA_";
                "_LITERAL_DATA_TC3" := "_LITERAL_DATA_";
#if defined(__PROC_TC39X__)
                "_LITERAL_DATA_TC4" := "_LITERAL_DATA_";
                "_LITERAL_DATA_TC5" := "_LITERAL_DATA_";
#endif

                "_A8_DATA_TC0" := "_A8_DATA_";
                "_A8_DATA_TC1" := "_A8_DATA_";
                "_A8_DATA_TC2" := "_A8_DATA_";
                "_A8_DATA_TC3" := "_A8_DATA_";
#if defined(__PROC_TC39X__)
                "_A8_DATA_TC4" := "_A8_DATA_";
                "_A8_DATA_TC5" := "_A8_DATA_";
#endif

                "_A9_DATA_TC0" := "_A9_DATA_";
                "_A9_DATA_TC1" := "_A9_DATA_";
                "_A9_DATA_TC2" := "_A9_DATA_";
                "_A9_DATA_TC3" := "_A9_DATA_";
#if defined(__PROC_TC39X__)
                "_A9_DATA_TC4" := "_A9_DATA_";
                "_A9_DATA_TC5" := "_A9_DATA_";
#endif
        }

        section_layout :vtc:linear
        {
                        "_lc_u_int_tab_tc0" = (INTTAB0);
                        "_lc_u_int_tab_tc1" = (INTTAB1);
                        "_lc_u_int_tab_tc2" = (INTTAB2);
                        "_lc_u_int_tab_tc3" = (INTTAB3);
#if defined(__PROC_TC39X__)
                        "_lc_u_int_tab_tc4" = (INTTAB4);
                        "_lc_u_int_tab_tc5" = (INTTAB5);
#endif
                        "_lc_u_int_tab" = "_lc_u_int_tab_tc0"; /* common cstart interface for first or single core */

                        // interrupt vector tables
                        group int_tab_tc0 (ordered)
                        {
#                               include "inttab0.lsl"
                        }
                        group int_tab_tc1 (ordered)
                        {
#                               include "inttab1.lsl"
                        }
                        group int_tab_tc2 (ordered)
                        {
#                               include "inttab2.lsl"
                        }
                        group int_tab_tc3 (ordered)
                        {
#                               include "inttab3.lsl"
                        }
#if defined(__PROC_TC39X__)
                        group int_tab_tc4 (ordered)
                        {
#                               include "inttab4.lsl"
                        }
                        group int_tab_tc5 (ordered)
                        {
#                               include "inttab5.lsl"
                        }
#endif
                        "_lc_u_trap_tab_tc0" = (TRAPTAB0);
                        "_lc_u_trap_tab_tc1" = (TRAPTAB1);
                        "_lc_u_trap_tab_tc2" = (TRAPTAB2);
                        "_lc_u_trap_tab_tc3" = (TRAPTAB3);
#if defined(__PROC_TC39X__)
                        "_lc_u_trap_tab_tc4" = (TRAPTAB4);
                        "_lc_u_trap_tab_tc5" = (TRAPTAB5);
#endif
                        "_lc_u_trap_tab" = "_lc_u_trap_tab_tc0"; /* common cstart interface for first or single core */

                        // trapvector tables
                        group trap_tab_tc0 (ordered)
                        {
#                               include "traptab0.lsl"
                        }
                        group trap_tab_tc1 (ordered)
                        {
#                               include "traptab1.lsl"
                        }
                        group trap_tab_tc2 (ordered)
                        {
#                               include "traptab2.lsl"
                        }
                        group trap_tab_tc3 (ordered)
                        {
#                               include "traptab3.lsl"
                        }
#if defined(__PROC_TC39X__)
                        group trap_tab_tc4 (ordered)
                        {
#                               include "traptab4.lsl"
                        }
                        group trap_tab_tc5 (ordered)
                        {
#                               include "traptab5.lsl"
                        }
#endif
        }

        section_layout :vtc:linear
        {
#include        "tc1v1_6_2.bmhd.lsl"

                group RESET_VECTOR(ordered, contiguous, run_addr = RESET, fill)
                {
                        section "RESET_VECTOR" (size = 0x20, attributes = rx, fill)
                        {
                                select ".text._START.libc.reset";
                        }
                }
    #if defined(__FBL_USED__)
    group (ordered, contiguous, run_addr = RESET + 0x20, align = 4)
    {
      /* RESET + 0x20 */
      section "MAINSW_MODULE_INFO" (size = 0x10, attributes = r, fill)
      {
        select ".rodata.MAINSW_MODULE_INFO";
      }
    }
    group (ordered, contiguous, run_addr = RESET + 0x100, align = 4)
    {
      /* RESET + 0x100 */
      section "MAINSW_SECURITY_KEY" (size = 0x100, attributes = r, fill)
      {
        select ".rodata.MAINSW_SECURITY_KEY";
      }
    }
    group (ordered, contiguous, run_addr = RESET + 0x200, align = 4)
    {
      /* RESET + 0x200 */
      section "MAINSW_CRC" (size = 0x100, attributes = r, fill)
      {
        select ".rodata.MAINSW_CRC";
      }
    }
    #endif
                
#ifndef NOXC800INIT
    group (ordered, run_addr = RESET+0x300, align=4)
    {
      memcopy ".rodata.xc800init" (memory = scr_xram, fill=XC800INIT_FILL);
    }
#endif
                /*Fixed memory Allocations for BMHD*/
                group (ordered)
                {
                        group  bmh_0_orig (run_addr=0xAF400000)
                        {
                                select ".rodata.bmhd_0_orig";
                        }
                        group  bmh_1_orig (run_addr=0xAF400200)
                        {
                                select ".rodata.bmhd_1_orig";
                        }
                        group  bmh_2_orig (run_addr=0xAF400400)
                        {
                                select ".rodata.bmhd_2_orig";
                        }
                        group  bmh_3_orig (run_addr=0xAF400600)
                        {
                                select ".rodata.bmhd_3_orig";
                        }
                        group  bmh_blank (run_addr=0xAF400800)
                        {
                        }
                        group  bmh_0_copy (run_addr=0xAF401000)
                        {
                                select ".rodata.bmhd_0_copy";
                        }
                        group  bmh_1_copy (run_addr=0xAF401200)
                        {
                                select ".rodata.bmhd_1_copy";
                        }
                        group  bmh_2_copy (run_addr=0xAF401400)
                        {
                                select ".rodata.bmhd_2_copy";
                        }
                        group  bmh_3_copy (run_addr=0xAF401600)
                        {
                                select ".rodata.bmhd_3_copy";
                        }
                }
			    
                /* ROM - Calibration DATA */
    group CALROMDATA0 (ordered, contiguous, align = 0, run_addr = 0xA0300000)
                {
                        group (ordered)
                        {
                                section "OverlayCalRom" (size = 128k, attributes = rx, fill)
                                {
                                        select ".rodata.RTE_ROM_CALIB_BOOLEAN";
                                        select ".rodata.RTE_ROM_CALIB_8";
                                        select ".rodata.RTE_ROM_CALIB_16";
                                        select ".rodata.RTE_ROM_CALIB_32";
                                        select ".rodata.RTE_ROM_CALIB_UNSPECIFIED";
                                        select ".*.EcucPartition_Main_ROM_CALIB_BOOLEAN";
                                        select ".*.EcucPartition_Main_ROM_CALIB_8";
                                        select ".*.EcucPartition_Main_ROM_CALIB_16";
                                        select ".*.EcucPartition_Main_ROM_CALIB_32";
                                        select ".*.EcucPartition_Main_ROM_CALIB_UNSPECIFIED";
                                        select ".*.EcucPartition_Sub1_ROM_CALIB_BOOLEAN";
                                        select ".*.EcucPartition_Sub1_ROM_CALIB_8";
                                        select ".*.EcucPartition_Sub1_ROM_CALIB_16";
                                        select ".*.EcucPartition_Sub1_ROM_CALIB_32";
                                        select ".*.EcucPartition_Sub1_ROM_CALIB_UNSPECIFIED";
                                        select ".*.EcucPartition_Sub2_ROM_CALIB_BOOLEAN";
                                        select ".*.EcucPartition_Sub2_ROM_CALIB_8";
                                        select ".*.EcucPartition_Sub2_ROM_CALIB_16";
                                        select ".*.EcucPartition_Sub2_ROM_CALIB_32";
                                        select ".*.EcucPartition_Sub2_ROM_CALIB_UNSPECIFIED";	
                                }
                        }
                }

                /* ROM - TEXT, RODATA, RAMDATA(REALLOC) */
                //For T1 Integration
                group T1_RAMCODE (copy, ordered, run_addr = mem:pspr0)
                {
                        select ".text.share.T1_codeFast*";
                }
                //For T1 Integration
                group T1_BSS_CORE0 (ordered, align = 8, run_addr = mem:dspr0)
                {
                        select ".bss.*.T1_bss*";
                        select ".bss.*.T1_traceBuffer0";
                }
                group T1_BSS_CORE1 (ordered, align = 8, run_addr = mem:dspr1)
                {
                        select ".bss.*.T1_traceBuffer1";
                }
                group T1_BSS_CORE2 (ordered, align = 8, run_addr = mem:dspr2)
                {
                        select ".bss.*.T1_traceBuffer2";
                }
                group T1_BSS_CORE3 (ordered, align = 8, run_addr = mem:dspr3)
                {
                        select ".bss.*.T1_traceBuffe3";
                }
        
                group T1_BSS_CORE4 (ordered, align = 8, run_addr = mem:dspr4)
                {
                        select ".bss.*.T1_traceBuffer4";
                }
                group T1_BSS_CORE5 (ordered, align = 8, run_addr = mem:dspr5)
                {
                        select ".bss.*.T1_traceBuffer5";
                }

                #if defined(__HSM_USED__)
                group (ordered, run_addr = mem:pflash0|mem:pflash1, contiguous, fill)
                #else
                group (ordered, run_addr = mem:pflash0|mem:pflash1, fill)
                #endif
                {
                        group TEXT(ordered, align = 0, fill)
                        {
                                /* BSW */
                                select ".text.*_CODE";
                                /* MCAL */
                                select ".text.Code.Cpu0";
                                /* Code sections for ECUC Partition */
                                #define OS_CODE_SECTION
                                #include "Os_LSL.lsl"
                                #undef OS_CODE_SECTION
                        }

                        group RODATA(ordered, align = 0, fill)
                        {
                                /* BSW */
                                select ".rodata.*_ROM_CONST_*";
                                select ".rodata.*_ROM_CONFIG_CONST_*";
                                select ".rodata.*_ROM_CONFIG_UNSPECIFIED";
                                /* MCAL */
                                select ".rodata.Config.Cpu0.*";
                                select ".rodata.Const.Cpu0.*";
                                /* COPY TABLE */
                                select "table";
                                /* Constant sections for ECUC Partition */
                                #define OS_CONST_SECTION
                                #include "Os_LSL.lsl"
                                #undef OS_CONST_SECTION
                        }

                        group UNDEFINED_ROMDATA (ordered, align = 0, fill)
                        {
                                select ".text*";
                                select ".rodata*";
                        }
                        group REALLOC_RAMDATA (ordered, align = 0, load_addr)
                        {
                                select ".data*";
                        }
                }
        		
                /* RAM (Core1) */
                group (ordered, align = 0, run_addr = mem:dspr1|mem:dlmucpu1)
                {
                        /* Variable sections for ECUC Partition in Core1 */
                        #define OS_VAR_SECTION_CORE1
                        #include "Os_LSL.lsl"
                        #undef OS_VAR_SECTION_CORE1
		            
                        /* Stack sections for Core1 */
                        #define OS_STACK_SECTION_CORE1
                        #include "Os_LSL.lsl" 
                        #undef OS_STACK_SECTION_CORE1
                        select ".bss.ACT_Logger.*";
                        select ".data.ACT_Logger.*";
                        select ".bss.CommonTypedef.*";
                        select ".data.CommonTypedef.*";
                        select ".bss.git_version.*";
                        select ".data.git_version.*";
                        select ".bss.IDC_version.*";
                        select ".data.IDC_version.*";
                        select ".bss.IDS_version.*";
                        select ".data.IDS_version.*";
                        select ".bss.IVC_version.*";
                        select ".data.IVC_version.*";
                        select ".bss.SA_version.*";
                        select ".data.SA_version.*";
                        select ".bss.VDISP_version.*";
                        select ".data.VDISP_version.*";
                        select ".bss.APCalDataForm_CCO_Brk.*";
                        select ".data.APCalDataForm_CCO_Brk.*";
                        select ".bss.APCalDataForm_CCO_Rear.*";
                        select ".data.APCalDataForm_CCO_Rear.*";
                        select ".bss.APCalDataForm_CCO_Str.*";
                        select ".data.APCalDataForm_CCO_Str.*";
                        select ".bss.APCalDataForm_CMD_Brk.*";
                        select ".data.APCalDataForm_CMD_Brk.*";
                        select ".bss.APCalDataForm_CMD_Rear.*";
                        select ".data.APCalDataForm_CMD_Rear.*";
                        select ".bss.APCalDataForm_CMD_Str.*";
                        select ".data.APCalDataForm_CMD_Str.*";
                        select ".bss.APCalDataForm_Comm.*";
                        select ".data.APCalDataForm_Comm.*";
                        select ".bss.APCalDataForm_COMMON.*";
                        select ".data.APCalDataForm_COMMON.*";
                        select ".bss.APCalDataForm_Comm_Rear.*";
                        select ".data.APCalDataForm_Comm_Rear.*";
                        select ".bss.APCalDataForm_CRD_Brk.*";
                        select ".data.APCalDataForm_CRD_Brk.*";
                        select ".bss.APCalDataForm_CRD_Rear.*";
                        select ".data.APCalDataForm_CRD_Rear.*";
                        select ".bss.APCalDataForm_CRD_Str.*";
                        select ".data.APCalDataForm_CRD_Str.*";
                        select ".bss.APCalDataForm_IDC.*";
                        select ".data.APCalDataForm_IDC.*";
                        select ".bss.APCalDataForm_LID_Str.*";
                        select ".data.APCalDataForm_LID_Str.*";
                        select ".bss.APCalDataForm_LSP1.*";
                        select ".data.APCalDataForm_LSP1.*";
                        select ".bss.APCalDataForm_LSP2.*";
                        select ".data.APCalDataForm_LSP2.*";
                        select ".bss.APCalDataForm_SA.*";
                        select ".data.APCalDataForm_SA.*";
                        select ".bss.APCalDataForm_SVPP.*";
                        select ".data.APCalDataForm_SVPP.*";
                        select ".bss.APCalDataForm_TCCRA.*";
                        select ".data.APCalDataForm_TCCRA.*";
                        select ".bss.APCalDataForm_TCPP.*";
                        select ".data.APCalDataForm_TCPP.*";
                        select ".bss.APCalDataForm_TCS.*";
                        select ".data.APCalDataForm_TCS.*";
                        select ".bss.APCalDataForm_TCWIC.*";
                        select ".data.APCalDataForm_TCWIC.*";
                        select ".bss.APCalDataForm_TID_Brk.*";
                        select ".data.APCalDataForm_TID_Brk.*";
                        select ".bss.APCalDataForm_TID_FCAP.*";
                        select ".data.APCalDataForm_TID_FCAP.*";
                        select ".bss.APCalDataForm_TID_Rear.*";
                        select ".data.APCalDataForm_TID_Rear.*";
                        select ".bss.APCalDataForm_TID_Str.*";
                        select ".data.APCalDataForm_TID_Str.*";
                        select ".bss.APCalDataForm_VDISP.*";
                        select ".data.APCalDataForm_VDISP.*";
                        select ".bss.APCalDataForm_VID_Brk.*";
                        select ".data.APCalDataForm_VID_Brk.*";
                        select ".bss.APCalDataForm_VID_Rear.*";
                        select ".data.APCalDataForm_VID_Rear.*";
                        select ".bss.APCalDataForm_VID_Str.*";
                        select ".data.APCalDataForm_VID_Str.*";
                        select ".bss.APCalDataForm_VSP1.*";
                        select ".data.APCalDataForm_VSP1.*";
                        select ".bss.APCalDataForm_VSP2.*";
                        select ".data.APCalDataForm_VSP2.*";
                        select ".bss.constants.*";
                        select ".data.constants.*";
                        select ".bss.wTuning.*";
                        select ".data.wTuning.*";
                        select ".bss.Variant_0_CCO_Brk.*";
                        select ".data.Variant_0_CCO_Brk.*";
                        select ".bss.Variant_0_CCO_Rear.*";
                        select ".data.Variant_0_CCO_Rear.*";
                        select ".bss.Variant_0_CCO_Str.*";
                        select ".data.Variant_0_CCO_Str.*";
                        select ".bss.Variant_0_CMD_Brk.*";
                        select ".data.Variant_0_CMD_Brk.*";
                        select ".bss.Variant_0_CMD_Rear.*";
                        select ".data.Variant_0_CMD_Rear.*";
                        select ".bss.Variant_0_CMD_Str.*";
                        select ".data.Variant_0_CMD_Str.*";
                        select ".bss.Variant_0_Comm.*";
                        select ".data.Variant_0_Comm.*";
                        select ".bss.Variant_0_COMMON.*";
                        select ".data.Variant_0_COMMON.*";
                        select ".bss.Variant_0_Comm_Rear.*";
                        select ".data.Variant_0_Comm_Rear.*";
                        select ".bss.Variant_0_CRD_Brk.*";
                        select ".data.Variant_0_CRD_Brk.*";
                        select ".bss.Variant_0_CRD_Rear.*";
                        select ".data.Variant_0_CRD_Rear.*";
                        select ".bss.Variant_0_CRD_Str.*";
                        select ".data.Variant_0_CRD_Str.*";
                        select ".bss.Variant_0_IDC.*";
                        select ".data.Variant_0_IDC.*";
                        select ".bss.Variant_0_LID_Str.*";
                        select ".data.Variant_0_LID_Str.*";
                        select ".bss.Variant_0_LSP1.*";
                        select ".data.Variant_0_LSP1.*";
                        select ".bss.Variant_0_LSP2.*";
                        select ".data.Variant_0_LSP2.*";
                        select ".bss.Variant_0_SA.*";
                        select ".data.Variant_0_SA.*";
                        select ".bss.Variant_0_SVPP.*";
                        select ".data.Variant_0_SVPP.*";
                        select ".bss.Variant_0_TCCRA.*";
                        select ".data.Variant_0_TCCRA.*";
                        select ".bss.Variant_0_TCPP.*";
                        select ".data.Variant_0_TCPP.*";
                        select ".bss.Variant_0_TCS.*";
                        select ".data.Variant_0_TCS.*";
                        select ".bss.Variant_0_TCWIC.*";
                        select ".data.Variant_0_TCWIC.*";
                        select ".bss.Variant_0_TID_Brk.*";
                        select ".data.Variant_0_TID_Brk.*";
                        select ".bss.Variant_0_TID_FCAP.*";
                        select ".data.Variant_0_TID_FCAP.*";
                        select ".bss.Variant_0_TID_Rear.*";
                        select ".data.Variant_0_TID_Rear.*";
                        select ".bss.Variant_0_TID_Str.*";
                        select ".data.Variant_0_TID_Str.*";
                        select ".bss.Variant_0_VDISP.*";
                        select ".data.Variant_0_VDISP.*";
                        select ".bss.Variant_0_VID_Brk.*";
                        select ".data.Variant_0_VID_Brk.*";
                        select ".bss.Variant_0_VID_Rear.*";
                        select ".data.Variant_0_VID_Rear.*";
                        select ".bss.Variant_0_VID_Str.*";
                        select ".data.Variant_0_VID_Str.*";
                        select ".bss.Variant_0_VSP1.*";
                        select ".data.Variant_0_VSP1.*";
                        select ".bss.Variant_0_VSP2.*";
                        select ".data.Variant_0_VSP2.*";
                        select ".bss.BINARYSEARCH_S16.*";
                        select ".data.BINARYSEARCH_S16.*";
                        select ".bss.BINARYSEARCH_S32.*";
                        select ".data.BINARYSEARCH_S32.*";
                        select ".bss.BINARYSEARCH_S32S16.*";
                        select ".data.BINARYSEARCH_S32S16.*";
                        select ".bss.BINARYSEARCH_S32S16_Near_iL.*";
                        select ".data.BINARYSEARCH_S32S16_Near_iL.*";
                        select ".bss.BINARYSEARCH_U16.*";
                        select ".data.BINARYSEARCH_U16.*";
                        select ".bss.BINARYSEARCH_U32.*";
                        select ".data.BINARYSEARCH_U32.*";
                        select ".bss.BINARYSEARCH_U32U16.*";
                        select ".data.BINARYSEARCH_U32U16.*";
                        select ".bss.BINARYSEARCH_U32U16_iL.*";
                        select ".data.BINARYSEARCH_U32U16_iL.*";
                        select ".bss.BINARYSEARCH_U8.*";
                        select ".data.BINARYSEARCH_U8.*";
                        select ".bss.binsearch_u32s16.*";
                        select ".data.binsearch_u32s16.*";
                        select ".bss.binsearch_u32s32.*";
                        select ".data.binsearch_u32s32.*";
                        select ".bss.binsearch_u32u32.*";
                        select ".data.binsearch_u32u32.*";
                        select ".bss.binsearch_u32u8.*";
                        select ".data.binsearch_u32u8.*";
                        select ".bss.const_params.*";
                        select ".data.const_params.*";
                        select ".bss.const_params_IDC.*";
                        select ".data.const_params_IDC.*";
                        select ".bss.const_params_IDS.*";
                        select ".data.const_params_IDS.*";
                        select ".bss.div_nde_s32_floor.*";
                        select ".data.div_nde_s32_floor.*";
                        select ".bss.div_nzp_repeat_u32.*";
                        select ".data.div_nzp_repeat_u32.*";
                        select ".bss.div_nzp_repeat_u32_ceiling.*";
                        select ".data.div_nzp_repeat_u32_ceiling.*";
                        select ".bss.div_nzp_repeat_u32_sat.*";
                        select ".data.div_nzp_repeat_u32_sat.*";
                        select ".bss.div_nzp_s32_round.*";
                        select ".data.div_nzp_s32_round.*";
                        select ".bss.div_repeat_u32.*";
                        select ".data.div_repeat_u32.*";
                        select ".bss.div_repeat_us32.*";
                        select ".data.div_repeat_us32.*";
                        select ".bss.div_repeat_us32_floor.*";
                        select ".data.div_repeat_us32_floor.*";
                        select ".bss.div_repeat_us32_sat.*";
                        select ".data.div_repeat_us32_sat.*";
                        select ".bss.div_s16s32.*";
                        select ".data.div_s16s32.*";
                        select ".bss.div_s16s32_floor.*";
                        select ".data.div_s16s32_floor.*";
                        select ".bss.div_s16su32.*";
                        select ".data.div_s16su32.*";
                        select ".bss.div_s16u32.*";
                        select ".data.div_s16u32.*";
                        select ".bss.div_s16us32_floor.*";
                        select ".data.div_s16us32_floor.*";
                        select ".bss.div_s32.*";
                        select ".data.div_s32.*";
                        select ".bss.div_s32_floor.*";
                        select ".data.div_s32_floor.*";
                        select ".bss.div_s32_near.*";
                        select ".data.div_s32_near.*";
                        select ".bss.div_s32_round.*";
                        select ".data.div_s32_round.*";
                        select ".bss.div_s32_sat.*";
                        select ".data.div_s32_sat.*";
                        select ".bss.div_s32_sat_floor.*";
                        select ".data.div_s32_sat_floor.*";
                        select ".bss.div_s8s32.*";
                        select ".data.div_s8s32.*";
                        select ".bss.div_ssu32.*";
                        select ".data.div_ssu32.*";
                        select ".bss.div_ssu32_floor.*";
                        select ".data.div_ssu32_floor.*";
                        select ".bss.div_su32.*";
                        select ".data.div_su32.*";
                        select ".bss.div_sus32.*";
                        select ".data.div_sus32.*";
                        select ".bss.div_sus32_floor.*";
                        select ".data.div_sus32_floor.*";
                        select ".bss.div_us32.*";
                        select ".data.div_us32.*";
                        select ".bss.div_us32_floor.*";
                        select ".data.div_us32_floor.*";
                        select ".bss.div_uus32.*";
                        select ".data.div_uus32.*";
                        select ".bss.div_uus32_sat.*";
                        select ".data.div_uus32_sat.*";
                        select ".bss.DTRC_DesiredTqOutRatioRateLimiter_DqlcIOio.*";
                        select ".data.DTRC_DesiredTqOutRatioRateLimiter_DqlcIOio.*";
                        select ".bss.INTERPOLATE_EVEN_S16U8_S16_ZERO.*";
                        select ".data.INTERPOLATE_EVEN_S16U8_S16_ZERO.*";
                        select ".bss.INTERPOLATE_EVEN_S16_S16_ZERO.*";
                        select ".data.INTERPOLATE_EVEN_S16_S16_ZERO.*";
                        select ".bss.INTERPOLATE_EVEN_S16_U16_ZERO.*";
                        select ".data.INTERPOLATE_EVEN_S16_U16_ZERO.*";
                        select ".bss.INTERPOLATE_EVEN_U16_S16_SIMPLEST.*";
                        select ".data.INTERPOLATE_EVEN_U16_S16_SIMPLEST.*";
                        select ".bss.INTERPOLATE_EVEN_U16_S16_ZERO.*";
                        select ".data.INTERPOLATE_EVEN_U16_S16_ZERO.*";
                        select ".bss.INTERPOLATE_EVEN_U16_U16.*";
                        select ".data.INTERPOLATE_EVEN_U16_U16.*";
                        select ".bss.INTERPOLATE_EVEN_U16_U16_SIMPLEST.*";
                        select ".data.INTERPOLATE_EVEN_U16_U16_SIMPLEST.*";
                        select ".bss.INTERPOLATE_EVEN_U16_U16_ZERO.*";
                        select ".data.INTERPOLATE_EVEN_U16_U16_ZERO.*";
                        select ".bss.INTERPOLATE_EVEN_U8_U16_ZERO.*";
                        select ".data.INTERPOLATE_EVEN_U8_U16_ZERO.*";
                        select ".bss.INTERPOLATE_S16U16_U16_ZERO.*";
                        select ".data.INTERPOLATE_S16U16_U16_ZERO.*";
                        select ".bss.INTERPOLATE_S16U8_S16_ZERO.*";
                        select ".data.INTERPOLATE_S16U8_S16_ZERO.*";
                        select ".bss.INTERPOLATE_S16U8_U16_ZERO.*";
                        select ".data.INTERPOLATE_S16U8_U16_ZERO.*";
                        select ".bss.INTERPOLATE_S16_S16.*";
                        select ".data.INTERPOLATE_S16_S16.*";
                        select ".bss.INTERPOLATE_S16_S16_ZERO.*";
                        select ".data.INTERPOLATE_S16_S16_ZERO.*";
                        select ".bss.INTERPOLATE_S16_U16_ZERO.*";
                        select ".data.INTERPOLATE_S16_U16_ZERO.*";
                        select ".bss.INTERPOLATE_S32S16_S16_ZERO.*";
                        select ".data.INTERPOLATE_S32S16_S16_ZERO.*";
                        select ".bss.INTERPOLATE_U16S16_S16_ZERO.*";
                        select ".data.INTERPOLATE_U16S16_S16_ZERO.*";
                        select ".bss.INTERPOLATE_U16S16_U16.*";
                        select ".data.INTERPOLATE_U16S16_U16.*";
                        select ".bss.INTERPOLATE_U16S16_U16_ZERO.*";
                        select ".data.INTERPOLATE_U16S16_U16_ZERO.*";
                        select ".bss.INTERPOLATE_U16U8_U16_ZERO.*";
                        select ".data.INTERPOLATE_U16U8_U16_ZERO.*";
                        select ".bss.INTERPOLATE_U16_S16_SIMPLEST.*";
                        select ".data.INTERPOLATE_U16_S16_SIMPLEST.*";
                        select ".bss.INTERPOLATE_U16_S16_ZERO.*";
                        select ".data.INTERPOLATE_U16_S16_ZERO.*";
                        select ".bss.INTERPOLATE_U16_U16.*";
                        select ".data.INTERPOLATE_U16_U16.*";
                        select ".bss.INTERPOLATE_U16_U16_SAT_SIMPLEST.*";
                        select ".data.INTERPOLATE_U16_U16_SAT_SIMPLEST.*";
                        select ".bss.INTERPOLATE_U16_U16_SIMPLEST.*";
                        select ".data.INTERPOLATE_U16_U16_SIMPLEST.*";
                        select ".bss.INTERPOLATE_U16_U16_ZERO.*";
                        select ".data.INTERPOLATE_U16_U16_ZERO.*";
                        select ".bss.INTERPOLATE_U16_U8_ZERO.*";
                        select ".data.INTERPOLATE_U16_U8_ZERO.*";
                        select ".bss.INTERPOLATE_U8U16_U16.*";
                        select ".data.INTERPOLATE_U8U16_U16.*";
                        select ".bss.INTERPOLATE_U8_S16_ZERO.*";
                        select ".data.INTERPOLATE_U8_S16_ZERO.*";
                        select ".bss.INTERPOLATE_U8_U16_SIMPLEST.*";
                        select ".data.INTERPOLATE_U8_U16_SIMPLEST.*";
                        select ".bss.INTERPOLATE_U8_U16_ZERO.*";
                        select ".data.INTERPOLATE_U8_U16_ZERO.*";
                        select ".bss.INTERPOLATE_U8_U8_ZERO.*";
                        select ".data.INTERPOLATE_U8_U8_ZERO.*";
                        select ".bss.intrp2d_s32u32u32u32u32n32la_e.*";
                        select ".data.intrp2d_s32u32u32u32u32n32la_e.*";
                        select ".bss.linsearch_u32s32.*";
                        select ".data.linsearch_u32s32.*";
                        select ".bss.look1_is16bs32lu16n16Ds32_binlca.*";
                        select ".data.look1_is16bs32lu16n16Ds32_binlca.*";
                        select ".bss.look1_is16bs32lu32n31ts32Du32_binlce.*";
                        select ".data.look1_is16bs32lu32n31ts32Du32_binlce.*";
                        select ".bss.look1_is16bu16lu16n16tu16_binlcae.*";
                        select ".data.look1_is16bu16lu16n16tu16_binlcae.*";
                        select ".bss.look1_is16bu16lu16n8tu8_binlce.*";
                        select ".data.look1_is16bu16lu16n8tu8_binlce.*";
                        select ".bss.look1_is16bu16lu32n16tu16_binlce.*";
                        select ".data.look1_is16bu16lu32n16tu16_binlce.*";
                        select ".bss.look1_is16bu32lu32n16Ds32_binlc.*";
                        select ".data.look1_is16bu32lu32n16Ds32_binlc.*";
                        select ".bss.look1_is16lu16n16Ds32_binlca.*";
                        select ".data.look1_is16lu16n16Ds32_binlca.*";
                        select ".bss.look1_is16lu16n8tu8_binlce.*";
                        select ".data.look1_is16lu16n8tu8_binlce.*";
                        select ".bss.look1_is16lu32n16Ds32_binlc.*";
                        select ".data.look1_is16lu32n16Ds32_binlc.*";
                        select ".bss.look1_is16lu32n16Ds32_binlcs.*";
                        select ".data.look1_is16lu32n16Ds32_binlcs.*";
                        select ".bss.look1_is16lu32n16tu16_binlce.*";
                        select ".data.look1_is16lu32n16tu16_binlce.*";
                        select ".bss.look1_is32bs16lu32n16ts16Ds32_binlcs.*";
                        select ".data.look1_is32bs16lu32n16ts16Ds32_binlcs.*";
                        select ".bss.look1_is32lu32n31Du32_binlce.*";
                        select ".data.look1_is32lu32n31Du32_binlce.*";
                        select ".bss.look1_is32lu32n31Du32_binlcse.*";
                        select ".data.look1_is32lu32n31Du32_binlcse.*";
                        select ".bss.look1_is32lu32n32Du32_binlcae.*";
                        select ".data.look1_is32lu32n32Du32_binlcae.*";
                        select ".bss.look1_iu16bs16lu16n16ts16Ds32_binlca.*";
                        select ".data.look1_iu16bs16lu16n16ts16Ds32_binlca.*";
                        select ".bss.look1_iu16bs16lu32n16ts16Ds32_binlc.*";
                        select ".data.look1_iu16bs16lu32n16ts16Ds32_binlc.*";
                        select ".bss.look1_iu16lu16n16ts16Ds32_binlca.*";
                        select ".data.look1_iu16lu16n16ts16Ds32_binlca.*";
                        select ".bss.look1_iu16lu16n16_binlcae.*";
                        select ".data.look1_iu16lu16n16_binlcae.*";
                        select ".bss.look1_iu16lu32n16_binlce.*";
                        select ".data.look1_iu16lu32n16_binlce.*";
                        select ".bss.look1_iu16lu32n32yu16tu32_binlcae.*";
                        select ".data.look1_iu16lu32n32yu16tu32_binlcae.*";
                        select ".bss.look1_iu16lu32n32yu16tu32_binlcase.*";
                        select ".data.look1_iu16lu32n32yu16tu32_binlcase.*";
                        select ".bss.look1_iu32lu32n16ts16Ds32_binlc.*";
                        select ".data.look1_iu32lu32n16ts16Ds32_binlc.*";
                        select ".bss.look1_iu32lu32n16ts16Ds32_binlcs.*";
                        select ".data.look1_iu32lu32n16ts16Ds32_binlcs.*";
                        select ".bss.Look2DEvenEven_S32_S16_S32_ZERO.*";
                        select ".data.Look2DEvenEven_S32_S16_S32_ZERO.*";
                        select ".bss.Look2DEvenEven_S32_S16_U16_ZERO.*";
                        select ".data.Look2DEvenEven_S32_S16_U16_ZERO.*";
                        select ".bss.Look2DEvenEven_U16_S16_S16_SIMPLEST.*";
                        select ".data.Look2DEvenEven_U16_S16_S16_SIMPLEST.*";
                        select ".bss.Look2DEvenEven_U16_U16_U16_ZERO.*";
                        select ".data.Look2DEvenEven_U16_U16_U16_ZERO.*";
                        select ".bss.Look2DEvenEven_U8_U16_U16_ZERO.*";
                        select ".data.Look2DEvenEven_U8_U16_U16_ZERO.*";
                        select ".bss.Look2D_S32_S16_S32_ZERO.*";
                        select ".data.Look2D_S32_S16_S32_ZERO.*";
                        select ".bss.Look2D_S32_S32_S32_ZERO.*";
                        select ".data.Look2D_S32_S32_S32_ZERO.*";
                        select ".bss.Look2D_S32_S32_U32_SIMPLEST.*";
                        select ".data.Look2D_S32_S32_U32_SIMPLEST.*";
                        select ".bss.Look2D_U16_S16_S16_SIMPLEST.*";
                        select ".data.Look2D_U16_S16_S16_SIMPLEST.*";
                        select ".bss.Look2D_U16_S16_U16_SIMPLEST.*";
                        select ".data.Look2D_U16_S16_U16_SIMPLEST.*";
                        select ".bss.Look2D_U16_U16_U16_SIMPLEST.*";
                        select ".data.Look2D_U16_U16_U16_SIMPLEST.*";
                        select ".bss.Look2D_U16_U16_U16_ZERO.*";
                        select ".data.Look2D_U16_U16_U16_ZERO.*";
                        select ".bss.Look2D_U16_U16_U8_ZERO.*";
                        select ".data.Look2D_U16_U16_U8_ZERO.*";
                        select ".bss.Look2D_U32_U16_U16_SIMPLEST.*";
                        select ".data.Look2D_U32_U16_U16_SIMPLEST.*";
                        select ".bss.Look2D_U8_U16_U16_ZERO.*";
                        select ".data.Look2D_U8_U16_U16_ZERO.*";
                        select ".bss.Look2D_U8_U16_U8_ZERO.*";
                        select ".data.Look2D_U8_U16_U8_ZERO.*";
                        select ".bss.look2_is16lu32n16Ds32ds32_binlc.*";
                        select ".data.look2_is16lu32n16Ds32ds32_binlc.*";
                        select ".bss.look2_is32lu32n32Du32du32_linlcae.*";
                        select ".data.look2_is32lu32n32Du32du32_linlcae.*";
                        select ".bss.LookUpEven_S16U8_S16_ZERO.*";
                        select ".data.LookUpEven_S16U8_S16_ZERO.*";
                        select ".bss.LookUpEven_S16_S16_ZERO.*";
                        select ".data.LookUpEven_S16_S16_ZERO.*";
                        select ".bss.LookUpEven_S16_S32_ZERO.*";
                        select ".data.LookUpEven_S16_S32_ZERO.*";
                        select ".bss.LookUpEven_S16_U16_ZERO.*";
                        select ".data.LookUpEven_S16_U16_ZERO.*";
                        select ".bss.LookUpEven_S16_U32_ZERO.*";
                        select ".data.LookUpEven_S16_U32_ZERO.*";
                        select ".bss.LookUpEven_S32_S32_ZERO.*";
                        select ".data.LookUpEven_S32_S32_ZERO.*";
                        select ".bss.LookUpEven_U16_S16_ZERO.*";
                        select ".data.LookUpEven_U16_S16_ZERO.*";
                        select ".bss.LookUpEven_U16_S32_ZERO.*";
                        select ".data.LookUpEven_U16_S32_ZERO.*";
                        select ".bss.LookUpEven_U16_U16.*";
                        select ".data.LookUpEven_U16_U16.*";
                        select ".bss.LookUpEven_U16_U16_SIMPLEST.*";
                        select ".data.LookUpEven_U16_U16_SIMPLEST.*";
                        select ".bss.LookUpEven_U16_U32_ZERO.*";
                        select ".data.LookUpEven_U16_U32_ZERO.*";
                        select ".bss.LookUpEven_U32_S32_ZERO.*";
                        select ".data.LookUpEven_U32_S32_ZERO.*";
                        select ".bss.LookUpEven_U32_U32_ZERO.*";
                        select ".data.LookUpEven_U32_U32_ZERO.*";
                        select ".bss.LookUpEven_U8_U32_ZERO.*";
                        select ".data.LookUpEven_U8_U32_ZERO.*";
                        select ".bss.LookUp_S16S32_S32_ZERO.*";
                        select ".data.LookUp_S16S32_S32_ZERO.*";
                        select ".bss.LookUp_S16S32_U16_ZERO.*";
                        select ".data.LookUp_S16S32_U16_ZERO.*";
                        select ".bss.LookUp_S16U16_S32_ZERO.*";
                        select ".data.LookUp_S16U16_S32_ZERO.*";
                        select ".bss.LookUp_S16U16_U16_ZERO.*";
                        select ".data.LookUp_S16U16_U16_ZERO.*";
                        select ".bss.LookUp_S16U32_U32_ZERO.*";
                        select ".data.LookUp_S16U32_U32_ZERO.*";
                        select ".bss.LookUp_S16U8_S16_ZERO.*";
                        select ".data.LookUp_S16U8_S16_ZERO.*";
                        select ".bss.LookUp_S16U8_S32_ZERO.*";
                        select ".data.LookUp_S16U8_S32_ZERO.*";
                        select ".bss.LookUp_S16U8_U16_ZERO.*";
                        select ".data.LookUp_S16U8_U16_ZERO.*";
                        select ".bss.LookUp_S16U8_U32_ZERO.*";
                        select ".data.LookUp_S16U8_U32_ZERO.*";
                        select ".bss.LookUp_S16_S16.*";
                        select ".data.LookUp_S16_S16.*";
                        select ".bss.LookUp_S16_S16_ZERO.*";
                        select ".data.LookUp_S16_S16_ZERO.*";
                        select ".bss.LookUp_S16_S32S16_ZERO.*";
                        select ".data.LookUp_S16_S32S16_ZERO.*";
                        select ".bss.LookUp_S16_S32_ZERO.*";
                        select ".data.LookUp_S16_S32_ZERO.*";
                        select ".bss.LookUp_S16_U16_ZERO.*";
                        select ".data.LookUp_S16_U16_ZERO.*";
                        select ".bss.LookUp_S16_U32_ZERO.*";
                        select ".data.LookUp_S16_U32_ZERO.*";
                        select ".bss.LookUp_S32S16_S16_ZERO.*";
                        select ".data.LookUp_S32S16_S16_ZERO.*";
                        select ".bss.LookUp_S32_S16_ZERO.*";
                        select ".data.LookUp_S32_S16_ZERO.*";
                        select ".bss.LookUp_S32_S32.*";
                        select ".data.LookUp_S32_S32.*";
                        select ".bss.LookUp_S32_S32_SAT_ZERO.*";
                        select ".data.LookUp_S32_S32_SAT_ZERO.*";
                        select ".bss.LookUp_S32_S32_ZERO.*";
                        select ".data.LookUp_S32_S32_ZERO.*";
                        select ".bss.LookUp_S32_U32_ZERO.*";
                        select ".data.LookUp_S32_U32_ZERO.*";
                        select ".bss.LookUp_U16S16_S16_ZERO.*";
                        select ".data.LookUp_U16S16_S16_ZERO.*";
                        select ".bss.LookUp_U16S16_U16.*";
                        select ".data.LookUp_U16S16_U16.*";
                        select ".bss.LookUp_U16S16_U16_ZERO.*";
                        select ".data.LookUp_U16S16_U16_ZERO.*";
                        select ".bss.LookUp_U16S16_U32_ZERO.*";
                        select ".data.LookUp_U16S16_U32_ZERO.*";
                        select ".bss.LookUp_U16U8_U16_ZERO.*";
                        select ".data.LookUp_U16U8_U16_ZERO.*";
                        select ".bss.LookUp_U16_S16_SIMPLEST.*";
                        select ".data.LookUp_U16_S16_SIMPLEST.*";
                        select ".bss.LookUp_U16_S16_ZERO.*";
                        select ".data.LookUp_U16_S16_ZERO.*";
                        select ".bss.LookUp_U16_S32_ZERO.*";
                        select ".data.LookUp_U16_S32_ZERO.*";
                        select ".bss.LookUp_U16_U16.*";
                        select ".data.LookUp_U16_U16.*";
                        select ".bss.LookUp_U16_U16_SAT_SIMPLEST.*";
                        select ".data.LookUp_U16_U16_SAT_SIMPLEST.*";
                        select ".bss.LookUp_U16_U16_SIMPLEST.*";
                        select ".data.LookUp_U16_U16_SIMPLEST.*";
                        select ".bss.LookUp_U16_U16_ZERO.*";
                        select ".data.LookUp_U16_U16_ZERO.*";
                        select ".bss.LookUp_U16_U32U16_ZERO.*";
                        select ".data.LookUp_U16_U32U16_ZERO.*";
                        select ".bss.LookUp_U16_U32_ZERO.*";
                        select ".data.LookUp_U16_U32_ZERO.*";
                        select ".bss.LookUp_U32_S32_ZERO.*";
                        select ".data.LookUp_U32_S32_ZERO.*";
                        select ".bss.LookUp_U32_U32_ZERO.*";
                        select ".data.LookUp_U32_U32_ZERO.*";
                        select ".bss.LookUp_U8U16_U16.*";
                        select ".data.LookUp_U8U16_U16.*";
                        select ".bss.LookUp_U8_S16_ZERO.*";
                        select ".data.LookUp_U8_S16_ZERO.*";
                        select ".bss.LookUp_U8_S32_ZERO.*";
                        select ".data.LookUp_U8_S32_ZERO.*";
                        select ".bss.LookUp_U8_U16_SIMPLEST.*";
                        select ".data.LookUp_U8_U16_SIMPLEST.*";
                        select ".bss.LookUp_U8_U16_ZERO.*";
                        select ".data.LookUp_U8_U16_ZERO.*";
                        select ".bss.LookUp_U8_U32_ZERO.*";
                        select ".data.LookUp_U8_U32_ZERO.*";
                        select ".bss.model_reference_types.*";
                        select ".data.model_reference_types.*";
                        select ".bss.MultiWord2Bool.*";
                        select ".data.MultiWord2Bool.*";
                        select ".bss.MultiWord2sLong.*";
                        select ".data.MultiWord2sLong.*";
                        select ".bss.MultiWord2uLong.*";
                        select ".data.MultiWord2uLong.*";
                        select ".bss.MultiWordAdd.*";
                        select ".data.MultiWordAdd.*";
                        select ".bss.MultiWordNeg.*";
                        select ".data.MultiWordNeg.*";
                        select ".bss.MultiWordSetSignedMax.*";
                        select ".data.MultiWordSetSignedMax.*";
                        select ".bss.MultiWordSetSignedMin.*";
                        select ".data.MultiWordSetSignedMin.*";
                        select ".bss.MultiWordSetUnsignedMax.*";
                        select ".data.MultiWordSetUnsignedMax.*";
                        select ".bss.MultiWordSignedWrap.*";
                        select ".data.MultiWordSignedWrap.*";
                        select ".bss.MultiWordSub.*";
                        select ".data.MultiWordSub.*";
                        select ".bss.MultiWordUnsignedWrap.*";
                        select ".data.MultiWordUnsignedWrap.*";
                        select ".bss.multiword_types.*";
                        select ".data.multiword_types.*";
                        select ".bss.mul_s32_s32_s32_sat.*";
                        select ".data.mul_s32_s32_s32_sat.*";
                        select ".bss.mul_s32_s32_u32_sat.*";
                        select ".data.mul_s32_s32_u32_sat.*";
                        select ".bss.mul_s32_s32_u32_sr31.*";
                        select ".data.mul_s32_s32_u32_sr31.*";
                        select ".bss.mul_s32_s32_u32_sr31_sat_zero.*";
                        select ".data.mul_s32_s32_u32_sr31_sat_zero.*";
                        select ".bss.mul_s32_s32_u32_sr31_zero.*";
                        select ".data.mul_s32_s32_u32_sr31_zero.*";
                        select ".bss.mul_s32_sat.*";
                        select ".data.mul_s32_sat.*";
                        select ".bss.mul_ssu32_loSR.*";
                        select ".data.mul_ssu32_loSR.*";
                        select ".bss.mul_ssu32_loSR_sat_zero.*";
                        select ".data.mul_ssu32_loSR_sat_zero.*";
                        select ".bss.mul_ssu32_loSR_zero.*";
                        select ".data.mul_ssu32_loSR_zero.*";
                        select ".bss.mul_ssu32_sat.*";
                        select ".data.mul_ssu32_sat.*";
                        select ".bss.mul_u32_loSR.*";
                        select ".data.mul_u32_loSR.*";
                        select ".bss.mul_u32_s32_u32_sat.*";
                        select ".data.mul_u32_s32_u32_sat.*";
                        select ".bss.mul_u32_sat.*";
                        select ".data.mul_u32_sat.*";
                        select ".bss.mul_u32_sr32.*";
                        select ".data.mul_u32_sr32.*";
                        select ".bss.mul_u32_u32_u32_sat.*";
                        select ".data.mul_u32_u32_u32_sat.*";
                        select ".bss.mul_u32_u32_u32_sr31.*";
                        select ".data.mul_u32_u32_u32_sr31.*";
                        select ".bss.mul_u32_u32_u32_sr32.*";
                        select ".data.mul_u32_u32_u32_sr32.*";
                        select ".bss.mul_usu32_sat.*";
                        select ".data.mul_usu32_sat.*";
                        select ".bss.mul_wide_s32.*";
                        select ".data.mul_wide_s32.*";
                        select ".bss.mul_wide_su32.*";
                        select ".data.mul_wide_su32.*";
                        select ".bss.mul_wide_u32.*";
                        select ".data.mul_wide_u32.*";
                        select ".bss.plook_u32s16s32u32n32_binca.*";
                        select ".data.plook_u32s16s32u32n32_binca.*";
                        select ".bss.plook_u32s16u32n32_binca.*";
                        select ".data.plook_u32s16u32n32_binca.*";
                        select ".bss.plook_u32s32u32n32_binca.*";
                        select ".data.plook_u32s32u32n32_binca.*";
                        select ".bss.plook_u32s32_bincka.*";
                        select ".data.plook_u32s32_bincka.*";
                        select ".bss.plook_u32s32_lincka.*";
                        select ".data.plook_u32s32_lincka.*";
                        select ".bss.plook_u32u32_bincka.*";
                        select ".data.plook_u32u32_bincka.*";
                        select ".bss.plook_u32u8_bincka.*";
                        select ".data.plook_u32u8_bincka.*";
                        select ".bss.rtwtypes.*";
                        select ".data.rtwtypes.*";
                        select ".bss.rt_sqrt_Us32_Ys32_Is64__s.*";
                        select ".data.rt_sqrt_Us32_Ys32_Is64__s.*";
                        select ".bss.rt_sqrt_Uu32_Ys32_Is64_f_s.*";
                        select ".data.rt_sqrt_Uu32_Ys32_Is64_f_s.*";
                        select ".bss.sLong2MultiWord.*";
                        select ".data.sLong2MultiWord.*";
                        select ".bss.sMultiWord2MultiWord.*";
                        select ".data.sMultiWord2MultiWord.*";
                        select ".bss.sMultiWordCmp.*";
                        select ".data.sMultiWordCmp.*";
                        select ".bss.sMultiWordDivFloor.*";
                        select ".data.sMultiWordDivFloor.*";
                        select ".bss.sMultiWordDivZero.*";
                        select ".data.sMultiWordDivZero.*";
                        select ".bss.sMultiWordEq.*";
                        select ".data.sMultiWordEq.*";
                        select ".bss.sMultiWordGe.*";
                        select ".data.sMultiWordGe.*";
                        select ".bss.sMultiWordGt.*";
                        select ".data.sMultiWordGt.*";
                        select ".bss.sMultiWordLe.*";
                        select ".data.sMultiWordLe.*";
                        select ".bss.sMultiWordLt.*";
                        select ".data.sMultiWordLt.*";
                        select ".bss.sMultiWordMul.*";
                        select ".data.sMultiWordMul.*";
                        select ".bss.sMultiWordShl.*";
                        select ".data.sMultiWordShl.*";
                        select ".bss.sMultiWordShr.*";
                        select ".data.sMultiWordShr.*";
                        select ".bss.sMultiWordShrZero.*";
                        select ".data.sMultiWordShrZero.*";
                        select ".bss.ssuMultiWordMul.*";
                        select ".data.ssuMultiWordMul.*";
                        select ".bss.uLong2MultiWord.*";
                        select ".data.uLong2MultiWord.*";
                        select ".bss.uMultiWord2MultiWord.*";
                        select ".data.uMultiWord2MultiWord.*";
                        select ".bss.uMultiWordDiv.*";
                        select ".data.uMultiWordDiv.*";
                        select ".bss.uMultiWordDivZero.*";
                        select ".data.uMultiWordDivZero.*";
                        select ".bss.uMultiWordInc.*";
                        select ".data.uMultiWordInc.*";
                        select ".bss.uMultiWordMul.*";
                        select ".data.uMultiWordMul.*";
                        select ".bss.uMultiWordShl.*";
                        select ".data.uMultiWordShl.*";
                        select ".bss.zero_crossing_types.*";
                        select ".data.zero_crossing_types.*";
                        select ".bss.IDSP1_Main.*";
                        select ".data.IDSP1_Main.*";
                        select ".bss.Ref_IDSP1.*";
                        select ".data.Ref_IDSP1.*";
                        select ".bss.look1_is16bu32lu16n8tu8_binlce.*";
                        select ".data.look1_is16bu32lu16n8tu8_binlce.*";
                        select ".bss.look1_iu32lu16n8tu8_binlce.*";
                        select ".data.look1_iu32lu16n8tu8_binlce.*";
                        
                        
                }
        
                /* RAM (Core2) */
                group (ordered, align = 0, run_addr = mem:dspr2|mem:dlmucpu2|mem:pspr2)
                {
                        /* Variable sections for ECUC Partition in Core2 */
                        #define OS_VAR_SECTION_CORE2
                        #include "Os_LSL.lsl"
                        #undef OS_VAR_SECTION_CORE2
		            
                        /* Stack sections for Core2 */
                        #define OS_STACK_SECTION_CORE2
                        #include "Os_LSL.lsl" 
                        #undef OS_STACK_SECTION_CORE2
                        select ".bss.IVC_Main.*";
                        select ".data.IVC_Main.*";
                        select ".bss.Lib_IVC_Main.*";
                        select ".data.Lib_IVC_Main.*";
                        select ".bss.IDC_Main.*";
                        select ".data.IDC_Main.*";
                        select ".bss.Lib_IDC_Main.*";
                        select ".data.Lib_IDC_Main.*";

                        
                }
		
		        /* RAM (Core3) */
                group (ordered, align = 0, run_addr = mem:dspr3|mem:dlmucpu3)
                {
                        /* Variable sections for ECUC Partition in Core3 */
                        #define OS_VAR_SECTION_CORE3
                        #include "Os_LSL.lsl"
                        #undef OS_VAR_SECTION_CORE3
		            
                        /* Stack sections for Core3 */
                        #define OS_STACK_SECTION_CORE3
                        #include "Os_LSL.lsl" 
                        #undef OS_STACK_SECTION_CORE3
                        select ".bss.LSFMain.*";
                        select ".data.LSFMain.*";
                        select ".bss.DataAssoc.*";
                        select ".data.DataAssoc.*";
                        select ".bss.DataAssoc_Common.*";
                        select ".data.DataAssoc_Common.*";
                        select ".bss.DataAssoc_Common_DataTypeDefine.*";
                        select ".data.DataAssoc_Common_DataTypeDefine.*";
                        select ".bss.DataAssoc_Common_EnumTypeDefine.*";
                        select ".data.DataAssoc_Common_EnumTypeDefine.*";
                        select ".bss.DataAssoc_Common_Function.*";
                        select ".data.DataAssoc_Common_Function.*";
                        select ".bss.DataAssoc_Common_MacroDefine.*";
                        select ".data.DataAssoc_Common_MacroDefine.*";
                        select ".bss.DataAssoc_Common_ModuleVariable.*";
                        select ".data.DataAssoc_Common_ModuleVariable.*";
                        select ".bss.DataAssoc_Common_TuneParams.*";
                        select ".data.DataAssoc_Common_TuneParams.*";
                        select ".bss.DataAssoc_Ped_Create.*";
                        select ".data.DataAssoc_Ped_Create.*";
                        select ".bss.DataAssoc_Ped_Update.*";
                        select ".data.DataAssoc_Ped_Update.*";
                        select ".bss.DataAssoc_Ped_Func.*";
                        select ".data.DataAssoc_Ped_Func.*";
                        select ".bss.DataAssoc_Ped_Gate.*";
                        select ".data.DataAssoc_Ped_Gate.*";
                        select ".bss.DataAssoc_Ped_Sub.*";
                        select ".data.DataAssoc_Ped_Sub.*";
                        select ".bss.DataAssoc_Ped_SuspectMap.*";
                        select ".data.DataAssoc_Ped_SuspectMap.*";
                        select ".bss.DataAssoc_ODM_Fusion.*";
                        select ".data.DataAssoc_ODM_Fusion.*";
                        select ".bss.DataAssoc_Static_CreateTrack.*";
                        select ".data.DataAssoc_Static_CreateTrack.*";
                        select ".bss.DataAssoc_Veh_Create.*";
                        select ".data.DataAssoc_Veh_Create.*";
                        select ".bss.DataAssoc_Veh_Update.*";
                        select ".data.DataAssoc_Veh_Update.*";
                        select ".bss.DataAssoc_Veh_Common.*";
                        select ".data.DataAssoc_Veh_Common.*";
                        select ".bss.DataAssoc_Veh_Common_Func.*";
                        select ".data.DataAssoc_Veh_Common_Func.*";
                        select ".bss.DataAssoc_Veh_Common_Func_AssocMin.*";
                        select ".data.DataAssoc_Veh_Common_Func_AssocMin.*";
                        select ".bss.DataAssoc_Veh_Create_Func.*";
                        select ".data.DataAssoc_Veh_Create_Func.*";
                        select ".bss.DataAssoc_Veh_Create_Gate.*";
                        select ".data.DataAssoc_Veh_Create_Gate.*";
                        select ".bss.DataAssoc_Veh_Create_Sub.*";
                        select ".data.DataAssoc_Veh_Create_Sub.*";
                        select ".bss.DataAssoc_Veh_Update_Func.*";
                        select ".data.DataAssoc_Veh_Update_Func.*";
                        select ".bss.DataAssoc_Veh_Update_Gate.*";
                        select ".data.DataAssoc_Veh_Update_Gate.*";
                        select ".bss.DataAssoc_Veh_Update_Sub.*";
                        select ".data.DataAssoc_Veh_Update_Sub.*";
                        select ".bss.DataAssoc_Veh_Update_Gate_Diagonal_Oncoming.*";
                        select ".data.DataAssoc_Veh_Update_Gate_Diagonal_Oncoming.*";
                        select ".bss.DataAssoc_Veh_Update_Gate_Lat.*";
                        select ".data.DataAssoc_Veh_Update_Gate_Lat.*";
                        select ".bss.DataAssoc_Veh_Update_Gate_Long.*";
                        select ".data.DataAssoc_Veh_Update_Gate_Long.*";
                        select ".bss.DataAssoc_Veh_Update_Gate_Oncoming.*";
                        select ".data.DataAssoc_Veh_Update_Gate_Oncoming.*";
                        select ".bss.DataFusion.*";
                        select ".data.DataFusion.*";
                        select ".bss.DataFusion_Common.*";
                        select ".data.DataFusion_Common.*";
                        select ".bss.DataFusion_Common_DataTypeDefine.*";
                        select ".data.DataFusion_Common_DataTypeDefine.*";
                        select ".bss.DataFusion_Common_Func.*";
                        select ".data.DataFusion_Common_Func.*";
                        select ".bss.DataFusion_Common_TuneParams.*";
                        select ".data.DataFusion_Common_TuneParams.*";
                        select ".bss.DataFusion_Merge.*";
                        select ".data.DataFusion_Merge.*";
                        select ".bss.DataFusion_Ped.*";
                        select ".data.DataFusion_Ped.*";
                        select ".bss.DataFusion_Ped_DynamicClassification.*";
                        select ".data.DataFusion_Ped_DynamicClassification.*";
                        select ".bss.DataFusion_Ped_Func.*";
                        select ".data.DataFusion_Ped_Func.*";
                        select ".bss.DataFusion_Ped_UpdateMeasurement.*";
                        select ".data.DataFusion_Ped_UpdateMeasurement.*";
                        select ".bss.DataFusion_Veh.*";
                        select ".data.DataFusion_Veh.*";
                        select ".bss.DataFusion_Veh_AbsVelocity.*";
                        select ".data.DataFusion_Veh_AbsVelocity.*";
                        select ".bss.DataFusion_Veh_Direction.*";
                        select ".data.DataFusion_Veh_Direction.*";
                        select ".bss.DataFusion_Veh_HeadingAngle.*";
                        select ".data.DataFusion_Veh_HeadingAngle.*";
                        select ".bss.DataFusion_Veh_MovingStatus.*";
                        select ".data.DataFusion_Veh_MovingStatus.*";
                        select ".bss.DataFusion_Veh_UpdateMeasurement.*";
                        select ".data.DataFusion_Veh_UpdateMeasurement.*";
                        select ".bss.Interface.*";
                        select ".data.Interface.*";
                        select ".bss.Interface_InputProc.*";
                        select ".data.Interface_InputProc.*";
                        select ".bss.Interface_InputProc_DataTypeDefine.*";
                        select ".data.Interface_InputProc_DataTypeDefine.*";
                        select ".bss.Inteface_OutputProc_TuneParams.*";
                        select ".data.Inteface_OutputProc_TuneParams.*";
                        select ".bss.Interface_OutputProc.*";
                        select ".data.Interface_OutputProc.*";
                        select ".bss.Interface_OutputProc_DataTypeDefine.*";
                        select ".data.Interface_OutputProc_DataTypeDefine.*";
                        select ".bss.PreProc.*";
                        select ".data.PreProc.*";
                        select ".bss.PrerProc.*";
                        select ".data.PrerProc.*";
                        select ".bss.PreProc_Common.*";
                        select ".data.PreProc_Common.*";
                        select ".bss.PreProc_Common_Func.*";
                        select ".data.PreProc_Common_Func.*";
                        select ".bss.PreProc_EnumTypeDefine.*";
                        select ".data.PreProc_EnumTypeDefine.*";
                        select ".bss.PreProc_MarcroDefine.*";
                        select ".data.PreProc_MarcroDefine.*";
                        select ".bss.PreProc_TuneParams.*";
                        select ".data.PreProc_TuneParams.*";
                        select ".bss.PreProc_CnrRdrValid.*";
                        select ".data.PreProc_CnrRdrValid.*";
                        select ".bss.PreProc_CnrrRdrValid.*";
                        select ".data.PreProc_CnrrRdrValid.*";
                        select ".bss.PreProc_FrtCmrValid.*";
                        select ".data.PreProc_FrtCmrValid.*";
                        select ".bss.PreProc_FrtRdrValid.*";
                        select ".data.PreProc_FrtRdrValid.*";
                        select ".bss.SF_Common.*";
                        select ".data.SF_Common.*";
                        select ".bss.SF_CommonFunction.*";
                        select ".data.SF_CommonFunction.*";
                        select ".bss.SF_Common_TuneParams.*";
                        select ".data.SF_Common_TuneParams.*";
                        select ".bss.SF_EnumTypeDefine.*";
                        select ".data.SF_EnumTypeDefine.*";
                        select ".bss.SF_IntegerDataTypeDefine.*";
                        select ".data.SF_IntegerDataTypeDefine.*";
                        select ".bss.SF_MacroDefine.*";
                        select ".data.SF_MacroDefine.*";
                        select ".bss.SF_MathFunction.*";
                        select ".data.SF_MathFunction.*";
                        select ".bss.SF_SysConfig.*";
                        select ".data.SF_SysConfig.*";
                        select ".bss.SF_SysDefine.*";
                        select ".data.SF_SysDefine.*";
                        select ".bss.SF_FusionTrackTypeDefine.*";
                        select ".data.SF_FusionTrackTypeDefine.*";
                        select ".bss.SF_ODMRelatedTypeDefine.*";
                        select ".data.SF_ODMRelatedTypeDefine.*";
                        select ".bss.SF_SensorTrackTypeDefine.*";
                        select ".data.SF_SensorTrackTypeDefine.*";
                        select ".bss.SF_StaticTrackTypeDefine.*";
                        select ".data.SF_StaticTrackTypeDefine.*";
                        select ".bss.SF_Var_FusionTrack.*";
                        select ".data.SF_Var_FusionTrack.*";
                        select ".bss.SF_Var_ODMRelated.*";
                        select ".data.SF_Var_ODMRelated.*";
                        select ".bss.SF_Var_SensorTrack.*";
                        select ".data.SF_Var_SensorTrack.*";
                        select ".bss.SF_Var_StaticTrack.*";
                        select ".data.SF_Var_StaticTrack.*";
                        select ".bss.Tracking.*";
                        select ".data.Tracking.*";
                        select ".bss.Tracking_Common.*";
                        select ".data.Tracking_Common.*";
                        select ".bss.Tracking_Common_Func.*";
                        select ".data.Tracking_Common_Func.*";
                        select ".bss.Tracking_TuneParams.*";
                        select ".data.Tracking_TuneParams.*";
                        select ".bss.Tracking_CorrectFusionTrackState.*";
                        select ".data.Tracking_CorrectFusionTrackState.*";
                        select ".bss.Tracking_PredictFusionTrackState.*";
                        select ".data.Tracking_PredictFusionTrackState.*";
                        select ".bss.TrackMngmt.*";
                        select ".data.TrackMngmt.*";
                        select ".bss.TrackMngmt_Common.*";
                        select ".data.TrackMngmt_Common.*";
                        select ".bss.TrackMngmt_Common_Func.*";
                        select ".data.TrackMngmt_Common_Func.*";
                        select ".bss.TrackMngmt_TuneParams.*";
                        select ".data.TrackMngmt_TuneParams.*";
                        select ".bss.TrackMaintain.*";
                        select ".data.TrackMaintain.*";
                        select ".bss.TrackMaintain_Common.*";
                        select ".data.TrackMaintain_Common.*";
                        select ".bss.TrackMaintain_Common_Func.*";
                        select ".data.TrackMaintain_Common_Func.*";
                        select ".bss.TrackMaintain_ManageODMCoastingTrack.*";
                        select ".data.TrackMaintain_ManageODMCoastingTrack.*";
                        select ".bss.TrackMaintain_SavePrevTrack.*";
                        select ".data.TrackMaintain_SavePrevTrack.*";
                        select ".bss.TrackMaintain_Var_ODMRelated.*";
                        select ".data.TrackMaintain_Var_ODMRelated.*";
                        select ".bss.TrackMngmt_FusionTrackLifeCycleMngmt.*";
                        select ".data.TrackMngmt_FusionTrackLifeCycleMngmt.*";
                        select ".bss.TrackMngmt_FusionTrackOverlapRemoval.*";
                        select ".data.TrackMngmt_FusionTrackOverlapRemoval.*";
                        select ".bss.TrackMngmt_FusionTrackValidation.*";
                        select ".data.TrackMngmt_FusionTrackValidation.*";

                        
						
                }
                
#if defined(__PROC_TC39X__)        
                /* RAM (Core4) */
                group (ordered, align = 0, run_addr = mem:dspr4|mem:dlmucpu4)
                {
                        /* Variable sections for ECUC Partition in Core4 */
                        #define OS_VAR_SECTION_CORE4
                        #include "Os_LSL.lsl"
                        #undef OS_VAR_SECTION_CORE4
		            
                        /* Stack sections for Core4 */
                        #define OS_STACK_SECTION_CORE4
                        #include "Os_LSL.lsl"
                        #undef OS_STACK_SECTION_CORE4
                        select ".bss.Lib_VDISP_Main.*";
                        select ".data.Lib_VDISP_Main.*";
                        select ".bss.VDISP_Main.*";
                        select ".data.VDISP_Main.*";
                        
                }
		
		        /* RAM (Core5) */
                group (ordered, align = 0, run_addr = mem:dspr5|mem:dlmucpu5)
                {
                        /* Variable sections for ECUC Partition in Core5 */
                        #define OS_VAR_SECTION_CORE5
                        #include "Os_LSL.lsl"
                        #undef OS_VAR_SECTION_CORE5
		            
                        /* Stack sections for Core5 */
                        #define OS_STACK_SECTION_CORE5
                        #include "Os_LSL.lsl" 
                        #undef OS_STACK_SECTION_CORE5
                        select ".bss.IDSP2_Main.*";
                        select ".data.IDSP2_Main.*";
                        select ".bss.Ref_IDSP2.*";
                        select ".data.Ref_IDSP2.*";   

                }
#endif       
     	
                /* RAM - BSS, DATA (Core0) */
                group (ordered, align = 0, run_addr = mem:dspr0|mem:dlmucpu0)
                {
                        #if defined(__HSM_USED__)
                        /* HAE HSM */
                        group HAE_HSM (ordered, align = 4)
                        {
                          select ".bss.Hsm_Context.*";
                          select ".bss.HSM_DRIVER*";
                        }
                        #endif
                        group BSS_CLEARED (ordered, align = 0)
                        {
                                /* BSW */
                                select ".bss.*_RAM_VAR_CLEARED_*";
                                select ".bss.*_RAM_VAR_POWER_ON_CLEARED_*";
                                select ".bss.*_RAM_VAR_INIT_*";
                                /* MCAL */
                                select ".bss.ClearedData.Cpu0.*";
                                select ".bss.ClearedData.LmuNC.*";
                        }
                        group BSS_NOCLEARED (ordered, align = 0)
                        {
                                /* BSW */
                                select ".bss.*_RAM_VAR_NO_INIT_*";
                                select ".bss.*_RAM_VAR_SAVED_ZONE_*";
                        }
                        group DATA (ordered, align = 0)
                        {
                                /* BSW */
                                select ".data.*_RAM_VAR_CLEARED_*";
                                select ".data.*_RAM_VAR_INIT_*";
                                /* MCAL */
                                select ".data.InitData.Cpu0.*";
                                select ".data.InitData.LmuNC.*";
                        }
					
                        /* Variable sections for ECUC Partition in Core0 */
                        #define OS_VAR_SECTION_CORE0
                        #include "Os_LSL.lsl"
                        #undef OS_VAR_SECTION_CORE0 
		            
                        /* Stack sections for Core0 */
                        #define OS_STACK_SECTION_CORE0
                        #include "Os_LSL.lsl" 
                        #undef OS_STACK_SECTION_CORE0
		                                   
                        group STACK_RAMDATA (ordered, align = 8)
                        {
                                select ".bss.OSAPP_STACK";
                                select ".bss.USR_STACK";
                                select ".bss.OSTASK_STACK";
                        }
					
                        group UNDEFINED_RAMDATA
                        {
                                select ".bss*";
                                select ".data*";
                        }
                }
        }

#if !defined(__DISABLE_SCR_BOOT_MAGIC)
        /*
         *      The last 8 bytes of SCR XRAM starting at address 0x01FF8 must contain
         *      4 pairs of bytes where each pair consists of 0x55 followed by 0xAA.
         *      The user code will not be executed and the SCR will enter an endless
         *      loop if the memory content does not match this data sequence. This
         *      feature is meant to avoid an unintentional entry into User Mode 1.
         *      When the 8 bytes match, the SCR boot code will trigger an interrupt
         *      to the TriCore by setting bit NMICON.SCRINTTC to 1 with a value of 0x80
         *      in the SCRINTEXCHG register. When the 8 bytes do not match, the same
         *      interrupt is triggered with a value of 0x81 in the SCRINTEXCHG register.
         */
        section_layout :xc800:xdata
        {
                group(ordered, run_addr=0x1ff8)
                {
                        struct "scr_boot_magic"
                        {
                                0x55:1; 0xaa:1;
                                0x55:1; 0xaa:1;
                                0x55:1; 0xaa:1;
                                0x55:1; 0xaa:1;
                        }
                }
        }
#endif
}

section_layout :vtc:linear
{
  #if defined(__FBL_USED__)
  group FBL             (run_addr = 0x80000000, ordered) reserved "FBL_CODE"                (size=128K);
  /* RAM to store Startup command by application to retain control in Bootloader for re-programming */
  group STARTUP_COMMAND (run_addr = 0x7003BFF0, ordered) reserved ".STARTUP_COMMAND"        (size=0x4);
  /* Shared RAM between application to store Programming conditions */
  group PROG_CONDITIONS (run_addr = 0x7003BFF4, ordered) reserved ".PROG_CONDITIONS"        (size=0xC);
  #endif
  #if defined(__HSM_USED__)
  /* Bank A */
  group HSM             (run_addr = 0x80020000, ordered) reserved "HSM_CODE"                (size=160K);
  /* Bank B */
  /* If you use memory swap, the hsm binary must exist in the bank B area. */
  #endif
}
//
//      The following macros are required for extmem.lsl
//
#define HAS_ON_CHIP_FLASH       // This derivative has on-chip flash
#define HAS_NO_EXTERNAL_RAM     // Exclude xram_8_a
#endif
