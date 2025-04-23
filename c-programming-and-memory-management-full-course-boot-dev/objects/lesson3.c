typedef enum SnekObjectKind
{
    INTEGER,
    FLOAT,
} snek_object_kind_t;

typedef union SnekObjectData
{
    int v_int;
    float v_float;
} snek_object_data_t;

typedef struct SnekObject
{
    snek_object_kind_t kind;
    snek_object_data_t data;
} snek_object_t;

#include <stdlib.h>

snek_object_t *new_snek_float(float value)
{
    snek_object_t *obj = malloc(sizeof(snek_object_t));
    if (obj == NULL)
    {
        return NULL;
    }

    obj->kind = FLOAT;
    obj->data.v_float = value;
    return obj;
}

snek_object_t *new_snek_integer(int value)
{
    snek_object_t *obj = malloc(sizeof(snek_object_t));
    if (obj == NULL)
    {
        return NULL;
    }

    obj->kind = INTEGER;
    obj->data.v_int = value;
    return obj;
}
