#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *left, *right;
} Node;

Node *insert(Node *t, int v) {
    if (t == NULL) {
        t = malloc(sizeof(Node));
        t->value = v;
        t->left = t->right = NULL;
    } else if (v < t->value)
        t->left = insert(t->left, v);
    else
        t->right = insert(t->right, v);
    return t;
}

void inorder(Node *t) {
    if (t == NULL) return;
    inorder(t->left);
    printf("%d ", t->value);
    inorder(t->right);
}

int main(void) {
    int v[7] = {50, 30, 70, 20, 40, 60, 80};
    int i;
    Node *root = NULL;
    for (i = 0; i < 7; i++)
        root = insert(root, v[i]);
    inorder(root);
    printf("\n");
    return 0;
}
