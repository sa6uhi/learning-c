#include <stdio.h>
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

void print_doubly_linked_list() {
    node_t* temp = head;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void print_reverse_doubly_linked_list() {
    node_t* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("Reverse: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    head = NULL;
    insert_at_head(1); print_doubly_linked_list(); print_reverse_doubly_linked_list();
    insert_at_head(2); print_doubly_linked_list(); print_reverse_doubly_linked_list();
    insert_at_head(3); print_doubly_linked_list(); print_reverse_doubly_linked_list();
    insert_at_head(4); print_doubly_linked_list(); print_reverse_doubly_linked_list();
    insert_at_head(5); print_doubly_linked_list(); print_reverse_doubly_linked_list();

    return 0;
}
