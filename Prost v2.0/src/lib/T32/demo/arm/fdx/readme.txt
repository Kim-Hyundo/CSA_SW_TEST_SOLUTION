; --------------------------------------------------------------------------------
; @Title: TRACE32 ARM FDX Examples - README
; @Description: -
; @Author: -
; @Copyright: (C) 1989-2014 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: readme.txt 16075 2020-05-15 09:36:04Z rweiss $

FDX Examples:

1. Files
--------

Base Files:
t32fdx.c - provides routines to handle the FDX protocol and the target code interface
t32fdx.h - forward definitions and macros to handle channels
t32fdxarm.c - routines for physical transfer over the DCC channel (arm communication channel)
build.sh - example build script wich calls the makefile with the right defines
makefile - the makefiles for the project with generic settings

FDX Trace Example:
fdxtrace.c - example application for using a intrusive trace over FDX
fdxtrace.cmm - example script

FDX Target Example:
fdxtarget.c - example application for exchanging data with fdxhost.exe
fdxtarget.cmm - example script

Misc Files:
armcc - Includes the same files but build with the ARMCC compiler


2. First Steps
--------------

FDX Trace:
- Start T32 and load fdxtrace.cmm with parameter <RamStart>
- execute script and press go
- execute "fdx.off" and "fdx.list" to view the trace

FDX Target:
- adapt config.t32 to use API-Port 20000
- Start T32 and load fdxtarget.cmm with parameter <RamStart>
- execute script and press go

3. Further Information
----------------------

fdx_app.pdf - Application note for FDX
FDXSlides.pdf - General overview and short description