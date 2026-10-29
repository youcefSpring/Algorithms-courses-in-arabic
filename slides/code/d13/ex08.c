#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int value;
    struct Node *left, *right;
} Node;

Node *newNode(int v) {
    Node *n = malloc(sizeof(Node));
    n->value = v;
    n->left = n->right = NULL;
    return n;
}

void freeTree(Node *t) {
    if (t == NULL) return;
    freeTree(t->left);
    freeTree(t->right);
    free(t);
}

int count(Node *t) {
    if (t == NULL) return 0;
    return 1 + count(t->left)
             + count(t->right);
}
int main(void) {
    Node *r = newNode(10);
    r->left = newNode(5);
    r->right = newNode(15);
    r->left->left = newNode(2);
    r->left->right = newNode(7);
    printf("Folders = %d\n", count(r));
    freeTree(r);
    return 0;
}
