/*
The realloc function is used to resize memory that was previously allocated with malloc or calloc. It takes a pointer to the old memory and the new size, and returns a pointer to the new memory:

void *realloc(void *ptr, size_t size);

int *smol_boi = malloc(10 * sizeof(int));
int *large_boi = realloc(smol_boi, 20 * sizeof(int));
*/

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

void stack_push(stack_t *stack, void *obj)
{
    if (stack->count >= stack->capacity)
    {
        stack->capacity *= 2;
        stack->data = realloc(stack->data, stack->capacity * sizeof(void *));
        if (stack->data == NULL) { return; }
    }
    stack->data[stack->count] = obj;
    stack->count++;
}

stack_t *stack_new(size_t capacity)
{
    stack_t *stack = malloc(sizeof(stack_t));
    if (stack == NULL)
    {
        return NULL;
    }

    stack->count = 0;
    stack->capacity = capacity;
    stack->data = malloc(stack->capacity * sizeof(void *));
    if (stack->data == NULL)
    {
        free(stack);
        return NULL;
    }

    return stack;
}

typedef struct Stack
{
    size_t count;
    size_t capacity;
    void **data;
} stack_t;