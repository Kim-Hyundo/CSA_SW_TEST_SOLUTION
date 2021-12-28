#include <stdint.h>

volatile uint32_t* const RCC_AHB1ENR   = (uint32_t*)0x40023830;

volatile uint32_t* const GPIOD = (uint32_t*)0x40020C00;
volatile uint32_t* const GPIOF = (uint32_t*)0x40021400;
volatile uint32_t* const GPIOG = (uint32_t*)0x40021800;
volatile uint32_t* const GPIOH = (uint32_t*)0x40021C00;
volatile uint32_t* const GPIOI = (uint32_t*)0x40022000;

enum{
	GPIOx_MODER   = 0,
	GPIOx_OTYPER  = 1,
	GPIOx_OSPEEDR = 2,
	GPIOx_PUPDR   = 3,
	GPIOx_IDR     = 4,
	GPIOx_ODR     = 5
};

#define IO_CFG_OUTPUT(GPIO,PIN) do { \
	GPIO[GPIOx_MODER]   = (GPIO[GPIOx_MODER] & ~(3<<(2*(PIN)))) | (1<<(2*(PIN))); /* Configure PIN as output */ \
	GPIO[GPIOx_OTYPER]  &= ~(1<<(PIN));     /* Configure PIN as "push-pull"  */ \
	GPIO[GPIOx_OSPEEDR] &= ~(3<<(2*(PIN))); /* Configure PIN for "low speed" */ \
	GPIO[GPIOx_PUPDR]   &= ~(3<<(2*(PIN))); /* Configure PIN without pull-up or pull-down */ \
} while(0)

#define IO_CFG_INPUT(GPIO,PIN) do { \
	GPIO[GPIOx_MODER]   = (GPIO[GPIOx_MODER] & ~(3<<(2*(PIN)))); /* Configure PIN as input */ \
	GPIO[GPIOx_OTYPER]  &= ~(1<<(PIN));     /* Configure PIN as "push-pull"  */ \
	GPIO[GPIOx_OSPEEDR] &= ~(3<<(2*(PIN))); /* Configure PIN for "low speed" */ \
	GPIO[GPIOx_PUPDR]   &= ~(3<<(2*(PIN))); /* Configure PIN without pull-up or pull-down */ \
} while(0)


static volatile uint32_t* const ITM_BASE = (uint32_t *)0xE0000000;

#define ITM_TRACE_D8(_channel_,_data_) { \
	volatile uint8_t *_ch_ = (uint8_t *)(ITM_BASE+(_channel_)); \
	while ( *_ch_ == 0); \
	(*((volatile uint8_t *)(_ch_)))=(_data_); \
}

#define ITM_TRACE_D16(_channel_,_data_) { \
	volatile uint16_t *_ch_ = (uint16_t *)(ITM_BASE+(_channel_)); \
	while ( *_ch_ == 0); \
	(*((volatile uint16_t *)(_ch_)))=(_data_); \
}

#define ITM_TRACE_D32(_channel_,_data_) { \
	volatile uint32_t *_ch_ = ITM_BASE+(_channel_); \
	while ( *_ch_ == 0); \
	*_ch_ = (_data_); \
}


int DiscoveryBoard = 0;
/* STM32F4-Discovery board  |  KEIL MCBSTM32F400
 *   PD12 : LED green       |    PH3
 *   PD13 : LED orange      |    PH6
 *   PD14 : LED red         |    PH7
 *   PD15 : LED blue        |    PI10
 *   PD15 : LED blue        |    PG6
 *                          |    PG7
 *                          |    PG8
 *                          |    PH2
 */

static int LED_InitGpio(void)
{
	DiscoveryBoard = 0;

	*RCC_AHB1ENR   |= 0x20;  /* Enable clock for GPIO port F */
	IO_CFG_OUTPUT(GPIOF,7);     /* Configure PF7 as output */
	GPIOF[GPIOx_ODR] = 1<<7; /* Set PF7 to High */

	if (!(GPIOF[GPIOx_IDR] & (1<<7)))  /* On the Dicovery Board PF7 will not become high since the pin does not exist on the used LQFP100 package.*/
		DiscoveryBoard = 1;

	GPIOF[GPIOx_ODR] &= ~(1<<7); /* Set PF7 to Low */
	*RCC_AHB1ENR &= ~0x20;       /* Disable clock for GPIO port F */

	if (DiscoveryBoard){
		*RCC_AHB1ENR  |= 0x08;   /* Enable clock for GPIO port D */
		IO_CFG_OUTPUT(GPIOD,12);
		IO_CFG_OUTPUT(GPIOD,13);
		IO_CFG_OUTPUT(GPIOD,14);
		IO_CFG_OUTPUT(GPIOD,15);
	} else {
		*RCC_AHB1ENR   |= 0x1C0;  /* Enable clock for GPIO port G, H and I */
		IO_CFG_OUTPUT(GPIOH,3);
		IO_CFG_OUTPUT(GPIOH,6);
		IO_CFG_OUTPUT(GPIOH,7);
		IO_CFG_OUTPUT(GPIOI,10);
		IO_CFG_OUTPUT(GPIOG,6);
		IO_CFG_OUTPUT(GPIOG,7);
		IO_CFG_OUTPUT(GPIOG,8);
		IO_CFG_OUTPUT(GPIOH,2);
		IO_CFG_INPUT(GPIOG,15);
	}
	return DiscoveryBoard;
}


void LED_Blink(void)
{
	static int init = 1;
	static int evt = 0;
	static int cnt = 0;
	static uint8_t led = 0;
	static const uint8_t pattern1[] = {0x1,0x1,0x3,0x2,0x2,0x6,0x4,0x4,0xC,0x8,0x8,0x9};
	static const uint8_t pattern2[] = {0x81,0x81,0xC3,0x42,0x42,0x66,0x24,0x24,0x3c,0x18,0x18,0x3c,0x24,0x24,0x66,0x42,0x42,0xC3,0x81,0x81,0x00};
	static const uint8_t pattern3[] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x00};
	static const uint8_t *pattern;
	static int size = 0;

	evt++;
	if (evt < 128)
		return;
	evt = 0;

	if (init) {
		LED_InitGpio();
		init = 0;
	}

	if (DiscoveryBoard){
		pattern = pattern1;
		size = sizeof(pattern1);
	} else if (!(GPIOG[GPIOx_IDR] & 0x8000)){ /* USER button pushed ? */
		/* user pattern in reverse order */
		pattern = pattern3;
		size = sizeof(pattern3);
	} else {
		pattern = pattern2;
		size = sizeof(pattern2);
	}

	cnt = (cnt + 1) % size;
	led = pattern[cnt];

	if (DiscoveryBoard){
		uint32_t ioD = GPIOD[GPIOx_IDR];
		ioD = (led << 12) | (ioD & 0x0fff);
		GPIOD[GPIOx_ODR] = ioD;
	} else {
		uint32_t ioI = GPIOI[GPIOx_IDR];
		uint32_t ioG = GPIOG[GPIOx_IDR];
		uint32_t ioH = GPIOH[GPIOx_IDR];
		ioH = !!(led & 0x01) << 3 | (ioH & ~(1<<3));
		ioH = !!(led & 0x02) << 6 | (ioH & ~(1<<6));
		ioH = !!(led & 0x04) << 7 | (ioH & ~(1<<7));
		ioI = !!(led & 0x08) <<10 | (ioI & ~(1<<10));
		ioG = !!(led & 0x10) << 6 | (ioG & ~(1<<6));
		ioG = !!(led & 0x20) << 7 | (ioG & ~(1<<7));
		ioG = !!(led & 0x40) << 8 | (ioG & ~(1<<8));
		ioH = !!(led & 0x80) << 2 | (ioH & ~(1<<2));
		GPIOI[GPIOx_ODR] = ioI;
		GPIOG[GPIOx_ODR] = ioG;
		GPIOH[GPIOx_ODR] = ioH;
	}

	ITM_TRACE_D8(0,led); // Enable ITM messages with "Data.Set E:0xE0000E00 %LONG 0xFFFFFFFF"

}

