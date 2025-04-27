#include <stdlib.h>

typedef struct node_t
{
    int data;
    struct node_t* next;
    struct node_t* prev;
} node_t;

struct node_t* head;

node_t* get_new_node(int x) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = x;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void insert_at_head(int x) {
    node_t* new_node = get_new_node(x);
    if (head == NULL) {
        head = new_node;
        return;
    }
    head->prev = new_node;
    new_node->next = head;
    head = new_node;
}

