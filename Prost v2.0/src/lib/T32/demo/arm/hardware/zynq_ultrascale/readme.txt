; --------------------------------------------------------------------------------
; @Title: Readme for ZYNQ-Ultrascale+
; @Description: Readme for ZYNQ-Ultrascale+
; @Keywords: ARM, Cortex-A53
; @Author: AME
; @Board: -
; @Chip: ZYNQ-ULTRASCALE+*
; @Props: ZIP
; @Copyright: (C) 1989-2016 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: readme.txt 15427 2019-12-16 12:05:21Z bschroefel $

= Bootmodes =
We recommend to use the JTAG-BOOT mode for the ZYNQ-Ultrascale. By the time of development of the scripts 
the JTAG-BOOT mode was the only bootmode which enables the JTAG Interface of the ZYNQ-Ultrascale+.

= Secure Access to AXI =
To make sure that a secure AXI access (ZAXI) is working, set jtag_dap_cfg[7:6] of the CSU to '11'.
All in all it is recommended to set jtag_dap_cfg (CSU) to 0xFF, to enable debugging and secure accesses.
