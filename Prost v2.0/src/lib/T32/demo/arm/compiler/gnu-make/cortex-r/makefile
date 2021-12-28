export SHELLOPTS := igncr

FLASHSTART ?= 0x00000000
RAMSTART   ?= 0x20000000
RAMSIZE    ?=
WATCHDOG   ?= 0
DEFINE     ?= 
SRC        ?= 
LIB        ?= 

CFLAGS     ?=
CPPFLAGS   ?=
LDFLAGS    ?=
INCLUDEDIR ?=
HARDFP     ?= 0


MKFILEPATH         := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
WORKPATH           := $(dir $(abspath $(CURDIR))/)
TMP                := $(WORKPATH)tmp
MISCSRC            :=
COMMA              := ,

IFLAGS             := -I$(CURDIR) -I$(MKFILEPATH)/src $(addprefix -I,$(INCLUDEDIR))
HEADERS            := $(wildcard $(CURDIR)/*.h $(MKFILEPATH)/src/*.h $(addsuffix /*.h,$(INCLUDEDIR)))
ifeq ($(WATCHDOG),0)
DFLAGS             := $(addprefix -D,$(DEFINE)) $(if $(RAMSIZE),-DRAMSTART=$(RAMSTART) -DRAMSIZE=$(RAMSIZE))
else
DFLAGS             := $(addprefix -D,$(DEFINE)) $(if $(RAMSIZE),-DRAMSTART=$(RAMSTART) -DRAMSIZE=$(RAMSIZE)) -DWATCHDOG
MISCSRC            += watchdog.c
endif

LIBS               := -Wl,-lgcc $(addprefix -Wl$(COMMA),$(LIB))

ifeq ($(HARDFP),0)
CPU_ARM_LE         := -march=armv7-r -marm -mlittle-endian -msoft-float
else
CPU_ARM_LE         := -march=armv7-r -marm -mlittle-endian -mfloat-abi=hard -mfpu=vfpv3-d16-fp16
endif
AOPT_ARM_LE        := -g -Wall $(CPU_ARM_LE) -Wa,--gdwarf2 -xassembler-with-cpp -c $(DFLAGS)
COPT_ARM_LE        := -g -Wall $(CPU_ARM_LE) -fshort-enums -c $(IFLAGS)  $(DFLAGS) $(CFLAGS)
CPPOPT_ARM_LE      := -g -Wall $(CPU_ARM_LE) -fshort-enums -fno-unwind-tables -fno-exceptions -fno-rtti  -c $(IFLAGS)  $(DFLAGS) $(CFLAGS)
LOPT_ARM_LE        := -g -Wall $(CPU_ARM_LE) -Wl,--nmagic -nostartfiles -nodefaultlibs -Wl,--entry=_start $(addprefix -Wl$(COMMA),$(LDFLAGS))

ifeq ($(HARDFP),0)
CPU_ARM_BE         := -march=armv7-r -marm -mbig-endian    -msoft-float
else
CPU_ARM_BE         := -march=armv7-r -marm -mbig-endian    -mfloat-abi=hard -mfpu=vfpv3-d16-fp16
endif
AOPT_ARM_BE        := -g -Wall $(CPU_ARM_BE) -Wa,--gdwarf2 -xassembler-with-cpp -c $(DFLAGS)
COPT_ARM_BE        := -g -Wall $(CPU_ARM_BE) -fshort-enums -c $(IFLAGS)  $(DFLAGS) $(CFLAGS)
CPPOPT_ARM_BE      := -g -Wall $(CPU_ARM_BE) -fshort-enums -fno-unwind-tables -fno-exceptions -fno-rtti -c $(IFLAGS)  $(DFLAGS) $(CPPFLAGS)
LOPT_ARM_BE        := -g -Wall $(CPU_ARM_BE) -Wl,--nmagic -nostartfiles -nodefaultlibs -Wl,--entry=_start $(addprefix -Wl$(COMMA),$(LDFLAGS))

ifeq ($(HARDFP),0)
CPU_THUMB2V7_LE    := -march=armv7-r -mthumb -mlittle-endian -msoft-float
else
CPU_THUMB2V7_LE    := -march=armv7-r -mthumb -mlittle-endian -mfloat-abi=hard -mfpu=vfpv3-d16-fp16
endif
AOPT_THUMB2V7_LE   := -g -Wall $(CPU_THUMB2V7_LE) -Wa,--gdwarf2 -Wa,-mthumb -xassembler-with-cpp -c $(DFLAGS)
COPT_THUMB2V7_LE   := -g -Wall $(CPU_THUMB2V7_LE) -fshort-enums -c $(IFLAGS) $(DFLAGS) $(CFLAGS)
CPPOPT_THUMB2V7_LE := -g -Wall $(CPU_THUMB2V7_LE) -fshort-enums -fno-unwind-tables -fno-exceptions -fno-rtti -c $(IFLAGS) $(DFLAGS) $(CPPFLAGS)
LOPT_THUMB2V7_LE   := -g -Wall $(CPU_THUMB2V7_LE) -Wl,--nmagic -nostartfiles -nodefaultlibs -Wl,--thumb-entry=_start $(addprefix -Wl$(COMMA),$(LDFLAGS))

ifeq ($(HARDFP),0)
CPU_THUMB2V7_BE    := -march=armv7-r -mthumb -mbig-endian -msoft-float
else
CPU_THUMB2V7_BE    := -march=armv7-r -mthumb -mbig-endian -mfloat-abi=hard -mfpu=vfpv3-d16-fp16
endif
AOPT_THUMB2V7_BE   := -g -Wall $(CPU_THUMB2V7_BE) -Wa,--gdwarf2 -Wa,-mthumb -xassembler-with-cpp -c $(DFLAGS)
COPT_THUMB2V7_BE   := -g -Wall $(CPU_THUMB2V7_BE) -fshort-enums -c $(IFLAGS) $(DFLAGS) $(CFLAGS)
CPPOPT_THUMB2V7_BE := -g -Wall $(CPU_THUMB2V7_BE) -fshort-enums -fno-unwind-tables -fno-exceptions -fno-rtti -c $(IFLAGS) $(DFLAGS) $(CPPFLAGS)
LOPT_THUMB2V7_BE   := -g -Wall $(CPU_THUMB2V7_BE) -Wl,--nmagic -nostartfiles -nodefaultlibs -Wl,--thumb-entry=_start $(addprefix -Wl$(COMMA),$(LDFLAGS))

CCGRP              := arm-none-eabi-

TARGET             ?= sieve.c 
SRCS               := crt0.s $(SRC) $(MISCSRC)
TARGETS             = $(TARGET:%.c=%_ram_arm_v7r_le.elf)        $(TARGET:%.c=%_ram_arm_v7r_be.elf) \
                      $(TARGET:%.c=%_flash_arm_v7r_le.elf)      $(TARGET:%.c=%_flash_arm_v7r_be.elf) \
                      $(TARGET:%.c=%_ram_thumb_ii_v7r_le.elf)   $(TARGET:%.c=%_ram_thumb_ii_v7r_be.elf) \
                      $(TARGET:%.c=%_flash_thumb_ii_v7r_le.elf) $(TARGET:%.c=%_flash_thumb_ii_v7r_be.elf)

-include ./special-cortex-r-defines.mk

all: $(TARGETS)
	

target-r% target-le-r% : $(filter %_arm_v7r_le.elf, $(TARGETS))
	

target-be-r% : $(filter %_arm_v7r_be.elf, $(TARGETS))
	

$(TMP):
	mkdir $(TMP)

./%.c : $(MKFILEPATH)src/%.c
	cp $< ./$@ 

./%.s : $(MKFILEPATH)src/%.s
	cp $< ./$@ 

$(TMP)/headers: $(HEADERS)
	touch $(TMP)/headers

$(TMP)/%.armv7rle.o:        ./%.c   $(MAKEFILE_LIST)
	$(CCGRP)gcc $(COPT_ARM_LE)        -o $@ $<

$(TMP)/%.armv7rbe.o:        ./%.c   $(MAKEFILE_LIST)
	$(CCGRP)gcc $(COPT_ARM_BE)        -o $@ $<

$(TMP)/%.thumbIIv7rle.o:   ./%.c    $(MAKEFILE_LIST)
	$(CCGRP)gcc $(COPT_THUMB2V7_LE)   -o $@ $<

$(TMP)/%.thumbIIv7rbe.o:   ./%.c    $(MAKEFILE_LIST)
	$(CCGRP)gcc $(COPT_THUMB2V7_BE)   -o $@ $<

$(TMP)/%.armv7rle.o:        ./%.cpp $(MAKEFILE_LIST)
	$(CCGRP)g++ $(CPPOPT_ARM_LE)      -o $@ $<

$(TMP)/%.armv7rbe.o:        ./%.cpp $(MAKEFILE_LIST)
	$(CCGRP)g++ $(CPPOPT_ARM_BE)      -o $@ $<

$(TMP)/%.thumbIIv7rle.o:   ./%.cpp  $(MAKEFILE_LIST)
	$(CCGRP)g++ $(CPPOPT_THUMB2V7_LE) -o $@ $<

$(TMP)/%.thumbIIv7rbe.o:   ./%.cpp  $(MAKEFILE_LIST)
	$(CCGRP)g++ $(CPPOPT_THUMB2V7_BE) -o $@ $<

$(TMP)/%.armv7rle.o:        ./%.s   $(MAKEFILE_LIST)
	$(CCGRP)gcc $(AOPT_ARM_LE)        -o $@ $<

$(TMP)/%.armv7rbe.o:        ./%.s   $(MAKEFILE_LIST)
	$(CCGRP)gcc $(AOPT_ARM_BE)        -o $@ $<

$(TMP)/%.thumbIIv7rle.o:   ./%.s    $(MAKEFILE_LIST)
	$(CCGRP)gcc $(AOPT_THUMB2V7_LE)   -o $@ $<

$(TMP)/%.thumbIIv7rbe.o:   ./%.s    $(MAKEFILE_LIST)
	$(CCGRP)gcc $(AOPT_THUMB2V7_BE)   -o $@ $<

.INTERMEDIATE :          $(TMP)/ram.ld
$(TMP)/ram.ld:           $(MKFILEPATH)src/linker.ldx $(MAKEFILE_LIST) | $(TMP)
	$(CCGRP)cpp -P -DRAMSTART=$(RAMSTART) $(DFLAGS) -o $@ $< 

.INTERMEDIATE :          $(TMP)/flash.ld
$(TMP)/flash.ld:         $(MKFILEPATH)src/linker.ldx $(MAKEFILE_LIST) | $(TMP)
	$(CCGRP)cpp -P -DFLASHSTART=$(FLASHSTART) -DRAMSTART=$(RAMSTART) $(DFLAGS) -o $@ $<

%_ram_arm_v7r_le.elf:        ./%.c $(addprefix ./,$(SRCS)) $(addprefix $(TMP)/,ram.ld   $(filter %.o, $(SRCS:%.s=%.armv7rle.o))     %.armv7rle.o     $(filter %.o, $(SRCS:%.c=%.armv7rle.o))     $(filter %.o, $(SRCS:%.cpp=%.armv7rle.o))    ) $(TMP)/headers
	$(CCGRP)gcc $(LOPT_ARM_LE)      -o $@ -T $(filter %.ld,$(^)) $(filter %.o,$(^)) -Wl,--start-group $(LIBS) -Wl,--end-group

%_ram_arm_v7r_be.elf:        ./%.c $(addprefix ./,$(SRCS)) $(addprefix $(TMP)/,ram.ld   $(filter %.o, $(SRCS:%.s=%.armv7rbe.o))     %.armv7rbe.o     $(filter %.o, $(SRCS:%.c=%.armv7rbe.o))     $(filter %.o, $(SRCS:%.cpp=%.armv7rbe.o))    ) $(TMP)/headers
	$(CCGRP)gcc $(LOPT_ARM_BE)      -o $@ -T $(filter %.ld,$(^)) $(filter %.o,$(^)) -Wl,--start-group $(LIBS) -Wl,--end-group

%_flash_arm_v7r_le.elf:      ./%.c $(addprefix ./,$(SRCS)) $(addprefix $(TMP)/,flash.ld $(filter %.o, $(SRCS:%.s=%.armv7rle.o))     %.armv7rle.o     $(filter %.o, $(SRCS:%.c=%.armv7rle.o))     $(filter %.o, $(SRCS:%.cpp=%.armv7rle.o))    ) $(TMP)/headers
	$(CCGRP)gcc $(LOPT_ARM_LE)      -o $@ -T $(filter %.ld,$(^)) $(filter %.o,$(^)) -Wl,--start-group $(LIBS) -Wl,--end-group

%_flash_arm_v7r_be.elf:      ./%.c $(addprefix ./,$(SRCS)) $(addprefix $(TMP)/,flash.ld $(filter %.o, $(SRCS:%.s=%.armv7rbe.o))     %.armv7rbe.o     $(filter %.o, $(SRCS:%.c=%.armv7rbe.o))     $(filter %.o, $(SRCS:%.cpp=%.armv7rbe.o))    ) $(TMP)/headers
	$(CCGRP)gcc $(LOPT_ARM_BE)      -o $@ -T $(filter %.ld,$(^)) $(filter %.o,$(^)) -Wl,--start-group $(LIBS) -Wl,--end-group

%_ram_thumb_ii_v7r_le.elf:   ./%.c $(addprefix ./,$(SRCS)) $(addprefix $(TMP)/,ram.ld   $(filter %.o, $(SRCS:%.s=%.thumbIIv7rle.o)) %.thumbIIv7rle.o $(filter %.o, $(SRCS:%.c=%.thumbIIv7rle.o)) $(filter %.o, $(SRCS:%.cpp=%.thumbIIv7rle.o))) $(TMP)/headers
	$(CCGRP)gcc $(LOPT_THUMB2V7_LE) -o $@ -T $(filter %.ld,$(^)) $(filter %.o,$(^)) -Wl,--start-group $(LIBS) -Wl,--end-group

%_ram_thumb_ii_v7r_be.elf:   ./%.c $(addprefix ./,$(SRCS)) $(addprefix $(TMP)/,ram.ld   $(filter %.o, $(SRCS:%.s=%.thumbIIv7rbe.o)) %.thumbIIv7rbe.o $(filter %.o, $(SRCS:%.c=%.thumbIIv7rbe.o)) $(filter %.o, $(SRCS:%.cpp=%.thumbIIv7rbe.o))) $(TMP)/headers
	$(CCGRP)gcc $(LOPT_THUMB2V7_BE) -o $@ -T $(filter %.ld,$(^)) $(filter %.o,$(^)) -Wl,--start-group $(LIBS) -Wl,--end-group

%_flash_thumb_ii_v7r_le.elf: ./%.c $(addprefix ./,$(SRCS)) $(addprefix $(TMP)/,flash.ld $(filter %.o, $(SRCS:%.s=%.thumbIIv7rle.o)) %.thumbIIv7rle.o $(filter %.o, $(SRCS:%.c=%.thumbIIv7rle.o)) $(filter %.o, $(SRCS:%.cpp=%.thumbIIv7rle.o))) $(TMP)/headers
	$(CCGRP)gcc $(LOPT_THUMB2V7_LE) -o $@ -T $(filter %.ld,$(^)) $(filter %.o,$(^)) -Wl,--start-group $(LIBS) -Wl,--end-group

%_flash_thumb_ii_v7r_be.elf: ./%.c $(addprefix ./,$(SRCS)) $(addprefix $(TMP)/,flash.ld $(filter %.o, $(SRCS:%.s=%.thumbIIv7rbe.o)) %.thumbIIv7rbe.o $(filter %.o, $(SRCS:%.c=%.thumbIIv7rbe.o)) $(filter %.o, $(SRCS:%.cpp=%.thumbIIv7rbe.o))) $(TMP)/headers
	$(CCGRP)gcc $(LOPT_THUMB2V7_BE) -o $@ -T $(filter %.ld,$(^)) $(filter %.o,$(^)) -Wl,--start-group $(LIBS) -Wl,--end-group

clean:
	-rm -fvr $(TMP)
	-rm -fv ./*_ram_arm_v7r_le.elf
	-rm -fv ./*_ram_arm_v7r_be.elf
	-rm -fv ./*_flash_arm_v7r_le.elf
	-rm -fv ./*_flash_arm_v7r_be.elf
	-rm -fv ./*_ram_thumb_ii_v7r_le.elf
	-rm -fv ./*_ram_thumb_ii_v7r_be.elf
	-rm -fv ./*_flash_thumb_ii_v7r_le.elf
	-rm -fv ./*_flash_thumb_ii_v7r_be.elf

-include ./special-cortex-r-rules.mk
