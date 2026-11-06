#include <stdio.h>
#include <stdlib.h>

int *mergeNew(const int *first, int sizeA, const int *second, int sizeB) {
    int *merged = malloc((sizeA + sizeB) * sizeof(int)), *out = merged;
    const int *left = first, *right = second, *endA = first + sizeA, *endB = second + sizeB;
    if (merged == NULL) return NULL;
    while (left < endA && right < endB)
        *out++ = (*left <= *right) ? *left++ : *right++;   // الأصغر أولًا
    while (left < endA) *out++ = *left++;
    while (right < endB) *out++ = *right++;
    return merged;
}

int main(void) {
    int supplierA[5] = {450, 900, 1500, 3200, 7800};
    int supplierB[4] = {300, 1200, 2500, 9900};
    int *merged = mergeNew(supplierA, 5, supplierB, 4), *ptr;
    for (ptr = merged; ptr < merged + 9; ptr++) printf("%d ", *ptr);
    printf("\n");
    free(merged);
    return 0;
}
