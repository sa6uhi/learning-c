#include <stdio.h>
#include <stdbool.h>

int main()
{

    // logical operators = &&(AND) checks if two conditions are true

    float temp = 25;
    bool sunny = false;

    if (temp >= 0 && temp <= 30 && sunny)
    {
        printf("The weather is good!\n");
    }
    else
    {
        printf("The weather is bad!\n");
    }

    return 0;
}