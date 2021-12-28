; --------------------------------------------------------------------------------
; @Title: OMAP3503 Mistral Board Demo Scripts - README
; @Description: -
; @Author: PEG
; @Board: Mistral
; @Chip: OMAP3530
; @Copyright: (C) 1989-2014 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: readme.txt 7050 2014-05-05 12:40:42Z mobermeir $

PEG, March 18, 2011


OMAP35x Evaluation Module (EVM), TMDSEVM3503, Mistral, Spectrum Digital

The board provides a TI 14-pin connector (P3). To connect our standard Debug Cable you
will need the converter: LA-7748 "Converter ARM-20 to TI-14".
There is also a Mictor connector (P4) to connect our trace Preprocessor.
In case you use a Preprocessor you should connect the Debug Cable to the Preprocessor
instead to the board.

demo.cmm: Small demo program running on the Cortex-A8.
etm.cmm: Initialization for trace.
