/*
 * Author: Insub Song (insub.song@halla.com)
 * Date  : 2019.02.01
 */

#include "Rte_SWC_DiagnosticMonitor.h"

#include "SWC_Failsafe.h"
#include "FS_BatteryVoltage.h"

static vol_cond_t bat_cond = {
    .high = {16000, 17000},
    .low = {8000, 9000},
    .detect_tick_thr = MS2TICK(10000),
    .recover_tick_thr = MS2TICK(4000),
};

vol_info_t bat_info = {
    .p_vol = &vol_grp[VOL_BAT],
};

void update_vol_info(boolean meet_precond, vol_info_t *info, vol_cond_t *cond)
{
/*
 * T: True / F: False / X: Don't care / D: Detect / R: Recover
 *
 * [Logic Table]
 * ----------------------------------------------------
 * |          Vol range          | fault | High | Low |
 * ----------------------------------------------------
 * |        v > high_upper       |   X   |   D  |  R  |
 * | high_lower < v < high_upper |   T   |   D  |  R  |
 * | high_lower < v < high_upper |   F   |   R  |  R  |
 * |  low_upper < v < high_lower |   X   |   R  |  R  |
 * |  low_lower < v < low_upper  |   F   |   R  |  R  |
 * |  low_lower < v < low_upper  |   T   |   R  |  D  |
 * |        v < low_lower        |   X   |   R  |  D  |
 * ----------------------------------------------------
 */
    if (!meet_precond) {
        if (!info->high.fault)
            info->high.detect_tick = 0;
        if (!info->low.fault)
            info->low.detect_tick = 0;
    }


    uint16 vol = *info->p_vol;

    if (vol > cond->high.upper || (vol > cond->high.lower && info->high.fault)) {
        // High detect & Low recover
        if (meet_precond) {
            info->high.detect_tick = __min(info->high.detect_tick + 1, cond->detect_tick_thr);
            info->high.recover_tick = 0;
        }
        info->low.detect_tick = 0;
        info->low.recover_tick = __min(info->low.recover_tick + 1, cond->recover_tick_thr);
    } else if (vol < cond->low.lower || (vol < cond->low.upper && info->low.fault)) {
        // High recover & Low detect
        if (meet_precond) {
            info->low.detect_tick = __min(info->low.detect_tick + 1, cond->detect_tick_thr);
            info->low.recover_tick = 0;
        }
        info->high.detect_tick = 0;
        info->high.recover_tick = __min(info->high.recover_tick + 1, cond->recover_tick_thr);
    } else {
        // High & Low recover
        info->high.detect_tick = 0;
        info->high.recover_tick = __min(info->high.recover_tick + 1, cond->recover_tick_thr);
        info->low.detect_tick = 0;
        info->low.recover_tick = __min(info->low.recover_tick + 1, cond->recover_tick_thr);
    }

    if (info->high.detect_tick == cond->detect_tick_thr)
        info->high.fault = TRUE;
    if (info->high.recover_tick == cond->recover_tick_thr)
        info->high.fault = FALSE;
    if (info->low.detect_tick == cond->detect_tick_thr)
        info->low.fault = TRUE;
    if (info->low.recover_tick == cond->recover_tick_thr)
        info->low.fault = FALSE;


    if (TEST_BIT(recover_mask[RECOVER_GROUP_0], VOL_HIGH))
        info->high.fault = FALSE;
    if (TEST_BIT(recover_mask[RECOVER_GROUP_0], VOL_LOW))
        info->low.fault = FALSE;
}

void FS_UpdateInfo_BatteryVoltage(void)
{
    struct precondition *p = get_precond_ptr();
    boolean meet_precond = p->is_eng_run && p->is_not_ecan_busoff && p->for_3min_after_ign_off;
    update_vol_info(meet_precond, &bat_info, &bat_cond);
}

void FS_SetDiagsta_BatteryVoltage(void)
{
    SET_DTC(C110117, bat_info.high.fault);
    SET_DTC(C110216, bat_info.low.fault);
}

void FS_SetInhibit_BatteryVoltage(void)
{
    if (bat_info.high.fault) {
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

    if (bat_info.low.fault) {
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

void FS_Clear_BatteryVoltage(void)
{
    bat_info = (vol_info_t) {.p_vol = &vol_grp[VOL_BAT]};
}