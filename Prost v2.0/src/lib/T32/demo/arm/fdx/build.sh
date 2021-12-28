#!/bin/bash
make clean
# ARM7, ARM9 builds
make DEFINE="T32_FDX_DCC T32_FDX_TRACE_COMPRESSED T32_FDX_TRACE_BUFSIZE=256 ARM7" fdxtarget_pic_arm.elf fdxtrace_pic_arm.elf
mv fdxtarget_pic_arm.elf fdxtarget_pic_arm7_arm9.elf 
mv fdxtrace_pic_arm.elf fdxtrace_pic_arm7_arm9.elf

# ARM11, Cortex-A, Cortex-R builds
make DEFINE="T32_FDX_DCC T32_FDX_TRACE_COMPRESSED T32_FDX_TRACE_BUFSIZE=256 ARM11" fdxtarget_pic_arm.elf fdxtrace_pic_arm.elf
mv fdxtarget_pic_arm.elf fdxtarget_pic_arm11_cortex.elf 
mv fdxtrace_pic_arm.elf fdxtrace_pic_arm11_cortex.elf

# Cortex-R big-endian builds
make DEFINE="T32_FDX_DCC T32_FDX_TRACE_COMPRESSED T32_FDX_TRACE_BUFSIZE=256 ARM11" fdxtarget_pic_armbe.elf fdxtrace_pic_armbe.elf
mv fdxtarget_pic_armbe.elf fdxtarget_pic_arm11_cortex_be.elf 
mv fdxtrace_pic_armbe.elf fdxtrace_pic_arm11_cortex_be.elf

# XSCALE builds
make DEFINE="T32_FDX_DCC T32_FDX_TRACE_COMPRESSED T32_FDX_TRACE_BUFSIZE=256 XSCALE" fdxtarget_pic_arm.elf fdxtrace_pic_arm.elf
mv fdxtarget_pic_arm.elf fdxtarget_pic_xscale.elf 
mv fdxtrace_pic_arm.elf fdxtrace_pic_xscale.elf

# Cortex-M0,M0+,M1 builds
make DEFINE="T32_FDX_TRACE_COMPRESSED T32_FDX_TRACE_BUFSIZE=256" fdxtarget_pic_thumb_v6m.elf fdxtrace_pic_thumb_v6m.elf

# Cortex-M3,M4,M7 builds
make DEFINE="T32_FDX_TRACE_COMPRESSED T32_FDX_TRACE_BUFSIZE=256" fdxtarget_pic_thumb_ii_v7m.elf fdxtrace_pic_thumb_ii_v7m.elf
