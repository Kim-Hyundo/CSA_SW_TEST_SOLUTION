.file   "crt0.s"
.text
.globl  _start

_start:
	# set stack and frame pointer
	ldr	%r1, .LSP
	mov	%r2, #0
        mov     %sp, %r1
        mov     %fp, %r2

	# clear .bss-section
	ldr	%r1, .LBssStart
	ldr	%r2, .LBssEnd	
	sub	%r2, %r1
	beq	.LBmCallStart


	mov 	%r0, #0
.LBssClear:
	strb	%r0, [%r1]
	add	%r1, #1
	sub	%r2, #1
	bne	.LBssClear

	# use r4,r5 because these are saved by callee
.LBmCallStart:
	ldr     %r4, .LBmStart
	ldr     %r5, .LBmEnd
	sub     %r5, %r4
	beq     .LGoMain
.LBmCall:
	ldr     %r3, [%r4]
	blx     %r3
	add     %r4, #4
	sub     %r5, #4
	bne     .LBmCall

.LGoMain:
	# call "main"
	bl	main
.LEnd:
	b	.LEnd


.align 2
.LBssStart:
	.word	_bss_start
.LBssEnd:
	.word	_bss_end
.LBmStart:
	.word   _bm_start
.LBmEnd:
	.word   _bm_end
.LSP:
	.word	_sp
