#include <stdio.h>
#include <stdlib.h>

typedef struct node_t
{
    int data;
    struct node_t *next;
} node_t;

node_t *insert(node_t *head, int data)
{
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp; // first node
    }
    else
    {
        node_t *temp1 = head;
        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
    return head;
}

void print(node_t *p)
{
    if (p == NULL)
    {
        return;
    }
    printf("%d ", p->data);
    if (p->next != NULL)
    {
        print(p->next);
    }
}

void print_reverse(node_t *p)
{
    if (p == NULL)
    {
        return;
    }
    if (p->next != NULL)
    {
        print_reverse(p->next);
    }
    printf("%d ", p->data);
}

int main()
{
    node_t *head = NULL;
    head = insert(head, 2);
    head = insert(head, 4);
    head = insert(head, 6);
    head = insert(head, 5);

    print(head);
    printf("\n");
    print_reverse(head);

    return 0;
}
