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

int leaves(Node *t) {
    if (t == NULL) return 0;
    if (t->left == NULL && t->right == NULL)
        return 1;
    return leaves(t->left)
         + leaves(t->right);
}
int main(void) {
    Node *r = newNode(50);
    r->left = newNode(30);
    r->right = newNode(70);
    r->left->left = newNode(20);
    r->left->right = newNode(40);
    printf("Decisions = %d\n", leaves(r));
    freeTree(r);
    return 0;
}
