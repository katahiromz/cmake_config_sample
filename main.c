#include "config.h"
#include <stdio.h>
#include "stpcpy.h"

int main(void)
{
    char buf[32];
    puts(PROGRAM_INFO);
    stpcpy(stpcpy(buf, "abc"), "def");
    puts(buf);    /* abcdef */
    return 0;
}
