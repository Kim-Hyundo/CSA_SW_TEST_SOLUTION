
/*****************************************************************************

	Simulation model for the Tricore STM timers

	This model support up to 3 STM timers and 3 TriCore cores running in SMP
	configuration.

	Usage:
		SIM.LOAD stm_aurix <stm0_base_address> <src_stm0sr0_address>

*****************************************************************************/

#include "simul.h"
#include <string.h>

#define MAX_STM_TIMERS     3
#define MAX_CORES          3

#define NUM_OF_STM_REGS    23 /* total number of stm registers */
#define NUM_OF_REGS_RW     21 /* number of Read Write registers */

#define CLC_OFFSET         0x00    /* rw */
#define CMP0_OFFSET        0x30    /* rw */
#define CMP1_OFFSET        0x34    /* rw */
#define CMCON_OFFSET       0x38    /* rw */
#define ICR_OFFSET         0x3C    /* rw */
#define ISCR_OFFSET        0x40    /* rw */
#define OCS_OFFSET         0xE8    /* rw */
#define KRSTCLR_OFFSET     0xEC    /* rw */
#define KRST1_OFFSET       0xF0    /* rw */
#define KRST0_OFFSET       0xF4    /* rw */
#define ACCEN0_OFFSET      0xFC    /* rw */

#define TIM0_OFFSET        0x10    /* ro -> rw */
#define TIM1_OFFSET        0x14    /* ro -> rw */
#define TIM2_OFFSET        0x18    /* ro -> rw */
#define TIM3_OFFSET        0x1C    /* ro -> rw */
#define TIM4_OFFSET        0x20    /* ro -> rw */
#define TIM5_OFFSET        0x24    /* ro -> rw */
#define TIM6_OFFSET        0x28    /* ro -> rw */
#define TIM0SV_OFFSET      0x50    /* ro -> rw */
#define CAP_OFFSET         0x2C    /* ro -> rw */
#define CAPSV_OFFSET       0x54    /* ro -> rw */
#define ID_OFFSET          0x08    /* ro */

#define ACCEN1_OFFSET      0xF8    /* ro */

#define TC_AURIX_ICR_OFFSET(core)         (0xF881FE2C|((core)<<17))

/**************************************************************************

	Model data structures

**************************************************************************/

/* STM 64 bit Timer struct */
struct Tim0 {                          simulWord64 v : 32;    simulWord64 after : 32; };
struct Tim1 { simulWord64 before : 4;  simulWord64 v : 32;    simulWord64 after : 28; };
struct Tim2 { simulWord64 before : 8;  simulWord64 v : 32;    simulWord64 after : 24; };
struct Tim3 { simulWord64 before : 12; simulWord64 v : 32;    simulWord64 after : 20; };
struct Tim4 { simulWord64 before : 16; simulWord64 v : 32;    simulWord64 after : 16; };
struct Tim5 { simulWord64 before : 20; simulWord64 v : 32;    simulWord64 after : 12; };
struct Tim6 { simulWord64 before : 32; simulWord64 v : 32;                            };

/* STM 64 bit Timer struct */
typedef union u_timer
{
    simulWord64 timer64;
    struct Tim0 s_tim0;
    struct Tim1 s_tim1;
    struct Tim2 s_tim2;
    struct Tim3 s_tim3;
    struct Tim4 s_tim4;
    struct Tim5 s_tim5;
    struct Tim6 s_tim6;
} u_timer;

/* STM Regsters struct */
typedef struct
{
    simulWord32    clc, cmp0, cmp1, cmcon, icr, iscr, ocs, krstclr, krst1, krst0, accen0, id, cap, tim0sv, capsv, accen1;
    u_timer        u_timer64;
}
StmRegisters;

/* STM struct */
typedef struct
{
    simulWord32    baseaddress;
    void *         p_timer;
    StmRegisters   reg;
}
STM;


/* Interrupt Router STM SRC registers struct */
typedef struct
{
    simulWord32    sr0, sr1;
    simulWord32    sr0address, sr1address;
}
StmSRCRegisters;


/* Interrupt controller struct */
typedef struct
{
    StmSRCRegisters  stm_src[MAX_STM_TIMERS];
    simulWord32      icr[MAX_CORES];          /*TriCore ICR registers*/
}
IntController;

/* PerModel complete module struct */
typedef struct
{
    int              bustype;
    STM              stm[MAX_STM_TIMERS];
    IntController    iController;
}
PerModel;

/**************************************************************************

	STM registers callback functions

**************************************************************************/

/* CLC (Clock Control Register) */
static int SIMULAPI CLC_Write(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    simulTime time = 1;
    int i = (cbs->x.bus.address>>8)&0x7;

    SIMUL_InsertWord(processor, &model->stm[i].reg.clc, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);

    if (model->stm[i].reg.clc & 0x1) {
        model->stm[i].reg.clc |= 0x2;
    } else {
        model->stm[i].reg.clc &= ~((simulWord32)0x2);
    }

    if (!(model->stm[i].reg.clc & 0x2)) /* DISS -> 0 PerModel module enabled */
    {
        SIMUL_StartTimer(processor, model->stm[i].p_timer, SIMUL_TIMER_REL | SIMUL_TIMER_CLOCKS, &time);
    }
    else /* DISS -> 1 PerModel module disabled */
    {
        SIMUL_StopTimer(processor, model->stm[i].p_timer);
    }
    return SIMUL_MEMORY_OK;
}

static int SIMULAPI CLC_Read(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    SIMUL_ExtractWord(processor, &model->stm[i].reg.clc, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

/* CMP0 (Compare Register 0) */
static int SIMULAPI CMP0_Write(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    SIMUL_InsertWord(processor, &model->stm[i].reg.cmp0, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

static int SIMULAPI CMP0_Read(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    SIMUL_ExtractWord(processor, &model->stm[i].reg.cmp0, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

/* CMP1 (Compare Register 1) */
static int SIMULAPI CMP1_Write(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    SIMUL_InsertWord(processor, &model->stm[i].reg.cmp1, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

static int SIMULAPI CMP1_Read(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    SIMUL_ExtractWord(processor, &model->stm[i].reg.cmp1, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

/* CMCON (Compare Match Control Register) */
static int SIMULAPI CMCON_Write(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    SIMUL_InsertWord(processor, &model->stm[i].reg.cmcon, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

static int SIMULAPI CMCON_Read(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    SIMUL_ExtractWord(processor, &model->stm[i].reg.cmcon, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

/* ICR (Interrupt Control Register) */
static int SIMULAPI ICR_Write(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    SIMUL_InsertWord(processor, &model->stm[i].reg.icr, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

static int SIMULAPI ICR_Read(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    SIMUL_ExtractWord(processor, &model->stm[i].reg.icr, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

/* ISCR (Interrupt Set/Clear Register) */
static int SIMULAPI ISCR_Write(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    SIMUL_InsertWord(processor, &model->stm[i].reg.iscr, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

static int SIMULAPI ISCR_Read(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    SIMUL_ExtractWord(processor, &model->stm[i].reg.iscr, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

/* OCS (OCDS Control adn Status Register) */
static int SIMULAPI OCS_Write(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    SIMUL_InsertWord(processor, &model->stm[i].reg.ocs, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

static int SIMULAPI OCS_Read(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    SIMUL_ExtractWord(processor, &model->stm[i].reg.ocs, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

/* KRSTCLR (Kernel Reset Status Clear Register) */
static int SIMULAPI KRSTCLR_Write(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    SIMUL_InsertWord(processor, &model->stm[i].reg.krstclr, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

static int SIMULAPI KRSTCLR_Read(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    SIMUL_ExtractWord(processor, &model->stm[i].reg.krstclr, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

/* KRST0 (Kernel Reset Register 0) */
static int SIMULAPI KRST0_Write(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    SIMUL_InsertWord(processor, &model->stm[i].reg.krst0, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

static int SIMULAPI KRST0_Read(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    SIMUL_ExtractWord(processor, &model->stm[i].reg.krst0, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

/* KRST1 (Kernel Reset Register 1) */
static int SIMULAPI KRST1_Write(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    SIMUL_InsertWord(processor, &model->stm[i].reg.krst1, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

static int SIMULAPI KRST1_Read(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    SIMUL_ExtractWord(processor, &model->stm[i].reg.krst1, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

/* ACCEN0 (Access Enable Register) */
static int SIMULAPI ACCEN0_Write(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    SIMUL_InsertWord(processor, &model->stm[i].reg.accen0, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

static int SIMULAPI ACCEN0_Read(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    SIMUL_ExtractWord(processor, &model->stm[i].reg.accen0, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

/* TIM0 (Timer Register 0) */
static int SIMULAPI TIM0_Read(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    simulWord32 tim0 = (simulWord32)model->stm[i].reg.u_timer64.s_tim0.v;
    SIMUL_ExtractWord(processor, &tim0, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);

    return SIMUL_MEMORY_OK;
}

static int SIMULAPI TIM0_Write(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    simulWord32 tim0 = 0;
    SIMUL_InsertWord(processor, &tim0, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    model->stm[i].reg.u_timer64.s_tim0.v = (simulWord64)tim0;
    return SIMUL_MEMORY_OK;
}

/* TIM1 (Timer Register 1) */
static int SIMULAPI TIM1_Read(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    simulWord32 tim1 = (simulWord32)model->stm[i].reg.u_timer64.s_tim1.v;
    SIMUL_ExtractWord(processor, &tim1, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

static int SIMULAPI TIM1_Write(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    simulWord32 tim1 = 0;
    SIMUL_InsertWord(processor, &tim1, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    model->stm[i].reg.u_timer64.s_tim1.v = (simulWord64)tim1;
    return SIMUL_MEMORY_OK;
}

/* TIM2 (Timer Register 2) */
static int SIMULAPI TIM2_Read(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    simulWord32 tim2 = (simulWord32)model->stm[i].reg.u_timer64.s_tim2.v;
    SIMUL_ExtractWord(processor, &tim2, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

static int SIMULAPI TIM2_Write(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    simulWord32 tim2 = 0;
    SIMUL_InsertWord(processor, &tim2, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    model->stm[i].reg.u_timer64.s_tim2.v = (simulWord64)tim2;
    return SIMUL_MEMORY_OK;
}

/* TIM3 (Timer Register 3) */
static int SIMULAPI TIM3_Read(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    simulWord32 tim3 = (simulWord32)model->stm[i].reg.u_timer64.s_tim3.v;
    SIMUL_ExtractWord(processor, &tim3, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

static int SIMULAPI TIM3_Write(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    simulWord32 tim3 = 0;
    SIMUL_InsertWord(processor, &tim3, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    model->stm[i].reg.u_timer64.s_tim3.v = (simulWord64)tim3;
    return SIMUL_MEMORY_OK;
}

/* TIM4 (Timer Register 4) */
static int SIMULAPI TIM4_Read(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    simulWord32 tim4 = (simulWord32)model->stm[i].reg.u_timer64.s_tim4.v;
    SIMUL_ExtractWord(processor, &tim4, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

static int SIMULAPI TIM4_Write(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    simulWord32 tim4 = 0;
    SIMUL_InsertWord(processor, &tim4, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    model->stm[i].reg.u_timer64.s_tim4.v = (simulWord64)tim4;
    return SIMUL_MEMORY_OK;
}

/* TIM5 (Timer Register 5) */
static int SIMULAPI TIM5_Read(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    simulWord32 tim5 = (simulWord32)model->stm[i].reg.u_timer64.s_tim5.v;
    SIMUL_ExtractWord(processor, &tim5, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

static int SIMULAPI TIM5_Write(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    simulWord32 tim5 = 0;
    SIMUL_InsertWord(processor, &tim5, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    model->stm[i].reg.u_timer64.s_tim5.v = (simulWord64)tim5;
    return SIMUL_MEMORY_OK;
}

/* TIM6 (Timer Register 6) */
static int SIMULAPI TIM6_Read(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    simulWord32 tim6 = (simulWord32)model->stm[i].reg.u_timer64.s_tim6.v;
    SIMUL_ExtractWord(processor, &tim6, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

static int SIMULAPI TIM6_Write(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    simulWord32 tim6 = 0;
    SIMUL_InsertWord(processor, &tim6, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    model->stm[i].reg.u_timer64.s_tim6.v = (simulWord64)tim6;
    return SIMUL_MEMORY_OK;
}

/* TIM0SV (Timer Register 0 Secong View) */
static int SIMULAPI TIM0SV_Read(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    SIMUL_ExtractWord(processor, &model->stm[i].reg.tim0sv, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

static int SIMULAPI TIM0SV_Write(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    SIMUL_InsertWord(processor, &model->stm[i].reg.tim0sv, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    model->stm[i].reg.u_timer64.s_tim0.v = (simulWord64)model->stm[i].reg.tim0sv;
    return SIMUL_MEMORY_OK;
}

/* CAP (Timer Capture Register) */
static int SIMULAPI CAP_Read(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    SIMUL_ExtractWord(processor, &model->stm[i].reg.cap, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

static int SIMULAPI CAP_Write(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    SIMUL_InsertWord(processor, &model->stm[i].reg.cap, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

/* CAPSV (Timer Capture Register Second View) */
static int SIMULAPI CAPSV_Read(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    SIMUL_ExtractWord(processor, &model->stm[i].reg.capsv, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

static int SIMULAPI CAPSV_Write(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    SIMUL_InsertWord(processor, &model->stm[i].reg.capsv, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

/* ID (Module Identification Register) */
static int SIMULAPI ID_Read(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    SIMUL_ExtractWord(processor, &model->stm[i].reg.id, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

static int SIMULAPI ACCEN1_Read(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int i = (cbs->x.bus.address >> 8) & 0x7;
    SIMUL_ExtractWord(processor, &model->stm[i].reg.accen1, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

static simulWord32 stm_regs_offset[NUM_OF_STM_REGS] = {
    CLC_OFFSET,
    CMP0_OFFSET,
    CMP1_OFFSET,
    CMCON_OFFSET,
    ICR_OFFSET,
    ISCR_OFFSET,
    OCS_OFFSET,
    KRSTCLR_OFFSET,
    KRST1_OFFSET,
    KRST0_OFFSET,
    ACCEN0_OFFSET,
    TIM0_OFFSET,
    TIM1_OFFSET,
    TIM2_OFFSET,
    TIM3_OFFSET,
    TIM4_OFFSET,
    TIM5_OFFSET,
    TIM6_OFFSET,
    TIM0SV_OFFSET,
    CAP_OFFSET,
    CAPSV_OFFSET,

    ID_OFFSET,
    ACCEN1_OFFSET,
};

void * stm_regread_func[NUM_OF_STM_REGS] = {
    CLC_Read,
    CMP0_Read,
    CMP1_Read,
    CMCON_Read,
    ICR_Read,
    ISCR_Read,
    OCS_Read,
    KRSTCLR_Read,
    KRST1_Read,
    KRST0_Read,
    ACCEN0_Read,
    TIM0_Read,
    TIM1_Read,
    TIM2_Read,
    TIM3_Read,
    TIM4_Read,
    TIM5_Read,
    TIM6_Read,
    TIM0SV_Read,
    CAP_Read,
    CAPSV_Read,

    ID_Read,
    ACCEN1_Read
};

void * stm_regwrite_func[NUM_OF_REGS_RW] = {
    CLC_Write,
    CMP0_Write,
    CMP1_Write,
    CMCON_Write,
    ICR_Write,
    ISCR_Write,
    OCS_Write,
    KRSTCLR_Write,
    KRST1_Write,
    KRST0_Write,
    ACCEN0_Write,
    TIM0_Write,
    TIM1_Write,
    TIM2_Write,
    TIM3_Write,
    TIM4_Write,
    TIM5_Write,
    TIM6_Write,
    TIM0SV_Write,
    CAP_Write,
    CAPSV_Write,
};

/**************************************************************************

	Interrupt controller callback functions

**************************************************************************/

static int SIMULAPI TC_ICR_Read(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    int core = (cbs->x.bus.address >> 17) & 0x7;
    SIMUL_ExtractWord(processor, &model->iController.icr[core], 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}
static int SIMULAPI TC_ICR_Write(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    unsigned int i;
    unsigned int core = (cbs->x.bus.address >> 17) & 0x7;
    simulWord icr_tc = cbs->x.bus.data;
    simulWord old_pipn = ((model->iController.icr[core] >> 16) & 0xff);
    simulWord new_pipn = ((icr_tc >> 16) & 0xff);
    simulWord port_val = 0;

    if (new_pipn == 0 && old_pipn != 0) { //clear pending interrupt from per with the same pending priority
        for (i = 0; i < MAX_STM_TIMERS; i++) {
            simulWord32 sr0 = model->iController.stm_src[i].sr0;
            simulWord32 sr1 = model->iController.stm_src[i].sr1;
            unsigned int tos0 = (unsigned int)((sr0 >> 11) & 0x3);
            unsigned int tos1 = (unsigned int)((sr1 >> 11) & 0x3);

            if (tos0 == core && !!(sr0 & 0x01000000) && !!(sr0 & 0x400)) {
                if (old_pipn == (sr0 & 0xFF)) {//clear this pending interrupt request
                    model->iController.stm_src[i].sr0 &= ~0x01000000;
                    SIMUL_SetPort(processor, -2 - (8 * core), 1, &port_val);
                    break;
                }
            }

            if (tos1 == core && !!(sr1 & 0x01000000) && !!(sr1 & 0x400)) {
                if (old_pipn == (sr1 & 0xFF)) {//clear this pending interrupt request
                    model->iController.stm_src[i].sr1 &= ~0x01000000;
                    SIMUL_SetPort(processor, -2 - (8 * core), 1, &port_val);
                    break;
                }
            }

        }
    }
    SIMUL_InsertWord(processor, &model->iController.icr[core], 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);

    return SIMUL_MEMORY_OK;
}


static int SIMULAPI SRC_STMSR0_Read(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    unsigned int stm_index = (cbs->x.bus.address - model->iController.stm_src[0].sr0address) >> 3;
    SIMUL_ExtractWord(processor, &model->iController.stm_src[stm_index].sr0, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

static int SIMULAPI SRC_STMSR0_Write(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    unsigned int stm_index = (cbs->x.bus.address - model->iController.stm_src[0].sr0address) >> 3;
    SIMUL_InsertWord(processor, &model->iController.stm_src[stm_index].sr0, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

static int SIMULAPI SRC_STMSR1_Read(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    unsigned int stm_index = (cbs->x.bus.address - model->iController.stm_src[0].sr1address) >> 3;
    SIMUL_ExtractWord(processor, &model->iController.stm_src[stm_index].sr1, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

static int SIMULAPI SRC_STMSR1_Write(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    PerModel * model = (PerModel*)_private;
    unsigned int stm_index = (cbs->x.bus.address - model->iController.stm_src[0].sr1address) >> 3;
    SIMUL_InsertWord(processor, &model->iController.stm_src[stm_index].sr1, 32, &cbs->x.bus.address, cbs->x.bus.width, &cbs->x.bus.data);
    return SIMUL_MEMORY_OK;
}

/**************************************************************************

	STM timers callback functions

**************************************************************************/
static void STM_compareInterrupt(PerModel * model, int index)
{
    simulWord64 stm_input_value = model->stm[index].reg.u_timer64.timer64, stm_value, compare_value, compare_value0, compare_value1;
    simulWord32 cmcon_mstart0, cmcon_mstart1, cmcon_msize0, cmcon_msize1, compare_mask = 0;
    simulWord32 icr_cmp0en, icr_cmp1en, icr_cmp0ir, icr_cmp1ir;
    simulWord32 sr_srr0, sr_srr1;
    unsigned int i;

    cmcon_mstart0 = (model->stm[index].reg.cmcon >> 24) & 0x1F;
    cmcon_mstart1 = (model->stm[index].reg.cmcon >> 8) & 0x1F;
    cmcon_msize0 = ((model->stm[index].reg.cmcon) & 0x1F) + 1;
    cmcon_msize1 = ((model->stm[index].reg.cmcon >> 16) & 0x1F) + 1;

    icr_cmp0en = !!(model->stm[index].reg.icr & 0x1);
    icr_cmp1en = !!(model->stm[index].reg.icr & 0x10);
    icr_cmp0ir = !!(model->stm[index].reg.icr & 0x2);
    icr_cmp1ir = !!(model->stm[index].reg.icr & 0x20);

    sr_srr0 = !!(model->iController.stm_src[index].sr0 & 0x01000000);
    sr_srr1 = !!(model->iController.stm_src[index].sr1 & 0x01000000);

    compare_value0 = model->stm[index].reg.cmp0;
    compare_value1 = model->stm[index].reg.cmp1;

    if (icr_cmp0en && !sr_srr0) {
        for (i = 0; i < cmcon_msize0; i++)
            compare_mask |= (1 << i);
        if (compare_mask) {
            stm_value = (stm_input_value >> cmcon_mstart0) & compare_mask;
            compare_value = compare_value0 & compare_mask;
            if (compare_value == stm_value){
                model->stm[index].reg.icr |= 0x2;
                model->iController.stm_src[index].sr0 |= 0x01000000;
            }
        }
    }

    if (icr_cmp1en && !sr_srr1) {
        for (i = 0; i < cmcon_msize1; i++)
            compare_mask |= (1 << i);
        if (compare_mask) {
            stm_value = (stm_input_value >> cmcon_mstart1) & compare_mask;
            compare_value = compare_value1 & compare_mask;
            if (compare_value == stm_value) {
                model->stm[index].reg.icr |= 0x20;
                model->iController.stm_src[index].sr1 |= 0x01000000;
            }
        }
    }

}

static int TIMx_callback(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private, int stm_index)
{
    PerModel * model = (PerModel*)_private;
    simulTime time = 1;
    simulWord32 sr_srr0, sr_srr1;

    /* increment timer value */
    model->stm[stm_index].reg.u_timer64.timer64++;

    STM_compareInterrupt(model, stm_index);

    sr_srr0 = !!(model->iController.stm_src[stm_index].sr0 & 0x01000000);
    sr_srr1 = !!(model->iController.stm_src[stm_index].sr1 & 0x01000000);

    if (sr_srr0 || sr_srr1) {
        simulWord32 sr;
        simulWord tc_pipn, stm_pipn;
        simulWord port_val = 1;
        unsigned int tos;

        if (sr_srr0) {
            sr = model->iController.stm_src[stm_index].sr0;
            tos = (unsigned int)((sr >> 11) & 0x3);
            if (tos < MAX_CORES) {
                tc_pipn = ((model->iController.icr[tos] >> 16) & 0xff);
                stm_pipn = (sr & 0xff);
                if (stm_pipn > tc_pipn) {
                    model->iController.icr[tos] &= ~0xff0000;
                    model->iController.icr[tos] |= stm_pipn << 16;
                    SIMUL_SetPort(processor, -2 - (8 * tos), 1, &port_val);
                }
            }
        }

        if (sr_srr1) {
            sr = model->iController.stm_src[stm_index].sr1;
            tos = (unsigned int)((sr >> 11) & 0x3);
            if (tos < MAX_CORES) {
                tc_pipn = ((model->iController.icr[tos] >> 16) & 0xff);
                stm_pipn = (sr & 0xff);
                if (stm_pipn > tc_pipn) {
                    model->iController.icr[tos] &= ~0xff0000;
                    model->iController.icr[tos] |= stm_pipn << 16;
                    SIMUL_SetPort(processor, -2 - (8 * tos), 1, &port_val);
                }
            }
        }
    }

    if (!(model->stm[stm_index].reg.clc & 0x2)) { /* DISS -> 0 PerModel module enabled */
        SIMUL_StartTimer(processor, model->stm[stm_index].p_timer, SIMUL_TIMER_REL | SIMUL_TIMER_CLOCKS, &time);
    }
    return SIMUL_TIMER_OK;
}


static int SIMULAPI TIM0_callback(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    return TIMx_callback(processor, cbs, _private, 0);
}

static int SIMULAPI TIM1_callback(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    return TIMx_callback(processor, cbs, _private, 1);
}

static int SIMULAPI TIM2_callback(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    return TIMx_callback(processor, cbs, _private, 2);
}

/* timers callbacks table */
void * tim_callback_func[MAX_STM_TIMERS] = {
    TIM0_callback,
    TIM1_callback,
    TIM2_callback,
};

/**************************************************************************

	Reset callback

**************************************************************************/
static int SIMULAPI TIMER_Reset(simulProcessor processor, simulCallbackStruct * cbs, simulPtr _private)
{
    unsigned int i;
    PerModel * model = (PerModel*)_private;
    simulTime time = 1;

    for (i = 0; i < MAX_STM_TIMERS; i++) {
        memset(&model->stm[i].reg, 0x00, sizeof(model->stm[i].reg));
        SIMUL_StartTimer(processor, model->stm[i].p_timer, SIMUL_TIMER_REL | SIMUL_TIMER_CLOCKS, &time);
    }

    return SIMUL_RESET_OK;
}

/**************************************************************************

	Model init functions

**************************************************************************/
static void Regs_Init(simulProcessor processor, PerModel * model)
{
    simulWord from, to;
    unsigned int i, j;
    for (i = 0; i < MAX_STM_TIMERS; i++) {
        for (j = 0; j < NUM_OF_STM_REGS; j++) {
            from = model->stm[i].baseaddress + stm_regs_offset[j];
            to = from + 3;

            SIMUL_RegisterBusReadCallback(processor, (simulCallbackFunctionPtr)stm_regread_func[j], (simulPtr)model, model->bustype, &from, &to);
            if (i < NUM_OF_REGS_RW)
                SIMUL_RegisterBusWriteCallback(processor, (simulCallbackFunctionPtr)stm_regwrite_func[j], (simulPtr)model, model->bustype, &from, &to);
        }

        from = model->iController.stm_src[i].sr0address;
        to = from + 3;
        SIMUL_RegisterBusReadCallback(processor, (simulCallbackFunctionPtr)SRC_STMSR0_Read, (simulPtr)model, model->bustype, &from, &to);
        SIMUL_RegisterBusWriteCallback(processor, (simulCallbackFunctionPtr)SRC_STMSR0_Write, (simulPtr)model, model->bustype, &from, &to);

        from = model->iController.stm_src[i].sr1address;
        to = from + 3;
        SIMUL_RegisterBusReadCallback(processor, (simulCallbackFunctionPtr)SRC_STMSR1_Read, (simulPtr)model, model->bustype, &from, &to);
        SIMUL_RegisterBusWriteCallback(processor, (simulCallbackFunctionPtr)SRC_STMSR1_Write, (simulPtr)model, model->bustype, &from, &to);
    }

    for (i = 0; i < MAX_CORES; i++) {
        from = TC_AURIX_ICR_OFFSET(i);
        to = from + 3;
        SIMUL_RegisterBusReadCallback(processor, (simulCallbackFunctionPtr)TC_ICR_Read, (simulPtr)model, model->bustype, &from, &to);
        SIMUL_RegisterBusWriteCallback(processor, (simulCallbackFunctionPtr)TC_ICR_Write, (simulPtr)model, model->bustype, &from, &to);
    }
}

/* Model entry point */
int SIMULAPI SIMUL_Init(simulProcessor processor, simulCallbackStruct * cbs)
{
    PerModel * model;
    unsigned int i;

    strcpy_s(cbs->x.init.modelname, 64, __DATE__ "  TriCore PerModel Model");
    model = (PerModel*)SIMUL_Alloc(processor, sizeof(PerModel));

    if (cbs->x.init.argc != 3) {
        SIMUL_Warning(processor, "parameters: <stm0_base_address> <src_stm0sr0_address>");
        return SIMUL_INIT_FAIL;
    }

    model->bustype = cbs->x.init.argpbustype[1];
    for (i = 0; i < MAX_STM_TIMERS; i++) {
        model->stm[i].baseaddress = cbs->x.init.argpaddress[1] + i*0x100;
        model->iController.stm_src[i].sr0address = cbs->x.init.argpaddress[2] + i * 8;
        model->iController.stm_src[i].sr1address = model->iController.stm_src[i].sr0address + 4;
    }

    /* inits */
    Regs_Init(processor, model);

    SIMUL_RegisterResetCallback(processor, TIMER_Reset, (simulPtr)model);

    for (i = 0; i < MAX_STM_TIMERS; i++) {
        model->stm[i].p_timer = SIMUL_RegisterTimerCallback(processor, tim_callback_func[i], (simulPtr)model);
    }

    TIMER_Reset(processor, cbs, model);

    return SIMUL_INIT_OK;
}