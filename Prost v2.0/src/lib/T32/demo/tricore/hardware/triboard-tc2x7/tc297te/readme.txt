; --------------------------------------------------------------------------------
; @Title: README for TC297TE on TriBoard-TC2x7
; @Description:
;   List of available demo scripts and applications. The provided applications
;   are running in internal scratch pad ram (*_intmem) or from processor
;   internal flash (*_intflash). Please read the comments and hints provided in
;   each script. Further information is available in in the Tricore Processor
;   Architecture Manual (pdf/debugger_tricore.pdf), chapter "Multi-Core
;   Debugging (AURIX)".
; @Author: MOB
; @Board: TriBoard-TC2x7
; @Chip: TC297TE
; @Copyright: (C) 1989-2020 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: readme.txt 15579 2020-01-27 15:08:53Z sltaief $


The following demos are available:

tc297te_demo.cmm:
  Loads the sieve demo application (single-core) into RAM and sets up a demo
  debug scenario. Use this script for getting started.

tc297te_demo_flash.cmm:
  Programs the sieve demo application (single-core) into the processor internal
  flash and sets up a demo debug scenario. This script can be used as a
  template for flashing an application.

tc297te_flash.cmm:
  Allows you to flash your application into memory. Please make sure to
  understand the comments in the script!

tc297te_smp_demo_loop.cmm:
  Assembles a simple endless loop into RAM and sets up a demo debug scenario
  for SMP debugging.

tc297te_smp_demo_multisieve.cmm:
  Loads the multisieve demo application (multi-core) into RAM and sets up a
  demo debug scenario for SMP debugging. Further information is available in in
  the Tricore Processor Architecture Manual (pdf/debugger_tricore.pdf), chapter
  "SMP Debugging - Quick Start".

tc297te_smp_demo_multisieve_flash.cmm:
  Programs the multisieve demo application (multi-core) into the processor
  internal flash and sets up a demo debug scenario for SMP debugging. Further
  information is available in in the Tricore Processor Architecture Manual
  (pdf/debugger_tricore.pdf), chapter "SMP Debugging - Quick Start".

tc297te_amp_demo_multisieve.cmm:
  Loads the multisieve demo application (multi-core) into RAM and sets up a
  demo debug scenario for AMP debugging. Further information is available in in
  the Tricore Processor Architecture Manual (pdf/debugger_tricore.pdf), chapter
  "AMP Debugging - Quick Start".

tc297te_amp_demo_multisieve_flash.cmm:
  Programs the multisieve demo application (multi-core) into the processor
  internal flash and sets up a demo debug scenario for AMP debugging. Further
  information is available in in the Tricore Processor Architecture Manual
  (pdf/debugger_tricore.pdf), chapter "AMP Debugging - Quick Start".

tc297te_amp_demo_multisieve_start_core0.bat:
  Windows batch file for a one-click start of the amp multisieve demo. It
  assumes TRACE32 is installed to C:\T32, modify it to fit your needs.

tc297te_smp_demo_waveform.cmm:
  Loads the waveform generation demo application (multi-core) into RAM and sets
  up a demo debug scenario for SMP debugging. Further information is available
  in in the Tricore Processor Architecture Manual (pdf/debugger_tricore.pdf),
  chapter "SMP Debugging - Quick Start". More information about the demo
  application can be found in "waveform.c".

tc297te_amp_demo_waveform.cmm:
  Loads the waveform generation demo application (multi-core) into RAM and sets
  up a demo debug scenario for AMP debugging. Further information is available
  in in the Tricore Processor Architecture Manual (pdf/debugger_tricore.pdf),
  chapter "SMP Debugging - Quick Start". More information about the demo
  application can be found in "waveform.c".
