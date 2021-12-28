## code generation
# FLASHSTART=0x0
RAMSTART=0x900000
# WATCHDOG=1
RAMSIZE=0x20000
DEFINE=ETRSIZE=0x8000

include ${T32SYS}/demo/arm64/compiler/gnu-make/cortex-a-aarch64/makefile

target: target-a53
	

# include special-rule.mk.internal if existing - for Lauterbach internal usage
-include special-rule.mk.internal

