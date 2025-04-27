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
        printf("Error: Stack Underflow\n");
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

int main(int argc, char const *argv[])
{
    push(2);
    push(5);
    push(10);
    pop();
    push(12);

    return 0;
}
