#include <stdio.h>
#include <stdlib.h>

typedef struct Tree { double sales; struct Tree *left, *right; } Tree;

Tree *newTree(double sales, Tree *left, Tree *right) {
    Tree *node = malloc(sizeof(Tree));
    node->sales = sales; node->left = left; node->right = right;
    return node;
}

void freeTree(Tree *node) { if (node) { freeTree(node->left); freeTree(node->right); free(node); } }

int main(void) {
    Tree *root = newTree(120000,
        newTree(310000, newTree(450000, NULL, NULL), newTree(380000, NULL, NULL)),
        newTree(290000, newTree(520000, NULL, NULL), newTree(410000, newTree(200000, NULL, NULL), NULL)));
    Tree *queue[32], *node;
    int front = 0, rear = 0, levelSize, idx, level = 0, bestLevel = 0;
    double sum, bestAvg = -1;
    queue[rear++] = root;
    while (front < rear) {
        levelSize = rear - front;
        for (sum = 0, idx = 0; idx < levelSize; idx++) {
            node = queue[front++];
            sum += node->sales;
            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
        printf("level %d: %d people, total %8.0f, average %8.0f\n", level, levelSize, sum, sum / levelSize);
        if (sum / levelSize > bestAvg) { bestAvg = sum / levelSize; bestLevel = level; }
        level++;
    }
    printf("Best average at level %d\n", bestLevel);
    freeTree(root);
    return 0;
}
