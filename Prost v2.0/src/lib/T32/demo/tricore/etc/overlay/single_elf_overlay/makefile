# Makefile to build Overlay Example
# with HighTec GCC 
#
# (use GNU make)

export SHELLOPTS := igncr

NAME    := ovdemo
OBJECTS := blubber task1 task sieve ovdemo
#OBJECTS := crt0 blubber task1 task sieve funcasm ovdemo
TMP     := ./tmp
VPATH    = ./src

GOBJECTS := $(addprefix $(TMP)/, $(addsuffix .o, $(OBJECTS)))
GNUCOPT  := -Wall -g3 -mcpu=tc39xx -fshort-enums -fno-common
GNULOPT  := -Wall -g -mcpu=tc39xx -Wl,--nmagic -Wl,--no-warn-flags -Wl,--gc-sections
GCC := tricore-gcc

.PHONY : help
help:
	@echo make gnu : build overlay example with GNU GCC toolchain

.PHONY : clean
clean: gnu.clean

$(TMP):
	mkdir $(TMP)

.PHONY : gnu
gnu: $(NAME).elf $(NAME).alt.elf

$(TMP)/%.o: %.s  $(MAKEFILE_LIST) | $(TMP)
	$(GCC) $(GNUCOPT) -xassembler-with-cpp -c -o $@ $<

$(TMP)/%.o: %.c  $(MAKEFILE_LIST) | $(TMP)
	$(GCC) $(GNUCOPT) -c -o $@ $<

$(NAME).alt.elf: $(NAME).ld $(GOBJECTS) $(TMP)/func.o $(TMP)/inc.o
	$(GCC) $(GNULOPT)                   -o $@ -T $^ -Wl,-Map,$(TMP)/$(@:.elf=.map)

$(NAME).elf:     $(NAME).ld $(GOBJECTS) $(TMP)/mix.o
	$(GCC) $(GNULOPT) -Wl,--emit-relocs -o $@ -T $^ -Wl,-Map,$(TMP)/$(@:.elf=.map)

.PHONY : gnu.clean
gnu.clean:
	rm -fv $(TMP)/*.o
	rm -fv $(NAME)*.elf


