#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "../headers/ioutil.h"
#include "../headers/minorutil.h"
#include "../headers/solvingutil.h"

int input(double *a, double *b, double *c)
{
    assert(a);
    assert(b);
    assert(c);

    printf("Please type in the coefficients a, b, c \n");

    while (scanf("%lf %lf %lf", a, b, c) != 3 || checkInput()) //spaces
      {
        printf("Incorrect input, please try again: ");
        bufferCleaner();
      }

    return OK;
}

int output(int result, double *x1, double *x2)
{
    assert(result);
    assert(x1);
    assert(x2);
    switch (result)
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
    while(getchar() != ' ')
        return 1;
    return 0;
}
