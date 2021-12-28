// --------------------------------------------------------------------------------
// @Title: perf_linux_dcc - DCC functions
// @Description: -
// @Author: ABO
// @Copyright: (C) 1989-2015 Lauterbach GmbH, licensed for use with TRACE32(R) only
// --------------------------------------------------------------------------------
// $Id: arm-dcc.h 8551 2015-07-23 11:07:29Z abouassida $


#ifdef __arm__
#ifndef ARMDCC_H_
#define ARMDCC_H_

#define TTY_BUF_SIZE 3072
#define TERMINAL_BLOCK_SIZE 3


int get_dcc_status(int arm);
void write_dcc_reg(int arm, int data, int terminal);

int send_dcc(char buf , int timeout, int terminal);

void get_arm_version();
#endif /*ARMDCC_H_*/
#endif /* __arm__ */

