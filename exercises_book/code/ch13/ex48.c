#include <stdio.h>
#include <stdlib.h>

typedef struct Tree { int price; struct Tree *left, *right; } Tree;

Tree *insert(Tree *node, int price) {
    if (node == NULL) { node = malloc(sizeof(Tree)); node->price = price; node->left = node->right = NULL; }
    else if (price < node->price) node->left = insert(node->left, price);
    else node->right = insert(node->right, price);
    return node;
}

int countThreads = 0;

void morris(Tree *root) {
    Tree *node = root, *pred;
    while (node != NULL) {
        if (node->left == NULL) {
            printf("%d ", node->price);
            node = node->right;                          // قد يكون رابطًا مؤقتًا
        } else {
            for (pred = node->left; pred->right != NULL && pred->right != node; pred = pred->right) {}
            if (pred->right == NULL) {
                pred->right = node;                      // رابط مؤقت للعودة
                countThreads++;
                node = node->left;
            } else {
                pred->right = NULL;                      // نزيل الرابط
                printf("%d ", node->price);
                node = node->right;
            }
        }
    }
    printf("\n");
}

void inorder(const Tree *node) { if (node) { inorder(node->left); printf("%d ", node->price); inorder(node->right); } }
void freeTree(Tree *node) { if (node) { freeTree(node->left); freeTree(node->right); free(node); } }

int main(void) {
    int prices[10] = {4500, 1200, 32000, 899, 3200, 12500, 89000, 450, 2000, 6800}, idx;
    Tree *root = NULL;
    for (idx = 0; idx < 10; idx++) root = insert(root, prices[idx]);
    printf("Morris:    ");
    morris(root);
    printf("temporary links created and removed: %d\n", countThreads);
    printf("recursive: ");
    inorder(root);                                       // الشجرة سليمة
    printf("\n");
    freeTree(root);
    return 0;
}
