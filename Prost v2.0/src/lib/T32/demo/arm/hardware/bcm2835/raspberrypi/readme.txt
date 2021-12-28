; --------------------------------------------------------------------------------
; @Title: How to use the Lauterbach debugger on a Raspberry Pi target
; @Description: Board adaption, GPIO configuration for JTAG, debugger start-up
; @Keywords: Raspberry Pi, BCM2835, BCM2708, ARM11 
; @Author: PEG
; @Board: Raspberry Pi
; @Copyright: (C) 1989-2014 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: readme.txt 7281 2014-07-01 08:13:41Z mobermeir $


The below was tested on a rev.1 board, only.


Overview:

The ARM1176 core on the BCM2835 chip (BCM2708 family) on the Raspberry Pi
target board has a JTAG based debug port. Other as you might think this debug
port does not show up on the JTAG interface at connector P2. You need to use
connector P1 which pinout does not match the debuggers connector pinout.
You need to build an adapter.

Unfortunately the pins are not by default connected to the outside world. You
need to have a program running on the board which configures the alternate GPIO
functions that the JTAG signals will show up on the pins of P1. During the
debug session no reset might happen because this would cause the default
configuration of the GPIOs and would disconnect the JTAG.


Checking the board revision:

On an older board revision (rev.1) one signal (TMS) is missing on P1. If you
have such a board you need to get the TMS signal from S5-11 instead from P1-13.

Pictures of board rev.1 show a black audio connector next to the yello video
connector. Pictures of board rev.2 show a blue audio connector.

To double-check the revision of your board, insert a SDcard which will boot
Linux, connect a monitor to the HDMI interface and a keyboard to one of the USB
interfaces. (Hint: A keyboard with internal hub did not work with my board/OS.)

Boot Linux and login: login: pi, password: raspberry
Enter: "cat /proc/cpuinfo" and check revision.
"beta", "0002", "0003" -> Rev. 1 -> TMS on S5-11
"0004", ..., "000f" -> Rev 2 -> TMS on P1-13
(Hint: The Linux expects a "qwerty" keyboard for the above input.)


Build an adapter:

JTAG-20   signal  GPIO pin  ALT mode  board pin

1         VREF                        P1-1 (3,3V)
3         nTRST   GPIO22    ALT4      P1-15
5         TDI     GPIO4     ALT5      P1-7
7         TMS     GPIO27    ALT4      P1-13 (Rev. 1 boards -> S5-11)
9         TCK     GPIO25    ALT4      P1-22
11        RTCK    GPIO23    ALT4      P1-16
13        TDO     GPIO24    ALT4      P1-18
2,4,..,20 GND                         P1-6,-9,-14,-20,-25 (GND)

(Hint: When looking for S5-11 on Rev.1 board:
The pins 1, 2, 3, 4, ... of S5 are on the same side, not alternating!)


Configure the alternate GPIO functions:

#define GPFSEL0 ((volatile unsigned int *) 0x20200000)
#define GPFSEL2 ((volatile unsigned int *) 0x20200008)
 
// GPIO4 alt5 -> TDI
*GPFSEL0 &= ~0x00007000; 
*GPFSEL0 |=  0x00002000;

// GPIO22,23,24,25,27 alt4 -> nTRST,RTCK,TDO,TCK,TMS
*GPFSEL2 &= ~0x00e3ffc0;
*GPFSEL2 |=  0x0061b6c0;


How to get this configuration executed:

Rename enclosed jtagenable.bin to kernel.img and replace that file on the
SDcard. It contains the configuration above and switches the OK LED on (no
Linux boot anymore). This way you can verify it got executed.

(Hint: The loader loads and starts kernel.img at 0x8000.)

The real solution is to place the above GPIO configuration for JTAG in the
program which runs after reset. Ensure that this configuration will not be
changed by your program later.


Debugger start-up:

SYStem.CPU ARM1176JZF
SYStem.JtagClock RTCK
SYStem.Up

Alternatively run the enclosed demo program.




