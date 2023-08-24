#include <stdio.h>

void flush_buffer()
{
    char p;
    while((p = getchar()) != EOF && p != '\n') {}
}
