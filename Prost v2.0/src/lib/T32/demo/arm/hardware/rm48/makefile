## code generation
FLASHSTART=0x0
RAMSTART=0x08000000
RAMSIZE=0x10000
DEFINE=RAMSTART=${RAMSTART} RAMSIZE=${RAMSIZE} RAM_ECC_QUAD
# WATCHDOG=1
HARDFP=1

include ${T32SYS}/demo/arm/compiler/gnu-make/cortex-r/makefile

target: target-r4
	

# include special-rule.mk.internal if existing - for Lauterbach internal usage
-include special-rule.mk.internal

