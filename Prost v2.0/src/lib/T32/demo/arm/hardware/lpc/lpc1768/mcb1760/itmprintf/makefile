TESTOBJS=test.o vsprintf.o retarget.o
TEST=test.axf

SETUPOBJS=setup_clocks.o
SETUP=setup_clocks.axf

all: $(TEST) $(SETUP)

test: $(TEST)

setup: $(SETUP)

%.o: %.c
	armcc -O0 --thumb --cpu=cortex-m3 -g -c $<

%.o: %.s
	armcc -O0 --thumb --cpu=cortex-m3 -g -c  $<

$(TEST): $(TESTOBJS)
	armlink --inline --scatter=scatter.scat --noremove --info=unused -o $@ $^ 

$(SETUP): $(SETUPOBJS)
	armlink --entry setup_clocks --ro_base 0x2007C000 --noremove --info=unused -o $@ $^ 

mrproper:
	rm -f *~ *.elf *.hex *.o *.srec *.mif *.bak *.o *.axf
	
clean:
	rm -f *.hex *.o *.srec *.mif *.bak *.o
