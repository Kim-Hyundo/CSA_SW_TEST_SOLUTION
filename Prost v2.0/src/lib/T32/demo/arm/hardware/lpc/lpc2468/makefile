# Makefile to build Example with ARM RealView (>=2.2) toolchain
#
# (use GNU make)

export SHELLOPTS := igncr

NAME    := demo
OBJ     := crt0.obj demo.obj
TMP     := ./tmp

COPT := --debug --dwarf2 --cpu=ARM7TDMI-S --arm --littleend
LOPT := --bestdebug --elf


.PHONY : all
all: $(NAME).axf

%.obj: %.asm $(MAKEFILE_LIST)
	armasm $(COPT) -o $@ $<

%.obj: %.c   $(MAKEFILE_LIST)
	armcc $(COPT) -O0 -c -o $@ $<

$(NAME).axf: $(NAME).scat $(OBJ)
	armlink $(LOPT) -o $@ --scatter $^

.PHONY : .clean
clean:
	rm -fv *.obj
	rm -fv $(NAME)*.axf

