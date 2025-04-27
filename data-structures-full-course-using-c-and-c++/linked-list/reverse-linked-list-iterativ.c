#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node_t;

node_t* insert(node_t* head, int data) {
    node_t* temp = (node_t *)malloc(sizeof(node_t));
    temp->data = data; temp->next = NULL;
    if (head == NULL) {
        head = temp; // first node
    } else {
        node_t* temp1 = head;
        while (temp1->next != NULL) {
            temp1 = temp1->next; // current points to the last node
        }
        temp1->next = temp; // last node points to the new node
    }
    return head; 
}

void print(node_t* head) {
    while(head != NULL) {
        printf("%d ", head->data); // (*temp).data
        head = head->next; // temp points to the next node
    }
}

node_t* reverse(node_t* head)
{
    node_t *current, *prev, *next;
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next; 
    }
    head = prev; // head points to the last node
    return head; // return the new head of the linked list
}

int main()
{
    node_t* head = NULL;
    head = insert(head, 2);
    head = insert(head, 4);
    head = insert(head, 6);
    head = insert(head, 8);
    print(head);
    printf("\n");
    head = reverse(head); 
    print(head);

}