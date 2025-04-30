#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
};

int findHeight(Node* root) {
    if (root == NULL) {
        return -1; // Return -1 for null nodes to count edges
    }
    return std::max(findHeight(root->left), findHeight(root->right)) + 1; // Add 1 for the current node
}