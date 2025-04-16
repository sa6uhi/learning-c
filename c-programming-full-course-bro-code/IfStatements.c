#include <stdio.h>

int main()
{
    int x = 5;
    int y = 10;

    // if statement
    if (x < y)
    {
        printf("%d is less than %d\n", x, y);
    }

    // if-else statement
    if (x > y)
    {
        printf("%d is greater than %d\n", x, y);
    }
    else
    {
        printf("%d is not greater than %d\n", x, y);
    }

    // if-else if-else statement
    if (x < y)
    {
        printf("%d is less than %d\n", x, y);
    }
    else if (x == y)
    {
        printf("%d is equal to %d\n", x, y);
    }
    else
    {
        printf("%d is greater than %d\n", x, y);
    }

    int age;

    printf("\nEnter your age: ");
    scanf("%d", &age);

    if (age >= 18)
    {
        printf("You are now signed up!");
    }
    else if (age == 0)
    {
        printf("You can't sign up! You were just born!");
    }
    else if (age < 0)
    {
        printf("You haven't been born yet!");
    }
    else
    {
        printf("You are too young to sign up!");
    }

    return 0;
}

// Shift + Alt + F to format the code
