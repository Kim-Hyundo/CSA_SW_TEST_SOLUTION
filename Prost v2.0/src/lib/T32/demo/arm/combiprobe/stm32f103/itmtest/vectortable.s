.file   "vectortable.s"
.section .vectortable, "ax"
.globl _vectortable
_vectortable:
	.word   0   /* 0x00    -         */
	.word   0   /*       Reset       */
	.word   0   /*       NMI         */
	.word   0   /*       Hard Fault  */
	.word   0   /* 0x10  Mem Manage  */
	.word   0   /*       Bus Fault   */
	.word   0   /*       Usage Fault */
	.word   0   /*         -         */
	.word   0   /* 0x20    -         */
	.word   0   /*                   */
	.word   0   /*                   */
	.word   0   /*       SVCall      */
	.word   0   /* 0x30  Debug Mon   */
	.word   0   /*       -           */
	.word   0   /*       PendSV      */
	.word   0   /*       SysTick     */
	.word   0   /* 0x40  IRQ   0     */
	.word   0   /*       IRQ   1     */
	.word   0   /*       IRQ   2     */
	.word   0   /*       IRQ   3     */
	.word   0   /* 0x50  IRQ   4     */
	.word   0   /*       IRQ   5     */
	.word   0   /*       IRQ   6     */
	.word   0   /*       IRQ   7     */
	.word   0   /* 0x60  IRQ   8     */
	.word   0   /*       IRQ   9     */
	.word   0   /*       IRQ  10     */
	.word   0   /*       IRQ  11     */
	.word   0   /* 0x70  IRQ  12     */
	.word   0   /*       IRQ  13     */
	.word   0   /*       IRQ  14     */
	.word   0   /*       IRQ  15     */
	.word   0   /* 0x80  IRQ  16     */
	.word   0   /*       IRQ  17     */
	.word   0   /*       IRQ  18     */
	.word   0   /*       IRQ  19     */
	.word   0   /* 0x90  IRQ  20     */
	.word   0   /*       IRQ  21     */
	.word   0   /*       IRQ  22     */
	.word   0   /*       IRQ  23     */
	.word   0   /* 0xA0  IRQ  24     */
	.word   0   /*       IRQ  25     */
	.word   0   /*       IRQ  26     */
	.word   0   /*       IRQ  27     */
 	.word	timerInterrupt
