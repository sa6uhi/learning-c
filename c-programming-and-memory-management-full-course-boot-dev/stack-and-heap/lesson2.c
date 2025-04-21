/* 
Why a Stack?
Allocating memory on the stack is preferred when possible because the stack is faster and simpler than the heap (which we'll get to, be patient):

Efficient Pointer Management: Stack "allocation" is just a quick increment or decrement of the stack pointer, which is extremely fast. Heap allocations require more complex bookkeeping.
Cache-Friendly Memory Access: Stack memory is stored in a contiguous block, enhancing cache performance due to spatial locality.
Automatic Memory Management: Stack memory is managed automatically as functions are called and as they return.
Inherent Thread Safety: Each thread has its own stack. Heap allocations require synchronization mechanisms when used concurrently, potentially introducing overhead.
 */