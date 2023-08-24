#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../headers/solvingutil.h"
#include "../headers/minorutil.h"
#include "../headers/tester.h"

const int LINES = 3;


void testEquation(void)
{
    FILE *fp;
    double a = NAN, b = NAN, c = NAN, numRoots = NAN, numRoots_t = NAN;
    double x1 = NAN, x2 = NAN, x1_test = NAN, x2_test = NAN;

    char name[] = "testsfxd.txt";
    if ((fp = fopen(name, "r")) == NULL)
      {
        printf("Unable to open file");
        exit(EXIT_FAILURE);
      }

    for (int i =  0; i < LINES; i++)
      {
        fscanf(fp, "%lg %lg %lg %lg %lg %lg", &a, &b, &c, &numRoots_t, &x1_test, &x2_test);

        printf("%lg %lg %lg %lg %lg %lg ", a, b, c, numRoots_t, x1_test, x2_test);

        int numRoots = equationSolver(a, b, c, &x1, &x2);

        printf("%lg %lg ", x1, x2);
        if (doubleCompare(numRoots, numRoots_t))
          {
            if (numRoots == ONE_ROOT)
              {
                checkTest(doubleCompare(x1, x1_test));
              }
            else if (numRoots == TWO_ROOTS)
              {
                checkTest(doubleCompare(x1, x1_test) && doubleCompare(x2, x2_test));
              }
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
}

