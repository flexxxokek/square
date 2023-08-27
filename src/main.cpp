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
#include "structs.h"

struct Option
{
    char name[MAXFLAGLENGTH];
    void (*action)(int argc, char** argv);
};

/**
 *  \brief при налиции флага, выводит мнформацию о флагах в консоль
*/
void flagHelp(int argc, char** argv);


/**
 *  \brief при налиции флага, запускает тестирующую систему
*/
void flagTest(int argc, char** argv);

/**
 *  \brief проверяет наличие флагов запуска
*/
void parseFlags(int argc, char** argv);


const struct Option OPTIONS[2] = {{"--help", &flagHelp},{"--test", &flagTest}};

int main(int argc, char** argv)
{
    parseFlags(argc, argv);

    //hello message
    printf( "\033[93mSQUARE EQUATION SOLUTION\n"
            "by Daniel Lipchkov\n\n\n"
            "Please enter coefficients of square equation:\n");
    
    struct coeffStruct coeffs {NAN, NAN, NAN};
    
    input(&coeffs);

    struct rootStruct roots;
    roots.nRoots = solveSquare(coeffs, &roots);

    output(roots);
}

void flagHelp(int argc, char** argv)
{
    printf( "\n %s\n\n"
            "\t--help Display this information\n"
            "\t--test 'file_name' start tests from the file\n",
            argv[0]);
    exit(argc);
}

void flagTest(int argc, char** argv)
{
    testAll(argv[argc - 1]);
    exit(argc);
}

void parseFlags(int argc, char** argv)
{
    for (int i = 1; i < argc; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (!strcmp(argv[i], OPTIONS[j].name))
            {
                OPTIONS[j].action(argc, argv);
            }
        }   
    }
}
