;=================================================================
;=== Serial Communication Routines for
;=== EPROM SIMULATOR
;=== 
;=== 13.12.2002
;=================================================================


ESIBASE	DCD	0x00001000

  INFO  0,"Using eprom simulator routines"

InitPort
	MOV	PC, LR
PrepCom
	MOV	R1, LR
	BL	prepcom1
prepcom1
	MOV	R0, LR
	MOV	LR, R1
	SUB	R0, R0, #0x64
	LDR	R1, ESIBASE
	ADD	R0, R0, R1
	MOV	PC, LR
ReadByte
	MOV	R3, R0
	MOV	R2, #0x0400
	ADD	R3, R3, R2
readbyte1
	LDRB 	R2, [R3]
	ANDS	R2, R2, #0x01
	BEQ	readbyte1
	MOV	R3, R0
	LDRB 	R3, [R3]
	MOV	PC, LR

ReadStatus
	MOV	R3, R0
	MOV	R2, #0x0400
	ADD	R3, R3, R2
	
	LDRB	R3, [R3]
	ANDS	R3, R3, #0x01
	MOV	PC, LR

WriteByte
	MOV	R1, R0
	MOV	R2, #0x0400
	ADD	R1, R1, R2
writebyte1
	LDRB 	R2, [R1]
	ANDS	R2, R2, #0x02
	BNE	writebyte1
	MOV	R1, R0
	MOV	R2, #0x0800
	ADD	R1, R1, R2
	LDRB	R3, [R1, R3]
	MOV	PC, LR

PrepGo	
	MOV	PC, LR
	
	END