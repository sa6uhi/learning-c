#include <stdlib.h>
#include <string.h>

typedef enum SnekObjectKind
{
    INTEGER,
    FLOAT,
    STRING,
} snek_object_kind_t;

typedef union SnekObjectData
{
    int v_int;
    float v_float;
    char *v_string;
} snek_object_data_t;

typedef struct SnekObject
{
    snek_object_kind_t kind;
    snek_object_data_t data;
} snek_object_t;

snek_object_t *new_snek_string(char *value)
{
    snek_object_t *obj = malloc(sizeof(snek_object_t));
    if (obj == NULL)
    {
        return NULL;
    }
    obj->kind = STRING;
    obj->data.v_string = malloc(strlen(value) + 1);
    if (obj->data.v_string == NULL)
    {
        free(obj);
        return NULL;
    }
    strcpy(obj->data.v_string, value);

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