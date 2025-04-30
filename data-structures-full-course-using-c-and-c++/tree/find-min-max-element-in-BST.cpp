#include <iostream>

typedef struct bstNode_t
{
    int data;
    struct bstNode_t *left;
    struct bstNode_t *right;
} bstNode_t;

int findMin(bstNode_t *root)
{
    if (root == NULL)
    {
        std::cout << "Tree is empty" << std::endl;
        return -1; // Tree is empty
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

int findMax(bstNode_t *root)
{
    if (root == NULL)
    {
        std::cout << "Tree is empty" << std::endl;
        return -1; // Tree is empty
    }
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}

int findMinRec(bstNode_t *root)
{
    if (root == NULL)
    {
        std::cout << "Tree is empty" << std::endl;
        return -1; // Tree is empty
    }
    if (root->left == NULL)
    {
        return root->data;
    }
    return findMinRec(root->left);
}

int findMaxRec(bstNode_t *root)
{
    if (root == NULL)
    {
        std::cout << "Tree is empty" << std::endl;
        return -1; // Tree is empty
    }
    if (root->right == NULL)
    {
        return root->data;
    }
    return findMaxRec(root->right);
}