#include <stdio.h>
#include <stdlib.h>

typedef struct node_t
{
    int data;
    struct node_t *next;
} node_t;

struct node_t* head;

void reverse_recursive(node_t* p) {
    if (p->next == NULL) {
        head = p;
        return;
    }
    reverse_recursive(p->next);
    /* node_t* q = p->next;
    q->next = p;
    p->next = NULL; */ 
    p->next->next = p;
}