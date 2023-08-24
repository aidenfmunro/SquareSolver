#include <stdio.h>
#include <math.h>
#include "minorutil.h"

#define EPS 1e-5

bool doubleCompare(double a, double b)
{
    return fabs(a - b) < EPS;
}

void bufferCleaner(void)
{
    while (getchar() != '\n') ;
}
