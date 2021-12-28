#include <stdint.h>

volatile uint32_t* const ITM_BASE = (uint32_t *)0xF8805000;

#define ITM_ENABLE_ACCESS()      ITM_BASE[0x3EC]=0xC5ACCE55  /* magic value to Lock Access Register (LAR) to unlock other ITM registers */
#define ITM_TRACE_ENABLE(mask)   ITM_BASE[0x380]=mask /* Trace Enable Register (TER) */

#ifdef ITM_BLOCKING
# define ITM_TRACE_D8(_channel_,_data_) { \
	volatile uint8_t *_ch_ = (uint8_t *)(ITM_BASE+(_channel_)); \
	while ( *_ch_ == 0); \
	(*((volatile uint8_t *)(_ch_)))=(_data_); \
  }
# define ITM_TRACE_D16(_channel_,_data_) { \
	volatile uint16_t *_ch_ = (uint16_t *)(ITM_BASE+(_channel_)); \
	while ( *_ch_ == 0); \
	(*((volatile uint16_t *)(_ch_)))=(_data_); \
  }
# define ITM_TRACE_D32(_channel_,_data_) { \
	volatile uint32_t *_ch_ = ITM_BASE+(_channel_); \
	*_ch_ = (_data_); \
  }
#else
# define ITM_TRACE_D8(_channel_,_data_) { \
	(*((volatile uint8_t *)(ITM_BASE+(_channel_)))) = (_data_); \
  }
# define ITM_TRACE_D16(_channel_,_data_) { \
	(*((volatile uint16_t *)(ITM_BASE+(_channel_)))) = (_data_); \
  }
# define ITM_TRACE_D32(_channel_,_data_) { \
	*(ITM_BASE+(_channel_)) = (_data_); \
  }
#endif


extern signed short int plot1, plot2;

void ItmMessage(void)
{
	static int init = 1;
	if (init) {
		ITM_ENABLE_ACCESS();
		ITM_TRACE_ENABLE(0xFFFFFFFF); /* enable all 32 ITM ports */
		init = 0;
	}

	ITM_TRACE_D16(0,plot1);
	ITM_TRACE_D16(1,plot2);
}

