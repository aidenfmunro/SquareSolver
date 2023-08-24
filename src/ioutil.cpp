#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "../headers/ioutil.h"
#include "../headers/minorutil.h"
#include "../headers/solvingutil.h"
#include "../headers/myassert.h"

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

int output(int result, double *x1, double *x2)
{
    myAssert(result, NULL_ERROR);
    myAssert(x1, NULL_ERROR);
    myAssert(x2, NULL_ERROR);
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
    char ch = 0;
    while((ch = getchar()) != '\n')
      {
        if (!isspace(ch))
          return 1;
      }
    return 0;
}
