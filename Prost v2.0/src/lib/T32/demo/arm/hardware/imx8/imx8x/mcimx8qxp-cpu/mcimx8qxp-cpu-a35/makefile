## code generation
# FLASHSTART=0x0
RAMSTART=0x80000000
TARGET=sieve.c stm_stimulus.c
# WATCHDOG=1
RAMSIZE=0x90000
DEFINE=ETRSIZE=0x80000

include ${T32SYS}/demo/arm64/compiler/gnu-make/cortex-a-aarch64/makefile

target: target-a35
	

# include special-rule.mk.internal if existing - for Lauterbach internal usage
-include special-rule.mk.internal

