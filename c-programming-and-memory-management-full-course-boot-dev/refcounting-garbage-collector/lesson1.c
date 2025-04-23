/* Garbage Collector

As you're painfully aware, we've been manually managing memory throughout this course with our C code. However, Sneklang, the language we're building, has automatic memory management. Specifically, it makes use of a garbage collector.

In C and C++, management of heap memory is done manually with malloc and free (and new and delete in C++).
Rust has a compile-time system that ensures memory safety.
Zig gives the programmer access to "allocators" to manage memory.
These are all examples of "manual memory management" - the programmer has to write code that keeps track of and frees memory.

So What's a Garbage Collector?
A garbage collector is a program (or part of a program) that automatically frees memory that is no longer in use. Languages like Python, Java, JavaScript, OCaml, and even Go use garbage collectors as the code is running to manage memory. It's "automatic memory management". Automatic memory management can be a huge productivity boost for developers (less code, and sometimes fewer memory-related bugs) but it typically comes with a performance cost because, like Forrest Gump, the garbage collector is always running.

It's no coincidence that C, C++, Rust, and Zig are all great choices when you need to squeeze every last drop of performance out of your code. */