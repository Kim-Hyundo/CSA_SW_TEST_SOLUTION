/*
 * Author: Insub Song (insub.song@halla.com)
 * Date  : 2019.02.01
 */

#ifndef FS_HWFAILURE_H
#define FS_HWFAILURE_H

inline void *getA11(void)
{
	void *ret;
	__asm volatile ("mov.aa %0, a11": "=a" (ret) : :"a11");
	return ret;
}

void put_hw_err(uint8 ag_idx, uint32 alarm);
void amend_hw_err_cnt(int amount);


void dump_ext_wdg_reset(void);
void dump_smu_debug(void);

void FS_HWFailureTest(void);

void FS_UpdateInfo_HWFailure(void);
void FS_SetDiagsta_HWFailure(void);
void FS_SetInhibit_HWFailure(void);

#endif  /* FS_HWFAILURE_H */
