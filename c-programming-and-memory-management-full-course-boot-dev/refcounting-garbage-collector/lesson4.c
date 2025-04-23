/* Decrement and free
Now things are going to get a touch more complicated. In a refcounting GC, the interesting stuff happens when the refcount equals 0. That's when the garbage gets collected.

When the refcount reaches 0, there are no references to this object anymore! So, we need to free the memory automagically -- that's the whole point of a garbage collector.

For our first pass at this, we will only handle integers, floats and strings to keep things simple. As we go a little further, we'll implement it for the rest of the SnekObject types. */

#include <stdbool.h>
#include <stddef.h>

typedef struct SnekObject snek_object_t;

typedef struct
{
    size_t size;
    snek_object_t **elements;
} snek_array_t;

typedef struct
{
    snek_object_t *x;
    snek_object_t *y;
    snek_object_t *z;
} snek_vector_t;

typedef enum SnekObjectKind
{
    INTEGER,
    FLOAT,
    STRING,
    VECTOR3,
    ARRAY,
} snek_object_kind_t;

typedef union SnekObjectData
{
    int v_int;
    float v_float;
    char *v_string;
    snek_vector_t v_vector3;
    snek_array_t v_array;
} snek_object_data_t;

typedef struct SnekObject
{
    int refcount;
    snek_object_kind_t kind;
    snek_object_data_t data;
} snek_object_t;

snek_object_t *new_snek_integer(int value);
snek_object_t *new_snek_float(float value);
snek_object_t *new_snek_string(char *value);
snek_object_t *new_snek_vector3(
    snek_object_t *x, snek_object_t *y, snek_object_t *z);
snek_object_t *new_snek_array(size_t size);

void refcount_inc(snek_object_t *obj);
void refcount_dec(snek_object_t *obj);
void refcount_free(snek_object_t *obj);

// EXERCISE

#include "assert.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void refcount_dec(snek_object_t *obj)
{
    if (obj == NULL)
    {
        return;
    }

    obj->refcount--;

    if (obj->refcount == 0)
    {
        refcount_free(obj);
    }
}

void refcount_free(snek_object_t *obj)
{
    if (obj == NULL)
    {
        return;
    }

    switch (obj->kind)
    {
        case INTEGER:
        {
            break;
        }
        case FLOAT:
        {
            break;
        }
        case STRING:
        {
            free(obj->data.v_string);
            break;
        }
    }
    free(obj);
}

void refcount_inc(snek_object_t *obj)
{
    if (obj == NULL)
    {
        return;
    }

    obj->refcount++;
    return;
}

snek_object_t *_new_snek_object()
{
    snek_object_t *obj = calloc(1, sizeof(snek_object_t));
    if (obj == NULL)
    {
        return NULL;
    }

    obj->refcount = 1;

    return obj;
}

snek_object_t *new_snek_array(size_t size)
{
    snek_object_t *obj = _new_snek_object();
    if (obj == NULL)
    {
        return NULL;
    }

    snek_object_t **elements = calloc(size, sizeof(snek_object_t *));
    if (elements == NULL)
    {
        free(obj);
        return NULL;
    }

    obj->kind = ARRAY;
    obj->data.v_array = (snek_array_t){.size = size, .elements = elements};

    return obj;
}

snek_object_t *new_snek_vector3(
    snek_object_t *x, snek_object_t *y, snek_object_t *z)
{
    if (x == NULL || y == NULL || z == NULL)
    {
        return NULL;
    }

    snek_object_t *obj = _new_snek_object();
    if (obj == NULL)
    {
        return NULL;
    }

    obj->kind = VECTOR3;
    obj->data.v_vector3 = (snek_vector_t){.x = x, .y = y, .z = z};

    return obj;
}

snek_object_t *new_snek_integer(int value)
{
    snek_object_t *obj = _new_snek_object();
    if (obj == NULL)
    {
        return NULL;
    }

    obj->kind = INTEGER;
    obj->data.v_int = value;
    return obj;
}

snek_object_t *new_snek_float(float value)
{
    snek_object_t *obj = _new_snek_object();
    if (obj == NULL)
    {
        return NULL;
    }

    obj->kind = FLOAT;
    obj->data.v_float = value;
    return obj;
}

snek_object_t *new_snek_string(char *value)
{
    snek_object_t *obj = _new_snek_object();
    if (obj == NULL)
    {
        return NULL;
    }

    int len = strlen(value);
    char *dst = malloc(len + 1);
    if (dst == NULL)
    {
        free(obj);
        return NULL;
    }

    strcpy(dst, value);

    obj->kind = STRING;
    obj->data.v_string = dst;
    return obj;
}
