#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data; // char* data
    struct Node* next;
} node_t;

struct Node* head; // global variable, can be accessed from anywhere in the program
void Insert(int x)
{
    node_t* temp = (node_t *)malloc(sizeof(node_t));
    temp->data = x; // (*temp).data = x;
    temp->next = head; // first node
    head = temp; // head points to the first node 
}
void Print() {
    node_t* temp = head; // temp points to the first node
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data); // (*temp).data
        temp = temp->next; // temp points to the next node
    }
    printf("\n");
}

int main()
{
    head = NULL; // empty linked list

    printf("How many numbers?\n");
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the number:\n");
        scanf("%d", &x);
        Insert(x);
        Print();
    }


    return 0;
}
