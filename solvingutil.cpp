#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "solvingutil.h"
#include "minorutil.h"

int linearSolver(double b, double c, double *x1)
{
    if (doubleCompare(b, 0))
      {
        if (doubleCompare(c, 0))
          {
            return INFINITE_ROOTS; // no roots
          }
        else
          {
            return NO_ROOTS;
          }
      }
    else
      {
        *x1 = - c / b;

        return ONE_ROOT;
      }
}

int squareSolver(double a, double b, double c, double *x1, double *x2)
{
    double d = 0;
    double sqrtd = 0;


    d = b * b - 4 * a * c;
    if (d < 0)
      {
        return NO_ROOTS;
      }
    else if (doubleCompare(d, 0))
      {
        *x1 = -b / (2 * a);

        return ONE_ROOT;
      }
    else
      {
        sqrtd = sqrt(d);
        *x1 = (-b + sqrtd) / (2 * a);
        *x2 =  (-b - sqrtd) / (2 * a);

        return TWO_ROOTS;
      }

}

int equationSolver(double a, double b, double c, double *x1, double *x2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1);
    assert(x2);

    if (doubleCompare(a, 0))
      {
        return linearSolver(b, c, x1);
      }
    else
      {
        return squareSolver(a, b, c, x1, x2);
      }

    return OK;
}

