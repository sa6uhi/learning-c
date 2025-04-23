#include <stdlib.h>
#include <string.h>

typedef struct SnekObject snek_object_t;

typedef enum SnekObjectKind
{
    INTEGER,
    FLOAT,
    STRING,
    VECTOR3,
} snek_object_kind_t;

typedef struct SnekVector
{
    snek_object_t *x;
    snek_object_t *y;
    snek_object_t *z;
} snek_vector_t;

typedef union SnekObjectData
{
    int v_int;
    float v_float;
    char *v_string;
    snek_vector_t v_vector3;
} snek_object_data_t;

typedef struct SnekObject
{
    snek_object_kind_t kind;
    snek_object_data_t data;
} snek_object_t;

snek_object_t *new_snek_vector3(
    snek_object_t *x, snek_object_t *y, snek_object_t *z)
{
    if (x == NULL || y == NULL || z == NULL)
    {
        return NULL;
    }
    snek_object_t *obj = malloc(sizeof(snek_object_t));
    if (obj == NULL)
    {
        return NULL;
    }

    obj->kind = VECTOR3;
    obj->data.v_vector3.x = x;
    obj->data.v_vector3.y = y;
    obj->data.v_vector3.z = z;
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

snek_object_t *new_snek_string(char *value)
{
    snek_object_t *obj = malloc(sizeof(snek_object_t));
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
