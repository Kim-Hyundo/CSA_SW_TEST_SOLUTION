
#include "string.h"
#include "t32fdx.h"

#define T32_FDX_TRACE_UNCOMPRESSED
#define T32_FDX_TRACE_BUFSIZE 5000
/**************************************************************************

	TRACE32 FDX target agent

	03/09/12						initial release
	06/03/21            corrected length decoding in UnbufferedReceiveDCC
	
	possible defines:
	
	T32_FDX_TRACE_COMPRESSED		enable compressed trace
	T32_FDX_TRACE_UNCOMPRESSED		enable uncompressed trace
	T32_FDX_DCC4						set for DCC based communication
	T32_FDX_DCC8					set for DCC8 based communication

	external calls:

	T32_Fdx_GetTimebase()			return timebase (used for trace only)
	
**************************************************************************/


#define T32_FDX_DOORBELL()

#define T32_FDX_WAITING()

#define T32_FDX_INTDISABLE()

#define T32_FDX_INTENABLE()

#define T32_FDX_COPY(t,s,l)	memcpy((t),(s),(l))

void * T32_Fdx_SendingChannel;
void * T32_Fdx_ReceivingChannel;


/**************************************************************************

	DCC polling functions
	
**************************************************************************/

#ifdef T32_FDX_DCC4
#define T32_FDX_DCC
#endif
#ifdef T32_FDX_DCC8
#define T32_FDX_DCC
#endif


#ifdef T32_FDX_DCC



extern unsigned long T32_TsMon_SendStatus(void);
extern unsigned long T32_TsMon_ReceiveStatus(void);
#ifdef T32_FDX_DCC4
extern void T32_TsMon_SendWord(unsigned long data);
extern unsigned long T32_TsMon_ReceiveWord(void);
#else
extern void T32_TsMon_SendWord_DCC8(unsigned long nLSBData,unsigned long nMSBData);
extern void T32_TsMon_ReceiveWord_DCC8(unsigned long* nLSBData,unsigned long* nMSBData);
#endif



#ifdef T32_FDX_DCC4
#define DCCLEN 4
#endif
#ifdef T32_FDX_DCC8
#define DCCLEN 8
#endif


unsigned char nByteCountInCurrentWord = 0;
unsigned long  nCurrentWordLo = 0;
#ifdef T32_FDX_DCC8
unsigned long  nCurrentWordHi = 0;
#endif

void UnbufferedSendDCCByte(unsigned char bSend)
{
	switch (nByteCountInCurrentWord)
	{
		case 0:
			nCurrentWordLo = bSend;
			break;
		case 1:
			nCurrentWordLo |= (bSend << 8);
			break;
		case 2:
			nCurrentWordLo |= (bSend << 16);
			break;
		case 3:
			nCurrentWordLo |= (bSend << 24);
#ifdef T32_FDX_DCC8
		case 4:
			nCurrentWordHi = bSend;
			break;
		case 5:
			nCurrentWordHi |= (bSend << 8);
			break;
		case 6:
			nCurrentWordHi |= (bSend << 16);
			break;
		case 7:
			nCurrentWordHi |= (bSend << 24);	
#endif
	}
	nByteCountInCurrentWord++;
	if (nByteCountInCurrentWord >= DCCLEN)
	{
	  while (T32_TsMon_SendStatus()){;} //Wait 
#ifdef T32_FDX_DCC4
	  T32_TsMon_SendWord(nCurrentWordLo);	
#endif
#ifdef T32_FDX_DCC8
	  T32_TsMon_SendWord_DCC8(nCurrentWordLo,nCurrentWordHi);
#endif
	   nByteCountInCurrentWord = 0;	
	}
}

void UnbufferedSendDCCFlush()
{
	while (nByteCountInCurrentWord) UnbufferedSendDCCByte(0);
}

int UnbufferedSendDCC(unsigned char *pBuffer, int nLength)
{
	int nRetLen = nLength;
	if (nLength > 0xFA)
	{
			UnbufferedSendDCCByte(0xFE);
  	  UnbufferedSendDCCByte((unsigned char) (nLength & 0xFF));
 	    UnbufferedSendDCCByte((unsigned char) ((nLength >>8) & 0xFF));
	} else
	{
		UnbufferedSendDCCByte(nLength);
	}
	while (nLength)
	{
		UnbufferedSendDCCByte(*pBuffer);
		nLength--;
		pBuffer++;
	}
	UnbufferedSendDCCFlush();	
	return nRetLen;
}

unsigned char UnbufferedReadDCCByte()
{
	unsigned char nResult;
	nResult = 0;
	if (!nByteCountInCurrentWord)
	{
	 	while (!T32_TsMon_ReceiveStatus()){;}
#ifdef T32_FDX_DCC4
	nCurrentWordLo = T32_TsMon_ReceiveWord();
#endif
#ifdef T32_FDX_DCC8
	T32_TsMon_ReceiveWord_DCC8(&nCurrentWordLo,&nCurrentWordHi);
#endif
	}
	switch(nByteCountInCurrentWord)
	{
		case 0:
			nResult	= (unsigned char) (nCurrentWordLo & 0xFF);
			break;
		case 1:
			nResult	= (unsigned char) ((nCurrentWordLo >> 8) & 0xFF);
			break;
		case 2:
			nResult	= (unsigned char) ((nCurrentWordLo >> 16) & 0xFF);
			break;
		case 3:
			nResult	= (unsigned char) ((nCurrentWordLo >> 24) & 0xFF);
			break;
#ifdef T32_FDX_DCC8
		case 4:
			nResult	= (unsigned char) (nCurrentWordHi & 0xFF);
			break;
		case 5:
			nResult	= (unsigned char) ((nCurrentWordHi >> 8) & 0xFF);
			break;
		case 6:
			nResult	= (unsigned char) ((nCurrentWordHi >> 16) & 0xFF);
			break;
		case 7:
			nResult	= (unsigned char) ((nCurrentWordHi >> 24) & 0xFF);
			break;
#endif					
	}
	nByteCountInCurrentWord++;
	if (nByteCountInCurrentWord == DCCLEN)
	   nByteCountInCurrentWord = 0;
	return nResult;
}

void UnbufferedReceiveDCCFlush()
{
	nByteCountInCurrentWord = 0;
}

unsigned int UnbufferedReceiveDCC(unsigned char *pBuffer, unsigned int nMaxLength)
{
	unsigned char nData;
	unsigned int  nLength;
	unsigned int  nResult;
	nData = UnbufferedReadDCCByte();
	while (nData == 0xFF || nData == 0xFD) nData = UnbufferedReadDCCByte();
	if (nData == 0xFE)
	{
		nLength = UnbufferedReadDCCByte();
		nLength += UnbufferedReadDCCByte() << 8;
	} else
		nLength = nData;
	nResult = (nLength < nMaxLength)?nLength:nMaxLength;
	while (nLength)
	{
		nData = UnbufferedReadDCCByte();
		if (nMaxLength)
		{
			*pBuffer = nData;
			pBuffer++;
			nMaxLength--;
		}
		nLength--;
	}
	UnbufferedReceiveDCCFlush();
	return nResult;
}

static void T32_Fdx_SendDCC(void * channel)
{
    int             len, headerlen;
    unsigned long    data;
#ifdef T32_FDX_DCC8
	unsigned long    data2;
#endif
    volatile T32_FDX_DATATYPE *fdxptr;
    T32_FDX_BUFFER *fdxchannel;

    if (T32_TsMon_SendStatus()) {
	return;
    }
    fdxchannel = channel;
    if (fdxchannel == NULL) {
	return;
    }
    if (fdxchannel->hostindex == fdxchannel->targetindex) {
	T32_Fdx_SendingChannel = NULL;
	return;
    }
    fdxptr = ((T32_FDX_DATATYPE *) (fdxchannel + 1)) + fdxchannel->hostindex;

    if (!fdxchannel->pending) {

	if (!fdxptr[0])
	    return;

	if (*fdxptr == (T32_FDX_DATATYPE) - 1) {
	    fdxchannel->hostindex = 0;

	    fdxptr = ((T32_FDX_DATATYPE *) (fdxchannel + 1)) + fdxchannel->hostindex;

	    if (!fdxptr[0])
		return;
	}
	headerlen = 1;
	if (*fdxptr == (T32_FDX_DATATYPE) - 2) {
	    len = fdxptr[1] | (fdxptr[2] << 8);
	    headerlen = 3;
	} else if (*fdxptr == (T32_FDX_DATATYPE) - 3) {
	    len = 0;
	} else {
	    len = *fdxptr;
	}

	fdxchannel->pending = headerlen + len;
    }
	data = 0;
#ifdef T32_FDX_DCC8
	data2 = 0;
#endif

    switch (fdxchannel->pending) {
    case 1:
		data = (unsigned long) fdxptr[0];
		break;
    case 2:
		data = ((unsigned long)fdxptr[0]) | (((unsigned long)fdxptr[1]) << 8);
		break;
    case 3:
		data = ((unsigned long)fdxptr[0]) | (((unsigned long)fdxptr[1]) << 8) | (((unsigned long)fdxptr[2]) << 16);
		break;
#ifdef T32_FDX_DCC4
    default:
		data = ((unsigned long)fdxptr[0]) | (((unsigned long)fdxptr[1]) << 8) | (((unsigned long)fdxptr[2]) << 16) | (((unsigned long)fdxptr[3]) << 24);
		break;
#else
	case 4:
		data = ((unsigned long)fdxptr[0]) | (((unsigned long)fdxptr[1]) << 8) | (((unsigned long)fdxptr[2]) << 16) | (((unsigned long)fdxptr[3]) << 24);		
		break;
	case 5:
		data = ((unsigned long)fdxptr[0]) | (((unsigned long)fdxptr[1]) << 8) | (((unsigned long)fdxptr[2]) << 16) | (((unsigned long)fdxptr[3]) << 24);		
		data2 = (unsigned long) fdxptr[4];
		break;
	case 6:
		data = ((unsigned long)fdxptr[0]) | (((unsigned long)fdxptr[1]) << 8) | (((unsigned long)fdxptr[2]) << 16) | (((unsigned long)fdxptr[3]) << 24);		
		data2 = ((unsigned long)fdxptr[4]) | (((unsigned long)fdxptr[5]) << 8);
		break;
	case 7:
		data = ((unsigned long)fdxptr[0]) | (((unsigned long)fdxptr[1]) << 8) | (((unsigned long)fdxptr[2]) << 16) | (((unsigned long)fdxptr[3]) << 24);		
		data2 = ((unsigned long)fdxptr[4]) | (((unsigned long)fdxptr[5]) << 8) | (((unsigned long)fdxptr[6]) << 16);
		break;
	default:
		data = ((unsigned long)fdxptr[0]) | (((unsigned long)fdxptr[1]) << 8) | (((unsigned long)fdxptr[2]) << 16) | (((unsigned long)fdxptr[3]) << 24);				
		data2 = ((unsigned long)fdxptr[4]) | (((unsigned long)fdxptr[5]) << 8) | (((unsigned long)fdxptr[6]) << 16) | (((unsigned long)fdxptr[7]) << 24);		
	 	break;
#endif
    }
#ifdef T32_FDX_DCC4
	T32_TsMon_SendWord(data);
#else
	T32_TsMon_SendWord_DCC8(data,data2);
#endif
    
    if (fdxchannel->pending > DCCLEN) {
	fdxchannel->hostindex += DCCLEN;
	fdxchannel->pending -= DCCLEN;
    } else {
	fdxchannel->hostindex += fdxchannel->pending;
	fdxchannel->pending = 0;
    }

    T32_Fdx_SendingChannel = channel;
}


static void T32_Fdx_ReceiveDCC(void * channel)
{
    int             len, headerlen;
    unsigned long			data;
#ifdef T32_FDX_DCC8
	unsigned long			data2;	
#endif
    volatile T32_FDX_DATATYPE *fdxptr;
    T32_FDX_BUFFER *fdxchannel;

    fdxchannel = channel;
    if (fdxchannel == NULL) {
	return;
    }
    T32_Fdx_ReceivingChannel = channel;

    if (fdxchannel->stall) {
	data = fdxchannel->stall;
	fdxchannel->stall = 0;
    } else {
	if (!T32_TsMon_ReceiveStatus()) {
	    return;
	}
#ifdef T32_FDX_DCC4
	data = T32_TsMon_ReceiveWord();
#else
	T32_TsMon_ReceiveWord_DCC8(&data,&data2);
#endif
    }

    if (!fdxchannel->pending) 
    {
		/*not pending*/
		headerlen = 1;
		len = data & 0xff;
		if ((T32_FDX_DATATYPE) len == (T32_FDX_DATATYPE) - 2) 
		{
		    headerlen = 3;
		    len = (data >> 8) & 0xffff;
		}
		if (((int) fdxchannel->hostindex) - len - 3 - 1 < 0) 
		{
		    if (fdxchannel->targetindex < fdxchannel->hostindex || fdxchannel->targetindex >= fdxchannel->size - 1) {
			fdxchannel->stall = data;
			return;
		    }
		    fdxptr = ((T32_FDX_DATATYPE *) (fdxchannel + 1)) + fdxchannel->size - 1;
		    *fdxptr = 0;
		    fdxptr = ((T32_FDX_DATATYPE *) (fdxchannel + 1)) + fdxchannel->hostindex;
		    *fdxptr = (T32_FDX_DATATYPE) - 1;
		    fdxchannel->hostindex = fdxchannel->size - 1;
		}
		if (fdxchannel->targetindex < fdxchannel->hostindex && fdxchannel->hostindex - len - 3 - 1 <= fdxchannel->targetindex) 
		{
		    fdxchannel->stall = data;
		    return;
		}
		fdxchannel->hostindex = fdxchannel->hostindex - 3 + 1;
		fdxchannel->transferlen = len;
		fdxchannel->pending = len;

		fdxptr = ((T32_FDX_DATATYPE *) (fdxchannel + 1)) + fdxchannel->hostindex - len - 1;
		*fdxptr = 0;

		fdxptr = ((T32_FDX_DATATYPE *) (fdxchannel + 1)) + fdxchannel->hostindex - len;
		if (headerlen == 1) 
		{
		    data >>= 8;
		    switch (fdxchannel->pending) 
		    {
			    case 1:
				fdxptr[0] = data & 0xff;
				fdxchannel->pending = 0;
				break;
			    case 2:
				fdxptr[0] = data & 0xff;
				fdxptr[1] = (data >> 8) & 0xff;
				fdxchannel->pending = 0;
				break;
	#ifdef T32_FDX_DCC4
			    default:
				fdxptr[0] = data & 0xff;
				fdxptr[1] = (data >> 8) & 0xff;
				fdxptr[2] = (data >> 16) & 0xff;
				fdxchannel->pending -= 3;
				break;
	#else
				case 3:
				fdxptr[0] = data & 0xff;
				fdxptr[1] = (data >> 8) & 0xff;
				fdxptr[2] = (data >> 16) & 0xff;
				fdxchannel->pending -= 3;
				break;
				case 4:
				fdxptr[0] = data & 0xff;
				fdxptr[1] = (data >> 8) & 0xff;
				fdxptr[2] = (data >> 16) & 0xff;
				fdxptr[3] = data2 & 0xff;
				fdxchannel->pending -= 4;		
				break;
				case 5:
				fdxptr[0] = data & 0xff;
				fdxptr[1] = (data >> 8) & 0xff;
				fdxptr[2] = (data >> 16) & 0xff;
				fdxptr[3] = data2 & 0xff;
				fdxptr[4] = (data2 >> 8) & 0xff;
				fdxchannel->pending -= 5;		
				break;		
				case 6:
				fdxptr[0] = data & 0xff;
				fdxptr[1] = (data >> 8) & 0xff;
				fdxptr[2] = (data >> 16) & 0xff;
				fdxptr[3] = data2 & 0xff;
				fdxptr[4] = (data2 >> 8) & 0xff;
				fdxptr[5] = (data2 >> 16) & 0xff;
				fdxchannel->pending -= 6;		
				break;		
				default:
				fdxptr[0] = data & 0xff;
				fdxptr[1] = (data >> 8) & 0xff;
				fdxptr[2] = (data >> 16) & 0xff;
				fdxptr[3] = data2 & 0xff;
				fdxptr[4] = (data2 >> 8) & 0xff;
				fdxptr[5] = (data2 >> 16) & 0xff;
				fdxptr[6] = (data2 >> 24) & 0xff;
				fdxchannel->pending -= 7;
				break;
	#endif
		    }
		} else 
		{ 
			/*Headerlen != 1*/
#ifdef T32_FDX_DCC8
		    fdxptr[0] = (data >> 24) & 0xff;
			fdxptr[1] = data2 & 0xff;
			fdxptr[2] = (data2 >> 8) & 0xff;
			fdxptr[3] = (data2 >> 16) & 0xff;
			fdxptr[4] = (data2 >> 24) & 0xff;
			fdxchannel->pending -= 5;

#else
			fdxptr[0] = (data >> 24) & 0xff;
			fdxchannel->pending -= 1;
#endif
		    
		}
    } else 
    {
		/*pending*/
		fdxptr = ((T32_FDX_DATATYPE *) (fdxchannel + 1)) + fdxchannel->hostindex - fdxchannel->pending;
		switch (fdxchannel->pending) 
		{
			case 1:
			    fdxptr[0] = data & 0xff;
			    fdxchannel->pending = 0;
			    break;
			case 2:
			    fdxptr[0] = data & 0xff;
			    fdxptr[1] = (data >> 8) & 0xff;
			    fdxchannel->pending = 0;
			    break;
			case 3:
			    fdxptr[0] = data & 0xff;
			    fdxptr[1] = (data >> 8) & 0xff;
			    fdxptr[2] = (data >> 16) & 0xff;
			    fdxchannel->pending = 0;
			    break;
#ifdef T32_FDX_DCC4
			default:
			    fdxptr[0] = data & 0xff;
			    fdxptr[1] = (data >> 8) & 0xff;
			    fdxptr[2] = (data >> 16) & 0xff;
			    fdxptr[3] = (data >> 24) & 0xff;
			    fdxchannel->pending -= 4;
			    break;
#else
			case 4:
			    fdxptr[0] = data & 0xff;
			    fdxptr[1] = (data >> 8) & 0xff;
			    fdxptr[2] = (data >> 16) & 0xff;
			    fdxptr[3] = (data >> 24) & 0xff;
			    fdxptr[4] = data2 & 0xff;
			    fdxchannel->pending -= 4;
			break;
			case 5:
			    fdxptr[0] = data & 0xff;
			    fdxptr[1] = (data >> 8) & 0xff;
			    fdxptr[2] = (data >> 16) & 0xff;
			    fdxptr[3] = (data >> 24) & 0xff;
			    fdxptr[4] = data2 & 0xff;
			    fdxchannel->pending -= 5;
			break;
			case 6:
			    fdxptr[0] = data & 0xff;
			    fdxptr[1] = (data >> 8) & 0xff;
			    fdxptr[2] = (data >> 16) & 0xff;
			    fdxptr[3] = (data >> 24) & 0xff;
			    fdxptr[4] = data2 & 0xff;
			    fdxptr[5] = (data2 >> 8) & 0xff;
			    fdxchannel->pending -= 6;
			break;
			case 7:
			    fdxptr[0] = data & 0xff;
			    fdxptr[1] = (data >> 8) & 0xff;
			    fdxptr[2] = (data >> 16) & 0xff;
			    fdxptr[3] = (data >> 24) & 0xff;
			    fdxptr[4] = data2 & 0xff;
			    fdxptr[5] = (data2 >> 8) & 0xff;
			    fdxptr[6] = (data2 >> 16) & 0xff;
			    fdxchannel->pending -= 7;
			break;
			default:
			    fdxptr[0] = data & 0xff;
			    fdxptr[1] = (data >> 8) & 0xff;
			    fdxptr[2] = (data >> 16) & 0xff;
			    fdxptr[3] = (data >> 24) & 0xff;
			    fdxptr[4] = data2 & 0xff;
			    fdxptr[5] = (data2 >> 8) & 0xff;
			    fdxptr[6] = (data2 >> 16) & 0xff;
			    fdxptr[7] = (data2 >> 24) & 0xff;
			    fdxchannel->pending -= 8;
			break;
#endif
			}
    }

    if (fdxchannel->pending == 0) 
    {
		len = fdxchannel->transferlen;
		fdxptr = ((T32_FDX_DATATYPE *) (fdxchannel + 1)) + fdxchannel->hostindex;
		fdxptr[0] = len & 0xff;
		fdxptr[1] = (len >> 8) & 0xff;
		fdxptr[2] = (T32_FDX_DATATYPE) - 2;
		fdxchannel->hostindex -= (len + 1);
    }
}

#define T32_FDX_SENDPOLL(channel) T32_Fdx_SendDCC(channel)
#define T32_FDX_RECEIVEPOLL(channel) T32_Fdx_ReceiveDCC(channel)

#define T32_FDX_POLL()		{ if (T32_Fdx_SendingChannel) T32_Fdx_SendDCC(T32_Fdx_SendingChannel); else T32_Fdx_ReceiveDCC(T32_Fdx_ReceivingChannel); }

#endif


/**************************************************************************

	generic polling macros (polling is not used)
	
**************************************************************************/

#ifndef T32_FDX_SENDPOLL
#define T32_FDX_SENDPOLL(channel)
#endif

#ifndef T32_FDX_RECEIVEPOLL
#define T32_FDX_RECEIVEPOLL(channel)
#endif

#ifndef T32_FDX_POLL
#define T32_FDX_POLL()
#endif



/**************************************************************************

	Send packet to ringbuffer or check state of ringbuffer
	
**************************************************************************/

static int T32_Fdx_SendToBuffer(void * channel, void * buf, int size)
{
    int             hsize;
    T32_FDX_PARAMETERTYPE targetindex;
    T32_FDX_BUFFER *fdxchannel;
    volatile T32_FDX_DATATYPE *fdxptr, *fdxptr2;

    fdxchannel = channel;

    if ((T32_FDX_PARAMETERTYPE) size > fdxchannel->size - 4 || size <= 0)
	return -1;

    hsize = 1;
    if ((unsigned int) size > (unsigned int) ((T32_FDX_DATATYPE) - 5))
	hsize = 3;
    targetindex = fdxchannel->targetindex;
    if (targetindex + hsize + size + 2 > fdxchannel->size) {	/* wrap arround ? */
	if (fdxchannel->hostindex > targetindex || fdxchannel->hostindex <= 1)
	    goto stall;
	fdxptr2 = (T32_FDX_DATATYPE *) (fdxchannel + 1);
	*fdxptr2 = (T32_FDX_DATATYPE) 0;
	fdxptr = ((T32_FDX_DATATYPE *) (fdxchannel + 1)) + targetindex;
	*fdxptr = (T32_FDX_DATATYPE) - 1;
	targetindex = 0;
	fdxchannel->targetindex = targetindex;
    }
    if (fdxchannel->hostindex > targetindex && targetindex + hsize + size + 2 > fdxchannel->hostindex)
	goto stall;

    if (buf) {			/* just polling state ? */

	fdxptr = ((T32_FDX_DATATYPE *) (fdxchannel + 1)) + targetindex;
	T32_FDX_COPY((void *) (fdxptr + hsize), buf, size);	/* copy payload data */

	fdxptr2 = fdxptr + hsize + size;
	*fdxptr2 = 0;		/* mark next packet as not ready */

	if (hsize == 3) {	/* large packet size ? */
	    fdxptr[2] = size >> 8;
	    fdxptr[1] = size;
	    fdxptr[0] = (T32_FDX_DATATYPE) - 2;
	} else {
	    fdxptr[0] = size;
	}

	fdxchannel->targetindex = targetindex + hsize + size;
	fdxchannel->stall = 0;

	T32_FDX_DOORBELL();
    }
    return size;

stall:
    if (buf && !fdxchannel->stall) {
	fdxptr = ((T32_FDX_DATATYPE *) (fdxchannel + 1)) + targetindex;
	fdxptr2 = fdxptr + 1;
	*fdxptr2 = (T32_FDX_DATATYPE) 0;
	*fdxptr = (T32_FDX_DATATYPE) - 3;
	fdxchannel->targetindex = targetindex + 1;
	fdxchannel->stall = 1;
    }
    return 0;
}



/**************************************************************************

	Receive packet from ringbuffer or check state of ringbuffer
	
**************************************************************************/

static int T32_Fdx_ReceiveFromBuffer(void * channel, void * buf, int maxsize)
{
    int             size, hsize, copysize;
    T32_FDX_PARAMETERTYPE targetindex;
    T32_FDX_BUFFER *fdxchannel;
    T32_FDX_DATATYPE *fdxptr;

    fdxchannel = channel;

    targetindex = fdxchannel->targetindex;
    fdxptr = ((T32_FDX_DATATYPE *) (fdxchannel + 1)) + targetindex;

    size = *fdxptr;
    if (size == (T32_FDX_DATATYPE) - 1) {
	targetindex = fdxchannel->size - 1;
	fdxptr = ((T32_FDX_DATATYPE *) (fdxchannel + 1)) + targetindex;
	size = *fdxptr;
    }
    if (buf == 0 || size == 0) {/* just return if nothing is ready */
	return size;
    }
    hsize = 1;
    if (size == (T32_FDX_DATATYPE) - 2) {
	size = fdxptr[-2] | (fdxptr[-1] << 8);
	hsize = 3;
    }
    targetindex -= size + hsize;

    copysize = (size > maxsize) ? maxsize : size;
    T32_FDX_COPY(buf, (void *) (((T32_FDX_DATATYPE *) (fdxchannel + 1)) + targetindex + 1), copysize);

    fdxchannel->targetindex = targetindex;

    T32_FDX_DOORBELL();

    return copysize;
}


/**************************************************************************

	Send packet to ringbuffer or poll state of ringbuffer
	
**************************************************************************/

int T32_Fdx_SendPoll(void * channel, void * buf, int size)
{
    int             result;

    T32_FDX_INTDISABLE();

    result = T32_Fdx_SendToBuffer(channel, buf, size);

    T32_FDX_SENDPOLL(channel);

    T32_FDX_INTENABLE();

    return result;
}


/**************************************************************************

	Send packet to ringbuffer, wait till packet can be saved
	
**************************************************************************/

int T32_Fdx_Send(void * channel, void * buf, int size)
{
    int             result;

    T32_FDX_INTDISABLE();

    while ((result = T32_Fdx_SendToBuffer(channel, buf, size)) == 0) {
	T32_FDX_WAITING();
	T32_FDX_POLL();
    }

    T32_FDX_SENDPOLL(channel);

    T32_FDX_INTENABLE();

    return result;
}



/**************************************************************************

	Receive packet from ringbuffer or poll state of ringbuffer
	
**************************************************************************/

int T32_Fdx_ReceivePoll(void * channel, void * buf, int size)
{
    int             result;

    T32_FDX_INTDISABLE();

    T32_FDX_RECEIVEPOLL(channel);

    result = T32_Fdx_ReceiveFromBuffer(channel, buf, size);

    T32_FDX_INTENABLE();

    return result;
}


/**************************************************************************

	Receive packet from ringbuffer, wait till packet arrives
	
**************************************************************************/

int T32_Fdx_Receive(void * channel, void * buf, int size)
{
    int             result;

    T32_FDX_INTDISABLE();

    T32_FDX_RECEIVEPOLL(channel);

    while ((result = T32_Fdx_ReceiveFromBuffer(channel, buf, size)) == 0) {
	T32_FDX_WAITING();
	T32_FDX_POLL();
    }

    T32_FDX_INTENABLE();

    return result;
}



/**************************************************************************

	Macro variant for fast data transmit
	
**************************************************************************/

#define T32_FDX_SEND(channel,buf,siz) \
{ \
    int             hsize, stalled; \
    T32_FDX_PARAMETERTYPE targetindex; \
    T32_FDX_BUFFER *fdxchannel; \
    volatile T32_FDX_DATATYPE *fdxptr, *fdxptr2; \
 \
    fdxchannel = (T32_FDX_BUFFER *)(channel); \
 \
    for (stalled = 0;; stalled = 1) { \
 \
	if (stalled) { \
	    if (!fdxchannel->stall) { \
		fdxptr = ((T32_FDX_DATATYPE *) (fdxchannel + 1)) + targetindex; \
		fdxptr2 = fdxptr + 1; \
		*fdxptr2 = (T32_FDX_DATATYPE) 0; \
		*fdxptr = (T32_FDX_DATATYPE) - 3; \
		fdxchannel->targetindex = targetindex + 1; \
		fdxchannel->stall = 1; \
	    } \
	    T32_FDX_WAITING(); \
	    T32_FDX_POLL(); \
	} \
	hsize = 1; \
	if ((unsigned int) (siz) > (unsigned int) ((T32_FDX_DATATYPE) - 5)) \
	    hsize = 3; \
	targetindex = fdxchannel->targetindex; \
	if (targetindex + hsize + (siz) + 2 > fdxchannel->size) {	/* wrap arround ? */ \
	    if (fdxchannel->hostindex > targetindex || fdxchannel->hostindex <= 1) \
		continue; \
	    fdxptr2 = (T32_FDX_DATATYPE *) (fdxchannel + 1); \
	    *fdxptr2 = (T32_FDX_DATATYPE) 0; \
	    fdxptr = ((T32_FDX_DATATYPE *) (fdxchannel + 1)) + targetindex; \
	    *fdxptr = (T32_FDX_DATATYPE) - 1; \
	    targetindex = 0; \
	    fdxchannel->targetindex = targetindex; \
	} \
	if (fdxchannel->hostindex > targetindex && targetindex + hsize + (siz) + 2 > fdxchannel->hostindex) \
	    continue; \
 \
	fdxptr = ((T32_FDX_DATATYPE *) (fdxchannel + 1)) + targetindex; \
	T32_FDX_COPY((void *) (fdxptr + hsize), (buf), (siz));	/* copy payload data */ \
 \
	fdxptr2 = fdxptr + hsize + (siz); \
	*fdxptr2 = 0;		/* mark next packet as not ready */ \
 \
	if (hsize == 3) {	/* large packet (siz) ? */ \
	    fdxptr[2] = (siz) >> 8; \
	    fdxptr[1] = (siz); \
	    fdxptr[0] = (T32_FDX_DATATYPE) - 2; \
	} else { \
	    fdxptr[0] = (siz); \
	} \
 \
	fdxchannel->targetindex = targetindex + hsize + (siz); \
	fdxchannel->stall = 0; \
 \
	T32_FDX_DOORBELL(); \
	break; \
    } \
}



/**************************************************************************

	Send 15byte packet to ringbuffer (example for uncompressed trace)
	
**************************************************************************/

int T32_Fdx_Send15(void * channel, void * buf)
{
    T32_FDX_INTDISABLE();
    
    T32_FDX_SEND(channel,buf,15);

    T32_FDX_SENDPOLL(channel);

    T32_FDX_INTENABLE();

    return 16;
}



/**************************************************************************

	Execute any interface polling
	
	Only needed for special communication variants.
	
**************************************************************************/

void T32_Fdx_Poll(void)
{
    T32_FDX_INTDISABLE();

    T32_FDX_POLL();

    T32_FDX_INTENABLE();
}


void T32_Fdx_PollInterrupt(void)
{
    T32_FDX_POLL();
}


#if defined(T32_FDX_TRACE_COMPRESSED) || defined(T32_FDX_TRACE_UNCOMPRESSED)

/**************************************************************************

	FDX Tracing functions
	
**************************************************************************/

extern unsigned long T32_Fdx_GetTimebase(void);

T32_Fdx_DefineChannel(FdxTraceSendBuffer,T32_FDX_TRACE_BUFSIZE);


void T32_Fdx_TraceInit(void)
{
    T32_Fdx_InitChannel(FdxTraceSendBuffer);

    T32_Fdx_EnableChannel(FdxTraceSendBuffer);
}



#ifdef T32_FDX_TRACE_COMPRESSED

static int T32_Fdx_LastCycle;
static unsigned long T32_Fdx_LastTimestamp;
static unsigned long T32_Fdx_LastAddress;
static unsigned long T32_Fdx_LastData;


#ifdef C55X

void T32_Fdx_TraceData(int cycletype, void* address, unsigned long data)
{
    int             len;
    unsigned long   addr;
    unsigned long   tslow;
    unsigned int    ctrl;
    unsigned int    buf[8];

    tslow = T32_Fdx_GetTimebase();

    ctrl = 0x00;
    len = 1;
    if (cycletype != T32_Fdx_LastCycle) {
	ctrl |= 0x80;
	ctrl |= (cycletype << 8);
	T32_Fdx_LastCycle = cycletype;
    }
    if (tslow != T32_Fdx_LastTimestamp) {
	if ((tslow & 0xffffff00) == (T32_Fdx_LastTimestamp & 0xffffff00) && !(ctrl & 0x80)) {
	    ctrl |= 0x20;
	    ctrl |= (tslow & 0xff) << 8;
	} else if ((tslow & 0xffff0000) == (T32_Fdx_LastTimestamp & 0xffff0000)) {
	    buf[len] = tslow & 0xffff;
	    len += 1;
	    ctrl |= 0x40;
	} else {
	    buf[len] = tslow & 0xffff;
	    buf[len + 1] = (tslow >> 16) & 0xffff;
	    buf[len + 2] = 0;
	    len += 3;
	    ctrl |= 0x60;
	}
	T32_Fdx_LastTimestamp = tslow;
    }
    addr = (unsigned long) address;
    if (addr != T32_Fdx_LastAddress) {
	if ((addr & 0xffffff00) == (T32_Fdx_LastAddress & 0xffffff00)) {
	    switch ((int) (addr - T32_Fdx_LastAddress)) {
	    case 0:
		break;
	    case 1:
		ctrl |= 0x04;
		break;
	    case 2:
		ctrl |= 0x08;
		break;
	    case 4:
		ctrl |= 0x0c;
		break;
	    case 8:
		ctrl |= 0x10;
		break;
	    default:
		buf[len] = addr & 0xffff;
		len += 1;
		ctrl |= 0x14;
	    }
	} else if ((addr & 0xffff0000) == (T32_Fdx_LastAddress & 0xffff0000)) {
	    buf[len] = addr & 0xffff;
	    len += 1;
	    ctrl |= 0x18;
	} else {
	    buf[len] = addr & 0xffff;
	    buf[len + 1] = (addr >> 16) & 0xffff;
	    len += 2;
	    ctrl |= 0x1c;
	}

	T32_Fdx_LastAddress = addr;
    }
    if (data != T32_Fdx_LastData) {
	if ((data & 0xffffff00) == (T32_Fdx_LastData & 0xffffff00) && !(ctrl & 0xa0)) {
	    ctrl |= 0x01;
	    ctrl |= (data & 0xff) << 8;
	} else if ((data & 0xffff0000) == (T32_Fdx_LastData & 0xffff0000)) {
	    buf[len] = data & 0xffff;
	    len += 1;
	    ctrl |= 0x02;
	} else {
	    buf[len] = data & 0xffff;
	    buf[len + 1] = (data >> 16) & 0xffff;
	    len += 2;
	    ctrl |= 0x03;
	}

	T32_Fdx_LastData = data;
    }
    buf[0] = ctrl;
    T32_Fdx_Send(&FdxTraceSendBuffer, buf, len);
}

#else

void T32_Fdx_TraceData(int cycletype, void* address, unsigned long data)
{
    int             len;
    unsigned long   addr;
    unsigned long   tslow;
    unsigned char   ctrl;
    unsigned char   buf[16];

    tslow = T32_Fdx_GetTimebase();
    
    ctrl = 0x00;
    len = 1;
    if (cycletype != T32_Fdx_LastCycle) {
	buf[len] = cycletype;
	len++;
	ctrl |= 0x80;
	T32_Fdx_LastCycle = cycletype;
    }

    if (tslow != T32_Fdx_LastTimestamp) {
	if ((tslow & 0xffffff00) == (T32_Fdx_LastTimestamp & 0xffffff00)) {
	    buf[len] = tslow & 0xff;
	    len += 1;
	    ctrl |= 0x20;
	} else if ((tslow & 0xffff0000) == (T32_Fdx_LastTimestamp & 0xffff0000)) {
	    buf[len] = tslow & 0xff;
	    buf[len + 1] = (tslow >> 8) & 0xff;
	    len += 2;
	    ctrl |= 0x40;
	} else {
	    buf[len] = tslow & 0xff;
	    buf[len + 1] = (tslow >> 8) & 0xff;
	    buf[len + 2] = (tslow >> 16) & 0xff;
	    buf[len + 3] = (tslow >> 24) & 0xff;
	    buf[len + 4] = 0;
	    buf[len + 5] = 0;
	    len += 6;
	    ctrl |= 0x60;
	}
	T32_Fdx_LastTimestamp = tslow;
    }

    addr = (unsigned long) address;
    if (addr != T32_Fdx_LastAddress) {
	if ((addr & 0xffffff00) == (T32_Fdx_LastAddress & 0xffffff00)) {
	    switch ((int) (addr - T32_Fdx_LastAddress)) {
	    case 0:
		break;
	    case 1:
		ctrl |= 0x04;
		break;
	    case 2:
		ctrl |= 0x08;
		break;
	    case 4:
		ctrl |= 0x0c;
		break;
	    case 8:
		ctrl |= 0x10;
		break;
	    default:
		buf[len] = addr & 0xff;
		len += 1;
		ctrl |= 0x14;
	    }
	} else if ((addr & 0xffff0000) == (T32_Fdx_LastAddress & 0xffff0000)) {
	    buf[len] = addr & 0xff;
	    buf[len + 1] = (addr >> 8) & 0xff;
	    len += 2;
	    ctrl |= 0x18;
	} else {
	    buf[len] = addr & 0xff;
	    buf[len + 1] = (addr >> 8) & 0xff;
	    buf[len + 2] = (addr >> 16) & 0xff;
	    buf[len + 3] = (addr >> 24) & 0xff;
	    len += 4;
	    ctrl |= 0x1c;
	}

	T32_Fdx_LastAddress = addr;
    }

    if (data != T32_Fdx_LastData) {
	if ((data & 0xffffff00) == (T32_Fdx_LastData & 0xffffff00)) {
	    buf[len] = data & 0xff;
	    len += 1;
	    ctrl |= 0x01;
	} else if ((data & 0xffff0000) == (T32_Fdx_LastData & 0xffff0000)) {
	    buf[len] = data & 0xff;
	    buf[len + 1] = (data >> 8) & 0xff;
	    len += 2;
	    ctrl |= 0x02;
	} else {
	    buf[len] = data & 0xff;
	    buf[len + 1] = (data >> 8) & 0xff;
	    buf[len + 2] = (data >> 16) & 0xff;
	    buf[len + 3] = (data >> 24) & 0xff;
	    len += 4;
	    ctrl |= 0x03;
	}

	T32_Fdx_LastData = data;
    }

    buf[0] = ctrl;
    T32_Fdx_Send(&FdxTraceSendBuffer, buf, len);
}

#endif
#endif

#ifdef T32_FDX_TRACE_UNCOMPRESSED

void T32_Fdx_TraceData(int cycletype, void* address, unsigned long data)
{
    struct {
#ifndef C55X
	unsigned char   align;
#endif
	unsigned char   cycletype;
	unsigned short  tsupper;
	unsigned long   tslower;
	unsigned long   address;
	unsigned long   data;
    }               traceframe;

    int             len = sizeof(traceframe);

#ifndef C55X
    len--;
#endif

    T32_FDX_INTDISABLE();

    traceframe.cycletype = cycletype;
    traceframe.tsupper = 0;
    traceframe.tslower = T32_Fdx_GetTimebase();
    traceframe.address = (unsigned long) address;
    traceframe.data = data;

    T32_FDX_SEND(&FdxTraceSendBuffer, &traceframe.cycletype, len);

    T32_FDX_SENDPOLL(&FdxTraceSendBuffer);

    T32_FDX_INTENABLE();
}

#endif

void T32_Fdx_TraceTrigger()
{
}

#endif
