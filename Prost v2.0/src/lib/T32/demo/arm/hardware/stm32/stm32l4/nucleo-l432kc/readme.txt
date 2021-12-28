; --------------------------------------------------------------------------------
; @Title: Readme for Nucleo32-L432KC
; @Description:
; @Keywords: ARM, Cortex-M4
; @Author: MIS
; @Board: nucleo-l432kc
; @Chip: STM32L432KC
; @Copyright: (C) 1989-2019 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: readme.txt 14082 2019-03-08 14:21:40Z mschleinkofer $

The Nucleo-l432kc board does not present a standard debug header.
To debug the STM32 controller using TRACE32 you need to perform the following modifications:


Disconnect ST-LINK from STM32L432KCU6:
  - Open solder bridge SB9
  - Either solder an ARM-20 female port to the pads around the STM32L432KCU6 according to the mapping below
  - Or solder a MIPI-20 female port to the pads around the STM32L432KCU6 according to the mapping below
  
Connect TRACE32 to STM32L432KCU6:

  - ARM-20 connector (Debug Cable):

    +---------------------------------------------------+
    | ARM-20        | Name   | STM32L432KCU6    | Name  |
    +---------------------------------------------------+
    | Pin 1         | VREF   | µC[5]            | VDD   |
    | Pin 4         | GND    | CN2[2]           | GND   |
    | Pin 7         | SWDIO  | µC[23]           | PA13  |
    | Pin 9         | SWCLK  | µC[24]           | PA14  |
    | Pin 13        | SWO    | µC[26]           | PB3   |
    | Pin 15        | RESET- | µC[4]            | NRST  |
    +---------------------------------------------------+

  - MIPI-20 connector (Debug Cable):

    +---------------------------------------------------+
    | MIPI-20       | Name   | STM32L432KCU6    | Name  |
    +---------------------------------------------------+
    | Pin 1         | VREF   | µC[5]            | VDD   |
    | Pin 2         | SWDIO  | µC[23]           | PA13  |
    | Pin 3         | GND    | CN2[2]           | GND   |
    | Pin 4         | SWCLK  | µC[24]           | PA14  |
    | Pin 6         | SWO    | µC[26]           | PB3   |
    | Pin 10        | RESET- | µC[4]            | NRST  |
    +---------------------------------------------------+