/**
 * LAUTERBACH multisieve demo application
 *
 * $Id: multisieve.c 15460 2019-12-22 17:08:06Z hdammak $
 */

#define TRUE 1
#define FALSE 0
#define SIZE 18

/* flagsc is a clone, each core have its own copy */
char flagsc[SIZE + 1];
char __share flags[SIZE + 1];
char __private0 flags0[SIZE + 1];
char __private1 flags1[SIZE + 1];
char __private2 flags2[SIZE + 1];


/**
 * sieve of erathostenes
 * Shared: All code and data are accessible by all cores.
 *         The symbols are located in shared memory.
 */
int __share sieve(void)
{
	register int i, primz, k;
	int anzahl;
	char core;
	core = __mfcr(CORE_ID);

	anzahl = 0;

	for (i = 0; i <= SIZE; flags[i++] = 0x10+core) {
	}

	for (i = 0; i <= SIZE; i++) {
		if (flags[i]) {
			primz = i + i + 3;
			k = i + primz;
			while (k <= SIZE) {
				flags[k] = FALSE;
				k += primz;
			}
			anzahl++;
		}
	}

	return anzahl;
}

/**
 * sieve of erathostenes
 * Operates on data specified as cloned.
 * Cloned: Code or data is copied to the local scratchpad memory
 *         of each binary compatible core, or a specific core.
 *         The core then treats the code/data as if it were private.
 */
int sievec(void)
{
	register int i, primz, k;
	int anzahl;
	char core;
	core = __mfcr(CORE_ID);

	anzahl = 0;

	for (i = 0; i <= SIZE; flagsc[i++] = 0xA0+core) {
	}

	for (i = 0; i <= SIZE; i++) {
		if (flagsc[i]) {
			primz = i + i + 3;
			k = i + primz;
			while (k <= SIZE) {
				flagsc[k] = FALSE;
				k += primz;
			}
			anzahl++;
		}
	}

	return anzahl;
}

/**
 * sieve of erathostenes only executed on core 0
 */
int sieve0(void)
{
	register int i, primz, k;
	int anzahl;

	anzahl = 0;

	for (i = 0; i <= SIZE; flags0[i++] = 0xA0) {
	}

	for (i = 0; i <= SIZE; i++) {
		if (flags0[i]) {
			primz = i + i + 3;
			k = i + primz;
			while (k <= SIZE) {
				flags0[k] = FALSE;
				k += primz;
			}
			anzahl++;
		}
	}

	return anzahl;
}

/**
 * sieve of erathostenes only executed on core 1
 */
int sieve1(void)
{
	register int i, primz, k;
	int anzahl;

	anzahl = 0;

	for (i = 0; i <= SIZE; flags1[i++] = 0xA1) {
	}

	for (i = 0; i <= SIZE; i++) {
		if (flags1[i]) {
			primz = i + i + 3;
			k = i + primz;
			while (k <= SIZE) {
				flags1[k] = FALSE;
				k += primz;
			}
			anzahl++;
		}
	}

	return anzahl;
}

/**
 * sieve of erathostenes only executed on core 2
 */
int sieve2(void)
{
	register int i, primz, k;
	int anzahl;

	anzahl = 0;

	for (i = 0; i <= SIZE; flags2[i++] = 0xA2) {
	}

	for (i = 0; i <= SIZE; i++) {
		if (flags2[i]) {
			primz = i + i + 3;
			k = i + primz;
			while (k <= SIZE) {
				flags2[k] = FALSE;
				k += primz;
			}
			anzahl++;
		}
	}

	return anzahl;
}

/**
 * main function
 */
int main(void)
{
	volatile unsigned int nCount = 0;

	while (TRUE) {
		sieve();
		sievec();
		if ( __mfcr(CORE_ID) == 0 ) {
			sieve0();
		}
		if ( __mfcr(CORE_ID) == 1 ) {
			sieve1();
		}
		if ( __mfcr(CORE_ID) == 2 ) {
			sieve2();
		}
		nCount++;
	}
}
