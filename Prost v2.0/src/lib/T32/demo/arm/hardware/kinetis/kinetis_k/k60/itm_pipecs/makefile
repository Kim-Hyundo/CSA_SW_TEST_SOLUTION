# Compile simple SORT demo for ARM, with Cygwin and GNU Compiler.

# First of all adopt ldsimple.script to define where your RAM is located

# CPUDEF is used to compile for the correct CPU.
CPUDEF:=-mthumb -mcpu=cortex-m3

# Use GNU Compiler.
CC:=arm-unknown-eabi-gcc
LD:=arm-unknown-eabi-ld

APPL:=sort.elf
SRCS:=sort.c

OBJS:=obj/crt0.o $(patsubst %.c,obj/%.o,$(SRCS))
SRCS:=$(patsubst %.c,src/%.c,$(SRCS))

all: $(APPL)

$(OBJS): | obj

obj:
	mkdir obj

$(APPL): $(OBJS)
	$(LD) -v -n -T ldsimple.script -o $@ $^

obj/crt0.o: src/crt0.s
	$(CC) $(CPUDEF) -g -c -o $@ $<

obj/%.o : src/%.c
	$(CC) $(CPUDEF) -g -O -fno-inline -c -o $@ $<

clean:
	rm -rf obj $(APPL)

