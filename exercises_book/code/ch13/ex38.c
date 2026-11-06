#include <stdio.h>
#include <stdlib.h>

typedef struct Tree { int price; struct Tree *left, *right; } Tree;

Tree *newTree(int price) { Tree *node = malloc(sizeof(Tree)); node->price = price; node->left = node->right = NULL; return node; }

Tree *insert(Tree *node, int price) {
    if (node == NULL) return newTree(price);
    if (price < node->price) node->left = insert(node->left, price);
    else node->right = insert(node->right, price);
    return node;
}

void collect(const Tree *node, int *out, int *count) {
    if (node == NULL) return;
    collect(node->left, out, count);
    out[(*count)++] = node->price;            // بالترتيب
    collect(node->right, out, count);
}

Tree *buildBalanced(const int *values, int low, int high) {
    Tree *node;
    int middle;
    if (low > high) return NULL;
    middle = (low + high) / 2;
    node = newTree(values[middle]);
    node->left = buildBalanced(values, low, middle - 1);
    node->right = buildBalanced(values, middle + 1, high);
    return node;
}

int height(const Tree *node) { int lh, rh; if (!node) return 0; lh = height(node->left); rh = height(node->right); return 1 + (lh > rh ? lh : rh); }
void freeTree(Tree *node) { if (node) { freeTree(node->left); freeTree(node->right); free(node); } }

int main(void) {
    int pricesA[6] = {4500, 1200, 32000, 899, 3200, 12500}, pricesB[6] = {3200, 650, 15000, 899, 89000, 2200};
    int listA[10], listB[10], merged[20], sizeA = 0, sizeB = 0, size = 0, left = 0, right = 0, idx;
    Tree *storeA = NULL, *storeB = NULL, *combined;
    for (idx = 0; idx < 6; idx++) { storeA = insert(storeA, pricesA[idx]); storeB = insert(storeB, pricesB[idx]); }
    collect(storeA, listA, &sizeA);
    collect(storeB, listB, &sizeB);
    while (left < sizeA || right < sizeB) {
        if (right == sizeB || (left < sizeA && listA[left] < listB[right])) merged[size++] = listA[left++];
        else if (left == sizeA || listB[right] < listA[left]) merged[size++] = listB[right++];
        else { merged[size++] = listA[left++]; right++; }   // نفس السعر مرة واحدة
    }
    combined = buildBalanced(merged, 0, size - 1);
    printf("merged (%d):", size);
    for (idx = 0; idx < size; idx++) printf(" %d", merged[idx]);
    printf("\nbalanced tree: root %d, height %d\n", combined->price, height(combined));
    freeTree(storeA); freeTree(storeB); freeTree(combined);
    return 0;
}
