; --------------------------------------------------------------------------------
; @Title: Readme for STM32F0DISCOVERY
; @Description:
; @Keywords: ARM, Cortex-M0
; @Author: MIS
; @Board: stm32f0-discovery
; @Chip: STM32F051R8
; @Copyright: (C) 1989-2019 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: readme.txt 14081 2019-03-08 14:14:26Z mschleinkofer $

The sieve demo was reduced, because of the limited sram of the chip
The STM32F0DISCOVERY board does not present a standard debug header.
To debug the board using TRACE32 you need to perform the following modifications:


Disconnect ST-LINK from STM32F051:

  - Remove both jumpers on CN2
  - Open solder bridges SB19 and SB22 (recommended)


Connect TRACE32 to STM32F051:


  - ARM-20 connector (Debug Cable):

    +---------------------------------------------------+
    | ARM-20        | Name   | STM32F0DISCOVERY | Name  |
    +---------------------------------------------------+
    | Pin 1         | VREF   | P2[5]            | VDD   |
    | Pin 4         | GND    | P2[2]            | GND   |
    | Pin 7         | SWDIO  | CN2[4]           | PA13  |
    | Pin 9         | SWCLK  | CN2[2]           | PA14  |
    | Pin 15        | RESET- | P1[10]           | NRST  |
    +---------------------------------------------------+

	 
  - MIPI-10, MIPI-20, MIPI-34 connector (CombiProbe, µTrace):

    +---------------------------------------------------+
    | MIPI-10/20/34 | Name   | STM32F0DISCOVERY | Name  |
    +---------------------------------------------------+
    | Pin 1         | VREF   | P2[5]            | VDD   |
    | Pin 3         | GND    | P2[2]            | GND   |
    | Pin 2         | SWDIO  | CN2[4]           | PA13  |
    | Pin 4         | SWCLK  | CN2[2]           | PA14  |
    | Pin 10        | RESET- | P1[10]           | NRST  |
    +---------------------------------------------------+