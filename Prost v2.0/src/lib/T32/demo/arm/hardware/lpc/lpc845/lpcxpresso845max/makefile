## code generation
FLASHSTART=0x0
RAMSTART=0x10000000
WATCHDOG=1
TARGET=midi.c
DEFINE=NVICSIZE=0x100 KEEPSIZE=0x340

include ${T32SYS}/demo/arm/compiler/gnu-make/cortex-m/makefile

target: target-m0p
	

# include special-rule.mk.internal if existing - for Lauterbach internal usage
-include special-rule.mk.internal

