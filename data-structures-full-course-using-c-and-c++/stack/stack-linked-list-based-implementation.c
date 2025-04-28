#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    int data;
    struct node_t* next;
} node_t;

struct node_t* top = NULL;

int main() {

}

void push(int data) {
    node_t* temp = (node_t*)malloc(sizeof(node_t));
    temp->data = data;
    temp->next = top;
    top = temp;
}

void pop() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    node_t* temp = top;
    top = top->next;
    free(temp);
}