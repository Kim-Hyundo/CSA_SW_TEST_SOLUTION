# Makefile to build Example with ARM RealView (>=2.2) toolchain
#
# (use GNU make)

export SHELLOPTS := igncr

NAME    := demo
OBJ     := crt0.obj demo.obj
TMP     := ./tmp

COPT := --debug --dwarf2 --cpu=Cortex-M4
LOPT := --bestdebug --elf


.PHONY : all
all: $(NAME).elf

%.obj: %.asm $(MAKEFILE_LIST)
	armasm $(COPT) -o $@ $<

%.obj: %.c   $(MAKEFILE_LIST)
	armcc $(COPT) -O0 -c -o $@ $<

$(NAME).elf: $(NAME).scat $(OBJ)
	armlink $(LOPT) -o $@ --scatter $^

.PHONY : .clean
clean:
	rm -fv *.obj
	rm -fv $(NAME)*.elf

