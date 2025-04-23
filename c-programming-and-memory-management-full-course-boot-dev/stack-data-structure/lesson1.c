#include <stdlib.h>

typedef struct Stack {
    size_t count;
    size_t capacity;
    void **data;
} stack_t;

stack_t *stack_new(size_t capacity) {
    stack_t *s = malloc(sizeof(stack_t));
    if (s == NULL) {
        return NULL;
    }

    s->count = 0;
    s->capacity = capacity;
    s->data = malloc(sizeof(void *) * capacity);
    if (s->data == NULL) {
        return NULL;
    }

    return s;
}

