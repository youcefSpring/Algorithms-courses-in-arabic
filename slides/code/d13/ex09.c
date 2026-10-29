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

int above(Node *t, int x) {
    if (t == NULL) return 0;
    int n = above(t->left, x)
          + above(t->right, x);
    if (t->value > x) n++;
    return n;
}
int main(void) {
    Node *r = newNode(110);
    r->left = newNode(60);
    r->right = newNode(150);
    r->left->left = newNode(40);
    r->left->right = newNode(105);
    printf("Polluted = %d\n", above(r, 100));
    freeTree(r);
    return 0;
}
