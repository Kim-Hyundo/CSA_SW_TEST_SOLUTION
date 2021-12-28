/*******************************************************************************
**  FILE-NAME : EcuM_Cfg.h                                                    **
**                                                                            **
**  PRODUCT   : AUTOSAR EcuM Module                                           **
**                                                                            **
**  NOTE: This file is auto generated, do not edit this file manually.        **
**                                                                            **
********************************************************************************

********************************************************************************
**                      Generation Tool Information                           **
********************************************************************************
**  Tool Version: 3.0.3                                                       **
**                                                                            **
**  Change History: Refer log file (use -l option to generate log file)       **
**                                                                            **
********************************************************************************
**                      File Generation Information                           **
*******************************************************************************/

/*
 * INPUT FILE:    Configuration\Ecu\Ecud_CanSM.arxml
 *                Configuration\Ecu\Mcal\Ecud_FlsLoader.arxml
 *                Configuration\Ecu\Ecud_Det.arxml
 *                Configuration\Ecu\Mcal\Ecud_Gpt.arxml
 *                Configuration\Ecu\Ecud_PduR.arxml
 *                Configuration\Ecu\Mcal\Ecud_Can.arxml
 *                Configuration\Ecu\Ecud_EcuC.arxml
 *                Configuration\Ecu\Ecud_Xcp.arxml
 *                Configuration\Ecu\Mcal\Ecud_Dio.arxml
 *                Configuration\Ecu\Ecud_Dcm.arxml
 *                Configuration\Ecu\Ecud_Dem.arxml
 *                Configuration\Ecu\Ecud_CanIf.arxml
 *                Configuration\Ecu\Mcal\Ecud_Mcu.arxml
 *                Configuration\Ecu\Ecud_ComM.arxml
 *                Configuration\Ecu\Ecud_CanTp.arxml
 *                Configuration\Ecu\Mcal\Ecud_Adc.arxml
 *                Configuration\Ecu\Mcal\Ecud_Port.arxml
 *                Configuration\Ecu\Ecud_EcuM.arxml
 *                Configuration\Ecu\Ecud_CanCM.arxml
 *                Configuration\Ecu\Ecud_CanTrcv_255_Autron.arxml
 *                Configuration\Ecu\Ecud_WdgM.arxml
 *                Configuration\Ecu\Mcal\Ecud_Wdg.arxml
 *                Configuration\Ecu\Mcal\Ecud_Pwm.arxml
 *                Configuration\Ecu\Ecud_IoHwAb.arxml
 *                Configuration\Ecu\Ecud_Nm.arxml
 *                Configuration\Ecu\Ecud_Os.arxml
 *                Configuration\Ecu\Mcal\Ecud_Icu.arxml
 *                Configuration\Ecu\Ecud_Csm.arxml
 *                Configuration\Ecu\Ecud_Com.arxml
 *                Configuration\Ecu\Ecud_T1Ad.arxml
 *                Configuration\Ecu\Mcal\Ecud_Spi.arxml
 * GENERATED ON: The time-stamp is removed
 */

#ifndef ECUM_CFG_H
#define ECUM_CFG_H

/* polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Common Published Information                          **
*******************************************************************************/
#define ECUM_AR_RELEASE_MAJOR_VERSION       4
#define ECUM_AR_RELEASE_MINOR_VERSION       0
#define ECUM_AR_RELEASE_REVISION_VERSION    3
#define ECUM_SW_MAJOR_VERSION               3
#define ECUM_SW_MINOR_VERSION               0
#define ECUM_SW_PATCH_VERSION               3
#define ECUM_VENDOR_ID                      76
#define ECUM_MODULE_ID                      10
/*******************************************************************************
**                      Precompile Options                                    **
*******************************************************************************/
/* Pre-Compile option for development error detection. */
#define ECUM_DEV_ERROR_DETECT               (STD_ON)

/* Pre-Compile option for including Det. */
#define ECUM_INCLUDE_DET                    (STD_ON)

/* Pre-Compile option for switching ON / OFF the defensive behaviour. */
#define ECUM_DEF_BEHAVIOUR_ENABLED          (STD_OFF)

/* Pre-Compile option for version check. */
#define ECUM_VERSION_INFO_API               (STD_OFF)

/* Pre-Compile option for AlarmClock feature is present or not. */
#define ECUM_ALARM_CLOCK_PRESENT            (STD_OFF)

/* Pre-Compile option for reset loop detection. */
#define ECUM_RESET_LOOP_DETECTION           (STD_OFF)

/* Macro for number of OsTask configured for EcuMOsTaskRef */
#define ECUM_NO_OF_OS_TASKS                 0U

/* Macro for number of EcuMAlarmClock containers configured */
#define ECUM_NO_OF_ALARMS                   0U

/* 
 * Macro for Number of Reset modes configured for EcuMResetModeId in
 * container EcuMResetMode
 */
#define ECUM_NO_OF_RESETMODES               3U

/* Number of Post-Build Config Sets */
#define ECUM_NO_OF_PB_CONFIG_SET            1U

/* 
 * Number of Flex Users configured for EcuMSetClockAllowedUserRef in
 * container EcuMSetClockAllowedUsers
 */
#define ECUM_NO_OF_CLOCKUSERS               1U

/* 
 * Macro for Number of Cores configured for Core Assignment of Container
 * OsApplication
 */
#define ECUM_NO_OF_CORES                    6U

/* 
 * Number of Flex Users configured for EcuMGoDownAllowedUserRef in
 * container EcuMGoDownAllowedUsers
 */
#define ECUM_NO_OF_GODOWNUSERS              2U

/* Total Hash values */
#define ECUM_NO_OF_HASH_SEGMENTS            2U

/* 
 * Macro for Number of Wakeups configured for EcuMWakeupSourceId in
 * container EcuMWakeupSource
 */
#define ECUM_NO_OF_WAKEUPSOURCES            6U

/* 
 * Number of Flex Users configured for the parameter EcuMFlexUser in
 * container EcuMFlexUserConfig
 */
#define ECUM_NO_OF_USERS                    2U

/* Pre-Compile option for Pm enabled. */
#define ECUM_PM_ENABLED                     (STD_OFF)

/* 
 * Macro for Number of Os Resources configured for the parameter
 * EcuMOSResource in container EcuMCommonConfiguration
 */
#define ECUM_NO_OF_OSRESOURCES              0U

/* 
 * Macro for Number of Shut down cause configured for EcuMShutdownCauseId
 * in container EcuMShutdownCause
 */
#define ECUM_NO_OF_SHUTDOWNCAUSE            5U

/* Macro for number of Event masks configured for a task */
#define ECUM_NO_OF_EVENT_MASKS              0U

/* 
 * Macro for Number of Sleepmodes configured for EcuMSleepModeId in
 * container EcuMSleepMode
 */
#define ECUM_NO_OF_SLEEPMODES               2U

/* Pre-Compile option for Multi core support */
#define ECUM_MULTI_CORE_SUPPORT             (STD_ON)

/* Pre-Compile option for Mcu Normal Mode support */
#define ECUM_MCU_NORMAL_MODE_SUPPORT        (STD_OFF)

/* 
 * Pre-Compile Option for EcuM_AL_DriverInitZero, it shall be STD_ON when
 * EcuMDriverInitListZero is configured
 */
#define ECUM_DRIVER_INIT_ZERO               (STD_ON)

/* 
 * Pre-Compile Option for EcuM_AL_DriverInitOne, it shall be STD_ON when
 * EcuMDriverInitListOne is configured
 */
#define ECUM_DRIVER_INIT_ONE                (STD_ON)

/* 
 * Pre-Compile Option for EcuM_AL_DriverRestart, it shall be STD_ON when
 * EcuMDriverRestartList is configured
 */
#define ECUM_DRIVER_RESTART                 (STD_OFF)

/* 
 * Pre-Compile Option for Wakeup Sources, it shall be STD_ON when
 * EcuMWakeupSource is configured
 */
#define ECUM_WAKEUPSOURCE_SUPPORT           (STD_ON)

/* 
 * Pre-Compile Option for Sleep Mode, it shall be STD_ON when EcuMSleepMode
 * is configured
 */
#define ECUM_SLEEPMODE_SUPPORT              (STD_ON)

/* 
 * Pre-Compile Option to indicate whether SCHM is configured by user for
 * FlexModuleRef or not
 */
#define ECUM_SCHM_PRECOMPILE                (STD_ON)

/* Defines Dem Container is present or not */
#define ECUM_DEMERROR_REPORT                (STD_ON)

/* 
 * Macro for default application mode of Os to start the Os. This is the
 * container name of OsAppMode
 */
#define ECUM_DEFAULT_APP_MODE               (OsAppMode0)

/* Main function period */
#define ECUM_MAIN_FUNCTION_PERIOD           0.01

/* Macro for spin lock of Os. This is the container name of OsSpinlock */
#define ECUM_OS_SPINLOCK                    (OsSpinlock_EcuM)

/* Macro for normal Mcu clock configured for parameter EcuMNormalMcuClockRef */
#define ECUM_MCU_NORMAL_CLOCK               0U

/* Macro for mask of all slave cores. */
#define ECUM_SLAVE_CORE_MASK                0x3EU

/* Pre-Compile option for Lp callout enabled. */
#define ECUM_LP_CALLOUT_ENABLED             (STD_OFF)

/* The maximum number of iterations to prevent an infinite loop. */
#define ECUM_LOOP_COUNT_MAX                 2000000U



/*******************************************************************************
**                      Configuration Set Handles                             **
*******************************************************************************/
/* Symbolic names */
/* This macro generates the short names of EcuMSleepMode parameter*/
#define ECUM_SLEEP_IDLE                     0U
#define ECUM_SLEEP_STOP                     2U

/* This macro generates the short names of EcuMWakeupSource parameter*/
#define ECUM_WKSOURCE_POWER                 0x00000001U
#define ECUM_WKSOURCE_RESET                 0x00000002U
#define ECUM_WKSOURCE_INTERNAL_RESET        0x00000004U
#define ECUM_WKSOURCE_INTERNAL_WDG          0x00000008U
#define ECUM_WKSOURCE_EXTERNAL_WDG          0x00000010U
#define ECUM_WKSOURCE_GPT                   0x00000020U

/* This macro generates the short names of EcuMAlarmClock parameter*/
#define ECUM_ALARM_Sleep                    0U

/* This macro generates the short names of EcuMFlexUserConfig parameter*/
#define ECUM_USER_BSWM                      42U
#define ECUM_USER_APP                       255U

/* This macro generates the short names of EcuMResetMode parameter*/
#define ECUM_RESET_MCU                      0U
#define ECUM_RESET_WDG                      1U
#define ECUM_RESET_IO                       2U

/* This macro generates the short names of EcuMShutdownCause parameter*/
#define ECUM_CAUSE_UNKNOWN                  0U
#define ECUM_CAUSE_ECU_STATE                1U
#define ECUM_CAUSE_WDGM                     2U
#define ECUM_CAUSE_DCM                      3U
#define ECUM_CAUSE_XCP                      4U

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
/* polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> Not a defect */
#endif /* ECUM_CFG_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
