#include <stdio.h>
#include <stdlib.h>

typedef struct Tree { int code; struct Tree *left, *right; } Tree;

Tree *newTree(int code, Tree *left, Tree *right) {
    Tree *node = malloc(sizeof(Tree));
    node->code = code; node->left = left; node->right = right;
    return node;
}

void preorder(const Tree *node)  { if (node) { printf("%d ", node->code); preorder(node->left); preorder(node->right); } }
void inorder(const Tree *node)   { if (node) { inorder(node->left); printf("%d ", node->code); inorder(node->right); } }
void postorder(const Tree *node) { if (node) { postorder(node->left); postorder(node->right); printf("%d ", node->code); } }

void freeTree(Tree *node) { if (node) { freeTree(node->left); freeTree(node->right); free(node); } }

int main(void) {
    Tree *root = newTree(50, newTree(30, newTree(20, NULL, NULL), newTree(40, NULL, NULL)),
                             newTree(70, newTree(60, NULL, NULL), newTree(80, NULL, NULL)));
    printf("preorder : "); preorder(root);  printf("\n");
    printf("inorder  : "); inorder(root);   printf("\n");
    printf("postorder: "); postorder(root); printf("\n");
    freeTree(root);
    return 0;
}
