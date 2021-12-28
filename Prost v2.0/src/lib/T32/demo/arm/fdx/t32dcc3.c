/**************************************************************************

	TRACE32 DCC3 protocol

  $Date: 2009-10-28 17:44:42 +0100 (Mi, 28 Okt 2009) $
  $Revision: 3202 $

	This is the current source for this demo.
	The latest source can be found in demo/etc/fdx/target.

	27/10/09	initial release

	possible defines:

	T32_FDX_DCC3	set for DCC3 based communication

  (c) Lauterbach GmbH
  http://www.lauterbach.com/

**************************************************************************/

#ifdef T32_FDX_DCC3

/*Imports*/
/*Imports from t32fdxarm.c, etc. for Read/Write 32Bit Values */
extern unsigned long T32_TsMon_SendStatus(void); /*returns 0 when a value can be written to DCC*/
extern unsigned long T32_TsMon_ReceiveStatus(void); /*returns 0 as long no value can be read from DCC*/
extern void T32_TsMon_SendWord(unsigned long data); /*send one word (4 bytes)*/
extern unsigned long T32_TsMon_ReceiveWord(void); /*send one word (4 bytes)*/

/*Exports*/
extern unsigned long T32DCC3_SendStatus(int nChannel); /*returns 0 when a value can be written to DCC*/
extern unsigned long T32DCC3_ReceiveStatus(int DCCChannel); /*returns 0 as long no value can be read from DCC3 for this channel.*/
extern void T32DCC3_SendWord(int nChannel, unsigned int nLength, unsigned int nData3); /*send 1 to 3 byte data on this channel*/
extern void T32DCC3_ReceiveWord(int nChannel, unsigned long *pLength, unsigned long *pData3); /*receive 1 to 3 byte for the channel passed by T32DCC3_ReceiveStatus before*/

/*Receive Buffer Variables*/
static int ReceiveStatusChannel = -1; /* DCC3 Channel. -1 : no word has been received*/
static unsigned long ReceivedWord; /* current word that has been received*/
static unsigned long ReceivedLength; /* length (1..3) of valid bytes in current data*/

unsigned long T32DCC3_ReceiveStatus(int DCCChannel)
{
	if (ReceiveStatusChannel == -1)
		if (T32_TsMon_ReceiveStatus())
		{
			unsigned long data;
			data = T32_TsMon_ReceiveWord();
			ReceiveStatusChannel = (data >> 26);
			ReceivedLength = (data >> 24)&0x3+1;
			ReceivedWord = data & 0x00FFFFFF;
		}
	return (ReceiveStatusChannel == DCCChannel)?1:0;
}

void T32DCC3_ReceiveWord(int nChannel, unsigned long *pLength, unsigned long *pData3)
{
	*pData3 = ReceivedWord;
	if (pLength)
		*pLength = ReceivedLength;
	ReceiveStatusChannel = -1;
}

unsigned long T32DCC3_SendStatus(int nChannel)
{
	return T32_TsMon_SendStatus();
}

void T32DCC3_SendWord(int nChannel, unsigned int nLength, unsigned int nData3)
{
	unsigned long data;
	data = (nData3 & 0x00FFFFFF) | ( ((nLength - 1) | (nChannel << 2)) << 24);
	T32_TsMon_SendWord(data);
}

#endif

