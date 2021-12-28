; --------------------------------------------------------------------------------
; @Title: How to use the Lauterbach debugger on a Raspberry Pi 2 target
; @Description: Board adaptation, GPIO configuration for JTAG, debugger start-up
; @Keywords: Cortex-A7, CORTEXA7MPCORE, enable, jtag, raspi2
; @Author: HDA
; @Board: Raspberry Pi 2
; @Chip: BCM2836
; @Copyright: (C) 1989-2016 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: readme.txt 9916 2016-09-02 08:24:27Z amerkle $

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

How to get this configuration executed:

Rename enclosed "jtagenable.bin" to "kernel.img" and replace that file on the
SD-card. It contains the configuration above and execute an infinite while loop (no
operating system boot any-more).

Further I had to remove/rename the existing kernel7.img to get it going.

(Hint: The loader loads and starts "kernel.img" at 0x8000.)

The real solution is to place the above GPIO configuration for JTAG in the
program which runs after reset. Ensure that this configuration will not be
changed by your program later.

Or you can compile the module "jtagenable_linux_module.c" and run it from your linux distrubution.

Debugger start-up:

SYStem.CPU BCM2836
SYStem.mode attach
Break.direct

Alternatively run the enclosed demo program.



