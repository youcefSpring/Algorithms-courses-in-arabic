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

int minValue(Node *t) {
    while (t->left != NULL)
        t = t->left;
    return t->value;
}
int main(void) {
    Node *r = newNode(24);
    r->left = newNode(15);
    r->right = newNode(33);
    r->left->left = newNode(8);
    r->left->right = newNode(19);
    printf("Min = %d C\n", minValue(r));
    freeTree(r);
    return 0;
}
