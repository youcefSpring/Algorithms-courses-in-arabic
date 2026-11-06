#include <stdio.h>
#include <stdlib.h>

typedef struct Tree { char name[14]; struct Tree *left, *right; } Tree;

Tree *newTree(const char *name, Tree *left, Tree *right) {
    Tree *node = malloc(sizeof(Tree));
    int pos;
    for (pos = 0; (node->name[pos] = name[pos]) != '\0'; pos++) {}
    node->left = left; node->right = right;
    return node;
}

int sameText(const char *first, const char *second) {
    while (*first != '\0' && *first == *second) { first++; second++; }
    return *first == *second;
}

int findPath(const Tree *node, const char *target, const Tree *path[], int depth) {
    int found;
    if (node == NULL) return 0;
    path[depth] = node;
    if (sameText(node->name, target)) return depth + 1;
    found = findPath(node->left, target, path, depth + 1);
    if (found == 0) found = findPath(node->right, target, path, depth + 1);
    return found;
}

void freeTree(Tree *node) { if (node) { freeTree(node->left); freeTree(node->right); free(node); } }

int main(void) {
    Tree *root = newTree("Store",
        newTree("Electronics", newTree("Phones", newTree("Android", NULL, NULL), newTree("iOS", NULL, NULL)), newTree("Laptops", NULL, NULL)),
        newTree("Home", newTree("Kitchen", NULL, NULL), newTree("Garden", newTree("Tools", NULL, NULL), NULL)));
    const Tree *path[10];
    char target[14];
    int len, idx, query;
    for (query = 0; query < 3; query++) {
        scanf("%13s", target);
        len = findPath(root, target, path, 0);
        if (len == 0) { printf("%s: not found\n", target); continue; }
        for (idx = 0; idx < len; idx++) printf("%s%s", path[idx]->name, idx < len - 1 ? " > " : "\n");
    }
    freeTree(root);
    return 0;
}
