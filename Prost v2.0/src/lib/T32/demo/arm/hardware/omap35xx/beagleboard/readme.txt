; --------------------------------------------------------------------------------
; @Title: BeagleBoard Demo Scripts - README
; @Description: -
; @Author: PEG
; @Board: BeagleBoard
; @Chip: OMAP3530
; @Copyright: (C) 1989-2014 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: readme.txt 7022 2014-04-28 15:08:24Z kjmal $

PEG, March 18, 2011


BeagleBoard

The BeagleBoard is an OMAP3530 based development board.

Link to the board provider: http://beagleboard.org/

On the board is a TI 14-pin connector. To connect our standard Debug Cable you will
need the converter: LA-7748 "Converter ARM-20 to TI-14"
There is no connector on the BeagleBoard to connect a trace tool.

"sieve":
Small demo program.
Run start_cortex.cmm for Cortex-A8 demo and start_dsp.cmm for TMS320C64x+ demo.
start_cortex.cmm needs to be started first to release the DSP from reset.

"semihosting"
Small demo to show usage of semihosting on the Cortex-A8.


