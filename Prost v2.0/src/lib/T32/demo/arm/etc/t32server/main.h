// --------------------------------------------------------------------------------
// @Title: t32server - main
// @Description: -
// @Author: KJM
// @Copyright: (C) 1989-2014 Lauterbach GmbH, licensed for use with TRACE32(R) only
// --------------------------------------------------------------------------------
// $Id: main.h 7571 2014-08-25 15:50:21Z kjmal $

#ifndef MAIN_
#define MAIN_

#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>	/* main.c, remote.c */
#include <errno.h>	/* fileio.c, main.c, remote.c */

#include <string.h>	/* fileio.c, main.c, remote.c */
#include <fcntl.h>	/* fileio.c, main.c, thread.c */

#include <sys/socket.h>	/* main.c, included in remote.c */

#include <time.h>

#define BUFSIZE  4095

extern char serial_dcc;
extern int armfamily;


#endif /*MAIN_*/
