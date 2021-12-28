.text

.globl  _start
.globl  _exit.crt0
.globl  watchdogTrigger


#ifdef __thumb__
# define subs sub
# define ands and
# define muls mul
#endif


_start:
    /* init SCTLR, VBAR and CPSR */
    mov    r1, #1
    mrc    p15,0x0,r0,c1,c0,0x0
    and    r0, r0, r1
    ldr    r1, .SCTLR_VALUE
    orr    r0, r0, r1
    mcr    p15,0x0,r0,c1,c0,0x0
    ldr    r0, .ISR_VECTOR_BASE
    mcr    p15,0x0,r0,c12,c0,0x0
    ldr    r0, .CPSR_VALUE
    msr    CPSR, R0
#if !defined(__SOFTFP__)
    bl     fpu_init
#endif
    /* check MPIDR - jump to _start_secondary*/
    mrc    p15,0x0,r0,c0,c0,0x5
    mov    r1, #3
    ands   r0,r1,r0
    bne    _start_secondary
    /* set stack and frame pointer */
    ldr    r1, .SP
    mov    r0, #7
    bic    r1, r0
    mov    r0, #0
    mov    sp, r1
    mov    fp, r0
    mov    lr, r0

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
    /* check MPIDR, calculate stackpointer */
    mrc   p15,0x0,r0,c0,c0,0x5
    mov   r1, #3
    ands  r0, r0, r1
    ldr   r1, .STACK_SIZE
    muls  r0, r1, r0
    /* set stack and frame pointer */
    ldr   r1, .SP_MP
    add   r1, r0, r1
    mov   r0, #0
    mov   sp, r1
    mov   fp, r0
    ldr   r3, .BACKGROUND
    bl    crt0_veneer
    b     _exit.crt0

#if !defined(__SOFTFP__)
fpu_init:
    ldr    r0, .CPACR_VALUE
    mrc    p15,0x0,r0,c1,c0,0x2
    ldr    r0, .FPEXC_VALUE
    vmsr   FPEXC, r0
    bx    r14
#endif

.align  2
.SP:
    .word __stack_end
.SP_MP:
    .word __stack_start_mp
.STACK_SIZE:
    .word __stack_size
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
.BACKGROUND:
    .word background
#ifdef __thumb__
.SCTLR_VALUE:
    .word 0x40C50078
.CPSR_VALUE:
    .word 0x000001F3
#else
.SCTLR_VALUE:
    .word 0x00C50078
.CPSR_VALUE:
    .word 0x000001D3
#endif
.ISR_VECTOR_BASE:
    .word isr_vector_base
#if defined(__ARM_FP)
.CPACR_VALUE:
    .word 0x00f00000
.FPEXC_VALUE:
    .word 0x40000000
#endif

.section .isr_vector,"ax"
isr_vector_base:
    b _start
    b _hang
    b _hang
    b _hang
    b _hang
    b _hang
    b _hang

#if BOOTHEADER
.org 0x40
boot_header:
    .4byte 0x31305341
    .2byte 0
    .2byte 0
    .2byte 0
    .2byte 0
    b _start
#endif


.section .data
watchdogTrigger:
    .word 0x0

.section .text
.weak background
background:
    nop
1:
    wfe
    b 1b
