#include <stdio.h>
#include <stdlib.h>

typedef struct Tree { int price; struct Tree *left, *right; } Tree;

Tree *insert(Tree *node, int price) {
    if (node == NULL) { node = malloc(sizeof(Tree)); node->price = price; node->left = node->right = NULL; }
    else if (price < node->price) node->left = insert(node->left, price);
    else node->right = insert(node->right, price);
    return node;
}

const Tree *lowestCommon(const Tree *node, int first, int second) {
    while (node != NULL) {
        if (first < node->price && second < node->price) node = node->left;
        else if (first > node->price && second > node->price) node = node->right;
        else return node;                             // تنفصل القيمتان هنا
    }
    return NULL;
}

int depthOf(const Tree *node, int price) {
    int depth = 0;
    while (node != NULL && node->price != price) { node = price < node->price ? node->left : node->right; depth++; }
    return depth;
}

void freeTree(Tree *node) { if (node) { freeTree(node->left); freeTree(node->right); free(node); } }

int main(void) {
    int prices[11] = {8000, 3000, 20000, 1200, 5000, 12000, 45000, 450, 2000, 4100, 15000};
    int pairs[3][2] = {{450, 2000}, {4100, 15000}, {12000, 15000}}, idx;
    Tree *root = NULL;
    const Tree *common;
    for (idx = 0; idx < 11; idx++) root = insert(root, prices[idx]);
    for (idx = 0; idx < 3; idx++) {
        common = lowestCommon(root, pairs[idx][0], pairs[idx][1]);
        printf("LCA(%d, %d) = %d, distance %d\n", pairs[idx][0], pairs[idx][1], common->price,
               depthOf(root, pairs[idx][0]) + depthOf(root, pairs[idx][1]) - 2 * depthOf(root, common->price));
    }
    freeTree(root);
    return 0;
}
