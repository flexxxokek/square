#include <math.h>
#include "constants.h"
#include "double_func.h"

bool equal_double(double const a, double const b)
{
    return (fabs(a - b) <= D_DIFFER)? true : false;
}

short int compare_d(double const a, double const b)
{
    if(equal_double(a, b))
    {
        return -1;
    }
    return (a - b > D_DIFFER)? 1 : 0;
}
