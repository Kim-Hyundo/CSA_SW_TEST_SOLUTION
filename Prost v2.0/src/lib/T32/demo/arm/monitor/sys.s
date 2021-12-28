	
	
; System routines

SystemInit
		; Copy Vector Table to 0x00000000
	    	    
			LDR	r0, =InitVectors			; source address
			MOV	r1, #0			         	; destination address
			MOV	r2, #(InitVectors_end-InitVectors+8)/4	; number of bytes to copy
	
copyLoop		LDR	r3, [r0], #4		   ;
			STR	r3, [r1], #4
			SUB	r2, r2, #1
			CMP	r2, #0
	
			BNE	copyLoop
		
			MOV	PC, LR
		

SystemClearInterrupt	NOP
			B	int1


SystemFlushCache	NOP
			MOV 	pc, lr

			
			END