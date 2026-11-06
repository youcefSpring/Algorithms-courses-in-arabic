#include <stdio.h>
#include <stdlib.h>

typedef struct Tree { int feature; double threshold; int label; double probability; struct Tree *left, *right; } Tree;

const char *names[3] = {"pages", "minutes", "cart_items"};

Tree *test(int feature, double threshold, Tree *left, Tree *right) {
    Tree *node = malloc(sizeof(Tree));
    node->feature = feature; node->threshold = threshold; node->left = left; node->right = right;
    node->label = -1; node->probability = 0;
    return node;
}

Tree *leaf(int label, double probability) {
    Tree *node = test(-1, 0, NULL, NULL);
    node->label = label; node->probability = probability;
    return node;
}

const Tree *classify(const Tree *node, const double *features) {
    while (node->feature != -1) {
        printf(" %s=%.0f%s%.0f", names[node->feature], features[node->feature],
               features[node->feature] <= node->threshold ? "<=" : ">", node->threshold);
        node = features[node->feature] <= node->threshold ? node->left : node->right;
    }
    return node;
}

void freeTree(Tree *node) { if (node) { freeTree(node->left); freeTree(node->right); free(node); } }

int main(void) {
    Tree *root = test(2, 0, test(1, 3, leaf(0, 0.95), test(0, 6, leaf(0, 0.70), leaf(1, 0.60))),
                            test(1, 2, leaf(0, 0.55), leaf(1, 0.85)));
    double visitors[4][3] = {{2, 1, 0}, {9, 12, 0}, {4, 1, 2}, {7, 9, 3}};
    const Tree *result;
    int idx;
    for (idx = 0; idx < 4; idx++) {
        printf("visitor %d:", idx + 1);
        result = classify(root, visitors[idx]);
        printf(" -> %s (%.0f%%)\n", result->label ? "BUY" : "no buy", 100 * result->probability);
    }
    freeTree(root);
    return 0;
}
