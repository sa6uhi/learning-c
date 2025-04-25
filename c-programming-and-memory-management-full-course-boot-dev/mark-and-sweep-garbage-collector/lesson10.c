#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct VirtualMachine
{
    stack_t *frames;
    stack_t *objects;
} vm_t;

typedef struct StackFrame
{
    stack_t *references;
} frame_t;

/// Our main functions for garbage collection.
void mark(vm_t *vm);
void trace(vm_t *vm);
void sweep(vm_t *vm);

/// This is the function that gets called to actually do the garbage collection,
/// but is just composed of `mark`, `trace`, and `sweep`.
///
/// Don't worry, it's not going to delete your code (hopefully!)
void vm_collect_garbage(vm_t *vm);

/// Already implemented
vm_t *vm_new();
void vm_free(vm_t *vm);
void vm_track_object(vm_t *vm, snek_object_t *obj);

void vm_frame_push(vm_t *vm, frame_t *frame);
frame_t *vm_new_frame(vm_t *vm);

void frame_free(frame_t *frame);

// Marks the object as referenced in the current stack frame.
void frame_reference_object(frame_t *frame, snek_object_t *obj);

typedef struct Stack
{
    size_t count;
    size_t capacity;
    void **data;
} stack_t;

stack_t *stack_new(size_t capacity);

void stack_push(stack_t *stack, void *obj);
void *stack_pop(stack_t *stack);

void stack_free(stack_t *stack);
void stack_remove_nulls(stack_t *stack);

void stack_push(stack_t *stack, void *obj)
{
    assert_ptr_not_null(obj, "must not have null obj");

    if (stack->count == stack->capacity)
    {
        // Double stack capacity to avoid reallocing often
        stack->capacity *= 2;
        stack->data = realloc(stack->data, stack->capacity * sizeof(void *));
        if (stack->data == NULL)
        {
            // Unable to realloc, just exit :) get gud
            exit(1);
        }
    }

    stack->data[stack->count] = obj;
    stack->count++;

    return;
}

void *stack_pop(stack_t *stack)
{
    if (stack->count == 0)
    {
        return NULL;
    }

    stack->count--;
    return stack->data[stack->count];
}

void stack_free(stack_t *stack)
{
    if (stack == NULL)
    {
        return;
    }

    if (stack->data != NULL)
    {
        free(stack->data);
    }

    free(stack);
}

void stack_remove_nulls(stack_t *stack)
{
    size_t new_count = 0;

    // Iterate through the stack and compact non-NULL pointers.
    for (size_t i = 0; i < stack->count; ++i)
    {
        if (stack->data[i] != NULL)
        {
            stack->data[new_count++] = stack->data[i];
        }
    }

    // Update the count to reflect the new number of elements.
    stack->count = new_count;

    // Optionally, you might want to zero out the remaining slots.
    for (size_t i = new_count; i < stack->capacity; ++i)
    {
        stack->data[i] = NULL;
    }
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
    bool is_marked;

    snek_object_kind_t kind;
    snek_object_data_t data;
} snek_object_t;

void snek_object_free(snek_object_t *obj);

void snek_object_free(snek_object_t *obj)
{
    switch (obj->kind)
    {
    // Integers and floats are allocated within the object, so nothing to free
    case INTEGER:
    case FLOAT:
        break;
    case STRING:
        // Free the allocated data for the string
        free(obj->data.v_string);
        break;
    case VECTOR3:
    {
        // Since x, y, and z are all allocated within the `snek_object_t`,
        // there is nothing additional for us to free here!
        break;
    }
    case ARRAY:
    {
        // Free the element list, but not the elements themselves.
        //  The rest of the mark-and-sweep algorithm will take care of that.
        snek_array_t *array = &obj->data.v_array;
        free(array->elements);

        break;
    }
    }

    free(obj);
}

snek_object_t *new_snek_integer(vm_t *vm, int value);
snek_object_t *new_snek_float(vm_t *vm, float value);
snek_object_t *new_snek_string(vm_t *vm, char *value);
snek_object_t *new_snek_vector3(
    vm_t *vm, snek_object_t *x, snek_object_t *y, snek_object_t *z);
snek_object_t *new_snek_array(vm_t *vm, size_t size);

snek_object_t *_new_snek_object(vm_t *vm)
{
    snek_object_t *obj = calloc(1, sizeof(snek_object_t));
    if (obj == NULL)
    {
        return NULL;
    }

    obj->is_marked = false;

    vm_track_object(vm, obj);

    return obj;
}

snek_object_t *new_snek_array(vm_t *vm, size_t size)
{
    snek_object_t *obj = _new_snek_object(vm);
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
    vm_t *vm, snek_object_t *x, snek_object_t *y, snek_object_t *z)
{
    if (x == NULL || y == NULL || z == NULL)
    {
        return NULL;
    }

    snek_object_t *obj = _new_snek_object(vm);
    if (obj == NULL)
    {
        return NULL;
    }

    obj->kind = VECTOR3;
    obj->data.v_vector3 = (snek_vector_t){.x = x, .y = y, .z = z};

    return obj;
}

snek_object_t *new_snek_integer(vm_t *vm, int value)
{
    snek_object_t *obj = _new_snek_object(vm);
    if (obj == NULL)
    {
        return NULL;
    }

    obj->kind = INTEGER;
    obj->data.v_int = value;

    return obj;
}

snek_object_t *new_snek_float(vm_t *vm, float value)
{
    snek_object_t *obj = _new_snek_object(vm);
    if (obj == NULL)
    {
        return NULL;
    }

    obj->kind = FLOAT;
    obj->data.v_float = value;
    return obj;
}

snek_object_t *new_snek_string(vm_t *vm, char *value)
{
    snek_object_t *obj = _new_snek_object(vm);
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

void trace(vm_t *vm)
{
    if (vm == NULL)
    {
        return;
    }

    stack_t *gray_objects = stack_new(8);
    if (gray_objects == NULL)
    {
        return;
    }

    for (size_t i = 0; i < vm->objects->count; i++)
    {
        snek_object_t *obj = vm->objects->data[i];
        if (obj && obj->is_marked)
        {
            stack_push(gray_objects, obj);
        }
    }

    while (gray_objects->count > 0)
    {
        snek_object_t *obj = stack_pop(gray_objects);
        trace_blacken_object(gray_objects, obj);
    }

    stack_free(gray_objects);
}

void trace_blacken_object(stack_t *gray_objects, snek_object_t *obj)
{
    // if (obj->kind == INTEGER || obj->kind == FLOAT || obj->kind == STRING)
    // {
    //     return;
    // }

    switch (obj->kind)
    {
    case INTEGER:
        return;
    case FLOAT:
        return;
    case STRING:
        return;
    case VECTOR3:
        trace_mark_object(gray_objects, obj->data.v_vector3.x);
        trace_mark_object(gray_objects, obj->data.v_vector3.y);
        trace_mark_object(gray_objects, obj->data.v_vector3.z);
        break;
    case ARRAY:
        snek_array_t arr = obj->data.v_array;
        for (size_t i = 0; i < arr.size; i++)
        {
            trace_mark_object(gray_objects, snek_arrat_get(obj, i));
        }
        break;
    }
}

void trace_mark_object(stack_t *gray_objects, snek_object_t *obj)
{
    if (obj == NULL || obj->is_marked)
    {
        return;
    }

    obj->is_marked = true;
    stack_push(gray_objects, (void *)obj);
}

void vm_collect_garbage(vm_t *vm)
{
    mark(vm);
    trace(vm);
    sweep(vm);
}

void sweep(vm_t *vm)
{
    for (size_t i = 0; i < vm->objects->count; i++)
    {
        snek_object_t *obj = vm->objects->data[i];

        if (obj->is_marked)
        {
            obj->is_marked = false;
        }
        else
        {
            snek_object_free(obj);
            vm->objects->data[i] = NULL;
        }
    }

    stack_remove_nulls(vm->objects);
}

void mark(vm_t *vm)
{
    for (size_t i = 0; i < vm->frames->count; i++)
    {
        frame_t *frame = vm->frames->data[i];
        for (size_t j = 0; j < frame->references->count; j++)
        {
            snek_object_t *obj = frame->references->data[j];
            obj->is_marked = true;
        }
    }
}

void frame_reference_object(frame_t *frame, snek_object_t *obj)
{
    stack_push(frame->references, obj);
}

vm_t *vm_new()
{
    vm_t *vm = malloc(sizeof(vm_t));
    if (vm == NULL)
    {
        return NULL;
    }

    vm->frames = stack_new(8);
    vm->objects = stack_new(8);
    return vm;
}

void vm_free(vm_t *vm)
{
    // Free the stack frames, and then their container
    for (int i = 0; i < vm->frames->count; i++)
    {
        frame_free(vm->frames->data[i]);
    }
    stack_free(vm->frames);

    // Free the objects, and then their container
    for (int i = 0; i < vm->objects->count; i++)
    {
        snek_object_free(vm->objects->data[i]);
    }
    stack_free(vm->objects);

    free(vm);
}

void vm_frame_push(vm_t *vm, frame_t *frame)
{
    stack_push(vm->frames, frame);
}

frame_t *vm_new_frame(vm_t *vm)
{
    frame_t *frame = malloc(sizeof(frame_t));
    frame->references = stack_new(8);

    vm_frame_push(vm, frame);
    return frame;
}

void frame_free(frame_t *frame)
{
    stack_free(frame->references);
    free(frame);
}

void vm_track_object(vm_t *vm, snek_object_t *obj)
{
    stack_push(vm->objects, obj);
}
