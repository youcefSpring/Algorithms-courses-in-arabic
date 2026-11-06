#include <stdio.h>
#include <stdlib.h>

typedef struct Tree { int price; struct Tree *left, *right; } Tree;

Tree *insert(Tree *node, int price) {
    if (node == NULL) { node = malloc(sizeof(Tree)); node->price = price; node->left = node->right = NULL; }
    else if (price < node->price) node->left = insert(node->left, price);
    else node->right = insert(node->right, price);
    return node;
}

void mirror(Tree *node) {
    Tree *tmp;
    if (node == NULL) return;
    tmp = node->left;                 // تبديل الابنين
    node->left = node->right;
    node->right = tmp;
    mirror(node->left);
    mirror(node->right);
}

void inorder(const Tree *node) { if (node) { inorder(node->left); printf("%d ", node->price); inorder(node->right); } }
void freeTree(Tree *node) { if (node) { freeTree(node->left); freeTree(node->right); free(node); } }

int main(void) {
    int prices[7] = {4500, 1200, 32000, 899, 3200, 12500, 89000}, idx;
    Tree *root = NULL;
    for (idx = 0; idx < 7; idx++) root = insert(root, prices[idx]);
    printf("original: "); inorder(root); printf("\n");
    mirror(root);
    printf("mirror:   "); inorder(root); printf("\n");
    mirror(root);
    printf("back:     "); inorder(root); printf("\n");
    freeTree(root);
    return 0;
}
