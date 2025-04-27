#include <stdio.h>
#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

void push(int x) {
    if (top == MAX_SIZE - 1) {
        printf("Error: Stack Overflow\n");
        return;
    }
    // top++;
    // A[top] = x;
    A[++top] = x;
}

void pop() {
    if (top == -1) {
        printf("Error: Stack Underflow(No element to pop)\n");
        return;
    }
    // top--;
    // return A[top + 1];
    top--;
}

int top_element() {
    if (top == -1) {
        printf("Error: Stack is empty\n");
        return -1;
    }
    return A[top];
}

void print_stack() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    push(2); print_stack();
    push(5); print_stack();
    push(10); print_stack();
    pop(); print_stack();
    push(12); print_stack();

    return 0;
}
