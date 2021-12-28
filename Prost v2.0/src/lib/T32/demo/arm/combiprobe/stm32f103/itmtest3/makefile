OBJS=crt0.o test.o vectortable.o
APPL=test.elf

all: $(APPL)

%.o: %.c
	arm-unknown-eabi-gcc -mthumb -mcpu=cortex-m3 -O -g -c $<

%.o: %.s
	arm-unknown-eabi-gcc -mthumb -mcpu=cortex-m3 -c -g $<

$(APPL): $(OBJS)
	arm-unknown-eabi-ld -v -n -T ldsimple.script -o $@ $^

clean:
	rm -f *~ *.elf *.hex *.o *.srec *.mif *.bak
