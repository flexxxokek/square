#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include "double_func.h"
#include "constants.h"
#include "square_equation.h"
#include "test.h"
#include "myfilestuff.h"

bool freadTest(struct testStruct* test, FILE* fp)
{
    if(fscanf(fp, "%lf %lf %lf %lf %lf %d", &test->a, &test->b, &test->c, &test->xref1, &test->xref2, &test->nRootsref) >= 6)
    {
        return true;
    }
    if(getc(fp) == EOF){
        return false;
    }
    printf( "\n\tError\n"
            "\tInvalid format of test file\n\n");
    return false;
}

void printFailTestInfo(struct testStruct test, double x1, double x2) // why i should test fail msg
{
    printf("Test number %d Failed\n"
           "\tEquation:\n"
           "\t\t%.3lfx^2 + %.3lfx + %.3lf = 0\n"
           "\t\tExpected:\n"
           "\t\t\tx1 = %lf, x2 = %lf\n"
           "\t\tGot:\n"
           "\t\t\tx1 = %lf, x2 = %lf\n", test.num, test.a, test.b, test.c, test.xref1, test.xref2, x1, x2);
}

bool runTest(struct testStruct test)
{
    assert(isfinite(test.a));
    assert(isfinite(test.b));
    assert(isfinite(test.c));
    assert(isfinite(test.xref1));
    assert(isfinite(test.xref2));
    assert(isfinite(test.nRootsref));
    double x1 = NAN, x2 = NAN;
    int nRoots = solveSquare(test.a, test.b, test.c, &x1, &x2);
    if(nRoots == test.nRootsref)
    {
        switch(nRoots)
        {
            case NOROOTS:
            case INFROOTS:
                return false;
            case ONEROOT:
                if(equal_d(x1, test.xref1) || equal_d(x1, test.xref2))
                {
                    return false;
                }
            case TWOROOTS:
                if((equal_d(x1, test.xref1) && equal_d(x2, test.xref2)) ||
                   (equal_d(x1, test.xref2) && equal_d(x2, test.xref1)))
                {
                    return false;
                }
            default:
                    printf( "\tError:\n"
                            "\tInvalid format of test file\n");

        }
    }
    printFailTestInfo(test, x1, x2);
    return true;
}

void testAll(char* fileName)
{
    FILE *fp = fopen(fileName, "r");
    assert(fp != NULL);
    int failedTests = 0, successTests = 0;
    if(checkFile(fp))
    {
        testStruct currTest;
        while(freadTest(&currTest, fp))
        {
            failedTests += runTest(currTest);
            currTest.num ++;
        }
        successTests = currTest.num - failedTests - 1;
        printf( "Ran %d tests\n"
                "\t%d tests failed, %d tests succeed\n", failedTests + successTests, failedTests, successTests);
        return;
    }
    printf( "\tError:\n"
            "\tInvalid format of test file\n");
}


