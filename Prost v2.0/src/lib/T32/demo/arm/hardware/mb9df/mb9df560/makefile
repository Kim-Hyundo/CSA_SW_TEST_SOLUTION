## code generation
FLASHSTART=0xa00000
RAMSTART=0x0
WATCHDOG=1
DEFINE=RAMSTART=${RAMSTART} RAMSIZE=0x4000 RAM_ECC_LONG

include ${T32SYS}/demo/arm/compiler/gnu-make/cortex-r/makefile

target: target-r5
	

# include special-rule.mk.internal if existing - for Lauterbach internal usage
-include special-rule.mk.internal

