/* 32 bit integer */
#define u_int32 unsigned int

/* integer as wide as a "void *", so as wide as a machine word */
#define u_intptr unsigned int

static volatile unsigned int  *g_itmBase = (volatile unsigned int *)0xE0000000;
#define ITM_ENABLE_ACCESS  g_itmBase[0x3EC]=0xC5ACCE55
#define ITM_TRACE_PRIV     g_itmBase[0x390]
#define ITM_TRACE_ENABLE   g_itmBase[0x380]

#define ITM_TRACE_BYTE(_channel_,_data_) (*((volatile unsigned char *)(g_itmBase+(_channel_))))=(unsigned char)(_data_)
#define ITM_TRACE_WORD(_channel_,_data_) (*((volatile unsigned short *)(g_itmBase+(_channel_))))=(unsigned short)(_data_)
#define ITM_TRACE_DWORD(_channel_,_data_) (*(g_itmBase+(_channel_)))=(unsigned int)(_data_)
#define ITM_WAIT_FOR_CHANNEL_READY(_channel_) while ((*(g_itmBase+(_channel_)))==0)

#define ITM_PUT_BYTE(_channel_,_data_) \
	ITM_WAIT_FOR_CHANNEL_READY(_channel_); \
	ITM_TRACE_BYTE(_channel_,_data_)

#define ITM_PUT_WORD(_channel_,_data_) \
	ITM_WAIT_FOR_CHANNEL_READY(_channel_); \
	ITM_TRACE_WORD(_channel_,_data_)

#define ITM_PUT_DWORD(_channel_,_data_) \
	ITM_WAIT_FOR_CHANNEL_READY(_channel_); \
	ITM_TRACE_DWORD(_channel_,_data_)

