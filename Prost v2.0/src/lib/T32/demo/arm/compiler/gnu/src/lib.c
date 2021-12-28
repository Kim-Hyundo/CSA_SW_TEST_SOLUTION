void* memcpy(void *s1, const void *s2, int n)
{
    char *c1 = (char*) s1;
    char *c2 = (char*) s2;

    for(;n;n--) {
	*c1 = *c2;
	c1++;
	c2++;
    }
    return s1;
}

/* or add "-lc" for linking */
