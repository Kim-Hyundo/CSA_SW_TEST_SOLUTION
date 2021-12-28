
#define GPFSEL0    ((volatile unsigned int *) 0x3F200000)
#define GPFSEL2    ((volatile unsigned int *) 0x3F200008)
#define GPPUD      ((volatile unsigned int *) 0x3F200094)
#define GPPUDCLK0  ((volatile unsigned int *) 0x3F200098)

void dummy (int i)
{
    return;
}

void wait_loop (int loop)
{
    unsigned int i;
    for(i=0;i<loop;i++) dummy(i);
}

int main( void )
{ 

    // Enable GPIO
    *GPPUD=0;
    wait_loop(1000);
    *GPPUDCLK0=0x0b400010;
    wait_loop(1000);
    *GPPUDCLK0=0;

    // GPIO4 alt5 -> TDI
    *GPFSEL0 =  0x00002000;
    // GPIO22,23,24,25,27 alt4 -> nTRST,RTCK,TDO,TCK,TMS
    *GPFSEL2 =  0x0061b6c0;

    while(1);

    return 0;
} 
