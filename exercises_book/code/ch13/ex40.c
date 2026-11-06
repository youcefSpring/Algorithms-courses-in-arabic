#include <stdio.h>
#include <stdlib.h>

typedef struct Tree { int code; struct Tree *left, *right; } Tree;

Tree *newTree(int code, Tree *left, Tree *right) {
    Tree *node = malloc(sizeof(Tree));
    node->code = code; node->left = left; node->right = right;
    return node;
}

int minDepth(const Tree *node) {
    int leftD, rightD;
    if (node->left == NULL && node->right == NULL) return 1;       // ورقة
    if (node->left == NULL) return 1 + minDepth(node->right);      // لا نأخذ الفرع الفارغ
    if (node->right == NULL) return 1 + minDepth(node->left);
    leftD = minDepth(node->left);
    rightD = minDepth(node->right);
    return 1 + (leftD < rightD ? leftD : rightD);
}

int height(const Tree *node) {
    int leftH, rightH;
    if (node == NULL) return 0;
    leftH = height(node->left); rightH = height(node->right);
    return 1 + (leftH > rightH ? leftH : rightH);
}

void freeTree(Tree *node) { if (node) { freeTree(node->left); freeTree(node->right); free(node); } }

int main(void) {
    Tree *root = newTree(1, newTree(2, NULL, newTree(4, newTree(7, NULL, NULL), NULL)),
                            newTree(3, newTree(5, NULL, NULL), newTree(6, newTree(8, newTree(9, NULL, NULL), NULL), NULL)));
    printf("Fewest clicks to a final category: %d levels\n", minDepth(root));
    printf("Most clicks (height): %d levels\n", height(root));
    freeTree(root);
    return 0;
}
