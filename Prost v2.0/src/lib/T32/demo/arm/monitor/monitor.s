;=================================================================
;=== Monitor for TRACE32/ARM
;=== 
;=== 
;=== 18.10.2002
;=================================================================

; entrypoint with information header for compile phase informations
	AREA	ARMMon, CODE, READONLY
	ENTRY
	
  	IF :DEF: DEBUG_IO
   		INFO 0,"Debug_IO enabled"
  	ENDIF
	
	IF :DEF: USE_FIQ_MODE
		INFO	0,"FIQ-Mode selected for async break"
	ELSE
		INFO	0,"IRQ-Mode selected for async break"
	ENDIF 
;=================================================================
InitVectors	LDR PC, _start_vec 		;0x00		Reset
		LDR PC, _breakp_vec		;0x04		Undefined Opcode   	
		LDR PC, _breakp_vec		;0x08			   	
		LDR PC, _breakp_vec    		;12 0x0C	
		LDR PC, _breakp_vec		;16 0x10	
		nop				;20 0x14
		LDR PC, _int_vec		;24 0x18	IRQ
		LDR PC, _int_vec		;28 0x1c	FIQ
		
_start_vec  	DCD _start			;32 0x20
_breakp_vec 	DCD breakp			;36 0x24
_int_vec    	DCD int				;40 0x28
_fill       	DCD 0x0 			;44 0x2c
InitVectors_end 	
  
  	nop

_errval	DCD	0xDEAD0000
	DCD	0x00000000
	DCD	0x00000000
	DCD	0x00000000
	DCD	0x00000000
	DCD	0x00000000
	DCD	0x00000000
	DCD	0x00000000
	DCD	0x00000000
	DCD	0x00000000
	DCD	0x00000000
	DCD	0x00000000
	DCD	0x00000000
	DCB	"TRACE32 ARM	SER	V1.01"


;================================================================
;include system-specific routines here
;
;

	INCLUDE PID7T_SER.S
	INCLUDE SYS.S

	
;=================================================================
;=	Monitor Entry Points: _start, breakp, int, trap, berr
;=================================================================
_start
 	NOP
	NOP
	NOP
	NOP
	NOP
	NOP

	MRS	R12, CPSR
	AND	R12, R12, #0xFB
	ORR	R12, R12, #0x0B
	MSR	CPSR_c, R12

	BL	SystemInit
	
	B	start0

breakp
	STR 	R12, [SP, #0x30]

	MOV	R12, #0x10
	B	breakp0

int
	B	SystemClearInterrupt
int1
	MSR	CPSR_c, #0xDB		; switch to undefined opcode mode
	STR	R12, [SP, #0x30]	; save r12
	STR	R7,  [SP, #0x1C]	; save r7
	MOV	R7, SP			; load SP_und into R7

	IF :DEF: USE_FIQ_MODE
		MSR	CPSR_c, #0xD1		; switch back to FIQ mode
	ELSE
		MSR	CPSR_c, #0xD2		; switch back to IRQ mode
	ENDIF 

	SUB	R14, R14, #0x04		; calculate and save PC
	STR	R14, [R7, #0x34]	;
		
	MRS	R12, SPSR		; save spsr
	STR	R12, [R7, #0x38]
		
	MSR	CPSR_c, #0xDB		; switch to undefined opcode mode

	MOV	R12, #0x10
	B	breakp0i

trap
	STR	R12, [SP, #0x30]
	MOV	R12, #0x30
	B	breakp0

berr
	STR	R12, [SP, #0x30]
	MOV	R12,#0x20
	B	breakp0
;=================================================================
start0
	
	BL	InitPort
	BL	PrepCom
 

	MOV	R12, #0x40		;# reason for entry is RESET
start1
	CMP	R12, #0x10		;# no burst if breakpoint
	BEQ	startr3
	MOV	R11, #0xFF
start2
	MOV	R3,  #0xFF		;# send burst 255*0xff
	BL 	WriteByte
	SUBS	R11, R11, #0x01
	BNE	start2
startr3
	BL 	ReadStatus		;# flush input queue
	CMP	R3, #0x00
	BEQ	mainlp2
	BL	ReadByte

mainlp2
	MOV	R3, #0x00
	BL	WriteByte		;# signal break to host

	MOV	R3, #0x20
	BL	WriteByte

	BL	ReadByte
	CMP	R3, #0x3F
	BNE	mainlp0

	MOV	R3, #0x00
	BL	WriteByte		;# send message size

	MOV	R10, R12
	MOV	R3,  R12
	BL 	WriteByte		;# send message ID
mainlp1
	MOV	R3, R10, LSR #0x08
	BL 	WriteByte		;# checksum high

	AND 	R3, R10, #0xFF
	BL 	WriteByte		;# checksum low

mainlp
	AND	R12, R12, #0xFF		;# clear message ID
mainlp0
	BL	ReadByte
	CMP	R3, #0x20
	BNE	mainlp0

	MOV	R3, #0x3F
	BL 	WriteByte

	BL 	ReadByte
	MOV	R10, R3			;# length (ignored)

	BL 	ReadByte
	ADD	R10, R10, R3
	AND	R12, R3, #0x0F		;# id

	BL	ReadByte		;# command
	ADD 	R10,R10,R3
	MOV	R9, R3

	CMP	R9, #0x00
	BEQ	goram			;# NOP
	
	CMP	R9, #0x07
	BEQ	goram			;# go to RAM
	
	CMP	R9, #0x07
	BGT	mainlp0			;# command out of range

	BL	ReadByte
	add	R10, R10, R3		;# access class
	MOV	R11, R3

	BL	ReadByte
	add	R10, R10, R3
	MOV	R8, R3			;# access width

	BL	ReadByte
	ADD	R10, R10, R3
	MOV	R7,R3			;# MMSB

	BL	ReadByte
	ADD	R10, R10, R3
	MOV	R4, R7, LSL #0x08
	ORR	R7 ,R4, R3		;# MLSB

	BL 	ReadByte
	ADD	R10, R10, R3
	MOV	R4, R7, LSL #0x08
	ORR 	R7, R4, R3		;# LMSB

	BL	ReadByte
	ADD	R10, R10, R3
	MOV	R4, R7, LSL #0x08
	ORR	R7, R4, R3		;# LLSB

	BL 	ReadByte
	ADD	R10, R10, R3
	MOV	R6, R3			;# memory transfer size

	BL	ReadByte
	AND	R4, R10, #0xFF
	CMP	R3, R4
	BNE	mainlp0			;# parameter checksum error
	ADD 	R10, R10, R3
;-------------------------------------------------------------------
;-	Block oriented Commands
;-------------------------------------------------------------------
	CMP	R9, #0x03
	BEQ	readreg

	CMP	R9, #0x04
	BEQ	writereg
	
	CMP	R9, #0x05
	BEQ	go
	
	CMP	R9, #0x06
	BEQ	go
	
	CMP	R9, #0x02
	BEQ	write
;-------------------------------------------------------------------
;-	Memory Read
;-------------------------------------------------------------------
read
	BL	ReadByte		;# checksum high
	MOV	R9, R3, LSL #0x08

	BL 	ReadByte
	ORR	R9, R9, R3
	CMP	R9, R10
	BNE	mainlp			;# checksum error ?

	MOV	R3, #0x20
	BL	WriteByte

	BL	ReadByte
	CMP	R3, #0x3F
	bne	mainlp

	MOV	R10, R6
	MOV	R3, R10
	BL	WriteByte

	AND	R3, R12, #0x0F
	ADD	R10, R10, R3
	BL 	WriteByte

	AND	R3, R11, #0xF0		;CP register ?
	CMP	R3, #0x80
	BEQ	readcpr
	
	CMP	R8, #0x02
	BEQ	readloopw
	CMP	R8, #0x04
	BEQ	readloopl
	CMP	R8, #0x08
	BEQ	readloopl

readloopb
	LDRB	R3, [R7]
	ADD	R10, R10, R3
	BL	WriteByte

	ADD	R7, R7, #0x01
	SUBS	R6, R6, #0x01
	BNE	readloopb

readfinish
	B 	mainlp1

 [ {ENDIAN}="little"	; Memory read little endian ===============================
     INFO  0,"Little Endian is selected"
 
readloopw
	LDRH	R11, [R7]
	AND	R3, R11, #0xFF
	ADD	R10, R10, R3
	BL	WriteByte
	
	MOV	R3, R11, LSR #0x08
	ADD	R10, R10, R3
	BL	WriteByte

	ADD	R7, R7, #0x02
	SUBS	R6, R6, #0x02
	BNE	readloopw

	B	readfinish

readloopl
	LDR	R11, [R7]
	MOV	R3, R11
	AND	R3, R3, #0xFF
	ADD	R10, R10, R3
	BL	WriteByte

	MOV	R3, R11, LSR #0x08
	AND	R3, R3, #0xFF
	ADD	R10, R10, R3
	BL	WriteByte

	MOV	R3, R11, LSR #0x10
	AND	R3, R3, #0xFF
	ADD	R10, R10, R3
	BL	WriteByte

	MOV	R3, R11, LSR #0x18
	ADD	R10, R10, R3
	BL	WriteByte

	ADD	R7, R7, #0x04
	SUBS	R6, R6, #0x04
	BNE	readloopl
	
 |			; Memory read big endian ===============================
      INFO  0,"Big Endian is selected"

readloopw
	LDRH	R11, [R7]
	MOV	R3, R11, LSR #0x08
	ADD	R10, R10, R3
	BL	WriteByte
	
	AND	R3, R11, #0xFF
	ADD	R10, R10, R3
	BL	WriteByte

	ADD	R7, R7, #0x02
	SUBS	R6, R6, #0x02
	BNE	readloopw

	B	readfinish

readloopl
	LDR	R11, [R7]
	AND	R3, R11, #0xFF
	ADD	R10, R10, R3
	BL	WriteByte

	MOV	R3, R11, LSR #0x08
	AND	R3, R3, #0xFF
	ADD	R10, R10, R3
	BL	WriteByte

	MOV	R3, R11, LSR #0x10
	AND	R3, R3, #0xFF
	ADD	R10, R10, R3
	BL	WriteByte

	MOV	R3, R11, LSR #0x18
	ADD	R10, R10, R3
	BL	WriteByte

	ADD	R7, R7, #0x04
	SUBS	R6, R6, #0x04
	BNE	readloopl
	
 ]			; ==========================
	
	B	readfinish
	
;Coprocessor access
readcpr
	MOV	R7, R7, LSR #0x02
	MOV	R9, R11
;R12: Memory Class 0x80:CP0 -- 0x8F:CP15
;R7 : Address
;R11: CP register value destination
	LDR	R11, _errval	;Value for unimplemented registers: 0xDEAD0000 + T32 CPR coding
	ADD	R11, R11, R7

	IF :DEF: CPACCESS_GENERIC	;***********************************
		INFO	0,"Generic CP access selected"
		;Generic method can access all CP registers
		;needs RAM for execution
		;
		;not implemented - return error value
		B	readcpr_send
	ELSE				;***********************************
	;Only a few explicitly defined CP15 registers will work
	INFO	0,"Static CP access selected"
	CMP	R9, #0x8F

	MOV	R3, R7, LSR #0x08
	CMP	R3, #0x00
	BNE	readcpr_op2

	;T32 Address    command
	;0x000ABCD   	MRCEQ	p15, A, Rdest, CRn_B, CRm_C, opc2_D
	
	;-------------- cX,c0,0 (CP15:0x000X)
	CMP	R7, #0x00	;ID
	MRCEQ	p15, 0, R11, c0, c0, 0
	
	CMP	R7, #0x01	;CR
	MRCEQ	p15, 0, R11, c1, c0, 0
	
	CMP	R7, #0x02	;DCACHE
	MRCEQ	p15, 0, R11, c2, c0, 0

	CMP	R7, #0x03
	MRCEQ	p15, 0, R11, c3, c0, 0

	CMP	R7, #0x04	
	MRCEQ	p15, 0, R11, c4, c0, 0
	
	CMP	R7, #0x05	;DACCESS
	MRCEQ	p15, 0, R11, c5, c0, 0
	
	CMP	R7, #0x06	
	MRCEQ	p15, 0, R11, c6, c0, 0
	
	CMP	R7, #0x07	
	MRCEQ	p15, 0, R11, c7, c0, 0
	
	CMP	R7, #0x08	
	MRCEQ	p15, 0, R11, c8, c0, 0
	
	CMP	R7, #0x09	;DLOCK
	MRCEQ	p15, 0, R11, c9, c0, 0
	
	CMP	R7, #0x0A	
	MRCEQ	p15, 0, R11, c10, c0, 0
	
	CMP	R7, #0x0B	
	MRCEQ	p15, 0, R11, c11, c0, 0
	
	CMP	R7, #0x0C	
	MRCEQ	p15, 0, R11, c12, c0, 0
	
	CMP	R7, #0x0D	
	MRCEQ	p15, 0, R11, c13, c0, 0
	
	CMP	R7, #0x0E	; StrongARM DBAR
	MRCEQ	p15, 0, R11, c14, c0, 0
	
	CMP	R7, #0x0F	
	MRCEQ	p15, 0, R11, c15, c0, 0

	;-------------- c6,cX,0(CP15:0x00X6)
	CMP	R7, #0x16	
	MRCEQ	p15, 0, R11, c6, c1, 0
	
	CMP	R7, #0x26	
	MRCEQ	p15, 0, R11, c6, c2, 0

	CMP	R7, #0x36	
	MRCEQ	p15, 0, R11, c6, c3, 0

	CMP	R7, #0x46	
	MRCEQ	p15, 0, R11, c6, c4, 0

	CMP	R7, #0x56	
	MRCEQ	p15, 0, R11, c6, c5, 0

	CMP	R7, #0x66	
	MRCEQ	p15, 0, R11, c6, c6, 0

	CMP	R7, #0x76	
	MRCEQ	p15, 0, R11, c6, c7, 0

	;-------------- c14,cX,0(CP15:0x00XD)
	;0x000ABCD   	MRCEQ	p15, A, Rdest, CRn_B, CRm_C, opc2_D
	CMP	R7, #0x1E	; StrongARM DBVR
	MRCEQ	p15, 0, R11, c14, c1, 0

	CMP	R7, #0x2E	; StrongARM DBMR
	MRCEQ	p15, 0, R11, c14, c2, 0

	CMP	R7, #0x3E	; StrongARM DBCR
	MRCEQ	p15, 0, R11, c14, c3, 0

	CMP	R7, #0x8E	; StrongARM IBCR
	MRCEQ	p15, 0, R11, c14, c8, 0


	;-------------- cX,c0,1 (CP15:0x010X)
readcpr_op2
	MOV	R3, R7, LSR #0x08
	CMP	R3, #0x01
	BNE	readcpr_send
	
	AND	R7, R7, #0xFF
	
	CMP	R7, #0x02	;ICACHE
	MRCEQ	p15, 0, R11, c2, c0, 1

	CMP	R7, #0x05	;IACCESS
	MRCEQ	p15, 0, R11, c5, c0, 1
	
	CMP	R7, #0x06	;IACCESS
	MRCEQ	p15, 0, R11, c6, c0, 1
	
	CMP	R7, #0x09	;ILOCK
	MRCEQ	p15, 0, R11, c9, c0, 1

	;-------------- c6,cX,0(CP15:0x01X6)
	CMP	R7, #0x16	
	MRCEQ	p15, 0, R11, c6, c1, 1
	
	CMP	R7, #0x26	
	MRCEQ	p15, 0, R11, c6, c2, 1

	CMP	R7, #0x36	
	MRCEQ	p15, 0, R11, c6, c3, 1

	CMP	R7, #0x46	
	MRCEQ	p15, 0, R11, c6, c4, 1

	CMP	R7, #0x56	
	MRCEQ	p15, 0, R11, c6, c5, 1

	CMP	R7, #0x66	
	MRCEQ	p15, 0, R11, c6, c6, 1

	CMP	R7, #0x76	
	MRCEQ	p15, 0, R11, c6, c7, 1
	;0x000ABCD   	MRCEQ	p15, A, Rdest, CRn_B, CRm_C, opc2_D
	CMP	R7, #0x76	
	MRCEQ	p15, 0, R11, c6, c7, 1
			
			
		
	ENDIF

readcpr_send
 [ {ENDIAN}="little"	; CPR write little endian ============================
	MOV	R3, R11, LSR #0x18
	ADD	R10, R10, R3
	BL	WriteByte
	
	MOV	R3, R11, LSR #0x10
	AND	R3, R3, #0xFF
	ADD	R10, R10, R3
	BL	WriteByte
	
	MOV	R3, R11, LSR #0x08
	AND	R3, R3, #0xFF
	ADD	R10, R10, R3
	BL	WriteByte
	
	AND	R3, R11, #0xFF
	ADD	R10, R10, R3
	BL	WriteByte
 |			; Memory write big endian ===============================
	AND	R3, R11, #0xFF
	ADD	R10, R10, R3
	BL	WriteByte
	
	MOV	R3, R11, LSR #0x08
	AND	R3, R3, #0xFF
	ADD	R10, R10, R3
	BL	WriteByte
	
	MOV	R3, R11, LSR #0x10
	AND	R3, R3, #0xFF
	ADD	R10, R10, R3
	BL	WriteByte
	
	MOV	R3, R11, LSR #0x18
	ADD	R10, R10, R3
	BL	WriteByte
 ]			; ==========================
 
	B	mainlp1

	
;################################################################################
;#
;#	Memory Write
;#
;################################################################################

write
	AND	R3, R11, #0xF0		;CP register ?
	CMP	R3, #0x80
	BEQ	writecpr

	CMP	R8, #0x02
	BEQ	writeloopw
	CMP	R8, #0x04
	BEQ	writeloopl
	CMP	R8, #0x08
	beq	writeloopl

writeloopb
	BL	ReadByte
	ADD	R10, R10, R3
	STRB	R3, [R7]

	ADD	R7, R7, #0x01
	SUBS	R6, R6, #0x01
	bne	writeloopb

writemfinish
	B	mainlp3

 [ {ENDIAN}="little"	; Memory write little endian ===============================

writeloopw
	BL	ReadByte
	ADD	R10, R10, R3
	MOV	R11, R3

	BL	ReadByte
	ADD	R10, R10, R3
	MOV	R3, R3, LSL #0x08
	ORR	R11, R11, R3
	STRH	R11, [R7]

	ADD	R7, R7, #0x02
	SUBS	R6, R6, #0x02
	BNE	writeloopw

	B	writemfinish

writeloopl
	BL	ReadByte
	ADD	R10, R10, R3
	MOV	R11, R3

	BL	ReadByte
	ADD	R10, R10, R3
	MOV	R3, R3, LSL #0x08
	ORR	R11, R11, R3

	BL	ReadByte
	ADD	R10, R10, R3
	MOV	R3, R3, LSL #0x10
	ORR	R11, R11, R3

	BL	ReadByte
	ADD	R10, R10, R3
	MOV	R3, R3, LSL #0x18
	ORR	R11, R11, R3
	STR	R11, [R7]

	ADD	R7, R7, #0x04
	SUBS	R6, R6, #0x04
	BNE	writeloopl
	
 |			; Memory write big endian ===============================

writeloopw
	BL	ReadByte
	ADD	R10, R10, R3
	MOV	R11, R3, LSL #0x08

	BL	ReadByte
	ADD	R10, R10, R3
	ORR	R11, R11, R3
	STRH	R11, [R7]

	ADD	R7, R7, #0x02
	SUBS	R6, R6, #0x02
	BNE	writeloopw

	B	writemfinish

writeloopl
	BL	ReadByte
	ADD	R10, R10, R3
	MOV	R11, R3, LSL #0x18

	BL	ReadByte
	ADD	R10, R10, R3
	MOV	R3, R3, LSL #0x10
	ORR	R11, R11, R3

	BL	ReadByte
	ADD	R10, R10, R3
	MOV	R3, R3, LSL #0x08
	ORR	R11, R11, R3

	BL	ReadByte
	ADD	R10, R10, R3
	ORR	R11, R11, R3
	STR	R11, [R7]

	ADD	R7, R7, #0x04
	SUBS	R6, R6, #0x04
	BNE	writeloopl
 ]			; ==========================

	B	writemfinish

writecpr
;Coprocessor access
	MOV	R7, R7, LSR #0x02
	MOV	R9, R11

;read new value from host
 [ {ENDIAN}="little"	; CPR write little endian ============================
 	BL	ReadByte
 	ADD	R10, R10, R3
 	MOV	R11, R3
 
 	BL	ReadByte
 	ADD	R10, R10, R3
 	MOV	R3, R3, LSL #0x08
 	ORR	R11, R11, R3
 
 	BL	ReadByte
 	ADD	R10, R10, R3
 	MOV	R3, R3, LSL #0x10
 	ORR	R11, R11, R3
 
 	BL	ReadByte
 	ADD	R10, R10, R3
 	MOV	R3, R3, LSL #0x18
 	ORR	R11, R11, R3
 |			; CPR write big endian ===============================
	BL	ReadByte
	ADD	R10, R10, R3
	MOV	R11, R3, LSL #0x18

	BL	ReadByte
	ADD	R10, R10, R3
	MOV	R3, R3, LSL #0x10
	ORR	R11, R11, R3

	BL	ReadByte
	ADD	R10, R10, R3
	MOV	R3, R3, LSL #0x08
	ORR	R11, R11, R3

	BL	ReadByte
	ADD	R10, R10, R3
	ORR	R11, R11, R3
 ]			; ==========================


;R12: Memory Class 0x80:CP0 -- 0x8F:CP15
;R7 : Address
;R11: CP register value destination

	IF :DEF: CPACCESS_GENERIC	;***********************************
		;Generic method can access all CP registers
		;needs RAM for execution
		;
		;not implemented - return error value
		B	berr
	ELSE				;***********************************
	;Only a few explicitly defined CP15 registers will work
	CMP	R9, #0x8F
	BNE	berr
	
	;-------------- cX,c0,0 (CP15:0x000X)
	CMP	R7, #0x00	;ID
	MCREQ	p15, 0, R11, c0, c0, 0
	
	CMP	R7, #0x01	;CR
	MCREQ	p15, 0, R11, c1, c0, 0
	
	CMP	R7, #0x02	;DCACHE
	MCREQ	p15, 0, R11, c2, c0, 0

	CMP	R7, #0x03
	MCREQ	p15, 0, R11, c3, c0, 0

	CMP	R7, #0x04	
	MCREQ	p15, 0, R11, c4, c0, 0
	
	CMP	R7, #0x05	;DACCESS
	MCREQ	p15, 0, R11, c5, c0, 0
	
	CMP	R7, #0x06	
	MCREQ	p15, 0, R11, c6, c0, 0
	
	CMP	R7, #0x07	
	MCREQ	p15, 0, R11, c7, c0, 0
	
	CMP	R7, #0x08	
	MCREQ	p15, 0, R11, c8, c0, 0
	
	CMP	R7, #0x09	;DLOCK
	MCREQ	p15, 0, R11, c9, c0, 0
	
	CMP	R7, #0x0A	
	MCREQ	p15, 0, R11, c10, c0, 0
	
	CMP	R7, #0x0B	
	MCREQ	p15, 0, R11, c11, c0, 0
	
	CMP	R7, #0x0C	
	MCREQ	p15, 0, R11, c12, c0, 0
	
	CMP	R7, #0x0D	
	MCREQ	p15, 0, R11, c13, c0, 0
	
	CMP	R7, #0x0E	; StrongARM DBAR
	MCREQ	p15, 0, R11, c14, c0, 0
	
	CMP	R7, #0x0F	
	MCREQ	p15, 0, R11, c15, c0, 0

	;-------------- c6,cX,0(CP15:0x00X6)
	CMP	R7, #0x16	
	MCREQ	p15, 0, R11, c6, c1, 0
	
	CMP	R7, #0x26	
	MCREQ	p15, 0, R11, c6, c2, 0

	CMP	R7, #0x36	
	MCREQ	p15, 0, R11, c6, c3, 0

	CMP	R7, #0x46	
	MCREQ	p15, 0, R11, c6, c4, 0

	CMP	R7, #0x56	
	MCREQ	p15, 0, R11, c6, c5, 0

	CMP	R7, #0x66	
	MCREQ	p15, 0, R11, c6, c6, 0

	CMP	R7, #0x76	
	MCREQ	p15, 0, R11, c6, c7, 0

	;-------------- c14,cX,0(CP15:0x00XD)
	;0x000ABCD   	MRCEQ	p15, A, Rdest, CRn_B, CRm_C, opc2_D
	CMP	R7, #0x1E	; StrongARM DBVR
	MCREQ	p15, 0, R11, c14, c1, 0

	CMP	R7, #0x2E	; StrongARM DBMR
	MCREQ	p15, 0, R11, c14, c2, 0

	CMP	R7, #0x3E	; StrongARM DBCR
	MCREQ	p15, 0, R11, c14, c3, 0

	CMP	R7, #0x8E	; StrongARM IBCR
	MCREQ	p15, 0, R11, c14, c8, 0

	;-------------- cX,c0,1 (CP15:0x010X)
	MOV	R3, R7, LSR #0x08
	CMP	R3, #0x01
	BNE	writecpr_end
	
	AND	R7, R7, #0xFF
	
	CMP	R7, #0x02	;ICACHE
	MCREQ	p15, 0, R11, c2, c0, 1

	CMP	R7, #0x05	;IACCESS
	MCREQ	p15, 0, R11, c5, c0, 1
	
	CMP	R7, #0x06	;IACCESS
	MCREQ	p15, 0, R11, c6, c0, 1
	
	CMP	R7, #0x09	;ILOCK
	MCREQ	p15, 0, R11, c9, c0, 1

	;-------------- c6,cX,0(CP15:0x01X6)
	CMP	R7, #0x16	
	MCREQ	p15, 0, R11, c6, c1, 1
	
	CMP	R7, #0x26	
	MCREQ	p15, 0, R11, c6, c2, 1

	CMP	R7, #0x36	
	MCREQ	p15, 0, R11, c6, c3, 1

	CMP	R7, #0x46	
	MCREQ	p15, 0, R11, c6, c4, 1

	CMP	R7, #0x56	
	MCREQ	p15, 0, R11, c6, c5, 1

	CMP	R7, #0x66	
	MCREQ	p15, 0, R11, c6, c6, 1

	CMP	R7, #0x76	
	MCREQ	p15, 0, R11, c6, c7, 1
		
	ENDIF

writecpr_end
	B	mainlp3


mainlp3
	BL	ReadByte
	MOV	R11, R3, LSL #0x08

	BL	ReadByte
	ORR	R11, R11, R3
	CMP	R11, R10
	BNE	mainlp

	B	mainlp2


;################################################################################
;#
;#	Read Registers
;#
;################################################################################

readreg
	BL	ReadByte		;# checksum high
	MOV	R11, R3, LSL #0x08

	BL	ReadByte		;# checksum low
	ORR	R11, R11, R3
	CMP	R11, R10
	BNE	mainlp			;# checksum error ?

	MOV	R3, #0x20
	BL	WriteByte

	BL	ReadByte
	CMP	R3, #0x3F
	BNE	mainlp

	MOV	R10, R6
	MOV	R3, R10
	BL	WriteByte

	AND	R3, R12, #0x0F
	ADD	R10, R10, R3
	BL 	WriteByte

	CMP	R6, #0x50
	BNE	readregpc
	
;==============================================================
	MRS	R0, CPSR		; switch to sys mode
	ORR	R1, R0, #0x0F
	MSR	CPSR_c, R1
	
	MOV	R11, R13
	MOV	R4, R14
	
	MSR	CPSR_c, R0		; switch back
	
	BL	writelong
	MOV	R11, R4
	BL	writelong
;==============================================================
	MRS	R0, CPSR		; switch to svc mode
	ORR	R1, R0, #0x03
	AND	R1, R1, #0xF3
	MSR	CPSR_c, R1

	MOV	R11, R13
	MOV	R4, R14
	MRS	R5, SPSR
	
	MSR	CPSR_c, R0		; switch back


	BL	writelong
	MOV	R11, R4
	BL	writelong
	MOV	R11, R5
	BL	writelong
;==============================================================
	MOV	R11, SP			; R13_und
	BL	writelong
;==============================================================
	MRS	R0, CPSR		; switch to fiq mode(1)
	ORR	R1, R0, #0x01
	AND	R1, R1, #0xf1
	MSR	CPSR_c, R1

	MOV	R3,  R8
	MOV	R4,  R9
	MOV	R5,  R10
	MOV	R6,  R11
	
	MSR	CPSR_c, R0		; switch back
	
	MOV	R11, R3
	BL	writelong
	MOV	R11, R4
	BL	writelong
	MOV	R11, R5
	BL	writelong
	MOV	R11, R6
	BL	writelong
	
	MRS	R0, CPSR		; switch to fiq mode(2)
	ORR	R1, R0, #0x01
	AND	R1, R1, #0xf1
	MSR	CPSR_c, R1

	MOV	R3,  R12
	MOV	R4,  R13
	MOV	R5,  R14
	MRS	R6,  SPSR
	
	MSR	CPSR_c, R0		; switch back
	
	MOV	R11, R3
	BL	writelong
	MOV	R11, R4
	BL	writelong
	MOV	R11, R5
	BL	writelong
	MOV	R11, R6
	BL	writelong
;==============================================================
	MRS	R0, CPSR		; switch to irq mode
	ORR	R1, R0, #0x02
	AND	R1, R1, #0xF2
	MSR	CPSR_c, R1
	
	MOV	R11, R13
	MOV	R4, R14
	MRS	R5, SPSR
	
	MSR	CPSR_c, R0		; switch back
	
	BL	writelong
	MOV	R11, R4
	BL	writelong
	MOV	R11, R5
	BL	writelong
;==============================================================
	MRS	R0, CPSR		; switch to abt mode
	ORR	R1, R0, #0x07
	AND	R1, R1, #0xF7
	MSR	CPSR_c, R1
	
	MOV	R11, R13
	MOV	R4, R14
	MRS	R5, SPSR
	
	MSR	CPSR_c, R0		; switch back
	
	BL	writelong
	MOV	R11, R4
	BL	writelong
	MOV	R11, R5
	BL	writelong
;==============================================================
	B	mainlp1

readregpc
	LDR	R11, [SP, #0x34]	; R14_und
	BL	writelong
	LDR	R11, [SP, #0x38]	; SPSR_und
	BL	writelong
	LDR	R11, [SP]		; R0
	BL	writelong
	LDR	R11, [SP, #0x04]	; R1
	BL	writelong
	LDR	R11, [SP, #0x08]	; R2
	BL	writelong
	LDR	R11, [SP, #0x0C]	; R3
	BL	writelong
	LDR	R11, [SP, #0x10]	; R4
	BL	writelong
	LDR	R11, [SP, #0x14]	; R5
	BL	writelong
	LDR	R11, [SP, #0x18]	; R6
	BL	writelong
	LDR	R11, [SP, #0x1C]	; R7
	BL	writelong
	LDR	R11, [SP, #0x20]	; R8
	BL	writelong
	LDR	R11, [SP, #0x24]	; R9
	BL	writelong
	LDR	R11, [SP, #0x28]	; R10
	BL	writelong
	LDR	R11, [SP, #0x2C]	; R11
	BL	writelong
	LDR	R11, [SP, #0x30]	; R12
	BL	writelong

	b 	mainlp1
;=================================================================
writelong
	MOV	R8, lr
	
 [ {ENDIAN}="little"
	AND	R3, R11, #0xFF
	ADD	R10, R10, R3
	BL 	WriteByte

	MOV	R3, R11, LSR #0x08
	AND	R3, R3, #0xFF
	ADD	R10, R10, R3
	BL 	WriteByte
	
	MOV	R3, R11, LSR #0x10
	AND	R3, R3, #0xFF
	ADD	R10, R10, R3
	BL 	WriteByte
	
	MOV	R3, R11, LSR #0x18
	AND	R3, R3, #0xFF
	ADD	R10, R10, R3
	BL	WriteByte
 | ;-----------------------------------------------------------
	MOV	R3, R11, LSR #0x18
	ADD	R10, R10, R3
	BL 	WriteByte

	MOV	R3, R11, LSR #0x10
	AND	R3, R3, #0xFF
	ADD	R10, R10, R3
	BL 	WriteByte
	
	MOV	R3, R11, LSR #0x08
	AND	R3, R3, #0xFF
	ADD	R10, R10, R3
	BL 	WriteByte
	
	MOV	R3, R11
	AND	R3, R3, #0xFF
	ADD	R10, R10, R3
	BL	WriteByte
 ] ;-----------------------------------------------------------
	MOV	pc, R8
;=================================================================

;################################################################################
;#
;#	Write Registers
;#
;################################################################################

writereg
	CMP	R6, #0x00
	BEQ	mainlp3

	CMP	R6, #0x04
	BNE	mainlp
	
	BL	readlong
	MOV	R3, R11

	MRS	R0, CPSR
	AND	R1, R0, #0xF0
	MOV	R2, R7, LSR #0x04
	ORR	R1, R1, R2
	AND	R7, R7, #0x0F
	
	MSR	CPSR_c, R1
	
	CMP	R7, #0x00
	MOVEQ	R8, R3
	CMP	R7, #0x01
	MOVEQ	R9, R3
	CMP	R7, #0x02
	MOVEQ	R10, R3
	CMP	R7, #0x03
	MOVEQ	R11, R3
	CMP	R7, #0x04
	MOVEQ	R12, R3
	CMP	R7, #0x05
	MOVEQ	R13, R3
	CMP	R7, #0x06
	MOVEQ	R14, R3
	CMP	R7, #0x07
	MSREQ	SPSR_cxfs, R3

	MSR	CPSR_c, R0

	B 	mainlp3
	
;=================================================================
readlong
	MOV	R8, LR
	
 [ {ENDIAN}="little"
	BL	ReadByte
	ADD	R10, R10, R3
	MOV	R11, R3
	
	BL	ReadByte
	ADD	R10, R10, R3
	MOV	R3, R3, LSL #0x08
	ORR	R11, R11, R3

	BL	ReadByte
	ADD	R10,R10,R3
	MOV	R3, R3, LSL #0x10
	ORR	R11, R11, R3

	BL	ReadByte
	ADD	R10, R10, R3
	MOV	R3, R3, LSL #0x18
	ORR	R11, R11, R3
 | ;-----------------------------------------------------------
	BL	ReadByte
	ADD	R10, R10, R3
	MOV	R11, R3, LSL #0x18
	
	BL	ReadByte
	ADD	R10, R10, R3
	MOV	R3, R3, LSL #0x10
	ORR	R11, R11, R3

	BL	ReadByte
	ADD	R10,R10,R3
	MOV	R3, R3, LSL #0x08
	ORR	R11, R11, R3

	BL	ReadByte
	ADD	R10, R10, R3
	ORR	R11, R11, R3
 ]
	MOV	PC, R8
 
;=================================================================
;=	Go
;=================================================================

go
	BL	readlong
	STR	R11, [SP, #0x34]
	BL	readlong
	STR	R11, [SP, #0x38]
	BL	readlong
	STR	R11, [SP]
	BL	readlong
	STR	R11, [SP, #0x04]
	BL	readlong
	STR	R11, [SP, #0x08]
	BL	readlong
	STR	R11, [SP, #0x0C]
	BL	readlong
	STR	R11, [SP, #0x10]
	BL	readlong
	STR	R11, [SP, #0x14]
	BL	readlong
	STR	R11, [SP, #0x18]
	BL	readlong
	STR	R11, [SP, #0x1C]
	BL	readlong
	STR	R11, [SP, #0x20]
	BL	readlong
	STR	R11, [SP, #0x24]
	BL	readlong
	STR	R11, [SP, #0x28]
	BL	readlong
	STR	R11, [SP, #0x2C]
	BL	readlong
	STR	R11, [SP, #0x30]
		
	BL	ReadByte		;# checksum high
	MOV	R11, R3, LSL #0x08

	BL	ReadByte		;# checksum low
	ORR	R11, R11, R3
	CMP	R11, R10
	BNE	mainlp

	MOV	R3, #0x20
	BL	WriteByte

	BL	ReadByte
	CMP	R3, #0x3F
	BNE	mainlp

	MOV	R3, #0x00
	BL	WriteByte

	MOV	R10, R12
	MOV	R3, R10
	BL	WriteByte

	MOV	R3, R10, LSR #0x08
	BL	WriteByte

	AND	R3, R10, #0xFF
	BL	WriteByte

	BL	SystemFlushCache

	BL	PrepGo

	LDR	R0, [SP, #0x38]		; SPSR_und
	MSR	SPSR_cxsf, R0		; Enable IRQ/FIQ for async break (via USART int)

	IF :DEF: USE_FIQ_MODE
		AND	R0, R0, #0xBF
	ELSE
		AND	R0, R0, #0x7F
	ENDIF 

	MSR	SPSR_c, R0

	LDR	R14, [SP, #0x34]	; R14_und
	LDR	R0,  [SP]		; R0
	LDR	R1,  [SP, #0x04]	; R1
	LDR	R2,  [SP, #0x08]	; R2
	LDR	R3,  [SP, #0x0C]	; R3
	LDR	R4,  [SP, #0x10]	; R4
	LDR	R5,  [SP, #0x14]	; R5
	LDR	R6,  [SP, #0x18]	; R6
	LDR	R7,  [SP, #0x1C]	; R7
	LDR	R8,  [SP, #0x20]	; R8
	LDR	R9,  [SP, #0x24]	; R9
	LDR	R10, [SP, #0x28]	; R10
	LDR	R11, [SP, #0x2C]	; R11
	LDR	R12, [SP, #0x30]	; R12

	MOVS	PC, R14			; return

;=================================================================
;=	Breakpoint Entry
;=================================================================

breakp0
	SUB	R14, R14, #0x04
	STR	R14, [SP, #0x34]	; R14_und = PC
	MRS	R14, SPSR
	STR	R14, [SP, #0x38]	; SPSR_und = CPSR
	STR	R7,  [SP, #0x1C]
breakp0i
	STR	R11, [SP, #0x2C]
	STR	R10, [SP, #0x28]
	STR	R9,  [SP, #0x24]
	STR	R8,  [SP, #0x20]
	
	STR	R6,  [SP, #0x18]
	STR	R5,  [SP, #0x14]
	STR	R4,  [SP, #0x10]
	STR	R3,  [SP, #0x0C]
	STR	R2,  [SP, #0x08]
	STR	R1,  [SP, #0x04]
	STR	R0,  [SP]
	
	BL	PrepCom
	B	start1

;=================================================================
;=	Hot Patch / Nop
;=================================================================

goram
	BL	ReadByte		;# checksum high
	MOV	R11, R3, LSL #0x08

	BL	ReadByte		;# checksum low
	ORR	R11,R11,R3
	CMP	R11,R10
	BNE	mainlp			;# checksum error ?

	MOV	R3, #0x20
	BL	WriteByte

	BL	ReadByte
	CMP	R3, #0x3F
	BNE	mainlp

	MOV	R10, R6
	MOV	R3, R10
	BL	WriteByte

	AND	R3, R12, #0x0F
	ADD	R10, R10, R3
	BL 	WriteByte

	MOV	R3, R10, LSR #0x08
	BL	WriteByte		;# checksum high

	AND	R3, R10, #0xFF
	CMP	R9, #0x00
;	BNE	goram0

	BL	WriteByte		;# checksum low

	B	mainlp


        	END