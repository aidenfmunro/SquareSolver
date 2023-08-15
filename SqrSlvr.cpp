#include <stdio.h>

main(){
    float a, b, c, d;
    printf("Please type in the coefficients a, b, c\n");
    scanf("%f%f%f", &a, &b, &c);
    d = pow(b, 2) - 4 * a * c;
    if (d < 0)
        printf("Oops! Your equation has no roots");
    else if (d == 0)
        printf("One root: %f", -b / (2 * a));
    else
        printf("Two roots: %f and %f", (-b + sqrt(d)) / (2 * a), (-b - sqrt(d)) / (2 * a));    
}
     
