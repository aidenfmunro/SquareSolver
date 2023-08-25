#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "solvingutil.h"
#include "minorutil.h"
#include "myassert.h"

int linearSolver(double b, double c, double *x1)
{
    if (doubleCompare(b, 0))
      {
        if (doubleCompare(c, 0))
          {
            return INFINITE_ROOTS;
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
    myAssert(x1, NULL_ERROR);
    myAssert(x2, NULL_ERROR);

    double d = b * b - 4 * a * c;

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
        double sqrtd = sqrt(d);

        double temp_x1 = (-b + sqrtd) / (2 * a);
        double temp_x2 = (-b - sqrtd) / (2 * a);

        if (temp_x1 > temp_x2)
          {
            *x1 = temp_x1;
            *x2 = temp_x2;
          }
        else
          {
            *x1 = temp_x2;
            *x2 = temp_x1;
          }

        return TWO_ROOTS;
      }

}

int equationSolver(double a, double b, double c, double *x1, double *x2)
{
    myAssert(isfinite(a), IS_FINITE_ERROR);
    myAssert(isfinite(b), IS_FINITE_ERROR);
    myAssert(isfinite(c), IS_FINITE_ERROR);

    myAssert(x1, NULL_ERROR);
    myAssert(x2, NULL_ERROR);

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

