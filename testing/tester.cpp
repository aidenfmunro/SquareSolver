#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "solvingutil.h"
#include "minorutil.h"
#include "tester.h"

void testEquation(void)
{
    char name[] = "testing/tests.txt";

    FILE *fp = fopen(name, "r");

    if (fp == NULL)
      {
        printf("Unable to open file");
        return;
      }

    double a = NAN, b = NAN, c = NAN, numRoots_t = NAN;
    double x1 = NAN, x2 = NAN, x1_test = NAN, x2_test = NAN;

    int LINES = 0;

    fscanf(fp, "%d", &LINES);

    for (int i =  0; i < LINES; i++)
      {
        fscanf(fp, "%lg %lg %lg %lg %lg %lg", &a, &b, &c, &numRoots_t, &x1_test, &x2_test);

        int numRoots = equationSolver(a, b, c, &x1, &x2);


        if (numRoots == ONE_ROOT)
          {
            printf("%lg %lg %lg %lg %lg ", a, b, c, numRoots_t, x1_test);
            printf("%lg ", x1);
            checkTest(doubleCompare(x1, x1_test));
          }
        else if (numRoots == TWO_ROOTS)
          {
            printf("%lg %lg %lg %lg %lg %lg ", a, b, c, numRoots_t, x1_test, x2_test);
            printf("%lg %lg ", x1, x2);
            checkTest(doubleCompare(x1, x1_test) && doubleCompare(x2, x2_test));
          }
        else if (numRoots == NO_ROOTS)
          {
            printf("%lg %lg %lg %lg ", a, b, c, numRoots_t);
            checkTest(doubleCompare(numRoots_t, numRoots));
          }
        else if (numRoots == INFINITE_ROOTS)
          {
            printf("%lg %lg %lg %lg ", a, b, c, numRoots_t);
            checkTest(doubleCompare(numRoots_t, numRoots));
          }

      }

    fclose(fp);
}

bool checkTest(bool state)
{
    if (state)
        printf("Test succeeded.\n");
    else
        printf("Test failed.\n");

    return true;
}

