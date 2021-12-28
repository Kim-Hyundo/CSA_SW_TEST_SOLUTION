; --------------------------------------------------------------------------------
; @Title: Position IndependentSieve Demo - README
; @Description: -
; @Author: AME
; @Copyright: (C) 1989-2014 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: readme.txt 9468 2016-06-28 08:48:28Z amerkle $

= Usage =
The files are compiled as Position Independent. Therefore the base offset 
must be specified before loading into the target
  
  Data.LOAD.Elf ~~/demo/arm/compiler/gnu-pic/<file>.elf <offset> /RelPATH

e.g. for a CortexM3 to load the code to address 0x20001000
  Data.LOAD.Elf ~~/demo/arm/compiler/gnu-pic/midi_thumb_ii_v7m.elf 0x20001000 /RelPATH
  
e.g. for a CortexA9 (ARM MODE) to load the code to address 0x40003000
  Data.LOAD.Elf ~~/demo/arm/compiler/gnu-pic/midi_arm.elf 0x40003000 /RelPATH
  
As an alternative use demo_<name>.cmm scripts. These try to select the most suitable file
depending on the supported cpu modes.
  DO ~~/demo/arm/compiler/gnu-pic/demo_midi.cmm 0x<offset>
e.g.
  DO ~~/demo/arm/compiler/gnu-pic/demo_midi.cmm 0x20000000
  
= Ram Requirements =
 midi_<mode>.elf  - requires  4k of RAM
 sieve_<mode>.elf - requires 12k of RAM


= Compatibility =
_arm.elf          - all Cortex-A/R cores, ARM7, ARM9, ARM11
_armbe.elf        - all Big-Endian Cortex-A/R cores, ARM7, ARM9, ARM11
_armv7a.elf       - all Cortex-A/R cores
_thumb_v4.elf     - all Cortex-A/R cores, ARM7T, ARM9, ARM11
_thumb_v6m.elf    - CortexM0+, CortexM0, CortexM1 
_thumb_ii_v7m.elf - CortexM3, CortexM4, CortexM7
