/*****************************************************************************
| Project Name: OSEK 2.1 (TriCore)
|    File Name: main.c 
|
|  Description: sample application
|
|-----------------------------------------------------------------------------
|               C O P Y R I G H T
|-----------------------------------------------------------------------------
| Copyright (c) 2000 Vector Informatik GmbH               All rights reserved.
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     ------------------------------------
| HH           Hartmut Hoerner           Vector Informatik GmbH
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date         Ver   Author  Description
| ----------   ----  ------  --------------------------------------------------
| 10.07.2000   1.00  HH      Adaptation to TriCore
|****************************************************************************/

/* define for automatic testing */
#define AUTO_TEST 

           	        
#include <osek.h>


/* for automatic testing */
#ifdef AUTO_TEST
void testOK(void)
{
   for (;;);
}

void testNOK(void)
{
   for (;;);
}
#endif


void GPTU_T1(void)
{
}

/*** tasks ***/

TASK(basicTaskFirst)
{
   for(;;)
   {
      GetResource(resBasic);
      ActivateTask(basicTaskSecond);
      ReleaseResource(resBasic);
      SetEvent(extendedTaskFirst, evExT1_1);
   }
} /* END OF basicTaskFirst */

int gAlarmActive=0;

TASK(basicTaskSecond)
{
   if(!gAlarmActive)
   {
      SetRelAlarm(myFirstAlarm, MSEC(1000), 0);
      gAlarmActive=1;
   }
   TerminateTask();
} /* END OF basicTaskSecond */

#ifdef AUTO_TEST
uint32 count=0;
#endif

TASK(basicTaskThird)
{
   #ifdef AUTO_TEST
   count++;
   /* terminate program after 30s if running automatic test */
   if(count>30)
      testOK();
   #endif
   gAlarmActive=0;
   TerminateTask();
} /* END OF basicTaskThird */

int gBasicTaskFirstActivated=0;

TASK(extendedTaskFirst)
{
   TaskStateType state;

   if(!gBasicTaskFirstActivated)
   {
         ActivateTask(basicTaskFirst);
         gBasicTaskFirstActivated=1;
   }
   
   for(;;)
   {
      WaitEvent(evExT1_1);
      ClearEvent(evExT1_1);
      GetTaskState(extendedTaskSecond,&state);
      if(state!=SUSPENDED)
      {
         SetEvent(extendedTaskSecond, evExT2_1);
         TerminateTask();
      }
      else
      {
         ActivateTask(extendedTaskSecond);
      }
   }

} /* END OF extendedTaskFirst */


TASK(extendedTaskSecond)
{
   WaitEvent(evExT2_1);
   ClearEvent(evExT2_1);
   ChainTask(extendedTaskFirst);
} /* END OF extendedTaskSecond */


/*** hook routines ***/

void StartupHook()
{
} /* END OF StartupHook */


volatile StatusType gErrorCode;
volatile uint16 guiError;

#if (STATUS_LEVEL == EXTENDED_STATUS) && !defined(osdSuppressFilenames)
void ErrorHook(StatusType ErrorCode, uint16 uiError, char *pModule, int iLine)
#else
void ErrorHook(StatusType ErrorCode, uint16 uiError)
#endif
{
#if (STATUS_LEVEL == EXTENDED_STATUS) && !defined(osdSuppressFilenames)
   iLine = iLine;   /* because of compiler warning */
   pModule = pModule; /* because of compiler warning */
#endif
   gErrorCode = ErrorCode;
   guiError = uiError;
#ifdef AUTO_TEST
   testNOK();
#else
   ShutdownOS(ErrorCode);
#endif
} /* END OF ErrorHook */

/*** main ***/
void main(void)
{
   #ifdef AUTO_TEST
   count=0;
   #endif
   gAlarmActive=0;
   gBasicTaskFirstActivated=0; 
   StartOS(0);
}
 
/* END OF MODULE main.c */


 
