## code generation
FLASHSTART=0x0
RAMSTART=0x20000000
WATCHDOG=1
DEFINE=NVICSIZE=0xc0 NO_FLOAT KEEPSIZE=0x420-0xc0

include ${T32SYS}/demo/arm/compiler/gnu-make/cortex-m/makefile

target: target-m0p
	

# include special-rule.mk.internal if existing - for Lauterbach internal usage
-include special-rule.mk.internal

