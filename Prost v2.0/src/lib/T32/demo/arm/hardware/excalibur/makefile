export SHELLOPTS := igncr


NAME    := arm
OBJECTS := crt0 arm

GOBJECTS := $(addsuffix .o, $(OBJECTS))
COPT := -g -Wall -mcpu=arm922t -mlittle-endian -msoft-float -fshort-enums
LOPT := -g -Wall -mcpu=arm922t -mlittle-endian -msoft-float -Wl,--nmagic -nostartfiles
GCC := arm-none-eabi-gcc


all: $(NAME).elf 

%.o: %.s makefile  $(MAKEFILE_LIST)
	$(GCC) $(COPT) -c -Wa,--gdwarf2 -xassembler-with-cpp -o $@ $< 

%.o: %.c makefile  $(MAKEFILE_LIST)
	$(GCC) $(COPT) -c -o $@ $< 

$(NAME).elf: $(GOBJECTS) $(NAME).ld makefile
	$(GCC) $(LOPT) -T$(NAME).ld -o $(NAME).elf $(GOBJECTS) -lm 


clean:
	rm -fv *.o 
	rm -fv $(NAME).elf 

