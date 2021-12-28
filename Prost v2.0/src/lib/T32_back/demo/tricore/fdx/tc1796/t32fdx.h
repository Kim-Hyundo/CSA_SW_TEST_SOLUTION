

#ifdef	__cplusplus
extern "C" {
#endif

typedef unsigned int T32_FDX_PARAMETERTYPE;
typedef unsigned char T32_FDX_DATATYPE;

typedef struct {
	volatile T32_FDX_PARAMETERTYPE enable;
	volatile T32_FDX_PARAMETERTYPE size;
	volatile T32_FDX_PARAMETERTYPE hostindex;
	volatile T32_FDX_PARAMETERTYPE targetindex;
	volatile T32_FDX_PARAMETERTYPE stall;
	volatile T32_FDX_PARAMETERTYPE pending;
	volatile T32_FDX_PARAMETERTYPE transferlen;
	volatile T32_FDX_PARAMETERTYPE resv4;
} T32_FDX_BUFFER;


#define T32_Fdx_DefineChannel(channel,size)		struct { T32_FDX_BUFFER header; volatile T32_FDX_DATATYPE data[size]; } channel

#define T32_Fdx_InitChannel(channel)			((channel).header.enable = 0, (channel).header.size = 0, (channel).header.hostindex = 0, (channel).header.targetindex = 0, (channel).header.stall = 0, (channel).header.pending = 0, (channel).data[0] = 0)

#define T32_Fdx_EnableChannel(channel)			((channel).header.size = sizeof((channel).data))

#define T32_Fdx_DisableChannel(channel)			((channel).header.size = 0)

#define T32_Fdx_Pending(channel)			((channel)->header.hostindex != (channel)->header.targetindex)

extern int T32_Fdx_SendPoll(void * channel, void * buf, int size);
extern int T32_Fdx_Send(void * channel, void * buf, int size);

extern int T32_Fdx_ReceivePoll(void * channel, void * buf, int maxsize);
extern int T32_Fdx_Receive(void * channel, void * buf, int size);

extern void T32_Fdx_Poll(void);
extern void T32_Fdx_PollInterrupt(void);

int T32_Fdx_Send15(void * channel, void * buf);

#ifdef	__cplusplus
}
#endif
