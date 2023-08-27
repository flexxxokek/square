#include <stdio.h>
#include <string.h>
#include "myfilestuff.h"

// TODO:
// Doxygen
// README.md
// makefile
// # AAA
// ## BBB
// _edded_
// `deded`

int fgetline(FILE* fp, int* s)
{
    int length = 0;
    while((s[length] = getc(fp)) != EOF && s[length] != '\n')
    {
        length++;
    }
    s[length] = '\n';
    length++;
    return length;
}

int checkFile(FILE* fp)
{
    char s[13];
    if(fscanf(fp, "%12s", s) == 1 && !strcmp(s, "Daniel_tests"))
    {
        int intCheck = 0;
        while((intCheck = getc(fp)) != '\n' && intCheck != EOF)
            ;
        return true;
    }
    return false;
}
int checkOption(const char* option, int argc, char** argv)
{
    for(int i = 1; i < argc; i++)
    {
        if(!strcmp(option, argv[i])) return i;
    }
    return -1;
}
