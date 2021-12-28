	PRESERVE8
	AREA |.text|, CODE, ALIGN=3
	CODE16
	EXTERN main
	EXTERN ||Image$$.bss$$ZI$$Base||
	EXTERN ||Image$$.bss$$ZI$$Limit||
	EXTERN ||Image$$.stack$$ZI$$Limit||
	GLOBAL __main
	ENTRY

__main 
	; initialize stack pointer
	mov 	r0, #0
	ldr 	r1, _SP
	mov 	sp, r1
	mov 	fp, r0

	; clear .bss-section
	ldr 	r4, BSS_S
	ldr 	r5, BSS_E	
	subs	r5, r5, r4
	beq 	gomain
bss_clear
	strb	r0, [r4]
	add 	r4, r4, #1
	subs	r5, r5, #1
	bne 	bss_clear

gomain
	bl  	main
	nop 
_end
	b   	_end

BSS_S	DCD	||Image$$.bss$$ZI$$Base||
BSS_E	DCD	||Image$$.bss$$ZI$$Limit||
_SP	DCD	||Image$$.stack$$ZI$$Limit||


	END