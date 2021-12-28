; --------------------------------------------------------------------------------
; @Title: ZedBoard Demo Scripts - README
; @Description: -
; @Author: PEG
; @Board: ZedBoard
; @Chip: Zynq-7000
; @Copyright: (C) 1989-2014 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: readme.txt 8148 2015-02-19 16:50:04Z amerkle $

These demo files should demonstrate debug and trace for the AVNET ZEDBOARD board using the TRACE32 debugger. The scripts will not run on any other board.


Before running the scripts please do the following:
- Connect the JTAG cable to J15 (JTAG)
- Set MIO[6-2] = 0y00000 or 0y01100
- remove all sd-cards

= Trace =
On the Zedboard board the only way to use the TRACE port is to attach the XILINX HW_FMC-105-DEBUG board to J1 FMC1 connector. A design that routes TRACECLK, TRACECTRL and TRACEDATA[15:0] signals has to be programmed to the FPGA. 
Please short TDI-TDO on the XILINX HW_FMC-105-DEBUG board.
Call zedboard_offchip_trace_demo.cmm