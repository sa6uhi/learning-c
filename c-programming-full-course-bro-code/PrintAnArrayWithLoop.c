#include <stdio.h>

int main()
{
    double prices[] = {5.0, 10.0, 15.0, 25.0, 20.0, 30.0};

    printf("%d bytes\n", sizeof(prices));

    for (int i = 0; i < sizeof(prices) / sizeof(prices[0]); i++) // 48 bytes / 8 bytes = 6
    {
        printf("$%.2lf\n", prices[i]);
    }

    return 0;
}