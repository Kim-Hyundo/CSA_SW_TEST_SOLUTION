#ifndef FS_INVALIDSIGNAL_H
#define FS_INVALIDSIGNAL_H

#include "Platform_Types.h"
#include "DRV_par.h"

#define VALID_CNT_THR   2

typedef struct {
    boolean fault;
    uint16 detect_cnt;
    uint16 recover_cnt;
} sigerr_t;

void update_info(sigerr_t *info, boolean meet_precond, boolean detect_cond, boolean recover_cond, uint16 detect_thr, uint16 recover_thr);

#if CCAN == CANFD
#if VEH_TYPE == NORMAL
enum {
    EMS_C161386_0,
    EMS_C161386_1,
    EMS_C161386_2,
    EMS_ITEM_NUM
};
enum {
    TCU_C164686_0,
    TCU_ITEM_NUM
};

#elif VEH_TYPE == EV
enum {
    VCU_C161C86_0,
    VCU_C161C86_1,
    VCU_ITEM_NUM
};

#elif VEH_TYPE == HEV
enum {
    EMS_C161386_0,
    EMS_ITEM_NUM
};
enum {
    HCU_C161C86_0,
    HCU_C161C86_1,
    HCU_ITEM_NUM
};
enum {
    HTCU_C164686_0,
    HTCU_ITEM_NUM
};
#endif /* VEH_TYPE */

enum {
    CLU_C165686_0,
    CLU_C165686_1,
    CLU_ITEM_NUM
};

enum {
    ESC_C164286_0,
    ESC_C164286_1,
    ESC_C164286_2,
    ESC_NA_0,
    ESC_C16B881_0,
    ESC_C136081_0,
    ESC_NA_1,
    ESC_C163881_0,
    ESC_C164282_0,
    ESC_C164281_0,
    ESC_ITEM_NUM
};

enum {
    MDPS_C168886_0,
    MDPS_C168886_1,
    MDPS_C223986_0,
    MDPS_C223986_1,
    MDPS_ITEM_NUM
};

enum {
    SAS_C181486_0,
    SAS_ITEM_NUM
};

enum {
    ICSC_C187002_0,
    ICSC_ITEM_NUM
};

enum {
    ICU_C183E86_0,
    ICU_ITEM_NUM
};

enum {
    YRS_C184286_0,
    YRS_ITEM_NUM
};

enum {
    SWRC_C183D82_0,
    SWRC_ITEM_NUM
};

enum {
    BCM_C181281_0,
    BCM_C181281_1,
    BCM_C181281_2,
    BCM_ITEM_NUM
};

enum {
    SBCM_C185481_0,
    SBCM_C185381_0,
    SBCM_ITEM_NUM
};


#elif CCAN == HSCAN
enum {
    EMS_C161386_0,
    EMS_C161386_1,
    EMS_ITEM_NUM
};

enum {
    TCU_C164686_0,
    TCU_ITEM_NUM
};

enum {
    CGW_C181786_0,
    CGW_ITEM_NUM
};

enum {
    CLU_C165686_0,
    CLU_C165686_1,
    CLU_ITEM_NUM
};

enum {
    ESC_C164286_0,
    ESC_C164286_1,
    ESC_NA_0,
    ESC_C16B881_0,
    ESC_C136081_0,
    ESC_NA_1,
    ESC_C163881_0,
    ESC_ITEM_NUM
};

enum {
    MDPS_C168886_0,
    MDPS_C168886_1,
    MDPS_C223986_0,
    MDPS_ITEM_NUM
};

enum {
    SAS_C181486_0,
    SAS_ITEM_NUM
};
#endif /* CCAN */

enum {
    NAVI_C174686_0,
    NAVI_C183186_0,
    NAVI_C183186_1,
    NAVI_ITEM_NUM
};

enum {
    FR_CMR_28B086_0,
    FR_CMR_28B086_1,
    FR_CMR_NA_0,
    FR_CMR_ITEM_NUM
};

enum {
    FR_RDR_C28B186_0,
    FR_RDR_NA_0,
    FR_RDR_ITEM_NUM
};

enum {
    FR_C_RDR_C188186_0,
    FR_C_RDR_C188186_1,
    FR_C_RDR_NA_0,
    FR_C_RDR_NA_1,
    FR_C_RDR_ITEM_NUM
};

boolean is_valid_ems(void);

void FS_UpdateInfo_InvalidSignal(void);
void FS_SetDiagsta_InvalidSignal(void);
void FS_SetInhibit_InvalidSignal(void);
void FS_Clear_InvalidSignal(void);



#endif  /* FS_INVALIDSIGNAL_H */
