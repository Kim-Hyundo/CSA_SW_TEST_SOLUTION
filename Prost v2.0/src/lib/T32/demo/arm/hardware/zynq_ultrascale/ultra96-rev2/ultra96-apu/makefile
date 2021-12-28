## code generation
# FLASHSTART=0x0
RAMSTART=0xffFc0000
TARGET=sieve.c stm_stimulus.c
# WATCHDOG=1
BOOTMPIDR=0x0000
RAMSIZE=0x8000
DEFINE=ETRSIZE=0x1000

include ${T32SYS}/demo/arm64/compiler/gnu-make/cortex-a-aarch64/makefile

target: target-a53
	

# include special-rule.mk.internal if existing - for Lauterbach internal usage
-include special-rule.mk.internal

