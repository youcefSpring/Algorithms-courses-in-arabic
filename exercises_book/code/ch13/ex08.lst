#include <stdio.h>
#include <stdlib.h>

typedef struct Tree { double price; struct Tree *left, *right; } Tree;

Tree *insert(Tree *node, double price) {
    if (node == NULL) { node = malloc(sizeof(Tree)); node->price = price; node->left = node->right = NULL; }
    else if (price < node->price) node->left = insert(node->left, price);
    else node->right = insert(node->right, price);
    return node;
}

Tree *minNode(Tree *node) { while (node->left != NULL) node = node->left; return node; }
Tree *maxNode(Tree *node) { while (node->right != NULL) node = node->right; return node; }

void freeTree(Tree *node) { if (node) { freeTree(node->left); freeTree(node->right); free(node); } }

int main(void) {
    double prices[8] = {4500, 1200, 32000, 899, 3200, 12500, 450, 89000};
    Tree *root = NULL;
    int idx;
    for (idx = 0; idx < 8; idx++) root = insert(root, prices[idx]);
    printf("Cheapest: %.0f DA, most expensive: %.0f DA\n", minNode(root)->price, maxNode(root)->price);
    freeTree(root);
    return 0;
}
