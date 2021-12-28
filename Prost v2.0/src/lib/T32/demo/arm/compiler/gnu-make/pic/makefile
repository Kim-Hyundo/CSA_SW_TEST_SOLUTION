export SHELLOPTS := igncr

RAMSTART   ?= 0x0
WATCHDOG   ?= 0
DEFINE     ?= 
SRC        ?= 
LIB        ?= 

CFLAGS     ?= 
CPPFLAGS   ?=
LDFLAGS    ?=
INCLUDEDIR ?=
HARDFP     ?= 0

MKFILEPATH      := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
WORKPATH        := $(dir $(abspath $(CURDIR))/)
TMP             := $(WORKPATH)tmp
MISCSRC         := 
COMMA           := ,

IFLAGS          := -I$(CURDIR) -I$(MKFILEPATH)/src $(addprefix -I,$(INCLUDEDIR))
HEADERS         := $(wildcard $(CURDIR)/*.h $(MKFILEPATH)/src/*.h $(addsuffix /*.h,$(INCLUDEDIR)))
ifeq ($(WATCHDOG),0)
DFLAGS          := -DRAMSTART=$(RAMSTART) $(addprefix -D,$(DEFINE))
else
DFLAGS          := -DRAMSTART=$(RAMSTART) $(addprefix -D,$(DEFINE)) -DWATCHDOG
MISCSRC         += watchdog.c
endif
DEFSYMFLAGS     := $(addprefix -Wl$(COMMA)--defsym=,$(filter STACKSIZE=% RAMSIZE=%,$(DEFINE)))
LIBS            := -Wl,-lgcc $(addprefix -Wl$(COMMA),$(LIB))

AOPT            := -g -Wall -Wa,--gdwarf2 -xassembler-with-cpp -c $(DFLAGS)
COPT            := -g -Wall -fshort-enums -c $(IFLAGS) $(DFLAGS) $(CFLAGS)
CPPOPT          := -g -Wall -fshort-enums -fno-unwind-tables -fno-exceptions -fno-rtti -c $(IFLAGS) $(DFLAGS) $(CPPFLAGS)
LOPT            := -g -Wall -Wl,--nmagic -nostartfiles -nodefaultlibs -Wl,--pic-veneer $(CFLAGS) $(addprefix -Wl$(COMMA),$(LDFLAGS))

CPU_ARM         := -march=armv4t -marm -mlittle-endian -msoft-float -fPIC
AOPT_ARM        := $(CPU_ARM)       $(AOPT)
COPT_ARM        := $(CPU_ARM)       $(COPT)
CPPOPT_ARM      := $(CPU_ARM)       $(CPPOPT)
LOPT_ARM        := $(CPU_ARM)       $(LOPT)

CPU_ARMBE       := -march=armv4t -marm -mbig-endian -msoft-float -fPIC
AOPT_ARMBE      := $(CPU_ARMBE)     $(AOPT)
COPT_ARMBE      := $(CPU_ARMBE)     $(COPT)
CPPOPT_ARMBE    := $(CPU_ARMBE)     $(CPPOPT)
LOPT_ARMBE      := $(CPU_ARMBE)     $(LOPT)

CPU_ARMV7       := -march=armv7-a -marm -mlittle-endian -msoft-float -fPIC -mno-unaligned-access
AOPT_ARMV7      := $(CPU_ARMV7)     $(AOPT)
COPT_ARMV7      := $(CPU_ARMV7)     $(COPT)
CPPOPT_ARMV7    := $(CPU_ARMV7)     $(CPPOPT)
LOPT_ARMV7      := $(CPU_ARMV7)     $(LOPT)

CPU_THUMBV4     := -march=armv4t -mthumb -mlittle-endian -msoft-float -fPIC
AOPT_THUMBV4    := $(CPU_THUMBV4)   $(AOPT)  -Wa,-mthumb
COPT_THUMBV4    := $(CPU_THUMBV4)   $(COPT)
CPPOPT_THUMBV4  := $(CPU_THUMBV4)   $(CPPOPT)
LOPT_THUMBV4    := $(CPU_THUMBV4)   $(LOPT)  -Wl,--thumb-entry=_start

CPU_THUMBV6M    := -march=armv6s-m -mthumb -mlittle-endian -msoft-float -fPIC
AOPT_THUMBV6M   := $(CPU_THUMBV6M)  $(AOPT)  -Wa,-mthumb 
COPT_THUMBV6M   := $(CPU_THUMBV6M)  $(COPT)
CPPOPT_THUMBV6M := $(CPU_THUMBV6M)  $(CPPOPT)
LOPT_THUMBV6M   := $(CPU_THUMBV6M)  $(LOPT)  -Wl,--thumb-entry=_start

ifneq ($(HARDFP),0)
CPU_THUMB2V7M   := -march=armv7-m -mthumb -mfix-cortex-m3-ldrd -mlittle-endian -mfloat-abi=hard -mfpu=fpv4-sp-d16 -fPIC
else
CPU_THUMB2V7M   := -march=armv7-m -mthumb -mfix-cortex-m3-ldrd -mlittle-endian -msoft-float -fPIC
endif
AOPT_THUMB2V7M  := $(CPU_THUMB2V7M) $(AOPT)  -Wa,-mthumb 
COPT_THUMB2V7M  := $(CPU_THUMB2V7M) $(COPT)
CPPOPT_THUMB2V7M:= $(CPU_THUMB2V7M) $(CPPOPT)
LOPT_THUMB2V7M  := $(CPU_THUMB2V7M) $(LOPT)  -Wl,--thumb-entry=_start

CCGRP           := arm-none-eabi-

TARGET          ?= sieve.c 
SRCS            := crt0-pic.s $(SRC) $(MISCSRC)
TARGETS          = $(TARGET:%.c=%_pic_arm.elf)          $(TARGET:%.c=%_pie_arm.elf) \
                   $(TARGET:%.c=%_pic_armbe.elf)        $(TARGET:%.c=%_pie_armbe.elf) \
                   $(TARGET:%.c=%_pic_armv7a.elf)       $(TARGET:%.c=%_pie_armv7a.elf) \
                   $(TARGET:%.c=%_pic_thumb_v4.elf)     $(TARGET:%.c=%_pie_thumb_v4.elf) \
                   $(TARGET:%.c=%_pic_thumb_v6m.elf)    $(TARGET:%.c=%_pie_thumb_v6m.elf) \
                   $(TARGET:%.c=%_pic_thumb_ii_v7m.elf) $(TARGET:%.c=%_pie_thumb_ii_v7m.elf)

-include ./special-pic-defines.mk

all: $(TARGETS)

$(TMP):
	mkdir $(TMP)

./%.c : $(MKFILEPATH)src/%.c
	cp $< ./$@ 

./%.s : $(MKFILEPATH)src/%.s
	cp $< ./$@ 

$(TMP)/headers: $(HEADERS)
	touch $(TMP)/headers

$(TMP)/%.arm.o:         ./%.c   $(MAKEFILE_LIST) | $(TMP)
	$(CCGRP)gcc $(COPT_ARM)         -o $@ $<

$(TMP)/%.armbe.o:       ./%.c   $(MAKEFILE_LIST) | $(TMP)
	$(CCGRP)gcc $(COPT_ARMBE)       -o $@ $<

$(TMP)/%.armv7.o:       ./%.c   $(MAKEFILE_LIST) | $(TMP)
	$(CCGRP)gcc $(COPT_ARMV7)       -o $@ $<

$(TMP)/%.thumbv4.o:     ./%.c   $(MAKEFILE_LIST) | $(TMP)
	$(CCGRP)gcc $(COPT_THUMBV4)     -o $@ $<
	
$(TMP)/%.thumbv6m.o:    ./%.c   $(MAKEFILE_LIST) | $(TMP)
	$(CCGRP)gcc $(COPT_THUMBV6M)    -o $@ $<

$(TMP)/%.thumbIIv7m.o:  ./%.c   $(MAKEFILE_LIST) | $(TMP)
	$(CCGRP)gcc $(COPT_THUMB2V7M)   -o $@ $<

$(TMP)/%.arm.o:         ./%.cpp $(MAKEFILE_LIST) | $(TMP)
	$(CCGRP)g++ $(CPPOPT_ARM)       -o $@ $<

$(TMP)/%.armbe.o:       ./%.cpp $(MAKEFILE_LIST) | $(TMP)
	$(CCGRP)g++ $(CPPOPT_ARMBE)     -o $@ $<

$(TMP)/%.armv7.o:       ./%.cpp $(MAKEFILE_LIST) | $(TMP)
	$(CCGRP)g++ $(CPPOPT_ARMV7)     -o $@ $<

$(TMP)/%.thumbv4.o:     ./%.cpp $(MAKEFILE_LIST) | $(TMP)
	$(CCGRP)g++ $(CPPOPT_THUMBV4)   -o $@ $<
	
$(TMP)/%.thumbv6m.o:    ./%.cpp $(MAKEFILE_LIST) | $(TMP)
	$(CCGRP)g++ $(CPPOPT_THUMBV6M)  -o $@ $<

$(TMP)/%.thumbIIv7m.o:  ./%.cpp $(MAKEFILE_LIST) | $(TMP)
	$(CCGRP)g++ $(CPPOPT_THUMB2V7M) -o $@ $<

$(TMP)/%.arm.o:         ./%.s   $(MAKEFILE_LIST) | $(TMP)
	$(CCGRP)gcc $(AOPT_ARM)         -o $@ $<

$(TMP)/%.armbe.o:       ./%.s   $(MAKEFILE_LIST) | $(TMP)
	$(CCGRP)gcc $(AOPT_ARMBE)       -o $@ $<

$(TMP)/%.armv7.o:       ./%.s   $(MAKEFILE_LIST) | $(TMP)
	$(CCGRP)gcc $(AOPT_ARMV7)       -o $@ $<

$(TMP)/%.thumbv4.o:     ./%.s   $(MAKEFILE_LIST) | $(TMP)
	$(CCGRP)gcc $(AOPT_THUMBV4)     -o $@ $<
	
$(TMP)/%.thumbv6m.o:    ./%.s   $(MAKEFILE_LIST) | $(TMP)
	$(CCGRP)gcc $(AOPT_THUMBV6M)    -o $@ $<

$(TMP)/%.thumbIIv7m.o:  ./%.s   $(MAKEFILE_LIST) | $(TMP)
	$(CCGRP)gcc $(AOPT_THUMB2V7M)   -o $@ $<

%_pic_arm.elf:          $(addprefix ./,%.c $(SRCS)) $(MKFILEPATH)src/pic.ld $(addprefix $(TMP)/,$(filter %.o, $(SRCS:%.s=%.arm.o)        %.arm.o        $(SRCS:%.c=%.arm.o)        $(SRCS:%.cpp=%.arm.o)        sections.arm.o       )) $(TMP)/headers
	$(CCGRP)gcc $(LOPT_ARM)      -Wl,--section-start=.text=$(RAMSTART) $(DEFSYMFLAGS)          -o $@ -T $(filter %.ld,$(^)) $(filter %.o,$(^)) -Wl,--start-group $(LIBS) -Wl,--end-group

%_pie_arm.elf:          $(addprefix ./,%.c $(SRCS)) $(MKFILEPATH)src/pic.ld $(addprefix $(TMP)/,$(filter %.o, $(SRCS:%.s=%.arm.o)        %.arm.o        $(SRCS:%.c=%.arm.o)        $(SRCS:%.cpp=%.arm.o)        sections.arm.o       )) $(TMP)/headers
	$(CCGRP)gcc $(LOPT_ARM)      -Wl,--section-start=.text=$(RAMSTART) $(DEFSYMFLAGS) -Wl,-pie -o $@ -T $(filter %.ld,$(^)) $(filter %.o,$(^)) -Wl,--start-group $(LIBS) -Wl,--end-group

%_pic_armbe.elf:        $(addprefix ./,%.c $(SRCS)) $(MKFILEPATH)src/pic.ld $(addprefix $(TMP)/,$(filter %.o, $(SRCS:%.s=%.armbe.o)      %.armbe.o      $(SRCS:%.c=%.armbe.o)      $(SRCS:%.cpp=%.armbe.o)      sections.armbe.o     )) $(TMP)/headers
	$(CCGRP)gcc $(LOPT_ARMBE)    -Wl,--section-start=.text=$(RAMSTART) $(DEFSYMFLAGS)          -o $@ -T $(filter %.ld,$(^)) $(filter %.o,$(^)) -Wl,--start-group $(LIBS) -Wl,--end-group

%_pie_armbe.elf:        $(addprefix ./,%.c $(SRCS)) $(MKFILEPATH)src/pic.ld $(addprefix $(TMP)/,$(filter %.o, $(SRCS:%.s=%.armbe.o)      %.armbe.o      $(SRCS:%.c=%.armbe.o)      $(SRCS:%.cpp=%.armbe.o)      sections.armbe.o     )) $(TMP)/headers
	$(CCGRP)gcc $(LOPT_ARMBE)    -Wl,--section-start=.text=$(RAMSTART) $(DEFSYMFLAGS) -Wl,-pie -o $@ -T $(filter %.ld,$(^)) $(filter %.o,$(^)) -Wl,--start-group $(LIBS) -Wl,--end-group

%_pic_armv7a.elf:       $(addprefix ./,%.c $(SRCS)) $(MKFILEPATH)src/pic.ld $(addprefix $(TMP)/,$(filter %.o, $(SRCS:%.s=%.armv7.o)      %.armv7.o      $(SRCS:%.c=%.armv7.o)      $(SRCS:%.cpp=%.armv7.o)      sections.armv7.o     )) $(TMP)/headers
	$(CCGRP)gcc $(LOPT_ARMV7)    -Wl,--section-start=.text=$(RAMSTART) $(DEFSYMFLAGS)          -o $@ -T $(filter %.ld,$(^)) $(filter %.o,$(^)) -Wl,--start-group $(LIBS) -Wl,--end-group

%_pie_armv7a.elf:       $(addprefix ./,%.c $(SRCS)) $(MKFILEPATH)src/pic.ld $(addprefix $(TMP)/,$(filter %.o, $(SRCS:%.s=%.armv7.o)      %.armv7.o      $(SRCS:%.c=%.armv7.o)      $(SRCS:%.cpp=%.armv7.o)      sections.armv7.o     )) $(TMP)/headers
	$(CCGRP)gcc $(LOPT_ARMV7)    -Wl,--section-start=.text=$(RAMSTART) $(DEFSYMFLAGS) -Wl,-pie -o $@ -T $(filter %.ld,$(^)) $(filter %.o,$(^)) -Wl,--start-group $(LIBS) -Wl,--end-group

%_pic_thumb_v4.elf:     $(addprefix ./,%.c $(SRCS)) $(MKFILEPATH)src/pic.ld $(addprefix $(TMP)/,$(filter %.o, $(SRCS:%.s=%.thumbv4.o)    %.thumbv4.o    $(SRCS:%.c=%.thumbv4.o)    $(SRCS:%.cpp=%.thumbv4.o)    sections.thumbv4.o   )) $(TMP)/headers
	$(CCGRP)gcc $(LOPT_THUMBV4)  -Wl,--section-start=.text=$(RAMSTART) $(DEFSYMFLAGS)          -o $@ -T $(filter %.ld,$(^)) $(filter %.o,$(^)) -Wl,--start-group $(LIBS) -Wl,--end-group

%_pie_thumb_v4.elf:     $(addprefix ./,%.c $(SRCS)) $(MKFILEPATH)src/pic.ld $(addprefix $(TMP)/,$(filter %.o, $(SRCS:%.s=%.thumbv4.o)    %.thumbv4.o    $(SRCS:%.c=%.thumbv4.o)    $(SRCS:%.cpp=%.thumbv4.o)    sections.thumbv4.o   )) $(TMP)/headers
	$(CCGRP)gcc $(LOPT_THUMBV4)  -Wl,--section-start=.text=$(RAMSTART) $(DEFSYMFLAGS) -Wl,-pie -o $@ -T $(filter %.ld,$(^)) $(filter %.o,$(^)) -Wl,--start-group $(LIBS) -Wl,--end-group
	
%_pic_thumb_v6m.elf:    $(addprefix ./,%.c $(SRCS)) $(MKFILEPATH)src/pic.ld $(addprefix $(TMP)/,$(filter %.o, $(SRCS:%.s=%.thumbv6m.o)   %.thumbv6m.o   $(SRCS:%.c=%.thumbv6m.o)   $(SRCS:%.cpp=%.thumbv6m.o)   sections.thumbv6m.o  )) $(TMP)/headers
	$(CCGRP)gcc $(LOPT_THUMBV6M) -Wl,--section-start=.text=$(RAMSTART) $(DEFSYMFLAGS)          -o $@ -T $(filter %.ld,$(^)) $(filter %.o,$(^)) -Wl,--start-group $(LIBS) -Wl,--end-group

%_pie_thumb_v6m.elf:    $(addprefix ./,%.c $(SRCS)) $(MKFILEPATH)src/pic.ld $(addprefix $(TMP)/,$(filter %.o, $(SRCS:%.s=%.thumbv6m.o)   %.thumbv6m.o   $(SRCS:%.c=%.thumbv6m.o)   $(SRCS:%.cpp=%.thumbv6m.o)   sections.thumbv6m.o  )) $(TMP)/headers
	$(CCGRP)gcc $(LOPT_THUMBV6M) -Wl,--section-start=.text=$(RAMSTART) $(DEFSYMFLAGS) -Wl,-pie -o $@ -T $(filter %.ld,$(^)) $(filter %.o,$(^)) -Wl,--start-group $(LIBS) -Wl,--end-group

%_pic_thumb_ii_v7m.elf: $(addprefix ./,%.c $(SRCS)) $(MKFILEPATH)src/pic.ld $(addprefix $(TMP)/,$(filter %.o, $(SRCS:%.s=%.thumbIIv7m.o) %.thumbIIv7m.o $(SRCS:%.c=%.thumbIIv7m.o) $(SRCS:%.cpp=%.thumbIIv7m.o) sections.thumbIIv7m.o)) $(TMP)/headers
	$(CCGRP)gcc $(LOPT_THUMB2V7M) -Wl,--section-start=.text=$(RAMSTART) $(DEFSYMFLAGS)          -o $@ -T $(filter %.ld,$(^)) $(filter %.o,$(^)) -Wl,--start-group $(LIBS) -Wl,--end-group

%_pie_thumb_ii_v7m.elf: $(addprefix ./,%.c $(SRCS)) $(MKFILEPATH)src/pic.ld $(addprefix $(TMP)/,$(filter %.o, $(SRCS:%.s=%.thumbIIv7m.o) %.thumbIIv7m.o $(SRCS:%.c=%.thumbIIv7m.o) $(SRCS:%.cpp=%.thumbIIv7m.o) sections.thumbIIv7m.o)) $(TMP)/headers
	$(CCGRP)gcc $(LOPT_THUMB2V7M) -Wl,--section-start=.text=$(RAMSTART) $(DEFSYMFLAGS) -Wl,-pie -o $@ -T $(filter %.ld,$(^)) $(filter %.o,$(^)) -Wl,--start-group $(LIBS) -Wl,--end-group

clean:
	-rm -fvr $(TMP)
	-rm -fv ./*_pic_arm.elf
	-rm -fv ./*_pic_armbe.elf
	-rm -fv ./*_pic_armv7a.elf
	-rm -fv ./*_pic_thumb_v4.elf
	-rm -fv ./*_pic_thumb_v6m.elf
	-rm -fv ./*_pic_thumb_ii_v7m.elf
	-rm -fv ./*_pie_arm.elf
	-rm -fv ./*_pie_armbe.elf
	-rm -fv ./*_pie_armv7a.elf
	-rm -fv ./*_pie_thumb_v4.elf
	-rm -fv ./*_pie_thumb_v6m.elf
	-rm -fv ./*_pie_thumb_ii_v7m.elf

-include ./special-pic-rules.mk
