#include <stdio.h>

int main()
{
    // nested loop = a loop inside of another loop

    int rows; 
    int columns;
    char symbol;

    printf("\nEnter # of rows: ");
    scanf("%d", &rows);

    printf("\nEnter # of columns: ");
    scanf("%d", &columns);

    printf("Enter a symbol to use: ");
    scanf(" %c", &symbol); // space before %c to ignore any whitespace

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= columns; j++)
        {
            printf("%c\t", symbol);
        }
        printf("\n");
    }

    return 0;
}