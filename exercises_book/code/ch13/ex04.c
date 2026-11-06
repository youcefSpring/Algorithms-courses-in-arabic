#include <stdio.h>
#include <stdlib.h>

typedef struct Tree { int code; struct Tree *left, *right; } Tree;

Tree *newTree(int code, Tree *left, Tree *right) {
    Tree *node = malloc(sizeof(Tree));
    node->code = code; node->left = left; node->right = right;
    return node;
}

int height(const Tree *node) {
    int leftH, rightH;
    if (node == NULL) return 0;
    leftH = height(node->left);
    rightH = height(node->right);
    return 1 + (leftH > rightH ? leftH : rightH);
}

void freeTree(Tree *node) { if (node) { freeTree(node->left); freeTree(node->right); free(node); } }

int main(void) {
    Tree *root = newTree(1, newTree(2, newTree(4, NULL, NULL), newTree(5, newTree(8, newTree(9, NULL, NULL), NULL), NULL)),
                            newTree(3, NULL, newTree(6, NULL, NULL)));
    printf("Menu depth (height): %d levels\n", height(root));
    printf("Left: %d, right: %d\n", height(root->left), height(root->right));
    freeTree(root);
    return 0;
}
