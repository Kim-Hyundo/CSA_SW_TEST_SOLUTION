; --------------------------------------------------------------------------------
; @Title: README for TC234LF on TriBoard-TC2x4
; @Description:
;   List of available demo scripts and applications. The provided applications
;   are running in internal scratch pad ram (*_intmem) or from processor
;   internal flash (*_intflash). Please read the comments and hints provided in
;   each script. Further information is available in in the Tricore Processor
;   Architecture Manual (pdf/debugger_tricore.pdf), chapter "Multi-Core
;   Debugging (AURIX)".
; @Author: MOB
; @Board: TriBoard-TC2x4
; @Chip: TC234LF
; @Copyright: (C) 1989-2020 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: readme.txt 15579 2020-01-27 15:08:53Z sltaief $


The following demos are available:

tc234lf_demo.cmm:
  Loads the sieve demo application (single-core) into RAM and sets up a demo
  debug scenario. Use this script for getting started.

tc234lf_demo_flash.cmm:
  Programs the sieve demo application (single-core) into the processor internal
  flash and sets up a demo debug scenario. This script can be used as a
  template for flashing an application.
