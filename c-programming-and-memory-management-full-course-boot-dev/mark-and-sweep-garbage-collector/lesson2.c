/*
Pros and Cons
To solve our cyclic reference issue (and to force you to implement another GC algorithm, HA!) we're going to implement a Mark and Sweep garbage collector.

Pros of MaS
Can detect cycles, and thus prevent memory leaks in certain cases
Less on-demand bookkeeping (Remember: all work done by the GC is "wasted" - it doesn't make your GPT-4 wrapper custom AI product run any faster)
Reduces potential performance degradation in highly multithreaded programs (refcounting requires atomic updates for thread safety)
Cons of MaS
More complex to implement (heh, you'll see)
Can cause "stop-the-world" pauses when lots of objects exist and must be freed (resulting in poor performance)
Higher memory overhead
Less predictable performance (refcounting is O(1) - Mark and Sweep is O(n), where n is the number of objects in memory)
*/

#include "vm.h"

vm_t *vm_new()
{
    vm_t *vm = malloc(sizeof(vm_t));
    if (vm == NULL)
    {
        return NULL;
    }

    vm->frames = stack_new(8);
    if (vm->frames == NULL)
    {
        free(vm);
        return NULL;
    }

    vm->objects = stack_new(8);
    if (vm->objects == NULL)
    {
        free(vm);
        return NULL;
    }

    return vm;
}

void vm_free(vm_t *vm)
{
    if (vm == NULL)
    {
        return;
    }

    stack_free(vm->frames);
    stack_free(vm->objects);
    free(vm);
}