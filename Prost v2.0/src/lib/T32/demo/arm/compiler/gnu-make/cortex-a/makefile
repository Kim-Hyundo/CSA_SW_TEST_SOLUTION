export SHELLOPTS := igncr

FLASHSTART ?= 0x00000000
RAMSTART   ?= 0x20000000
RAMSIZE    ?= 
WATCHDOG   ?= 0
DEFINE     ?= 
SRC        ?= 
LIB        ?= 
HARDFP     ?= 0

CFLAGS     ?=
LDFLAGS    ?=
INCLUDEDIR ?=

MKFILEPATH      := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
WORKPATH        := $(dir $(abspath $(CURDIR))/)
TMP             := $(WORKPATH)tmp
MISCSRC         :=
COMMA           := ,

IFLAGS          := -I$(CURDIR) -I$(MKFILEPATH)/src $(addprefix -I,$(INCLUDEDIR))
HEADERS         := $(wildcard $(CURDIR)/*.h $(MKFILEPATH)/src/*.h $(addsuffix /*.h,$(INCLUDEDIR)))
ifeq ($(WATCHDOG),0)
DFLAGS          := $(addprefix -D,$(DEFINE)) $(if $(RAMSIZE),-DRAMSTART=$(RAMSTART) -DRAMSIZE=$(RAMSIZE))
else
DFLAGS          := $(addprefix -D,$(DEFINE)) $(if $(RAMSIZE),-DRAMSTART=$(RAMSTART) -DRAMSIZE=$(RAMSIZE)) -DWATCHDOG
MISCSRC         += watchdog.c
endif

LIBS            := -Wl,-lgcc $(addprefix -Wl$(COMMA),$(LIB))

ifeq ($(strip $(HARDFP)),0)
CPU_FPU         := -mfloat-abi=soft
else ifeq ($(strip $(HARDFP)),1)
CPU_FPU         := -mfloat-abi=hard -mfpu=vfpv3-d16-fp16
else ifneq (,$(findstring VFPv3,$(HARDFP)))
CPU_FPU         := -mfloat-abi=hard -mfpu=vfpv3-d16-fp16
else ifneq (,$(findstring VFPv4,$(HARDFP)))
CPU_FPU         := -mfloat-abi=hard -mfpu=vfpv4-d16
else
$(error Unsupported HARDFP option! Valid options are empty,1,VFPv3,VFPv4.)
endif

CPU_ARM         := -march=armv7-a -marm -mlittle-endian $(CPU_FPU) -mno-unaligned-access
AOPT_ARM        := -g -Wall $(CPU_ARM) -Wa,--gdwarf2 -xassembler-with-cpp -c $(DFLAGS)
COPT_ARM        := -g -Wall $(CPU_ARM) -fshort-enums -c $(IFLAGS) $(DFLAGS) $(CFLAGS)
LOPT_ARM        := -g -Wall $(CPU_ARM) -Wl,--nmagic -nostartfiles -nodefaultlibs -Wl,--entry=_start $(addprefix -Wl$(COMMA),$(LDFLAGS))

CPU_THUMB2V7    := -march=armv7-a -mthumb -mlittle-endian $(CPU_FPU) -mno-unaligned-access
AOPT_THUMB2V7   := -g -Wall $(CPU_THUMB2V7) -Wa,--gdwarf2 -Wa,-mthumb -xassembler-with-cpp -c $(DFLAGS)
COPT_THUMB2V7   := -g -Wall $(CPU_THUMB2V7) -fshort-enums -c $(IFLAGS) $(DFLAGS) $(CFLAGS)
LOPT_THUMB2V7   := -g -Wall $(CPU_THUMB2V7) -Wl,--nmagic -nostartfiles -nodefaultlibs -Wl,--thumb-entry=_start $(addprefix -Wl$(COMMA),$(LDFLAGS))

CCGRP           := arm-none-eabi-

TARGET          ?= sieve.c 
SRCS            := crt0.s $(SRC) $(MISCSRC)
TARGETS          = $(TARGET:%.c=%_ram_arm_v7.elf) \
                   $(TARGET:%.c=%_flash_arm_v7.elf) \
                   $(TARGET:%.c=%_ram_thumb_ii_v7.elf) \
                   $(TARGET:%.c=%_flash_thumb_ii_v7.elf)

-include ./special-cortex-a-defines.mk

all: $(TARGETS)
	
	
target-a% : $(filter %_arm_v7.elf, $(TARGETS))
	

$(TMP):
	mkdir $(TMP)

./%.c : $(MKFILEPATH)src/%.c
	cp $< ./$@ 

./%.s : $(MKFILEPATH)src/%.s
	cp $< ./$@ 

$(TMP)/headers: $(HEADERS)
	touch $(TMP)/headers

$(TMP)/%.armv7.o:        ./%.c   $(MAKEFILE_LIST)
	$(CCGRP)gcc $(COPT_ARM) -o $@ $<

$(TMP)/%.thumbIIv7m.o:   ./%.c   $(MAKEFILE_LIST)
	$(CCGRP)gcc $(COPT_THUMB2V7) -o $@ $<

$(TMP)/%.armv7.o:        ./%.s   $(MAKEFILE_LIST)
	$(CCGRP)gcc $(AOPT_ARM) -o $@ $<

$(TMP)/%.thumbIIv7m.o:   ./%.s   $(MAKEFILE_LIST)
	$(CCGRP)gcc $(AOPT_THUMB2V7) -o $@ $<

.INTERMEDIATE :          $(TMP)/ram.ld 
$(TMP)/ram.ld:           $(MKFILEPATH)src/linker.ldx $(MAKEFILE_LIST) | $(TMP)
	$(CCGRP)cpp -P -DRAMSTART=$(RAMSTART) $(DFLAGS) -o $@ $< 

.INTERMEDIATE :          $(TMP)/flash.ld
$(TMP)/flash.ld:         $(MKFILEPATH)src/linker.ldx $(MAKEFILE_LIST) | $(TMP)
	$(CCGRP)cpp -P -DFLASHSTART=$(FLASHSTART) -DRAMSTART=$(RAMSTART) $(DFLAGS) -o $@ $<

%_ram_arm_v7.elf:        ./%.c $(addprefix ./,$(SRCS)) $(addprefix $(TMP)/,ram.ld   $(filter %.o, $(SRCS:%.s=%.armv7.o))      %.armv7.o      $(filter %.o, $(SRCS:%.c=%.armv7.o))     ) $(TMP)/headers
	$(CCGRP)gcc $(LOPT_ARM)      -o $@ -T $(filter %.ld,$(^)) $(filter %.o,$(^)) -Wl,--start-group $(LIBS) -Wl,--end-group

%_flash_arm_v7.elf:      ./%.c $(addprefix ./,$(SRCS)) $(addprefix $(TMP)/,flash.ld $(filter %.o, $(SRCS:%.s=%.armv7.o))      %.armv7.o      $(filter %.o, $(SRCS:%.c=%.armv7.o))     ) $(TMP)/headers
	$(CCGRP)gcc $(LOPT_ARM)      -o $@ -T $(filter %.ld,$(^)) $(filter %.o,$(^)) -Wl,--start-group $(LIBS) -Wl,--end-group

%_ram_thumb_ii_v7.elf:   ./%.c $(addprefix ./,$(SRCS)) $(addprefix $(TMP)/,ram.ld   $(filter %.o, $(SRCS:%.s=%.thumbIIv7m.o)) %.thumbIIv7m.o $(filter %.o, $(SRCS:%.c=%.thumbIIv7m.o))) $(TMP)/headers
	$(CCGRP)gcc $(LOPT_THUMB2V7) -o $@ -T $(filter %.ld,$(^)) $(filter %.o,$(^)) -Wl,--start-group $(LIBS) -Wl,--end-group

%_flash_thumb_ii_v7.elf: ./%.c $(addprefix ./,$(SRCS)) $(addprefix $(TMP)/,flash.ld $(filter %.o, $(SRCS:%.s=%.thumbIIv7m.o)) %.thumbIIv7m.o $(filter %.o, $(SRCS:%.c=%.thumbIIv7m.o))) $(TMP)/headers
	$(CCGRP)gcc $(LOPT_THUMB2V7) -o $@ -T $(filter %.ld,$(^)) $(filter %.o,$(^)) -Wl,--start-group $(LIBS) -Wl,--end-group

clean:
	-rm -fvr $(TMP)
	-rm -fv ./*_ram_arm_v7.elf
	-rm -fv ./*_flash_arm_v7.elf
	-rm -fv ./*_ram_thumb_ii_v7.elf
	-rm -fv ./*_flash_thumb_ii_v7.elf

-include ./special-cortex-a-rules.mk
