extern void Monitor_Handler(void);


/* Interrupt Service Routine for Timer0 to serve monitor code
 *  for real-time memory access or
 * on an ARM922T Excalibur device
 */
void exc_isr() __attribute__ ((interrupt ("IRQ")));
void exc_isr()
{
	Monitor_Handler();
	*((unsigned int*)0x7FFFC200)=0x1C; // remove interrrupt from Timer0
}


/* Interrupt Service Routine for Timer0 to serve monitor code
 *  for real-time snooping of the PC
 * on an ARM922T Excalibur device
 */
void exc_snoop() __attribute__ ((interrupt ("IRQ")));
void exc_snoop()
{
	__asm__("mcr p14,0,r14,c1,c0"); // save location at which interrupt occured to DCC register
	*((unsigned int*)0x7FFFC200)=0x1C; // remove interrrupt from Timer0
}


