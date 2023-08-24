#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../headers/myassert.h"

const char* printError(int state)
{
    switch (state)
      {
        case IS_FINITE_ERROR:
            return "Number is not finite, failed at %s:%d";
            break;
        case NULL_ERROR:
            return "Number is null, failed at %s:%d";
            break;
        default: "Unknown error, failed at %s:%d";
      }
}

