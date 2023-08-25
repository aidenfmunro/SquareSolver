//! @file
//! @author Aiden Munro
//! @version 1.0

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "ioutil.h"
#include "minorutil.h"
#include "solvingutil.h"
#include "myassert.h"

int input(double *a, double *b, double *c)
{
    myAssert(a, NULL_ERROR);
    myAssert(b, NULL_ERROR);
    myAssert(c, NULL_ERROR);

    printf("Please type in the coefficients a, b, c \n");

    while (scanf("%lf %lf %lf", a, b, c) != 3 || checkInput())
      {
        printf("Incorrect input, please try again: ");
        bufferCleaner();
      }

    return OK;
}

int output(int numRoots, double *x1, double *x2)
{
    myAssert(x1, NULL_ERROR);
    myAssert(x2, NULL_ERROR);
    switch (numRoots)
      {
        case NO_ROOTS:
          printf("No roots.");
          break;

        case ONE_ROOT:
          printf("One root: %lg", *x1);
          break;

        case TWO_ROOTS:
          printf("Two roots: %lg %lg", *x1, *x2);
          break;

        case INFINITE_ROOTS:
          printf("Infinite roots.");
          break;

        default: printf("main(): Unknown option.");
      }

    return OK;
}

int checkInput(void)
{
    int ch = (char)0;
    while((ch = getchar()) != '\n')
      {
        if (!isspace(ch))
          return YES;
      }
    return NO;
}
