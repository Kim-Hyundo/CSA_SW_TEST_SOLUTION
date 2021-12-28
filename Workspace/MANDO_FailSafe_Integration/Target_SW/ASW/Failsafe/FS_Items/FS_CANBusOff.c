/*
 * Author: Insub Song (insub.song@halla.com)
 * Date  : 2019.02.01
 */
#include "Rte_SWC_DiagnosticMonitor.h"

#include "SWC_Failsafe.h"
#include "FS_CANBusOff.h"

#define DETECT_TIME 500 // ms

volatile struct busoff_info ecan_busoff, acan_busoff;

void FS_UpdateInfo_CANBusOff(void)
{
    struct precondition *p = get_precond_ptr();
    boolean meet_precond = p->is_norm_vol && p->is_3s_after_ign_on && p->for_3min_after_ign_off;

    if (ecan_busoff.bor_enter == FALSE) {
        ecan_busoff.bor_tick = 0;
        ecan_busoff.fault = FALSE;
    } else if (meet_precond) {
        if (++ecan_busoff.bor_tick >= MS2TICK(DETECT_TIME)) {
            ecan_busoff.bor_tick = MS2TICK(DETECT_TIME);
            ecan_busoff.fault = TRUE;
        }
    } else {
        ecan_busoff.bor_tick = 0;
    }

    meet_precond = p->is_norm_vol && p->is_3s_after_ign_on;

    if (acan_busoff.bor_enter == FALSE) {
        acan_busoff.bor_tick = 0;
        acan_busoff.fault = FALSE;
    } else if (meet_precond) {
        if (++acan_busoff.bor_tick >= MS2TICK(DETECT_TIME)) {
            acan_busoff.bor_tick = MS2TICK(DETECT_TIME);
            acan_busoff.fault = TRUE;
        }
    } else {
        acan_busoff.bor_tick = 0;
    }

    if (TEST_BIT(recover_mask[RECOVER_GROUP_0], ECAN_BUSOFF))
        ecan_busoff.fault = FALSE;
    if (TEST_BIT(recover_mask[RECOVER_GROUP_0], ACAN_BUSOFF))
        acan_busoff.fault = FALSE;
}

void FS_SetDiagsta_CANBusOff(void)
{
    SET_DTC(C161E88, ecan_busoff.fault);
    SET_DTC(C160A88, acan_busoff.fault);
}

void FS_SetInhibit_CANBusOff(void)
{
    if (ecan_busoff.fault) {
        update_inhibit_info(
            (struct inhibit_info) {
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

    if (acan_busoff.fault) {
        update_inhibit_info(
            (struct inhibit_info) {
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