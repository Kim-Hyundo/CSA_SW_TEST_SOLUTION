export SHELLOPTS := igncr


ARMCOPT := --debug --dwarf2 --cpu=4T --arm --littleend
ARMLOPT := --bestdebug --elf 


all: cppdemo.axf

%.obj: %.asm $(MAKEFILE_LIST)
	armasm $(ARMCOPT) -o $@ $< 

%.obj: %.c $(MAKEFILE_LIST)
	armcc $(ARMCOPT) -O0 -c -o $@ $< 

%.obj: %.cpp $(MAKEFILE_LIST)
	armcc $(ARMCOPT) -O0 -c -o $@ $< 

cppdemo.axf : linker.scat cppdemo.obj
	armlink $(ARMLOPT) -o $@ --scatter $^

clean:
	-rm -fv *.obj 
	-rm -fv cppdemo.axf

