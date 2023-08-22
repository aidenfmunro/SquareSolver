#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <assert.h>

#define EPS 1e-9

enum State
{
  INFINITE_ROOTS =  -1, // add headers
  NO_ROOTS = 0,
  ONE_ROOT,
  TWO_ROOTS,
  OK
};

int input(double *a, double *b, double *c);
int output(int result, double *x1, double *x2);
int linearSolver(double b, double c, double *x1, double *x2);
int squareSolver(double a, double b, double c, double *x1, double *x2);
int equationSolver(double a, double b, double c, double *x1, double *x2);
bool doubleCompare(double a, double b);
void bufferCleaner(void);



int main()
{
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;

    input(&a, &b, &c);

    int result = equationSolver(a, b, c, &x1, &x2);

    output(result, &x1, &x2);
}


int linearSolver(double b, double c, double *x1, double *x2)
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
        return linearSolver(b, c, x1, x2);
      }
    else
      {
        return squareSolver(a, b, c, x1, x2);
      }

    return OK;
}

int input(double *a, double *b, double *c)
{
    assert(a);
    assert(b);
    assert(c);

    printf("Please type in the coefficients a, b, c \n");

    while (scanf("%lf %lf %lf", a, b, c) != 3 || getchar() != '\n') //spaces
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

bool doubleCompare(double a, double b)
{
    return fabs(a - b) < EPS;
}

void bufferCleaner(void)
{
    while (getchar() != '\n') ;
}
