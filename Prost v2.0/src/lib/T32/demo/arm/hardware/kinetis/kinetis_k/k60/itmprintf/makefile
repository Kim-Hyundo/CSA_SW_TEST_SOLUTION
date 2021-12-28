# Makefile to compile with a recent GCC for ARM

CC:=arm-unknown-eabi-gcc
LD:=arm-unknown-eabi-ld

APPL:=printfk60.elf
OBJSK60:=crt0.o printfk60.o timerk60.o vsprintf.o vectortablek60.o


OBJSK60:=$(patsubst %.o,obj/%.o,$(OBJSK60))

all: $(APPL)

$(OBJSK60): | obj

obj:
	mkdir obj

obj/%.o: src/%.c
	$(CC) -mthumb -mcpu=cortex-m3 -O -g -c -o $@ $<

obj/%.o: src/%.s
	$(CC) -mthumb -mcpu=cortex-m3 -c -g -o $@ $<

$(APPL): $(OBJSK60)
	$(LD) -v -n -T ldsimple.script -o $@ $^

clean:
	rm -rf obj
	rm -f $(APPL) *~ 
