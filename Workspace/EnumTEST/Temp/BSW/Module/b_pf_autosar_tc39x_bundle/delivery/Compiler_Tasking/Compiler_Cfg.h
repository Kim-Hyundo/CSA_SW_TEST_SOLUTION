/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2018)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME     : Compiler_Cfg.h                                             **
**                                                                            **
**  VERSION      : 0.0.2                                                      **
**                                                                            **
**  DATE         : 2016-03-26                                                 **
**                                                                            **
**  VARIANT      : NA                                                         **
**                                                                            **
**  PLATFORM     : Infineon AURIX2G                                           **
**                                                                            **
**  AUTHOR       : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**  VENDOR       : Infineon Technologies                                      **
**                                                                            **
**  TRACEABILITY : [cover parentID={035D74CB-B32E-40b3-BDF7-72AE57794957}]    **
**                                                                            **
**  DESCRIPTION  : Compiler Configuration File                                **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
**  SPECIFICATION(S) : Specification of Compiler Abstraction,                 **
**                     AUTOSAR Release 4.2.2                                  **
**                                                                            **
**  MAY BE CHANGED BY USER : yes                                              **
**                                                                            **
*******************************************************************************/

#ifndef COMPILER_CFG_H
#define COMPILER_CFG_H

/*

 * The following memory and pointer classes can be configured per module.

 * Those defines are passed to the compiler abstraction macros in Compiler.h

 */

/*******************************************************************************

**                                 MCU                                        **

*******************************************************************************/

/*To be used for code*/

#define MCU_CODE

/*To be used for all global or static variables that are never initialized*/

#define MCU_VAR_NOINIT

/*To be used for all global or static variables that are initialized only after power on reset*/

#define MCU_VAR_POWER_ON_INIT

/* To be used for all global or static variables that have at least one of the

following properties:

-accessed bitwise

-frequently used

-high number of accesses in source code*/

#define MCU_VAR_FAST

/*To be used for global or static variables that are initialized after every

reset.*/

#define MCU_VAR

/*To be used for global or static constants*/

#define MCU_CONST

/*To be used for references on application data (expected to be in RAM or ROM) passed via API*/

#define MCU_APPL_DATA

/*To be used for references on application constants (expected to be certainly in ROM, for instance pointer of Init-function) passed via API*/

#define MCU_APPL_CONST

/*To be used for references on application functions. (e.g. call back function pointers)*/

#define MCU_APPL_CODE

/*******************************************************************************

**                                 PORT                                        *

*******************************************************************************/

/*To be used for code*/

#define PORT_CODE

/*To be used for all global or static variables that are never initialized*/

#define PORT_VAR_NOINIT

/*To be used for all global or static variables that are initialized only after power on reset*/

#define PORT_VAR_POWER_ON_INIT

/* To be used for all global or static variables that have at least one of the

following properties:

-accessed bitwise

-frequently used

-high number of accesses in source code*/

#define PORT_VAR_FAST

/*To be used for global or static variables that are initialized after every

reset.*/

#define PORT_VAR

/*To be used for global or static constants*/

#define PORT_CONST

/*To be used for references on application data (expected to be in RAM or ROM) passed via API*/

#define PORT_APPL_DATA

/*To be used for references on application constants (expected to be certainly in ROM, for instance pointer of Init-function) passed via API*/

#define PORT_APPL_CONST

/*To be used for references on application functions. (e.g. call back function pointers)*/

#define PORT_APPL_CODE

/*******************************************************************************

**                                 DIO                                        **

*******************************************************************************/

/*To be used for code*/

#define DIO_CODE

/*To be used for all global or static variables that are never initialized*/

#define DIO_VAR_NOINIT

/*To be used for all global or static variables that are initialized only after power on reset*/

#define DIO_VAR_POWER_ON_INIT

/* To be used for all global or static variables that have at least one of the

following properties:

-accessed bitwise

-frequently used

-high number of accesses in source code*/

#define DIO_VAR_FAST

/*To be used for global or static variables that are initialized after every

reset.*/

#define DIO_VAR

/*To be used for global or static constants*/

#define DIO_CONST

/*To be used for references on application data (expected to be in RAM or ROM) passed via API*/

#define DIO_APPL_DATA

/*To be used for references on application constants (expected to be certainly in ROM, for instance pointer of Init-function) passed via API*/

#define DIO_APPL_CONST

/*To be used for references on application functions. (e.g. call back function pointers)*/

#define DIO_APPL_CODE

/*******************************************************************************

**                                 ADC                                        **

*******************************************************************************/

/*To be used for code*/

#define ADC_CODE

/*To be used for all global or static variables that are never initialized*/

#define ADC_VAR_NOINIT

/*To be used for all global or static variables that are initialized only after power on reset*/

#define ADC_VAR_POWER_ON_INIT

/* To be used for all global or static variables that have at least one of the

following properties:

-accessed bitwise

-frequently used

-high number of accesses in source code*/

#define ADC_VAR_FAST

/*To be used for global or static variables that are initialized after every

reset.*/

#define ADC_VAR

/*To be used for global or static constants*/

#define ADC_CONST

/*To be used for references on application data (expected to be in RAM or ROM) passed via API*/

#define ADC_APPL_DATA

/*To be used for references on application constants (expected to be certainly in ROM, for instance pointer of Init-function) passed via API*/

#define ADC_APPL_CONST

/*To be used for references on application functions. (e.g. call back function pointers)*/

#define ADC_APPL_CODE

/*******************************************************************************

**                                 GPTA                                        *

*******************************************************************************/

/*To be used for code*/

#define GPTA_CODE

/*To be used for all global or static variables that are never initialized*/

#define GPTA_VAR_NOINIT

/*To be used for all global or static variables that are initialized only after power on reset*/

#define GPTA_VAR_POWER_ON_INIT

/* To be used for all global or static variables that have at least one of the

following properties:

-accessed bitwise

-frequently used

-high number of accesses in source code*/

#define GPTA_VAR_FAST

/*To be used for global or static variables that are initialized after every

reset.*/

#define GPTA_VAR

/*To be used for global or static constants*/

#define GPTA_CONST

/*To be used for references on application data (expected to be in RAM or ROM) passed via API*/

#define GPTA_APPL_DATA

/*To be used for references on application constants (expected to be certainly in ROM, for instance pointer of Init-function) passed via API*/

#define GPTA_APPL_CONST

/*To be used for references on application functions. (e.g. call back function pointers)*/

#define GPTA_APPL_CODE

/*******************************************************************************

**                                 GPT                                        **

*******************************************************************************/

/*To be used for code*/

#define GPT_CODE

/*To be used for all global or static variables that are never initialized*/

#define GPT_VAR_NOINIT

/*To be used for all global or static variables that are initialized only after power on reset*/

#define GPT_VAR_POWER_ON_INIT

/* To be used for all global or static variables that have at least one of the

following properties:

-accessed bitwise

-frequently used

-high number of accesses in source code*/

#define GPT_VAR_FAST

/*To be used for global or static variables that are initialized after every

reset.*/

#define GPT_VAR

/*To be used for global or static constants*/

#define GPT_CONST

/*To be used for references on application data (expected to be in RAM or ROM) passed via API*/

#define GPT_APPL_DATA

/*To be used for references on application constants (expected to be certainly in ROM, for instance pointer of Init-function) passed via API*/

#define GPT_APPL_CONST

/*To be used for references on application functions. (e.g. call back function pointers)*/

#define GPT_APPL_CODE

/*******************************************************************************

**                                 ICU                                        **

*******************************************************************************/

/*To be used for code*/

#define ICU_CODE

/*To be used for all global or static variables that are never initialized*/

#define ICU_VAR_NOINIT

/*To be used for all global or static variables that are initialized only after power on reset*/

#define ICU_VAR_POWER_ON_INIT

/* To be used for all global or static variables that have at least one of the

following properties:

-accessed bitwise

-frequently used

-high number of accesses in source code*/

#define ICU_VAR_FAST

/*To be used for global or static variables that are initialized after every

reset.*/

#define ICU_VAR

/*To be used for global or static constants*/

#define ICU_CONST

/*To be used for references on application data (expected to be in RAM or ROM) passed via API*/

#define ICU_APPL_DATA

/*To be used for references on application constants (expected to be certainly in ROM, for instance pointer of Init-function) passed via API*/

#define ICU_APPL_CONST

/*To be used for references on application functions. (e.g. call back function pointers)*/

#define ICU_APPL_CODE

/*******************************************************************************

**                                 PWM                                        **

*******************************************************************************/

/*To be used for code*/

#define PWM_CODE

/*To be used for all global or static variables that are never initialized*/

#define PWM_VAR_NOINIT

/*To be used for all global or static variables that are initialized only after power on reset*/

#define PWM_VAR_POWER_ON_INIT

/* To be used for all global or static variables that have at least one of the

following properties:

-accessed bitwise

-frequently used

-high number of accesses in source code*/

#define PWM_VAR_FAST

/*To be used for global or static variables that are initialized after every

reset.*/

#define PWM_VAR

/*To be used for global or static constants*/

#define PWM_CONST

/*To be used for references on application data (expected to be in RAM or ROM) passed via API*/

#define PWM_APPL_DATA

/*To be used for references on application constants (expected to be certainly in ROM, for instance pointer of Init-function) passed via API*/

#define PWM_APPL_CONST

/*To be used for references on application functions. (e.g. call back function pointers)*/

#define PWM_APPL_CODE

/*******************************************************************************

**                                 SPI                                        **

*******************************************************************************/

/*To be used for code*/

#define SPI_CODE

/*To be used for all global or static variables that are never initialized*/

#define SPI_VAR_NOINIT

/*To be used for all global or static variables that are initialized only after power on reset*/

#define SPI_VAR_POWER_ON_INIT

/* To be used for all global or static variables that have at least one of the

following properties:

-accessed bitwise

-frequently used

-high number of accesses in source code*/

#define SPI_VAR_FAST

/*To be used for global or static variables that are initialized after every

reset.*/

#define SPI_VAR

/*To be used for global or static constants*/

#define SPI_CONST

/*To be used for references on application data (expected to be in RAM or ROM) passed via API*/

#define SPI_APPL_DATA

/*To be used for references on application constants (expected to be certainly in ROM, for instance pointer of Init-function) passed via API*/

#define SPI_APPL_CONST

/*To be used for references on application functions. (e.g. call back function pointers)*/

#define SPI_APPL_CODE

/*******************************************************************************

**                                 CAN                                        **

*******************************************************************************/

/*To be used for code*/

#define CAN_CODE

/*To be used for all global or static variables that are never initialized*/

#define CAN_VAR_NOINIT

/*To be used for all global or static variables that are initialized only after power on reset*/

#define CAN_VAR_POWER_ON_INIT

/* To be used for all global or static variables that have at least one of the

following properties:

-accessed bitwise

-frequently used

-high number of accesses in source code*/

#define CAN_VAR_FAST

/*To be used for global or static variables that are initialized after every

reset.*/

#define CAN_VAR

/*To be used for global or static constants*/

#define CAN_CONST

/*To be used for references on application data (expected to be in RAM or ROM) passed via API*/

#define CAN_APPL_DATA

/*To be used for references on application constants (expected to be certainly in ROM, for instance pointer of Init-function) passed via API*/

#define CAN_APPL_CONST

/*To be used for references on application functions. (e.g. call back function pointers)*/

#define CAN_APPL_CODE

/*******************************************************************************

**                                 WDG                                        **

*******************************************************************************/

/*To be used for code*/

#define WDG_CODE

/*To be used for all global or static variables that are never initialized*/

#define WDG_VAR_NOINIT

/*To be used for all global or static variables that are initialized only after power on reset*/

#define WDG_VAR_POWER_ON_INIT

/* To be used for all global or static variables that have at least one of the

following properties:

-accessed bitwise

-frequently used

-high number of accesses in source code*/

#define WDG_VAR_FAST

/*To be used for global or static variables that are initialized after every

reset.*/

#define WDG_VAR

/*To be used for global or static constants*/

#define WDG_CONST

/*To be used for references on application data (expected to be in RAM or ROM) passed via API*/

#define WDG_APPL_DATA

/*To be used for references on application constants (expected to be certainly in ROM, for instance pointer of Init-function) passed via API*/

#define WDG_APPL_CONST

/*To be used for references on application functions. (e.g. call back function pointers)*/

#define WDG_APPL_CODE

/*******************************************************************************

**                                 CANTRCV                                     *

*******************************************************************************/

/*To be used for code*/

#define CANTRCV_CODE

/*To be used for all global or static variables that are never initialized*/

#define CANTRCV_VAR_NOINIT

/*To be used for all global or static variables that are initialized only after power on reset*/

#define CANTRCV_VAR_POWER_ON_INIT

/* To be used for all global or static variables that have at least one of the

following properties:

-accessed bitwise

-frequently used

-high number of accesses in source code*/

#define CANTRCV_VAR_FAST

/*To be used for global or static variables that are initialized after every

reset.*/

#define CANTRCV_VAR

/*To be used for global or static constants*/

#define CANTRCV_CONST

/*To be used for references on application data (expected to be in RAM or ROM) passed via API*/

#define CANTRCV_APPL_DATA

/*To be used for references on application constants (expected to be certainly in ROM, for instance pointer of Init-function) passed via API*/

#define CANTRCV_APPL_CONST

/*To be used for references on application functions. (e.g. call back function pointers)*/

#define CANTRCV_APPL_CODE

/* Changed by AUTRON -----------------------------------------------------------------------------*/
/* ---------------------------------------------------------------------------*/
/*                   CANTP                                                    */
/* ---------------------------------------------------------------------------*/

#define CANTP_CODE                /* API functions                     */
#define CANTP_CONST               /* API constants                     */

#define CANTP_CODE               /* Internal functions                */

#define CANTP_CONST              /* Internal ROM Data                 */

#define CANTP_APPL_CODE                  /* callbacks of the Application      */

#define CANTP_CODE                       /* memory class for code             */
#define CANTP_CONST                      /* Constant data                     */
#define CANTP_APPL_DATA                  /* Applications' RAM Data            */

#define CANTP_APPL_CONST                 /* Applications' ROM Data            */
#define CANTP_APPL_CODE                  /* Callbacks of the Application      */
#define CANTP_CALLOUT_CODE          /* memory class for pointers to application
                                    functions (e.g. callout function pointers)*/
#define CANTP_VAR_NOINIT            /* Data which is not initialized during
                                           Startup                            */
#define CANTP_VAR_POWER_ON_INIT     /* memory class for all global or static
                                      variables that are initialized only after
                                                               power on reset */
#define CANTP_VAR_FAST  /* memory class for all global or static variables that
                           have at least one of the following properties:
                           1. accessed bitwise 2. frequently used
                           3.high number of accesses in source code */
#define CANTP_VAR       /* memory class for all global or static variables that
                           are initialized after every reset */


/* ---------------------------------------------------------------------------*/
/*                             DCM                                            */
/* ---------------------------------------------------------------------------*/
#define DCM_VAR                   /* For variables which are initialised
                                       during startup */
#define DCM_CODE                  /* APIs and functions            */

#define DCM_APPL_CODE                   /* memory class for pointers to
                                      application functions
                                      (e.g. call back function pointers)   */

#define DCM_CALLOUT_CODE            /* memory class for pointers to
                                      application functions
                                     (e.g. callout function pointers).  */

#define DCM_VAR_POWER_ON_INIT     /* For variables that are
                                    initialized only after power on reset */

#define DCM_APPL_CONST           /* memory class for pointers to application
                                     constants  */

#define DCM_APPL_DATA            /* Memory class for pointers to application
                                      data            */

#define DCM_CONST                /* Data Constants                    */


/* ---------------------------------------------------------------------------*/
/*                 Dem                                                    */
/* ---------------------------------------------------------------------------*/
#define DEM_CODE                /* API functions                        */
#define DEM_CONST               /* API constants                        */

#define DEM_APPL_DATA                  /* Applications' RAM Data            */
#define DEM_APPL_CONST                 /* Applications' ROM Data            */
#define DEM_APPL_CODE                /* Callbacks of the Application      */

#define DEM_VAR_NOINIT            /* Data which is not initialized during */

#define DEM_VAR             /* Global or static variables that are initialized
                               after every reset. */


/* ---------------------------------------------------------------------------*/
/*                   OS                                                     */
/* ---------------------------------------------------------------------------*/

#define OS_CODE                /* API functions                               */
#define OS_CONST               /* API constants                               */

#define OS_VAR                 /* To be used for references on appl data      */
#define OS_CONST          /* To be used for references on appl const     */

#define OS_APPL_CODE           /* Callbacks of the Application                */
#define OS_CALLOUT_CODE        /* To be used for references on appl functions */

#define OS_VAR_NOINIT          /* Data which is not initialized during Startup*/
#define OS_VAR_POWER_ON_INIT   /* Data which is initialized during Startup    */
#define OS_VAR_FAST            /* 'Near' RAM Data                             */

#define OS_VAR                 /*
                                * To be used for global or static variables
                                * that are initialized after every reset */

/* ---------------------------------------------------------------------------*/
/*                             DET                                          */
/* ---------------------------------------------------------------------------*/
#define DET_CODE                       /* API functions                       */
#define DET_CONST                      /* Internal ROM Data                   */
#define DET_APPL_CODE                  /* Callbacks of the Application        */
#define DET_APPL_CONST                 /* Applications' ROM Data              */
#define DET_APPL_DATA                  /* Applications' RAM Data              */

/* ---------------------------------------------------------------------------*/
/*                             LINNM                                          */
/* ---------------------------------------------------------------------------*/
#define LINNM_VAR                   /* For variables which are initialised
                                       during startup */
#define LINNM_CODE                  /* APIs and functions            */

#define LINNM_APPL_CODE                   /* memory class for pointers to
                                      application functions
                                      (e.g. call back function pointers)   */

#define LINNM_CALLOUT_CODE            /* memory class for pointers to
                                      application functions
                                     (e.g. callout function pointers).  */

#define LINNM_VAR_NOINIT            /* For variables that are
                                        never initialised */

#define LINNM_VAR_POWER_ON_INIT     /* For variables that are
                                    initialized only after power on reset */

#define LINNM_VAR_FAST              /* For variables that are
                          either accessed bitwise or frequently used or have
                           high number of accesses in source code */

#define LINNM_APPL_CONST           /* memory class for pointers to application
                                     constants  */

#define LINNM_APPL_DATA            /* Memory class for pointers to application
                                      data            */

#define LINNM_CONST                /* Data Constants                    */

/* ---------------------------------------------------------------------------*/
/*                             WDGIF                                          */
/* ---------------------------------------------------------------------------*/
#define WDGIF_CODE                       /* API functions */
#define WDGIF_CONST                       /* API functions */
#define WDGIF_APPL_DATA            /* Memory class for pointers to application
                                      data            */
/* --------------------------------------------------------------------------*/
/*                       WDGM                                                 */
/* --------------------------------------------------------------------------*/
#define WDGM_CODE                /* API functions                     */

#define WDGM_DATA                /* Constant data */

#define WDGM_APPL_CODE                  /* Callbacks of the Application      */
#define WDGM_APPL_CONST                 /* Applications' ROM Data            */
#define WDGM_APPL_DATA                  /* Applications' RAM Data            */

#define WDGM_VAR_NOINIT                  /* Data which is not initialized during
                                           Startup */
#define WDGM_VAR_POWER_ON_INIT            /* Data which is initialized with ZERO
                                            during startup                    */
#define WDGM_CONST                       /* Constant data                     */

/* ---------------------------------------------------------------------------*/
/*                   MemIf                                                     */
/* ---------------------------------------------------------------------------*/
#define MEMIF_CODE                /* API functions                      */
/* ---------------------------------------------------------------------------*/
/*                   CRC                                                      */
/* ---------------------------------------------------------------------------*/
#define CRC_CODE
#define CRC_CONST
/* ---------------------------------------------------------------------------*/
/*                   NVM                                                      */
/* ---------------------------------------------------------------------------*/
#define NVM_CODE                        /* API functions                      */

#define NVM_APPL_CODE

#define NVM_CONST               /* API constants                      */
#define NVM_DATA
#define NVM_APPL_CONST                 /* Applications' ROM Data             */

#define NVM_APPL_DATA                  /* Applications' RAM Data             */

#define NVM_VAR_NOINIT               /* Data which is not initialized during
                                          Startup                             */

#define NVM_VAR_POWER_ON_INIT             /* Data which is initialized with ZERO
                                         during startup                       */
/* ---------------------------------------------------------------------------*/
/*                   Eep                                                      */
/* ---------------------------------------------------------------------------*/
#define EEP_CODE                /* API functions                              */
#define EEP_VAR_POWER_ON_INIT
#define EEP_APPL_CONST
#define EEP_CONST
/* ---------------------------------------------------------------------------*/
/*                   Ea                                                       */
/* ---------------------------------------------------------------------------*/
#define EA_CODE                 /* API functions                              */
#define EA_CONST
#define EA_VAR_POWER_ON_INIT
#define EA_VAR_NOINIT

/* ---------------------------------------------------------------------------*/
/*                   LINSM                                                    */
/* ---------------------------------------------------------------------------*/
#define LINSM_CODE                       /* memory class for code             */

#define LINSM_CONST                      /* Constant data                     */

#define LINSM_APPL_DATA                  /* Applications' RAM Data            */

#define LINSM_APPL_CONST                 /* Applications' ROM Data            */

#define LINSM_APPL_CODE                  /* Callbacks of the Application      */

#define LINSM_VAR       /* memory class for all global or static variables that
                           are initialized after every reset */
/* ---------------------------------------------------------------------------*/
/*                   FRIF                                                    */
/* ---------------------------------------------------------------------------*/
#define FRIF_CODE                /* API functions                             */

#define FRIF_CONST               /* API constants                             */

#define FRIF_APPL_CODE                  /* callbacks of the Application      */

#define FRIF_APPL_CONST                 /* Applications' ROM Data            */

#define FRIF_APPL_DATA                  /* Applications' RAM Data            */
/* ---------------------------------------------------------------------------*/
/*                   FrSM                                                    */
/* ---------------------------------------------------------------------------*/

#define FRSM_CODE                       /* API functions                     */

#define FRSM_CONST                      /* API constants                     */

#define FRSM_APPL_DATA                  /* Applications' RAM Data            */

#define FRSM_APPL_CONST                  /* Applications' ROM Data            */

#define FRSM_VAR_POWER_ON_INIT           /* Data which is initialized during
                                           Startup                           */
#define FRSM_VAR_NOINIT                /* Data which is not initialized during
                                            Startup                           */
#define FRSM_VAR                /* Data which is not initialized during
                                            Startup                           */
/* ---------------------------------------------------------------------------*/
/*                   FIM                                                    */
/* ---------------------------------------------------------------------------*/
#define FIM_CODE                       /* API functions                       */

#define FIM_PRIVATE_DATA               /* Module internal data                */

#define FIM_APPL_CONST                 /* Applications' ROM Data              */

#define FIM_APPL_DATA                  /* Applications' RAM Data              */

#define FIM_CONST                      /* Data Constants                      */
/* ---------------------------------------------------------------------------*/
/*                   BswM                                                     */
/* ---------------------------------------------------------------------------*/
#define BSWM_CODE                /* API functions                      */

#define BSWM_CONST               /* API constants                      */

#define BSWM_APPL_CONST                 /* Applications' ROM Data             */

#define BSWM_APPL_DATA                  /* Applications' RAM Data             */

#define BSWM_VAR_NOINIT               /* Data which is not initialized during
                                          Startup                             */
#define BSWM_VAR_POWER_ON_INIT             /* Data which is initialized with ZERO
                                         during startup                       */


/* ---------------------------------------------------------------------------*/
/*                                  CANIF                                     */
/* ---------------------------------------------------------------------------*/

#define CANIF_CODE                /* API functions                     */
#define CANIF_CONST               /* API constants                     */

#define CANIF_CODE               /* Internal functions                */

#define CANIF_DATA               /* Module internal data              */
#define CANIF_CONST              /* Internal ROM Data                 */

#define CANIF_APPL_CODE                  /* callbacks of the Application      */

#define CANIF_CODE                       /* memory class for code             */
#define CANIF_CONST                      /* Constant data                     */
#define CANIF_APPL_DATA                  /* Applications' RAM Data            */

#define CANIF_APPL_CONST                 /* Applications' ROM Data            */
#define CANIF_APPL_CODE                  /* Callbacks of the Application      */
#define CANIF_CALLOUT_CODE          /* memory class for pointers to application
                                    functions (e.g. callout function pointers)*/
#define CANIF_VAR_NOINIT            /* Data which is not initialized during
                                           Startup                            */
#define CANIF_VAR_POWER_ON_INIT     /* memory class for all global or static
                                      variables that are initialized only after
                                                               power on reset */
#define CANIF_VAR_FAST  /* memory class for all global or static variables that
                           have at least one of the following properties:
                           1. accessed bitwise 2. frequently used
                           3.high number of accesses in source code */
#define CANIF_VAR       /* memory class for all global or static variables that
                           are initialized after every reset */



/* ---------------------------------------------------------------------------*/
/*                                  CAN                                     */
/* ---------------------------------------------------------------------------*/

#define CAN_CODE                /* API functions                     */
#define CAN_17_CODE                /* API functions                     */
#define CAN_CONST               /* API constants                     */

#define CAN_CODE               /* Internal functions                */

#define CAN_DATA               /* Module internal data              */
#define CAN_CONST              /* Internal ROM Data                 */

#define CAN_APPL_CODE                  /* callbacks of the Application      */

#define CAN_CODE                       /* memory class for code             */
#define CAN_CONST                      /* Constant data                     */
#define CAN_APPL_DATA                  /* Applications' RAM Data            */

#define CAN_APPL_CONST                 /* Applications' ROM Data            */
#define CAN_APPL_CODE                  /* Callbacks of the Application      */
#define CAN_CALLOUT_CODE          /* memory class for pointers to application
                                    functions (e.g. callout function pointers)*/
#define CAN_VAR_NOINIT            /* Data which is not initialized during
                                           Startup                            */
#define CAN_VAR_POWER_ON_INIT     /* memory class for all global or static
                                      variables that are initialized only after
                                                               power on reset */
#define CAN_VAR_FAST  /* memory class for all global or static variables that
                           have at least one of the following properties:
                           1. accessed bitwise 2. frequently used
                           3.high number of accesses in source code */
#define CAN_VAR       /* memory class for all global or static variables that
                           are initialized after every reset */

/* ---------------------------------------------------------------------------*/
/*                       COMM                                                 */
/* ---------------------------------------------------------------------------*/
#define COMM_CODE                /* API functions                      */

#define COMM_CONST               /* API constants                      */

#define COMM_APPL_CODE                  /* Callbacks of the Application       */

#define COMM_APPL_CONST                 /* Applications' ROM Data             */

#define COMM_APPL_DATA                  /* Applications' RAM Data             */

#define COMM_VAR_NOINIT                /* Data which is not initialized during
                                           Startup                            */
#define COMM_VAR_POWER_ON_INIT             /* Data which is initialized with ZERO
                                         during startup                       */

/* ---------------------------------------------------------------------------*/
/*                       COM                                                 */
/* ---------------------------------------------------------------------------*/
#define COM_CODE                /* API functions                      */

#define COM_CONST               /* API constants                      */

#define COM_APPL_CODE                  /* Callbacks of the Application       */

#define COM_APPL_CONST                 /* Applications' ROM Data             */

#define COM_APPL_DATA                  /* Applications' RAM Data             */

#define COM_VAR_NOINIT                /* Data which is not initialized during
                                           Startup                            */
#define COM_VAR_POWER_ON_INIT             /* Data which is initialized with ZERO
                                         during startup                       */

/* ---------------------------------------------------------------------------*/
/*                       PDUR                                                 */
/* ---------------------------------------------------------------------------*/
#define PDUR_CODE                /* API functions                      */

#define PDUR_VAR

#define PDUR_CONST               /* API constants                      */

#define PDUR_APPL_CODE                  /* Callbacks of the Application       */

#define PDUR_APPL_CONST                 /* Applications' ROM Data             */

#define PDUR_APPL_DATA                  /* Applications' RAM Data             */

#define PDUR_VAR_NOINIT                /* Data which is not initialized during
                                           Startup                            */
#define PDUR_VAR_POWER_ON_INIT             /* Data which is initialized with ZERO
                                         during startup                       */

/* ---------------------------------------------------------------------------*/
/*                       CANSM                                                 */
/* ---------------------------------------------------------------------------*/
#define CANSM_CODE                /* API functions                      */

#define CANSM_VAR

#define CANSM_CONST               /* API constants                      */

#define CANSM_APPL_CODE                  /* Callbacks of the Application       */

#define CANSM_APPL_CONST                 /* Applications' ROM Data             */

#define CANSM_APPL_DATA                  /* Applications' RAM Data             */

#define CANSM_VAR_NOINIT                /* Data which is not initialized during
                                           Startup                            */
#define CANSM_VAR_POWER_ON_INIT             /* Data which is initialized with ZERO
                                         during startup                       */

/* ---------------------------------------------------------------------------*/
/*                       CANNM                                                 */
/* ---------------------------------------------------------------------------*/
#define CANNM_CODE                /* API functions                      */

#define CANNM_VAR

#define CANNM_CONST					/* API constants                      */

#define CANNM_APPL_CONST                 /* Applications' ROM Data             */

#define CANNM_APPL_DATA                  /* Applications' RAM Data             */

/* ---------------------------------------------------------------------------*/
/*                   NM                                                       */
/* ---------------------------------------------------------------------------*/
#define NM_CODE                       /* API functions                        */

#define NM_APPL_CODE                  /* callbacks of the Application         */
#define NM_APPL_CONST                 /* Applications' ROM Data               */
#define NM_APPL_DATA                  /* Applications' RAM Data               */
#define NM_VAR_NOINIT
#define NM_VAR_POWER_ON_INIT

#define NM_CONST                      /* Data Constants                       */

/* ---------------------------------------------------------------------------*/
/*                  RTE                                                    */
/* ---------------------------------------------------------------------------*/

#define RTE_CODE                       /* API functions                        */
#define RTE_CONST					/* API constants                      */
#define RTE_APPL_DATA					/* API constants                      */
#define RTE_DATA					/* API constants                      */
#define RTE_PB_CONFIG_DATA					/* API constants                      */
#define BSWMODULEDESCRIPTION_CALIB_CODE
#define SWC_PerInstParameter_CODE

/* ---------------------------------------------------------------------------*/
/*                 ECUM                                                  */
/* ---------------------------------------------------------------------------*/

#define ECUM_CODE
#define ECUM_CONST
#define ECUM_CALLOUT_CODE
#define ECUM_APPL_CONST

/* ---------------------------------------------------------------------------*/
/*                 LINIF                                                  */
/* ---------------------------------------------------------------------------*/
#define LINIF_CODE
#define LINIF_APPL_CONST
#define LINIF_APPL_DATA
#define LINIF_APPL_CODE
#define LINIF_DATA
#define LINIF_CONST
#define LINIF_CONFIG_DATA
#define LINIF_CONFIG_CONST
#define LINIF_ZERO_INIT_DATA
#define LINIF_VAR_NOINIT
#define LINIF_VAR

/* ---------------------------------------------------------------------------*/
/*                 LINTP                                                  */
/* ---------------------------------------------------------------------------*/
#define LINTP_CODE
#define LINTP_CONST
#define LINTP_APPL_CONST
#define LINTP_APPL_DATA
#define LINTP_CONFIG_DATA
#define LINTP_VAR_NOINIT
#define LINTP_VAR


/* ---------------------------------------------------------------------------*/
/*                   IPDUM                                                    */
/* ---------------------------------------------------------------------------*/
#define IPDUM_CODE                       /* memory class for code             */
#define IPDUM_CONST                      /* Constant data                     */
#define IPDUM_APPL_DATA                  /* Applications' RAM Data            */
#define IPDUM_APPL_CONST                 /* Applications' ROM Data            */
#define IPDUM_APPL_CODE                  /* Callbacks of the Application      */
#define IPDUM_CALLOUT_CODE          /* memory class for pointers to application
                                    functions (e.g. callout function pointers)*/
#define IPDUM_VAR_NOINIT            /* Data which is not initialized during
                                           Startup                            */
#define IPDUM_VAR_POWER_ON_INIT     /* memory class for all global or static
                                      variables that are initialized only after
                                                               power on reset */
#define IPDUM_VAR_FAST  /* memory class for all global or static variables that
                           have at least one of the following properties:
                           1. accessed bitwise 2. frequently used
                           3.high number of accesses in source code */
#define IPDUM_VAR       /* memory class for all global or static variables that
                           are initialized after every reset */

/* ---------------------------------------------------------------------------*/
/*                   XCP                                                     */
/* ---------------------------------------------------------------------------*/

#define XCP_CODE                  /* callbacks of the Application       */
#define XCP_DATA                  /* Applications' RAM Data             */

#define XCP_VAR_NOINIT               /* Data which is not initialized during */
#define XCP_CONST                      /* Data Constants                     */
/*------------------------------------------------------------------------------------------------*/

#endif /* COMPILER_CFG_H */

