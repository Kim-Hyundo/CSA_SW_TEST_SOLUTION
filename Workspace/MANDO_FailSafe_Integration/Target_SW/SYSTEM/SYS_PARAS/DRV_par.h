/* *************************************************************************
 *                                                                       *

 * Name :

 * Description:

 * Version : 1.0

 *****************************************************************************

 * Project :
 * Component:
 * Runnable :
 *****************************************************************************
 * Tool  :
 * Author:
 * Date  :
 ****************************************************************************/

#ifndef DRV_PAR_H
#define DRV_PAR_H


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"                  /* Standard type header */
#include "DRV_def.h"


/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

/* Vehicle Parameter */
#define HKMC_RS4	0x1
#define HKMC_SG2    0x2


#define OEM_CAR     HKMC_RS4

#define NORMAL 0x1
#define EV     0x2
#define HEV    0x3
#define PHEV   0x3

#define HSCAN 1
#define CANFD 2

#define NOT_APPLIED 0
#define APPLIED     1
#define MIXED       2

/* NAVI Map Version */
#define V2      0
#define V2_3    1

/* NAVI Version */
#define GEN5      0
#define GEN6      1

/*
 * [ Function Macro List ]
 * CUSTOM_MODE: custom mode using ICSC_02_100ms(DMIC signals)
 * LFA_SW_INTEG: LKA/LFA switch integration (switch info. from FR_CMR not SWRC)
 * HANDSHAKING: Navigation handshaking
 * NO_SWRC: SWRC signals are moved into CLU
 * HU_USM: USM signal from HU_USM instead of CLU (CLU --> ccICCLU)
 * MAP_VER: MAP VERSION
 * NAVI_VER: NAVI VERSION
 * IMU_MSG : for name compatibility with YRS_01_10ms and IMU_01_10ms messages
 * ICSC_MSG : ICSC Msg is included for Failsafe
 */

#if OEM_CAR == HKMC_RS4
    #define VEH_TYPE     NORMAL
    #define CCAN         CANFD
    #define CUSTOM_MODE  NOT_APPLIED
    #define LFA_SW_INTEG APPLIED
    #define HANDSHAKING  NOT_APPLIED
    #define NO_SWRC      NOT_APPLIED
    #define HU_USM       APPLIED
    #define MAP_VER      V2
    #define NAVI_VER     GEN6
    #define IMU_MSG      NOT_APPLIED
#elif OEM_CAR == HKMC_SG2
    #define VEH_TYPE	 EV
    #define CCAN         CANFD
    #define CUSTOM_MODE  NOT_APPLIED
    #define LFA_SW_INTEG APPLIED
    #define HANDSHAKING  NOT_APPLIED
    #define NO_SWRC 	 NOT_APPLIED
    #define HU_USM       NOT_APPLIED
    #define MAP_VER 	 V2_3
    #define NAVI_VER	 GEN6
    #define IMU_MSG      APPLIED
    #define ICSC_MSG     APPLIED
#endif

/* Transmission Option */
#define TRANSMISSION_OPTION		AUTO_TRANSMISSION


/* Driver Seat Position */
#define DRIVER_SEAT_POSITION	LEFT_HANDED_DRIVER


/* NSCC-C Option */
#define NSCC_C_OPTION	_ENABLE

/* NSCC-Z Option */
#define NSCC_Z_OPTION	_ENABLE


/* NSCC-R Option */
#define NSCC_R_OPTION	_ENABLE


/* HDA2 Option */
#define HDA2_OPTION		_ENABLE


/* Failsafe Option */
#define FAILSAFE_OPTION		_ENABLE

/* Inhibit Flags Option */
#define SWC_INHIBIT_OPTION	_ENABLE

/* SF Logger Option */
#define SF_LOGGER_OPTION    _ENABLE

/*******************************************************************************
**                      Developer Parameters                                  **
*******************************************************************************/
#define VX1000_ENABLE		_DISABLE		/* ENABLE or DISABLE */

#define USER_PROFILE        _DISABLE

#if IMU_MSG == APPLIED
    #define MsgGr_E2E_ECANFD_YRS_01_10ms    MsgGr_E2E_ECANFD_IMU_01_10ms
	#define YRS_01_10ms_POS                 IMU_01_10ms_POS
	#define YRS_01_10ms                     IMU_01_10ms

	#define YRS_YawSigSta                   IMU_YawSigSta
	#define YRS_LatAccelSigSta              IMU_LatAccelSigSta
	#define YRS_LongAccelSigSta             IMU_LongAccelSigSta
	#define YRS_AcuRstSta                   IMU_AcuRstSta
	#define YRS_YawRtVal                    IMU_YawRtVal
	#define YRS_LatAccelVal                 IMU_LatAccelVal
	#define YRS_LongAccelVal                IMU_LongAccelVal
	#define YRS_01_10ms_E2EReserved         IMU_01_10ms_E2EReserved
    #define MsgCbk_ECANFD_YRS_01_10ms       MsgCbk_ECANFD_IMU_01_10ms  
    #define Rte_IRead_RCtApFAILSAFE_10ms_PpYRS_01_10ms_DeYRS_01_10ms  \
            Rte_IRead_RCtApFAILSAFE_10ms_PpIMU_01_10ms_DeIMU_01_10ms
    #define Rte_IRead_RCtApIDC_10ms_PpYRS_01_10ms_DeYRS_01_10ms  \
            Rte_IRead_RCtApIDC_10ms_PpIMU_01_10ms_DeIMU_01_10ms
    #define Rte_IRead_RCtApIDSP1_10ms_PpYRS_01_10ms_DeYRS_01_10ms  \
            Rte_IRead_RCtApIDSP1_10ms_PpIMU_01_10ms_DeIMU_01_10ms
    #define Rte_IRead_RCtApIDSP2_10ms_PpYRS_01_10ms_DeYRS_01_10ms  \
            Rte_IRead_RCtApIDSP2_10ms_PpIMU_01_10ms_DeIMU_01_10ms
    #define Rte_Read_Gr_MsgGr_E2E_ECANFD_YRS_01_10ms_MsgGr_E2E_ECANFD_YRS_01_10ms   \
            Rte_Read_Gr_MsgGr_E2E_ECANFD_IMU_01_10ms_MsgGr_E2E_ECANFD_IMU_01_10ms
    #define Rte_IRead_RCtApVDISP_D_10ms_PpYRS_01_10ms_DeYRS_01_10ms  \
            Rte_IRead_RCtApVDISP_D_10ms_PpIMU_01_10ms_DeIMU_01_10ms
    #define Rte_IWrite_RCtApISR_10ms_PpYRS_01_10ms_DeYRS_01_10ms \
            Rte_IWrite_RCtApISR_10ms_PpIMU_01_10ms_DeIMU_01_10ms
#endif




#endif

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

