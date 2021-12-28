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

#ifndef DRV_DEF_H
#define DRV_DEF_H


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"                  /* Standard type header */

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

/*Global MACRO CONSTANT Definition**************************/
/* Enable/Disable definitions */
#ifndef _DISABLE
#define	_DISABLE	0x00
#endif

#ifndef _ENABLE
#define	_ENABLE		0x01
#endif

#ifndef _FALSE
#define _FALSE		0x00
#endif

#ifndef _TRUE
#define _TRUE		0x01
#endif

#ifndef _OFF
#define _OFF		0x00
#endif

#ifndef _ON
#define _ON			0x01
#endif


/* Transmission Option */
#define AUTO_TRANSMISSION		0x00
#define MANUAL_TRANSMISSION		0x01

/* Driver Seat Position */
#define LEFT_HANDED_DRIVER		0x00
#define RIGHT_HANDED_DRIVER		0x01


#endif

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

