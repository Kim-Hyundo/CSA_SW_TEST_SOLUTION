= ZYNQ =
Booting the ZYNQ using TCL files & loading the bitstream is shown in scripts/trace/start.cmm.

= Troubleshooting =
== BUS ERROR after SYStem.Up ==
On old FSBL versions of Xilinx the DBG_CLK was not properly initialized. Which resulted in a BusError and possible debug session crash.
To prevent this use the following connection sequence:
  SYStem.CPU ZYNQ-7000
  ; SYStem.CONFIG DAPIR/DR PRE/POST <values> if applicable
  ETM.OFF
  SYStem.Mode.Attach
  
  ; now verify that the DBG_CLK_CTRL is properly initialized.
  ; if not
  ; SLCR - UNLOCK WRITE
  Data.Set ASD:0XF8000008 %LONG 0x0000DF0D
  ;DBG_CLK_CTRL - use ARM_PLL/6 ~ 111MHz with ARMPLL=666MHz
  Data.Set ASD:0xF8000164 %LONG 0x623 
  ; SLCR - LOCK WRITE
  Data.Set ASD:0XF8000004 %LONG 0x0000767B
  
  ETM.ON
  