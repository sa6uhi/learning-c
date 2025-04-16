# include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;

    printf("Enter side a: ");
    scanf("%lf", &a);
    printf("Enter side b: ");
    scanf("%lf", &b);

    // Calculate the length of the hypotenuse using Pythagorean theorem
    c = sqrt(a * a + b * b);

    printf("The length of the hypotenuse(side c) is: %.2lf\n", c);

    return 0;
}