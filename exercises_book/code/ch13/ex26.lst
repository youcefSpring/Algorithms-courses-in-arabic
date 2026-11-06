#include <stdio.h>
#include <stdlib.h>

typedef struct Tree { int code; struct Tree *left, *right; } Tree;

int maxDepth = 0;

Tree *newTree(int code, Tree *left, Tree *right) {
    Tree *node = malloc(sizeof(Tree));
    node->code = code; node->left = left; node->right = right;
    return node;
}

void countAtDepth(const Tree *node, int depth, int counts[]) {
    if (node == NULL) return;
    counts[depth]++;
    if (depth > maxDepth) maxDepth = depth;
    countAtDepth(node->left, depth + 1, counts);
    countAtDepth(node->right, depth + 1, counts);
}

void freeTree(Tree *node) { if (node) { freeTree(node->left); freeTree(node->right); free(node); } }

int main(void) {
    Tree *root = newTree(1, newTree(2, newTree(4, newTree(8, NULL, NULL), NULL), newTree(5, NULL, NULL)),
                            newTree(3, newTree(6, newTree(9, NULL, NULL), newTree(10, NULL, NULL)),
                                       newTree(7, NULL, newTree(11, NULL, NULL))));
    int counts[20] = {0}, level, widest = 0;
    countAtDepth(root, 0, counts);
    for (level = 0; level <= maxDepth; level++) {
        printf("level %d: %d categories\n", level, counts[level]);
        if (counts[level] > counts[widest]) widest = level;
    }
    printf("Widest level: %d (%d items)\n", widest, counts[widest]);
    freeTree(root);
    return 0;
}
