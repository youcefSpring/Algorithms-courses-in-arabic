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

int maxValue(Node *t) {
    while (t->right != NULL)
        t = t->right;
    return t->value;
}
int main(void) {
    Node *r = newNode(65);
    r->left = newNode(40);
    r->right = newNode(90);
    r->left->left = newNode(25);
    r->left->right = newNode(52);
    printf("Best = %d\n", maxValue(r));
    freeTree(r);
    return 0;
}
