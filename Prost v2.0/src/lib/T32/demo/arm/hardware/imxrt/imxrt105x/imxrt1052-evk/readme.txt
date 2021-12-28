; --------------------------------------------------------------------------------
; @Title: Readme for IMXRT105x
; @Description:
;   Readme for IMXRT105x.
; @Keywords: ARM, Cortex-M7
; @Author: AME
; @Board: -
; @Chip: IMXRT1052
; @Copyright: (C) 1989-2017 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: readme.txt 12203 2018-02-22 11:31:42Z mobermeir $

= JTAG =
Factory default for JTAG is disabled thus only SWD is available.
JTAG can be enabled via DAP_SJC_SWD_SEL fuse.

= SWO/SWV =
In contrast to the ARM default the SerialWireViewer uses a separate output pin GPIO_B0_13 and not the TDO line.
Thus the SWO/SWV pin must be wired to the TDO of the Combiprobe/uTrace to use SerialWireViewer.