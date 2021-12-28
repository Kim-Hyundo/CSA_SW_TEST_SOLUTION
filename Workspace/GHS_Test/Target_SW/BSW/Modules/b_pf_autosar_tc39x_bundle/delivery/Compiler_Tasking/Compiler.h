/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2019)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Compiler.h                                                    **
**                                                                            **
**  VERSION   : 1.30.0_8.0.0                                                  **
**                                                                            **
**  DATE      : 2019-09-12                                                    **
**                                                                            **
**  VARIANT   : NA                                                            **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY : [cover parentID={FB97B5EA-8796-4991-B969-37114769C0BA}]    **
**                                                                            **
**  DESCRIPTION  : Compiler Abstraction Macros                                **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
**  SPECIFICATION(S) : AUTOSAR_SWS_CompilerAbstraction, AUTOSAR Release 4.2.2 **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
#ifndef COMPILER_H
#define COMPILER_H

/******************************************************************************
**                      Includes                                             **
******************************************************************************/
#include "Compiler_Cfg.h"

/******************************************************************************
**                      Global Macro Definitions                             **
******************************************************************************/
/*
 * Vendor ID of the dedicated implementation of this module according
 * to the AUTOSAR vendor list
 */
#define COMPILER_VENDOR_ID        (17u)


#define COMPILER_AR_RELEASE_MAJOR_VERSION    (4u)
#define COMPILER_AR_RELEASE_MINOR_VERSION    (2u)
#define COMPILER_AR_RELEASE_REVISION_VERSION (2u)

#if defined(__HIGHTEC__)
  #define _GNU_C_TRICORE_ 1U
  /*
   * HIGHTEC V4.9.2.0
   */
  #define COMPILER_SW_MAJOR_VERSION (4u)
  #define COMPILER_SW_MINOR_VERSION (9u)
  #define COMPILER_SW_PATCH_VERSION (2u)
#endif

#if defined (__TASKING__)
  #define _TASKING_C_TRICORE_ 1U
  #if (__VERSION__ == 6003)
    /*
     * TASKING V6.3R1P1
     */
    #define COMPILER_SW_MAJOR_VERSION (6u)
    #define COMPILER_SW_MINOR_VERSION (3u)
    #define COMPILER_SW_PATCH_VERSION (1u)
  #else
    /*
     * TASKING V6.2R2P2
     */
    #define COMPILER_SW_MAJOR_VERSION (6u)
    #define COMPILER_SW_MINOR_VERSION (2u)
    #define COMPILER_SW_PATCH_VERSION (2u)
  #endif
#endif

#if defined(__DCC__)
#define _DIABDATA_C_TRICORE_ 1U
  /*
   * WINDRIVER 5.9.6.4
   */
  #define COMPILER_SW_MAJOR_VERSION (5u)
  #define COMPILER_SW_MINOR_VERSION (9u)
  #define COMPILER_SW_PATCH_VERSION (6u)
#endif

#if defined (__ghs__)
  #define _GHS_C_TRICORE_ 1U
  /*
   * GREEN HILLS V2018.1.5 R9.15.1
   */
  #define COMPILER_SW_MAJOR_VERSION (18u)
  #define COMPILER_SW_MINOR_VERSION (1u)
  #define COMPILER_SW_PATCH_VERSION (5u)
#endif

#ifndef STATIC
#define STATIC    static
#endif

/*used for local non static variables*/
#define AUTOMATIC

#define TYPEDEF

#define NULL_PTR ((void *)0)

/*abstraction of the keyword inline in functions with “static” scope*/
#ifdef _GNU_C_TRICORE_

#ifndef INLINE
#define INLINE      __inline__
#endif

#ifndef LOCAL_INLINE
#define LOCAL_INLINE    static __inline__
#endif

#endif

#ifdef _TASKING_C_TRICORE_

#ifndef INLINE
#define INLINE      inline
#endif

#ifndef LOCAL_INLINE
#define LOCAL_INLINE    static inline
#endif

#endif

#ifdef _DIABDATA_C_TRICORE_

#ifndef INLINE
#define INLINE      __inline__
#endif

#ifndef LOCAL_INLINE
#define LOCAL_INLINE  static __inline__
#endif

#endif

#ifdef _GHS_C_TRICORE_

#ifndef INLINE
#define INLINE     __inline__
#endif

#ifndef LOCAL_INLINE
#define LOCAL_INLINE   static inline
#endif

#endif

/* Changed by AUTRON -----------------------------------------------------------------------------*/
/* AUTOMATIC used for the declaration of local pointers */
#define AUTOMATIC

/* Type definition of pointers to functions
   rettype     return type of the function
   ptrclass    defines the classification of the pointer's distance
               (not used on 32bit platforms)
   fctname     function name respectivly name of the defined type
 */
#define P2FUNC(rettype, ptrclass, fctname) rettype (*fctname)

/* Type definition of const pointers to functions
   rettype     return type of the function
   ptrclass    defines the classification of the pointer's distance
               (not used on 32bit platforms)
   fctname     function name respectivly name of the defined type
 */
#define CONSTP2FUNC(rettype, ptrclass, fctname)  rettype (*const fctname)

/* The compiler abstraction shall define the FUNC macro for the declaration and
   definition of functions, that ensures correct syntax of function declarations
   as required by a specific compiler. - used for API functions
   rettype     return type of the function
   memclass    classification of the function itself
               (not used on 32bit platforms)
 */
#define FUNC(type, memclass) type

/* FUNC_P2CONST macro for the declaration and definition of functions returning
   a pointer to a constant. This shall ensure the correct syntax of function
   declarations as required by a specific compiler.
   rettype     return type of the function
   ptrclass    defines the classification of the pointer distance
   memclass    classification of the function itself
*/
#define FUNC_P2CONST(rettype, ptrclass, memclass) const ptrclass rettype * memclass

/* FUNC_P2VAR macro for the declaration and definition of functions returning a
   pointer to a variable. This shall ensure the correct syntax of function
   declarations as required by a specific compiler.
   rettype     return type of the function
   ptrclass    defines the classification of the pointer distance
   memclass    classification of the function itself
*/
#define FUNC_P2VAR(rettype, ptrclass, memclass) ptrclass rettype * memclass

/* Pointer to constant data
   ptrtype     type of the referenced data
   memclass    classification of the pointer's variable itself
               (not used on 32bit platforms)
   ptrclass    defines the classification of the pointer's distance
               (not used on 32bit platforms)
 */
#define P2CONST(ptrtype, memclass, ptrclass)  const ptrtype *

/* Pointer to variable data
   ptrtype     type of the referenced data
   memclass    classification of the pointer's variable itself
               (not used on 32bit platforms)
   ptrclass    defines the classification of the pointer's distance
               (not used on 32bit platforms)
 */
#define P2VAR(ptrtype, memclass, ptrclass) ptrtype *

/* Const pointer to variable data
   ptrtype     type of the referenced data
   memclass    classification of the pointer's variable itself
               (not used on 32bit platforms)
   ptrclass    defines the classification of the pointer's distance
               (not used on 32bit platforms)
 */
#define CONSTP2VAR(ptrtype, memclass, ptrclass) ptrtype * const

/* Const pointer to constant data
   ptrtype     type of the referenced data
   memclass    classification of the pointer's variable itself
               (not used on 32bit platforms)
   ptrclass    defines the classification of the pointer's distance
               (not used on 32bit platforms)
 */
#define CONSTP2CONST(ptrtype, memclass, ptrclass) const ptrtype * const

/* ROM constant
   type        type of the constant
   memclass    classification of the constant
               (not used on 32bit platforms)
 */
#define CONST(type, memclass) const type

/* RAM variables
   type        type of the variable
   memclass    classification of the variable
               (not used on 32bit platforms)
 */
#define VAR(type, memclass) type
/*------------------------------------------------------------------------------------------------*/
/******************************************************************************
**                      Global Type Definitions                              **
******************************************************************************/

/******************************************************************************
**                      Global Constant Declarations                         **
******************************************************************************/

/******************************************************************************
**                      Global Variable Declarations                         **
******************************************************************************/

/******************************************************************************
**                      Global Function Declarations                         **
******************************************************************************/
#endif /* } COMPILER_H  */

