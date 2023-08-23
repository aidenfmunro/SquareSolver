#include <stdio.h>
#include <math.h>
#include "../headers/minorutil.h"

#define EPS 1e-9

bool doubleCompare(double a, double b)
{
    return fabs(a - b) < EPS;
}

void bufferCleaner(void)
{
    while (getchar() != '\n') ;
}
