/*
Free
The free function deallocates memory that was previously allocated by malloc, calloc, or realloc.

IMPORTANT: free does not change the value stored in the memory, and it doesn't even change the address stored in the pointer. Instead, it simply informs the Operating System that the memory can be used again.

Forgetting to free
Forgetting to call free leads to a memory leak. This means that the allocated memory remains occupied and cannot be reused, even though the program no longer needs it. Over time, if a program continues to allocate memory without freeing it, the program may run out of memory and crash.

Memory leaks are one of the most common bugs in C programs, and they can be difficult to track down because the memory is still allocated and accessible, even though it is no longer needed.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int num_lists = 500;
    for (int i = 0; i < num_lists; i++)
    {
        int *lst = allocate_scalar_list(50000, 2);
        if (lst == NULL)
        {
            printf("Failed to allocate list\n");
            return 1;
        }
        else
        {
            printf("Allocated list %d\n", i);
            free(lst); // Free the allocated memory
        }
    }
    return 0;
}

int *allocate_scalar_list(int size, int multiplier)
{
    int *lst = (int *)malloc(size * sizeof(int));
    if (lst == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < size; i++)
    {
        lst[i] = i * multiplier;
    }
    return lst;
}
