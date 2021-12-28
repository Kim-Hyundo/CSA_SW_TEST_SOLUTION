export SHELLOPTS := igncr

CPU   := -march=armv4t -mlittle-endian  -mthumb -msoft-float
CPUM  := -march=armv7-m -mcpu=cortex-m3 -mthumb -msoft-float -mfix-cortex-m3-ldrd
AOPT  := -Wall -g -Wa,--gdwarf2 -xassembler-with-cpp -c
COPT  := -Wall -g3 -fshort-enums -c
LOPTA := -Wall -g -Wl,--nmagic -nostartfiles -nodefaultlibs
LOPT  := $(LOPTA) -Wl,--thumb-entry=_start
TMP   := ./tmp
VPATH := . ./src

CCGRP := arm-none-eabi-

all: sieve.elf sieve_cm.elf sieve_flash.elf sieve_cm_flash.elf cppdemo.elf

$(TMP):
	-mkdir $(TMP)

$(TMP)/%.thumb.o: %.c   $(MAKEFILE_LIST)
	$(CCGRP)gcc $(CPU)  $(COPT) -o $@ $<

$(TMP)/%.thumb2.o: %.c   $(MAKEFILE_LIST)
	$(CCGRP)gcc $(CPUM) $(COPT) -o $@ $<

$(TMP)/%.arm.o:    %.c   $(MAKEFILE_LIST)
	$(CCGRP)gcc $(CPU)  $(COPT) -marm -o $@ $<

$(TMP)/%.arm9.o:   %.c   $(MAKEFILE_LIST)
	$(CCGRP)gcc $(CPU)  $(COPT) -marm -DARM9 -o $@ $<

$(TMP)/%.thumb.o:  %.cpp $(MAKEFILE_LIST)
	$(CCGRP)g++ $(CPU)  $(COPT) -o $@ $<

$(TMP)/%.arm.o:    %.sx  $(MAKEFILE_LIST)
	$(CCGRP)gcc $(CPU)  $(AOPT) -marm -o $@ $<

$(TMP)/%.thumb.o:  %.sx  $(MAKEFILE_LIST)
	$(CCGRP)gcc $(CPU)  $(AOPT) -Wa,-mthumb -o $@ $<

$(TMP)/%.flash.o:  %.sx  $(MAKEFILE_LIST)
	$(CCGRP)gcc $(CPU)  $(AOPT) -Wa,-mthumb -o $@ $< -D BOOT_FROM_FLASH

$(TMP)/sieve1.ld: sieve.ldx $(MAKEFILE_LIST) | $(TMP)
	$(CCGRP)cpp -P -o $@ $< -D RAM_ORIGIN=0x00000400

$(TMP)/sieve2.ld: sieve.ldx $(MAKEFILE_LIST) | $(TMP)
	$(CCGRP)cpp -P -o $@ $< -D RAM_ORIGIN=0x20000000

$(TMP)/sieve3.ld: sieve.ldx $(MAKEFILE_LIST) | $(TMP)
	$(CCGRP)cpp -P -o $@ $< -D RAM_ORIGIN=0x20000000 -D ROM_ORIGIN=0x00000400

cppdemo.ld:  | $(TMP)

sieve_arm32.elf:        $(addprefix $(TMP)/,sieve1.ld crt0.arm.o sieve.arm.o)
	$(CCGRP)gcc $(CPU)  $(LOPTA) -o $@ -T $^ -lm -lgcc

sieve.elf:              $(addprefix $(TMP)/,sieve1.ld crt0.thumb.o isr.arm9.o sieve.thumb.o monitor.arm9.o itm.thumb.o)
	$(CCGRP)gcc $(CPU)  $(LOPT)  -o $@ -T $^ -lm -lgcc

sieve_flash.elf:        $(addprefix $(TMP)/,sieve3.ld crt0.flash.o sieve.thumb.o monitor.arm9.o lib.thumb.o)
	$(CCGRP)gcc $(CPU)  $(LOPT)  -o $@ -T $^ -lm -lgcc

sieve_cm.elf:           $(addprefix $(TMP)/,sieve2.ld crt0.thumb.o sieve.thumb2.o led.thumb2.o)
	$(CCGRP)gcc $(CPUM) $(LOPT)  -o $@ -T $^ -lm -lgcc

sieve_cm_flash.elf:     $(addprefix $(TMP)/,sieve3.ld crt0.flash.o sieve.thumb2.o led.thumb2.o lib.thumb2.o)
	$(CCGRP)gcc $(CPUM) $(LOPT)  -o $@ -T $^ -lm -lgcc

cppdemo.elf:            cppdemo.ld $(addprefix $(TMP)/,crt0.thumb.o syscalls.thumb.o cppdemo.thumb.o)
	$(CCGRP)g++ $(CPU)  $(LOPT)  -o $@ -T $^ -lm -lstdc++ -lc -lgcc

clean:
	-rm -fvr $(TMP)
	-rm -fv *.elf
