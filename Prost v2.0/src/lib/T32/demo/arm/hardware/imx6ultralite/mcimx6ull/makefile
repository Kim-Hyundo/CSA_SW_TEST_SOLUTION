## code generation
# FLASHSTART=0x0
RAMSTART=0x900000
# WATCHDOG=1

include ${T32SYS}/demo/arm/compiler/gnu-make/cortex-a/makefile

target: target-a9 target-pic

target-pic:
	make -f ${T32SYS}/demo/arm/compiler/gnu-make/pic/makefile RAMSTART=0x80000000 sieve_pic_armv7a.elf

-include special-rule.mk.internal

