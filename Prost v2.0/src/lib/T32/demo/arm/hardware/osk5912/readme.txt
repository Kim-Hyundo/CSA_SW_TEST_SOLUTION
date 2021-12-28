; --------------------------------------------------------------------------------
; @Title: OSK5912 Demo Scriptst - README
; @Description: -
; @Author: STK
; @Copyright: (C) 1989-2014 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: readme.txt 7026 2014-04-28 16:42:44Z kjmal $

OSK5912 Demo Files
==================

Linux Run/Stopp Mode Debugging:

  - Change to the Linux sub directory and run the script linux.cmm or linuxGDB.cmm

Multicore debugging:

  - Create two start links for a C54x debugger and an ARM debugger
  - Assign to the start link the configuration files config_dsp.t32 and config_arm.t32
  - Start the debuggers: At first the ARM debugger (master) and the the DSP debugger (slave)
  - Run first the script start_arm.cmm in the ARM debugger and than the script start start_dsp.cmm
  - In the Synch window of each debugger you can controll the master slave behaviour during debugging

Power Measurement:
  
  - Install your tools as shown on the pictures under PowerMeasurement\InstallationPictures.
  - Run the idemo.cmm file in the PowerMeasurement sub directory.
