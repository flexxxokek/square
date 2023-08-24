#include <stdio.h>
#include "flush.h"
#include "constants.h"

void input(double* a, double* b, double* c)
{
    while(scanf("%lf %lf %lf", a, b, c) != 3)
    {
        flush_buffer();
    }
}

void output(int nRoots, double const x1, double const x2)
{
    switch (nRoots)
    {
        case NOROOTS:
            printf("Sorry, there is no roots\n");
            break;

        case ONEROOT:
            printf("Congratulations, your single root is %lf\n", x1); // code-style
            break;

        case TWOROOTS:
            printf("Congratulations, your roots are %lf, %lf\n", x1, x2);
            break;

        case INFROOTS:
            printf("Mnogo Roots\n");
            break;
    }
}
