/*
 ******************************************************************************
 *                     PROGRAM MODULE
 *
 *     $Workfile:   t32printf.c  $
 *     $Author:   dienstbeck  $
 *     $Date:   10/16/01  $
 *
 *       
 *
 ******************************************************************************
 */

#include "bios.h"
#include "cpu.h"
#include "outfmt.h"

#define BUFSIZE 512


/* We use a 256 byte buffer to transfer data from
// and to TRACE32. The first byte is the message
// length, the message itself starts at buffer+4
// (i.e. maximum length is 252 characters).
*/


volatile char T32OUTBUF[256], T32INBUF[256];
volatile char T32started = 0;


/* either start terminal output by
// - pressing a key inside the terminal window
// - writing a non-zero value to T32INBUF[0]
// - writing a non-zero value to T32started
*/

/* Prepare the TRACE32 Terminal Emulation:
   if you have dualport access:
     TERM.Protocol BufferE  ; dual port memory access
   if you don't, only access if halted on T32PUTBUF:
     TERM.Protocol BufferC address.offset(T32PUTBUF)
     Break.Set T32PUTBUF    ; set breakpoint to halt on put
     
   The TRACE32 terminal is started by
     TERM T32OUTBUF T32INBUF
*/


void T32PutBuffer (const char* data, long size)
{
    int i, j;

    if (!T32started) 
        return;
    
    while (size > 0)
    {
        i = size;
        if ( i > 252)
            i = 252;
        while (T32OUTBUF[0]) ;	/* wait for ready */
        for (j = 0 ; j < i; j++)
            T32OUTBUF[j+4] = data[j];
        T32OUTBUF[0] = i;
        data += i;
        size -= i;
    }
    
T32PUTBUF:
    return;
}


static long handler(long fc, long _format, long _ap, long dummy1, long dummy2, long dummy3, long dummy4)
{
  long length;

  if (T32INBUF[0])
  {
    T32INBUF[0] = 0;  /* receive ack */
    T32started = 1;
  }
      
  if (fc == 0)
    {
      const char *format = (const char *)_format;
      static char buffer[BUFSIZE]; /* Static buffer => not reentrant. */
      va_list * ap;
      ap = (va_list *) _ap;

      LOCK_PUSH();
      length = vsnprintf(buffer, sizeof buffer, format, *ap);
      
      if (length > 0)
        T32PutBuffer (buffer, length);

      LOCK_POP();
    }
  else if (fc == 1)
    {
      const char *buffer = (const char *)_format;
      length = _ap;

      if (length > 0)
      {
        LOCK_PUSH();
        T32PutBuffer (buffer, length);
        LOCK_POP();
      }
    }
  
  return length;
}

void init_dbgprintf(void)
{
	biosInstall("dbgprintf", handler, BIOS_USERMODE_ALLOWED);
}
