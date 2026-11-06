#include <stdio.h>
#include <stdlib.h>

typedef struct Tree { int price; struct Tree *left, *right; } Tree;

Tree *insert(Tree *node, int price) {
    if (node == NULL) { node = malloc(sizeof(Tree)); node->price = price; node->left = node->right = NULL; }
    else if (price < node->price) node->left = insert(node->left, price);
    else node->right = insert(node->right, price);
    return node;
}

const Tree *successor(const Tree *node, int price) {
    const Tree *best = NULL;
    while (node != NULL) {
        if (node->price > price) { best = node; node = node->left; }   // مرشح أقرب
        else node = node->right;
    }
    return best;
}

void freeTree(Tree *node) { if (node) { freeTree(node->left); freeTree(node->right); free(node); } }

int main(void) {
    int prices[9] = {4500, 1200, 32000, 899, 3200, 12500, 89000, 6800, 15000}, idx, price;
    const Tree *next;
    Tree *root = NULL;
    for (idx = 0; idx < 9; idx++) root = insert(root, prices[idx]);
    scanf("%d", &price);
    printf("Walking up from %d:", price);
    for (next = successor(root, price); next != NULL; next = successor(root, next->price))
        printf(" -> %d", next->price);
    printf(" -> end\n");
    freeTree(root);
    return 0;
}
