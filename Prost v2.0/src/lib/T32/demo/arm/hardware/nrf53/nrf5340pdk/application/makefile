## code generation
#FLASHSTART=0x00000000  # internal flash
FLASHSTART=0x10000000  # external flash
RAMSTART=0x20000000
# WATCHDOG=1

include ${T32SYS}/demo/arm/compiler/gnu-make/cortex-m/makefile

target: target-m7
	

# include special-rule.mk.internal if existing - for Lauterbach internal usage
-include special-rule.mk.internal

