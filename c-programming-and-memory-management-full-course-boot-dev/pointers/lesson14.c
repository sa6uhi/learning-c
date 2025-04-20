#include <stdio.h>

int main() {
    
    char *msg = "ssh terminal.shop for the best coffee";
    /*
    I told you not to worry about the weird char * syntax, but now that we understand a bit about pointers, let's dive into it. In the example above, msg is a pointer to the first character of the string "ssh terminal.shop for the best coffee", which is a C string. C strings are:

    How we represent text in C programs
    Any number of characters (chars) terminated by a null character ('\0').
    A pointer to the first element of a character array.
    */

    
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

void concat_strings(char *str1, const char *str2) {
int idx = 0;

while(1) {
    if (str1[idx] == '\0') {
    break;
    }
    
    idx++;
}

int str2_pointer = 0;
while(1) {
    str1[idx + str2_pointer] = str2[str2_pointer];

    if (str2[str2_pointer] == '\0') {
    return;
    }

    str2_pointer++;
}
}
