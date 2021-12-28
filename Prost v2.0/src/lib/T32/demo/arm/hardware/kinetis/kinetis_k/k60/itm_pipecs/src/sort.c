#define uint32_t unsigned int

static volatile unsigned int *ITM_BASE = (volatile unsigned int *)0xE0000000;
#define ITM_ENABLE_ACCESS  do { ITM_BASE[0x3EC]=0xC5ACCE55; } while ((0))
#define ITM_TRACE_PRIV     ITM_BASE[0x390]
#define ITM_TRACE_ENABLE   ITM_BASE[0x380]

#define ITM_TRACE_D8(_channel_,_data_) { \
	volatile unsigned int *_ch_=ITM_BASE+(_channel_); \
	while ( *_ch_ == 0); \
	(*((volatile unsigned char *)(_ch_)))=(_data_); \
}

#define ITM_TRACE_D16(_channel_,_data_) { \
	volatile unsigned int *_ch_=ITM_BASE+(_channel_); \
	while ( *_ch_ == 0); \
	(*((volatile unsigned short *)(_ch_)))=(_data_); \
}

#define ITM_TRACE_D32(_channel_,_data_) { \
	volatile unsigned int *_ch_=ITM_BASE+(_channel_); \
	while ( *_ch_ == 0); \
	*_ch_ = (_data_); \
}


#define MAX_ARRAY_SIZE 1024
/* count defines how many times the main function loops    */
/* can be increased by debugger to get longer running time */
volatile int count = 51;
volatile uint32_t array_size = MAX_ARRAY_SIZE;

static uint32_t array[MAX_ARRAY_SIZE];
static uint32_t merge_array[MAX_ARRAY_SIZE];

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

static void rdxsort(uint32_t *array,uint32_t len)
{
	uint32_t b_cnt[16];
	uint32_t shft,i,v,n,p;
	shft=0;
	while (shft<32) {
		for (i=0;i<16;i++) {
			b_cnt[i]=0;
		}
		for (i=0;i<len;i++) {
			v=array[i];
			v>>=shft;
			v&=0xF;
			b_cnt[v]++;
		}
		v=0;
		for (i=0;i<16;i++) {
			n=b_cnt[i];
			b_cnt[i]=v;
			v+=n;
		}
		for (i=0;i<len;i++) {
			v=array[i];
			n=v>>shft;
			n&=0xF;
			p=b_cnt[n];
			merge_array[p]=v;
			p++;
			b_cnt[n]=p;
		}
		for (i=0;i<len;i++) {
			array[i]=merge_array[i];
		}
		shft+=4;
	}
}

static void rdxsort2_h(uint32_t *array, uint32_t len, int shft)
{
	uint32_t b_cnt[16],b_pos[16];
	uint32_t i,v,n,p,bp;

	// count number of elements in buckets
	for (i=0;i<16;i++) {
		b_cnt[i]=0;
	}
	for (i=0;i<len;i++) {
		v=array[i];
		n=v>>shft;
		n&=0xF;
		b_cnt[n]++;
	}

	// calculate start positions of buckets
	p=0;
	for (i=0;i<16;i++) {
		n=b_cnt[i];
		b_cnt[i]=p; // b_cnt[i]: start position of bucket i
		b_pos[i]=p; // b_pos[i]: next element to put in bucket i.
		p+=n;
	}

	// i points to next bucket start
	// we are currently in bucket i-1.
	// skip over empty buckets:
	i=1;
	while (i<16 && b_cnt[i]==0) i++;

	// if i>=16 or b_cnt[i]>=len
	// then there only is one bucket (i-1),
	// which contains ALL elements.
	// In this case we do not need to sort anything.
	if (i<16 && b_cnt[i]<len) {
		// p points to currently unsorted position
		p=0;
		// start with putting array[0] into correct bucket
		v=array[0];
		for (;;) {
			// calculate bucket for v
			n=v>>shft;
			n&=0xF;
			// get current position in bucket n
			bp=b_pos[n];
			b_pos[n]=bp+1; // increment position in current bucket n
			if (bp==p) {
				// v belongs to bucket we are currently in
				// (we are in bucket i-1) => so store current v
				array[bp]=v;
				// move to next position
				p++;
				// skip over already sorted elements
				while (i<16 && p==b_cnt[i]) {
					p=b_pos[i];
					i++;
				}
				// stop if we have no more unsorted elements
				if (p>=len)
					break;
				// trick: if i==16 then all remaining
				// elements belong to bucket 15 AND ALREADY
				// are in bucket 15. So we are finished.
				if (i>=16) {
					// need to record that bucket 15 contains all remaining elements
					b_pos[15]=len;
					break;
				}
				// trick2: if b_cnt[i]>=len, then all remaining
				// elements belong to bucket i-1 AND ALREADY
				// are in bucket i-1. So we are finished.
				if (b_cnt[i]>=len) {
					// neet to record that bucket i-1 contains all remaining elements
					b_pos[i-1]=len;
					break;
				}
				// get value of current unsorted position
				v=array[p];
			} else {
				uint32_t nv;
				// put v into found bucket and
				// take replaced value as new v
				nv=array[bp];
				array[bp]=v;
				v=nv;
			}
		}
	} else {
		// ALL elements belong to bucket i-1
		// record that all elements into bucket i-1
		b_pos[i-1]=len;
	}
	if (shft<4)
		return;
	// recursively sort buckets which contain more than 2 elements:
	shft-=4;
	for (i=0;i<16;i++) {
		p=b_cnt[i];    // p  = start of bucket i
		bp=b_pos[i]-p; // bp = length of bucket i
		if (bp>1)
			rdxsort2_h(array+p,bp,shft);
	}
}

static void rdxsort2(uint32_t *array, uint32_t len)
{
	rdxsort2_h(array,len,28);
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
		ITM_TRACE_D32(3,v1);
		len--;
	}
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
	if ((ar-al)>=8) {
		ITM_TRACE_D32(4,pivot);
	}
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

void heapsort(uint32_t *arr, uint32_t len)
{
	uint32_t n;  /* current size of heap */
	uint32_t nm; /* == n-1 */
	uint32_t i;  /* position of element which is pushed down in the heap */
	uint32_t iv; /* value of this element */
	uint32_t parent, child; /* parent/child element in heap */
	uint32_t cv;            /* value of child element       */

	n = len;     /* start full array as heap */
	i = len>>1;  /* for initialization phase, start at middle of heap */

	/* heap order: biggest element is in arr[0] */
	for (;;) {
		if (i > 0) {
			/* init phase */
			i--;
			iv = arr[i];
		} else {
			/* sorting phase */
			n--;
			if (n == 0)
				return;
			/* swap last element of heap with first(biggest) element of heap */
			iv = arr[n];
			cv = arr[0];
			arr[n] = cv;
			ITM_TRACE_D32(5,cv);
		}
		/* push element in position "i" down in the heap.*/
		/* "iv" is value of this element */
		parent = i;
		child  = (i<<1) + 1;
		nm     = n-1;
		while (child < n) {
			/* find bigger child */
			cv = arr[child];
			if (child < nm) {
				uint32_t child2;
				uint32_t cv2;
				child2 = child+1;
				cv2 = arr[child2];
				if (cv2 > cv) {
					child = child2;
					cv    = cv2;
				}
			}
			if (cv > iv) {
				/* found child which is bigger than t */
				/* move child value up in heap        */
				arr[parent] = cv;
				parent = child;
				child = (parent<<1) + 1;
			} else {
				/* both childs are smaller than iv, so stop */
				break;
			}
		}
		arr[parent] = iv;
	}
}

static void shell_h(uint32_t *aleft, uint32_t *aright,int inc)
{
	uint32_t *i,*j,*k,v,h;
	/* we want to check if (k - inc) will be still in range.*/
	/* Instead we compare k<aleft+inc                       */
	aleft+=inc;
	i=aleft;
	while (i<=aright)
	{
		v=*i; /* v == value at array[i] */
		j=i;
		k=i-inc;
		for(;;)
		{
			h=*k;      /* h == value at array[i-n*inc], n>=1     */
			if (h<=v)  /* h<=v found the place to insert h       */
				break;
			*j=h;      /* h>v => copy h to array[i-n*inc + inc]  */
			j=k;
			if (k<aleft)
				break;
			k-=inc;
		}
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

static void merge_sort(uint32_t *arr,int len)
{
	int half,i,h1,h2;
	uint32_t e1,e2;

	if (len<=1)
		return;

	half=(len+1)/2;
	if (len>2) {
		// sort two halves
		merge_sort(arr,half);
		merge_sort(arr+half,len-half);
	}

	// copy 1st halve to merge_array
	for (i=0;i<half;i++) {
		merge_array[i]=arr[i];
	}
	// merge sort
	h1=0;    // position in "merge_array"
	h2=half; // position in second half of array
	i=0;     // position where to store merged result
	e1=merge_array[h1]; // current number at h1
	e2=arr[h2];         // current number at h2
	do {
		if (e1<e2) {
			arr[i]=e1;
			h1++;
			e1=merge_array[h1];
		} else {
			arr[i]=e2;
			h2++;
			e2=arr[h2];
		}
		i++;
	} while (h1<half && h2<len);
	while (h1<half) {
		arr[i]=e1;
		h1++;
		e1=merge_array[h1];
		i++;
	}
}

static void merge_sort2(uint32_t *arr,int len)
{
	int half,i;
	uint32_t v1,v2,*dst,*h1,*h2,*e1,*e2,*ee;

	half=1;      // half of current length of sub block.
	ee=arr+len;  // pointer to end of array
	while (half<len) {

		// copy 1st halves of sub block.
		h1=merge_array;
		h2=arr;
		do {
			i=half;
			do {
				v2=*h2;
				*h1=v2;
				h2++;
				h1++;
				i--;
			} while (i>0);
			h2+=half;
		} while (h2<ee && h2+half<ee);

		// merge two halves of sub block
		h1=merge_array;
		dst=arr; // pointer start of merge sub block.
		do {
			e1=h1+half;
			h2=dst+half;         // pointer to start of 2nd halve, stored in arr
			if (ee<=h2)          // 2nd half already outside of array, so we do not need to sort.
				break;
			e2=h2+half;          // pointer to end of 2nd halve
			if (ee<e2)
				e2=ee;

			v1=*h1;  // value of element of 1st halve
			v2=*h2;  // value of element of 2nd halve
			do {
				if (v1<=v2) {
					// 1st halve has smaller element, consume this element
					*dst=v1;
					h1++;
					v1=*h1;
				} else {
					// 2nd halve has smaller element, consume this element
					*dst=v2;
					h2++;
					v2=*h2;
				}
				dst++;
			} while (h2<e2 && h1<e1);
			// 1st half is stored in merge_array.
			// consume potential rest of 1st half:
			while (h1<e1) {
				*dst=v1;
				dst++;
				h1++;
				v1=*h1;
			}
			dst=e2;
		} while (dst<ee);
		half+=half;
	}
}


static void bitonic_split(uint32_t *values,int len)
{
	uint32_t tmp1,tmp2;
	int idx1,idx2;

	idx1=0;
	idx2=(len+1)/2;
	while (idx2<len) {
		tmp1=values[idx1];
		tmp2=values[idx2];
		if (tmp1>tmp2) {
			values[idx1]=tmp2;
			values[idx2]=tmp1;
		}
		idx1++;
		idx2++;
	}
}

static void bitonic_merge(uint32_t *values,int len)
{
	uint32_t tmp1,tmp2;
	int idx1,idx2;

	idx1=(len/2)-1;
	idx2=(len+1)/2;
	while (idx2<len) {
		tmp1=values[idx1];
		tmp2=values[idx2];
		if ( tmp1>tmp2 ) {
			values[idx1]=tmp2;
			values[idx2]=tmp1;
		}
		idx1--;
		idx2++;
	}
}

static void bitonic_sort(uint32_t *values,int len)
{
	if (len<2)
		return;

	/*
		split bitonic sequenc into two halfes.
		1st half is guaranteed to be smaller than 2nd half.
	*/
	bitonic_split(values,len);
	/* two elements will be sorted now, so stop */
	if (len<3)
		return;

	if ((len&1)==0) {
		/*
			if we have an even number of elements,
			just split into two halves.
		*/
		bitonic_sort(values,len/2);
		bitonic_sort(values+(len/2),len/2);
		return;
	}

	/* odd number of elements: */
	{
		/* have to decide where to put the middle element */
		uint32_t el;
		int first;
		len=len/2;
		/* value of middle element */
		el=values[len];
		/* assume middle element belongs to 1st half */
		first=1;
		/* check if middle element cannot be in 1st half */
		if ( el>values[0] && el>values[len-1] ) {
			first=0;
		}
		bitonic_sort(values,len+first);
		bitonic_sort(values+(len+first),len+(1-first));
	}
}

static void bitonic_build(uint32_t *values,int len)
{
	if (len<2)
		return;
	if (len<4) {
		/* 2 and 3 elements are ALWAYS bitonic, so just sort */
		bitonic_sort(values,len);
		return;
	}
	/* build 1st half sorted ascending */
	bitonic_build(values,(len+1)/2);
	/* build 2nd half sorted ascending */
	bitonic_build(values+((len+1)/2),len/2);

	/* merge two halves into two bitonic sequences, */
	/* where 1st seq. is guaranteed to be smaller than 2nd seq */
	bitonic_merge(values,len);

	/* if we have an odd number of elements and we add */
	/* the middle element to the upper half, this still */
	/* will work. */
	bitonic_sort(values,len/2);
	bitonic_sort(values+(len/2),(len+1)/2);
}

static void create_random_lfsr(uint32_t *arr,int len)
{
	static uint32_t gen_cur=0x72233445;
	uint32_t cmp;
	uint32_t v;
	int i;

	switch(count&0x3) {
	case 0:
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
		break;
	case 1:
		v=0;
		cmp=0xFFFF0000/len;
		cmp*=7;
		for(i=0;i<len;i++)
		{
			arr[i]=v;
			v+=cmp;
		}
		break;
	case 2:
		v=0xFFFFFFFF;
		cmp=0xFFFF0000/len;
		cmp*=3;
		for(i=0;i<len;i++)
		{
			arr[i]=v;
			v-=cmp;
		}
		break;
	default:
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
			arr[i]=(cmp&0xF000F)<<12;
		}
		gen_cur=cmp;
		break;
	}
}

#define SIM_SCGC6   (*((volatile unsigned int *)(0x4004803C)))
#define PIT_MCR     (*((volatile unsigned int *)(0x40037000)))
#define PIT_LDVAL0  (*((volatile unsigned int *)(0x40037100)))
#define PIT_TCTRL0  (*((volatile unsigned int *)(0x40037108)))

int main(void)
{
	unsigned int r1,r2;
	volatile unsigned int *cval = ((volatile unsigned int *)(0x40037104));

	/* Enable clock for PIT */
	r1 = SIM_SCGC6;
	r1 |= 0x00800000;
	SIM_SCGC6 = r1;

	/* Enable PIT module */
	PIT_MCR = 0x0;

	/* Reload value for PIT Timer 0 */
	PIT_LDVAL0 = 0xFFFFFFFF;

	/* Now start timer */
	PIT_TCTRL0 = 0x1;

	/* Enable access to ITM trace */
	ITM_ENABLE_ACCESS;
	ITM_TRACE_PRIV=0;
	ITM_TRACE_ENABLE=0xFFFFFFFF;

	while (count>0) {
		create_random_lfsr(array,array_size);
		r1  = *cval;
		ITM_TRACE_D32(1,r1);
		bubblesort(array,array_size);
		r1  = *cval;
		ITM_TRACE_D32(1,r1);
		ITM_TRACE_D8(2,1);

		create_random_lfsr(array,array_size);
		r1  = *cval;
		ITM_TRACE_D32(1,r1);
		quicksort(array,array_size);
		r1  = *cval;
		ITM_TRACE_D32(1,r1);
		ITM_TRACE_D8(2,2);

		create_random_lfsr(array,array_size);
		r1  = *cval;
		ITM_TRACE_D32(1,r1);
		heapsort(array,array_size);
		r1  = *cval;
		ITM_TRACE_D32(1,r1);
		ITM_TRACE_D8(2,3);

		create_random_lfsr(array,array_size);
		r1  = *cval;
		ITM_TRACE_D32(1,r1);
		shellsort(array,array_size);
		r1  = *cval;
		ITM_TRACE_D32(1,r1);
		ITM_TRACE_D8(2,4);

		create_random_lfsr(array,array_size);
		r1  = *cval;
		ITM_TRACE_D32(1,r1);
		merge_sort(array,array_size);
		r1  = *cval;
		ITM_TRACE_D32(1,r1);
		ITM_TRACE_D8(2,5);

		create_random_lfsr(array,array_size);
		r1  = *cval;
		ITM_TRACE_D32(1,r1);
		merge_sort2(array,array_size);
		r1  = *cval;
		ITM_TRACE_D32(1,r1);
		ITM_TRACE_D8(2,6);

		create_random_lfsr(array,array_size);
		r1  = *cval;
		ITM_TRACE_D32(1,r1);
		isort(array,array_size);
		r1  = *cval;
		ITM_TRACE_D32(1,r1);
		ITM_TRACE_D8(2,7);

		create_random_lfsr(array,array_size);
		r1  = *cval;
		ITM_TRACE_D32(1,r1);
		selsort(array,array_size);
		r1  = *cval;
		ITM_TRACE_D32(1,r1);
		ITM_TRACE_D8(2,8);

		create_random_lfsr(array,array_size);
		r1  = *cval;
		ITM_TRACE_D32(1,r1);
		rdxsort(array,array_size);
		r1  = *cval;
		ITM_TRACE_D32(1,r1);
		ITM_TRACE_D8(2,9);

		create_random_lfsr(array,array_size);
		r1  = *cval;
		ITM_TRACE_D32(1,r1);
		rdxsort2(array,array_size);
		r1  = *cval;
		ITM_TRACE_D32(1,r1);
		ITM_TRACE_D8(2,10);

		create_random_lfsr(array,array_size);
		r1  = *cval;
		ITM_TRACE_D32(1,r1);
		bitonic_build(array,array_size);
		r1  = *cval;
		ITM_TRACE_D32(1,r1);
		ITM_TRACE_D8(2,11);

		count--;
	}
}

