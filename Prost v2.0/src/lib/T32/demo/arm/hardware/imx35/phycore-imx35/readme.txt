; --------------------------------------------------------------------------------
; @Title: phyCORE-i.MX35 Demo Scripts - README
; @Description: -
; @Author: PEG
; @Board: phyCORE-i.MX35
; @Chip: IMX35
; @Copyright: (C) 1989-2014 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: readme.txt 7050 2014-05-05 12:40:42Z mobermeir $

03-03-2011, PEG

Hints for debugging the phyCORE-i.MX35 (PCM043) board:


Lauterbach tool selection:
http://www.lauterbach.com/frames.html?pro/pro_imx23.php?chip=MCIMX35


Start-up scripts:
The minimum start-up sequence will be:  

  RESet
  SYStem.CPU IMX35
  SYStem.Option ResBreak OFF
  SYStem.JtagClock RTCK
  SYStem.Up


Scripts to set-up a debug session for Linux based applications can be found under demo/arm/kernel/linux/board/phycore-imx35


imx35-spi.cmm:
Script file and the flash algorithm to program a serial flash
of type NUMONYX, M25P32 which is connected to CSPI1_SS0 of i.MX35.

