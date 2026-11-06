#include <stdio.h>
#include <stdlib.h>

typedef struct Tree { double price; struct Tree *left, *right; } Tree;

Tree *newTree(double price, Tree *left, Tree *right) {
    Tree *node = malloc(sizeof(Tree));
    node->price = price; node->left = left; node->right = right;
    return node;
}

double sumPrices(const Tree *node) {
    if (node == NULL) return 0;
    return node->price + sumPrices(node->left) + sumPrices(node->right);
}

double maxPrice(const Tree *node) {
    double best, side;
    if (node == NULL) return 0;
    best = node->price;
    side = maxPrice(node->left);  if (side > best) best = side;
    side = maxPrice(node->right); if (side > best) best = side;
    return best;
}

void freeTree(Tree *node) { if (node) { freeTree(node->left); freeTree(node->right); free(node); } }

int main(void) {
    Tree *root = newTree(4500, newTree(1200, newTree(899, NULL, NULL), NULL),
                               newTree(32000, newTree(450, NULL, NULL), newTree(89000, NULL, NULL)));
    printf("Total: %.0f DA, most expensive: %.0f DA\n", sumPrices(root), maxPrice(root));
    freeTree(root);
    return 0;
}
