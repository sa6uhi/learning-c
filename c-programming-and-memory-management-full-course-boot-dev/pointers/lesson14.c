#include <stdio.h>

int main() {
    // Pointers vs. Arrays
    // You can declare strings in C using either arrays or pointers:

    char str1[] = "Hi";
    char *str2 = "Snek";
    printf("%s %s\n", str1, str2);
    // Output: Hi Snek

    // The output is the same. Let's break down the memory of this example:

    // notice we aren't using all 50 characters
    char first[50] = "Snek";
    char *second = "lang!";
    strcat(first, second);
    printf("Hello, %s\n", first);
    // Output: Hello, Sneklang!
}
