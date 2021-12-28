/* *********************************************************************** */
/* ROM Monitor Test Program for TriCore                                    */
/*                                                                         */
/* Version Information                                                     */
/* $LastChangedDate: 2014-04-01 10:32:02 +0200 (Tue, 01 Apr 2014) $         */
/* $LastChangedRevision: 6599 $                                           */
/* $LastChangedBy: mobermeir $                                            */
/*                                                                         */
/* (c) Lauterbach Datentechnik GmbH                                        */
/* *********************************************************************** */



/* *********************************************************************** */
/* Important Note                                                         */
/* The ROM Monitor expects to have both the upper and lower context. An    */
/* Exception (Interrupt, Trap) or call instruction only saves the lower    */
/* context. It is compiler dependent whether a svlcx/ rslcx instruction    */
/* is inserted when entering/ leaving the Exception handler or the called  */
/* function. This may also depend on the optimizion switches.              */
/* the examle.
/* *********************************************************************** */



/* externs from Monitor */
#pragma extern Monitor_EntryReset
#pragma extern Monitor_EntryBusError
#pragma extern Monitor_EntryTrap
#pragma extern Monitor_EntryBreak

extern unsigned int MON_SR;    /* 32 bit Monitor Status Register */



/* ----------------------------------------------------------------------- */
/* Call to Monitor on reset.                                               */
/* Enables debug support in chip and configures Monitor Interface.         */
/* CSA areas must already be configured and valid.                         */

void Monitor_Init(void)
{
	/* TASKING v2.5rb saves the lower context in case of an Exception. For
	 * a correct register display the Monitor also requires this for the
	 * Monitor entry via reset.
	 */

	__asm("svlcx");
	__asm("jl Monitor_EntryReset");
	__asm("rslcx");
	__asm("nop");
}


/* ----------------------------------------------------------------------- */
/* Interrupt Handler for Serial Interface ASC0.                            */
/* Used for asynchronous break, hightest priority.                         */

void __interrupt(0xff) ISR_ASC0(void)
{
	/* ASC0 is the only interrupt source using the highest priority level */
	__asm("jl Monitor_EntryBreak");
}


/* ----------------------------------------------------------------------- */
/* Trap Handler for Instruction Errors (Class 2).                          */

void __trap(2) Trap_InstructionError(void)
{
	int TIN;    /* Trap ID */

	__asm("mov %0,d15" : "=d"(TIN));    /* get TIN from Register D15 */

	switch (TIN) {
		case 1:    /* IOPC - Illegal Opcode                */
			/* enter Monitor (Software Breakpoint 0)       */
			__asm("jl Monitor_EntryBreak");
			break;
		case 2:    /* UOPC - Unimplemented Opcode          */
		case 3:    /* OPD  - Invalid operand specification */
		case 4:    /* ALN  - Data address alignment error  */
		case 5:    /* MEM  - Invalid local memory address  */
			/* implement your own debug handler here       */
			/* or enter Monitor by default                 */
		default:
			/* enter Monitor */
			__asm("jl Monitor_EntryTrap");
	}
}


/* ----------------------------------------------------------------------- */
/* Trap Handler for Context Traps (Class 4).                               */
/* Just an example if the Monitor should be entered in case of this trap.  */

void __trap(2) Trap_Context(void)
{
	__asm("jl Monitor_EntryTrap");
	return;
}


/* ----------------------------------------------------------------------- */
/* Trap Handler for Bus Errors (Class 4).                                  */
/* Just an example if the Monitor should be entered in case of this trap.  */

void __trap(4) Trap_BusError(void)
{
	__asm("jl Monitor_EntryBusError");
	return;
}



/* ----------------------------------------------------------------------- */
/* main() program.                                                         */

void main(void)
{
	int a, b, c;

	Monitor_Init();     /* initialize Monitor for debug and setup Interface */
	__enable();         /* enable Interrupts */


	/* this loop represents the user application */
	while(1) {
		a = 5;
		b = 3;

		c = a + b;
	};
}



/* *********************************************************************** */
/* End                                                                     */
/* *********************************************************************** */
