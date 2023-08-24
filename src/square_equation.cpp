#include "double_func.h"
#include "constants.h"
#include <assert.h>
#include <math.h>

int solveLinear(double const b, double const c, double* x1)
{
    if(equal_d(b, 0))
    {
        if(equal_d(c, 0))
        {
            *x1 = NAN;
            return INFROOTS;
        }
        else
        {
            *x1 = NAN;
            return NOROOTS;
        }
    }
    else
    {
        *x1 = -c / b;
        return 1;
    }
}

int solveSquare(const double a, const double b, const double c, double* x1, double* x2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(x1 != x2);
    assert(x1 != NULL);
    assert(x2 != NULL);
    if(equal_d(a, 0))
    {
        *x2 = NAN;
        return solveLinear(b, c, x1);
    }
    else
    {
        double discriminant = b * b - 4 * a * c;
        if(compare_d(discriminant, 0) == 1)
        {
            double sqr_discr = sqrt(discriminant);
            *x1 = (-b - sqr_discr) / (2 * a);
            *x2 = (-b + sqr_discr) / (2 * a);
            return 2;
        }
        else if(equal_d(discriminant, 0))
        {
            *x1 = -b / (2 * a);
            *x2 = NAN;
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
