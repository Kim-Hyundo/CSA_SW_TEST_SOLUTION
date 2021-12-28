// --------------------------------------------------------------------------------
// @Title: perf_linux_dcc - DCC functions
// @Description: -
// @Author: ABO
// @Copyright: (C) 1989-2015 Lauterbach GmbH, licensed for use with TRACE32(R) only
// --------------------------------------------------------------------------------
// $Id: arm-dcc.c 8551 2015-07-23 11:07:29Z abouassida $

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#include "arm-dcc.h"

#define MIN(A,B) (( (A) < (B)) ? (A) : (B))

char serial_dcc = 0;

int armfamily; 	/* = 9 for arm7,9 and =11 for arm10,11, CORTEX */

int get_dcc_status(int arm)
{
	int status = 0;

	if (arm == 9)
		asm volatile("MRC p14,0,%0,c0,c0": "=r" (status));
	else if (arm == 11)
	{
		asm volatile("MRC p14,0,%0,c0,c1": "=r" (status));
		status = ((status & 0x40000000) >> 30) + ((status & 0x20000000) >> 28);
	}

	return status;
}
 
void write_dcc_reg(int arm, int data, int terminal)
{
 	if (!terminal)
		data |= 0x0c000000;
	if (arm == 9)
		asm volatile("MCR p14,0,%0,c1,c0"::"r" (data));
	else if (arm == 11)
		asm volatile("MCR p14,0,%0,c0,c5"::"r" (data));
	return;
}


int send_dcc(char buf , int timeout, int terminal)
{
	int status;
	int data = 0;
	time_t startingTime;
 
		data = buf;
		startingTime = time(NULL);
		do {
			status = get_dcc_status(armfamily);
			if (((time(NULL)-startingTime)*2000) >= timeout) {
			    return 0;
			}

		} while (status & 0x2);
		write_dcc_reg(armfamily, data, terminal);
 
return 0;
}


void get_arm_version()
{
	int count = 0;;
	FILE * fd;
	char buf[500];
	char *res, *ptr;
	printf("1\n");
	fd = fopen("/proc/cpuinfo", "r");
	if (fd < 0) {
		printf("error identifying arm version, assuming it is arm 7/9\n");
		armfamily = 9;
		return;
	}
	while (1) {
		res = fgets(buf, sizeof buf - 1, fd);
		if ((int)res == EOF)
			break;
		if (count == 0)
			printf("%s", buf);
		count++;
		if (strstr(buf, "Processor") || strstr(buf, "processor") || strstr(buf, "PROCESSOR")) {
			if (strstr(buf, "CORTEX") || strstr(buf, "cortex")) {
				armfamily = 11;
	 			goto done;
			}
			ptr = strstr(buf, "ARM");
			if (ptr) {
				ptr += 3;
				if (*ptr == '9' || *ptr == '7') {
					armfamily = 9;
					goto done;
				} else if (ptr[0] == '1' && ptr[1] == '1') {
					armfamily = 11;
					goto done;
				}
			}
			ptr = strstr(buf, "Feroceon");
			if (ptr) {
				armfamily = 9;
				goto done;
			}

			continue;
		}
		if (strstr(buf, "architecture")) {
			ptr = strchr(buf, ':');
			if (ptr)
				ptr+=2;
			else
				continue;
			if (*ptr == '5') {
				armfamily = 9;
			} else {
				armfamily = 11;
			}
			goto done;
		}
		if (strstr(buf, "CPU part") || strstr(buf, "cpu part")) {
			if (strstr(buf, "0x9") || strstr(buf, "0x7")) {
				armfamily = 9;
			} else {
				armfamily = 11;
			}
		}
	}
	printf("error identifying arm version, assuming it is arm 7/9\n");
	armfamily = 9;
	return;
done:
	fclose(fd);
}

