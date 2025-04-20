#include <stdio.h>

int main()
{
  int age = 37;
  printf("The address of age is: %p\n", &age);
  return 0;
}

// The address of age is: 0xfff8

unsigned long size_of_addr(long long i)
{
  unsigned long sizeof_snek_version = sizeof(&i);
  return sizeof_snek_version;
}