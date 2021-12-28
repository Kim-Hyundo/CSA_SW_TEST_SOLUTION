.syntax unified
.cpu cortex-m3

.file "clang_mem.s"
.text

.align 2
.thumb
.globl __aeabi_memset
// r0: dest
// r1: length
// r2: byte value
__aeabi_memset:
	// do nothing if length == 0
	cmp	r1, #0
	it	eq
	bxeq	lr

	// r1 := end of array
	add.w	r1, r0

	// fill array with byte value
1:
	strb	r2, [r0], #1
	cmp	r0, r1
	blo	1b

	// return
	bx	lr


.align 2
.globl __aeabi_memset4
// r0: dest
// r1: length
// r2: byte value
__aeabi_memset4:
	// r3 := length & ~0x3
	bic	r3, r1, #3

	// call __aeabi_memset if length<4
	cmp	r3, #0
	it	eq
	beq	__aeabi_memset

	// r12 == end of 4 byte aligned destination
	add.w	r12, r0, r3

	// Convert byte value into 32-bit value
	uxtb	r3, r2
	orr.w	r3, r3, r3, lsl #8
	orr.w	r3, r3, r3, lsl #16

	// r1 := length of rest to fill with aeabi_memset
	and	r1, r1, #3

	// fill (aligned) array with value
1:
	str	r3, [r0], #4
	cmp	r0, r12
	blo	1b

	// fill rest (<4 bytes) with aeabi_memset
	b	__aeabi_memset


.align 2
.globl __aeabi_memclr
// r0: dest
// r1: length
__aeabi_memclr:
	mov	r2,#0
	b	__aeabi_memset


.align 2
.globl __aeabi_memclr4
// r0: dest
// r1: length
__aeabi_memclr4:
	// r2: fill with 0
	mov	r2,#0

	// r3 := length & ~0x3
	bic	r3, r1, #3

	// call __aeabi_memset if length<4
	cmp	r3, #0
	it	eq
	beq	__aeabi_memset

	// r3 := end of 4 byte aligned destination
	add	r3, r0
	// r1 := length of rest to fill with aeabi_memset
	and	r1, r1, #3

	// fill (aligned) array with value
1:
	str	r2, [r0], #4
	cmp	r0, r3
	blo	1b

	// fill rest (<4 bytes) with aeabi_memset
	b	__aeabi_memset



.align 2
.globl __aeabi_memcpy
// r0: dest
// r1: src
// r2: length
__aeabi_memcpy:
	// do nothing if length == 0
	cmp	r2, #0
	it	eq
	bxeq	lr

	// r2 := end of array
	add	r2, r1

	// copy array via ldrb/strb
1:
	ldrb	r3, [r1], #1
	strb	r3, [r0], #1
	cmp	r1, r2
	blo	1b

	// return
	bx	lr


.align 2
.globl __aeabi_memcpy4
// r0: dest
// r1: src
// r2: length
__aeabi_memcpy4:
	// r3 := length & ~0x3
	bic	r3, r2, #3

	// call __aeabi_memcpy if length<4
	cmp	r3, #0
	it	eq
	beq	__aeabi_memcpy

	// r12 := end of 4 byte aligned source
	add.w	r12, r1, r3

	// copy (aligned) array
1:
	ldr	r3, [r1], #4
	str	r3, [r0], #4
	cmp	r1, r12
	blo	1b

	// copy rest (<4 bytes) with aeabi_memcpy
	and	r2, r2, #3
	b	__aeabi_memcpy
