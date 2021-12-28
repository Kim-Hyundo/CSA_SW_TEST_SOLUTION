
/* MODIFY SJCHOI
 * File: pil_target_tc277.h
 *
 * Code generated for Simulink model 'pil_target_tc277'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 8.7 (R2014b) 08-Sep-2014
 * C/C++ source code generated on : Thu Jan 15 18:35:44 2015
 *
 * Target selection: trace32_tc_ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_pil_target_tc277_h_
#define RTW_HEADER_pil_target_tc277_h_
#include <math.h>
#include <string.h>
#ifndef pil_target_tc277_COMMON_INCLUDES_
# define pil_target_tc277_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* pil_target_tc277_COMMON_INCLUDES_ */

#include "pil_target_tc277_types.h"

/* Shared type includes */
#include "model_reference_types.h"


/* Block states (auto storage) for model 'pil_target_tc277' */
typedef struct {
  uint16_T IntegerDelay1_DSTATE;       /* '<Root>/Integer Delay1' */
  uint16_T IntegerDelay_DSTATE[3];     /* '<Root>/Integer Delay' */
} rtDW_pil_target_tc277;

/* Real-time Model Data Structure */
struct tag_RTM_pil_target_tc277 {
  const char_T **errorStatus;
};

typedef struct {
  rtDW_pil_target_tc277 rtdw;
  RT_MODEL_pil_target_tc277 rtm;
} rtMdlrefDWork_pil_target_tc277;

/* Model reference registration function */
extern void VC_Initialize(void);
extern void VC_Step(void);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'pil_target_tc277'
 */
#endif                                 /* RTW_HEADER_pil_target_tc277_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
