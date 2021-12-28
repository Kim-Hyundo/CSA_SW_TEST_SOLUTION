	
	
; Serial communication routines for the ARM Development Board PID7T
; Note: ReadStatus, ReadByte and WriteByte are limited to R0-R2.
; 	R3 contains the RX/RX Data
;	InitPort, PrepCom and PrepGo can use R0-R12
;
;


	IF :DEF: PORT_B
	INFO	0,"NISA serial port B selected"
NisaSer		EQU	0x0D800020	; Port B
	ELSE
	INFO	0,"NISA serial port A selected"
NisaSer		EQU	0x0D800000	; Port A
	ENDIF
	
Ser_RHR		EQU	NisaSer+0x00	; Rx Data
Ser_THR		EQU	NisaSer+0x00	; Tx Data
Ser_IER		EQU	NisaSer+0x04	; Int Enable
Ser_FCR		EQU	NisaSer+0x08	; Fifo Ctrl
Ser_ISR		EQU	NisaSer+0x08	; Int Status
Ser_LCR		EQU	NisaSer+0x0C	; Line Ctrl
Ser_MCR		EQU	NisaSer+0x10	; Modem Ctrl
Ser_LSR		EQU	NisaSer+0x14	; Line Status
Ser_MSR		EQU	NisaSer+0x18	; Modem Status
Ser_SPR		EQU	NisaSer+0x1C	; Scratchpad
Ser_DLL		EQU	NisaSer+0x00	; Div Latch L
Ser_DLM		EQU	NisaSer+0x04	; Div Latch M

InitPort	LDR	r1, =Ser_FCR	; FIFO reset
		MOV	r0, #0x07
		STRB	r0, [r1]
		
		LDR	r2, =Ser_LCR	; set baud rate
		MOV	r0, #0x83	; 
		STRB	r0, [r2]
		
		LDR	R3, =Ser_DLL	; set Baud div
		MOV	r0, #0x02	; 0x0002 for 57.6@1.8MHz
		STRB	r0, [R3]
		
		ADD	R3, R3, #0x04
		MOV	r0, #0x00
		STRB	r0, [R3]
		
		MOV	r0, #0x03	; 
		STRB	r0, [r2]	
		
		LDR	r2, =Ser_MCR	; set MCR
		MOV	r0, #0x00
		STRB	r0, [r2]
		
		MOV 	pc, lr
;---------------------------------------------------------------------

PrepCom		LDR	r1, =Ser_IER	; disable UART RX interrupt
		MOV	r0, #0x00
		STRB	r0, [r1]
		
		MOV	pc, lr
;---------------------------------------------------------------------

PrepGo		LDR	r1, =Ser_IER	; enable UART RX interrupt
		MOV	r0, #0x03
		STRB	r0, [r1]
		
		MOV	pc, lr
;---------------------------------------------------------------------

ReadStatus	LDR	r0, =Ser_LSR	; returns 0x01 if there is a
		LDRB	r0, [r0]	; byte in the RX buffer
		ANDS	r3, r0, #0x01
		
		MOV	pc, lr		
;---------------------------------------------------------------------

ReadByte	LDR	r0, =Ser_LSR	; wait for a byte in RX buffer
		LDRB	r0, [r0] 
		ANDS	r0, r0, #0x01
		BEQ	ReadByte

		LDR	r0, =Ser_RHR	; then read byte and return in r3
		LDRB	R3, [r0]
		
		MOV	pc, lr
;---------------------------------------------------------------------

WriteByte	LDR	r0, =Ser_LSR	; wait until TX buffer can hold
		LDRB	r0, [r0] 	; 
		ANDS	r0, r0, #0x20
		BEQ	WriteByte
		
		LDR	r0, =Ser_THR	; then write byte (from r3) to tx buffer
		STRB	R3, [r0]
		
		MOV	pc, lr
;---------------------------------------------------------------------

		END