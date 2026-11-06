#include <stdio.h>
#include <stdlib.h>

typedef struct Tree { int price; struct Tree *left, *right; } Tree;

Tree *insert(Tree *node, int price) {
    if (node == NULL) { node = malloc(sizeof(Tree)); node->price = price; node->left = node->right = NULL; }
    else if (price < node->price) node->left = insert(node->left, price);
    else node->right = insert(node->right, price);
    return node;
}

int checkBalance(const Tree *node) {
    int leftH, rightH, diff;
    if (node == NULL) return 0;
    leftH = checkBalance(node->left);
    rightH = checkBalance(node->right);
    diff = leftH - rightH;
    if (leftH < 0 || rightH < 0 || diff > 1 || diff < -1) return -1;   // غير متوازنة
    return 1 + (leftH > rightH ? leftH : rightH);
}

void freeTree(Tree *node) { if (node) { freeTree(node->left); freeTree(node->right); free(node); } }

int main(void) {
    int mixed[7] = {4000, 2000, 6000, 1000, 3000, 5000, 7000};
    int sorted[7] = {1000, 2000, 3000, 4000, 5000, 6000, 7000};
    Tree *first = NULL, *second = NULL;
    int idx, result;
    for (idx = 0; idx < 7; idx++) { first = insert(first, mixed[idx]); second = insert(second, sorted[idx]); }
    result = checkBalance(first);
    printf("mixed input:  %s (height %d)\n", result >= 0 ? "balanced" : "unbalanced", result);
    result = checkBalance(second);
    printf("sorted input: %s\n", result >= 0 ? "balanced" : "unbalanced (a chain of 7 nodes)");
    freeTree(first);
    freeTree(second);
    return 0;
}
