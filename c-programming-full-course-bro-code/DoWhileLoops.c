#include <stdio.h>

int main()
{
    // while loop = checks a condition, then executes a block of code if condition is true
    // do while loop = always executes a block of code once, then checks a condition, if true, continue another loop

    int number = 0;
    int sum = 0;

    /*while(number > 0)
    {
        printf("Enter a number above 0: ");
        scanf("%d", &number);
        if(number > 0)
        {
            sum += number;
        }
    }*/

    
    do
    {
        printf("Enter a number above 0: ");
        scanf("%d", &number);
        if (number > 0)
        {
            sum += number;
        }
    } while (number > 0);

    printf("sum: %d", sum);

    return 0;
}