
#define TRUE 1
#define FALSE 0
#define SIZE 18

#define STM_BASE 0x54000000
int abcd, channel;
// Address space 0
#define STP_TRACE0_D8(_channel_,_data_) {*((volatile unsigned char *) (STM_BASE + 0x1000 * _channel_)) = _data_;}
#define STP_TRACE0_D8TS(_channel_,_data_) {*((volatile unsigned char *) (STM_BASE + 0x800 + 0x1000 * _channel_)) = _data_;}
#define STP_TRACE0_D16(_channel_,_data_) {*((volatile unsigned short *) (STM_BASE + 0x1000 * _channel_)) = _data_;}
#define STP_TRACE0_D16TS(_channel_,_data_) {*((volatile unsigned short *) (STM_BASE + 0x800 + 0x1000 * _channel_)) = _data_;}
#define STP_TRACE0_D32(_channel_,_data_) {*((volatile unsigned int *) (STM_BASE + 0x1000 * _channel_)) = _data_;}
#define STP_TRACE0_D32TS(_channel_,_data_) {*((volatile unsigned int *) (STM_BASE + 0x800 + 0x1000 * _channel_)) = _data_;}

// Address space 1
#define STP_TRACE1_D8(_channel_,_data_) {*((volatile unsigned char *) (STM_BASE + 0x400 * _channel_)) = _data_;}
#define STP_TRACE1_D8TS(_channel_,_data_) {*((volatile unsigned char *) (STM_BASE + 0x200 + 0x400 * _channel_)) = _data_;}
#define STP_TRACE1_D16(_channel_,_data_) {*((volatile unsigned short *) (STM_BASE + 0x400 * _channel_)) = _data_;}
#define STP_TRACE1_D16TS(_channel_,_data_) {*((volatile unsigned short *) (STM_BASE + 0x200 + 0x400 * _channel_)) = _data_;}
#define STP_TRACE1_D32(_channel_,_data_) {*((volatile unsigned int *) (STM_BASE + 0x400 * _channel_)) = _data_;}
#define STP_TRACE1_D32TS(_channel_,_data_) {*((volatile unsigned int *) (STM_BASE + 0x200 + 0x400 * _channel_)) = _data_;}



const char cstr1[] = "Constant String1";

static int mstatic1;

typedef int tdef1;

tdef1 vtdef1;

typedef short tdef2[10];

tdef2 vtdef2;

struct
{
	int x, y;
}
vstruct1;

char vchar;
short vshort;
int vint;
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

char vtripplearray[2][3][4];

struct struct4 {
		struct struct5 * pstruct5;
		struct struct5 * * ppstruct5;
		struct struct5 * pastruct5[2];
		} ;

struct struct5 {
		struct struct4 * pstruct4;
		struct struct4 * * ppstruct4;
		struct struct4 * pastruct4[2];
		} ;


typedef struct struct1 {
	char * word;
	int count;
	struct struct1 * left;
	struct struct1 * right;
	int field1:2;
	unsigned field2:3;
	} strtype1 ;

strtype1 ast;

typedef struct struct1 structarray[10];

structarray stra1;

struct struct4 stra2[5][5];


int ( *funcptr ) ();


static void func1(int * intptr )		/* static function */
{
	(*intptr)++;
}


void func2()
{
	int autovar;
	register int regvar;
	static int fstatic = 44;	/* initialized static variable */
	static int fstatic2;		/* not initialized static variable */

	autovar = regvar = fstatic;
	autovar++;

	func1( &autovar );	/* to force autovar as stack-scope */

	func1( &fstatic );	/* to force fstatic as static-scope */

	for ( regvar = 0; regvar < 5 ; regvar++ )
		mstatic1 += regvar*autovar;

	fstatic += mstatic1;

	fstatic2 = 2*fstatic;

	func1( &fstatic2 );
}

void func2a()
{
	auto char autovar;	/* char stack variable */
	register char regvar;	/* char register variable */

	autovar = regvar = mstatic1;
	autovar++;

	for ( regvar = 0; regvar < (char) 5 ; regvar++ )
		vchar += regvar*autovar;
}

void func2b()
{
	auto long autovar;	/* long stack variable */
	register long regvar;	/* long register variable */

	autovar = regvar = mstatic1;
	autovar++;

	for ( regvar = 0; regvar < 5l ; regvar++ )
		vlong += regvar*autovar;
}

void func2c()
{
	auto int autovar;
	register int regvar;

	autovar = regvar = (int) mstatic1;
	autovar++;

	for ( regvar = 0.0; regvar < 5.0 ; regvar += 1.0 )
		vlong += regvar*autovar;
}

void func2d()
{
	auto short autovar;	/* short stack variable */
	register short regvar;	/* short register variable */

	autovar = regvar = mstatic1;
	autovar++;

	for ( regvar = 0; regvar < 5l ; regvar++ )
		vlong += regvar*autovar;
}


static int func3()			/* simple function */
{
	return 5;
}

struct struct1 func4(struct struct1 str )		/* function returning struct */
{
	str.count++;

	return str;
}

int func5(int a, char b, long c )			/* multiple arguments */
{
	return a+b*c;
}


func10()
{
	register int i, j;
	register int v1, v2, v3, v4, v5, v6, v7, v8;
	register int v9, v10, v11, v12, v13, v14, v15, v16, v17;

	v17 = 0;
	for ( i = 0 ; i < 3 ; i++ )
		v17 += i;

	for ( v1 = 0 ; v1 < 3 ; v1++ )
		v17 += v1;
	for ( v2 = 0 ; v2 < 3 ; v2++ )
		v17 += v2;
	for ( v3 = 0 ; v3 < 3 ; v3++ )
		v17 += v3;
	for ( v4 = 0 ; v4 < 3 ; v4++ )
		v17 += v4;
	for ( v5 = 0 ; v5 < 3 ; v5++ )
		v17 += v5;
	for ( v6 = 0 ; v6 < 3 ; v6++ )
		v17 += v6;
	for ( v7 = 0 ; v7 < 3 ; v7++ )
		v17 += v7;
	for ( v8 = 0 ; v8 < 3 ; v8++ )
		v17 += v8;
	for ( v9 = 0 ; v9 < 3 ; v9++ )
		v17 += v9;
	for ( v10 = 0 ; v10 < 3 ; v10++ )
		v17 += v10;
	for ( v11 = 0 ; v11 < 3 ; v11++ )
		v17 += v11;
	for ( v12 = 0 ; v12 < 3 ; v12++ )
		v17 += v12;
	for ( v13 = 0 ; v13 < 3 ; v13++ )
		v17 += v13;
	for ( v14 = 0 ; v14 < 3 ; v14++ )
		v17 += v14;
	for ( v15 = 0 ; v15 < 3 ; v15++ )
		v17 += v15;
	for ( v16 = 0 ; v16 < 3 ; v16++ )
		v17 += v16;

	i = j = v17;

	for ( v1 = 0 ; v1 < 3 ; v1++ )
		v17 += v1;
	for ( v2 = 0 ; v2 < 3 ; v2++ )
		v17 += v2;
	for ( v3 = 0 ; v3 < 3 ; v3++ )
		v17 += v3;
	for ( v4 = 0 ; v4 < 3 ; v4++ )
		v17 += v4;
	for ( v5 = 0 ; v5 < 3 ; v5++ )
		v17 += v5;
	for ( v6 = 0 ; v6 < 3 ; v6++ )
		v17 += v6;
	for ( v7 = 0 ; v7 < 3 ; v7++ )
		v17 += v7;
	for ( v8 = 0 ; v8 < 3 ; v8++ )
		v17 += v8;
	for ( v9 = 0 ; v9 < 3 ; v9++ )
		v17 += v9;
	for ( v10 = 0 ; v10 < 3 ; v10++ )
		v17 += v10;
	for ( v11 = 0 ; v11 < 3 ; v11++ )
		v17 += v11;
	for ( v12 = 0 ; v12 < 3 ; v12++ )
		v17 += v12;
	for ( v13 = 0 ; v13 < 3 ; v13++ )
		v17 += v13;
	for ( v14 = 0 ; v14 < 3 ; v14++ )
		v17 += v14;
	for ( v15 = 0 ; v15 < 3 ; v15++ )
		v17 += v15;
	for ( v16 = 0 ; v16 < 3 ; v16++ )
		v17 += v16;

	return v17;
}


int func11( int x )				/* multiple returns */
{
	switch ( x )
	{
	case 1:
		x = x+1;
		x = x*2;
		return x*x;
	case 2:
		return x+x;
	case 3:
		return x-x;
	case 4:
		x = x+1;
		x = x*2;
		return x*x;
	case 5:
		break;
	case 6:
		return x+x;
	default:
		break;
	}
	return x;
}


int func13( int a, int c, int e )			/* arguments and locals stack-tracking */
{
	int b, d, f;

	b = a+c+e;
	f = b+a;
	d = f*b;

	if ( e > 0 )
		c += func13( b, f, e-1 );

	return c+e+d;
}

int func14( char x1 )		/* Parameter: 1 Byte */
{
	return 2*x1;
}

int func15( short x1 )		/* Parameter: 1 Word */
{
	return 2*x1;
}

int func16( long x1 )		/* Parameter: 1 Long */
{
	return (int) (2*x1);
}

int func17( short x1, short x2 )		/* Parameter: 2 Short */
{
	return x1*x2;
}

int func18(short x1, long x2 )		/* Parameter: Short,Long */
{
	return x1*x2;
}



int sieve(void);

main()
{
	int j;
	
	abcd = 0;

	while ( TRUE )
	{
		vtripplearray[0][0][0] = 1;
		vtripplearray[1][0][0] = 2;
		vtripplearray[0][1][0] = 3;
		vtripplearray[0][0][1] = 4;
	
		func2();
	
		func2a();
	
		func2b();
	
		func2d();
	
		funcptr = func3;
	
		ast.count = 12345;
		ast.left = &ast;
		ast.field1 = 1;
		ast.field2 = 2;
	
		ast = func4( ast );
	
		j = (*funcptr)();
	

start:
		j = func5( (int) j, (char) 2, (long) 3 );
	
		if ( j == 0 )
			goto start;		
	
		sieve();
	}
}


char flags[SIZE+1];

int sieve(void)          /* sieve of erathostenes */
{
	register int i, primz, k;
	int anzahl;
	
	anzahl = 0;

	for ( i = 0 ; i <= SIZE ; flags[ i++ ] = TRUE ) ;

	for ( i = 0 ; i <= SIZE ; i++ )
	{
		if ( flags[ i ] )
		{
			primz = i + i + 3;
			k = i + primz;
			while ( k <= SIZE )
			{
				flags[ k ] = FALSE;
				k += primz;
			}
			anzahl++;
			abcd++;
			channel = (abcd >> 4) & 0xf;
			
			//channel = 2;
			//if (abcd < 10)
			{
				STP_TRACE0_D16(channel,primz);
				STP_TRACE0_D16TS(channel, primz);
			}
		}
	}

	return anzahl;
}

int background()			/* job for background-demo */
{
	register long count1, count2;

	count1 = count2 = 0;

	while ( TRUE )
	{
		while ( ++count1 ) ;
		count2++;
	}

	return TRUE;
}




void task2()
{
	while ( TRUE )
	{
		func10();
	
		func11( 5 );
	
		func13( 1, 2, 3 );
		
		func14( (char) 55 );
	
		func15( (short) 55 );
	
		func16( (long) 55 );
	
		func17( (short) 44, (short) 55 );
	
		func18( (short) 44, (long) 55 );
	}
}
