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

void InsertPosition(int x, int pos) {
    node_t* temp1 = (node_t *)malloc(sizeof(node_t));
    temp1->data = x;
    temp1->next = NULL; 
    if (pos == 1) {
        temp1->next = head; 
        head = temp1;
        return;
    }
    node_t* temp2 = head;
    for (int i =0; i < pos - 2; i++) {
        if (temp2 == NULL) {
            printf("Position out of range\n");
            return;
        }
        temp2 = temp2->next; // temp2 points to the next node
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
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

    head = NULL;
    InsertPosition(2, 1); // Linked List: 2
    InsertPosition(3, 2); // Linked List: 2 3
    InsertPosition(4, 1); // Linked List: 4 2 3
    InsertPosition(5, 2); // Linked List: 4 5 2 3
    Print();
    return 0;
}
