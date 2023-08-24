#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include "double_func.h"
#include "constants.h"
#include "flush.h"
#include "square_equation.h"
#include "io.h"
#include "test.h"
#include "myfilestuff.h"


int main(int argc, char** argv)
{
    if(checkOption(OPTIONS[0], argc, argv) > 0)
    {
        printf("\n\tcode: 0 --help Display this information\n"
               "\tcode: 1--test 'file_name' start tests from the file\n");
        exit(1);
    }
    printf( "SQUARE EQUATION SOLUTION\n"
            "by Daniel Lipchkov\n\n\n");
    double a = 0, b = 0, c = 0;
    if(checkOption(OPTIONS[1], argc, argv)){
        testAll(argv[checkOption(OPTIONS[1], argc, argv) + 1]);
    }
    input(&a, &b, &c);
    double x1 = 0, x2 = 0;
    int nRoots = solveSquare(a, b, c, &x1, &x2);
    output(nRoots, x1, x2);
}
