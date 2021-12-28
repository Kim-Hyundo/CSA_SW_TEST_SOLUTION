; --------------------------------------------------------------------------------
; @Title: IMX53 QuickStart Board Demo Scripts - README
; @Description: -
; @Author: PEG
; @Board: IMX53 QuickStart
; @Chip: IMX53*
; @Copyright: (C) 1989-2014 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: readme.txt 7022 2014-04-28 15:08:24Z kjmal $

09-06-2011, PEG: readme updated; peripheral files are available, now 
07-03-2011, PEG: R38 needs to be not populated which is default.
24-02-2011, PEG

Hints for debugging the Freescale i.MX53 Quick Start Board:


Lauterbach tool selection:

See: http://www.lauterbach.com/frames.html?pro/pro_imx23.php?chip=MCIMX53
The i.MX53 processor provides an off-chip trace port but it is not accessible on this board.
The on-chip trace can be used. For on-chip trace you need to have
LA-7970X "Trace License for the ARM Architecture" or you need to have an off-chip trace probe
"Preprocessor" connected to your tool (includes the on-chip license).


Lauterbach tool connection and board preparation:

(JTAG-MOD signal needs to be low to select the JTAG chain configuration the debugger expects.
 This is done by not populating R38 which is default on this board.)
 
(There is no chance to connect an off-chip trace probe to this board.)
 
Connect the Lauterbach Debug Cable to J15.
Provide 5V power at J1 and push power switch SW2.
The minimum start-up commands you need are:

  SYStem.CPU IMX535
  SYStem.Option ResBreak OFF
  SYStem.Option WaitReset 100ms
  SYStem.Up


Required TRACE32 software version:

>= build 25870 (November 10, 2010 release)
The November 2010 release can be downloaded from our web but does not include proper peripheral
and menu files.

Updates including suitable peripheral and menu files are available since April 8, 2011.
Such an update is expected to become available on our web in June 2011.
Meanwhile drop me (Peter.Egold@lauterbach.com) an email to get an update including these files.


Demo Script:

See imx53_sieve for a simple demo.