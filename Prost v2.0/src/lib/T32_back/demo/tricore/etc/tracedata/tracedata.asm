; --------------------------------------------------------------------------------
; @Title: Code for data visibility in OCDS-L2 off-chip trace
; @Description:
;   This assembler code example implements the generation of artificial data trace
;   cycles for the OCDS-L2 off chip trace of TriCore AUDO chips.
;
; @Keywords: Infineon, data, trace, tracedata, TriCore, OCDS-L2
; @Author: MAX
; @Chip: 
; @Copyright: (C) 1989-2015 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: tracedata.asm 8303 2015-04-08 12:30:35Z mobermaier $

; Implementation Remarks:
; This example code is not interrupt safe. Any exception that occurrs during the
; execution of this code will lead to unpredictable results. Recommendation is to
; disable interrupts during the execution of this code.
; This example needs to be adapted to the used compiler/assembler, device, board 
; and appication.


        .global T32_DataTrace_Write8
		.global T32_DataTrace_Write16
		.global T32_DataTrace_Write32
		.global T32_DataTrace_Address

        .global T32_DataTrace_Write0
		.global T32_DataTrace_Write1
		.global T32_DataTrace_Write2
		.global T32_DataTrace_Write3

		.global T32_DataTrace_Address0
		.global T32_DataTrace_Address1
		.global T32_DataTrace_Address2
		.global T32_DataTrace_Address3


        .sdecl  ".text.tracedata",CODE
        .sect   ".text.tracedata"
        .align  4



T32_DataTrace_Write8:
		and		d15,d4,#0xff
		movh.a	a15,#@HIS(T32_DataTrace_Write0)
		lea		a15,[a15]@LOS(T32_DataTrace_Write0)
		addsc16.a	a15,a15,d15,#1
		nop

		ji16	a15


T32_DataTrace_Write16:
		sh		d15,d4,#-8
		and		d15,d15,#0xff
		movh.a	a14,#@HIS(T32_DataTrace_Write1)
		lea		a14,[a14]@LOS(T32_DataTrace_Write1)
		addsc16.a	a14,a14,d15,#1

		and		d15,d4,#0xff
		movh.a	a15,#@HIS(T32_DataTrace_Write0)
		lea		a15,[a15]@LOS(T32_DataTrace_Write0)
		addsc16.a	a15,a15,d15,#1

		ji16	a14


T32_DataTrace_Write32:
		sh		d15,d4,#-24
		and		d15,d15,#0xff
		movh.a	a12,#@HIS(T32_DataTrace_Write3)
		lea		a12,[a12]@LOS(T32_DataTrace_Write3)
		addsc16.a	a12,a12,d15,#1

		sh		d15,d4,#-16
		and		d15,d15,#0xff
		movh.a	a13,#@HIS(T32_DataTrace_Write2)
		lea		a13,[a13]@LOS(T32_DataTrace_Write2)
		addsc16.a	a13,a13,d15,#1

		sh		d15,d4,#-8
		and		d15,d15,#0xff
		movh.a	a14,#@HIS(T32_DataTrace_Write1)
		lea		a14,[a14]@LOS(T32_DataTrace_Write1)
		addsc16.a	a14,a14,d15,#1

		and		d15,d4,#0xff
		movh.a	a15,#@HIS(T32_DataTrace_Write0)
		lea		a15,[a15]@LOS(T32_DataTrace_Write0)
		addsc16.a	a15,a15,d15,#1

		ji16	a12

T32_DataTrace_Write3:
		.dup	256
		ji16	a13
		.endm

T32_DataTrace_Write2:
		.dup	256
		ji16	a14
		.endm

T32_DataTrace_Write1:
		.dup	256
		ji16	a15
		.endm

T32_DataTrace_Write0:
		nop
		nop
		.dup	127
		j16		T32_DataTrace_AddressX
		.endm
T32_DataTrace_AddressX:
		.dup	127
		j16		T32_DataTrace_Address
		.endm


T32_DataTrace_Address:
		mov.d	d14,a4

		sh		d15,d14,#-24
		and		d15,d15,#0xff
		movh.a	a12,#@HIS(T32_DataTrace_Address3)
		lea		a12,[a12]@LOS(T32_DataTrace_Address3)
		addsc16.a	a12,a12,d15,#1

		sh		d15,d14,#-16
		and		d15,d15,#0xff
		movh.a	a13,#@HIS(T32_DataTrace_Address2)
		lea		a13,[a13]@LOS(T32_DataTrace_Address2)
		addsc16.a	a13,a13,d15,#1

		sh		d15,d14,#-8
		and		d15,d15,#0xff
		movh.a	a14,#@HIS(T32_DataTrace_Address1)
		lea		a14,[a14]@LOS(T32_DataTrace_Address1)
		addsc16.a	a14,a14,d15,#1

		and		d15,d14,#0xff
		movh.a	a15,#@HIS(T32_DataTrace_Address0)
		lea		a15,[a15]@LOS(T32_DataTrace_Address0)
		addsc16.a	a15,a15,d15,#1

		ji16	a12
 
 T32_DataTrace_Address3:
		.dup	256
		ji16	a13
		.endm

 T32_DataTrace_Address2:
		.dup	256
		ji16	a14
		.endm

 T32_DataTrace_Address1:
		.dup	256
		ji16	a15
		.endm

 T32_DataTrace_Address0:
		.dup	256
		ret16
		.endm

