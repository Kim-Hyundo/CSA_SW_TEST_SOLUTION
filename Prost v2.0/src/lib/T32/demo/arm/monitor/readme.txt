; --------------------------------------------------------------------------------
; @Title: TRACE32 ARM ROM Monitor - README
; @Description: -
; @Author: -
; @Copyright: (C) 1989-2014 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: readme.txt 7025 2014-04-28 15:42:01Z kjmal $

== ROM MONITOR FOR TRACE32/ARM
== 13.12.2002
==============================================================================

General Information
==============================================================================
- compatible to big and little endian systems via compiler option
- monitor runs in undefined opcode mode and uses an Undefined Instruction
  for software breakpoints
- by default, the monitor uses the irq mode for asynchronous breaks
  to use the fiq mode, set compiler option: -PD "USE_FIQ_MODE SETL {TRUE}"

Files
==============================================================================
MONITOR.S:   monitor kernel
*_SER.S:     serial port comminucation routines
*_INIT.S:    initialization routines
PID7T*.*     files for the PID7T arm development board
MAKEFILE.bat sample makefile

Usage
==============================================================================
- at monitor startup, it sends 255x 0xFF to the host computer
- to run user programs, the monitor needs some ram (60 bytes). Assign the
  base address for the monitor-ram to R13_undef. 
- if you encounter communication problems, try reducing the baud rate, 
  or enable hw-handshake (option octs=on + tx fifo disable on host system
  & enable/implement rts handshake in monitor source(see Preparation))

Preparation
==============================================================================
- open MONITOR.S and set (abt. line 60) the system-specific files for your
  target. One file with communication routines (ESI.S or *_SER.S) and one
  with system routines (*_INIT.S).
  
- *_SER.S files must implement following functions:
  - InitPort:   general Port Init, like reset, setting Baud rate, etc.
  - PrepCom:    disable rx interrupt for poll mode
  - PrepGo:     enable rx interrupt for asynchronous breaks
  - ReadStatus: returns 1, if there's a byte in the rx buffer
  - ReadByte:   waits for a byte in rx buffer and reads
  - WriteByte:  writes one byte to the serial port
  
- *_INIT.S files must implement following functions
  - SystemInit: general system init (e.g. copy vector table,
                set interrupt controller)
  - SystemClearInterrupt: for interrupt controller treatment after port-int
  
Communication via Eprom/FLASH Simulator
==============================================================================
- faster downloads (60..400 KByte/s)
- instead of *_SER.S, include ESI.S
- include the *_INIT.S needed for your target
- set a communication base address in ESI.S, line 1

Notes for PID7T
==============================================================================
- files: PID7T_SER.s and PID7T_INIT.s
- default port used by the monitor is Port A. Select port B via compiler
  option: -PD "PORTB SETL {TRUE}"


