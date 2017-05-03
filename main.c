#include "config.h"
#include <stdio.h>
#include "stpcpy.h"

int main(void)
{
    char buf[32];
    stpcpy(stpcpy(buf, "abc"), "def");
    printf("%s\n", buf);    /* abcdef */
    return 0;
}
