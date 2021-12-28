## code generation
FLASHSTART=0x01000000
RAMSTART=0x1000
WATCHDOG=1
DEFINE=RAMSIZE=0x4000 RAMSTART=${RAMSTART} RAM_ECC_LONG

include ${T32SYS}/demo/arm/compiler/gnu-make/cortex-r/makefile

target: target-r4
	

# include special-rule.mk.internal if existing - for Lauterbach internal usage
-include special-rule.mk.internal

