#include <stdio.h>

double square(double x)
{
    /*double result = x * x;
    return result;*/
    return x * x; // This is a more concise way to write the same thing
}

int main()
{

    double x = square(3.14);
    printf("%lf", x);

    return 0;
}