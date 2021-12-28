## code generation
# FLASHSTART=0x0
RAMSTART=0xFFFF0000
WATCHDOG=1
RAMSIZE=0xFFC0
DEFINE=ETRSIZE=0x9000 BOOTHEADER=1
SRC=stm.c

.PHONY: default
default: sieve_ram_arm_v7.elf

include ${T32SYS}/demo/arm/compiler/gnu-make/cortex-a/makefile

target: target-a9


# include special-rule.mk.internal if existing - for Lauterbach internal usage
-include special-rule.mk.internal

