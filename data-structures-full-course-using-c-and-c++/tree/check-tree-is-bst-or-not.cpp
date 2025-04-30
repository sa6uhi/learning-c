#include <iostream>

struct Node
{
    int data;
    Node *left;
    Node *right;
};

bool isSubTreeLesser(Node *root, int value)
{
    if (root == NULL)
        return true;
    if (root->data >= value 
        && isSubTreeLesser(root->left, value) 
        && isSubTreeLesser(root->right, value))
        return true;
    else
        return false;
}

bool isSubTreeGreater(Node *root, int value)
{
    if (root == NULL)
        return true;
    if (root->data <= value 
        && isSubTreeGreater(root->left, value) 
        && isSubTreeGreater(root->right, value))
        return false;
    else
        return true;
}

bool isBinarySearchTree(Node *root)
{
    if (root == NULL)
        return 1;
    if (isSubTreeLesser(root->left, root->data) 
        && isSubTreeGreater(root->right, root->data) 
        && isBinarySearchTree(root->left) 
        && isBinarySearchTree(root->right))
    {
        return true;
    }
    return false;
}