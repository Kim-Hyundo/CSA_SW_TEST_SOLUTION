
#include "stddef.h"
#include "math.h"


#define TRUE 1
#define FALSE 0
#define SIZE 18

const char cstr1[] = "Constant String1";
char defaultstring[] = "test";

static int mstatic1, mstatic2, mcount;

#ifdef FLOATING_POINT

float vfloat = 1.0;
double vdouble = 1.0;
double vdouble2;

#endif

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


struct abc
{
	int x;
	int y;
};

struct abc def;

union tunion
{
	int z1;
	short z2;
	char z3;
	struct abc z4;
} vunion;

enum enumtyp { enum1, enum2, enum4=4, enum7=7, enum8, enumx= -1 } enumvar;

int ( *funcptr ) ();

typedef int (*fp)();

fp fpa[10];
int (*fpb[10])();


#ifdef C_PLUS_PLUS

/* C++ specific stuff */

int & refvar = vint;

class X1 {
public:
	int i;
};

class X2 {
public:
	int i;
};

class X12: public X1, public X2
{
	int j;
} x12;


class A
{
public:
	int i,j;
	void foo(int,char * = defaultstring );
	virtual void vfun(char);
	virtual int vfun2(int);
	virtual int vfun3(int);
	int operator+(int);
	static int c;
	int a;
private:
	static int bar(int = 3);
	char * p;
} a;


int (A::*vfptr)( int ) = &A::vfun2;
int (A::*vfptr2)( int ) = &A::vfun3;


class B
{
	int a;
	friend int func33();
};


class D
{
public:
	int index;
	int index2;
} d;

class C: public A, virtual public B
{
public:
	C();
	~C();
	int intmember;

protected:
	char buffer[100];
	virtual void vfun(char);
	friend class D;
	class B * PB;
};

class C varc;

C::C()
{
	intmember = 0;
}

C::~C()
{
}

void C::vfun( char ch )
{
	mstatic1 = ch;
}


class F: virtual public A
{
public:
	int fmember;
};

class E: public C, public D
{
public:
	int emember;
};


class G: public C, public F
{
public:
	int gmember;
};


class H
{
public:
	H() : refmember(mstatic2)
	{
		intmember = 1;
		ptrmember = &mstatic1;
	}
	H & operator=(H & source)
	{
	    return source;
	}
	int intmember;
	int * ptrmember;
	int & refmember;
};



void A::vfun(char x)
{
	mstatic1 = x;
}

int A::vfun2(int x)
{
	return x;
}

int A::vfun3(int x)
{
	return -x;
}

int cpp_func2()
{
	int D::*PTDM = &D::index;
	H * ph = new H;
	H h2;

	D * dp = new D;

	D & dobj = *dp;

	dobj.*PTDM = 1;

	PTDM = &D::index2;

	dobj.*PTDM = 2;

	h2 = *ph;

	delete dp;
	delete ph;

	return 0;
}


class protection
{
	int nonprot;
protected:
	int prot;
public:
	int pub;
	int putc1();
	int putc3( int a, int b, int c ) {
		return (mstatic1 = a+b+c);
	};
};

static protection prot;

class Tree;

class Forest {
	int tree_branches;
public:
	int get_branches( Tree *);
};

class Tree {
	int branch_cnt;
	friend int count_branches( Tree *);
	friend int Forest::get_branches( Tree *);
	static int static_member;

public:
	int branch_public;
	void set_branch( int n );
	void set_branch_impl( int n );
	int get_branch_const() const {	// Const Method
		return branch_cnt;
	};
	int get_branch_vol() volatile {	// Volatile Method
		return branch_cnt;
	};
	static int get_branch_static();	// Static Method

	Tree &operator++();		// Operation, no arguments

	Tree &operator+(int);
	Tree &operator+(Tree &);

	operator int () { return branch_cnt; };

	Tree(int = 10);			// Constructor
	~Tree() {			// Destructor
		branch_cnt = 0;
	};

	int Tree::*mptr;

protected:
	int branch_prot;
};


Tree vtree;
int Tree::*TreeMPtr = &Tree::branch_public;
void (Tree::*TreeMFPtr) ( int ) = &Tree::set_branch;


class Wood : private Tree {
public:
	Wood() : Tree( 7 ) { woodmember = 0; };
	int get_branch_derived() {
		return branch_prot+woodmember;
	};
	int woodmember;
};

int count_branches( Tree * tp ) {		/* Friend function */
	return tp->branch_cnt;
}


int Forest::get_branches( Tree * tp ) {		/* Friend function  */
	tree_branches = tp->branch_cnt;
	return 1;
}


Tree::Tree( int cnt )				/* Constructor */
{
	branch_cnt = cnt;
}

void Tree::set_branch( int n )			/* using this */
{
	this->branch_cnt = n;
}

void Tree::set_branch_impl( int n )		/* implizit use of this */
{
	branch_cnt = n;
}

int Tree::get_branch_static()
{
	return mstatic2;
}

Tree & Tree::operator++()
{
	branch_cnt++;
	return *this;
}

Tree & Tree::operator+( int n )
{
	branch_cnt += n;
	return *this;
}

Tree & Tree::operator+( Tree & t2)
{
	branch_cnt += t2.branch_cnt;
	return *this;
}


class vclass1 {
public:
	virtual void func_vclass() {
		mstatic1 = 1;
	};
	int member_vclass;
};

class vclass2 : public vclass1 {
public:
	virtual void func_vclass() {
		mstatic1 = 2;
	};
	int member_vclass;
};

class aclass1 {
public:
	virtual void func_aclass() = 0;
	virtual int func_test(int) = 0;
	int member_aclass;
};

class aclass2 : public aclass1 {
public:
	virtual int func_test(int x) {
		return (mstatic2 = 2*x);
	};
	virtual void func_aclass() {
		mstatic1 = 3;
	};
} ac2;



void cpp_func1()
{
	int x;
	class Tree * tptr;
	class Wood * wptr;
	class vclass1 * vclassp1;
	class vclass2 * vclassp2;
	class aclass2 * aclassp;

	mstatic2 = ac2.func_test(mstatic1);

	class Tree object( 0 );

	object.set_branch( 4 );		/* Method call via . */

	mstatic2 = object.get_branch_vol();

	object.*TreeMPtr = 4;

	(object.*TreeMFPtr)( 5 );	/* Method call via .* */

	tptr = new Tree( 2 );

	tptr->set_branch( 55 );		/* Method call via -> */

	tptr->*TreeMPtr = 4;

	(tptr->*TreeMFPtr)( 5 );	/* Method call via ->* */

	x = int (*tptr);

	x += object.get_branch_const();

	wptr = new Wood();
	x += wptr->get_branch_derived();

	vclassp1 = new vclass1;
	vclassp2 = new vclass2;

	vclassp1->func_vclass();	/* Virtual Method call */
	vclassp2->func_vclass();

	delete vclassp1;

	vclassp1 = vclassp2;
	vclassp1->func_vclass();

	aclassp = new aclass2;
	aclassp->func_aclass();

	vfptr = &A::vfun2;

	mstatic1 = (a.*vfptr)(1);	/* Virtual Method via .* */

	mstatic1 = aclassp->func_test(mstatic1);

	mstatic2 = x+prot.putc3( 1, 2, 3 );

	delete tptr;
	delete wptr;
	delete vclassp1;
	delete aclassp;
}


class nesta
{
private:
	int a, b, c;
public:
	int i;
	void set(int x,int y) {
		a = x;
		b = y;
		c = x+y;
	};
};


class nestb
{
public:
	int b, c, d, f;
};

class nestc
{
public:
	int g, h;
};

class nestd : virtual public nesta, virtual public nestb, virtual public nestc
{
public:
	int c, d, e;
};

static class nestd nestdvar;


class neste : public nesta, public nestb, public nestc
{
public:
	int c, d, e;
};

static class neste nestevar;


class nestf : private nesta, private nestb, private nestc
{
public:
	int c, d, e;
};

static class nestf nestfvar;

class nestg : private neste, private nestf
{
public:
	int c, d, e;
};

static class nestg nestgvar;


int cpp_func3()
{
	nestdvar.c = 1;
	nestdvar.d = 2;
	nestdvar.e = 3;
	nestdvar.f = 4;
	nestdvar.g = 5;
	nestdvar.i = 6;

	nestdvar.nestb::c = 7;

	nestdvar.set( 1, 2 );

	nestevar.c = 1;
	nestevar.d = 2;
	nestevar.e = 3;
	nestevar.f = 4;
	nestevar.g = 5;
	nestevar.i = 6;

	nestfvar.c = 1;

	nestgvar.c = 1;
	nestgvar.d = 2;
	nestgvar.e = 3;

	return nestgvar.c+nestdvar.c+nestevar.c+nestfvar.c;
}


int x;

class enclose {
public:
	int x;

	class inner {
		int ix;

		void f(int i) {
			::x = i;
		}
	public:
		int ip;
		void fp(int i) {
			f(i+1);
			::x = i;
		}
	} ivar;
};


class enclose evar;


class ops : public X1
{
public:
	int j;

	void * operator new(size_t);
	void operator delete(void *);

	ops & operator=(ops &);

	ops & operator-(void);	/* unary operators */
	ops & operator+(void);
	ops & operator++(void);
	ops & operator--(void);
	ops & operator~(void);
	ops & operator!(void);
	void * operator&(void);

	int operator!=(int);
	int operator==(int);
	int operator>(int);
	int operator>=(int);
	int operator<(int);
	int operator<=(int);

	int operator+(int);
	int operator+=(int);
	int operator-(int);
	int operator-=(int);
	int operator*(int);
	int operator*=(int);
	int operator/(int);
	int operator/=(int);
	int operator%(int);
	int operator%=(int);
	int operator&(int);
	int operator&=(int);
	int operator|(int);
	int operator|=(int);
	int operator^(int);
	int operator^=(int);
	int operator<<(int);
	int operator<<=(int);
	int operator>>(int);
	int operator>>=(int);

	int operator,(int);
	int operator[](int);

	int operator()(int);
	int operator*(void);
	ops * operator->(void);

	int operator->*(int);
	int operator&&(int);
	int operator||(int);

} vops;

ops & ops::operator=(ops & x) {
	return x;
}

int ops::operator!=(int x) {
	return i+j+x;
}

int ops::operator==(int x) {
	return i+j+x;
}

int ops::operator>(int x) {
	return i+j+x;
}

int ops::operator>=(int x) {
	return i+j+x;
}

int ops::operator<(int x) {
	return i+j+x;
}

int ops::operator<=(int x) {
	return i+j+x;
}

int ops::operator+(int x) {
	return i+j+x;
}

int ops::operator+=(int x) {
	return i+j+x;
}

int ops::operator-(int x) {
	return i+j-x;
}

int ops::operator-=(int x) {
	return i+j-x;
}

int ops::operator*(int x) {
	return i+j*x;
}

int ops::operator*=(int x) {
	return i+j*x;
}

int ops::operator/(int x) {
	return i+j/x;
}

int ops::operator/=(int x) {
	return i+j/x;
}

int ops::operator%(int x) {
	return i+j%x;
}

int ops::operator%=(int x) {
	return i+j%x;
}

int ops::operator&(int x) {
	return i+j/x;
}

int ops::operator&=(int x) {
	return i+j/x;
}

int ops::operator^(int x) {
	return i+j^x;
}

int ops::operator^=(int x) {
	return i+j^x;
}

int ops::operator|(int x) {
	return i+j|x;
}

int ops::operator|=(int x) {
	return i+j|x;
}

int ops::operator&&(int x) {
	return i+j&&x;
}

int ops::operator||(int x) {
	return i+j||x;
}

ops & ops::operator!(void) {
	return *this;
}

ops & ops::operator~(void) {
	return *this;
}

ops & ops::operator+(void) {
	return *this;
}

ops & ops::operator-(void) {
	return *this;
}

ops & ops::operator++(void) {
	return *this;
}

ops & ops::operator--(void) {
	return *this;
}

void * ops::operator&() {
	return &vpchar;
}

int ops::operator[](int x) {
	return i+j||x;
}

int ops::operator,(int x) {
	return i+j||x;
}

int ops::operator()(int x) {
	return i+j||x;
}

int ops::operator<<(int x) {
	return i+j||x;
}

int ops::operator<<=(int x) {
	return i+j||x;
}

int ops::operator>>(int x) {
	return i+j||x;
}

int ops::operator>>=(int x) {
	return i+j||x;
}

ops * ops::operator->() {
	return this;
}

int ops::operator*(void) {
	return i+j||x;
}

int ops::operator->*(int x) {
	return i+j||x;
}



void * ops::operator new( size_t x) {
	mstatic1 = x;
	return vpchar;
}

void ops::operator delete(void *) {
}


void cpp_func4()
{
    evar.ivar.fp(4);

	mstatic1 = vops+4;
	mstatic1 = vops-4;
	mstatic1 = vops*4;
	mstatic1 = vops/4;
}


int cpp_funcargs1( long x = 1, int y = 2, char * p = defaultstring )
{
	vpchar = p;
	return x+y;
}


int cpp_funcargs2( enumtyp e, char * p = 0, int x = 0 )
{
	if ( e == enum1 )
	{
		vpchar = p;
	}
	return x+1;
}


int cpp_funcargs3( int e, char * p = 0, int x = 0 )
{
	if ( e == 0 )
	{
		vpchar = p;
	}
	return x+1;
}


int cpp_funcargs4( int e = 0, char * p = 0u, int x = 0 )
{
	if ( e == 0 )
	{
		vpchar = p;
	}
	return x+1;
}

int cpp_funcargs5( int e = 0, char * p = 0x0, int x = 2 )
{
	if ( e == 0 )
	{
		vpchar = p;
	}
	return x+1;
}


int cpp_funcrefargs( int & x, int & y )
{
	x++;
	y++;
	return x+y;
}


class nestx
{
public:
	int method(int x)
	{
		return 2*x;
	}
	int x;
};

class nestx1 : public nestx
{
public:
	int x1;
};

class nestx2 : public nestx
{
public:
	int x2_1;
	int x2_2;
};

class nestx3 : public nestx
{
public:
	int x3;
};


class nestxv1 : virtual public nestx
{
public:
	int x1;
};

class nestxv2 : virtual public nestx
{
public:
	int x2_1;
	int x2_2;
};

class nestxv3 : virtual public nestx
{
public:
	int x3;
};


class nestxf
{
public:
	virtual int method(int x)
	{
		return 2*x;
	}
	int x;
};

class nestxf1 : public nestxf
{
public:
	virtual int method(int x)
	{
		return 3*x;
	}
	int x1;
};

class nestxf2 : public nestxf
{
public:
	virtual int method(int x)
	{
		return 4*x;
	}
	int x2_1;
	int x2_2;
};

class nestxf3 : public nestxf
{
public:
	int x3;
};


nestx1 vnestx1;
nestx2 vnestx2;
nestx3 vnestx3;

nestxv1 vnestxv1;
nestxv2 vnestxv2;
nestxv3 vnestxv3;

nestxf1 vnestxf1;
nestxf2 vnestxf2;
nestxf3 vnestxf3;

nestx * nestxarray[3];

nestxf * nestxfarray[3];

void cpp_func5()
{
	int i;

	nestxarray[0] = &vnestx1;
	nestxarray[1] = &vnestx2;
	nestxarray[2] = &vnestx3;

	for (i = 0 ; i < 3 ; i++)
	   mstatic1 = nestxarray[i]->method(i);

	nestxarray[0] = &vnestxv1;
	nestxarray[1] = &vnestxv2;
	nestxarray[2] = &vnestxv3;

	for (i = 0 ; i < 3 ; i++)
	   mstatic1 = nestxarray[i]->method(i);

	nestxfarray[0] = &vnestxf1;
	nestxfarray[1] = &vnestxf2;
	nestxfarray[2] = &vnestxf3;

	for (i = 0 ; i < 3 ; i++)
	   mstatic1 = nestxfarray[i]->method(i);
}

#endif


void func0()					/* empty function */
{
}

static void func1( int * intptr )		/* static function */
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

	autovar = regvar = (char) mstatic1;
	autovar++;

	for ( regvar = 0; regvar < (char) 5 ; regvar++ )
		vchar = (char)(vchar+regvar*autovar);
}

void func2b()
{
	auto long autovar;	/* long stack variable */
	register long regvar;	/* long register variable */

	autovar = regvar = mstatic1;
	autovar++;

	for ( regvar = 0; regvar < 5l ; regvar++ )
		vlong += regvar+autovar;
}


#ifdef FLOATING_POINT

void func2c()
{
	auto double autovar;	/* double stack variable */
	register double regvar;	/* double register variable */

	autovar = regvar = (double) mstatic1;
	autovar++;

	for ( regvar = 0.0; regvar < 5.0 ; regvar += 1.0 )
		vdouble += regvar*autovar;
}

#endif


static int func3()			/* simple function */
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
	return a+b+c;
}


#ifdef FLOATING_POINT

float func6( float a, float b )
{
	vfloat = 1.0;
	vfloat = -1.0;
	vfloat = 10.0;
	vfloat = (float) 1.6;

	return a*b;
}

double func7( double a, double b )
{
	vdouble = 1.0;
	vdouble = -1.0;
	vdouble = 10.0;
	vdouble = 1.6;

	return a*b;
}

#endif

struct bfield
{
	int a:1;
	int b:2;
	int c:3;
	int d:7;
	int e:8;
	int f:15;
	int g:1;
	int h:15;
	int i:1;
	int j:16;
	unsigned k:1;
	unsigned l:2;
	unsigned m:16;
	long n;
	char o;
	int p:15;
	char q:6;
	char r:1;
};

struct bfield vbfield;

void func8()
{
	vbfield.a = 1;
	vbfield.b = 1;
	vbfield.c = 1;
	vbfield.d = 1;
	vbfield.e = 1;
	vbfield.f = 1;
	vbfield.g = 1;
	vbfield.h = 1;
	vbfield.i = 1;
	vbfield.j = 1;
	vbfield.k = 1;
	vbfield.l = 1;
	vbfield.m = 1;
	vbfield.n = 1;
	vbfield.o = 1;
	vbfield.p = 1;
	vbfield.q = 1;
	vbfield.r = 1;

	vbfield.a = -1;
	vbfield.b = -1;
	vbfield.c = -1;
	vbfield.d = -1;
	vbfield.e = -1;
	vbfield.f = -1;
	vbfield.g = -1;
	vbfield.h = -1;
	vbfield.i = -1;
	vbfield.j = -1;
	vbfield.k = 1;
	vbfield.l = 3;
	vbfield.m = 65535;
	vbfield.n = -1;
	vbfield.o = -1;
	vbfield.p = -1;
	vbfield.q = -1;
	vbfield.r = -1;
}


static int * func9()			/* nested local variables */
{
	static int stat1 = 0;
	register int reg1;
	auto int auto1;

	auto1 = stat1;

	for ( reg1 = 0 ; reg1 < 2 ; reg1++ )
	{
		static int stat2 = 0;
		register int reg2;
		auto int auto2;

		auto2 = stat2;

		for ( reg2 = 0 ; reg2 < reg1 ; reg2++ )
		{
			func1( &stat1 );
			func1( &auto1 );
			func1( &stat2 );
			func1( &auto2 );
		}
	}

	return &stat1;
}

int func10()				/* lokal varaibles with coloring */
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

	return v17+j;
}

int func11( int x )				/* problems with optimizer */
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

typedef char undefarray[1];
typedef undefarray * undefptr;

void func12( undefptr ptr )		/* pointer to array of unknown size */
{
	(*ptr)[0] = 1;
}


int func13( int a, int c, int e )	/* arguments and locals stack-tracking */
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
	return 2+x1;
}

int func16( long x1 )		/* Parameter: 1 Long */
{
	return (int) (2+x1);
}

int func17( short x1, short x2 ) /* Parameter: 2 Short */
{
	return x1*x2;
}

int func18( short x1, long x2 )	/* Parameter: Short,Long */
{
	return x1+x2;
}

int func19( long x1, short x2 )	/* Parameter: Long,Short */
{
	return x1+x2;
}

int func20( short x1, short x2, short x3 ) /* Parameter: 3 Short */
{
	return x1*x2*x3;
}

int func21( long x1, short x2, short x3 ) /* Parameter: Long,Short,Short */
{
	return x1+x2+x3;
}

int func22( short x1, long x2, short x3 ) /* Parameter: Short,Long,Short */
{
	return x1+x2+x3;
}

int func23( short x1, short x2, long x3 ) /* Parameter: Short,Short,Long */
{
	return x1+x2+x3;
}

char func24()			/* Char Return */
{
	return 55;
}

long func25()			/* Long Return */
{
	return 12345678l;
}

char * func26()			/* Pointer Return */
{
	static char x1[] = "abc";

	return x1;
}

struct struct1 func27( short x1, short x2 ) /* function returning struct */
{
	ast.count = x1*x2;

	return ast;
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



#ifdef FLOATING_POINT

double sinewave[130];


void funcsinewave()
{
	int index;
	double x;

	index = 0;
	for ( x = 0.0 ; x < 12.0 ; x += 0.1 )
		sinewave[index++] = sin(x)/(x+0.1);
}

#endif


int sieve();

int main()
{
    int j;
	char * p;

#ifdef FLOATING_POINT
	funcsinewave();
#endif

	do
	{

	mstatic1 = 12;
	mstatic2 = 34;
	mcount++;

	vtripplearray[0][0][0] = 1;
	vtripplearray[1][0][0] = 2;
	vtripplearray[0][1][0] = 3;
	vtripplearray[0][0][1] = 4;

	func2();

	func2a();

	func2b();

#ifdef FLOATING_POINT
	func2c();
#endif

	funcptr = (int (*)()) 0;
	funcptr = func3;

	ast.count = 12345;
	ast.left = &ast;
	ast.field1 = 1+mstatic2;
	ast.field2 = 2;

	ast = func4( ast );

	j = (*funcptr)();

start:
	j = func5( (int) j, (char) 2, (long) 3 );

	if ( j == 0 )
		goto start;

	enumvar = enumx;

#ifdef FLOATING_POINT
	vfloat = 2.0;

	func6( vfloat, (float) 3.0 );

	vdouble = 2.0;

	func7( vdouble, (double) 3.0 );
#endif

	func8();

	func9();

	func10();

	func11( 5 );

	func13( 1, 2, 3 );

	func14( (char) 55 );

	func15( (short) 55 );

	func16( (long) 55 );

	func17( (short) 44, (short) 55 );

	func18( (short) 44, (long) 55 );

	func19( (long) 44, (short) 55 );

	func20( (short) 33, (short) 44, (short) 55 );

	func21( (long) 33, (short) 44, (short) 55 );

	func22( (short) 33, (long) 44, (short) 55 );

	func23( (short) 33, (short) 44, (long) 55 );

	j = func24();

	vlong = func25();

	p = func26();

    vint = *p;

	vshortrecord = func28(vshortrecord);

#ifdef C_PLUS_PLUS
	cpp_func1();

	mstatic1 = cpp_func2();

	mstatic1 = cpp_func3();

    cpp_func4();

	cpp_func5();

	mstatic1 = cpp_funcargs1();

	mstatic1 = cpp_funcargs2(enum1);

	mstatic1 = cpp_funcargs3(1);

	mstatic1 = cpp_funcargs4();

	mstatic1 = cpp_funcargs5();

	mstatic1 = cpp_funcrefargs(mstatic1, mstatic2);
#endif

    vint = 1;

    sieve();
	} while (vint);
}


char flags[SIZE+1];

int sieve()				/* sieve of erathostenes */
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
                }
        }

	return anzahl;
}



