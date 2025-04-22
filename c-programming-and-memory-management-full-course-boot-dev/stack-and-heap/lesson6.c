/* 
Malloc
The malloc function (memory allocation) is a standard library function in C that allocates a specified number of bytes of memory on the heap and returns a pointer to the allocated memory.

This new memory is uninitialized, which means:

It contains whatever data was previously at that location.
It is the programmer's responsibility to ensure that the allocated memory is properly initialized and eventually freed using free to avoid memory leaks.
If you want to make sure that the memory is properly initialized, you can use the calloc function, which allocates the specified number of bytes of memory on the heap and returns a pointer to the allocated memory. This memory is initialized to zero (meaning it contains all zeroes).
 */

#include <stdio.h>
#include <stdlib.h> // For malloc and free

// Function Signature
void* malloc(size_t size);
/* size: The number of bytes to allocate.
Returns: A pointer to the allocated memory or NULL if the allocation fails. */

// Example Usage
// Allocates memory for an array of 4 integers
int main() {
    int *ptr = malloc(4 * sizeof(int));
    if (ptr == NULL) {
        // Handle memory allocation failure
        printf("Memory allocation failed\n");
        exit(1);
    }
    // use the memory here
    // ...
    free(ptr); // Free the allocated memory
}

/* 
Manual Memory Management
This idea of manually calling malloc and free is what puts the "manual" in "manually managing memory":

The programmer must remember to eventually free the allocated memory using free(ptr) to avoid memory leaks.
Otherwise, that allocated memory is never returned to the operating system for use by other programs. (Until the program exits, at which point the operating system will clean up after it, but that's not ideal.)
Manually managing memory can be error-prone and tedious, but languages that automatically manage memory (like Python, Java, and C#) have their own trade-offs, usually in terms of performance.
 */

int *allocate_scalar_array(int size, int multiplier) {
    int *result = malloc(size * sizeof(int));
    if (result == NULL) { return NULL; }
    for (int i = 0; i < size; i++) {
        result[i] = i * multiplier;
    }
    return result;
}
  