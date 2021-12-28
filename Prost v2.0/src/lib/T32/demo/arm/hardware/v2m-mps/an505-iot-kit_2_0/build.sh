#!/bin/bash

make FLASHSTART=0x0 RAMSTART=0x20000000 DEFINE=NONSECURE_BASE=0x00200000 HARDFP=1 -f ${T32SYS}/demo/arm/compiler/gnu-make/cortex-m/makefile secure_flash_thumb_ii_v8m_main_secure.elf
make FLASHSTART=0x00200000 RAMSTART=0x20004000 SRC=secure_flash_thumb_ii_v8m_main_secure.lib HARDFP=1 -f ${T32SYS}/demo/arm/compiler/gnu-make/cortex-m/makefile sieve_flash_thumb_ii_v8m_main.elf
