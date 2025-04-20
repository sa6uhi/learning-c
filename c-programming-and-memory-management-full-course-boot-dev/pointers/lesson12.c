#include <stdio.h>

int main()
{
    // Pointer Example
    int *intPtr;
    char *charPtr;
    double *doublePtr;
    printf("Size of int pointer: %zu bytes\n", sizeof(intPtr));
    printf("Size of char pointer: %zu bytes\n", sizeof(charPtr));
    printf("Size of double pointer: %zu bytes\n", sizeof(doublePtr));
    // Size of int pointer: 4 bytes
    // Size of char pointer: 4 bytes
    // Size of double pointer: 4 bytes
    // They're all the same size, because they're all just 32-bit memory addresses: it doesn't matter how much memory the value at that address takes up.

    // Array Example
    int intArray[10];
    char charArray[10];
    double doubleArray[10];
    printf("Size of int array: %zu bytes\n", sizeof(intArray));
    printf("Size of char array: %zu bytes\n", sizeof(charArray));
    printf("Size of double array: %zu bytes\n", sizeof(doubleArray));
    // Size of int array: 40 bytes
    // Size of char array: 10 bytes
    // Size of double array: 80 bytes
}