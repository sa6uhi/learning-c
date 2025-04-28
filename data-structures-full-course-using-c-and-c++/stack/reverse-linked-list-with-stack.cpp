#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

typedef struct node_t
{
    int data;
    struct node_t *next;
} node_t;

struct node_t *head;

int main()
{
}

void reverse()
{
    if (head == NULL)
    {
        return;
    }

    stack<node_t *> S;
    node_t *temp = head;
    while (temp != NULL)
    {
        S.push(temp);
        temp = temp->next;
    }

    temp = S.top();
    head = temp;
    S.pop();
    while (!S.empty())
    {
        temp->next = S.top();
        S.pop();
        temp = temp->next;
    }
    temp->next = NULL;
}