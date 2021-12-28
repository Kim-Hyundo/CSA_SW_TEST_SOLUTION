#include <stddef.h>
#include <math.h>

enum { FALSE = 0, TRUE = 1 };

const char cstr1[] = "Constant String1";
char defaultstring[] = "test";
static int mstatic1, mstatic2, mcount = 0;
static int period = 1000;
signed short int  plot1 = -15000;

typedef int tdef1;
tdef1 vtdef1;

typedef short tdef2[10];
tdef2 vtdef2;

struct vstruct1_s {
	int x, y;
}
vstruct1;

char vchar;
short vshort;
int vint = 1;
long vlong;

char * vpchar;
short * vpshort;
int * vpint;
long * vplong;

unsigned char vuchar;
unsigned short vushort;
unsigned int vuint;
unsigned long vulong;

unsigned char * vpuchar;
unsigned short * vpushort;
unsigned int * vpuint;
unsigned long * vpulong;

unsigned char * * vppuchar;
unsigned short * * vppushort;
unsigned int * * vppuint;
unsigned long * * vppulong;

unsigned long * * * vpppulong;
unsigned long * * * * vppppulong;

int varray[10];

typedef int tarray[10];
tarray vtarray;

char vdarray[5];
char vdiarray[] = "abcd";
char vdblarray[5][6];
char vtriplearray[2][3][4];

struct struct4 {
	struct struct5 * pstruct5;
	struct struct5 * * ppstruct5;
	struct struct5 * pastruct5[2];
};

struct struct5 {
	struct struct4 * pstruct4;
	struct struct4 * * ppstruct4;
	struct struct4 * pastruct4[2];
};


typedef struct struct1 {
	const char * word;
	int count;
	struct struct1 * left;
	struct struct1 * right;
	int field1:2;
	unsigned field2:3;
} strtype1 ;

strtype1 ast;
strtype1 pLinkedListBuf[5];

typedef struct struct1 structarray[10];

structarray stra1;

struct struct4 stra2[5][5];

struct union1 {
	char * word;
	int count;
	struct struct1 * left;
	struct struct1 * right;
	union {
		int ival;
		float fval;
		char * pval;
	} uval;
	int field1:2;
	unsigned field2:3;
} aun;

struct struct2 {
	char * word;
	int count;
	char name[10];
} str2;

struct struct6 {
	int x;
	struct struct7 {
		char * word;
		int count;
	} vstruct7;
	int y;
} str6;


struct abc {
	int x;
	int y;
};

struct abc def;

union tunion {
	int z1;
	short z2;
	char z3;
	struct abc z4;
} vunion;

enum enumtyp { enum1, enum2, enum4=4, enum7=7, enum8, enumx= -1 } enumvar;

int ( *funcptr ) (void);

void func0(void)					/* empty function */
{
}

static int func3(void)			/* simple function */
{
	return 5;
}

struct struct1 func4( struct struct1 str )		/* function returning struct */
{
	str.count++;

	return str;
}

int func5( int a, char b, long c )			/* multiple arguments */
{
	return a+b*c;
}

struct struct1 func27( short x1, short x2 )		/* function returning struct */
{
	ast.count = x1*x2;

	return ast;
}

static int test_cond_instr( int arg1, int arg2 )		/* function with conditional (non-branch) instructions */
{
	int result;
	/* For - ARM Mode - OR - ThumbII - force conditional instructions */
#if defined(__arm__)&&(!defined(__thumb__)||(defined(__thumb__)&&__ARM_ARCH==7)||(defined(__thumb__)&&__ARM_ARCH==8&&!__ARM_ARCH_8M_BASE__))
	__asm__ (
		"subs  %[arg2],%[arg1],%[arg2] \n\t"
		"ittte  ne                     \n\t"
		"mulne %[arg2],%[arg1],%[arg2] \n\t"
		"addne %[arg2],%[arg2],#42     \n\t"
		"asrne %[result],%[arg2],#1    \n\t"
		"moveq %[result],#0            \n\t"
		: [result] "=r" (result) : [arg1] "r" (arg1), [arg2] "r" (arg2)
	);
#else
	arg2 = arg1 - arg2;
	if (arg2){
		arg2 = arg2 * arg1;
		arg2 = arg2 + 42;
		result = arg2 >> 1;
	} else {
		result = 0;
	}
#endif
	return result;
}

int int_sin(unsigned int x)
{
	int sign=1;
	if (x&0x20)
		sign=-1;
	x=x&0x1f;
	if ((x&0x10)&&(x&0xf))
		x=0x10-(x&0xf);

	// sin(x) -Pi/2 <= x <= Pi/2 = x-x^3/3!+x^5/5!-...
	return sign*((120*10*10*10*10*x - (20*10*10*x*x*x) + (x*x*x*x*x))>>9);
}

static short sinewave[630];

void func_sin()
{
	int x;
	
	for (x = 0; x < 628; x++) 
		sinewave[x] = int_sin(x)/(x/32+1);
}

void init_linked_list(void)
{
	int i = 0;
	const int last = sizeof(pLinkedListBuf) / sizeof(pLinkedListBuf[0]) - 1;
	static const char* text[] = {"Mon", "Tue", "Wed", "Thr", "Fri", "Sat", "Sun"};

	ast.left = pLinkedListBuf;
	ast.right = NULL;
	ast.count = 0;
	ast.word = NULL;

	for (i = 0; i <= last; i++) {
		pLinkedListBuf[i].left  = (i==last) ? NULL : &pLinkedListBuf[i+1]; /* next element */
		pLinkedListBuf[i].right =    (i==0) ? &ast : &pLinkedListBuf[i-1]; /* previous element */
		pLinkedListBuf[i].count = i;
		pLinkedListBuf[i].word  = text[i % 7];
	}
}

struct shortrecord
{
	short x;
	short y;
};

struct shortrecord vshortrecord;

struct shortrecord func28( struct shortrecord x )
{
	x.x++;
	x.y = (short) (x.x+1);
	return x;
}

static int sieve(void);

void (*monHook)(void) __attribute__ ((section (".data"))) = 0;
extern void (*watchdogTrigger)(void);

int main(void)
{
	short int  inc, sign;
	
	func_sin();
	
	do {
		if (monHook)
			monHook();
		if (watchdogTrigger)
			watchdogTrigger();

		mstatic1 = 12;
		mstatic2 = 34;
		mcount++;

		inc  = (4 * 15000) / period;
		sign = ( (mcount % period) >= period/2 ) ?  -1 : +1;
		plot1 = plot1 + sign * inc;

		vtriplearray[0][0][0] = 1;
		vtriplearray[1][0][0] = 2;
		vtriplearray[0][1][0] = 3;
		vtriplearray[0][0][1] = 4;

		funcptr = (int (*) ()) 0;
		funcptr = func3;

		init_linked_list();
		ast.count = 12345;
		ast.field1 = 1 + mstatic2;
		ast.field2 = 2;

		ast = func4(ast);

		enumvar = enumx;

		vshortrecord = func28(vshortrecord);


		sieve();

		mstatic1 = test_cond_instr( 14, 14 ); /* returns 0 */
		mstatic2 = test_cond_instr( 78, 55 ); /* returns 918 */

	} while (vint);

	return 0;
}


#define SIZE 18
char flags[SIZE+1];

static int sieve(void)			/* sieve of erathostenes */
{
	register int    i, prime, k;
	int             count;

	count = 0;

	for ( i = 0 ; i <= SIZE ; flags[ i++ ] = TRUE ) ;

	for (i = 0; i <= SIZE; i++) {
		if (flags[i]) {
			prime = i + i + 3;
			k = i + prime;
			while (k <= SIZE) {
				flags[k] = FALSE;
				k += prime;
			}
			count++;
		}
	}

	return count;
}


int __attribute__ ((naked)) background(void)		/* job for background-demo - doesn't use stack*/
{
	static long int bcnt1, bcnt2;

	bcnt1 = bcnt2 = 0;

	while (1) {
		bcnt1 = 10000000;
		while (bcnt1>0)
			bcnt1--;
		bcnt2++;
	}

	return 0;
}


