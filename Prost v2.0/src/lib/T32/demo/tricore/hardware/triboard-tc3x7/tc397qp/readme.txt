; --------------------------------------------------------------------------------
; @Title: README for TC397QP on TriBoard-TC3x7
; @Description:
;   List of available demo scripts and applications. The provided applications
;   are running in internal scratch pad ram (*_intmem) or from processor
;   internal flash (*_intflash). Please read the comments and hints provided in
;   each script. Further information is available in in the Tricore Processor
;   Architecture Manual (pdf/debugger_tricore.pdf), chapter "Multi-Core
;   Debugging (AURIX)".
; @Author: MOB
; @Board: TriBoard-TC3x7
; @Chip: TC397QP
; @Copyright: (C) 1989-2020 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: readme.txt 15539 2020-01-17 12:22:53Z meick $


The following demos are available:

demo.cmm:
  Loads the sieve demo application (single-core) into RAM and sets up a demo
  debug scenario. Use this script for getting started.

demo_flash.cmm:
  Programs the sieve demo application (single-core) into the processor internal
  flash and sets up a demo debug scenario. This script can be used as a
  template for flashing an application.

smp_demo_multisieve.cmm:
  Loads the multisieve demo application (multi-core) into RAM and sets up a
  demo debug scenario for SMP debugging. Further information is available in in
  the Tricore Processor Architecture Manual (pdf/debugger_tricore.pdf), chapter
  "SMP Debugging - Quick Start".

smp_demo_multisieve_flash.cmm:
  Programs the multisieve demo application (multi-core) into the processor
  internal flash and sets up a demo debug scenario for SMP debugging. Further
  information is available in in the Tricore Processor Architecture Manual
  (pdf/debugger_tricore.pdf), chapter "SMP Debugging - Quick Start".

demo_amp_loop.cmm:
  Assembles a simple endless loop into RAM and sets up a demo debug scenario
  for AMP debugging.

disable_tlf35584.cmm:
  Initialisation script to switch off TLF35584 watchdog and error pin on
  TriBoard. Usage: disable_tlf35584.cmm ["AREA"|"SILENT"]. Based on Infineon
  script.

demo_amp_waveform.cmm:
  Loads the waveform generation demo application (multi-core) into RAM and sets
  up a demo debug scenario for AMP debugging. Further information is available
  in in the Tricore Processor Architecture Manual (pdf/debugger_tricore.pdf),
  chapter "AMP Debugging - Quick Start". More information about the demo
  application can be found in "waveform.c".

demo_amp_waveform_flash.cmm:
  Loads the waveform generation demo application (multi-core) into flash and
  sets up a demo debug scenario for AMP debugging. Further information is
  available in in the Tricore Processor Architecture Manual
  (pdf/debugger_tricore.pdf), chapter "AMP Debugging - Quick Start". More
  information about the demo application can be found in "waveform.c".

init_amp_waveform.cmm:
  Helper script to start and initialize cores 1 to 5
