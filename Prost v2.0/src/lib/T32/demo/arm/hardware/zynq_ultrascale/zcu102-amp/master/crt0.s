
/*
 * Branch according to exception level
 * [taken from U-Boot]
 */
.macro  switch_el, xreg, el3_label, el2_label, el1_label
    mrs     \xreg, CurrentEL
    cmp     \xreg, 0xc
    b.eq    \el3_label
    cmp     \xreg, 0x8
    b.eq    \el2_label
    cmp     \xreg, 0x4
    b.eq    \el1_label
.endm

.text

.globl  _start
.globl  _exit.crt0
.globl  watchdogTrigger


_start:
    /* set stack and frame pointer */
    ldr     x1,  .SP
    mov     x0,  #0xf
    bic     x1,  x1,  x0
    mov     sp,  x1
    mov     x29, #0x0
    
    ldr     x0, .ISR_VECTOR_BASE
    switch_el x1, 3f, 2f, 1f
3:  /* EL3 */
    msr     vbar_el3, x0
    b       0f
    
2:  /* EL2 */
    msr     vbar_el2, x0
#if !defined(__SOFTFP__)
    /* enable FPU */
    mov     x0,  #0x33ff
    msr     cptr_el2, x0
#endif
    b       0f
    
1:  /* EL1 */
    msr     vbar_el1, x0
#if !defined(__SOFTFP__)
    /* enable FPU */
    mov     x0,  #3 << 20
    msr     cpacr_el1, x0
#endif

0: 
    /* Check MultiprocessorID */
    mrs	    x0,  mpidr_el1
    tst	    x0,  #0xf
    b.ne	_start_secondary

bss_init:
    /* clear .bss-section */
    ldr     x4,  .BSS_S
    ldr     x5,  .BSS_E
    mov     x0,  #0
    b       bss_check
bss_clear:
    strb    w0,  [x4]
    add     x4,  x4, #1
bss_check:
    cmp     x5,  x4
    bne     bss_clear
bss_done:

    /* initialize Watchdog */
    ldr     x3,  .WDG_INIT
    cmp     x3,  #0
    beq     wdg_init_done
    bl      crt0_veneer
wdg_init_done:
    /* register the WatchdogHook */
    ldr     x3,  .WDG_TRIGGER
    ldr     x4,  .WDG_HOOK
    str     x3,  [x4]

    /* initialization of e.g. static objects */
    ldr     x4,  .INIT_S
    ldr     x5,  .INIT_E
    b       init_check
init:
    ldr     x3,  [x4]
    bl      crt0_veneer
    add     x4,  x4,  #8
init_check:
    cmp     x5,  x4
    bne     init
init_done:

gomain:
    ldr     x3,  .MAIN
    bl      crt0_veneer
    nop

_exit.crt0:
    b       _exit.crt0
    
_hang:
    b       _hang

crt0_veneer:
    /* make a generic veneer call to r3 */
    /* lr is set by preceding bl instruction      */
    mov     x0,  #0
    mov     x1,  #0
    br      x3

//.org     0xF8
_start_secondary:
    ldr     x1,  .STACK_SIZE
    mul     x0,  x0, x1
    ldr     x1,  .SP_MP
    add     x0,  x0, x1
    mov     sp,  x0
    mov     x29, #0
    ldr     x3,  .BACKGROUND
    bl      crt0_veneer
    nop
    b       _exit.crt0
.align  3
.SP:
    .quad   __stack_end
.SP_MP:
    .quad   __stack_start_mp
.STACK_SIZE:
    .quad   __stack_size
.BSS_S:
    .quad   __bss_start
.BSS_E:
    .quad   __bss_end
.INIT_S:
    .quad   __init_array_start
.INIT_E:
    .quad   __init_array_end
.DATA_S:
    .quad   __data_vaddr
.DATA_LADDR:
    .quad __data_laddr
.DATA_SIZE  :
    .quad   __data_size
#ifndef WATCHDOG
.WDG_INIT:
    .quad   0x0
.WDG_TRIGGER:
    .quad   0x0
#else
.WDG_INIT:
    .quad   WatchdogInit
.WDG_TRIGGER:
    .quad   WatchdogTrigger
#endif
.WDG_HOOK:
    .quad   watchdogTrigger
.MAIN:
    .quad   main
.BACKGROUND:
    .quad   background
.ISR_VECTOR_BASE:
    .quad   isr_vector_base

.section .isr_vector,"ax"
isr_vector_base:
    .org 0x000
    b       _hang   /* Current EL Synchronous Thread */

    .org 0x080
    b       _hang   /* Current EL IRQ Thread */

    .org 0x100
    b       _hang   /* Current EL FIQ Thread */

    .org 0x180
    b       _hang   /* Current EL Error Thread */

    .org 0x200
    b       _hang   /* Current EL Synchronous Handler */

    .org 0x280
    b       _hang   /* Current EL IRQ Handler */

    .org 0x300
    b       _hang   /* Current EL FIQ Handler */

    .org 0x380
    b       _hang   /* Current EL Error Handler */

.section .data
.align  3
watchdogTrigger:
    .quad 0x0

.section .text
.weak background
background:
    nop
1:
    wfe
    b 1b
