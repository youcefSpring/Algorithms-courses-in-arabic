#include <stdio.h>
#include <stdlib.h>

typedef struct Tree { int code; struct Tree *left, *right; } Tree;

Tree *newTree(int code, Tree *left, Tree *right) {
    Tree *node = malloc(sizeof(Tree));
    node->code = code; node->left = left; node->right = right;
    return node;
}

int sameTree(const Tree *first, const Tree *second) {
    if (first == NULL && second == NULL) return 1;
    if (first == NULL || second == NULL) return 0;
    return first->code == second->code && sameTree(first->left, second->left) && sameTree(first->right, second->right);
}

int countNodes(const Tree *node) { return node == NULL ? 0 : 1 + countNodes(node->left) + countNodes(node->right); }

int countDiff(const Tree *first, const Tree *second) {
    if (first == NULL) return countNodes(second);              // عقد مضافة
    if (second == NULL) return countNodes(first);              // عقد محذوفة
    return (first->code != second->code) + countDiff(first->left, second->left) + countDiff(first->right, second->right);
}

void freeTree(Tree *node) { if (node) { freeTree(node->left); freeTree(node->right); free(node); } }

int main(void) {
    Tree *oldTree = newTree(1, newTree(2, newTree(4, NULL, NULL), NULL), newTree(3, newTree(5, NULL, NULL), newTree(6, NULL, NULL)));
    Tree *sameCopy = newTree(1, newTree(2, newTree(4, NULL, NULL), NULL), newTree(3, newTree(5, NULL, NULL), newTree(6, NULL, NULL)));
    Tree *newVersion = newTree(1, newTree(2, newTree(4, NULL, NULL), newTree(7, NULL, NULL)), newTree(9, newTree(5, NULL, NULL), NULL));
    printf("old vs copy: %s, %d differences\n", sameTree(oldTree, sameCopy) ? "same" : "different", countDiff(oldTree, sameCopy));
    printf("old vs new:  %s, %d differences\n", sameTree(oldTree, newVersion) ? "same" : "different", countDiff(oldTree, newVersion));
    freeTree(oldTree); freeTree(sameCopy); freeTree(newVersion);
    return 0;
}
