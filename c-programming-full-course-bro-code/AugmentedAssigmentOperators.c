#include <stdio.h>

int main(){

    /*
    Augmented Assignment Operators = used to replace a statement 
                                    where an operator takes a variable 
                                    as one of its arguments 
                                    and then assigns the result back to 
                                    the same variable.

                                    x+=1
                                    x = x + 1
    */
    int x = 10;
    x += 2; 
    printf("%d\n", x); // 12

    x -= 2;
    printf("%d\n", x); // 10

    x *= 2;
    printf("%d\n", x); // 20

    x /= 2;
    printf("%d\n", x); // 10
}