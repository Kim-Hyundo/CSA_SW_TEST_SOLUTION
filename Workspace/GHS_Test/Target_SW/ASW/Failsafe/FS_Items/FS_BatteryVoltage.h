#ifndef FS_BATTERYVOLTAGE_H
#define FS_BATTERYVOLTAGE_H

#include "Platform_Types.h"

typedef const struct {
    struct {
        uint16 lower;
        uint16 upper;
    } high, low;

    uint16 detect_tick_thr;
    uint16 recover_tick_thr;
} vol_cond_t;

typedef struct {
    struct {
        boolean fault;
        uint16 detect_tick;
        uint16 recover_tick;
    } high, low;

    uint16 *p_vol;
} vol_info_t;

extern vol_info_t bat_info;


void update_vol_info(boolean meet_precond, vol_info_t *info, vol_cond_t *cond);

void FS_UpdateInfo_BatteryVoltage(void);
void FS_SetDiagsta_BatteryVoltage(void);
void FS_SetInhibit_BatteryVoltage(void);
void FS_Clear_BatteryVoltage(void);

#endif  /* FS_BATTERYVOLTAGE_H */
