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
	beq	.LGoMain

	mov 	%r0, #0
.LBssClear:
	strb	%r0, [%r1]
	add	%r1, #1
	sub	%r2, #1
	bne	.LBssClear

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
.LSP:
	.word	_sp
