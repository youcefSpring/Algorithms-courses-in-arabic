#include <stdio.h>
#include <stdlib.h>

typedef struct Tree { char name[16]; double price; struct Tree *left, *right; } Tree;

int compareText(const char *first, const char *second) {
    while (*first != '\0' && *first == *second) { first++; second++; }
    return *first - *second;
}

int startsWith(const char *text, const char *prefix) {
    while (*prefix != '\0') if (*text++ != *prefix++) return 0;
    return 1;
}

Tree *insert(Tree *node, const char *name, double price) {
    int pos;
    if (node == NULL) {
        node = malloc(sizeof(Tree));
        for (pos = 0; (node->name[pos] = name[pos]) != '\0'; pos++) {}
        node->price = price;
        node->left = node->right = NULL;
    } else if (compareText(name, node->name) < 0) node->left = insert(node->left, name, price);
    else node->right = insert(node->right, name, price);
    return node;
}

void inorder(const Tree *node) { if (node) { inorder(node->left); printf("%s ", node->name); inorder(node->right); } }

void printPrefix(const Tree *node, const char *prefix) {
    if (node == NULL) return;
    if (compareText(prefix, node->name) < 0) printPrefix(node->left, prefix);    // قد توجد يسارًا
    if (startsWith(node->name, prefix)) printf("  %s %.0f\n", node->name, node->price);
    if (startsWith(node->name, prefix) || compareText(node->name, prefix) < 0) printPrefix(node->right, prefix);
}

void freeTree(Tree *node) { if (node) { freeTree(node->left); freeTree(node->right); free(node); } }

int main(void) {
    const char *names[8] = {"Monitor", "Cable", "Mouse", "Laptop", "Webcam", "Modem", "Hub", "Keyboard"};
    double prices[8] = {32000, 450, 1500, 89000, 4100, 6200, 3100, 3200};
    Tree *root = NULL;
    char prefix[16];
    int idx;
    for (idx = 0; idx < 8; idx++) root = insert(root, names[idx], prices[idx]);
    printf("A-Z: "); inorder(root); printf("\n");
    scanf("%15s", prefix);
    printf("Starting with \"%s\":\n", prefix);
    printPrefix(root, prefix);
    freeTree(root);
    return 0;
}
