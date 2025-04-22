#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Array of Pointers
    // Making an array of integers on the heap is pretty simple:

    int *int_array = malloc(sizeof(int) * 3);
    int_array[0] = 1;
    int_array[1] = 2;
    int_array[2] = 3;

    // But we can also make an array of pointers! It's quite common to do this in C, especially considering that strings are just pointers to chars:

    char **string_array = malloc(sizeof(char *) * 3);
    string_array[0] = "foo";
    string_array[1] = "bar";
    string_array[2] = "baz";
}

typedef struct Token
{
    char *literal;
    int line;
    int column;
} token_t;

token_t **create_token_pointer_array(token_t *tokens, size_t count)
{
    token_t **token_pointers = malloc(count * sizeof(token_t *));
    if (token_pointers == NULL)
    {
        exit(1);
    }
    for (size_t i = 0; i < count; ++i)
    {
        token_t *pointer = malloc(sizeof(token_t));
        token_pointers[i] = pointer;
        *token_pointers[i] = tokens[i];
    }
    return token_pointers;
}
