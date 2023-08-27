#include <stdio.h>
#include <math.h>
#include "flush.h"
#include "constants.h"
#include "io.h"
#include "structs.h"

void input(struct coeffStruct* coeffs)
{
    while(scanf("%lf %lf %lf", &coeffs->a, &coeffs->b, &coeffs->c) != 3)
    {
        printf("ERROR: invalid coefficients! Try again.\n");
        flush_buffer();
    }
}

void output(struct rootStruct roots)
{
    switch (roots.nRoots)
    {
        case NOROOTS:
            printf("Sorry, there is no roots\n");
            break;

        case ONEROOT:
            printf("Congratulations, your single root is %lf\n", roots.x1);
            break;

        case TWOROOTS:
            printf("Congratulations, your roots are %lf, %lf\n", roots.x1, roots.x2);
            break;

        case INFROOTS:
            printf("Mnogo Roots\n");
            break;
        default:
            printf("HAHAHA");
    }
}
