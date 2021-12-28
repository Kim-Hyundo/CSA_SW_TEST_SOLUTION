#define uint32_t unsigned int

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

static void qs_h(uint32_t *aleft, uint32_t *aright)
{
	uint32_t pivot,temp1,temp2;
	uint32_t *al,*ar;

	if (aleft >= aright)
		return;

	al=aleft;
	ar=aright;
	pivot = *(al+(((uint32_t)(ar-al))/2));
	do
	{
		temp1 = *al;
		if (temp1 < pivot) {
			do {
				al++;
				temp1 = *al;
			} while (temp1 < pivot);
		}
		temp2 = *ar;
		if (temp2 > pivot) {
			do {
				ar--;
				temp2 = *ar;
			} while (temp2 > pivot);
		}
		if (al <= ar)
		{
			*al = temp2;
			*ar = temp1;
			al++; 
			ar--;
		}
	} while (al <= ar);
	qs_h(aleft, ar);
	qs_h(al, aright);
}

void quicksort(uint32_t *array, uint32_t len)
{
	qs_h(array,array+(len-1));
}

void heapsort(unsigned int *arr, unsigned int N)
{
	unsigned int n = N, i = n>>1 , parent, child;
	int t;

	for (;;) {
		if (i > 0) {
			i--;
			t = arr[i];
		} else {
			n--;
			if (n == 0) return;
			t = arr[n];
			arr[n] = arr[0];
		}

		parent = i;
		child = (i<<1) + 1;

		while (child < n) {
			if (child + 1 < n  &&  arr[child + 1] > arr[child]) {
				child++;
			}
			if (arr[child] > t) {
				arr[parent] = arr[child];
				parent = child;
				child = (parent<<1) + 1;
			} else {
				break;
			}
		}
		arr[parent] = t;
	}
}

static void shell_h(uint32_t *aleft, uint32_t *aright,int inc)
{
	uint32_t *i,*j,*k,v,h;
	i=aleft+inc;
	while (i<=aright)
	{
		v=*i; // v == value at array[i]
		j=i;
		k=i-inc;
		do
		{
			h=*k;  // h == value at array[i-n*inc], n>=1
			if (h<=v)  // h<=v found the place to insert h
				break;
			*j=h;  // h>v => copy h to array[i-n*inc + inc]
			j=k;
			k-=inc;
		} while (k>=aleft);
		*j=v;
		i++;
	}
}

static void shellsort(uint32_t *array,int len)
{
	static int seq[] = {0, 1, 4, 10, 23, 57, 132, 301, 701, 1750, 3850, 8470, 18634, 40995, 90189 };
	uint32_t *aright;
	int *h,*n;
	h=seq;
	for(;;)
	{
		n=h+1;
		if (*n>=len)
			break;
		h=n;
	}
	aright=array+(len-1);
	while (*h>0)
	{
		shell_h(array,aright,*h);
		h--;
	}
}

static void create_random_lfsr(uint32_t *arr,int len)
{
	static uint32_t gen_cur=0x72233445;
	uint32_t cmp;
	int i;

	cmp=gen_cur;
	for (i=0;i<len;i++)
	{
		if (cmp&0x80000000)
		{
			cmp<<=1;
			cmp^=0x10904081;
		}
		else
			cmp<<=1;
		arr[i]=cmp;
	}
	gen_cur=cmp;
}

#define ARRAY_SIZE 1024
static uint32_t array[ARRAY_SIZE];
/* count defines how many times the main function loops    */
/* can be increased by debugger to get longer running time */
int count = 50;
int main(void)
{
	while (count>0) {
		create_random_lfsr(array,ARRAY_SIZE);
		quicksort(array,ARRAY_SIZE);
		create_random_lfsr(array,ARRAY_SIZE);
		heapsort(array,ARRAY_SIZE);
		create_random_lfsr(array,ARRAY_SIZE);
		shellsort(array,ARRAY_SIZE);
		create_random_lfsr(array,ARRAY_SIZE);
		isort(array,ARRAY_SIZE);
		count--;
	}
}
