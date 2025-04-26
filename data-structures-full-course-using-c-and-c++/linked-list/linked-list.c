#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* link;
} node_t;

int main() {
    node_t* A;
    A = NULL; // emply linked list
    
    node_t* temp = (node_t *)malloc(sizeof(node_t));

    (*temp).data = 2; // temp->data = 2;
    (*temp).link = NULL; // temp->link = NULL;
    A = temp; // A points to the first node

    temp = (node_t *)malloc(sizeof(node_t));
    (*temp).data = 3;
    (*temp).link = NULL;
    A->link = temp; // A points to the second node
}