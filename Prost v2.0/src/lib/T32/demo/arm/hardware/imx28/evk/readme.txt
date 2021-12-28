; --------------------------------------------------------------------------------
; @Title: Freescale i.MX28 Evaluation Kit Demo Scripts - README
; @Description: -
; @Author: PEG
; @Board: i.MX28 EVK
; @Chip: IMX287
; @Copyright: (C) 1989-2014 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: readme.txt 7058 2014-05-06 05:48:13Z pegold $

23-02-2011, PEG

Hints for debugging the Freescale i.MX28 Evaluation Kit (EVK):

Board:
http://www.freescale.com/webapp/sps/site/prod_summary.jsp?code=MCIMX28EVKJ


Lauterbach tool selection:
http://www.lauterbach.com/frames.html?pro/pro_imx23.php?chip=MCIMX28


Lauterbach tool connection and board preparation:

For debugging connect Lauterbach Debug Cable to 20-pin JTAG connector (J87).

For trace you need to remove the LCD board, solder a Mictor connector at P4,
additionally connect the Lauterbach Preprocessor (not tested).

You can power the board via Micro USB (J82), set S16="USB 5V", switch on by S3="ON".
Or you can power it by external power supply (J84), set S16="WALL 5V".


Demo Script:
See demo.zip for a simple demo.
