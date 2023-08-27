#include <stdio.h>
#include "flush.h"

void flush_buffer()
{
    int p;
    while((p = getchar()) != EOF && p != '\n') {}
}
