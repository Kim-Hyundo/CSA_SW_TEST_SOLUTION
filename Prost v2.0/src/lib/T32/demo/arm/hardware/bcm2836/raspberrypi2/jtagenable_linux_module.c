
/**
 * File: jtagenable_linux_module.c
 * @Description: Linux module to enable jtag pins on raspberry pi2
 * @Author: YDA
 * @Board: Raspberry Pi2
 * @Chip: BCM2836
 * @Copyright: (C) 1989-2016 Lauterbach GmbH, licensed for use with TRACE32(R) only 
 * $Id: jtagenable_linux_module.c 10103 2016-10-17 14:14:02Z pegold $
*/

#include <linux/init.h>    
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sizes.h>
#include <linux/io.h>

MODULE_AUTHOR("YDA");
MODULE_DESCRIPTION("Linux module to enable jtag pins on raspberry pi2");

static void *GPPUD,*GPPUDCLK0,*GPFSEL0,*GPFSEL2 ;

void dummy (int i)
{
    return;
}

void wait_loop (int loop)
{
    unsigned int i;
    for(i=0;i<loop;i++) dummy(i);
}

 static int jtagenable_init(void){

    // Enable GPIO
    GPPUD = ioremap(0x3F200094, SZ_4K);
    writel(0x0,GPPUD);
    wait_loop(1000);

    GPPUDCLK0 = ioremap(0x3F200098, SZ_4K);
    writel(0x0b400010,GPPUDCLK0);    
	
	wait_loop(1000);
    GPPUDCLK0 = ioremap(0x3F200098, SZ_4K);
    writel(0x0,GPPUDCLK0); 
	
    // GPIO4 alt5 -> TDI
    GPFSEL0 = ioremap(0x3F200000, SZ_4K);
    writel(0x00002000,GPFSEL0); 
    
    // GPIO22,23,24,25,27 alt4 -> nTRST,RTCK,TDO,TCK,TMS
    GPFSEL2 = ioremap(0x3F200008, SZ_4K);
    writel(0x0061b6c0,GPFSEL2); 	
    
    return 0;
}
 

static void jtagenable_exit(void){

}
 
module_init(jtagenable_init);
module_exit(jtagenable_exit);
