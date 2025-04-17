#include <stdio.h>
#include <string.h>


int main()
{
    char x = 'X';
    char y = 'Y';
    char temp;

    temp = x;
    x = y;
    y = temp;

    char a[15] = "water";  
    char b[15] = "lemo"; // we need to make sure that the length of "a" and "b" are the same
    char temp2[15];


    strcpy(temp2, a);
    strcpy(a, b);
    strcpy(b, temp2);

    printf("a = %s\n", a);
    printf("b = %s\n", b);


    printf("x = %c\n", x);
    printf("y = %c\n", y);

    return 0;
}