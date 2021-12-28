#ifndef FS_CANBUSOFF_H
#define FS_CANBUSOFF_H

#include "Platform_Types.h"

struct busoff_info {
    boolean fault;
    boolean bor_enter;
    uint16 bor_tick;
};

extern volatile struct busoff_info ecan_busoff, acan_busoff;

void FS_UpdateInfo_CANBusOff(void);
void FS_SetDiagsta_CANBusOff(void);
void FS_SetInhibit_CANBusOff(void);

#endif  /* FS_CANBUSOFF_H */
