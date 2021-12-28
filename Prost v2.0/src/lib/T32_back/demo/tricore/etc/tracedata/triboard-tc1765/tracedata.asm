;***************************************************************************
;**                                                                        *
;**  FILE        :  tracedata.asm                                          *
;**                                                                        *
;**  DESCRIPTION :  Code for data visibility in OCDS-L2 off-chip trace     *
;**                                                                        *
;**  Copyright (c) 2003-2015 Lauterbach Datentechnik                       *
;**                                                                        *
;**************************************************************************/

        .global T32_DataTrace_Write8
		.global T32_DataTrace_Write16
		.global T32_DataTrace_Write32
		.global T32_DataTrace_Address

        .sdecl  ".text.tracedata",CODE
        .sect   ".text.tracedata"
        .align  4



T32_DataTrace_Write8:
		and		d15,d4,#0xff
		lea		a15,T32_DataTrace_Write0
		addsc16.a	a15,a15,d15,#1

		ji16	a15


T32_DataTrace_Write16:
		sh		d15,d4,#-8
		and		d15,d15,#0xff
		lea		a14,T32_DataTrace_Write1
		addsc16.a	a14,a14,d15,#1

		and		d15,d4,#0xff
		lea		a15,T32_DataTrace_Write0
		addsc16.a	a15,a15,d15,#1

		ji16	a14


T32_DataTrace_Write32:
		sh		d15,d4,#-24
		and		d15,d15,#0xff
		lea		a12,T32_DataTrace_Write3
		addsc16.a	a12,a12,d15,#1

		sh		d15,d4,#-16
		and		d15,d15,#0xff
		lea		a13,T32_DataTrace_Write2
		addsc16.a	a13,a13,d15,#1

		sh		d15,d4,#-8
		and		d15,d15,#0xff
		lea		a14,T32_DataTrace_Write1
		addsc16.a	a14,a14,d15,#1

		and		d15,d4,#0xff
		lea		a15,T32_DataTrace_Write0
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
		lea		a12,T32_DataTrace_Address3
		addsc16.a	a12,a12,d15,#1

		sh		d15,d14,#-16
		and		d15,d15,#0xff
		lea		a13,T32_DataTrace_Address2
		addsc16.a	a13,a13,d15,#1

		sh		d15,d14,#-8
		and		d15,d15,#0xff
		lea		a14,T32_DataTrace_Address1
		addsc16.a	a14,a14,d15,#1

		and		d15,d14,#0xff
		lea		a15,T32_DataTrace_Address0
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

