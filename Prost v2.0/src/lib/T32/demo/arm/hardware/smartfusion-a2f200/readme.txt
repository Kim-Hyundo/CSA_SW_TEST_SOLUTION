; --------------------------------------------------------------------------------
; @Title: Readme for Actel/Microsemi Smartfusion A2F
; @Description:
; @Keywords: ARM, Cortex-M3
; @Author: AME
; @Board: -
; @Chip: A2F*
; @Props: ZIP
; @Copyright: (C) 1989-2016 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: readme.txt 10110 2016-10-21 07:15:58Z amerkle $

= FAQ =
== The RESET line is continuously asserted ==
The last sectors of the eNVM/FLASH are used by the Smartfusion MSS configurator to 
store configuration data. In case this memory region gets erased e.g. by 
  FLASH.ERASE
  FLASH.ReProgram /ERASE
or is used by the user code binary the device might not boot properly. In worst 
case the RESET line stays asserted continuously. In such a situation please 
reprogram the FPGA portion using the Actel/Microsemi FlashPRO tool of by using 
  JTAG.PROGRAM.JAM <filename>.stp /A "PROGRAM"
. An example for the latter case is available (a2f-eval-kit_program_fpga.cmm).

As the amount of data used for the MSS configuration depends on the user 
configuration we do not "guard" any flash-sectors against erasing/writing.

Please refer to the "Smartfusion Microcontroller Subsytem" manual section 
"Embedded Nonvolatile Memory – Memory Organization" for more details.