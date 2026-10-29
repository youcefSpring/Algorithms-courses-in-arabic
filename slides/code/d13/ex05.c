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

int height(Node *t) {
    if (t == NULL) return 0;
    int a = height(t->left);
    int b = height(t->right);
    if (a > b) return 1 + a;
    return 1 + b;
}
int main(void) {
    Node *r = newNode(5);
    r->left = newNode(3);
    r->right = newNode(8);
    r->left->left = newNode(1);
    r->left->right = newNode(4);
    printf("Height = %d\n", height(r));
    freeTree(r);
    return 0;
}
