; ***************************************************************************
; ROM Monitor for the Infineon TriCore Family.
;
; Serial Interface Configuration for the TC1796 Family.
;
; Version Information
; $LastChangedDate: 2014-04-01 10:20:59 +0200 (Tue, 01 Apr 2014) $
; $LastChangedRevision: 6598 $
; $LastChangedBy: mobermeir $
;
; Supported devices
; TC1792, TC1796, TC1796ED.
; Probably all AUDO-NG and TC116x devices supported by this file.
;
; (c) Lauterbach Datentechnik GmbH
; ***************************************************************************


; ***************************************************************************
; Tested Hardware
; TriBoard-TC1796 ASC0 @ Port5,  9600 Baud 8 N 1
; TriBoard-TC1796 ASC0 @ Port5, 28800 Baud 8 N 1


; ***************************************************************************
; Important Notes
;
; This source file provides all TC1796 specific code for connecting the ROM
; Monitor to the Serial Interface.
; If any other configuration is required it is recommended to copy this file
; and make all necessary changes. This structure can be taken as reference.
;
; The ROM Monitor code is written for the TASKING Assembler v2.5rb. Other
; compilers or versions may require changes.
;
; Interrupt usage
; Real interrupt functionality is only required when the host software wants
; to take over control, e.g. on an asynchronous break. When already in debug
; mode, interrupts are used for checking if new data is available (receive)
; or write data has been transmitted.
;
; Watchdog usage
; A global disabling of any Watchdog timer is assumed to be done by the
; application before entering the Monitor by Reset. This can also be done
; in IF_Configure().
; If it is necessary to debug a system with any enabled watchdog, compile
; with the WATCHDOG_ENABLED define. When polling for the interface status,
; the watchdogs will be serviced.
;
; Interface Function Design and Usage
; The Interface Functions are called from the Monitor via a call instruction:
; - All Interface Functions have to be implemented at least with a minium
;   functionality to provide a proper return to the Monitor.
; - Within the Interface functions the upper register context can be used
;   without restrictions. Do not use the lower context registers!
; - Be aware that A11 contains the return address.
; - Parameters to or from the Interface Functions are passed via register D7.
; - Only use assembler, no C/C++ code). Using the stack is not recommended.



; ***************************************************************************
; Serial Interface Configuration
;
; TC1796 on TriBoard-TC1796
; - 20 MHz Oscillator, ByPass = On, f(sys) = 1/2 f(cpu)
; - Serial Interface ASC0 with 28800 Baud, 8 N 1
; - no error checking (partiy, framing, fifo overflow, ...)
; - Host connected to Port 5,
;   - pin P5.0 as RxD (input)
;   - pin P5.1 as TxD (output)
; For alternate configurations see IF_Configure.



; ***************************************************************************
; Monitor Helper Hunctions and Macros

; ===========================================================================
; Disable/ enable End-Of-Init Protection.
; Do not use the functionality provided by the compiler, it may use registers
; that interfer with the ROM Monitor.
;
; Parameter Register P0: 0 = disable protection,
;                        1 = enable protection

	.EXTERN SetEndOfInitProtection


; ===========================================================================
; Service Watchdog Timer(s).
; For the internal watchdog timer use the functionality provided by the ROM
; Monitor to avoid conflicts with registers by the Montior.

	.EXTERN ServiceInternalWatchdog

	.SDECL "ServiceWatchdog",CODE
	.SECT  "ServiceWatchdog"
	.ALIGN 4

SERVICE_WATCHDOG .MACRO
.IF @DEF(WATCHDOG_ENABLED)
	; service internal Watchdog
	call    ServiceInternalWatchdog

	; service external Watchdog(s)
	; ...
.ENDIF
	.ENDM


; ===========================================================================
; Monitor Status Register.
; The Monitor status register is used to make the internal status of the
; Monitor available to the outside. The outside can also flag the Monitor
; certain events.
;
; Bit description:     [0]  MONACT    Monitor active
;                   [31:1]  reserved  read and write 0

	.EXTERN MON_SR


; ===========================================================================
; Store 32 bit constant to memory or memory mapped register.

STORE .MACRO addr, const
	lea     a12,addr
	movh    d10,#@his(const)
	addi    d10,d10,#@los(const)
	st.w    [a12],d10
	.ENDM


; ***************************************************************************
; Monitor Interface Functions

; ===========================================================================
; Configure the Interface for use with the Monitor.
; The function is called by the Monitor once when entering after a target
; resetd occured. If the interface is set up by the target application, this
; function can be left empty.
; Additional functionality required for debugging (e.g. disabling the
; Watchdog timer(s), ...) can also be implemented here.

	.SDECL "IF_Configure",CODE
	.SECT  "IF_Configure"
	.ALIGN 4

	.GLOBAL IF_Configure

IF_Configure: .TYPE FUNC
	; set up GPIO Port 5 and ASC0 for communication between Monitor and Host

	; disable End-Of-Init protection
	mov.u   D7,#0
	call    SetEndOfInitProtection

	; GPIO Port 5 setup
	; pin P5.0 is input, P5.1 is output
	;   P5_IOCR0.PC0  = 0y0xxx    IN  No pull device
	;   P5_IOCR0.PC1  = 0y1x01    OUT Push-pull ALT1
	; pad driver mode
	;   P5_PDR.PDASC0 = Strong/Sharp
	STORE   P5_IOCR0,0x20209000;
	STORE   P5_PDR,  0x00000000;

	; ASC0 setup
	; Clock Signal generation for ASC modules (supports ASC0 and ASC1)
	;   ASC0_CLC.DISR  = Enabled    enable clock
	;   ASC0_CLC.RMC   = 1          f(ASC) = f(SYS) = 1/2 f(CPU)
	;   ASC0_PISEL.RIS = 0          RXD0A
	; Baud rate generation
	;   ASC0_CON.FDE = Disabled
	;   ASC0_CON.R   = Enabled     enable baud rate generation
	;   ASC0_CON.BRS = <divider>   Divide-by-2, Divide-by-3
	;   ASC0.BG      = <reload value>
	;   ASC Mode
	;   ASC0_CON.M    = 8-bit sync    8-bit asynchronous mode
	;   ASC0_CON.STP  = One           1 stop bit
	STORE   ASC0_CLC,  0x00000100;
	STORE   ASC0_PISEL,0x00000000;

	; example Baud rates
	; Baud =  9600:   Divide-By     Reload Value   ASC0_CON     ASC0_BG
	;                 Divide-by-2   32             0x00008011   0x00000020
	;                 Divide-by-3   20             0x0000a011   0x00000015
	; Baud = 14400:   Divide-By     Reload Value
	;                 Divide-by-2   21             0x00008011   0x00000015
	;                 Divide-by-3   13             0x0000a011   0x0000000d
	; Baud = 28800:   Divide-By     Reload Value
	;                 Divide-by-2   10             0x00008011   0x0000000a
	;                 Divide-by-3   6              0x0000a011   0x00000006
	STORE   ASC0_CON,0x00008011;
	STORE   ASC0_BG, 0x0000000a;


	; Interrupt setup
	; Configure Receive Interupt
	;   ASC0_RSRC.SETR = 0
	;   ASC0_RSRC.CLRR = 1        clear pending request
	;   ASC0_RSRC.SRR  = 0        read-only
	;   ASC0_RSRC.SRE  = 1        enable host to interrupt
	;   ASC0_RSRC.TOS  = TriCore
	;   ASC0_RSRC.SRPN = 0xff     highest priority for ASC0 receive interrupts
	;                             Interrupt handler for ASC0 must be configured
	;                             to use the very same interrupt priority!
	; Configure Error Interupt
	;   ASC0_RSRC.SETR = 0
	;   ASC0_RSRC.CLRR = 1        clear pending request
	;   ASC0_RSRC.SRR  = 0        read-only
	;   ASC0_RSRC.SRE  = 0        enable host to interrupt
	;   ASC0_RSRC.TOS  = TriCore
	;   ASC0_RSRC.SRPN = 0        do not generate error interrupts for ASC0
	STORE   ASC0_RSRC,0x000050ff;
	STORE   ASC0_ESRC,0x00004000;

	; enable End-Of-Init protection
	mov.u   D7,#1
	call    SetEndOfInitProtection

	ret
	.SIZE IF_Configure,*-IF_Configure


; ===========================================================================
; Flush Input Queue.
; Discard data in receive buffer and clear error flags.
; The function is called once after entering the Monitor by any event to
; discard all data still in receive buffer, and to clear any pending error
; flags.

	.SDECL "IF_FlushInputQueue",CODE
	.SECT  "IF_FlushInputQueue"
	.ALIGN 4

	.GLOBAL IF_FlushInputQueue

IF_FlushInputQueue: .TYPE FUNC
	SERVICE_WATCHDOG

	imask   e12,#1,#14,#1
	ldmst   ASC0_ESRC,e12    ; ASC0_ESRC.CLRR = 0    clear ASC0 transmission error flag
	ldmst   ASC0_RSRC,e12    ; ASC0_RSRC.CLRR = 0    clear ASC0 receive data available flag

	ret
	.SIZE IF_FlushInputQueue,*-IF_FlushInputQueue


; ===========================================================================
; Flush Output Queue.
; Discard data in output buffer and clear error flags.
; The function is called once before leaving the Monitor for a Go or Step
; event to discard all data still in receive buffer, and to clear any pending
; service requests or error flags.

	.SDECL "IF_FlushOutputQueue",CODE
	.SECT  "IF_FlushOutputQueue"
	.ALIGN 4

	.GLOBAL IF_FlushOutputQueue

IF_FlushOutputQueue: .TYPE FUNC
	SERVICE_WATCHDOG

	; nothing to be done for ASC0
	nop

	ret
	.SIZE IF_FlushOutputQueue,*-IF_FlushOutputQueue


; ===========================================================================
; Receive data byte from Monitor interface.
; Receive data is moved into D7[7:0]. Bits D7[31:8] must be set 0.

	.SDECL "IF_ReceiveByte",CODE
	.SECT  "IF_ReceiveByte"
	.ALIGN 4

	.GLOBAL IF_ReceiveByte

IF_ReceiveByte .TYPE FUNC
__getreceivestatus:
	SERVICE_WATCHDOG
	; get status from ASC
	ld.w   d13,ASC0_RSRC
	jz.t   d13:#13,__getreceivestatus

	; data available, clear Receive Interrupt Request Flag
	imask   e12,#1,#14,#1
	ldmst   ASC0_RSRC,e12    ; ASC0_RSRC.CLRR = 0

	; get byte from receive buffer
	; ASC hardware assures that bits [31:8] are always 0
	ld.bu   D7,ASC0_RBUF

	ret
	.SIZE IF_ReceiveByte,*-IF_ReceiveByte


; ===========================================================================
; Transmit data byte to Monitor interface.
; Transmit data is expected in D7[7:0].

	.SDECL "IF_TransmitByte",CODE
	.SECT  "IF_TransmitByte"
	.ALIGN 4

	.GLOBAL IF_TransmitByte

IF_TransmitByte .TYPE FUNC
	; write byte to transmit buffer
	; ASC hardware ignorest bits [31:8]
	st.b    ASC0_TBUF,D7

__gettransmitstatus:
	SERVICE_WATCHDOG
	; get status from ASC
	ld.w   d13,ASC0_TSRC
	jz.t   d13:#13,__gettransmitstatus

	; data sent, clear Transmit Interrupt Request Flag
	imask   e12,#1,#14,#1
	ldmst   ASC0_TSRC,e12    ; ASC0_TSRC.CLRR = 0

	ret
	.SIZE IF_TransmitByte,*-IF_TransmitByte



; ***************************************************************************
; end serrom_tc1796.asm
