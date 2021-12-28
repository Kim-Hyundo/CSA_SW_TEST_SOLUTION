.section .text.crt
.globl  _start
.globl  _exit.crt0
.globl  watchdogTrigger

#ifdef __thumb__
# define subs sub
#endif

_start:
    /* get current PC , in R7 */
    bl     _start_pc
_start_pc:
    /* get PC from LR and correct it */
    mov    r7, lr
    mov    r0, #1
    bic    r7,r7,r0
    ldr    r0, .BASE
    subs   r7,r7,r0

    /* set stack and frame pointer */
    ldr    r1, .SP
    add    r1, r7
    mov    r0, #3
    bic    r1, r0 
    mov    r0, #0
    mov    sp, r1
    mov    fp, r0

    /* clear .bss-section */
    ldr    r4, .BSS_S
    ldr    r5, .BSS_E
    mov    r0, #0
    b      bss_check
bss_clear:
    strb   r0, [r7,r4]
    add    r4, r4, #1
bss_check:
    cmp    r5, r4
    bne    bss_clear
bss_done:

    /* correct global-offset-table, GOT */
    ldr    r4, .GOT_S
    ldr    r5, .GOT_E
    b      got_check
got:
    ldr    r3, [r7,r4]
    add    r3, r7
    str    r3, [r7,r4]
    add    r4, r4, #4
got_check:
    cmp    r5, r4
    bne    got
got_done:

    /* initialize Watchdog */
    ldr    r3, .WDG_INIT
    cmp    r3, #0
    beq    wdg_init_done
    add    r3, r7
    bl     crt0_veneer
wdg_init_done:
    /* register the WatchdogHook */
    ldr    r3, .WDG_TRIGGER
    ldr    r4, .WDG_HOOK
    cmp    r3, #0
    beq    wdg_hook_done
    add    r3, r7
wdg_hook_done:
    str    r3,[r7,r4]

    /* initialization of e.g. static objects */
    ldr    r4, .INIT_S
    ldr    r5, .INIT_E
    b      init_check
init:
    ldr    r3,[r7,r4]
    add    r3, r7
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
    b      _exit.crt0

crt0_veneer:
    /* make a THUMB/ARM generic veneer call to r3 */
    /* lr is set by preceding bl instruction      */
    mov    r0, #0
    mov    r1, #0
    bx     r3

.org     0xFC
_start_secondary:
    /* get current PC , in R7 */
    bl    _start_secondary_pc
    .align 1
_start_secondary_pc:
    /* get PC from LR and correct it */
    mov    r7, lr
    mov    r0, #1
    bic    r7,r7,r0
    subs   r7,r7,#4

    /* set stack and frame pointer */
    /* _start_secondary-_start = 0x100 -> SP is placed 0x100 bytes after SP of Core0 */
    ldr    r1, .SP
    add    r1, r7
    mov    r0, #0
    mov    sp, r1
    mov    fp, r0
    bl     background
    b      _exit.crt0

.align  2
.BASE:
    .word __SRAM_start+0x4+0x4
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
.GOT_S:
    .word __got_start
.GOT_E:
    .word __got_end
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

.section .data
watchdogTrigger:
    .word 0x0

