; ***************************************************************************
; ROM Monitor
; for the Infineon TriCore Family.
;
; Version Information
; $LastChangedDate: 2014-04-01 10:20:59 +0200 (Tue, 01 Apr 2014) $
; $LastChangedRevision: 6598 $
; $LastChangedBy: mobermeir $
;
; (c) Lauterbach Datentechnik GmbH
; ***************************************************************************


; ***************************************************************************
; Version History
; V0.10  2008-03-01  Major features working.
; V0.00  2008-01-22  Initial Version

	.DEFINE VERSION 'V0.10   '    ; must have 8 characters
	.DEFINE TYPE    'SER     '    ; must have 8 characters


; ***************************************************************************
; Important Notes
;
; This source file does not contain any interface specific code. Files with
; interface specific code are provided separately.
;
; The ROM Monitor code is written for the TASKING Assembler v2.5rb. Other
; compilers or versions may require changes.



; ***************************************************************************
; External Interface Functions

	.EXTERN IF_Configure
	.EXTERN IF_FlushInputQueue
	.EXTERN IF_FlushOutputQueue
	.EXTERN IF_ReceiveByte
	.EXTERN IF_TransmitByte



; ***************************************************************************
; Global Register Usage
	; message registers, GLOBAL valid
	.DEFINE CS  'D0'    ; Message Checksum
	.DEFINE LEN 'D1'    ; Message Length (probably ignored by Monitor)
	.DEFINE ID  'D2'    ; Message ID
	.DEFINE CMD 'D3'    ; Message Command

	; access registers, only valid within DoAccess
	.DEFINE ACC_AC  'D4'     ; Access class
	.DEFINE ACC_WDT 'D5'     ; Access witdh
	.DEFINE ACC_LEN 'D6'     ; Access length
	.DEFINE ACC_ADR 'D14'    ; Access address

	; parameter registers
	.DEFINE P0 'D7'    ; Parameter 1 (in and out) for function call

	; other
	; - do not use A11 since it is used for return to calling function
	;   or exception handler



; ***************************************************************************
; Monitor Data

; ===========================================================================
; Monitor Information.
; Contains Name, Type and Version of Monitor.

	.SDECL ".rodata.Monitor",DATA
	.SECT  ".rodata.Monitor"
	.ALIGN 4

	.GLOBAL MON_Info

MON_Info: .TYPE OBJECT
	.ASCII "TRACE32 MTC     ","TYPE","VERSION","\0"
	.SIZE MON_Info,*-MON_Info


; ===========================================================================
; Various Data

	.SDECL ".zdata.Monitor",DATA
	.SECT  ".zdata.Monitor"
	.ALIGN 4

	.GLOBAL MON_SR

; Monitor Status Register.
; The Monitor status register is used to make the internal status of the
; Monitor available to the outside. The outside can also flag the Monitor
; certain events.
;
; Bit description:     [0] MONACT Monitor active
;                   [31:1] reserved, read and write 0

MON_SR: .TYPE OBJECT
	.WORD 0x00000000
	.SIZE MON_SR,4



; ***************************************************************************
; Gobal helper macros

; ===========================================================================
; Move 32 bit constant to data register.
MOVD.W .MACRO dx, const
	movh    dx,#@his(const)
	addi    dx,dx,#@los(const)
	.ENDM



; ***************************************************************************
; Monitor helper functions

; ===========================================================================
; Enable or disable End-Of-Init protection.
;
; Parameter Register P0: 0 = disable protection,
;                        1 = enable protection

	.SDECL "SetEndOfInitProtection",CODE
	.SECT  "SetEndOfInitProtection"
	.ALIGN 4

	.GLOBAL SetEndOfInitProtection

SetEndOfInitProtection: .TYPE FUNC
	ld.w    d14,WDT_CON0
	ld.w    d15,WDT_CON1

	; unlock WDTCON0
	MOVD.W  d12,0xffffff01
	and     d14,d12           ; WDT_CON0 &= 0xffffff01
	or      d14,d14,#0xf0     ; WDT_CON0 |= WDTHPW1
	and     d13,d15,#0x0c     ; WDTHPW0 = WDT_CON1 & 0x0000000c
	or      d14,d14,d13       ; WDT_CON0 |= WDTHPW0
	st.w    WDT_CON0,d14

	; clear End-Of-Init Bit
	MOVD.W  d12,0xfffffff0
	and     d14,d12           ; WDT_CON0 &= 0xfffffff0 (clears End-Of-Init protection)
	or      d14,d14,#0x02     ; set LOCK bit
	or      d14,d14,P0        ; set or clear ENDINIT bit
	isync
	st.w    WDT_CON0,d14
	ld.w    d14,WDT_CON0      ; necessary dummy read

	ret
	.SIZE SetEndOfInitProtection,*-SetEndOfInitProtection


; ===========================================================================
; Service Internal Watchdog.
; ### untested - tbd. ###

	.SDECL "ServiceInternalWatchdog",CODE
	.SECT  "ServiceInternalWatchdog"
	.ALIGN 4

	.GLOBAL ServiceInternalWatchdog

ServiceInternalWatchdog: .TYPE FUNC
	ld.w    d14,WDT_CON0
	ld.w    d15,WDT_CON1

	; unlock WDTCON0
	MOVD.W  d12,0xffffff01
	and     d14,d12           ; WDT_CON0 &= 0xffffff01
	or      d14,d14,#0xf0     ; WDT_CON0 |= WDTHPW1
	and     d13,d15,#0x0c     ; WDTHPW0 = WDT_CON1 & 0x0000000c
	or      d14,d14,d13       ; WDT_CON0 |= WDTHPW0
	st.w    WDT_CON0,d14

	; clear End-Of-Init Bit
	MOVD.W  d12,0xfffffff0
	and     d14,d12           ; WDT_CON0 &= 0xfffffff0 (clears End-Of-Init protection)
	or      d14,d14,#0x03     ; set LOCK and ENDINIT bit
	isync
	st.w    WDT_CON0,d14
	ld.w    d14,WDT_CON0      ; necessary dummy read

	ret
	.SIZE ServiceInternalWatchdog,*-ServiceInternalWatchdog


; ===========================================================================
; Read Byte (8 Bit) from Monitor Interface
; Read data is moved into P0[7:0], checksum CS is updated.

	.SDECL "IF_ReadByte",CODE
	.SECT  "IF_ReadByte"
	.ALIGN 4

IF_ReadByte .TYPE FUNC
	call    IF_ReceiveByte
	add     CS,P0

	ret
	.SIZE IF_ReadByte,*-IF_ReadByte


; ===========================================================================
; Read HWord (16 bit) from Monitor Interface.
; Read data is moved into P0[15:0], checksum CS is updated.

	.SDECL "IF_ReadHWord",CODE
	.SECT  "IF_ReadHWord"
	.ALIGN 4

IF_ReadHWord: .TYPE FUNC
	; bits [15:8]
	call    IF_ReceiveByte
	add     CS,P0
	mov     d14,P0

	; bits [7:0]
	call    IF_ReceiveByte
	add     CS,P0
	sh      P0,P0,#8
	or      d14,P0

	mov     P0,d14

	ret
	.SIZE IF_ReadHWord,*-IF_ReadHWord


; ===========================================================================
; Read Word (32 bit) from Monitor Interface.
; Read data is moved into P0[31:0], checksum CS is updated.

	.SDECL "IF_ReadWord",CODE
	.SECT  "IF_ReadWord"
	.ALIGN 4

IF_ReadWord: .TYPE FUNC
	; bits [31:24]
	call    IF_ReceiveByte
	add     CS,P0
	mov     d14,P0

	; bits [23:16]
	call    IF_ReceiveByte
	add     CS,P0
	sh      P0,P0,#8
	or      d14,P0

	; bits [15:8]
	call    IF_ReceiveByte
	add     CS,P0
	sh      P0,P0,#16
	or      d14,P0

	; bits [7:0]
	call    IF_ReceiveByte
	add     CS,P0
	sh      P0,P0,#24
	or      d14,P0

	mov     P0,d14

	ret
	.SIZE IF_ReadWord,*-IF_ReadWord


; ===========================================================================
; Read Address from Monitor Interface.
; Address comes in 32 Bit Big Endian from Host.
; Read data is moved into P0[31:0], checksum CS is updated.

	.SDECL "IF_ReadAddress",CODE
	.SECT  "IF_ReadAddress"
	.ALIGN 4

IF_ReadAddress: .TYPE FUNC
	; bits [31:24]
	call    IF_ReceiveByte
	add     CS,P0
	sh      P0,P0,#24
	mov     d14,P0

	; bits [23:16]
	call    IF_ReceiveByte
	add     CS,P0
	sh      P0,P0,#16
	or      d14,P0

	; bits [15:8]
	call    IF_ReceiveByte
	add     CS,P0
	sh      P0,P0,#8
	or      d14,P0

	; bits [7:0]
	call    IF_ReceiveByte
	add     CS,P0
	or      d14,P0

	mov     P0,d14

	ret
	.SIZE IF_ReadAddress,*-IF_ReadAddress


; ===========================================================================
; Write Byte (8 Bit) to Monitor Interface.
; Write data is in P0[7:0], checksum CS is updated.

	.SDECL "IF_WriteByte",CODE
	.SECT  "IF_WriteByte"
	.ALIGN 4

IF_WriteByte: .TYPE FUNC
	add     CS,P0
	call    IF_TransmitByte

	ret
	.SIZE IF_WriteByte,*-IF_WriteByte


; ===========================================================================
; Write HWord (16 bit) to Monitor interface.
; Write data is in P0[15:0], checksum CS is updated.

	.SDECL "IF_WriteHWord",CODE
	.SECT  "IF_WriteHWord"
	.ALIGN 4

IF_WriteHWord .TYPE FUNC
	mov     d14,P0    ; free parameter register for new function calls

	; bits [15:8]
	and     P0,d14,#0xff
	add     CS,P0
	call    IF_TransmitByte

	; bits [7:0]
	sh      P0,d14,#-8
	and     P0,P0,#0xff
	add     CS,P0
	call    IF_TransmitByte

	ret
	.SIZE IF_WriteHWord,*-IF_WriteHWord


; ===========================================================================
; Write Word (32 bit) to Monitor interface.
; Write data is in P0[31:0], checksum CS is updated.

	.SDECL "IF_WriteWord",CODE
	.SECT  "IF_WriteWord"
	.ALIGN 4

IF_WriteWord .TYPE FUNC
	mov     d14,P0    ; free parameter register for new function calls

	; bits [31:24]
	and     P0,d14,#0xff
	add     CS,P0
	call    IF_TransmitByte

	; bits [23:16]
	sh      P0,d14,#-8
	and     P0,P0,#0xff
	add     CS,P0
	call    IF_TransmitByte

	; bits [15:8]
	sh      P0,d14,#-16
	and     P0,P0,#0xff
	add     CS,P0
	call    IF_TransmitByte

	; bits [7:0]
	sh      P0,d14,#-24
	and     P0,P0,#0xff
	add     CS,P0
	call    IF_TransmitByte

	ret
	.SIZE IF_WriteWord,*-IF_WriteWord


; ===========================================================================
; Decode address stored in PCXI pointer format.
; Content PCXI pointer expected in dx, decoded address is returned in dx.

GetAddressFromPCXI .MACRO dx
	mov     d11,dx
	movh    d12,#0x000f
	and     dx,d12
	sh      dx,dx,#12
	mov.u   d12,#0xffff
	and     d11,d12
	sh      d11,#6
	or      dx,d11
	.ENDM


; ===========================================================================
; Checked write to CSFR.
; Compare addr and csfr to check for write request to given CSFR.
; Value to write is expected in value.

CSFR_CheckWrite .MACRO addr, csfr, value
	mov.u   d15,#csfr
	jne     addr,d15,__continue
	mtcr    #csfr,value    ; write to CSFR
	isync
	j       _WriteMemoryCSFRLoopEnd
__continue:
	.ENDM


; ===========================================================================
; Checked read from CSFR.
; Compare addr and csfr to check for write request to given CSFR.
; Value to write is expected in _value_.

CSFR_CheckRead .MACRO addr, csfr, value
	mov.u   d15,#csfr
	jne     addr,d15,__continue
	mfcr    value,#csfr    ; write _value_ to CSFR
	j       _ReadMemoryCSFRLoopEnd
__continue:
	.ENDM


; ===========================================================================
; Read Message Checksum from Host.
; Check Host checksum to local checksum. If they do not match,
; leave and wait for new message.

MSG_ReadChecksum .MACRO
	; get checksum high byte
	call    IF_ReceiveByte
	sh      d10,P0,#8

	; get checksum low byte
	call    IF_ReceiveByte
	or      d10,P0

	; compare
	jne     CS,d10,_ReceiveMessage    ; checksum error
	.ENDM


; ===========================================================================
; Start sending a new message:
; - send start token and get acknowlegement
; - sent message length and ID (expected in registers LEN and ID)
; - start computing checksum
; If message is not acknowlegded, leave and wait for new message.

MSG_SendHeader .MACRO
	; send message start token
	mov.u   P0,#0x20
	call    IF_TransmitByte

	; get acknowledgement from host
	call    IF_ReceiveByte
	mov.u   d11,#0x3f
	jne     P0,d11,_ReceiveMessage
	; message acknowledged by Host

	; send message length
	mov     CS,LEN
	mov     P0,LEN
	call    IF_TransmitByte

	; send Message ID
	add     CS,ID
	mov     P0,ID
	call    IF_TransmitByte
	.ENDM


; ===========================================================================
; Send message checksum to Host.
; This finishes the current message.

MSG_SendChecksum .MACRO
	; send checksum high byte
	mov     P0,CS
	sh      P0,#-8
	call    IF_TransmitByte

	; send checksum low byte
	mov     P0,CS
	call    IF_TransmitByte
	.ENDM



; ***************************************************************************
; Monitor Code

	.SDECL "Monitor",CODE
	.SECT  "Monitor"
	.ALIGN 4

; export labels called by application
	.GLOBAL Monitor_EntryReset
	.GLOBAL Monitor_EntryBusError
	.GLOBAL Monitor_EntryTrap
	.GLOBAL Monitor_EntryBreak


Monitor: .TYPE FUNC
	; -----------------------------------------------------------------------
	; Monitor Entry Points

	; Monitor entry on reset
	; - enable Debug Subsystem (OCDS-L1)
	; - configure Monitor Interface
Monitor_EntryReset:
	mov.u   ID,#0x40    ; set Monitor entry reason

	; enable OCDS-L1 Debug System
	mov.u   d10,#0xa1
	st.w    CBS_OEC,d10
	mov.u   d10,#0x5e
	st.w    CBS_OEC,d10
	mov.u   d10,#0xa1
	st.w    CBS_OEC,d10
	mov.u   d10,#0x5e
	st.w    CBS_OEC,d10

	; setup Software Breakpoint 0 Interrupt
	;   CPU_SBSRC0.SRPN = 0xff  highest priority
	;   CPU_SBSRC0.TOS  = 0     CPU
	;   CPU_SBSRC0.SRE  = 1     enable
	;   CPU_SBSRC0.CLRR = 1     disable pending request
	MOVD.W  d10,CPU_SBSRC
	mov.a   a12,d10
	mov.u   d10,#0x10ff
	st.w    [a12],d10

	; configure Monitor Interface
	call    IF_Configure
	j       _PrepareMonitor


	; Monitor entry on TRAP
Monitor_EntryTrap:
	mov.u   ID,#0x30    ; set Monitor entry reason
	j       _SendBurst


	; Monitor entry when Bus Error occured (e.g. memory access failed)
Monitor_EntryBusError:
	mov.u   ID,#0x20    ; set Monitor entry reason
	j       _SendBurst


	; Monitor entry on Asynchronous Break (Host Software),
	; Software- or On-chip Breakpoint
Monitor_EntryBreak:
	mov.u   ID,#0x10    ; set Monitor entry reason


	; -----------------------------------------------------------------------
	; start communication with Host

	; send burst to host
_SendBurst:
	mov.u   d0,#0x100
	mov.a   a12,d0       ; loop counter
	mov.u   P0,#0xff
_LoopBurstToken:
	call    IF_TransmitByte
	add     d15,#-1
	loop    a12,_LoopBurstToken


	; enable Monitor for full CPU access
_PrepareMonitor:
	; set Monitor active flag
	imask   e12,#1,#0,#1
	ldmst   MON_SR,e12    ; MON_SR.MONACT = 1

	; Global Write enable (for write access to A0, A1, A8, A9)
	mfcr    d10,#PSW
	or      d10,d10,#0x100
	mtcr    #PSW,d10


	; Flush Input Queue, Host may still send data
_FlushInputQueue:
	call    IF_FlushInputQueue

	; send break command to host
	mov.u   P0,#0x00
	call    IF_TransmitByte

	mov.u   LEN,#0x00
	MSG_SendHeader
	MSG_SendChecksum


	; -----------------------------------------------------------------------
	; receive new message from Host
_ReceiveMessage:
	mov.u   d11,#0x20    ; Start Token
_PollForStartToken:
	call    IF_ReceiveByte
	jne     P0,d11,_PollForStartToken

	; get message header
	mov.u   P0,#0x3f
	call    IF_TransmitByte    ; acknowledge message start

	; ### really required ??? ###
	mov.u   CS,#0x00           ; clear checksum
	mov.u   ID,#0x00           ; clear Message ID

	call    IF_ReadByte        ; Message Length
	mov     LEN,P0
	call    IF_ReadByte        ; Message ID
	AND     ID,P0,#0x0f        ; only lower nibble is used
	call    IF_ReadByte        ; Message Command
	mov     CMD,P0

_DoCommand:
	; decode CMD
	jeq     CMD,#0,_DoNOP
	jeq     CMD,#1,_GetAccessParameters
	jeq     CMD,#2,_GetAccessParameters
	jeq     CMD,#3,_GetAccessParameters
	jeq     CMD,#4,_GetAccessParameters
	jeq     CMD,#5,_Go
	jeq     CMD,#6,_Step
	jeq     CMD,#7,_DoGoRAM

	j       _NotImplemented    ; CMD out of range

	; 1 <= CMD <= 6
	; Memory/ Register Access, Go/ Step
_GetAccessParameters:
	; access class and width
	call    IF_ReadByte
	mov     ACC_AC,P0
	call    IF_ReadByte
	mov     ACC_WDT,P0

	; access address
	call    IF_ReadAddress
	mov     ACC_ADR,P0

	; access length
	call    IF_ReadByte
	mov     ACC_LEN,P0
	mov.u   d9,#0xff
	jeq     ACC_LEN,d9,_ReceiveMessage    ; invalid length, abort

	; compare with intermediate checksum from host (only low byte valid)
	nop                        ; workaround CPU_TC.094
	call    IF_ReceiveByte           ; checksum from host
	and     d9,CS,#0xff              ; only compare against low byte of local checksum
	jne     d9,P0,_ReceiveMessage    ; invalid header, abort
	add     CS,P0                    ; required for consecutive checksum tests

	; process access
	jeq     CMD,#1,_ReadMemory
	jeq     CMD,#2,_WriteMemory
	jeq     CMD,#3,_ReadRegister
	jeq     CMD,#4,_WriteRegister


	; -----------------------------------------------------------------------
	; Command Implementation

	; function not implemented (default)
_NotImplemented
	nop     ; workaround CPU_TC.065
	j       _ReceiveMessage


	; -----------------------------------------------------------------------
	; prepare memory in case of ESICON
	; not implemented for TriCore, redirected to DoNOP
_DoGoRAM:
	; j       _DO NOP


	; -----------------------------------------------------------------------
	; reply to PING message
_DoNOP:
	MSG_ReadChecksum

	; send empty message
	mov.u   LEN,#0x00
	MSG_SendHeader
	MSG_SendChecksum

	j       _ReceiveMessage


	; -----------------------------------------------------------------------
	; read data from memory
	; allow access widths: 1, 2, 4
	; unaligned acceses and illegal addresses will result in trap/ bus error
_ReadMemory:
	MSG_ReadChecksum

	mov     LEN,ACC_LEN
	MSG_SendHeader

	; all access widths != 4 are treated as accesses to RAM
	jne     ACC_WDT,#4,_ReadMemoryRAM

	; check if read from a Core Special Function Register
	; CSFR area is 0xF7E1xxxx (0xF7E1 is core_base and chip dependent)
	movh    d10,#0xffff
	and     d11,ACC_ADR,d10
	movh    d10,#core_base
	jne     d10,d11,_ReadMemoryRAM    ; no read from CSFR

	; write to Core Special Function Register
	; write of 32 bit values is allowed only
_ReadMemoryCSFR:
	mov.u   d11,#0xffff
	and     d10,ACC_ADR,d11    ; cut CSFR offset

	; read each CSFR separately (there is no MFCR da,db instruction)
	CSFR_CheckRead d10, DBGSR, P0      ; Debug Status Register
	CSFR_CheckRead d10, EXEVT, P0      ; External Break Input Event Specifier
	CSFR_CheckRead d10, CREVT, P0      ; Emulator Resource Protection Event Specifier
	CSFR_CheckRead d10, SWEVT, P0      ; Software Break Event Specifier
	CSFR_CheckRead d10, TR0EVT, P0     ; Trigger Event 0 Specifier
	CSFR_CheckRead d10, TR1EVT, P0     ; Trigger Event 1 Specifier
	CSFR_CheckRead d10, CPR0_0L, P0    ; Code Seg. Prot. Reg. 0, Set 0, lower
	CSFR_CheckRead d10, CPR0_0U, P0    ; Code Seg. Prot. Reg. 0, Set 0, upper
	CSFR_CheckRead d10, CPR0_1L, P0    ; Code Seg. Prot. Reg. 1, Set 0, lower
	CSFR_CheckRead d10, CPR0_1U, P0    ; Code Seg. Prot. Reg. 1, Set 0, upper
	CSFR_CheckRead d10, CPR1_0L, P0    ; Code Seg. Prot. Reg. 0, Set 1, lower
	CSFR_CheckRead d10, CPR1_0U, P0    ; Code Seg. Prot. Reg. 0, Set 1, upper
	CSFR_CheckRead d10, CPR1_1L, P0    ; Code Seg. Prot. Reg. 1, Set 1, lower
	CSFR_CheckRead d10, CPR1_1U, P0    ; Code Seg. Prot. Reg. 1, Set 1, upper
	CSFR_CheckRead d10, CPM0, P0       ; Code Protection Mode Register, Set 0
	CSFR_CheckRead d10, CPM1, P0       ; Code Protection Mode Register, Set 1
	CSFR_CheckRead d10, DPR0_0L, P0    ; Data Seg. Prot. Reg. 0, Set 0, lower
	CSFR_CheckRead d10, DPR0_0U, P0    ; Data Seg. Prot. Reg. 0, Set 0, upper
	CSFR_CheckRead d10, DPR0_1L, P0    ; Data Seg. Prot. Reg. 1, Set 0, lower
	CSFR_CheckRead d10, DPR0_1U, P0    ; Data Seg. Prot. Reg. 1, Set 0, upper
	CSFR_CheckRead d10, DPR0_2L, P0    ; Data Seg. Prot. Reg. 2, Set 0, lower
	CSFR_CheckRead d10, DPR0_2U, P0    ; Data Seg. Prot. Reg. 2, Set 0, upper
	CSFR_CheckRead d10, DPR0_2U, P0    ; Data Seg. Prot. Reg. 2, Set 0, upper
	CSFR_CheckRead d10, DPR0_3L, P0    ; Data Seg. Prot. Reg. 3, Set 0, lower
	CSFR_CheckRead d10, DPR0_3U, P0    ; Data Seg. Prot. Reg. 3, Set 0, upper
	CSFR_CheckRead d10, DPR1_0L, P0    ; Data Seg. Prot. Reg. 0, Set 1, lower
	CSFR_CheckRead d10, DPR1_0U, P0    ; Data Seg. Prot. Reg. 0, Set 1, upper
	CSFR_CheckRead d10, DPR1_1L, P0    ; Data Seg. Prot. Reg. 1, Set 1, lower
	CSFR_CheckRead d10, DPR1_1U, P0    ; Data Seg. Prot. Reg. 1, Set 1, upper
	CSFR_CheckRead d10, DPR1_2L, P0    ; Data Seg. Prot. Reg. 2, Set 1, lower
	CSFR_CheckRead d10, DPR1_2U, P0    ; Data Seg. Prot. Reg. 2, Set 1, upper
	CSFR_CheckRead d10, DPR1_3L, P0    ; Data Seg. Prot. Reg. 3, Set 1, lower
	CSFR_CheckRead d10, DPR1_3U, P0    ; Data Seg. Prot. Reg. 3, Set 1, upper
	CSFR_CheckRead d10, DPM0, P0       ; Data Protection Mode Register, Set 0
	CSFR_CheckRead d10, DPM1, P0       ; Data Protection Mode Register, Set 1
	CSFR_CheckRead d10, PCXI, P0       ; Previous Context Info Register
	CSFR_CheckRead d10, PSW, P0        ; Program Status Word
	CSFR_CheckRead d10, PC, P0         ; Program Counter
	CSFR_CheckRead d10, SYSCON, P0     ; System Configuration Control Register
	CSFR_CheckRead d10, CPU_ID, P0     ; CPU Identification Register
	CSFR_CheckRead d10, BIV, P0        ; Interrupt Vector Table
	CSFR_CheckRead d10, BTV, P0        ; Trap Vector Table Pointer.
	CSFR_CheckRead d10, ISP, P0        ; Interrupt Stack Pointer
	CSFR_CheckRead d10, ICR, P0        ; Interrupt Unit Control Register
	CSFR_CheckRead d10, FCX, P0        ; Free CSA List Head Pointer
	CSFR_CheckRead d10, LCX, P0        ; Free CSA List Limit Pointer
	CSFR_CheckRead d10, DMS, P0        ; Debug Monitor Start Address Register
	CSFR_CheckRead d10, DCX, d12        ; Debug Context Save Area Pointer

	;unsupported CSFR, read zero
	mov.u     P0,#0x0000

_ReadMemoryCSFRLoopEnd:
	call    IF_WriteWord      ; write read data to host
	add     ACC_ADR,#4        ; increment address
	add     ACC_LEN,#-4       ; decrement length
	mov.u   d10,#0
	jne     ACC_LEN,d10,_ReadMemoryCSFR
	j       _ReadMemoryEnd


	; read from RAM
_ReadMemoryRAM:
	mov.a   a12,ACC_ADR    ; start address
	mov.u   d10,#0         ; read loop exit condition

	jeq     ACC_WDT,#0x1,_LoopReadMemoryByte
	jeq     ACC_WDT,#0x2,_LoopReadMemoryHWord
	jeq     ACC_WDT,#0x4,_LoopReadMemoryWord

_LoopReadMemoryByte:
	ld.bu   P0,[a12]
	call    IF_WriteByte       ; write read data to host
	add.a   a12,#1             ; increment address
	add     ACC_LEN,#-1        ; decrement length
	jne     ACC_LEN,d10,_LoopReadMemoryByte
	j       _ReadMemoryEnd

_LoopReadMemoryHWord:
	ld.hu   P0,[a12]
	call    IF_WriteHWord    ; write read data to host
	add.a   a12,#2             ; increment address
	add     ACC_LEN,#-2        ; decrement length
	jne     ACC_LEN,d10,_LoopReadMemoryHWord
	j       _ReadMemoryEnd

_LoopReadMemoryWord:
	ld.w    P0,[a12]
	call    IF_WriteWord    ; write read data to host
	add.a   a12,#4            ; increment address
	add     ACC_LEN,#-4       ; decrement length
	jne     ACC_LEN,d10,_LoopReadMemoryWord


_ReadMemoryEnd:
	MSG_SendChecksum
	j       _ReceiveMessage


	; -----------------------------------------------------------------------
	; write data to memory
	; allow access widths: 1, 2, 4
	; unaligned acceses and illegal addresses will result in trap/ bus error
_WriteMemory:
	; all access widths != 4 are treated as accesses to RAM
	jne     ACC_WDT,#4,_WriteMemoryRAM

	; check if write to a Core Special Function Register
	; CSFR area is 0xF7E1xxxx (0xF7E1 is core_base and chip dependent)
	movh    d10,#0xffff
	and     d11,ACC_ADR,d10
	movh    d10,#core_base
	jeq     d10,d11,_WriteMemoryCSFR    ; write to CSFR

	; check for write to end-of-init protected register
	; - address is 0xfxxxxxxx
	; - access length == 4
	; - access width  == 4 (already checked above)
	movh    d10,#0xf000
	and     d11,ACC_ADR,d10
	jne     d10,d11,_WriteMemoryRAM        ; no write to End-Of-InitProtected register
	jne     ACC_LEN,#4,_WriteMemoryRAM     ; no write to End-Of-InitProtected register


	; write to End-Of-InitProtected Register
_WriteMemoryEndOfInitRegister:
	nop                        ; workaround CPU_TC.094
	call    IF_ReadWord      ; get write data from host
	mov     d12,P0

	mov.u   P0,#0              ; disable End-Of-Init Protection
	call    SetEndOfInitProtection

	mov.a   a12,ACC_ADR        ; write to protected register
	st.w    [a12],d12

	mov.u   P0,#1              ; re-enable End-Of-Init Protection
	call    SetEndOfInitProtection
	j       _WriteMemoryEnd


	; write to Core Special Function Register
	; write of 32 bit values is allowed only
_WriteMemoryCSFR:
	call    IF_ReadWord      ; get write data from host
	mov.u   d11,#0xffff
	and     d10,ACC_ADR,d11    ; cut CSFR offset

	; write each CSFR separately (there is no MTCR da,db instruction)
	CSFR_CheckWrite d10, DBGSR, P0      ; Debug Status Register
	CSFR_CheckWrite d10, EXEVT, P0      ; External Break Input Event Specifier
	CSFR_CheckWrite d10, CREVT, P0      ; Emulator Resource Protection Event Specifier
	CSFR_CheckWrite d10, SWEVT, P0      ; Software Break Event Specifier
	CSFR_CheckWrite d10, TR0EVT, P0     ; Trigger Event 0 Specifier
	CSFR_CheckWrite d10, TR1EVT, P0     ; Trigger Event 1 Specifier
	CSFR_CheckWrite d10, CPR0_0L, P0    ; Code Seg. Prot. Reg. 0, Set 0, lower
	CSFR_CheckWrite d10, CPR0_0U, P0    ; Code Seg. Prot. Reg. 0, Set 0, upper
	CSFR_CheckWrite d10, CPR0_1L, P0    ; Code Seg. Prot. Reg. 1, Set 0, lower
	CSFR_CheckWrite d10, CPR0_1U, P0    ; Code Seg. Prot. Reg. 1, Set 0, upper
	CSFR_CheckWrite d10, CPR1_0L, P0    ; Code Seg. Prot. Reg. 0, Set 1, lower
	CSFR_CheckWrite d10, CPR1_0U, P0    ; Code Seg. Prot. Reg. 0, Set 1, upper
	CSFR_CheckWrite d10, CPR1_1L, P0    ; Code Seg. Prot. Reg. 1, Set 1, lower
	CSFR_CheckWrite d10, CPR1_1U, P0    ; Code Seg. Prot. Reg. 1, Set 1, upper
	CSFR_CheckWrite d10, CPM0, P0       ; Code Protection Mode Register, Set 0
	CSFR_CheckWrite d10, CPM1, P0       ; Code Protection Mode Register, Set 1
	CSFR_CheckWrite d10, DPR0_0L, P0    ; Data Seg. Prot. Reg. 0, Set 0, lower
	CSFR_CheckWrite d10, DPR0_0U, P0    ; Data Seg. Prot. Reg. 0, Set 0, upper
	CSFR_CheckWrite d10, DPR0_1L, P0    ; Data Seg. Prot. Reg. 1, Set 0, lower
	CSFR_CheckWrite d10, DPR0_1U, P0    ; Data Seg. Prot. Reg. 1, Set 0, upper
	CSFR_CheckWrite d10, DPR0_2L, P0    ; Data Seg. Prot. Reg. 2, Set 0, lower
	CSFR_CheckWrite d10, DPR0_2U, P0    ; Data Seg. Prot. Reg. 2, Set 0, upper
	CSFR_CheckWrite d10, DPR0_2U, P0    ; Data Seg. Prot. Reg. 2, Set 0, upper
	CSFR_CheckWrite d10, DPR0_3L, P0    ; Data Seg. Prot. Reg. 3, Set 0, lower
	CSFR_CheckWrite d10, DPR0_3U, P0    ; Data Seg. Prot. Reg. 3, Set 0, upper
	CSFR_CheckWrite d10, DPR1_0L, P0    ; Data Seg. Prot. Reg. 0, Set 1, lower
	CSFR_CheckWrite d10, DPR1_0U, P0    ; Data Seg. Prot. Reg. 0, Set 1, upper
	CSFR_CheckWrite d10, DPR1_1L, P0    ; Data Seg. Prot. Reg. 1, Set 1, lower
	CSFR_CheckWrite d10, DPR1_1U, P0    ; Data Seg. Prot. Reg. 1, Set 1, upper
	CSFR_CheckWrite d10, DPR1_2L, P0    ; Data Seg. Prot. Reg. 2, Set 1, lower
	CSFR_CheckWrite d10, DPR1_2U, P0    ; Data Seg. Prot. Reg. 2, Set 1, upper
	CSFR_CheckWrite d10, DPR1_3L, P0    ; Data Seg. Prot. Reg. 3, Set 1, lower
	CSFR_CheckWrite d10, DPR1_3U, P0    ; Data Seg. Prot. Reg. 3, Set 1, upper
	CSFR_CheckWrite d10, DPM0, P0       ; Data Protection Mode Register, Set 0
	CSFR_CheckWrite d10, DPM1, P0       ; Data Protection Mode Register, Set 1
	CSFR_CheckWrite d10, PCXI, P0       ; Previous Context Info Register
	CSFR_CheckWrite d10, PSW, P0        ; Program Status Word
	CSFR_CheckWrite d10, PC, P0         ; Program Counter
	CSFR_CheckWrite d10, SYSCON, P0     ; System Configuration Control Register
	CSFR_CheckWrite d10, CPU_ID, P0     ; CPU Identification Register
	CSFR_CheckWrite d10, BIV, P0        ; Interrupt Vector Table
	CSFR_CheckWrite d10, BTV, P0        ; Trap Vector Table Pointer.
	CSFR_CheckWrite d10, ISP, P0        ; Interrupt Stack Pointer
	CSFR_CheckWrite d10, ICR, P0        ; Interrupt Unit Control Register
	CSFR_CheckWrite d10, FCX, P0        ; Free CSA List Head Pointer
	CSFR_CheckWrite d10, LCX, P0        ; Free CSA List Limit Pointer
	CSFR_CheckWrite d10, DMS, P0        ; Debug Monitor Start Address Register
	CSFR_CheckWrite d10, DCX, P0        ; Debug Context Save Area Pointer

	; unsupported CSFR, ignore
	nop     ; workaround CPU_TC.065
	j       _WriteMemoryEnd

_WriteMemoryCSFRLoopEnd:
	add     ACC_ADR,#4     ; increment address
	add     ACC_LEN,#-4    ; decrement length
	mov.u   d10,#0
	jne     ACC_LEN,d10,_WriteMemoryCSFR
	j       _WriteMemoryEnd


	; write to RAM
_WriteMemoryRAM:
	mov.a   a12,ACC_ADR    ; start address
	mov.u   d10,#0         ; read loop exit condition

	jeq     ACC_WDT,#0x1,_LoopWriteMemoryByte
	jeq     ACC_WDT,#0x2,_LoopWriteMemoryHWord
	jeq     ACC_WDT,#0x4,_LoopWriteMemoryWord
	nop     ; workaround CPU_TC.094

_LoopWriteMemoryByte
	call    IF_ReadByte      ; read write data from host
	st.b    [a12],P0
	add.a   a12,#1           ; increment address
	add     ACC_LEN,#-1      ; decrement length
	jne     ACC_LEN,d10,_LoopWriteMemoryByte
	j       _WriteMemoryEnd

_LoopWriteMemoryHWord
	call    IF_ReadHWord    ; read write data from host
	st.h    [a12],P0
	add.a   a12,#2            ; increment address
	add     ACC_LEN,#-2       ; decrement length
	jne     ACC_LEN,d10,_LoopWriteMemoryHWord
	j       _WriteMemoryEnd

_LoopWriteMemoryWord
	call    IF_ReadWord    ; read write data from host
	st.w    [a12],P0
	add.a   a12,#4           ; increment address
	add     ACC_LEN,#-4      ; decrement length
	jne     ACC_LEN,d10,_LoopWriteMemoryWord


_WriteMemoryEnd:
	nop     ; workaround CPU_TC.094
	MSG_ReadChecksum

	; send confirmation
	mov.u   LEN,#0x00
	MSG_SendHeader
	MSG_SendChecksum

	j       _ReceiveMessage


	; -----------------------------------------------------------------------
	; read Register
	; treat address as offset
	; - PC only (if offset == 0xA0 and length == 4)
	; - all registers (if offset = 0x00)
	; registers are to be obtained from CSA via PCXI
_ReadRegister:
	MSG_ReadChecksum

	; decode effective address of application's lower context into a12
	mfcr    d10,#PCXI
	GetAddressFromPCXI d10    ; lower context of application
	mov.a   a12,d10

	; send message header
	mov     LEN,ACC_LEN
	MSG_SendHeader

	; test which registers should be read
	mov.u   d10,#0xa0
	jne     ACC_ADR,d10,_ReadAllRegister

	; read PC only
_ReadPC:
	ld.w    P0,[a12]0x4    ; A11 from lower context
	call    IF_WriteWord

	MSG_SendChecksum
	j       _ReceiveMessage

	; read all registers
_ReadAllRegister:
	mov.u   d10,#31
	mov.a   a15,d10    ; loop counter
_LoopCSA:              ; loop upper and lower context
	ld.w    P0,[a12]
	call    IF_WriteWord
	add.a   a12,#4
	loop    a15,_LoopCSA

	; registers not in CSA
	mov.d   P0,a0
	call    IF_WriteWord
	mov.d   P0,a1
	call    IF_WriteWord
	mov.d   P0,a8
	call    IF_WriteWord
	mov.d   P0,a9
	call    IF_WriteWord
	mfcr    P0,#FCX
	call    IF_WriteWord
	mfcr    P0,#LCX
	call    IF_WriteWord
	mfcr    P0,#ISP
	call    IF_WriteWord
	mfcr    P0,#ICR
	call    IF_WriteWord
	mfcr    P0,#BTV
	call    IF_WriteWord
	mfcr    P0,#BIV
	call    IF_WriteWord

	MSG_SendChecksum
	j       _ReceiveMessage


	; -----------------------------------------------------------------------
	; write single register
	; ACC_ADR: register offset
_WriteRegister:
	; get value
	call    IF_ReadWord

	; decode effective address of application's lower context into a12
	mfcr    d10,#PCXI
	GetAddressFromPCXI d10    ; lower context of application
	mov.a   a12,d10

	; check where register is located
	mov.u   d10,#0x20
	jlt     ACC_ADR,d10,_WriteRegisterInCSA

	; registers not in CSA
	mov.u   d10,#0xa0    ; different offset to ReadRegister
	jeq     ACC_ADR,d10,_WritePC

	mov.u   d10,#0x20
	jne     ACC_ADR,d10,*+6
	mov16.a a0,P0    ; write register A0
	mov.u   d10,#0x21
	jne     ACC_ADR,d10,*+6
	mov16.a a1,P0    ; write register A1
	mov.u   d10,#0x22
	jne     ACC_ADR,d10,*+6
	mov16.a a0,P0    ; write register A8
	mov.u   d10,#0x23
	jne     ACC_ADR,d10,*+6
	mov16.a a1,P0    ; write register A9

	mov.u   d10,#0x24
	jne     ACC_ADR,d10,*+8
	mtcr    #FCX,P0    ; write register FCX
	mov.u   d10,#0x25
	jne     ACC_ADR,d10,*+8
	mtcr    #LCX,P0    ; write register LCX

	mov.u   d10,#0x26
	jne     ACC_ADR,d10,*+8
	mtcr    #ISP,P0    ; write register ISP
	mov.u   d10,#0x27
	jne     ACC_ADR,d10,*+8
	mtcr    #ICR,P0    ; write register ICR

	mov.u   d10,#0x28
	jne     ACC_ADR,d10,*+8
	mtcr    #BTV,P0    ; write register BTV
	mov.u   d10,#0x29
	jne     ACC_ADR,d10,*+8
	mtcr    #BIV,P0    ; write register BIV

	j       _WriteRegisterEnd    ; also unsupported register


_WriteRegisterInCSA:
	muls.u  d10,ACC_ADR,#4    ; offset in d10
	mov.a   a13,d10
	add.a   a12,a13
	st.w    [a12],P0
	j       _WriteRegisterEnd

_WritePC:
	st.w    [a12]0x4,P0    ; A11 in lower context


_WriteRegisterEnd:
	MSG_ReadChecksum

	; send confirmation
	mov.u   LEN,#0x00
	MSG_SendHeader
	MSG_SendChecksum

	j       _ReceiveMessage


	; -----------------------------------------------------------------------
	; single step assembler instruction
	; Host has set debug instruction, just perform a Go here
_Step:
	; j       _Go


	; -----------------------------------------------------------------------
	; leave Monitor and resume application
_Go:
	MSG_ReadChecksum

	; send confirmation
	mov.u   LEN,#0x00
	MSG_SendHeader
	MSG_SendChecksum

	call    IF_FlushOutputQueue

	; clear Debug Monitor Active Flag
	imask   e12,#0,#0,#1
	ldmst   MON_SR,e12    ; MON_SR.MONACT = 0

	nop     ; workaround CPU_TC.048
	ji      a11
	.SIZE Monitor,*-Monitor


; ***************************************************************************
; end romtc.asm
