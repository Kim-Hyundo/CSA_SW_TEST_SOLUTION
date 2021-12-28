; --------------------------------------------------------------------------------
; @Title: Freescale i.MX35 Board Demo Scripts - README
; @Description: -
; @Author: PEG
; @Board: phyCORE-i.MX35
; @Chip: IMX35
; @Copyright: (C) 1989-2014 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: readme.txt 7050 2014-05-05 12:40:42Z mobermeir $

03-03-2011, PEG

Hints for debugging the Freescale i.MX35 Board of the Product Development Kit (PDK):


Board:
http://www.freescale.com/webapp/sps/site/prod_summary.jsp?code=IMX35PDK


Lauterbach tool selection:
http://www.lauterbach.com/frames.html?pro/pro_imx23.php?chip=MCIMX35


Start-up scripts:
Unfortunately we do not have scripts prepared for this board.
But the following start-up sequence should work:  

  RESet
  SYStem.CPU IMX35
  SYStem.Option ResBreak OFF
  SYStem.JtagClock RTCK
  SYStem.Up

  <board specific initialization if needed>


imx35-spi.cmm:
This includes a script file and the flash algorithm to program a serial flash
of type NUMONYX, M25P32 which is connected to CSPI1_SS0 of i.MX35.

