#include "calc_util.h"

#pragma inline
int add( int a, int b )
{
     int i=4;
     return( a + b );
}
#pragma noinline
int ovar;
int invert(int ivar)
{
    __asm ("not %0": "=d"(ovar): "0"(ivar) );

    return ovar;
}
