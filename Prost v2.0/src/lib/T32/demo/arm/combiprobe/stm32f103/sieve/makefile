OBJS=crt0.o sieve.o
APPL=sieve.elf

all: $(APPL)

%.o: %.c
	arm-none-eabi-gcc -mthumb -mcpu=cortex-m3 -g -c $<

%.o: %.s
	arm-none-eabi-gcc -mthumb -mcpu=cortex-m3 -g -c $<

$(APPL): $(OBJS)
	arm-none-eabi-ld -v -n -T ldsimple.script -o $@ $^

clean:
	rm -f *~ *.elf *.hex *.o *.srec *.mif *.bak
