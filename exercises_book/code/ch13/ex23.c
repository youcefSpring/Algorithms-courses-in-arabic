#include <stdio.h>
#include <stdlib.h>

typedef struct Tree { int code; struct Tree *left, *right; } Tree;

Tree *newTree(int code) {
    Tree *node = malloc(sizeof(Tree));
    node->code = code; node->left = node->right = NULL;
    return node;
}

Tree *buildBalanced(const int *codes, int low, int high) {
    Tree *node;
    int middle;
    if (low > high) return NULL;
    middle = (low + high) / 2;
    node = newTree(codes[middle]);                       // الأوسط جذرًا
    node->left = buildBalanced(codes, low, middle - 1);
    node->right = buildBalanced(codes, middle + 1, high);
    return node;
}

Tree *insert(Tree *node, int code) {
    if (node == NULL) return newTree(code);
    if (code < node->code) node->left = insert(node->left, code);
    else node->right = insert(node->right, code);
    return node;
}

int height(const Tree *node) {
    int leftH, rightH;
    if (node == NULL) return 0;
    leftH = height(node->left); rightH = height(node->right);
    return 1 + (leftH > rightH ? leftH : rightH);
}

void freeTree(Tree *node) { if (node) { freeTree(node->left); freeTree(node->right); free(node); } }

int main(void) {
    int codes[15], idx;
    Tree *balanced, *chain = NULL;
    for (idx = 0; idx < 15; idx++) codes[idx] = 1001 + idx * 7;
    balanced = buildBalanced(codes, 0, 14);
    for (idx = 0; idx < 15; idx++) chain = insert(chain, codes[idx]);
    printf("15 sorted codes\nbalanced build: root %d, height %d\n", balanced->code, height(balanced));
    printf("insert one by one: root %d, height %d\n", chain->code, height(chain));
    freeTree(balanced);
    freeTree(chain);
    return 0;
}
