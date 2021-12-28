// --------------------------------------------------------------------------------
// @Title: perf_linux_dcc - main
// @Description:
//  Sending data to DCC
// @Author: ABO
// @Copyright: (C) 1989-2014 Lauterbach GmbH, licensed for use with TRACE32(R) only
// --------------------------------------------------------------------------------
// $Id: main.c 8551 2015-07-23 11:07:29Z abouassida $

 
#include "main.h"
#include "arm-dcc.h"

#include <sched.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>	 
#include <errno.h>	 
#include <fcntl.h> 
#include <sys/socket.h> 
#include <time.h> 

int main(int argc, char *argv[])
{
	char ch='a';
 

	cpu_set_t cur_mask,new_mask;
	/* force the DCC_app to run on core 0 since TRACE32 only uses the DCC register of the first core */
	CPU_ZERO(&new_mask);	
	CPU_SET(0, &new_mask);

	if (sched_setaffinity(0, sizeof (new_mask), &new_mask)) {
		printf("failed to set affinity.\n");
		goto done;
	}

	if (sched_getaffinity(0, sizeof (cur_mask), &cur_mask) < 0) {
		printf( "failed to get affinity.\n");
	}
done:
	get_arm_version();
	while (1)
	{ 
		send_dcc(ch,5000,1);
		sleep(1);
		ch++;
		if (ch>'z')
		ch='a';
			
	}
	return 0;	
}
/* end of main.c */
