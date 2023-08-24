#include <stdio.h>
#include <string.h>

int fgetline(FILE* fp, char* s)
{
    int length = 0;
    while((s[length] = getc(fp)) != EOF && s[length] != '\n')
    {
        length++;
    }
    return length;
}

int checkFile(FILE* fp)
{
    char s[8] = "$1111$";
    int length = fgetline(fp, s);
    return (length % 2 == 0 && s[0] == '$' && s[length - 1] == '$')? 1 : 0;
}
int checkOption(const char* option, int argc,char** argv)
{
    for(int i = 1;i < argc;i++)
    {
        if(!strcmp(option, argv[i])) return i;
    }
    return -1;
}
