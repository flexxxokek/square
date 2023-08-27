#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include "double_func.h"
#include "constants.h"
#include "square_equation.h"
#include "test.h"
#include "myfilestuff.h"
#include "structs.h"

bool fscanTest(struct testStruct* test, FILE* fp)
{
    if (fscanf( fp, "%lf %lf %lf %lf %lf %d",
                &test->coeffs.a, &test->coeffs.b, &test->coeffs.c,
                &test->roots.x1, &test->roots.x2, &test->roots.nRoots) == 6)
    {
        return true;
    }
    if (getc(fp) == EOF){
        return false;
    }
    printf( "\n\tError\n"
            "\tInvalid format of test file\n\n");
    return false;
}

void printFailTestInfo(struct testStruct test, struct rootStruct wrongRoots)
{
    switch(test.roots.nRoots)
    {
        default:
            printf( "\n\t\t\t\033[31mTEST NUMBER %d IS INCORRECT, "
                    "PLEASE CHECK IT OUT!\n\n\n", test.num);
            break;
        case NOROOTS:
        case INFROOTS:
            printf( "\033[31mTest number %d Failed\n"
                    "\tEquation:\n"
                    "\t\t%.3lfx^2 + %.3lfx + %.3lf = 0\n"
                    "\t\tExpected:\n"
                    "\t\t\tnumber of roots = %d\n"
                    "\t\tGot:\n"
                    "\t\t\tx1 = %lf, x2 = %lf, number of roots = %d\n\033[0m",
                    test.num,
                    test.coeffs.a, test.coeffs.b, test.coeffs.c,
                    test.roots.nRoots,
                    wrongRoots.x1, wrongRoots.x2, wrongRoots.nRoots);
            break;
        case ONEROOT:
            printf( "\033[31mTest number %d Failed\n"
                    "\tEquation:\n"
                    "\t\t%.3lfx^2 + %.3lfx + %.3lf = 0\n"
                    "\t\tExpected:\n"
                    "\t\t\tx1 = %lf, number of roots = %d\n"
                    "\t\tGot:\n"
                    "\t\t\tx1 = %lf, x2 = %lf, number of roots = %d\n\033[0m",
                    test.num,
                    test.coeffs.a, test.coeffs.b, test.coeffs.c,
                    test.roots.x1, test.roots.nRoots,
                    wrongRoots.x1, wrongRoots.x2, wrongRoots.nRoots);
            break;
        case TWOROOTS:
            printf( "\033[31mTest number %d Failed\n"
                    "\tEquation:\n"
                    "\t\t%.3lfx^2 + %.3lfx + %.3lf = 0\n"
                    "\t\tExpected:\n"
                    "\t\t\tx1 = %lf, x2 = %lf, number of roots = %d\n"
                    "\t\tGot:\n"
                    "\t\t\tx1 = %lf, x2 = %lf, number of roots = %d\n\033[0m",
                    test.num,
                    test.coeffs.a, test.coeffs.b, test.coeffs.c,
                    test.roots.x1, test.roots.x2, test.roots.nRoots,
                    wrongRoots.x1, wrongRoots.x2, wrongRoots.nRoots);
            break;
    }
}

bool runTest(struct testStruct test)
{
    assert(isfinite(test.coeffs.a));
    assert(isfinite(test.coeffs.b));
    assert(isfinite(test.coeffs.c));
    assert(isfinite(test.roots.x1));
    assert(isfinite(test.roots.x2));
    assert(isfinite(test.roots.nRoots));

    struct rootStruct roots = {NAN, NAN, INFROOTS};
    roots.nRoots = solveSquare(test.coeffs, &roots);
   
    if(roots.nRoots == test.roots.nRoots)
    {
        switch(roots.nRoots)
        {
            case NOROOTS:
            case INFROOTS:
                return false;
            case ONEROOT:
                if(equal_double(roots.x1, test.roots.x1) || equal_double(roots.x1, test.roots.x2))
                {
                    return false;
                }
                break;
            case TWOROOTS:
                if(
                    (equal_double(roots.x1, test.roots.x1) && equal_double(roots.x2, test.roots.x2)) ||
                    (equal_double(roots.x1, test.roots.x2) && equal_double(roots.x2, test.roots.x1))
                )
                {
                    return false;
                }
                break;
            default:
                printf( "\tError:\n"
                        "\tInvalid format of test file\n");
                break;

        }
    }
    printFailTestInfo(test, roots);
    return true;
}

void testAll(char* fileName)
{
    FILE *fp = fopen(fileName, "r");
    if(fp == NULL)
    {
        printf( "\n\tError:"
                "\n\t%s is not found", fileName);
        return;
    }
    int failedTests = 0, successTests = 0;
    if(checkFile(fp))
    {
        testStruct currTest = {{NAN, NAN, NAN}, {NAN, NAN, -1}, 1};
        while(fscanTest(&currTest, fp))
        {
            failedTests += runTest(currTest);
            currTest.num ++;
        }
        successTests = currTest.num - failedTests - 1;
        printf( "\tRan %d tests\n"
                "\033[31m\t\t%d tests failed\033[32m\t%d tests succeed\n\033[0m", failedTests + successTests, failedTests, successTests);
        return;
    }
    printf( "\tError:\n"
            "\tInvalid format of test file\n");
}


