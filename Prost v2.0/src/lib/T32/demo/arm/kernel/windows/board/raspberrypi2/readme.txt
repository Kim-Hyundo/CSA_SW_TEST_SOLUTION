; --------------------------------------------------------------------------------
; @Title: How to debug windows 10 on a Raspberry Pi 2 using TRACE32 
; @Description: Board adaptation, GPIO configuration for JTAG, debugger start-up
; @Keywords: ARM, awareness, enable, jtag, raspi2, win10, win
; @Author: HDA
; @Board: Raspberry Pi 2
; @Chip: BCM2836
; @Copyright: (C) 1989-2016 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: readme.txt 10165 2016-11-14 14:42:32Z hdammak $

The below was tested on a Raspberry Pi 2 Model B V1.1 board.

Overview:

The Raspberry Pi 2 Model B board has 4 Cortex-A7 cores plus a video core.
When power on your RASPI2, the video core executes first-stage bootloader from ROM
memory in order to mount the SD-card. The "bootcode.bin" and "start.elf" binaries, 
loaded from SD-card, are executed by the video core in order to prepare the RAM memory,
load the "kernel.img" and releases the reset on the ARM CPUs. Then, the Cortex-A7 cores
execute the "kernel.img".
Unfortunately, JTAG pins are not connected by default to the outside world.
The developer, needs to have a program that configures the alternate GPIO functions, 
so that the JTAG signals will show up on the J8 connector. During the debug session 
no reset might happen because this would cause the default configuration of the GPIOs
and would disconnect the JTAG.
The RASPI2 does not have a standard ARM20 JTAG-20 connector, so the user needs to build 
an adapter.

RASPI2 J8 to JTAG-20 pin adapter :

JTAG-20     signal  GPIO pin  ALT mode  RASPI2 J8 pin
1           VREF                        J8-1 (3.3v)
3           nTRST   GPIO22    ALT4      J8-15
5           TDI     GPIO04    ALT5      J8-7
7           TMS     GPIO27    ALT4      J8-13
9           TCK     GPIO25    ALT4      J8-22
13          TDO     GPIO24    ALT4      J8-18
4, 6,..,20  GND                         J8-6, 9, 14, 20, 25, 30, 34, 39

Configure the alternate GPIO functions:

#define GPFSEL0    ((volatile unsigned int *) 0x3F200000)
#define GPFSEL2    ((volatile unsigned int *) 0x3F200008)

// GPIO22,24,25,27 alt4 -> nTRST,TDO,TCK,TMS
*GPFSEL2 &= ~0x00e3f1c0;
*GPFSEL2 |=  0x0061b0c0;

// GPIO4 alt5 -> TDI
*GPFSEL0 &= ~0x00007000; 
*GPFSEL0 |=  0x00002000;

Starting windows 10 with JTAG enabled

First you have to prepare your SD card as usual. The steps are detailed in the 
following link:
https://ms-iot.github.io/content/en-US/win10/RPI.htm

After your SD-card is ready please copy "kernel.img" file from your SD-card to the local working directory and copy enclosed "jtagenable.bin" to your SD-card and rename it to "kernel.img" (replace the file on your SD-card).

Open config.txt file and check kernel_old value:
If kernel_old=0 or not defined then the kernel load address is 0x0x8000 (default)

If kernel_old=1 then the kernel load address is 0x0. You need to change this to
kernel_old=0 (jtag_enable.bin is supposed to be loaded at address 0x8000)
Additionally the script raspi2_start_windows10iot.cmm need to be executed as following:
DO raspi2_start_windows10iot.cmm kernel_old=1

Insert the SD-card into your RASPI2 and power on your board. The jtagenable program
will execute the above instructions in order to enable JTAG then it remains in
an infinite loop (no windows boot anymore)

Now run TRACE32 and execute enclosed "raspi2_start_windows10iot.cmm" script. 
DO raspi2_start_windows10iot.cmm [kernel_old=<0|1>]
This will copy the "kernel.img" relative to windows 10 to RASPI2 RAM memory
at kernel load address and setup necessary configurations in order to boot windows10 
with JTAG enabled.
