; --------------------------------------------------------------------------------
; @Title: How to use the Lauterbach debugger on a Nitrogen6x-SOM target
; @Description: Needed board modification
; @Keywords: Raspberry Pi, BCM2835, BCM2708, ARM11 
; @Author: KJM
; @Board: Nitrogen6x-SOM
; @Chip: IMX6*
; @Copyright: (C) 1989-2014 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: readme.txt 7353 2014-07-07 08:21:07Z mobermeir $


Using JTAG on the Nitrogen6x-SOM board requires that the RN1 set of resistors are not populated, on both the SOM board and the carrier board. 
Also, the RN2 set of resistors must be populated, on both the SOM board and the carrier board.

On the daughter card, please make sure that jumpers J3, J4, and J6 are populated, with the remaining jumpers left open.

Please use the start-up scripts from demo/arm/hardware/imx6/sabrelite