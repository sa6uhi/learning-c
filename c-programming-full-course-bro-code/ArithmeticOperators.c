#include <stdio.h>

int main(){

    // arithmetic operators:
    /*
    1. + (addition)
    2. - (subtraction)
    3. * (multiplication)
    4. / (division)
    5. % (modulus)
    6. ++ (increment)
    7. -- (decrement)
    */

    int x = 5;
    int y = 2;

    int z = x + y; 
    
    printf("%d\n", z); 

    int x1 = x / y;
    printf("%d\n", x1); // 2

    float a = x / y;
    printf("%f\n", a); // 2.0

    float a1 = (float)x / y; // or float a1 = x / (float)y;
    printf("%f\n", a1); // 2.5

    x++;
    return 0;
}