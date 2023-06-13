#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to perform in-order traversal of the BST
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node *root = newNode(5);
    root->left        = newNode(3);
    root->right       = newNode(7);
	root->right->left = newNode(6);
    root->left->left  = newNode(2);
    root->left->right = newNode(4);
	root->left->left->left = newNode(1);
	//5 3 7 2 4 6 1
    inorder(root);
 
    return 0;
}
