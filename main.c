#include "config.h"
#include <stdio.h>
#include "stpcpy.h"

int main(void)
{
    char buf[32];
    puts(PROGRAM_INFO);
    stpcpy(stpcpy(buf, "abc"), "def");
    printf("%s\n", buf);    /* abcdef */
    return 0;
}
