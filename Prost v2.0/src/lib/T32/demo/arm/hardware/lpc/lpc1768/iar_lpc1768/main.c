
#include <intrinsics.h>
#include <stdio.h>
#include <nxp/iolpc1768.h>
#include <assert.h>

#include "board.h"

#define TIMER0_TICK_PER_SEC   10
#define TIMER0_IN_FREQ        25000000

static int mstatic1;
char vchar;

/*variable for clitical section entry control*/
Int32U CriticalSecCntr;
/*************************************************************************
 * Function Name: NVIC_IntEnable
 * Parameters: IntNumber - Interrup number
 * Return: void
 *
 * Description: Enable interrup at NVIC
 *
 *
 *************************************************************************/
void NVIC_IntEnable(Int32U IntNumber)
{
volatile unsigned long * pNVIC_SetEn = &SETENA0;

  assert((NVIC_WDT <= IntNumber) && (NVIC_PLL1 >= IntNumber));
  IntNumber -= NVIC_WDT;

  pNVIC_SetEn += IntNumber/32;
  *pNVIC_SetEn |= (1UL<<(IntNumber%32));

}

/*************************************************************************
 * Function Name: NVIC_IntDisable
 * Parameters: IntNumber - Interrup number
 * Return: void
 *
 * Description: Disables interrup at NVIC
 *
 *
 *************************************************************************/
void NVIC_IntDisable(Int32U IntNumber)
{
volatile unsigned long * pNVIC_ClrEn = &CLRENA0;

  assert((NVIC_WDT <= IntNumber) && (NVIC_PLL1 >= IntNumber));
  IntNumber -= NVIC_WDT;

  pNVIC_ClrEn += IntNumber/32;
  *pNVIC_ClrEn |= (1UL<<(IntNumber%32));

}

/*************************************************************************
 * Function Name: NVIC_ClrPend
 * Parameters: IntNumber - Interrup number
 * Return: void
 *
 * Description:Clear pending interrupt at NVIC
 *
 *
 *************************************************************************/
void NVIC_ClrPend(Int32U IntNumber)
{
volatile unsigned long * pNVIC_ClrPend = &CLRPEND0;

  assert((NVIC_WDT <= IntNumber) && (NVIC_PLL1 >= IntNumber));
  IntNumber -= NVIC_WDT;

  pNVIC_ClrPend += IntNumber/32;
  *pNVIC_ClrPend |= (1UL<<(IntNumber%32));

}

/*************************************************************************
 * Function Name: NVIC_ClrPend
 * Parameters: IntNumber - Interrup number, Interrupt Priority
 * Return: void
 *
 * Description:Sets Interrupt priority
 *
 *
 *************************************************************************/
void NVIC_IntPri(Int32U IntNumber, Int8U Priority)
{
volatile Int8U * pNVIC_IntPri = (Int8U *)&IP0;

  assert((NVIC_WDT <= IntNumber) && (NVIC_PLL1 >= IntNumber));
  IntNumber -= NVIC_WDT;
  pNVIC_IntPri += IntNumber;
  *pNVIC_IntPri = Priority;
}

/*************************************************************************
 * Function Name: TMR0_IRQHandler
 * Parameters: none
 *
 * Return: none
 *
 * Description: Timer 0 interrupt handler
 *
 *************************************************************************/
void TMR0_IRQHandler (void)
{
  /* Toggle LED1 */
  LED1_FIO ^= LED1_MASK;
  /*clear interrupt */
  T0IR_bit.MR0INT = 1;
  /**/
  NVIC_ClrPend(NVIC_TIMER0);
}

#define FCCLK_FREQ 100000000
/*************************************************************************
 * Function Name: InitClock
 * Parameters: void
 * Return: void
 *
  * Description: Initialize PLL and clocks' dividers. Hclk - 300MHz,
 *              Fcckl = 100MHz
 *
 *************************************************************************/
void InitClock(void)
{
  // 1. Init OSC
  SCS_bit.OSCRANGE = 0;
  SCS_bit.OSCEN = 1;
  // 2.  Wait for OSC ready
  while(!SCS_bit.OSCSTAT);
  // 3. Disconnect PLL
  PLL0CON_bit.PLLC = 0;
  PLL0FEED = 0xAA;
  PLL0FEED = 0x55;
  // 4. Disable PLL
  PLL0CON_bit.PLLE = 0;
  PLL0FEED = 0xAA;
  PLL0FEED = 0x55;
  // 5. Select source clock for PLL
  CLKSRCSEL_bit.CLKSRC = 1; // Selects the main oscillator as a PLL clock source.
  // 6. Set PLL settings 300 MHz
  PLL0CFG_bit.MSEL = 25-1;
  PLL0CFG_bit.NSEL = 2-1;
  PLL0FEED = 0xAA;
  PLL0FEED = 0x55;
  // 7. Enable PLL
  PLL0CON_bit.PLLE = 1;
  PLL0FEED = 0xAA;
  PLL0FEED = 0x55;
  // 8. Wait for the PLL to achieve lock
  while(!PLL0STAT_bit.PLOCK);
  // 9. Set clk divider settings
  CCLKCFG   = 3-1;            // 1/3 Fpll
  PCLKSEL0 = PCLKSEL1 = 0;    // other peripherals 100/4 = 25MHz
  // 10. Connect the PLL
  PLL0CON_bit.PLLC = 1;
  PLL0FEED = 0xAA;
  PLL0FEED = 0x55;
}

/*************************************************************************
 * Function Name: GpioInit
 * Parameters: void
 * Return: void
 *
 * Description: Reset all GPIO pins to default: primary function
 *
 *************************************************************************/
void GpioInit(void)
{
  // Set to inputs
  FIO0DIR = \
  FIO1DIR = \
  FIO2DIR = \
  FIO3DIR = \
  FIO4DIR = 0;

  // clear mask registers
  FIO0MASK =\
  FIO1MASK =\
  FIO2MASK =\
  FIO3MASK =\
  FIO4MASK = 0;

  // Reset all GPIO pins to default primary function
  PINSEL0 =\
  PINSEL1 =\
  PINSEL2 =\
  PINSEL3 =\
  PINSEL7 =\
  PINSEL8 =\
  PINSEL9 = 0;
  
  PINSEL4 = 0x3FF0;   //Map to ETM
  PINSEL10 = 0x08;    //Enable TPIU for ETM trace signals
}

////////////////////////////////////////////////////////////////////////////////
// func1
//
////////////////////////////////////////////////////////////////////////////////
static void func1( intptr )		/* static function */
int * intptr;
{
  (*intptr)++;
}

///////////////////////////////////////////////////////////////////////////////
// func2
//
///////////////////////////////////////////////////////////////////////////////
void func2()
{
  int autovar;
  register int regvar;
  static int fstatic = 44;	/* initialized static variable */
  static int fstatic2;		/* not initialized static variable */

  autovar = regvar = fstatic;
  autovar++;

  func1( &autovar );	/* to force autovar as stack-scope */

  func1( &fstatic );	/* to force fstatic as static-scope */

  for ( regvar = 0; regvar < 5 ; regvar++ )
    mstatic1 += regvar*autovar;

  fstatic += mstatic1;

  fstatic2 = 2*fstatic;

  func1( &fstatic2 );
}

//////////////////////////////////////////////////////////////////////////////
// func2a
//
//////////////////////////////////////////////////////////////////////////////
void func2a()
{
  auto char autovar;	/* char stack variable */
  register char regvar;	/* char register variable */

  autovar = regvar = mstatic1;
  autovar++;

  for ( regvar = 0; regvar < (char) 5 ; regvar++ )
    vchar += regvar*autovar;
}


///////////////////////////////////////////////////////////////////////////////
// func9
//
///////////////////////////////////////////////////////////////////////////////
static int * func9()			/* nested local variables */
{
  static int stat1 = 0;
  register unsigned int reg1;
  auto int auto1;

  auto1 = stat1;

  for ( reg1 = 0 ; reg1 < 2 ; reg1++ )
  {
    static int stat2 = 0;
    register unsigned int reg2;
    auto int auto2;

    auto2 = stat2;

    for ( reg2 = 0 ; reg2 < reg1 ; reg2++ )
    {
      func1( &stat1 );
      func1( &auto1 );
      func1( &stat2 );
      func1( &auto2 );
    }
  }

  return &stat1;
}

/////////////////////////////////////////////////////////////////////////
// sieve
//
////////////////////////////////////////////////////////////////////////
//#define TRUE 1
#define FASLE 0
#define SIZE 18
char flags[SIZE+1];
int anzahl;

void sieve(void)
{
  register int i, primz, k;
  
  for ( i = 0 ; i <= SIZE ; flags[ i++ ] = TRUE ) ;
  
  for ( i = 0 ; i <= SIZE ; i++ )
  {
    if ( flags[ i ] )
    {
      primz = i + i + 3;
      k = i + primz;
      while ( k <= SIZE )
      {
        flags[ k ] = FALSE;
        k += primz;
      }
      anzahl++;
    }
  }
}


/*************************************************************************
 * main
 *************************************************************************/
int main(void)
{
  // Flash accelerator init
  FLASHCFG = (0x5UL<<12) | 0x3AUL;
  // Init clock
  InitClock();
#if FCCLK_FREQ < 20000000
  FLASHCFG = (0x0UL<<12) | 0x3AUL;
#elif FCCLK_FREQ < 40000000
  FLASHCFG = (0x1UL<<12) | 0x3AUL;
#elif FCCLK_FREQ < 60000000
  FLASHCFG = (0x2UL<<12) | 0x3AUL;
#elif FCCLK_FREQ < 80000000
  FLASHCFG = (0x3UL<<12) | 0x3AUL;
#elif FCCLK_FREQ < 100000000
  FLASHCFG = (0x4UL<<12) | 0x3AUL;
#endif
  // Init GPIO
  GpioInit();
  // Init LED1 Pin
  LED1_FDIR = LED1_MASK;
  LED1_FSET = LED1_MASK;

  // Enable TIM0 clocks
 // PCONP_bit.PCTIM0 = 1; // enable clock

  // Init Time0
//  T0TCR_bit.CE = 0;     // counting  disable
//  T0TCR_bit.CR = 1;     // set reset
//  T0TCR_bit.CR = 0;     // release reset
//  T0CTCR_bit.CTM = 0;   // Timer Mode: every rising PCLK edge
//  T0MCR_bit.MR0I = 1;   // Enable Interrupt on MR0
//  T0MCR_bit.MR0R = 1;   // Enable reset on MR0
//  T0MCR_bit.MR0S = 0;   // Disable stop on MR0
  // set timer 0 period
//  T0PR = 18-1;
//  T0MR0 = (TIMER0_IN_FREQ)/(18 * TIMER0_TICK_PER_SEC);
  // init timer 0 interrupt
//  T0IR_bit.MR0INT = 1;  // clear pending interrupt
//  T0TCR_bit.CE = 1;     // counting Enable
  /*Enable NVIC TMR0 Interrupt*/
//  NVIC_IntEnable(NVIC_TIMER0);
//  __enable_interrupt();
  
  while(1)
  {
    func2();
    func2a();
    func9();
    sieve();
  }
}
