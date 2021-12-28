/*
 * Author: Insub Song (insub.song@halla.com)
 * Date  : 2019.02.01
 */
#include "Rte_SWC_DiagnosticMonitor.h"
#include "App_NvM_Ram.h"
#include "DRV_par.h"

/* Infineon */
#include "Mcu.h"
#include "IfxScu_reg.h"
#include "Smu.h"

#include "SWC_Failsafe.h"
#include "FS_HWFailure.h"
#include "FS_BatteryVoltage.h"

enum {
    PMIC_1P3V,
    PMIC_3P3V,
    PMIC_5P0V,
    PMIC_NUM
};

boolean internal_hw_fault = FALSE;

static vol_cond_t vol_cond[PMIC_NUM] = {
    [PMIC_1P3V] = {
        .high = {1400, 1500},
        .low = {1000, 1100},
        .detect_tick_thr = MS2TICK(10000),
        .recover_tick_thr = MS2TICK(4000),
    },
    [PMIC_3P3V] = {
        .high = {3600, 3800},
        .low = {2800, 3000},
        .detect_tick_thr = MS2TICK(10000),
        .recover_tick_thr = MS2TICK(4000),
    },
    [PMIC_5P0V] = {
        .high = {5300, 5700},
        .low = {4300, 4700},
        .detect_tick_thr = MS2TICK(10000),
        .recover_tick_thr = MS2TICK(4000),
    },
};
static vol_info_t vol_info[PMIC_NUM] = {
    [PMIC_1P3V].p_vol = &vol_grp[VOL_PMIC1P25],
    [PMIC_3P3V].p_vol = &vol_grp[VOL_PMIC3P3],
    [PMIC_5P0V].p_vol = &vol_grp[VOL_PMIC5P0],
};

inline void put_hw_err(uint8 ag_idx, uint32 alarm)
{
    if (!get_precond_ptr()->is_norm_vol)
        return;

    if (int_err_info.hw_err_cnt < 255)
        int_err_info.hw_err_cnt++;

    for (int i = ARRAY_SIZE(int_err_info.hw_err) - 1; i > 0; i--)
        int_err_info.hw_err[i] = int_err_info.hw_err[i - 1];

    int_err_info.hw_err[0].ag_idx = ag_idx;
    int_err_info.hw_err[0].alarm = alarm;
}

void amend_hw_err_cnt(int amount)
{
    /* Increase or decrease by passed amount and ranging from 0 to 255 */
    int cnt = (int)(int_err_info.hw_err_cnt + amount);
    cnt = __max(__min(cnt, 255), 0);
    int_err_info.hw_err_cnt = cnt;
}

void dump_ext_wdg_reset(void)
{
    put_hw_err(7, 0xFFFFFFFF);
}

void dump_smu_status(void)
{
#ifndef __PROST_TEST
    static uint32 SMU_ALARM_Prev[16];
    for (uint32 SMU_ALARM, i = SMU_ALARM_GROUP0; i <= SMU_ALARM_GROUP11; i++) {
        Smu_GetAlarmStatus((uint8)i, &SMU_ALARM);
		switch(i)
		{
		    case SMU_ALARM_GROUP0:
			case SMU_ALARM_GROUP1: 
			case SMU_ALARM_GROUP2: 
			case SMU_ALARM_GROUP3: 
			case SMU_ALARM_GROUP4:
			case SMU_ALARM_GROUP5:
				//if((SMU_ALARM != 0x2490)&&(SMU_ALARM_Prev[i]!=SMU_ALARM))
                if(((SMU_ALARM & (~0x2490))!=0x0)&&(SMU_ALARM_Prev[i]!=SMU_ALARM))
				{
				    SMU_ALARM_Prev[i] = SMU_ALARM;
                    put_hw_err((uint8)i, SMU_ALARM);
					store_in_nvm();
				}
				break;
			case SMU_ALARM_GROUP6:
				if(((SMU_ALARM & (~0x124800))!=0x0)&&(SMU_ALARM_Prev[i]!=SMU_ALARM))
				{
				    SMU_ALARM_Prev[i] = SMU_ALARM;
                    put_hw_err((uint8)i, SMU_ALARM);
					store_in_nvm();
				}
				break;
			case SMU_ALARM_GROUP7:
				if(((SMU_ALARM & (~0x0E0E0092))!=0x0)&&(SMU_ALARM_Prev[i]!=SMU_ALARM))
				{
				    SMU_ALARM_Prev[i] = SMU_ALARM;
                    put_hw_err((uint8)i, SMU_ALARM);
					store_in_nvm();
				}
				break;
			case SMU_ALARM_GROUP8:
			case SMU_ALARM_GROUP9:
			case SMU_ALARM_GROUP10:
			case SMU_ALARM_GROUP11:
				if((SMU_ALARM != 0x0)&&(SMU_ALARM_Prev[i]!=SMU_ALARM))
				{
				    SMU_ALARM_Prev[i] = SMU_ALARM;
                    put_hw_err((uint8)i, SMU_ALARM);
					store_in_nvm();
				}
				break;
			default :
				break;
			}
          
    }
#endif /* __PROST_TEST */
}


void dump_smu_debug(void)
{
#ifndef __PROST_TEST
    for (uint32 SMU_ALARM, i = SMU_ALARM_GROUP0; i <= SMU_ALARM_GROUP6; i++) {
        Smu_GetAlarmDebugStatus((uint8)i, &SMU_ALARM);
        if (SMU_ALARM) {
            put_hw_err((uint8)i, SMU_ALARM);
            break;
        }
    }
#endif
}


#if FS_DEBUG
/*TODO: develop hw test code after template code release*/
uint8 hw_test_case = 0;
uint32 test_val = 0;
uint8 AG5_pos = 0;

void FS_HWFailureTest(void)
{
    /* S watchdog timeout (3, 17) */
    if (hw_test_case == 1)
        while (1) ;

    Mcal_ResetSafetyENDINIT_Timed(MCU_SAFETY_ENDINT_TIMEOUT);

    uint32 *test_ptr;

    switch (hw_test_case) {
    case 2:
        SCU_LCLTEST.U = 2;
        break;
    case 3:
        SCU_EVRUVMON.U = test_val;
        break;
    case 4:
        FLASH0_FCON.U = test_val;
        break;
    case 5: /* SW monitor (5, X) */
        Smu_SetAlarmStatus(5, AG5_pos);
        break;
    case 9: /* Multiple fault */
        test_ptr = (uint32 *)0x8003A510;
        *test_ptr = 100;
        break;
    }
    hw_test_case = 0;

    Mcal_SetSafetyENDINIT_Timed();
}
#endif


void FS_UpdateInfo_HWFailure(void)
{
#ifndef __PROST_TEST
    struct precondition *p = get_precond_ptr();
    boolean meet_precond = p->is_norm_vol && p->for_3min_after_ign_off;

    if (meet_precond) {
		dump_smu_status();

        /* PMIC Voltage */
        for (int i = PMIC_NUM; i--;) {
            update_vol_info(meet_precond, &vol_info[i], &vol_cond[i]);
            if (vol_info[i].high.fault || vol_info[i].low.fault)
                Smu_SetAlarmStatus(SMU_ALARM_GROUP10, SMU_ALARM_6);
        }

        internal_hw_fault = (int_err_info.hw_err_cnt > ERR_CNT_THR) ? TRUE : FALSE;
    }
#endif
}

void FS_SetDiagsta_HWFailure(void)
{
    SET_DTC(C160404, internal_hw_fault);
}

void FS_SetInhibit_HWFailure(void)
{
    if (internal_hw_fault) {
        update_inhibit_info(
            (struct inhibit_info){
                .fca = {1,1,1,1,1,1,1,1,1},
                .scc = {1,1,1,1},
                .sccml = {1},
                .nscc = {1,1},
                .lfa = {1,1},
                .hda = {1,1,1,1},
                .bca = {1,0,1,0},
                .sea = {1},
                .rcca = {1,0},
                .warning = {3,3,3,3,HDA_LFA_FAULT,5,1},
            }
        );
    }
}