#define uint32_t unsigned int
#include "slow_sorts.h"

static void is_h(uint32_t *aleft, uint32_t *aright)
{
	uint32_t *i,*j,*k,v,h;

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
}

static void isort(uint32_t *array, uint32_t len)
{
	is_h(array,array+(len-1));
}

static void selsort(uint32_t *array, uint32_t len)
{
	uint32_t v,w;
	uint32_t *ee,*pc,*pv;
	ee=array+len;
	while (array<ee) {
		pv=array;
		v=*pv;
		pc=array+1;
		while(pc<ee) {
			w=*pc;
			if (w<v) {
				v=w;
				pv=pc;
			}
			pc++;
		}
		*pv=*array;
		*array=v;
		array++;
	}
}


static void bubblesort(uint32_t *array, uint32_t len)
{
	uint32_t i,v1,v2;

	while (len>1) {
		v1=array[0];
		for(i=1;i<len;i++) {
			v2=array[i];
			if (v1>v2) {
				array[i-1]=v2;
				array[i]=v1;
			} else {
				v1=v2;
			}
		}
		len--;
	}
}

static struct slow_sort_ptrs slow_sort_impl1 = {
	isort,
	selsort,
	bubblesort
};

extern struct slow_sort_ptrs *slow_sorts;

static void before_main1(void)
{
	slow_sorts = &slow_sort_impl1;
}

/*
	the startup code in crt0.s
	will call all functions listed in the ".beforemain" section,
	before main is called.
	Create a function pointer which points to before_main1.
	This function pointer will be linked into ".beforemain" so that
	before_main1 is called before "main()".
*/
void (*before_main1_ptr)(void) __attribute__ ((section (".beforemain"))) = before_main1;
