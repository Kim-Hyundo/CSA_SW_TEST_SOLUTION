
#ifdef __GNUC__
# define MRC(CORPROC,OPCODE,RD,CRN,CRM) __asm__ ("mrc " #CORPROC "," #OPCODE ",%[dst]," #CRN "," #CRM : [dst] "=r" (RD))
# define MCR(CORPROC,OPCODE,RD,CRN,CRM) __asm__ ("mcr " #CORPROC "," #OPCODE ",%[src]," #CRN "," #CRM :: [src] "r" (RD))
#else
# define MRC(CORPROC,OPCODE,RD,CRN,CRM) __asm { mrc CORPROC,OPCODE,RD,CRN,CRM }
# define MCR(CORPROC,OPCODE,RD,CRN,CRM) __asm { mcr CORPROC,OPCODE,RD,CRN,CRM }
#endif


/**************************************************************************

	ARM family dependent DCC driver functions

**************************************************************************/

#if defined(ARM7)||defined(ARM9) /* ARM7, ARM9 */

static unsigned int DCC_SendStatus (void)
{
	unsigned int status;
	MRC( p14, 0, status, c0, c0 );
	return (status & 2);
}

static void DCC_SendWord (unsigned int data)
{
	MCR( p14, 0, data, c1, c0  );
}

static unsigned int DCC_ReceiveStatus (void)
{
	unsigned int  status;
	MRC( p14, 0, status, c0, c0  );
	return (status & 1);
}

static unsigned int DCC_ReceiveWord (void)
{
	unsigned int data;
	MRC( p14, 0, data, c1, c0  );
	return data;
}

#elif defined(ARM10) /* ARM10 */

static unsigned int DCC_SendStatus (void)
{
	unsigned int status;
	MRC( p14, 0, status, c0, c1 );
	return !(status & 0x40);
}

static void DCC_SendWord (unsigned int data)
{
	MCR( p14, 0, data, c0, c5 );
}

static unsigned int DCC_ReceiveStatus (void)
{
	unsigned int status;
	MRC( p14, 0, status, c0, c1 );
	return (status & 0x80);
}

static unsigned int DCC_ReceiveWord (void)
{
	unsigned int data;
	MRC( p14, 0, data, c0, c5 );
	return data;
}

#elif defined(ARM11)||defined(CORTEXR)||defined(CORTEXA) /* ARM11, Cortex-R4, Cortex-A8 */

static unsigned int DCC_SendStatus (void)
{
	unsigned int status;
	MRC( p14, 0, status, c0, c1 );
	return (status & 0x20000000);
}

static void DCC_SendWord (unsigned int data)
{
	MCR( p14, 0, data, c0, c5 );
}

static unsigned int DCC_ReceiveStatus (void)
{
	unsigned int status;
	MRC( p14, 0, status, c0, c1 );
	return (status & 0x40000000);
}

static unsigned int DCC_ReceiveWord (void)
{
	unsigned int    data;
	MRC( p14, 0, data, c0, c5 );
	return data;
}

#else
# error Please define ARM7, ARM9, ARM10, ARM11, CORTEXR or CORTEXA according to your CPU

static unsigned int DCC_SendStatus (void)
{
	return 0;
}

static void DCC_SendWord (unsigned int data)
{
}

static unsigned int DCC_ReceiveStatus (void)
{
	return 0;
}

static unsigned int DCC_ReceiveWord (void)
{
	return 0;
}

#endif

/**************************************************************************

	memory access

**************************************************************************/

static void Monitor_ReadByte (void * buf, void * address, int len)
{
	int i;
	unsigned char *source = (unsigned char *) address;
	unsigned char *target = (unsigned char *) buf;

	for (i = 0; i < len; i++) {
		target[i] = source[i];
	}
}


static void Monitor_ReadHalf (void * buf, void * address, int len)
{
	int i;
	unsigned short *source = (unsigned short *) address;
	unsigned short *target = (unsigned short *) buf;

	for (i = 0; i < len; i++) {
		target[i] = source[i];
	}
}


static void Monitor_ReadWord (void * buf, void * address, int len)
{
	int i;
	unsigned int *source = (unsigned int *) address;
	unsigned int *target = (unsigned int *) buf;

	for (i = 0; i < len; i++) {
		target[i] = source[i];
	}
}


static void Monitor_WriteByte (void * buf, void * address, int len)
{
	int i;
	unsigned char *source = (unsigned char *) address;
	unsigned char *target = (unsigned char *) buf;

	for (i = 0; i < len; i++) {
		target[i] = source[i];
	}
}


static void Monitor_WriteHalf (void * buf, void * address, int len)
{
	int i;
	unsigned short *source = (unsigned short *) address;
	unsigned short *target = (unsigned short *) buf;

	for (i = 0; i < len; i++) {
		target[i] = source[i];
	}
}


static void Monitor_WriteWord (void * buf, void * address, int len)
{
	int i;
	unsigned int *source = (unsigned int *) address;
	unsigned int *target = (unsigned int *) buf;

	for (i = 0; i < len; i++) {
		target[i] = source[i];
	}
}


/**************************************************************************

	CP15 access

	Can be extended appropriate to your need.

**************************************************************************/


static unsigned int Monitor_ReadCP15 (unsigned int address)
{
	unsigned int data = 0;

	switch (address) {
		case 0xf000:
			MRC( p15, 0, data, c0, c0 );
			break;
		case 0xf001:
			MRC( p15, 0, data, c1, c0 );
			break;
		case 0xf002:
			MRC( p15, 0, data, c2, c0 );
			break;
		case 0xf003:
			MRC( p15, 0, data, c3, c0 );
			break;
		case 0xf004:
			MRC( p15, 0, data, c4, c0 );
			break;
		case 0xf005:
			MRC( p15, 0, data, c5, c0 );
			break;
	}
	return data;
}


static void Monitor_WriteCP15 (unsigned int address, unsigned int data)
{
	switch (address) {
		case 0xf000:
			MCR( p15, 0, data, c0, c0 );
			break;
		case 0xf001:
			MCR( p15, 0, data, c1, c0 );
			break;
		case 0xf002:
			MCR( p15, 0, data, c2, c0 );
			break;
		case 0xf003:
			MCR( p15, 0, data, c3, c0 );
			break;
		case 0xf004:
			MCR( p15, 0, data, c4, c0 );
			break;
		case 0xf005:
			MCR( p15, 0, data, c5, c0 );
			break;
	}
}


/**************************************************************************

	Monitor

	The Monitor_Handler() needs to be called by the application routine.

	TSMON, UDMON:
	The call is typically included in a periodic interrupt or in the idle
	task of the kernel.

	PTMON:
	The call is typically included in the interrupt service routine which
	will be triggered by the trigger output signal coming from the debugger.

**************************************************************************/

void Monitor_Handler(void)
{
	int index, len;
	unsigned int address, data;

	static unsigned int Monitor_AddressHigh = 1, Monitor_AddressLow = 1, Monitor_Buffer[16] = {1};
	static unsigned int Monitor_Index = 1, Monitor_Count = 1; /* Initialized with 1 to ensure that both variables or not placed in the .bss section, to ensure that both are initialized before the startup-code (crt0.c) ist running. */

	/* receive data from debugger via DCC channel */
	if (DCC_ReceiveStatus()) {
		data = DCC_ReceiveWord();

		switch (data >> 28) {
			case 0x01: /* 8-bit read access */
				len = ((data >> 24) & 0x0f) + 1;
				address = (Monitor_AddressLow & ~0xffffff) | (data & 0xffffff);
				Monitor_ReadByte (Monitor_Buffer, (void *) address, len);
				Monitor_Index = 0;
				Monitor_Count = len;
				break;

			case 0x02: /* 16-bit read access */
				len = ((data >> 24) & 0x0f) + 1;
				address = (Monitor_AddressLow & ~0xffffff) | (data & 0xffffff);
				Monitor_ReadHalf (Monitor_Buffer, (void *) address, len);
				Monitor_Index = 0;
				Monitor_Count = len * 2;
				break;

			case 0x03: /* 32-bit read access */
				len = ((data >> 24) & 0x0f) + 1;
				address = (Monitor_AddressLow & ~0xffffff) | (data & 0xffffff);
				Monitor_ReadWord (Monitor_Buffer, (void *) address, len);
				Monitor_Index = 0;
				Monitor_Count = len * 4;
				break;

			case 0x04: /* 8-bit write access */
				len = ((data >> 24) & 0x0f) + 1;
				((unsigned char *) Monitor_Buffer)[len - 1] = (data >> 16) & 0xff;
				address = (Monitor_AddressLow & ~0xffff) | (data & 0xffff);
				Monitor_WriteByte ((void *) address, Monitor_Buffer, len);
				break;

			case 0x05: /* 16-bit write access */
				len = ((data >> 24) & 0x0f) + 1;
				((unsigned char *) Monitor_Buffer)[len * 2 - 1] = (data >> 16) & 0xff;
				address = (Monitor_AddressLow & ~0xffff) | (data & 0xffff);
				Monitor_WriteHalf ((void *) address, Monitor_Buffer, len);
				break;

			case 0x06: /* 32-bit write access */
				len = ((data >> 24) & 0x0f) + 1;
				((unsigned char *) Monitor_Buffer)[len * 4 - 1] = (data >> 16) & 0xff;
				address = (Monitor_AddressLow & ~0xffff) | (data & 0xffff);
				Monitor_WriteWord ((void *) address, Monitor_Buffer, len);
				break;

			case 0x07: /* 32-bit CP15 read access */
				Monitor_Buffer[0] = Monitor_ReadCP15 (data & 0xffff);
				Monitor_Index = 0;
				Monitor_Count = 4;
				break;

			case 0x08: /* 32-bit CP15 write access */
				((unsigned char *) Monitor_Buffer)[4 - 1] = (data >> 16) & 0xff;
				Monitor_WriteCP15 (data & 0xffff, Monitor_Buffer[0]);
				break;

			case 0x0d: /* set address */
				if ((data & 0x01000000) == 0){
					/* Bits 16..39 */
					Monitor_AddressLow = (data << 16);
					Monitor_AddressHigh = (Monitor_AddressHigh & ~0xff) | ((data >> 16) & 0xff);
				} else {
					/* Bits 40..63 */
					Monitor_AddressHigh = (Monitor_AddressHigh & ~0xffffff00) | ((data << 8) & 0xffffff00);
				}
				break;

			case 0x0e: /* set data to buffer */
			case 0x0f:
				index = ((data >> 24) & 0x1f) * 3;
				if (index < 21) {
					((unsigned char *) Monitor_Buffer)[index] = data & 0xff;
					((unsigned char *) Monitor_Buffer)[index + 1] = (data >> 8) & 0xff;
					((unsigned char *) Monitor_Buffer)[index + 2] = (data >> 16) & 0xff;
				}
				break;
		}
	}

	/* send data from debugger via DCC channel */
	if (Monitor_Index < Monitor_Count && !DCC_SendStatus()) {
		data = (((unsigned char *) Monitor_Buffer)[Monitor_Index]) | (((unsigned char *) Monitor_Buffer)[Monitor_Index + 1] << 8) | (((unsigned char *) Monitor_Buffer)[Monitor_Index + 2] << 16) | 0x10000000;
		DCC_SendWord(data);
		Monitor_Index += 3;
	}
}

