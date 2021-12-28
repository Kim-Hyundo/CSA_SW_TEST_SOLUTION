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
	.word   0   /* 0x040 IRQ   0     */
	.word   0   /*       IRQ   1     */
	.word   0   /*       IRQ   2     */
	.word   0   /*       IRQ   3     */
	.word   0   /* 0x050 IRQ   4     */
	.word   0   /*       IRQ   5     */
	.word   0   /*       IRQ   6     */
	.word   0   /*       IRQ   7     */
	.word   0   /* 0x060 IRQ   8     */
	.word   0   /*       IRQ   9     */
	.word   0   /*       IRQ  10     */
	.word   0   /*       IRQ  11     */
	.word   0   /* 0x070 IRQ  12     */
	.word   0   /*       IRQ  13     */
	.word   0   /*       IRQ  14     */
	.word   0   /*       IRQ  15     */
	.word   0   /* 0x080 IRQ  16     */
	.word   0   /*       IRQ  17     */
	.word   0   /*       IRQ  18     */
	.word   0   /*       IRQ  19     */
	.word   0   /* 0x090 IRQ  20     */
	.word   0   /*       IRQ  21     */
	.word   0   /*       IRQ  22     */
	.word   0   /*       IRQ  23     */
	.word   0   /* 0x0A0 IRQ  24     */
	.word   0   /*       IRQ  25     */
	.word   0   /*       IRQ  26     */
	.word   0   /*       IRQ  27     */
	.word   0   /* 0x0B0 IRQ  28     */
	.word   0   /*       IRQ  29     */
	.word   0   /*       IRQ  30     */
	.word   0   /*       IRQ  31     */
	.word   0   /* 0x0C0 IRQ  32     */
	.word   0   /*       IRQ  33     */
	.word   0   /*       IRQ  34     */
	.word   0   /*       IRQ  35     */
	.word   0   /* 0x0D0 IRQ  36     */
	.word   0   /*       IRQ  37     */
	.word   0   /*       IRQ  38     */
	.word   0   /*       IRQ  39     */
	.word   0   /* 0x0E0 IRQ  40     */
	.word   0   /*       IRQ  41     */
	.word   0   /*       IRQ  42     */
	.word   0   /*       IRQ  43     */
	.word   0   /* 0x0F0 IRQ  44     */
	.word   0   /*       IRQ  45     */
	.word   0   /*       IRQ  46     */
	.word   0   /*       IRQ  47     */
	.word   0   /* 0x100 IRQ  48     */
	.word   0   /*       IRQ  49     */
	.word   0   /*       IRQ  50     */
	.word   0   /*       IRQ  51     */
	.word   0   /* 0x110 IRQ  52     */
	.word   0   /*       IRQ  53     */
	.word   0   /*       IRQ  54     */
	.word   0   /*       IRQ  55     */
	.word   0   /* 0x120 IRQ  56     */
	.word   0   /*       IRQ  57     */
	.word   0   /*       IRQ  58     */
	.word   0   /*       IRQ  59     */
	.word   0   /* 0x130 IRQ  60     */
	.word   0   /*       IRQ  61     */
	.word   0   /*       IRQ  62     */
	.word   0   /*       IRQ  63     */
	.word   0   /* 0x140 IRQ  64     */
	.word   0   /*       IRQ  65     */
	.word   0   /*       IRQ  66     */
	.word   0   /*       IRQ  67     */
	.word   timerInterrupt
