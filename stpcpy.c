#include "config.h"

#ifndef HAVE_STPCPY
/*
 * Copy the string and return the advanced pointer.
 */
char *stpcpy(char *dest, const char *src)
{
    const char *s;
    char *d;

    for (s = src, d = dest; (*d++ = *s++) != '\0'; )
        ;
    return d - 1;
}
#endif  /* ndef HAVE_STPCPY */
