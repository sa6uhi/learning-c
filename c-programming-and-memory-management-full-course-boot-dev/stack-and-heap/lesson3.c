#include <stdio.h>

/* 
Stack Overflow
So the stack is great and all, but one of the downsides is that it has a limited size. If you keep pushing frames onto the stack without popping them off, you'll eventually run out of memory and get a stack overflow. (yes, that's what the famous site is named after)

That's one of the reasons recursion without tail-call optimization can be dangerous. Each recursive call pushes a new frame onto the stack, and if you have too many recursive calls, you'll run out of stack space.
 */


/* 
int main() {
    const int pool_size = 1024 * 10;
    char snek_pool[pool_size];
    snek_pool[0] = 's';
    snek_pool[1] = 'n';
    snek_pool[2] = 'e';
    snek_pool[3] = 'k';
    snek_pool[4] = '\0';

    printf("Size of pool: %d\n", pool_size);
    printf("Initial string: %s\n", snek_pool);
    return 0;
}
 */