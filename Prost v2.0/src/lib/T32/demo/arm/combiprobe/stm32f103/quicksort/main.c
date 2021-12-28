#include "define.h"

extern void heapsort(unsigned int *arr, unsigned int N);
extern void quicksort(u_int32 *array, u_int32 len);

#define ARRAY_SIZE 200
u_int32 g_array[ARRAY_SIZE];
int main()
{
	u_int32 cmp,i;

	/* Enable ITM tracing */
	ITM_ENABLE_ACCESS;
	ITM_TRACE_PRIV=0;
	ITM_TRACE_ENABLE=0xFFFFFFFF;

	cmp=0x72233445;
	for (;;)
	{
		for (i=0;i<ARRAY_SIZE;i++)
		{
			if (cmp&0x80000000)
			{
				cmp<<=1;
				cmp^=0x10904081;
			}
			else
				cmp<<=1;
			g_array[i]=cmp;
		}
		quicksort(g_array,ARRAY_SIZE);
	}
}
