#define GPFSEL0 ((volatile unsigned int *) 0x20200000)
#define GPFSEL1 ((volatile unsigned int *) 0x20200004)
#define GPFSEL2 ((volatile unsigned int *) 0x20200008)
#define GPCLR0  ((volatile unsigned int *) 0x20200028)

void JTAG_Enable()
{ 
  // GPIO4 alt5 -> TDI
  *GPFSEL0 &= ~0x00007000; 
  *GPFSEL0 |=  0x00002000;

  // GPIO22,23,24,25,27 alt4 -> nTRST,RTCK,TDO,TCK,TMS
  *GPFSEL2 &= ~0x00e3ffc0;
  *GPFSEL2 |=  0x0061b6c0;

  // GPIO16 output, clear -> switch on "OK" LED to check JTAG_Enable() got executed
  *GPFSEL1 &= ~0x001c0000; 
  *GPFSEL1 |=  0x00040000;
  *GPCLR0  |=  0x00010000;
 
loop:
  goto loop;
} 