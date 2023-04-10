#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct sbb_node {
    int value;
    struct sbb_node* left;
    struct sbb_node* right;
    int level;
} sbb_node;

sbb_node* sbb_new_node(int value) {
    sbb_node* node = (sbb_node*)malloc(sizeof(sbb_node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->level = 0;
    return node;
}

sbb_node* sbb_skew(sbb_node* node) {
    if (node == NULL) {
        return NULL;
    } else if (node->left == NULL) {
        return node;
    } else if (node->left->level == node->level) {
        sbb_node* left = node->left;
        node->left = left->right;
        left->right = node;
        return left;
    } else {
        return node;
    }
}

sbb_node* sbb_split(sbb_node* node) {
    if (node == NULL) {
        return NULL;
    } else if (node->right == NULL || node->right->right == NULL) {
        return node;
    } else if (node->level == node->right->right->level) {
        sbb_node* right = node->right;
        node->right = right->left;
        right->left = node;
        right->level = right->level + 1;
        return right;
    } else {
        return node;
    }
}

sbb_node* sbb_insert(sbb_node* node, int value) {
    if (node == NULL) {
        return sbb_new_node(value);
    }
    if (value < node->value) {
        node->left = sbb_insert(node->left, value);
    } else if (value > node->value) {
        node->right = sbb_insert(node->right, value);
    } else {
        return node;
    }
    node = sbb_skew(node);
    node = sbb_split(node);
    return node;
}

void sbb_inorder(sbb_node* node) {
    if (node == NULL) {
        return;
    }
    sbb_inorder(node->left);
    printf("%d ", node->value);
    sbb_inorder(node->right);
}

int main() {
    //O custo para inserção,remoção e busca variam de acordo com a altura da árvore.
    //Árvore Binária Balanceda.
    sbb_node* root = NULL;
    root = sbb_insert(root, 5);
    root = sbb_insert(root, 3);
    root = sbb_insert(root, 7);
    root = sbb_insert(root, 1);
    root = sbb_insert(root, 4);
    root = sbb_insert(root, 6);
    root = sbb_insert(root, 8);
    printf("Inorder traversal of the SBB tree: ");
    sbb_inorder(root);
    return 0;
}

