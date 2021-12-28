/**************************************************************************

    FDX communication demo application

    $Date: 2011-01-13 11:05:55 +0100 (Thu, 13 Jan 2011) $
    $Revision: 3888 $

    This is the current source for this demo.
    The latest source can be found in demo/etc/fdx/target.

    This part runs on the target processor.
    It communicates with "fdxhost.c" on the host system.

    (c) Lauterbach GmbH
    http://www.lauterbach.com/

**************************************************************************/

#include "stddef.h"
#include "t32fdx.h"

#ifdef C55X
#define FDXTEST_BUFSIZE	0x0820
#else
#define FDXTEST_BUFSIZE	0x1000
#endif


T32_Fdx_DefineChannel(FdxTestSendBuffer,FDXTEST_BUFSIZE);
T32_Fdx_DefineChannel(FdxTestReceiveBuffer,FDXTEST_BUFSIZE);

static unsigned char buf[1024];

static void fdxerror()
{
    /* place a breakpoint here to catch communication errors */
}

static void fdxtest()
{
    int             i;
    int             len;

    T32_Fdx_InitChannel(FdxTestSendBuffer);
    T32_Fdx_InitChannel(FdxTestReceiveBuffer);

    T32_Fdx_EnableChannel(FdxTestSendBuffer);
    T32_Fdx_EnableChannel(FdxTestReceiveBuffer);

    for (i = 0; i < 50; i++) {
	len = i + 2;
	buf[0] = (unsigned char)( '0' + i );
	buf[len - 1] = (unsigned char)( '1' + i );
	T32_Fdx_Send(&FdxTestSendBuffer, buf, len);
    }

    buf[0] = 0;
    T32_Fdx_Send(&FdxTestSendBuffer, buf, 1);

    for (i = 0; i < 10; i++) {
	buf[0] = 'a';
	buf[1] = 'b';
	buf[2] = 'c';
	buf[3] = (unsigned char) i;
	buf[999] = (unsigned char) i;
	T32_Fdx_Send(&FdxTestSendBuffer, buf, 1000);
    }

    buf[0] = 0;
    T32_Fdx_Send(&FdxTestSendBuffer, buf, 1);

    for (i = 0; i < 50; i++) {
	len = T32_Fdx_Receive(&FdxTestReceiveBuffer, buf, sizeof(buf));
	if (len <= 0)
	    fdxerror();
	if (len != i + 2 || buf[0] != '0' + i || buf[len - 1] != '1' + i)
	    fdxerror();
    }

    len = T32_Fdx_Receive(&FdxTestReceiveBuffer, buf, sizeof(buf));
    if (len != 1)
	fdxerror();

    for (i = 0; i < 10; i++) {
	len = T32_Fdx_Receive(&FdxTestReceiveBuffer, buf, sizeof(buf));
	if (len != 1000)
	    fdxerror();
    }

    len = T32_Fdx_Receive(&FdxTestReceiveBuffer, buf, sizeof(buf));
    if (len != 1)
	fdxerror();

    for (i = 0; i < 1000; i++) {
	buf[0] = 0;
	T32_Fdx_Send(&FdxTestSendBuffer, buf, 1);
    }

    len = T32_Fdx_Receive(&FdxTestReceiveBuffer, buf, sizeof(buf));
    if (len != 1)
	fdxerror();

    for (i = 0; i < 1000; i++) {
	buf[0] = 0;
	T32_Fdx_Send(&FdxTestSendBuffer, buf, 1);
    }

    len = T32_Fdx_Receive(&FdxTestReceiveBuffer, buf, sizeof(buf));
    if (len != 1)
	fdxerror();

    for (i = 0; i < 1000; i++) {
	len = T32_Fdx_Receive(&FdxTestReceiveBuffer, buf, sizeof(buf));
	if (len <= 0)
	    fdxerror();
	if (len != 1)
	    fdxerror();
    }

    buf[0] = 0;
    T32_Fdx_Send(&FdxTestSendBuffer, buf, 1);

    for (i = 0; i < 1000; i++) {
	len = T32_Fdx_Receive(&FdxTestReceiveBuffer, buf, sizeof(buf));
	if (len <= 0)
	    fdxerror();
	if (len != 1)
	    fdxerror();
	buf[0] = 0;
	T32_Fdx_Send(&FdxTestSendBuffer, buf, 1);
    }

    for (i = 0; i < 100; i++) {
	buf[0] = 0;
	T32_Fdx_Send(&FdxTestSendBuffer, buf, 1024);
    }

    for (i = 0; i < 100; i++) {
	len = T32_Fdx_Receive(&FdxTestReceiveBuffer, buf, sizeof(buf));
	if (len <= 0)
	    fdxerror();
	if (len != 1024)
	    fdxerror();
    }

    buf[0] = 0;
    T32_Fdx_Send(&FdxTestSendBuffer, buf, 1);

    while (T32_Fdx_Pending(&FdxTestSendBuffer))
       T32_Fdx_Poll();
}


int main()
{
    fdxtest();
    return 0;
}

