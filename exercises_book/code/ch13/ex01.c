#include <stdio.h>
#include <stdlib.h>

typedef struct Tree { char name[14]; struct Tree *left, *right; } Tree;

Tree *newTree(const char *name) {
    Tree *node = malloc(sizeof(Tree));
    int pos;
    for (pos = 0; (node->name[pos] = name[pos]) != '\0'; pos++) {}
    node->left = node->right = NULL;
    return node;
}

void printPre(const Tree *node, int depth) {
    if (node == NULL) return;
    printf("%*s%s\n", 2 * depth, "", node->name);    // العقدة أولًا
    printPre(node->left, depth + 1);
    printPre(node->right, depth + 1);
}

void freeTree(Tree *node) {
    if (node == NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

int main(void) {
    Tree *root = newTree("Store");
    root->left = newTree("Electronics");
    root->right = newTree("Home");
    root->left->left = newTree("Phones");
    root->left->right = newTree("Laptops");
    root->right->left = newTree("Kitchen");
    printPre(root, 0);
    freeTree(root);
    return 0;
}
