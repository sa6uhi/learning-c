#include <stdio.h>
#include <math.h>

int main(){

    double A = sqrt(9);
    double B = pow(2, 4);
    int C = round(3.14);
    int D = ceil(3.14); // round a number up
    int E = floor(3.99); // round a number down
    double F = fabs(-100); // find the absolute value
    double G = log(3); //   logarithm
    double H = sin(45); // sine
    double I = cos(45); // cosine
    double J = tan(45); // tangent

    printf("\n%lf", A);
    printf("\n%lf", B);
    printf("\n%d", C);
    printf("\n%d", D);
    printf("\n%d", E);
    printf("\n%lf", F);
    printf("\n%lf", G);
    printf("\n%lf", H);
    printf("\n%lf", I);
    printf("\n%lf", J);
}