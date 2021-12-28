## code generation
# FLASHSTART=0x0
RAMSTART=0x40300000
WATCHDOG=1
HARDFP=VFPv3

include ${T32SYS}/demo/arm/compiler/gnu-make/cortex-a/makefile

target: target-a8 target-m3

target-m3:
	make -f ${T32SYS}/demo/arm/compiler/gnu-make/pic/makefile RAMSTART=0x20000000 sieve_pic_thumb_ii_v7m.elf
	

# include special-rule.mk.internal if existing - for Lauterbach internal usage
-include special-rule.mk.internal

