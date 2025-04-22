int main() {
    int value;
    int *pointer;
    int **pointer_pointer;

    int v1 = 1;
    int v2 = 2;
    int checkpoint = 0;

    int *ptr = &v1;
    int **ptr_ptr = &ptr;
    checkpoint = **ptr_ptr; // checkpoint = 1

    ptr = &v2;
    checkpoint = **ptr_ptr; // checkpoint = 2
}    

#include "stdlib.h"

void allocate_int(int **pointer_pointer, int value) {
    int *new_pointer = (int *)malloc(sizeof(int));
    *new_pointer = value;
    *pointer_pointer = new_pointer;
}