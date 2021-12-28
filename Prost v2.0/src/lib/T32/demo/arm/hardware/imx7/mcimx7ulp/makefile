## code generation
# FLASHSTART=0x0
RAMSTART=0x20000000
WATCHDOG=1
HARDFP=1
RAMSIZE=0x10000
DEFINE=ETRSIZE=0x2000

include ${T32SYS}/demo/arm/compiler/gnu-make/cortex-m/makefile

target: target-m4 target-a7

target-a7:
	make -f ${T32SYS}/demo/arm/compiler/gnu-make/pic/makefile RAMSTART=0x2F000000 sieve_pic_arm.elf
	

# include special-rule.mk.internal if existing - for Lauterbach internal usage
-include special-rule.mk.internal

