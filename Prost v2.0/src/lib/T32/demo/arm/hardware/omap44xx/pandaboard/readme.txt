; --------------------------------------------------------------------------------
; @Title: OMAP44xx TRACE32 Suport - README
; @Description: -
; @Author: PEG
; @Copyright: (C) 1989-2014 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: readme.txt 7025 2014-04-28 15:42:01Z kjmal $

History:
April    24, 2014: Separate demo for sieve, STM, PTM, STM+PTM & update sd card sript.
May      18, 2011: Software Update and Minidemo and readme.txt updated to support PTM+STM trace simultaneously.
May      12, 2011: Software update for Windows hosts added. Needed also for trace.
                   Hints for software versions changed. 
April    18, 2011: linux scripts updated. Software version from April 2011 or newer needed for the new scripts.
March    18, 2011: readme.txt and ti_scripts.zip updated. It includes a start-up guide, now.
March     8, 2011: Readme updated; Update removed because it becomes available on our web, now.
March     3, 2011: New version of ti_scripts.zip.
March     2, 2011: Script for eMMC programming added. 
February 10, 2011: New software update. Hints for software versions changed.
February  8, 2011: Linux demo added.
February  4, 2011: First files provided.



Dear PandaBoard User,

The PandaBoard is a new OMAP4430 based evaluation board. We have started to work with it and want
to share all experiences with you. We expect the information provided here to change frequently
within the next weeks. Our tests are done on a PandaBoard Rev A1 with an OMAP4430 ES2.1 GP.


Link to the board provider:

http://www.pandaboard.org/


Included cores and debug features:

The OMAP4430 includes a dual Cortex-A9 and some other cores which are all supported by our tools.
The OMAP4430 provides program trace (PTM) for the two Cortex-A9 (on-chip and off-chip @155MHz DDR)
and a system trace port (STM). In the following we focus on the dual Cortex-A9 because we think most
of you intend to program and debug the application processors.


Lauterbach tool connection:

The PandaBoard provides a 14-pin TI debug connector, only. This is not the default connector of
our tools. If you have a tool with a "Debug Cable" you will need the converter LA-7748 "Converter
ARM-20 to TI-14". It needs to be ordered separately. If you use a "CombiProbe" you will need the
converter LA-3771 "ARM Converter MIPI-34 to ARM-20 or TI-14" which comes with the CombiProbe.

Helpful direct links showing pinout and connector type:
http://www.lauterbach.com/frames.html?adarmdbg.html
http://www.lauterbach.com/frames.html?adarmcombi.html
http://www.lauterbach.com/frames.html?order/ord_ad7748.html
http://www.lauterbach.com/frames.html?order/ord_ad3771.html

For connecting a trace probe ("Preprocessor" or "CombiProbe") for off-chip trace (PTM or STM)
we provide a board which can be plugged onto the PandaBoard: LA-3840 "Trace Converter for
OMAP4430 PandaBoard". It has a connector for a "Preprocessor" for 16-bit off-chip program trace
(PTM) and a connector for "CombiProbe" for 4-bit system trace (STM). For details see
"Prepare_PandaBoard_for_Offchip_Trace.pdf". This document is also helpful if you intend to build
the trace converter yourself.

LA-3840 "Trace Converter for OMAP4430 PandaBoard" allows only to connect one probe cable! Otherwise
you will get signal issues caused by stubs on the JTAG lines. If you connect a Preprocessor to it
you need to connect the Debug Cable or CombiProbe to the Preprocessor instead to the adapter board.
If you want to get PTM trace and STM trace simultaneously you should use a MIPI Preprocessor (LA-7993)
and additionally a CombiProbe connected to this Preprocessor.

Helpful direct links showing pinout and connector type:
http://www.lauterbach.com/frames.html?adetmmictor.html (see ETMv3, Connector 1)
http://www.lauterbach.com/frames.html?adetmmipi60.html (see ETMv3)
http://www.lauterbach.com/frames.html?adarmcombi.html  (see 34-pin MIPI connector)


Lauterbach tool selection:

General tool recommendation for OMAP4430 can be found here:
http://www.lauterbach.com/frames.html?pro/pro_omap4430.php?chip=OMAP4430

The Lauterbach system which suits best depend on what cores you are going to debug, if on-chip and
off-chip trace is needed, and you should consider planned future projects. Mostly you can at least
partly re-use existing Lauterbach tools. Contact our representative in your country:
http://www.lauterbach.com/frames.html?worldreps.html

In the following we provide some possible example configurations assuming you want to debug Cortex-A9
on the PandaBoard:

Example "Debugging both Cortex-A9, no trace"
LA-7708 Power Debug Interface / USB-2
LA-7843 JTAG Debugger for CORTEX-A/-R
LA-7748 Converter ARM-20 to TI-14
LA-7960X License for Multicore Debugging

Example "Debugging both Cortex-A9, on-chip PTM and STM trace"
LA-7708 Power Debug Interface / USB-2
LA-7843 JTAG Debugger for CORTEX-A/-R
LA-7748 Converter ARM-20 to TI-14
LA-7960X License for Multicore Debugging
LA-7970X Trace License for the ARM Architecture

Example "Debugging both Cortex-A9, off-chip 4-bit STM trace"
LA-7708 Power Debug Interface / USB-2
LA-4502 CombiProbe ARM-Debugger and 4-Bit Trace
LA-7843A JTAG Debugger for CORTEX-A/-R
LA-7960X License for Multicore Debugging
LA-3840 Trace Converter for OMAP4430 PandaBoard

Example "Debugging both Cortex-A9, off-chip 16-bit PTM trace"
LA-7690 PowerTrace Ethernet 512 MB
LA-7843 JTAG Debugger for CORTEX-A/-R
LA-7960X License for Multicore Debugging
LA-7992 Preprocessor for ARM-ETM/AUTOFOCUS II 600 Flex
LA-3840 Trace Converter for OMAP4430 PandaBoard


Required TRACE32 software version:

For basic debugging you need to use at least the November 2010 DVD release which includes peripheral
and menu files. The DVD release versions can be downloaded at our download center on our web site.

For tracing and/or using the new Linux scripts and for latest improvements and bug fixes you need a
software version May 18, 2011 or newer. I have attached an update packet for Windows hosts to this
PandaBoard download (update_for_windows_hosts.zip). Just copy/replace the files in your TRACE32 system
directory (c:\t32?). Let me know if you have a different OS on your host.


If you are one of our representatives and are looking for demo examples for the "Pandaboard-Set",
then you should know the demo together with demo script files are on the SDcard which comes with the set.


"mini" folder:

Mini folder hold some small demos script to show basic debugging. It can configure the OMAP4430 for 16-bit 
program trace or 4-bit system trace or 8-bit PTM and 4-bit STM. You can run the demo by running one of those 
scripts: demo_sieve_sar-ram.cmm, demo_ptm.cmm, demo_stm.cmm, demo_stm_ptm.cmm.
 

"mmc_sd":
Contains a script and program algorithm for programming an MMC plugged into the SD/MMC card slot.
Better cause a board reset before running this script file.

Scripts from Texas Instruments "ti_scripts":

We have attached as well a script collection provided by Texas Instruments for our tool. It includes
further chip configurations and will especially be helpful if you want to debug cores other than the
Cortex-A9. There is also a start-up guide describing the script and tool usage.


Known issues:

LA-3840 "Trace Converter for OMAP4430 PandaBoard" allows only to connect one probe cable! See also above.


On issues drop an email to: khaled.jmal@lauterbach.com or peter.egold@lauterbach.com

Your Lauterbach Support Team
