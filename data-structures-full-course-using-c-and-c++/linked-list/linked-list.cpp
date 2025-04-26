#include <cstdio>

typedef struct Node {
    int data;
    struct Node* link;
} node_t;

int main() {
    node_t* A;
    A = nullptr; // emply linked list
    
    // Add first node (2)
    node_t* temp = new node_t;
    temp->data = 2;
    temp->link = nullptr;
    A = temp; // A points to the first node

    // Add second node (4)
    temp = new node_t;
    temp->data = 4;
    temp->link = nullptr;
    A->link = temp; // A → 2 → 4

    // Add third node (6)
    temp = new node_t;
    temp->data = 6;
    temp->link = nullptr;
    A->link->link = temp;  // A → 2 → 4 → 6

    // Add fourth node (8) with while loop | Traverse to the end of the list
    temp = new node_t;
    temp->data = 8;
    temp->link = nullptr;

    node_t* last = A;
    while (last->link != nullptr) {
        last = last->link; // Traverse to the last node
    }
    last->link = temp; // Append new node at the end


    
    // Free all nodes (avoid memory leaks)
    node_t* current = A;
    while (current != nullptr) {
        node_t* next = current->link;
        delete current;
        current = next;
    }

    return 0;

}

void addNode(node_t** head, int value) {
    node_t* newNode = new node_t; // node_t* newNode = new node_t{value, nullptr}; 
    newNode->data = value;
    newNode->link = nullptr;

    if (*head == nullptr) {
        *head = newNode; // If list is empty, newNode becomes head
        return;
    }

    node_t* temp = *head;
    while (temp->link != nullptr) {
        temp = temp->link;
    }
    temp->link = newNode; // Append newNode at the end
}

void printList(node_t* head) {
    node_t* temp = head;
    while (temp != nullptr) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("nullptr\n");
}