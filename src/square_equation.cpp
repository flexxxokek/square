#include <assert.h>
#include <math.h>
#include "double_func.h"
#include "constants.h"
#include "square_equation.h"
#include "structs.h"

ROOTSNUM solveLinear(struct coeffStruct coeffs, struct rootStruct* roots)
{
    if(equal_double(coeffs.b, 0))
    {
        if(equal_double(coeffs.c, 0))
        {
            roots->x1 = NAN;
            return INFROOTS;
        }
        else
        {
            roots->x1 = NAN;
            return NOROOTS;
        }
    }
    else
    {
        roots->x1 = -coeffs.c / coeffs.b;
        return ONEROOT;
    }
}

ROOTSNUM solveSquare(struct coeffStruct coeffs, struct rootStruct* roots)
{
    assert(isfinite(coeffs.a));
    assert(isfinite(coeffs.b));
    assert(isfinite(coeffs.c));
    if(equal_double(coeffs.a, 0))
    {
        roots->x2 = NAN;
        return solveLinear(coeffs, roots);
    }
    else
    {
        double discriminant = coeffs.b * coeffs.b - 4 * coeffs.a * coeffs.c;
        if(compare_d(discriminant, 0) == 1)
        {
            double sqr_discr = sqrt(discriminant);
            roots->x1 = (-coeffs.b - sqr_discr) / (2 * coeffs.a);
            roots->x2 = (-coeffs.b + sqr_discr) / (2 * coeffs.a);
            return TWOROOTS;
        }
        else if(equal_double(discriminant, 0))
        {
            roots->x1 = -coeffs.b / (2 * coeffs.a);
            roots->x2 = NAN;
            return ONEROOT;
        }
        else
        {
            return NOROOTS;
        }
    }
}
