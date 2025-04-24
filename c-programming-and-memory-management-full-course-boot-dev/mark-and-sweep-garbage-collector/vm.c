#include "vm.h"
#include "snekobject.h"
#include "stack.h"

void vm_track_object(vm_t *vm, snek_object_t *obj)
{
    if (vm == NULL || obj == NULL)
    {
        return;
    }

    stack_push(vm->objects, (void *)obj);
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
    for (int i = 0; i < vm->frames->count; i++)
    {
        frame_free(vm->frames->data[i]);
    }
    stack_free(vm->frames);
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
