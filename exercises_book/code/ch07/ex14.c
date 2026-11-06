#include <stdio.h>

int findProduct(int codes[], int size, int target) {
    int idx;
    for (idx = 0; idx < size; idx++)
        if (codes[idx] == target)
            return idx;                 // نخرج فور العثور
    return -1;                          // غير موجود
}

int main(void) {
    int codes[6] = {1001, 2045, 3310, 5120, 7781, 9002};
    double prices[6] = {450, 12500, 899, 3200, 27000, 650};
    int nbQueries, query, target, idx;
    scanf("%d", &nbQueries);
    for (query = 0; query < nbQueries; query++) {
        scanf("%d", &target);
        idx = findProduct(codes, 6, target);
        if (idx >= 0)
            printf("Product %d: %.2f DA\n", target, prices[idx]);
        else
            printf("Product %d: not found\n", target);
    }
    return 0;
}
