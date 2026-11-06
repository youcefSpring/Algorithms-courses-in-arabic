#include <stdio.h>
#include <stdlib.h>

typedef struct Tree { int code; struct Tree *left, *right; } Tree;

Tree *newTree(int code, Tree *left, Tree *right) {
    Tree *node = malloc(sizeof(Tree));
    node->code = code; node->left = left; node->right = right;
    return node;
}

int countNodes(const Tree *node) {
    if (node == NULL) return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

void freeTree(Tree *node) { if (node) { freeTree(node->left); freeTree(node->right); free(node); } }

int main(void) {
    Tree *root = newTree(1, newTree(2, newTree(4, NULL, NULL), newTree(5, newTree(8, NULL, NULL), NULL)),
                            newTree(3, NULL, newTree(6, NULL, newTree(7, NULL, NULL))));
    printf("Total categories: %d\n", countNodes(root));
    printf("Left branch: %d, right branch: %d\n", countNodes(root->left), countNodes(root->right));
    freeTree(root);
    return 0;
}
