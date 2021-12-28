# Compile simple SORT demo for ARM, with Cygwin and GNU Compiler.

# First of all adopt ldsimple.script to define where your RAM is located

# CPUDEF is used to compile for the correct CPU.
CPUDEF:=-mthumb -mcpu=cortex-m3

# Use GNU Compiler.
CC:=arm-unknown-eabi-gcc
LD:=arm-unknown-eabi-ld


SRCS:=test.c timerk60.c
OBJS:=$(patsubst %.c,obj/%.o,$(SRCS))
SRCS:=$(patsubst %.c,src/%.c,$(SRCS))

OBJS:=obj/crt0.o obj/vectortablek60.o $(OBJS)

all: itm_infinite.elf

$(OBJS) : obj

obj:
	mkdir obj

itm_infinite.elf: $(OBJS)
	$(LD) -v -n -T ldsimple.script -o $@ $^

obj/crt0.o: src/crt0.s
	$(CC) $(CPUDEF) -g -c -o $@ $<

obj/vectortablek60.o: src/vectortablek60.s
	$(CC) $(CPUDEF) -g -c -o $@ $<

obj/%.o : src/%.c
	$(CC) $(CPUDEF) -g -Os -fno-inline -c -o $@ $<

clean:
	rm -rf obj itm_infinite.elf
