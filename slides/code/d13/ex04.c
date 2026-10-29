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

int sum(Node *t) {
    if (t == NULL) return 0;
    return t->value + sum(t->left)
                    + sum(t->right);
}
int main(void) {
    Node *r = newNode(3000);
    r->left = newNode(1500);
    r->right = newNode(4500);
    r->left->left = newNode(800);
    r->left->right = newNode(2000);
    printf("Total = %d DA\n", sum(r));
    freeTree(r);
    return 0;
}
