/*
Struct Padding
There are a bunch of complicated rules and heuristics that different compilers use to determine how to lay out your structs. But to oversimplify:

The fields of a struct are laid out in memory contiguously (next to each other)
Structs can vary in size depending on how they are laid out.
C is a language that aims to give tight control over memory, so the fact that you can control the layout of your structs is a feature, not a bug.

Compilers + modern hardware + optimizations + skill issues means that sometimes what you think the computer is going to do isn't exactly what it actually does. That said, C is designed to get you close to the machine and allows you to dig in and figure out what's going on if you want to for a specific compiler or architecture.

As a rule of thumb, ordering your fields from largest to smallest will help the compiler minimize padding:
*/

typedef struct {
  char a;
  double b;
  char c;
  char d;
  long e;
  char f;
} poorly_aligned_t;

typedef struct {
  double b;
  long e;
  char a;
  char c;
  char d;
  char f;
} better_t;