/*
** Copyright (C) ARM Limited, 2006. All rights reserved.
*/

/*
** This file contains Stack and Heap settings
** used for scatter file and MPU config.
**/

#define TWO_REGION

#define STACK_BASE  0x20080000      /* Stack start address */
#define STACK_SIZE  0x1000          /* length stack grows downwards */

#define HEAP_BASE   0x2008E000       /* Heap starts address */
#define HEAP_SIZE   0x1000           /* Heap Length */

#define PROCESS_STACK_SIZE 0x400
