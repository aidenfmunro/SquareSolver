#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

#define EPS 1e-9

int input(void);
int output(void);
int linear_solver(double b, double c);
int square_solver(double a, double b, double c);
bool isAlmostEqual(double a, double b);

double coefficients[3] = {0, 0, 0};
char letters[3] = {'a', 'b', 'c'};
double roots[2] = {0, 0};


int main()
{
    printf("Please type in the coefficients a, b, c \n");

    input();

    output();
}


int linear_solver(double b, double c)
{
    if (isAlmostEqual(b, 0))
      {
        return 1;
      }
    else
      {
        roots[0] = - c / b;
      }

    return 0;

}


int square_solver(double a, double b, double c)
{
    double d, sqrt_d;
    d = pow(b, 2) - 4 * a * c;
    sqrt_d = sqrt(d);

    if (d < 0)
      {
        return 1;
      }
    else if (isAlmostEqual(d, 0))
      {
        roots[0] = -b / (2 * a);
        return 2;

      }
    else
      {
        roots[0] = (-b + sqrt_d) / (2 * a);
        roots[1] =  (-b - sqrt_d) / (2 * a);
      }

    return 0;
}


int input(void)
{
    for (int i = 0; i <= 2; ++i)
        {

        int res = 0;

        do {
            printf("Type in coefficient %c\n", letters[i]);
            res = scanf("%lf", &coefficients[i]);
            fflush(stdin);
           } while (res != 1);

        }

    return 0;
}


int output(void)
{
    if (isAlmostEqual(coefficients[0], 0))
        {
            if (linear_solver(coefficients[1], coefficients[2]) == 1)
            {
                printf("Invalid expression");
            }
            else
            {
                printf("One root: %lf", roots[0]);
            }
        }
    else
        {
            if (square_solver(coefficients[0], coefficients[1], coefficients[2]) == 1)
            {
                printf("Oops! Your equation has no real roots.");
            }
            else if (square_solver(coefficients[0], coefficients[1], coefficients[2]) == 2)
            {
                printf("One root: %lf", roots[0]);
            }
            else
                printf("Two roots: %lf and %lf", roots[0], roots[1]);
        }

    return 0;
}



bool isAlmostEqual(double a, double b)
{
    return fabs(a - b) < EPS;
}



