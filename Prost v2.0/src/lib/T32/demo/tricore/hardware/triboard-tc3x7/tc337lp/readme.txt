; --------------------------------------------------------------------------------
; @Title: README for TC337LP on TriBoard-TC3x7
; @Description:
;   List of available demo scripts and applications. The provided applications
;   are running in internal scratch pad ram (*_intmem) or from processor
;   internal flash (*_intflash). Please read the comments and hints provided in
;   each script. Further information is available in in the Tricore Processor
;   Architecture Manual (pdf/debugger_tricore.pdf), chapter "Multi-Core
;   Debugging (AURIX)".
; @Author: MOB
; @Board: TriBoard-TC3x7
; @Chip: TC337LP
; @Copyright: (C) 1989-2020 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: readme.txt 15580 2020-01-27 15:36:09Z sltaief $


The following demos are available:

demo.cmm:
  Loads the sieve demo application (single-core) into RAM and sets up a demo
  debug scenario. Use this script for getting started.

demo_flash.cmm:
  Programs the sieve demo application (single-core) into the processor internal
  flash and sets up a demo debug scenario. This script can be used as a
  template for flashing an application.

disable_tlf35584.cmm:
  Initialisation script to switch off TLF35584 watchdog and error pin on
  TriBoard. Usage: disable_tlf35584.cmm ["AREA"|"SILENT"]. Based on Infineon
  script.
