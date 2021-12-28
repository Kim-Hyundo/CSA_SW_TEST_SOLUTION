# Compile simple SORT demo for ARM, with Cygwin and GNU Compiler.

# First of all adopt ldsimple.script to define where your RAM is located

# CPUDEF is used to compile for the correct CPU.
CPUDEF:=-mthumb -mcpu=cortex-m3

# Use GNU Compiler.
CC:=arm-unknown-eabi-gcc
LD:=arm-unknown-eabi-ld

APPL:=sort.elf
SRCS:=sort.c

# If you comment out the following line there will be no call
# to all the O(n*n) sort algorithms
# these include
#  * Selection Sort (selsort)
#  * Bubble Sort
#  * Insertion Sort (isort)
# This is done by a trick which allows to call functions before
# the "main()" function is executed.
# This in turn allows to run initialization code, depending on the
# object files you link to your application.
SRCS+=before_main1.c

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

obj/%.o: src/%.s
	$(CC) $(CPUDEF) -g -c -o $@ $<

obj/%.o : src/%.c
	$(CC) $(CPUDEF) -g -Og -fno-inline -c -o $@ $<

clean:
	rm -rf obj $(APPL)

