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

void inorder(Node *t) {
    if (t == NULL) return;
    inorder(t->left);
    printf("%d ", t->value);
    inorder(t->right);
}
int main(void) {
    Node *r = newNode(50);
    r->left = newNode(30);
    r->right = newNode(70);
    r->left->left = newNode(20);
    r->left->right = newNode(40);
    inorder(r);
    printf("\n");
    freeTree(r);
    return 0;
}
