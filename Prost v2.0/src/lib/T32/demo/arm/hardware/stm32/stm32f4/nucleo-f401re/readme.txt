; --------------------------------------------------------------------------------
; @Title: Readme for Nucleo64-F401RE
; @Description:
; @Keywords: ARM, Cortex-M4
; @Author: MIS
; @Board: nucleo-f401re
; @Chip: STM32F401RE
; @Copyright: (C) 1989-2019 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: readme.txt 14082 2019-03-08 14:21:40Z mschleinkofer $

The Nucleo-f446re board does not present a standard debug header.
To debug the board using TRACE32 you need to perform the following modifications:

Disconnect the ST-LINK from STM32F446RE:
	- Remove both jumpers on CN2
	- Open solder bridges SB12 and SB15 (optional but makes sure, that the debug-chip does not accidentally interfere with the debugging)
	
Connect TRACE32 to STM32F401RE:

	- MIPI-20 connector (Debug Cable):
    +---------------------------------------------------+
    | MIPI-20       | Name   | STM32F446RE      | Name  |
    +---------------------------------------------------+
    | Pin 1         | VREF   | CN10[7]          | 3.3V  |
    | Pin 2         | TMS    | CN7[13]          | PA13  |
    | Pin 3         | GND    | CN7[19]          | GND   |
    | Pin 4         | TCK    | CN7[15]          | PA14  |
    | Pin 6         | TDO    | CN10[31]         | PB3   |
    | Pin 8         | TDI    | CN7[17]          | PA15  |
    | Pin 10        | RESET- | CN7[14]          | NRST  |
    +---------------------------------------------------+
