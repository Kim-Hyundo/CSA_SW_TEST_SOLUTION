#include "define.h"

#define ITM_CHANNEL_QS 1

#define ITM_ENTRY_QS    1
#define ITM_ENTRY_IS    2
#define ITM_QS_START    3
#define ITM_EXIT     0x80

static void is_h(u_int32 *aleft, u_int32 *aright)
{
	u_int32 *i,*j,*k,v,h;
	ITM_PUT_BYTE(ITM_CHANNEL_QS,ITM_ENTRY_IS);
	ITM_PUT_DWORD(ITM_CHANNEL_QS,aleft);
	ITM_PUT_DWORD(ITM_CHANNEL_QS,aright);

	i=aleft+1;
	while (i<=aright)
	{
		v=*i;
		j=i;
		do
		{
			k=j-1;
			h=*k;
			if (h<=v)
				break;
			*j=h;
			j=k;
		} while (j>aleft);
		i++;
		*j=v;
	}

	ITM_PUT_BYTE(ITM_CHANNEL_QS,ITM_EXIT);
}

static void qs_h(u_int32 *aleft, u_int32 *aright)
{
	u_int32 pivot, temp;
	u_int32 *al,*ar;

	ITM_PUT_BYTE(ITM_CHANNEL_QS,ITM_ENTRY_QS);
	ITM_PUT_DWORD(ITM_CHANNEL_QS,aleft);
	ITM_PUT_DWORD(ITM_CHANNEL_QS,aright);

	if (aleft < aright) 
	{
		temp=(u_int32)(((u_intptr)aright)-((u_intptr)aleft));

		/* Insertion sort if 8 or less elements */
		if ( temp <= (7*sizeof(u_int32)) )
		{
			is_h(aleft,aright);
			ITM_PUT_BYTE(ITM_CHANNEL_QS,ITM_EXIT);
			return;
		}

		al=aleft;
		ar=aright;
		pivot = *( (u_int32 *)(((((u_intptr)al)+((u_intptr)ar))>>1)&(~(sizeof(u_int32)-1))) );
		do
		{
			while (*al < pivot) { al++; }
			while (*ar > pivot) { ar--; }

			if (al <= ar)
			{
				temp = *ar; *ar = *al; *al = temp;
				al++; ar--;
			}
		}
		while (al <= ar);
		qs_h(aleft, ar);
		qs_h(al, aright);
	}
	ITM_PUT_BYTE(ITM_CHANNEL_QS,ITM_EXIT);
}

void quicksort(u_int32 *array, u_int32 len)
{
	ITM_PUT_BYTE(ITM_CHANNEL_QS,ITM_QS_START);
	qs_h(array,array+(len-1));
}
