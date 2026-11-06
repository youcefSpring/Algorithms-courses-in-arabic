#include <stdio.h>
#include <stdlib.h>

typedef struct Tree { int price; struct Tree *left, *right; } Tree;

Tree *insert(Tree *node, int price) {
    if (node == NULL) { node = malloc(sizeof(Tree)); node->price = price; node->left = node->right = NULL; }
    else if (price < node->price) node->left = insert(node->left, price);
    else node->right = insert(node->right, price);
    return node;
}

Tree *removeKey(Tree *node, int price) {
    Tree *child, *succ;
    if (node == NULL) return NULL;
    if (price < node->price) node->left = removeKey(node->left, price);
    else if (price > node->price) node->right = removeKey(node->right, price);
    else if (node->left == NULL || node->right == NULL) {      // 0 أو 1 ابن
        child = node->left != NULL ? node->left : node->right;
        free(node);
        return child;
    } else {                                                   // ابنان
        for (succ = node->right; succ->left != NULL; succ = succ->left) {}
        node->price = succ->price;                             // نسخ الخلف
        node->right = removeKey(node->right, succ->price);
    }
    return node;
}

void inorder(const Tree *node) { if (node) { inorder(node->left); printf("%d ", node->price); inorder(node->right); } }
void freeTree(Tree *node) { if (node) { freeTree(node->left); freeTree(node->right); free(node); } }

int main(void) {
    int prices[9] = {4500, 1200, 32000, 899, 3200, 12500, 89000, 2000, 15000}, idx;
    Tree *root = NULL;
    for (idx = 0; idx < 9; idx++) root = insert(root, prices[idx]);
    printf("start:          "); inorder(root); printf("\n");
    root = removeKey(root, 899);   printf("remove leaf 899: "); inorder(root); printf("\n");
    root = removeKey(root, 12500); printf("remove 1-child:  "); inorder(root); printf("\n");
    root = removeKey(root, 4500);  printf("remove root:     "); inorder(root); printf("\n");
    printf("new root: %d\n", root->price);
    freeTree(root);
    return 0;
}
