
CC:=arm-unknown-eabi-gcc
LD:=arm-unknown-eabi-ld

APPL:=pin_tgl.elf
SRCS:=crt0.s vectortablek60.s timerk60.c pin_tgl.c

ifneq ($(MAKECMDGOALS),clean)
  # First call script to find full relative path name of source code files
  SRCSFULL:=$(shell ./scripts/find_files.sh $(SRCS))
  ifeq ($(SRCSFULL),)
    $(error could not find all source files)
  endif

  # Now convert source code files into path to object files
  OBJSFULL:=$(patsubst src/%,obj/%,$(SRCSFULL))
  OBJSFULL:=$(patsubst %.c,%.o,$(OBJSFULL))
  OBJSFULL:=$(patsubst %.s,%.o,$(OBJSFULL))

  # Generate directories here
  # Stupid trick to call make_dirs here.
  DUMMY:=$(shell ./scripts/make_dirs.sh $(OBJSFULL))
endif

# Directed Acyclic Graph what is needed to build application
all: $(APPL)

obj/%.o : src/%.c
	$(CC) -mthumb -mcpu=cortex-m3 -O -g -c -o $@ $<

obj/%.o : src/%.s
	$(CC) -mthumb -mcpu=cortex-m3 -g -c -o $@ $<

$(APPL): $(OBJSFULL)
	$(LD) -v -n -T ldsimple.script -o $@ $^

# mini rule to clean project
clean:
	rm -rf obj
	rm -f $(APPL) *~ 
