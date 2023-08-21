#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

#define EPS 1e-9

enum State {InvalidExpression =  -1, NoRoots = 0, OneRoot = 1, TwoRoots = 2, Ok = 3};

int input(double *a, double *b, double *c);
int output(double a, double b, double c, double *roots);
int linearSolver(double b, double c, double *roots);
int squareSolver(double a, double b, double c, double *roots);
bool doubleCompare(double a, double b);
void bufferCleaner(void);



int main()
{
    double a = 0;
    double b = 0;
    double c = 0;

    double roots[2] = {0, 0};

    printf("Please type in the coefficients a, b, c \n");

    input(&a, &b, &c);

    output(a, b, c, roots);
}


int linearSolver(double b, double c, double *roots)
{
    if (doubleCompare(b, 0))
      {
        return InvalidExpression;
      }
    else
      {
        *roots = - c / b;

        return OneRoot;
      }
}


int squareSolver(double a, double b, double c, double *roots)
{
    double d = 0;
    double sqrt_d = 0;

    d = b * b - 4 * a * c;

    if (doubleCompare(a, 0))
      {
        linearSolver(b, c, roots);

        return Ok;
      }
    else
      {
        if (d < 0)
          {
            return NoRoots;
          }
        else if (doubleCompare(d, 0))
          {
            *roots = -b / (2 * a);

            return OneRoot;
          }
        else
          {
            sqrt_d = sqrt(d);
            *roots = (-b + sqrt_d) / (2 * a);
            *(roots + 1) =  (-b - sqrt_d) / (2 * a);

            return TwoRoots;
          }
      }
}

int input(double *a, double *b, double *c) // changed
{
    while (scanf("%lf %lf %lf", a, b, c) != 3)
      {
        printf("Incorrect input, please try again: ");
        bufferCleaner();
      }

    return Ok;
}

int output(double a, double b, double c, double *roots)
{
    int result = 0;

    result = squareSolver(a, b, c, roots);

    if (result == -1)
      {
        printf("Invalid expression.");
      }
    else if (result == 0)
      {
        printf("No roots.");
      }
    else if (result == 1)
      {
        printf("One root: %lf", *roots);
      }
    else if (result == 2)
      {
        printf("Two roots: %lf %lf", *roots, *(roots + 1));
      }

    return Ok;
}

bool doubleCompare(double a, double b) //change name doubleCompare
{
    return fabs(a - b) < EPS;
}

void bufferCleaner(void)
{
    while (getchar() != '\n') { ; }
}
