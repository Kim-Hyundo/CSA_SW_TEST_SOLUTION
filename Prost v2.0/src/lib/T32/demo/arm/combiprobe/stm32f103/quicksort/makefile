OBJS=crt0.o quicksort.o main.o
APPL=quicksort.elf

all: $(APPL)

%.o: %.c
	arm-none-eabi-gcc -mthumb -mcpu=cortex-m3 -O -g -c $<

%.o: %.s
	arm-none-eabi-gcc -mthumb -mcpu=cortex-m3 -c -g $<

$(APPL): $(OBJS)
	arm-none-eabi-ld -v -n -T ldsimple.script -o $@ $^

clean:
	rm -f *~ *.elf *.hex *.o *.srec *.mif *.bak
