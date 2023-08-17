#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double input();
int linear_eq(double b, double c);
int square_eq(double a, double b, double c);

int main(){
    double a = 0;
    double b = 0;
    double c = 0;
    printf("Please type in the coefficients a, b, c \n");
    printf("Coefficient a:\n");
    a = input();
    printf("Coefficient b:\n");
    b = input();
    printf("Coefficient c:\n");
    c = input();
    if ((int)a == 0)
        linear_eq(b, c);
    else
        square_eq(a, b, c);
}

int linear_eq(double b, double c){
    if ((int)b == 0)
        printf("Invalid expression.");
    else
        printf("One root: %lf", - c / b);
    return 0;

}

int square_eq(double a, double b, double c){
    double d, sqrt_d;
    d = pow(b, 2) - 4 * a * c;
    sqrt_d = sqrt(d);
    if (d < 0)
        printf("Oops! Your equation has no real roots.");
    else if ((int)d == 0)
        printf("One root: %lf", -b / (2 * a));
    else
        printf("Two roots: %lf and %lf", (-b + sqrt_d) / (2 * a), (-b - sqrt_d) / (2 * a));
    return 0;
}

double input(void){
    double coef;
    if (scanf("%lf", &coef) != 0)
        return coef;
    else
        printf("Incorrect input, try again.");
        exit(0);
    return coef;
}
