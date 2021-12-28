.text
.globl  _start
.globl  _exit.crt0
.globl  watchdogTrigger


#ifdef __thumb__
# define subs sub
#endif


_start:
    /* disable interrupts, enable faults */
    cpsid  i
    cpsie  f
    mov    r0, #0
    msr    BASEPRI, r0
    /* set stack and frame pointer */
    ldr    r1, .SP
    mov    r0, #7
    bic    r1, r0 
    mov    r0, #0
    mov    sp, r1
    mov    fp, r0
    mov    lr, r0
#if defined(__ARM_ARCH_7M__)||defined(__ARM_ARCH_7EM__)
    /* set NVIC Base */
    ldr    r4, .VTOR
    ldr    r0, .NVIC_BASE
    str    r0, [r4]
#if (__ARM_FP==4)||(__ARM_FP==5)
    /* enable FPU */
    ldr    r4, .CPACR
    ldr    r1, .CPACR_FPU_EN
    ldr    r0,[r4]
    orr    r0, r1
    str    r0,[r4]
#endif
#endif

    /* copy data from FLASH to SRAM */
    ldr    r4, .DATA_S
    ldr    r5, .DATA_LADDR
    ldr    r6, .DATA_SIZE
    cmp    r4, r5
    beq    data_done
data_copy:
    ldrb   r0, [r5]
    strb   r0, [r4]
    add    r4, r4, #1
    add    r5, r5, #1
    subs   r6, r6, #1
    bne    data_copy
data_done:

    /* clear .bss-section */
    ldr    r4, .BSS_S
    ldr    r5, .BSS_E
    mov    r0, #0
    b      bss_check
bss_clear:
    strb   r0, [r4]
    add    r4, r4, #1
bss_check:
    cmp    r5, r4
    bne    bss_clear
bss_done:

    /* initialize Watchdog */
    ldr    r3, .WDG_INIT
    cmp    r3, #0
    beq    wdg_init_done
    bl     crt0_veneer
wdg_init_done:
    /* register the WatchdogHook */
    ldr    r3, .WDG_TRIGGER
    ldr    r4, .WDG_HOOK
    str    r3, [r4]

    /* initialization of e.g. static objects */
    ldr    r4, .INIT_S
    ldr    r5, .INIT_E
    b      init_check
init:
    ldr    r3,[r4]
    bl     crt0_veneer
    add    r4, r4, #4
init_check:
    cmp    r5, r4
    bne    init
init_done:

gomain:
    ldr    r3, .MAIN
    bl     crt0_veneer

_exit.crt0:
    /* we should never get here */
    b     _exit.crt0

_hang:
    /* default fault handler */
    b     _hang

crt0_veneer:
    /* make a THUMB/ARM generic veneer call to r3 */
    /* lr is set by preceding bl instruction      */
    mov    r0, #0
    mov    r1, #0
    bx     r3

.org 0x100
_start_secondary:
    /* set stack and frame pointer */
    /* _start_secondary-_start = 0x100 -> SP is placed 0x100 bytes after SP of Core0 */
    ldr   r1, .SP
    mov   r0, #0
    mov   sp, r1
    mov   fp, r0
    bl    background
    b     _exit.crt0

.align  2
.SP:
    .word __stack_end
.BSS_S:
    .word __bss_start
.BSS_E:
    .word __bss_end
.INIT_S:
    .word __init_array_start
.INIT_E:
    .word __init_array_end
.DATA_S:
    .word __data_vaddr
.DATA_LADDR:
    .word __data_laddr
.DATA_SIZE:
    .word __data_size
#ifndef WATCHDOG
.WDG_INIT:
    .word 0x0
.WDG_TRIGGER:
    .word 0x0
#else
.WDG_INIT:
    .word WatchdogInit
.WDG_TRIGGER:
    .word WatchdogTrigger
#endif
.WDG_HOOK:
    .word watchdogTrigger
.MAIN:
    .word main
.NVIC_BASE:
    .word __nvic_base
.VTOR:
    .word 0xe000ed08
.CPACR:
    .word 0xe000ed88
.CPACR_FPU_EN:
    .word 0x00f00000

.section .isr_vector
    .word __stack_end  /* 0x00 initial SP */
    .word _start+1     /* 0x04 Reset */
    .word _hang+1      /* 0x08 NMI */
    .word _hang+1      /* 0x0c Hard fault */
    .word 0            /* 0x10 MPU */
    .word 0            /* 0x14 Bus fault */
    .word 0            /* 0x18 Usage fault */
    .word 0            /* 0x1C Reserved */
    .word 0            /* 0x20 Reserved */
    .word 0            /* 0x24 Reserved */
    .word 0            /* 0x28 Reserved */
    .word 0            /* 0x2c SVCall */
    .word 0            /* 0x30 Reserved */
    .word 0            /* 0x34 Reserved */
    .word 0            /* 0x38 PendSV */
    .word 0            /* 0x3c Systick */
    /* 0x40 onwards NVIC table */

.section .data
watchdogTrigger:
    .word 0x0

