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

int found(Node *t, int x) {
    if (t == NULL) return 0;
    if (x == t->value) return 1;
    if (x < t->value)
        return found(t->left, x);
    return found(t->right, x);
}
int main(void) {
    Node *r = newNode(1500);
    r->left = newNode(900);
    r->right = newNode(2400);
    r->left->left = newNode(400);
    r->left->right = newNode(1200);
    printf("User 1200: %d\n", found(r, 1200));
    freeTree(r);
    return 0;
}
