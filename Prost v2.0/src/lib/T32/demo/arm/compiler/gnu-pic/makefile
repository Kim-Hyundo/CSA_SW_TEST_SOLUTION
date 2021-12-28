RAMSTART := 0x0
TARGET   := sieve.c midi.c stm_stimulus.c itm_stimulus.c
DEFINE   := STACKSIZE=0x100

include ${T32SYS}/demo/arm/compiler/gnu-make/pic/makefile

rename: all
	find . -name "*_pic_*elf" -exec rename -f 's/_pic_/_/g' \{\} \;
	rm *_pie_*elf
