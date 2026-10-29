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

void preorder(Node *t) {
    if (t == NULL) return;
    printf("%d ", t->value);
    preorder(t->left);
    preorder(t->right);
}
int main(void) {
    Node *r = newNode(100);
    r->left = newNode(50);
    r->right = newNode(150);
    r->left->left = newNode(20);
    r->left->right = newNode(70);
    preorder(r);
    printf("\n");
    freeTree(r);
    return 0;
}
