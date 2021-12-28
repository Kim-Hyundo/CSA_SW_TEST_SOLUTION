; --------------------------------------------------------------------------------
; @Title: README for TriBoard with TC1782-based processors
; @Description:
;   List of available demo scripts and applications. The provided applications
;   are running in internal scratch pad ram (*_intmem) or from processor
;   internal flash (*_intflash). Please read the comments and hints provided in
;   each script. Further information is available in in the Tricore Processor
;   Architecture Manual (pdf/debugger_tricore.pdf).
; @Author: MOB
; @Board: TriBoard-tc1782
; @Chip: TC1782*
; @Copyright: (C) 1989-2014 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: readme.txt 6993 2014-04-24 13:26:40Z mobermeir $


The following demos are available for each CPU:
demo   Loads the Lauterbach sieve demo into RAM and sets up a demo
       debug scenario.
flash  Configures flash programming for available flash memories, and
       offers the possibility to erase and program.


The following demos applications are available:
triboard-tc1782_sieve_intmem.elf
    Lauterbach sieve demo for running from internal RAM.
triboard-tc1782_sieve_intflash.elf
    Lauterbach sieve demo for running from internal FLASH.
    Demo needs to be flashed first.
