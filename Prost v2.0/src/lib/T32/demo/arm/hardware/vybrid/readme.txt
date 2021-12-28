; --------------------------------------------------------------------------------
; @Title: Readme for VF3xx VF4xx VF5xx VF6xx VF7xx Vybrid
; @Description:
; @Keywords: ARM, Cortex-A5, Cortex-M4
; @Author: AME
; @Board: TWR-VF65GS10
; @Chip: VF32* VF52* VF6* VF7*
; @Props: ZIP
; @Copyright: (C) 1989-2016 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: readme.txt 14222 2019-04-01 12:40:51Z hlohn $

Example files are written for VF65GS10 Tower board but should also work for other boards.

To debug revision H of tower board TWR-VF65GS10 you have to solder a 10K Ohm resistor at R161 (which is unpopulated by default).
If a revision H board is used stand alone (without the tower elevator boards) set J19 to 2-3 and power the board via micro USB connector J8.
