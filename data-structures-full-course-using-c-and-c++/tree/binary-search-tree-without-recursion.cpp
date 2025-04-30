#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int key)
{
    Node *node = new Node;
    node->data = key;
    node->left = node->right = nullptr;

    return node;
}

void insert(Node **headref, int data)
{

    if (*headref == NULL)
    {
        *headref = newNode(data);
        return;
    }

    Node *travptr = *headref;
    Node *parentNode = NULL;

    while (travptr != NULL)
    {
        parentNode = travptr;
        travptr = (data > travptr->data) ? travptr->right : travptr->left;
    }

    if (data > parentNode->data)
        parentNode->right = newNode(data);

    else
        parentNode->left = newNode(data);
}

bool find(Node **headref, int data)
{
    Node *travptr = *headref;

    if (data == (*headref)->data)
        return true;

    while (travptr != NULL && travptr->data != data)
        travptr = (data > travptr->data) ? travptr->right : travptr->left;

    if (travptr == NULL)
    {
        return false;
    }
    return true;
}

int main()
{

    Node *head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    cout << find(&head, 3) << "\t" << find(&head, 10);
    return 0;
}