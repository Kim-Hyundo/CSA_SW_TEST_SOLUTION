# Compile simple SIEVE demo for ARM, with Cygwin and GNU Compiler.

# First of all adopt ldsimple.script to define where your RAM is located

# CPUDEF is used to compile for the correct CPU.
CPUDEF:=-mthumb -mcpu=cortex-m3
COPTS:=-O -fno-inline -finstrument-functions

# Use GNU Compiler.
CCGRP := arm-none-eabi-
CC:=$(CCGRP)gcc
LD:=$(CCGRP)ld

APPL:=sieve.elf
SRCS:=sieve.c

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
	$(CC) $(CPUDEF) -g $(COPTS) -c -o $@ $<

clean:
	rm -rf obj $(APPL)

